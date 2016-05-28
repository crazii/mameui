// license:BSD-3-Clause
// copyright-holders:Aaron Giles
/***************************************************************************

    audit.c

    ROM set auditing functions.

***************************************************************************/

#include "emu.h"
#include "emuopts.h"
#include "audit.h"
#include "chd.h"
#include "drivenum.h"
#include "sound/samples.h"
#include "softlist.h"
#include "util/unzip.h"
#include <set>
#include <map>

//-------------------------------------------------
//  internal helper
//-------------------------------------------------
void	check_archive(const char* paths, const char* subpaths, std::set<std::string>& valid_paths, std::set<std::string>& invalid_paths)
{
	typedef util::archive_file::error(*open_func)(const std::string &filename, util::archive_file::ptr &result);
	char const *const suffixes[] = { ".zip", ".7z" };
	open_func const open_funcs[ARRAY_LENGTH(suffixes)] = { &util::archive_file::open_zip, &util::archive_file::open_7z };

	static std::map<std::string, bool> rootmap;

	//root archive exist? i.e. roms.zip
	std::map<std::string, bool>::iterator rootmap_iter = rootmap.find(paths);
	if(rootmap_iter == rootmap.end() )
	{
		bool root_exist = false;
		path_iterator media(paths);
		std::string media_path;
		while (media.next(media_path) && !root_exist)
		{
			if (media_path.empty())
				continue;

			for (unsigned i = 0; i < ARRAY_LENGTH(suffixes); i++)
			{
				// attempt to open the archive file
				util::archive_file::ptr zip;
				util::archive_file::error ziperr = open_funcs[i](media_path + suffixes[i], zip);
				zip.reset();
				if (ziperr == util::archive_file::error::NONE)
				{
					root_exist = true;
					break;
				}
			}
		}
		rootmap_iter = rootmap.insert(std::make_pair(paths, root_exist)).first;
	}
	bool root_exist = rootmap_iter->second;

	path_iterator iter(subpaths);
	std::string path;
	while (iter.next(path))
	{
		if(path.empty())
			continue;
		if(invalid_paths.find(path) != invalid_paths.end())
			continue;
		if (valid_paths.find(path) != valid_paths.end())
			continue;

		path_iterator media(paths);
		std::string media_path;
		while (media.next(media_path))
		{
			if(media_path.empty())
				continue;

			std::string fullpath = media_path + PATH_SEPARATOR + path;
			osd_directory *dir = osd_opendir(fullpath.c_str());
			if (dir != NULL)
				valid_paths.insert(path);
			if (dir)
				osd_closedir(dir);
			if(dir != NULL)
				continue;

			bool found = false;
			for (unsigned i = 0; i < ARRAY_LENGTH(suffixes); i++)
			{
				// attempt to open the archive file
				util::archive_file::ptr zip;
				util::archive_file::error ziperr = open_funcs[i](fullpath + suffixes[i], zip);
				zip.reset();
				if (ziperr == util::archive_file::error::NONE)
				{
					found = true;
					break;
				}
			}

			if (!found && root_exist)
			{
				//find folder in root archive. (roms.zip/xxx)
				for (unsigned i = 0; i < ARRAY_LENGTH(suffixes); i++)
				{
					util::archive_file::ptr zip;
					//check against any root folder. TODO: another map each folder?
					util::archive_file::error ziperr = open_funcs[i](media_path + suffixes[i], zip);
					if (ziperr == util::archive_file::error::NONE && (zip->search(path, true) || zip->search(path, false)))
					{
						found = true;
						break;
					}
				}
			}

			if (found)
				valid_paths.insert(path);
			else
				invalid_paths.insert(path);
		}
	}
}

//**************************************************************************
//  CORE FUNCTIONS
//**************************************************************************

//-------------------------------------------------
//  media_auditor - constructor
//-------------------------------------------------

media_auditor::media_auditor(const driver_enumerator &enumerator)
	: m_enumerator(enumerator),
		m_validation(AUDIT_VALIDATE_FULL),
		m_searchpath(nullptr)
{
}


//-------------------------------------------------
//  audit_media - audit the media described by the
//  currently-enumerated driver
//-------------------------------------------------

media_auditor::summary media_auditor::audit_media(const char *validation)
{
	// start fresh
	m_record_list.reset();

	// store validation for later
	m_validation = validation;

	// temporary hack until romload is update: get the driver path and support it for
	// all searches
	const char *driverpath = m_enumerator.config().root_device().searchpath();
	
	//early exit if all directories/zips are invalid
	std::set<std::string> root_pathset;
	std::set<std::string> root_invalid_pathset;
	check_archive(m_enumerator.options().media_path(), driverpath, root_pathset, root_invalid_pathset);

	std::vector<std::set<std::string> > all_pathset;

	int device_count = device_iterator(m_enumerator.config().root_device()).count();
	all_pathset.resize( device_count, root_pathset);
	{
		size_t valid_count = 0;
		size_t device_index = 0;
		for (device_t &device : device_iterator(m_enumerator.config().root_device()))
		{
			if(device_index!=0)	//root already checked
			{
				std::set<std::string> invalid_pathset = root_invalid_pathset;
				check_archive(m_enumerator.options().media_path(), device.searchpath(), all_pathset[device_index], invalid_pathset);
				if (device.shortname())
					check_archive(m_enumerator.options().media_path(), device.shortname(), all_pathset[device_index], invalid_pathset);				
			}
			valid_count += all_pathset[device_index].size();
			++device_index;
		}
		if(valid_count == 0)
			return NOTFOUND;
	}

	int found = 0;
	int required = 0;
	int shared_found = 0;
	int shared_required = 0;

	// iterate over devices and regions
	size_t device_index = 0;
	for (device_t &device : device_iterator(m_enumerator.config().root_device()))
	{
		std::string combinedpath = "";
		
		const std::set<std::string>& pathset = all_pathset[device_index++];
		if( !pathset.empty() )
		{
			combinedpath = *pathset.begin();
			for (std::set<std::string>::iterator iter = ++pathset.begin(); iter != pathset.end(); ++iter)
				combinedpath += ";" + *iter;
		}		
		m_searchpath = combinedpath.c_str();
		
		// now iterate over regions and ROMs within
		for (const rom_entry *region = rom_first_region(device); region != nullptr; region = rom_next_region(region))
		{
			if (pathset.empty())
			{
				for (const rom_entry *rom = rom_first_file(region); rom; rom = rom_next_file(rom))
				{
					const char *name = ROM_GETNAME(rom);
					hash_collection hashes(ROM_GETHASHDATA(rom));
					device_t *shared_device = find_shared_device(device, name, hashes, ROM_GETLENGTH(rom));
					if (!hashes.flag(hash_collection::FLAG_NO_DUMP) && !ROM_ISOPTIONAL(rom))
					{
						required++;
						if (shared_device != nullptr)
							shared_required++;
					}
					audit_record::media_type tp = ROMREGION_ISROMDATA(region) ? audit_record::MEDIA_ROM : audit_record::MEDIA_DISK;
					audit_record &record = m_record_list.append(*global_alloc(audit_record(*rom, tp)));
					record.set_shared_device(shared_device);
					compute_status(record, rom, false);
				}
				continue;
			}

			for (const rom_entry *rom = rom_first_file(region); rom; rom = rom_next_file(rom))
			{
				const char *name = ROM_GETNAME(rom);
				hash_collection hashes(ROM_GETHASHDATA(rom));
				device_t *shared_device = find_shared_device(device, name, hashes, ROM_GETLENGTH(rom));

				// count the number of files with hashes
				if (!hashes.flag(hash_collection::FLAG_NO_DUMP) && !ROM_ISOPTIONAL(rom))
				{
					required++;
					if (shared_device != nullptr)
						shared_required++;
				}

				// audit a file
				audit_record *record = nullptr;
				if (ROMREGION_ISROMDATA(region))
					record = audit_one_rom(rom);

				// audit a disk
				else if (ROMREGION_ISDISKDATA(region))
					record = audit_one_disk(rom);

				if (record != nullptr)
				{
					// count the number of files that are found.
					if (record->status() == audit_record::STATUS_GOOD || (record->status() == audit_record::STATUS_FOUND_INVALID && find_shared_device(device, name, record->actual_hashes(), record->actual_length()) == nullptr))
					{
						found++;
						if (shared_device != nullptr)
							shared_found++;
					}

					record->set_shared_device(shared_device);
				}
			}
		}
	}

	// if we only find files that are in the parent & either the set has no unique files or the parent is not found, then assume we don't have the set at all
	if (found == shared_found && required > 0 && (required != shared_required || shared_found == 0))
	{
		m_record_list.reset();
		return NOTFOUND;
	}

	// return a summary
	return summarize(m_enumerator.driver().name);
}


//-------------------------------------------------
//  audit_device - audit the device
//-------------------------------------------------

media_auditor::summary media_auditor::audit_device(device_t &device, const char *validation)
{
	// start fresh
	m_record_list.reset();

	// store validation for later
	m_validation = validation;
	m_searchpath = device.shortname();

	int found = 0;
	int required = 0;

	// now iterate over regions and ROMs within
	for (const rom_entry *region = rom_first_region(device); region != nullptr; region = rom_next_region(region))
	{
		for (const rom_entry *rom = rom_first_file(region); rom; rom = rom_next_file(rom))
		{
			hash_collection hashes(ROM_GETHASHDATA(rom));

			// count the number of files with hashes
			if (!hashes.flag(hash_collection::FLAG_NO_DUMP) && !ROM_ISOPTIONAL(rom))
			{
				required++;
			}

			// audit a file
			audit_record *record = nullptr;
			if (ROMREGION_ISROMDATA(region))
				record = audit_one_rom(rom);

			// audit a disk
			else if (ROMREGION_ISDISKDATA(region))
				record = audit_one_disk(rom);

			// count the number of files that are found.
			if (record != nullptr && (record->status() == audit_record::STATUS_GOOD || record->status() == audit_record::STATUS_FOUND_INVALID))
			{
				found++;
			}
		}
	}

	if (found == 0 && required > 0)
	{
		m_record_list.reset();
		return NOTFOUND;
	}

	// return a summary
	return summarize(device.shortname());
}


//-------------------------------------------------
//  audit_software
//-------------------------------------------------
media_auditor::summary media_auditor::audit_software(const char *list_name, software_info *swinfo, const char *validation)
{
	// start fresh
	m_record_list.reset();

	// store validation for later
	m_validation = validation;

	std::string combinedpath(swinfo->shortname());
	combinedpath.append(";");
	combinedpath.append(list_name);
	combinedpath.append(PATH_SEPARATOR);
	combinedpath.append(swinfo->shortname());
	std::string locationtag(list_name);
	locationtag.append("%");
	locationtag.append(swinfo->shortname());
	locationtag.append("%");
	if (swinfo->parentname() != nullptr)
	{
		locationtag.append(swinfo->parentname());
		combinedpath.append(";").append(swinfo->parentname()).append(";").append(list_name).append(PATH_SEPARATOR).append(swinfo->parentname());
	}
	m_searchpath = combinedpath.c_str();

	int found = 0;
	int required = 0;

	// now iterate over software parts
	for (software_part &part : swinfo->parts())
	{
		// now iterate over regions
		for ( const rom_entry *region = part.romdata(); region; region = rom_next_region( region ) )
		{
			// now iterate over rom definitions
			for (const rom_entry *rom = rom_first_file(region); rom; rom = rom_next_file(rom))
			{
				hash_collection hashes(ROM_GETHASHDATA(rom));

				// count the number of files with hashes
				if (!hashes.flag(hash_collection::FLAG_NO_DUMP) && !ROM_ISOPTIONAL(rom))
				{
					required++;
				}

				// audit a file
				audit_record *record = nullptr;
				if (ROMREGION_ISROMDATA(region))
				{
					record = audit_one_rom(rom);
				}
				// audit a disk
				else if (ROMREGION_ISDISKDATA(region))
				{
					record = audit_one_disk(rom, locationtag.c_str());
				}

				// count the number of files that are found.
				if (record != nullptr && (record->status() == audit_record::STATUS_GOOD || record->status() == audit_record::STATUS_FOUND_INVALID))
				{
					found++;
				}
			}
		}
	}

	if (found == 0 && required > 0)
	{
		m_record_list.reset();
		return NOTFOUND;
	}

	// return a summary
	return summarize(list_name);
}


//-------------------------------------------------
//  audit_samples - validate the samples for the
//  currently-enumerated driver
//-------------------------------------------------

media_auditor::summary media_auditor::audit_samples()
{
	// start fresh
	m_record_list.reset();

	int required = 0;
	int found = 0;

	// iterate over sample entries
	for (samples_device &device : samples_device_iterator(m_enumerator.config().root_device()))
	{
		// by default we just search using the driver name
		std::set<std::string> pathset;
		std::set<std::string> invalid_pathset;
		check_archive(m_enumerator.options().sample_path(), m_enumerator.driver().name, pathset, invalid_pathset);

		// add the alternate path if present
		samples_iterator iter(device);
		if (iter.altbasename() != nullptr)
			check_archive(m_enumerator.options().sample_path(), iter.altbasename(), pathset, invalid_pathset);

		if (pathset.empty())
		{
			for (const char *samplename = iter.first(); samplename != nullptr; samplename = iter.next())
			{
				++required;
				audit_record &record = m_record_list.append(*global_alloc(audit_record(samplename, audit_record::MEDIA_SAMPLE)));
				record.set_status(audit_record::STATUS_NOT_FOUND, audit_record::SUBSTATUS_NOT_FOUND);
			}
			continue;
		}

		std::string searchpath = *pathset.begin();
		for (std::set<std::string>::iterator _iter = ++pathset.begin(); _iter != pathset.end(); ++_iter)
			searchpath += ";" + *_iter;

		// iterate over samples in this entry
		for (const char *samplename = iter.first(); samplename != nullptr; samplename = iter.next())
		{
			required++;

			// create a new record
			audit_record &record = m_record_list.append(*global_alloc(audit_record(samplename, audit_record::MEDIA_SAMPLE)));

			// look for the files
			emu_file file(m_enumerator.options().sample_path(), OPEN_FLAG_READ | OPEN_FLAG_NO_PRELOAD);
			path_iterator path(searchpath.c_str());
			std::string curpath;
			while (path.next(curpath, samplename))
			{
				// attempt to access the file (.flac) or (.wav)
				osd_file::error filerr = file.open(curpath.c_str(), ".flac");
				if (filerr != osd_file::error::NONE)
					filerr = file.open(curpath.c_str(), ".wav");

				if (filerr == osd_file::error::NONE)
				{
					record.set_status(audit_record::STATUS_GOOD, audit_record::SUBSTATUS_GOOD);
					found++;
				}
				else
					record.set_status(audit_record::STATUS_NOT_FOUND, audit_record::SUBSTATUS_NOT_FOUND);
			}
		}
	}

	if (found == 0 && required > 0)
	{
		m_record_list.reset();
		return NOTFOUND;
	}

	// return a summary
	return summarize(m_enumerator.driver().name);
}


//-------------------------------------------------
//  summary - generate a summary, with an optional
//  string format
//-------------------------------------------------

media_auditor::summary media_auditor::summarize(const char *name, std::string *output)
{
	if (m_record_list.count() == 0)
	{
		return NONE_NEEDED;
	}

	// loop over records
	summary overall_status = CORRECT;
	for (audit_record &record : m_record_list)
	{
		summary best_new_status = INCORRECT;

		// skip anything that's fine
		if (record.substatus() == audit_record::SUBSTATUS_GOOD)
			continue;

		// output the game name, file name, and length (if applicable)
		if (output != nullptr)
		{
			output->append(string_format("%-12s: %s", name, record.name()));
			if (record.expected_length() > 0)
				output->append(string_format(" (%d bytes)", record.expected_length()));
			output->append(" - ");
		}

		// use the substatus for finer details
		switch (record.substatus())
		{
			case audit_record::SUBSTATUS_GOOD_NEEDS_REDUMP:
				if (output != nullptr) output->append("NEEDS REDUMP\n");
				best_new_status = BEST_AVAILABLE;
				break;

			case audit_record::SUBSTATUS_FOUND_NODUMP:
				if (output != nullptr) output->append("NO GOOD DUMP KNOWN\n");
				best_new_status = BEST_AVAILABLE;
				break;

			case audit_record::SUBSTATUS_FOUND_BAD_CHECKSUM:
				if (output != nullptr)
				{
					output->append("INCORRECT CHECKSUM:\n");
					output->append(string_format("EXPECTED: %s\n", record.expected_hashes().macro_string().c_str()));
					output->append(string_format("   FOUND: %s\n", record.actual_hashes().macro_string().c_str()));
				}
				break;

			case audit_record::SUBSTATUS_FOUND_WRONG_LENGTH:
				if (output != nullptr) output->append(string_format("INCORRECT LENGTH: %d bytes\n", record.actual_length()));
				break;

			case audit_record::SUBSTATUS_NOT_FOUND:
				if (output != nullptr)
				{
					device_t *shared_device = record.shared_device();
					if (shared_device == nullptr)
						output->append("NOT FOUND\n");
					else
						output->append(string_format("NOT FOUND (%s)\n", shared_device->shortname()));
				}
				break;

			case audit_record::SUBSTATUS_NOT_FOUND_NODUMP:
				if (output != nullptr) output->append("NOT FOUND - NO GOOD DUMP KNOWN\n");
				best_new_status = BEST_AVAILABLE;
				break;

			case audit_record::SUBSTATUS_NOT_FOUND_OPTIONAL:
				if (output != nullptr) output->append("NOT FOUND BUT OPTIONAL\n");
				best_new_status = BEST_AVAILABLE;
				break;

			default:
				assert(false);
		}

		// downgrade the overall status if necessary
		overall_status = MAX(overall_status, best_new_status);
	}
	return overall_status;
}

// WINUI - only report problems that the user can fix
media_auditor::summary media_auditor::winui_summarize(const char *name, std::string *output)
{
	if (m_record_list.count() == 0)
	{
		return NONE_NEEDED;
	}

	// loop over records
	summary overall_status = CORRECT;
	for (audit_record *record = m_record_list.first(); record; record = record->next())
	{
		summary best_new_status = INCORRECT;

		// skip anything that's fine
		if ( (record->substatus() == audit_record::SUBSTATUS_GOOD)
			|| (record->substatus() == audit_record::SUBSTATUS_GOOD_NEEDS_REDUMP)
			|| (record->substatus() == audit_record::SUBSTATUS_NOT_FOUND_NODUMP)
			|| (record->substatus() == audit_record::SUBSTATUS_FOUND_NODUMP)
			)
			continue;

		// output the game name, file name, and length (if applicable)
		if (output)
		{
			output->append(string_format("%-12s: %s", name, record->name()));
			if (record->expected_length() > 0)
				output->append(string_format(" (%d bytes)", record->expected_length()));
			output->append(" - ");
		}

		// use the substatus for finer details
		switch (record->substatus())
		{
			case audit_record::SUBSTATUS_GOOD_NEEDS_REDUMP:
				if (output) output->append("NEEDS REDUMP\n");
				best_new_status = BEST_AVAILABLE;
				break;

			//case audit_record::SUBSTATUS_FOUND_NODUMP:
			//	if (output) output->append("NO GOOD DUMP KNOWN\n");
			//	best_new_status = BEST_AVAILABLE;
			//	break;

			case audit_record::SUBSTATUS_FOUND_BAD_CHECKSUM:
				if (output)
				{
					output->append("INCORRECT CHECKSUM:\n");
					output->append(string_format("EXPECTED: %s\n", record->expected_hashes().macro_string().c_str()));
					output->append(string_format("   FOUND: %s\n", record->actual_hashes().macro_string().c_str()));
				}
				break;

			case audit_record::SUBSTATUS_FOUND_WRONG_LENGTH:
				if (output) output->append(string_format("INCORRECT LENGTH: %d bytes\n", record->actual_length()));
				break;

			case audit_record::SUBSTATUS_NOT_FOUND:
				if (output)
				{
					device_t *shared_device = record->shared_device();
					if (shared_device)
						output->append(string_format("NOT FOUND (%s)\n", shared_device->shortname()));
					else
						output->append("NOT FOUND\n");
				}
				best_new_status = NOTFOUND;
				break;

			//case audit_record::SUBSTATUS_NOT_FOUND_NODUMP:
			//	if (output) output->append("NOT FOUND - NO GOOD DUMP KNOWN\n");
			//	best_new_status = BEST_AVAILABLE;
			//	break;

			case audit_record::SUBSTATUS_NOT_FOUND_OPTIONAL:
				if (output) output->append("NOT FOUND BUT OPTIONAL\n");
				best_new_status = BEST_AVAILABLE;
				break;

			default:
				break;
		}

		// downgrade the overall status if necessary
		overall_status = MAX(overall_status, best_new_status);
	}
	return overall_status;
}

//-------------------------------------------------
//  audit_one_rom - validate a single ROM entry
//-------------------------------------------------

audit_record *media_auditor::audit_one_rom(const rom_entry *rom)
{
	// allocate and append a new record
	audit_record &record = m_record_list.append(*global_alloc(audit_record(*rom, audit_record::MEDIA_ROM)));

	// see if we have a CRC and extract it if so
	UINT32 crc = 0;
	bool has_crc = record.expected_hashes().crc(crc);

	// find the file and checksum it, getting the file length along the way
	emu_file file(m_enumerator.options().media_path(), OPEN_FLAG_READ | OPEN_FLAG_NO_PRELOAD);
	file.set_restrict_to_mediapath(true);
	path_iterator path(m_searchpath);
	std::string curpath;
	while (path.next(curpath, record.name()))
	{
		// open the file if we can
		osd_file::error filerr;
		if (has_crc)
			filerr = file.open(curpath.c_str(), crc);
		else
			filerr = file.open(curpath.c_str());

		// if it worked, get the actual length and hashes, then stop
		if (filerr == osd_file::error::NONE)
		{
			record.set_actual(file.hashes(m_validation), file.size());
			break;
		}
	}

	// compute the final status
	compute_status(record, rom, record.actual_length() != 0);
	return &record;
}


//-------------------------------------------------
//  audit_one_disk - validate a single disk entry
//-------------------------------------------------

audit_record *media_auditor::audit_one_disk(const rom_entry *rom, const char *locationtag)
{
	// allocate and append a new record
	audit_record &record = m_record_list.append(*global_alloc(audit_record(*rom, audit_record::MEDIA_DISK)));

	// open the disk
	chd_file source;
	chd_error err = chd_error(open_disk_image(m_enumerator.options(), &m_enumerator.driver(), rom, source, locationtag));

	// if we succeeded, get the hashes
	if (err == CHDERR_NONE)
	{
		hash_collection hashes;

		// if there's a SHA1 hash, add them to the output hash
		if (source.sha1() != sha1_t::null)
			hashes.add_sha1(source.sha1());

		// update the actual values
		record.set_actual(hashes);
	}

	// compute the final status
	compute_status(record, rom, err == CHDERR_NONE);
	return &record;
}


//-------------------------------------------------
//  compute_status - compute a detailed status
//  based on the information we have
//-------------------------------------------------

void media_auditor::compute_status(audit_record &record, const rom_entry *rom, bool found)
{
	// if not found, provide more details
	if (!found)
	{
		// no good dump
		if (record.expected_hashes().flag(hash_collection::FLAG_NO_DUMP))
			record.set_status(audit_record::STATUS_NOT_FOUND, audit_record::SUBSTATUS_NOT_FOUND_NODUMP);

		// optional ROM
		else if (ROM_ISOPTIONAL(rom))
			record.set_status(audit_record::STATUS_NOT_FOUND, audit_record::SUBSTATUS_NOT_FOUND_OPTIONAL);

		// just plain old not found
		else
			record.set_status(audit_record::STATUS_NOT_FOUND, audit_record::SUBSTATUS_NOT_FOUND);
	}

	// if found, provide more details
	else
	{
		// length mismatch
		if (record.expected_length() != record.actual_length())
			record.set_status(audit_record::STATUS_FOUND_INVALID, audit_record::SUBSTATUS_FOUND_WRONG_LENGTH);

		// found but needs a dump
		else if (record.expected_hashes().flag(hash_collection::FLAG_NO_DUMP))
			record.set_status(audit_record::STATUS_GOOD, audit_record::SUBSTATUS_FOUND_NODUMP);

		// incorrect hash
		else if (record.expected_hashes() != record.actual_hashes())
			record.set_status(audit_record::STATUS_FOUND_INVALID, audit_record::SUBSTATUS_FOUND_BAD_CHECKSUM);

		// correct hash but needs a redump
		else if (record.expected_hashes().flag(hash_collection::FLAG_BAD_DUMP))
			record.set_status(audit_record::STATUS_GOOD, audit_record::SUBSTATUS_GOOD_NEEDS_REDUMP);

		// just plain old good
		else
			record.set_status(audit_record::STATUS_GOOD, audit_record::SUBSTATUS_GOOD);
	}
}


//-------------------------------------------------
//  find_shared_device - return the source that
//  shares a media entry with the same hashes
//-------------------------------------------------

device_t *media_auditor::find_shared_device(device_t &device, const char *name, const hash_collection &romhashes, UINT64 romlength)
{
	bool dumped = !romhashes.flag(hash_collection::FLAG_NO_DUMP);

	// special case for non-root devices
	device_t *highest_device = nullptr;
	if (device.owner() != nullptr)
	{
		for (const rom_entry *region = rom_first_region(device); region != nullptr; region = rom_next_region(region))
			for (const rom_entry *rom = rom_first_file(region); rom != nullptr; rom = rom_next_file(rom))
				if (ROM_GETLENGTH(rom) == romlength)
				{
					hash_collection hashes(ROM_GETHASHDATA(rom));
					if ((dumped && hashes == romhashes) || (!dumped && ROM_GETNAME(rom) == name))
						highest_device = &device;
				}
	}
	else
	{
		// iterate up the parent chain
		for (int drvindex = m_enumerator.find(m_enumerator.driver().parent); drvindex != -1; drvindex = m_enumerator.find(m_enumerator.driver(drvindex).parent))
		{
			for (device_t &scandevice : device_iterator(m_enumerator.config(drvindex).root_device()))
				for (const rom_entry *region = rom_first_region(scandevice); region; region = rom_next_region(region))
					for (const rom_entry *rom = rom_first_file(region); rom; rom = rom_next_file(rom))
						if (ROM_GETLENGTH(rom) == romlength)
						{
							hash_collection hashes(ROM_GETHASHDATA(rom));
							if ((dumped && hashes == romhashes) || (!dumped && ROM_GETNAME(rom) == name))
								highest_device = &scandevice;
						}
		}
	}

	return highest_device;
}


//-------------------------------------------------
//  audit_record - constructor
//-------------------------------------------------

audit_record::audit_record(const rom_entry &media, media_type type)
	: m_next(nullptr),
		m_type(type),
		m_status(STATUS_ERROR),
		m_substatus(SUBSTATUS_ERROR),
		m_name(ROM_GETNAME(&media)),
		m_explength(rom_file_size(&media)),
		m_length(0),
		m_shared_device(nullptr)
{
	m_exphashes.from_internal_string(ROM_GETHASHDATA(&media));
}

audit_record::audit_record(const char *name, media_type type)
	: m_next(nullptr),
		m_type(type),
		m_status(STATUS_ERROR),
		m_substatus(SUBSTATUS_ERROR),
		m_name(name),
		m_explength(0),
		m_length(0),
		m_shared_device(nullptr)
{
}

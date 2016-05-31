-- license:BSD-3-Clause
-- copyright-holders:MAMEdev Team

---------------------------------------------------------------------------
--
--   ncp.lua: Neogeo,CPS,PGM
--
--   MAME target makefile
--
---------------------------------------------------------------------------

--------------------------------------------------
-- specify available CPU cores
---------------------------------------------------

CPUS["Z80"] = true
CPUS["Z180"] = true
CPUS["I8085"] = true
CPUS["I8089"] = true
CPUS["M6502"] = true
CPUS["H6280"] = true
CPUS["I86"] = true
CPUS["I386"] = true
CPUS["NEC"] = true
CPUS["V30MZ"] = true
CPUS["V60"] = true
CPUS["MCS48"] = true
CPUS["MCS51"] = true
CPUS["MCS96"] = true
CPUS["M6800"] = true
CPUS["M6805"] = true
CPUS["HD6309"] = true
CPUS["M6809"] = true
CPUS["KONAMI"] = true
CPUS["M680X0"] = true
CPUS["T11"] = true
CPUS["S2650"] = true
CPUS["TMS340X0"] = true
CPUS["TMS9900"] = true
CPUS["TMS9995"] = true
CPUS["TMS9900L"] = true
CPUS["Z8000"] = true
CPUS["Z8001"] = true
CPUS["TMS32010"] = true
CPUS["TMS32025"] = true
CPUS["TMS32031"] = true
CPUS["TMS32051"] = true
CPUS["TMS32082"] = true
CPUS["TMS57002"] = true
CPUS["CCPU"] = true
CPUS["ADSP21XX"] = true
CPUS["ASAP"] = true
CPUS["AM29000"] = true
CPUS["UPD7810"] = true
CPUS["ARM"] = true
CPUS["ARM7"] = true
CPUS["JAGUAR"] = true
CPUS["CUBEQCPU"] = true
CPUS["ESRIP"] = true
CPUS["MIPS"] = true
CPUS["R3000"] = true
CPUS["PSX"] = true
CPUS["SH2"] = true
CPUS["SH4"] = true
CPUS["DSP16A"] = true
CPUS["DSP32C"] = true
CPUS["PIC16C5X"] = true
CPUS["PIC16C62X"] = true
CPUS["G65816"] = true
CPUS["SPC700"] = true
CPUS["E1"] = true
CPUS["I860"] = true
CPUS["I960"] = true
CPUS["H8"] = true
CPUS["V810"] = true
CPUS["M37710"] = true
CPUS["POWERPC"] = true
CPUS["SE3208"] = true
CPUS["MC68HC11"] = true
CPUS["ADSP21062"] = true
CPUS["DSP56156"] = true
CPUS["RSP"] = true
CPUS["ALPHA8201"] = true
CPUS["COP400"] = true
CPUS["TLCS90"] = true
CPUS["TLCS900"] = true
CPUS["MB88XX"] = true
CPUS["MB86233"] = true
CPUS["MB86235"] = true
CPUS["SSP1601"] = true
CPUS["APEXC"] = true
CPUS["CP1610"] = true
CPUS["F8"] = true
CPUS["LH5801"] = true
CPUS["PDP1"] = true
CPUS["SATURN"] = true
CPUS["SC61860"] = true
CPUS["LR35902"] = true
CPUS["TMS7000"] = true
CPUS["SM8500"] = true
CPUS["MINX"] = true
CPUS["SSEM"] = true
CPUS["AVR8"] = true
--CPUS["TMS1000"] = true
CPUS["I4004"] = true
CPUS["SUPERFX"] = true
CPUS["Z8"] = true
CPUS["I8008"] = true
CPUS["SCMP"] = true
CPUS["MN10200"] = true
CPUS["COSMAC"] = true
CPUS["UNSP"] = true
CPUS["HCD62121"] = true
CPUS["PPS4"] = true
CPUS["UPD7725"] = true
CPUS["HD61700"] = true
CPUS["LC8670"] = true
CPUS["SCORE"] = true
CPUS["ES5510"] = true
CPUS["SCUDSP"] = true
CPUS["IE15"] = true
CPUS["8X300"] = true
CPUS["ALTO2"] = true
--CPUS["W65816"] = true
CPUS["ARC"] = true
CPUS["ARCOMPACT"] = true
--CPUS["AMIS2000"] = true
--CPUS["UCOM4"] = true
CPUS["HMCS40"] = true
--CPUS["E0C6200"] = true
--CPUS["MELPS4"] = true
--CPUS["HPHYBRID"] = true
--CPUS["SM510"] = true

--------------------------------------------------
-- specify available sound cores
--------------------------------------------------

SOUNDS["SAMPLES"] = true
SOUNDS["DAC"] = true
SOUNDS["DMADAC"] = true
SOUNDS["SPEAKER"] = true
SOUNDS["BEEP"] = true
SOUNDS["DISCRETE"] = true
SOUNDS["AY8910"] = true
SOUNDS["YM2151"] = true
SOUNDS["YM2203"] = true
SOUNDS["YM2413"] = true
SOUNDS["YM2608"] = true
SOUNDS["YM2610"] = true
SOUNDS["YM2610B"] = true
SOUNDS["YM2612"] = true
SOUNDS["YM3438"] = true
SOUNDS["YM3812"] = true
SOUNDS["YM3526"] = true
SOUNDS["Y8950"] = true
SOUNDS["YMF262"] = true
SOUNDS["YMF271"] = true
SOUNDS["YMF278B"] = true
SOUNDS["YMZ280B"] = true
SOUNDS["SN76477"] = true
SOUNDS["SN76496"] = true
SOUNDS["POKEY"] = true
SOUNDS["TIA"] = true
SOUNDS["NES_APU"] = true
SOUNDS["AMIGA"] = true
SOUNDS["ASTROCADE"] = true
SOUNDS["NAMCO"] = true
SOUNDS["NAMCO_15XX"] = true
SOUNDS["NAMCO_CUS30"] = true
SOUNDS["NAMCO_52XX"] = true
SOUNDS["NAMCO_63701X"] = true
SOUNDS["T6W28"] = true
SOUNDS["SNKWAVE"] = true
SOUNDS["C140"] = true
SOUNDS["C352"] = true
SOUNDS["TMS36XX"] = true
SOUNDS["TMS3615"] = true
SOUNDS["TMS5110"] = true
SOUNDS["TMS5220"] = true
SOUNDS["VLM5030"] = true
SOUNDS["ADPCM"] = true
SOUNDS["MSM5205"] = true
SOUNDS["MSM5232"] = true
SOUNDS["OKIM6258"] = true
SOUNDS["OKIM6295"] = true
SOUNDS["OKIM6376"] = true
SOUNDS["OKIM9810"] = true
--SOUNDS["UPD7752"] = true
SOUNDS["UPD7759"] = true
SOUNDS["HC55516"] = true
SOUNDS["TC8830F"] = true
SOUNDS["K005289"] = true
SOUNDS["K007232"] = true
SOUNDS["K051649"] = true
SOUNDS["K053260"] = true
SOUNDS["K054539"] = true
SOUNDS["K056800"] = true
SOUNDS["SEGAPCM"] = true
SOUNDS["MULTIPCM"] = true
SOUNDS["SCSP"] = true
SOUNDS["AICA"] = true
SOUNDS["RF5C68"] = true
SOUNDS["RF5C400"] = true
SOUNDS["CEM3394"] = true
SOUNDS["QSOUND"] = true
SOUNDS["QS1000"] = true
SOUNDS["SAA1099"] = true
SOUNDS["IREMGA20"] = true
SOUNDS["ES5503"] = true
SOUNDS["ES5505"] = true
SOUNDS["ES5506"] = true
SOUNDS["BSMT2000"] = true
SOUNDS["GAELCO_CG1V"] = true
SOUNDS["GAELCO_GAE1"] = true
SOUNDS["C6280"] = true
SOUNDS["SP0250"] = true
SOUNDS["SPU"] = true
SOUNDS["CDDA"] = true
SOUNDS["ICS2115"] = true
SOUNDS["I5000_SND"] = true
SOUNDS["ST0016"] = true
SOUNDS["NILE"] = true
SOUNDS["X1_010"] = true
SOUNDS["VRENDER0"] = true
SOUNDS["VOTRAX"] = true
SOUNDS["ES8712"] = true
SOUNDS["CDP1869"] = true
SOUNDS["S14001A"] = true
SOUNDS["WAVE"] = true
SOUNDS["SID6581"] = true
SOUNDS["SID8580"] = true
SOUNDS["SP0256"] = true
SOUNDS["DIGITALKER"] = true
SOUNDS["CDP1863"] = true
SOUNDS["CDP1864"] = true
SOUNDS["ZSG2"] = true
SOUNDS["MOS656X"] = true
SOUNDS["ASC"] = true
SOUNDS["MAS3507D"] = true
SOUNDS["SOCRATES"] = true
SOUNDS["TMC0285"] = true
SOUNDS["TMS5200"] = true
SOUNDS["CD2801"] = true
SOUNDS["CD2802"] = true
SOUNDS["M58817"] = true
SOUNDS["TMC0281"] = true
SOUNDS["TMS5100"] = true
SOUNDS["TMS5110A"] = true
SOUNDS["LMC1992"] = true
SOUNDS["AWACS"] = true
SOUNDS["YMZ770"] = true
SOUNDS["MPEG_AUDIO"] = true
SOUNDS["T6721A"] = true
SOUNDS["MOS7360"] = true
--SOUNDS["ESQPUMP"] = true
--SOUNDS["VRC6"] = true
SOUNDS["SB0400"] = true
SOUNDS["AC97"] = true
SOUNDS["ES1373"] = true
SOUNDS["L7A1045"] = true
SOUNDS["AD1848"] = true
--SOUNDS["UPD1771"] = true

--------------------------------------------------
-- specify available video cores
--------------------------------------------------

VIDEOS["SEGA315_5124"] = true
VIDEOS["SEGA315_5313"] = true
VIDEOS["BUFSPRITE"] = true
--VIDEOS["CDP1861"] = true
--VIDEOS["CDP1862"] = true
--VIDEOS["CRT9007"] = true
--VIDEOS["CRT9021"] = true
--VIDEOS["CRT9212"] = true
--VIDEOS["CRTC_EGA"] = true
--VIDEOS["DL1416"] = true
VIDEOS["DM9368"] = true
--VIDEOS["EF9340_1"] = true
--VIDEOS["EF9345"] = true
--VIDEOS["EF9364"] = true
--VIDEOS["EF9365"] = true
--VIDEOS["GF4500"] = true
VIDEOS["GF7600GS"] = true
VIDEOS["EPIC12"] = true
VIDEOS["FIXFREQ"] = true
--VIDEOS["HD44102"] = true
--VIDEOS["HD44352"] = true
VIDEOS["HD44780"] = true
VIDEOS["HD61830"] = true
VIDEOS["HD63484"] = true
--VIDEOS["HD66421"] = true
VIDEOS["HUC6202"] = true
VIDEOS["HUC6260"] = true
--VIDEOS["HUC6261"] = true
VIDEOS["HUC6270"] = true
--VIDEOS["HUC6272"] = true
--VIDEOS["I8244"] = true
VIDEOS["I8275"] = true
VIDEOS["JANGOU_BLITTER"] = true
VIDEOS["M50458"] = true
VIDEOS["MB90082"] = true
VIDEOS["MB_VCU"] = true
VIDEOS["MC6845"] = true
--VIDEOS["MC6847"] = true
--VIDEOS["MSM6222B"] = true
--VIDEOS["MSM6255"] = true
--VIDEOS["MOS6566"] = true
VIDEOS["PC_VGA"] = true
VIDEOS["POLY"] = true
VIDEOS["PSX"] = true
VIDEOS["RAMDAC"] = true
--VIDEOS["S2636"] = true
VIDEOS["SAA5050"] = true
VIDEOS["SCN2674"] = true
--VIDEOS["SED1200"] = true
--VIDEOS["SED1330"] = true
--VIDEOS["SED1520"] = true
VIDEOS["SNES_PPU"] = true
VIDEOS["STVVDP"] = true
--VIDEOS["T6A04"] = true
VIDEOS["TLC34076"] = true
VIDEOS["TMS34061"] = true
--VIDEOS["TMS3556"] = true
VIDEOS["TMS9927"] = true
VIDEOS["TMS9928A"] = true
--VIDEOS["UPD3301"] = true
--VIDEOS["UPD7220"] = true
--VIDEOS["UPD7227"] = true
VIDEOS["V9938"] = true
--VIDEOS["VIC4567"] = true
VIDEOS["VOODOO"] = true
VIDEOS["VOODOO_PCI"] = true

--------------------------------------------------
-- specify available machine cores
--------------------------------------------------

MACHINES["AKIKO"] = true
MACHINES["NCR53C7XX"] = true
MACHINES["LSI53C810"] = true
MACHINES["6522VIA"] = true
MACHINES["TPI6525"] = true
MACHINES["RIOT6532"] = true
MACHINES["6821PIA"] = true
MACHINES["6840PTM"] = true
--MACHINES["68561MPCC"] = true
MACHINES["ACIA6850"] = true
MACHINES["68681"] = true
MACHINES["7200FIFO"] = true
--MACHINES["8530SCC"] = true
MACHINES["TTL74123"] = true
MACHINES["TTL74145"] = true
MACHINES["TTL74148"] = true
MACHINES["TTL74153"] = true
MACHINES["TTL74181"] = true
MACHINES["TTL7474"] = true
MACHINES["KBDC8042"] = true
MACHINES["I8257"] = true
MACHINES["AAKARTDEV"] = true
--MACHINES["ACIA6850"] = true
MACHINES["ADC0808"] = true
MACHINES["ADC083X"] = true
MACHINES["ADC1038"] = true
MACHINES["ADC1213X"] = true
MACHINES["AICARTC"] = true
MACHINES["AM53CF96"] = true
MACHINES["AM9517A"] = true
MACHINES["AMIGAFDC"] = true
--MACHINES["AT_KEYBC"] = true
MACHINES["AT28C16"] = true
MACHINES["AT29X"] = true
MACHINES["AT45DBXX"] = true
MACHINES["ATAFLASH"] = true
MACHINES["AY31015"] = true
MACHINES["BANKDEV"] = true
MACHINES["CDP1852"] = true
MACHINES["CDP1871"] = true
--MACHINES["CMOS40105"] = true
MACHINES["CDU76S"] = true
MACHINES["COM8116"] = true
MACHINES["CR589"] = true
--MACHINES["CS4031"] = true
--MACHINES["CS8221"] = true
--MACHINES["DP8390"] = true
MACHINES["DS1204"] = true
MACHINES["DS1302"] = true
--MACHINES["DS1315"] = true
MACHINES["DS2401"] = true
MACHINES["DS2404"] = true
MACHINES["DS75160A"] = true
MACHINES["DS75161A"] = true
MACHINES["E0516"] = true
MACHINES["E05A03"] = true
MACHINES["E05A30"] = true
MACHINES["EEPROMDEV"] = true
MACHINES["ER2055"] = true
MACHINES["F3853"] = true
--MACHINES["HD63450"] = true
--MACHINES["HD64610"] = true
MACHINES["I2CMEM"] = true
--MACHINES["I80130"] = true
--MACHINES["I8089"] = true
MACHINES["I8155"] = true
MACHINES["I8212"] = true
MACHINES["I8214"] = true
MACHINES["I8243"] = true
MACHINES["I8251"] = true
MACHINES["I8255"] = true
--MACHINES["I8257"] = true
--MACHINES["I8271"] = true
MACHINES["I8279"] = true
MACHINES["I8355"] = true
MACHINES["IDE"] = true
MACHINES["IM6402"] = true
MACHINES["INS8154"] = true
MACHINES["INS8250"] = true
MACHINES["INTELFLASH"] = true
MACHINES["JVS"] = true
MACHINES["K033906"] = true
MACHINES["K053252"] = true
MACHINES["K056230"] = true
--MACHINES["KB3600"] = true
--MACHINES["KBDC8042"] = true
--MACHINES["KR2376"] = true
MACHINES["LATCH8"] = true
MACHINES["LC89510"] = true
MACHINES["LDPR8210"] = true
MACHINES["LDSTUB"] = true
MACHINES["LDV1000"] = true
MACHINES["LDVP931"] = true
--MACHINES["LH5810"] = true
MACHINES["LINFLASH"] = true
MACHINES["LPCI"] = true
--MACHINES["LSI53C810"] = true
--MACHINES["M68307"] = true
--MACHINES["M68340"] = true
MACHINES["M6M80011AP"] = true
MACHINES["MATSUCD"] = true
MACHINES["MB14241"] = true
MACHINES["MB3773"] = true
MACHINES["MB8421"] = true
MACHINES["MB87078"] = true
--MACHINES["MB8795"] = true
--MACHINES["MB89352"] = true
MACHINES["MB89371"] = true
MACHINES["MC146818"] = true
MACHINES["MC2661"] = true
MACHINES["MC6843"] = true
MACHINES["MC6846"] = true
MACHINES["MC6852"] = true
MACHINES["MC6854"] = true
--MACHINES["MC68328"] = true
MACHINES["MC68901"] = true
MACHINES["MCCS1850"] = true
MACHINES["M68307"] = true
MACHINES["M68340"] = true
MACHINES["MCF5206E"] = true
MACHINES["MICROTOUCH"] = true
--MACHINES["MIOT6530"] = true
--MACHINES["MM58167"] = true
MACHINES["MM58274C"] = true
MACHINES["MM74C922"] = true
MACHINES["MOS6526"] = true
MACHINES["MOS6529"] = true
MACHINES["MIOT6530"] = true
MACHINES["MOS6551"] = true
--MACHINES["MOS6702"] = true
--MACHINES["MOS8706"] = true
--MACHINES["MOS8722"] = true
--MACHINES["MOS8726"] = true
--MACHINES["MPU401"] = true
MACHINES["MSM5832"] = true
MACHINES["MSM58321"] = true
MACHINES["MSM6242"] = true
--MACHINES["NCR5380"] = true
--MACHINES["NCR5380N"] = true
--MACHINES["NCR5390"] = true
MACHINES["NCR539x"] = true
MACHINES["NETLIST"] = true
--MACHINES["NCR53C7XX"] = true
MACHINES["NMC9306"] = true
--MACHINES["NSC810"] = true
MACHINES["NSCSI"] = true
--MACHINES["PC_FDC"] = true
--MACHINES["PC_LPT"] = true
--MACHINES["PCCARD"] = true
MACHINES["PCF8593"] = true
MACHINES["PCI"] = true
MACHINES["PCKEYBRD"] = true
MACHINES["PIC8259"] = true
MACHINES["PIT8253"] = true
MACHINES["PLA"] = true
--MACHINES["PROFILE"] = true
MACHINES["R10696"] = true
MACHINES["R10788"] = true
MACHINES["RA17XX"] = true
--MACHINES["R64H156"] = true
MACHINES["RF5C296"] = true
--MACHINES["RIOT6532"] = true
MACHINES["ROC10937"] = true
MACHINES["RP5C01"] = true
MACHINES["RP5C15"] = true
MACHINES["RP5H01"] = true
MACHINES["RTC4543"] = true
MACHINES["RTC65271"] = true
MACHINES["RTC9701"] = true
MACHINES["S2636"] = true
MACHINES["S3520CF"] = true
MACHINES["S3C2400"] = true
MACHINES["S3C2410"] = true
MACHINES["S3C2440"] = true
--MACHINES["S3C44B0"] = true
MACHINES["SATURN"] = true
MACHINES["SCSI"] = true
MACHINES["SCUDSP"] = true
--MACHINES["SECFLASH"] = true
MACHINES["SERFLASH"] = true
MACHINES["SMC91C9X"] = true
MACHINES["SMPC"] = true
MACHINES["STVCD"] = true
MACHINES["TC0091LVC"] = true
MACHINES["TIMEKPR"] = true
MACHINES["TMP68301"] = true
--MACHINES["TMS5501"] = true
MACHINES["TMS6100"] = true
MACHINES["TMS9901"] = true
MACHINES["TMS9902"] = true
--MACHINES["TPI6525"] = true
--MACHINES["TTL74123"] = true
--MACHINES["TTL74145"] = true
--MACHINES["TTL74148"] = true
--MACHINES["TTL74153"] = true
--MACHINES["TTL74181"] = true
--MACHINES["TTL7474"] = true
MACHINES["UPD1990A"] = true
MACHINES["UPD4992"] = true
MACHINES["UPD4701"] = true
MACHINES["UPD7002"] = true
MACHINES["UPD71071"] = true
MACHINES["UPD765"] = true
MACHINES["FDC_PLL"] = true
MACHINES["V3021"] = true
MACHINES["WD_FDC"] = true
MACHINES["WD11C00_17"] = true
MACHINES["WD2010"] = true
MACHINES["WD33C93"] = true
MACHINES["X2212"] = true
MACHINES["X76F041"] = true
MACHINES["X76F100"] = true
MACHINES["Z80CTC"] = true
MACHINES["Z80DART"] = true
MACHINES["Z80DMA"] = true
MACHINES["Z80PIO"] = true
MACHINES["Z80STI"] = true
MACHINES["Z8536"] = true
MACHINES["SECFLASH"] = true
MACHINES["PCCARD"] = true
MACHINES["FDC37C665GT"] = true
--MACHINES["SMC92X4"] = true
--MACHINES["TI99_HD"] = true
--MACHINES["STRATA"] = true
MACHINES["STEPPERS"] = true
--MACHINES["CORVUSHD"] = true
--MACHINES["WOZFDC"] = true
--MACHINES["DIABLO_HD"] = true
MACHINES["PCI9050"] = true
--MACHINES["TMS1024"] = true
MACHINES["GENPC"] = true
MACHINES["GEN_LATCH"] = true
MACHINES["WATCHDOG"] = true

--------------------------------------------------
-- specify available bus cores
--------------------------------------------------

--BUSES["A1BUS"] = true
--BUSES["A2BUS"] = true
--BUSES["A7800"] = true
--BUSES["A800"] = true
--BUSES["ABCBUS"] = true
--BUSES["ABCKB"] = true
--BUSES["ADAM"] = true
--BUSES["ADAMNET"] = true
--BUSES["APF"] = true
--BUSES["ARCADIA"] = true
--BUSES["ASTROCADE"] = true
--BUSES["BML3"] = true
--BUSES["BW2"] = true
--BUSES["C64"] = true
--BUSES["CBM2"] = true
--BUSES["CBMIEC"] = true
BUSES["CENTRONICS"] = true
--BUSES["CHANNELF"] = true
--BUSES["COCO"] = true
--BUSES["COLECO"] = true
--BUSES["COMPUCOLOR"] = true
--BUSES["COMX35"] = true
--BUSES["CPC"] = true
--BUSES["CRVISION"] = true
--BUSES["DMV"] = true
--BUSES["ECBBUS"] = true
--BUSES["ECONET"] = true
--BUSES["EP64"] = true
--BUSES["EPSON_SIO"] = true
--BUSES["GAMEBOY"] = true
BUSES["GAMEGEAR"] = true
--BUSES["GBA"] = true
BUSES["GENERIC"] = true
--BUSES["IEEE488"] = true
--BUSES["IMI7000"] = true
--BUSES["INTV"] = true
--BUSES["IQ151"] = true
BUSES["ISA"] = true
--BUSES["ISBX"] = true
--BUSES["KC"] = true
--BUSES["LPCI"] = true
--BUSES["MACPDS"] = true
BUSES["MIDI"] = true
--BUSES["MEGADRIVE"] = true
--BUSES["MSX_SLOT"] = true
BUSES["NEOGEO"] = true
BUSES["NEOGEO_CTRL"] = true
--BUSES["NES"] = true
--BUSES["NUBUS"] = true
--BUSES["O2"] = true
--BUSES["ORICEXT"] = true
--BUSES["PCE"] = true
BUSES["PC_JOY"] = true
BUSES["PC_KBD"] = true
--BUSES["PET"] = true
--BUSES["PLUS4"] = true
--BUSES["PSX_CONTROLLER"] = true
--BUSES["QL"] = true
BUSES["RS232"] = true
--BUSES["S100"] = true
BUSES["SAT_CTRL"] = true
--BUSES["SATURN"] = true
BUSES["SCSI"] = true
--BUSES["SCV"] = true
BUSES["SEGA8"] = true
BUSES["SMS_CTRL"] = true
BUSES["SMS_EXP"] = true
--BUSES["SNES"] = true
--BUSES["SPC1000"] = true
--BUSES["TI99PEB"] = true
--BUSES["TVC"] = true
--BUSES["VBOY"] = true
--BUSES["VC4000"] = true
--BUSES["VCS"] = true
--BUSES["VCS_CTRL"] = true
BUSES["VECTREX"] = true
--BUSES["VIC10"] = true
--BUSES["VIC20"] = true
--BUSES["VIDBRAIN"] = true
--BUSES["VIP"] = true
--BUSES["VTECH_IOEXP"] = true
--BUSES["VTECH_MEMEXP"] = true
--BUSES["WANGPC"] = true
--BUSES["WSWAN"] = true
--BUSES["X68K"] = true
--BUSES["Z88"] = true
--BUSES["ZORRO"] = true

--------------------------------------------------
-- this is the list of driver libraries that
-- comprise MAME plus mamedriv.o which contains
-- the list of drivers
--------------------------------------------------

function linkProjects_mame_ncp(_target, _subtarget)
	links {
		"capcom",
		"igs",
		"neogeo",
		"psikyo",
		"snk",
		"technos",
		"toaplan",
		"misc",
		"shared",
	}
end

function createMAMEProjects(_target, _subtarget, _name)
	project (_name)
	targetsubdir(_target .."_" .. _subtarget)
	kind (LIBTYPE)
	uuid (os.uuid("drv-" .. _target .."_" .. _subtarget .. "_" .._name))
	addprojectflags()
	precompiledheaders()

	includedirs {
		MAME_DIR .. "src/osd",
		MAME_DIR .. "src/emu",
		MAME_DIR .. "src/devices",
		MAME_DIR .. "src/mame",
		MAME_DIR .. "src/lib",
		MAME_DIR .. "src/lib/util",
		MAME_DIR .. "src/lib/netlist",
		MAME_DIR .. "3rdparty",
		GEN_DIR  .. "mame/layout",
	}
	includedirs {
		ext_includedir("flac"),
	}

end

function createProjects_mame_ncp(_target, _subtarget)

--------------------------------------------------
-- the following files are general components and
-- shared across a number of drivers
--------------------------------------------------

createMAMEProjects(_target, _subtarget, "shared")
files {
	MAME_DIR .. "src/mame/machine/nmk112.cpp",
	MAME_DIR .. "src/mame/machine/nmk112.h",
	MAME_DIR .. "src/mame/machine/pcshare.cpp",
	MAME_DIR .. "src/mame/machine/pcshare.h",
	MAME_DIR .. "src/mame/machine/segacrpt_device.cpp",
	MAME_DIR .. "src/mame/machine/segacrpt_device.h",
	MAME_DIR .. "src/mame/machine/ticket.cpp",
	MAME_DIR .. "src/mame/machine/ticket.h",
	MAME_DIR .. "src/mame/video/avgdvg.cpp",
	MAME_DIR .. "src/mame/video/avgdvg.h",
	MAME_DIR .. "src/mame/audio/dcs.cpp",
	MAME_DIR .. "src/mame/audio/dcs.h",
	MAME_DIR .. "src/mame/audio/decobsmt.cpp",
	MAME_DIR .. "src/mame/audio/decobsmt.h",
	MAME_DIR .. "src/mame/audio/segam1audio.cpp",
	MAME_DIR .. "src/mame/audio/segam1audio.h",
}

--------------------------------------------------
-- manufacturer-specific groupings for drivers
--------------------------------------------------
createMAMEProjects(_target, _subtarget, "atlus")
files {
	MAME_DIR .. "src/mame/drivers/blmbycar.cpp",
	MAME_DIR .. "src/mame/includes/blmbycar.h",
	MAME_DIR .. "src/mame/video/blmbycar.cpp",
	MAME_DIR .. "src/mame/drivers/ohmygod.cpp",
	MAME_DIR .. "src/mame/includes/ohmygod.h",
	MAME_DIR .. "src/mame/video/ohmygod.cpp",
	MAME_DIR .. "src/mame/drivers/powerins.cpp",
	MAME_DIR .. "src/mame/includes/powerins.h",
	MAME_DIR .. "src/mame/video/powerins.cpp",
	MAME_DIR .. "src/mame/drivers/bowltry.cpp",
}

createMAMEProjects(_target, _subtarget, "capcom")
files {
	MAME_DIR .. "src/mame/drivers/1942.cpp",
	MAME_DIR .. "src/mame/includes/1942.h",
	MAME_DIR .. "src/mame/video/1942.cpp",
	MAME_DIR .. "src/mame/drivers/1943.cpp",
	MAME_DIR .. "src/mame/includes/1943.h",
	MAME_DIR .. "src/mame/video/1943.cpp",
	MAME_DIR .. "src/mame/drivers/alien.cpp",
	MAME_DIR .. "src/mame/drivers/bionicc.cpp",
	MAME_DIR .. "src/mame/includes/bionicc.h",
	MAME_DIR .. "src/mame/video/bionicc.cpp",
	MAME_DIR .. "src/mame/drivers/supduck.cpp",
	MAME_DIR .. "src/mame/video/tigeroad_spr.cpp",
	MAME_DIR .. "src/mame/video/tigeroad_spr.h",
	MAME_DIR .. "src/mame/drivers/blktiger.cpp",
	MAME_DIR .. "src/mame/includes/blktiger.h",
	MAME_DIR .. "src/mame/video/blktiger.cpp",
	MAME_DIR .. "src/mame/drivers/cbasebal.cpp",
	MAME_DIR .. "src/mame/includes/cbasebal.h",
	MAME_DIR .. "src/mame/video/cbasebal.cpp",
	MAME_DIR .. "src/mame/drivers/commando.cpp",
	MAME_DIR .. "src/mame/includes/commando.h",
	MAME_DIR .. "src/mame/video/commando.cpp",
	MAME_DIR .. "src/mame/drivers/cps1.cpp",
	MAME_DIR .. "src/mame/includes/cps1.h",
	MAME_DIR .. "src/mame/video/cps1.cpp",
	MAME_DIR .. "src/mame/drivers/kenseim.cpp",
	MAME_DIR .. "src/mame/drivers/cps2.cpp",
	MAME_DIR .. "src/mame/machine/cps2crypt.cpp",
	MAME_DIR .. "src/mame/machine/cps2crypt.h",
	MAME_DIR .. "src/mame/drivers/cps3.cpp",
	MAME_DIR .. "src/mame/includes/cps3.h",
	MAME_DIR .. "src/mame/audio/cps3.cpp",
	MAME_DIR .. "src/mame/audio/cps3.h",
	MAME_DIR .. "src/mame/drivers/egghunt.cpp",
	MAME_DIR .. "src/mame/drivers/exedexes.cpp",
	MAME_DIR .. "src/mame/includes/exedexes.h",
	MAME_DIR .. "src/mame/video/exedexes.cpp",
	MAME_DIR .. "src/mame/drivers/fcrash.cpp",
	MAME_DIR .. "src/mame/drivers/gng.cpp",
	MAME_DIR .. "src/mame/includes/gng.h",
	MAME_DIR .. "src/mame/video/gng.cpp",
	MAME_DIR .. "src/mame/drivers/gunsmoke.cpp",
	MAME_DIR .. "src/mame/includes/gunsmoke.h",
	MAME_DIR .. "src/mame/video/gunsmoke.cpp",
	MAME_DIR .. "src/mame/drivers/higemaru.cpp",
	MAME_DIR .. "src/mame/includes/higemaru.h",
	MAME_DIR .. "src/mame/video/higemaru.cpp",
	MAME_DIR .. "src/mame/drivers/lastduel.cpp",
	MAME_DIR .. "src/mame/includes/lastduel.h",
	MAME_DIR .. "src/mame/video/lastduel.cpp",
	MAME_DIR .. "src/mame/drivers/lwings.cpp",
	MAME_DIR .. "src/mame/includes/lwings.h",
	MAME_DIR .. "src/mame/video/lwings.cpp",
	MAME_DIR .. "src/mame/drivers/mitchell.cpp",
	MAME_DIR .. "src/mame/includes/mitchell.h",
	MAME_DIR .. "src/mame/video/mitchell.cpp",
	MAME_DIR .. "src/mame/drivers/sf.cpp",
	MAME_DIR .. "src/mame/includes/sf.h",
	MAME_DIR .. "src/mame/video/sf.cpp",
	MAME_DIR .. "src/mame/drivers/sidearms.cpp",
	MAME_DIR .. "src/mame/includes/sidearms.h",
	MAME_DIR .. "src/mame/video/sidearms.cpp",
	MAME_DIR .. "src/mame/drivers/sonson.cpp",
	MAME_DIR .. "src/mame/includes/sonson.h",
	MAME_DIR .. "src/mame/video/sonson.cpp",
	MAME_DIR .. "src/mame/drivers/srumbler.cpp",
	MAME_DIR .. "src/mame/includes/srumbler.h",
	MAME_DIR .. "src/mame/video/srumbler.cpp",
	MAME_DIR .. "src/mame/drivers/tigeroad.cpp",
	MAME_DIR .. "src/mame/includes/tigeroad.h",
	MAME_DIR .. "src/mame/video/tigeroad.cpp",
	MAME_DIR .. "src/mame/machine/tigeroad.cpp",
	MAME_DIR .. "src/mame/drivers/vulgus.cpp",
	MAME_DIR .. "src/mame/includes/vulgus.h",
	MAME_DIR .. "src/mame/video/vulgus.cpp",
	MAME_DIR .. "src/mame/machine/kabuki.cpp",
	MAME_DIR .. "src/mame/machine/kabuki.h",
	MAME_DIR .. "src/mame/drivers/tvcapcom.cpp",
	MAME_DIR .. "src/mame/drivers/instantm.cpp",
}

createMAMEProjects(_target, _subtarget, "igs")
files {
	MAME_DIR .. "src/mame/drivers/cabaret.cpp",
	MAME_DIR .. "src/mame/drivers/dunhuang.cpp",
	MAME_DIR .. "src/mame/drivers/goldstar.cpp",
	MAME_DIR .. "src/mame/includes/goldstar.h",
	MAME_DIR .. "src/mame/video/goldstar.cpp",
	MAME_DIR .. "src/mame/drivers/jackie.cpp",
	MAME_DIR .. "src/mame/drivers/igspoker.cpp",
	MAME_DIR .. "src/mame/drivers/igs009.cpp",
	MAME_DIR .. "src/mame/drivers/igs011.cpp",
	MAME_DIR .. "src/mame/drivers/igs017.cpp",
	MAME_DIR .. "src/mame/video/igs017_igs031.cpp",
	MAME_DIR .. "src/mame/video/igs017_igs031.h",
	MAME_DIR .. "src/mame/drivers/igs_fear.cpp",
	MAME_DIR .. "src/mame/drivers/igs_m027.cpp",
	MAME_DIR .. "src/mame/drivers/igs_m036.cpp",
	MAME_DIR .. "src/mame/drivers/iqblock.cpp",
	MAME_DIR .. "src/mame/includes/iqblock.h",
	MAME_DIR .. "src/mame/video/iqblock.cpp",
	MAME_DIR .. "src/mame/drivers/lordgun.cpp",
	MAME_DIR .. "src/mame/includes/lordgun.h",
	MAME_DIR .. "src/mame/video/lordgun.cpp",
	MAME_DIR .. "src/mame/drivers/pgm.cpp",
	MAME_DIR .. "src/mame/includes/pgm.h",
	MAME_DIR .. "src/mame/video/pgm.cpp",
	MAME_DIR .. "src/mame/machine/pgmprot_igs027a_type1.cpp",
	MAME_DIR .. "src/mame/machine/pgmprot_igs027a_type1.h",
	MAME_DIR .. "src/mame/machine/pgmprot_igs027a_type2.cpp",
	MAME_DIR .. "src/mame/machine/pgmprot_igs027a_type2.h",
	MAME_DIR .. "src/mame/machine/pgmprot_igs027a_type3.cpp",
	MAME_DIR .. "src/mame/machine/pgmprot_igs027a_type3.h",
	MAME_DIR .. "src/mame/machine/pgmprot_igs025_igs012.cpp",
	MAME_DIR .. "src/mame/machine/pgmprot_igs025_igs012.h",
	MAME_DIR .. "src/mame/machine/pgmprot_igs025_igs022.cpp",
	MAME_DIR .. "src/mame/machine/pgmprot_igs025_igs022.h",
	MAME_DIR .. "src/mame/machine/pgmprot_igs025_igs028.cpp",
	MAME_DIR .. "src/mame/machine/pgmprot_igs025_igs028.h",
	MAME_DIR .. "src/mame/machine/pgmprot_orlegend.cpp",
	MAME_DIR .. "src/mame/machine/pgmprot_orlegend.h",
	MAME_DIR .. "src/mame/drivers/pgm2.cpp",
	MAME_DIR .. "src/mame/drivers/spoker.cpp",
	MAME_DIR .. "src/mame/machine/igs036crypt.cpp",
	MAME_DIR .. "src/mame/machine/igs036crypt.h",
	MAME_DIR .. "src/mame/machine/pgmcrypt.cpp",
	MAME_DIR .. "src/mame/machine/pgmcrypt.h",
	MAME_DIR .. "src/mame/machine/igs025.cpp",
	MAME_DIR .. "src/mame/machine/igs025.h",
	MAME_DIR .. "src/mame/machine/igs022.cpp",
	MAME_DIR .. "src/mame/machine/igs022.h",
	MAME_DIR .. "src/mame/machine/igs028.cpp",
	MAME_DIR .. "src/mame/machine/igs028.h",
}

createMAMEProjects(_target, _subtarget, "neogeo")
files {
	MAME_DIR .. "src/mame/drivers/neogeo.cpp",
	MAME_DIR .. "src/mame/includes/neogeo.h",
	MAME_DIR .. "src/mame/drivers/neodriv.hxx",
	MAME_DIR .. "src/mame/video/neogeo.cpp",
	MAME_DIR .. "src/mame/drivers/neopcb.cpp",
	MAME_DIR .. "src/mame/video/neogeo_spr.cpp",
	MAME_DIR .. "src/mame/video/neogeo_spr.h",
	MAME_DIR .. "src/mame/machine/ng_memcard.cpp",
	MAME_DIR .. "src/mame/machine/ng_memcard.h",
}

createMAMEProjects(_target, _subtarget, "psikyo")
files {
	MAME_DIR .. "src/mame/drivers/psikyo.cpp",
	MAME_DIR .. "src/mame/includes/psikyo.h",
	MAME_DIR .. "src/mame/video/psikyo.cpp",
	MAME_DIR .. "src/mame/drivers/psikyo4.cpp",
	MAME_DIR .. "src/mame/includes/psikyo4.h",
	MAME_DIR .. "src/mame/video/psikyo4.cpp",
	MAME_DIR .. "src/mame/drivers/psikyosh.cpp",
	MAME_DIR .. "src/mame/includes/psikyosh.h",
	MAME_DIR .. "src/mame/video/psikyosh.cpp",
}

createMAMEProjects(_target, _subtarget, "snk")
files {
	MAME_DIR .. "src/mame/drivers/bbusters.cpp",
	MAME_DIR .. "src/mame/includes/bbusters.h",
	MAME_DIR .. "src/mame/video/bbusters.cpp",
	MAME_DIR .. "src/mame/drivers/dmndrby.cpp",
	MAME_DIR .. "src/mame/drivers/hng64.cpp",
	MAME_DIR .. "src/mame/includes/hng64.h",
	MAME_DIR .. "src/mame/video/hng64.cpp",
	MAME_DIR .. "src/mame/audio/hng64.cpp",
	MAME_DIR .. "src/mame/machine/hng64_net.cpp",
	MAME_DIR .. "src/mame/machine/hng64_net.h",
	MAME_DIR .. "src/mame/video/hng64_3d.hxx",
	MAME_DIR .. "src/mame/video/hng64_sprite.hxx",
	MAME_DIR .. "src/mame/drivers/lasso.cpp",
	MAME_DIR .. "src/mame/includes/lasso.h",
	MAME_DIR .. "src/mame/video/lasso.cpp",
	MAME_DIR .. "src/mame/drivers/mainsnk.cpp",
	MAME_DIR .. "src/mame/includes/mainsnk.h",
	MAME_DIR .. "src/mame/video/mainsnk.cpp",
	MAME_DIR .. "src/mame/drivers/munchmo.cpp",
	MAME_DIR .. "src/mame/includes/munchmo.h",
	MAME_DIR .. "src/mame/video/munchmo.cpp",
	MAME_DIR .. "src/mame/drivers/prehisle.cpp",
	MAME_DIR .. "src/mame/includes/prehisle.h",
	MAME_DIR .. "src/mame/video/prehisle.cpp",
	MAME_DIR .. "src/mame/drivers/snk6502.cpp",
	MAME_DIR .. "src/mame/includes/snk6502.h",
	MAME_DIR .. "src/mame/audio/snk6502.cpp",
	MAME_DIR .. "src/mame/video/snk6502.cpp",
	MAME_DIR .. "src/mame/drivers/snk.cpp",
	MAME_DIR .. "src/mame/includes/snk.h",
	MAME_DIR .. "src/mame/video/snk.cpp",
	MAME_DIR .. "src/mame/drivers/snk68.cpp",
	MAME_DIR .. "src/mame/includes/snk68.h",
	MAME_DIR .. "src/mame/video/snk68.cpp",
	MAME_DIR .. "src/mame/video/snk68_spr.cpp",

}

createMAMEProjects(_target, _subtarget, "technos")
files {
	MAME_DIR .. "src/mame/drivers/chinagat.cpp",
	MAME_DIR .. "src/mame/drivers/ddragon.cpp",
	MAME_DIR .. "src/mame/includes/ddragon.h",
	MAME_DIR .. "src/mame/video/ddragon.cpp",
	MAME_DIR .. "src/mame/drivers/ddragon3.cpp",
	MAME_DIR .. "src/mame/includes/ddragon3.h",
	MAME_DIR .. "src/mame/video/ddragon3.cpp",
	MAME_DIR .. "src/mame/drivers/shadfrce.cpp",
	MAME_DIR .. "src/mame/includes/shadfrce.h",
	MAME_DIR .. "src/mame/video/shadfrce.cpp",
}

createMAMEProjects(_target, _subtarget, "toaplan")
files {
	MAME_DIR .. "src/mame/drivers/snowbros.cpp",
	MAME_DIR .. "src/mame/includes/snowbros.h",
	MAME_DIR .. "src/mame/video/snowbros.cpp",
	MAME_DIR .. "src/mame/video/kan_pand.cpp",
	MAME_DIR .. "src/mame/video/kan_pand.h",
	MAME_DIR .. "src/mame/drivers/toaplan1.cpp",
	MAME_DIR .. "src/mame/includes/toaplan1.h",
	MAME_DIR .. "src/mame/machine/toaplan1.cpp",
	MAME_DIR .. "src/mame/video/toaplan1.cpp",
	MAME_DIR .. "src/mame/includes/toaplipt.h",
	MAME_DIR .. "src/mame/drivers/toaplan2.cpp",
	MAME_DIR .. "src/mame/includes/toaplan2.h",
	MAME_DIR .. "src/mame/video/toaplan2.cpp",
	MAME_DIR .. "src/mame/video/gp9001.cpp",
	MAME_DIR .. "src/mame/video/gp9001.h",
	MAME_DIR .. "src/mame/video/toaplan_scu.cpp",
	MAME_DIR .. "src/mame/video/toaplan_scu.h",
}

--------------------------------------------------
-- remaining drivers
--------------------------------------------------

createMAMEProjects(_target, _subtarget, "misc")
files {
	MAME_DIR .. "src/mame/drivers/1945kiii.cpp",
}
end


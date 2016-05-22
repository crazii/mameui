/**
 * \file   os_isdir.c
 * \brief  Returns true if the specified directory exists.
 * \author Copyright (c) 2002-2008 Jason Perkins and the Premake project
 */

#include <string.h>
#include <sys/stat.h>
#include "premake.h"


int os_isdir(lua_State* L)
{
	const char* path = luaL_checkstring(L, 1);
	
#if PLATFORM_WINDOWS && !PLATFORM_CYGWIN
	DWORD dwAttrib;
#else
	struct stat buf;
#endif

	/* empty path is equivalent to ".", must be true */
	if (strlen(path) == 0)
	{
		lua_pushboolean(L, 1);
	}
#if PLATFORM_WINDOWS && !PLATFORM_CYGWIN
	else if ((dwAttrib = GetFileAttributes(path)) != INVALID_FILE_ATTRIBUTES)
	{
		lua_pushboolean(L, !(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
	}
#else
	else if (stat(path, &buf) == 0)
	{
		lua_pushboolean(L, buf.st_mode & S_IFDIR);
	}
#endif
	else
	{
		lua_pushboolean(L, 0);
	}

	return 1;
}



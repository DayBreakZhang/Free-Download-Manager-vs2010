/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __DBGLOG_H_
#define __DBGLOG_H_

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <windows.h>

void dbglog ( char* szFormat ... )
{
	va_list ap;
	char str [100000];

	va_start ( ap, szFormat );
	vsprintf ( str, szFormat, ap );
	strcat (str, "\r\n");
	va_end (ap);

	int file = _lopen ( DBGLOG_FILENAME, OF_WRITE );

	if ( file == -1 )
	{
		file = _lcreat ( DBGLOG_FILENAME, 0 );
	}

	_llseek ( file, 0, FILE_END );
	_lwrite ( file, str, lstrlen (str) );
	FlushFileBuffers ((HANDLE)file);
	_lclose ( file );
}

void dbglog_eraselog ()
{
	_lclose ( _lcreat ( DBGLOG_FILENAME, 0 ) );
}

#endif
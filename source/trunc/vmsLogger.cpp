/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsLogger.h"
#include <fstream>
#include "mfchelp.h"

void vmsLogger::WriteLog(const tstring& message)
{
	tstring logFile = fsGetDataFilePath("fdmlog.txt");

	std::fstream file(logFile, std::ios_base::app);
	file << GetTimeStamp() << _T(" ") << message << std::endl;
}

tstring vmsLogger::GetTimeStamp()
{
	time_t t = time(0);   
    struct tm * now = localtime( & t );

	tstringstream bufa;
    bufa << (now->tm_year + 1900) << '-' 
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday;

	return bufa.str();
}

/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once
#include "vmsCrashReporter.h"
#include "vmsCrashCatcher.h"
class vmsFdmCrashReporter : 
	protected vmsCrashReporter,
	protected vmsCrashCatcher
{
public:
	vmsFdmCrashReporter(void);
	virtual ~vmsFdmCrashReporter(void);

protected:
	void onCrashDumpCreated ();

public:
	bool CheckIfSubmitDumpIsRequestedByCommandLine(bool& bContinue);
};


/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "fsHistoriesMgr.h"
#include "HFEWnd.h"

extern CHFEWnd *_pwndHFE;

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsHistoriesMgr::fsHistoriesMgr()
{

}

fsHistoriesMgr::~fsHistoriesMgr()
{

}

void fsHistoriesMgr::ReadSettings()
{
	fsCmdHistoryMgr* hs [] = {
		&_LastUrlFiles, &_LastUrlPaths, &_LastBatchUrls, &_LastFolders,
		&_LastFind
	};

	BOOL bUseHistory = _App.History_Use ();
	BOOL bFoldersOnly = _App.History_FoldersOnly ();
	int cDays = _App.History_KeepDays ();
	int cMaxRecs = _App.History_MaxRecords ();

	for (int i = 0; i < sizeof (hs) / sizeof (fsCmdHistoryMgr*); i++)
	{
		hs [i]->Set_NoHistory (bUseHistory == FALSE);
		if (bFoldersOnly && hs [i] != &_LastFolders)
			hs [i]->Set_NoHistory (TRUE);
		hs [i]->Set_MaxDaysCount (cDays);
		hs [i]->Set_MaxRecordCount (cMaxRecs);
	}
}

void fsHistoriesMgr::ClearAll()
{
	_LastUrlFiles.ClearHistory ();
	_LastUrlPaths.ClearHistory ();
	_LastBatchUrls.ClearHistory ();
	_LastFolders.ClearHistory ();
	_LastFind.ClearHistory ();
	_LastFlashVideoUrls.ClearHistory ();

	_pwndHFE->ClearHistory ();
}

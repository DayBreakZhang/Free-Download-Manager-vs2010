/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsFilesToDelete.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsFilesToDelete::vmsFilesToDelete()
{

}

vmsFilesToDelete::~vmsFilesToDelete()
{

}

void vmsFilesToDelete::AddFile(LPCSTR pszFile)
{
	CStringList sl;
	
	_App.FilesToDelete (sl);
	
	sl.AddTail (pszFile);
	
	_App.FilesToDelete_save (sl);
}

void vmsFilesToDelete::Process()
{
	CStringList sl;
	_App.FilesToDelete (sl);

	for (int i = sl.GetCount () - 1; i >= 0; i--)
	{
		LPCSTR psz = sl.GetAt (sl.FindIndex (i));
		BOOL bOK = TRUE;
		if (GetFileAttributes (psz) != DWORD (-1))
			bOK = DeleteFile (psz);
		if (bOK)
			sl.RemoveAt (sl.FindIndex (i));
	}

	
	
	_App.FilesToDelete_save (sl);
}

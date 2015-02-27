/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

BOOL vmsBuildPathToFile (LPCTSTR ptszFileName)
{
	LPCTSTR ptsz = ptszFileName;

	for (;;)
	{
		ptsz = _tcschr (ptsz + 1, '\\');
		if (ptsz == NULL)
			break;
		if (ptsz - ptszFileName == 2)
			continue;
		tstring tstr;
		tstr.assign (ptszFileName, ptsz - ptszFileName);
		CreateDirectory (tstr.c_str (), NULL);
	}

	return TRUE;
}

/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "fsDownloads_GroupsMgr.h"
#include "DownloadsWnd.h"
#include "system.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define	GRPREG_OUTFOLDER	"OutFolder"
#define	GRPREG_EXTENSIONS	"Extensions"
#define GRPREG_OTHER		"Other"

fsDownloads_GroupsMgr::fsDownloads_GroupsMgr()
{
	m_hGroups = NULL;
}

fsDownloads_GroupsMgr::~fsDownloads_GroupsMgr()
{
	if (m_hGroups)
		RegCloseKey (m_hGroups);
}

BOOL fsDownloads_GroupsMgr::LoadGroups()
{
	CString strKey = _T ("Software\\FreeDownloadManager.ORG\\Free Download Manager\\Settings\\Groups");

	if (m_hGroups == NULL)
	{
		LONG lResult;
		lResult =  RegOpenKeyEx (HKEY_CURRENT_USER, strKey, 0, KEY_READ, &m_hGroups);
				
		if (lResult != ERROR_SUCCESS)
			return FALSE;
	}

	return LoadGroupsFromReg () && m_vGroups.size () != 0;
}

BOOL fsDownloads_GroupsMgr::LoadGroupsFromReg()
{
	LONG lResult;
	DWORD dwIndex = 0;
	CHAR szGroup [MAX_GROUP_LEN];
	DWORD dwSize;
	FILETIME lastTime;
	HKEY hGroup;
	fsDownloadGroup grp;
	BOOL bHaveOther = FALSE;
	LONG lRes = ERROR_SUCCESS;

	m_vGroups.clear ();

	do
	{
		dwSize = MAX_GROUP_LEN;
		lResult = RegEnumKeyEx (m_hGroups, dwIndex++, szGroup, &dwSize, NULL, NULL, NULL, &lastTime);

		
		if (lResult != ERROR_SUCCESS)
		{
			

			if (lResult == ERROR_NO_MORE_ITEMS)
				break;

			return LastError (lResult);
		}

		

		lResult = RegOpenKeyEx (m_hGroups, szGroup, 0, KEY_READ, &hGroup);
		if (lResult != ERROR_SUCCESS)
		{
			lRes = lResult;
			RegDeleteKey (m_hGroups, szGroup);
			continue;
		}

		strcpy (grp.szName, szGroup);

		dwSize  = MY_MAX_PATH;
		lResult = RegQueryValueEx (hGroup, GRPREG_OUTFOLDER, NULL, NULL, (LPBYTE) grp.szOutFolder, &dwSize);
		if (lResult != ERROR_SUCCESS)
		{
			lRes = lResult;
			strcpy (grp.szOutFolder, "C:\\Downloads\\");
		}

		dwSize  = MAX_EXTS_LEN;
		lResult = RegQueryValueEx (hGroup, GRPREG_EXTENSIONS, NULL, NULL, (LPBYTE) grp.szExts, &dwSize);
		if (lResult != ERROR_SUCCESS)
		{
			lRes = lResult;
			*grp.szExts = 0;
		}
		else if (dwSize == 0)
		{
			*grp.szExts = 0;
		}

		dwSize  = sizeof (BOOL);
		lResult = RegQueryValueEx (hGroup, GRPREG_OTHER, NULL, NULL, (LPBYTE) &grp.bOther, &dwSize);
		if (lResult != ERROR_SUCCESS)
		{
			lRes = lResult;
			grp.bOther = FALSE;
		}

		RegCloseKey (hGroup);

		bHaveOther = bHaveOther || grp.bOther;

		m_vGroups.add (grp);

	} while (TRUE);

	if (bHaveOther == FALSE) 
	{
		for (int i = 0; i < m_vGroups.size (); i++)
		{
			if (lstrcmpi (m_vGroups [i].szName, GRP_OTHER_NAME) == 0) {
				m_vGroups [i].bOther = TRUE;
				bHaveOther = TRUE;
				lRes = 0;
				break;
			}
		}
	}

	
	if (dwIndex == 1 || bHaveOther == FALSE)
	{
		m_vGroups.clear ();
		SetLastError (ERROR_BAD_ENVIRONMENT);
		return FALSE;
	}

	return LastError (lRes);
}

BOOL fsDownloads_GroupsMgr::LastError(LONG lResult)
{
	SetLastError (lResult);
	return lResult == ERROR_SUCCESS;
}

BOOL fsDownloads_GroupsMgr::SaveGroups()
{
	LONG lResult = ERROR_SUCCESS;
	LONG lRes = ERROR_SUCCESS;

	for (int i = 0; i < m_vGroups.size (); i++)
	{
		fsDownloadGroup grp = m_vGroups [i];
		HKEY hGroup;

		lResult = RegCreateKeyEx (m_hGroups, grp.szName, 0, NULL, REG_OPTION_NON_VOLATILE,
						KEY_WRITE, NULL, &hGroup, NULL);

		if (lResult != ERROR_SUCCESS)
		{
			lRes = lResult;
			continue;
		}

		lResult = RegSetValueEx (hGroup, GRPREG_OUTFOLDER, 0, REG_SZ, (LPBYTE) grp.szOutFolder, strlen (grp.szOutFolder));
		if (lResult != ERROR_SUCCESS)
			lRes = lResult;

		lResult = RegSetValueEx (hGroup, GRPREG_EXTENSIONS, 0, REG_SZ, (LPBYTE) grp.szExts, strlen (grp.szExts));
		if (lResult != ERROR_SUCCESS)
			lRes = lResult;

		lResult = RegSetValueEx (hGroup, GRPREG_OTHER, 0, REG_DWORD, (LPBYTE) &grp.bOther, sizeof (grp.bOther));
		if (lResult != ERROR_SUCCESS)
			lRes = lResult;
		
		RegCloseKey (hGroup);
	}

	if (lRes != ERROR_SUCCESS)
		return LastError (lRes);

	return TRUE;
}

int fsDownloads_GroupsMgr::GetCount()
{
	return m_vGroups.size ();
}

BOOL fsDownloads_GroupsMgr::GetGroup(fsDownloadGroup *pGroup, int iGroup)
{
	if (iGroup >= GetCount () || iGroup < 0)
		iGroup = FindGroupByName (GRP_OTHER_NAME);
	*pGroup = m_vGroups [iGroup];
	return TRUE;
}

int fsDownloads_GroupsMgr::FindGroupByExt(LPCSTR pszExt)
{
	for (int grp = 0; grp < m_vGroups.size (); grp++)
	{
		fsDownloadGroup *pgrp = &m_vGroups [grp];
		if (IsExtInExtsStr (pgrp->szExts, pszExt))
			return grp;
	}

	return -1;
}

int fsDownloads_GroupsMgr::FindGroupByName(LPCSTR pszName)
{
	for (int i = 0; i < m_vGroups.size (); i++)
		if (!fsStrCmpNC (m_vGroups [i].szName, pszName))
			return i;
	
	return -1;
}

void fsDownloads_GroupsMgr::DeleteGroup(LPCSTR pszGroup)
{
	int grp = FindGroupByName (pszGroup);
	if (grp == -1)
		return;

	m_vGroups.del (grp);

	CRegKey key;
	key.Attach (m_hGroups);
	key.RecurseDeleteKey (pszGroup);
	key.Detach ();
}

void fsDownloads_GroupsMgr::CreateGroup(fsDownloadGroup *grp)
{
	m_vGroups.add (*grp);
}

void fsDownloads_GroupsMgr::UpdateGroup(int iGrp, fsDownloadGroup *grp)
{
	if (strcmp (m_vGroups [iGrp].szName, grp->szName))
		RegDeleteKey (m_hGroups, m_vGroups [iGrp].szName);
	
	m_vGroups [iGrp] = *grp;
}

LPCSTR fsDownloads_GroupsMgr::GetGroupName(int iGrp)
{
	return m_vGroups [iGrp].szName;
}

LPCSTR fsDownloads_GroupsMgr::GetGroupFolder(int iGrp)
{
	return m_vGroups [iGrp].szOutFolder;
}

void fsDownloads_GroupsMgr::SetGroupFolder(int iGrp, LPCSTR pszFldr)
{
	lstrcpy (m_vGroups [iGrp].szOutFolder, pszFldr);
}

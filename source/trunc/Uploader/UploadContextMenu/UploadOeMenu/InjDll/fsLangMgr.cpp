/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fsLangMgr.h"
#include "vmsFile.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsLangMgr _LngMgr;

fsLangMgr::fsLangMgr()
{
	m_iCurLng = -1;
}

fsLangMgr::~fsLangMgr()
{

}

#define LNG_COMMENT_CHAR	';'

BOOL fsLangMgr::Initialize(LPCSTR pszFolder)
{
	m_strFolder = pszFolder;

	WIN32_FIND_DATA wfd;

	std::string strMask = m_strFolder;
	strMask += "\\*.lng";

	HANDLE hFind = FindFirstFile (strMask.c_str (), &wfd);
	BOOL bFind = hFind != INVALID_HANDLE_VALUE;

	while (bFind)
	{
		fsLngFileInfo info;
		info.strFileName = m_strFolder; 
		info.strFileName += "\\"; 
		info.strFileName += wfd.cFileName;

		vmsFile file;
		if (file.open (info.strFileName.c_str ()))
		{
			
			while (file.read (info.strLngName))
			{
				if (info.strLngName.length () && info.strLngName [0] != LNG_COMMENT_CHAR)
				{
					AddLngFileInfo (info);
					break;
				}
			}
		}

		bFind = FindNextFile (hFind, &wfd);
	}

	if (hFind != INVALID_HANDLE_VALUE)
		FindClose (hFind);

	LoadEngFileStrings ();

	return m_vLngFiles.size () != 0;
}

int fsLangMgr::GetLngCount()
{
	return m_vLngFiles.size ();
}

LPCSTR fsLangMgr::GetLngName(int iIndex)
{
	return m_vLngFiles [iIndex].strLngName.c_str ();
}

LPCSTR fsLangMgr::GetLngFilePathName(int iIndex)
{
	return m_vLngFiles [iIndex].strFileName.c_str ();
}

BOOL fsLangMgr::LoadLng(int iIndex)
{	
	vmsFile file;
	if (file.open (m_vLngFiles [iIndex].strFileName.c_str ()))
	{
		std::string str;

		
		do
		{
			if (FALSE == file.read (str))
				return FALSE;

			if (str.length () && str [0] != LNG_COMMENT_CHAR)
				break;
		}
		while (TRUE);

		m_vStrings.clear ();

		
		while (file.read (str))
		{
			if (str.length () == 0 || str [0] == LNG_COMMENT_CHAR)
				continue;

			PreprocessLanguageString (str);
			m_vStrings.add (str);
		}

		m_iCurLng = iIndex;

		return m_vStrings.size () != 0;
	}

	return FALSE;
}

int fsLangMgr::FindLngByName(LPCSTR pszName)
{
	for (int i = 0; i < m_vLngFiles.size (); i++)
		if (m_vLngFiles [i].strLngName == pszName)
			return i;

	return -1;
}

int fsLangMgr::GetStringCount()
{
	return m_vStrings.size ();
}

LPCSTR fsLangMgr::GetString(int iIndex)
{
	static char szNull [1] = {0};

	if (iIndex < m_vStrings.size ()) 
		return m_vStrings [iIndex].c_str ();
	else if (iIndex < m_vEngStrings.size ()) 
		return m_vEngStrings [iIndex].c_str ();
	else
		return szNull;
}

int fsLangMgr::GetCurLng()
{
	return m_iCurLng;
}

void fsLangMgr::AddLngFileInfo(fsLngFileInfo &info)
{
	for (int i = 0; i < m_vLngFiles.size (); i++)
	{
		if (lstrcmpi (m_vLngFiles [i].strLngName.c_str (), info.strLngName.c_str ()) > 0)
		{
			m_vLngFiles.insert (i, info);
			return;
		}
	}

	m_vLngFiles.add (info);
}

void fsLangMgr::LoadEngFileStrings()
{
	for (int i = 0; i < GetLngCount (); i++)
	{
		if (stricmp (GetLngName (i), "English") == 0)
		{
			LoadLng (i);
			m_vEngStrings = m_vStrings;
		}
	}
}

void fsLangMgr::PreprocessLanguageString(std::string &str)
{
	int n;
	
	do {
		n = str.find ("\\n");
		if (n != -1)
			str.replace (n, 2, "\n");
	}while (n != -1);
}

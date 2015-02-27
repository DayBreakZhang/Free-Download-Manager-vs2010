/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsStringRecentList.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsStringRecentList::vmsStringRecentList()
{
	m_nMaxEntries = 10;
}

vmsStringRecentList::~vmsStringRecentList()
{

}

void vmsStringRecentList::Add(LPCSTR psz)
{
	m_vList.Add (psz);

	bool bNeedDel = true;

	for (int i = 0; i < m_vList.get_Count () - 1; i++)
	{
		if (lstrcmp (m_vList.get_String (i), psz) == 0)
		{
			m_vList.Del (i);
			bNeedDel = false;
			break;
		}
	}

	if (bNeedDel)
	{
		if (m_vList.get_Count () > m_nMaxEntries)
			m_vList.Del (0);
	}
}

int vmsStringRecentList::get_Count() const
{
	return m_vList.get_Count ();
}

LPCSTR vmsStringRecentList::get_String(int nIndex) const
{
	return m_vList.get_String (nIndex);
}

void vmsStringRecentList::Clear()
{
	m_vList.Clear ();
}

BOOL vmsStringRecentList::Save(HANDLE hFile)
{
	return m_vList.Save (hFile);
}

BOOL vmsStringRecentList::Load(HANDLE hFile)
{
	return m_vList.Load (hFile);
}

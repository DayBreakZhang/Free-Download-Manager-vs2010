/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsStringList.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsStringList::vmsStringList()
{

}

vmsStringList::~vmsStringList()
{

}

void vmsStringList::Add(LPCSTR psz)
{
	m_vList.add (psz);
}

int vmsStringList::get_Count() const
{
	return m_vList.size ();
}

void vmsStringList::Del(int nIndex)
{
	m_vList.del (nIndex);
}

LPCSTR vmsStringList::get_String(int nIndex) const
{
	const fs::list <fsString>* pv = &m_vList;
	return ((fs::list <fsString>*)pv)->at (nIndex);
}

BOOL vmsStringList::Save(HANDLE hFile)
{
	int c = m_vList.size ();
	
	DWORD dw;

	if (FALSE == WriteFile (hFile, &c, sizeof (c), &dw, NULL))
		return FALSE;

	for (int i = 0; i < c; i++)
	{
		if (FALSE == fsSaveStrToFile (get_String (i), hFile))
			return FALSE;
	}

	return TRUE;
}

BOOL vmsStringList::Load(HANDLE hFile)
{
	Clear ();

	int c = 0;
	DWORD dw;

	if (FALSE == ReadFile (hFile, &c, sizeof (c), &dw, NULL))
		return FALSE;

	for (int i = 0; i < c; i++)
	{
		LPSTR psz;

		if (FALSE == fsReadStrFromFile (&psz, hFile))
			return FALSE;

		Add (psz);

		delete [] psz;
	}

	return TRUE;
}

void vmsStringList::Clear()
{
	m_vList.clear ();
}

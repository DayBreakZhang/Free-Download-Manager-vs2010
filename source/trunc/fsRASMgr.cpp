/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "fsRASMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsRASMgr::fsRASMgr()
{

}

fsRASMgr::~fsRASMgr()
{

}

BOOL fsRASMgr::EnumEntries()
{
	LPRASENTRYNAME pREN;
	fsnew (pREN, RASENTRYNAME, 1);
	UINT nRet;
	ULONG cb = sizeof(RASENTRYNAME);
	ULONG cEntries;

	pREN->dwSize = sizeof(RASENTRYNAME);

	nRet = fsRasEnumEntries (NULL, NULL, pREN, &cb, &cEntries);
	
	if (nRet)
	{
		delete [] pREN;

		if (nRet == ERROR_BUFFER_TOO_SMALL)
		{
			BYTE *pb;
			fsnew (pb, BYTE, cb);
			pREN = (LPRASENTRYNAME) pb; 
			pREN->dwSize = sizeof(RASENTRYNAME);

			
			nRet = fsRasEnumEntries (NULL, NULL, pREN, &cb, &cEntries);

			if (nRet != ERROR_SUCCESS)
			{
				delete [] pREN;
				return FALSE;
			}
		}
		else
		{
			return FALSE;
		}
	}
 
	m_vEntries.clear ();

    for (UINT i=0; i < cEntries; i++)
          m_vEntries.add (pREN [i].szEntryName);

	delete [] pREN;

	return TRUE;
}

UINT fsRASMgr::GetEntriesCount()
{
	return m_vEntries.size ();
}

LPCSTR fsRASMgr::GetEntry(UINT nEntry)
{
	ASSERT (nEntry < (UINT)m_vEntries.size ());

	return m_vEntries [nEntry];
}

BOOL fsRASMgr::EnumConnections()
{
	LPRASCONN pRC;
	fsnew (pRC, RASCONN, 1);
	DWORD sz = sizeof (RASCONN);
	DWORD cConns;

	pRC->dwSize = sizeof (RASCONN);

	DWORD dwRet = fsRasEnumConnections (pRC, &sz, &cConns);

	if (dwRet != ERROR_SUCCESS)
	{
		delete [] pRC;

		if (dwRet == ERROR_BUFFER_TOO_SMALL)
		{
			BYTE *pb;
			fsnew (pb, BYTE, sz);
			pRC = (LPRASCONN) pb; 
			pRC->dwSize = sizeof (RASCONN);
			dwRet = fsRasEnumConnections (pRC, &sz, &cConns);

			if (dwRet != ERROR_SUCCESS)
			{
				delete [] pRC;
				return FALSE;
			}
		}
		else
		{
			return FALSE;
		}
	}

	m_vConns.clear ();

	for (DWORD i = 0; i < cConns; i++)
		m_vConns.add (pRC [i]);

	delete [] pRC;

	return TRUE;
}

int fsRASMgr::GetConnectionCount()
{
	return m_vConns.size ();
}

LPRASCONN fsRASMgr::GetConnection(int iIndex)
{
	return &m_vConns [iIndex];
}

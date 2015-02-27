/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "vmsXOR.h"

vmsXOR::vmsXOR()
{

}

vmsXOR::~vmsXOR()
{

}

void vmsXOR::set_Key(LPCSTR pszKey)
{
	m_strKey = pszKey;
}

void vmsXOR::Encrypt(LPBYTE pbIn, LPBYTE pbOut, DWORD dwSize)
{
	LPCSTR pszKey = m_strKey.c_str ();

	while (dwSize--)
	{
		*pbOut++ = *pbIn++ ^ *pszKey++;
		if (*pszKey == 0)
			pszKey = m_strKey.c_str ();
	}
}

void vmsXOR::Decrypt(LPBYTE pbIn, LPBYTE pbOut, DWORD dwSize)
{
	Encrypt (pbIn, pbOut, dwSize);
}

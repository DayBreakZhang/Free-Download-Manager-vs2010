/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSXOR_H__5AD8FE3E_D6E2_4D2F_9725_0B8D6F12115C__INCLUDED_)
#define AFX_VMSXOR_H__5AD8FE3E_D6E2_4D2F_9725_0B8D6F12115C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <windows.h>
#include <string>

class vmsXOR  
{
public:
	void Decrypt(LPBYTE pbIn, LPBYTE pbOut, DWORD dwSize);
	void Encrypt(LPBYTE pbIn, LPBYTE pbOut, DWORD dwSize);
	void set_Key (LPCSTR pszKey);
	vmsXOR();
	virtual ~vmsXOR();

protected:
	std::string m_strKey;
};

#endif 

/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSDES_H__F4F35898_CAE4_400F_84AA_922FD377DE21__INCLUDED_)
#define AFX_VMSDES_H__F4F35898_CAE4_400F_84AA_922FD377DE21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <windows.h>
#include "libdes\des.h"

typedef unsigned char* DES_KEY;

class vmsDES  
{
public:
	void Decrypt (LPBYTE pbIn, LPBYTE pbOut, DWORD dwSize);
	void Encrypt (LPBYTE pbIn, LPBYTE pbOut, DWORD dwSize);
	void set_Key (DES_KEY szKey);
	vmsDES();
	virtual ~vmsDES();

protected:
	void DoDES (LPBYTE pbIn, LPBYTE pbOut, DWORD dwSize, BOOL bEncrypt);
	des_key_schedule m_hardkey;
};

#endif 

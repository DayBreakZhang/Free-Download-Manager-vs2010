/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSDLL_H__B98FCFE8_F468_47BF_B1A6_B42567CEDED8__INCLUDED_)
#define AFX_VMSDLL_H__B98FCFE8_F468_47BF_B1A6_B42567CEDED8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsDLL  
{
public:
	virtual bool is_Loaded();
	FARPROC GetProcAddress (LPCSTR pszProcName);
	virtual void Free();
	virtual bool Load(LPCSTR pszDll);
	vmsDLL(LPCSTR pszDll = NULL);
	virtual ~vmsDLL();

protected:
	HMODULE m_hDLL;
};

#endif 

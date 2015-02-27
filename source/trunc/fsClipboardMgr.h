/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSCLIPBOARDMGR_H__7D232619_1541_409D_A94A_F6B2CCFF7456__INCLUDED_)
#define AFX_FSCLIPBOARDMGR_H__7D232619_1541_409D_A94A_F6B2CCFF7456__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class fsClipboardMgr  
{
public:
	
	BOOL Text (LPCSTR psz);
	
	LPCSTR Text();
	
	void Initialize (HWND hWnd);

	fsClipboardMgr();
	virtual ~fsClipboardMgr();

protected:
	fsString m_strText;	
	HWND m_hWnd;
};

#endif 

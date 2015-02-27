/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSSINGLEINSTANCE_H__63F59A67_04AD_4F96_B174_02D846146257__INCLUDED_)
#define AFX_VMSSINGLEINSTANCE_H__63F59A67_04AD_4F96_B174_02D846146257__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#define WM_APP_NEEDSHUTDOWN			0x8000	

class vmsSingleInstance  
{
public:
	void FreeInstance();
	
	BOOL is_1stInstance ();
	
	void Shutdown1stInstance();
	
	HWND get_1stInstanceHWND();
	
	
	void set_1stInstanceHWND (HWND hwnd);

	
	vmsSingleInstance(LPCSTR pszAppName);
	virtual ~vmsSingleInstance();

protected:
	HANDLE m_hmx;	
};

#endif 

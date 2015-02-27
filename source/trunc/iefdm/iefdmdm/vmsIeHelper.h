/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSIEHELPER_H__593D37CC_F335_442E_95EF_C1A358E68D63__INCLUDED_)
#define AFX_VMSIEHELPER_H__593D37CC_F335_442E_95EF_C1A358E68D63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsIeHelper  
{
public:
	static int GetTabCount (HWND hwndIeWindow);
	static void GetIeWindows (vector <HWND> &vWnds);
	vmsIeHelper();
	virtual ~vmsIeHelper();

};

#endif 

/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSOEWINDOWS_H__DAB59B4B_7124_4C0F_8821_C1D564DADFC1__INCLUDED_)
#define AFX_VMSOEWINDOWS_H__DAB59B4B_7124_4C0F_8821_C1D564DADFC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsOeWindows  
{
public:
	HWND m_hwndMain;
	HWND m_hwndRebar;
	HWND m_hwndMessageList;
	HWND m_hwndFoldersList;
	BOOL Initialize();
	vmsOeWindows();
	virtual ~vmsOeWindows();

};

#endif 

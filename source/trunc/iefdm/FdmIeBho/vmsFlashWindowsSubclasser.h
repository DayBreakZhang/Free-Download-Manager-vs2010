/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSFLASHWINDOWSSUBCLASSER_H__9F1C33DA_D4DD_4732_9410_0A389D4AA6C5__INCLUDED_)
#define AFX_VMSFLASHWINDOWSSUBCLASSER_H__9F1C33DA_D4DD_4732_9410_0A389D4AA6C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <vector>
#include <Exdisp.h>

class vmsFlashWindowsSubclasser  
{
public:
	struct FlashWindow
	{
		HWND hwnd;
		WNDPROC pfnOldProc;
		LPVOID pvData;
		POINT ptMousePos;
	};
public:
	static vmsFlashWindowsSubclasser& o();
	FlashWindow* getWindow (int nIndex);
	bool Subclass (HWND hwnd, WNDPROC pfn, LPVOID pvData);
	int FindWindow (HWND hwnd) const;
	vmsFlashWindowsSubclasser();
	virtual ~vmsFlashWindowsSubclasser();

protected:
	std::vector <FlashWindow> m_vWnds;

};

#endif 

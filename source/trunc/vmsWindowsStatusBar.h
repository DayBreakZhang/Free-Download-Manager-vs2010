/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSWINDOWSSTATUSBAR_H__58F3DD11_9E1F_425E_8358_D8878C08A6B9__INCLUDED_)
#define AFX_VMSWINDOWSSTATUSBAR_H__58F3DD11_9E1F_425E_8358_D8878C08A6B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsWindowsStatusBar  
{
public:
	static vmsWindowsStatusBar& o();
	void RestoreBarStateIfRequired();
	void MakeSureBarIsVisible();
	vmsWindowsStatusBar();
	virtual ~vmsWindowsStatusBar();

protected:
	UINT m_uBarPrevState;
};

#endif 

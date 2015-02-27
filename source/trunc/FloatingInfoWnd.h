/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FLOATINGINFOWND_H__DB782E8B_7598_4C06_B0D1_A624A1D5A0A5__INCLUDED_)
#define AFX_FLOATINGINFOWND_H__DB782E8B_7598_4C06_B0D1_A624A1D5A0A5__INCLUDED_

#include "FloatingWndDropTarget.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

#include "FloatingInfo_ListCtrlWnd.h"
#include "fsMutex.h"	

class CFloatingInfoWnd : public CFrameWnd
{
	DECLARE_DYNCREATE(CFloatingInfoWnd)
protected:

public:
	CFloatingInfoWnd();
	virtual ~CFloatingInfoWnd();

public:
	void HideAlways();
	void SetBlend (BYTE val);
	
	void TurnOffWindow ();
	
	
	
	void NeedToShow (BOOL b);
	
	void SaveState();
	
	void AddDownloadToList (vmsDownloadSmartPtr dld, bool bUploadInfo);
	
	void RebuildList();
	
	BOOL Create ();

	
	//{{AFX_VIRTUAL(CFloatingInfoWnd)
	//}}AFX_VIRTUAL

protected:
	BOOL m_bHideAlways;
	CImageList m_imgsList, m_imgsList_sel;
	
	void UpdateDownloadSpeed(int nItem);
	BOOL m_bNeedToShow;
	
	BOOL m_bWasFS;
	fsMutex m_mxList;	
	int m_cxPercent;	
	int m_cxSpeed;		
	
	int FindIndex (vmsDownloadSmartPtr dld);
	
	void UpdateDownloadProgress (int nItem);
	
	CFloatingInfo_ListCtrlWnd m_wndList;
	BYTE m_blend;	
	CFloatingWndDropTarget m_drop;	

	
	//{{AFX_MSG(CFloatingInfoWnd)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 

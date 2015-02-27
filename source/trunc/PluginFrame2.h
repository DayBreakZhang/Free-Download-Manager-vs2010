/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_PLUGINFRAME2_H__78130894_AE9B_4887_8FA3_4303C9C534FF__INCLUDED_)
#define AFX_PLUGINFRAME2_H__78130894_AE9B_4887_8FA3_4303C9C534FF__INCLUDED_

#include "PlugFrame2Tabs.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CPluginFrame2 : public CWnd
{

public:
	CPluginFrame2();

public:

public:

	
	//{{AFX_VIRTUAL(CPluginFrame2)
	//}}AFX_VIRTUAL

public:
	
	void OnNewLng();
	
	int GetActivePlugin();
	void SetActivePlugin (int iPlugin);
	BOOL Create (CWnd* pParent);
	
	void SendPluginCommand (UINT uCmd);
	virtual ~CPluginFrame2();

	
protected:
	BOOL m_bMoreTabs;
	CPlugFrame2Tabs m_wndTabs;
	int m_iActivePlugin;
	class CMainFrame* m_pMainFrame;
	BOOL Initialize();
	//{{AFX_MSG(CPluginFrame2)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 

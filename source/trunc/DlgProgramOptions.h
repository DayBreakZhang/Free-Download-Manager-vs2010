/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGPROGRAMOPTIONS_H__5A3E08EE_CD22_4363_9BE5_347F5D20D1A3__INCLUDED_)
#define AFX_DLGPROGRAMOPTIONS_H__5A3E08EE_CD22_4363_9BE5_347F5D20D1A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "resource.h"
#include "Dlg_Options.h"
#include "Dlg_Options_General.h"	
#include "Dlg_Options_General_History.h"	
#include "Dlg_Options_General_Misc.h"	
#include "Dlg_Options_General_Misc_Advanced.h"	
#include "Dlg_Options_Downloads.h"	
#include "Dlg_Options_Downloads_NewDld.h"	
#include "Dlg_Options_Downloads_Network.h"	
#include "Dlg_Options_Downloads_Bittorrent.h"	
#include "Dlg_Options_Downloads_Mirrors.h"	
#include "Dlg_Options_Downloads_Monitoring.h"	
#include "Dlg_Options_Notifications.h"	
#include "Dlg_Options_SiteMgr.h"	
#include "Dlg_Options_Downloads_TimeLimit.h"	
#include "Dlg_Options_Downloads_Flv.h"	

class CProgramOptions : public CDlg_Options
{

public:
	CProgramOptions(CWnd* pParent = NULL, LPCSTR pszStartPage = NULL);   

	//{{AFX_DATA(CDlgProgramOptions)
	enum { IDD = IDD_OPTIONS };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlgProgramOptions)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	CDlg_Options_Downloads_Flv m_downloads_flv;
	CDlg_Options_Downloads_TimeLimit m_downloads_timelimit;
	CDlg_Options_SiteMgr m_sitemgr;
	CDlg_Options_Notifications m_notifications;
	CDlg_Options_Downloads_Monitoring m_downloads_monitoring;
	CDlg_Options_Downloads_Mirrors m_downloads_mirrors;
	CDlg_Options_Downloads_Bittorrent m_downloads_bittorrent;
	CDlg_Options_Downloads_Network m_downloads_network;
	CDlg_Options_Downloads_NewDld m_downloads_newdld;
	CDlg_Options_Downloads m_downloads;
	CDlg_Options_General_Misc_Advanced m_general_misc_adv;
	CDlg_Options_General_Misc m_general_misc;
	CDlg_Options_General_History m_general_history;
	void InitializeData();
	CDlg_Options_General m_general;

	
	//{{AFX_MSG(CDlgProgramOptions)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 

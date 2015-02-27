/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADERPROPERTIES_COMMUNITYPAGE_H__A65950D2_D1C1_4E55_9854_8B6C2F3B5D3F__INCLUDED_)
#define AFX_DOWNLOADERPROPERTIES_COMMUNITYPAGE_H__A65950D2_D1C1_4E55_9854_8B6C2F3B5D3F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDownloaderProperties_CommunityPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CDownloaderProperties_CommunityPage)

public:
	CDownloaderProperties_CommunityPage();
	~CDownloaderProperties_CommunityPage();

	//{{AFX_DATA(CDownloaderProperties_CommunityPage)
	enum { IDD = IDD_DLDR_COMMUNITY };
		
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDownloaderProperties_CommunityPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void UpdateEnabled();
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	
	//{{AFX_MSG(CDownloaderProperties_CommunityPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnSwitchtoopinions();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnWhatisthis();
	afx_msg void OnCheckifmal();
	afx_msg void OnDisplayopinions();
	afx_msg void OnChangeMalrepsminimum();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 

/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADPROPERTIES_MIRRORSPAGE_H__B018736A_B41A_4F22_B07E_709D814F0BA7__INCLUDED_)
#define AFX_DOWNLOADPROPERTIES_MIRRORSPAGE_H__B018736A_B41A_4F22_B07E_709D814F0BA7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDownloadProperties_MirrorsPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CDownloadProperties_MirrorsPage)

public:
	vmsDownloadSmartPtr m_dld;
	CDownloadProperties_MirrorsPage();
	~CDownloadProperties_MirrorsPage();

	//{{AFX_DATA(CDownloadProperties_MirrorsPage)
	enum { IDD = IDD_DOWNLOAD_MIRRORS };
	CListCtrl	m_wndMirrs;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDownloadProperties_MirrorsPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void UpdateEnabled();
	BOOL m_bNeedStop;	
	
	void FullUpdateMirrList();
	
	static DWORD WINAPI _threadCalcMirrSpeed2 (LPVOID lp);
	static DWORD WINAPI _threadCalcMirrSpeed (LPVOID lp);
	
	void FillMirrsList();
	
	static DWORD WINAPI _threadFindMirrors2(LPVOID lp);
	static DWORD WINAPI _threadFindMirrors (LPVOID lp);
	
	void CheckFileSizeKnown();
	
	
	
	void UpdateMirrUsing();
	
	void UpdateMirrSpeed();
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	
	//{{AFX_MSG(CDownloadProperties_MirrorsPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnWhatisthis();
	afx_msg void OnCalcmirrspeed();
	afx_msg void OnAddmirror();
	afx_msg void OnFindmirrors();
	afx_msg void OnClickMirrs(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKeydownMirrs(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRemove();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 

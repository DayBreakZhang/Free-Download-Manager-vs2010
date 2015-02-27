/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADALREXISTSDLG_H__4F114883_25D2_41A8_9224_707C31E0CC35__INCLUDED_)
#define AFX_DOWNLOADALREXISTSDLG_H__4F114883_25D2_41A8_9224_707C31E0CC35__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDownloadAlrExistsDlg : public CDialog
{

public:
	BOOL m_bNeedTopMost;	
	vmsDownloadSmartPtr m_dld;	
	CDownloadAlrExistsDlg(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDownloadAlrExistsDlg)
	enum { IDD = IDD_DLDALREXISTS };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDownloadAlrExistsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();

	
	//{{AFX_MSG(CDownloadAlrExistsDlg)
	afx_msg void OnResume();
	afx_msg void OnRestart();
	afx_msg void OnLaunch();
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 

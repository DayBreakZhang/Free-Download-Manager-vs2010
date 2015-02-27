/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGCREATEFLVDOWNLOADS_H__3B06233F_69C9_47B3_B861_42D7014FAF1A__INCLUDED_)
#define AFX_DLGCREATEFLVDOWNLOADS_H__3B06233F_69C9_47B3_B861_42D7014FAF1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlgCreateFlvDownloads : public CDialog
{
public:
	struct FlvDownload
	{
		CString strTitle;
		CString strUrl;
		UINT64 uSize;
	};

public:
	bool m_bReqTopMostDialog;
	CDlgCreateFlvDownloads(CWnd* pParent = NULL, class CFdmUiWindow *pUiWindow = NULL);   

	//{{AFX_DATA(CDlgCreateFlvDownloads)
	enum { IDD = IDD_CREATEFLVDOWNLOADS };
	CListCtrl	m_wndFlvList;
	//}}AFX_DATA

	std::vector <FlvDownload> m_vDlds;
	std::vector <bool> m_vbDldSelected;
	CString m_strWebPageUrl;
	CString m_strDstFolder;
	vmsMediaFileConvertSettings m_convertSettings;
	bool m_bUseAutoConvert;

	
	//{{AFX_VIRTUAL(CDlgCreateFlvDownloads)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();
	void UpdateEnabled();
	CFdmUiWindow *m_pUiWindow;

	
	//{{AFX_MSG(CDlgCreateFlvDownloads)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnUseAutoConvert();
	afx_msg void OnCnvrtSettings();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
};

//{{AFX_INSERT_LOCATION}}

#endif 

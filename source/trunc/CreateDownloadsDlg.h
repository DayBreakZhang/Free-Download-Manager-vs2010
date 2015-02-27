/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_CREATEDOWNLOADSDLG_H__E22D64EE_8C08_40A3_8958_2A867A894D35__INCLUDED_)
#define AFX_CREATEDOWNLOADSDLG_H__E22D64EE_8C08_40A3_8958_2A867A894D35__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "fsTree.h"
#include "TreeCtrlEx.h"
#include "fsScheduleMgr.h"	
#include "DownloadsGroupsComboBox.h"

class CCreateDownloadsDlg : public CDialog
{

public:
	

	~CCreateDownloadsDlg();
	CString m_strRootUrl;	
	
	fsScheduleEx m_schScheduleParam;
	BOOL m_bSort;			
	fs::tree <fsFileInfo*>* m_pFileList;	
	CCreateDownloadsDlg(CWnd* pParent = NULL);   

	CTreeCtrlEx	m_wndFiles;

	//{{AFX_DATA(CCreateDownloadsDlg)
	enum { IDD = IDD_CREATEDOWNLOADS };
	CButton	m_btnOutFolderSetDefault;
	CDownloadsGroupsComboBox m_wndGroups;
	CButton	m_btnSetTime;
	CButton	m_btnChooseFolder;
	CButton	m_btnCreateGroup;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CCreateDownloadsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	int m_iAutostart;
	void ReadAutostart();
	void ApplyLanguage();
	vmsDownloadsGroupSmartPtr m_pGroup;
	BOOL m_bAutoStart;
	
	
	
	
	
	
	void CreateDownloads (HTREEITEM hTree, LPCSTR pszRootDir, BOOL bCreate);
	void UpdateEnabled();
	
	
	
	void BuildDownloads (fs::tree <fsFileInfo*>* pTree, LPCSTR pszRootUrl);
	DLDS_LIST m_vpDlds;	
	DLDS_LIST m_vpDldsToStart;	
	CImageList m_checks;
	
	void AddToList (fs::tree <fsFileInfo*>* pTree, HTREEITEM hWhere);

	
	//{{AFX_MSG(CCreateDownloadsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeGroups();
	afx_msg void OnCreategroup();
	afx_msg void OnChoosefolder();
	afx_msg void OnSettime();
	afx_msg void OnAdvanced();
	afx_msg void OnStartnow();
	afx_msg void OnStartmanual();
	afx_msg void OnStartschedule();
	virtual void OnOK();
	afx_msg void OnSelchangedFiles(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelectfolder();
	afx_msg void OnUnselectfolder();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnOutfolderSetdefault();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 

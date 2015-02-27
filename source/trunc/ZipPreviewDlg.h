/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_ZIPPREVIEWDLG_H__6D19EE44_DCBD_463B_B861_4F53B970BFB4__INCLUDED_)
#define AFX_ZIPPREVIEWDLG_H__6D19EE44_DCBD_463B_B861_4F53B970BFB4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "tree.h"
#include "fsArchiveRebuilder.h"
#include "TreeCtrlEx.h"

class CZipPreviewDlg : public CDialog
{

public:
	fsArchive::fsArchiveRebuilder* m_ar;

	CZipPreviewDlg(CWnd* pParent = NULL);   

	//{{AFX_DATA(CZipPreviewDlg)
	enum { IDD = IDD_ZIPPREVIEW };
	CTreeCtrlEx	m_wndFiles;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CZipPreviewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void CheckAllItems (HTREEITEM hRoot, BOOL bCheck);
	void ApplyLanguage();
	
	void ApplyTreeChecks (HTREEITEM hRoot, fs::list <int> &vFiles);
	
	BOOL ApplyTreeChecks();

	struct fsFile
	{
		fsString strName;
		int iIndex;	

		fsFile () {}

		fsFile (fsFile& file)
		{
			operator = (file);
		}

		const fsFile& operator = (const fsFile& file)
		{
			strName = file.strName;
			iIndex = file.iIndex;
			return *this;
		}
	};	

	void TreeToDlg (HTREEITEM hRoot, fs::ListTree <fsFile>* root);
	void AddToTree (LPCSTR pszFile, int iIndex, fs::ListTree <fsFile>* root);
	void BuildTreeOfFiles();
	CImageList m_checks;
	
	fs::ListTree <fsFile>::ListTreePtr m_tFiles;

	
	//{{AFX_MSG(CZipPreviewDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnCheckuncheckall();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 

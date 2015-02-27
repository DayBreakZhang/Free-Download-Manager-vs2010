/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_HFE_FILELIST_H__716594B1_1516_4417_982C_DB67037D89C8__INCLUDED_)
#define AFX_HFE_FILELIST_H__716594B1_1516_4417_982C_DB67037D89C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "ListCtrlEx.h"
#include "fsTree.h"
#include "fsODMenu.h"	

class CHFE_FileList : public CListCtrlEx
{
	friend class CHFEWnd; 
	friend class CCreateDownloadsDlg; 

public:
	CHFE_FileList();

public:

public:

	
	//{{AFX_VIRTUAL(CHFE_FileList)
	//}}AFX_VIRTUAL

public:
	
	void ApplyLanguage();
	void ApplyLanguageToMenu (CMenu* menu);
	
	int OnUpdateToolBar (UINT nID);
	
	void UpdateList();
	BOOL Create (CWnd* pParent);
	virtual ~CHFE_FileList();

	
protected:
	
	void OnForceUpdate();
	
	
	void CalcCoordsForCurSel();
	fsODMenu m_odmenu;
	
	
	
	
	fs::tree <fsFileInfo*>* m_pList;
	
	
	static DWORD WINAPI _threadBuildList (LPVOID lp);
	BOOL m_bDontUpdateList;	
	
	
	
	
	
	
	static fs::tree <fsFileInfo*>* BuildList (LPCSTR pszFolder, BOOL *pbNeedStop, int* piProgress, int iProgressDone);
	void cleanFiles();
	void cleanFilesSubtree(fs::tree <fsFileInfo*>* pCur);
	
	void DownloadSelected();
	
	
	
	void OnKeyDown (WORD wVK);
	
	
	
	BOOL Open1SelectedItem();
	
	static int CALLBACK _SortFunc (LPARAM item1, LPARAM item2, LPARAM lParam);
	void UpdateMenu (CMenu *pMenu);
	void OnRClick();
	CPoint m_rbPt;	
	
	
	int GetFileImage (fsFileInfo* file);
	CImageList m_images, m_selImages;	
	//{{AFX_MSG(CHFE_FileList)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnHfeDownload();
	afx_msg void OnHfeGo();
	afx_msg void OnHfeRefresh();
	afx_msg void OnHfeSettings();
	afx_msg void OnHfeStop();
	afx_msg void OnHfeOpenfolder();
	afx_msg void OnHfeParentfolder();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnHfeDisconnect();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 

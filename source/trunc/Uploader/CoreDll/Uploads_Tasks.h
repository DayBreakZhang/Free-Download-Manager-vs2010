/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_UPLOADS_TASKS_H__167C993F_5B15_4415_B650_712927B89F3E__INCLUDED_)
#define AFX_UPLOADS_TASKS_H__167C993F_5B15_4415_B650_712927B89F3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "listctrlex.h"
#include "fsUpload.h"	
#include "fsODMenu.h"	

enum vmsUploadsTasksText
{
	UTT_PACKAGE_URL			= 0,
	UTT_PACKAGE_NAME		= 1,
	UTT_SIZE				= 2,
	UTT_UPLOADED			= 3,
	UTT_TIME_REMAINING		= 4,
	UTT_SPEED				= 5,
	UTT_DATE_ADDED			= 6,
};

class CUploads_Tasks : public CListCtrlEx
{
	friend class CUploadsWnd;

public:
	CUploads_Tasks();

public:

public:

	
	//{{AFX_VIRTUAL(CUploads_Tasks)
	//}}AFX_VIRTUAL

public:
	void CallSelectedUpload();
	void SelectLastUpload();
	void GetMenuCommandState(UINT nCmd, BOOL &bEnabled, BOOL &bChecked);
	void ApplyLanguageToMenu (CMenu* menu);
	void UpdateUpload (vmsUploadSmartPtr upl, BOOL bRedraw = TRUE);
	static CString GetUploadText (vmsUploadSmartPtr upl, int nSubItem);
	static int GetUploadImage (vmsUploadSmartPtr upl);
	void OnUploadCountChanged();
	int OnUpdateToolBar (UINT nID);
	void UpdateMenu (CMenu *menu);
	void ApplyLanguage();
	BOOL Create(CWnd *pParent);
	virtual ~CUploads_Tasks();

	
protected:
	CImageList m_dimgsMenu;
	CImageList m_imgsMenu;
	void OnKeyDown(WORD wVK);
	void GetSelectedListState(BOOL &bHasRunning, BOOL &bHasStopped, BOOL &bHasDone);
	void OnItemChanged(NM_LISTVIEW *pLV);
	void UpdateUpload (int nIndex, BOOL bRedraw);
	afx_msg void OnGetdispinfo(NMHDR *pNMHDR, LRESULT *pResult);
	CImageList m_images, m_selimages;
	fsODMenu m_odmenu;
	void OnRClick();
	//{{AFX_MSG(CUploads_Tasks)
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnUplCreatenew();
	afx_msg void OnUplStart();
	afx_msg void OnUplStop();
	afx_msg void OnUplProperties();
	afx_msg void OnUplDelete();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnUplCopyurl();
	afx_msg void OnUplOpeninbrowser();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 

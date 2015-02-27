/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADS_TASKS_H__510D187D_8CB0_40F0_BE64_6B11DF08C7F9__INCLUDED_)
#define AFX_DOWNLOADS_TASKS_H__510D187D_8CB0_40F0_BE64_6B11DF08C7F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "ListCtrlEx.h"
#include "fsODMenu.h"	
#include "FloatingWndDropTarget.h"	
#include "fsMutex.h"	

enum vmsMoveType
{
	MT_TOP,			
	MT_BOTTOM,		
	MT_UP,			
	MT_DOWN,		
};

#define DOWNLOADTEXT_FILENAME		0
#define DOWNLOADTEXT_SIZE			1
#define DOWNLOADTEXT_PROGRESS		2
#define DOWNLOADTEXT_TIMELEFT		3
#define DOWNLOADTEXT_SECTIONS		4
#define DOWNLOADTEXT_SPEED			5

class CDownloads_Tasks : public CListCtrlEx
{
	friend class CDownloadsWnd; 
	friend class CDownloaderProperties_ListPage;
	friend class CDlg_Options_Downloads;

public:
	CDownloads_Tasks();

public:

public:

	
	//{{AFX_VIRTUAL(CDownloads_Tasks)
	protected:
	//}}AFX_VIRTUAL

public:
	
	void BeginAddDownloads();
	
	void EndAddDownloads();
	
	vmsDownloadSmartPtr GetItemData (int nItem);
	void DeleteAllItems();
	
	void UnlockList();
	void LockList();
	
	void SelectDownload (vmsDownloadSmartPtr dld);
	
	
	void CallSelectedDownload();
	static void GetFileName (vmsDownloadSmartPtr dld, LPSTR pszFile);
	static std::string GetFileName (vmsDownloadSmartPtr dld);

	
	
	BOOL m_bSizesInBytes;	
	
	
	
	void ApplyLanguage();
	void ApplyLanguageToMenu (CMenu *menu);
	
	
	int  OnUpdateToolBar (UINT nID);
	
	
	
	void UnscheduleDownload (UINT nID);
	
	
	void UpdateAllDownloads();
	void DeleteDownload (vmsDownloadSmartPtr dld);
	
	
	void AddDownload (vmsDownloadSmartPtr dld, BOOL bSelThisDld = FALSE);
	
	void UpdateMenu (CMenu *pMenu);
	
	void WillBeDeleted (vmsDownloadSmartPtr dld);
	vmsDownloadSmartPtr GetActiveDownload();
	class CDownloadsWnd* m_pDownloadsWnd;	
	
	void UpdateDownload (vmsDownloadSmartPtr dld, BOOL bRedraw = TRUE);
	
	
	void AddDownloadToList (vmsDownloadSmartPtr dld, BOOL bSelThisDld = FALSE, bool bPlaceToTop = false);
	
	static int GetDownloadImage (vmsDownloadSmartPtr dld);
	
	int FindItem (vmsDownloadSmartPtr dld);
	static CString GetDownloadText (vmsDownloadSmartPtr dld, int nSubItem);
	BOOL Create (CWnd* pParent);
	virtual ~CDownloads_Tasks();

	
protected:
	static int _compareDownloadsByDateAdded (LPCVOID p1, LPCVOID p2);
	static int _compareDownloadsByComment (LPCVOID p1, LPCVOID p2);
	static int _compareDownloadsBySpeed (LPCVOID p1, LPCVOID p2);
	static int _compareDownloadsByNumberOfSections (LPCVOID p1, LPCVOID p2);
	static int _compareDownloadsByTimeRamaining (LPCVOID p1, LPCVOID p2);
	static int _compareDownloadsByDownloadedByteCount (LPCVOID p1, LPCVOID p2);
	static int _compareDownloadsByLDFileSize (LPCVOID p1, LPCVOID p2);
	static int _compareDownloadsByFileName (LPCVOID p1, LPCVOID p2);
	bool m_bHasEnableSeedingDlds;
	void UpdateDownload (size_t nIndex, BOOL bRedraw);
	
	bool m_bAddingDownloads;
	
	void ScheduleSelectedDlds (BOOL bStart);
	void Sort();
	void MoveSelectedDownloads (vmsMoveType);
	virtual void OnItemChanged(NM_LISTVIEW* pLV);
	
	void SortDownloads();
	
	afx_msg void OnGetdispinfo(NMHDR* pNMHDR, LRESULT* pResult);
	fsMutex m_mxAddDel;	
	
	CFloatingWndDropTarget m_drop;
	
	void OnSortModeChanged();
	
	DLDS_LIST m_vDownloads;
	CImageList m_selimages;
	
	
	void CalcCoordsForCurSel ();
	fsODMenu m_odmenu;	
	
	void OnForceUpdate();
	CPoint m_rbPt;	
	struct _sRecordInfo 
	{
		vmsDownloadSmartPtr dld;
		size_t iIndex;
	};

	
	
	
	void DeleteSelected(BOOL bDontConfirmFileDeleting = FALSE);
	
	
	
	void UpdateActiveDownload (int adjSelected);
	void OnKeyDown (WORD wVK);
	vmsDownloadSmartPtr m_pActiveDownload;	
	void OnRClick ();
	void OnClick();
	
	CImageList m_images;	
	//{{AFX_MSG(CDownloads_Tasks)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnDldcreate();
	afx_msg void OnDlddelete();
	afx_msg void OnDldproperties();
	afx_msg void OnDldstart();
	afx_msg void OnDldstop();
	afx_msg void OnDldlaunch();
	afx_msg void OnDldopenfolder();
	afx_msg void OnDldschedule();
	afx_msg void OnDldautostart();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnDldaddsection();
	afx_msg void OnDlddelsection();
	afx_msg void OnDldrestart();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnDldqsize();
	afx_msg void OnDldcreatebatch();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDldcheckvir();
	afx_msg void OnDldfind();
	afx_msg void OnDldfindnext();
	afx_msg void OnDldunpack();
	afx_msg void OnDldmovedown();
	afx_msg void OnDldmoveup();
	afx_msg void OnDldcheckintegrity();
	afx_msg void OnDldmovetofolder();
	afx_msg void OnDldmovebottom();
	afx_msg void OnDldmovetop();
	afx_msg void OnDldschedulestop();
	afx_msg void OnDldgrantbandwidthfordld();
	afx_msg void OnDldshowprogressdlg();
	afx_msg void OnDldconvert();
	afx_msg void OnDldenableseeding();
	afx_msg void OnDldcreateTP();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	
	
	BOOL m_bAutoStart;
};

//{{AFX_INSERT_LOCATION}}

#endif 

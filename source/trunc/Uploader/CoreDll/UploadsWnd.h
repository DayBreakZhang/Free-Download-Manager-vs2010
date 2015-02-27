/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_UPLOADSWND_H__10043ADB_1AF4_4035_8F21_703313BD9459__INCLUDED_)
#define AFX_UPLOADSWND_H__10043ADB_1AF4_4035_8F21_703313BD9459__INCLUDED_

#include "Uploads_Log.h"	
#include "WndSplitter.h"	
#include "Uploads_Tasks.h"	
#include "vmsUploadsWnd.h"
#include "fsUpload.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

extern class CUploadsWnd *_pwndUploads;

class CUploadsWnd : public CWnd,
	public vmsUploadsWnd, 
	public vmsUploadsStat
{

public:
	CUploadsWnd();

public:

public:

	
	//{{AFX_VIRTUAL(CUploadsWnd)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

public:
	BOOL IsUploadsRunning();
	vmsUploadsStat* get_UploadsStat();
	BOOL LoadAll();
	HMENU GetUploadsMenu();
	void ShowProperties();
	bool GetUploadPackageName (long lId, LPSTR pszName, UINT cchNameMax);
	void CreateNewPackage (vmsUploadPackage **p);
	vmsUploadSmartPtr CreateUpload (vmsUploadPackageImpl *pkg);
	bool GetUploadUrl (long lId, LPSTR pszUrl, DWORD *cchUrlMax);
	bool CreateUpload (vmsUploadPackage *pkg, BOOL bDialogReq, long* pUplId);
	void StopAllUploads(BOOL bByUser);
	void GetMenuCommandState (UINT nCmd, BOOL &bEnabled, BOOL &bChecked);
	void UpdateMenu (CMenu *menu);
	int GetListViewColumnCount (vmsWhichListView);
	void ChangeListViewColumnVisibility (vmsWhichListView, int nIndex);
	BOOL IsListViewColumnShown (vmsWhichListView, int nIndex);
	void ApplyLanguageToMenu (CMenu* menu);
	void ApplyLanguage();
	CWnd* get_Wnd ();
	vmsUploadSmartPtr CreateNewUpload(LPCSTR pszPkgName = NULL, std::vector <fsString> *pvFiles = NULL);
	BOOL SaveAll();
	CUploads_Tasks m_wndTasks;
	CWndSplitter m_wndSplitter;
	CUploads_Log m_wndLog;
	void ShowLog(BOOL bShow);
	BOOL Create(CWnd *pWndParent);
	virtual ~CUploadsWnd();

	
protected:
	void OnDeleteUploads (int cUploads, UINT nIdMem);
	UINT m_nUplsDeletedMsg;
	afx_msg LRESULT OnCreateUploadDoneDlg (WPARAM, LPARAM lp);
	static DWORD WINAPI _threadAskCaptchaValue (LPVOID lp);
	afx_msg LRESULT OnCreateUploadingDialog (WPARAM, LPARAM);
	static DWORD _UploadsMgrEvents (class fsUploadsMgr*, vmsUploadSmartPtr, fsUploadsMgrEvent, LPVOID pData, LPVOID pParam);
	BOOL m_bShowLog;
	//{{AFX_MSG(CUploadsWnd)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnUplCreatenew();
	afx_msg void OnUplStart();
	afx_msg void OnUplStop();
	afx_msg void OnUplProperties();
	afx_msg void OnUplDelete();
	afx_msg void OnUplCopyurl();
	afx_msg void OnUplOpeninbrowser();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 

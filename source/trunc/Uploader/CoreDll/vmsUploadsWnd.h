/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSUPLOADSWND_H__9B58702B_7407_46F7_8E2A_3A6B53B899BD__INCLUDED_)
#define AFX_VMSUPLOADSWND_H__9B58702B_7407_46F7_8E2A_3A6B53B899BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

enum vmsWhichListView
{
	LV_UPLOADS_TASKS,
	LV_TASK_LOG,
};

class vmsUploadPackage
{
public:
	virtual void set_name (LPCSTR pszName) = NULL;
	virtual void add (LPCSTR pszPathName) = NULL;
	virtual void set_numberOfDaysToKeepThisUpload (int nDays) = NULL;
	virtual void set_supposedNumberOfDownloads (int) = NULL;
	virtual void set_passwordForDownload (LPCSTR pszPwd) = NULL;
	virtual void set_addLinkToUploadInCatalogue (BOOL bAdd) = NULL;
	virtual void set_Description (LPCSTR pszDesc) = NULL;
	virtual void set_Tags (LPCSTR pszTags) = NULL;
	virtual void set_OwnerName (LPCSTR pszName) = NULL;
	virtual void set_OwnerEmail (LPCSTR pszEmail) = NULL;
	virtual void set_RecipientEmail (LPCSTR pszEmail) = NULL;
};

class vmsUploadsStat 
{
public:
	virtual BOOL IsUploadsRunning () = NULL;
};

class vmsUploadsWnd  
{
public:
	virtual CWnd* get_Wnd () = NULL;
	virtual void  ApplyLanguage () = NULL;
	virtual void  ApplyLanguageToMenu (CMenu* menu) = NULL;
	virtual void  UpdateMenu (CMenu *menu) = NULL;
	virtual void  GetMenuCommandState (UINT nCmd, BOOL &bEnabled, BOOL &bChecked) = NULL;
	virtual int   GetListViewColumnCount (vmsWhichListView) = NULL;
	virtual BOOL  IsListViewColumnShown (vmsWhichListView, int nIndex) = NULL;
	virtual void  ChangeListViewColumnVisibility (vmsWhichListView, int nIndex) = NULL;
	virtual void  StopAllUploads (BOOL bByUser) = NULL;
	virtual BOOL  SaveAll () = NULL;
	virtual void  CreateNewPackage (vmsUploadPackage **p) = NULL;
	virtual bool  CreateUpload (vmsUploadPackage *pkg, BOOL bDialogReq, long* pUplId) = NULL;
	virtual bool  GetUploadUrl (long lId, LPSTR pszUrl, DWORD *cchUrlMax) = NULL;
	virtual bool  GetUploadPackageName (long lId, LPSTR pszName, UINT cchNameMax) = NULL;
	virtual void  ShowProperties () = NULL;
	virtual HMENU GetUploadsMenu () = NULL;
	virtual vmsUploadsStat* get_UploadsStat () = NULL;
};

#endif 

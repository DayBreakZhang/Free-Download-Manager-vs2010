/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSUPLOADSMGR_H__24050CEC_6CF9_4428_A1C6_14142EA03D15__INCLUDED_)
#define AFX_FSUPLOADSMGR_H__24050CEC_6CF9_4428_A1C6_14142EA03D15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "fsUpload.h"
#include "vmsSharedData.h"	

enum fsUploadsMgrEvent 
{
	UME_UPLOADER_EVENT,
	UME_UPLOAD_LOG_ADDED,
	UME_UPLOAD_STATE_CHANGED,
	UME_UPLOAD_WILL_BE_DELETED,
	UME_UPLOADS_WERE_DELETED,
	UME_ASK_CAPTCHA_VALUE,
	UME_UPLOAD_STOPPED_OR_DONE,
};

typedef DWORD (*fntUploadsMgrEventFunc)(class fsUploadsMgr*, vmsUploadSmartPtr, fsUploadsMgrEvent, LPVOID pData, LPVOID pParam);

#define ULFILE_CURRENT_VERSION	(2)

#define ULFILE_SIG "FUM Uploads"

struct fsULFileHdr
{
	char szSig [sizeof (ULFILE_SIG) + 1];
	WORD wVer;

	fsULFileHdr ()
	{
		strcpy (szSig, ULFILE_SIG);
		wVer = ULFILE_CURRENT_VERSION;
	}
};

const char* const _pszUploadsDeletedNotifyMsg	= "msg - fumcore - uplds deleted";
const char* const _pszSharedMemoryName			= "shmem - fumcore - %d";

class fsUploadsMgr
{
public:
	BOOL IsRunning();
	BOOL LoadAll();
	BOOL SaveAll();
	vmsUploadSmartPtr FindUploadById (UINT nId);
	void StopAllUploads(BOOL bByUser);
	static void GetEventColors(fsInternetUploaderMessageType enType, COLORREF &clrText, COLORREF &clrBg, int &iImage);
	void DeleteUploads(UPLS_LIST_REF v);
	void StopUploads(UPLS_LIST_REF v, BOOL bByUser);
	void StartUploads (UPLS_LIST_REF v);
	vmsUploadSmartPtr FindUploadByManager (fsUploadMgr *pMgr);
	void SetEventFunc (fntUploadsMgrEventFunc pfn, LPVOID lpParam);
	vmsUploadSmartPtr GetUpload (int nIndex);
	void ProcessUploads();
	int GetCount();
	void Add (vmsUploadSmartPtr upl, BOOL bKeepIdAsIs = FALSE);
	fsUploadsMgr();
	virtual ~fsUploadsMgr();

protected:
	LPLONG m_pnUplNextId;
	LPLONG m_pnNextSharedMemId;
	LPBYTE m_pbFileCellBusy;	
	vmsSharedData m_shdata;
	static DWORD WINAPI _threadSaveAll (LPVOID lp);
	int m_nFile;
	int m_cDontSaveUploads;
	HANDLE m_mxAccFiles;
	BOOL LoadUploads (HANDLE hFile, BOOL bCompletedOnly, WORD wVer);
	BOOL SaveUploads (HANDLE hFile);
	static DWORD WINAPI _threadDeleteUploads (LPVOID lp);
	void OnMessageRecieved (vmsUploadSmartPtr upl, LPCSTR pszText, fsInternetUploaderMessageType enType);
	DWORD Event (vmsUploadSmartPtr upl, fsUploadsMgrEvent ev, LPVOID pData = NULL);
	static DWORD _UploadMgrEvents(fsUploadMgr*, fsUploadMgrEvent, DWORD dwData, LPVOID pData, LPVOID);
	UPLS_LIST m_vUploads;
	fntUploadsMgrEventFunc m_pfnEvents;
	LPVOID m_lpEventParam;
};

#endif 

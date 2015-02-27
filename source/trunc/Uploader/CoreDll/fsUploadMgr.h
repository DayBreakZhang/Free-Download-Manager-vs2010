/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSUPLOADMGR_H__327B20A7_55A2_480F_8B44_34287E7713E1__INCLUDED_)
#define AFX_FSUPLOADMGR_H__327B20A7_55A2_480F_8B44_34287E7713E1__INCLUDED_

#include "fsSpeedMeter.h"	
#include "fsInternetUploader.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsObject.h"
#include <vector>
#include <fsString.h>
#include "vmsUploadPackageImpl.h"

enum fsUploadMgrEvent
{
	UMGRE_UPLOADER_EVENT,
	UMGRE_BEFORE_UPLOAD,
	UMGRE_ZIP_FILES_START,
	UMGRE_ZIP_FILES_DONE,
	UMGRE_ZIP_FILES_FAILED,
	UMGRE_CRC_UPLOAD_FILE,
	UMGRE_CRC_UPLOAD_FILE_FAILED,
	UMGRE_CRC_UPLOAD_FILE_DONE,
	UMGRE_REQ_UPLOAD_INIT,
	UMGRE_REQ_UPLOAD_INIT_DONE,
	UMGRE_REQ_UPLOAD_INIT_FAILED,
	UMGRE_STARTING_UPLOAD_FILE,
	UMGRE_SENDING_UPLOAD_DETAILS,
	UMGRE_SENDING_UPLOAD_DETAILS_DONE,
	UMGRE_SENDING_UPLOAD_DETAILS_FAILED,
	UMGRE_VALIDATING_UPLOAD,
	UMGRE_NEED_ASK_CAPTCHA_VALUE,
	UMGRE_VALIDATING_UPLOAD_DONE,
	UMGRE_VALIDATING_UPLOAD_FAILED,
	UMGRE_STOPPED_OR_DONE,
	UMGRE_UPLOADER_STOPPED_OR_DONE,
};

typedef DWORD (*fntUploadMgrEventFunc)(class fsUploadMgr*, fsUploadMgrEvent, DWORD dwData, LPVOID pData, LPVOID);

class fsUploadMgr : public vmsObject 
{
public:
	fsString get_UploadName();
	BOOL Load (HANDLE hFile);
	BOOL Save (HANDLE hFile);
	void DeleteZipFile();
	vmsUploadPackageImpl* get_Package();
	fsInternetUploader* GetUploader();
	LPCSTR GetUploadingFile();
	LPCSTR get_PackageUrl();
	LPCSTR get_PackageName();
	DWORD GetSpeed();
	UINT64 GetUploadedByteCount();
	UINT64 GetTotalSize();
	BOOL IsDone();
	void SetEventFunc (fntUploadMgrEventFunc pfn, LPVOID lpParam);
	double GetProgress();
	void StopUploading(BOOL bWaitStop = FALSE);
	void StartUploading(BOOL bRequestUploadUrlOnly = FALSE);
	BOOL IsRunning();
	
	void Create (vmsUploadPackageImpl *pkg);
	fsUploadMgr();
	virtual ~fsUploadMgr();

protected:
	BOOL Load_Package (HANDLE hFile);
	BOOL Save_Package (HANDLE hFile);
	void AddItemToZipContentsDescHtml (LPCSTR pszName, UINT64 uSize);
	BOOL CalculateUploadFileCrc32();
	DWORD m_dwUploadFileCrc32;
	BOOL m_bUploadFileCrc32IsValid;
	BOOL m_bRequestUploadUrlOnly;
	BOOL m_bZipFileCreated;
	BOOL m_bCaptchaValidated;
	fsInternetResult ValidateCaptcha();
	CString m_strZipContentsDescHtml;
	fsInternetURLFile m_networkOpFile;
	fsInternetResult SendUploadDetails();
	fsString m_strDetailsScriptUrl;
	BOOL m_bDetailsWasSent;
	fsString m_strDownloadUrl;
	fsString m_strCaptchaUrl, m_strCaptchaValidateUrl;
	int m_nFileId;
	static DWORD WINAPI _threadUploadMgr (LPVOID lp);
	BOOL RequestUploadInfo_parse (LPCSTR psz);
	fsInternetURLFileDownloader m_memDldr;
	fsInternetResult RequestUploadInfo();
	bool m_bNeedStop;
	bool m_bRunning;
	DWORD Event (fsUploadMgrEvent, DWORD dwData = 0, LPVOID pData = NULL);
	BOOL Zip_AddFolder (void *zip, LPCSTR pszFolder, LPCSTR pszFolderNameInZip, int nDepth);
	BOOL Zip_AddFile (void *zip, LPCSTR pszFile, LPCSTR pszNameInZip);
	BOOL ZipFiles ();
	vmsUploadPackageImpl m_pkg;
	fsString m_strUploadFile;
	fsString m_strUploadUrl;
	fntUploadMgrEventFunc m_pfnEventHandler;
	LPVOID m_lpEventParam;
	static DWORD _UploaderEvents (fsInternetUploader* upldr, fsInternetUploaderEvent ev, LPVOID pData, LPVOID lpThis);
	fsInternetUploader m_upldr;
	long m_cThreads;
};

#endif 

/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSINTERNETUPLOADER_H__FD40E657_F6CF_49A1_875E_7F2A2D1D141C__INCLUDED_)
#define AFX_FSINTERNETUPLOADER_H__FD40E657_F6CF_49A1_875E_7F2A2D1D141C__INCLUDED_

#include "UploadProperties.h"	
#include "fsSpeedMeter.h"	

#if _MSC_VER > 1000
#pragma once
#endif 

enum fsInternetUploaderEvent
{
	IUE_OPENINGFILEONDISK,			
	IUE_FILE_WAS_OPENED,
	IUE_E_FAILEDTOOPENSRCFILE,		
	IUE_E_SRCFILESIZEWASCHANGED,	
	IUE_CONNECTING,					
	IUE_CONNECTED,
	IUE_MESSAGE,					
	IUE_PAUSEMODE,					
	IUE_E_UNEXPECTED,
	IUE_UPLOADSTOPPEDORDONE,
};

enum fsInternetUploaderMessageType
{
	EDT_INQUIRY,			
	EDT_RESPONSE_S,			
	EDT_RESPONSE_E,			
	EDT_DONE,				
	EDT_WARNING,			
	EDT_INQUIRY2,			
	EDT_RESPONSE_S2,		
};

struct fsInternetUploaderMessage
{
	LPCSTR pszText;
	fsInternetUploaderMessageType enType;
};

typedef DWORD (*fntInternetUploaderEventFunc)(class fsInternetUploader*, fsInternetUploaderEvent, LPVOID pData, LPVOID);

class fsInternetUploader
{
public:
	BOOL Load (HANDLE hFile);
	BOOL Save (HANDLE hFile);
	LPCSTR get_UploadFileName();
	float GetProgress();
	UINT GetSpeed();
	UINT64 GetFileSize();
	UINT64 GetCurrentPosition ();
	fsUpload_Properties* GetUP();
	fsInternetResult CreateForFile (LPCSTR pszFileName, LPCSTR pszUploadUrl);
	BOOL IsDone();
	BOOL IsRunning();
	void SetEventFunc (fntInternetUploaderEventFunc pfn, LPVOID lpParam);
	void StopUploading (BOOL bWaitStop = FALSE);
	void StartUploading ();
	fsInternetUploader();
	virtual ~fsInternetUploader();

protected:
	DWORD m_dwUploadPartSize;
	fsSpeedMeter m_speed;
	DWORD Event (fsInternetUploaderEvent ev, LPVOID pData = NULL);
	BOOL DoSleep ();
	UINT64 m_uPosition; 
	UINT64 m_uFileSize;
	static DWORD WINAPI _threadUploading (LPVOID lp);
	BOOL m_bRunning;
	static void _InetFileDialogFunc(fsInetFileDialogDirection dir, LPCSTR pszMsg, LPVOID lp1, LPVOID lp2);
	BOOL m_bNeedStop;
	void ApplyProxySettings(fsInternetSession *pSession, fsUpload_NetworkProperties* unp);
	void ApplyProperties(fsInternetURLFile *pFile, fsUpload_NetworkProperties* dnp);
	fsInternetURLFile *m_pInetFile;
	fsInternetResult OpenUrl ();
	fsUpload_Properties m_unp;
	fntInternetUploaderEventFunc m_pfnEvents;
	LPVOID m_lpEventParam;
};

#endif 

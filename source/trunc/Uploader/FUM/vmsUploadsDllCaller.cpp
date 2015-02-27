/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsUploadsDllCaller.h"
#include "resource.h"
#include "mfchelp.h"
#include "MainFrm.h"
#include "fum.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsUploadsDllCaller::vmsUploadsDllCaller()
{

}

vmsUploadsDllCaller::~vmsUploadsDllCaller()
{

}

LPCSTR vmsUploadsDllCaller::GetTranslatedString(int nId)
{
	return LS (nId);
}

vmsUploadsDll::vmsDllCallerSettings* vmsUploadsDllCaller::GetSettings()
{
	return &m_stgs;
}

BOOL fsIRToStr (fsInternetResult ir, LPSTR pszStr, UINT uMaxSize)
{
	LPCSTR pszDesc;

	switch (ir)
	{
		case IR_WININETUNKERROR:
		case IR_ERROR:
			pszDesc = LS (L_UNKNETERR);
			break;

		case IR_LOGINFAILURE:
			pszDesc = LS (L_INVLOGIN);
			break;

		case IR_INVALIDPASSWORD:
			pszDesc = LS (L_INVPWD);
			break;

		case IR_SUCCESS:
			pszDesc = LS (L_SUCCESS);
			break;

		case IR_CANTCONNECT:
			pszDesc = LS (L_CANTCONNECT);
			break;

		case IR_FILENOTFOUND:
			pszDesc = LS (L_NOTFOUND);
			break;

		case IR_LOSTCONNECTION:
			pszDesc = LS (L_CONNWASLOST);
			break;

		case IR_TIMEOUT:
			pszDesc = LS (L_NOTRESPONSE);
			break;

		case IR_NAMENOTRESOLVED:
			pszDesc = LS (L_NOTRESOLVED);
			break;

		case IR_RANGESNOTAVAIL:
			pszDesc = LS (L_NORESUME);
			break;

		case IR_DOUBTFUL_RANGESRESPONSE:
			pszDesc = LS (L_DOUBTFULRANGESRESPONSE);
			break;

		case IR_PROXYAUTHREQ:
			pszDesc = LS (L_PROXYLOGINREQ);
			break;

		case IR_EXTERROR:
			pszDesc = LS (L_EXTERR);
			break;

		case IR_SERVERBADREQUEST:
			pszDesc = LS (L_BADREQ);
			break;

		case IR_SERVERUNKERROR:
			pszDesc = LS (L_UNKSERVERR);
			break;

		case IR_CONNECTIONABORTED:
			pszDesc = LS (L_CONNABORTED);
			break;

		case IR_BADURL:
			pszDesc = LS (L_BADURL);
			break;

		case IR_NOINTERNETCONNECTION:
			pszDesc = LS (L_NOINETCONN);
			break;

		case IR_HTTPVERNOTSUP:
			pszDesc = LS (L_HTTPNOTSUPP);
			break;

		default:
			pszDesc = LS (L_UNKERR);
	}

	if (strlen (pszDesc) >= uMaxSize)
		return FALSE;

	strcpy (pszStr, pszDesc);

	return TRUE;
}

void vmsUploadsDllCaller::IRToStr(int ir, char *sz, UINT cch)
{
	fsIRToStr ((fsInternetResult)ir, sz, cch);
}

HBITMAP vmsUploadsDllCaller::GetBitmap(vmsUploadsDll::vmsWhichBitmap enBmp)
{
	UINT nId = 0;

	switch (enBmp)
	{
	case vmsUploadsDll::BMP_FOR_UPLOADSMENU:
		nId = IDB_TOOL_DLD_16; break;

	case vmsUploadsDll::BMP_FOR_UPLOADSMENU_D:
		nId = IDB_TOOL_DLD_16_D; break;

	case vmsUploadsDll::BMP_FOR_TASKSLIST: 
		nId = IDB_DOWNLOADSTASKS; break;

	case vmsUploadsDll::BMP_FOR_TASKSLIST_SEL: 
		nId = IDB_DOWNLOADSTASKS_SEL; break;

	case vmsUploadsDll::BMP_FOR_LOGLIST: 
		nId = IDB_LOGSTATES; break;
	}

	
	return LoadBitmap (AfxGetInstanceHandle (), MAKEINTRESOURCE (nId));
}

vmsUploadsDll::vmsDllPersist* vmsUploadsDllCaller::GetPersist()
{
	return &m_persist;
}

void vmsUploadsDllCaller::GetDataFilePath(LPCSTR pszName, LPSTR pszResult)
{
	lstrcpy (pszResult, fsGetDataFilePath (pszName));
}

void vmsUploadsDllCaller::GetCommonFilesFolder(LPSTR pszResult)
{
	lstrcpy (pszResult, vmsGetAppFolder ());
}

extern CFUMApp theApp;
BOOL vmsUploadsDllCaller::OnBeforeUpload(LPSTR pszStopReason, bool* pbNeedStop)
{
	return ((CMainFrame*)theApp.m_pMainWnd)->OnBeforeUpload (pszStopReason, pbNeedStop);
}

vmsUploadsDll::vmsDllCallerEx* vmsUploadsDllCaller::GetExtendedFeatures()
{
	return NULL;
}

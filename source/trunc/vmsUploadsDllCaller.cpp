/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsUploadsDllCaller.h"
#include "inetutil.h"
#include "mfchelp.h"

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

void vmsUploadsDllCaller::IRToStr(int ir, char *sz, UINT cch)
{
	fsIRToStr ((fsInternetResult)ir, sz, cch);
}

HBITMAP vmsUploadsDllCaller::GetBitmap(vmsUploadsDll::vmsWhichBitmap enBmp)
{
	UINT nId = 0;
	BOOL bCheckAlpha = FALSE;

	switch (enBmp)
	{
	case vmsUploadsDll::BMP_FOR_UPLOADSMENU:
		bCheckAlpha = _SkinMgr.tbUseAlpha_ForAllPluginMenuImages ();
		nId = IDB_TOOL_DLD_16; break;

	case vmsUploadsDll::BMP_FOR_UPLOADSMENU_D:
		bCheckAlpha = _SkinMgr.tbUseAlpha_ForAllPluginMenuImages ();
		nId = IDB_TOOL_DLD_16_D; break;

	case vmsUploadsDll::BMP_FOR_TASKSLIST:
		nId = IDB_DOWNLOADSTASKS; break;

	case vmsUploadsDll::BMP_FOR_TASKSLIST_SEL:
		nId = IDB_DOWNLOADSTASKS_SEL; break;

	case vmsUploadsDll::BMP_FOR_LOGLIST: 
		nId = IDB_LOGSTATES; break;
	}

	HBITMAP hbm = SBMP  (nId);

	if (bCheckAlpha && _TB_USE_ALPHA)
	{
		CBitmap bmp; bmp.Attach (hbm);
		ConvertBmp32WithAlphaToBmp32WithoutAlpha (bmp, GetSysColor (COLOR_MENU));
		hbm = (HBITMAP)bmp.Detach ();
	}

	return hbm;
}

vmsUploadsDll::vmsDllPersist* vmsUploadsDllCaller::GetPersist()
{
	return &m_persist;
}

void vmsUploadsDllCaller::GetDataFilePath(LPCSTR pszName, LPSTR pszResult)
{
	lstrcpy (pszResult, fsGetDataFilePath (pszName));
}

void vmsUploadsDllCaller::GetCommonFilesFolder(LPSTR psz)
{
	lstrcpy (psz, fsGetFumProgramFilesFolder ());
}

BOOL vmsUploadsDllCaller::OnBeforeUpload(LPSTR, bool*)
{
	return TRUE;
}

vmsUploadsDll::vmsDllCallerEx* vmsUploadsDllCaller::GetExtendedFeatures()
{
	return NULL;
}

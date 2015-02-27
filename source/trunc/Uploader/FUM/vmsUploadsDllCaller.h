/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSUPLOADSDLLCALLER_H__0DB1F7B9_7EE8_4D15_8ABE_68D1D244F6D7__INCLUDED_)
#define AFX_VMSUPLOADSDLLCALLER_H__0DB1F7B9_7EE8_4D15_8ABE_68D1D244F6D7__INCLUDED_

#include "vmsUploadsDllCallerSettings.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

#include "..\CoreDll\dll.h"
#include "vmsUploaderDllPersist.h"	

class vmsUploadsDllCaller : public vmsUploadsDll::vmsDllCaller 
{
public:
	vmsUploadsDll::vmsDllCallerEx* GetExtendedFeatures();
	BOOL OnBeforeUpload (LPSTR pszStopReason, bool* pbNeedStop);
	void GetCommonFilesFolder (LPSTR pszResult);
	void GetDataFilePath(LPCSTR pszName, LPSTR pszResult);
	
	vmsUploadsDll::vmsDllPersist* GetPersist();
	
	HBITMAP GetBitmap (vmsUploadsDll::vmsWhichBitmap enBmp);
	
	void IRToStr (int ir, char *sz, UINT cch);
	
	virtual vmsUploadsDll::vmsDllCallerSettings* GetSettings();
	
	virtual LPCSTR GetTranslatedString (int nId);

	vmsUploadsDllCaller();
	virtual ~vmsUploadsDllCaller();

protected:
	
	vmsUploaderDllPersist m_persist;
	
	vmsUploadsDllCallerSettings m_stgs;
};

#endif 

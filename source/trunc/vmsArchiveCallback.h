/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSARCHIVECALLBACK_H__7EC4DC57_1869_4484_84A2_DFBEB2BE063C__INCLUDED_)
#define AFX_VMSARCHIVECALLBACK_H__7EC4DC57_1869_4484_84A2_DFBEB2BE063C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

enum vmsAC_ExtractResult {
	AC_ER_OK,
	AC_ER_FAILED
};

enum vmsAC_OverwriteMode {
	AC_OM_OVERWRITE,
	AC_OM_SKIP,
	AC_OM_CANCEL,
};

struct vmsOverwriteFileInfo {
	LPCSTR pszFile;
	UINT64* puNewSize;	
	FILETIME* ptimeNewLastWrite;
};

class vmsArchiveCallback  
{
public:
	
	
	virtual void AskOverwrite (vmsOverwriteFileInfo& ofi, vmsAC_OverwriteMode& enOM, bool& bForAll) = NULL;
	
	virtual bool BeforeExtract (LPCSTR pszFile) = NULL;
	
	virtual bool AfterExtract (LPCSTR pszFile, vmsAC_ExtractResult res) = NULL;
	
	virtual bool SetProgress (int nProgress) = NULL;

	vmsArchiveCallback();
	virtual ~vmsArchiveCallback();
};

#endif 

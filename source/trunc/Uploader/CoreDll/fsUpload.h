/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FS_UPLOAD_
#define __FS_UPLOAD_

#include "vmsObjectSmartPtr.h"
#include "fsInternetUploader.h"
#include "fsEventsMgr.h"
#include "fsUploadMgr.h"

typedef vmsObjectSmartPtr <fsInternetUploader> vmsInternetUploaderSmartPtr;
typedef vmsObjectSmartPtr <fsUploadMgr> vmsUploadMgrSmartPtr;

#define US_UPLOADINGDLGISSHOWN		1

#define UF_DONTSAVETOFILE			1
#define UF_READONLY					(1 << 1)
#define UF_DONTNOTIFYABOUTDELETE	(1 << 2)

struct fsUpload : public vmsObject
{
	vmsUploadMgrSmartPtr pMgr;
	fsEventsMgr log;	
	BOOL bAutostart;	
	UINT nID;			
	DWORD dwFlags;		
	DWORD dwState;		
	DWORD dwReserved;
	FILETIME dateAdded;	
};

typedef vmsObjectSmartPtr <fsUpload> vmsUploadSmartPtr;

inline void Upload_CreateInstance (vmsUploadSmartPtr &ptr)
{
	ptr.CreateInstance ();
	ptr->pMgr.CreateInstance ();
}

typedef std::vector <vmsUploadSmartPtr> UPLS_LIST, &UPLS_LIST_REF;

#endif 
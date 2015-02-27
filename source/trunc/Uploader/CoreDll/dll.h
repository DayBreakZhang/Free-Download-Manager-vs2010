/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __UPLOADS_DLL_H_
#define __UPLOADS_DLL_H_

namespace vmsUploadsDll
{

const int DLL_INTERFACE_VERSION = 2;
const int DLL_BUILD_NUMBER = 640;

const char* const MSG_NAME_1 = "msg - fumcore - uplds deleted";

#include "vmsUploadsWnd.h"
#include "vmsDllCaller.h"

typedef void (*FNSDC)(vmsDllCaller*);

typedef vmsUploadsWnd* (*FNCUW)(CWnd *pwndParent);

typedef void (*FNSIS) (CWnd *pwndParent);

typedef void (*FNEI) (BOOL bEnable, DWORD dwReserved);

typedef void (*FNGV) (DWORD *dwMajorVersion, DWORD *dwMinorVersion);

};

#endif 
#ifndef __FDM_H_
#define __FDM_H_


// FDM's Plugins API version
#define FDMSDK_MAJOR_VERSION		0
#define FDMSDK_MINOR_VERSION		9


#include "fdmdlsmgr.h"

class vmsFdmApi
{
public:
	virtual vmsFdmApiDownloadsMgr* getDownloadsMgr () = NULL;
	virtual UINT getFdmBuildNumber () = NULL;
	virtual HWND getFdmWindowHandle () = NULL;
	virtual void ShutdownFdm () = NULL;
};


#endif //__FDM_H_
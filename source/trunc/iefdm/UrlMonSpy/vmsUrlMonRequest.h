/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __URMLON_REQUEST__
#define __URMLON_REQUEST__

#include "vmsObject.h"

class vmsUrlMonRequest : public vmsObject
{
public:
	virtual LPCWSTR getUrl () const = NULL;
	virtual LPCWSTR getRedirectedUrl () const = NULL;
	virtual LPCWSTR getSrcTabUrl () const = NULL;
	virtual LPCSTR getRequestHeaders () const = NULL;
	virtual LPCSTR getResponseHeaders () const = NULL;
	virtual bool isCompleted () const = NULL;
	virtual LPBYTE getPostData () const = NULL;
	virtual DWORD getPostDataSize () const = NULL;
	virtual bool isSrcTabCalculated () const = NULL;
};

typedef vmsObjectSmartPtr <vmsUrlMonRequest> vmsUrlMonRequestPtr;

#endif 
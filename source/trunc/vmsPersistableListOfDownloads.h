/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef PERSISTABLE_LIST_OF_DOWNLOADS_INCLUDED_FILE
#define PERSISTABLE_LIST_OF_DOWNLOADS_INCLUDED_FILE

#include "fsDownload.h"
#include "vmsPersistObject.h"

class vmsDownloadList : public vmsPersistObjectsArray <vmsDownloadSmartPtr>
{
public:
	vmsDownloadList();
	virtual ~vmsDownloadList();
	virtual void getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage);
	virtual bool loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer);
	vmsDownloadList& operator = (const DLDS_LIST& v);
	vmsDownloadList& operator = (const vmsDownloadList& listObj);
	void resetDirty();
	void Copy(DLDS_LIST& v);
};

#endif

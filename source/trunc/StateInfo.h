/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef STATEINFO_INCLUDED_FILE
#define STATEINFO_INCLUDED_FILE

#include "vmsPersistObject.h"
#include "vmsFileRecentList.h"

class CStateInfo : public vmsPersistObject
{
public:
	CStateInfo();
	virtual ~CStateInfo();
	void SetId(LONG nId);
	LONG IncId();
	LONG IncIdSafely();
	LONG GetId() const;
	vmsFileRecentList& GetFileRecentList();

	virtual void getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage);
	virtual bool loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer);

protected:
	LONG m_nId;
	vmsFileRecentList m_frlFileRecentList;
};

#endif

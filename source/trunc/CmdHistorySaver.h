/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef CMDHISTORYSAVER_INCLUDED_FILE
#define CMDHISTORYSAVER_INCLUDED_FILE

#include "vmsPersistObject.h"

#define HISTFILE_CURRENT_VERSION	(2)

#define HISTFILE_SIG "FDM History"

struct fsHistFileHdr
{
	char szSig [sizeof (HISTFILE_SIG) + 1];
	WORD wVer;

	fsHistFileHdr ()
	{
		strcpy (szSig, HISTFILE_SIG);
		wVer = HISTFILE_CURRENT_VERSION;
	}
};

class CCmdHistorySaver : public vmsPersistObject
{
public:
	static CCmdHistorySaver& Instance();
	virtual ~CCmdHistorySaver();
	void Save();
	void Load();
	virtual void getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage);
	virtual bool loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer);

protected:
	CCmdHistorySaver();
	CCmdHistorySaver(const CCmdHistorySaver&);
	CCmdHistorySaver& operator = (const CCmdHistorySaver&);
};

#endif

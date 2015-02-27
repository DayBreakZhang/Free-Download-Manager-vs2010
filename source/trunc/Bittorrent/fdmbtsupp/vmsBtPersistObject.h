/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

class vmsBtPersistObject
{
public:
	
	virtual bool isDirty () = NULL;
	
	
	
	
	
	
	virtual void getStateBuffer (LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage) = NULL;
};
/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FDMBTOBJECT_H_
#define __FDMBTOBJECT_H_

class vmsFdmBtObject
{
public:
	virtual void AddRef () = NULL;
	virtual void Release () = NULL;
};

#endif 
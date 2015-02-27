/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FDMFIREFOXEXTENSION_H_
#define __FDMFIREFOXEXTENSION_H_

#include "common.h"

#define FDMFIREFOXEXTENSION_CONTRACTID "@freedownloadmanager.org/FDMFirefoxExtension;1"
#define FDMFIREFOXEXTENSION_CLASSNAME "Free Download Manager extension component for Firefox"

#define FDMFIREFOXEXTENSION_CID { 0xf574eac, 0x54a5, 0x48e0, { 0x95, 0x49, 0x4f, 0xba, 0xa2, 0x14, 0x62, 0x62 } }

class CFDMFirefoxExtension : public IFDMFirefoxExtension
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IFDMFIREFOXEXTENSION

  CFDMFirefoxExtension();

private:
  ~CFDMFirefoxExtension();

protected:
	static nsISupports* _pLastPost;
};

#endif 
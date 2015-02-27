/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FDMURL_H_
#define __FDMURL_H_

#include "common.h"

#define FDMURL_CONTRACTID "@freedownloadmanager.org/FDMUrl;1"
#define FDMURL_CLASSNAME "Free Download Manager Url component for Firefox"

#define FDMURL_CID { 0xde19d41e, 0xecd8, 0x4e0b, { 0x99, 0x0, 0xa2, 0x3b, 0x65, 0xe0, 0x12, 0x5e } }

#include <windows.h>
#include <fsString.h>
#include <comutil.h>
#include <string>

class CFDMUrl : public IFDMUrl
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IFDMURL

  CFDMUrl();

private:
  ~CFDMUrl();

protected:
	std::wstring m_wstrUrl;
	std::wstring m_wstrReferer;
	std::wstring m_wstrComment;
	std::wstring m_wstrCookies;
	std::wstring m_wstrPostData;
	std::wstring m_wstrUserAgent, m_wstrOriginalUrl;
};

#endif 
/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FDMFORFIREFOX_H_
#define __FDMFORFIREFOX_H_

#include "common.h"
#include <atlbase.h>
#include <string>
#include <vector>
#include "vmsObject.h"
#include <assert.h>
#include "vmsCriticalSection.h"
#include "vmsbrowseractivitymonitor.h"

using namespace std;

#define FDMFORFIREFOX_CONTRACTID "@freedownloadmanager.org/FDMForFirefox;1"
#define FDMFORFIREFOX_CLASSNAME "Free Download Manager component for Firefox"

#define FDMFORFIREFOX_CID { 0x2b141cfe, 0xd16c, 0x499a, { 0x91, 0x5, 0x6, 0xab, 0xdc, 0xe9, 0x85, 0x66 } }

class CFDMForFirefox : public IFDMForFirefox
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IFDMFORFIREFOX

  static bool is_FlashGotInstalled();

  CFDMForFirefox();

private:
  ~CFDMForFirefox();

protected:
	struct threadOnDownloadItBtnClicked_a_params 
	{
		class vmsFlvSniffDll *pSniffDll;
		LPCSTR pszUrl;
		LPCSTR pszFrameUrl;
		LPCSTR pszSwfUrl;
		LPCSTR pszFlashVars;
		LPCSTR pszOtherSwfUrls;
		LPCSTR pszOtherFlashVars;
		HANDLE hevCloseDlg;
	};
	static DWORD WINAPI _threadOnDownloadItBtnClicked_a (LPVOID lp);
	struct _threadOnDownloadItBtnClicked_param {
		CFDMForFirefox *pthis;
		std::string strUrl;
		std::string strFrameUrl;
		std::string strSwfUrl;
		std::string strFlashVars;
		std::string strOtherSwfUrls;
		std::string strOtherFlashVars;
		HWND hwndParent;
	};
	static DWORD WINAPI _threadOnDownloadItBtnClicked (LPVOID lp);
	XULSDK_PRBool TransferUrlToFDM (IFDMUrl* url);
	bool IsUrlShouldBeSkipped (IFDMUrl *url, const PRUnicharIDL* pwszSuggFileName);
	bool IsServerToSkip (IFDMUrl *url);
	CRegKey m_keyFDM, m_keyFDMMonitor, m_keyFDMFfStgs;
};

#endif 
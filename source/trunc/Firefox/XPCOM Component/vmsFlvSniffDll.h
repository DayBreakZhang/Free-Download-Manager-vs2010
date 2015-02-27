/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSFLVSNIFFDLL_H__764CC7C6_4DE9_42E1_B040_6C7AF2A82C36__INCLUDED_)
#define AFX_VMSFLVSNIFFDLL_H__764CC7C6_4DE9_42E1_B040_6C7AF2A82C36__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <windows.h>

class vmsFlvSniffDll  
{
public:
	enum ButtonResult
	{
		NONE,
		SUCCEEDED,
		E_SNIFF_MODULE_NOT_FOUND,
		E_FAILED,
		E_NO_FLV_FOUND,
		E_URL_NOT_FOUND,
	};
public:
	static void OnNewHttpRequest (LPCSTR pszUrl, LPCSTR pszSrcTabUrl);
	static void onHttpDialogClosed (UINT nUID);
	static void onHttpDialogDataReceived (UINT nUID, LPBYTE pbData, UINT nSize);
	static UINT onNewHttpDialog (LPCSTR pszUrl, LPCSTR pszRequestHdrs, LPCSTR pszRespHdrs);
	void OnDownloadItBtnClicked_ShowMsgIfReq (HWND hwndParent) const;
	BOOL IsVideoFlash (const char* pszWebPageUrl, const char* pszFrameUrl, const char* pszSwfUrl, const char* pszFlashVars, const char* pszOtherSwfUrls, const char* pszOtherFlashVars);
	void OnDownloadItBtnClicked3 (const char* pszWebPageUrl, const char* pszFrameUrl, const char* pszSwfUrl, const char* pszFlashVars, const char* pszOtherSwfUrls, const char* pszOtherFlashVars);
	void OnDownloadItBtnClicked2 (const char* pszWebPageUrl, const char* pszSwfUrl, const char* pszFlashVars);
	void OnDownloadItBtnClicked (const char* pszWebPageUrl);
	vmsFlvSniffDll();
	virtual ~vmsFlvSniffDll();

protected:
	HRESULT m_hrLast;
	ButtonResult m_enBR;

};

#endif 

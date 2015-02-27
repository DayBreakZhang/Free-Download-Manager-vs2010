/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSFLVSNIFFDLL_H__764CC7C6_4DE9_42E1_B040_6C7AF2A82C36__INCLUDED_)
#define AFX_VMSFLVSNIFFDLL_H__764CC7C6_4DE9_42E1_B040_6C7AF2A82C36__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

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
	static BOOL IsVideoFlash (const char* pszWebPageUrl, const char* pszFrameUrl, const char* pszSwfUrl, const char* pszFlashVars, const char* pszOtherSwfUrls, const char* pszOtherFlashVars);
	void OnDownloadItBtnClicked_ShowMsgIfReq (HWND hwndParent) const;
	void OnDownloadItBtnClicked (LPCSTR pszWebPageUrl, LPCSTR pszFrameUrl, LPCSTR pszSwfUrl, LPCSTR pszFlashVars, LPCSTR pszOtherSwfUrls, LPCSTR pszOtherFlashVars);
	vmsFlvSniffDll();
	virtual ~vmsFlvSniffDll();

protected:
	HRESULT m_hrLast;
	ButtonResult m_enBR;

};

#endif 

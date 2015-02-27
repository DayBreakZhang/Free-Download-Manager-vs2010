/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __gen_ivmsfdmff_h__
#define __gen_ivmsfdmff_h__

#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

#define IFDMURL_IID_STR "7e3effb1-64c0-412b-8515-542029434669"

#define IFDMURL_IID \
  {0x7e3effb1, 0x64c0, 0x412b, \
    { 0x85, 0x15, 0x54, 0x20, 0x29, 0x43, 0x46, 0x69 }}

class NS_NO_VTABLE NS_SCRIPTABLE IFDMUrl : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IFDMURL_IID)

  
  NS_SCRIPTABLE NS_IMETHOD GetUrl(PRUnichar **aUrl) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetUrl(const PRUnichar *aUrl) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD GetReferer(PRUnichar **aReferer) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetReferer(const PRUnichar *aReferer) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD GetComment(PRUnichar **aComment) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetComment(const PRUnichar *aComment) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD GetCookies(PRUnichar **aCookies) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCookies(const PRUnichar *aCookies) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD GetPostData(PRUnichar **aPostData) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPostData(const PRUnichar *aPostData) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD GetUserAgent(PRUnichar **aUserAgent) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetUserAgent(const PRUnichar *aUserAgent) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD GetOriginalUrl(PRUnichar **aOriginalUrl) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOriginalUrl(const PRUnichar *aOriginalUrl) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(IFDMUrl, IFDMURL_IID)

#define NS_DECL_IFDMURL \
  NS_SCRIPTABLE NS_IMETHOD GetUrl(PRUnichar **aUrl); \
  NS_SCRIPTABLE NS_IMETHOD SetUrl(const PRUnichar *aUrl); \
  NS_SCRIPTABLE NS_IMETHOD GetReferer(PRUnichar **aReferer); \
  NS_SCRIPTABLE NS_IMETHOD SetReferer(const PRUnichar *aReferer); \
  NS_SCRIPTABLE NS_IMETHOD GetComment(PRUnichar **aComment); \
  NS_SCRIPTABLE NS_IMETHOD SetComment(const PRUnichar *aComment); \
  NS_SCRIPTABLE NS_IMETHOD GetCookies(PRUnichar **aCookies); \
  NS_SCRIPTABLE NS_IMETHOD SetCookies(const PRUnichar *aCookies); \
  NS_SCRIPTABLE NS_IMETHOD GetPostData(PRUnichar **aPostData); \
  NS_SCRIPTABLE NS_IMETHOD SetPostData(const PRUnichar *aPostData); \
  NS_SCRIPTABLE NS_IMETHOD GetUserAgent(PRUnichar **aUserAgent); \
  NS_SCRIPTABLE NS_IMETHOD SetUserAgent(const PRUnichar *aUserAgent); \
  NS_SCRIPTABLE NS_IMETHOD GetOriginalUrl(PRUnichar **aOriginalUrl); \
  NS_SCRIPTABLE NS_IMETHOD SetOriginalUrl(const PRUnichar *aOriginalUrl); 

#define NS_FORWARD_IFDMURL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetUrl(PRUnichar **aUrl) { return _to GetUrl(aUrl); } \
  NS_SCRIPTABLE NS_IMETHOD SetUrl(const PRUnichar *aUrl) { return _to SetUrl(aUrl); } \
  NS_SCRIPTABLE NS_IMETHOD GetReferer(PRUnichar **aReferer) { return _to GetReferer(aReferer); } \
  NS_SCRIPTABLE NS_IMETHOD SetReferer(const PRUnichar *aReferer) { return _to SetReferer(aReferer); } \
  NS_SCRIPTABLE NS_IMETHOD GetComment(PRUnichar **aComment) { return _to GetComment(aComment); } \
  NS_SCRIPTABLE NS_IMETHOD SetComment(const PRUnichar *aComment) { return _to SetComment(aComment); } \
  NS_SCRIPTABLE NS_IMETHOD GetCookies(PRUnichar **aCookies) { return _to GetCookies(aCookies); } \
  NS_SCRIPTABLE NS_IMETHOD SetCookies(const PRUnichar *aCookies) { return _to SetCookies(aCookies); } \
  NS_SCRIPTABLE NS_IMETHOD GetPostData(PRUnichar **aPostData) { return _to GetPostData(aPostData); } \
  NS_SCRIPTABLE NS_IMETHOD SetPostData(const PRUnichar *aPostData) { return _to SetPostData(aPostData); } \
  NS_SCRIPTABLE NS_IMETHOD GetUserAgent(PRUnichar **aUserAgent) { return _to GetUserAgent(aUserAgent); } \
  NS_SCRIPTABLE NS_IMETHOD SetUserAgent(const PRUnichar *aUserAgent) { return _to SetUserAgent(aUserAgent); } \
  NS_SCRIPTABLE NS_IMETHOD GetOriginalUrl(PRUnichar **aOriginalUrl) { return _to GetOriginalUrl(aOriginalUrl); } \
  NS_SCRIPTABLE NS_IMETHOD SetOriginalUrl(const PRUnichar *aOriginalUrl) { return _to SetOriginalUrl(aOriginalUrl); } 

#define NS_FORWARD_SAFE_IFDMURL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetUrl(PRUnichar **aUrl) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUrl(aUrl); } \
  NS_SCRIPTABLE NS_IMETHOD SetUrl(const PRUnichar *aUrl) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUrl(aUrl); } \
  NS_SCRIPTABLE NS_IMETHOD GetReferer(PRUnichar **aReferer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReferer(aReferer); } \
  NS_SCRIPTABLE NS_IMETHOD SetReferer(const PRUnichar *aReferer) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReferer(aReferer); } \
  NS_SCRIPTABLE NS_IMETHOD GetComment(PRUnichar **aComment) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetComment(aComment); } \
  NS_SCRIPTABLE NS_IMETHOD SetComment(const PRUnichar *aComment) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetComment(aComment); } \
  NS_SCRIPTABLE NS_IMETHOD GetCookies(PRUnichar **aCookies) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCookies(aCookies); } \
  NS_SCRIPTABLE NS_IMETHOD SetCookies(const PRUnichar *aCookies) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCookies(aCookies); } \
  NS_SCRIPTABLE NS_IMETHOD GetPostData(PRUnichar **aPostData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPostData(aPostData); } \
  NS_SCRIPTABLE NS_IMETHOD SetPostData(const PRUnichar *aPostData) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPostData(aPostData); } \
  NS_SCRIPTABLE NS_IMETHOD GetUserAgent(PRUnichar **aUserAgent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUserAgent(aUserAgent); } \
  NS_SCRIPTABLE NS_IMETHOD SetUserAgent(const PRUnichar *aUserAgent) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUserAgent(aUserAgent); } \
  NS_SCRIPTABLE NS_IMETHOD GetOriginalUrl(PRUnichar **aOriginalUrl) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOriginalUrl(aOriginalUrl); } \
  NS_SCRIPTABLE NS_IMETHOD SetOriginalUrl(const PRUnichar *aOriginalUrl) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOriginalUrl(aOriginalUrl); } 

#if 0

class _MYCLASS_ : public IFDMUrl
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IFDMURL

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  
};

NS_IMPL_ISUPPORTS1(_MYCLASS_, IFDMUrl)

_MYCLASS_::_MYCLASS_()
{
  
}

_MYCLASS_::~_MYCLASS_()
{
  
}

NS_IMETHODIMP _MYCLASS_::GetUrl(PRUnichar **aUrl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetUrl(const PRUnichar *aUrl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::GetReferer(PRUnichar **aReferer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetReferer(const PRUnichar *aReferer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::GetComment(PRUnichar **aComment)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetComment(const PRUnichar *aComment)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::GetCookies(PRUnichar **aCookies)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetCookies(const PRUnichar *aCookies)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::GetPostData(PRUnichar **aPostData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetPostData(const PRUnichar *aPostData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::GetUserAgent(PRUnichar **aUserAgent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetUserAgent(const PRUnichar *aUserAgent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::GetOriginalUrl(PRUnichar **aOriginalUrl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetOriginalUrl(const PRUnichar *aOriginalUrl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

#endif

#define IFDMURLLISTRECEIVER_IID_STR "f89db1ad-64dd-4e7d-acc9-b3795b74833b"

#define IFDMURLLISTRECEIVER_IID \
  {0xf89db1ad, 0x64dd, 0x4e7d, \
    { 0xac, 0xc9, 0xb3, 0x79, 0x5b, 0x74, 0x83, 0x3b }}

class NS_NO_VTABLE NS_SCRIPTABLE IFDMUrlListReceiver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IFDMURLLISTRECEIVER_IID)

  
  NS_SCRIPTABLE NS_IMETHOD AddUrl(IFDMUrl *url) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD ShowAddUrlListDialog(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(IFDMUrlListReceiver, IFDMURLLISTRECEIVER_IID)

#define NS_DECL_IFDMURLLISTRECEIVER \
  NS_SCRIPTABLE NS_IMETHOD AddUrl(IFDMUrl *url); \
  NS_SCRIPTABLE NS_IMETHOD ShowAddUrlListDialog(void); 

#define NS_FORWARD_IFDMURLLISTRECEIVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddUrl(IFDMUrl *url) { return _to AddUrl(url); } \
  NS_SCRIPTABLE NS_IMETHOD ShowAddUrlListDialog(void) { return _to ShowAddUrlListDialog(); } 

#define NS_FORWARD_SAFE_IFDMURLLISTRECEIVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddUrl(IFDMUrl *url) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddUrl(url); } \
  NS_SCRIPTABLE NS_IMETHOD ShowAddUrlListDialog(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowAddUrlListDialog(); } 

#if 0

class _MYCLASS_ : public IFDMUrlListReceiver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IFDMURLLISTRECEIVER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  
};

NS_IMPL_ISUPPORTS1(_MYCLASS_, IFDMUrlListReceiver)

_MYCLASS_::_MYCLASS_()
{
  
}

_MYCLASS_::~_MYCLASS_()
{
  
}

NS_IMETHODIMP _MYCLASS_::AddUrl(IFDMUrl *url)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::ShowAddUrlListDialog()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

#endif

#define IFDMURLRECEIVER_IID_STR "1951e03a-2b97-4692-aa0b-1f0e316383ab"

#define IFDMURLRECEIVER_IID \
  {0x1951e03a, 0x2b97, 0x4692, \
    { 0xaa, 0x0b, 0x1f, 0x0e, 0x31, 0x63, 0x83, 0xab }}

class NS_NO_VTABLE NS_SCRIPTABLE IFDMUrlReceiver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IFDMURLRECEIVER_IID)

  
  NS_SCRIPTABLE NS_IMETHOD SetUrl(IFDMUrl *url) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD ShowAddDownloadDialog(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(IFDMUrlReceiver, IFDMURLRECEIVER_IID)

#define NS_DECL_IFDMURLRECEIVER \
  NS_SCRIPTABLE NS_IMETHOD SetUrl(IFDMUrl *url); \
  NS_SCRIPTABLE NS_IMETHOD ShowAddDownloadDialog(void); 

#define NS_FORWARD_IFDMURLRECEIVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetUrl(IFDMUrl *url) { return _to SetUrl(url); } \
  NS_SCRIPTABLE NS_IMETHOD ShowAddDownloadDialog(void) { return _to ShowAddDownloadDialog(); } 

#define NS_FORWARD_SAFE_IFDMURLRECEIVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetUrl(IFDMUrl *url) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUrl(url); } \
  NS_SCRIPTABLE NS_IMETHOD ShowAddDownloadDialog(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowAddDownloadDialog(); } 

#if 0

class _MYCLASS_ : public IFDMUrlReceiver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IFDMURLRECEIVER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  
};

NS_IMPL_ISUPPORTS1(_MYCLASS_, IFDMUrlReceiver)

_MYCLASS_::_MYCLASS_()
{
  
}

_MYCLASS_::~_MYCLASS_()
{
  
}

NS_IMETHODIMP _MYCLASS_::SetUrl(IFDMUrl *url)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::ShowAddDownloadDialog()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

#endif

#define IFDMFORFIREFOX_IID_STR "a2dedbb7-dd3a-4ff3-a1cc-75736fc557fa"

#define IFDMFORFIREFOX_IID \
  {0xa2dedbb7, 0xdd3a, 0x4ff3, \
    { 0xa1, 0xcc, 0x75, 0x73, 0x6f, 0xc5, 0x57, 0xfa }}

class NS_NO_VTABLE NS_SCRIPTABLE IFDMForFirefox : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IFDMFORFIREFOX_IID)

  
  NS_SCRIPTABLE NS_IMETHOD GetLngString(const char *strIDString, PRUnichar **_retval NS_OUTPARAM) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD IsContextMenuItemShouldBeHidden(const char *strMenuItemID, PRBool *_retval NS_OUTPARAM) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD IsALTShouldBePressed(PRBool *_retval NS_OUTPARAM) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD IsLinkShouldBeSkipped(IFDMUrl *url, const PRUnichar *wstrSuggFileName, PRBool *_retval NS_OUTPARAM) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD CatchLink(IFDMUrl *url, const PRUnichar *wstrSuggFileName, PRBool *_retval NS_OUTPARAM) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD IsDomainSupportedForVideoDownloads(const PRUnichar *wstrDomain, PRBool *_retval NS_OUTPARAM) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD ProcessVideoDocument(const PRUnichar *wstrDomain, const PRUnichar *wstrReferer, const PRUnichar *wstrHTML, PRBool *_retval NS_OUTPARAM) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD CreateVideoDownloadFromUrl(const PRUnichar *wstrUrl, PRBool *_retval NS_OUTPARAM) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD SetProxyType(PRInt32 nType) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD SetProxy(const char *strProtocol, const char *strAddr, PRInt32 nPort) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD CreateVideoDownloadFromUrl2(const PRUnichar *wstrUrl, const PRUnichar *wstrSwfUrl, const PRUnichar *wstrFlashVars, PRBool *_retval NS_OUTPARAM) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD CreateVideoDownloadFromUrl3(const PRUnichar *wstrUrl, const PRUnichar *wstrFrameUrl, const PRUnichar *wstrSwfUrl, const PRUnichar *wstrFlashVars, const PRUnichar *wstrOtherSwfUrls, const PRUnichar *wstrOtherFlashVars, PRBool *_retval NS_OUTPARAM) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD IsVideoFlash(const PRUnichar *wstrUrl, const PRUnichar *wstrFrameUrl, const PRUnichar *wstrSwfUrl, const PRUnichar *wstrFlashVars, const PRUnichar *wstrOtherSwfUrls, const PRUnichar *wstrOtherFlashVars, PRBool *_retval NS_OUTPARAM) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD OnNewHttpRequest(const PRUnichar *wstrUrl, const PRUnichar *wstrSourceTabUrl) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD OnHttpRedirect(const PRUnichar *wstrUrl, const PRUnichar *wstrOriginalUrl) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD DownloadComplete(const PRUnichar *wstrUrl) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD DownloadBegin(const PRUnichar *wstrUrl) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD OnHttpActivity(const PRUnichar *wstrUrl) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(IFDMForFirefox, IFDMFORFIREFOX_IID)

#define NS_DECL_IFDMFORFIREFOX \
  NS_SCRIPTABLE NS_IMETHOD GetLngString(const char *strIDString, PRUnichar **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsContextMenuItemShouldBeHidden(const char *strMenuItemID, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsALTShouldBePressed(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsLinkShouldBeSkipped(IFDMUrl *url, const PRUnichar *wstrSuggFileName, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CatchLink(IFDMUrl *url, const PRUnichar *wstrSuggFileName, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsDomainSupportedForVideoDownloads(const PRUnichar *wstrDomain, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ProcessVideoDocument(const PRUnichar *wstrDomain, const PRUnichar *wstrReferer, const PRUnichar *wstrHTML, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateVideoDownloadFromUrl(const PRUnichar *wstrUrl, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetProxyType(PRInt32 nType); \
  NS_SCRIPTABLE NS_IMETHOD SetProxy(const char *strProtocol, const char *strAddr, PRInt32 nPort); \
  NS_SCRIPTABLE NS_IMETHOD CreateVideoDownloadFromUrl2(const PRUnichar *wstrUrl, const PRUnichar *wstrSwfUrl, const PRUnichar *wstrFlashVars, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateVideoDownloadFromUrl3(const PRUnichar *wstrUrl, const PRUnichar *wstrFrameUrl, const PRUnichar *wstrSwfUrl, const PRUnichar *wstrFlashVars, const PRUnichar *wstrOtherSwfUrls, const PRUnichar *wstrOtherFlashVars, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsVideoFlash(const PRUnichar *wstrUrl, const PRUnichar *wstrFrameUrl, const PRUnichar *wstrSwfUrl, const PRUnichar *wstrFlashVars, const PRUnichar *wstrOtherSwfUrls, const PRUnichar *wstrOtherFlashVars, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD OnNewHttpRequest(const PRUnichar *wstrUrl, const PRUnichar *wstrSourceTabUrl); \
  NS_SCRIPTABLE NS_IMETHOD OnHttpRedirect(const PRUnichar *wstrUrl, const PRUnichar *wstrOriginalUrl); \
  NS_SCRIPTABLE NS_IMETHOD DownloadComplete(const PRUnichar *wstrUrl); \
  NS_SCRIPTABLE NS_IMETHOD DownloadBegin(const PRUnichar *wstrUrl); \
  NS_SCRIPTABLE NS_IMETHOD OnHttpActivity(const PRUnichar *wstrUrl); 

#define NS_FORWARD_IFDMFORFIREFOX(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLngString(const char *strIDString, PRUnichar **_retval NS_OUTPARAM) { return _to GetLngString(strIDString, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsContextMenuItemShouldBeHidden(const char *strMenuItemID, PRBool *_retval NS_OUTPARAM) { return _to IsContextMenuItemShouldBeHidden(strMenuItemID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsALTShouldBePressed(PRBool *_retval NS_OUTPARAM) { return _to IsALTShouldBePressed(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsLinkShouldBeSkipped(IFDMUrl *url, const PRUnichar *wstrSuggFileName, PRBool *_retval NS_OUTPARAM) { return _to IsLinkShouldBeSkipped(url, wstrSuggFileName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CatchLink(IFDMUrl *url, const PRUnichar *wstrSuggFileName, PRBool *_retval NS_OUTPARAM) { return _to CatchLink(url, wstrSuggFileName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsDomainSupportedForVideoDownloads(const PRUnichar *wstrDomain, PRBool *_retval NS_OUTPARAM) { return _to IsDomainSupportedForVideoDownloads(wstrDomain, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ProcessVideoDocument(const PRUnichar *wstrDomain, const PRUnichar *wstrReferer, const PRUnichar *wstrHTML, PRBool *_retval NS_OUTPARAM) { return _to ProcessVideoDocument(wstrDomain, wstrReferer, wstrHTML, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateVideoDownloadFromUrl(const PRUnichar *wstrUrl, PRBool *_retval NS_OUTPARAM) { return _to CreateVideoDownloadFromUrl(wstrUrl, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetProxyType(PRInt32 nType) { return _to SetProxyType(nType); } \
  NS_SCRIPTABLE NS_IMETHOD SetProxy(const char *strProtocol, const char *strAddr, PRInt32 nPort) { return _to SetProxy(strProtocol, strAddr, nPort); } \
  NS_SCRIPTABLE NS_IMETHOD CreateVideoDownloadFromUrl2(const PRUnichar *wstrUrl, const PRUnichar *wstrSwfUrl, const PRUnichar *wstrFlashVars, PRBool *_retval NS_OUTPARAM) { return _to CreateVideoDownloadFromUrl2(wstrUrl, wstrSwfUrl, wstrFlashVars, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateVideoDownloadFromUrl3(const PRUnichar *wstrUrl, const PRUnichar *wstrFrameUrl, const PRUnichar *wstrSwfUrl, const PRUnichar *wstrFlashVars, const PRUnichar *wstrOtherSwfUrls, const PRUnichar *wstrOtherFlashVars, PRBool *_retval NS_OUTPARAM) { return _to CreateVideoDownloadFromUrl3(wstrUrl, wstrFrameUrl, wstrSwfUrl, wstrFlashVars, wstrOtherSwfUrls, wstrOtherFlashVars, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsVideoFlash(const PRUnichar *wstrUrl, const PRUnichar *wstrFrameUrl, const PRUnichar *wstrSwfUrl, const PRUnichar *wstrFlashVars, const PRUnichar *wstrOtherSwfUrls, const PRUnichar *wstrOtherFlashVars, PRBool *_retval NS_OUTPARAM) { return _to IsVideoFlash(wstrUrl, wstrFrameUrl, wstrSwfUrl, wstrFlashVars, wstrOtherSwfUrls, wstrOtherFlashVars, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OnNewHttpRequest(const PRUnichar *wstrUrl, const PRUnichar *wstrSourceTabUrl) { return _to OnNewHttpRequest(wstrUrl, wstrSourceTabUrl); } \
  NS_SCRIPTABLE NS_IMETHOD OnHttpRedirect(const PRUnichar *wstrUrl, const PRUnichar *wstrOriginalUrl) { return _to OnHttpRedirect(wstrUrl, wstrOriginalUrl); } \
  NS_SCRIPTABLE NS_IMETHOD DownloadComplete(const PRUnichar *wstrUrl) { return _to DownloadComplete(wstrUrl); } \
  NS_SCRIPTABLE NS_IMETHOD DownloadBegin(const PRUnichar *wstrUrl) { return _to DownloadBegin(wstrUrl); } \
  NS_SCRIPTABLE NS_IMETHOD OnHttpActivity(const PRUnichar *wstrUrl) { return _to OnHttpActivity(wstrUrl); } 

#define NS_FORWARD_SAFE_IFDMFORFIREFOX(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLngString(const char *strIDString, PRUnichar **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLngString(strIDString, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsContextMenuItemShouldBeHidden(const char *strMenuItemID, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsContextMenuItemShouldBeHidden(strMenuItemID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsALTShouldBePressed(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsALTShouldBePressed(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsLinkShouldBeSkipped(IFDMUrl *url, const PRUnichar *wstrSuggFileName, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsLinkShouldBeSkipped(url, wstrSuggFileName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CatchLink(IFDMUrl *url, const PRUnichar *wstrSuggFileName, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CatchLink(url, wstrSuggFileName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsDomainSupportedForVideoDownloads(const PRUnichar *wstrDomain, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsDomainSupportedForVideoDownloads(wstrDomain, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ProcessVideoDocument(const PRUnichar *wstrDomain, const PRUnichar *wstrReferer, const PRUnichar *wstrHTML, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ProcessVideoDocument(wstrDomain, wstrReferer, wstrHTML, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateVideoDownloadFromUrl(const PRUnichar *wstrUrl, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateVideoDownloadFromUrl(wstrUrl, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetProxyType(PRInt32 nType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProxyType(nType); } \
  NS_SCRIPTABLE NS_IMETHOD SetProxy(const char *strProtocol, const char *strAddr, PRInt32 nPort) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProxy(strProtocol, strAddr, nPort); } \
  NS_SCRIPTABLE NS_IMETHOD CreateVideoDownloadFromUrl2(const PRUnichar *wstrUrl, const PRUnichar *wstrSwfUrl, const PRUnichar *wstrFlashVars, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateVideoDownloadFromUrl2(wstrUrl, wstrSwfUrl, wstrFlashVars, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateVideoDownloadFromUrl3(const PRUnichar *wstrUrl, const PRUnichar *wstrFrameUrl, const PRUnichar *wstrSwfUrl, const PRUnichar *wstrFlashVars, const PRUnichar *wstrOtherSwfUrls, const PRUnichar *wstrOtherFlashVars, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateVideoDownloadFromUrl3(wstrUrl, wstrFrameUrl, wstrSwfUrl, wstrFlashVars, wstrOtherSwfUrls, wstrOtherFlashVars, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsVideoFlash(const PRUnichar *wstrUrl, const PRUnichar *wstrFrameUrl, const PRUnichar *wstrSwfUrl, const PRUnichar *wstrFlashVars, const PRUnichar *wstrOtherSwfUrls, const PRUnichar *wstrOtherFlashVars, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsVideoFlash(wstrUrl, wstrFrameUrl, wstrSwfUrl, wstrFlashVars, wstrOtherSwfUrls, wstrOtherFlashVars, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OnNewHttpRequest(const PRUnichar *wstrUrl, const PRUnichar *wstrSourceTabUrl) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnNewHttpRequest(wstrUrl, wstrSourceTabUrl); } \
  NS_SCRIPTABLE NS_IMETHOD OnHttpRedirect(const PRUnichar *wstrUrl, const PRUnichar *wstrOriginalUrl) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnHttpRedirect(wstrUrl, wstrOriginalUrl); } \
  NS_SCRIPTABLE NS_IMETHOD DownloadComplete(const PRUnichar *wstrUrl) { return !_to ? NS_ERROR_NULL_POINTER : _to->DownloadComplete(wstrUrl); } \
  NS_SCRIPTABLE NS_IMETHOD DownloadBegin(const PRUnichar *wstrUrl) { return !_to ? NS_ERROR_NULL_POINTER : _to->DownloadBegin(wstrUrl); } \
  NS_SCRIPTABLE NS_IMETHOD OnHttpActivity(const PRUnichar *wstrUrl) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnHttpActivity(wstrUrl); } 

#if 0

class _MYCLASS_ : public IFDMForFirefox
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IFDMFORFIREFOX

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  
};

NS_IMPL_ISUPPORTS1(_MYCLASS_, IFDMForFirefox)

_MYCLASS_::_MYCLASS_()
{
  
}

_MYCLASS_::~_MYCLASS_()
{
  
}

NS_IMETHODIMP _MYCLASS_::GetLngString(const char *strIDString, PRUnichar **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::IsContextMenuItemShouldBeHidden(const char *strMenuItemID, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::IsALTShouldBePressed(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::IsLinkShouldBeSkipped(IFDMUrl *url, const PRUnichar *wstrSuggFileName, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::CatchLink(IFDMUrl *url, const PRUnichar *wstrSuggFileName, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::IsDomainSupportedForVideoDownloads(const PRUnichar *wstrDomain, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::ProcessVideoDocument(const PRUnichar *wstrDomain, const PRUnichar *wstrReferer, const PRUnichar *wstrHTML, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::CreateVideoDownloadFromUrl(const PRUnichar *wstrUrl, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::SetProxyType(PRInt32 nType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::SetProxy(const char *strProtocol, const char *strAddr, PRInt32 nPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::CreateVideoDownloadFromUrl2(const PRUnichar *wstrUrl, const PRUnichar *wstrSwfUrl, const PRUnichar *wstrFlashVars, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::CreateVideoDownloadFromUrl3(const PRUnichar *wstrUrl, const PRUnichar *wstrFrameUrl, const PRUnichar *wstrSwfUrl, const PRUnichar *wstrFlashVars, const PRUnichar *wstrOtherSwfUrls, const PRUnichar *wstrOtherFlashVars, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::IsVideoFlash(const PRUnichar *wstrUrl, const PRUnichar *wstrFrameUrl, const PRUnichar *wstrSwfUrl, const PRUnichar *wstrFlashVars, const PRUnichar *wstrOtherSwfUrls, const PRUnichar *wstrOtherFlashVars, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::OnNewHttpRequest(const PRUnichar *wstrUrl, const PRUnichar *wstrSourceTabUrl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::OnHttpRedirect(const PRUnichar *wstrUrl, const PRUnichar *wstrOriginalUrl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::DownloadComplete(const PRUnichar *wstrUrl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::DownloadBegin(const PRUnichar *wstrUrl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::OnHttpActivity(const PRUnichar *wstrUrl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

#endif

#define IFDMFFCACHEMONITOR_IID_STR "ebfec047-f68d-491e-8d7d-268b9c762cb7"

#define IFDMFFCACHEMONITOR_IID \
  {0xebfec047, 0xf68d, 0x491e, \
    { 0x8d, 0x7d, 0x26, 0x8b, 0x9c, 0x76, 0x2c, 0xb7 }}

class NS_NO_VTABLE NS_SCRIPTABLE IFDMFfCacheMonitor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IFDMFFCACHEMONITOR_IID)

  
  NS_SCRIPTABLE NS_IMETHOD OnNewHttpDialog(const char *strUrl, const char *strRequestHdrs, const char *strResponseHdrs, PRUint32 *_retval NS_OUTPARAM) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD OnDataReceived(PRUint32 nUID, PRUint32 count, PRUint8 *bytes) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD OnDialogClosed(PRUint32 nUID) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(IFDMFfCacheMonitor, IFDMFFCACHEMONITOR_IID)

#define NS_DECL_IFDMFFCACHEMONITOR \
  NS_SCRIPTABLE NS_IMETHOD OnNewHttpDialog(const char *strUrl, const char *strRequestHdrs, const char *strResponseHdrs, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD OnDataReceived(PRUint32 nUID, PRUint32 count, PRUint8 *bytes); \
  NS_SCRIPTABLE NS_IMETHOD OnDialogClosed(PRUint32 nUID); 

#define NS_FORWARD_IFDMFFCACHEMONITOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnNewHttpDialog(const char *strUrl, const char *strRequestHdrs, const char *strResponseHdrs, PRUint32 *_retval NS_OUTPARAM) { return _to OnNewHttpDialog(strUrl, strRequestHdrs, strResponseHdrs, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OnDataReceived(PRUint32 nUID, PRUint32 count, PRUint8 *bytes) { return _to OnDataReceived(nUID, count, bytes); } \
  NS_SCRIPTABLE NS_IMETHOD OnDialogClosed(PRUint32 nUID) { return _to OnDialogClosed(nUID); } 

#define NS_FORWARD_SAFE_IFDMFFCACHEMONITOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnNewHttpDialog(const char *strUrl, const char *strRequestHdrs, const char *strResponseHdrs, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnNewHttpDialog(strUrl, strRequestHdrs, strResponseHdrs, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OnDataReceived(PRUint32 nUID, PRUint32 count, PRUint8 *bytes) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDataReceived(nUID, count, bytes); } \
  NS_SCRIPTABLE NS_IMETHOD OnDialogClosed(PRUint32 nUID) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDialogClosed(nUID); } 

#if 0

class _MYCLASS_ : public IFDMFfCacheMonitor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IFDMFFCACHEMONITOR

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  
};

NS_IMPL_ISUPPORTS1(_MYCLASS_, IFDMFfCacheMonitor)

_MYCLASS_::_MYCLASS_()
{
  
}

_MYCLASS_::~_MYCLASS_()
{
  
}

NS_IMETHODIMP _MYCLASS_::OnNewHttpDialog(const char *strUrl, const char *strRequestHdrs, const char *strResponseHdrs, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::OnDataReceived(PRUint32 nUID, PRUint32 count, PRUint8 *bytes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::OnDialogClosed(PRUint32 nUID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

#endif

#define IFDMFIREFOXEXTENSION_IID_STR "28bc56f7-1409-40c7-a9bb-10f113eb2d70"

#define IFDMFIREFOXEXTENSION_IID \
  {0x28bc56f7, 0x1409, 0x40c7, \
    { 0xa9, 0xbb, 0x10, 0xf1, 0x13, 0xeb, 0x2d, 0x70 }}

class NS_NO_VTABLE NS_SCRIPTABLE IFDMFirefoxExtension : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IFDMFIREFOXEXTENSION_IID)

  
  NS_SCRIPTABLE NS_IMETHOD GetLastPost(nsISupports **aLastPost) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLastPost(nsISupports *aLastPost) = 0;

  
  NS_SCRIPTABLE NS_IMETHOD MakeSureFlvSniffDllLoaded(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(IFDMFirefoxExtension, IFDMFIREFOXEXTENSION_IID)

#define NS_DECL_IFDMFIREFOXEXTENSION \
  NS_SCRIPTABLE NS_IMETHOD GetLastPost(nsISupports **aLastPost); \
  NS_SCRIPTABLE NS_IMETHOD SetLastPost(nsISupports *aLastPost); \
  NS_SCRIPTABLE NS_IMETHOD MakeSureFlvSniffDllLoaded(void); 

#define NS_FORWARD_IFDMFIREFOXEXTENSION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLastPost(nsISupports **aLastPost) { return _to GetLastPost(aLastPost); } \
  NS_SCRIPTABLE NS_IMETHOD SetLastPost(nsISupports *aLastPost) { return _to SetLastPost(aLastPost); } \
  NS_SCRIPTABLE NS_IMETHOD MakeSureFlvSniffDllLoaded(void) { return _to MakeSureFlvSniffDllLoaded(); } 

#define NS_FORWARD_SAFE_IFDMFIREFOXEXTENSION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLastPost(nsISupports **aLastPost) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastPost(aLastPost); } \
  NS_SCRIPTABLE NS_IMETHOD SetLastPost(nsISupports *aLastPost) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLastPost(aLastPost); } \
  NS_SCRIPTABLE NS_IMETHOD MakeSureFlvSniffDllLoaded(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->MakeSureFlvSniffDllLoaded(); } 

#if 0

class _MYCLASS_ : public IFDMFirefoxExtension
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IFDMFIREFOXEXTENSION

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  
};

NS_IMPL_ISUPPORTS1(_MYCLASS_, IFDMFirefoxExtension)

_MYCLASS_::_MYCLASS_()
{
  
}

_MYCLASS_::~_MYCLASS_()
{
  
}

NS_IMETHODIMP _MYCLASS_::GetLastPost(nsISupports **aLastPost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetLastPost(nsISupports *aLastPost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP _MYCLASS_::MakeSureFlvSniffDllLoaded()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

#endif

#endif 

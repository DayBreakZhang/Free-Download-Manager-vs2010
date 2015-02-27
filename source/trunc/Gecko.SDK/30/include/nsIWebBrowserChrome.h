/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIWebBrowserChrome.idl
 */

#ifndef __gen_nsIWebBrowserChrome_h__
#define __gen_nsIWebBrowserChrome_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIWebBrowser; /* forward declaration */

class nsIDocShellTreeItem; /* forward declaration */


/* starting interface:    nsIWebBrowserChrome */
#define NS_IWEBBROWSERCHROME_IID_STR "e8c414c4-dc38-4ba3-ab4e-ec4cbbe22907"

#define NS_IWEBBROWSERCHROME_IID \
  {0xe8c414c4, 0xdc38, 0x4ba3, \
    { 0xab, 0x4e, 0xec, 0x4c, 0xbb, 0xe2, 0x29, 0x07 }}

class NS_NO_VTABLE nsIWebBrowserChrome : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBBROWSERCHROME_IID)

  enum {
    STATUS_SCRIPT = 1U,
    STATUS_LINK = 3U
  };

  /* void setStatus (in unsigned long statusType, in wstring status); */
  NS_IMETHOD SetStatus(uint32_t statusType, const char16_t * status) = 0;

  /* attribute nsIWebBrowser webBrowser; */
  NS_IMETHOD GetWebBrowser(nsIWebBrowser * *aWebBrowser) = 0;
  NS_IMETHOD SetWebBrowser(nsIWebBrowser *aWebBrowser) = 0;

  enum {
    CHROME_DEFAULT = 1U,
    CHROME_WINDOW_BORDERS = 2U,
    CHROME_WINDOW_CLOSE = 4U,
    CHROME_WINDOW_RESIZE = 8U,
    CHROME_MENUBAR = 16U,
    CHROME_TOOLBAR = 32U,
    CHROME_LOCATIONBAR = 64U,
    CHROME_STATUSBAR = 128U,
    CHROME_PERSONAL_TOOLBAR = 256U,
    CHROME_SCROLLBARS = 512U,
    CHROME_TITLEBAR = 1024U,
    CHROME_EXTRA = 2048U,
    CHROME_WITH_SIZE = 4096U,
    CHROME_WITH_POSITION = 8192U,
    CHROME_WINDOW_MIN = 16384U,
    CHROME_WINDOW_POPUP = 32768U,
    CHROME_PRIVATE_WINDOW = 65536U,
    CHROME_NON_PRIVATE_WINDOW = 131072U,
    CHROME_PRIVATE_LIFETIME = 262144U,
    CHROME_MODAL_CONTENT_WINDOW = 524288U,
    CHROME_REMOTE_WINDOW = 1048576U,
    CHROME_MAC_SUPPRESS_ANIMATION = 16777216U,
    CHROME_WINDOW_RAISED = 33554432U,
    CHROME_WINDOW_LOWERED = 67108864U,
    CHROME_CENTER_SCREEN = 134217728U,
    CHROME_DEPENDENT = 268435456U,
    CHROME_MODAL = 536870912U,
    CHROME_OPENAS_DIALOG = 1073741824U,
    CHROME_OPENAS_CHROME = 2147483648U,
    CHROME_ALL = 4094U
  };

  /* attribute unsigned long chromeFlags; */
  NS_IMETHOD GetChromeFlags(uint32_t *aChromeFlags) = 0;
  NS_IMETHOD SetChromeFlags(uint32_t aChromeFlags) = 0;

  /* void destroyBrowserWindow (); */
  NS_IMETHOD DestroyBrowserWindow(void) = 0;

  /* void sizeBrowserTo (in long aCX, in long aCY); */
  NS_IMETHOD SizeBrowserTo(int32_t aCX, int32_t aCY) = 0;

  /* void showAsModal (); */
  NS_IMETHOD ShowAsModal(void) = 0;

  /* boolean isWindowModal (); */
  NS_IMETHOD IsWindowModal(bool *_retval) = 0;

  /* void exitModalEventLoop (in nsresult aStatus); */
  NS_IMETHOD ExitModalEventLoop(nsresult aStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebBrowserChrome, NS_IWEBBROWSERCHROME_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBBROWSERCHROME \
  NS_IMETHOD SetStatus(uint32_t statusType, const char16_t * status); \
  NS_IMETHOD GetWebBrowser(nsIWebBrowser * *aWebBrowser); \
  NS_IMETHOD SetWebBrowser(nsIWebBrowser *aWebBrowser); \
  NS_IMETHOD GetChromeFlags(uint32_t *aChromeFlags); \
  NS_IMETHOD SetChromeFlags(uint32_t aChromeFlags); \
  NS_IMETHOD DestroyBrowserWindow(void); \
  NS_IMETHOD SizeBrowserTo(int32_t aCX, int32_t aCY); \
  NS_IMETHOD ShowAsModal(void); \
  NS_IMETHOD IsWindowModal(bool *_retval); \
  NS_IMETHOD ExitModalEventLoop(nsresult aStatus); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBBROWSERCHROME(_to) \
  NS_IMETHOD SetStatus(uint32_t statusType, const char16_t * status) { return _to SetStatus(statusType, status); } \
  NS_IMETHOD GetWebBrowser(nsIWebBrowser * *aWebBrowser) { return _to GetWebBrowser(aWebBrowser); } \
  NS_IMETHOD SetWebBrowser(nsIWebBrowser *aWebBrowser) { return _to SetWebBrowser(aWebBrowser); } \
  NS_IMETHOD GetChromeFlags(uint32_t *aChromeFlags) { return _to GetChromeFlags(aChromeFlags); } \
  NS_IMETHOD SetChromeFlags(uint32_t aChromeFlags) { return _to SetChromeFlags(aChromeFlags); } \
  NS_IMETHOD DestroyBrowserWindow(void) { return _to DestroyBrowserWindow(); } \
  NS_IMETHOD SizeBrowserTo(int32_t aCX, int32_t aCY) { return _to SizeBrowserTo(aCX, aCY); } \
  NS_IMETHOD ShowAsModal(void) { return _to ShowAsModal(); } \
  NS_IMETHOD IsWindowModal(bool *_retval) { return _to IsWindowModal(_retval); } \
  NS_IMETHOD ExitModalEventLoop(nsresult aStatus) { return _to ExitModalEventLoop(aStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBBROWSERCHROME(_to) \
  NS_IMETHOD SetStatus(uint32_t statusType, const char16_t * status) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStatus(statusType, status); } \
  NS_IMETHOD GetWebBrowser(nsIWebBrowser * *aWebBrowser) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWebBrowser(aWebBrowser); } \
  NS_IMETHOD SetWebBrowser(nsIWebBrowser *aWebBrowser) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWebBrowser(aWebBrowser); } \
  NS_IMETHOD GetChromeFlags(uint32_t *aChromeFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChromeFlags(aChromeFlags); } \
  NS_IMETHOD SetChromeFlags(uint32_t aChromeFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChromeFlags(aChromeFlags); } \
  NS_IMETHOD DestroyBrowserWindow(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DestroyBrowserWindow(); } \
  NS_IMETHOD SizeBrowserTo(int32_t aCX, int32_t aCY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SizeBrowserTo(aCX, aCY); } \
  NS_IMETHOD ShowAsModal(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowAsModal(); } \
  NS_IMETHOD IsWindowModal(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsWindowModal(_retval); } \
  NS_IMETHOD ExitModalEventLoop(nsresult aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExitModalEventLoop(aStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebBrowserChrome : public nsIWebBrowserChrome
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBBROWSERCHROME

  nsWebBrowserChrome();

private:
  ~nsWebBrowserChrome();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebBrowserChrome, nsIWebBrowserChrome)

nsWebBrowserChrome::nsWebBrowserChrome()
{
  /* member initializers and constructor code */
}

nsWebBrowserChrome::~nsWebBrowserChrome()
{
  /* destructor code */
}

/* void setStatus (in unsigned long statusType, in wstring status); */
NS_IMETHODIMP nsWebBrowserChrome::SetStatus(uint32_t statusType, const char16_t * status)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIWebBrowser webBrowser; */
NS_IMETHODIMP nsWebBrowserChrome::GetWebBrowser(nsIWebBrowser * *aWebBrowser)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebBrowserChrome::SetWebBrowser(nsIWebBrowser *aWebBrowser)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long chromeFlags; */
NS_IMETHODIMP nsWebBrowserChrome::GetChromeFlags(uint32_t *aChromeFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebBrowserChrome::SetChromeFlags(uint32_t aChromeFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void destroyBrowserWindow (); */
NS_IMETHODIMP nsWebBrowserChrome::DestroyBrowserWindow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sizeBrowserTo (in long aCX, in long aCY); */
NS_IMETHODIMP nsWebBrowserChrome::SizeBrowserTo(int32_t aCX, int32_t aCY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showAsModal (); */
NS_IMETHODIMP nsWebBrowserChrome::ShowAsModal()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isWindowModal (); */
NS_IMETHODIMP nsWebBrowserChrome::IsWindowModal(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void exitModalEventLoop (in nsresult aStatus); */
NS_IMETHODIMP nsWebBrowserChrome::ExitModalEventLoop(nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebBrowserChrome_h__ */

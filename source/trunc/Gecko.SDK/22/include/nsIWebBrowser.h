/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/embedding/browser/webBrowser/nsIWebBrowser.idl
 */

#ifndef __gen_nsIWebBrowser_h__
#define __gen_nsIWebBrowser_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInterfaceRequestor; /* forward declaration */

class nsIWebBrowserChrome; /* forward declaration */

class nsIURIContentListener; /* forward declaration */

class nsIDOMWindow; /* forward declaration */

class nsIWeakReference; /* forward declaration */


/* starting interface:    nsIWebBrowser */
#define NS_IWEBBROWSER_IID_STR "33e9d001-caab-4ba9-8961-54902f197202"

#define NS_IWEBBROWSER_IID \
  {0x33e9d001, 0xcaab, 0x4ba9, \
    { 0x89, 0x61, 0x54, 0x90, 0x2f, 0x19, 0x72, 0x02 }}

class NS_NO_VTABLE nsIWebBrowser : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBBROWSER_IID)

  /* void addWebBrowserListener (in nsIWeakReference aListener, in nsIIDRef aIID); */
  NS_IMETHOD AddWebBrowserListener(nsIWeakReference *aListener, const nsIID & aIID) = 0;

  /* void removeWebBrowserListener (in nsIWeakReference aListener, in nsIIDRef aIID); */
  NS_IMETHOD RemoveWebBrowserListener(nsIWeakReference *aListener, const nsIID & aIID) = 0;

  /* attribute nsIWebBrowserChrome containerWindow; */
  NS_IMETHOD GetContainerWindow(nsIWebBrowserChrome * *aContainerWindow) = 0;
  NS_IMETHOD SetContainerWindow(nsIWebBrowserChrome *aContainerWindow) = 0;

  /* attribute nsIURIContentListener parentURIContentListener; */
  NS_IMETHOD GetParentURIContentListener(nsIURIContentListener * *aParentURIContentListener) = 0;
  NS_IMETHOD SetParentURIContentListener(nsIURIContentListener *aParentURIContentListener) = 0;

  /* readonly attribute nsIDOMWindow contentDOMWindow; */
  NS_IMETHOD GetContentDOMWindow(nsIDOMWindow * *aContentDOMWindow) = 0;

  /* attribute boolean isActive; */
  NS_IMETHOD GetIsActive(bool *aIsActive) = 0;
  NS_IMETHOD SetIsActive(bool aIsActive) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebBrowser, NS_IWEBBROWSER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBBROWSER \
  NS_IMETHOD AddWebBrowserListener(nsIWeakReference *aListener, const nsIID & aIID); \
  NS_IMETHOD RemoveWebBrowserListener(nsIWeakReference *aListener, const nsIID & aIID); \
  NS_IMETHOD GetContainerWindow(nsIWebBrowserChrome * *aContainerWindow); \
  NS_IMETHOD SetContainerWindow(nsIWebBrowserChrome *aContainerWindow); \
  NS_IMETHOD GetParentURIContentListener(nsIURIContentListener * *aParentURIContentListener); \
  NS_IMETHOD SetParentURIContentListener(nsIURIContentListener *aParentURIContentListener); \
  NS_IMETHOD GetContentDOMWindow(nsIDOMWindow * *aContentDOMWindow); \
  NS_IMETHOD GetIsActive(bool *aIsActive); \
  NS_IMETHOD SetIsActive(bool aIsActive); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBBROWSER(_to) \
  NS_IMETHOD AddWebBrowserListener(nsIWeakReference *aListener, const nsIID & aIID) { return _to AddWebBrowserListener(aListener, aIID); } \
  NS_IMETHOD RemoveWebBrowserListener(nsIWeakReference *aListener, const nsIID & aIID) { return _to RemoveWebBrowserListener(aListener, aIID); } \
  NS_IMETHOD GetContainerWindow(nsIWebBrowserChrome * *aContainerWindow) { return _to GetContainerWindow(aContainerWindow); } \
  NS_IMETHOD SetContainerWindow(nsIWebBrowserChrome *aContainerWindow) { return _to SetContainerWindow(aContainerWindow); } \
  NS_IMETHOD GetParentURIContentListener(nsIURIContentListener * *aParentURIContentListener) { return _to GetParentURIContentListener(aParentURIContentListener); } \
  NS_IMETHOD SetParentURIContentListener(nsIURIContentListener *aParentURIContentListener) { return _to SetParentURIContentListener(aParentURIContentListener); } \
  NS_IMETHOD GetContentDOMWindow(nsIDOMWindow * *aContentDOMWindow) { return _to GetContentDOMWindow(aContentDOMWindow); } \
  NS_IMETHOD GetIsActive(bool *aIsActive) { return _to GetIsActive(aIsActive); } \
  NS_IMETHOD SetIsActive(bool aIsActive) { return _to SetIsActive(aIsActive); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBBROWSER(_to) \
  NS_IMETHOD AddWebBrowserListener(nsIWeakReference *aListener, const nsIID & aIID) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddWebBrowserListener(aListener, aIID); } \
  NS_IMETHOD RemoveWebBrowserListener(nsIWeakReference *aListener, const nsIID & aIID) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveWebBrowserListener(aListener, aIID); } \
  NS_IMETHOD GetContainerWindow(nsIWebBrowserChrome * *aContainerWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContainerWindow(aContainerWindow); } \
  NS_IMETHOD SetContainerWindow(nsIWebBrowserChrome *aContainerWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContainerWindow(aContainerWindow); } \
  NS_IMETHOD GetParentURIContentListener(nsIURIContentListener * *aParentURIContentListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentURIContentListener(aParentURIContentListener); } \
  NS_IMETHOD SetParentURIContentListener(nsIURIContentListener *aParentURIContentListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetParentURIContentListener(aParentURIContentListener); } \
  NS_IMETHOD GetContentDOMWindow(nsIDOMWindow * *aContentDOMWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentDOMWindow(aContentDOMWindow); } \
  NS_IMETHOD GetIsActive(bool *aIsActive) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsActive(aIsActive); } \
  NS_IMETHOD SetIsActive(bool aIsActive) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsActive(aIsActive); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebBrowser : public nsIWebBrowser
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBBROWSER

  nsWebBrowser();

private:
  ~nsWebBrowser();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebBrowser, nsIWebBrowser)

nsWebBrowser::nsWebBrowser()
{
  /* member initializers and constructor code */
}

nsWebBrowser::~nsWebBrowser()
{
  /* destructor code */
}

/* void addWebBrowserListener (in nsIWeakReference aListener, in nsIIDRef aIID); */
NS_IMETHODIMP nsWebBrowser::AddWebBrowserListener(nsIWeakReference *aListener, const nsIID & aIID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeWebBrowserListener (in nsIWeakReference aListener, in nsIIDRef aIID); */
NS_IMETHODIMP nsWebBrowser::RemoveWebBrowserListener(nsIWeakReference *aListener, const nsIID & aIID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIWebBrowserChrome containerWindow; */
NS_IMETHODIMP nsWebBrowser::GetContainerWindow(nsIWebBrowserChrome * *aContainerWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebBrowser::SetContainerWindow(nsIWebBrowserChrome *aContainerWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIURIContentListener parentURIContentListener; */
NS_IMETHODIMP nsWebBrowser::GetParentURIContentListener(nsIURIContentListener * *aParentURIContentListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebBrowser::SetParentURIContentListener(nsIURIContentListener *aParentURIContentListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow contentDOMWindow; */
NS_IMETHODIMP nsWebBrowser::GetContentDOMWindow(nsIDOMWindow * *aContentDOMWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isActive; */
NS_IMETHODIMP nsWebBrowser::GetIsActive(bool *aIsActive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebBrowser::SetIsActive(bool aIsActive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebBrowser_h__ */

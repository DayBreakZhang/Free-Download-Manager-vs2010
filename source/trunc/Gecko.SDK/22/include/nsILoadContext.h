/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/docshell/base/nsILoadContext.idl
 */

#ifndef __gen_nsILoadContext_h__
#define __gen_nsILoadContext_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIDOMElement; /* forward declaration */


/* starting interface:    nsILoadContext */
#define NS_ILOADCONTEXT_IID_STR "d0029474-0cc4-42fd-bb21-d9ff22f5293c"

#define NS_ILOADCONTEXT_IID \
  {0xd0029474, 0x0cc4, 0x42fd, \
    { 0xbb, 0x21, 0xd9, 0xff, 0x22, 0xf5, 0x29, 0x3c }}

class nsILoadContext : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOADCONTEXT_IID)

  /* readonly attribute nsIDOMWindow associatedWindow; */
  NS_IMETHOD GetAssociatedWindow(nsIDOMWindow * *aAssociatedWindow) = 0;

  /* readonly attribute nsIDOMWindow topWindow; */
  NS_IMETHOD GetTopWindow(nsIDOMWindow * *aTopWindow) = 0;

  /* readonly attribute nsIDOMElement topFrameElement; */
  NS_IMETHOD GetTopFrameElement(nsIDOMElement * *aTopFrameElement) = 0;

  /* boolean isAppOfType (in unsigned long appType); */
  NS_IMETHOD IsAppOfType(uint32_t appType, bool *_retval) = 0;

  /* readonly attribute boolean isContent; */
  NS_IMETHOD GetIsContent(bool *aIsContent) = 0;

  /* attribute boolean usePrivateBrowsing; */
  NS_IMETHOD GetUsePrivateBrowsing(bool *aUsePrivateBrowsing) = 0;
  NS_IMETHOD SetUsePrivateBrowsing(bool aUsePrivateBrowsing) = 0;

   /**
   * De-XPCOMed getter to make call-sites cleaner.
   */
  bool UsePrivateBrowsing() {
    bool usingPB;
    GetUsePrivateBrowsing(&usingPB);
    return usingPB;
  }
  /* [noscript] void SetPrivateBrowsing (in boolean aInPrivateBrowsing); */
  NS_IMETHOD SetPrivateBrowsing(bool aInPrivateBrowsing) = 0;

  /* readonly attribute boolean isInBrowserElement; */
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement) = 0;

  /* readonly attribute unsigned long appId; */
  NS_IMETHOD GetAppId(uint32_t *aAppId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILoadContext, NS_ILOADCONTEXT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOADCONTEXT \
  NS_IMETHOD GetAssociatedWindow(nsIDOMWindow * *aAssociatedWindow); \
  NS_IMETHOD GetTopWindow(nsIDOMWindow * *aTopWindow); \
  NS_IMETHOD GetTopFrameElement(nsIDOMElement * *aTopFrameElement); \
  NS_IMETHOD IsAppOfType(uint32_t appType, bool *_retval); \
  NS_IMETHOD GetIsContent(bool *aIsContent); \
  NS_IMETHOD GetUsePrivateBrowsing(bool *aUsePrivateBrowsing); \
  NS_IMETHOD SetUsePrivateBrowsing(bool aUsePrivateBrowsing); \
  NS_IMETHOD SetPrivateBrowsing(bool aInPrivateBrowsing); \
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement); \
  NS_IMETHOD GetAppId(uint32_t *aAppId); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOADCONTEXT(_to) \
  NS_IMETHOD GetAssociatedWindow(nsIDOMWindow * *aAssociatedWindow) { return _to GetAssociatedWindow(aAssociatedWindow); } \
  NS_IMETHOD GetTopWindow(nsIDOMWindow * *aTopWindow) { return _to GetTopWindow(aTopWindow); } \
  NS_IMETHOD GetTopFrameElement(nsIDOMElement * *aTopFrameElement) { return _to GetTopFrameElement(aTopFrameElement); } \
  NS_IMETHOD IsAppOfType(uint32_t appType, bool *_retval) { return _to IsAppOfType(appType, _retval); } \
  NS_IMETHOD GetIsContent(bool *aIsContent) { return _to GetIsContent(aIsContent); } \
  NS_IMETHOD GetUsePrivateBrowsing(bool *aUsePrivateBrowsing) { return _to GetUsePrivateBrowsing(aUsePrivateBrowsing); } \
  NS_IMETHOD SetUsePrivateBrowsing(bool aUsePrivateBrowsing) { return _to SetUsePrivateBrowsing(aUsePrivateBrowsing); } \
  NS_IMETHOD SetPrivateBrowsing(bool aInPrivateBrowsing) { return _to SetPrivateBrowsing(aInPrivateBrowsing); } \
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement) { return _to GetIsInBrowserElement(aIsInBrowserElement); } \
  NS_IMETHOD GetAppId(uint32_t *aAppId) { return _to GetAppId(aAppId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOADCONTEXT(_to) \
  NS_IMETHOD GetAssociatedWindow(nsIDOMWindow * *aAssociatedWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAssociatedWindow(aAssociatedWindow); } \
  NS_IMETHOD GetTopWindow(nsIDOMWindow * *aTopWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTopWindow(aTopWindow); } \
  NS_IMETHOD GetTopFrameElement(nsIDOMElement * *aTopFrameElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTopFrameElement(aTopFrameElement); } \
  NS_IMETHOD IsAppOfType(uint32_t appType, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsAppOfType(appType, _retval); } \
  NS_IMETHOD GetIsContent(bool *aIsContent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsContent(aIsContent); } \
  NS_IMETHOD GetUsePrivateBrowsing(bool *aUsePrivateBrowsing) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsePrivateBrowsing(aUsePrivateBrowsing); } \
  NS_IMETHOD SetUsePrivateBrowsing(bool aUsePrivateBrowsing) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUsePrivateBrowsing(aUsePrivateBrowsing); } \
  NS_IMETHOD SetPrivateBrowsing(bool aInPrivateBrowsing) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrivateBrowsing(aInPrivateBrowsing); } \
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsInBrowserElement(aIsInBrowserElement); } \
  NS_IMETHOD GetAppId(uint32_t *aAppId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppId(aAppId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLoadContext : public nsILoadContext
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOADCONTEXT

  nsLoadContext();

private:
  ~nsLoadContext();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLoadContext, nsILoadContext)

nsLoadContext::nsLoadContext()
{
  /* member initializers and constructor code */
}

nsLoadContext::~nsLoadContext()
{
  /* destructor code */
}

/* readonly attribute nsIDOMWindow associatedWindow; */
NS_IMETHODIMP nsLoadContext::GetAssociatedWindow(nsIDOMWindow * *aAssociatedWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow topWindow; */
NS_IMETHODIMP nsLoadContext::GetTopWindow(nsIDOMWindow * *aTopWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement topFrameElement; */
NS_IMETHODIMP nsLoadContext::GetTopFrameElement(nsIDOMElement * *aTopFrameElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isAppOfType (in unsigned long appType); */
NS_IMETHODIMP nsLoadContext::IsAppOfType(uint32_t appType, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isContent; */
NS_IMETHODIMP nsLoadContext::GetIsContent(bool *aIsContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean usePrivateBrowsing; */
NS_IMETHODIMP nsLoadContext::GetUsePrivateBrowsing(bool *aUsePrivateBrowsing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoadContext::SetUsePrivateBrowsing(bool aUsePrivateBrowsing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void SetPrivateBrowsing (in boolean aInPrivateBrowsing); */
NS_IMETHODIMP nsLoadContext::SetPrivateBrowsing(bool aInPrivateBrowsing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isInBrowserElement; */
NS_IMETHODIMP nsLoadContext::GetIsInBrowserElement(bool *aIsInBrowserElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long appId; */
NS_IMETHODIMP nsLoadContext::GetAppId(uint32_t *aAppId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsILoadContext_h__ */

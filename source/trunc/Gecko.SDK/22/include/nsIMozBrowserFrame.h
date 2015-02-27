/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIMozBrowserFrame.idl
 */

#ifndef __gen_nsIMozBrowserFrame_h__
#define __gen_nsIMozBrowserFrame_h__


#ifndef __gen_nsIDOMMozBrowserFrame_h__
#include "nsIDOMMozBrowserFrame.h"
#endif

#include "mozilla/Assertions.h"
#include "mozilla/DebugOnly.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITabParent; /* forward declaration */


/* starting interface:    nsIMozBrowserFrame */
#define NS_IMOZBROWSERFRAME_IID_STR "929aed00-3e15-49b7-8ca2-75003715b7e7"

#define NS_IMOZBROWSERFRAME_IID \
  {0x929aed00, 0x3e15, 0x49b7, \
    { 0x8c, 0xa2, 0x75, 0x00, 0x37, 0x15, 0xb7, 0xe7 }}

class NS_NO_VTABLE nsIMozBrowserFrame : public nsIDOMMozBrowserFrame {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOZBROWSERFRAME_IID)

  /* [infallible] readonly attribute boolean reallyIsBrowserOrApp; */
  NS_IMETHOD GetReallyIsBrowserOrApp(bool *aReallyIsBrowserOrApp) = 0;
  inline bool GetReallyIsBrowserOrApp()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetReallyIsBrowserOrApp(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean reallyIsApp; */
  NS_IMETHOD GetReallyIsApp(bool *aReallyIsApp) = 0;
  inline bool GetReallyIsApp()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetReallyIsApp(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean isExpectingSystemMessage; */
  NS_IMETHOD GetIsExpectingSystemMessage(bool *aIsExpectingSystemMessage) = 0;
  inline bool GetIsExpectingSystemMessage()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetIsExpectingSystemMessage(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* readonly attribute AString appManifestURL; */
  NS_IMETHOD GetAppManifestURL(nsAString & aAppManifestURL) = 0;

  /* void disallowCreateFrameLoader (); */
  NS_IMETHOD DisallowCreateFrameLoader(void) = 0;

  /* void allowCreateFrameLoader (); */
  NS_IMETHOD AllowCreateFrameLoader(void) = 0;

  /* void createRemoteFrameLoader (in nsITabParent aTabParent); */
  NS_IMETHOD CreateRemoteFrameLoader(nsITabParent *aTabParent) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMozBrowserFrame, NS_IMOZBROWSERFRAME_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOZBROWSERFRAME \
  NS_IMETHOD GetReallyIsBrowserOrApp(bool *aReallyIsBrowserOrApp); \
  NS_IMETHOD GetReallyIsApp(bool *aReallyIsApp); \
  NS_IMETHOD GetIsExpectingSystemMessage(bool *aIsExpectingSystemMessage); \
  NS_IMETHOD GetAppManifestURL(nsAString & aAppManifestURL); \
  NS_IMETHOD DisallowCreateFrameLoader(void); \
  NS_IMETHOD AllowCreateFrameLoader(void); \
  NS_IMETHOD CreateRemoteFrameLoader(nsITabParent *aTabParent); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOZBROWSERFRAME(_to) \
  NS_IMETHOD GetReallyIsBrowserOrApp(bool *aReallyIsBrowserOrApp) { return _to GetReallyIsBrowserOrApp(aReallyIsBrowserOrApp); } \
  NS_IMETHOD GetReallyIsApp(bool *aReallyIsApp) { return _to GetReallyIsApp(aReallyIsApp); } \
  NS_IMETHOD GetIsExpectingSystemMessage(bool *aIsExpectingSystemMessage) { return _to GetIsExpectingSystemMessage(aIsExpectingSystemMessage); } \
  NS_IMETHOD GetAppManifestURL(nsAString & aAppManifestURL) { return _to GetAppManifestURL(aAppManifestURL); } \
  NS_IMETHOD DisallowCreateFrameLoader(void) { return _to DisallowCreateFrameLoader(); } \
  NS_IMETHOD AllowCreateFrameLoader(void) { return _to AllowCreateFrameLoader(); } \
  NS_IMETHOD CreateRemoteFrameLoader(nsITabParent *aTabParent) { return _to CreateRemoteFrameLoader(aTabParent); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOZBROWSERFRAME(_to) \
  NS_IMETHOD GetReallyIsBrowserOrApp(bool *aReallyIsBrowserOrApp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReallyIsBrowserOrApp(aReallyIsBrowserOrApp); } \
  NS_IMETHOD GetReallyIsApp(bool *aReallyIsApp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReallyIsApp(aReallyIsApp); } \
  NS_IMETHOD GetIsExpectingSystemMessage(bool *aIsExpectingSystemMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsExpectingSystemMessage(aIsExpectingSystemMessage); } \
  NS_IMETHOD GetAppManifestURL(nsAString & aAppManifestURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppManifestURL(aAppManifestURL); } \
  NS_IMETHOD DisallowCreateFrameLoader(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DisallowCreateFrameLoader(); } \
  NS_IMETHOD AllowCreateFrameLoader(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->AllowCreateFrameLoader(); } \
  NS_IMETHOD CreateRemoteFrameLoader(nsITabParent *aTabParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateRemoteFrameLoader(aTabParent); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMozBrowserFrame : public nsIMozBrowserFrame
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOZBROWSERFRAME

  nsMozBrowserFrame();

private:
  ~nsMozBrowserFrame();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMozBrowserFrame, nsIMozBrowserFrame)

nsMozBrowserFrame::nsMozBrowserFrame()
{
  /* member initializers and constructor code */
}

nsMozBrowserFrame::~nsMozBrowserFrame()
{
  /* destructor code */
}

/* [infallible] readonly attribute boolean reallyIsBrowserOrApp; */
NS_IMETHODIMP nsMozBrowserFrame::GetReallyIsBrowserOrApp(bool *aReallyIsBrowserOrApp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean reallyIsApp; */
NS_IMETHODIMP nsMozBrowserFrame::GetReallyIsApp(bool *aReallyIsApp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean isExpectingSystemMessage; */
NS_IMETHODIMP nsMozBrowserFrame::GetIsExpectingSystemMessage(bool *aIsExpectingSystemMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString appManifestURL; */
NS_IMETHODIMP nsMozBrowserFrame::GetAppManifestURL(nsAString & aAppManifestURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void disallowCreateFrameLoader (); */
NS_IMETHODIMP nsMozBrowserFrame::DisallowCreateFrameLoader()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void allowCreateFrameLoader (); */
NS_IMETHODIMP nsMozBrowserFrame::AllowCreateFrameLoader()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void createRemoteFrameLoader (in nsITabParent aTabParent); */
NS_IMETHODIMP nsMozBrowserFrame::CreateRemoteFrameLoader(nsITabParent *aTabParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMozBrowserFrame_h__ */

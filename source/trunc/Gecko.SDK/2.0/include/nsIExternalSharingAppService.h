/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/uriloader/exthandler/nsIExternalSharingAppService.idl
 */

#ifndef __gen_nsIExternalSharingAppService_h__
#define __gen_nsIExternalSharingAppService_h__


#ifndef __gen_nsIMIMEInfo_h__
#include "nsIMIMEInfo.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define NS_EXTERNALSHARINGAPPSERVICE_CONTRACTID    "@mozilla.org/uriloader/external-sharing-app-service;1"
#define NS_IEXTERNALSHARINGAPPSERVICE_CLASSNAME "Mozilla Sharing App Service"

/* starting interface:    nsISharingHandlerApp */
#define NS_ISHARINGHANDLERAPP_IID_STR "7111f769-53ec-41fd-b314-613661d5b6ba"

#define NS_ISHARINGHANDLERAPP_IID \
  {0x7111f769, 0x53ec, 0x41fd, \
    { 0xb3, 0x14, 0x61, 0x36, 0x61, 0xd5, 0xb6, 0xba }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISharingHandlerApp : public nsIHandlerApp {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISHARINGHANDLERAPP_IID)

  /* void share (in AString data, [optional] in AString title); */
  NS_SCRIPTABLE NS_IMETHOD Share(const nsAString & data, const nsAString & title) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISharingHandlerApp, NS_ISHARINGHANDLERAPP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISHARINGHANDLERAPP \
  NS_SCRIPTABLE NS_IMETHOD Share(const nsAString & data, const nsAString & title); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISHARINGHANDLERAPP(_to) \
  NS_SCRIPTABLE NS_IMETHOD Share(const nsAString & data, const nsAString & title) { return _to Share(data, title); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISHARINGHANDLERAPP(_to) \
  NS_SCRIPTABLE NS_IMETHOD Share(const nsAString & data, const nsAString & title) { return !_to ? NS_ERROR_NULL_POINTER : _to->Share(data, title); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSharingHandlerApp : public nsISharingHandlerApp
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISHARINGHANDLERAPP

  nsSharingHandlerApp();

private:
  ~nsSharingHandlerApp();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSharingHandlerApp, nsISharingHandlerApp)

nsSharingHandlerApp::nsSharingHandlerApp()
{
  /* member initializers and constructor code */
}

nsSharingHandlerApp::~nsSharingHandlerApp()
{
  /* destructor code */
}

/* void share (in AString data, [optional] in AString title); */
NS_IMETHODIMP nsSharingHandlerApp::Share(const nsAString & data, const nsAString & title)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIExternalSharingAppService */
#define NS_IEXTERNALSHARINGAPPSERVICE_IID_STR "cf7d04e5-3892-482e-81bb-073dc1c83f76"

#define NS_IEXTERNALSHARINGAPPSERVICE_IID \
  {0xcf7d04e5, 0x3892, 0x482e, \
    { 0x81, 0xbb, 0x07, 0x3d, 0xc1, 0xc8, 0x3f, 0x76 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIExternalSharingAppService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEXTERNALSHARINGAPPSERVICE_IID)

  /* void shareWithDefault (in AString data, in AString mime, [optional] in AString title); */
  NS_SCRIPTABLE NS_IMETHOD ShareWithDefault(const nsAString & data, const nsAString & mime, const nsAString & title) = 0;

  /* void getSharingApps (in AString aMIMEType, [optional] out unsigned long aLen, [array, size_is (aLen), retval] out nsISharingHandlerApp handlerApps); */
  NS_SCRIPTABLE NS_IMETHOD GetSharingApps(const nsAString & aMIMEType, PRUint32 *aLen NS_OUTPARAM, nsISharingHandlerApp ***handlerApps NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIExternalSharingAppService, NS_IEXTERNALSHARINGAPPSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEXTERNALSHARINGAPPSERVICE \
  NS_SCRIPTABLE NS_IMETHOD ShareWithDefault(const nsAString & data, const nsAString & mime, const nsAString & title); \
  NS_SCRIPTABLE NS_IMETHOD GetSharingApps(const nsAString & aMIMEType, PRUint32 *aLen NS_OUTPARAM, nsISharingHandlerApp ***handlerApps NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEXTERNALSHARINGAPPSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD ShareWithDefault(const nsAString & data, const nsAString & mime, const nsAString & title) { return _to ShareWithDefault(data, mime, title); } \
  NS_SCRIPTABLE NS_IMETHOD GetSharingApps(const nsAString & aMIMEType, PRUint32 *aLen NS_OUTPARAM, nsISharingHandlerApp ***handlerApps NS_OUTPARAM) { return _to GetSharingApps(aMIMEType, aLen, handlerApps); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEXTERNALSHARINGAPPSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD ShareWithDefault(const nsAString & data, const nsAString & mime, const nsAString & title) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShareWithDefault(data, mime, title); } \
  NS_SCRIPTABLE NS_IMETHOD GetSharingApps(const nsAString & aMIMEType, PRUint32 *aLen NS_OUTPARAM, nsISharingHandlerApp ***handlerApps NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSharingApps(aMIMEType, aLen, handlerApps); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsExternalSharingAppService : public nsIExternalSharingAppService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEXTERNALSHARINGAPPSERVICE

  nsExternalSharingAppService();

private:
  ~nsExternalSharingAppService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsExternalSharingAppService, nsIExternalSharingAppService)

nsExternalSharingAppService::nsExternalSharingAppService()
{
  /* member initializers and constructor code */
}

nsExternalSharingAppService::~nsExternalSharingAppService()
{
  /* destructor code */
}

/* void shareWithDefault (in AString data, in AString mime, [optional] in AString title); */
NS_IMETHODIMP nsExternalSharingAppService::ShareWithDefault(const nsAString & data, const nsAString & mime, const nsAString & title)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSharingApps (in AString aMIMEType, [optional] out unsigned long aLen, [array, size_is (aLen), retval] out nsISharingHandlerApp handlerApps); */
NS_IMETHODIMP nsExternalSharingAppService::GetSharingApps(const nsAString & aMIMEType, PRUint32 *aLen NS_OUTPARAM, nsISharingHandlerApp ***handlerApps NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIExternalSharingAppService_h__ */

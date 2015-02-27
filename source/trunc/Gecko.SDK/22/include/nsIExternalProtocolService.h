/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/uriloader/exthandler/nsIExternalProtocolService.idl
 */

#ifndef __gen_nsIExternalProtocolService_h__
#define __gen_nsIExternalProtocolService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIInterfaceRequestor; /* forward declaration */

class nsIHandlerInfo; /* forward declaration */


/* starting interface:    nsIExternalProtocolService */
#define NS_IEXTERNALPROTOCOLSERVICE_IID_STR "70f93b7a-3ec6-4bcb-b093-92d9984c9f83"

#define NS_IEXTERNALPROTOCOLSERVICE_IID \
  {0x70f93b7a, 0x3ec6, 0x4bcb, \
    { 0xb0, 0x93, 0x92, 0xd9, 0x98, 0x4c, 0x9f, 0x83 }}

class NS_NO_VTABLE nsIExternalProtocolService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEXTERNALPROTOCOLSERVICE_IID)

  /* boolean externalProtocolHandlerExists (in string aProtocolScheme); */
  NS_IMETHOD ExternalProtocolHandlerExists(const char * aProtocolScheme, bool *_retval) = 0;

  /* boolean isExposedProtocol (in string aProtocolScheme); */
  NS_IMETHOD IsExposedProtocol(const char * aProtocolScheme, bool *_retval) = 0;

  /* nsIHandlerInfo getProtocolHandlerInfo (in ACString aProtocolScheme); */
  NS_IMETHOD GetProtocolHandlerInfo(const nsACString & aProtocolScheme, nsIHandlerInfo * *_retval) = 0;

  /* nsIHandlerInfo getProtocolHandlerInfoFromOS (in ACString aProtocolScheme, out boolean aFound); */
  NS_IMETHOD GetProtocolHandlerInfoFromOS(const nsACString & aProtocolScheme, bool *aFound, nsIHandlerInfo * *_retval) = 0;

  /* void setProtocolHandlerDefaults (in nsIHandlerInfo aHandlerInfo, in boolean aOSHandlerExists); */
  NS_IMETHOD SetProtocolHandlerDefaults(nsIHandlerInfo *aHandlerInfo, bool aOSHandlerExists) = 0;

  /* [deprecated] void loadUrl (in nsIURI aURL); */
  NS_IMETHOD LoadUrl(nsIURI *aURL) = 0;

  /* void loadURI (in nsIURI aURI, [optional] in nsIInterfaceRequestor aWindowContext); */
  NS_IMETHOD LoadURI(nsIURI *aURI, nsIInterfaceRequestor *aWindowContext) = 0;

  /* AString getApplicationDescription (in AUTF8String aScheme); */
  NS_IMETHOD GetApplicationDescription(const nsACString & aScheme, nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIExternalProtocolService, NS_IEXTERNALPROTOCOLSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEXTERNALPROTOCOLSERVICE \
  NS_IMETHOD ExternalProtocolHandlerExists(const char * aProtocolScheme, bool *_retval); \
  NS_IMETHOD IsExposedProtocol(const char * aProtocolScheme, bool *_retval); \
  NS_IMETHOD GetProtocolHandlerInfo(const nsACString & aProtocolScheme, nsIHandlerInfo * *_retval); \
  NS_IMETHOD GetProtocolHandlerInfoFromOS(const nsACString & aProtocolScheme, bool *aFound, nsIHandlerInfo * *_retval); \
  NS_IMETHOD SetProtocolHandlerDefaults(nsIHandlerInfo *aHandlerInfo, bool aOSHandlerExists); \
  NS_IMETHOD LoadUrl(nsIURI *aURL); \
  NS_IMETHOD LoadURI(nsIURI *aURI, nsIInterfaceRequestor *aWindowContext); \
  NS_IMETHOD GetApplicationDescription(const nsACString & aScheme, nsAString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEXTERNALPROTOCOLSERVICE(_to) \
  NS_IMETHOD ExternalProtocolHandlerExists(const char * aProtocolScheme, bool *_retval) { return _to ExternalProtocolHandlerExists(aProtocolScheme, _retval); } \
  NS_IMETHOD IsExposedProtocol(const char * aProtocolScheme, bool *_retval) { return _to IsExposedProtocol(aProtocolScheme, _retval); } \
  NS_IMETHOD GetProtocolHandlerInfo(const nsACString & aProtocolScheme, nsIHandlerInfo * *_retval) { return _to GetProtocolHandlerInfo(aProtocolScheme, _retval); } \
  NS_IMETHOD GetProtocolHandlerInfoFromOS(const nsACString & aProtocolScheme, bool *aFound, nsIHandlerInfo * *_retval) { return _to GetProtocolHandlerInfoFromOS(aProtocolScheme, aFound, _retval); } \
  NS_IMETHOD SetProtocolHandlerDefaults(nsIHandlerInfo *aHandlerInfo, bool aOSHandlerExists) { return _to SetProtocolHandlerDefaults(aHandlerInfo, aOSHandlerExists); } \
  NS_IMETHOD LoadUrl(nsIURI *aURL) { return _to LoadUrl(aURL); } \
  NS_IMETHOD LoadURI(nsIURI *aURI, nsIInterfaceRequestor *aWindowContext) { return _to LoadURI(aURI, aWindowContext); } \
  NS_IMETHOD GetApplicationDescription(const nsACString & aScheme, nsAString & _retval) { return _to GetApplicationDescription(aScheme, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEXTERNALPROTOCOLSERVICE(_to) \
  NS_IMETHOD ExternalProtocolHandlerExists(const char * aProtocolScheme, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExternalProtocolHandlerExists(aProtocolScheme, _retval); } \
  NS_IMETHOD IsExposedProtocol(const char * aProtocolScheme, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsExposedProtocol(aProtocolScheme, _retval); } \
  NS_IMETHOD GetProtocolHandlerInfo(const nsACString & aProtocolScheme, nsIHandlerInfo * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProtocolHandlerInfo(aProtocolScheme, _retval); } \
  NS_IMETHOD GetProtocolHandlerInfoFromOS(const nsACString & aProtocolScheme, bool *aFound, nsIHandlerInfo * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProtocolHandlerInfoFromOS(aProtocolScheme, aFound, _retval); } \
  NS_IMETHOD SetProtocolHandlerDefaults(nsIHandlerInfo *aHandlerInfo, bool aOSHandlerExists) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProtocolHandlerDefaults(aHandlerInfo, aOSHandlerExists); } \
  NS_IMETHOD LoadUrl(nsIURI *aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadUrl(aURL); } \
  NS_IMETHOD LoadURI(nsIURI *aURI, nsIInterfaceRequestor *aWindowContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadURI(aURI, aWindowContext); } \
  NS_IMETHOD GetApplicationDescription(const nsACString & aScheme, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApplicationDescription(aScheme, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsExternalProtocolService : public nsIExternalProtocolService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEXTERNALPROTOCOLSERVICE

  nsExternalProtocolService();

private:
  ~nsExternalProtocolService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsExternalProtocolService, nsIExternalProtocolService)

nsExternalProtocolService::nsExternalProtocolService()
{
  /* member initializers and constructor code */
}

nsExternalProtocolService::~nsExternalProtocolService()
{
  /* destructor code */
}

/* boolean externalProtocolHandlerExists (in string aProtocolScheme); */
NS_IMETHODIMP nsExternalProtocolService::ExternalProtocolHandlerExists(const char * aProtocolScheme, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isExposedProtocol (in string aProtocolScheme); */
NS_IMETHODIMP nsExternalProtocolService::IsExposedProtocol(const char * aProtocolScheme, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIHandlerInfo getProtocolHandlerInfo (in ACString aProtocolScheme); */
NS_IMETHODIMP nsExternalProtocolService::GetProtocolHandlerInfo(const nsACString & aProtocolScheme, nsIHandlerInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIHandlerInfo getProtocolHandlerInfoFromOS (in ACString aProtocolScheme, out boolean aFound); */
NS_IMETHODIMP nsExternalProtocolService::GetProtocolHandlerInfoFromOS(const nsACString & aProtocolScheme, bool *aFound, nsIHandlerInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setProtocolHandlerDefaults (in nsIHandlerInfo aHandlerInfo, in boolean aOSHandlerExists); */
NS_IMETHODIMP nsExternalProtocolService::SetProtocolHandlerDefaults(nsIHandlerInfo *aHandlerInfo, bool aOSHandlerExists)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [deprecated] void loadUrl (in nsIURI aURL); */
NS_IMETHODIMP nsExternalProtocolService::LoadUrl(nsIURI *aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadURI (in nsIURI aURI, [optional] in nsIInterfaceRequestor aWindowContext); */
NS_IMETHODIMP nsExternalProtocolService::LoadURI(nsIURI *aURI, nsIInterfaceRequestor *aWindowContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getApplicationDescription (in AUTF8String aScheme); */
NS_IMETHODIMP nsExternalProtocolService::GetApplicationDescription(const nsACString & aScheme, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIExternalProtocolService_h__ */

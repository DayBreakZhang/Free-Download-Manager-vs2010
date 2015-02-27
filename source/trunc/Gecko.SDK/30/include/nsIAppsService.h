/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAppsService.idl
 */

#ifndef __gen_nsIAppsService_h__
#define __gen_nsIAppsService_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class mozIDOMApplication; /* forward declaration */

class mozIApplication; /* forward declaration */

class nsIURI; /* forward declaration */

#define APPS_SERVICE_CID { 0x05072afa, 0x92fe, 0x45bf, { 0xae, 0x22, 0x39, 0xb6, 0x9c, 0x11, 0x70, 0x58 } }
#define APPS_SERVICE_CONTRACTID "@mozilla.org/AppsService;1"

/* starting interface:    nsIAppsService */
#define NS_IAPPSSERVICE_IID_STR "93cde78d-56f6-4322-b707-9b23eb80d90d"

#define NS_IAPPSSERVICE_IID \
  {0x93cde78d, 0x56f6, 0x4322, \
    { 0xb7, 0x07, 0x9b, 0x23, 0xeb, 0x80, 0xd9, 0x0d }}

class NS_NO_VTABLE nsIAppsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPSSERVICE_IID)

  /* mozIApplication getAppByManifestURL (in DOMString manifestURL); */
  NS_IMETHOD GetAppByManifestURL(const nsAString & manifestURL, mozIApplication * *_retval) = 0;

  /* unsigned long getAppLocalIdByManifestURL (in DOMString manifestURL); */
  NS_IMETHOD GetAppLocalIdByManifestURL(const nsAString & manifestURL, uint32_t *_retval) = 0;

  /* mozIApplication getAppByLocalId (in unsigned long localId); */
  NS_IMETHOD GetAppByLocalId(uint32_t localId, mozIApplication * *_retval) = 0;

  /* DOMString getManifestURLByLocalId (in unsigned long localId); */
  NS_IMETHOD GetManifestURLByLocalId(uint32_t localId, nsAString & _retval) = 0;

  /* DOMString getCSPByLocalId (in unsigned long localId); */
  NS_IMETHOD GetCSPByLocalId(uint32_t localId, nsAString & _retval) = 0;

  /* DOMString getCoreAppsBasePath (); */
  NS_IMETHOD GetCoreAppsBasePath(nsAString & _retval) = 0;

  /* DOMString getWebAppsBasePath (); */
  NS_IMETHOD GetWebAppsBasePath(nsAString & _retval) = 0;

  /* jsval getAppInfo (in DOMString appId); */
  NS_IMETHOD GetAppInfo(const nsAString & appId, JS::MutableHandleValue _retval) = 0;

  /* nsIURI getRedirect (in unsigned long localId, in nsIURI uri); */
  NS_IMETHOD GetRedirect(uint32_t localId, nsIURI *uri, nsIURI * *_retval) = 0;

  /* DOMString getAppLocalIdByStoreId (in DOMString storeID); */
  NS_IMETHOD GetAppLocalIdByStoreId(const nsAString & storeID, nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAppsService, NS_IAPPSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPSSERVICE \
  NS_IMETHOD GetAppByManifestURL(const nsAString & manifestURL, mozIApplication * *_retval); \
  NS_IMETHOD GetAppLocalIdByManifestURL(const nsAString & manifestURL, uint32_t *_retval); \
  NS_IMETHOD GetAppByLocalId(uint32_t localId, mozIApplication * *_retval); \
  NS_IMETHOD GetManifestURLByLocalId(uint32_t localId, nsAString & _retval); \
  NS_IMETHOD GetCSPByLocalId(uint32_t localId, nsAString & _retval); \
  NS_IMETHOD GetCoreAppsBasePath(nsAString & _retval); \
  NS_IMETHOD GetWebAppsBasePath(nsAString & _retval); \
  NS_IMETHOD GetAppInfo(const nsAString & appId, JS::MutableHandleValue _retval); \
  NS_IMETHOD GetRedirect(uint32_t localId, nsIURI *uri, nsIURI * *_retval); \
  NS_IMETHOD GetAppLocalIdByStoreId(const nsAString & storeID, nsAString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPSSERVICE(_to) \
  NS_IMETHOD GetAppByManifestURL(const nsAString & manifestURL, mozIApplication * *_retval) { return _to GetAppByManifestURL(manifestURL, _retval); } \
  NS_IMETHOD GetAppLocalIdByManifestURL(const nsAString & manifestURL, uint32_t *_retval) { return _to GetAppLocalIdByManifestURL(manifestURL, _retval); } \
  NS_IMETHOD GetAppByLocalId(uint32_t localId, mozIApplication * *_retval) { return _to GetAppByLocalId(localId, _retval); } \
  NS_IMETHOD GetManifestURLByLocalId(uint32_t localId, nsAString & _retval) { return _to GetManifestURLByLocalId(localId, _retval); } \
  NS_IMETHOD GetCSPByLocalId(uint32_t localId, nsAString & _retval) { return _to GetCSPByLocalId(localId, _retval); } \
  NS_IMETHOD GetCoreAppsBasePath(nsAString & _retval) { return _to GetCoreAppsBasePath(_retval); } \
  NS_IMETHOD GetWebAppsBasePath(nsAString & _retval) { return _to GetWebAppsBasePath(_retval); } \
  NS_IMETHOD GetAppInfo(const nsAString & appId, JS::MutableHandleValue _retval) { return _to GetAppInfo(appId, _retval); } \
  NS_IMETHOD GetRedirect(uint32_t localId, nsIURI *uri, nsIURI * *_retval) { return _to GetRedirect(localId, uri, _retval); } \
  NS_IMETHOD GetAppLocalIdByStoreId(const nsAString & storeID, nsAString & _retval) { return _to GetAppLocalIdByStoreId(storeID, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPSSERVICE(_to) \
  NS_IMETHOD GetAppByManifestURL(const nsAString & manifestURL, mozIApplication * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppByManifestURL(manifestURL, _retval); } \
  NS_IMETHOD GetAppLocalIdByManifestURL(const nsAString & manifestURL, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppLocalIdByManifestURL(manifestURL, _retval); } \
  NS_IMETHOD GetAppByLocalId(uint32_t localId, mozIApplication * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppByLocalId(localId, _retval); } \
  NS_IMETHOD GetManifestURLByLocalId(uint32_t localId, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetManifestURLByLocalId(localId, _retval); } \
  NS_IMETHOD GetCSPByLocalId(uint32_t localId, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCSPByLocalId(localId, _retval); } \
  NS_IMETHOD GetCoreAppsBasePath(nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCoreAppsBasePath(_retval); } \
  NS_IMETHOD GetWebAppsBasePath(nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWebAppsBasePath(_retval); } \
  NS_IMETHOD GetAppInfo(const nsAString & appId, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppInfo(appId, _retval); } \
  NS_IMETHOD GetRedirect(uint32_t localId, nsIURI *uri, nsIURI * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRedirect(localId, uri, _retval); } \
  NS_IMETHOD GetAppLocalIdByStoreId(const nsAString & storeID, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppLocalIdByStoreId(storeID, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAppsService : public nsIAppsService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPSSERVICE

  nsAppsService();

private:
  ~nsAppsService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAppsService, nsIAppsService)

nsAppsService::nsAppsService()
{
  /* member initializers and constructor code */
}

nsAppsService::~nsAppsService()
{
  /* destructor code */
}

/* mozIApplication getAppByManifestURL (in DOMString manifestURL); */
NS_IMETHODIMP nsAppsService::GetAppByManifestURL(const nsAString & manifestURL, mozIApplication * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getAppLocalIdByManifestURL (in DOMString manifestURL); */
NS_IMETHODIMP nsAppsService::GetAppLocalIdByManifestURL(const nsAString & manifestURL, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIApplication getAppByLocalId (in unsigned long localId); */
NS_IMETHODIMP nsAppsService::GetAppByLocalId(uint32_t localId, mozIApplication * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getManifestURLByLocalId (in unsigned long localId); */
NS_IMETHODIMP nsAppsService::GetManifestURLByLocalId(uint32_t localId, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getCSPByLocalId (in unsigned long localId); */
NS_IMETHODIMP nsAppsService::GetCSPByLocalId(uint32_t localId, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getCoreAppsBasePath (); */
NS_IMETHODIMP nsAppsService::GetCoreAppsBasePath(nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getWebAppsBasePath (); */
NS_IMETHODIMP nsAppsService::GetWebAppsBasePath(nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval getAppInfo (in DOMString appId); */
NS_IMETHODIMP nsAppsService::GetAppInfo(const nsAString & appId, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI getRedirect (in unsigned long localId, in nsIURI uri); */
NS_IMETHODIMP nsAppsService::GetRedirect(uint32_t localId, nsIURI *uri, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getAppLocalIdByStoreId (in DOMString storeID); */
NS_IMETHODIMP nsAppsService::GetAppLocalIdByStoreId(const nsAString & storeID, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAppsService_h__ */

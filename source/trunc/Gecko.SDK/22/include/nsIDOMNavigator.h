/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/base/nsIDOMNavigator.idl
 */

#ifndef __gen_nsIDOMNavigator_h__
#define __gen_nsIDOMNavigator_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIIdleObserver; /* forward declaration */


/* starting interface:    nsIDOMNavigator */
#define NS_IDOMNAVIGATOR_IID_STR "b0ccf251-d793-48a1-94aa-cf840fe6639d"

#define NS_IDOMNAVIGATOR_IID \
  {0xb0ccf251, 0xd793, 0x48a1, \
    { 0x94, 0xaa, 0xcf, 0x84, 0x0f, 0xe6, 0x63, 0x9d }}

class NS_NO_VTABLE nsIDOMNavigator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNAVIGATOR_IID)

  /* readonly attribute DOMString appCodeName; */
  NS_IMETHOD GetAppCodeName(nsAString & aAppCodeName) = 0;

  /* readonly attribute DOMString appName; */
  NS_IMETHOD GetAppName(nsAString & aAppName) = 0;

  /* readonly attribute DOMString appVersion; */
  NS_IMETHOD GetAppVersion(nsAString & aAppVersion) = 0;

  /* readonly attribute DOMString language; */
  NS_IMETHOD GetLanguage(nsAString & aLanguage) = 0;

  /* readonly attribute nsIDOMMimeTypeArray mimeTypes; */
  NS_IMETHOD GetMimeTypes(nsIDOMMimeTypeArray * *aMimeTypes) = 0;

  /* readonly attribute DOMString platform; */
  NS_IMETHOD GetPlatform(nsAString & aPlatform) = 0;

  /* readonly attribute DOMString oscpu; */
  NS_IMETHOD GetOscpu(nsAString & aOscpu) = 0;

  /* readonly attribute DOMString vendor; */
  NS_IMETHOD GetVendor(nsAString & aVendor) = 0;

  /* readonly attribute DOMString vendorSub; */
  NS_IMETHOD GetVendorSub(nsAString & aVendorSub) = 0;

  /* readonly attribute DOMString product; */
  NS_IMETHOD GetProduct(nsAString & aProduct) = 0;

  /* readonly attribute DOMString productSub; */
  NS_IMETHOD GetProductSub(nsAString & aProductSub) = 0;

  /* readonly attribute nsIDOMPluginArray plugins; */
  NS_IMETHOD GetPlugins(nsIDOMPluginArray * *aPlugins) = 0;

  /* readonly attribute DOMString userAgent; */
  NS_IMETHOD GetUserAgent(nsAString & aUserAgent) = 0;

  /* readonly attribute boolean cookieEnabled; */
  NS_IMETHOD GetCookieEnabled(bool *aCookieEnabled) = 0;

  /* readonly attribute boolean onLine; */
  NS_IMETHOD GetOnLine(bool *aOnLine) = 0;

  /* readonly attribute DOMString buildID; */
  NS_IMETHOD GetBuildID(nsAString & aBuildID) = 0;

  /* readonly attribute DOMString doNotTrack; */
  NS_IMETHOD GetDoNotTrack(nsAString & aDoNotTrack) = 0;

  /* readonly attribute nsIDOMMozPowerManager mozPower; */
  NS_IMETHOD GetMozPower(nsIDOMMozPowerManager * *aMozPower) = 0;

  /* boolean javaEnabled (); */
  NS_IMETHOD JavaEnabled(bool *_retval) = 0;

  /* boolean taintEnabled (); */
  NS_IMETHOD TaintEnabled(bool *_retval) = 0;

  /* [implicit_jscontext] void vibrate (in jsval aPattern); */
  NS_IMETHOD Vibrate(const JS::Value & aPattern, JSContext* cx) = 0;

  /* void addIdleObserver (in nsIIdleObserver aIdleObserver); */
  NS_IMETHOD AddIdleObserver(nsIIdleObserver *aIdleObserver) = 0;

  /* void removeIdleObserver (in nsIIdleObserver aIdleObserver); */
  NS_IMETHOD RemoveIdleObserver(nsIIdleObserver *aIdleObserver) = 0;

  /* nsIDOMMozWakeLock requestWakeLock (in DOMString aTopic); */
  NS_IMETHOD RequestWakeLock(const nsAString & aTopic, nsIDOMMozWakeLock * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNavigator, NS_IDOMNAVIGATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNAVIGATOR \
  NS_IMETHOD GetAppCodeName(nsAString & aAppCodeName); \
  NS_IMETHOD GetAppName(nsAString & aAppName); \
  NS_IMETHOD GetAppVersion(nsAString & aAppVersion); \
  NS_IMETHOD GetLanguage(nsAString & aLanguage); \
  NS_IMETHOD GetMimeTypes(nsIDOMMimeTypeArray * *aMimeTypes); \
  NS_IMETHOD GetPlatform(nsAString & aPlatform); \
  NS_IMETHOD GetOscpu(nsAString & aOscpu); \
  NS_IMETHOD GetVendor(nsAString & aVendor); \
  NS_IMETHOD GetVendorSub(nsAString & aVendorSub); \
  NS_IMETHOD GetProduct(nsAString & aProduct); \
  NS_IMETHOD GetProductSub(nsAString & aProductSub); \
  NS_IMETHOD GetPlugins(nsIDOMPluginArray * *aPlugins); \
  NS_IMETHOD GetUserAgent(nsAString & aUserAgent); \
  NS_IMETHOD GetCookieEnabled(bool *aCookieEnabled); \
  NS_IMETHOD GetOnLine(bool *aOnLine); \
  NS_IMETHOD GetBuildID(nsAString & aBuildID); \
  NS_IMETHOD GetDoNotTrack(nsAString & aDoNotTrack); \
  NS_IMETHOD GetMozPower(nsIDOMMozPowerManager * *aMozPower); \
  NS_IMETHOD JavaEnabled(bool *_retval); \
  NS_IMETHOD TaintEnabled(bool *_retval); \
  NS_IMETHOD Vibrate(const JS::Value & aPattern, JSContext* cx); \
  NS_IMETHOD AddIdleObserver(nsIIdleObserver *aIdleObserver); \
  NS_IMETHOD RemoveIdleObserver(nsIIdleObserver *aIdleObserver); \
  NS_IMETHOD RequestWakeLock(const nsAString & aTopic, nsIDOMMozWakeLock * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNAVIGATOR(_to) \
  NS_IMETHOD GetAppCodeName(nsAString & aAppCodeName) { return _to GetAppCodeName(aAppCodeName); } \
  NS_IMETHOD GetAppName(nsAString & aAppName) { return _to GetAppName(aAppName); } \
  NS_IMETHOD GetAppVersion(nsAString & aAppVersion) { return _to GetAppVersion(aAppVersion); } \
  NS_IMETHOD GetLanguage(nsAString & aLanguage) { return _to GetLanguage(aLanguage); } \
  NS_IMETHOD GetMimeTypes(nsIDOMMimeTypeArray * *aMimeTypes) { return _to GetMimeTypes(aMimeTypes); } \
  NS_IMETHOD GetPlatform(nsAString & aPlatform) { return _to GetPlatform(aPlatform); } \
  NS_IMETHOD GetOscpu(nsAString & aOscpu) { return _to GetOscpu(aOscpu); } \
  NS_IMETHOD GetVendor(nsAString & aVendor) { return _to GetVendor(aVendor); } \
  NS_IMETHOD GetVendorSub(nsAString & aVendorSub) { return _to GetVendorSub(aVendorSub); } \
  NS_IMETHOD GetProduct(nsAString & aProduct) { return _to GetProduct(aProduct); } \
  NS_IMETHOD GetProductSub(nsAString & aProductSub) { return _to GetProductSub(aProductSub); } \
  NS_IMETHOD GetPlugins(nsIDOMPluginArray * *aPlugins) { return _to GetPlugins(aPlugins); } \
  NS_IMETHOD GetUserAgent(nsAString & aUserAgent) { return _to GetUserAgent(aUserAgent); } \
  NS_IMETHOD GetCookieEnabled(bool *aCookieEnabled) { return _to GetCookieEnabled(aCookieEnabled); } \
  NS_IMETHOD GetOnLine(bool *aOnLine) { return _to GetOnLine(aOnLine); } \
  NS_IMETHOD GetBuildID(nsAString & aBuildID) { return _to GetBuildID(aBuildID); } \
  NS_IMETHOD GetDoNotTrack(nsAString & aDoNotTrack) { return _to GetDoNotTrack(aDoNotTrack); } \
  NS_IMETHOD GetMozPower(nsIDOMMozPowerManager * *aMozPower) { return _to GetMozPower(aMozPower); } \
  NS_IMETHOD JavaEnabled(bool *_retval) { return _to JavaEnabled(_retval); } \
  NS_IMETHOD TaintEnabled(bool *_retval) { return _to TaintEnabled(_retval); } \
  NS_IMETHOD Vibrate(const JS::Value & aPattern, JSContext* cx) { return _to Vibrate(aPattern, cx); } \
  NS_IMETHOD AddIdleObserver(nsIIdleObserver *aIdleObserver) { return _to AddIdleObserver(aIdleObserver); } \
  NS_IMETHOD RemoveIdleObserver(nsIIdleObserver *aIdleObserver) { return _to RemoveIdleObserver(aIdleObserver); } \
  NS_IMETHOD RequestWakeLock(const nsAString & aTopic, nsIDOMMozWakeLock * *_retval) { return _to RequestWakeLock(aTopic, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNAVIGATOR(_to) \
  NS_IMETHOD GetAppCodeName(nsAString & aAppCodeName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppCodeName(aAppCodeName); } \
  NS_IMETHOD GetAppName(nsAString & aAppName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppName(aAppName); } \
  NS_IMETHOD GetAppVersion(nsAString & aAppVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppVersion(aAppVersion); } \
  NS_IMETHOD GetLanguage(nsAString & aLanguage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLanguage(aLanguage); } \
  NS_IMETHOD GetMimeTypes(nsIDOMMimeTypeArray * *aMimeTypes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMimeTypes(aMimeTypes); } \
  NS_IMETHOD GetPlatform(nsAString & aPlatform) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlatform(aPlatform); } \
  NS_IMETHOD GetOscpu(nsAString & aOscpu) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOscpu(aOscpu); } \
  NS_IMETHOD GetVendor(nsAString & aVendor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVendor(aVendor); } \
  NS_IMETHOD GetVendorSub(nsAString & aVendorSub) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVendorSub(aVendorSub); } \
  NS_IMETHOD GetProduct(nsAString & aProduct) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProduct(aProduct); } \
  NS_IMETHOD GetProductSub(nsAString & aProductSub) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProductSub(aProductSub); } \
  NS_IMETHOD GetPlugins(nsIDOMPluginArray * *aPlugins) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlugins(aPlugins); } \
  NS_IMETHOD GetUserAgent(nsAString & aUserAgent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUserAgent(aUserAgent); } \
  NS_IMETHOD GetCookieEnabled(bool *aCookieEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCookieEnabled(aCookieEnabled); } \
  NS_IMETHOD GetOnLine(bool *aOnLine) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnLine(aOnLine); } \
  NS_IMETHOD GetBuildID(nsAString & aBuildID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBuildID(aBuildID); } \
  NS_IMETHOD GetDoNotTrack(nsAString & aDoNotTrack) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDoNotTrack(aDoNotTrack); } \
  NS_IMETHOD GetMozPower(nsIDOMMozPowerManager * *aMozPower) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozPower(aMozPower); } \
  NS_IMETHOD JavaEnabled(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->JavaEnabled(_retval); } \
  NS_IMETHOD TaintEnabled(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TaintEnabled(_retval); } \
  NS_IMETHOD Vibrate(const JS::Value & aPattern, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->Vibrate(aPattern, cx); } \
  NS_IMETHOD AddIdleObserver(nsIIdleObserver *aIdleObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddIdleObserver(aIdleObserver); } \
  NS_IMETHOD RemoveIdleObserver(nsIIdleObserver *aIdleObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveIdleObserver(aIdleObserver); } \
  NS_IMETHOD RequestWakeLock(const nsAString & aTopic, nsIDOMMozWakeLock * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestWakeLock(aTopic, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNavigator : public nsIDOMNavigator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNAVIGATOR

  nsDOMNavigator();

private:
  ~nsDOMNavigator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNavigator, nsIDOMNavigator)

nsDOMNavigator::nsDOMNavigator()
{
  /* member initializers and constructor code */
}

nsDOMNavigator::~nsDOMNavigator()
{
  /* destructor code */
}

/* readonly attribute DOMString appCodeName; */
NS_IMETHODIMP nsDOMNavigator::GetAppCodeName(nsAString & aAppCodeName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString appName; */
NS_IMETHODIMP nsDOMNavigator::GetAppName(nsAString & aAppName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString appVersion; */
NS_IMETHODIMP nsDOMNavigator::GetAppVersion(nsAString & aAppVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString language; */
NS_IMETHODIMP nsDOMNavigator::GetLanguage(nsAString & aLanguage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMMimeTypeArray mimeTypes; */
NS_IMETHODIMP nsDOMNavigator::GetMimeTypes(nsIDOMMimeTypeArray * *aMimeTypes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString platform; */
NS_IMETHODIMP nsDOMNavigator::GetPlatform(nsAString & aPlatform)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString oscpu; */
NS_IMETHODIMP nsDOMNavigator::GetOscpu(nsAString & aOscpu)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString vendor; */
NS_IMETHODIMP nsDOMNavigator::GetVendor(nsAString & aVendor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString vendorSub; */
NS_IMETHODIMP nsDOMNavigator::GetVendorSub(nsAString & aVendorSub)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString product; */
NS_IMETHODIMP nsDOMNavigator::GetProduct(nsAString & aProduct)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString productSub; */
NS_IMETHODIMP nsDOMNavigator::GetProductSub(nsAString & aProductSub)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMPluginArray plugins; */
NS_IMETHODIMP nsDOMNavigator::GetPlugins(nsIDOMPluginArray * *aPlugins)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString userAgent; */
NS_IMETHODIMP nsDOMNavigator::GetUserAgent(nsAString & aUserAgent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean cookieEnabled; */
NS_IMETHODIMP nsDOMNavigator::GetCookieEnabled(bool *aCookieEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean onLine; */
NS_IMETHODIMP nsDOMNavigator::GetOnLine(bool *aOnLine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString buildID; */
NS_IMETHODIMP nsDOMNavigator::GetBuildID(nsAString & aBuildID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString doNotTrack; */
NS_IMETHODIMP nsDOMNavigator::GetDoNotTrack(nsAString & aDoNotTrack)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMMozPowerManager mozPower; */
NS_IMETHODIMP nsDOMNavigator::GetMozPower(nsIDOMMozPowerManager * *aMozPower)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean javaEnabled (); */
NS_IMETHODIMP nsDOMNavigator::JavaEnabled(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean taintEnabled (); */
NS_IMETHODIMP nsDOMNavigator::TaintEnabled(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void vibrate (in jsval aPattern); */
NS_IMETHODIMP nsDOMNavigator::Vibrate(const JS::Value & aPattern, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addIdleObserver (in nsIIdleObserver aIdleObserver); */
NS_IMETHODIMP nsDOMNavigator::AddIdleObserver(nsIIdleObserver *aIdleObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeIdleObserver (in nsIIdleObserver aIdleObserver); */
NS_IMETHODIMP nsDOMNavigator::RemoveIdleObserver(nsIIdleObserver *aIdleObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMMozWakeLock requestWakeLock (in DOMString aTopic); */
NS_IMETHODIMP nsDOMNavigator::RequestWakeLock(const nsAString & aTopic, nsIDOMMozWakeLock * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNavigator_h__ */

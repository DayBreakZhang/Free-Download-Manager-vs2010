/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/geolocation/nsIDOMGeoGeolocation.idl
 */

#ifndef __gen_nsIDOMGeoGeolocation_h__
#define __gen_nsIDOMGeoGeolocation_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMGeoPosition; /* forward declaration */

class nsIDOMGeoPositionOptions; /* forward declaration */

class nsIDOMGeoPositionCallback; /* forward declaration */

class nsIDOMGeoPositionErrorCallback; /* forward declaration */


/* starting interface:    nsIDOMGeoGeolocation */
#define NS_IDOMGEOGEOLOCATION_IID_STR "b9a301f7-285b-4be9-b739-fb869019c77a"

#define NS_IDOMGEOGEOLOCATION_IID \
  {0xb9a301f7, 0x285b, 0x4be9, \
    { 0xb7, 0x39, 0xfb, 0x86, 0x90, 0x19, 0xc7, 0x7a }}

class NS_NO_VTABLE nsIDOMGeoGeolocation : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGEOGEOLOCATION_IID)

  /* [implicit_jscontext] void getCurrentPosition (in nsIDOMGeoPositionCallback successCallback, [optional] in nsIDOMGeoPositionErrorCallback errorCallback, [optional] in jsval options); */
  NS_IMETHOD GetCurrentPosition(nsIDOMGeoPositionCallback *successCallback, nsIDOMGeoPositionErrorCallback *errorCallback, const JS::Value & options, JSContext* cx) = 0;

  /* [implicit_jscontext] long watchPosition (in nsIDOMGeoPositionCallback successCallback, [optional] in nsIDOMGeoPositionErrorCallback errorCallback, [optional] in jsval options); */
  NS_IMETHOD WatchPosition(nsIDOMGeoPositionCallback *successCallback, nsIDOMGeoPositionErrorCallback *errorCallback, const JS::Value & options, JSContext* cx, int32_t *_retval) = 0;

  /* void clearWatch (in long watchId); */
  NS_IMETHOD ClearWatch(int32_t watchId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGeoGeolocation, NS_IDOMGEOGEOLOCATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGEOGEOLOCATION \
  NS_IMETHOD GetCurrentPosition(nsIDOMGeoPositionCallback *successCallback, nsIDOMGeoPositionErrorCallback *errorCallback, const JS::Value & options, JSContext* cx); \
  NS_IMETHOD WatchPosition(nsIDOMGeoPositionCallback *successCallback, nsIDOMGeoPositionErrorCallback *errorCallback, const JS::Value & options, JSContext* cx, int32_t *_retval); \
  NS_IMETHOD ClearWatch(int32_t watchId); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGEOGEOLOCATION(_to) \
  NS_IMETHOD GetCurrentPosition(nsIDOMGeoPositionCallback *successCallback, nsIDOMGeoPositionErrorCallback *errorCallback, const JS::Value & options, JSContext* cx) { return _to GetCurrentPosition(successCallback, errorCallback, options, cx); } \
  NS_IMETHOD WatchPosition(nsIDOMGeoPositionCallback *successCallback, nsIDOMGeoPositionErrorCallback *errorCallback, const JS::Value & options, JSContext* cx, int32_t *_retval) { return _to WatchPosition(successCallback, errorCallback, options, cx, _retval); } \
  NS_IMETHOD ClearWatch(int32_t watchId) { return _to ClearWatch(watchId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGEOGEOLOCATION(_to) \
  NS_IMETHOD GetCurrentPosition(nsIDOMGeoPositionCallback *successCallback, nsIDOMGeoPositionErrorCallback *errorCallback, const JS::Value & options, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentPosition(successCallback, errorCallback, options, cx); } \
  NS_IMETHOD WatchPosition(nsIDOMGeoPositionCallback *successCallback, nsIDOMGeoPositionErrorCallback *errorCallback, const JS::Value & options, JSContext* cx, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->WatchPosition(successCallback, errorCallback, options, cx, _retval); } \
  NS_IMETHOD ClearWatch(int32_t watchId) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearWatch(watchId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGeoGeolocation : public nsIDOMGeoGeolocation
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGEOGEOLOCATION

  nsDOMGeoGeolocation();

private:
  ~nsDOMGeoGeolocation();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMGeoGeolocation, nsIDOMGeoGeolocation)

nsDOMGeoGeolocation::nsDOMGeoGeolocation()
{
  /* member initializers and constructor code */
}

nsDOMGeoGeolocation::~nsDOMGeoGeolocation()
{
  /* destructor code */
}

/* [implicit_jscontext] void getCurrentPosition (in nsIDOMGeoPositionCallback successCallback, [optional] in nsIDOMGeoPositionErrorCallback errorCallback, [optional] in jsval options); */
NS_IMETHODIMP nsDOMGeoGeolocation::GetCurrentPosition(nsIDOMGeoPositionCallback *successCallback, nsIDOMGeoPositionErrorCallback *errorCallback, const JS::Value & options, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] long watchPosition (in nsIDOMGeoPositionCallback successCallback, [optional] in nsIDOMGeoPositionErrorCallback errorCallback, [optional] in jsval options); */
NS_IMETHODIMP nsDOMGeoGeolocation::WatchPosition(nsIDOMGeoPositionCallback *successCallback, nsIDOMGeoPositionErrorCallback *errorCallback, const JS::Value & options, JSContext* cx, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearWatch (in long watchId); */
NS_IMETHODIMP nsDOMGeoGeolocation::ClearWatch(int32_t watchId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMGeoGeolocation_h__ */

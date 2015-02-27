/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/geolocation/nsIGeolocation.idl
 */

#ifndef __gen_nsIGeolocation_h__
#define __gen_nsIGeolocation_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMGeoPositionCallback; /* forward declaration */

class nsIDOMGeoPositionErrorCallback; /* forward declaration */

namespace mozilla {
namespace idl {
class GeoPositionOptions;
}
}

/* starting interface:    nsIGeolocation */
#define NS_IGEOLOCATION_IID_STR "d8e6449f-92c8-4c6a-aa9f-fef70157ec29"

#define NS_IGEOLOCATION_IID \
  {0xd8e6449f, 0x92c8, 0x4c6a, \
    { 0xaa, 0x9f, 0xfe, 0xf7, 0x01, 0x57, 0xec, 0x29 }}

class NS_NO_VTABLE nsIGeolocation : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGEOLOCATION_IID)

  /* int32_t watchPosition (in nsIDOMGeoPositionCallback callback, in nsIDOMGeoPositionErrorCallback errorCallback, in GeoPositionOptions options); */
  NS_IMETHOD WatchPosition(nsIDOMGeoPositionCallback *callback, nsIDOMGeoPositionErrorCallback *errorCallback, mozilla::idl::GeoPositionOptions *options, int32_t *_retval) = 0;

  /* void getCurrentPosition (in nsIDOMGeoPositionCallback callback, in nsIDOMGeoPositionErrorCallback errorCallback, in GeoPositionOptions options); */
  NS_IMETHOD GetCurrentPosition(nsIDOMGeoPositionCallback *callback, nsIDOMGeoPositionErrorCallback *errorCallback, mozilla::idl::GeoPositionOptions *options) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGeolocation, NS_IGEOLOCATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGEOLOCATION \
  NS_IMETHOD WatchPosition(nsIDOMGeoPositionCallback *callback, nsIDOMGeoPositionErrorCallback *errorCallback, mozilla::idl::GeoPositionOptions *options, int32_t *_retval); \
  NS_IMETHOD GetCurrentPosition(nsIDOMGeoPositionCallback *callback, nsIDOMGeoPositionErrorCallback *errorCallback, mozilla::idl::GeoPositionOptions *options); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGEOLOCATION(_to) \
  NS_IMETHOD WatchPosition(nsIDOMGeoPositionCallback *callback, nsIDOMGeoPositionErrorCallback *errorCallback, mozilla::idl::GeoPositionOptions *options, int32_t *_retval) { return _to WatchPosition(callback, errorCallback, options, _retval); } \
  NS_IMETHOD GetCurrentPosition(nsIDOMGeoPositionCallback *callback, nsIDOMGeoPositionErrorCallback *errorCallback, mozilla::idl::GeoPositionOptions *options) { return _to GetCurrentPosition(callback, errorCallback, options); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGEOLOCATION(_to) \
  NS_IMETHOD WatchPosition(nsIDOMGeoPositionCallback *callback, nsIDOMGeoPositionErrorCallback *errorCallback, mozilla::idl::GeoPositionOptions *options, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->WatchPosition(callback, errorCallback, options, _retval); } \
  NS_IMETHOD GetCurrentPosition(nsIDOMGeoPositionCallback *callback, nsIDOMGeoPositionErrorCallback *errorCallback, mozilla::idl::GeoPositionOptions *options) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentPosition(callback, errorCallback, options); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGeolocation : public nsIGeolocation
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGEOLOCATION

  nsGeolocation();

private:
  ~nsGeolocation();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsGeolocation, nsIGeolocation)

nsGeolocation::nsGeolocation()
{
  /* member initializers and constructor code */
}

nsGeolocation::~nsGeolocation()
{
  /* destructor code */
}

/* int32_t watchPosition (in nsIDOMGeoPositionCallback callback, in nsIDOMGeoPositionErrorCallback errorCallback, in GeoPositionOptions options); */
NS_IMETHODIMP nsGeolocation::WatchPosition(nsIDOMGeoPositionCallback *callback, nsIDOMGeoPositionErrorCallback *errorCallback, mozilla::idl::GeoPositionOptions *options, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCurrentPosition (in nsIDOMGeoPositionCallback callback, in nsIDOMGeoPositionErrorCallback errorCallback, in GeoPositionOptions options); */
NS_IMETHODIMP nsGeolocation::GetCurrentPosition(nsIDOMGeoPositionCallback *callback, nsIDOMGeoPositionErrorCallback *errorCallback, mozilla::idl::GeoPositionOptions *options)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIGeolocation_h__ */

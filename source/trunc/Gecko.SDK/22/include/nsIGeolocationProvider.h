/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/system/nsIGeolocationProvider.idl
 */

#ifndef __gen_nsIGeolocationProvider_h__
#define __gen_nsIGeolocationProvider_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIDOMWindow; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIDOMGeoPosition; /* forward declaration */

class nsIGeolocationPrompt; /* forward declaration */


/* starting interface:    nsIGeolocationUpdate */
#define NS_IGEOLOCATIONUPDATE_IID_STR "b89d7227-9f04-4236-a582-25a3f2779d72"

#define NS_IGEOLOCATIONUPDATE_IID \
  {0xb89d7227, 0x9f04, 0x4236, \
    { 0xa5, 0x82, 0x25, 0xa3, 0xf2, 0x77, 0x9d, 0x72 }}

class NS_NO_VTABLE nsIGeolocationUpdate : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGEOLOCATIONUPDATE_IID)

  /* void update (in nsIDOMGeoPosition position); */
  NS_IMETHOD Update(nsIDOMGeoPosition *position) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGeolocationUpdate, NS_IGEOLOCATIONUPDATE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGEOLOCATIONUPDATE \
  NS_IMETHOD Update(nsIDOMGeoPosition *position); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGEOLOCATIONUPDATE(_to) \
  NS_IMETHOD Update(nsIDOMGeoPosition *position) { return _to Update(position); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGEOLOCATIONUPDATE(_to) \
  NS_IMETHOD Update(nsIDOMGeoPosition *position) { return !_to ? NS_ERROR_NULL_POINTER : _to->Update(position); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGeolocationUpdate : public nsIGeolocationUpdate
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGEOLOCATIONUPDATE

  nsGeolocationUpdate();

private:
  ~nsGeolocationUpdate();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsGeolocationUpdate, nsIGeolocationUpdate)

nsGeolocationUpdate::nsGeolocationUpdate()
{
  /* member initializers and constructor code */
}

nsGeolocationUpdate::~nsGeolocationUpdate()
{
  /* destructor code */
}

/* void update (in nsIDOMGeoPosition position); */
NS_IMETHODIMP nsGeolocationUpdate::Update(nsIDOMGeoPosition *position)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIGeolocationProvider */
#define NS_IGEOLOCATIONPROVIDER_IID_STR "d32b87b3-fe96-4f42-81ab-2f39f7ec43ff"

#define NS_IGEOLOCATIONPROVIDER_IID \
  {0xd32b87b3, 0xfe96, 0x4f42, \
    { 0x81, 0xab, 0x2f, 0x39, 0xf7, 0xec, 0x43, 0xff }}

class NS_NO_VTABLE nsIGeolocationProvider : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGEOLOCATIONPROVIDER_IID)

  /* void startup (); */
  NS_IMETHOD Startup(void) = 0;

  /* void watch (in nsIGeolocationUpdate callback, in boolean requestPrivate); */
  NS_IMETHOD Watch(nsIGeolocationUpdate *callback, bool requestPrivate) = 0;

  /* void shutdown (); */
  NS_IMETHOD Shutdown(void) = 0;

  /* void setHighAccuracy (in boolean enable); */
  NS_IMETHOD SetHighAccuracy(bool enable) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGeolocationProvider, NS_IGEOLOCATIONPROVIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGEOLOCATIONPROVIDER \
  NS_IMETHOD Startup(void); \
  NS_IMETHOD Watch(nsIGeolocationUpdate *callback, bool requestPrivate); \
  NS_IMETHOD Shutdown(void); \
  NS_IMETHOD SetHighAccuracy(bool enable); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGEOLOCATIONPROVIDER(_to) \
  NS_IMETHOD Startup(void) { return _to Startup(); } \
  NS_IMETHOD Watch(nsIGeolocationUpdate *callback, bool requestPrivate) { return _to Watch(callback, requestPrivate); } \
  NS_IMETHOD Shutdown(void) { return _to Shutdown(); } \
  NS_IMETHOD SetHighAccuracy(bool enable) { return _to SetHighAccuracy(enable); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGEOLOCATIONPROVIDER(_to) \
  NS_IMETHOD Startup(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Startup(); } \
  NS_IMETHOD Watch(nsIGeolocationUpdate *callback, bool requestPrivate) { return !_to ? NS_ERROR_NULL_POINTER : _to->Watch(callback, requestPrivate); } \
  NS_IMETHOD Shutdown(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Shutdown(); } \
  NS_IMETHOD SetHighAccuracy(bool enable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHighAccuracy(enable); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGeolocationProvider : public nsIGeolocationProvider
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGEOLOCATIONPROVIDER

  nsGeolocationProvider();

private:
  ~nsGeolocationProvider();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsGeolocationProvider, nsIGeolocationProvider)

nsGeolocationProvider::nsGeolocationProvider()
{
  /* member initializers and constructor code */
}

nsGeolocationProvider::~nsGeolocationProvider()
{
  /* destructor code */
}

/* void startup (); */
NS_IMETHODIMP nsGeolocationProvider::Startup()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void watch (in nsIGeolocationUpdate callback, in boolean requestPrivate); */
NS_IMETHODIMP nsGeolocationProvider::Watch(nsIGeolocationUpdate *callback, bool requestPrivate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void shutdown (); */
NS_IMETHODIMP nsGeolocationProvider::Shutdown()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setHighAccuracy (in boolean enable); */
NS_IMETHODIMP nsGeolocationProvider::SetHighAccuracy(bool enable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/*  
    This must be implemented by geolocation providers.  It
    must support nsIGeolocationProvider.
*/
#define NS_GEOLOCATION_PROVIDER_CONTRACTID "@mozilla.org/geolocation/provider;1"

#endif /* __gen_nsIGeolocationProvider_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIGeolocationProvider.idl
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
#define NS_IGEOLOCATIONUPDATE_IID_STR "643dc5e9-b911-4b2c-8d44-603162696baf"

#define NS_IGEOLOCATIONUPDATE_IID \
  {0x643dc5e9, 0xb911, 0x4b2c, \
    { 0x8d, 0x44, 0x60, 0x31, 0x62, 0x69, 0x6b, 0xaf }}

class NS_NO_VTABLE nsIGeolocationUpdate : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGEOLOCATIONUPDATE_IID)

  /* void update (in nsIDOMGeoPosition position); */
  NS_IMETHOD Update(nsIDOMGeoPosition *position) = 0;

  /* void locationUpdatePending (); */
  NS_IMETHOD LocationUpdatePending(void) = 0;

  /* void notifyError (in unsigned short error); */
  NS_IMETHOD NotifyError(uint16_t error) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGeolocationUpdate, NS_IGEOLOCATIONUPDATE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGEOLOCATIONUPDATE \
  NS_IMETHOD Update(nsIDOMGeoPosition *position); \
  NS_IMETHOD LocationUpdatePending(void); \
  NS_IMETHOD NotifyError(uint16_t error); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGEOLOCATIONUPDATE(_to) \
  NS_IMETHOD Update(nsIDOMGeoPosition *position) { return _to Update(position); } \
  NS_IMETHOD LocationUpdatePending(void) { return _to LocationUpdatePending(); } \
  NS_IMETHOD NotifyError(uint16_t error) { return _to NotifyError(error); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGEOLOCATIONUPDATE(_to) \
  NS_IMETHOD Update(nsIDOMGeoPosition *position) { return !_to ? NS_ERROR_NULL_POINTER : _to->Update(position); } \
  NS_IMETHOD LocationUpdatePending(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->LocationUpdatePending(); } \
  NS_IMETHOD NotifyError(uint16_t error) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyError(error); } 

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

/* void locationUpdatePending (); */
NS_IMETHODIMP nsGeolocationUpdate::LocationUpdatePending()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyError (in unsigned short error); */
NS_IMETHODIMP nsGeolocationUpdate::NotifyError(uint16_t error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIGeolocationProvider */
#define NS_IGEOLOCATIONPROVIDER_IID_STR "ac4a133b-9f92-4f7c-b369-d40cb6b17650"

#define NS_IGEOLOCATIONPROVIDER_IID \
  {0xac4a133b, 0x9f92, 0x4f7c, \
    { 0xb3, 0x69, 0xd4, 0x0c, 0xb6, 0xb1, 0x76, 0x50 }}

class NS_NO_VTABLE nsIGeolocationProvider : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGEOLOCATIONPROVIDER_IID)

  /* void startup (); */
  NS_IMETHOD Startup(void) = 0;

  /* void watch (in nsIGeolocationUpdate callback); */
  NS_IMETHOD Watch(nsIGeolocationUpdate *callback) = 0;

  /* void shutdown (); */
  NS_IMETHOD Shutdown(void) = 0;

  /* void setHighAccuracy (in boolean enable); */
  NS_IMETHOD SetHighAccuracy(bool enable) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGeolocationProvider, NS_IGEOLOCATIONPROVIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGEOLOCATIONPROVIDER \
  NS_IMETHOD Startup(void); \
  NS_IMETHOD Watch(nsIGeolocationUpdate *callback); \
  NS_IMETHOD Shutdown(void); \
  NS_IMETHOD SetHighAccuracy(bool enable); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGEOLOCATIONPROVIDER(_to) \
  NS_IMETHOD Startup(void) { return _to Startup(); } \
  NS_IMETHOD Watch(nsIGeolocationUpdate *callback) { return _to Watch(callback); } \
  NS_IMETHOD Shutdown(void) { return _to Shutdown(); } \
  NS_IMETHOD SetHighAccuracy(bool enable) { return _to SetHighAccuracy(enable); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGEOLOCATIONPROVIDER(_to) \
  NS_IMETHOD Startup(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Startup(); } \
  NS_IMETHOD Watch(nsIGeolocationUpdate *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->Watch(callback); } \
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

/* void watch (in nsIGeolocationUpdate callback); */
NS_IMETHODIMP nsGeolocationProvider::Watch(nsIGeolocationUpdate *callback)
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

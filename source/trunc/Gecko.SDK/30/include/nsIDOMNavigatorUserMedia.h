/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMNavigatorUserMedia.idl
 */

#ifndef __gen_nsIDOMNavigatorUserMedia_h__
#define __gen_nsIDOMNavigatorUserMedia_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIVariant_h__
#include "nsIVariant.h"
#endif

#ifndef __gen_nsIDOMMediaStream_h__
#include "nsIDOMMediaStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMediaDevice */
#define NS_IMEDIADEVICE_IID_STR "4af2bdb7-1547-4d10-8886-02a78c3c0b83"

#define NS_IMEDIADEVICE_IID \
  {0x4af2bdb7, 0x1547, 0x4d10, \
    { 0x88, 0x86, 0x02, 0xa7, 0x8c, 0x3c, 0x0b, 0x83 }}

class NS_NO_VTABLE nsIMediaDevice : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMEDIADEVICE_IID)

  /* readonly attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;

  /* readonly attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute DOMString id; */
  NS_IMETHOD GetId(nsAString & aId) = 0;

  /* readonly attribute DOMString facingMode; */
  NS_IMETHOD GetFacingMode(nsAString & aFacingMode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMediaDevice, NS_IMEDIADEVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMEDIADEVICE \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD GetId(nsAString & aId); \
  NS_IMETHOD GetFacingMode(nsAString & aFacingMode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMEDIADEVICE(_to) \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD GetId(nsAString & aId) { return _to GetId(aId); } \
  NS_IMETHOD GetFacingMode(nsAString & aFacingMode) { return _to GetFacingMode(aFacingMode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMEDIADEVICE(_to) \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetId(nsAString & aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_IMETHOD GetFacingMode(nsAString & aFacingMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFacingMode(aFacingMode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMediaDevice : public nsIMediaDevice
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMEDIADEVICE

  nsMediaDevice();

private:
  ~nsMediaDevice();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMediaDevice, nsIMediaDevice)

nsMediaDevice::nsMediaDevice()
{
  /* member initializers and constructor code */
}

nsMediaDevice::~nsMediaDevice()
{
  /* destructor code */
}

/* readonly attribute DOMString type; */
NS_IMETHODIMP nsMediaDevice::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString name; */
NS_IMETHODIMP nsMediaDevice::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString id; */
NS_IMETHODIMP nsMediaDevice::GetId(nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString facingMode; */
NS_IMETHODIMP nsMediaDevice::GetFacingMode(nsAString & aFacingMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIGetUserMediaDevicesSuccessCallback */
#define NS_IGETUSERMEDIADEVICESSUCCESSCALLBACK_IID_STR "24544878-d35e-4962-8c5f-fb84e97bdfee"

#define NS_IGETUSERMEDIADEVICESSUCCESSCALLBACK_IID \
  {0x24544878, 0xd35e, 0x4962, \
    { 0x8c, 0x5f, 0xfb, 0x84, 0xe9, 0x7b, 0xdf, 0xee }}

class NS_NO_VTABLE nsIGetUserMediaDevicesSuccessCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGETUSERMEDIADEVICESSUCCESSCALLBACK_IID)

  /* void onSuccess (in nsIVariant devices); */
  NS_IMETHOD OnSuccess(nsIVariant *devices) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGetUserMediaDevicesSuccessCallback, NS_IGETUSERMEDIADEVICESSUCCESSCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGETUSERMEDIADEVICESSUCCESSCALLBACK \
  NS_IMETHOD OnSuccess(nsIVariant *devices); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGETUSERMEDIADEVICESSUCCESSCALLBACK(_to) \
  NS_IMETHOD OnSuccess(nsIVariant *devices) { return _to OnSuccess(devices); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGETUSERMEDIADEVICESSUCCESSCALLBACK(_to) \
  NS_IMETHOD OnSuccess(nsIVariant *devices) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSuccess(devices); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGetUserMediaDevicesSuccessCallback : public nsIGetUserMediaDevicesSuccessCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGETUSERMEDIADEVICESSUCCESSCALLBACK

  nsGetUserMediaDevicesSuccessCallback();

private:
  ~nsGetUserMediaDevicesSuccessCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsGetUserMediaDevicesSuccessCallback, nsIGetUserMediaDevicesSuccessCallback)

nsGetUserMediaDevicesSuccessCallback::nsGetUserMediaDevicesSuccessCallback()
{
  /* member initializers and constructor code */
}

nsGetUserMediaDevicesSuccessCallback::~nsGetUserMediaDevicesSuccessCallback()
{
  /* destructor code */
}

/* void onSuccess (in nsIVariant devices); */
NS_IMETHODIMP nsGetUserMediaDevicesSuccessCallback::OnSuccess(nsIVariant *devices)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMGetUserMediaSuccessCallback */
#define NS_IDOMGETUSERMEDIASUCCESSCALLBACK_IID_STR "f2a144fc-3534-4761-8c5d-989ae720f89a"

#define NS_IDOMGETUSERMEDIASUCCESSCALLBACK_IID \
  {0xf2a144fc, 0x3534, 0x4761, \
    { 0x8c, 0x5d, 0x98, 0x9a, 0xe7, 0x20, 0xf8, 0x9a }}

class NS_NO_VTABLE nsIDOMGetUserMediaSuccessCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGETUSERMEDIASUCCESSCALLBACK_IID)

  /* void onSuccess (in nsISupports value); */
  NS_IMETHOD OnSuccess(nsISupports *value) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGetUserMediaSuccessCallback, NS_IDOMGETUSERMEDIASUCCESSCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGETUSERMEDIASUCCESSCALLBACK \
  NS_IMETHOD OnSuccess(nsISupports *value); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGETUSERMEDIASUCCESSCALLBACK(_to) \
  NS_IMETHOD OnSuccess(nsISupports *value) { return _to OnSuccess(value); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGETUSERMEDIASUCCESSCALLBACK(_to) \
  NS_IMETHOD OnSuccess(nsISupports *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSuccess(value); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGetUserMediaSuccessCallback : public nsIDOMGetUserMediaSuccessCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGETUSERMEDIASUCCESSCALLBACK

  nsDOMGetUserMediaSuccessCallback();

private:
  ~nsDOMGetUserMediaSuccessCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMGetUserMediaSuccessCallback, nsIDOMGetUserMediaSuccessCallback)

nsDOMGetUserMediaSuccessCallback::nsDOMGetUserMediaSuccessCallback()
{
  /* member initializers and constructor code */
}

nsDOMGetUserMediaSuccessCallback::~nsDOMGetUserMediaSuccessCallback()
{
  /* destructor code */
}

/* void onSuccess (in nsISupports value); */
NS_IMETHODIMP nsDOMGetUserMediaSuccessCallback::OnSuccess(nsISupports *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMGetUserMediaErrorCallback */
#define NS_IDOMGETUSERMEDIAERRORCALLBACK_IID_STR "2614bbcf-85cc-43e5-8740-964f52bdc7ca"

#define NS_IDOMGETUSERMEDIAERRORCALLBACK_IID \
  {0x2614bbcf, 0x85cc, 0x43e5, \
    { 0x87, 0x40, 0x96, 0x4f, 0x52, 0xbd, 0xc7, 0xca }}

class NS_NO_VTABLE nsIDOMGetUserMediaErrorCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGETUSERMEDIAERRORCALLBACK_IID)

  /* void onError (in DOMString error); */
  NS_IMETHOD OnError(const nsAString & error) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGetUserMediaErrorCallback, NS_IDOMGETUSERMEDIAERRORCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGETUSERMEDIAERRORCALLBACK \
  NS_IMETHOD OnError(const nsAString & error); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGETUSERMEDIAERRORCALLBACK(_to) \
  NS_IMETHOD OnError(const nsAString & error) { return _to OnError(error); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGETUSERMEDIAERRORCALLBACK(_to) \
  NS_IMETHOD OnError(const nsAString & error) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnError(error); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGetUserMediaErrorCallback : public nsIDOMGetUserMediaErrorCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGETUSERMEDIAERRORCALLBACK

  nsDOMGetUserMediaErrorCallback();

private:
  ~nsDOMGetUserMediaErrorCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMGetUserMediaErrorCallback, nsIDOMGetUserMediaErrorCallback)

nsDOMGetUserMediaErrorCallback::nsDOMGetUserMediaErrorCallback()
{
  /* member initializers and constructor code */
}

nsDOMGetUserMediaErrorCallback::~nsDOMGetUserMediaErrorCallback()
{
  /* destructor code */
}

/* void onError (in DOMString error); */
NS_IMETHODIMP nsDOMGetUserMediaErrorCallback::OnError(const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNavigatorUserMedia_h__ */

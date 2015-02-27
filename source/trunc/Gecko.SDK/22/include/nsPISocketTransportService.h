/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsPISocketTransportService.idl
 */

#ifndef __gen_nsPISocketTransportService_h__
#define __gen_nsPISocketTransportService_h__


#ifndef __gen_nsISocketTransportService_h__
#include "nsISocketTransportService.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsPISocketTransportService */
#define NS_PISOCKETTRANSPORTSERVICE_IID_STR "32de7b6e-90c3-11e1-b57e-001fbc092072"

#define NS_PISOCKETTRANSPORTSERVICE_IID \
  {0x32de7b6e, 0x90c3, 0x11e1, \
    { 0xb5, 0x7e, 0x00, 0x1f, 0xbc, 0x09, 0x20, 0x72 }}

class NS_NO_VTABLE nsPISocketTransportService : public nsISocketTransportService {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PISOCKETTRANSPORTSERVICE_IID)

  /* void init (); */
  NS_IMETHOD Init(void) = 0;

  /* void shutdown (); */
  NS_IMETHOD Shutdown(void) = 0;

  /* attribute boolean autodialEnabled; */
  NS_IMETHOD GetAutodialEnabled(bool *aAutodialEnabled) = 0;
  NS_IMETHOD SetAutodialEnabled(bool aAutodialEnabled) = 0;

  /* readonly attribute long sendBufferSize; */
  NS_IMETHOD GetSendBufferSize(int32_t *aSendBufferSize) = 0;

  /* attribute boolean offline; */
  NS_IMETHOD GetOffline(bool *aOffline) = 0;
  NS_IMETHOD SetOffline(bool aOffline) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPISocketTransportService, NS_PISOCKETTRANSPORTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPISOCKETTRANSPORTSERVICE \
  NS_IMETHOD Init(void); \
  NS_IMETHOD Shutdown(void); \
  NS_IMETHOD GetAutodialEnabled(bool *aAutodialEnabled); \
  NS_IMETHOD SetAutodialEnabled(bool aAutodialEnabled); \
  NS_IMETHOD GetSendBufferSize(int32_t *aSendBufferSize); \
  NS_IMETHOD GetOffline(bool *aOffline); \
  NS_IMETHOD SetOffline(bool aOffline); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPISOCKETTRANSPORTSERVICE(_to) \
  NS_IMETHOD Init(void) { return _to Init(); } \
  NS_IMETHOD Shutdown(void) { return _to Shutdown(); } \
  NS_IMETHOD GetAutodialEnabled(bool *aAutodialEnabled) { return _to GetAutodialEnabled(aAutodialEnabled); } \
  NS_IMETHOD SetAutodialEnabled(bool aAutodialEnabled) { return _to SetAutodialEnabled(aAutodialEnabled); } \
  NS_IMETHOD GetSendBufferSize(int32_t *aSendBufferSize) { return _to GetSendBufferSize(aSendBufferSize); } \
  NS_IMETHOD GetOffline(bool *aOffline) { return _to GetOffline(aOffline); } \
  NS_IMETHOD SetOffline(bool aOffline) { return _to SetOffline(aOffline); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPISOCKETTRANSPORTSERVICE(_to) \
  NS_IMETHOD Init(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(); } \
  NS_IMETHOD Shutdown(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Shutdown(); } \
  NS_IMETHOD GetAutodialEnabled(bool *aAutodialEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAutodialEnabled(aAutodialEnabled); } \
  NS_IMETHOD SetAutodialEnabled(bool aAutodialEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAutodialEnabled(aAutodialEnabled); } \
  NS_IMETHOD GetSendBufferSize(int32_t *aSendBufferSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSendBufferSize(aSendBufferSize); } \
  NS_IMETHOD GetOffline(bool *aOffline) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffline(aOffline); } \
  NS_IMETHOD SetOffline(bool aOffline) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOffline(aOffline); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPISocketTransportService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPISOCKETTRANSPORTSERVICE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, nsPISocketTransportService)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void init (); */
NS_IMETHODIMP _MYCLASS_::Init()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void shutdown (); */
NS_IMETHODIMP _MYCLASS_::Shutdown()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean autodialEnabled; */
NS_IMETHODIMP _MYCLASS_::GetAutodialEnabled(bool *aAutodialEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetAutodialEnabled(bool aAutodialEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long sendBufferSize; */
NS_IMETHODIMP _MYCLASS_::GetSendBufferSize(int32_t *aSendBufferSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean offline; */
NS_IMETHODIMP _MYCLASS_::GetOffline(bool *aOffline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetOffline(bool aOffline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/*
 * Network activity indicator: we send out these topics no more than every
 * blipIntervalMilliseconds (as set by the
 * "network.activity.blipIntervalMilliseconds" preference: if 0 no notifications
 * are sent) if the network is currently active (i.e. we're sending/receiving
 * data to/from the socket).
 */
#define NS_NETWORK_ACTIVITY_BLIP_UPLOAD_TOPIC   "network-activity-blip-upload"
#define NS_NETWORK_ACTIVITY_BLIP_DOWNLOAD_TOPIC "network-activity-blip-download"

#endif /* __gen_nsPISocketTransportService_h__ */

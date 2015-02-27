/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsPISocketTransportService.idl
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
#define NS_PISOCKETTRANSPORTSERVICE_IID_STR "bc5869e7-53a6-4195-8ab8-32e7116b87dd"

#define NS_PISOCKETTRANSPORTSERVICE_IID \
  {0xbc5869e7, 0x53a6, 0x4195, \
    { 0x8a, 0xb8, 0x32, 0xe7, 0x11, 0x6b, 0x87, 0xdd }}

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

  /* readonly attribute long keepaliveIdleTime; */
  NS_IMETHOD GetKeepaliveIdleTime(int32_t *aKeepaliveIdleTime) = 0;

  /* readonly attribute long keepaliveRetryInterval; */
  NS_IMETHOD GetKeepaliveRetryInterval(int32_t *aKeepaliveRetryInterval) = 0;

  /* readonly attribute long keepaliveProbeCount; */
  NS_IMETHOD GetKeepaliveProbeCount(int32_t *aKeepaliveProbeCount) = 0;

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
  NS_IMETHOD SetOffline(bool aOffline); \
  NS_IMETHOD GetKeepaliveIdleTime(int32_t *aKeepaliveIdleTime); \
  NS_IMETHOD GetKeepaliveRetryInterval(int32_t *aKeepaliveRetryInterval); \
  NS_IMETHOD GetKeepaliveProbeCount(int32_t *aKeepaliveProbeCount); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPISOCKETTRANSPORTSERVICE(_to) \
  NS_IMETHOD Init(void) { return _to Init(); } \
  NS_IMETHOD Shutdown(void) { return _to Shutdown(); } \
  NS_IMETHOD GetAutodialEnabled(bool *aAutodialEnabled) { return _to GetAutodialEnabled(aAutodialEnabled); } \
  NS_IMETHOD SetAutodialEnabled(bool aAutodialEnabled) { return _to SetAutodialEnabled(aAutodialEnabled); } \
  NS_IMETHOD GetSendBufferSize(int32_t *aSendBufferSize) { return _to GetSendBufferSize(aSendBufferSize); } \
  NS_IMETHOD GetOffline(bool *aOffline) { return _to GetOffline(aOffline); } \
  NS_IMETHOD SetOffline(bool aOffline) { return _to SetOffline(aOffline); } \
  NS_IMETHOD GetKeepaliveIdleTime(int32_t *aKeepaliveIdleTime) { return _to GetKeepaliveIdleTime(aKeepaliveIdleTime); } \
  NS_IMETHOD GetKeepaliveRetryInterval(int32_t *aKeepaliveRetryInterval) { return _to GetKeepaliveRetryInterval(aKeepaliveRetryInterval); } \
  NS_IMETHOD GetKeepaliveProbeCount(int32_t *aKeepaliveProbeCount) { return _to GetKeepaliveProbeCount(aKeepaliveProbeCount); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPISOCKETTRANSPORTSERVICE(_to) \
  NS_IMETHOD Init(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(); } \
  NS_IMETHOD Shutdown(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Shutdown(); } \
  NS_IMETHOD GetAutodialEnabled(bool *aAutodialEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAutodialEnabled(aAutodialEnabled); } \
  NS_IMETHOD SetAutodialEnabled(bool aAutodialEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAutodialEnabled(aAutodialEnabled); } \
  NS_IMETHOD GetSendBufferSize(int32_t *aSendBufferSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSendBufferSize(aSendBufferSize); } \
  NS_IMETHOD GetOffline(bool *aOffline) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffline(aOffline); } \
  NS_IMETHOD SetOffline(bool aOffline) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOffline(aOffline); } \
  NS_IMETHOD GetKeepaliveIdleTime(int32_t *aKeepaliveIdleTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeepaliveIdleTime(aKeepaliveIdleTime); } \
  NS_IMETHOD GetKeepaliveRetryInterval(int32_t *aKeepaliveRetryInterval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeepaliveRetryInterval(aKeepaliveRetryInterval); } \
  NS_IMETHOD GetKeepaliveProbeCount(int32_t *aKeepaliveProbeCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeepaliveProbeCount(aKeepaliveProbeCount); } 

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

/* readonly attribute long keepaliveIdleTime; */
NS_IMETHODIMP _MYCLASS_::GetKeepaliveIdleTime(int32_t *aKeepaliveIdleTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long keepaliveRetryInterval; */
NS_IMETHODIMP _MYCLASS_::GetKeepaliveRetryInterval(int32_t *aKeepaliveRetryInterval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long keepaliveProbeCount; */
NS_IMETHODIMP _MYCLASS_::GetKeepaliveProbeCount(int32_t *aKeepaliveProbeCount)
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

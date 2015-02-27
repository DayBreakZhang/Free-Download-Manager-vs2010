/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsILoadGroup.idl
 */

#ifndef __gen_nsILoadGroup_h__
#define __gen_nsILoadGroup_h__


#ifndef __gen_nsIRequest_h__
#include "nsIRequest.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISimpleEnumerator; /* forward declaration */

class nsIRequestObserver; /* forward declaration */

class nsIInterfaceRequestor; /* forward declaration */

class nsILoadGroupConnectionInfo; /* forward declaration */

typedef uint32_t  nsLoadFlags;


/* starting interface:    nsILoadGroup */
#define NS_ILOADGROUP_IID_STR "afb57ac2-bce5-4ee3-bb34-385089a9ba5c"

#define NS_ILOADGROUP_IID \
  {0xafb57ac2, 0xbce5, 0x4ee3, \
    { 0xbb, 0x34, 0x38, 0x50, 0x89, 0xa9, 0xba, 0x5c }}

class NS_NO_VTABLE nsILoadGroup : public nsIRequest {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOADGROUP_IID)

  /* attribute nsIRequestObserver groupObserver; */
  NS_IMETHOD GetGroupObserver(nsIRequestObserver * *aGroupObserver) = 0;
  NS_IMETHOD SetGroupObserver(nsIRequestObserver *aGroupObserver) = 0;

  /* attribute nsIRequest defaultLoadRequest; */
  NS_IMETHOD GetDefaultLoadRequest(nsIRequest * *aDefaultLoadRequest) = 0;
  NS_IMETHOD SetDefaultLoadRequest(nsIRequest *aDefaultLoadRequest) = 0;

  /* void addRequest (in nsIRequest aRequest, in nsISupports aContext); */
  NS_IMETHOD AddRequest(nsIRequest *aRequest, nsISupports *aContext) = 0;

  /* void removeRequest (in nsIRequest aRequest, in nsISupports aContext, in nsresult aStatus); */
  NS_IMETHOD RemoveRequest(nsIRequest *aRequest, nsISupports *aContext, nsresult aStatus) = 0;

  /* readonly attribute nsISimpleEnumerator requests; */
  NS_IMETHOD GetRequests(nsISimpleEnumerator * *aRequests) = 0;

  /* readonly attribute unsigned long activeCount; */
  NS_IMETHOD GetActiveCount(uint32_t *aActiveCount) = 0;

  /* attribute nsIInterfaceRequestor notificationCallbacks; */
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks) = 0;
  NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks) = 0;

  /* readonly attribute nsILoadGroupConnectionInfo connectionInfo; */
  NS_IMETHOD GetConnectionInfo(nsILoadGroupConnectionInfo * *aConnectionInfo) = 0;

  /* attribute nsLoadFlags defaultLoadFlags; */
  NS_IMETHOD GetDefaultLoadFlags(nsLoadFlags *aDefaultLoadFlags) = 0;
  NS_IMETHOD SetDefaultLoadFlags(nsLoadFlags aDefaultLoadFlags) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILoadGroup, NS_ILOADGROUP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOADGROUP \
  NS_IMETHOD GetGroupObserver(nsIRequestObserver * *aGroupObserver); \
  NS_IMETHOD SetGroupObserver(nsIRequestObserver *aGroupObserver); \
  NS_IMETHOD GetDefaultLoadRequest(nsIRequest * *aDefaultLoadRequest); \
  NS_IMETHOD SetDefaultLoadRequest(nsIRequest *aDefaultLoadRequest); \
  NS_IMETHOD AddRequest(nsIRequest *aRequest, nsISupports *aContext); \
  NS_IMETHOD RemoveRequest(nsIRequest *aRequest, nsISupports *aContext, nsresult aStatus); \
  NS_IMETHOD GetRequests(nsISimpleEnumerator * *aRequests); \
  NS_IMETHOD GetActiveCount(uint32_t *aActiveCount); \
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks); \
  NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks); \
  NS_IMETHOD GetConnectionInfo(nsILoadGroupConnectionInfo * *aConnectionInfo); \
  NS_IMETHOD GetDefaultLoadFlags(nsLoadFlags *aDefaultLoadFlags); \
  NS_IMETHOD SetDefaultLoadFlags(nsLoadFlags aDefaultLoadFlags); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOADGROUP(_to) \
  NS_IMETHOD GetGroupObserver(nsIRequestObserver * *aGroupObserver) { return _to GetGroupObserver(aGroupObserver); } \
  NS_IMETHOD SetGroupObserver(nsIRequestObserver *aGroupObserver) { return _to SetGroupObserver(aGroupObserver); } \
  NS_IMETHOD GetDefaultLoadRequest(nsIRequest * *aDefaultLoadRequest) { return _to GetDefaultLoadRequest(aDefaultLoadRequest); } \
  NS_IMETHOD SetDefaultLoadRequest(nsIRequest *aDefaultLoadRequest) { return _to SetDefaultLoadRequest(aDefaultLoadRequest); } \
  NS_IMETHOD AddRequest(nsIRequest *aRequest, nsISupports *aContext) { return _to AddRequest(aRequest, aContext); } \
  NS_IMETHOD RemoveRequest(nsIRequest *aRequest, nsISupports *aContext, nsresult aStatus) { return _to RemoveRequest(aRequest, aContext, aStatus); } \
  NS_IMETHOD GetRequests(nsISimpleEnumerator * *aRequests) { return _to GetRequests(aRequests); } \
  NS_IMETHOD GetActiveCount(uint32_t *aActiveCount) { return _to GetActiveCount(aActiveCount); } \
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks) { return _to GetNotificationCallbacks(aNotificationCallbacks); } \
  NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks) { return _to SetNotificationCallbacks(aNotificationCallbacks); } \
  NS_IMETHOD GetConnectionInfo(nsILoadGroupConnectionInfo * *aConnectionInfo) { return _to GetConnectionInfo(aConnectionInfo); } \
  NS_IMETHOD GetDefaultLoadFlags(nsLoadFlags *aDefaultLoadFlags) { return _to GetDefaultLoadFlags(aDefaultLoadFlags); } \
  NS_IMETHOD SetDefaultLoadFlags(nsLoadFlags aDefaultLoadFlags) { return _to SetDefaultLoadFlags(aDefaultLoadFlags); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOADGROUP(_to) \
  NS_IMETHOD GetGroupObserver(nsIRequestObserver * *aGroupObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGroupObserver(aGroupObserver); } \
  NS_IMETHOD SetGroupObserver(nsIRequestObserver *aGroupObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetGroupObserver(aGroupObserver); } \
  NS_IMETHOD GetDefaultLoadRequest(nsIRequest * *aDefaultLoadRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultLoadRequest(aDefaultLoadRequest); } \
  NS_IMETHOD SetDefaultLoadRequest(nsIRequest *aDefaultLoadRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultLoadRequest(aDefaultLoadRequest); } \
  NS_IMETHOD AddRequest(nsIRequest *aRequest, nsISupports *aContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddRequest(aRequest, aContext); } \
  NS_IMETHOD RemoveRequest(nsIRequest *aRequest, nsISupports *aContext, nsresult aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveRequest(aRequest, aContext, aStatus); } \
  NS_IMETHOD GetRequests(nsISimpleEnumerator * *aRequests) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequests(aRequests); } \
  NS_IMETHOD GetActiveCount(uint32_t *aActiveCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActiveCount(aActiveCount); } \
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNotificationCallbacks(aNotificationCallbacks); } \
  NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNotificationCallbacks(aNotificationCallbacks); } \
  NS_IMETHOD GetConnectionInfo(nsILoadGroupConnectionInfo * *aConnectionInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConnectionInfo(aConnectionInfo); } \
  NS_IMETHOD GetDefaultLoadFlags(nsLoadFlags *aDefaultLoadFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultLoadFlags(aDefaultLoadFlags); } \
  NS_IMETHOD SetDefaultLoadFlags(nsLoadFlags aDefaultLoadFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultLoadFlags(aDefaultLoadFlags); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLoadGroup : public nsILoadGroup
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOADGROUP

  nsLoadGroup();

private:
  ~nsLoadGroup();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLoadGroup, nsILoadGroup)

nsLoadGroup::nsLoadGroup()
{
  /* member initializers and constructor code */
}

nsLoadGroup::~nsLoadGroup()
{
  /* destructor code */
}

/* attribute nsIRequestObserver groupObserver; */
NS_IMETHODIMP nsLoadGroup::GetGroupObserver(nsIRequestObserver * *aGroupObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoadGroup::SetGroupObserver(nsIRequestObserver *aGroupObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIRequest defaultLoadRequest; */
NS_IMETHODIMP nsLoadGroup::GetDefaultLoadRequest(nsIRequest * *aDefaultLoadRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoadGroup::SetDefaultLoadRequest(nsIRequest *aDefaultLoadRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addRequest (in nsIRequest aRequest, in nsISupports aContext); */
NS_IMETHODIMP nsLoadGroup::AddRequest(nsIRequest *aRequest, nsISupports *aContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeRequest (in nsIRequest aRequest, in nsISupports aContext, in nsresult aStatus); */
NS_IMETHODIMP nsLoadGroup::RemoveRequest(nsIRequest *aRequest, nsISupports *aContext, nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISimpleEnumerator requests; */
NS_IMETHODIMP nsLoadGroup::GetRequests(nsISimpleEnumerator * *aRequests)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long activeCount; */
NS_IMETHODIMP nsLoadGroup::GetActiveCount(uint32_t *aActiveCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIInterfaceRequestor notificationCallbacks; */
NS_IMETHODIMP nsLoadGroup::GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoadGroup::SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsILoadGroupConnectionInfo connectionInfo; */
NS_IMETHODIMP nsLoadGroup::GetConnectionInfo(nsILoadGroupConnectionInfo * *aConnectionInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsLoadFlags defaultLoadFlags; */
NS_IMETHODIMP nsLoadGroup::GetDefaultLoadFlags(nsLoadFlags *aDefaultLoadFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoadGroup::SetDefaultLoadFlags(nsLoadFlags aDefaultLoadFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// Forward-declare mozilla::net::SpdyPushCache
namespace mozilla {
namespace net {
class SpdyPushCache;
}
}

/* starting interface:    nsILoadGroupConnectionInfo */
#define NS_ILOADGROUPCONNECTIONINFO_IID_STR "fdc9659c-b597-4ac0-9c9e-14b04dbb682f"

#define NS_ILOADGROUPCONNECTIONINFO_IID \
  {0xfdc9659c, 0xb597, 0x4ac0, \
    { 0x9c, 0x9e, 0x14, 0xb0, 0x4d, 0xbb, 0x68, 0x2f }}

class NS_NO_VTABLE nsILoadGroupConnectionInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOADGROUPCONNECTIONINFO_IID)

  /* readonly attribute unsigned long blockingTransactionCount; */
  NS_IMETHOD GetBlockingTransactionCount(uint32_t *aBlockingTransactionCount) = 0;

  /* void addBlockingTransaction (); */
  NS_IMETHOD AddBlockingTransaction(void) = 0;

  /* unsigned long removeBlockingTransaction (); */
  NS_IMETHOD RemoveBlockingTransaction(uint32_t *_retval) = 0;

  /* [noscript] attribute SpdyPushCachePtr spdyPushCache; */
  NS_IMETHOD GetSpdyPushCache(mozilla::net::SpdyPushCache **aSpdyPushCache) = 0;
  NS_IMETHOD SetSpdyPushCache(mozilla::net::SpdyPushCache *aSpdyPushCache) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILoadGroupConnectionInfo, NS_ILOADGROUPCONNECTIONINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOADGROUPCONNECTIONINFO \
  NS_IMETHOD GetBlockingTransactionCount(uint32_t *aBlockingTransactionCount); \
  NS_IMETHOD AddBlockingTransaction(void); \
  NS_IMETHOD RemoveBlockingTransaction(uint32_t *_retval); \
  NS_IMETHOD GetSpdyPushCache(mozilla::net::SpdyPushCache **aSpdyPushCache); \
  NS_IMETHOD SetSpdyPushCache(mozilla::net::SpdyPushCache *aSpdyPushCache); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOADGROUPCONNECTIONINFO(_to) \
  NS_IMETHOD GetBlockingTransactionCount(uint32_t *aBlockingTransactionCount) { return _to GetBlockingTransactionCount(aBlockingTransactionCount); } \
  NS_IMETHOD AddBlockingTransaction(void) { return _to AddBlockingTransaction(); } \
  NS_IMETHOD RemoveBlockingTransaction(uint32_t *_retval) { return _to RemoveBlockingTransaction(_retval); } \
  NS_IMETHOD GetSpdyPushCache(mozilla::net::SpdyPushCache **aSpdyPushCache) { return _to GetSpdyPushCache(aSpdyPushCache); } \
  NS_IMETHOD SetSpdyPushCache(mozilla::net::SpdyPushCache *aSpdyPushCache) { return _to SetSpdyPushCache(aSpdyPushCache); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOADGROUPCONNECTIONINFO(_to) \
  NS_IMETHOD GetBlockingTransactionCount(uint32_t *aBlockingTransactionCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBlockingTransactionCount(aBlockingTransactionCount); } \
  NS_IMETHOD AddBlockingTransaction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddBlockingTransaction(); } \
  NS_IMETHOD RemoveBlockingTransaction(uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveBlockingTransaction(_retval); } \
  NS_IMETHOD GetSpdyPushCache(mozilla::net::SpdyPushCache **aSpdyPushCache) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSpdyPushCache(aSpdyPushCache); } \
  NS_IMETHOD SetSpdyPushCache(mozilla::net::SpdyPushCache *aSpdyPushCache) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSpdyPushCache(aSpdyPushCache); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLoadGroupConnectionInfo : public nsILoadGroupConnectionInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOADGROUPCONNECTIONINFO

  nsLoadGroupConnectionInfo();

private:
  ~nsLoadGroupConnectionInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLoadGroupConnectionInfo, nsILoadGroupConnectionInfo)

nsLoadGroupConnectionInfo::nsLoadGroupConnectionInfo()
{
  /* member initializers and constructor code */
}

nsLoadGroupConnectionInfo::~nsLoadGroupConnectionInfo()
{
  /* destructor code */
}

/* readonly attribute unsigned long blockingTransactionCount; */
NS_IMETHODIMP nsLoadGroupConnectionInfo::GetBlockingTransactionCount(uint32_t *aBlockingTransactionCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addBlockingTransaction (); */
NS_IMETHODIMP nsLoadGroupConnectionInfo::AddBlockingTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long removeBlockingTransaction (); */
NS_IMETHODIMP nsLoadGroupConnectionInfo::RemoveBlockingTransaction(uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute SpdyPushCachePtr spdyPushCache; */
NS_IMETHODIMP nsLoadGroupConnectionInfo::GetSpdyPushCache(mozilla::net::SpdyPushCache **aSpdyPushCache)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoadGroupConnectionInfo::SetSpdyPushCache(mozilla::net::SpdyPushCache *aSpdyPushCache)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsILoadGroup_h__ */

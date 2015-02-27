/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIApplicationCacheChannel.idl
 */

#ifndef __gen_nsIApplicationCacheChannel_h__
#define __gen_nsIApplicationCacheChannel_h__


#ifndef __gen_nsIApplicationCacheContainer_h__
#include "nsIApplicationCacheContainer.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIApplicationCacheChannel */
#define NS_IAPPLICATIONCACHECHANNEL_IID_STR "6fa816b1-6d5f-4380-9704-054d0908cfa3"

#define NS_IAPPLICATIONCACHECHANNEL_IID \
  {0x6fa816b1, 0x6d5f, 0x4380, \
    { 0x97, 0x04, 0x05, 0x4d, 0x09, 0x08, 0xcf, 0xa3 }}

class NS_NO_VTABLE nsIApplicationCacheChannel : public nsIApplicationCacheContainer {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPLICATIONCACHECHANNEL_IID)

  /* readonly attribute boolean loadedFromApplicationCache; */
  NS_IMETHOD GetLoadedFromApplicationCache(bool *aLoadedFromApplicationCache) = 0;

  /* attribute boolean inheritApplicationCache; */
  NS_IMETHOD GetInheritApplicationCache(bool *aInheritApplicationCache) = 0;
  NS_IMETHOD SetInheritApplicationCache(bool aInheritApplicationCache) = 0;

  /* attribute boolean chooseApplicationCache; */
  NS_IMETHOD GetChooseApplicationCache(bool *aChooseApplicationCache) = 0;
  NS_IMETHOD SetChooseApplicationCache(bool aChooseApplicationCache) = 0;

  /* void markOfflineCacheEntryAsForeign (); */
  NS_IMETHOD MarkOfflineCacheEntryAsForeign(void) = 0;

  /* attribute nsIApplicationCache applicationCacheForWrite; */
  NS_IMETHOD GetApplicationCacheForWrite(nsIApplicationCache * *aApplicationCacheForWrite) = 0;
  NS_IMETHOD SetApplicationCacheForWrite(nsIApplicationCache *aApplicationCacheForWrite) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIApplicationCacheChannel, NS_IAPPLICATIONCACHECHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPLICATIONCACHECHANNEL \
  NS_IMETHOD GetLoadedFromApplicationCache(bool *aLoadedFromApplicationCache); \
  NS_IMETHOD GetInheritApplicationCache(bool *aInheritApplicationCache); \
  NS_IMETHOD SetInheritApplicationCache(bool aInheritApplicationCache); \
  NS_IMETHOD GetChooseApplicationCache(bool *aChooseApplicationCache); \
  NS_IMETHOD SetChooseApplicationCache(bool aChooseApplicationCache); \
  NS_IMETHOD MarkOfflineCacheEntryAsForeign(void); \
  NS_IMETHOD GetApplicationCacheForWrite(nsIApplicationCache * *aApplicationCacheForWrite); \
  NS_IMETHOD SetApplicationCacheForWrite(nsIApplicationCache *aApplicationCacheForWrite); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPLICATIONCACHECHANNEL(_to) \
  NS_IMETHOD GetLoadedFromApplicationCache(bool *aLoadedFromApplicationCache) { return _to GetLoadedFromApplicationCache(aLoadedFromApplicationCache); } \
  NS_IMETHOD GetInheritApplicationCache(bool *aInheritApplicationCache) { return _to GetInheritApplicationCache(aInheritApplicationCache); } \
  NS_IMETHOD SetInheritApplicationCache(bool aInheritApplicationCache) { return _to SetInheritApplicationCache(aInheritApplicationCache); } \
  NS_IMETHOD GetChooseApplicationCache(bool *aChooseApplicationCache) { return _to GetChooseApplicationCache(aChooseApplicationCache); } \
  NS_IMETHOD SetChooseApplicationCache(bool aChooseApplicationCache) { return _to SetChooseApplicationCache(aChooseApplicationCache); } \
  NS_IMETHOD MarkOfflineCacheEntryAsForeign(void) { return _to MarkOfflineCacheEntryAsForeign(); } \
  NS_IMETHOD GetApplicationCacheForWrite(nsIApplicationCache * *aApplicationCacheForWrite) { return _to GetApplicationCacheForWrite(aApplicationCacheForWrite); } \
  NS_IMETHOD SetApplicationCacheForWrite(nsIApplicationCache *aApplicationCacheForWrite) { return _to SetApplicationCacheForWrite(aApplicationCacheForWrite); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPLICATIONCACHECHANNEL(_to) \
  NS_IMETHOD GetLoadedFromApplicationCache(bool *aLoadedFromApplicationCache) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadedFromApplicationCache(aLoadedFromApplicationCache); } \
  NS_IMETHOD GetInheritApplicationCache(bool *aInheritApplicationCache) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInheritApplicationCache(aInheritApplicationCache); } \
  NS_IMETHOD SetInheritApplicationCache(bool aInheritApplicationCache) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInheritApplicationCache(aInheritApplicationCache); } \
  NS_IMETHOD GetChooseApplicationCache(bool *aChooseApplicationCache) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChooseApplicationCache(aChooseApplicationCache); } \
  NS_IMETHOD SetChooseApplicationCache(bool aChooseApplicationCache) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChooseApplicationCache(aChooseApplicationCache); } \
  NS_IMETHOD MarkOfflineCacheEntryAsForeign(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkOfflineCacheEntryAsForeign(); } \
  NS_IMETHOD GetApplicationCacheForWrite(nsIApplicationCache * *aApplicationCacheForWrite) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApplicationCacheForWrite(aApplicationCacheForWrite); } \
  NS_IMETHOD SetApplicationCacheForWrite(nsIApplicationCache *aApplicationCacheForWrite) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetApplicationCacheForWrite(aApplicationCacheForWrite); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsApplicationCacheChannel : public nsIApplicationCacheChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPLICATIONCACHECHANNEL

  nsApplicationCacheChannel();

private:
  ~nsApplicationCacheChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsApplicationCacheChannel, nsIApplicationCacheChannel)

nsApplicationCacheChannel::nsApplicationCacheChannel()
{
  /* member initializers and constructor code */
}

nsApplicationCacheChannel::~nsApplicationCacheChannel()
{
  /* destructor code */
}

/* readonly attribute boolean loadedFromApplicationCache; */
NS_IMETHODIMP nsApplicationCacheChannel::GetLoadedFromApplicationCache(bool *aLoadedFromApplicationCache)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean inheritApplicationCache; */
NS_IMETHODIMP nsApplicationCacheChannel::GetInheritApplicationCache(bool *aInheritApplicationCache)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsApplicationCacheChannel::SetInheritApplicationCache(bool aInheritApplicationCache)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean chooseApplicationCache; */
NS_IMETHODIMP nsApplicationCacheChannel::GetChooseApplicationCache(bool *aChooseApplicationCache)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsApplicationCacheChannel::SetChooseApplicationCache(bool aChooseApplicationCache)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markOfflineCacheEntryAsForeign (); */
NS_IMETHODIMP nsApplicationCacheChannel::MarkOfflineCacheEntryAsForeign()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIApplicationCache applicationCacheForWrite; */
NS_IMETHODIMP nsApplicationCacheChannel::GetApplicationCacheForWrite(nsIApplicationCache * *aApplicationCacheForWrite)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsApplicationCacheChannel::SetApplicationCacheForWrite(nsIApplicationCache *aApplicationCacheForWrite)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIApplicationCacheChannel_h__ */

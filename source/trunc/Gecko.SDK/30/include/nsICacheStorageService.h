/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICacheStorageService.idl
 */

#ifndef __gen_nsICacheStorageService_h__
#define __gen_nsICacheStorageService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICacheStorage; /* forward declaration */

class nsILoadContextInfo; /* forward declaration */

class nsIApplicationCache; /* forward declaration */

class nsIEventTarget; /* forward declaration */


/* starting interface:    nsICacheStorageService */
#define NS_ICACHESTORAGESERVICE_IID_STR "d669bf30-b6d9-48e1-a8fb-33cd18b0d752"

#define NS_ICACHESTORAGESERVICE_IID \
  {0xd669bf30, 0xb6d9, 0x48e1, \
    { 0xa8, 0xfb, 0x33, 0xcd, 0x18, 0xb0, 0xd7, 0x52 }}

class NS_NO_VTABLE nsICacheStorageService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHESTORAGESERVICE_IID)

  /* nsICacheStorage memoryCacheStorage (in nsILoadContextInfo aLoadContextInfo); */
  NS_IMETHOD MemoryCacheStorage(nsILoadContextInfo *aLoadContextInfo, nsICacheStorage * *_retval) = 0;

  /* nsICacheStorage diskCacheStorage (in nsILoadContextInfo aLoadContextInfo, in bool aLookupAppCache); */
  NS_IMETHOD DiskCacheStorage(nsILoadContextInfo *aLoadContextInfo, bool aLookupAppCache, nsICacheStorage * *_retval) = 0;

  /* nsICacheStorage appCacheStorage (in nsILoadContextInfo aLoadContextInfo, in nsIApplicationCache aApplicationCache); */
  NS_IMETHOD AppCacheStorage(nsILoadContextInfo *aLoadContextInfo, nsIApplicationCache *aApplicationCache, nsICacheStorage * *_retval) = 0;

  /* void clear (); */
  NS_IMETHOD Clear(void) = 0;

  enum {
    PURGE_DISK_DATA_ONLY = 1U,
    PURGE_DISK_ALL = 2U,
    PURGE_EVERYTHING = 3U
  };

  /* void purgeFromMemory (in uint32_t aWhat); */
  NS_IMETHOD PurgeFromMemory(uint32_t aWhat) = 0;

  /* readonly attribute nsIEventTarget ioTarget; */
  NS_IMETHOD GetIoTarget(nsIEventTarget * *aIoTarget) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheStorageService, NS_ICACHESTORAGESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHESTORAGESERVICE \
  NS_IMETHOD MemoryCacheStorage(nsILoadContextInfo *aLoadContextInfo, nsICacheStorage * *_retval); \
  NS_IMETHOD DiskCacheStorage(nsILoadContextInfo *aLoadContextInfo, bool aLookupAppCache, nsICacheStorage * *_retval); \
  NS_IMETHOD AppCacheStorage(nsILoadContextInfo *aLoadContextInfo, nsIApplicationCache *aApplicationCache, nsICacheStorage * *_retval); \
  NS_IMETHOD Clear(void); \
  NS_IMETHOD PurgeFromMemory(uint32_t aWhat); \
  NS_IMETHOD GetIoTarget(nsIEventTarget * *aIoTarget); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHESTORAGESERVICE(_to) \
  NS_IMETHOD MemoryCacheStorage(nsILoadContextInfo *aLoadContextInfo, nsICacheStorage * *_retval) { return _to MemoryCacheStorage(aLoadContextInfo, _retval); } \
  NS_IMETHOD DiskCacheStorage(nsILoadContextInfo *aLoadContextInfo, bool aLookupAppCache, nsICacheStorage * *_retval) { return _to DiskCacheStorage(aLoadContextInfo, aLookupAppCache, _retval); } \
  NS_IMETHOD AppCacheStorage(nsILoadContextInfo *aLoadContextInfo, nsIApplicationCache *aApplicationCache, nsICacheStorage * *_retval) { return _to AppCacheStorage(aLoadContextInfo, aApplicationCache, _retval); } \
  NS_IMETHOD Clear(void) { return _to Clear(); } \
  NS_IMETHOD PurgeFromMemory(uint32_t aWhat) { return _to PurgeFromMemory(aWhat); } \
  NS_IMETHOD GetIoTarget(nsIEventTarget * *aIoTarget) { return _to GetIoTarget(aIoTarget); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHESTORAGESERVICE(_to) \
  NS_IMETHOD MemoryCacheStorage(nsILoadContextInfo *aLoadContextInfo, nsICacheStorage * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MemoryCacheStorage(aLoadContextInfo, _retval); } \
  NS_IMETHOD DiskCacheStorage(nsILoadContextInfo *aLoadContextInfo, bool aLookupAppCache, nsICacheStorage * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->DiskCacheStorage(aLoadContextInfo, aLookupAppCache, _retval); } \
  NS_IMETHOD AppCacheStorage(nsILoadContextInfo *aLoadContextInfo, nsIApplicationCache *aApplicationCache, nsICacheStorage * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppCacheStorage(aLoadContextInfo, aApplicationCache, _retval); } \
  NS_IMETHOD Clear(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(); } \
  NS_IMETHOD PurgeFromMemory(uint32_t aWhat) { return !_to ? NS_ERROR_NULL_POINTER : _to->PurgeFromMemory(aWhat); } \
  NS_IMETHOD GetIoTarget(nsIEventTarget * *aIoTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIoTarget(aIoTarget); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheStorageService : public nsICacheStorageService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHESTORAGESERVICE

  nsCacheStorageService();

private:
  ~nsCacheStorageService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCacheStorageService, nsICacheStorageService)

nsCacheStorageService::nsCacheStorageService()
{
  /* member initializers and constructor code */
}

nsCacheStorageService::~nsCacheStorageService()
{
  /* destructor code */
}

/* nsICacheStorage memoryCacheStorage (in nsILoadContextInfo aLoadContextInfo); */
NS_IMETHODIMP nsCacheStorageService::MemoryCacheStorage(nsILoadContextInfo *aLoadContextInfo, nsICacheStorage * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsICacheStorage diskCacheStorage (in nsILoadContextInfo aLoadContextInfo, in bool aLookupAppCache); */
NS_IMETHODIMP nsCacheStorageService::DiskCacheStorage(nsILoadContextInfo *aLoadContextInfo, bool aLookupAppCache, nsICacheStorage * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsICacheStorage appCacheStorage (in nsILoadContextInfo aLoadContextInfo, in nsIApplicationCache aApplicationCache); */
NS_IMETHODIMP nsCacheStorageService::AppCacheStorage(nsILoadContextInfo *aLoadContextInfo, nsIApplicationCache *aApplicationCache, nsICacheStorage * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clear (); */
NS_IMETHODIMP nsCacheStorageService::Clear()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void purgeFromMemory (in uint32_t aWhat); */
NS_IMETHODIMP nsCacheStorageService::PurgeFromMemory(uint32_t aWhat)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIEventTarget ioTarget; */
NS_IMETHODIMP nsCacheStorageService::GetIoTarget(nsIEventTarget * *aIoTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICacheStorageService_h__ */

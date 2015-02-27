/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/cache/nsICacheSession.idl
 */

#ifndef __gen_nsICacheSession_h__
#define __gen_nsICacheSession_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsICache_h__
#include "nsICache.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICacheEntryDescriptor; /* forward declaration */

class nsICacheListener; /* forward declaration */

class nsIFile; /* forward declaration */


/* starting interface:    nsICacheSession */
#define NS_ICACHESESSION_IID_STR "1dd7708c-de48-4ffe-b5aa-cd218c762887"

#define NS_ICACHESESSION_IID \
  {0x1dd7708c, 0xde48, 0x4ffe, \
    { 0xb5, 0xaa, 0xcd, 0x21, 0x8c, 0x76, 0x28, 0x87 }}

class NS_NO_VTABLE nsICacheSession : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHESESSION_IID)

  /* attribute boolean doomEntriesIfExpired; */
  NS_IMETHOD GetDoomEntriesIfExpired(bool *aDoomEntriesIfExpired) = 0;
  NS_IMETHOD SetDoomEntriesIfExpired(bool aDoomEntriesIfExpired) = 0;

  /* attribute nsIFile profileDirectory; */
  NS_IMETHOD GetProfileDirectory(nsIFile * *aProfileDirectory) = 0;
  NS_IMETHOD SetProfileDirectory(nsIFile *aProfileDirectory) = 0;

  /* nsICacheEntryDescriptor openCacheEntry (in ACString key, in nsCacheAccessMode accessRequested, in boolean blockingMode); */
  NS_IMETHOD OpenCacheEntry(const nsACString & key, nsCacheAccessMode accessRequested, bool blockingMode, nsICacheEntryDescriptor * *_retval) = 0;

  /* void asyncOpenCacheEntry (in ACString key, in nsCacheAccessMode accessRequested, in nsICacheListener listener, [optional] in boolean noWait); */
  NS_IMETHOD AsyncOpenCacheEntry(const nsACString & key, nsCacheAccessMode accessRequested, nsICacheListener *listener, bool noWait) = 0;

  /* void evictEntries (); */
  NS_IMETHOD EvictEntries(void) = 0;

  /* boolean isStorageEnabled (); */
  NS_IMETHOD IsStorageEnabled(bool *_retval) = 0;

  /* void doomEntry (in ACString key, in nsICacheListener listener); */
  NS_IMETHOD DoomEntry(const nsACString & key, nsICacheListener *listener) = 0;

  /* attribute boolean isPrivate; */
  NS_IMETHOD GetIsPrivate(bool *aIsPrivate) = 0;
  NS_IMETHOD SetIsPrivate(bool aIsPrivate) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheSession, NS_ICACHESESSION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHESESSION \
  NS_IMETHOD GetDoomEntriesIfExpired(bool *aDoomEntriesIfExpired); \
  NS_IMETHOD SetDoomEntriesIfExpired(bool aDoomEntriesIfExpired); \
  NS_IMETHOD GetProfileDirectory(nsIFile * *aProfileDirectory); \
  NS_IMETHOD SetProfileDirectory(nsIFile *aProfileDirectory); \
  NS_IMETHOD OpenCacheEntry(const nsACString & key, nsCacheAccessMode accessRequested, bool blockingMode, nsICacheEntryDescriptor * *_retval); \
  NS_IMETHOD AsyncOpenCacheEntry(const nsACString & key, nsCacheAccessMode accessRequested, nsICacheListener *listener, bool noWait); \
  NS_IMETHOD EvictEntries(void); \
  NS_IMETHOD IsStorageEnabled(bool *_retval); \
  NS_IMETHOD DoomEntry(const nsACString & key, nsICacheListener *listener); \
  NS_IMETHOD GetIsPrivate(bool *aIsPrivate); \
  NS_IMETHOD SetIsPrivate(bool aIsPrivate); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHESESSION(_to) \
  NS_IMETHOD GetDoomEntriesIfExpired(bool *aDoomEntriesIfExpired) { return _to GetDoomEntriesIfExpired(aDoomEntriesIfExpired); } \
  NS_IMETHOD SetDoomEntriesIfExpired(bool aDoomEntriesIfExpired) { return _to SetDoomEntriesIfExpired(aDoomEntriesIfExpired); } \
  NS_IMETHOD GetProfileDirectory(nsIFile * *aProfileDirectory) { return _to GetProfileDirectory(aProfileDirectory); } \
  NS_IMETHOD SetProfileDirectory(nsIFile *aProfileDirectory) { return _to SetProfileDirectory(aProfileDirectory); } \
  NS_IMETHOD OpenCacheEntry(const nsACString & key, nsCacheAccessMode accessRequested, bool blockingMode, nsICacheEntryDescriptor * *_retval) { return _to OpenCacheEntry(key, accessRequested, blockingMode, _retval); } \
  NS_IMETHOD AsyncOpenCacheEntry(const nsACString & key, nsCacheAccessMode accessRequested, nsICacheListener *listener, bool noWait) { return _to AsyncOpenCacheEntry(key, accessRequested, listener, noWait); } \
  NS_IMETHOD EvictEntries(void) { return _to EvictEntries(); } \
  NS_IMETHOD IsStorageEnabled(bool *_retval) { return _to IsStorageEnabled(_retval); } \
  NS_IMETHOD DoomEntry(const nsACString & key, nsICacheListener *listener) { return _to DoomEntry(key, listener); } \
  NS_IMETHOD GetIsPrivate(bool *aIsPrivate) { return _to GetIsPrivate(aIsPrivate); } \
  NS_IMETHOD SetIsPrivate(bool aIsPrivate) { return _to SetIsPrivate(aIsPrivate); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHESESSION(_to) \
  NS_IMETHOD GetDoomEntriesIfExpired(bool *aDoomEntriesIfExpired) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDoomEntriesIfExpired(aDoomEntriesIfExpired); } \
  NS_IMETHOD SetDoomEntriesIfExpired(bool aDoomEntriesIfExpired) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDoomEntriesIfExpired(aDoomEntriesIfExpired); } \
  NS_IMETHOD GetProfileDirectory(nsIFile * *aProfileDirectory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProfileDirectory(aProfileDirectory); } \
  NS_IMETHOD SetProfileDirectory(nsIFile *aProfileDirectory) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProfileDirectory(aProfileDirectory); } \
  NS_IMETHOD OpenCacheEntry(const nsACString & key, nsCacheAccessMode accessRequested, bool blockingMode, nsICacheEntryDescriptor * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenCacheEntry(key, accessRequested, blockingMode, _retval); } \
  NS_IMETHOD AsyncOpenCacheEntry(const nsACString & key, nsCacheAccessMode accessRequested, nsICacheListener *listener, bool noWait) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncOpenCacheEntry(key, accessRequested, listener, noWait); } \
  NS_IMETHOD EvictEntries(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EvictEntries(); } \
  NS_IMETHOD IsStorageEnabled(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsStorageEnabled(_retval); } \
  NS_IMETHOD DoomEntry(const nsACString & key, nsICacheListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoomEntry(key, listener); } \
  NS_IMETHOD GetIsPrivate(bool *aIsPrivate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsPrivate(aIsPrivate); } \
  NS_IMETHOD SetIsPrivate(bool aIsPrivate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsPrivate(aIsPrivate); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheSession : public nsICacheSession
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHESESSION

  nsCacheSession();

private:
  ~nsCacheSession();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCacheSession, nsICacheSession)

nsCacheSession::nsCacheSession()
{
  /* member initializers and constructor code */
}

nsCacheSession::~nsCacheSession()
{
  /* destructor code */
}

/* attribute boolean doomEntriesIfExpired; */
NS_IMETHODIMP nsCacheSession::GetDoomEntriesIfExpired(bool *aDoomEntriesIfExpired)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCacheSession::SetDoomEntriesIfExpired(bool aDoomEntriesIfExpired)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIFile profileDirectory; */
NS_IMETHODIMP nsCacheSession::GetProfileDirectory(nsIFile * *aProfileDirectory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCacheSession::SetProfileDirectory(nsIFile *aProfileDirectory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsICacheEntryDescriptor openCacheEntry (in ACString key, in nsCacheAccessMode accessRequested, in boolean blockingMode); */
NS_IMETHODIMP nsCacheSession::OpenCacheEntry(const nsACString & key, nsCacheAccessMode accessRequested, bool blockingMode, nsICacheEntryDescriptor * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncOpenCacheEntry (in ACString key, in nsCacheAccessMode accessRequested, in nsICacheListener listener, [optional] in boolean noWait); */
NS_IMETHODIMP nsCacheSession::AsyncOpenCacheEntry(const nsACString & key, nsCacheAccessMode accessRequested, nsICacheListener *listener, bool noWait)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void evictEntries (); */
NS_IMETHODIMP nsCacheSession::EvictEntries()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isStorageEnabled (); */
NS_IMETHODIMP nsCacheSession::IsStorageEnabled(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doomEntry (in ACString key, in nsICacheListener listener); */
NS_IMETHODIMP nsCacheSession::DoomEntry(const nsACString & key, nsICacheListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isPrivate; */
NS_IMETHODIMP nsCacheSession::GetIsPrivate(bool *aIsPrivate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCacheSession::SetIsPrivate(bool aIsPrivate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICacheSession_h__ */

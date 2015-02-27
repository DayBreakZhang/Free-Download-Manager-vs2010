/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICacheEntry.idl
 */

#ifndef __gen_nsICacheEntry_h__
#define __gen_nsICacheEntry_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

class nsIOutputStream; /* forward declaration */

class nsICacheEntryDoomCallback; /* forward declaration */

typedef int32_t  nsCacheAccessMode;

typedef int32_t  nsCacheStoragePolicy;

class nsICacheListener; /* forward declaration */

class nsIFile; /* forward declaration */

class nsICacheMetaDataVisitor; /* forward declaration */


/* starting interface:    nsICacheEntry */
#define NS_ICACHEENTRY_IID_STR "d3fbd879-6d3a-4bd0-b12e-7d86ab27ea90"

#define NS_ICACHEENTRY_IID \
  {0xd3fbd879, 0x6d3a, 0x4bd0, \
    { 0xb1, 0x2e, 0x7d, 0x86, 0xab, 0x27, 0xea, 0x90 }}

class NS_NO_VTABLE nsICacheEntry : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHEENTRY_IID)

  /* readonly attribute ACString key; */
  NS_IMETHOD GetKey(nsACString & aKey) = 0;

  /* readonly attribute boolean persistent; */
  NS_IMETHOD GetPersistent(bool *aPersistent) = 0;

  /* readonly attribute long fetchCount; */
  NS_IMETHOD GetFetchCount(int32_t *aFetchCount) = 0;

  /* readonly attribute uint32_t lastFetched; */
  NS_IMETHOD GetLastFetched(uint32_t *aLastFetched) = 0;

  /* readonly attribute uint32_t lastModified; */
  NS_IMETHOD GetLastModified(uint32_t *aLastModified) = 0;

  /* readonly attribute uint32_t expirationTime; */
  NS_IMETHOD GetExpirationTime(uint32_t *aExpirationTime) = 0;

  /* void setExpirationTime (in uint32_t expirationTime); */
  NS_IMETHOD SetExpirationTime(uint32_t expirationTime) = 0;

  /* nsIInputStream openInputStream (in long long offset); */
  NS_IMETHOD OpenInputStream(int64_t offset, nsIInputStream * *_retval) = 0;

  /* nsIOutputStream openOutputStream (in long long offset); */
  NS_IMETHOD OpenOutputStream(int64_t offset, nsIOutputStream * *_retval) = 0;

  /* attribute int64_t predictedDataSize; */
  NS_IMETHOD GetPredictedDataSize(int64_t *aPredictedDataSize) = 0;
  NS_IMETHOD SetPredictedDataSize(int64_t aPredictedDataSize) = 0;

  /* attribute nsISupports securityInfo; */
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) = 0;
  NS_IMETHOD SetSecurityInfo(nsISupports *aSecurityInfo) = 0;

  /* readonly attribute unsigned long storageDataSize; */
  NS_IMETHOD GetStorageDataSize(uint32_t *aStorageDataSize) = 0;

  /* void asyncDoom (in nsICacheEntryDoomCallback listener); */
  NS_IMETHOD AsyncDoom(nsICacheEntryDoomCallback *listener) = 0;

  /* string getMetaDataElement (in string key); */
  NS_IMETHOD GetMetaDataElement(const char * key, char * *_retval) = 0;

  /* void setMetaDataElement (in string key, in string value); */
  NS_IMETHOD SetMetaDataElement(const char * key, const char * value) = 0;

  /* void metaDataReady (); */
  NS_IMETHOD MetaDataReady(void) = 0;

  /* void setValid (); */
  NS_IMETHOD SetValid(void) = 0;

  /* nsICacheEntry recreate ([optional] in boolean aMemoryOnly); */
  NS_IMETHOD Recreate(bool aMemoryOnly, nsICacheEntry * *_retval) = 0;

  /* readonly attribute long long dataSize; */
  NS_IMETHOD GetDataSize(int64_t *aDataSize) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

  /* void markValid (); */
  NS_IMETHOD MarkValid(void) = 0;

  /* void maybeMarkValid (); */
  NS_IMETHOD MaybeMarkValid(void) = 0;

  /* boolean hasWriteAccess (in boolean aWriteAllowed); */
  NS_IMETHOD HasWriteAccess(bool aWriteAllowed, bool *_retval) = 0;

  enum {
    NO_EXPIRATION_TIME = 4294967295U
  };

  /* void setDataSize (in unsigned long size); */
  NS_IMETHOD SetDataSize(uint32_t size) = 0;

  /* attribute nsCacheStoragePolicy storagePolicy; */
  NS_IMETHOD GetStoragePolicy(nsCacheStoragePolicy *aStoragePolicy) = 0;
  NS_IMETHOD SetStoragePolicy(nsCacheStoragePolicy aStoragePolicy) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheEntry, NS_ICACHEENTRY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHEENTRY \
  NS_IMETHOD GetKey(nsACString & aKey); \
  NS_IMETHOD GetPersistent(bool *aPersistent); \
  NS_IMETHOD GetFetchCount(int32_t *aFetchCount); \
  NS_IMETHOD GetLastFetched(uint32_t *aLastFetched); \
  NS_IMETHOD GetLastModified(uint32_t *aLastModified); \
  NS_IMETHOD GetExpirationTime(uint32_t *aExpirationTime); \
  NS_IMETHOD SetExpirationTime(uint32_t expirationTime); \
  NS_IMETHOD OpenInputStream(int64_t offset, nsIInputStream * *_retval); \
  NS_IMETHOD OpenOutputStream(int64_t offset, nsIOutputStream * *_retval); \
  NS_IMETHOD GetPredictedDataSize(int64_t *aPredictedDataSize); \
  NS_IMETHOD SetPredictedDataSize(int64_t aPredictedDataSize); \
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo); \
  NS_IMETHOD SetSecurityInfo(nsISupports *aSecurityInfo); \
  NS_IMETHOD GetStorageDataSize(uint32_t *aStorageDataSize); \
  NS_IMETHOD AsyncDoom(nsICacheEntryDoomCallback *listener); \
  NS_IMETHOD GetMetaDataElement(const char * key, char * *_retval); \
  NS_IMETHOD SetMetaDataElement(const char * key, const char * value); \
  NS_IMETHOD MetaDataReady(void); \
  NS_IMETHOD SetValid(void); \
  NS_IMETHOD Recreate(bool aMemoryOnly, nsICacheEntry * *_retval); \
  NS_IMETHOD GetDataSize(int64_t *aDataSize); \
  NS_IMETHOD Close(void); \
  NS_IMETHOD MarkValid(void); \
  NS_IMETHOD MaybeMarkValid(void); \
  NS_IMETHOD HasWriteAccess(bool aWriteAllowed, bool *_retval); \
  NS_IMETHOD SetDataSize(uint32_t size); \
  NS_IMETHOD GetStoragePolicy(nsCacheStoragePolicy *aStoragePolicy); \
  NS_IMETHOD SetStoragePolicy(nsCacheStoragePolicy aStoragePolicy); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHEENTRY(_to) \
  NS_IMETHOD GetKey(nsACString & aKey) { return _to GetKey(aKey); } \
  NS_IMETHOD GetPersistent(bool *aPersistent) { return _to GetPersistent(aPersistent); } \
  NS_IMETHOD GetFetchCount(int32_t *aFetchCount) { return _to GetFetchCount(aFetchCount); } \
  NS_IMETHOD GetLastFetched(uint32_t *aLastFetched) { return _to GetLastFetched(aLastFetched); } \
  NS_IMETHOD GetLastModified(uint32_t *aLastModified) { return _to GetLastModified(aLastModified); } \
  NS_IMETHOD GetExpirationTime(uint32_t *aExpirationTime) { return _to GetExpirationTime(aExpirationTime); } \
  NS_IMETHOD SetExpirationTime(uint32_t expirationTime) { return _to SetExpirationTime(expirationTime); } \
  NS_IMETHOD OpenInputStream(int64_t offset, nsIInputStream * *_retval) { return _to OpenInputStream(offset, _retval); } \
  NS_IMETHOD OpenOutputStream(int64_t offset, nsIOutputStream * *_retval) { return _to OpenOutputStream(offset, _retval); } \
  NS_IMETHOD GetPredictedDataSize(int64_t *aPredictedDataSize) { return _to GetPredictedDataSize(aPredictedDataSize); } \
  NS_IMETHOD SetPredictedDataSize(int64_t aPredictedDataSize) { return _to SetPredictedDataSize(aPredictedDataSize); } \
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) { return _to GetSecurityInfo(aSecurityInfo); } \
  NS_IMETHOD SetSecurityInfo(nsISupports *aSecurityInfo) { return _to SetSecurityInfo(aSecurityInfo); } \
  NS_IMETHOD GetStorageDataSize(uint32_t *aStorageDataSize) { return _to GetStorageDataSize(aStorageDataSize); } \
  NS_IMETHOD AsyncDoom(nsICacheEntryDoomCallback *listener) { return _to AsyncDoom(listener); } \
  NS_IMETHOD GetMetaDataElement(const char * key, char * *_retval) { return _to GetMetaDataElement(key, _retval); } \
  NS_IMETHOD SetMetaDataElement(const char * key, const char * value) { return _to SetMetaDataElement(key, value); } \
  NS_IMETHOD MetaDataReady(void) { return _to MetaDataReady(); } \
  NS_IMETHOD SetValid(void) { return _to SetValid(); } \
  NS_IMETHOD Recreate(bool aMemoryOnly, nsICacheEntry * *_retval) { return _to Recreate(aMemoryOnly, _retval); } \
  NS_IMETHOD GetDataSize(int64_t *aDataSize) { return _to GetDataSize(aDataSize); } \
  NS_IMETHOD Close(void) { return _to Close(); } \
  NS_IMETHOD MarkValid(void) { return _to MarkValid(); } \
  NS_IMETHOD MaybeMarkValid(void) { return _to MaybeMarkValid(); } \
  NS_IMETHOD HasWriteAccess(bool aWriteAllowed, bool *_retval) { return _to HasWriteAccess(aWriteAllowed, _retval); } \
  NS_IMETHOD SetDataSize(uint32_t size) { return _to SetDataSize(size); } \
  NS_IMETHOD GetStoragePolicy(nsCacheStoragePolicy *aStoragePolicy) { return _to GetStoragePolicy(aStoragePolicy); } \
  NS_IMETHOD SetStoragePolicy(nsCacheStoragePolicy aStoragePolicy) { return _to SetStoragePolicy(aStoragePolicy); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHEENTRY(_to) \
  NS_IMETHOD GetKey(nsACString & aKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKey(aKey); } \
  NS_IMETHOD GetPersistent(bool *aPersistent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPersistent(aPersistent); } \
  NS_IMETHOD GetFetchCount(int32_t *aFetchCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFetchCount(aFetchCount); } \
  NS_IMETHOD GetLastFetched(uint32_t *aLastFetched) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastFetched(aLastFetched); } \
  NS_IMETHOD GetLastModified(uint32_t *aLastModified) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastModified(aLastModified); } \
  NS_IMETHOD GetExpirationTime(uint32_t *aExpirationTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExpirationTime(aExpirationTime); } \
  NS_IMETHOD SetExpirationTime(uint32_t expirationTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExpirationTime(expirationTime); } \
  NS_IMETHOD OpenInputStream(int64_t offset, nsIInputStream * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenInputStream(offset, _retval); } \
  NS_IMETHOD OpenOutputStream(int64_t offset, nsIOutputStream * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenOutputStream(offset, _retval); } \
  NS_IMETHOD GetPredictedDataSize(int64_t *aPredictedDataSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPredictedDataSize(aPredictedDataSize); } \
  NS_IMETHOD SetPredictedDataSize(int64_t aPredictedDataSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPredictedDataSize(aPredictedDataSize); } \
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSecurityInfo(aSecurityInfo); } \
  NS_IMETHOD SetSecurityInfo(nsISupports *aSecurityInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSecurityInfo(aSecurityInfo); } \
  NS_IMETHOD GetStorageDataSize(uint32_t *aStorageDataSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStorageDataSize(aStorageDataSize); } \
  NS_IMETHOD AsyncDoom(nsICacheEntryDoomCallback *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncDoom(listener); } \
  NS_IMETHOD GetMetaDataElement(const char * key, char * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMetaDataElement(key, _retval); } \
  NS_IMETHOD SetMetaDataElement(const char * key, const char * value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMetaDataElement(key, value); } \
  NS_IMETHOD MetaDataReady(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->MetaDataReady(); } \
  NS_IMETHOD SetValid(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValid(); } \
  NS_IMETHOD Recreate(bool aMemoryOnly, nsICacheEntry * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Recreate(aMemoryOnly, _retval); } \
  NS_IMETHOD GetDataSize(int64_t *aDataSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataSize(aDataSize); } \
  NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_IMETHOD MarkValid(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkValid(); } \
  NS_IMETHOD MaybeMarkValid(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->MaybeMarkValid(); } \
  NS_IMETHOD HasWriteAccess(bool aWriteAllowed, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasWriteAccess(aWriteAllowed, _retval); } \
  NS_IMETHOD SetDataSize(uint32_t size) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDataSize(size); } \
  NS_IMETHOD GetStoragePolicy(nsCacheStoragePolicy *aStoragePolicy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStoragePolicy(aStoragePolicy); } \
  NS_IMETHOD SetStoragePolicy(nsCacheStoragePolicy aStoragePolicy) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStoragePolicy(aStoragePolicy); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheEntry : public nsICacheEntry
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHEENTRY

  nsCacheEntry();

private:
  ~nsCacheEntry();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCacheEntry, nsICacheEntry)

nsCacheEntry::nsCacheEntry()
{
  /* member initializers and constructor code */
}

nsCacheEntry::~nsCacheEntry()
{
  /* destructor code */
}

/* readonly attribute ACString key; */
NS_IMETHODIMP nsCacheEntry::GetKey(nsACString & aKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean persistent; */
NS_IMETHODIMP nsCacheEntry::GetPersistent(bool *aPersistent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long fetchCount; */
NS_IMETHODIMP nsCacheEntry::GetFetchCount(int32_t *aFetchCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t lastFetched; */
NS_IMETHODIMP nsCacheEntry::GetLastFetched(uint32_t *aLastFetched)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t lastModified; */
NS_IMETHODIMP nsCacheEntry::GetLastModified(uint32_t *aLastModified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t expirationTime; */
NS_IMETHODIMP nsCacheEntry::GetExpirationTime(uint32_t *aExpirationTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setExpirationTime (in uint32_t expirationTime); */
NS_IMETHODIMP nsCacheEntry::SetExpirationTime(uint32_t expirationTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream openInputStream (in long long offset); */
NS_IMETHODIMP nsCacheEntry::OpenInputStream(int64_t offset, nsIInputStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIOutputStream openOutputStream (in long long offset); */
NS_IMETHODIMP nsCacheEntry::OpenOutputStream(int64_t offset, nsIOutputStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute int64_t predictedDataSize; */
NS_IMETHODIMP nsCacheEntry::GetPredictedDataSize(int64_t *aPredictedDataSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCacheEntry::SetPredictedDataSize(int64_t aPredictedDataSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISupports securityInfo; */
NS_IMETHODIMP nsCacheEntry::GetSecurityInfo(nsISupports * *aSecurityInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCacheEntry::SetSecurityInfo(nsISupports *aSecurityInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long storageDataSize; */
NS_IMETHODIMP nsCacheEntry::GetStorageDataSize(uint32_t *aStorageDataSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncDoom (in nsICacheEntryDoomCallback listener); */
NS_IMETHODIMP nsCacheEntry::AsyncDoom(nsICacheEntryDoomCallback *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string getMetaDataElement (in string key); */
NS_IMETHODIMP nsCacheEntry::GetMetaDataElement(const char * key, char * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setMetaDataElement (in string key, in string value); */
NS_IMETHODIMP nsCacheEntry::SetMetaDataElement(const char * key, const char * value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void metaDataReady (); */
NS_IMETHODIMP nsCacheEntry::MetaDataReady()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setValid (); */
NS_IMETHODIMP nsCacheEntry::SetValid()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsICacheEntry recreate ([optional] in boolean aMemoryOnly); */
NS_IMETHODIMP nsCacheEntry::Recreate(bool aMemoryOnly, nsICacheEntry * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long dataSize; */
NS_IMETHODIMP nsCacheEntry::GetDataSize(int64_t *aDataSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsCacheEntry::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markValid (); */
NS_IMETHODIMP nsCacheEntry::MarkValid()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void maybeMarkValid (); */
NS_IMETHODIMP nsCacheEntry::MaybeMarkValid()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasWriteAccess (in boolean aWriteAllowed); */
NS_IMETHODIMP nsCacheEntry::HasWriteAccess(bool aWriteAllowed, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDataSize (in unsigned long size); */
NS_IMETHODIMP nsCacheEntry::SetDataSize(uint32_t size)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsCacheStoragePolicy storagePolicy; */
NS_IMETHODIMP nsCacheEntry::GetStoragePolicy(nsCacheStoragePolicy *aStoragePolicy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCacheEntry::SetStoragePolicy(nsCacheStoragePolicy aStoragePolicy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICacheEntry_h__ */

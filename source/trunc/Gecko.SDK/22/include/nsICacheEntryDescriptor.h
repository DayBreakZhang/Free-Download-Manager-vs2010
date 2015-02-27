/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/cache/nsICacheEntryDescriptor.idl
 */

#ifndef __gen_nsICacheEntryDescriptor_h__
#define __gen_nsICacheEntryDescriptor_h__


#ifndef __gen_nsICacheVisitor_h__
#include "nsICacheVisitor.h"
#endif

#ifndef __gen_nsICache_h__
#include "nsICache.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISimpleEnumerator; /* forward declaration */

class nsICacheListener; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIOutputStream; /* forward declaration */

class nsIFile; /* forward declaration */

class nsICacheMetaDataVisitor; /* forward declaration */


/* starting interface:    nsICacheEntryDescriptor */
#define NS_ICACHEENTRYDESCRIPTOR_IID_STR "90b17d31-46aa-4fb1-a206-473c966cbc18"

#define NS_ICACHEENTRYDESCRIPTOR_IID \
  {0x90b17d31, 0x46aa, 0x4fb1, \
    { 0xa2, 0x06, 0x47, 0x3c, 0x96, 0x6c, 0xbc, 0x18 }}

class NS_NO_VTABLE nsICacheEntryDescriptor : public nsICacheEntryInfo {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHEENTRYDESCRIPTOR_IID)

  /* void setExpirationTime (in uint32_t expirationTime); */
  NS_IMETHOD SetExpirationTime(uint32_t expirationTime) = 0;

  /* void setDataSize (in unsigned long size); */
  NS_IMETHOD SetDataSize(uint32_t size) = 0;

  /* nsIInputStream openInputStream (in unsigned long offset); */
  NS_IMETHOD OpenInputStream(uint32_t offset, nsIInputStream * *_retval) = 0;

  /* nsIOutputStream openOutputStream (in unsigned long offset); */
  NS_IMETHOD OpenOutputStream(uint32_t offset, nsIOutputStream * *_retval) = 0;

  /* attribute nsISupports cacheElement; */
  NS_IMETHOD GetCacheElement(nsISupports * *aCacheElement) = 0;
  NS_IMETHOD SetCacheElement(nsISupports *aCacheElement) = 0;

  /* attribute int64_t predictedDataSize; */
  NS_IMETHOD GetPredictedDataSize(int64_t *aPredictedDataSize) = 0;
  NS_IMETHOD SetPredictedDataSize(int64_t aPredictedDataSize) = 0;

  /* readonly attribute nsCacheAccessMode accessGranted; */
  NS_IMETHOD GetAccessGranted(nsCacheAccessMode *aAccessGranted) = 0;

  /* attribute nsCacheStoragePolicy storagePolicy; */
  NS_IMETHOD GetStoragePolicy(nsCacheStoragePolicy *aStoragePolicy) = 0;
  NS_IMETHOD SetStoragePolicy(nsCacheStoragePolicy aStoragePolicy) = 0;

  /* readonly attribute nsIFile file; */
  NS_IMETHOD GetFile(nsIFile * *aFile) = 0;

  /* attribute nsISupports securityInfo; */
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) = 0;
  NS_IMETHOD SetSecurityInfo(nsISupports *aSecurityInfo) = 0;

  /* readonly attribute unsigned long storageDataSize; */
  NS_IMETHOD GetStorageDataSize(uint32_t *aStorageDataSize) = 0;

  /* void doom (); */
  NS_IMETHOD Doom(void) = 0;

  /* void doomAndFailPendingRequests (in nsresult status); */
  NS_IMETHOD DoomAndFailPendingRequests(nsresult status) = 0;

  /* void asyncDoom (in nsICacheListener listener); */
  NS_IMETHOD AsyncDoom(nsICacheListener *listener) = 0;

  /* void markValid (); */
  NS_IMETHOD MarkValid(void) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

  /* string getMetaDataElement (in string key); */
  NS_IMETHOD GetMetaDataElement(const char * key, char * *_retval) = 0;

  /* void setMetaDataElement (in string key, in string value); */
  NS_IMETHOD SetMetaDataElement(const char * key, const char * value) = 0;

  /* void visitMetaData (in nsICacheMetaDataVisitor visitor); */
  NS_IMETHOD VisitMetaData(nsICacheMetaDataVisitor *visitor) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheEntryDescriptor, NS_ICACHEENTRYDESCRIPTOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHEENTRYDESCRIPTOR \
  NS_IMETHOD SetExpirationTime(uint32_t expirationTime); \
  NS_IMETHOD SetDataSize(uint32_t size); \
  NS_IMETHOD OpenInputStream(uint32_t offset, nsIInputStream * *_retval); \
  NS_IMETHOD OpenOutputStream(uint32_t offset, nsIOutputStream * *_retval); \
  NS_IMETHOD GetCacheElement(nsISupports * *aCacheElement); \
  NS_IMETHOD SetCacheElement(nsISupports *aCacheElement); \
  NS_IMETHOD GetPredictedDataSize(int64_t *aPredictedDataSize); \
  NS_IMETHOD SetPredictedDataSize(int64_t aPredictedDataSize); \
  NS_IMETHOD GetAccessGranted(nsCacheAccessMode *aAccessGranted); \
  NS_IMETHOD GetStoragePolicy(nsCacheStoragePolicy *aStoragePolicy); \
  NS_IMETHOD SetStoragePolicy(nsCacheStoragePolicy aStoragePolicy); \
  NS_IMETHOD GetFile(nsIFile * *aFile); \
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo); \
  NS_IMETHOD SetSecurityInfo(nsISupports *aSecurityInfo); \
  NS_IMETHOD GetStorageDataSize(uint32_t *aStorageDataSize); \
  NS_IMETHOD Doom(void); \
  NS_IMETHOD DoomAndFailPendingRequests(nsresult status); \
  NS_IMETHOD AsyncDoom(nsICacheListener *listener); \
  NS_IMETHOD MarkValid(void); \
  NS_IMETHOD Close(void); \
  NS_IMETHOD GetMetaDataElement(const char * key, char * *_retval); \
  NS_IMETHOD SetMetaDataElement(const char * key, const char * value); \
  NS_IMETHOD VisitMetaData(nsICacheMetaDataVisitor *visitor); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHEENTRYDESCRIPTOR(_to) \
  NS_IMETHOD SetExpirationTime(uint32_t expirationTime) { return _to SetExpirationTime(expirationTime); } \
  NS_IMETHOD SetDataSize(uint32_t size) { return _to SetDataSize(size); } \
  NS_IMETHOD OpenInputStream(uint32_t offset, nsIInputStream * *_retval) { return _to OpenInputStream(offset, _retval); } \
  NS_IMETHOD OpenOutputStream(uint32_t offset, nsIOutputStream * *_retval) { return _to OpenOutputStream(offset, _retval); } \
  NS_IMETHOD GetCacheElement(nsISupports * *aCacheElement) { return _to GetCacheElement(aCacheElement); } \
  NS_IMETHOD SetCacheElement(nsISupports *aCacheElement) { return _to SetCacheElement(aCacheElement); } \
  NS_IMETHOD GetPredictedDataSize(int64_t *aPredictedDataSize) { return _to GetPredictedDataSize(aPredictedDataSize); } \
  NS_IMETHOD SetPredictedDataSize(int64_t aPredictedDataSize) { return _to SetPredictedDataSize(aPredictedDataSize); } \
  NS_IMETHOD GetAccessGranted(nsCacheAccessMode *aAccessGranted) { return _to GetAccessGranted(aAccessGranted); } \
  NS_IMETHOD GetStoragePolicy(nsCacheStoragePolicy *aStoragePolicy) { return _to GetStoragePolicy(aStoragePolicy); } \
  NS_IMETHOD SetStoragePolicy(nsCacheStoragePolicy aStoragePolicy) { return _to SetStoragePolicy(aStoragePolicy); } \
  NS_IMETHOD GetFile(nsIFile * *aFile) { return _to GetFile(aFile); } \
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) { return _to GetSecurityInfo(aSecurityInfo); } \
  NS_IMETHOD SetSecurityInfo(nsISupports *aSecurityInfo) { return _to SetSecurityInfo(aSecurityInfo); } \
  NS_IMETHOD GetStorageDataSize(uint32_t *aStorageDataSize) { return _to GetStorageDataSize(aStorageDataSize); } \
  NS_IMETHOD Doom(void) { return _to Doom(); } \
  NS_IMETHOD DoomAndFailPendingRequests(nsresult status) { return _to DoomAndFailPendingRequests(status); } \
  NS_IMETHOD AsyncDoom(nsICacheListener *listener) { return _to AsyncDoom(listener); } \
  NS_IMETHOD MarkValid(void) { return _to MarkValid(); } \
  NS_IMETHOD Close(void) { return _to Close(); } \
  NS_IMETHOD GetMetaDataElement(const char * key, char * *_retval) { return _to GetMetaDataElement(key, _retval); } \
  NS_IMETHOD SetMetaDataElement(const char * key, const char * value) { return _to SetMetaDataElement(key, value); } \
  NS_IMETHOD VisitMetaData(nsICacheMetaDataVisitor *visitor) { return _to VisitMetaData(visitor); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHEENTRYDESCRIPTOR(_to) \
  NS_IMETHOD SetExpirationTime(uint32_t expirationTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExpirationTime(expirationTime); } \
  NS_IMETHOD SetDataSize(uint32_t size) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDataSize(size); } \
  NS_IMETHOD OpenInputStream(uint32_t offset, nsIInputStream * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenInputStream(offset, _retval); } \
  NS_IMETHOD OpenOutputStream(uint32_t offset, nsIOutputStream * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenOutputStream(offset, _retval); } \
  NS_IMETHOD GetCacheElement(nsISupports * *aCacheElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCacheElement(aCacheElement); } \
  NS_IMETHOD SetCacheElement(nsISupports *aCacheElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCacheElement(aCacheElement); } \
  NS_IMETHOD GetPredictedDataSize(int64_t *aPredictedDataSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPredictedDataSize(aPredictedDataSize); } \
  NS_IMETHOD SetPredictedDataSize(int64_t aPredictedDataSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPredictedDataSize(aPredictedDataSize); } \
  NS_IMETHOD GetAccessGranted(nsCacheAccessMode *aAccessGranted) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessGranted(aAccessGranted); } \
  NS_IMETHOD GetStoragePolicy(nsCacheStoragePolicy *aStoragePolicy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStoragePolicy(aStoragePolicy); } \
  NS_IMETHOD SetStoragePolicy(nsCacheStoragePolicy aStoragePolicy) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStoragePolicy(aStoragePolicy); } \
  NS_IMETHOD GetFile(nsIFile * *aFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFile(aFile); } \
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSecurityInfo(aSecurityInfo); } \
  NS_IMETHOD SetSecurityInfo(nsISupports *aSecurityInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSecurityInfo(aSecurityInfo); } \
  NS_IMETHOD GetStorageDataSize(uint32_t *aStorageDataSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStorageDataSize(aStorageDataSize); } \
  NS_IMETHOD Doom(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Doom(); } \
  NS_IMETHOD DoomAndFailPendingRequests(nsresult status) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoomAndFailPendingRequests(status); } \
  NS_IMETHOD AsyncDoom(nsICacheListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncDoom(listener); } \
  NS_IMETHOD MarkValid(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkValid(); } \
  NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_IMETHOD GetMetaDataElement(const char * key, char * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMetaDataElement(key, _retval); } \
  NS_IMETHOD SetMetaDataElement(const char * key, const char * value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMetaDataElement(key, value); } \
  NS_IMETHOD VisitMetaData(nsICacheMetaDataVisitor *visitor) { return !_to ? NS_ERROR_NULL_POINTER : _to->VisitMetaData(visitor); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheEntryDescriptor : public nsICacheEntryDescriptor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHEENTRYDESCRIPTOR

  nsCacheEntryDescriptor();

private:
  ~nsCacheEntryDescriptor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCacheEntryDescriptor, nsICacheEntryDescriptor)

nsCacheEntryDescriptor::nsCacheEntryDescriptor()
{
  /* member initializers and constructor code */
}

nsCacheEntryDescriptor::~nsCacheEntryDescriptor()
{
  /* destructor code */
}

/* void setExpirationTime (in uint32_t expirationTime); */
NS_IMETHODIMP nsCacheEntryDescriptor::SetExpirationTime(uint32_t expirationTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDataSize (in unsigned long size); */
NS_IMETHODIMP nsCacheEntryDescriptor::SetDataSize(uint32_t size)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream openInputStream (in unsigned long offset); */
NS_IMETHODIMP nsCacheEntryDescriptor::OpenInputStream(uint32_t offset, nsIInputStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIOutputStream openOutputStream (in unsigned long offset); */
NS_IMETHODIMP nsCacheEntryDescriptor::OpenOutputStream(uint32_t offset, nsIOutputStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISupports cacheElement; */
NS_IMETHODIMP nsCacheEntryDescriptor::GetCacheElement(nsISupports * *aCacheElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCacheEntryDescriptor::SetCacheElement(nsISupports *aCacheElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute int64_t predictedDataSize; */
NS_IMETHODIMP nsCacheEntryDescriptor::GetPredictedDataSize(int64_t *aPredictedDataSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCacheEntryDescriptor::SetPredictedDataSize(int64_t aPredictedDataSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsCacheAccessMode accessGranted; */
NS_IMETHODIMP nsCacheEntryDescriptor::GetAccessGranted(nsCacheAccessMode *aAccessGranted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsCacheStoragePolicy storagePolicy; */
NS_IMETHODIMP nsCacheEntryDescriptor::GetStoragePolicy(nsCacheStoragePolicy *aStoragePolicy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCacheEntryDescriptor::SetStoragePolicy(nsCacheStoragePolicy aStoragePolicy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile file; */
NS_IMETHODIMP nsCacheEntryDescriptor::GetFile(nsIFile * *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISupports securityInfo; */
NS_IMETHODIMP nsCacheEntryDescriptor::GetSecurityInfo(nsISupports * *aSecurityInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCacheEntryDescriptor::SetSecurityInfo(nsISupports *aSecurityInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long storageDataSize; */
NS_IMETHODIMP nsCacheEntryDescriptor::GetStorageDataSize(uint32_t *aStorageDataSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doom (); */
NS_IMETHODIMP nsCacheEntryDescriptor::Doom()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doomAndFailPendingRequests (in nsresult status); */
NS_IMETHODIMP nsCacheEntryDescriptor::DoomAndFailPendingRequests(nsresult status)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncDoom (in nsICacheListener listener); */
NS_IMETHODIMP nsCacheEntryDescriptor::AsyncDoom(nsICacheListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markValid (); */
NS_IMETHODIMP nsCacheEntryDescriptor::MarkValid()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsCacheEntryDescriptor::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string getMetaDataElement (in string key); */
NS_IMETHODIMP nsCacheEntryDescriptor::GetMetaDataElement(const char * key, char * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setMetaDataElement (in string key, in string value); */
NS_IMETHODIMP nsCacheEntryDescriptor::SetMetaDataElement(const char * key, const char * value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void visitMetaData (in nsICacheMetaDataVisitor visitor); */
NS_IMETHODIMP nsCacheEntryDescriptor::VisitMetaData(nsICacheMetaDataVisitor *visitor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICacheMetaDataVisitor */
#define NS_ICACHEMETADATAVISITOR_IID_STR "22f9a49c-3cf8-4c23-8006-54efb11ac562"

#define NS_ICACHEMETADATAVISITOR_IID \
  {0x22f9a49c, 0x3cf8, 0x4c23, \
    { 0x80, 0x06, 0x54, 0xef, 0xb1, 0x1a, 0xc5, 0x62 }}

class NS_NO_VTABLE nsICacheMetaDataVisitor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHEMETADATAVISITOR_IID)

  /* boolean visitMetaDataElement (in string key, in string value); */
  NS_IMETHOD VisitMetaDataElement(const char * key, const char * value, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheMetaDataVisitor, NS_ICACHEMETADATAVISITOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHEMETADATAVISITOR \
  NS_IMETHOD VisitMetaDataElement(const char * key, const char * value, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHEMETADATAVISITOR(_to) \
  NS_IMETHOD VisitMetaDataElement(const char * key, const char * value, bool *_retval) { return _to VisitMetaDataElement(key, value, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHEMETADATAVISITOR(_to) \
  NS_IMETHOD VisitMetaDataElement(const char * key, const char * value, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->VisitMetaDataElement(key, value, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheMetaDataVisitor : public nsICacheMetaDataVisitor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHEMETADATAVISITOR

  nsCacheMetaDataVisitor();

private:
  ~nsCacheMetaDataVisitor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCacheMetaDataVisitor, nsICacheMetaDataVisitor)

nsCacheMetaDataVisitor::nsCacheMetaDataVisitor()
{
  /* member initializers and constructor code */
}

nsCacheMetaDataVisitor::~nsCacheMetaDataVisitor()
{
  /* destructor code */
}

/* boolean visitMetaDataElement (in string key, in string value); */
NS_IMETHODIMP nsCacheMetaDataVisitor::VisitMetaDataElement(const char * key, const char * value, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICacheEntryDescriptor_h__ */

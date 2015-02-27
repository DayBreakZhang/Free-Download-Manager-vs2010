/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/cache/nsICacheVisitor.idl
 */

#ifndef __gen_nsICacheVisitor_h__
#define __gen_nsICacheVisitor_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICacheDeviceInfo; /* forward declaration */

class nsICacheEntryInfo; /* forward declaration */


/* starting interface:    nsICacheVisitor */
#define NS_ICACHEVISITOR_IID_STR "f8c08c4b-d778-49d1-a59b-866fdc500d95"

#define NS_ICACHEVISITOR_IID \
  {0xf8c08c4b, 0xd778, 0x49d1, \
    { 0xa5, 0x9b, 0x86, 0x6f, 0xdc, 0x50, 0x0d, 0x95 }}

class NS_NO_VTABLE nsICacheVisitor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHEVISITOR_IID)

  /* boolean visitDevice (in string deviceID, in nsICacheDeviceInfo deviceInfo); */
  NS_IMETHOD VisitDevice(const char * deviceID, nsICacheDeviceInfo *deviceInfo, bool *_retval) = 0;

  /* boolean visitEntry (in string deviceID, in nsICacheEntryInfo entryInfo); */
  NS_IMETHOD VisitEntry(const char * deviceID, nsICacheEntryInfo *entryInfo, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheVisitor, NS_ICACHEVISITOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHEVISITOR \
  NS_IMETHOD VisitDevice(const char * deviceID, nsICacheDeviceInfo *deviceInfo, bool *_retval); \
  NS_IMETHOD VisitEntry(const char * deviceID, nsICacheEntryInfo *entryInfo, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHEVISITOR(_to) \
  NS_IMETHOD VisitDevice(const char * deviceID, nsICacheDeviceInfo *deviceInfo, bool *_retval) { return _to VisitDevice(deviceID, deviceInfo, _retval); } \
  NS_IMETHOD VisitEntry(const char * deviceID, nsICacheEntryInfo *entryInfo, bool *_retval) { return _to VisitEntry(deviceID, entryInfo, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHEVISITOR(_to) \
  NS_IMETHOD VisitDevice(const char * deviceID, nsICacheDeviceInfo *deviceInfo, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->VisitDevice(deviceID, deviceInfo, _retval); } \
  NS_IMETHOD VisitEntry(const char * deviceID, nsICacheEntryInfo *entryInfo, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->VisitEntry(deviceID, entryInfo, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheVisitor : public nsICacheVisitor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHEVISITOR

  nsCacheVisitor();

private:
  ~nsCacheVisitor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCacheVisitor, nsICacheVisitor)

nsCacheVisitor::nsCacheVisitor()
{
  /* member initializers and constructor code */
}

nsCacheVisitor::~nsCacheVisitor()
{
  /* destructor code */
}

/* boolean visitDevice (in string deviceID, in nsICacheDeviceInfo deviceInfo); */
NS_IMETHODIMP nsCacheVisitor::VisitDevice(const char * deviceID, nsICacheDeviceInfo *deviceInfo, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean visitEntry (in string deviceID, in nsICacheEntryInfo entryInfo); */
NS_IMETHODIMP nsCacheVisitor::VisitEntry(const char * deviceID, nsICacheEntryInfo *entryInfo, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICacheDeviceInfo */
#define NS_ICACHEDEVICEINFO_IID_STR "31d1c294-1dd2-11b2-be3a-c79230dca297"

#define NS_ICACHEDEVICEINFO_IID \
  {0x31d1c294, 0x1dd2, 0x11b2, \
    { 0xbe, 0x3a, 0xc7, 0x92, 0x30, 0xdc, 0xa2, 0x97 }}

class NS_NO_VTABLE nsICacheDeviceInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHEDEVICEINFO_IID)

  /* readonly attribute string description; */
  NS_IMETHOD GetDescription(char * *aDescription) = 0;

  /* readonly attribute string usageReport; */
  NS_IMETHOD GetUsageReport(char * *aUsageReport) = 0;

  /* readonly attribute unsigned long entryCount; */
  NS_IMETHOD GetEntryCount(uint32_t *aEntryCount) = 0;

  /* readonly attribute unsigned long totalSize; */
  NS_IMETHOD GetTotalSize(uint32_t *aTotalSize) = 0;

  /* readonly attribute unsigned long maximumSize; */
  NS_IMETHOD GetMaximumSize(uint32_t *aMaximumSize) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheDeviceInfo, NS_ICACHEDEVICEINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHEDEVICEINFO \
  NS_IMETHOD GetDescription(char * *aDescription); \
  NS_IMETHOD GetUsageReport(char * *aUsageReport); \
  NS_IMETHOD GetEntryCount(uint32_t *aEntryCount); \
  NS_IMETHOD GetTotalSize(uint32_t *aTotalSize); \
  NS_IMETHOD GetMaximumSize(uint32_t *aMaximumSize); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHEDEVICEINFO(_to) \
  NS_IMETHOD GetDescription(char * *aDescription) { return _to GetDescription(aDescription); } \
  NS_IMETHOD GetUsageReport(char * *aUsageReport) { return _to GetUsageReport(aUsageReport); } \
  NS_IMETHOD GetEntryCount(uint32_t *aEntryCount) { return _to GetEntryCount(aEntryCount); } \
  NS_IMETHOD GetTotalSize(uint32_t *aTotalSize) { return _to GetTotalSize(aTotalSize); } \
  NS_IMETHOD GetMaximumSize(uint32_t *aMaximumSize) { return _to GetMaximumSize(aMaximumSize); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHEDEVICEINFO(_to) \
  NS_IMETHOD GetDescription(char * *aDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDescription(aDescription); } \
  NS_IMETHOD GetUsageReport(char * *aUsageReport) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsageReport(aUsageReport); } \
  NS_IMETHOD GetEntryCount(uint32_t *aEntryCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEntryCount(aEntryCount); } \
  NS_IMETHOD GetTotalSize(uint32_t *aTotalSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTotalSize(aTotalSize); } \
  NS_IMETHOD GetMaximumSize(uint32_t *aMaximumSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaximumSize(aMaximumSize); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheDeviceInfo : public nsICacheDeviceInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHEDEVICEINFO

  nsCacheDeviceInfo();

private:
  ~nsCacheDeviceInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCacheDeviceInfo, nsICacheDeviceInfo)

nsCacheDeviceInfo::nsCacheDeviceInfo()
{
  /* member initializers and constructor code */
}

nsCacheDeviceInfo::~nsCacheDeviceInfo()
{
  /* destructor code */
}

/* readonly attribute string description; */
NS_IMETHODIMP nsCacheDeviceInfo::GetDescription(char * *aDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string usageReport; */
NS_IMETHODIMP nsCacheDeviceInfo::GetUsageReport(char * *aUsageReport)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long entryCount; */
NS_IMETHODIMP nsCacheDeviceInfo::GetEntryCount(uint32_t *aEntryCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long totalSize; */
NS_IMETHODIMP nsCacheDeviceInfo::GetTotalSize(uint32_t *aTotalSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long maximumSize; */
NS_IMETHODIMP nsCacheDeviceInfo::GetMaximumSize(uint32_t *aMaximumSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICacheEntryInfo */
#define NS_ICACHEENTRYINFO_IID_STR "fab51c92-95c3-4468-b317-7de4d7588254"

#define NS_ICACHEENTRYINFO_IID \
  {0xfab51c92, 0x95c3, 0x4468, \
    { 0xb3, 0x17, 0x7d, 0xe4, 0xd7, 0x58, 0x82, 0x54 }}

class NS_NO_VTABLE nsICacheEntryInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHEENTRYINFO_IID)

  /* readonly attribute string clientID; */
  NS_IMETHOD GetClientID(char * *aClientID) = 0;

  /* readonly attribute string deviceID; */
  NS_IMETHOD GetDeviceID(char * *aDeviceID) = 0;

  /* readonly attribute ACString key; */
  NS_IMETHOD GetKey(nsACString & aKey) = 0;

  /* readonly attribute long fetchCount; */
  NS_IMETHOD GetFetchCount(int32_t *aFetchCount) = 0;

  /* readonly attribute uint32_t lastFetched; */
  NS_IMETHOD GetLastFetched(uint32_t *aLastFetched) = 0;

  /* readonly attribute uint32_t lastModified; */
  NS_IMETHOD GetLastModified(uint32_t *aLastModified) = 0;

  /* readonly attribute uint32_t expirationTime; */
  NS_IMETHOD GetExpirationTime(uint32_t *aExpirationTime) = 0;

  /* readonly attribute unsigned long dataSize; */
  NS_IMETHOD GetDataSize(uint32_t *aDataSize) = 0;

  /* boolean isStreamBased (); */
  NS_IMETHOD IsStreamBased(bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheEntryInfo, NS_ICACHEENTRYINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHEENTRYINFO \
  NS_IMETHOD GetClientID(char * *aClientID); \
  NS_IMETHOD GetDeviceID(char * *aDeviceID); \
  NS_IMETHOD GetKey(nsACString & aKey); \
  NS_IMETHOD GetFetchCount(int32_t *aFetchCount); \
  NS_IMETHOD GetLastFetched(uint32_t *aLastFetched); \
  NS_IMETHOD GetLastModified(uint32_t *aLastModified); \
  NS_IMETHOD GetExpirationTime(uint32_t *aExpirationTime); \
  NS_IMETHOD GetDataSize(uint32_t *aDataSize); \
  NS_IMETHOD IsStreamBased(bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHEENTRYINFO(_to) \
  NS_IMETHOD GetClientID(char * *aClientID) { return _to GetClientID(aClientID); } \
  NS_IMETHOD GetDeviceID(char * *aDeviceID) { return _to GetDeviceID(aDeviceID); } \
  NS_IMETHOD GetKey(nsACString & aKey) { return _to GetKey(aKey); } \
  NS_IMETHOD GetFetchCount(int32_t *aFetchCount) { return _to GetFetchCount(aFetchCount); } \
  NS_IMETHOD GetLastFetched(uint32_t *aLastFetched) { return _to GetLastFetched(aLastFetched); } \
  NS_IMETHOD GetLastModified(uint32_t *aLastModified) { return _to GetLastModified(aLastModified); } \
  NS_IMETHOD GetExpirationTime(uint32_t *aExpirationTime) { return _to GetExpirationTime(aExpirationTime); } \
  NS_IMETHOD GetDataSize(uint32_t *aDataSize) { return _to GetDataSize(aDataSize); } \
  NS_IMETHOD IsStreamBased(bool *_retval) { return _to IsStreamBased(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHEENTRYINFO(_to) \
  NS_IMETHOD GetClientID(char * *aClientID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientID(aClientID); } \
  NS_IMETHOD GetDeviceID(char * *aDeviceID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDeviceID(aDeviceID); } \
  NS_IMETHOD GetKey(nsACString & aKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKey(aKey); } \
  NS_IMETHOD GetFetchCount(int32_t *aFetchCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFetchCount(aFetchCount); } \
  NS_IMETHOD GetLastFetched(uint32_t *aLastFetched) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastFetched(aLastFetched); } \
  NS_IMETHOD GetLastModified(uint32_t *aLastModified) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastModified(aLastModified); } \
  NS_IMETHOD GetExpirationTime(uint32_t *aExpirationTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExpirationTime(aExpirationTime); } \
  NS_IMETHOD GetDataSize(uint32_t *aDataSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataSize(aDataSize); } \
  NS_IMETHOD IsStreamBased(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsStreamBased(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheEntryInfo : public nsICacheEntryInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHEENTRYINFO

  nsCacheEntryInfo();

private:
  ~nsCacheEntryInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCacheEntryInfo, nsICacheEntryInfo)

nsCacheEntryInfo::nsCacheEntryInfo()
{
  /* member initializers and constructor code */
}

nsCacheEntryInfo::~nsCacheEntryInfo()
{
  /* destructor code */
}

/* readonly attribute string clientID; */
NS_IMETHODIMP nsCacheEntryInfo::GetClientID(char * *aClientID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string deviceID; */
NS_IMETHODIMP nsCacheEntryInfo::GetDeviceID(char * *aDeviceID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString key; */
NS_IMETHODIMP nsCacheEntryInfo::GetKey(nsACString & aKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long fetchCount; */
NS_IMETHODIMP nsCacheEntryInfo::GetFetchCount(int32_t *aFetchCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t lastFetched; */
NS_IMETHODIMP nsCacheEntryInfo::GetLastFetched(uint32_t *aLastFetched)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t lastModified; */
NS_IMETHODIMP nsCacheEntryInfo::GetLastModified(uint32_t *aLastModified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t expirationTime; */
NS_IMETHODIMP nsCacheEntryInfo::GetExpirationTime(uint32_t *aExpirationTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long dataSize; */
NS_IMETHODIMP nsCacheEntryInfo::GetDataSize(uint32_t *aDataSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isStreamBased (); */
NS_IMETHODIMP nsCacheEntryInfo::IsStreamBased(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICacheVisitor_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITelemetry.idl
 */

#ifndef __gen_nsITelemetry_h__
#define __gen_nsITelemetry_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIFile_h__
#include "nsIFile.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIFetchTelemetryDataCallback */
#define NS_IFETCHTELEMETRYDATACALLBACK_IID_STR "3d3b9075-5549-4244-9c08-b64fefa1dd60"

#define NS_IFETCHTELEMETRYDATACALLBACK_IID \
  {0x3d3b9075, 0x5549, 0x4244, \
    { 0x9c, 0x08, 0xb6, 0x4f, 0xef, 0xa1, 0xdd, 0x60 }}

class NS_NO_VTABLE nsIFetchTelemetryDataCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFETCHTELEMETRYDATACALLBACK_IID)

  /* void complete (); */
  NS_IMETHOD Complete(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFetchTelemetryDataCallback, NS_IFETCHTELEMETRYDATACALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFETCHTELEMETRYDATACALLBACK \
  NS_IMETHOD Complete(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFETCHTELEMETRYDATACALLBACK(_to) \
  NS_IMETHOD Complete(void) { return _to Complete(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFETCHTELEMETRYDATACALLBACK(_to) \
  NS_IMETHOD Complete(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Complete(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFetchTelemetryDataCallback : public nsIFetchTelemetryDataCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFETCHTELEMETRYDATACALLBACK

  nsFetchTelemetryDataCallback();

private:
  ~nsFetchTelemetryDataCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFetchTelemetryDataCallback, nsIFetchTelemetryDataCallback)

nsFetchTelemetryDataCallback::nsFetchTelemetryDataCallback()
{
  /* member initializers and constructor code */
}

nsFetchTelemetryDataCallback::~nsFetchTelemetryDataCallback()
{
  /* destructor code */
}

/* void complete (); */
NS_IMETHODIMP nsFetchTelemetryDataCallback::Complete()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITelemetry */
#define NS_ITELEMETRY_IID_STR "4e4bfc35-dac6-4b28-ade4-7e45760051d5"

#define NS_ITELEMETRY_IID \
  {0x4e4bfc35, 0xdac6, 0x4b28, \
    { 0xad, 0xe4, 0x7e, 0x45, 0x76, 0x00, 0x51, 0xd5 }}

class NS_NO_VTABLE nsITelemetry : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITELEMETRY_IID)

  enum {
    HISTOGRAM_EXPONENTIAL = 0U,
    HISTOGRAM_LINEAR = 1U,
    HISTOGRAM_BOOLEAN = 2U,
    HISTOGRAM_FLAG = 3U
  };

  /* [implicit_jscontext] readonly attribute jsval histogramSnapshots; */
  NS_IMETHOD GetHistogramSnapshots(JSContext* cx, JS::MutableHandleValue aHistogramSnapshots) = 0;

  /* readonly attribute uint32_t lastShutdownDuration; */
  NS_IMETHOD GetLastShutdownDuration(uint32_t *aLastShutdownDuration) = 0;

  /* readonly attribute uint32_t failedProfileLockCount; */
  NS_IMETHOD GetFailedProfileLockCount(uint32_t *aFailedProfileLockCount) = 0;

  /* [implicit_jscontext] readonly attribute jsval slowSQL; */
  NS_IMETHOD GetSlowSQL(JSContext* cx, JS::MutableHandleValue aSlowSQL) = 0;

  /* [implicit_jscontext] readonly attribute jsval debugSlowSQL; */
  NS_IMETHOD GetDebugSlowSQL(JSContext* cx, JS::MutableHandleValue aDebugSlowSQL) = 0;

  /* readonly attribute uint32_t maximalNumberOfConcurrentThreads; */
  NS_IMETHOD GetMaximalNumberOfConcurrentThreads(uint32_t *aMaximalNumberOfConcurrentThreads) = 0;

  /* [implicit_jscontext] readonly attribute jsval chromeHangs; */
  NS_IMETHOD GetChromeHangs(JSContext* cx, JS::MutableHandleValue aChromeHangs) = 0;

  /* [implicit_jscontext] readonly attribute jsval threadHangStats; */
  NS_IMETHOD GetThreadHangStats(JSContext* cx, JS::MutableHandleValue aThreadHangStats) = 0;

  /* [implicit_jscontext] readonly attribute jsval lateWrites; */
  NS_IMETHOD GetLateWrites(JSContext* cx, JS::MutableHandleValue aLateWrites) = 0;

  /* void registeredHistograms (out uint32_t count, [array, size_is (count), retval] out string histograms); */
  NS_IMETHOD RegisteredHistograms(uint32_t *count, char * **histograms) = 0;

  /* [implicit_jscontext] jsval newHistogram (in ACString name, in ACString expiration, in uint32_t min, in uint32_t max, in uint32_t bucket_count, in unsigned long histogram_type); */
  NS_IMETHOD NewHistogram(const nsACString & name, const nsACString & expiration, uint32_t min, uint32_t max, uint32_t bucket_count, uint32_t histogram_type, JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* [implicit_jscontext] jsval histogramFrom (in ACString name, in ACString existing_name); */
  NS_IMETHOD HistogramFrom(const nsACString & name, const nsACString & existing_name, JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* [implicit_jscontext] jsval getHistogramById (in ACString id); */
  NS_IMETHOD GetHistogramById(const nsACString & id, JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* attribute boolean canRecord; */
  NS_IMETHOD GetCanRecord(bool *aCanRecord) = 0;
  NS_IMETHOD SetCanRecord(bool aCanRecord) = 0;

  /* readonly attribute boolean canSend; */
  NS_IMETHOD GetCanSend(bool *aCanSend) = 0;

  /* void registerAddonHistogram (in ACString addon_id, in ACString name, in uint32_t min, in uint32_t max, in uint32_t bucket_count, in unsigned long histogram_type); */
  NS_IMETHOD RegisterAddonHistogram(const nsACString & addon_id, const nsACString & name, uint32_t min, uint32_t max, uint32_t bucket_count, uint32_t histogram_type) = 0;

  /* [implicit_jscontext] jsval getAddonHistogram (in ACString addon_id, in ACString name); */
  NS_IMETHOD GetAddonHistogram(const nsACString & addon_id, const nsACString & name, JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* void unregisterAddonHistograms (in ACString addon_id); */
  NS_IMETHOD UnregisterAddonHistograms(const nsACString & addon_id) = 0;

  /* [implicit_jscontext] readonly attribute jsval addonHistogramSnapshots; */
  NS_IMETHOD GetAddonHistogramSnapshots(JSContext* cx, JS::MutableHandleValue aAddonHistogramSnapshots) = 0;

  /* void asyncFetchTelemetryData (in nsIFetchTelemetryDataCallback aCallback); */
  NS_IMETHOD AsyncFetchTelemetryData(nsIFetchTelemetryDataCallback *aCallback) = 0;

  /* [implicit_jscontext] readonly attribute jsval fileIOReports; */
  NS_IMETHOD GetFileIOReports(JSContext* cx, JS::MutableHandleValue aFileIOReports) = 0;

  /* double msSinceProcessStart (); */
  NS_IMETHOD MsSinceProcessStart(double *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITelemetry, NS_ITELEMETRY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITELEMETRY \
  NS_IMETHOD GetHistogramSnapshots(JSContext* cx, JS::MutableHandleValue aHistogramSnapshots); \
  NS_IMETHOD GetLastShutdownDuration(uint32_t *aLastShutdownDuration); \
  NS_IMETHOD GetFailedProfileLockCount(uint32_t *aFailedProfileLockCount); \
  NS_IMETHOD GetSlowSQL(JSContext* cx, JS::MutableHandleValue aSlowSQL); \
  NS_IMETHOD GetDebugSlowSQL(JSContext* cx, JS::MutableHandleValue aDebugSlowSQL); \
  NS_IMETHOD GetMaximalNumberOfConcurrentThreads(uint32_t *aMaximalNumberOfConcurrentThreads); \
  NS_IMETHOD GetChromeHangs(JSContext* cx, JS::MutableHandleValue aChromeHangs); \
  NS_IMETHOD GetThreadHangStats(JSContext* cx, JS::MutableHandleValue aThreadHangStats); \
  NS_IMETHOD GetLateWrites(JSContext* cx, JS::MutableHandleValue aLateWrites); \
  NS_IMETHOD RegisteredHistograms(uint32_t *count, char * **histograms); \
  NS_IMETHOD NewHistogram(const nsACString & name, const nsACString & expiration, uint32_t min, uint32_t max, uint32_t bucket_count, uint32_t histogram_type, JSContext* cx, JS::MutableHandleValue _retval); \
  NS_IMETHOD HistogramFrom(const nsACString & name, const nsACString & existing_name, JSContext* cx, JS::MutableHandleValue _retval); \
  NS_IMETHOD GetHistogramById(const nsACString & id, JSContext* cx, JS::MutableHandleValue _retval); \
  NS_IMETHOD GetCanRecord(bool *aCanRecord); \
  NS_IMETHOD SetCanRecord(bool aCanRecord); \
  NS_IMETHOD GetCanSend(bool *aCanSend); \
  NS_IMETHOD RegisterAddonHistogram(const nsACString & addon_id, const nsACString & name, uint32_t min, uint32_t max, uint32_t bucket_count, uint32_t histogram_type); \
  NS_IMETHOD GetAddonHistogram(const nsACString & addon_id, const nsACString & name, JSContext* cx, JS::MutableHandleValue _retval); \
  NS_IMETHOD UnregisterAddonHistograms(const nsACString & addon_id); \
  NS_IMETHOD GetAddonHistogramSnapshots(JSContext* cx, JS::MutableHandleValue aAddonHistogramSnapshots); \
  NS_IMETHOD AsyncFetchTelemetryData(nsIFetchTelemetryDataCallback *aCallback); \
  NS_IMETHOD GetFileIOReports(JSContext* cx, JS::MutableHandleValue aFileIOReports); \
  NS_IMETHOD MsSinceProcessStart(double *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITELEMETRY(_to) \
  NS_IMETHOD GetHistogramSnapshots(JSContext* cx, JS::MutableHandleValue aHistogramSnapshots) { return _to GetHistogramSnapshots(cx, aHistogramSnapshots); } \
  NS_IMETHOD GetLastShutdownDuration(uint32_t *aLastShutdownDuration) { return _to GetLastShutdownDuration(aLastShutdownDuration); } \
  NS_IMETHOD GetFailedProfileLockCount(uint32_t *aFailedProfileLockCount) { return _to GetFailedProfileLockCount(aFailedProfileLockCount); } \
  NS_IMETHOD GetSlowSQL(JSContext* cx, JS::MutableHandleValue aSlowSQL) { return _to GetSlowSQL(cx, aSlowSQL); } \
  NS_IMETHOD GetDebugSlowSQL(JSContext* cx, JS::MutableHandleValue aDebugSlowSQL) { return _to GetDebugSlowSQL(cx, aDebugSlowSQL); } \
  NS_IMETHOD GetMaximalNumberOfConcurrentThreads(uint32_t *aMaximalNumberOfConcurrentThreads) { return _to GetMaximalNumberOfConcurrentThreads(aMaximalNumberOfConcurrentThreads); } \
  NS_IMETHOD GetChromeHangs(JSContext* cx, JS::MutableHandleValue aChromeHangs) { return _to GetChromeHangs(cx, aChromeHangs); } \
  NS_IMETHOD GetThreadHangStats(JSContext* cx, JS::MutableHandleValue aThreadHangStats) { return _to GetThreadHangStats(cx, aThreadHangStats); } \
  NS_IMETHOD GetLateWrites(JSContext* cx, JS::MutableHandleValue aLateWrites) { return _to GetLateWrites(cx, aLateWrites); } \
  NS_IMETHOD RegisteredHistograms(uint32_t *count, char * **histograms) { return _to RegisteredHistograms(count, histograms); } \
  NS_IMETHOD NewHistogram(const nsACString & name, const nsACString & expiration, uint32_t min, uint32_t max, uint32_t bucket_count, uint32_t histogram_type, JSContext* cx, JS::MutableHandleValue _retval) { return _to NewHistogram(name, expiration, min, max, bucket_count, histogram_type, cx, _retval); } \
  NS_IMETHOD HistogramFrom(const nsACString & name, const nsACString & existing_name, JSContext* cx, JS::MutableHandleValue _retval) { return _to HistogramFrom(name, existing_name, cx, _retval); } \
  NS_IMETHOD GetHistogramById(const nsACString & id, JSContext* cx, JS::MutableHandleValue _retval) { return _to GetHistogramById(id, cx, _retval); } \
  NS_IMETHOD GetCanRecord(bool *aCanRecord) { return _to GetCanRecord(aCanRecord); } \
  NS_IMETHOD SetCanRecord(bool aCanRecord) { return _to SetCanRecord(aCanRecord); } \
  NS_IMETHOD GetCanSend(bool *aCanSend) { return _to GetCanSend(aCanSend); } \
  NS_IMETHOD RegisterAddonHistogram(const nsACString & addon_id, const nsACString & name, uint32_t min, uint32_t max, uint32_t bucket_count, uint32_t histogram_type) { return _to RegisterAddonHistogram(addon_id, name, min, max, bucket_count, histogram_type); } \
  NS_IMETHOD GetAddonHistogram(const nsACString & addon_id, const nsACString & name, JSContext* cx, JS::MutableHandleValue _retval) { return _to GetAddonHistogram(addon_id, name, cx, _retval); } \
  NS_IMETHOD UnregisterAddonHistograms(const nsACString & addon_id) { return _to UnregisterAddonHistograms(addon_id); } \
  NS_IMETHOD GetAddonHistogramSnapshots(JSContext* cx, JS::MutableHandleValue aAddonHistogramSnapshots) { return _to GetAddonHistogramSnapshots(cx, aAddonHistogramSnapshots); } \
  NS_IMETHOD AsyncFetchTelemetryData(nsIFetchTelemetryDataCallback *aCallback) { return _to AsyncFetchTelemetryData(aCallback); } \
  NS_IMETHOD GetFileIOReports(JSContext* cx, JS::MutableHandleValue aFileIOReports) { return _to GetFileIOReports(cx, aFileIOReports); } \
  NS_IMETHOD MsSinceProcessStart(double *_retval) { return _to MsSinceProcessStart(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITELEMETRY(_to) \
  NS_IMETHOD GetHistogramSnapshots(JSContext* cx, JS::MutableHandleValue aHistogramSnapshots) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHistogramSnapshots(cx, aHistogramSnapshots); } \
  NS_IMETHOD GetLastShutdownDuration(uint32_t *aLastShutdownDuration) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastShutdownDuration(aLastShutdownDuration); } \
  NS_IMETHOD GetFailedProfileLockCount(uint32_t *aFailedProfileLockCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFailedProfileLockCount(aFailedProfileLockCount); } \
  NS_IMETHOD GetSlowSQL(JSContext* cx, JS::MutableHandleValue aSlowSQL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSlowSQL(cx, aSlowSQL); } \
  NS_IMETHOD GetDebugSlowSQL(JSContext* cx, JS::MutableHandleValue aDebugSlowSQL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDebugSlowSQL(cx, aDebugSlowSQL); } \
  NS_IMETHOD GetMaximalNumberOfConcurrentThreads(uint32_t *aMaximalNumberOfConcurrentThreads) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaximalNumberOfConcurrentThreads(aMaximalNumberOfConcurrentThreads); } \
  NS_IMETHOD GetChromeHangs(JSContext* cx, JS::MutableHandleValue aChromeHangs) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChromeHangs(cx, aChromeHangs); } \
  NS_IMETHOD GetThreadHangStats(JSContext* cx, JS::MutableHandleValue aThreadHangStats) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetThreadHangStats(cx, aThreadHangStats); } \
  NS_IMETHOD GetLateWrites(JSContext* cx, JS::MutableHandleValue aLateWrites) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLateWrites(cx, aLateWrites); } \
  NS_IMETHOD RegisteredHistograms(uint32_t *count, char * **histograms) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisteredHistograms(count, histograms); } \
  NS_IMETHOD NewHistogram(const nsACString & name, const nsACString & expiration, uint32_t min, uint32_t max, uint32_t bucket_count, uint32_t histogram_type, JSContext* cx, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewHistogram(name, expiration, min, max, bucket_count, histogram_type, cx, _retval); } \
  NS_IMETHOD HistogramFrom(const nsACString & name, const nsACString & existing_name, JSContext* cx, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HistogramFrom(name, existing_name, cx, _retval); } \
  NS_IMETHOD GetHistogramById(const nsACString & id, JSContext* cx, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHistogramById(id, cx, _retval); } \
  NS_IMETHOD GetCanRecord(bool *aCanRecord) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanRecord(aCanRecord); } \
  NS_IMETHOD SetCanRecord(bool aCanRecord) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCanRecord(aCanRecord); } \
  NS_IMETHOD GetCanSend(bool *aCanSend) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanSend(aCanSend); } \
  NS_IMETHOD RegisterAddonHistogram(const nsACString & addon_id, const nsACString & name, uint32_t min, uint32_t max, uint32_t bucket_count, uint32_t histogram_type) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterAddonHistogram(addon_id, name, min, max, bucket_count, histogram_type); } \
  NS_IMETHOD GetAddonHistogram(const nsACString & addon_id, const nsACString & name, JSContext* cx, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAddonHistogram(addon_id, name, cx, _retval); } \
  NS_IMETHOD UnregisterAddonHistograms(const nsACString & addon_id) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterAddonHistograms(addon_id); } \
  NS_IMETHOD GetAddonHistogramSnapshots(JSContext* cx, JS::MutableHandleValue aAddonHistogramSnapshots) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAddonHistogramSnapshots(cx, aAddonHistogramSnapshots); } \
  NS_IMETHOD AsyncFetchTelemetryData(nsIFetchTelemetryDataCallback *aCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncFetchTelemetryData(aCallback); } \
  NS_IMETHOD GetFileIOReports(JSContext* cx, JS::MutableHandleValue aFileIOReports) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileIOReports(cx, aFileIOReports); } \
  NS_IMETHOD MsSinceProcessStart(double *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MsSinceProcessStart(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTelemetry : public nsITelemetry
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITELEMETRY

  nsTelemetry();

private:
  ~nsTelemetry();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTelemetry, nsITelemetry)

nsTelemetry::nsTelemetry()
{
  /* member initializers and constructor code */
}

nsTelemetry::~nsTelemetry()
{
  /* destructor code */
}

/* [implicit_jscontext] readonly attribute jsval histogramSnapshots; */
NS_IMETHODIMP nsTelemetry::GetHistogramSnapshots(JSContext* cx, JS::MutableHandleValue aHistogramSnapshots)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t lastShutdownDuration; */
NS_IMETHODIMP nsTelemetry::GetLastShutdownDuration(uint32_t *aLastShutdownDuration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t failedProfileLockCount; */
NS_IMETHODIMP nsTelemetry::GetFailedProfileLockCount(uint32_t *aFailedProfileLockCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval slowSQL; */
NS_IMETHODIMP nsTelemetry::GetSlowSQL(JSContext* cx, JS::MutableHandleValue aSlowSQL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval debugSlowSQL; */
NS_IMETHODIMP nsTelemetry::GetDebugSlowSQL(JSContext* cx, JS::MutableHandleValue aDebugSlowSQL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t maximalNumberOfConcurrentThreads; */
NS_IMETHODIMP nsTelemetry::GetMaximalNumberOfConcurrentThreads(uint32_t *aMaximalNumberOfConcurrentThreads)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval chromeHangs; */
NS_IMETHODIMP nsTelemetry::GetChromeHangs(JSContext* cx, JS::MutableHandleValue aChromeHangs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval threadHangStats; */
NS_IMETHODIMP nsTelemetry::GetThreadHangStats(JSContext* cx, JS::MutableHandleValue aThreadHangStats)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval lateWrites; */
NS_IMETHODIMP nsTelemetry::GetLateWrites(JSContext* cx, JS::MutableHandleValue aLateWrites)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registeredHistograms (out uint32_t count, [array, size_is (count), retval] out string histograms); */
NS_IMETHODIMP nsTelemetry::RegisteredHistograms(uint32_t *count, char * **histograms)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval newHistogram (in ACString name, in ACString expiration, in uint32_t min, in uint32_t max, in uint32_t bucket_count, in unsigned long histogram_type); */
NS_IMETHODIMP nsTelemetry::NewHistogram(const nsACString & name, const nsACString & expiration, uint32_t min, uint32_t max, uint32_t bucket_count, uint32_t histogram_type, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval histogramFrom (in ACString name, in ACString existing_name); */
NS_IMETHODIMP nsTelemetry::HistogramFrom(const nsACString & name, const nsACString & existing_name, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getHistogramById (in ACString id); */
NS_IMETHODIMP nsTelemetry::GetHistogramById(const nsACString & id, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean canRecord; */
NS_IMETHODIMP nsTelemetry::GetCanRecord(bool *aCanRecord)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTelemetry::SetCanRecord(bool aCanRecord)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean canSend; */
NS_IMETHODIMP nsTelemetry::GetCanSend(bool *aCanSend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerAddonHistogram (in ACString addon_id, in ACString name, in uint32_t min, in uint32_t max, in uint32_t bucket_count, in unsigned long histogram_type); */
NS_IMETHODIMP nsTelemetry::RegisterAddonHistogram(const nsACString & addon_id, const nsACString & name, uint32_t min, uint32_t max, uint32_t bucket_count, uint32_t histogram_type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getAddonHistogram (in ACString addon_id, in ACString name); */
NS_IMETHODIMP nsTelemetry::GetAddonHistogram(const nsACString & addon_id, const nsACString & name, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterAddonHistograms (in ACString addon_id); */
NS_IMETHODIMP nsTelemetry::UnregisterAddonHistograms(const nsACString & addon_id)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval addonHistogramSnapshots; */
NS_IMETHODIMP nsTelemetry::GetAddonHistogramSnapshots(JSContext* cx, JS::MutableHandleValue aAddonHistogramSnapshots)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncFetchTelemetryData (in nsIFetchTelemetryDataCallback aCallback); */
NS_IMETHODIMP nsTelemetry::AsyncFetchTelemetryData(nsIFetchTelemetryDataCallback *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval fileIOReports; */
NS_IMETHODIMP nsTelemetry::GetFileIOReports(JSContext* cx, JS::MutableHandleValue aFileIOReports)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* double msSinceProcessStart (); */
NS_IMETHODIMP nsTelemetry::MsSinceProcessStart(double *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITelemetry_h__ */

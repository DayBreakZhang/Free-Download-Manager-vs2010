/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/toolkit/components/telemetry/nsITelemetry.idl
 */

#ifndef __gen_nsITelemetry_h__
#define __gen_nsITelemetry_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIFile_h__
#include "nsIFile.h"
#endif

#include "jspubtd.h"

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
#define NS_ITELEMETRY_IID_STR "e70ba4cc-7ccd-41fe-a75c-e4042233a8cb"

#define NS_ITELEMETRY_IID \
  {0xe70ba4cc, 0x7ccd, 0x41fe, \
    { 0xa7, 0x5c, 0xe4, 0x04, 0x22, 0x33, 0xa8, 0xcb }}

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
  NS_IMETHOD GetHistogramSnapshots(JSContext* cx, JS::Value *aHistogramSnapshots) = 0;

  /* readonly attribute uint32_t lastShutdownDuration; */
  NS_IMETHOD GetLastShutdownDuration(uint32_t *aLastShutdownDuration) = 0;

  /* readonly attribute uint32_t failedProfileLockCount; */
  NS_IMETHOD GetFailedProfileLockCount(uint32_t *aFailedProfileLockCount) = 0;

  /* [implicit_jscontext] readonly attribute jsval slowSQL; */
  NS_IMETHOD GetSlowSQL(JSContext* cx, JS::Value *aSlowSQL) = 0;

  /* [implicit_jscontext] readonly attribute jsval debugSlowSQL; */
  NS_IMETHOD GetDebugSlowSQL(JSContext* cx, JS::Value *aDebugSlowSQL) = 0;

  /* [implicit_jscontext] readonly attribute jsval chromeHangs; */
  NS_IMETHOD GetChromeHangs(JSContext* cx, JS::Value *aChromeHangs) = 0;

  /* [implicit_jscontext] readonly attribute jsval lateWrites; */
  NS_IMETHOD GetLateWrites(JSContext* cx, JS::Value *aLateWrites) = 0;

  /* [implicit_jscontext] readonly attribute jsval registeredHistograms; */
  NS_IMETHOD GetRegisteredHistograms(JSContext* cx, JS::Value *aRegisteredHistograms) = 0;

  /* [implicit_jscontext] jsval newHistogram (in ACString name, in uint32_t min, in uint32_t max, in uint32_t bucket_count, in unsigned long histogram_type); */
  NS_IMETHOD NewHistogram(const nsACString & name, uint32_t min, uint32_t max, uint32_t bucket_count, uint32_t histogram_type, JSContext* cx, JS::Value *_retval) = 0;

  /* [implicit_jscontext] jsval histogramFrom (in ACString name, in ACString existing_name); */
  NS_IMETHOD HistogramFrom(const nsACString & name, const nsACString & existing_name, JSContext* cx, JS::Value *_retval) = 0;

  /* [implicit_jscontext] jsval getHistogramById (in ACString id); */
  NS_IMETHOD GetHistogramById(const nsACString & id, JSContext* cx, JS::Value *_retval) = 0;

  /* attribute boolean canRecord; */
  NS_IMETHOD GetCanRecord(bool *aCanRecord) = 0;
  NS_IMETHOD SetCanRecord(bool aCanRecord) = 0;

  /* readonly attribute boolean canSend; */
  NS_IMETHOD GetCanSend(bool *aCanSend) = 0;

  /* void registerAddonHistogram (in ACString addon_id, in ACString name, in uint32_t min, in uint32_t max, in uint32_t bucket_count, in unsigned long histogram_type); */
  NS_IMETHOD RegisterAddonHistogram(const nsACString & addon_id, const nsACString & name, uint32_t min, uint32_t max, uint32_t bucket_count, uint32_t histogram_type) = 0;

  /* [implicit_jscontext] jsval getAddonHistogram (in ACString addon_id, in ACString name); */
  NS_IMETHOD GetAddonHistogram(const nsACString & addon_id, const nsACString & name, JSContext* cx, JS::Value *_retval) = 0;

  /* void unregisterAddonHistograms (in ACString addon_id); */
  NS_IMETHOD UnregisterAddonHistograms(const nsACString & addon_id) = 0;

  /* [implicit_jscontext] readonly attribute jsval addonHistogramSnapshots; */
  NS_IMETHOD GetAddonHistogramSnapshots(JSContext* cx, JS::Value *aAddonHistogramSnapshots) = 0;

  /* void asyncFetchTelemetryData (in nsIFetchTelemetryDataCallback aCallback); */
  NS_IMETHOD AsyncFetchTelemetryData(nsIFetchTelemetryDataCallback *aCallback) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITelemetry, NS_ITELEMETRY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITELEMETRY \
  NS_IMETHOD GetHistogramSnapshots(JSContext* cx, JS::Value *aHistogramSnapshots); \
  NS_IMETHOD GetLastShutdownDuration(uint32_t *aLastShutdownDuration); \
  NS_IMETHOD GetFailedProfileLockCount(uint32_t *aFailedProfileLockCount); \
  NS_IMETHOD GetSlowSQL(JSContext* cx, JS::Value *aSlowSQL); \
  NS_IMETHOD GetDebugSlowSQL(JSContext* cx, JS::Value *aDebugSlowSQL); \
  NS_IMETHOD GetChromeHangs(JSContext* cx, JS::Value *aChromeHangs); \
  NS_IMETHOD GetLateWrites(JSContext* cx, JS::Value *aLateWrites); \
  NS_IMETHOD GetRegisteredHistograms(JSContext* cx, JS::Value *aRegisteredHistograms); \
  NS_IMETHOD NewHistogram(const nsACString & name, uint32_t min, uint32_t max, uint32_t bucket_count, uint32_t histogram_type, JSContext* cx, JS::Value *_retval); \
  NS_IMETHOD HistogramFrom(const nsACString & name, const nsACString & existing_name, JSContext* cx, JS::Value *_retval); \
  NS_IMETHOD GetHistogramById(const nsACString & id, JSContext* cx, JS::Value *_retval); \
  NS_IMETHOD GetCanRecord(bool *aCanRecord); \
  NS_IMETHOD SetCanRecord(bool aCanRecord); \
  NS_IMETHOD GetCanSend(bool *aCanSend); \
  NS_IMETHOD RegisterAddonHistogram(const nsACString & addon_id, const nsACString & name, uint32_t min, uint32_t max, uint32_t bucket_count, uint32_t histogram_type); \
  NS_IMETHOD GetAddonHistogram(const nsACString & addon_id, const nsACString & name, JSContext* cx, JS::Value *_retval); \
  NS_IMETHOD UnregisterAddonHistograms(const nsACString & addon_id); \
  NS_IMETHOD GetAddonHistogramSnapshots(JSContext* cx, JS::Value *aAddonHistogramSnapshots); \
  NS_IMETHOD AsyncFetchTelemetryData(nsIFetchTelemetryDataCallback *aCallback); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITELEMETRY(_to) \
  NS_IMETHOD GetHistogramSnapshots(JSContext* cx, JS::Value *aHistogramSnapshots) { return _to GetHistogramSnapshots(cx, aHistogramSnapshots); } \
  NS_IMETHOD GetLastShutdownDuration(uint32_t *aLastShutdownDuration) { return _to GetLastShutdownDuration(aLastShutdownDuration); } \
  NS_IMETHOD GetFailedProfileLockCount(uint32_t *aFailedProfileLockCount) { return _to GetFailedProfileLockCount(aFailedProfileLockCount); } \
  NS_IMETHOD GetSlowSQL(JSContext* cx, JS::Value *aSlowSQL) { return _to GetSlowSQL(cx, aSlowSQL); } \
  NS_IMETHOD GetDebugSlowSQL(JSContext* cx, JS::Value *aDebugSlowSQL) { return _to GetDebugSlowSQL(cx, aDebugSlowSQL); } \
  NS_IMETHOD GetChromeHangs(JSContext* cx, JS::Value *aChromeHangs) { return _to GetChromeHangs(cx, aChromeHangs); } \
  NS_IMETHOD GetLateWrites(JSContext* cx, JS::Value *aLateWrites) { return _to GetLateWrites(cx, aLateWrites); } \
  NS_IMETHOD GetRegisteredHistograms(JSContext* cx, JS::Value *aRegisteredHistograms) { return _to GetRegisteredHistograms(cx, aRegisteredHistograms); } \
  NS_IMETHOD NewHistogram(const nsACString & name, uint32_t min, uint32_t max, uint32_t bucket_count, uint32_t histogram_type, JSContext* cx, JS::Value *_retval) { return _to NewHistogram(name, min, max, bucket_count, histogram_type, cx, _retval); } \
  NS_IMETHOD HistogramFrom(const nsACString & name, const nsACString & existing_name, JSContext* cx, JS::Value *_retval) { return _to HistogramFrom(name, existing_name, cx, _retval); } \
  NS_IMETHOD GetHistogramById(const nsACString & id, JSContext* cx, JS::Value *_retval) { return _to GetHistogramById(id, cx, _retval); } \
  NS_IMETHOD GetCanRecord(bool *aCanRecord) { return _to GetCanRecord(aCanRecord); } \
  NS_IMETHOD SetCanRecord(bool aCanRecord) { return _to SetCanRecord(aCanRecord); } \
  NS_IMETHOD GetCanSend(bool *aCanSend) { return _to GetCanSend(aCanSend); } \
  NS_IMETHOD RegisterAddonHistogram(const nsACString & addon_id, const nsACString & name, uint32_t min, uint32_t max, uint32_t bucket_count, uint32_t histogram_type) { return _to RegisterAddonHistogram(addon_id, name, min, max, bucket_count, histogram_type); } \
  NS_IMETHOD GetAddonHistogram(const nsACString & addon_id, const nsACString & name, JSContext* cx, JS::Value *_retval) { return _to GetAddonHistogram(addon_id, name, cx, _retval); } \
  NS_IMETHOD UnregisterAddonHistograms(const nsACString & addon_id) { return _to UnregisterAddonHistograms(addon_id); } \
  NS_IMETHOD GetAddonHistogramSnapshots(JSContext* cx, JS::Value *aAddonHistogramSnapshots) { return _to GetAddonHistogramSnapshots(cx, aAddonHistogramSnapshots); } \
  NS_IMETHOD AsyncFetchTelemetryData(nsIFetchTelemetryDataCallback *aCallback) { return _to AsyncFetchTelemetryData(aCallback); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITELEMETRY(_to) \
  NS_IMETHOD GetHistogramSnapshots(JSContext* cx, JS::Value *aHistogramSnapshots) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHistogramSnapshots(cx, aHistogramSnapshots); } \
  NS_IMETHOD GetLastShutdownDuration(uint32_t *aLastShutdownDuration) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastShutdownDuration(aLastShutdownDuration); } \
  NS_IMETHOD GetFailedProfileLockCount(uint32_t *aFailedProfileLockCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFailedProfileLockCount(aFailedProfileLockCount); } \
  NS_IMETHOD GetSlowSQL(JSContext* cx, JS::Value *aSlowSQL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSlowSQL(cx, aSlowSQL); } \
  NS_IMETHOD GetDebugSlowSQL(JSContext* cx, JS::Value *aDebugSlowSQL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDebugSlowSQL(cx, aDebugSlowSQL); } \
  NS_IMETHOD GetChromeHangs(JSContext* cx, JS::Value *aChromeHangs) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChromeHangs(cx, aChromeHangs); } \
  NS_IMETHOD GetLateWrites(JSContext* cx, JS::Value *aLateWrites) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLateWrites(cx, aLateWrites); } \
  NS_IMETHOD GetRegisteredHistograms(JSContext* cx, JS::Value *aRegisteredHistograms) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRegisteredHistograms(cx, aRegisteredHistograms); } \
  NS_IMETHOD NewHistogram(const nsACString & name, uint32_t min, uint32_t max, uint32_t bucket_count, uint32_t histogram_type, JSContext* cx, JS::Value *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewHistogram(name, min, max, bucket_count, histogram_type, cx, _retval); } \
  NS_IMETHOD HistogramFrom(const nsACString & name, const nsACString & existing_name, JSContext* cx, JS::Value *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HistogramFrom(name, existing_name, cx, _retval); } \
  NS_IMETHOD GetHistogramById(const nsACString & id, JSContext* cx, JS::Value *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHistogramById(id, cx, _retval); } \
  NS_IMETHOD GetCanRecord(bool *aCanRecord) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanRecord(aCanRecord); } \
  NS_IMETHOD SetCanRecord(bool aCanRecord) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCanRecord(aCanRecord); } \
  NS_IMETHOD GetCanSend(bool *aCanSend) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanSend(aCanSend); } \
  NS_IMETHOD RegisterAddonHistogram(const nsACString & addon_id, const nsACString & name, uint32_t min, uint32_t max, uint32_t bucket_count, uint32_t histogram_type) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterAddonHistogram(addon_id, name, min, max, bucket_count, histogram_type); } \
  NS_IMETHOD GetAddonHistogram(const nsACString & addon_id, const nsACString & name, JSContext* cx, JS::Value *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAddonHistogram(addon_id, name, cx, _retval); } \
  NS_IMETHOD UnregisterAddonHistograms(const nsACString & addon_id) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterAddonHistograms(addon_id); } \
  NS_IMETHOD GetAddonHistogramSnapshots(JSContext* cx, JS::Value *aAddonHistogramSnapshots) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAddonHistogramSnapshots(cx, aAddonHistogramSnapshots); } \
  NS_IMETHOD AsyncFetchTelemetryData(nsIFetchTelemetryDataCallback *aCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncFetchTelemetryData(aCallback); } 

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
NS_IMETHODIMP nsTelemetry::GetHistogramSnapshots(JSContext* cx, JS::Value *aHistogramSnapshots)
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
NS_IMETHODIMP nsTelemetry::GetSlowSQL(JSContext* cx, JS::Value *aSlowSQL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval debugSlowSQL; */
NS_IMETHODIMP nsTelemetry::GetDebugSlowSQL(JSContext* cx, JS::Value *aDebugSlowSQL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval chromeHangs; */
NS_IMETHODIMP nsTelemetry::GetChromeHangs(JSContext* cx, JS::Value *aChromeHangs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval lateWrites; */
NS_IMETHODIMP nsTelemetry::GetLateWrites(JSContext* cx, JS::Value *aLateWrites)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval registeredHistograms; */
NS_IMETHODIMP nsTelemetry::GetRegisteredHistograms(JSContext* cx, JS::Value *aRegisteredHistograms)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval newHistogram (in ACString name, in uint32_t min, in uint32_t max, in uint32_t bucket_count, in unsigned long histogram_type); */
NS_IMETHODIMP nsTelemetry::NewHistogram(const nsACString & name, uint32_t min, uint32_t max, uint32_t bucket_count, uint32_t histogram_type, JSContext* cx, JS::Value *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval histogramFrom (in ACString name, in ACString existing_name); */
NS_IMETHODIMP nsTelemetry::HistogramFrom(const nsACString & name, const nsACString & existing_name, JSContext* cx, JS::Value *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getHistogramById (in ACString id); */
NS_IMETHODIMP nsTelemetry::GetHistogramById(const nsACString & id, JSContext* cx, JS::Value *_retval)
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
NS_IMETHODIMP nsTelemetry::GetAddonHistogram(const nsACString & addon_id, const nsACString & name, JSContext* cx, JS::Value *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterAddonHistograms (in ACString addon_id); */
NS_IMETHODIMP nsTelemetry::UnregisterAddonHistograms(const nsACString & addon_id)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval addonHistogramSnapshots; */
NS_IMETHODIMP nsTelemetry::GetAddonHistogramSnapshots(JSContext* cx, JS::Value *aAddonHistogramSnapshots)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncFetchTelemetryData (in nsIFetchTelemetryDataCallback aCallback); */
NS_IMETHODIMP nsTelemetry::AsyncFetchTelemetryData(nsIFetchTelemetryDataCallback *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITelemetry_h__ */

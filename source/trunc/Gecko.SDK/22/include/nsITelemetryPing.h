/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/toolkit/components/telemetry/nsITelemetryPing.idl
 */

#ifndef __gen_nsITelemetryPing_h__
#define __gen_nsITelemetryPing_h__


#ifndef __gen_nsIObserver_h__
#include "nsIObserver.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */


/* starting interface:    nsITelemetryPing */
#define NS_ITELEMETRYPING_IID_STR "37fb32f5-d5ed-45e3-8feb-fa085935e732"

#define NS_ITELEMETRYPING_IID \
  {0x37fb32f5, 0xd5ed, 0x45e3, \
    { 0x8f, 0xeb, 0xfa, 0x08, 0x59, 0x35, 0xe7, 0x32 }}

class NS_NO_VTABLE nsITelemetryPing : public nsIObserver {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITELEMETRYPING_IID)

  /* jsval getPayload (); */
  NS_IMETHOD GetPayload(JS::Value *_retval) = 0;

  /* void saveHistograms (in nsIFile aFile, in boolean aSync); */
  NS_IMETHOD SaveHistograms(nsIFile *aFile, bool aSync) = 0;

  /* void gatherStartup (); */
  NS_IMETHOD GatherStartup(void) = 0;

  /* void enableLoadSaveNotifications (); */
  NS_IMETHOD EnableLoadSaveNotifications(void) = 0;

  /* void cacheProfileDirectory (); */
  NS_IMETHOD CacheProfileDirectory(void) = 0;

  /* void setAddOns (in AString aAddOns); */
  NS_IMETHOD SetAddOns(const nsAString & aAddOns) = 0;

  /* void testPing (in AString aServer); */
  NS_IMETHOD TestPing(const nsAString & aServer) = 0;

  /* void testLoadHistograms (in nsIFile aFile, in boolean aSync); */
  NS_IMETHOD TestLoadHistograms(nsIFile *aFile, bool aSync) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITelemetryPing, NS_ITELEMETRYPING_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITELEMETRYPING \
  NS_IMETHOD GetPayload(JS::Value *_retval); \
  NS_IMETHOD SaveHistograms(nsIFile *aFile, bool aSync); \
  NS_IMETHOD GatherStartup(void); \
  NS_IMETHOD EnableLoadSaveNotifications(void); \
  NS_IMETHOD CacheProfileDirectory(void); \
  NS_IMETHOD SetAddOns(const nsAString & aAddOns); \
  NS_IMETHOD TestPing(const nsAString & aServer); \
  NS_IMETHOD TestLoadHistograms(nsIFile *aFile, bool aSync); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITELEMETRYPING(_to) \
  NS_IMETHOD GetPayload(JS::Value *_retval) { return _to GetPayload(_retval); } \
  NS_IMETHOD SaveHistograms(nsIFile *aFile, bool aSync) { return _to SaveHistograms(aFile, aSync); } \
  NS_IMETHOD GatherStartup(void) { return _to GatherStartup(); } \
  NS_IMETHOD EnableLoadSaveNotifications(void) { return _to EnableLoadSaveNotifications(); } \
  NS_IMETHOD CacheProfileDirectory(void) { return _to CacheProfileDirectory(); } \
  NS_IMETHOD SetAddOns(const nsAString & aAddOns) { return _to SetAddOns(aAddOns); } \
  NS_IMETHOD TestPing(const nsAString & aServer) { return _to TestPing(aServer); } \
  NS_IMETHOD TestLoadHistograms(nsIFile *aFile, bool aSync) { return _to TestLoadHistograms(aFile, aSync); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITELEMETRYPING(_to) \
  NS_IMETHOD GetPayload(JS::Value *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPayload(_retval); } \
  NS_IMETHOD SaveHistograms(nsIFile *aFile, bool aSync) { return !_to ? NS_ERROR_NULL_POINTER : _to->SaveHistograms(aFile, aSync); } \
  NS_IMETHOD GatherStartup(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GatherStartup(); } \
  NS_IMETHOD EnableLoadSaveNotifications(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableLoadSaveNotifications(); } \
  NS_IMETHOD CacheProfileDirectory(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CacheProfileDirectory(); } \
  NS_IMETHOD SetAddOns(const nsAString & aAddOns) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAddOns(aAddOns); } \
  NS_IMETHOD TestPing(const nsAString & aServer) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestPing(aServer); } \
  NS_IMETHOD TestLoadHistograms(nsIFile *aFile, bool aSync) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestLoadHistograms(aFile, aSync); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTelemetryPing : public nsITelemetryPing
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITELEMETRYPING

  nsTelemetryPing();

private:
  ~nsTelemetryPing();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTelemetryPing, nsITelemetryPing)

nsTelemetryPing::nsTelemetryPing()
{
  /* member initializers and constructor code */
}

nsTelemetryPing::~nsTelemetryPing()
{
  /* destructor code */
}

/* jsval getPayload (); */
NS_IMETHODIMP nsTelemetryPing::GetPayload(JS::Value *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void saveHistograms (in nsIFile aFile, in boolean aSync); */
NS_IMETHODIMP nsTelemetryPing::SaveHistograms(nsIFile *aFile, bool aSync)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void gatherStartup (); */
NS_IMETHODIMP nsTelemetryPing::GatherStartup()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enableLoadSaveNotifications (); */
NS_IMETHODIMP nsTelemetryPing::EnableLoadSaveNotifications()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cacheProfileDirectory (); */
NS_IMETHODIMP nsTelemetryPing::CacheProfileDirectory()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAddOns (in AString aAddOns); */
NS_IMETHODIMP nsTelemetryPing::SetAddOns(const nsAString & aAddOns)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void testPing (in AString aServer); */
NS_IMETHODIMP nsTelemetryPing::TestPing(const nsAString & aServer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void testLoadHistograms (in nsIFile aFile, in boolean aSync); */
NS_IMETHODIMP nsTelemetryPing::TestLoadHistograms(nsIFile *aFile, bool aSync)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITelemetryPing_h__ */

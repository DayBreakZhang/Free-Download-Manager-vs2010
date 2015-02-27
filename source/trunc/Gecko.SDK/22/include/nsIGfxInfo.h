/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/widget/nsIGfxInfo.idl
 */

#ifndef __gen_nsIGfxInfo_h__
#define __gen_nsIGfxInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIGfxInfo */
#define NS_IGFXINFO_IID_STR "8a9797ae-22d4-431d-a628-18fd5900c53c"

#define NS_IGFXINFO_IID \
  {0x8a9797ae, 0x22d4, 0x431d, \
    { 0xa6, 0x28, 0x18, 0xfd, 0x59, 0x00, 0xc5, 0x3c }}

class NS_NO_VTABLE nsIGfxInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGFXINFO_IID)

  /* readonly attribute boolean D2DEnabled; */
  NS_IMETHOD GetD2DEnabled(bool *aD2DEnabled) = 0;

  /* readonly attribute boolean DWriteEnabled; */
  NS_IMETHOD GetDWriteEnabled(bool *aDWriteEnabled) = 0;

  /* readonly attribute DOMString DWriteVersion; */
  NS_IMETHOD GetDWriteVersion(nsAString & aDWriteVersion) = 0;

  /* readonly attribute DOMString cleartypeParameters; */
  NS_IMETHOD GetCleartypeParameters(nsAString & aCleartypeParameters) = 0;

  /* readonly attribute DOMString adapterDescription; */
  NS_IMETHOD GetAdapterDescription(nsAString & aAdapterDescription) = 0;

  /* readonly attribute DOMString adapterDescription2; */
  NS_IMETHOD GetAdapterDescription2(nsAString & aAdapterDescription2) = 0;

  /* readonly attribute DOMString adapterDriver; */
  NS_IMETHOD GetAdapterDriver(nsAString & aAdapterDriver) = 0;

  /* readonly attribute DOMString adapterDriver2; */
  NS_IMETHOD GetAdapterDriver2(nsAString & aAdapterDriver2) = 0;

  /* readonly attribute DOMString adapterVendorID; */
  NS_IMETHOD GetAdapterVendorID(nsAString & aAdapterVendorID) = 0;

  /* readonly attribute DOMString adapterVendorID2; */
  NS_IMETHOD GetAdapterVendorID2(nsAString & aAdapterVendorID2) = 0;

  /* readonly attribute DOMString adapterDeviceID; */
  NS_IMETHOD GetAdapterDeviceID(nsAString & aAdapterDeviceID) = 0;

  /* readonly attribute DOMString adapterDeviceID2; */
  NS_IMETHOD GetAdapterDeviceID2(nsAString & aAdapterDeviceID2) = 0;

  /* readonly attribute DOMString adapterRAM; */
  NS_IMETHOD GetAdapterRAM(nsAString & aAdapterRAM) = 0;

  /* readonly attribute DOMString adapterRAM2; */
  NS_IMETHOD GetAdapterRAM2(nsAString & aAdapterRAM2) = 0;

  /* readonly attribute DOMString adapterDriverVersion; */
  NS_IMETHOD GetAdapterDriverVersion(nsAString & aAdapterDriverVersion) = 0;

  /* readonly attribute DOMString adapterDriverVersion2; */
  NS_IMETHOD GetAdapterDriverVersion2(nsAString & aAdapterDriverVersion2) = 0;

  /* readonly attribute DOMString adapterDriverDate; */
  NS_IMETHOD GetAdapterDriverDate(nsAString & aAdapterDriverDate) = 0;

  /* readonly attribute DOMString adapterDriverDate2; */
  NS_IMETHOD GetAdapterDriverDate2(nsAString & aAdapterDriverDate2) = 0;

  /* readonly attribute boolean isGPU2Active; */
  NS_IMETHOD GetIsGPU2Active(bool *aIsGPU2Active) = 0;

  /* void getFailures ([optional] out unsigned long failureCount, [array, size_is (failureCount), retval] out string failures); */
  NS_IMETHOD GetFailures(uint32_t *failureCount, char * **failures) = 0;

  /* [noscript,notxpcom] void logFailure (in ACString failure); */
  NS_IMETHOD_(void) LogFailure(const nsACString & failure) = 0;

  enum {
    FEATURE_DIRECT2D = 1,
    FEATURE_DIRECT3D_9_LAYERS = 2,
    FEATURE_DIRECT3D_10_LAYERS = 3,
    FEATURE_DIRECT3D_10_1_LAYERS = 4,
    FEATURE_OPENGL_LAYERS = 5,
    FEATURE_WEBGL_OPENGL = 6,
    FEATURE_WEBGL_ANGLE = 7,
    FEATURE_WEBGL_MSAA = 8,
    FEATURE_STAGEFRIGHT = 9,
    FEATURE_NO_INFO = 1,
    FEATURE_STATUS_UNKNOWN = 2,
    FEATURE_BLOCKED_DRIVER_VERSION = 3,
    FEATURE_BLOCKED_DEVICE = 4,
    FEATURE_DISCOURAGED = 5,
    FEATURE_BLOCKED_OS_VERSION = 6
  };

  /* long getFeatureStatus (in long aFeature); */
  NS_IMETHOD GetFeatureStatus(int32_t aFeature, int32_t *_retval) = 0;

  /* DOMString getFeatureSuggestedDriverVersion (in long aFeature); */
  NS_IMETHOD GetFeatureSuggestedDriverVersion(int32_t aFeature, nsAString & _retval) = 0;

  /* DOMString getWebGLParameter (in DOMString aParam); */
  NS_IMETHOD GetWebGLParameter(const nsAString & aParam, nsAString & _retval) = 0;

  /* [noscript,notxpcom] void GetData (); */
  NS_IMETHOD_(void) GetData(void) = 0;

  /* [implicit_jscontext] jsval getInfo (); */
  NS_IMETHOD GetInfo(JSContext* cx, JS::Value *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGfxInfo, NS_IGFXINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGFXINFO \
  NS_IMETHOD GetD2DEnabled(bool *aD2DEnabled); \
  NS_IMETHOD GetDWriteEnabled(bool *aDWriteEnabled); \
  NS_IMETHOD GetDWriteVersion(nsAString & aDWriteVersion); \
  NS_IMETHOD GetCleartypeParameters(nsAString & aCleartypeParameters); \
  NS_IMETHOD GetAdapterDescription(nsAString & aAdapterDescription); \
  NS_IMETHOD GetAdapterDescription2(nsAString & aAdapterDescription2); \
  NS_IMETHOD GetAdapterDriver(nsAString & aAdapterDriver); \
  NS_IMETHOD GetAdapterDriver2(nsAString & aAdapterDriver2); \
  NS_IMETHOD GetAdapterVendorID(nsAString & aAdapterVendorID); \
  NS_IMETHOD GetAdapterVendorID2(nsAString & aAdapterVendorID2); \
  NS_IMETHOD GetAdapterDeviceID(nsAString & aAdapterDeviceID); \
  NS_IMETHOD GetAdapterDeviceID2(nsAString & aAdapterDeviceID2); \
  NS_IMETHOD GetAdapterRAM(nsAString & aAdapterRAM); \
  NS_IMETHOD GetAdapterRAM2(nsAString & aAdapterRAM2); \
  NS_IMETHOD GetAdapterDriverVersion(nsAString & aAdapterDriverVersion); \
  NS_IMETHOD GetAdapterDriverVersion2(nsAString & aAdapterDriverVersion2); \
  NS_IMETHOD GetAdapterDriverDate(nsAString & aAdapterDriverDate); \
  NS_IMETHOD GetAdapterDriverDate2(nsAString & aAdapterDriverDate2); \
  NS_IMETHOD GetIsGPU2Active(bool *aIsGPU2Active); \
  NS_IMETHOD GetFailures(uint32_t *failureCount, char * **failures); \
  NS_IMETHOD_(void) LogFailure(const nsACString & failure); \
  NS_IMETHOD GetFeatureStatus(int32_t aFeature, int32_t *_retval); \
  NS_IMETHOD GetFeatureSuggestedDriverVersion(int32_t aFeature, nsAString & _retval); \
  NS_IMETHOD GetWebGLParameter(const nsAString & aParam, nsAString & _retval); \
  NS_IMETHOD_(void) GetData(void); \
  NS_IMETHOD GetInfo(JSContext* cx, JS::Value *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGFXINFO(_to) \
  NS_IMETHOD GetD2DEnabled(bool *aD2DEnabled) { return _to GetD2DEnabled(aD2DEnabled); } \
  NS_IMETHOD GetDWriteEnabled(bool *aDWriteEnabled) { return _to GetDWriteEnabled(aDWriteEnabled); } \
  NS_IMETHOD GetDWriteVersion(nsAString & aDWriteVersion) { return _to GetDWriteVersion(aDWriteVersion); } \
  NS_IMETHOD GetCleartypeParameters(nsAString & aCleartypeParameters) { return _to GetCleartypeParameters(aCleartypeParameters); } \
  NS_IMETHOD GetAdapterDescription(nsAString & aAdapterDescription) { return _to GetAdapterDescription(aAdapterDescription); } \
  NS_IMETHOD GetAdapterDescription2(nsAString & aAdapterDescription2) { return _to GetAdapterDescription2(aAdapterDescription2); } \
  NS_IMETHOD GetAdapterDriver(nsAString & aAdapterDriver) { return _to GetAdapterDriver(aAdapterDriver); } \
  NS_IMETHOD GetAdapterDriver2(nsAString & aAdapterDriver2) { return _to GetAdapterDriver2(aAdapterDriver2); } \
  NS_IMETHOD GetAdapterVendorID(nsAString & aAdapterVendorID) { return _to GetAdapterVendorID(aAdapterVendorID); } \
  NS_IMETHOD GetAdapterVendorID2(nsAString & aAdapterVendorID2) { return _to GetAdapterVendorID2(aAdapterVendorID2); } \
  NS_IMETHOD GetAdapterDeviceID(nsAString & aAdapterDeviceID) { return _to GetAdapterDeviceID(aAdapterDeviceID); } \
  NS_IMETHOD GetAdapterDeviceID2(nsAString & aAdapterDeviceID2) { return _to GetAdapterDeviceID2(aAdapterDeviceID2); } \
  NS_IMETHOD GetAdapterRAM(nsAString & aAdapterRAM) { return _to GetAdapterRAM(aAdapterRAM); } \
  NS_IMETHOD GetAdapterRAM2(nsAString & aAdapterRAM2) { return _to GetAdapterRAM2(aAdapterRAM2); } \
  NS_IMETHOD GetAdapterDriverVersion(nsAString & aAdapterDriverVersion) { return _to GetAdapterDriverVersion(aAdapterDriverVersion); } \
  NS_IMETHOD GetAdapterDriverVersion2(nsAString & aAdapterDriverVersion2) { return _to GetAdapterDriverVersion2(aAdapterDriverVersion2); } \
  NS_IMETHOD GetAdapterDriverDate(nsAString & aAdapterDriverDate) { return _to GetAdapterDriverDate(aAdapterDriverDate); } \
  NS_IMETHOD GetAdapterDriverDate2(nsAString & aAdapterDriverDate2) { return _to GetAdapterDriverDate2(aAdapterDriverDate2); } \
  NS_IMETHOD GetIsGPU2Active(bool *aIsGPU2Active) { return _to GetIsGPU2Active(aIsGPU2Active); } \
  NS_IMETHOD GetFailures(uint32_t *failureCount, char * **failures) { return _to GetFailures(failureCount, failures); } \
  NS_IMETHOD_(void) LogFailure(const nsACString & failure) { return _to LogFailure(failure); } \
  NS_IMETHOD GetFeatureStatus(int32_t aFeature, int32_t *_retval) { return _to GetFeatureStatus(aFeature, _retval); } \
  NS_IMETHOD GetFeatureSuggestedDriverVersion(int32_t aFeature, nsAString & _retval) { return _to GetFeatureSuggestedDriverVersion(aFeature, _retval); } \
  NS_IMETHOD GetWebGLParameter(const nsAString & aParam, nsAString & _retval) { return _to GetWebGLParameter(aParam, _retval); } \
  NS_IMETHOD_(void) GetData(void) { return _to GetData(); } \
  NS_IMETHOD GetInfo(JSContext* cx, JS::Value *_retval) { return _to GetInfo(cx, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGFXINFO(_to) \
  NS_IMETHOD GetD2DEnabled(bool *aD2DEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetD2DEnabled(aD2DEnabled); } \
  NS_IMETHOD GetDWriteEnabled(bool *aDWriteEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDWriteEnabled(aDWriteEnabled); } \
  NS_IMETHOD GetDWriteVersion(nsAString & aDWriteVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDWriteVersion(aDWriteVersion); } \
  NS_IMETHOD GetCleartypeParameters(nsAString & aCleartypeParameters) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCleartypeParameters(aCleartypeParameters); } \
  NS_IMETHOD GetAdapterDescription(nsAString & aAdapterDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdapterDescription(aAdapterDescription); } \
  NS_IMETHOD GetAdapterDescription2(nsAString & aAdapterDescription2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdapterDescription2(aAdapterDescription2); } \
  NS_IMETHOD GetAdapterDriver(nsAString & aAdapterDriver) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdapterDriver(aAdapterDriver); } \
  NS_IMETHOD GetAdapterDriver2(nsAString & aAdapterDriver2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdapterDriver2(aAdapterDriver2); } \
  NS_IMETHOD GetAdapterVendorID(nsAString & aAdapterVendorID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdapterVendorID(aAdapterVendorID); } \
  NS_IMETHOD GetAdapterVendorID2(nsAString & aAdapterVendorID2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdapterVendorID2(aAdapterVendorID2); } \
  NS_IMETHOD GetAdapterDeviceID(nsAString & aAdapterDeviceID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdapterDeviceID(aAdapterDeviceID); } \
  NS_IMETHOD GetAdapterDeviceID2(nsAString & aAdapterDeviceID2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdapterDeviceID2(aAdapterDeviceID2); } \
  NS_IMETHOD GetAdapterRAM(nsAString & aAdapterRAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdapterRAM(aAdapterRAM); } \
  NS_IMETHOD GetAdapterRAM2(nsAString & aAdapterRAM2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdapterRAM2(aAdapterRAM2); } \
  NS_IMETHOD GetAdapterDriverVersion(nsAString & aAdapterDriverVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdapterDriverVersion(aAdapterDriverVersion); } \
  NS_IMETHOD GetAdapterDriverVersion2(nsAString & aAdapterDriverVersion2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdapterDriverVersion2(aAdapterDriverVersion2); } \
  NS_IMETHOD GetAdapterDriverDate(nsAString & aAdapterDriverDate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdapterDriverDate(aAdapterDriverDate); } \
  NS_IMETHOD GetAdapterDriverDate2(nsAString & aAdapterDriverDate2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdapterDriverDate2(aAdapterDriverDate2); } \
  NS_IMETHOD GetIsGPU2Active(bool *aIsGPU2Active) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsGPU2Active(aIsGPU2Active); } \
  NS_IMETHOD GetFailures(uint32_t *failureCount, char * **failures) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFailures(failureCount, failures); } \
  NS_IMETHOD_(void) LogFailure(const nsACString & failure); \
  NS_IMETHOD GetFeatureStatus(int32_t aFeature, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFeatureStatus(aFeature, _retval); } \
  NS_IMETHOD GetFeatureSuggestedDriverVersion(int32_t aFeature, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFeatureSuggestedDriverVersion(aFeature, _retval); } \
  NS_IMETHOD GetWebGLParameter(const nsAString & aParam, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWebGLParameter(aParam, _retval); } \
  NS_IMETHOD_(void) GetData(void); \
  NS_IMETHOD GetInfo(JSContext* cx, JS::Value *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInfo(cx, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGfxInfo : public nsIGfxInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGFXINFO

  nsGfxInfo();

private:
  ~nsGfxInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsGfxInfo, nsIGfxInfo)

nsGfxInfo::nsGfxInfo()
{
  /* member initializers and constructor code */
}

nsGfxInfo::~nsGfxInfo()
{
  /* destructor code */
}

/* readonly attribute boolean D2DEnabled; */
NS_IMETHODIMP nsGfxInfo::GetD2DEnabled(bool *aD2DEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean DWriteEnabled; */
NS_IMETHODIMP nsGfxInfo::GetDWriteEnabled(bool *aDWriteEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString DWriteVersion; */
NS_IMETHODIMP nsGfxInfo::GetDWriteVersion(nsAString & aDWriteVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString cleartypeParameters; */
NS_IMETHODIMP nsGfxInfo::GetCleartypeParameters(nsAString & aCleartypeParameters)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString adapterDescription; */
NS_IMETHODIMP nsGfxInfo::GetAdapterDescription(nsAString & aAdapterDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString adapterDescription2; */
NS_IMETHODIMP nsGfxInfo::GetAdapterDescription2(nsAString & aAdapterDescription2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString adapterDriver; */
NS_IMETHODIMP nsGfxInfo::GetAdapterDriver(nsAString & aAdapterDriver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString adapterDriver2; */
NS_IMETHODIMP nsGfxInfo::GetAdapterDriver2(nsAString & aAdapterDriver2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString adapterVendorID; */
NS_IMETHODIMP nsGfxInfo::GetAdapterVendorID(nsAString & aAdapterVendorID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString adapterVendorID2; */
NS_IMETHODIMP nsGfxInfo::GetAdapterVendorID2(nsAString & aAdapterVendorID2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString adapterDeviceID; */
NS_IMETHODIMP nsGfxInfo::GetAdapterDeviceID(nsAString & aAdapterDeviceID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString adapterDeviceID2; */
NS_IMETHODIMP nsGfxInfo::GetAdapterDeviceID2(nsAString & aAdapterDeviceID2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString adapterRAM; */
NS_IMETHODIMP nsGfxInfo::GetAdapterRAM(nsAString & aAdapterRAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString adapterRAM2; */
NS_IMETHODIMP nsGfxInfo::GetAdapterRAM2(nsAString & aAdapterRAM2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString adapterDriverVersion; */
NS_IMETHODIMP nsGfxInfo::GetAdapterDriverVersion(nsAString & aAdapterDriverVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString adapterDriverVersion2; */
NS_IMETHODIMP nsGfxInfo::GetAdapterDriverVersion2(nsAString & aAdapterDriverVersion2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString adapterDriverDate; */
NS_IMETHODIMP nsGfxInfo::GetAdapterDriverDate(nsAString & aAdapterDriverDate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString adapterDriverDate2; */
NS_IMETHODIMP nsGfxInfo::GetAdapterDriverDate2(nsAString & aAdapterDriverDate2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isGPU2Active; */
NS_IMETHODIMP nsGfxInfo::GetIsGPU2Active(bool *aIsGPU2Active)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getFailures ([optional] out unsigned long failureCount, [array, size_is (failureCount), retval] out string failures); */
NS_IMETHODIMP nsGfxInfo::GetFailures(uint32_t *failureCount, char * **failures)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] void logFailure (in ACString failure); */
NS_IMETHODIMP_(void) nsGfxInfo::LogFailure(const nsACString & failure)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getFeatureStatus (in long aFeature); */
NS_IMETHODIMP nsGfxInfo::GetFeatureStatus(int32_t aFeature, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getFeatureSuggestedDriverVersion (in long aFeature); */
NS_IMETHODIMP nsGfxInfo::GetFeatureSuggestedDriverVersion(int32_t aFeature, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getWebGLParameter (in DOMString aParam); */
NS_IMETHODIMP nsGfxInfo::GetWebGLParameter(const nsAString & aParam, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] void GetData (); */
NS_IMETHODIMP_(void) nsGfxInfo::GetData()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getInfo (); */
NS_IMETHODIMP nsGfxInfo::GetInfo(JSContext* cx, JS::Value *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIGfxInfo_h__ */

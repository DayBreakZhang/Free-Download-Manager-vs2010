/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/widget/public/nsIGfxInfo.idl
 */

#ifndef __gen_nsIGfxInfo_h__
#define __gen_nsIGfxInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIGfxInfo */
#define NS_IGFXINFO_IID_STR "5c5de1e7-f7f4-46b4-9ced-03ab1f869eaf"

#define NS_IGFXINFO_IID \
  {0x5c5de1e7, 0xf7f4, 0x46b4, \
    { 0x9c, 0xed, 0x03, 0xab, 0x1f, 0x86, 0x9e, 0xaf }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIGfxInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGFXINFO_IID)

  /* readonly attribute boolean D2DEnabled; */
  NS_SCRIPTABLE NS_IMETHOD GetD2DEnabled(PRBool *aD2DEnabled) = 0;

  /* readonly attribute boolean DWriteEnabled; */
  NS_SCRIPTABLE NS_IMETHOD GetDWriteEnabled(PRBool *aDWriteEnabled) = 0;

  /* readonly attribute DOMString DWriteVersion; */
  NS_SCRIPTABLE NS_IMETHOD GetDWriteVersion(nsAString & aDWriteVersion) = 0;

  /**
   * The name of the display adapter.
   */
  /* readonly attribute DOMString adapterDescription; */
  NS_SCRIPTABLE NS_IMETHOD GetAdapterDescription(nsAString & aAdapterDescription) = 0;

  /* readonly attribute DOMString adapterDriver; */
  NS_SCRIPTABLE NS_IMETHOD GetAdapterDriver(nsAString & aAdapterDriver) = 0;

  /* readonly attribute unsigned long adapterVendorID; */
  NS_SCRIPTABLE NS_IMETHOD GetAdapterVendorID(PRUint32 *aAdapterVendorID) = 0;

  /* readonly attribute unsigned long adapterDeviceID; */
  NS_SCRIPTABLE NS_IMETHOD GetAdapterDeviceID(PRUint32 *aAdapterDeviceID) = 0;

  /**
   * The amount of RAM in MB in the display adapter.
   */
  /* readonly attribute DOMString adapterRAM; */
  NS_SCRIPTABLE NS_IMETHOD GetAdapterRAM(nsAString & aAdapterRAM) = 0;

  /* readonly attribute DOMString adapterDriverVersion; */
  NS_SCRIPTABLE NS_IMETHOD GetAdapterDriverVersion(nsAString & aAdapterDriverVersion) = 0;

  /* readonly attribute DOMString adapterDriverDate; */
  NS_SCRIPTABLE NS_IMETHOD GetAdapterDriverDate(nsAString & aAdapterDriverDate) = 0;

  /* void getFailures ([optional] out unsigned long failureCount, [array, size_is (failureCount), retval] out string failures); */
  NS_SCRIPTABLE NS_IMETHOD GetFailures(PRUint32 *failureCount NS_OUTPARAM, char ***failures NS_OUTPARAM) = 0;

  /* [noscript, notxpcom] void logFailure (in ACString failure); */
  NS_IMETHOD_(void) LogFailure(const nsACString & failure) = 0;

  enum { FEATURE_DIRECT2D = 1 };

  enum { FEATURE_DIRECT3D_9_LAYERS = 2 };

  enum { FEATURE_DIRECT3D_10_LAYERS = 3 };

  enum { FEATURE_DIRECT3D_10_1_LAYERS = 4 };

  enum { FEATURE_OPENGL_LAYERS = 5 };

  enum { FEATURE_WEBGL_OPENGL = 6 };

  enum { FEATURE_WEBGL_ANGLE = 7 };

  enum { FEATURE_NO_INFO = 1 };

  enum { FEATURE_BLOCKED_DRIVER_VERSION = 2 };

  enum { FEATURE_BLOCKED_DEVICE = 3 };

  enum { FEATURE_DISCOURAGED = 4 };

  enum { FEATURE_BLOCKED_OS_VERSION = 5 };

  /**
   * Ask about a feature, and return the status of that feature
   */
  /* long getFeatureStatus (in long aFeature); */
  NS_SCRIPTABLE NS_IMETHOD GetFeatureStatus(PRInt32 aFeature, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* DOMString getFeatureSuggestedDriverVersion (in long aFeature); */
  NS_SCRIPTABLE NS_IMETHOD GetFeatureSuggestedDriverVersion(PRInt32 aFeature, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * WebGL info; valid params are "full-renderer", "vendor", "renderer", "version",
   * "shading_language_version", "extensions".  These return info from
   * underlying GL impl that's used to implement WebGL.
   */
  /* DOMString getWebGLParameter (in DOMString aParam); */
  NS_SCRIPTABLE NS_IMETHOD GetWebGLParameter(const nsAString & aParam, nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGfxInfo, NS_IGFXINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGFXINFO \
  NS_SCRIPTABLE NS_IMETHOD GetD2DEnabled(PRBool *aD2DEnabled); \
  NS_SCRIPTABLE NS_IMETHOD GetDWriteEnabled(PRBool *aDWriteEnabled); \
  NS_SCRIPTABLE NS_IMETHOD GetDWriteVersion(nsAString & aDWriteVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetAdapterDescription(nsAString & aAdapterDescription); \
  NS_SCRIPTABLE NS_IMETHOD GetAdapterDriver(nsAString & aAdapterDriver); \
  NS_SCRIPTABLE NS_IMETHOD GetAdapterVendorID(PRUint32 *aAdapterVendorID); \
  NS_SCRIPTABLE NS_IMETHOD GetAdapterDeviceID(PRUint32 *aAdapterDeviceID); \
  NS_SCRIPTABLE NS_IMETHOD GetAdapterRAM(nsAString & aAdapterRAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAdapterDriverVersion(nsAString & aAdapterDriverVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetAdapterDriverDate(nsAString & aAdapterDriverDate); \
  NS_SCRIPTABLE NS_IMETHOD GetFailures(PRUint32 *failureCount NS_OUTPARAM, char ***failures NS_OUTPARAM); \
  NS_IMETHOD_(void) LogFailure(const nsACString & failure); \
  NS_SCRIPTABLE NS_IMETHOD GetFeatureStatus(PRInt32 aFeature, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetFeatureSuggestedDriverVersion(PRInt32 aFeature, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetWebGLParameter(const nsAString & aParam, nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGFXINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetD2DEnabled(PRBool *aD2DEnabled) { return _to GetD2DEnabled(aD2DEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetDWriteEnabled(PRBool *aDWriteEnabled) { return _to GetDWriteEnabled(aDWriteEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetDWriteVersion(nsAString & aDWriteVersion) { return _to GetDWriteVersion(aDWriteVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetAdapterDescription(nsAString & aAdapterDescription) { return _to GetAdapterDescription(aAdapterDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetAdapterDriver(nsAString & aAdapterDriver) { return _to GetAdapterDriver(aAdapterDriver); } \
  NS_SCRIPTABLE NS_IMETHOD GetAdapterVendorID(PRUint32 *aAdapterVendorID) { return _to GetAdapterVendorID(aAdapterVendorID); } \
  NS_SCRIPTABLE NS_IMETHOD GetAdapterDeviceID(PRUint32 *aAdapterDeviceID) { return _to GetAdapterDeviceID(aAdapterDeviceID); } \
  NS_SCRIPTABLE NS_IMETHOD GetAdapterRAM(nsAString & aAdapterRAM) { return _to GetAdapterRAM(aAdapterRAM); } \
  NS_SCRIPTABLE NS_IMETHOD GetAdapterDriverVersion(nsAString & aAdapterDriverVersion) { return _to GetAdapterDriverVersion(aAdapterDriverVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetAdapterDriverDate(nsAString & aAdapterDriverDate) { return _to GetAdapterDriverDate(aAdapterDriverDate); } \
  NS_SCRIPTABLE NS_IMETHOD GetFailures(PRUint32 *failureCount NS_OUTPARAM, char ***failures NS_OUTPARAM) { return _to GetFailures(failureCount, failures); } \
  NS_IMETHOD_(void) LogFailure(const nsACString & failure) { return _to LogFailure(failure); } \
  NS_SCRIPTABLE NS_IMETHOD GetFeatureStatus(PRInt32 aFeature, PRInt32 *_retval NS_OUTPARAM) { return _to GetFeatureStatus(aFeature, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFeatureSuggestedDriverVersion(PRInt32 aFeature, nsAString & _retval NS_OUTPARAM) { return _to GetFeatureSuggestedDriverVersion(aFeature, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetWebGLParameter(const nsAString & aParam, nsAString & _retval NS_OUTPARAM) { return _to GetWebGLParameter(aParam, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGFXINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetD2DEnabled(PRBool *aD2DEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetD2DEnabled(aD2DEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetDWriteEnabled(PRBool *aDWriteEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDWriteEnabled(aDWriteEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetDWriteVersion(nsAString & aDWriteVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDWriteVersion(aDWriteVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetAdapterDescription(nsAString & aAdapterDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdapterDescription(aAdapterDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetAdapterDriver(nsAString & aAdapterDriver) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdapterDriver(aAdapterDriver); } \
  NS_SCRIPTABLE NS_IMETHOD GetAdapterVendorID(PRUint32 *aAdapterVendorID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdapterVendorID(aAdapterVendorID); } \
  NS_SCRIPTABLE NS_IMETHOD GetAdapterDeviceID(PRUint32 *aAdapterDeviceID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdapterDeviceID(aAdapterDeviceID); } \
  NS_SCRIPTABLE NS_IMETHOD GetAdapterRAM(nsAString & aAdapterRAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdapterRAM(aAdapterRAM); } \
  NS_SCRIPTABLE NS_IMETHOD GetAdapterDriverVersion(nsAString & aAdapterDriverVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdapterDriverVersion(aAdapterDriverVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetAdapterDriverDate(nsAString & aAdapterDriverDate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdapterDriverDate(aAdapterDriverDate); } \
  NS_SCRIPTABLE NS_IMETHOD GetFailures(PRUint32 *failureCount NS_OUTPARAM, char ***failures NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFailures(failureCount, failures); } \
  NS_IMETHOD_(void) LogFailure(const nsACString & failure) { return !_to ? NS_ERROR_NULL_POINTER : _to->LogFailure(failure); } \
  NS_SCRIPTABLE NS_IMETHOD GetFeatureStatus(PRInt32 aFeature, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFeatureStatus(aFeature, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFeatureSuggestedDriverVersion(PRInt32 aFeature, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFeatureSuggestedDriverVersion(aFeature, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetWebGLParameter(const nsAString & aParam, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWebGLParameter(aParam, _retval); } 

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
NS_IMETHODIMP nsGfxInfo::GetD2DEnabled(PRBool *aD2DEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean DWriteEnabled; */
NS_IMETHODIMP nsGfxInfo::GetDWriteEnabled(PRBool *aDWriteEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString DWriteVersion; */
NS_IMETHODIMP nsGfxInfo::GetDWriteVersion(nsAString & aDWriteVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString adapterDescription; */
NS_IMETHODIMP nsGfxInfo::GetAdapterDescription(nsAString & aAdapterDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString adapterDriver; */
NS_IMETHODIMP nsGfxInfo::GetAdapterDriver(nsAString & aAdapterDriver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long adapterVendorID; */
NS_IMETHODIMP nsGfxInfo::GetAdapterVendorID(PRUint32 *aAdapterVendorID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long adapterDeviceID; */
NS_IMETHODIMP nsGfxInfo::GetAdapterDeviceID(PRUint32 *aAdapterDeviceID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString adapterRAM; */
NS_IMETHODIMP nsGfxInfo::GetAdapterRAM(nsAString & aAdapterRAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString adapterDriverVersion; */
NS_IMETHODIMP nsGfxInfo::GetAdapterDriverVersion(nsAString & aAdapterDriverVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString adapterDriverDate; */
NS_IMETHODIMP nsGfxInfo::GetAdapterDriverDate(nsAString & aAdapterDriverDate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getFailures ([optional] out unsigned long failureCount, [array, size_is (failureCount), retval] out string failures); */
NS_IMETHODIMP nsGfxInfo::GetFailures(PRUint32 *failureCount NS_OUTPARAM, char ***failures NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript, notxpcom] void logFailure (in ACString failure); */
NS_IMETHODIMP_(void) nsGfxInfo::LogFailure(const nsACString & failure)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getFeatureStatus (in long aFeature); */
NS_IMETHODIMP nsGfxInfo::GetFeatureStatus(PRInt32 aFeature, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getFeatureSuggestedDriverVersion (in long aFeature); */
NS_IMETHODIMP nsGfxInfo::GetFeatureSuggestedDriverVersion(PRInt32 aFeature, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getWebGLParameter (in DOMString aParam); */
NS_IMETHODIMP nsGfxInfo::GetWebGLParameter(const nsAString & aParam, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIGfxInfo_h__ */

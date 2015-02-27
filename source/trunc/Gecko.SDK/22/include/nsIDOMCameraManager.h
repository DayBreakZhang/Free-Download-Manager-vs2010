/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/camera/nsIDOMCameraManager.idl
 */

#ifndef __gen_nsIDOMCameraManager_h__
#define __gen_nsIDOMCameraManager_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDOMMediaStream_h__
#include "nsIDOMMediaStream.h"
#endif

#ifndef __gen_nsIDOMDOMRequest_h__
#include "nsIDOMDOMRequest.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMBlob; /* forward declaration */

class nsIDOMDeviceStorage; /* forward declaration */


/* starting interface:    nsICameraCapabilities */
#define NS_ICAMERACAPABILITIES_IID_STR "177472c9-f83d-48b5-8782-03b43b27f25d"

#define NS_ICAMERACAPABILITIES_IID \
  {0x177472c9, 0xf83d, 0x48b5, \
    { 0x87, 0x82, 0x03, 0xb4, 0x3b, 0x27, 0xf2, 0x5d }}

class NS_NO_VTABLE nsICameraCapabilities : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICAMERACAPABILITIES_IID)

  /* [implicit_jscontext] readonly attribute jsval previewSizes; */
  NS_IMETHOD GetPreviewSizes(JSContext* cx, JS::Value *aPreviewSizes) = 0;

  /* [implicit_jscontext] readonly attribute jsval pictureSizes; */
  NS_IMETHOD GetPictureSizes(JSContext* cx, JS::Value *aPictureSizes) = 0;

  /* [implicit_jscontext] readonly attribute jsval fileFormats; */
  NS_IMETHOD GetFileFormats(JSContext* cx, JS::Value *aFileFormats) = 0;

  /* [implicit_jscontext] readonly attribute jsval whiteBalanceModes; */
  NS_IMETHOD GetWhiteBalanceModes(JSContext* cx, JS::Value *aWhiteBalanceModes) = 0;

  /* [implicit_jscontext] readonly attribute jsval sceneModes; */
  NS_IMETHOD GetSceneModes(JSContext* cx, JS::Value *aSceneModes) = 0;

  /* [implicit_jscontext] readonly attribute jsval effects; */
  NS_IMETHOD GetEffects(JSContext* cx, JS::Value *aEffects) = 0;

  /* [implicit_jscontext] readonly attribute jsval flashModes; */
  NS_IMETHOD GetFlashModes(JSContext* cx, JS::Value *aFlashModes) = 0;

  /* [implicit_jscontext] readonly attribute jsval focusModes; */
  NS_IMETHOD GetFocusModes(JSContext* cx, JS::Value *aFocusModes) = 0;

  /* [implicit_jscontext] readonly attribute long maxFocusAreas; */
  NS_IMETHOD GetMaxFocusAreas(JSContext* cx, int32_t *aMaxFocusAreas) = 0;

  /* [implicit_jscontext] readonly attribute double minExposureCompensation; */
  NS_IMETHOD GetMinExposureCompensation(JSContext* cx, double *aMinExposureCompensation) = 0;

  /* [implicit_jscontext] readonly attribute double maxExposureCompensation; */
  NS_IMETHOD GetMaxExposureCompensation(JSContext* cx, double *aMaxExposureCompensation) = 0;

  /* [implicit_jscontext] readonly attribute double stepExposureCompensation; */
  NS_IMETHOD GetStepExposureCompensation(JSContext* cx, double *aStepExposureCompensation) = 0;

  /* [implicit_jscontext] readonly attribute long maxMeteringAreas; */
  NS_IMETHOD GetMaxMeteringAreas(JSContext* cx, int32_t *aMaxMeteringAreas) = 0;

  /* [implicit_jscontext] readonly attribute jsval zoomRatios; */
  NS_IMETHOD GetZoomRatios(JSContext* cx, JS::Value *aZoomRatios) = 0;

  /* [implicit_jscontext] readonly attribute jsval videoSizes; */
  NS_IMETHOD GetVideoSizes(JSContext* cx, JS::Value *aVideoSizes) = 0;

  /* [implicit_jscontext] readonly attribute jsval recorderProfiles; */
  NS_IMETHOD GetRecorderProfiles(JSContext* cx, JS::Value *aRecorderProfiles) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICameraCapabilities, NS_ICAMERACAPABILITIES_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICAMERACAPABILITIES \
  NS_IMETHOD GetPreviewSizes(JSContext* cx, JS::Value *aPreviewSizes); \
  NS_IMETHOD GetPictureSizes(JSContext* cx, JS::Value *aPictureSizes); \
  NS_IMETHOD GetFileFormats(JSContext* cx, JS::Value *aFileFormats); \
  NS_IMETHOD GetWhiteBalanceModes(JSContext* cx, JS::Value *aWhiteBalanceModes); \
  NS_IMETHOD GetSceneModes(JSContext* cx, JS::Value *aSceneModes); \
  NS_IMETHOD GetEffects(JSContext* cx, JS::Value *aEffects); \
  NS_IMETHOD GetFlashModes(JSContext* cx, JS::Value *aFlashModes); \
  NS_IMETHOD GetFocusModes(JSContext* cx, JS::Value *aFocusModes); \
  NS_IMETHOD GetMaxFocusAreas(JSContext* cx, int32_t *aMaxFocusAreas); \
  NS_IMETHOD GetMinExposureCompensation(JSContext* cx, double *aMinExposureCompensation); \
  NS_IMETHOD GetMaxExposureCompensation(JSContext* cx, double *aMaxExposureCompensation); \
  NS_IMETHOD GetStepExposureCompensation(JSContext* cx, double *aStepExposureCompensation); \
  NS_IMETHOD GetMaxMeteringAreas(JSContext* cx, int32_t *aMaxMeteringAreas); \
  NS_IMETHOD GetZoomRatios(JSContext* cx, JS::Value *aZoomRatios); \
  NS_IMETHOD GetVideoSizes(JSContext* cx, JS::Value *aVideoSizes); \
  NS_IMETHOD GetRecorderProfiles(JSContext* cx, JS::Value *aRecorderProfiles); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICAMERACAPABILITIES(_to) \
  NS_IMETHOD GetPreviewSizes(JSContext* cx, JS::Value *aPreviewSizes) { return _to GetPreviewSizes(cx, aPreviewSizes); } \
  NS_IMETHOD GetPictureSizes(JSContext* cx, JS::Value *aPictureSizes) { return _to GetPictureSizes(cx, aPictureSizes); } \
  NS_IMETHOD GetFileFormats(JSContext* cx, JS::Value *aFileFormats) { return _to GetFileFormats(cx, aFileFormats); } \
  NS_IMETHOD GetWhiteBalanceModes(JSContext* cx, JS::Value *aWhiteBalanceModes) { return _to GetWhiteBalanceModes(cx, aWhiteBalanceModes); } \
  NS_IMETHOD GetSceneModes(JSContext* cx, JS::Value *aSceneModes) { return _to GetSceneModes(cx, aSceneModes); } \
  NS_IMETHOD GetEffects(JSContext* cx, JS::Value *aEffects) { return _to GetEffects(cx, aEffects); } \
  NS_IMETHOD GetFlashModes(JSContext* cx, JS::Value *aFlashModes) { return _to GetFlashModes(cx, aFlashModes); } \
  NS_IMETHOD GetFocusModes(JSContext* cx, JS::Value *aFocusModes) { return _to GetFocusModes(cx, aFocusModes); } \
  NS_IMETHOD GetMaxFocusAreas(JSContext* cx, int32_t *aMaxFocusAreas) { return _to GetMaxFocusAreas(cx, aMaxFocusAreas); } \
  NS_IMETHOD GetMinExposureCompensation(JSContext* cx, double *aMinExposureCompensation) { return _to GetMinExposureCompensation(cx, aMinExposureCompensation); } \
  NS_IMETHOD GetMaxExposureCompensation(JSContext* cx, double *aMaxExposureCompensation) { return _to GetMaxExposureCompensation(cx, aMaxExposureCompensation); } \
  NS_IMETHOD GetStepExposureCompensation(JSContext* cx, double *aStepExposureCompensation) { return _to GetStepExposureCompensation(cx, aStepExposureCompensation); } \
  NS_IMETHOD GetMaxMeteringAreas(JSContext* cx, int32_t *aMaxMeteringAreas) { return _to GetMaxMeteringAreas(cx, aMaxMeteringAreas); } \
  NS_IMETHOD GetZoomRatios(JSContext* cx, JS::Value *aZoomRatios) { return _to GetZoomRatios(cx, aZoomRatios); } \
  NS_IMETHOD GetVideoSizes(JSContext* cx, JS::Value *aVideoSizes) { return _to GetVideoSizes(cx, aVideoSizes); } \
  NS_IMETHOD GetRecorderProfiles(JSContext* cx, JS::Value *aRecorderProfiles) { return _to GetRecorderProfiles(cx, aRecorderProfiles); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICAMERACAPABILITIES(_to) \
  NS_IMETHOD GetPreviewSizes(JSContext* cx, JS::Value *aPreviewSizes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreviewSizes(cx, aPreviewSizes); } \
  NS_IMETHOD GetPictureSizes(JSContext* cx, JS::Value *aPictureSizes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPictureSizes(cx, aPictureSizes); } \
  NS_IMETHOD GetFileFormats(JSContext* cx, JS::Value *aFileFormats) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileFormats(cx, aFileFormats); } \
  NS_IMETHOD GetWhiteBalanceModes(JSContext* cx, JS::Value *aWhiteBalanceModes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWhiteBalanceModes(cx, aWhiteBalanceModes); } \
  NS_IMETHOD GetSceneModes(JSContext* cx, JS::Value *aSceneModes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSceneModes(cx, aSceneModes); } \
  NS_IMETHOD GetEffects(JSContext* cx, JS::Value *aEffects) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEffects(cx, aEffects); } \
  NS_IMETHOD GetFlashModes(JSContext* cx, JS::Value *aFlashModes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFlashModes(cx, aFlashModes); } \
  NS_IMETHOD GetFocusModes(JSContext* cx, JS::Value *aFocusModes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocusModes(cx, aFocusModes); } \
  NS_IMETHOD GetMaxFocusAreas(JSContext* cx, int32_t *aMaxFocusAreas) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxFocusAreas(cx, aMaxFocusAreas); } \
  NS_IMETHOD GetMinExposureCompensation(JSContext* cx, double *aMinExposureCompensation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMinExposureCompensation(cx, aMinExposureCompensation); } \
  NS_IMETHOD GetMaxExposureCompensation(JSContext* cx, double *aMaxExposureCompensation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxExposureCompensation(cx, aMaxExposureCompensation); } \
  NS_IMETHOD GetStepExposureCompensation(JSContext* cx, double *aStepExposureCompensation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStepExposureCompensation(cx, aStepExposureCompensation); } \
  NS_IMETHOD GetMaxMeteringAreas(JSContext* cx, int32_t *aMaxMeteringAreas) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxMeteringAreas(cx, aMaxMeteringAreas); } \
  NS_IMETHOD GetZoomRatios(JSContext* cx, JS::Value *aZoomRatios) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZoomRatios(cx, aZoomRatios); } \
  NS_IMETHOD GetVideoSizes(JSContext* cx, JS::Value *aVideoSizes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVideoSizes(cx, aVideoSizes); } \
  NS_IMETHOD GetRecorderProfiles(JSContext* cx, JS::Value *aRecorderProfiles) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRecorderProfiles(cx, aRecorderProfiles); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCameraCapabilities : public nsICameraCapabilities
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICAMERACAPABILITIES

  nsCameraCapabilities();

private:
  ~nsCameraCapabilities();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCameraCapabilities, nsICameraCapabilities)

nsCameraCapabilities::nsCameraCapabilities()
{
  /* member initializers and constructor code */
}

nsCameraCapabilities::~nsCameraCapabilities()
{
  /* destructor code */
}

/* [implicit_jscontext] readonly attribute jsval previewSizes; */
NS_IMETHODIMP nsCameraCapabilities::GetPreviewSizes(JSContext* cx, JS::Value *aPreviewSizes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval pictureSizes; */
NS_IMETHODIMP nsCameraCapabilities::GetPictureSizes(JSContext* cx, JS::Value *aPictureSizes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval fileFormats; */
NS_IMETHODIMP nsCameraCapabilities::GetFileFormats(JSContext* cx, JS::Value *aFileFormats)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval whiteBalanceModes; */
NS_IMETHODIMP nsCameraCapabilities::GetWhiteBalanceModes(JSContext* cx, JS::Value *aWhiteBalanceModes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval sceneModes; */
NS_IMETHODIMP nsCameraCapabilities::GetSceneModes(JSContext* cx, JS::Value *aSceneModes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval effects; */
NS_IMETHODIMP nsCameraCapabilities::GetEffects(JSContext* cx, JS::Value *aEffects)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval flashModes; */
NS_IMETHODIMP nsCameraCapabilities::GetFlashModes(JSContext* cx, JS::Value *aFlashModes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval focusModes; */
NS_IMETHODIMP nsCameraCapabilities::GetFocusModes(JSContext* cx, JS::Value *aFocusModes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute long maxFocusAreas; */
NS_IMETHODIMP nsCameraCapabilities::GetMaxFocusAreas(JSContext* cx, int32_t *aMaxFocusAreas)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute double minExposureCompensation; */
NS_IMETHODIMP nsCameraCapabilities::GetMinExposureCompensation(JSContext* cx, double *aMinExposureCompensation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute double maxExposureCompensation; */
NS_IMETHODIMP nsCameraCapabilities::GetMaxExposureCompensation(JSContext* cx, double *aMaxExposureCompensation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute double stepExposureCompensation; */
NS_IMETHODIMP nsCameraCapabilities::GetStepExposureCompensation(JSContext* cx, double *aStepExposureCompensation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute long maxMeteringAreas; */
NS_IMETHODIMP nsCameraCapabilities::GetMaxMeteringAreas(JSContext* cx, int32_t *aMaxMeteringAreas)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval zoomRatios; */
NS_IMETHODIMP nsCameraCapabilities::GetZoomRatios(JSContext* cx, JS::Value *aZoomRatios)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval videoSizes; */
NS_IMETHODIMP nsCameraCapabilities::GetVideoSizes(JSContext* cx, JS::Value *aVideoSizes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval recorderProfiles; */
NS_IMETHODIMP nsCameraCapabilities::GetRecorderProfiles(JSContext* cx, JS::Value *aRecorderProfiles)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICameraPreviewStreamCallback */
#define NS_ICAMERAPREVIEWSTREAMCALLBACK_IID_STR "0444a687-4bc9-462c-8246-5423f0fe46a4"

#define NS_ICAMERAPREVIEWSTREAMCALLBACK_IID \
  {0x0444a687, 0x4bc9, 0x462c, \
    { 0x82, 0x46, 0x54, 0x23, 0xf0, 0xfe, 0x46, 0xa4 }}

class NS_NO_VTABLE nsICameraPreviewStreamCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICAMERAPREVIEWSTREAMCALLBACK_IID)

  /* void handleEvent (in nsIDOMMediaStream stream); */
  NS_IMETHOD HandleEvent(nsIDOMMediaStream *stream) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICameraPreviewStreamCallback, NS_ICAMERAPREVIEWSTREAMCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICAMERAPREVIEWSTREAMCALLBACK \
  NS_IMETHOD HandleEvent(nsIDOMMediaStream *stream); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICAMERAPREVIEWSTREAMCALLBACK(_to) \
  NS_IMETHOD HandleEvent(nsIDOMMediaStream *stream) { return _to HandleEvent(stream); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICAMERAPREVIEWSTREAMCALLBACK(_to) \
  NS_IMETHOD HandleEvent(nsIDOMMediaStream *stream) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEvent(stream); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCameraPreviewStreamCallback : public nsICameraPreviewStreamCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICAMERAPREVIEWSTREAMCALLBACK

  nsCameraPreviewStreamCallback();

private:
  ~nsCameraPreviewStreamCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCameraPreviewStreamCallback, nsICameraPreviewStreamCallback)

nsCameraPreviewStreamCallback::nsCameraPreviewStreamCallback()
{
  /* member initializers and constructor code */
}

nsCameraPreviewStreamCallback::~nsCameraPreviewStreamCallback()
{
  /* destructor code */
}

/* void handleEvent (in nsIDOMMediaStream stream); */
NS_IMETHODIMP nsCameraPreviewStreamCallback::HandleEvent(nsIDOMMediaStream *stream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICameraAutoFocusCallback */
#define NS_ICAMERAAUTOFOCUSCALLBACK_IID_STR "6baa4ac7-9c25-4c48-9bb0-5193b38b9b0a"

#define NS_ICAMERAAUTOFOCUSCALLBACK_IID \
  {0x6baa4ac7, 0x9c25, 0x4c48, \
    { 0x9b, 0xb0, 0x51, 0x93, 0xb3, 0x8b, 0x9b, 0x0a }}

class NS_NO_VTABLE nsICameraAutoFocusCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICAMERAAUTOFOCUSCALLBACK_IID)

  /* void handleEvent (in boolean success); */
  NS_IMETHOD HandleEvent(bool success) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICameraAutoFocusCallback, NS_ICAMERAAUTOFOCUSCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICAMERAAUTOFOCUSCALLBACK \
  NS_IMETHOD HandleEvent(bool success); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICAMERAAUTOFOCUSCALLBACK(_to) \
  NS_IMETHOD HandleEvent(bool success) { return _to HandleEvent(success); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICAMERAAUTOFOCUSCALLBACK(_to) \
  NS_IMETHOD HandleEvent(bool success) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEvent(success); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCameraAutoFocusCallback : public nsICameraAutoFocusCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICAMERAAUTOFOCUSCALLBACK

  nsCameraAutoFocusCallback();

private:
  ~nsCameraAutoFocusCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCameraAutoFocusCallback, nsICameraAutoFocusCallback)

nsCameraAutoFocusCallback::nsCameraAutoFocusCallback()
{
  /* member initializers and constructor code */
}

nsCameraAutoFocusCallback::~nsCameraAutoFocusCallback()
{
  /* destructor code */
}

/* void handleEvent (in boolean success); */
NS_IMETHODIMP nsCameraAutoFocusCallback::HandleEvent(bool success)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICameraTakePictureCallback */
#define NS_ICAMERATAKEPICTURECALLBACK_IID_STR "17af779e-cb6f-4ca5-890c-06468ff82e4f"

#define NS_ICAMERATAKEPICTURECALLBACK_IID \
  {0x17af779e, 0xcb6f, 0x4ca5, \
    { 0x89, 0x0c, 0x06, 0x46, 0x8f, 0xf8, 0x2e, 0x4f }}

class NS_NO_VTABLE nsICameraTakePictureCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICAMERATAKEPICTURECALLBACK_IID)

  /* void handleEvent (in nsIDOMBlob picture); */
  NS_IMETHOD HandleEvent(nsIDOMBlob *picture) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICameraTakePictureCallback, NS_ICAMERATAKEPICTURECALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICAMERATAKEPICTURECALLBACK \
  NS_IMETHOD HandleEvent(nsIDOMBlob *picture); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICAMERATAKEPICTURECALLBACK(_to) \
  NS_IMETHOD HandleEvent(nsIDOMBlob *picture) { return _to HandleEvent(picture); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICAMERATAKEPICTURECALLBACK(_to) \
  NS_IMETHOD HandleEvent(nsIDOMBlob *picture) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEvent(picture); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCameraTakePictureCallback : public nsICameraTakePictureCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICAMERATAKEPICTURECALLBACK

  nsCameraTakePictureCallback();

private:
  ~nsCameraTakePictureCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCameraTakePictureCallback, nsICameraTakePictureCallback)

nsCameraTakePictureCallback::nsCameraTakePictureCallback()
{
  /* member initializers and constructor code */
}

nsCameraTakePictureCallback::~nsCameraTakePictureCallback()
{
  /* destructor code */
}

/* void handleEvent (in nsIDOMBlob picture); */
NS_IMETHODIMP nsCameraTakePictureCallback::HandleEvent(nsIDOMBlob *picture)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICameraStartRecordingCallback */
#define NS_ICAMERASTARTRECORDINGCALLBACK_IID_STR "89a762f8-581b-410a-ad86-e2bd2113ad82"

#define NS_ICAMERASTARTRECORDINGCALLBACK_IID \
  {0x89a762f8, 0x581b, 0x410a, \
    { 0xad, 0x86, 0xe2, 0xbd, 0x21, 0x13, 0xad, 0x82 }}

class NS_NO_VTABLE nsICameraStartRecordingCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICAMERASTARTRECORDINGCALLBACK_IID)

  /* void handleEvent (); */
  NS_IMETHOD HandleEvent(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICameraStartRecordingCallback, NS_ICAMERASTARTRECORDINGCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICAMERASTARTRECORDINGCALLBACK \
  NS_IMETHOD HandleEvent(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICAMERASTARTRECORDINGCALLBACK(_to) \
  NS_IMETHOD HandleEvent(void) { return _to HandleEvent(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICAMERASTARTRECORDINGCALLBACK(_to) \
  NS_IMETHOD HandleEvent(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEvent(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCameraStartRecordingCallback : public nsICameraStartRecordingCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICAMERASTARTRECORDINGCALLBACK

  nsCameraStartRecordingCallback();

private:
  ~nsCameraStartRecordingCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCameraStartRecordingCallback, nsICameraStartRecordingCallback)

nsCameraStartRecordingCallback::nsCameraStartRecordingCallback()
{
  /* member initializers and constructor code */
}

nsCameraStartRecordingCallback::~nsCameraStartRecordingCallback()
{
  /* destructor code */
}

/* void handleEvent (); */
NS_IMETHODIMP nsCameraStartRecordingCallback::HandleEvent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICameraShutterCallback */
#define NS_ICAMERASHUTTERCALLBACK_IID_STR "fb80db71-e315-42f0-9ea9-dd3dd312ed70"

#define NS_ICAMERASHUTTERCALLBACK_IID \
  {0xfb80db71, 0xe315, 0x42f0, \
    { 0x9e, 0xa9, 0xdd, 0x3d, 0xd3, 0x12, 0xed, 0x70 }}

class NS_NO_VTABLE nsICameraShutterCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICAMERASHUTTERCALLBACK_IID)

  /* void handleEvent (); */
  NS_IMETHOD HandleEvent(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICameraShutterCallback, NS_ICAMERASHUTTERCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICAMERASHUTTERCALLBACK \
  NS_IMETHOD HandleEvent(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICAMERASHUTTERCALLBACK(_to) \
  NS_IMETHOD HandleEvent(void) { return _to HandleEvent(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICAMERASHUTTERCALLBACK(_to) \
  NS_IMETHOD HandleEvent(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEvent(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCameraShutterCallback : public nsICameraShutterCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICAMERASHUTTERCALLBACK

  nsCameraShutterCallback();

private:
  ~nsCameraShutterCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCameraShutterCallback, nsICameraShutterCallback)

nsCameraShutterCallback::nsCameraShutterCallback()
{
  /* member initializers and constructor code */
}

nsCameraShutterCallback::~nsCameraShutterCallback()
{
  /* destructor code */
}

/* void handleEvent (); */
NS_IMETHODIMP nsCameraShutterCallback::HandleEvent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICameraClosedCallback */
#define NS_ICAMERACLOSEDCALLBACK_IID_STR "0ef0f01e-ce74-4741-9bba-54376adfb7a2"

#define NS_ICAMERACLOSEDCALLBACK_IID \
  {0x0ef0f01e, 0xce74, 0x4741, \
    { 0x9b, 0xba, 0x54, 0x37, 0x6a, 0xdf, 0xb7, 0xa2 }}

class NS_NO_VTABLE nsICameraClosedCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICAMERACLOSEDCALLBACK_IID)

  /* void handleEvent (); */
  NS_IMETHOD HandleEvent(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICameraClosedCallback, NS_ICAMERACLOSEDCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICAMERACLOSEDCALLBACK \
  NS_IMETHOD HandleEvent(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICAMERACLOSEDCALLBACK(_to) \
  NS_IMETHOD HandleEvent(void) { return _to HandleEvent(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICAMERACLOSEDCALLBACK(_to) \
  NS_IMETHOD HandleEvent(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEvent(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCameraClosedCallback : public nsICameraClosedCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICAMERACLOSEDCALLBACK

  nsCameraClosedCallback();

private:
  ~nsCameraClosedCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCameraClosedCallback, nsICameraClosedCallback)

nsCameraClosedCallback::nsCameraClosedCallback()
{
  /* member initializers and constructor code */
}

nsCameraClosedCallback::~nsCameraClosedCallback()
{
  /* destructor code */
}

/* void handleEvent (); */
NS_IMETHODIMP nsCameraClosedCallback::HandleEvent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICameraRecorderStateChange */
#define NS_ICAMERARECORDERSTATECHANGE_IID_STR "550d675a-257d-4713-8b3d-0da53eba68fc"

#define NS_ICAMERARECORDERSTATECHANGE_IID \
  {0x550d675a, 0x257d, 0x4713, \
    { 0x8b, 0x3d, 0x0d, 0xa5, 0x3e, 0xba, 0x68, 0xfc }}

class NS_NO_VTABLE nsICameraRecorderStateChange : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICAMERARECORDERSTATECHANGE_IID)

  /* void handleStateChange (in DOMString newState); */
  NS_IMETHOD HandleStateChange(const nsAString & newState) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICameraRecorderStateChange, NS_ICAMERARECORDERSTATECHANGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICAMERARECORDERSTATECHANGE \
  NS_IMETHOD HandleStateChange(const nsAString & newState); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICAMERARECORDERSTATECHANGE(_to) \
  NS_IMETHOD HandleStateChange(const nsAString & newState) { return _to HandleStateChange(newState); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICAMERARECORDERSTATECHANGE(_to) \
  NS_IMETHOD HandleStateChange(const nsAString & newState) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleStateChange(newState); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCameraRecorderStateChange : public nsICameraRecorderStateChange
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICAMERARECORDERSTATECHANGE

  nsCameraRecorderStateChange();

private:
  ~nsCameraRecorderStateChange();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCameraRecorderStateChange, nsICameraRecorderStateChange)

nsCameraRecorderStateChange::nsCameraRecorderStateChange()
{
  /* member initializers and constructor code */
}

nsCameraRecorderStateChange::~nsCameraRecorderStateChange()
{
  /* destructor code */
}

/* void handleStateChange (in DOMString newState); */
NS_IMETHODIMP nsCameraRecorderStateChange::HandleStateChange(const nsAString & newState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICameraReleaseCallback */
#define NS_ICAMERARELEASECALLBACK_IID_STR "f84d607b-554c-413d-8810-cf848642765a"

#define NS_ICAMERARELEASECALLBACK_IID \
  {0xf84d607b, 0x554c, 0x413d, \
    { 0x88, 0x10, 0xcf, 0x84, 0x86, 0x42, 0x76, 0x5a }}

class NS_NO_VTABLE nsICameraReleaseCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICAMERARELEASECALLBACK_IID)

  /* void handleEvent (); */
  NS_IMETHOD HandleEvent(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICameraReleaseCallback, NS_ICAMERARELEASECALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICAMERARELEASECALLBACK \
  NS_IMETHOD HandleEvent(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICAMERARELEASECALLBACK(_to) \
  NS_IMETHOD HandleEvent(void) { return _to HandleEvent(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICAMERARELEASECALLBACK(_to) \
  NS_IMETHOD HandleEvent(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEvent(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCameraReleaseCallback : public nsICameraReleaseCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICAMERARELEASECALLBACK

  nsCameraReleaseCallback();

private:
  ~nsCameraReleaseCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCameraReleaseCallback, nsICameraReleaseCallback)

nsCameraReleaseCallback::nsCameraReleaseCallback()
{
  /* member initializers and constructor code */
}

nsCameraReleaseCallback::~nsCameraReleaseCallback()
{
  /* destructor code */
}

/* void handleEvent (); */
NS_IMETHODIMP nsCameraReleaseCallback::HandleEvent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICameraErrorCallback */
#define NS_ICAMERAERRORCALLBACK_IID_STR "a302c6c9-3776-4d1d-a395-f4105d47c3d3"

#define NS_ICAMERAERRORCALLBACK_IID \
  {0xa302c6c9, 0x3776, 0x4d1d, \
    { 0xa3, 0x95, 0xf4, 0x10, 0x5d, 0x47, 0xc3, 0xd3 }}

class NS_NO_VTABLE nsICameraErrorCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICAMERAERRORCALLBACK_IID)

  /* void handleEvent (in DOMString error); */
  NS_IMETHOD HandleEvent(const nsAString & error) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICameraErrorCallback, NS_ICAMERAERRORCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICAMERAERRORCALLBACK \
  NS_IMETHOD HandleEvent(const nsAString & error); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICAMERAERRORCALLBACK(_to) \
  NS_IMETHOD HandleEvent(const nsAString & error) { return _to HandleEvent(error); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICAMERAERRORCALLBACK(_to) \
  NS_IMETHOD HandleEvent(const nsAString & error) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEvent(error); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCameraErrorCallback : public nsICameraErrorCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICAMERAERRORCALLBACK

  nsCameraErrorCallback();

private:
  ~nsCameraErrorCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCameraErrorCallback, nsICameraErrorCallback)

nsCameraErrorCallback::nsCameraErrorCallback()
{
  /* member initializers and constructor code */
}

nsCameraErrorCallback::~nsCameraErrorCallback()
{
  /* destructor code */
}

/* void handleEvent (in DOMString error); */
NS_IMETHODIMP nsCameraErrorCallback::HandleEvent(const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICameraControl */
#define NS_ICAMERACONTROL_IID_STR "c8e7418d-8913-4b66-bd9f-562fba627266"

#define NS_ICAMERACONTROL_IID \
  {0xc8e7418d, 0x8913, 0x4b66, \
    { 0xbd, 0x9f, 0x56, 0x2f, 0xba, 0x62, 0x72, 0x66 }}

class NS_NO_VTABLE nsICameraControl : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICAMERACONTROL_IID)

  /* readonly attribute nsICameraCapabilities capabilities; */
  NS_IMETHOD GetCapabilities(nsICameraCapabilities * *aCapabilities) = 0;

  /* attribute DOMString effect; */
  NS_IMETHOD GetEffect(nsAString & aEffect) = 0;
  NS_IMETHOD SetEffect(const nsAString & aEffect) = 0;

  /* attribute DOMString whiteBalanceMode; */
  NS_IMETHOD GetWhiteBalanceMode(nsAString & aWhiteBalanceMode) = 0;
  NS_IMETHOD SetWhiteBalanceMode(const nsAString & aWhiteBalanceMode) = 0;

  /* attribute DOMString sceneMode; */
  NS_IMETHOD GetSceneMode(nsAString & aSceneMode) = 0;
  NS_IMETHOD SetSceneMode(const nsAString & aSceneMode) = 0;

  /* attribute DOMString flashMode; */
  NS_IMETHOD GetFlashMode(nsAString & aFlashMode) = 0;
  NS_IMETHOD SetFlashMode(const nsAString & aFlashMode) = 0;

  /* attribute DOMString focusMode; */
  NS_IMETHOD GetFocusMode(nsAString & aFocusMode) = 0;
  NS_IMETHOD SetFocusMode(const nsAString & aFocusMode) = 0;

  /* attribute double zoom; */
  NS_IMETHOD GetZoom(double *aZoom) = 0;
  NS_IMETHOD SetZoom(double aZoom) = 0;

  /* [implicit_jscontext] attribute jsval meteringAreas; */
  NS_IMETHOD GetMeteringAreas(JSContext* cx, JS::Value *aMeteringAreas) = 0;
  NS_IMETHOD SetMeteringAreas(JSContext* cx, const JS::Value & aMeteringAreas) = 0;

  /* [implicit_jscontext] attribute jsval focusAreas; */
  NS_IMETHOD GetFocusAreas(JSContext* cx, JS::Value *aFocusAreas) = 0;
  NS_IMETHOD SetFocusAreas(JSContext* cx, const JS::Value & aFocusAreas) = 0;

  /* readonly attribute double focalLength; */
  NS_IMETHOD GetFocalLength(double *aFocalLength) = 0;

  /* readonly attribute double focusDistanceNear; */
  NS_IMETHOD GetFocusDistanceNear(double *aFocusDistanceNear) = 0;

  /* readonly attribute double focusDistanceOptimum; */
  NS_IMETHOD GetFocusDistanceOptimum(double *aFocusDistanceOptimum) = 0;

  /* readonly attribute double focusDistanceFar; */
  NS_IMETHOD GetFocusDistanceFar(double *aFocusDistanceFar) = 0;

  /* [implicit_jscontext] void setExposureCompensation ([optional] in jsval compensation); */
  NS_IMETHOD SetExposureCompensation(const JS::Value & compensation, JSContext* cx) = 0;

  /* readonly attribute double exposureCompensation; */
  NS_IMETHOD GetExposureCompensation(double *aExposureCompensation) = 0;

  /* attribute nsICameraShutterCallback onShutter; */
  NS_IMETHOD GetOnShutter(nsICameraShutterCallback * *aOnShutter) = 0;
  NS_IMETHOD SetOnShutter(nsICameraShutterCallback *aOnShutter) = 0;

  /* attribute nsICameraClosedCallback onClosed; */
  NS_IMETHOD GetOnClosed(nsICameraClosedCallback * *aOnClosed) = 0;
  NS_IMETHOD SetOnClosed(nsICameraClosedCallback *aOnClosed) = 0;

  /* attribute nsICameraRecorderStateChange onRecorderStateChange; */
  NS_IMETHOD GetOnRecorderStateChange(nsICameraRecorderStateChange * *aOnRecorderStateChange) = 0;
  NS_IMETHOD SetOnRecorderStateChange(nsICameraRecorderStateChange *aOnRecorderStateChange) = 0;

  /* void autoFocus (in nsICameraAutoFocusCallback onSuccess, [optional] in nsICameraErrorCallback onError); */
  NS_IMETHOD AutoFocus(nsICameraAutoFocusCallback *onSuccess, nsICameraErrorCallback *onError) = 0;

  /* [implicit_jscontext] void takePicture (in jsval aOptions, in nsICameraTakePictureCallback onSuccess, [optional] in nsICameraErrorCallback onError); */
  NS_IMETHOD TakePicture(const JS::Value & aOptions, nsICameraTakePictureCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx) = 0;

  /* [implicit_jscontext] void getPreviewStreamVideoMode (in jsval aOptions, in nsICameraPreviewStreamCallback onSuccess, [optional] in nsICameraErrorCallback onError); */
  NS_IMETHOD GetPreviewStreamVideoMode(const JS::Value & aOptions, nsICameraPreviewStreamCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx) = 0;

  /* [implicit_jscontext] void startRecording (in jsval aOptions, in nsIDOMDeviceStorage storageArea, in DOMString filename, in nsICameraStartRecordingCallback onSuccess, [optional] in nsICameraErrorCallback onError); */
  NS_IMETHOD StartRecording(const JS::Value & aOptions, nsIDOMDeviceStorage *storageArea, const nsAString & filename, nsICameraStartRecordingCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx) = 0;

  /* void stopRecording (); */
  NS_IMETHOD StopRecording(void) = 0;

  /* [implicit_jscontext] void getPreviewStream (in jsval aOptions, in nsICameraPreviewStreamCallback onSuccess, [optional] in nsICameraErrorCallback onError); */
  NS_IMETHOD GetPreviewStream(const JS::Value & aOptions, nsICameraPreviewStreamCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx) = 0;

  /* void resumePreview (); */
  NS_IMETHOD ResumePreview(void) = 0;

  /* [binaryname(ReleaseHardware)] void release ([optional] in nsICameraReleaseCallback onSuccess, [optional] in nsICameraErrorCallback onError); */
  NS_IMETHOD ReleaseHardware(nsICameraReleaseCallback *onSuccess, nsICameraErrorCallback *onError) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICameraControl, NS_ICAMERACONTROL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICAMERACONTROL \
  NS_IMETHOD GetCapabilities(nsICameraCapabilities * *aCapabilities); \
  NS_IMETHOD GetEffect(nsAString & aEffect); \
  NS_IMETHOD SetEffect(const nsAString & aEffect); \
  NS_IMETHOD GetWhiteBalanceMode(nsAString & aWhiteBalanceMode); \
  NS_IMETHOD SetWhiteBalanceMode(const nsAString & aWhiteBalanceMode); \
  NS_IMETHOD GetSceneMode(nsAString & aSceneMode); \
  NS_IMETHOD SetSceneMode(const nsAString & aSceneMode); \
  NS_IMETHOD GetFlashMode(nsAString & aFlashMode); \
  NS_IMETHOD SetFlashMode(const nsAString & aFlashMode); \
  NS_IMETHOD GetFocusMode(nsAString & aFocusMode); \
  NS_IMETHOD SetFocusMode(const nsAString & aFocusMode); \
  NS_IMETHOD GetZoom(double *aZoom); \
  NS_IMETHOD SetZoom(double aZoom); \
  NS_IMETHOD GetMeteringAreas(JSContext* cx, JS::Value *aMeteringAreas); \
  NS_IMETHOD SetMeteringAreas(JSContext* cx, const JS::Value & aMeteringAreas); \
  NS_IMETHOD GetFocusAreas(JSContext* cx, JS::Value *aFocusAreas); \
  NS_IMETHOD SetFocusAreas(JSContext* cx, const JS::Value & aFocusAreas); \
  NS_IMETHOD GetFocalLength(double *aFocalLength); \
  NS_IMETHOD GetFocusDistanceNear(double *aFocusDistanceNear); \
  NS_IMETHOD GetFocusDistanceOptimum(double *aFocusDistanceOptimum); \
  NS_IMETHOD GetFocusDistanceFar(double *aFocusDistanceFar); \
  NS_IMETHOD SetExposureCompensation(const JS::Value & compensation, JSContext* cx); \
  NS_IMETHOD GetExposureCompensation(double *aExposureCompensation); \
  NS_IMETHOD GetOnShutter(nsICameraShutterCallback * *aOnShutter); \
  NS_IMETHOD SetOnShutter(nsICameraShutterCallback *aOnShutter); \
  NS_IMETHOD GetOnClosed(nsICameraClosedCallback * *aOnClosed); \
  NS_IMETHOD SetOnClosed(nsICameraClosedCallback *aOnClosed); \
  NS_IMETHOD GetOnRecorderStateChange(nsICameraRecorderStateChange * *aOnRecorderStateChange); \
  NS_IMETHOD SetOnRecorderStateChange(nsICameraRecorderStateChange *aOnRecorderStateChange); \
  NS_IMETHOD AutoFocus(nsICameraAutoFocusCallback *onSuccess, nsICameraErrorCallback *onError); \
  NS_IMETHOD TakePicture(const JS::Value & aOptions, nsICameraTakePictureCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx); \
  NS_IMETHOD GetPreviewStreamVideoMode(const JS::Value & aOptions, nsICameraPreviewStreamCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx); \
  NS_IMETHOD StartRecording(const JS::Value & aOptions, nsIDOMDeviceStorage *storageArea, const nsAString & filename, nsICameraStartRecordingCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx); \
  NS_IMETHOD StopRecording(void); \
  NS_IMETHOD GetPreviewStream(const JS::Value & aOptions, nsICameraPreviewStreamCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx); \
  NS_IMETHOD ResumePreview(void); \
  NS_IMETHOD ReleaseHardware(nsICameraReleaseCallback *onSuccess, nsICameraErrorCallback *onError); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICAMERACONTROL(_to) \
  NS_IMETHOD GetCapabilities(nsICameraCapabilities * *aCapabilities) { return _to GetCapabilities(aCapabilities); } \
  NS_IMETHOD GetEffect(nsAString & aEffect) { return _to GetEffect(aEffect); } \
  NS_IMETHOD SetEffect(const nsAString & aEffect) { return _to SetEffect(aEffect); } \
  NS_IMETHOD GetWhiteBalanceMode(nsAString & aWhiteBalanceMode) { return _to GetWhiteBalanceMode(aWhiteBalanceMode); } \
  NS_IMETHOD SetWhiteBalanceMode(const nsAString & aWhiteBalanceMode) { return _to SetWhiteBalanceMode(aWhiteBalanceMode); } \
  NS_IMETHOD GetSceneMode(nsAString & aSceneMode) { return _to GetSceneMode(aSceneMode); } \
  NS_IMETHOD SetSceneMode(const nsAString & aSceneMode) { return _to SetSceneMode(aSceneMode); } \
  NS_IMETHOD GetFlashMode(nsAString & aFlashMode) { return _to GetFlashMode(aFlashMode); } \
  NS_IMETHOD SetFlashMode(const nsAString & aFlashMode) { return _to SetFlashMode(aFlashMode); } \
  NS_IMETHOD GetFocusMode(nsAString & aFocusMode) { return _to GetFocusMode(aFocusMode); } \
  NS_IMETHOD SetFocusMode(const nsAString & aFocusMode) { return _to SetFocusMode(aFocusMode); } \
  NS_IMETHOD GetZoom(double *aZoom) { return _to GetZoom(aZoom); } \
  NS_IMETHOD SetZoom(double aZoom) { return _to SetZoom(aZoom); } \
  NS_IMETHOD GetMeteringAreas(JSContext* cx, JS::Value *aMeteringAreas) { return _to GetMeteringAreas(cx, aMeteringAreas); } \
  NS_IMETHOD SetMeteringAreas(JSContext* cx, const JS::Value & aMeteringAreas) { return _to SetMeteringAreas(cx, aMeteringAreas); } \
  NS_IMETHOD GetFocusAreas(JSContext* cx, JS::Value *aFocusAreas) { return _to GetFocusAreas(cx, aFocusAreas); } \
  NS_IMETHOD SetFocusAreas(JSContext* cx, const JS::Value & aFocusAreas) { return _to SetFocusAreas(cx, aFocusAreas); } \
  NS_IMETHOD GetFocalLength(double *aFocalLength) { return _to GetFocalLength(aFocalLength); } \
  NS_IMETHOD GetFocusDistanceNear(double *aFocusDistanceNear) { return _to GetFocusDistanceNear(aFocusDistanceNear); } \
  NS_IMETHOD GetFocusDistanceOptimum(double *aFocusDistanceOptimum) { return _to GetFocusDistanceOptimum(aFocusDistanceOptimum); } \
  NS_IMETHOD GetFocusDistanceFar(double *aFocusDistanceFar) { return _to GetFocusDistanceFar(aFocusDistanceFar); } \
  NS_IMETHOD SetExposureCompensation(const JS::Value & compensation, JSContext* cx) { return _to SetExposureCompensation(compensation, cx); } \
  NS_IMETHOD GetExposureCompensation(double *aExposureCompensation) { return _to GetExposureCompensation(aExposureCompensation); } \
  NS_IMETHOD GetOnShutter(nsICameraShutterCallback * *aOnShutter) { return _to GetOnShutter(aOnShutter); } \
  NS_IMETHOD SetOnShutter(nsICameraShutterCallback *aOnShutter) { return _to SetOnShutter(aOnShutter); } \
  NS_IMETHOD GetOnClosed(nsICameraClosedCallback * *aOnClosed) { return _to GetOnClosed(aOnClosed); } \
  NS_IMETHOD SetOnClosed(nsICameraClosedCallback *aOnClosed) { return _to SetOnClosed(aOnClosed); } \
  NS_IMETHOD GetOnRecorderStateChange(nsICameraRecorderStateChange * *aOnRecorderStateChange) { return _to GetOnRecorderStateChange(aOnRecorderStateChange); } \
  NS_IMETHOD SetOnRecorderStateChange(nsICameraRecorderStateChange *aOnRecorderStateChange) { return _to SetOnRecorderStateChange(aOnRecorderStateChange); } \
  NS_IMETHOD AutoFocus(nsICameraAutoFocusCallback *onSuccess, nsICameraErrorCallback *onError) { return _to AutoFocus(onSuccess, onError); } \
  NS_IMETHOD TakePicture(const JS::Value & aOptions, nsICameraTakePictureCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx) { return _to TakePicture(aOptions, onSuccess, onError, cx); } \
  NS_IMETHOD GetPreviewStreamVideoMode(const JS::Value & aOptions, nsICameraPreviewStreamCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx) { return _to GetPreviewStreamVideoMode(aOptions, onSuccess, onError, cx); } \
  NS_IMETHOD StartRecording(const JS::Value & aOptions, nsIDOMDeviceStorage *storageArea, const nsAString & filename, nsICameraStartRecordingCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx) { return _to StartRecording(aOptions, storageArea, filename, onSuccess, onError, cx); } \
  NS_IMETHOD StopRecording(void) { return _to StopRecording(); } \
  NS_IMETHOD GetPreviewStream(const JS::Value & aOptions, nsICameraPreviewStreamCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx) { return _to GetPreviewStream(aOptions, onSuccess, onError, cx); } \
  NS_IMETHOD ResumePreview(void) { return _to ResumePreview(); } \
  NS_IMETHOD ReleaseHardware(nsICameraReleaseCallback *onSuccess, nsICameraErrorCallback *onError) { return _to ReleaseHardware(onSuccess, onError); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICAMERACONTROL(_to) \
  NS_IMETHOD GetCapabilities(nsICameraCapabilities * *aCapabilities) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCapabilities(aCapabilities); } \
  NS_IMETHOD GetEffect(nsAString & aEffect) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEffect(aEffect); } \
  NS_IMETHOD SetEffect(const nsAString & aEffect) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEffect(aEffect); } \
  NS_IMETHOD GetWhiteBalanceMode(nsAString & aWhiteBalanceMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWhiteBalanceMode(aWhiteBalanceMode); } \
  NS_IMETHOD SetWhiteBalanceMode(const nsAString & aWhiteBalanceMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWhiteBalanceMode(aWhiteBalanceMode); } \
  NS_IMETHOD GetSceneMode(nsAString & aSceneMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSceneMode(aSceneMode); } \
  NS_IMETHOD SetSceneMode(const nsAString & aSceneMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSceneMode(aSceneMode); } \
  NS_IMETHOD GetFlashMode(nsAString & aFlashMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFlashMode(aFlashMode); } \
  NS_IMETHOD SetFlashMode(const nsAString & aFlashMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFlashMode(aFlashMode); } \
  NS_IMETHOD GetFocusMode(nsAString & aFocusMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocusMode(aFocusMode); } \
  NS_IMETHOD SetFocusMode(const nsAString & aFocusMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFocusMode(aFocusMode); } \
  NS_IMETHOD GetZoom(double *aZoom) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZoom(aZoom); } \
  NS_IMETHOD SetZoom(double aZoom) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetZoom(aZoom); } \
  NS_IMETHOD GetMeteringAreas(JSContext* cx, JS::Value *aMeteringAreas) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMeteringAreas(cx, aMeteringAreas); } \
  NS_IMETHOD SetMeteringAreas(JSContext* cx, const JS::Value & aMeteringAreas) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMeteringAreas(cx, aMeteringAreas); } \
  NS_IMETHOD GetFocusAreas(JSContext* cx, JS::Value *aFocusAreas) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocusAreas(cx, aFocusAreas); } \
  NS_IMETHOD SetFocusAreas(JSContext* cx, const JS::Value & aFocusAreas) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFocusAreas(cx, aFocusAreas); } \
  NS_IMETHOD GetFocalLength(double *aFocalLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocalLength(aFocalLength); } \
  NS_IMETHOD GetFocusDistanceNear(double *aFocusDistanceNear) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocusDistanceNear(aFocusDistanceNear); } \
  NS_IMETHOD GetFocusDistanceOptimum(double *aFocusDistanceOptimum) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocusDistanceOptimum(aFocusDistanceOptimum); } \
  NS_IMETHOD GetFocusDistanceFar(double *aFocusDistanceFar) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocusDistanceFar(aFocusDistanceFar); } \
  NS_IMETHOD SetExposureCompensation(const JS::Value & compensation, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExposureCompensation(compensation, cx); } \
  NS_IMETHOD GetExposureCompensation(double *aExposureCompensation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExposureCompensation(aExposureCompensation); } \
  NS_IMETHOD GetOnShutter(nsICameraShutterCallback * *aOnShutter) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnShutter(aOnShutter); } \
  NS_IMETHOD SetOnShutter(nsICameraShutterCallback *aOnShutter) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnShutter(aOnShutter); } \
  NS_IMETHOD GetOnClosed(nsICameraClosedCallback * *aOnClosed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnClosed(aOnClosed); } \
  NS_IMETHOD SetOnClosed(nsICameraClosedCallback *aOnClosed) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnClosed(aOnClosed); } \
  NS_IMETHOD GetOnRecorderStateChange(nsICameraRecorderStateChange * *aOnRecorderStateChange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnRecorderStateChange(aOnRecorderStateChange); } \
  NS_IMETHOD SetOnRecorderStateChange(nsICameraRecorderStateChange *aOnRecorderStateChange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnRecorderStateChange(aOnRecorderStateChange); } \
  NS_IMETHOD AutoFocus(nsICameraAutoFocusCallback *onSuccess, nsICameraErrorCallback *onError) { return !_to ? NS_ERROR_NULL_POINTER : _to->AutoFocus(onSuccess, onError); } \
  NS_IMETHOD TakePicture(const JS::Value & aOptions, nsICameraTakePictureCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->TakePicture(aOptions, onSuccess, onError, cx); } \
  NS_IMETHOD GetPreviewStreamVideoMode(const JS::Value & aOptions, nsICameraPreviewStreamCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreviewStreamVideoMode(aOptions, onSuccess, onError, cx); } \
  NS_IMETHOD StartRecording(const JS::Value & aOptions, nsIDOMDeviceStorage *storageArea, const nsAString & filename, nsICameraStartRecordingCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartRecording(aOptions, storageArea, filename, onSuccess, onError, cx); } \
  NS_IMETHOD StopRecording(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StopRecording(); } \
  NS_IMETHOD GetPreviewStream(const JS::Value & aOptions, nsICameraPreviewStreamCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreviewStream(aOptions, onSuccess, onError, cx); } \
  NS_IMETHOD ResumePreview(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResumePreview(); } \
  NS_IMETHOD ReleaseHardware(nsICameraReleaseCallback *onSuccess, nsICameraErrorCallback *onError) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReleaseHardware(onSuccess, onError); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCameraControl : public nsICameraControl
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICAMERACONTROL

  nsCameraControl();

private:
  ~nsCameraControl();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCameraControl, nsICameraControl)

nsCameraControl::nsCameraControl()
{
  /* member initializers and constructor code */
}

nsCameraControl::~nsCameraControl()
{
  /* destructor code */
}

/* readonly attribute nsICameraCapabilities capabilities; */
NS_IMETHODIMP nsCameraControl::GetCapabilities(nsICameraCapabilities * *aCapabilities)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString effect; */
NS_IMETHODIMP nsCameraControl::GetEffect(nsAString & aEffect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCameraControl::SetEffect(const nsAString & aEffect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString whiteBalanceMode; */
NS_IMETHODIMP nsCameraControl::GetWhiteBalanceMode(nsAString & aWhiteBalanceMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCameraControl::SetWhiteBalanceMode(const nsAString & aWhiteBalanceMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString sceneMode; */
NS_IMETHODIMP nsCameraControl::GetSceneMode(nsAString & aSceneMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCameraControl::SetSceneMode(const nsAString & aSceneMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString flashMode; */
NS_IMETHODIMP nsCameraControl::GetFlashMode(nsAString & aFlashMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCameraControl::SetFlashMode(const nsAString & aFlashMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString focusMode; */
NS_IMETHODIMP nsCameraControl::GetFocusMode(nsAString & aFocusMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCameraControl::SetFocusMode(const nsAString & aFocusMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double zoom; */
NS_IMETHODIMP nsCameraControl::GetZoom(double *aZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCameraControl::SetZoom(double aZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval meteringAreas; */
NS_IMETHODIMP nsCameraControl::GetMeteringAreas(JSContext* cx, JS::Value *aMeteringAreas)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCameraControl::SetMeteringAreas(JSContext* cx, const JS::Value & aMeteringAreas)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval focusAreas; */
NS_IMETHODIMP nsCameraControl::GetFocusAreas(JSContext* cx, JS::Value *aFocusAreas)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCameraControl::SetFocusAreas(JSContext* cx, const JS::Value & aFocusAreas)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double focalLength; */
NS_IMETHODIMP nsCameraControl::GetFocalLength(double *aFocalLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double focusDistanceNear; */
NS_IMETHODIMP nsCameraControl::GetFocusDistanceNear(double *aFocusDistanceNear)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double focusDistanceOptimum; */
NS_IMETHODIMP nsCameraControl::GetFocusDistanceOptimum(double *aFocusDistanceOptimum)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double focusDistanceFar; */
NS_IMETHODIMP nsCameraControl::GetFocusDistanceFar(double *aFocusDistanceFar)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void setExposureCompensation ([optional] in jsval compensation); */
NS_IMETHODIMP nsCameraControl::SetExposureCompensation(const JS::Value & compensation, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double exposureCompensation; */
NS_IMETHODIMP nsCameraControl::GetExposureCompensation(double *aExposureCompensation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsICameraShutterCallback onShutter; */
NS_IMETHODIMP nsCameraControl::GetOnShutter(nsICameraShutterCallback * *aOnShutter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCameraControl::SetOnShutter(nsICameraShutterCallback *aOnShutter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsICameraClosedCallback onClosed; */
NS_IMETHODIMP nsCameraControl::GetOnClosed(nsICameraClosedCallback * *aOnClosed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCameraControl::SetOnClosed(nsICameraClosedCallback *aOnClosed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsICameraRecorderStateChange onRecorderStateChange; */
NS_IMETHODIMP nsCameraControl::GetOnRecorderStateChange(nsICameraRecorderStateChange * *aOnRecorderStateChange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCameraControl::SetOnRecorderStateChange(nsICameraRecorderStateChange *aOnRecorderStateChange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void autoFocus (in nsICameraAutoFocusCallback onSuccess, [optional] in nsICameraErrorCallback onError); */
NS_IMETHODIMP nsCameraControl::AutoFocus(nsICameraAutoFocusCallback *onSuccess, nsICameraErrorCallback *onError)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void takePicture (in jsval aOptions, in nsICameraTakePictureCallback onSuccess, [optional] in nsICameraErrorCallback onError); */
NS_IMETHODIMP nsCameraControl::TakePicture(const JS::Value & aOptions, nsICameraTakePictureCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void getPreviewStreamVideoMode (in jsval aOptions, in nsICameraPreviewStreamCallback onSuccess, [optional] in nsICameraErrorCallback onError); */
NS_IMETHODIMP nsCameraControl::GetPreviewStreamVideoMode(const JS::Value & aOptions, nsICameraPreviewStreamCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void startRecording (in jsval aOptions, in nsIDOMDeviceStorage storageArea, in DOMString filename, in nsICameraStartRecordingCallback onSuccess, [optional] in nsICameraErrorCallback onError); */
NS_IMETHODIMP nsCameraControl::StartRecording(const JS::Value & aOptions, nsIDOMDeviceStorage *storageArea, const nsAString & filename, nsICameraStartRecordingCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stopRecording (); */
NS_IMETHODIMP nsCameraControl::StopRecording()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void getPreviewStream (in jsval aOptions, in nsICameraPreviewStreamCallback onSuccess, [optional] in nsICameraErrorCallback onError); */
NS_IMETHODIMP nsCameraControl::GetPreviewStream(const JS::Value & aOptions, nsICameraPreviewStreamCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resumePreview (); */
NS_IMETHODIMP nsCameraControl::ResumePreview()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(ReleaseHardware)] void release ([optional] in nsICameraReleaseCallback onSuccess, [optional] in nsICameraErrorCallback onError); */
NS_IMETHODIMP nsCameraControl::ReleaseHardware(nsICameraReleaseCallback *onSuccess, nsICameraErrorCallback *onError)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICameraGetCameraCallback */
#define NS_ICAMERAGETCAMERACALLBACK_IID_STR "a267afbc-d91c-413a-8de5-0b94aecffa3e"

#define NS_ICAMERAGETCAMERACALLBACK_IID \
  {0xa267afbc, 0xd91c, 0x413a, \
    { 0x8d, 0xe5, 0x0b, 0x94, 0xae, 0xcf, 0xfa, 0x3e }}

class NS_NO_VTABLE nsICameraGetCameraCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICAMERAGETCAMERACALLBACK_IID)

  /* void handleEvent (in nsICameraControl camera); */
  NS_IMETHOD HandleEvent(nsICameraControl *camera) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICameraGetCameraCallback, NS_ICAMERAGETCAMERACALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICAMERAGETCAMERACALLBACK \
  NS_IMETHOD HandleEvent(nsICameraControl *camera); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICAMERAGETCAMERACALLBACK(_to) \
  NS_IMETHOD HandleEvent(nsICameraControl *camera) { return _to HandleEvent(camera); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICAMERAGETCAMERACALLBACK(_to) \
  NS_IMETHOD HandleEvent(nsICameraControl *camera) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEvent(camera); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCameraGetCameraCallback : public nsICameraGetCameraCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICAMERAGETCAMERACALLBACK

  nsCameraGetCameraCallback();

private:
  ~nsCameraGetCameraCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCameraGetCameraCallback, nsICameraGetCameraCallback)

nsCameraGetCameraCallback::nsCameraGetCameraCallback()
{
  /* member initializers and constructor code */
}

nsCameraGetCameraCallback::~nsCameraGetCameraCallback()
{
  /* destructor code */
}

/* void handleEvent (in nsICameraControl camera); */
NS_IMETHODIMP nsCameraGetCameraCallback::HandleEvent(nsICameraControl *camera)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMCameraManager */
#define NS_IDOMCAMERAMANAGER_IID_STR "671ee624-0336-441a-a24e-26b5319f14fe"

#define NS_IDOMCAMERAMANAGER_IID \
  {0x671ee624, 0x0336, 0x441a, \
    { 0xa2, 0x4e, 0x26, 0xb5, 0x31, 0x9f, 0x14, 0xfe }}

class NS_NO_VTABLE nsIDOMCameraManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCAMERAMANAGER_IID)

  /* [implicit_jscontext] void getCamera ([optional] in jsval aOptions, in nsICameraGetCameraCallback onSuccess, [optional] in nsICameraErrorCallback onError); */
  NS_IMETHOD GetCamera(const JS::Value & aOptions, nsICameraGetCameraCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx) = 0;

  /* [implicit_jscontext] jsval getListOfCameras (); */
  NS_IMETHOD GetListOfCameras(JSContext* cx, JS::Value *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCameraManager, NS_IDOMCAMERAMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCAMERAMANAGER \
  NS_IMETHOD GetCamera(const JS::Value & aOptions, nsICameraGetCameraCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx); \
  NS_IMETHOD GetListOfCameras(JSContext* cx, JS::Value *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCAMERAMANAGER(_to) \
  NS_IMETHOD GetCamera(const JS::Value & aOptions, nsICameraGetCameraCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx) { return _to GetCamera(aOptions, onSuccess, onError, cx); } \
  NS_IMETHOD GetListOfCameras(JSContext* cx, JS::Value *_retval) { return _to GetListOfCameras(cx, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCAMERAMANAGER(_to) \
  NS_IMETHOD GetCamera(const JS::Value & aOptions, nsICameraGetCameraCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCamera(aOptions, onSuccess, onError, cx); } \
  NS_IMETHOD GetListOfCameras(JSContext* cx, JS::Value *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetListOfCameras(cx, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCameraManager : public nsIDOMCameraManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCAMERAMANAGER

  nsDOMCameraManager();

private:
  ~nsDOMCameraManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCameraManager, nsIDOMCameraManager)

nsDOMCameraManager::nsDOMCameraManager()
{
  /* member initializers and constructor code */
}

nsDOMCameraManager::~nsDOMCameraManager()
{
  /* destructor code */
}

/* [implicit_jscontext] void getCamera ([optional] in jsval aOptions, in nsICameraGetCameraCallback onSuccess, [optional] in nsICameraErrorCallback onError); */
NS_IMETHODIMP nsDOMCameraManager::GetCamera(const JS::Value & aOptions, nsICameraGetCameraCallback *onSuccess, nsICameraErrorCallback *onError, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getListOfCameras (); */
NS_IMETHODIMP nsDOMCameraManager::GetListOfCameras(JSContext* cx, JS::Value *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCameraManager_h__ */

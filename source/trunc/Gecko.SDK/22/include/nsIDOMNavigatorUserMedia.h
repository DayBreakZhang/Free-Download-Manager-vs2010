/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/media/nsIDOMNavigatorUserMedia.idl
 */

#ifndef __gen_nsIDOMNavigatorUserMedia_h__
#define __gen_nsIDOMNavigatorUserMedia_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIVariant_h__
#include "nsIVariant.h"
#endif

#ifndef __gen_nsIDOMMediaStream_h__
#include "nsIDOMMediaStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMediaDevice */
#define NS_IMEDIADEVICE_IID_STR "6de854f9-acf8-4383-b464-4803631ef309"

#define NS_IMEDIADEVICE_IID \
  {0x6de854f9, 0xacf8, 0x4383, \
    { 0xb4, 0x64, 0x48, 0x03, 0x63, 0x1e, 0xf3, 0x09 }}

class NS_NO_VTABLE nsIMediaDevice : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMEDIADEVICE_IID)

  /* readonly attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;

  /* readonly attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute DOMString id; */
  NS_IMETHOD GetId(nsAString & aId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMediaDevice, NS_IMEDIADEVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMEDIADEVICE \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD GetId(nsAString & aId); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMEDIADEVICE(_to) \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD GetId(nsAString & aId) { return _to GetId(aId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMEDIADEVICE(_to) \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetId(nsAString & aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMediaDevice : public nsIMediaDevice
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMEDIADEVICE

  nsMediaDevice();

private:
  ~nsMediaDevice();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMediaDevice, nsIMediaDevice)

nsMediaDevice::nsMediaDevice()
{
  /* member initializers and constructor code */
}

nsMediaDevice::~nsMediaDevice()
{
  /* destructor code */
}

/* readonly attribute DOMString type; */
NS_IMETHODIMP nsMediaDevice::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString name; */
NS_IMETHODIMP nsMediaDevice::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString id; */
NS_IMETHODIMP nsMediaDevice::GetId(nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIGetUserMediaDevicesSuccessCallback */
#define NS_IGETUSERMEDIADEVICESSUCCESSCALLBACK_IID_STR "24544878-d35e-4962-8c5f-fb84e97bdfee"

#define NS_IGETUSERMEDIADEVICESSUCCESSCALLBACK_IID \
  {0x24544878, 0xd35e, 0x4962, \
    { 0x8c, 0x5f, 0xfb, 0x84, 0xe9, 0x7b, 0xdf, 0xee }}

class NS_NO_VTABLE nsIGetUserMediaDevicesSuccessCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGETUSERMEDIADEVICESSUCCESSCALLBACK_IID)

  /* void onSuccess (in nsIVariant devices); */
  NS_IMETHOD OnSuccess(nsIVariant *devices) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGetUserMediaDevicesSuccessCallback, NS_IGETUSERMEDIADEVICESSUCCESSCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGETUSERMEDIADEVICESSUCCESSCALLBACK \
  NS_IMETHOD OnSuccess(nsIVariant *devices); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGETUSERMEDIADEVICESSUCCESSCALLBACK(_to) \
  NS_IMETHOD OnSuccess(nsIVariant *devices) { return _to OnSuccess(devices); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGETUSERMEDIADEVICESSUCCESSCALLBACK(_to) \
  NS_IMETHOD OnSuccess(nsIVariant *devices) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSuccess(devices); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGetUserMediaDevicesSuccessCallback : public nsIGetUserMediaDevicesSuccessCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGETUSERMEDIADEVICESSUCCESSCALLBACK

  nsGetUserMediaDevicesSuccessCallback();

private:
  ~nsGetUserMediaDevicesSuccessCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsGetUserMediaDevicesSuccessCallback, nsIGetUserMediaDevicesSuccessCallback)

nsGetUserMediaDevicesSuccessCallback::nsGetUserMediaDevicesSuccessCallback()
{
  /* member initializers and constructor code */
}

nsGetUserMediaDevicesSuccessCallback::~nsGetUserMediaDevicesSuccessCallback()
{
  /* destructor code */
}

/* void onSuccess (in nsIVariant devices); */
NS_IMETHODIMP nsGetUserMediaDevicesSuccessCallback::OnSuccess(nsIVariant *devices)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMGetUserMediaSuccessCallback */
#define NS_IDOMGETUSERMEDIASUCCESSCALLBACK_IID_STR "f2a144fc-3534-4761-8c5d-989ae720f89a"

#define NS_IDOMGETUSERMEDIASUCCESSCALLBACK_IID \
  {0xf2a144fc, 0x3534, 0x4761, \
    { 0x8c, 0x5d, 0x98, 0x9a, 0xe7, 0x20, 0xf8, 0x9a }}

class NS_NO_VTABLE nsIDOMGetUserMediaSuccessCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGETUSERMEDIASUCCESSCALLBACK_IID)

  /* void onSuccess (in nsISupports value); */
  NS_IMETHOD OnSuccess(nsISupports *value) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGetUserMediaSuccessCallback, NS_IDOMGETUSERMEDIASUCCESSCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGETUSERMEDIASUCCESSCALLBACK \
  NS_IMETHOD OnSuccess(nsISupports *value); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGETUSERMEDIASUCCESSCALLBACK(_to) \
  NS_IMETHOD OnSuccess(nsISupports *value) { return _to OnSuccess(value); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGETUSERMEDIASUCCESSCALLBACK(_to) \
  NS_IMETHOD OnSuccess(nsISupports *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSuccess(value); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGetUserMediaSuccessCallback : public nsIDOMGetUserMediaSuccessCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGETUSERMEDIASUCCESSCALLBACK

  nsDOMGetUserMediaSuccessCallback();

private:
  ~nsDOMGetUserMediaSuccessCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMGetUserMediaSuccessCallback, nsIDOMGetUserMediaSuccessCallback)

nsDOMGetUserMediaSuccessCallback::nsDOMGetUserMediaSuccessCallback()
{
  /* member initializers and constructor code */
}

nsDOMGetUserMediaSuccessCallback::~nsDOMGetUserMediaSuccessCallback()
{
  /* destructor code */
}

/* void onSuccess (in nsISupports value); */
NS_IMETHODIMP nsDOMGetUserMediaSuccessCallback::OnSuccess(nsISupports *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMGetUserMediaErrorCallback */
#define NS_IDOMGETUSERMEDIAERRORCALLBACK_IID_STR "2614bbcf-85cc-43e5-8740-964f52bdc7ca"

#define NS_IDOMGETUSERMEDIAERRORCALLBACK_IID \
  {0x2614bbcf, 0x85cc, 0x43e5, \
    { 0x87, 0x40, 0x96, 0x4f, 0x52, 0xbd, 0xc7, 0xca }}

class NS_NO_VTABLE nsIDOMGetUserMediaErrorCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGETUSERMEDIAERRORCALLBACK_IID)

  /* void onError (in DOMString error); */
  NS_IMETHOD OnError(const nsAString & error) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGetUserMediaErrorCallback, NS_IDOMGETUSERMEDIAERRORCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGETUSERMEDIAERRORCALLBACK \
  NS_IMETHOD OnError(const nsAString & error); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGETUSERMEDIAERRORCALLBACK(_to) \
  NS_IMETHOD OnError(const nsAString & error) { return _to OnError(error); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGETUSERMEDIAERRORCALLBACK(_to) \
  NS_IMETHOD OnError(const nsAString & error) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnError(error); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGetUserMediaErrorCallback : public nsIDOMGetUserMediaErrorCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGETUSERMEDIAERRORCALLBACK

  nsDOMGetUserMediaErrorCallback();

private:
  ~nsDOMGetUserMediaErrorCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMGetUserMediaErrorCallback, nsIDOMGetUserMediaErrorCallback)

nsDOMGetUserMediaErrorCallback::nsDOMGetUserMediaErrorCallback()
{
  /* member initializers and constructor code */
}

nsDOMGetUserMediaErrorCallback::~nsDOMGetUserMediaErrorCallback()
{
  /* destructor code */
}

/* void onError (in DOMString error); */
NS_IMETHODIMP nsDOMGetUserMediaErrorCallback::OnError(const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIMediaStreamOptions */
#define NS_IMEDIASTREAMOPTIONS_IID_STR "f34a3616-395a-43cd-b275-bf81750ac8b9"

#define NS_IMEDIASTREAMOPTIONS_IID \
  {0xf34a3616, 0x395a, 0x43cd, \
    { 0xb2, 0x75, 0xbf, 0x81, 0x75, 0x0a, 0xc8, 0xb9 }}

class NS_NO_VTABLE nsIMediaStreamOptions : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMEDIASTREAMOPTIONS_IID)

  /* readonly attribute boolean fake; */
  NS_IMETHOD GetFake(bool *aFake) = 0;

  /* readonly attribute boolean audio; */
  NS_IMETHOD GetAudio(bool *aAudio) = 0;

  /* readonly attribute boolean video; */
  NS_IMETHOD GetVideo(bool *aVideo) = 0;

  /* readonly attribute boolean picture; */
  NS_IMETHOD GetPicture(bool *aPicture) = 0;

  /* readonly attribute DOMString camera; */
  NS_IMETHOD GetCamera(nsAString & aCamera) = 0;

  /* readonly attribute nsIMediaDevice audioDevice; */
  NS_IMETHOD GetAudioDevice(nsIMediaDevice * *aAudioDevice) = 0;

  /* readonly attribute nsIMediaDevice videoDevice; */
  NS_IMETHOD GetVideoDevice(nsIMediaDevice * *aVideoDevice) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMediaStreamOptions, NS_IMEDIASTREAMOPTIONS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMEDIASTREAMOPTIONS \
  NS_IMETHOD GetFake(bool *aFake); \
  NS_IMETHOD GetAudio(bool *aAudio); \
  NS_IMETHOD GetVideo(bool *aVideo); \
  NS_IMETHOD GetPicture(bool *aPicture); \
  NS_IMETHOD GetCamera(nsAString & aCamera); \
  NS_IMETHOD GetAudioDevice(nsIMediaDevice * *aAudioDevice); \
  NS_IMETHOD GetVideoDevice(nsIMediaDevice * *aVideoDevice); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMEDIASTREAMOPTIONS(_to) \
  NS_IMETHOD GetFake(bool *aFake) { return _to GetFake(aFake); } \
  NS_IMETHOD GetAudio(bool *aAudio) { return _to GetAudio(aAudio); } \
  NS_IMETHOD GetVideo(bool *aVideo) { return _to GetVideo(aVideo); } \
  NS_IMETHOD GetPicture(bool *aPicture) { return _to GetPicture(aPicture); } \
  NS_IMETHOD GetCamera(nsAString & aCamera) { return _to GetCamera(aCamera); } \
  NS_IMETHOD GetAudioDevice(nsIMediaDevice * *aAudioDevice) { return _to GetAudioDevice(aAudioDevice); } \
  NS_IMETHOD GetVideoDevice(nsIMediaDevice * *aVideoDevice) { return _to GetVideoDevice(aVideoDevice); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMEDIASTREAMOPTIONS(_to) \
  NS_IMETHOD GetFake(bool *aFake) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFake(aFake); } \
  NS_IMETHOD GetAudio(bool *aAudio) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAudio(aAudio); } \
  NS_IMETHOD GetVideo(bool *aVideo) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVideo(aVideo); } \
  NS_IMETHOD GetPicture(bool *aPicture) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPicture(aPicture); } \
  NS_IMETHOD GetCamera(nsAString & aCamera) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCamera(aCamera); } \
  NS_IMETHOD GetAudioDevice(nsIMediaDevice * *aAudioDevice) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAudioDevice(aAudioDevice); } \
  NS_IMETHOD GetVideoDevice(nsIMediaDevice * *aVideoDevice) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVideoDevice(aVideoDevice); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMediaStreamOptions : public nsIMediaStreamOptions
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMEDIASTREAMOPTIONS

  nsMediaStreamOptions();

private:
  ~nsMediaStreamOptions();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMediaStreamOptions, nsIMediaStreamOptions)

nsMediaStreamOptions::nsMediaStreamOptions()
{
  /* member initializers and constructor code */
}

nsMediaStreamOptions::~nsMediaStreamOptions()
{
  /* destructor code */
}

/* readonly attribute boolean fake; */
NS_IMETHODIMP nsMediaStreamOptions::GetFake(bool *aFake)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean audio; */
NS_IMETHODIMP nsMediaStreamOptions::GetAudio(bool *aAudio)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean video; */
NS_IMETHODIMP nsMediaStreamOptions::GetVideo(bool *aVideo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean picture; */
NS_IMETHODIMP nsMediaStreamOptions::GetPicture(bool *aPicture)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString camera; */
NS_IMETHODIMP nsMediaStreamOptions::GetCamera(nsAString & aCamera)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIMediaDevice audioDevice; */
NS_IMETHODIMP nsMediaStreamOptions::GetAudioDevice(nsIMediaDevice * *aAudioDevice)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIMediaDevice videoDevice; */
NS_IMETHODIMP nsMediaStreamOptions::GetVideoDevice(nsIMediaDevice * *aVideoDevice)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMNavigatorUserMedia */
#define NS_IDOMNAVIGATORUSERMEDIA_IID_STR "381e0071-0be5-4f6b-ae21-8e3407a37faa"

#define NS_IDOMNAVIGATORUSERMEDIA_IID \
  {0x381e0071, 0x0be5, 0x4f6b, \
    { 0xae, 0x21, 0x8e, 0x34, 0x07, 0xa3, 0x7f, 0xaa }}

class NS_NO_VTABLE nsIDOMNavigatorUserMedia : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNAVIGATORUSERMEDIA_IID)

  /* void mozGetUserMedia (in nsIMediaStreamOptions params, in nsIDOMGetUserMediaSuccessCallback onsuccess, in nsIDOMGetUserMediaErrorCallback onerror); */
  NS_IMETHOD MozGetUserMedia(nsIMediaStreamOptions *params, nsIDOMGetUserMediaSuccessCallback *onsuccess, nsIDOMGetUserMediaErrorCallback *onerror) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNavigatorUserMedia, NS_IDOMNAVIGATORUSERMEDIA_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNAVIGATORUSERMEDIA \
  NS_IMETHOD MozGetUserMedia(nsIMediaStreamOptions *params, nsIDOMGetUserMediaSuccessCallback *onsuccess, nsIDOMGetUserMediaErrorCallback *onerror); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNAVIGATORUSERMEDIA(_to) \
  NS_IMETHOD MozGetUserMedia(nsIMediaStreamOptions *params, nsIDOMGetUserMediaSuccessCallback *onsuccess, nsIDOMGetUserMediaErrorCallback *onerror) { return _to MozGetUserMedia(params, onsuccess, onerror); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNAVIGATORUSERMEDIA(_to) \
  NS_IMETHOD MozGetUserMedia(nsIMediaStreamOptions *params, nsIDOMGetUserMediaSuccessCallback *onsuccess, nsIDOMGetUserMediaErrorCallback *onerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozGetUserMedia(params, onsuccess, onerror); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNavigatorUserMedia : public nsIDOMNavigatorUserMedia
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNAVIGATORUSERMEDIA

  nsDOMNavigatorUserMedia();

private:
  ~nsDOMNavigatorUserMedia();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNavigatorUserMedia, nsIDOMNavigatorUserMedia)

nsDOMNavigatorUserMedia::nsDOMNavigatorUserMedia()
{
  /* member initializers and constructor code */
}

nsDOMNavigatorUserMedia::~nsDOMNavigatorUserMedia()
{
  /* destructor code */
}

/* void mozGetUserMedia (in nsIMediaStreamOptions params, in nsIDOMGetUserMediaSuccessCallback onsuccess, in nsIDOMGetUserMediaErrorCallback onerror); */
NS_IMETHODIMP nsDOMNavigatorUserMedia::MozGetUserMedia(nsIMediaStreamOptions *params, nsIDOMGetUserMediaSuccessCallback *onsuccess, nsIDOMGetUserMediaErrorCallback *onerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavigatorUserMedia */
#define NS_INAVIGATORUSERMEDIA_IID_STR "20e9c794-fdfe-43f4-a81b-ebd9069e0af1"

#define NS_INAVIGATORUSERMEDIA_IID \
  {0x20e9c794, 0xfdfe, 0x43f4, \
    { 0xa8, 0x1b, 0xeb, 0xd9, 0x06, 0x9e, 0x0a, 0xf1 }}

class NS_NO_VTABLE nsINavigatorUserMedia : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVIGATORUSERMEDIA_IID)

  /* void mozGetUserMediaDevices (in nsIGetUserMediaDevicesSuccessCallback onsuccess, in nsIDOMGetUserMediaErrorCallback onerror); */
  NS_IMETHOD MozGetUserMediaDevices(nsIGetUserMediaDevicesSuccessCallback *onsuccess, nsIDOMGetUserMediaErrorCallback *onerror) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavigatorUserMedia, NS_INAVIGATORUSERMEDIA_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVIGATORUSERMEDIA \
  NS_IMETHOD MozGetUserMediaDevices(nsIGetUserMediaDevicesSuccessCallback *onsuccess, nsIDOMGetUserMediaErrorCallback *onerror); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVIGATORUSERMEDIA(_to) \
  NS_IMETHOD MozGetUserMediaDevices(nsIGetUserMediaDevicesSuccessCallback *onsuccess, nsIDOMGetUserMediaErrorCallback *onerror) { return _to MozGetUserMediaDevices(onsuccess, onerror); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVIGATORUSERMEDIA(_to) \
  NS_IMETHOD MozGetUserMediaDevices(nsIGetUserMediaDevicesSuccessCallback *onsuccess, nsIDOMGetUserMediaErrorCallback *onerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozGetUserMediaDevices(onsuccess, onerror); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavigatorUserMedia : public nsINavigatorUserMedia
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVIGATORUSERMEDIA

  nsNavigatorUserMedia();

private:
  ~nsNavigatorUserMedia();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavigatorUserMedia, nsINavigatorUserMedia)

nsNavigatorUserMedia::nsNavigatorUserMedia()
{
  /* member initializers and constructor code */
}

nsNavigatorUserMedia::~nsNavigatorUserMedia()
{
  /* destructor code */
}

/* void mozGetUserMediaDevices (in nsIGetUserMediaDevicesSuccessCallback onsuccess, in nsIDOMGetUserMediaErrorCallback onerror); */
NS_IMETHODIMP nsNavigatorUserMedia::MozGetUserMediaDevices(nsIGetUserMediaDevicesSuccessCallback *onsuccess, nsIDOMGetUserMediaErrorCallback *onerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNavigatorUserMedia_h__ */

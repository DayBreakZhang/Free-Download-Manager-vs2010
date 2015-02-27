/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISpeechService.idl
 */

#ifndef __gen_nsISpeechService_h__
#define __gen_nsISpeechService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
typedef uint16_t  SpeechServiceType;


/* starting interface:    nsISpeechTaskCallback */
#define NS_ISPEECHTASKCALLBACK_IID_STR "408251b0-1d7b-4876-888f-718859ce8c9d"

#define NS_ISPEECHTASKCALLBACK_IID \
  {0x408251b0, 0x1d7b, 0x4876, \
    { 0x88, 0x8f, 0x71, 0x88, 0x59, 0xce, 0x8c, 0x9d }}

class NS_NO_VTABLE nsISpeechTaskCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISPEECHTASKCALLBACK_IID)

  /* void onPause (); */
  NS_IMETHOD OnPause(void) = 0;

  /* void onResume (); */
  NS_IMETHOD OnResume(void) = 0;

  /* void onCancel (); */
  NS_IMETHOD OnCancel(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISpeechTaskCallback, NS_ISPEECHTASKCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISPEECHTASKCALLBACK \
  NS_IMETHOD OnPause(void); \
  NS_IMETHOD OnResume(void); \
  NS_IMETHOD OnCancel(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISPEECHTASKCALLBACK(_to) \
  NS_IMETHOD OnPause(void) { return _to OnPause(); } \
  NS_IMETHOD OnResume(void) { return _to OnResume(); } \
  NS_IMETHOD OnCancel(void) { return _to OnCancel(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISPEECHTASKCALLBACK(_to) \
  NS_IMETHOD OnPause(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnPause(); } \
  NS_IMETHOD OnResume(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnResume(); } \
  NS_IMETHOD OnCancel(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCancel(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSpeechTaskCallback : public nsISpeechTaskCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISPEECHTASKCALLBACK

  nsSpeechTaskCallback();

private:
  ~nsSpeechTaskCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSpeechTaskCallback, nsISpeechTaskCallback)

nsSpeechTaskCallback::nsSpeechTaskCallback()
{
  /* member initializers and constructor code */
}

nsSpeechTaskCallback::~nsSpeechTaskCallback()
{
  /* destructor code */
}

/* void onPause (); */
NS_IMETHODIMP nsSpeechTaskCallback::OnPause()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onResume (); */
NS_IMETHODIMP nsSpeechTaskCallback::OnResume()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onCancel (); */
NS_IMETHODIMP nsSpeechTaskCallback::OnCancel()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISpeechTask */
#define NS_ISPEECHTASK_IID_STR "ad59949c-2437-4b35-8eeb-d760caab75c5"

#define NS_ISPEECHTASK_IID \
  {0xad59949c, 0x2437, 0x4b35, \
    { 0x8e, 0xeb, 0xd7, 0x60, 0xca, 0xab, 0x75, 0xc5 }}

class NS_NO_VTABLE nsISpeechTask : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISPEECHTASK_IID)

  /* [optional_argc] void setup (in nsISpeechTaskCallback aCallback, [optional] in uint32_t aChannels, [optional] in uint32_t aRate); */
  NS_IMETHOD Setup(nsISpeechTaskCallback *aCallback, uint32_t aChannels, uint32_t aRate, uint8_t _argc) = 0;

  /* [implicit_jscontext] void sendAudio (in jsval aData, in jsval aLandmarks); */
  NS_IMETHOD SendAudio(JS::HandleValue aData, JS::HandleValue aLandmarks, JSContext* cx) = 0;

  /* [noscript] void sendAudioNative ([array, size_is (aDataLen)] in short aData, in unsigned long aDataLen); */
  NS_IMETHOD SendAudioNative(int16_t *aData, uint32_t aDataLen) = 0;

  /* void dispatchStart (); */
  NS_IMETHOD DispatchStart(void) = 0;

  /* void dispatchEnd (in float aElapsedTime, in unsigned long aCharIndex); */
  NS_IMETHOD DispatchEnd(float aElapsedTime, uint32_t aCharIndex) = 0;

  /* void dispatchPause (in float aElapsedTime, in unsigned long aCharIndex); */
  NS_IMETHOD DispatchPause(float aElapsedTime, uint32_t aCharIndex) = 0;

  /* void dispatchResume (in float aElapsedTime, in unsigned long aCharIndex); */
  NS_IMETHOD DispatchResume(float aElapsedTime, uint32_t aCharIndex) = 0;

  /* void dispatchError (in float aElapsedTime, in unsigned long aCharIndex); */
  NS_IMETHOD DispatchError(float aElapsedTime, uint32_t aCharIndex) = 0;

  /* void dispatchBoundary (in DOMString aName, in float aElapsedTime, in unsigned long aCharIndex); */
  NS_IMETHOD DispatchBoundary(const nsAString & aName, float aElapsedTime, uint32_t aCharIndex) = 0;

  /* void dispatchMark (in DOMString aName, in float aElapsedTime, in unsigned long aCharIndex); */
  NS_IMETHOD DispatchMark(const nsAString & aName, float aElapsedTime, uint32_t aCharIndex) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISpeechTask, NS_ISPEECHTASK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISPEECHTASK \
  NS_IMETHOD Setup(nsISpeechTaskCallback *aCallback, uint32_t aChannels, uint32_t aRate, uint8_t _argc); \
  NS_IMETHOD SendAudio(JS::HandleValue aData, JS::HandleValue aLandmarks, JSContext* cx); \
  NS_IMETHOD SendAudioNative(int16_t *aData, uint32_t aDataLen); \
  NS_IMETHOD DispatchStart(void); \
  NS_IMETHOD DispatchEnd(float aElapsedTime, uint32_t aCharIndex); \
  NS_IMETHOD DispatchPause(float aElapsedTime, uint32_t aCharIndex); \
  NS_IMETHOD DispatchResume(float aElapsedTime, uint32_t aCharIndex); \
  NS_IMETHOD DispatchError(float aElapsedTime, uint32_t aCharIndex); \
  NS_IMETHOD DispatchBoundary(const nsAString & aName, float aElapsedTime, uint32_t aCharIndex); \
  NS_IMETHOD DispatchMark(const nsAString & aName, float aElapsedTime, uint32_t aCharIndex); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISPEECHTASK(_to) \
  NS_IMETHOD Setup(nsISpeechTaskCallback *aCallback, uint32_t aChannels, uint32_t aRate, uint8_t _argc) { return _to Setup(aCallback, aChannels, aRate, _argc); } \
  NS_IMETHOD SendAudio(JS::HandleValue aData, JS::HandleValue aLandmarks, JSContext* cx) { return _to SendAudio(aData, aLandmarks, cx); } \
  NS_IMETHOD SendAudioNative(int16_t *aData, uint32_t aDataLen) { return _to SendAudioNative(aData, aDataLen); } \
  NS_IMETHOD DispatchStart(void) { return _to DispatchStart(); } \
  NS_IMETHOD DispatchEnd(float aElapsedTime, uint32_t aCharIndex) { return _to DispatchEnd(aElapsedTime, aCharIndex); } \
  NS_IMETHOD DispatchPause(float aElapsedTime, uint32_t aCharIndex) { return _to DispatchPause(aElapsedTime, aCharIndex); } \
  NS_IMETHOD DispatchResume(float aElapsedTime, uint32_t aCharIndex) { return _to DispatchResume(aElapsedTime, aCharIndex); } \
  NS_IMETHOD DispatchError(float aElapsedTime, uint32_t aCharIndex) { return _to DispatchError(aElapsedTime, aCharIndex); } \
  NS_IMETHOD DispatchBoundary(const nsAString & aName, float aElapsedTime, uint32_t aCharIndex) { return _to DispatchBoundary(aName, aElapsedTime, aCharIndex); } \
  NS_IMETHOD DispatchMark(const nsAString & aName, float aElapsedTime, uint32_t aCharIndex) { return _to DispatchMark(aName, aElapsedTime, aCharIndex); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISPEECHTASK(_to) \
  NS_IMETHOD Setup(nsISpeechTaskCallback *aCallback, uint32_t aChannels, uint32_t aRate, uint8_t _argc) { return !_to ? NS_ERROR_NULL_POINTER : _to->Setup(aCallback, aChannels, aRate, _argc); } \
  NS_IMETHOD SendAudio(JS::HandleValue aData, JS::HandleValue aLandmarks, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendAudio(aData, aLandmarks, cx); } \
  NS_IMETHOD SendAudioNative(int16_t *aData, uint32_t aDataLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendAudioNative(aData, aDataLen); } \
  NS_IMETHOD DispatchStart(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DispatchStart(); } \
  NS_IMETHOD DispatchEnd(float aElapsedTime, uint32_t aCharIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->DispatchEnd(aElapsedTime, aCharIndex); } \
  NS_IMETHOD DispatchPause(float aElapsedTime, uint32_t aCharIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->DispatchPause(aElapsedTime, aCharIndex); } \
  NS_IMETHOD DispatchResume(float aElapsedTime, uint32_t aCharIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->DispatchResume(aElapsedTime, aCharIndex); } \
  NS_IMETHOD DispatchError(float aElapsedTime, uint32_t aCharIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->DispatchError(aElapsedTime, aCharIndex); } \
  NS_IMETHOD DispatchBoundary(const nsAString & aName, float aElapsedTime, uint32_t aCharIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->DispatchBoundary(aName, aElapsedTime, aCharIndex); } \
  NS_IMETHOD DispatchMark(const nsAString & aName, float aElapsedTime, uint32_t aCharIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->DispatchMark(aName, aElapsedTime, aCharIndex); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSpeechTask : public nsISpeechTask
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISPEECHTASK

  nsSpeechTask();

private:
  ~nsSpeechTask();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSpeechTask, nsISpeechTask)

nsSpeechTask::nsSpeechTask()
{
  /* member initializers and constructor code */
}

nsSpeechTask::~nsSpeechTask()
{
  /* destructor code */
}

/* [optional_argc] void setup (in nsISpeechTaskCallback aCallback, [optional] in uint32_t aChannels, [optional] in uint32_t aRate); */
NS_IMETHODIMP nsSpeechTask::Setup(nsISpeechTaskCallback *aCallback, uint32_t aChannels, uint32_t aRate, uint8_t _argc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void sendAudio (in jsval aData, in jsval aLandmarks); */
NS_IMETHODIMP nsSpeechTask::SendAudio(JS::HandleValue aData, JS::HandleValue aLandmarks, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void sendAudioNative ([array, size_is (aDataLen)] in short aData, in unsigned long aDataLen); */
NS_IMETHODIMP nsSpeechTask::SendAudioNative(int16_t *aData, uint32_t aDataLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dispatchStart (); */
NS_IMETHODIMP nsSpeechTask::DispatchStart()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dispatchEnd (in float aElapsedTime, in unsigned long aCharIndex); */
NS_IMETHODIMP nsSpeechTask::DispatchEnd(float aElapsedTime, uint32_t aCharIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dispatchPause (in float aElapsedTime, in unsigned long aCharIndex); */
NS_IMETHODIMP nsSpeechTask::DispatchPause(float aElapsedTime, uint32_t aCharIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dispatchResume (in float aElapsedTime, in unsigned long aCharIndex); */
NS_IMETHODIMP nsSpeechTask::DispatchResume(float aElapsedTime, uint32_t aCharIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dispatchError (in float aElapsedTime, in unsigned long aCharIndex); */
NS_IMETHODIMP nsSpeechTask::DispatchError(float aElapsedTime, uint32_t aCharIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dispatchBoundary (in DOMString aName, in float aElapsedTime, in unsigned long aCharIndex); */
NS_IMETHODIMP nsSpeechTask::DispatchBoundary(const nsAString & aName, float aElapsedTime, uint32_t aCharIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dispatchMark (in DOMString aName, in float aElapsedTime, in unsigned long aCharIndex); */
NS_IMETHODIMP nsSpeechTask::DispatchMark(const nsAString & aName, float aElapsedTime, uint32_t aCharIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISpeechService */
#define NS_ISPEECHSERVICE_IID_STR "3952d388-050c-47ba-a70f-5fc1cadf1db0"

#define NS_ISPEECHSERVICE_IID \
  {0x3952d388, 0x050c, 0x47ba, \
    { 0xa7, 0x0f, 0x5f, 0xc1, 0xca, 0xdf, 0x1d, 0xb0 }}

class NS_NO_VTABLE nsISpeechService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISPEECHSERVICE_IID)

  /* void speak (in DOMString aText, in DOMString aUri, in float aRate, in float aPitch, in nsISpeechTask aTask); */
  NS_IMETHOD Speak(const nsAString & aText, const nsAString & aUri, float aRate, float aPitch, nsISpeechTask *aTask) = 0;

  enum {
    SERVICETYPE_DIRECT_AUDIO = 1U,
    SERVICETYPE_INDIRECT_AUDIO = 2U
  };

  /* readonly attribute SpeechServiceType serviceType; */
  NS_IMETHOD GetServiceType(SpeechServiceType *aServiceType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISpeechService, NS_ISPEECHSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISPEECHSERVICE \
  NS_IMETHOD Speak(const nsAString & aText, const nsAString & aUri, float aRate, float aPitch, nsISpeechTask *aTask); \
  NS_IMETHOD GetServiceType(SpeechServiceType *aServiceType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISPEECHSERVICE(_to) \
  NS_IMETHOD Speak(const nsAString & aText, const nsAString & aUri, float aRate, float aPitch, nsISpeechTask *aTask) { return _to Speak(aText, aUri, aRate, aPitch, aTask); } \
  NS_IMETHOD GetServiceType(SpeechServiceType *aServiceType) { return _to GetServiceType(aServiceType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISPEECHSERVICE(_to) \
  NS_IMETHOD Speak(const nsAString & aText, const nsAString & aUri, float aRate, float aPitch, nsISpeechTask *aTask) { return !_to ? NS_ERROR_NULL_POINTER : _to->Speak(aText, aUri, aRate, aPitch, aTask); } \
  NS_IMETHOD GetServiceType(SpeechServiceType *aServiceType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetServiceType(aServiceType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSpeechService : public nsISpeechService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISPEECHSERVICE

  nsSpeechService();

private:
  ~nsSpeechService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSpeechService, nsISpeechService)

nsSpeechService::nsSpeechService()
{
  /* member initializers and constructor code */
}

nsSpeechService::~nsSpeechService()
{
  /* destructor code */
}

/* void speak (in DOMString aText, in DOMString aUri, in float aRate, in float aPitch, in nsISpeechTask aTask); */
NS_IMETHODIMP nsSpeechService::Speak(const nsAString & aText, const nsAString & aUri, float aRate, float aPitch, nsISpeechTask *aTask)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute SpeechServiceType serviceType; */
NS_IMETHODIMP nsSpeechService::GetServiceType(SpeechServiceType *aServiceType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISpeechService_h__ */

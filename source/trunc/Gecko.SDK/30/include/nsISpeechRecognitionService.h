/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISpeechRecognitionService.idl
 */

#ifndef __gen_nsISpeechRecognitionService_h__
#define __gen_nsISpeechRecognitionService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "mozilla/WeakPtr.h"

/* starting interface:    nsISpeechRecognitionService */
#define NS_ISPEECHRECOGNITIONSERVICE_IID_STR "cb98d929-81cd-4a51-a214-80d3e6281d24"

#define NS_ISPEECHRECOGNITIONSERVICE_IID \
  {0xcb98d929, 0x81cd, 0x4a51, \
    { 0xa2, 0x14, 0x80, 0xd3, 0xe6, 0x28, 0x1d, 0x24 }}

class NS_NO_VTABLE nsISpeechRecognitionService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISPEECHRECOGNITIONSERVICE_IID)

  /* void initialize (in SpeechRecognitionWeakPtr aSpeechRecognition); */
  NS_IMETHOD Initialize(mozilla::WeakPtr<mozilla::dom::SpeechRecognition> aSpeechRecognition) = 0;

  /* void processAudioSegment (in AudioSegmentPtr aAudioSegment); */
  NS_IMETHOD ProcessAudioSegment(mozilla::AudioSegment *aAudioSegment) = 0;

  /* void soundEnd (); */
  NS_IMETHOD SoundEnd(void) = 0;

  /* void abort (); */
  NS_IMETHOD Abort(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISpeechRecognitionService, NS_ISPEECHRECOGNITIONSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISPEECHRECOGNITIONSERVICE \
  NS_IMETHOD Initialize(mozilla::WeakPtr<mozilla::dom::SpeechRecognition> aSpeechRecognition); \
  NS_IMETHOD ProcessAudioSegment(mozilla::AudioSegment *aAudioSegment); \
  NS_IMETHOD SoundEnd(void); \
  NS_IMETHOD Abort(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISPEECHRECOGNITIONSERVICE(_to) \
  NS_IMETHOD Initialize(mozilla::WeakPtr<mozilla::dom::SpeechRecognition> aSpeechRecognition) { return _to Initialize(aSpeechRecognition); } \
  NS_IMETHOD ProcessAudioSegment(mozilla::AudioSegment *aAudioSegment) { return _to ProcessAudioSegment(aAudioSegment); } \
  NS_IMETHOD SoundEnd(void) { return _to SoundEnd(); } \
  NS_IMETHOD Abort(void) { return _to Abort(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISPEECHRECOGNITIONSERVICE(_to) \
  NS_IMETHOD Initialize(mozilla::WeakPtr<mozilla::dom::SpeechRecognition> aSpeechRecognition) { return !_to ? NS_ERROR_NULL_POINTER : _to->Initialize(aSpeechRecognition); } \
  NS_IMETHOD ProcessAudioSegment(mozilla::AudioSegment *aAudioSegment) { return !_to ? NS_ERROR_NULL_POINTER : _to->ProcessAudioSegment(aAudioSegment); } \
  NS_IMETHOD SoundEnd(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SoundEnd(); } \
  NS_IMETHOD Abort(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Abort(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSpeechRecognitionService : public nsISpeechRecognitionService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISPEECHRECOGNITIONSERVICE

  nsSpeechRecognitionService();

private:
  ~nsSpeechRecognitionService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSpeechRecognitionService, nsISpeechRecognitionService)

nsSpeechRecognitionService::nsSpeechRecognitionService()
{
  /* member initializers and constructor code */
}

nsSpeechRecognitionService::~nsSpeechRecognitionService()
{
  /* destructor code */
}

/* void initialize (in SpeechRecognitionWeakPtr aSpeechRecognition); */
NS_IMETHODIMP nsSpeechRecognitionService::Initialize(mozilla::WeakPtr<mozilla::dom::SpeechRecognition> aSpeechRecognition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void processAudioSegment (in AudioSegmentPtr aAudioSegment); */
NS_IMETHODIMP nsSpeechRecognitionService::ProcessAudioSegment(mozilla::AudioSegment *aAudioSegment)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void soundEnd (); */
NS_IMETHODIMP nsSpeechRecognitionService::SoundEnd()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void abort (); */
NS_IMETHODIMP nsSpeechRecognitionService::Abort()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_SPEECH_RECOGNITION_SERVICE_CONTRACTID_PREFIX "@mozilla.org/webspeech/service;1?name="

#endif /* __gen_nsISpeechRecognitionService_h__ */

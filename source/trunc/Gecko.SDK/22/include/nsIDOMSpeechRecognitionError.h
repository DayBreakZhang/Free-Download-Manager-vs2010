/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/content/media/webspeech/recognition/nsIDOMSpeechRecognitionError.idl
 */

#ifndef __gen_nsIDOMSpeechRecognitionError_h__
#define __gen_nsIDOMSpeechRecognitionError_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSpeechRecognitionError */
#define NS_IDOMSPEECHRECOGNITIONERROR_IID_STR "5ddc5a46-e7db-4c5c-8ed4-80cf5d88fca3"

#define NS_IDOMSPEECHRECOGNITIONERROR_IID \
  {0x5ddc5a46, 0xe7db, 0x4c5c, \
    { 0x8e, 0xd4, 0x80, 0xcf, 0x5d, 0x88, 0xfc, 0xa3 }}

class NS_NO_VTABLE nsIDOMSpeechRecognitionError : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSPEECHRECOGNITIONERROR_IID)

  enum {
    NO_SPEECH = 0U,
    ABORTED = 1U,
    AUDIO_CAPTURE = 2U,
    NETWORK = 3U,
    NOT_ALLOWED = 4U,
    SERVICE_NOT_ALLOWED = 5U,
    BAD_GRAMMAR = 6U,
    LANGUAGE_NOT_SUPPORTED = 7U
  };

  /* [noscript] void initSpeechRecognitionError (in DOMString eventTypeArg, in boolean canBubbleArg, in boolean cancelableArg, in unsigned long error, in DOMString message); */
  NS_IMETHOD InitSpeechRecognitionError(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, uint32_t error, const nsAString & message) = 0;

  /* readonly attribute unsigned long error; */
  NS_IMETHOD GetError(uint32_t *aError) = 0;

  /* readonly attribute DOMString message; */
  NS_IMETHOD GetMessage(nsAString & aMessage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSpeechRecognitionError, NS_IDOMSPEECHRECOGNITIONERROR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSPEECHRECOGNITIONERROR \
  NS_IMETHOD InitSpeechRecognitionError(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, uint32_t error, const nsAString & message); \
  NS_IMETHOD GetError(uint32_t *aError); \
  NS_IMETHOD GetMessage(nsAString & aMessage); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSPEECHRECOGNITIONERROR(_to) \
  NS_IMETHOD InitSpeechRecognitionError(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, uint32_t error, const nsAString & message) { return _to InitSpeechRecognitionError(eventTypeArg, canBubbleArg, cancelableArg, error, message); } \
  NS_IMETHOD GetError(uint32_t *aError) { return _to GetError(aError); } \
  NS_IMETHOD GetMessage(nsAString & aMessage) { return _to GetMessage(aMessage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSPEECHRECOGNITIONERROR(_to) \
  NS_IMETHOD InitSpeechRecognitionError(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, uint32_t error, const nsAString & message) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitSpeechRecognitionError(eventTypeArg, canBubbleArg, cancelableArg, error, message); } \
  NS_IMETHOD GetError(uint32_t *aError) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetError(aError); } \
  NS_IMETHOD GetMessage(nsAString & aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessage(aMessage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSpeechRecognitionError : public nsIDOMSpeechRecognitionError
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSPEECHRECOGNITIONERROR

  nsDOMSpeechRecognitionError();

private:
  ~nsDOMSpeechRecognitionError();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSpeechRecognitionError, nsIDOMSpeechRecognitionError)

nsDOMSpeechRecognitionError::nsDOMSpeechRecognitionError()
{
  /* member initializers and constructor code */
}

nsDOMSpeechRecognitionError::~nsDOMSpeechRecognitionError()
{
  /* destructor code */
}

/* [noscript] void initSpeechRecognitionError (in DOMString eventTypeArg, in boolean canBubbleArg, in boolean cancelableArg, in unsigned long error, in DOMString message); */
NS_IMETHODIMP nsDOMSpeechRecognitionError::InitSpeechRecognitionError(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, uint32_t error, const nsAString & message)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long error; */
NS_IMETHODIMP nsDOMSpeechRecognitionError::GetError(uint32_t *aError)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString message; */
NS_IMETHODIMP nsDOMSpeechRecognitionError::GetMessage(nsAString & aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSpeechRecognitionError_h__ */

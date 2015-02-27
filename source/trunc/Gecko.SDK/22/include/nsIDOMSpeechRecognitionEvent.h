/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/content/media/webspeech/recognition/nsIDOMSpeechRecognitionEvent.idl
 */

#ifndef __gen_nsIDOMSpeechRecognitionEvent_h__
#define __gen_nsIDOMSpeechRecognitionEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class SpeechRecognitionResultList; /* forward declaration */


/* starting interface:    nsIDOMSpeechRecognitionEvent */
#define NS_IDOMSPEECHRECOGNITIONEVENT_IID_STR "98dded70-33af-42d5-819d-e15b6f4a3aba"

#define NS_IDOMSPEECHRECOGNITIONEVENT_IID \
  {0x98dded70, 0x33af, 0x42d5, \
    { 0x81, 0x9d, 0xe1, 0x5b, 0x6f, 0x4a, 0x3a, 0xba }}

class NS_NO_VTABLE nsIDOMSpeechRecognitionEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSPEECHRECOGNITIONEVENT_IID)

  /* [noscript] void initSpeechRecognitionEvent (in DOMString eventTypeArg, in boolean canBubbleArg, in boolean cancelableArg, in unsigned long resultIndex, in nsISupports results, in DOMString interpretation, in nsIDOMDocument emma); */
  NS_IMETHOD InitSpeechRecognitionEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, uint32_t resultIndex, nsISupports *results, const nsAString & interpretation, nsIDOMDocument *emma) = 0;

  /* readonly attribute unsigned long resultIndex; */
  NS_IMETHOD GetResultIndex(uint32_t *aResultIndex) = 0;

  /* readonly attribute nsISupports results; */
  NS_IMETHOD GetResults(nsISupports * *aResults) = 0;

  /* readonly attribute DOMString interpretation; */
  NS_IMETHOD GetInterpretation(nsAString & aInterpretation) = 0;

  /* readonly attribute nsIDOMDocument emma; */
  NS_IMETHOD GetEmma(nsIDOMDocument * *aEmma) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSpeechRecognitionEvent, NS_IDOMSPEECHRECOGNITIONEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSPEECHRECOGNITIONEVENT \
  NS_IMETHOD InitSpeechRecognitionEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, uint32_t resultIndex, nsISupports *results, const nsAString & interpretation, nsIDOMDocument *emma); \
  NS_IMETHOD GetResultIndex(uint32_t *aResultIndex); \
  NS_IMETHOD GetResults(nsISupports * *aResults); \
  NS_IMETHOD GetInterpretation(nsAString & aInterpretation); \
  NS_IMETHOD GetEmma(nsIDOMDocument * *aEmma); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSPEECHRECOGNITIONEVENT(_to) \
  NS_IMETHOD InitSpeechRecognitionEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, uint32_t resultIndex, nsISupports *results, const nsAString & interpretation, nsIDOMDocument *emma) { return _to InitSpeechRecognitionEvent(eventTypeArg, canBubbleArg, cancelableArg, resultIndex, results, interpretation, emma); } \
  NS_IMETHOD GetResultIndex(uint32_t *aResultIndex) { return _to GetResultIndex(aResultIndex); } \
  NS_IMETHOD GetResults(nsISupports * *aResults) { return _to GetResults(aResults); } \
  NS_IMETHOD GetInterpretation(nsAString & aInterpretation) { return _to GetInterpretation(aInterpretation); } \
  NS_IMETHOD GetEmma(nsIDOMDocument * *aEmma) { return _to GetEmma(aEmma); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSPEECHRECOGNITIONEVENT(_to) \
  NS_IMETHOD InitSpeechRecognitionEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, uint32_t resultIndex, nsISupports *results, const nsAString & interpretation, nsIDOMDocument *emma) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitSpeechRecognitionEvent(eventTypeArg, canBubbleArg, cancelableArg, resultIndex, results, interpretation, emma); } \
  NS_IMETHOD GetResultIndex(uint32_t *aResultIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResultIndex(aResultIndex); } \
  NS_IMETHOD GetResults(nsISupports * *aResults) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResults(aResults); } \
  NS_IMETHOD GetInterpretation(nsAString & aInterpretation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterpretation(aInterpretation); } \
  NS_IMETHOD GetEmma(nsIDOMDocument * *aEmma) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEmma(aEmma); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSpeechRecognitionEvent : public nsIDOMSpeechRecognitionEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSPEECHRECOGNITIONEVENT

  nsDOMSpeechRecognitionEvent();

private:
  ~nsDOMSpeechRecognitionEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSpeechRecognitionEvent, nsIDOMSpeechRecognitionEvent)

nsDOMSpeechRecognitionEvent::nsDOMSpeechRecognitionEvent()
{
  /* member initializers and constructor code */
}

nsDOMSpeechRecognitionEvent::~nsDOMSpeechRecognitionEvent()
{
  /* destructor code */
}

/* [noscript] void initSpeechRecognitionEvent (in DOMString eventTypeArg, in boolean canBubbleArg, in boolean cancelableArg, in unsigned long resultIndex, in nsISupports results, in DOMString interpretation, in nsIDOMDocument emma); */
NS_IMETHODIMP nsDOMSpeechRecognitionEvent::InitSpeechRecognitionEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, uint32_t resultIndex, nsISupports *results, const nsAString & interpretation, nsIDOMDocument *emma)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long resultIndex; */
NS_IMETHODIMP nsDOMSpeechRecognitionEvent::GetResultIndex(uint32_t *aResultIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports results; */
NS_IMETHODIMP nsDOMSpeechRecognitionEvent::GetResults(nsISupports * *aResults)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString interpretation; */
NS_IMETHODIMP nsDOMSpeechRecognitionEvent::GetInterpretation(nsAString & aInterpretation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDocument emma; */
NS_IMETHODIMP nsDOMSpeechRecognitionEvent::GetEmma(nsIDOMDocument * *aEmma)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSpeechRecognitionEvent_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMSpeechSynthesisEvent.idl
 */

#ifndef __gen_nsIDOMSpeechSynthesisEvent_h__
#define __gen_nsIDOMSpeechSynthesisEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSpeechSynthesisEvent */
#define NS_IDOMSPEECHSYNTHESISEVENT_IID_STR "b5240841-dc69-43dd-bcf1-9306b8ddaa09"

#define NS_IDOMSPEECHSYNTHESISEVENT_IID \
  {0xb5240841, 0xdc69, 0x43dd, \
    { 0xbc, 0xf1, 0x93, 0x06, 0xb8, 0xdd, 0xaa, 0x09 }}

class NS_NO_VTABLE nsIDOMSpeechSynthesisEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSPEECHSYNTHESISEVENT_IID)

  /* [noscript] void initSpeechSynthesisEvent (in DOMString aEventTypeArg, in boolean aCanBubbleArg, in boolean aCancelableArg, in unsigned long aCharIndex, in float aElapsedTime, in DOMString aName); */
  NS_IMETHOD InitSpeechSynthesisEvent(const nsAString & aEventTypeArg, bool aCanBubbleArg, bool aCancelableArg, uint32_t aCharIndex, float aElapsedTime, const nsAString & aName) = 0;

  /* readonly attribute unsigned long charIndex; */
  NS_IMETHOD GetCharIndex(uint32_t *aCharIndex) = 0;

  /* readonly attribute float elapsedTime; */
  NS_IMETHOD GetElapsedTime(float *aElapsedTime) = 0;

  /* readonly attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSpeechSynthesisEvent, NS_IDOMSPEECHSYNTHESISEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSPEECHSYNTHESISEVENT \
  NS_IMETHOD InitSpeechSynthesisEvent(const nsAString & aEventTypeArg, bool aCanBubbleArg, bool aCancelableArg, uint32_t aCharIndex, float aElapsedTime, const nsAString & aName); \
  NS_IMETHOD GetCharIndex(uint32_t *aCharIndex); \
  NS_IMETHOD GetElapsedTime(float *aElapsedTime); \
  NS_IMETHOD GetName(nsAString & aName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSPEECHSYNTHESISEVENT(_to) \
  NS_IMETHOD InitSpeechSynthesisEvent(const nsAString & aEventTypeArg, bool aCanBubbleArg, bool aCancelableArg, uint32_t aCharIndex, float aElapsedTime, const nsAString & aName) { return _to InitSpeechSynthesisEvent(aEventTypeArg, aCanBubbleArg, aCancelableArg, aCharIndex, aElapsedTime, aName); } \
  NS_IMETHOD GetCharIndex(uint32_t *aCharIndex) { return _to GetCharIndex(aCharIndex); } \
  NS_IMETHOD GetElapsedTime(float *aElapsedTime) { return _to GetElapsedTime(aElapsedTime); } \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSPEECHSYNTHESISEVENT(_to) \
  NS_IMETHOD InitSpeechSynthesisEvent(const nsAString & aEventTypeArg, bool aCanBubbleArg, bool aCancelableArg, uint32_t aCharIndex, float aElapsedTime, const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitSpeechSynthesisEvent(aEventTypeArg, aCanBubbleArg, aCancelableArg, aCharIndex, aElapsedTime, aName); } \
  NS_IMETHOD GetCharIndex(uint32_t *aCharIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharIndex(aCharIndex); } \
  NS_IMETHOD GetElapsedTime(float *aElapsedTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElapsedTime(aElapsedTime); } \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSpeechSynthesisEvent : public nsIDOMSpeechSynthesisEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSPEECHSYNTHESISEVENT

  nsDOMSpeechSynthesisEvent();

private:
  ~nsDOMSpeechSynthesisEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSpeechSynthesisEvent, nsIDOMSpeechSynthesisEvent)

nsDOMSpeechSynthesisEvent::nsDOMSpeechSynthesisEvent()
{
  /* member initializers and constructor code */
}

nsDOMSpeechSynthesisEvent::~nsDOMSpeechSynthesisEvent()
{
  /* destructor code */
}

/* [noscript] void initSpeechSynthesisEvent (in DOMString aEventTypeArg, in boolean aCanBubbleArg, in boolean aCancelableArg, in unsigned long aCharIndex, in float aElapsedTime, in DOMString aName); */
NS_IMETHODIMP nsDOMSpeechSynthesisEvent::InitSpeechSynthesisEvent(const nsAString & aEventTypeArg, bool aCanBubbleArg, bool aCancelableArg, uint32_t aCharIndex, float aElapsedTime, const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long charIndex; */
NS_IMETHODIMP nsDOMSpeechSynthesisEvent::GetCharIndex(uint32_t *aCharIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float elapsedTime; */
NS_IMETHODIMP nsDOMSpeechSynthesisEvent::GetElapsedTime(float *aElapsedTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString name; */
NS_IMETHODIMP nsDOMSpeechSynthesisEvent::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSpeechSynthesisEvent_h__ */

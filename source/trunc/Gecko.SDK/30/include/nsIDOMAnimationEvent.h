/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMAnimationEvent.idl
 */

#ifndef __gen_nsIDOMAnimationEvent_h__
#define __gen_nsIDOMAnimationEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMAnimationEvent */
#define NS_IDOMANIMATIONEVENT_IID_STR "b1bea1bc-689b-4e07-8cbc-ef342725f9a6"

#define NS_IDOMANIMATIONEVENT_IID \
  {0xb1bea1bc, 0x689b, 0x4e07, \
    { 0x8c, 0xbc, 0xef, 0x34, 0x27, 0x25, 0xf9, 0xa6 }}

class NS_NO_VTABLE nsIDOMAnimationEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMANIMATIONEVENT_IID)

  /* readonly attribute DOMString animationName; */
  NS_IMETHOD GetAnimationName(nsAString & aAnimationName) = 0;

  /* readonly attribute float elapsedTime; */
  NS_IMETHOD GetElapsedTime(float *aElapsedTime) = 0;

  /* readonly attribute DOMString pseudoElement; */
  NS_IMETHOD GetPseudoElement(nsAString & aPseudoElement) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMAnimationEvent, NS_IDOMANIMATIONEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMANIMATIONEVENT \
  NS_IMETHOD GetAnimationName(nsAString & aAnimationName); \
  NS_IMETHOD GetElapsedTime(float *aElapsedTime); \
  NS_IMETHOD GetPseudoElement(nsAString & aPseudoElement); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMANIMATIONEVENT(_to) \
  NS_IMETHOD GetAnimationName(nsAString & aAnimationName) { return _to GetAnimationName(aAnimationName); } \
  NS_IMETHOD GetElapsedTime(float *aElapsedTime) { return _to GetElapsedTime(aElapsedTime); } \
  NS_IMETHOD GetPseudoElement(nsAString & aPseudoElement) { return _to GetPseudoElement(aPseudoElement); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMANIMATIONEVENT(_to) \
  NS_IMETHOD GetAnimationName(nsAString & aAnimationName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnimationName(aAnimationName); } \
  NS_IMETHOD GetElapsedTime(float *aElapsedTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElapsedTime(aElapsedTime); } \
  NS_IMETHOD GetPseudoElement(nsAString & aPseudoElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPseudoElement(aPseudoElement); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMAnimationEvent : public nsIDOMAnimationEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMANIMATIONEVENT

  nsDOMAnimationEvent();

private:
  ~nsDOMAnimationEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMAnimationEvent, nsIDOMAnimationEvent)

nsDOMAnimationEvent::nsDOMAnimationEvent()
{
  /* member initializers and constructor code */
}

nsDOMAnimationEvent::~nsDOMAnimationEvent()
{
  /* destructor code */
}

/* readonly attribute DOMString animationName; */
NS_IMETHODIMP nsDOMAnimationEvent::GetAnimationName(nsAString & aAnimationName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float elapsedTime; */
NS_IMETHODIMP nsDOMAnimationEvent::GetElapsedTime(float *aElapsedTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString pseudoElement; */
NS_IMETHODIMP nsDOMAnimationEvent::GetPseudoElement(nsAString & aPseudoElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMAnimationEvent_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMTransitionEvent.idl
 */

#ifndef __gen_nsIDOMTransitionEvent_h__
#define __gen_nsIDOMTransitionEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMTransitionEvent */
#define NS_IDOMTRANSITIONEVENT_IID_STR "a37171e0-9f43-41ea-a25c-0b78a3329683"

#define NS_IDOMTRANSITIONEVENT_IID \
  {0xa37171e0, 0x9f43, 0x41ea, \
    { 0xa2, 0x5c, 0x0b, 0x78, 0xa3, 0x32, 0x96, 0x83 }}

class NS_NO_VTABLE nsIDOMTransitionEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMTRANSITIONEVENT_IID)

  /* readonly attribute DOMString propertyName; */
  NS_IMETHOD GetPropertyName(nsAString & aPropertyName) = 0;

  /* readonly attribute float elapsedTime; */
  NS_IMETHOD GetElapsedTime(float *aElapsedTime) = 0;

  /* readonly attribute DOMString pseudoElement; */
  NS_IMETHOD GetPseudoElement(nsAString & aPseudoElement) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMTransitionEvent, NS_IDOMTRANSITIONEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMTRANSITIONEVENT \
  NS_IMETHOD GetPropertyName(nsAString & aPropertyName); \
  NS_IMETHOD GetElapsedTime(float *aElapsedTime); \
  NS_IMETHOD GetPseudoElement(nsAString & aPseudoElement); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMTRANSITIONEVENT(_to) \
  NS_IMETHOD GetPropertyName(nsAString & aPropertyName) { return _to GetPropertyName(aPropertyName); } \
  NS_IMETHOD GetElapsedTime(float *aElapsedTime) { return _to GetElapsedTime(aElapsedTime); } \
  NS_IMETHOD GetPseudoElement(nsAString & aPseudoElement) { return _to GetPseudoElement(aPseudoElement); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMTRANSITIONEVENT(_to) \
  NS_IMETHOD GetPropertyName(nsAString & aPropertyName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPropertyName(aPropertyName); } \
  NS_IMETHOD GetElapsedTime(float *aElapsedTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElapsedTime(aElapsedTime); } \
  NS_IMETHOD GetPseudoElement(nsAString & aPseudoElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPseudoElement(aPseudoElement); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMTransitionEvent : public nsIDOMTransitionEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMTRANSITIONEVENT

  nsDOMTransitionEvent();

private:
  ~nsDOMTransitionEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMTransitionEvent, nsIDOMTransitionEvent)

nsDOMTransitionEvent::nsDOMTransitionEvent()
{
  /* member initializers and constructor code */
}

nsDOMTransitionEvent::~nsDOMTransitionEvent()
{
  /* destructor code */
}

/* readonly attribute DOMString propertyName; */
NS_IMETHODIMP nsDOMTransitionEvent::GetPropertyName(nsAString & aPropertyName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float elapsedTime; */
NS_IMETHODIMP nsDOMTransitionEvent::GetElapsedTime(float *aElapsedTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString pseudoElement; */
NS_IMETHODIMP nsDOMTransitionEvent::GetPseudoElement(nsAString & aPseudoElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMTransitionEvent_h__ */

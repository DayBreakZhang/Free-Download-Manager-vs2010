/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMTransitionEvent.idl
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
#define NS_IDOMTRANSITIONEVENT_IID_STR "9013310a-e376-40bc-b141-9b9ae3085daa"

#define NS_IDOMTRANSITIONEVENT_IID \
  {0x9013310a, 0xe376, 0x40bc, \
    { 0xb1, 0x41, 0x9b, 0x9a, 0xe3, 0x08, 0x5d, 0xaa }}

class NS_NO_VTABLE nsIDOMTransitionEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMTRANSITIONEVENT_IID)

  /* readonly attribute DOMString propertyName; */
  NS_IMETHOD GetPropertyName(nsAString & aPropertyName) = 0;

  /* readonly attribute float elapsedTime; */
  NS_IMETHOD GetElapsedTime(float *aElapsedTime) = 0;

  /* void initTransitionEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in DOMString propertyNameArg, in float elapsedTimeArg); */
  NS_IMETHOD InitTransitionEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & propertyNameArg, float elapsedTimeArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMTransitionEvent, NS_IDOMTRANSITIONEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMTRANSITIONEVENT \
  NS_IMETHOD GetPropertyName(nsAString & aPropertyName); \
  NS_IMETHOD GetElapsedTime(float *aElapsedTime); \
  NS_IMETHOD InitTransitionEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & propertyNameArg, float elapsedTimeArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMTRANSITIONEVENT(_to) \
  NS_IMETHOD GetPropertyName(nsAString & aPropertyName) { return _to GetPropertyName(aPropertyName); } \
  NS_IMETHOD GetElapsedTime(float *aElapsedTime) { return _to GetElapsedTime(aElapsedTime); } \
  NS_IMETHOD InitTransitionEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & propertyNameArg, float elapsedTimeArg) { return _to InitTransitionEvent(typeArg, canBubbleArg, cancelableArg, propertyNameArg, elapsedTimeArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMTRANSITIONEVENT(_to) \
  NS_IMETHOD GetPropertyName(nsAString & aPropertyName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPropertyName(aPropertyName); } \
  NS_IMETHOD GetElapsedTime(float *aElapsedTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElapsedTime(aElapsedTime); } \
  NS_IMETHOD InitTransitionEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & propertyNameArg, float elapsedTimeArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitTransitionEvent(typeArg, canBubbleArg, cancelableArg, propertyNameArg, elapsedTimeArg); } 

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

/* void initTransitionEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in DOMString propertyNameArg, in float elapsedTimeArg); */
NS_IMETHODIMP nsDOMTransitionEvent::InitTransitionEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & propertyNameArg, float elapsedTimeArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMTransitionEvent_h__ */

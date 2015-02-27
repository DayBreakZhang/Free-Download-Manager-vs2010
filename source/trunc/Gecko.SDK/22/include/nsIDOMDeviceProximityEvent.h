/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMDeviceProximityEvent.idl
 */

#ifndef __gen_nsIDOMDeviceProximityEvent_h__
#define __gen_nsIDOMDeviceProximityEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDeviceProximityEvent */
#define NS_IDOMDEVICEPROXIMITYEVENT_IID_STR "86c7c396-9c2b-4d45-9c7c-b0dcda024105"

#define NS_IDOMDEVICEPROXIMITYEVENT_IID \
  {0x86c7c396, 0x9c2b, 0x4d45, \
    { 0x9c, 0x7c, 0xb0, 0xdc, 0xda, 0x02, 0x41, 0x05 }}

class NS_NO_VTABLE nsIDOMDeviceProximityEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDEVICEPROXIMITYEVENT_IID)

  /* [noscript] void initDeviceProximityEvent (in DOMString eventTypeArg, in boolean canBubbleArg, in boolean cancelableArg, in double value, in double min, in double max); */
  NS_IMETHOD InitDeviceProximityEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, double value, double min, double max) = 0;

  /* readonly attribute double value; */
  NS_IMETHOD GetValue(double *aValue) = 0;

  /* readonly attribute double min; */
  NS_IMETHOD GetMin(double *aMin) = 0;

  /* readonly attribute double max; */
  NS_IMETHOD GetMax(double *aMax) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDeviceProximityEvent, NS_IDOMDEVICEPROXIMITYEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDEVICEPROXIMITYEVENT \
  NS_IMETHOD InitDeviceProximityEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, double value, double min, double max); \
  NS_IMETHOD GetValue(double *aValue); \
  NS_IMETHOD GetMin(double *aMin); \
  NS_IMETHOD GetMax(double *aMax); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDEVICEPROXIMITYEVENT(_to) \
  NS_IMETHOD InitDeviceProximityEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, double value, double min, double max) { return _to InitDeviceProximityEvent(eventTypeArg, canBubbleArg, cancelableArg, value, min, max); } \
  NS_IMETHOD GetValue(double *aValue) { return _to GetValue(aValue); } \
  NS_IMETHOD GetMin(double *aMin) { return _to GetMin(aMin); } \
  NS_IMETHOD GetMax(double *aMax) { return _to GetMax(aMax); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDEVICEPROXIMITYEVENT(_to) \
  NS_IMETHOD InitDeviceProximityEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, double value, double min, double max) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitDeviceProximityEvent(eventTypeArg, canBubbleArg, cancelableArg, value, min, max); } \
  NS_IMETHOD GetValue(double *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_IMETHOD GetMin(double *aMin) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMin(aMin); } \
  NS_IMETHOD GetMax(double *aMax) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMax(aMax); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDeviceProximityEvent : public nsIDOMDeviceProximityEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDEVICEPROXIMITYEVENT

  nsDOMDeviceProximityEvent();

private:
  ~nsDOMDeviceProximityEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDeviceProximityEvent, nsIDOMDeviceProximityEvent)

nsDOMDeviceProximityEvent::nsDOMDeviceProximityEvent()
{
  /* member initializers and constructor code */
}

nsDOMDeviceProximityEvent::~nsDOMDeviceProximityEvent()
{
  /* destructor code */
}

/* [noscript] void initDeviceProximityEvent (in DOMString eventTypeArg, in boolean canBubbleArg, in boolean cancelableArg, in double value, in double min, in double max); */
NS_IMETHODIMP nsDOMDeviceProximityEvent::InitDeviceProximityEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, double value, double min, double max)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double value; */
NS_IMETHODIMP nsDOMDeviceProximityEvent::GetValue(double *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double min; */
NS_IMETHODIMP nsDOMDeviceProximityEvent::GetMin(double *aMin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double max; */
NS_IMETHODIMP nsDOMDeviceProximityEvent::GetMax(double *aMax)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDeviceProximityEvent_h__ */

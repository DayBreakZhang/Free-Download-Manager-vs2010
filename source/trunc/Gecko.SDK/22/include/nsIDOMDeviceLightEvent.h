/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMDeviceLightEvent.idl
 */

#ifndef __gen_nsIDOMDeviceLightEvent_h__
#define __gen_nsIDOMDeviceLightEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDeviceLightEvent */
#define NS_IDOMDEVICELIGHTEVENT_IID_STR "0e4d1751-fdcd-4ee6-b82d-d3f5d992370d"

#define NS_IDOMDEVICELIGHTEVENT_IID \
  {0x0e4d1751, 0xfdcd, 0x4ee6, \
    { 0xb8, 0x2d, 0xd3, 0xf5, 0xd9, 0x92, 0x37, 0x0d }}

class NS_NO_VTABLE nsIDOMDeviceLightEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDEVICELIGHTEVENT_IID)

  /* [noscript] void initDeviceLightEvent (in DOMString eventTypeArg, in boolean canBubbleArg, in boolean cancelableArg, in double value); */
  NS_IMETHOD InitDeviceLightEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, double value) = 0;

  /* readonly attribute double value; */
  NS_IMETHOD GetValue(double *aValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDeviceLightEvent, NS_IDOMDEVICELIGHTEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDEVICELIGHTEVENT \
  NS_IMETHOD InitDeviceLightEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, double value); \
  NS_IMETHOD GetValue(double *aValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDEVICELIGHTEVENT(_to) \
  NS_IMETHOD InitDeviceLightEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, double value) { return _to InitDeviceLightEvent(eventTypeArg, canBubbleArg, cancelableArg, value); } \
  NS_IMETHOD GetValue(double *aValue) { return _to GetValue(aValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDEVICELIGHTEVENT(_to) \
  NS_IMETHOD InitDeviceLightEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, double value) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitDeviceLightEvent(eventTypeArg, canBubbleArg, cancelableArg, value); } \
  NS_IMETHOD GetValue(double *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDeviceLightEvent : public nsIDOMDeviceLightEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDEVICELIGHTEVENT

  nsDOMDeviceLightEvent();

private:
  ~nsDOMDeviceLightEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDeviceLightEvent, nsIDOMDeviceLightEvent)

nsDOMDeviceLightEvent::nsDOMDeviceLightEvent()
{
  /* member initializers and constructor code */
}

nsDOMDeviceLightEvent::~nsDOMDeviceLightEvent()
{
  /* destructor code */
}

/* [noscript] void initDeviceLightEvent (in DOMString eventTypeArg, in boolean canBubbleArg, in boolean cancelableArg, in double value); */
NS_IMETHODIMP nsDOMDeviceLightEvent::InitDeviceLightEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, double value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double value; */
NS_IMETHODIMP nsDOMDeviceLightEvent::GetValue(double *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDeviceLightEvent_h__ */

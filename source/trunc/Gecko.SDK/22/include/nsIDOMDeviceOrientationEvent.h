/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMDeviceOrientationEvent.idl
 */

#ifndef __gen_nsIDOMDeviceOrientationEvent_h__
#define __gen_nsIDOMDeviceOrientationEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDeviceOrientationEvent */
#define NS_IDOMDEVICEORIENTATIONEVENT_IID_STR "f5921a77-3ac5-4374-bc0c-1ed52fe83123"

#define NS_IDOMDEVICEORIENTATIONEVENT_IID \
  {0xf5921a77, 0x3ac5, 0x4374, \
    { 0xbc, 0x0c, 0x1e, 0xd5, 0x2f, 0xe8, 0x31, 0x23 }}

class NS_NO_VTABLE nsIDOMDeviceOrientationEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDEVICEORIENTATIONEVENT_IID)

  /* void initDeviceOrientationEvent (in DOMString eventTypeArg, in boolean canBubbleArg, in boolean cancelableArg, in double alpha, in double beta, in double gamma, in boolean absolute); */
  NS_IMETHOD InitDeviceOrientationEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, double alpha, double beta, double gamma, bool absolute) = 0;

  /* readonly attribute double alpha; */
  NS_IMETHOD GetAlpha(double *aAlpha) = 0;

  /* readonly attribute double beta; */
  NS_IMETHOD GetBeta(double *aBeta) = 0;

  /* readonly attribute double gamma; */
  NS_IMETHOD GetGamma(double *aGamma) = 0;

  /* readonly attribute boolean absolute; */
  NS_IMETHOD GetAbsolute(bool *aAbsolute) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDeviceOrientationEvent, NS_IDOMDEVICEORIENTATIONEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDEVICEORIENTATIONEVENT \
  NS_IMETHOD InitDeviceOrientationEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, double alpha, double beta, double gamma, bool absolute); \
  NS_IMETHOD GetAlpha(double *aAlpha); \
  NS_IMETHOD GetBeta(double *aBeta); \
  NS_IMETHOD GetGamma(double *aGamma); \
  NS_IMETHOD GetAbsolute(bool *aAbsolute); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDEVICEORIENTATIONEVENT(_to) \
  NS_IMETHOD InitDeviceOrientationEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, double alpha, double beta, double gamma, bool absolute) { return _to InitDeviceOrientationEvent(eventTypeArg, canBubbleArg, cancelableArg, alpha, beta, gamma, absolute); } \
  NS_IMETHOD GetAlpha(double *aAlpha) { return _to GetAlpha(aAlpha); } \
  NS_IMETHOD GetBeta(double *aBeta) { return _to GetBeta(aBeta); } \
  NS_IMETHOD GetGamma(double *aGamma) { return _to GetGamma(aGamma); } \
  NS_IMETHOD GetAbsolute(bool *aAbsolute) { return _to GetAbsolute(aAbsolute); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDEVICEORIENTATIONEVENT(_to) \
  NS_IMETHOD InitDeviceOrientationEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, double alpha, double beta, double gamma, bool absolute) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitDeviceOrientationEvent(eventTypeArg, canBubbleArg, cancelableArg, alpha, beta, gamma, absolute); } \
  NS_IMETHOD GetAlpha(double *aAlpha) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlpha(aAlpha); } \
  NS_IMETHOD GetBeta(double *aBeta) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBeta(aBeta); } \
  NS_IMETHOD GetGamma(double *aGamma) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGamma(aGamma); } \
  NS_IMETHOD GetAbsolute(bool *aAbsolute) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAbsolute(aAbsolute); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDeviceOrientationEvent : public nsIDOMDeviceOrientationEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDEVICEORIENTATIONEVENT

  nsDOMDeviceOrientationEvent();

private:
  ~nsDOMDeviceOrientationEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDeviceOrientationEvent, nsIDOMDeviceOrientationEvent)

nsDOMDeviceOrientationEvent::nsDOMDeviceOrientationEvent()
{
  /* member initializers and constructor code */
}

nsDOMDeviceOrientationEvent::~nsDOMDeviceOrientationEvent()
{
  /* destructor code */
}

/* void initDeviceOrientationEvent (in DOMString eventTypeArg, in boolean canBubbleArg, in boolean cancelableArg, in double alpha, in double beta, in double gamma, in boolean absolute); */
NS_IMETHODIMP nsDOMDeviceOrientationEvent::InitDeviceOrientationEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, double alpha, double beta, double gamma, bool absolute)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double alpha; */
NS_IMETHODIMP nsDOMDeviceOrientationEvent::GetAlpha(double *aAlpha)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double beta; */
NS_IMETHODIMP nsDOMDeviceOrientationEvent::GetBeta(double *aBeta)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double gamma; */
NS_IMETHODIMP nsDOMDeviceOrientationEvent::GetGamma(double *aGamma)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean absolute; */
NS_IMETHODIMP nsDOMDeviceOrientationEvent::GetAbsolute(bool *aAbsolute)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDeviceOrientationEvent_h__ */

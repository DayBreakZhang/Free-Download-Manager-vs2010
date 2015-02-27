/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMDeviceMotionEvent.idl
 */

#ifndef __gen_nsIDOMDeviceMotionEvent_h__
#define __gen_nsIDOMDeviceMotionEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDeviceAcceleration */
#define NS_IDOMDEVICEACCELERATION_IID_STR "2ad6ebc0-35ab-41d0-a755-0ca6a0e21565"

#define NS_IDOMDEVICEACCELERATION_IID \
  {0x2ad6ebc0, 0x35ab, 0x41d0, \
    { 0xa7, 0x55, 0x0c, 0xa6, 0xa0, 0xe2, 0x15, 0x65 }}

class NS_NO_VTABLE nsIDOMDeviceAcceleration : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDEVICEACCELERATION_IID)

  /* readonly attribute double x; */
  NS_IMETHOD GetX(double *aX) = 0;

  /* readonly attribute double y; */
  NS_IMETHOD GetY(double *aY) = 0;

  /* readonly attribute double z; */
  NS_IMETHOD GetZ(double *aZ) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDeviceAcceleration, NS_IDOMDEVICEACCELERATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDEVICEACCELERATION \
  NS_IMETHOD GetX(double *aX); \
  NS_IMETHOD GetY(double *aY); \
  NS_IMETHOD GetZ(double *aZ); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDEVICEACCELERATION(_to) \
  NS_IMETHOD GetX(double *aX) { return _to GetX(aX); } \
  NS_IMETHOD GetY(double *aY) { return _to GetY(aY); } \
  NS_IMETHOD GetZ(double *aZ) { return _to GetZ(aZ); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDEVICEACCELERATION(_to) \
  NS_IMETHOD GetX(double *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_IMETHOD GetY(double *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_IMETHOD GetZ(double *aZ) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZ(aZ); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDeviceAcceleration : public nsIDOMDeviceAcceleration
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDEVICEACCELERATION

  nsDOMDeviceAcceleration();

private:
  ~nsDOMDeviceAcceleration();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDeviceAcceleration, nsIDOMDeviceAcceleration)

nsDOMDeviceAcceleration::nsDOMDeviceAcceleration()
{
  /* member initializers and constructor code */
}

nsDOMDeviceAcceleration::~nsDOMDeviceAcceleration()
{
  /* destructor code */
}

/* readonly attribute double x; */
NS_IMETHODIMP nsDOMDeviceAcceleration::GetX(double *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double y; */
NS_IMETHODIMP nsDOMDeviceAcceleration::GetY(double *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double z; */
NS_IMETHODIMP nsDOMDeviceAcceleration::GetZ(double *aZ)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMDeviceRotationRate */
#define NS_IDOMDEVICEROTATIONRATE_IID_STR "e76ac929-61fe-4519-9eac-d496a53cbc9b"

#define NS_IDOMDEVICEROTATIONRATE_IID \
  {0xe76ac929, 0x61fe, 0x4519, \
    { 0x9e, 0xac, 0xd4, 0x96, 0xa5, 0x3c, 0xbc, 0x9b }}

class NS_NO_VTABLE nsIDOMDeviceRotationRate : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDEVICEROTATIONRATE_IID)

  /* readonly attribute double alpha; */
  NS_IMETHOD GetAlpha(double *aAlpha) = 0;

  /* readonly attribute double beta; */
  NS_IMETHOD GetBeta(double *aBeta) = 0;

  /* readonly attribute double gamma; */
  NS_IMETHOD GetGamma(double *aGamma) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDeviceRotationRate, NS_IDOMDEVICEROTATIONRATE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDEVICEROTATIONRATE \
  NS_IMETHOD GetAlpha(double *aAlpha); \
  NS_IMETHOD GetBeta(double *aBeta); \
  NS_IMETHOD GetGamma(double *aGamma); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDEVICEROTATIONRATE(_to) \
  NS_IMETHOD GetAlpha(double *aAlpha) { return _to GetAlpha(aAlpha); } \
  NS_IMETHOD GetBeta(double *aBeta) { return _to GetBeta(aBeta); } \
  NS_IMETHOD GetGamma(double *aGamma) { return _to GetGamma(aGamma); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDEVICEROTATIONRATE(_to) \
  NS_IMETHOD GetAlpha(double *aAlpha) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlpha(aAlpha); } \
  NS_IMETHOD GetBeta(double *aBeta) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBeta(aBeta); } \
  NS_IMETHOD GetGamma(double *aGamma) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGamma(aGamma); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDeviceRotationRate : public nsIDOMDeviceRotationRate
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDEVICEROTATIONRATE

  nsDOMDeviceRotationRate();

private:
  ~nsDOMDeviceRotationRate();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDeviceRotationRate, nsIDOMDeviceRotationRate)

nsDOMDeviceRotationRate::nsDOMDeviceRotationRate()
{
  /* member initializers and constructor code */
}

nsDOMDeviceRotationRate::~nsDOMDeviceRotationRate()
{
  /* destructor code */
}

/* readonly attribute double alpha; */
NS_IMETHODIMP nsDOMDeviceRotationRate::GetAlpha(double *aAlpha)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double beta; */
NS_IMETHODIMP nsDOMDeviceRotationRate::GetBeta(double *aBeta)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double gamma; */
NS_IMETHODIMP nsDOMDeviceRotationRate::GetGamma(double *aGamma)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMDeviceMotionEvent */
#define NS_IDOMDEVICEMOTIONEVENT_IID_STR "64c300f8-4bf9-47d0-86bc-2fafd7de38c7"

#define NS_IDOMDEVICEMOTIONEVENT_IID \
  {0x64c300f8, 0x4bf9, 0x47d0, \
    { 0x86, 0xbc, 0x2f, 0xaf, 0xd7, 0xde, 0x38, 0xc7 }}

class NS_NO_VTABLE nsIDOMDeviceMotionEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDEVICEMOTIONEVENT_IID)

  /* void initDeviceMotionEvent (in DOMString eventTypeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMDeviceAcceleration acceleration, in nsIDOMDeviceAcceleration accelerationIncludingGravity, in nsIDOMDeviceRotationRate rotationRate, in double interval); */
  NS_IMETHOD InitDeviceMotionEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, nsIDOMDeviceAcceleration *acceleration, nsIDOMDeviceAcceleration *accelerationIncludingGravity, nsIDOMDeviceRotationRate *rotationRate, double interval) = 0;

  /* readonly attribute nsIDOMDeviceAcceleration acceleration; */
  NS_IMETHOD GetAcceleration(nsIDOMDeviceAcceleration * *aAcceleration) = 0;

  /* readonly attribute nsIDOMDeviceAcceleration accelerationIncludingGravity; */
  NS_IMETHOD GetAccelerationIncludingGravity(nsIDOMDeviceAcceleration * *aAccelerationIncludingGravity) = 0;

  /* readonly attribute nsIDOMDeviceRotationRate rotationRate; */
  NS_IMETHOD GetRotationRate(nsIDOMDeviceRotationRate * *aRotationRate) = 0;

  /* readonly attribute double interval; */
  NS_IMETHOD GetInterval(double *aInterval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDeviceMotionEvent, NS_IDOMDEVICEMOTIONEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDEVICEMOTIONEVENT \
  NS_IMETHOD InitDeviceMotionEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, nsIDOMDeviceAcceleration *acceleration, nsIDOMDeviceAcceleration *accelerationIncludingGravity, nsIDOMDeviceRotationRate *rotationRate, double interval); \
  NS_IMETHOD GetAcceleration(nsIDOMDeviceAcceleration * *aAcceleration); \
  NS_IMETHOD GetAccelerationIncludingGravity(nsIDOMDeviceAcceleration * *aAccelerationIncludingGravity); \
  NS_IMETHOD GetRotationRate(nsIDOMDeviceRotationRate * *aRotationRate); \
  NS_IMETHOD GetInterval(double *aInterval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDEVICEMOTIONEVENT(_to) \
  NS_IMETHOD InitDeviceMotionEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, nsIDOMDeviceAcceleration *acceleration, nsIDOMDeviceAcceleration *accelerationIncludingGravity, nsIDOMDeviceRotationRate *rotationRate, double interval) { return _to InitDeviceMotionEvent(eventTypeArg, canBubbleArg, cancelableArg, acceleration, accelerationIncludingGravity, rotationRate, interval); } \
  NS_IMETHOD GetAcceleration(nsIDOMDeviceAcceleration * *aAcceleration) { return _to GetAcceleration(aAcceleration); } \
  NS_IMETHOD GetAccelerationIncludingGravity(nsIDOMDeviceAcceleration * *aAccelerationIncludingGravity) { return _to GetAccelerationIncludingGravity(aAccelerationIncludingGravity); } \
  NS_IMETHOD GetRotationRate(nsIDOMDeviceRotationRate * *aRotationRate) { return _to GetRotationRate(aRotationRate); } \
  NS_IMETHOD GetInterval(double *aInterval) { return _to GetInterval(aInterval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDEVICEMOTIONEVENT(_to) \
  NS_IMETHOD InitDeviceMotionEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, nsIDOMDeviceAcceleration *acceleration, nsIDOMDeviceAcceleration *accelerationIncludingGravity, nsIDOMDeviceRotationRate *rotationRate, double interval) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitDeviceMotionEvent(eventTypeArg, canBubbleArg, cancelableArg, acceleration, accelerationIncludingGravity, rotationRate, interval); } \
  NS_IMETHOD GetAcceleration(nsIDOMDeviceAcceleration * *aAcceleration) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAcceleration(aAcceleration); } \
  NS_IMETHOD GetAccelerationIncludingGravity(nsIDOMDeviceAcceleration * *aAccelerationIncludingGravity) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccelerationIncludingGravity(aAccelerationIncludingGravity); } \
  NS_IMETHOD GetRotationRate(nsIDOMDeviceRotationRate * *aRotationRate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRotationRate(aRotationRate); } \
  NS_IMETHOD GetInterval(double *aInterval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterval(aInterval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDeviceMotionEvent : public nsIDOMDeviceMotionEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDEVICEMOTIONEVENT

  nsDOMDeviceMotionEvent();

private:
  ~nsDOMDeviceMotionEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDeviceMotionEvent, nsIDOMDeviceMotionEvent)

nsDOMDeviceMotionEvent::nsDOMDeviceMotionEvent()
{
  /* member initializers and constructor code */
}

nsDOMDeviceMotionEvent::~nsDOMDeviceMotionEvent()
{
  /* destructor code */
}

/* void initDeviceMotionEvent (in DOMString eventTypeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMDeviceAcceleration acceleration, in nsIDOMDeviceAcceleration accelerationIncludingGravity, in nsIDOMDeviceRotationRate rotationRate, in double interval); */
NS_IMETHODIMP nsDOMDeviceMotionEvent::InitDeviceMotionEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, nsIDOMDeviceAcceleration *acceleration, nsIDOMDeviceAcceleration *accelerationIncludingGravity, nsIDOMDeviceRotationRate *rotationRate, double interval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDeviceAcceleration acceleration; */
NS_IMETHODIMP nsDOMDeviceMotionEvent::GetAcceleration(nsIDOMDeviceAcceleration * *aAcceleration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDeviceAcceleration accelerationIncludingGravity; */
NS_IMETHODIMP nsDOMDeviceMotionEvent::GetAccelerationIncludingGravity(nsIDOMDeviceAcceleration * *aAccelerationIncludingGravity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDeviceRotationRate rotationRate; */
NS_IMETHODIMP nsDOMDeviceMotionEvent::GetRotationRate(nsIDOMDeviceRotationRate * *aRotationRate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double interval; */
NS_IMETHODIMP nsDOMDeviceMotionEvent::GetInterval(double *aInterval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDeviceMotionEvent_h__ */

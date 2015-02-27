/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/events/nsIDOMOrientationEvent.idl
 */

#ifndef __gen_nsIDOMOrientationEvent_h__
#define __gen_nsIDOMOrientationEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMOrientationEvent */
#define NS_IDOMORIENTATIONEVENT_IID_STR "1618546a-c176-40a2-9086-2d973acceeb1"

#define NS_IDOMORIENTATIONEVENT_IID \
  {0x1618546a, 0xc176, 0x40a2, \
    { 0x90, 0x86, 0x2d, 0x97, 0x3a, 0xcc, 0xee, 0xb1 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMOrientationEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMORIENTATIONEVENT_IID)

  /* void initOrientationEvent (in DOMString eventTypeArg, in boolean canBubbleArg, in boolean cancelableArg, in double x, in double y, in double z); */
  NS_SCRIPTABLE NS_IMETHOD InitOrientationEvent(const nsAString & eventTypeArg, PRBool canBubbleArg, PRBool cancelableArg, double x, double y, double z) = 0;

  /* readonly attribute double x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(double *aX) = 0;

  /* readonly attribute double y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(double *aY) = 0;

  /* readonly attribute double z; */
  NS_SCRIPTABLE NS_IMETHOD GetZ(double *aZ) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMOrientationEvent, NS_IDOMORIENTATIONEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMORIENTATIONEVENT \
  NS_SCRIPTABLE NS_IMETHOD InitOrientationEvent(const nsAString & eventTypeArg, PRBool canBubbleArg, PRBool cancelableArg, double x, double y, double z); \
  NS_SCRIPTABLE NS_IMETHOD GetX(double *aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(double *aY); \
  NS_SCRIPTABLE NS_IMETHOD GetZ(double *aZ); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMORIENTATIONEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD InitOrientationEvent(const nsAString & eventTypeArg, PRBool canBubbleArg, PRBool cancelableArg, double x, double y, double z) { return _to InitOrientationEvent(eventTypeArg, canBubbleArg, cancelableArg, x, y, z); } \
  NS_SCRIPTABLE NS_IMETHOD GetX(double *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(double *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetZ(double *aZ) { return _to GetZ(aZ); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMORIENTATIONEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD InitOrientationEvent(const nsAString & eventTypeArg, PRBool canBubbleArg, PRBool cancelableArg, double x, double y, double z) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitOrientationEvent(eventTypeArg, canBubbleArg, cancelableArg, x, y, z); } \
  NS_SCRIPTABLE NS_IMETHOD GetX(double *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(double *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetZ(double *aZ) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZ(aZ); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMOrientationEvent : public nsIDOMOrientationEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMORIENTATIONEVENT

  nsDOMOrientationEvent();

private:
  ~nsDOMOrientationEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMOrientationEvent, nsIDOMOrientationEvent)

nsDOMOrientationEvent::nsDOMOrientationEvent()
{
  /* member initializers and constructor code */
}

nsDOMOrientationEvent::~nsDOMOrientationEvent()
{
  /* destructor code */
}

/* void initOrientationEvent (in DOMString eventTypeArg, in boolean canBubbleArg, in boolean cancelableArg, in double x, in double y, in double z); */
NS_IMETHODIMP nsDOMOrientationEvent::InitOrientationEvent(const nsAString & eventTypeArg, PRBool canBubbleArg, PRBool cancelableArg, double x, double y, double z)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double x; */
NS_IMETHODIMP nsDOMOrientationEvent::GetX(double *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double y; */
NS_IMETHODIMP nsDOMOrientationEvent::GetY(double *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double z; */
NS_IMETHODIMP nsDOMOrientationEvent::GetZ(double *aZ)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMOrientationEvent_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMGamepadAxisMoveEvent.idl
 */

#ifndef __gen_nsIDOMGamepadAxisMoveEvent_h__
#define __gen_nsIDOMGamepadAxisMoveEvent_h__


#ifndef __gen_nsIDOMGamepadEvent_h__
#include "nsIDOMGamepadEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMGamepadAxisMoveEvent */
#define NS_IDOMGAMEPADAXISMOVEEVENT_IID_STR "bd09eef8-8e07-4baf-8d39-4f92003dbca8"

#define NS_IDOMGAMEPADAXISMOVEEVENT_IID \
  {0xbd09eef8, 0x8e07, 0x4baf, \
    { 0x8d, 0x39, 0x4f, 0x92, 0x00, 0x3d, 0xbc, 0xa8 }}

class NS_NO_VTABLE nsIDOMGamepadAxisMoveEvent : public nsIDOMGamepadEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGAMEPADAXISMOVEEVENT_IID)

  /* readonly attribute unsigned long axis; */
  NS_IMETHOD GetAxis(uint32_t *aAxis) = 0;

  /* readonly attribute double value; */
  NS_IMETHOD GetValue(double *aValue) = 0;

  /* [noscript] void initGamepadAxisMoveEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMGamepad gamepad, in unsigned long axis, in double value); */
  NS_IMETHOD InitGamepadAxisMoveEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMGamepad *gamepad, uint32_t axis, double value) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGamepadAxisMoveEvent, NS_IDOMGAMEPADAXISMOVEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGAMEPADAXISMOVEEVENT \
  NS_IMETHOD GetAxis(uint32_t *aAxis); \
  NS_IMETHOD GetValue(double *aValue); \
  NS_IMETHOD InitGamepadAxisMoveEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMGamepad *gamepad, uint32_t axis, double value); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGAMEPADAXISMOVEEVENT(_to) \
  NS_IMETHOD GetAxis(uint32_t *aAxis) { return _to GetAxis(aAxis); } \
  NS_IMETHOD GetValue(double *aValue) { return _to GetValue(aValue); } \
  NS_IMETHOD InitGamepadAxisMoveEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMGamepad *gamepad, uint32_t axis, double value) { return _to InitGamepadAxisMoveEvent(typeArg, canBubbleArg, cancelableArg, gamepad, axis, value); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGAMEPADAXISMOVEEVENT(_to) \
  NS_IMETHOD GetAxis(uint32_t *aAxis) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAxis(aAxis); } \
  NS_IMETHOD GetValue(double *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_IMETHOD InitGamepadAxisMoveEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMGamepad *gamepad, uint32_t axis, double value) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitGamepadAxisMoveEvent(typeArg, canBubbleArg, cancelableArg, gamepad, axis, value); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGamepadAxisMoveEvent : public nsIDOMGamepadAxisMoveEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGAMEPADAXISMOVEEVENT

  nsDOMGamepadAxisMoveEvent();

private:
  ~nsDOMGamepadAxisMoveEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMGamepadAxisMoveEvent, nsIDOMGamepadAxisMoveEvent)

nsDOMGamepadAxisMoveEvent::nsDOMGamepadAxisMoveEvent()
{
  /* member initializers and constructor code */
}

nsDOMGamepadAxisMoveEvent::~nsDOMGamepadAxisMoveEvent()
{
  /* destructor code */
}

/* readonly attribute unsigned long axis; */
NS_IMETHODIMP nsDOMGamepadAxisMoveEvent::GetAxis(uint32_t *aAxis)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double value; */
NS_IMETHODIMP nsDOMGamepadAxisMoveEvent::GetValue(double *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initGamepadAxisMoveEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMGamepad gamepad, in unsigned long axis, in double value); */
NS_IMETHODIMP nsDOMGamepadAxisMoveEvent::InitGamepadAxisMoveEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMGamepad *gamepad, uint32_t axis, double value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMGamepadAxisMoveEvent_h__ */

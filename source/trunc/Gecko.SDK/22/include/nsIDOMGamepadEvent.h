/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMGamepadEvent.idl
 */

#ifndef __gen_nsIDOMGamepadEvent_h__
#define __gen_nsIDOMGamepadEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMGamepad; /* forward declaration */


/* starting interface:    nsIDOMGamepadEvent */
#define NS_IDOMGAMEPADEVENT_IID_STR "93b048d6-2aef-46a9-b0f4-06d7f00d8ef2"

#define NS_IDOMGAMEPADEVENT_IID \
  {0x93b048d6, 0x2aef, 0x46a9, \
    { 0xb0, 0xf4, 0x06, 0xd7, 0xf0, 0x0d, 0x8e, 0xf2 }}

class NS_NO_VTABLE nsIDOMGamepadEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGAMEPADEVENT_IID)

  /* readonly attribute nsIDOMGamepad gamepad; */
  NS_IMETHOD GetGamepad(nsIDOMGamepad * *aGamepad) = 0;

  /* [noscript] void initGamepadEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMGamepad gamepad); */
  NS_IMETHOD InitGamepadEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMGamepad *gamepad) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGamepadEvent, NS_IDOMGAMEPADEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGAMEPADEVENT \
  NS_IMETHOD GetGamepad(nsIDOMGamepad * *aGamepad); \
  NS_IMETHOD InitGamepadEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMGamepad *gamepad); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGAMEPADEVENT(_to) \
  NS_IMETHOD GetGamepad(nsIDOMGamepad * *aGamepad) { return _to GetGamepad(aGamepad); } \
  NS_IMETHOD InitGamepadEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMGamepad *gamepad) { return _to InitGamepadEvent(typeArg, canBubbleArg, cancelableArg, gamepad); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGAMEPADEVENT(_to) \
  NS_IMETHOD GetGamepad(nsIDOMGamepad * *aGamepad) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGamepad(aGamepad); } \
  NS_IMETHOD InitGamepadEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMGamepad *gamepad) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitGamepadEvent(typeArg, canBubbleArg, cancelableArg, gamepad); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGamepadEvent : public nsIDOMGamepadEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGAMEPADEVENT

  nsDOMGamepadEvent();

private:
  ~nsDOMGamepadEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMGamepadEvent, nsIDOMGamepadEvent)

nsDOMGamepadEvent::nsDOMGamepadEvent()
{
  /* member initializers and constructor code */
}

nsDOMGamepadEvent::~nsDOMGamepadEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMGamepad gamepad; */
NS_IMETHODIMP nsDOMGamepadEvent::GetGamepad(nsIDOMGamepad * *aGamepad)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initGamepadEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMGamepad gamepad); */
NS_IMETHODIMP nsDOMGamepadEvent::InitGamepadEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMGamepad *gamepad)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMGamepadEvent_h__ */

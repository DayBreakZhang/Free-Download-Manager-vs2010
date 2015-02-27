/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMGamepadButtonEvent.idl
 */

#ifndef __gen_nsIDOMGamepadButtonEvent_h__
#define __gen_nsIDOMGamepadButtonEvent_h__


#ifndef __gen_nsIDOMGamepadEvent_h__
#include "nsIDOMGamepadEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMGamepadButtonEvent */
#define NS_IDOMGAMEPADBUTTONEVENT_IID_STR "d75d4d2b-e7b4-4b93-ac35-2e70b57d9b28"

#define NS_IDOMGAMEPADBUTTONEVENT_IID \
  {0xd75d4d2b, 0xe7b4, 0x4b93, \
    { 0xac, 0x35, 0x2e, 0x70, 0xb5, 0x7d, 0x9b, 0x28 }}

class NS_NO_VTABLE nsIDOMGamepadButtonEvent : public nsIDOMGamepadEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGAMEPADBUTTONEVENT_IID)

  /* readonly attribute unsigned long button; */
  NS_IMETHOD GetButton(uint32_t *aButton) = 0;

  /* [noscript] void initGamepadButtonEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMGamepad gamepad, in unsigned long button); */
  NS_IMETHOD InitGamepadButtonEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMGamepad *gamepad, uint32_t button) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGamepadButtonEvent, NS_IDOMGAMEPADBUTTONEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGAMEPADBUTTONEVENT \
  NS_IMETHOD GetButton(uint32_t *aButton); \
  NS_IMETHOD InitGamepadButtonEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMGamepad *gamepad, uint32_t button); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGAMEPADBUTTONEVENT(_to) \
  NS_IMETHOD GetButton(uint32_t *aButton) { return _to GetButton(aButton); } \
  NS_IMETHOD InitGamepadButtonEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMGamepad *gamepad, uint32_t button) { return _to InitGamepadButtonEvent(typeArg, canBubbleArg, cancelableArg, gamepad, button); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGAMEPADBUTTONEVENT(_to) \
  NS_IMETHOD GetButton(uint32_t *aButton) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetButton(aButton); } \
  NS_IMETHOD InitGamepadButtonEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMGamepad *gamepad, uint32_t button) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitGamepadButtonEvent(typeArg, canBubbleArg, cancelableArg, gamepad, button); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGamepadButtonEvent : public nsIDOMGamepadButtonEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGAMEPADBUTTONEVENT

  nsDOMGamepadButtonEvent();

private:
  ~nsDOMGamepadButtonEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMGamepadButtonEvent, nsIDOMGamepadButtonEvent)

nsDOMGamepadButtonEvent::nsDOMGamepadButtonEvent()
{
  /* member initializers and constructor code */
}

nsDOMGamepadButtonEvent::~nsDOMGamepadButtonEvent()
{
  /* destructor code */
}

/* readonly attribute unsigned long button; */
NS_IMETHODIMP nsDOMGamepadButtonEvent::GetButton(uint32_t *aButton)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initGamepadButtonEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMGamepad gamepad, in unsigned long button); */
NS_IMETHODIMP nsDOMGamepadButtonEvent::InitGamepadButtonEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMGamepad *gamepad, uint32_t button)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMGamepadButtonEvent_h__ */

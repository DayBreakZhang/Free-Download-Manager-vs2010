/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMPopStateEvent.idl
 */

#ifndef __gen_nsIDOMPopStateEvent_h__
#define __gen_nsIDOMPopStateEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */


/* starting interface:    nsIDOMPopStateEvent */
#define NS_IDOMPOPSTATEEVENT_IID_STR "f0def4a3-0eb3-4c08-b476-582e37b8564b"

#define NS_IDOMPOPSTATEEVENT_IID \
  {0xf0def4a3, 0x0eb3, 0x4c08, \
    { 0xb4, 0x76, 0x58, 0x2e, 0x37, 0xb8, 0x56, 0x4b }}

class NS_NO_VTABLE nsIDOMPopStateEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMPOPSTATEEVENT_IID)

  /* readonly attribute nsIVariant state; */
  NS_IMETHOD GetState(nsIVariant * *aState) = 0;

  /* void initPopStateEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIVariant stateArg); */
  NS_IMETHOD InitPopStateEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIVariant *stateArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMPopStateEvent, NS_IDOMPOPSTATEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMPOPSTATEEVENT \
  NS_IMETHOD GetState(nsIVariant * *aState); \
  NS_IMETHOD InitPopStateEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIVariant *stateArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMPOPSTATEEVENT(_to) \
  NS_IMETHOD GetState(nsIVariant * *aState) { return _to GetState(aState); } \
  NS_IMETHOD InitPopStateEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIVariant *stateArg) { return _to InitPopStateEvent(typeArg, canBubbleArg, cancelableArg, stateArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMPOPSTATEEVENT(_to) \
  NS_IMETHOD GetState(nsIVariant * *aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_IMETHOD InitPopStateEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIVariant *stateArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitPopStateEvent(typeArg, canBubbleArg, cancelableArg, stateArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMPopStateEvent : public nsIDOMPopStateEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMPOPSTATEEVENT

  nsDOMPopStateEvent();

private:
  ~nsDOMPopStateEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMPopStateEvent, nsIDOMPopStateEvent)

nsDOMPopStateEvent::nsDOMPopStateEvent()
{
  /* member initializers and constructor code */
}

nsDOMPopStateEvent::~nsDOMPopStateEvent()
{
  /* destructor code */
}

/* readonly attribute nsIVariant state; */
NS_IMETHODIMP nsDOMPopStateEvent::GetState(nsIVariant * *aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initPopStateEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIVariant stateArg); */
NS_IMETHODIMP nsDOMPopStateEvent::InitPopStateEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIVariant *stateArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMPopStateEvent_h__ */

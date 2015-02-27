/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMUserProximityEvent.idl
 */

#ifndef __gen_nsIDOMUserProximityEvent_h__
#define __gen_nsIDOMUserProximityEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMUserProximityEvent */
#define NS_IDOMUSERPROXIMITYEVENT_IID_STR "5f1a4c25-e65d-4b50-a883-7498ab88c677"

#define NS_IDOMUSERPROXIMITYEVENT_IID \
  {0x5f1a4c25, 0xe65d, 0x4b50, \
    { 0xa8, 0x83, 0x74, 0x98, 0xab, 0x88, 0xc6, 0x77 }}

class NS_NO_VTABLE nsIDOMUserProximityEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMUSERPROXIMITYEVENT_IID)

  /* [noscript] void initUserProximityEvent (in DOMString eventTypeArg, in boolean canBubbleArg, in boolean cancelableArg, in boolean near); */
  NS_IMETHOD InitUserProximityEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, bool near) = 0;

  /* readonly attribute boolean near; */
  NS_IMETHOD GetNear(bool *aNear) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMUserProximityEvent, NS_IDOMUSERPROXIMITYEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMUSERPROXIMITYEVENT \
  NS_IMETHOD InitUserProximityEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, bool near); \
  NS_IMETHOD GetNear(bool *aNear); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMUSERPROXIMITYEVENT(_to) \
  NS_IMETHOD InitUserProximityEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, bool near) { return _to InitUserProximityEvent(eventTypeArg, canBubbleArg, cancelableArg, near); } \
  NS_IMETHOD GetNear(bool *aNear) { return _to GetNear(aNear); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMUSERPROXIMITYEVENT(_to) \
  NS_IMETHOD InitUserProximityEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, bool near) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitUserProximityEvent(eventTypeArg, canBubbleArg, cancelableArg, near); } \
  NS_IMETHOD GetNear(bool *aNear) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNear(aNear); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMUserProximityEvent : public nsIDOMUserProximityEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMUSERPROXIMITYEVENT

  nsDOMUserProximityEvent();

private:
  ~nsDOMUserProximityEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMUserProximityEvent, nsIDOMUserProximityEvent)

nsDOMUserProximityEvent::nsDOMUserProximityEvent()
{
  /* member initializers and constructor code */
}

nsDOMUserProximityEvent::~nsDOMUserProximityEvent()
{
  /* destructor code */
}

/* [noscript] void initUserProximityEvent (in DOMString eventTypeArg, in boolean canBubbleArg, in boolean cancelableArg, in boolean near); */
NS_IMETHODIMP nsDOMUserProximityEvent::InitUserProximityEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, bool near)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean near; */
NS_IMETHODIMP nsDOMUserProximityEvent::GetNear(bool *aNear)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMUserProximityEvent_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMCommandEvent.idl
 */

#ifndef __gen_nsIDOMCommandEvent_h__
#define __gen_nsIDOMCommandEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCommandEvent */
#define NS_IDOMCOMMANDEVENT_IID_STR "3fdc07cb-3b2e-4c6e-a054-008a4f302202"

#define NS_IDOMCOMMANDEVENT_IID \
  {0x3fdc07cb, 0x3b2e, 0x4c6e, \
    { 0xa0, 0x54, 0x00, 0x8a, 0x4f, 0x30, 0x22, 0x02 }}

class NS_NO_VTABLE nsIDOMCommandEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCOMMANDEVENT_IID)

  /* readonly attribute DOMString command; */
  NS_IMETHOD GetCommand(nsAString & aCommand) = 0;

  /* void initCommandEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean canCancelArg, in DOMString command); */
  NS_IMETHOD InitCommandEvent(const nsAString & typeArg, bool canBubbleArg, bool canCancelArg, const nsAString & command) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCommandEvent, NS_IDOMCOMMANDEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCOMMANDEVENT \
  NS_IMETHOD GetCommand(nsAString & aCommand); \
  NS_IMETHOD InitCommandEvent(const nsAString & typeArg, bool canBubbleArg, bool canCancelArg, const nsAString & command); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCOMMANDEVENT(_to) \
  NS_IMETHOD GetCommand(nsAString & aCommand) { return _to GetCommand(aCommand); } \
  NS_IMETHOD InitCommandEvent(const nsAString & typeArg, bool canBubbleArg, bool canCancelArg, const nsAString & command) { return _to InitCommandEvent(typeArg, canBubbleArg, canCancelArg, command); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCOMMANDEVENT(_to) \
  NS_IMETHOD GetCommand(nsAString & aCommand) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCommand(aCommand); } \
  NS_IMETHOD InitCommandEvent(const nsAString & typeArg, bool canBubbleArg, bool canCancelArg, const nsAString & command) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitCommandEvent(typeArg, canBubbleArg, canCancelArg, command); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCommandEvent : public nsIDOMCommandEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCOMMANDEVENT

  nsDOMCommandEvent();

private:
  ~nsDOMCommandEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCommandEvent, nsIDOMCommandEvent)

nsDOMCommandEvent::nsDOMCommandEvent()
{
  /* member initializers and constructor code */
}

nsDOMCommandEvent::~nsDOMCommandEvent()
{
  /* destructor code */
}

/* readonly attribute DOMString command; */
NS_IMETHODIMP nsDOMCommandEvent::GetCommand(nsAString & aCommand)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initCommandEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean canCancelArg, in DOMString command); */
NS_IMETHODIMP nsDOMCommandEvent::InitCommandEvent(const nsAString & typeArg, bool canBubbleArg, bool canCancelArg, const nsAString & command)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCommandEvent_h__ */

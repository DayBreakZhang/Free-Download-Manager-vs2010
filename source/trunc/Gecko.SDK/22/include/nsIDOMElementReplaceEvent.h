/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMElementReplaceEvent.idl
 */

#ifndef __gen_nsIDOMElementReplaceEvent_h__
#define __gen_nsIDOMElementReplaceEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */


/* starting interface:    nsIDOMElementReplaceEvent */
#define NS_IDOMELEMENTREPLACEEVENT_IID_STR "19a31767-54bf-4044-8769-cd172e37eca2"

#define NS_IDOMELEMENTREPLACEEVENT_IID \
  {0x19a31767, 0x54bf, 0x4044, \
    { 0x87, 0x69, 0xcd, 0x17, 0x2e, 0x37, 0xec, 0xa2 }}

class NS_NO_VTABLE nsIDOMElementReplaceEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMELEMENTREPLACEEVENT_IID)

  /* readonly attribute nsIDOMElement upgrade; */
  NS_IMETHOD GetUpgrade(nsIDOMElement * *aUpgrade) = 0;

  /* void initElementReplaceEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean canCancelArg, in nsIDOMElement upgrade); */
  NS_IMETHOD InitElementReplaceEvent(const nsAString & typeArg, bool canBubbleArg, bool canCancelArg, nsIDOMElement *upgrade) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMElementReplaceEvent, NS_IDOMELEMENTREPLACEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMELEMENTREPLACEEVENT \
  NS_IMETHOD GetUpgrade(nsIDOMElement * *aUpgrade); \
  NS_IMETHOD InitElementReplaceEvent(const nsAString & typeArg, bool canBubbleArg, bool canCancelArg, nsIDOMElement *upgrade); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMELEMENTREPLACEEVENT(_to) \
  NS_IMETHOD GetUpgrade(nsIDOMElement * *aUpgrade) { return _to GetUpgrade(aUpgrade); } \
  NS_IMETHOD InitElementReplaceEvent(const nsAString & typeArg, bool canBubbleArg, bool canCancelArg, nsIDOMElement *upgrade) { return _to InitElementReplaceEvent(typeArg, canBubbleArg, canCancelArg, upgrade); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMELEMENTREPLACEEVENT(_to) \
  NS_IMETHOD GetUpgrade(nsIDOMElement * *aUpgrade) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpgrade(aUpgrade); } \
  NS_IMETHOD InitElementReplaceEvent(const nsAString & typeArg, bool canBubbleArg, bool canCancelArg, nsIDOMElement *upgrade) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitElementReplaceEvent(typeArg, canBubbleArg, canCancelArg, upgrade); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMElementReplaceEvent : public nsIDOMElementReplaceEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMELEMENTREPLACEEVENT

  nsDOMElementReplaceEvent();

private:
  ~nsDOMElementReplaceEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMElementReplaceEvent, nsIDOMElementReplaceEvent)

nsDOMElementReplaceEvent::nsDOMElementReplaceEvent()
{
  /* member initializers and constructor code */
}

nsDOMElementReplaceEvent::~nsDOMElementReplaceEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMElement upgrade; */
NS_IMETHODIMP nsDOMElementReplaceEvent::GetUpgrade(nsIDOMElement * *aUpgrade)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initElementReplaceEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean canCancelArg, in nsIDOMElement upgrade); */
NS_IMETHODIMP nsDOMElementReplaceEvent::InitElementReplaceEvent(const nsAString & typeArg, bool canBubbleArg, bool canCancelArg, nsIDOMElement *upgrade)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMElementReplaceEvent_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMCustomEvent.idl
 */

#ifndef __gen_nsIDOMCustomEvent_h__
#define __gen_nsIDOMCustomEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */


/* starting interface:    nsIDOMCustomEvent */
#define NS_IDOMCUSTOMEVENT_IID_STR "b56ae6ca-c822-489e-be71-2a9f3c56082e"

#define NS_IDOMCUSTOMEVENT_IID \
  {0xb56ae6ca, 0xc822, 0x489e, \
    { 0xbe, 0x71, 0x2a, 0x9f, 0x3c, 0x56, 0x08, 0x2e }}

class NS_NO_VTABLE nsIDOMCustomEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCUSTOMEVENT_IID)

  /* readonly attribute nsIVariant detail; */
  NS_IMETHOD GetDetail(nsIVariant * *aDetail) = 0;

  /* void initCustomEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIVariant detailArg); */
  NS_IMETHOD InitCustomEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIVariant *detailArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCustomEvent, NS_IDOMCUSTOMEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCUSTOMEVENT \
  NS_IMETHOD GetDetail(nsIVariant * *aDetail); \
  NS_IMETHOD InitCustomEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIVariant *detailArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCUSTOMEVENT(_to) \
  NS_IMETHOD GetDetail(nsIVariant * *aDetail) { return _to GetDetail(aDetail); } \
  NS_IMETHOD InitCustomEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIVariant *detailArg) { return _to InitCustomEvent(typeArg, canBubbleArg, cancelableArg, detailArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCUSTOMEVENT(_to) \
  NS_IMETHOD GetDetail(nsIVariant * *aDetail) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDetail(aDetail); } \
  NS_IMETHOD InitCustomEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIVariant *detailArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitCustomEvent(typeArg, canBubbleArg, cancelableArg, detailArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCustomEvent : public nsIDOMCustomEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCUSTOMEVENT

  nsDOMCustomEvent();

private:
  ~nsDOMCustomEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCustomEvent, nsIDOMCustomEvent)

nsDOMCustomEvent::nsDOMCustomEvent()
{
  /* member initializers and constructor code */
}

nsDOMCustomEvent::~nsDOMCustomEvent()
{
  /* destructor code */
}

/* readonly attribute nsIVariant detail; */
NS_IMETHODIMP nsDOMCustomEvent::GetDetail(nsIVariant * *aDetail)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initCustomEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIVariant detailArg); */
NS_IMETHODIMP nsDOMCustomEvent::InitCustomEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIVariant *detailArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCustomEvent_h__ */

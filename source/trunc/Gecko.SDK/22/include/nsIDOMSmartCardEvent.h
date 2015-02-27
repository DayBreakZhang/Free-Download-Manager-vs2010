/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMSmartCardEvent.idl
 */

#ifndef __gen_nsIDOMSmartCardEvent_h__
#define __gen_nsIDOMSmartCardEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define SMARTCARDEVENT_INSERT "smartcard-insert"
#define SMARTCARDEVENT_REMOVE "smartcard-remove"

/* starting interface:    nsIDOMSmartCardEvent */
#define NS_IDOMSMARTCARDEVENT_IID_STR "cd251f11-7020-4f85-a7bd-94c98d884fa7"

#define NS_IDOMSMARTCARDEVENT_IID \
  {0xcd251f11, 0x7020, 0x4f85, \
    { 0xa7, 0xbd, 0x94, 0xc9, 0x8d, 0x88, 0x4f, 0xa7 }}

class NS_NO_VTABLE nsIDOMSmartCardEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSMARTCARDEVENT_IID)

  /* readonly attribute DOMString tokenName; */
  NS_IMETHOD GetTokenName(nsAString & aTokenName) = 0;

  /* [noscript] void initSmartCardEvent (in DOMString aTypeArg, in boolean aCanBubbleArg, in boolean aCancelableArg, in DOMString aTokenNAme); */
  NS_IMETHOD InitSmartCardEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, const nsAString & aTokenNAme) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSmartCardEvent, NS_IDOMSMARTCARDEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSMARTCARDEVENT \
  NS_IMETHOD GetTokenName(nsAString & aTokenName); \
  NS_IMETHOD InitSmartCardEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, const nsAString & aTokenNAme); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSMARTCARDEVENT(_to) \
  NS_IMETHOD GetTokenName(nsAString & aTokenName) { return _to GetTokenName(aTokenName); } \
  NS_IMETHOD InitSmartCardEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, const nsAString & aTokenNAme) { return _to InitSmartCardEvent(aTypeArg, aCanBubbleArg, aCancelableArg, aTokenNAme); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSMARTCARDEVENT(_to) \
  NS_IMETHOD GetTokenName(nsAString & aTokenName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTokenName(aTokenName); } \
  NS_IMETHOD InitSmartCardEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, const nsAString & aTokenNAme) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitSmartCardEvent(aTypeArg, aCanBubbleArg, aCancelableArg, aTokenNAme); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSmartCardEvent : public nsIDOMSmartCardEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSMARTCARDEVENT

  nsDOMSmartCardEvent();

private:
  ~nsDOMSmartCardEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSmartCardEvent, nsIDOMSmartCardEvent)

nsDOMSmartCardEvent::nsDOMSmartCardEvent()
{
  /* member initializers and constructor code */
}

nsDOMSmartCardEvent::~nsDOMSmartCardEvent()
{
  /* destructor code */
}

/* readonly attribute DOMString tokenName; */
NS_IMETHODIMP nsDOMSmartCardEvent::GetTokenName(nsAString & aTokenName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initSmartCardEvent (in DOMString aTypeArg, in boolean aCanBubbleArg, in boolean aCancelableArg, in DOMString aTokenNAme); */
NS_IMETHODIMP nsDOMSmartCardEvent::InitSmartCardEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, const nsAString & aTokenNAme)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSmartCardEvent_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMHashChangeEvent.idl
 */

#ifndef __gen_nsIDOMHashChangeEvent_h__
#define __gen_nsIDOMHashChangeEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHashChangeEvent */
#define NS_IDOMHASHCHANGEEVENT_IID_STR "d83f3cb2-1fa4-4ee0-8eb1-8181f6d3e214"

#define NS_IDOMHASHCHANGEEVENT_IID \
  {0xd83f3cb2, 0x1fa4, 0x4ee0, \
    { 0x8e, 0xb1, 0x81, 0x81, 0xf6, 0xd3, 0xe2, 0x14 }}

class NS_NO_VTABLE nsIDOMHashChangeEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHASHCHANGEEVENT_IID)

  /* readonly attribute DOMString oldURL; */
  NS_IMETHOD GetOldURL(nsAString & aOldURL) = 0;

  /* readonly attribute DOMString newURL; */
  NS_IMETHOD GetNewURL(nsAString & aNewURL) = 0;

  /* void initHashChangeEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in DOMString oldURLArg, in DOMString newURLArg); */
  NS_IMETHOD InitHashChangeEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & oldURLArg, const nsAString & newURLArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHashChangeEvent, NS_IDOMHASHCHANGEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHASHCHANGEEVENT \
  NS_IMETHOD GetOldURL(nsAString & aOldURL); \
  NS_IMETHOD GetNewURL(nsAString & aNewURL); \
  NS_IMETHOD InitHashChangeEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & oldURLArg, const nsAString & newURLArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHASHCHANGEEVENT(_to) \
  NS_IMETHOD GetOldURL(nsAString & aOldURL) { return _to GetOldURL(aOldURL); } \
  NS_IMETHOD GetNewURL(nsAString & aNewURL) { return _to GetNewURL(aNewURL); } \
  NS_IMETHOD InitHashChangeEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & oldURLArg, const nsAString & newURLArg) { return _to InitHashChangeEvent(typeArg, canBubbleArg, cancelableArg, oldURLArg, newURLArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHASHCHANGEEVENT(_to) \
  NS_IMETHOD GetOldURL(nsAString & aOldURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOldURL(aOldURL); } \
  NS_IMETHOD GetNewURL(nsAString & aNewURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNewURL(aNewURL); } \
  NS_IMETHOD InitHashChangeEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & oldURLArg, const nsAString & newURLArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitHashChangeEvent(typeArg, canBubbleArg, cancelableArg, oldURLArg, newURLArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHashChangeEvent : public nsIDOMHashChangeEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHASHCHANGEEVENT

  nsDOMHashChangeEvent();

private:
  ~nsDOMHashChangeEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHashChangeEvent, nsIDOMHashChangeEvent)

nsDOMHashChangeEvent::nsDOMHashChangeEvent()
{
  /* member initializers and constructor code */
}

nsDOMHashChangeEvent::~nsDOMHashChangeEvent()
{
  /* destructor code */
}

/* readonly attribute DOMString oldURL; */
NS_IMETHODIMP nsDOMHashChangeEvent::GetOldURL(nsAString & aOldURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString newURL; */
NS_IMETHODIMP nsDOMHashChangeEvent::GetNewURL(nsAString & aNewURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initHashChangeEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in DOMString oldURLArg, in DOMString newURLArg); */
NS_IMETHODIMP nsDOMHashChangeEvent::InitHashChangeEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & oldURLArg, const nsAString & newURLArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHashChangeEvent_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMStyleSheetApplicableStateChangeEvent.idl
 */

#ifndef __gen_nsIDOMStyleSheetApplicableStateChangeEvent_h__
#define __gen_nsIDOMStyleSheetApplicableStateChangeEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMCSSStyleSheet; /* forward declaration */


/* starting interface:    nsIDOMStyleSheetApplicableStateChangeEvent */
#define NS_IDOMSTYLESHEETAPPLICABLESTATECHANGEEVENT_IID_STR "75f27960-fd1a-4e05-8b8b-55d97ea22a9a"

#define NS_IDOMSTYLESHEETAPPLICABLESTATECHANGEEVENT_IID \
  {0x75f27960, 0xfd1a, 0x4e05, \
    { 0x8b, 0x8b, 0x55, 0xd9, 0x7e, 0xa2, 0x2a, 0x9a }}

class NS_NO_VTABLE nsIDOMStyleSheetApplicableStateChangeEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTYLESHEETAPPLICABLESTATECHANGEEVENT_IID)

  /* readonly attribute nsIDOMCSSStyleSheet stylesheet; */
  NS_IMETHOD GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet) = 0;

  /* readonly attribute boolean applicable; */
  NS_IMETHOD GetApplicable(bool *aApplicable) = 0;

  /* [noscript] void initStyleSheetApplicableStateChangeEvent (in DOMString aTypeArg, in boolean aCanBubbleArg, in boolean aCancelableArg, in nsIDOMCSSStyleSheet aStyleSheet, in boolean aApplicable); */
  NS_IMETHOD InitStyleSheetApplicableStateChangeEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, bool aApplicable) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStyleSheetApplicableStateChangeEvent, NS_IDOMSTYLESHEETAPPLICABLESTATECHANGEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTYLESHEETAPPLICABLESTATECHANGEEVENT \
  NS_IMETHOD GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet); \
  NS_IMETHOD GetApplicable(bool *aApplicable); \
  NS_IMETHOD InitStyleSheetApplicableStateChangeEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, bool aApplicable); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTYLESHEETAPPLICABLESTATECHANGEEVENT(_to) \
  NS_IMETHOD GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet) { return _to GetStylesheet(aStylesheet); } \
  NS_IMETHOD GetApplicable(bool *aApplicable) { return _to GetApplicable(aApplicable); } \
  NS_IMETHOD InitStyleSheetApplicableStateChangeEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, bool aApplicable) { return _to InitStyleSheetApplicableStateChangeEvent(aTypeArg, aCanBubbleArg, aCancelableArg, aStyleSheet, aApplicable); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTYLESHEETAPPLICABLESTATECHANGEEVENT(_to) \
  NS_IMETHOD GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStylesheet(aStylesheet); } \
  NS_IMETHOD GetApplicable(bool *aApplicable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApplicable(aApplicable); } \
  NS_IMETHOD InitStyleSheetApplicableStateChangeEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, bool aApplicable) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitStyleSheetApplicableStateChangeEvent(aTypeArg, aCanBubbleArg, aCancelableArg, aStyleSheet, aApplicable); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMStyleSheetApplicableStateChangeEvent : public nsIDOMStyleSheetApplicableStateChangeEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSTYLESHEETAPPLICABLESTATECHANGEEVENT

  nsDOMStyleSheetApplicableStateChangeEvent();

private:
  ~nsDOMStyleSheetApplicableStateChangeEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMStyleSheetApplicableStateChangeEvent, nsIDOMStyleSheetApplicableStateChangeEvent)

nsDOMStyleSheetApplicableStateChangeEvent::nsDOMStyleSheetApplicableStateChangeEvent()
{
  /* member initializers and constructor code */
}

nsDOMStyleSheetApplicableStateChangeEvent::~nsDOMStyleSheetApplicableStateChangeEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMCSSStyleSheet stylesheet; */
NS_IMETHODIMP nsDOMStyleSheetApplicableStateChangeEvent::GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean applicable; */
NS_IMETHODIMP nsDOMStyleSheetApplicableStateChangeEvent::GetApplicable(bool *aApplicable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initStyleSheetApplicableStateChangeEvent (in DOMString aTypeArg, in boolean aCanBubbleArg, in boolean aCancelableArg, in nsIDOMCSSStyleSheet aStyleSheet, in boolean aApplicable); */
NS_IMETHODIMP nsDOMStyleSheetApplicableStateChangeEvent::InitStyleSheetApplicableStateChangeEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, bool aApplicable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMStyleSheetApplicableStateChangeEvent_h__ */

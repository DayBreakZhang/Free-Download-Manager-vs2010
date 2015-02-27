/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMStyleRuleChangeEvent.idl
 */

#ifndef __gen_nsIDOMStyleRuleChangeEvent_h__
#define __gen_nsIDOMStyleRuleChangeEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMCSSRule; /* forward declaration */

class nsIDOMCSSStyleSheet; /* forward declaration */


/* starting interface:    nsIDOMStyleRuleChangeEvent */
#define NS_IDOMSTYLERULECHANGEEVENT_IID_STR "36098d39-b471-47e9-976e-33fee3d81467"

#define NS_IDOMSTYLERULECHANGEEVENT_IID \
  {0x36098d39, 0xb471, 0x47e9, \
    { 0x97, 0x6e, 0x33, 0xfe, 0xe3, 0xd8, 0x14, 0x67 }}

class NS_NO_VTABLE nsIDOMStyleRuleChangeEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTYLERULECHANGEEVENT_IID)

  /* readonly attribute nsIDOMCSSStyleSheet stylesheet; */
  NS_IMETHOD GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet) = 0;

  /* readonly attribute nsIDOMCSSRule rule; */
  NS_IMETHOD GetRule(nsIDOMCSSRule * *aRule) = 0;

  /* [noscript] void initStyleRuleChangeEvent (in DOMString aTypeArg, in boolean aCanBubbleArg, in boolean aCancelableArg, in nsIDOMCSSStyleSheet aStyleSheet, in nsIDOMCSSRule aRule); */
  NS_IMETHOD InitStyleRuleChangeEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, nsIDOMCSSRule *aRule) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStyleRuleChangeEvent, NS_IDOMSTYLERULECHANGEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTYLERULECHANGEEVENT \
  NS_IMETHOD GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet); \
  NS_IMETHOD GetRule(nsIDOMCSSRule * *aRule); \
  NS_IMETHOD InitStyleRuleChangeEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, nsIDOMCSSRule *aRule); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTYLERULECHANGEEVENT(_to) \
  NS_IMETHOD GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet) { return _to GetStylesheet(aStylesheet); } \
  NS_IMETHOD GetRule(nsIDOMCSSRule * *aRule) { return _to GetRule(aRule); } \
  NS_IMETHOD InitStyleRuleChangeEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, nsIDOMCSSRule *aRule) { return _to InitStyleRuleChangeEvent(aTypeArg, aCanBubbleArg, aCancelableArg, aStyleSheet, aRule); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTYLERULECHANGEEVENT(_to) \
  NS_IMETHOD GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStylesheet(aStylesheet); } \
  NS_IMETHOD GetRule(nsIDOMCSSRule * *aRule) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRule(aRule); } \
  NS_IMETHOD InitStyleRuleChangeEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, nsIDOMCSSRule *aRule) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitStyleRuleChangeEvent(aTypeArg, aCanBubbleArg, aCancelableArg, aStyleSheet, aRule); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMStyleRuleChangeEvent : public nsIDOMStyleRuleChangeEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSTYLERULECHANGEEVENT

  nsDOMStyleRuleChangeEvent();

private:
  ~nsDOMStyleRuleChangeEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMStyleRuleChangeEvent, nsIDOMStyleRuleChangeEvent)

nsDOMStyleRuleChangeEvent::nsDOMStyleRuleChangeEvent()
{
  /* member initializers and constructor code */
}

nsDOMStyleRuleChangeEvent::~nsDOMStyleRuleChangeEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMCSSStyleSheet stylesheet; */
NS_IMETHODIMP nsDOMStyleRuleChangeEvent::GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMCSSRule rule; */
NS_IMETHODIMP nsDOMStyleRuleChangeEvent::GetRule(nsIDOMCSSRule * *aRule)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initStyleRuleChangeEvent (in DOMString aTypeArg, in boolean aCanBubbleArg, in boolean aCancelableArg, in nsIDOMCSSStyleSheet aStyleSheet, in nsIDOMCSSRule aRule); */
NS_IMETHODIMP nsDOMStyleRuleChangeEvent::InitStyleRuleChangeEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, nsIDOMCSSRule *aRule)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMStyleRuleChangeEvent_h__ */

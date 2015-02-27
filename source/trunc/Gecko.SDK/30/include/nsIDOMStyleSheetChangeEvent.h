/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMStyleSheetChangeEvent.idl
 */

#ifndef __gen_nsIDOMStyleSheetChangeEvent_h__
#define __gen_nsIDOMStyleSheetChangeEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMCSSStyleSheet; /* forward declaration */


/* starting interface:    nsIDOMStyleSheetChangeEvent */
#define NS_IDOMSTYLESHEETCHANGEEVENT_IID_STR "f94c6a47-58f0-4996-b1db-3ea1d14c4ddd"

#define NS_IDOMSTYLESHEETCHANGEEVENT_IID \
  {0xf94c6a47, 0x58f0, 0x4996, \
    { 0xb1, 0xdb, 0x3e, 0xa1, 0xd1, 0x4c, 0x4d, 0xdd }}

class NS_NO_VTABLE nsIDOMStyleSheetChangeEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTYLESHEETCHANGEEVENT_IID)

  /* readonly attribute nsIDOMCSSStyleSheet stylesheet; */
  NS_IMETHOD GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet) = 0;

  /* readonly attribute boolean documentSheet; */
  NS_IMETHOD GetDocumentSheet(bool *aDocumentSheet) = 0;

  /* [noscript] void initStyleSheetChangeEvent (in DOMString aTypeArg, in boolean aCanBubbleArg, in boolean aCancelableArg, in nsIDOMCSSStyleSheet aStyleSheet, in boolean aDocumentSheet); */
  NS_IMETHOD InitStyleSheetChangeEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, bool aDocumentSheet) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStyleSheetChangeEvent, NS_IDOMSTYLESHEETCHANGEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTYLESHEETCHANGEEVENT \
  NS_IMETHOD GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet); \
  NS_IMETHOD GetDocumentSheet(bool *aDocumentSheet); \
  NS_IMETHOD InitStyleSheetChangeEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, bool aDocumentSheet); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTYLESHEETCHANGEEVENT(_to) \
  NS_IMETHOD GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet) { return _to GetStylesheet(aStylesheet); } \
  NS_IMETHOD GetDocumentSheet(bool *aDocumentSheet) { return _to GetDocumentSheet(aDocumentSheet); } \
  NS_IMETHOD InitStyleSheetChangeEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, bool aDocumentSheet) { return _to InitStyleSheetChangeEvent(aTypeArg, aCanBubbleArg, aCancelableArg, aStyleSheet, aDocumentSheet); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTYLESHEETCHANGEEVENT(_to) \
  NS_IMETHOD GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStylesheet(aStylesheet); } \
  NS_IMETHOD GetDocumentSheet(bool *aDocumentSheet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentSheet(aDocumentSheet); } \
  NS_IMETHOD InitStyleSheetChangeEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, bool aDocumentSheet) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitStyleSheetChangeEvent(aTypeArg, aCanBubbleArg, aCancelableArg, aStyleSheet, aDocumentSheet); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMStyleSheetChangeEvent : public nsIDOMStyleSheetChangeEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSTYLESHEETCHANGEEVENT

  nsDOMStyleSheetChangeEvent();

private:
  ~nsDOMStyleSheetChangeEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMStyleSheetChangeEvent, nsIDOMStyleSheetChangeEvent)

nsDOMStyleSheetChangeEvent::nsDOMStyleSheetChangeEvent()
{
  /* member initializers and constructor code */
}

nsDOMStyleSheetChangeEvent::~nsDOMStyleSheetChangeEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMCSSStyleSheet stylesheet; */
NS_IMETHODIMP nsDOMStyleSheetChangeEvent::GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean documentSheet; */
NS_IMETHODIMP nsDOMStyleSheetChangeEvent::GetDocumentSheet(bool *aDocumentSheet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initStyleSheetChangeEvent (in DOMString aTypeArg, in boolean aCanBubbleArg, in boolean aCancelableArg, in nsIDOMCSSStyleSheet aStyleSheet, in boolean aDocumentSheet); */
NS_IMETHODIMP nsDOMStyleSheetChangeEvent::InitStyleSheetChangeEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, bool aDocumentSheet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMStyleSheetChangeEvent_h__ */

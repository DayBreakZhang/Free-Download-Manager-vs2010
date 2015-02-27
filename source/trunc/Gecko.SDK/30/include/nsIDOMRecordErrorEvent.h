/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMRecordErrorEvent.idl
 */

#ifndef __gen_nsIDOMRecordErrorEvent_h__
#define __gen_nsIDOMRecordErrorEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMRecordErrorEvent */
#define NS_IDOMRECORDERROREVENT_IID_STR "606e6f94-bf02-11e2-8a01-e722108c6d66"

#define NS_IDOMRECORDERROREVENT_IID \
  {0x606e6f94, 0xbf02, 0x11e2, \
    { 0x8a, 0x01, 0xe7, 0x22, 0x10, 0x8c, 0x6d, 0x66 }}

class NS_NO_VTABLE nsIDOMRecordErrorEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMRECORDERROREVENT_IID)

  /* readonly attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* [noscript] void initRecordErrorEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in DOMString aName); */
  NS_IMETHOD InitRecordErrorEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMRecordErrorEvent, NS_IDOMRECORDERROREVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMRECORDERROREVENT \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD InitRecordErrorEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMRECORDERROREVENT(_to) \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD InitRecordErrorEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aName) { return _to InitRecordErrorEvent(aType, aCanBubble, aCancelable, aName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMRECORDERROREVENT(_to) \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD InitRecordErrorEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitRecordErrorEvent(aType, aCanBubble, aCancelable, aName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMRecordErrorEvent : public nsIDOMRecordErrorEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMRECORDERROREVENT

  nsDOMRecordErrorEvent();

private:
  ~nsDOMRecordErrorEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMRecordErrorEvent, nsIDOMRecordErrorEvent)

nsDOMRecordErrorEvent::nsDOMRecordErrorEvent()
{
  /* member initializers and constructor code */
}

nsDOMRecordErrorEvent::~nsDOMRecordErrorEvent()
{
  /* destructor code */
}

/* readonly attribute DOMString name; */
NS_IMETHODIMP nsDOMRecordErrorEvent::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initRecordErrorEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in DOMString aName); */
NS_IMETHODIMP nsDOMRecordErrorEvent::InitRecordErrorEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMRecordErrorEvent_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/network/interfaces/nsIDOMUSSDReceivedEvent.idl
 */

#ifndef __gen_nsIDOMUSSDReceivedEvent_h__
#define __gen_nsIDOMUSSDReceivedEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

#include "mozilla/Assertions.h"
#include "mozilla/DebugOnly.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMUSSDReceivedEvent */
#define NS_IDOMUSSDRECEIVEDEVENT_IID_STR "d26880c8-0468-4abb-94a6-9143defb5545"

#define NS_IDOMUSSDRECEIVEDEVENT_IID \
  {0xd26880c8, 0x0468, 0x4abb, \
    { 0x94, 0xa6, 0x91, 0x43, 0xde, 0xfb, 0x55, 0x45 }}

class NS_NO_VTABLE nsIDOMUSSDReceivedEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMUSSDRECEIVEDEVENT_IID)

  /* readonly attribute DOMString message; */
  NS_IMETHOD GetMessage(nsAString & aMessage) = 0;

  /* [infallible] readonly attribute boolean sessionEnded; */
  NS_IMETHOD GetSessionEnded(bool *aSessionEnded) = 0;
  inline bool GetSessionEnded()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetSessionEnded(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [noscript] void initUSSDReceivedEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in DOMString aMessage, in boolean aSessionEnded); */
  NS_IMETHOD InitUSSDReceivedEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aMessage, bool aSessionEnded) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMUSSDReceivedEvent, NS_IDOMUSSDRECEIVEDEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMUSSDRECEIVEDEVENT \
  NS_IMETHOD GetMessage(nsAString & aMessage); \
  NS_IMETHOD GetSessionEnded(bool *aSessionEnded); \
  NS_IMETHOD InitUSSDReceivedEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aMessage, bool aSessionEnded); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMUSSDRECEIVEDEVENT(_to) \
  NS_IMETHOD GetMessage(nsAString & aMessage) { return _to GetMessage(aMessage); } \
  NS_IMETHOD GetSessionEnded(bool *aSessionEnded) { return _to GetSessionEnded(aSessionEnded); } \
  NS_IMETHOD InitUSSDReceivedEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aMessage, bool aSessionEnded) { return _to InitUSSDReceivedEvent(aType, aCanBubble, aCancelable, aMessage, aSessionEnded); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMUSSDRECEIVEDEVENT(_to) \
  NS_IMETHOD GetMessage(nsAString & aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessage(aMessage); } \
  NS_IMETHOD GetSessionEnded(bool *aSessionEnded) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSessionEnded(aSessionEnded); } \
  NS_IMETHOD InitUSSDReceivedEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aMessage, bool aSessionEnded) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitUSSDReceivedEvent(aType, aCanBubble, aCancelable, aMessage, aSessionEnded); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMUSSDReceivedEvent : public nsIDOMUSSDReceivedEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMUSSDRECEIVEDEVENT

  nsDOMUSSDReceivedEvent();

private:
  ~nsDOMUSSDReceivedEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMUSSDReceivedEvent, nsIDOMUSSDReceivedEvent)

nsDOMUSSDReceivedEvent::nsDOMUSSDReceivedEvent()
{
  /* member initializers and constructor code */
}

nsDOMUSSDReceivedEvent::~nsDOMUSSDReceivedEvent()
{
  /* destructor code */
}

/* readonly attribute DOMString message; */
NS_IMETHODIMP nsDOMUSSDReceivedEvent::GetMessage(nsAString & aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean sessionEnded; */
NS_IMETHODIMP nsDOMUSSDReceivedEvent::GetSessionEnded(bool *aSessionEnded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initUSSDReceivedEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in DOMString aMessage, in boolean aSessionEnded); */
NS_IMETHODIMP nsDOMUSSDReceivedEvent::InitUSSDReceivedEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aMessage, bool aSessionEnded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMUSSDReceivedEvent_h__ */

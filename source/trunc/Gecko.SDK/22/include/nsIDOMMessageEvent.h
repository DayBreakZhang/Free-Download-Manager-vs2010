/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMMessageEvent.idl
 */

#ifndef __gen_nsIDOMMessageEvent_h__
#define __gen_nsIDOMMessageEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMessageEvent */
#define NS_IDOMMESSAGEEVENT_IID_STR "bb869a03-5fc0-4a1b-838a-342e5025fc05"

#define NS_IDOMMESSAGEEVENT_IID \
  {0xbb869a03, 0x5fc0, 0x4a1b, \
    { 0x83, 0x8a, 0x34, 0x2e, 0x50, 0x25, 0xfc, 0x05 }}

class NS_NO_VTABLE nsIDOMMessageEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMESSAGEEVENT_IID)

  /* [implicit_jscontext] readonly attribute jsval data; */
  NS_IMETHOD GetData(JSContext* cx, JS::Value *aData) = 0;

  /* readonly attribute DOMString origin; */
  NS_IMETHOD GetOrigin(nsAString & aOrigin) = 0;

  /* readonly attribute DOMString lastEventId; */
  NS_IMETHOD GetLastEventId(nsAString & aLastEventId) = 0;

  /* readonly attribute nsIDOMWindow source; */
  NS_IMETHOD GetSource(nsIDOMWindow * *aSource) = 0;

  /* void initMessageEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in jsval aData, in DOMString aOrigin, in DOMString aLastEventId, in nsIDOMWindow aSource); */
  NS_IMETHOD InitMessageEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const JS::Value & aData, const nsAString & aOrigin, const nsAString & aLastEventId, nsIDOMWindow *aSource) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMessageEvent, NS_IDOMMESSAGEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMESSAGEEVENT \
  NS_IMETHOD GetData(JSContext* cx, JS::Value *aData); \
  NS_IMETHOD GetOrigin(nsAString & aOrigin); \
  NS_IMETHOD GetLastEventId(nsAString & aLastEventId); \
  NS_IMETHOD GetSource(nsIDOMWindow * *aSource); \
  NS_IMETHOD InitMessageEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const JS::Value & aData, const nsAString & aOrigin, const nsAString & aLastEventId, nsIDOMWindow *aSource); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMESSAGEEVENT(_to) \
  NS_IMETHOD GetData(JSContext* cx, JS::Value *aData) { return _to GetData(cx, aData); } \
  NS_IMETHOD GetOrigin(nsAString & aOrigin) { return _to GetOrigin(aOrigin); } \
  NS_IMETHOD GetLastEventId(nsAString & aLastEventId) { return _to GetLastEventId(aLastEventId); } \
  NS_IMETHOD GetSource(nsIDOMWindow * *aSource) { return _to GetSource(aSource); } \
  NS_IMETHOD InitMessageEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const JS::Value & aData, const nsAString & aOrigin, const nsAString & aLastEventId, nsIDOMWindow *aSource) { return _to InitMessageEvent(aType, aCanBubble, aCancelable, aData, aOrigin, aLastEventId, aSource); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMESSAGEEVENT(_to) \
  NS_IMETHOD GetData(JSContext* cx, JS::Value *aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(cx, aData); } \
  NS_IMETHOD GetOrigin(nsAString & aOrigin) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOrigin(aOrigin); } \
  NS_IMETHOD GetLastEventId(nsAString & aLastEventId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastEventId(aLastEventId); } \
  NS_IMETHOD GetSource(nsIDOMWindow * *aSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSource(aSource); } \
  NS_IMETHOD InitMessageEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const JS::Value & aData, const nsAString & aOrigin, const nsAString & aLastEventId, nsIDOMWindow *aSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitMessageEvent(aType, aCanBubble, aCancelable, aData, aOrigin, aLastEventId, aSource); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMessageEvent : public nsIDOMMessageEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMESSAGEEVENT

  nsDOMMessageEvent();

private:
  ~nsDOMMessageEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMessageEvent, nsIDOMMessageEvent)

nsDOMMessageEvent::nsDOMMessageEvent()
{
  /* member initializers and constructor code */
}

nsDOMMessageEvent::~nsDOMMessageEvent()
{
  /* destructor code */
}

/* [implicit_jscontext] readonly attribute jsval data; */
NS_IMETHODIMP nsDOMMessageEvent::GetData(JSContext* cx, JS::Value *aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString origin; */
NS_IMETHODIMP nsDOMMessageEvent::GetOrigin(nsAString & aOrigin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString lastEventId; */
NS_IMETHODIMP nsDOMMessageEvent::GetLastEventId(nsAString & aLastEventId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow source; */
NS_IMETHODIMP nsDOMMessageEvent::GetSource(nsIDOMWindow * *aSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initMessageEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in jsval aData, in DOMString aOrigin, in DOMString aLastEventId, in nsIDOMWindow aSource); */
NS_IMETHODIMP nsDOMMessageEvent::InitMessageEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const JS::Value & aData, const nsAString & aOrigin, const nsAString & aLastEventId, nsIDOMWindow *aSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMessageEvent_h__ */

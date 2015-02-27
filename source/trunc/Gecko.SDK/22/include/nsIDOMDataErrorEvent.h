/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/network/interfaces/nsIDOMDataErrorEvent.idl
 */

#ifndef __gen_nsIDOMDataErrorEvent_h__
#define __gen_nsIDOMDataErrorEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDataErrorEvent */
#define NS_IDOMDATAERROREVENT_IID_STR "8b4ed443-a6b0-4445-aab0-9aa9fd5f6c1e"

#define NS_IDOMDATAERROREVENT_IID \
  {0x8b4ed443, 0xa6b0, 0x4445, \
    { 0xaa, 0xb0, 0x9a, 0xa9, 0xfd, 0x5f, 0x6c, 0x1e }}

class NS_NO_VTABLE nsIDOMDataErrorEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDATAERROREVENT_IID)

  /* readonly attribute DOMString message; */
  NS_IMETHOD GetMessage(nsAString & aMessage) = 0;

  /* [noscript] void initDataErrorEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in DOMString aMessage); */
  NS_IMETHOD InitDataErrorEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aMessage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDataErrorEvent, NS_IDOMDATAERROREVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDATAERROREVENT \
  NS_IMETHOD GetMessage(nsAString & aMessage); \
  NS_IMETHOD InitDataErrorEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aMessage); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDATAERROREVENT(_to) \
  NS_IMETHOD GetMessage(nsAString & aMessage) { return _to GetMessage(aMessage); } \
  NS_IMETHOD InitDataErrorEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aMessage) { return _to InitDataErrorEvent(aType, aCanBubble, aCancelable, aMessage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDATAERROREVENT(_to) \
  NS_IMETHOD GetMessage(nsAString & aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessage(aMessage); } \
  NS_IMETHOD InitDataErrorEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitDataErrorEvent(aType, aCanBubble, aCancelable, aMessage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDataErrorEvent : public nsIDOMDataErrorEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDATAERROREVENT

  nsDOMDataErrorEvent();

private:
  ~nsDOMDataErrorEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDataErrorEvent, nsIDOMDataErrorEvent)

nsDOMDataErrorEvent::nsDOMDataErrorEvent()
{
  /* member initializers and constructor code */
}

nsDOMDataErrorEvent::~nsDOMDataErrorEvent()
{
  /* destructor code */
}

/* readonly attribute DOMString message; */
NS_IMETHODIMP nsDOMDataErrorEvent::GetMessage(nsAString & aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initDataErrorEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in DOMString aMessage); */
NS_IMETHODIMP nsDOMDataErrorEvent::InitDataErrorEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDataErrorEvent_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/events/nsIDOMCloseEvent.idl
 */

#ifndef __gen_nsIDOMCloseEvent_h__
#define __gen_nsIDOMCloseEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCloseEvent */
#define NS_IDOMCLOSEEVENT_IID_STR "a94d4379-eba2-45f4-be3a-6cc2fa1453a8"

#define NS_IDOMCLOSEEVENT_IID \
  {0xa94d4379, 0xeba2, 0x45f4, \
    { 0xbe, 0x3a, 0x6c, 0xc2, 0xfa, 0x14, 0x53, 0xa8 }}

/**
 * The nsIDOMCloseEvent interface is the interface to the event
 * close on a WebSocket object.
 *
 * For more information on this interface, please see
 * http://dev.w3.org/html5/websockets/#closeevent
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMCloseEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCLOSEEVENT_IID)

  /* readonly attribute boolean wasClean; */
  NS_SCRIPTABLE NS_IMETHOD GetWasClean(PRBool *aWasClean) = 0;

  /* void initCloseEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in boolean aWasClean); */
  NS_SCRIPTABLE NS_IMETHOD InitCloseEvent(const nsAString & aType, PRBool aCanBubble, PRBool aCancelable, PRBool aWasClean) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCloseEvent, NS_IDOMCLOSEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCLOSEEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetWasClean(PRBool *aWasClean); \
  NS_SCRIPTABLE NS_IMETHOD InitCloseEvent(const nsAString & aType, PRBool aCanBubble, PRBool aCancelable, PRBool aWasClean); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCLOSEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWasClean(PRBool *aWasClean) { return _to GetWasClean(aWasClean); } \
  NS_SCRIPTABLE NS_IMETHOD InitCloseEvent(const nsAString & aType, PRBool aCanBubble, PRBool aCancelable, PRBool aWasClean) { return _to InitCloseEvent(aType, aCanBubble, aCancelable, aWasClean); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCLOSEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWasClean(PRBool *aWasClean) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWasClean(aWasClean); } \
  NS_SCRIPTABLE NS_IMETHOD InitCloseEvent(const nsAString & aType, PRBool aCanBubble, PRBool aCancelable, PRBool aWasClean) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitCloseEvent(aType, aCanBubble, aCancelable, aWasClean); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCloseEvent : public nsIDOMCloseEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCLOSEEVENT

  nsDOMCloseEvent();

private:
  ~nsDOMCloseEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCloseEvent, nsIDOMCloseEvent)

nsDOMCloseEvent::nsDOMCloseEvent()
{
  /* member initializers and constructor code */
}

nsDOMCloseEvent::~nsDOMCloseEvent()
{
  /* destructor code */
}

/* readonly attribute boolean wasClean; */
NS_IMETHODIMP nsDOMCloseEvent::GetWasClean(PRBool *aWasClean)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initCloseEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in boolean aWasClean); */
NS_IMETHODIMP nsDOMCloseEvent::InitCloseEvent(const nsAString & aType, PRBool aCanBubble, PRBool aCancelable, PRBool aWasClean)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCloseEvent_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/events/nsIDOMPopStateEvent.idl
 */

#ifndef __gen_nsIDOMPopStateEvent_h__
#define __gen_nsIDOMPopStateEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */


/* starting interface:    nsIDOMPopStateEvent */
#define NS_IDOMPOPSTATEEVENT_IID_STR "f3834fd5-0ef5-4ccd-a741-0b6685414342"

#define NS_IDOMPOPSTATEEVENT_IID \
  {0xf3834fd5, 0x0ef5, 0x4ccd, \
    { 0xa7, 0x41, 0x0b, 0x66, 0x85, 0x41, 0x43, 0x42 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMPopStateEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMPOPSTATEEVENT_IID)

  /**
   * The state associated with this popstate event
   */
  /* readonly attribute nsIVariant state; */
  NS_SCRIPTABLE NS_IMETHOD GetState(nsIVariant **aState) = 0;

  /**
   * This function sets isInitial to false.  If you want to set isInitial to
   * true, use the method in nsIDOMPopStateEvent_MOZILLA_2_BRANCH.
   */
  /* [noscript] void initPopStateEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIVariant stateArg); */
  NS_IMETHOD InitPopStateEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIVariant *stateArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMPopStateEvent, NS_IDOMPOPSTATEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMPOPSTATEEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetState(nsIVariant **aState); \
  NS_IMETHOD InitPopStateEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIVariant *stateArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMPOPSTATEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetState(nsIVariant **aState) { return _to GetState(aState); } \
  NS_IMETHOD InitPopStateEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIVariant *stateArg) { return _to InitPopStateEvent(typeArg, canBubbleArg, cancelableArg, stateArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMPOPSTATEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetState(nsIVariant **aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_IMETHOD InitPopStateEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIVariant *stateArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitPopStateEvent(typeArg, canBubbleArg, cancelableArg, stateArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMPopStateEvent : public nsIDOMPopStateEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMPOPSTATEEVENT

  nsDOMPopStateEvent();

private:
  ~nsDOMPopStateEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMPopStateEvent, nsIDOMPopStateEvent)

nsDOMPopStateEvent::nsDOMPopStateEvent()
{
  /* member initializers and constructor code */
}

nsDOMPopStateEvent::~nsDOMPopStateEvent()
{
  /* destructor code */
}

/* readonly attribute nsIVariant state; */
NS_IMETHODIMP nsDOMPopStateEvent::GetState(nsIVariant **aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initPopStateEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIVariant stateArg); */
NS_IMETHODIMP nsDOMPopStateEvent::InitPopStateEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIVariant *stateArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMPopStateEvent_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMClipboardEvent.idl
 */

#ifndef __gen_nsIDOMClipboardEvent_h__
#define __gen_nsIDOMClipboardEvent_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDataTransfer; /* forward declaration */


/* starting interface:    nsIDOMClipboardEvent */
#define NS_IDOMCLIPBOARDEVENT_IID_STR "8d92944a-f2e5-41f4-9cf3-d85043b90cac"

#define NS_IDOMCLIPBOARDEVENT_IID \
  {0x8d92944a, 0xf2e5, 0x41f4, \
    { 0x9c, 0xf3, 0xd8, 0x50, 0x43, 0xb9, 0x0c, 0xac }}

class NS_NO_VTABLE nsIDOMClipboardEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCLIPBOARDEVENT_IID)

  /* readonly attribute nsIDOMDataTransfer clipboardData; */
  NS_IMETHOD GetClipboardData(nsIDOMDataTransfer * *aClipboardData) = 0;

  /* [noscript] void initClipboardEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMDataTransfer clipboardData); */
  NS_IMETHOD InitClipboardEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMDataTransfer *clipboardData) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMClipboardEvent, NS_IDOMCLIPBOARDEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCLIPBOARDEVENT \
  NS_IMETHOD GetClipboardData(nsIDOMDataTransfer * *aClipboardData); \
  NS_IMETHOD InitClipboardEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMDataTransfer *clipboardData); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCLIPBOARDEVENT(_to) \
  NS_IMETHOD GetClipboardData(nsIDOMDataTransfer * *aClipboardData) { return _to GetClipboardData(aClipboardData); } \
  NS_IMETHOD InitClipboardEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMDataTransfer *clipboardData) { return _to InitClipboardEvent(typeArg, canBubbleArg, cancelableArg, clipboardData); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCLIPBOARDEVENT(_to) \
  NS_IMETHOD GetClipboardData(nsIDOMDataTransfer * *aClipboardData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClipboardData(aClipboardData); } \
  NS_IMETHOD InitClipboardEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMDataTransfer *clipboardData) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitClipboardEvent(typeArg, canBubbleArg, cancelableArg, clipboardData); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMClipboardEvent : public nsIDOMClipboardEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCLIPBOARDEVENT

  nsDOMClipboardEvent();

private:
  ~nsDOMClipboardEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMClipboardEvent, nsIDOMClipboardEvent)

nsDOMClipboardEvent::nsDOMClipboardEvent()
{
  /* member initializers and constructor code */
}

nsDOMClipboardEvent::~nsDOMClipboardEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMDataTransfer clipboardData; */
NS_IMETHODIMP nsDOMClipboardEvent::GetClipboardData(nsIDOMDataTransfer * *aClipboardData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initClipboardEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMDataTransfer clipboardData); */
NS_IMETHODIMP nsDOMClipboardEvent::InitClipboardEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMDataTransfer *clipboardData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMClipboardEvent_h__ */

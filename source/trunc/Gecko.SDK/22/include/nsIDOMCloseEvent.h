/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMCloseEvent.idl
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
#define NS_IDOMCLOSEEVENT_IID_STR "0b85dc61-2436-4786-b153-097f5c3a33b6"

#define NS_IDOMCLOSEEVENT_IID \
  {0x0b85dc61, 0x2436, 0x4786, \
    { 0xb1, 0x53, 0x09, 0x7f, 0x5c, 0x3a, 0x33, 0xb6 }}

class NS_NO_VTABLE nsIDOMCloseEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCLOSEEVENT_IID)

  /* readonly attribute boolean wasClean; */
  NS_IMETHOD GetWasClean(bool *aWasClean) = 0;

  /* readonly attribute unsigned short code; */
  NS_IMETHOD GetCode(uint16_t *aCode) = 0;

  /* readonly attribute DOMString reason; */
  NS_IMETHOD GetReason(nsAString & aReason) = 0;

  /* void initCloseEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in boolean aWasClean, in unsigned short aReasonCode, in DOMString aReason); */
  NS_IMETHOD InitCloseEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, bool aWasClean, uint16_t aReasonCode, const nsAString & aReason) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCloseEvent, NS_IDOMCLOSEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCLOSEEVENT \
  NS_IMETHOD GetWasClean(bool *aWasClean); \
  NS_IMETHOD GetCode(uint16_t *aCode); \
  NS_IMETHOD GetReason(nsAString & aReason); \
  NS_IMETHOD InitCloseEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, bool aWasClean, uint16_t aReasonCode, const nsAString & aReason); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCLOSEEVENT(_to) \
  NS_IMETHOD GetWasClean(bool *aWasClean) { return _to GetWasClean(aWasClean); } \
  NS_IMETHOD GetCode(uint16_t *aCode) { return _to GetCode(aCode); } \
  NS_IMETHOD GetReason(nsAString & aReason) { return _to GetReason(aReason); } \
  NS_IMETHOD InitCloseEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, bool aWasClean, uint16_t aReasonCode, const nsAString & aReason) { return _to InitCloseEvent(aType, aCanBubble, aCancelable, aWasClean, aReasonCode, aReason); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCLOSEEVENT(_to) \
  NS_IMETHOD GetWasClean(bool *aWasClean) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWasClean(aWasClean); } \
  NS_IMETHOD GetCode(uint16_t *aCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCode(aCode); } \
  NS_IMETHOD GetReason(nsAString & aReason) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReason(aReason); } \
  NS_IMETHOD InitCloseEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, bool aWasClean, uint16_t aReasonCode, const nsAString & aReason) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitCloseEvent(aType, aCanBubble, aCancelable, aWasClean, aReasonCode, aReason); } 

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
NS_IMETHODIMP nsDOMCloseEvent::GetWasClean(bool *aWasClean)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short code; */
NS_IMETHODIMP nsDOMCloseEvent::GetCode(uint16_t *aCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString reason; */
NS_IMETHODIMP nsDOMCloseEvent::GetReason(nsAString & aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initCloseEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in boolean aWasClean, in unsigned short aReasonCode, in DOMString aReason); */
NS_IMETHODIMP nsDOMCloseEvent::InitCloseEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, bool aWasClean, uint16_t aReasonCode, const nsAString & aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCloseEvent_h__ */

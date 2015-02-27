/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/contacts/nsIDOMMozContactChangeEvent.idl
 */

#ifndef __gen_nsIDOMMozContactChangeEvent_h__
#define __gen_nsIDOMMozContactChangeEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMozContactChangeEvent */
#define NS_IDOMMOZCONTACTCHANGEEVENT_IID_STR "7ee758eb-9353-4ade-8715-9953ea512ee2"

#define NS_IDOMMOZCONTACTCHANGEEVENT_IID \
  {0x7ee758eb, 0x9353, 0x4ade, \
    { 0x87, 0x15, 0x99, 0x53, 0xea, 0x51, 0x2e, 0xe2 }}

class NS_NO_VTABLE nsIDOMMozContactChangeEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZCONTACTCHANGEEVENT_IID)

  /* readonly attribute DOMString contactID; */
  NS_IMETHOD GetContactID(nsAString & aContactID) = 0;

  /* readonly attribute DOMString reason; */
  NS_IMETHOD GetReason(nsAString & aReason) = 0;

  /* [noscript] void initMozContactChangeEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in DOMString aContactID, in DOMString aReason); */
  NS_IMETHOD InitMozContactChangeEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aContactID, const nsAString & aReason) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozContactChangeEvent, NS_IDOMMOZCONTACTCHANGEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZCONTACTCHANGEEVENT \
  NS_IMETHOD GetContactID(nsAString & aContactID); \
  NS_IMETHOD GetReason(nsAString & aReason); \
  NS_IMETHOD InitMozContactChangeEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aContactID, const nsAString & aReason); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZCONTACTCHANGEEVENT(_to) \
  NS_IMETHOD GetContactID(nsAString & aContactID) { return _to GetContactID(aContactID); } \
  NS_IMETHOD GetReason(nsAString & aReason) { return _to GetReason(aReason); } \
  NS_IMETHOD InitMozContactChangeEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aContactID, const nsAString & aReason) { return _to InitMozContactChangeEvent(aType, aCanBubble, aCancelable, aContactID, aReason); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZCONTACTCHANGEEVENT(_to) \
  NS_IMETHOD GetContactID(nsAString & aContactID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContactID(aContactID); } \
  NS_IMETHOD GetReason(nsAString & aReason) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReason(aReason); } \
  NS_IMETHOD InitMozContactChangeEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aContactID, const nsAString & aReason) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitMozContactChangeEvent(aType, aCanBubble, aCancelable, aContactID, aReason); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozContactChangeEvent : public nsIDOMMozContactChangeEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZCONTACTCHANGEEVENT

  nsDOMMozContactChangeEvent();

private:
  ~nsDOMMozContactChangeEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozContactChangeEvent, nsIDOMMozContactChangeEvent)

nsDOMMozContactChangeEvent::nsDOMMozContactChangeEvent()
{
  /* member initializers and constructor code */
}

nsDOMMozContactChangeEvent::~nsDOMMozContactChangeEvent()
{
  /* destructor code */
}

/* readonly attribute DOMString contactID; */
NS_IMETHODIMP nsDOMMozContactChangeEvent::GetContactID(nsAString & aContactID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString reason; */
NS_IMETHODIMP nsDOMMozContactChangeEvent::GetReason(nsAString & aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initMozContactChangeEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in DOMString aContactID, in DOMString aReason); */
NS_IMETHODIMP nsDOMMozContactChangeEvent::InitMozContactChangeEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aContactID, const nsAString & aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMozContactChangeEvent_h__ */

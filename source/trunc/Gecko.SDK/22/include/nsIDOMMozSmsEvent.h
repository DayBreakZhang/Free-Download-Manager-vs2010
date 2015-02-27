/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/mobilemessage/interfaces/nsIDOMMozSmsEvent.idl
 */

#ifndef __gen_nsIDOMMozSmsEvent_h__
#define __gen_nsIDOMMozSmsEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMMozSmsMessage; /* forward declaration */


/* starting interface:    nsIDOMMozSmsEvent */
#define NS_IDOMMOZSMSEVENT_IID_STR "f12f9208-0abd-4d95-9a27-93a74b5e47a2"

#define NS_IDOMMOZSMSEVENT_IID \
  {0xf12f9208, 0x0abd, 0x4d95, \
    { 0x9a, 0x27, 0x93, 0xa7, 0x4b, 0x5e, 0x47, 0xa2 }}

class NS_NO_VTABLE nsIDOMMozSmsEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZSMSEVENT_IID)

  /* readonly attribute nsIDOMMozSmsMessage message; */
  NS_IMETHOD GetMessage(nsIDOMMozSmsMessage * *aMessage) = 0;

  /* [noscript] void initMozSmsEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in nsIDOMMozSmsMessage aMessage); */
  NS_IMETHOD InitMozSmsEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, nsIDOMMozSmsMessage *aMessage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozSmsEvent, NS_IDOMMOZSMSEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZSMSEVENT \
  NS_IMETHOD GetMessage(nsIDOMMozSmsMessage * *aMessage); \
  NS_IMETHOD InitMozSmsEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, nsIDOMMozSmsMessage *aMessage); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZSMSEVENT(_to) \
  NS_IMETHOD GetMessage(nsIDOMMozSmsMessage * *aMessage) { return _to GetMessage(aMessage); } \
  NS_IMETHOD InitMozSmsEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, nsIDOMMozSmsMessage *aMessage) { return _to InitMozSmsEvent(aType, aCanBubble, aCancelable, aMessage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZSMSEVENT(_to) \
  NS_IMETHOD GetMessage(nsIDOMMozSmsMessage * *aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessage(aMessage); } \
  NS_IMETHOD InitMozSmsEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, nsIDOMMozSmsMessage *aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitMozSmsEvent(aType, aCanBubble, aCancelable, aMessage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozSmsEvent : public nsIDOMMozSmsEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZSMSEVENT

  nsDOMMozSmsEvent();

private:
  ~nsDOMMozSmsEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozSmsEvent, nsIDOMMozSmsEvent)

nsDOMMozSmsEvent::nsDOMMozSmsEvent()
{
  /* member initializers and constructor code */
}

nsDOMMozSmsEvent::~nsDOMMozSmsEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMMozSmsMessage message; */
NS_IMETHODIMP nsDOMMozSmsEvent::GetMessage(nsIDOMMozSmsMessage * *aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initMozSmsEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in nsIDOMMozSmsMessage aMessage); */
NS_IMETHODIMP nsDOMMozSmsEvent::InitMozSmsEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, nsIDOMMozSmsMessage *aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMozSmsEvent_h__ */

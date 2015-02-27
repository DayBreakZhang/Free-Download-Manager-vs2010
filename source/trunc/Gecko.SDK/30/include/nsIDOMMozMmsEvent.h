/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMMozMmsEvent.idl
 */

#ifndef __gen_nsIDOMMozMmsEvent_h__
#define __gen_nsIDOMMozMmsEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMMozMmsMessage; /* forward declaration */


/* starting interface:    nsIDOMMozMmsEvent */
#define NS_IDOMMOZMMSEVENT_IID_STR "b33cc0f2-8886-11e2-9433-eff9a8af9a70"

#define NS_IDOMMOZMMSEVENT_IID \
  {0xb33cc0f2, 0x8886, 0x11e2, \
    { 0x94, 0x33, 0xef, 0xf9, 0xa8, 0xaf, 0x9a, 0x70 }}

class NS_NO_VTABLE nsIDOMMozMmsEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZMMSEVENT_IID)

  /* readonly attribute nsIDOMMozMmsMessage message; */
  NS_IMETHOD GetMessage(nsIDOMMozMmsMessage * *aMessage) = 0;

  /* [noscript] void initMozMmsEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in nsIDOMMozMmsMessage aMessage); */
  NS_IMETHOD InitMozMmsEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, nsIDOMMozMmsMessage *aMessage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozMmsEvent, NS_IDOMMOZMMSEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZMMSEVENT \
  NS_IMETHOD GetMessage(nsIDOMMozMmsMessage * *aMessage); \
  NS_IMETHOD InitMozMmsEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, nsIDOMMozMmsMessage *aMessage); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZMMSEVENT(_to) \
  NS_IMETHOD GetMessage(nsIDOMMozMmsMessage * *aMessage) { return _to GetMessage(aMessage); } \
  NS_IMETHOD InitMozMmsEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, nsIDOMMozMmsMessage *aMessage) { return _to InitMozMmsEvent(aType, aCanBubble, aCancelable, aMessage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZMMSEVENT(_to) \
  NS_IMETHOD GetMessage(nsIDOMMozMmsMessage * *aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessage(aMessage); } \
  NS_IMETHOD InitMozMmsEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, nsIDOMMozMmsMessage *aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitMozMmsEvent(aType, aCanBubble, aCancelable, aMessage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozMmsEvent : public nsIDOMMozMmsEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZMMSEVENT

  nsDOMMozMmsEvent();

private:
  ~nsDOMMozMmsEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozMmsEvent, nsIDOMMozMmsEvent)

nsDOMMozMmsEvent::nsDOMMozMmsEvent()
{
  /* member initializers and constructor code */
}

nsDOMMozMmsEvent::~nsDOMMozMmsEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMMozMmsMessage message; */
NS_IMETHODIMP nsDOMMozMmsEvent::GetMessage(nsIDOMMozMmsMessage * *aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initMozMmsEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in nsIDOMMozMmsMessage aMessage); */
NS_IMETHODIMP nsDOMMozMmsEvent::InitMozMmsEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, nsIDOMMozMmsMessage *aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMozMmsEvent_h__ */

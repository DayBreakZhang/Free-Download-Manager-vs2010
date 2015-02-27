/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMMozApplicationEvent.idl
 */

#ifndef __gen_nsIDOMMozApplicationEvent_h__
#define __gen_nsIDOMMozApplicationEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class mozIDOMApplication; /* forward declaration */


/* starting interface:    nsIDOMMozApplicationEvent */
#define NS_IDOMMOZAPPLICATIONEVENT_IID_STR "453ae38a-8d8d-465f-a718-3f01240f8f75"

#define NS_IDOMMOZAPPLICATIONEVENT_IID \
  {0x453ae38a, 0x8d8d, 0x465f, \
    { 0xa7, 0x18, 0x3f, 0x01, 0x24, 0x0f, 0x8f, 0x75 }}

class NS_NO_VTABLE nsIDOMMozApplicationEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZAPPLICATIONEVENT_IID)

  /* readonly attribute mozIDOMApplication application; */
  NS_IMETHOD GetApplication(mozIDOMApplication * *aApplication) = 0;

  /* [noscript] void initMozApplicationEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in mozIDOMApplication aApplication); */
  NS_IMETHOD InitMozApplicationEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, mozIDOMApplication *aApplication) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozApplicationEvent, NS_IDOMMOZAPPLICATIONEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZAPPLICATIONEVENT \
  NS_IMETHOD GetApplication(mozIDOMApplication * *aApplication); \
  NS_IMETHOD InitMozApplicationEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, mozIDOMApplication *aApplication); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZAPPLICATIONEVENT(_to) \
  NS_IMETHOD GetApplication(mozIDOMApplication * *aApplication) { return _to GetApplication(aApplication); } \
  NS_IMETHOD InitMozApplicationEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, mozIDOMApplication *aApplication) { return _to InitMozApplicationEvent(aType, aCanBubble, aCancelable, aApplication); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZAPPLICATIONEVENT(_to) \
  NS_IMETHOD GetApplication(mozIDOMApplication * *aApplication) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApplication(aApplication); } \
  NS_IMETHOD InitMozApplicationEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, mozIDOMApplication *aApplication) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitMozApplicationEvent(aType, aCanBubble, aCancelable, aApplication); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozApplicationEvent : public nsIDOMMozApplicationEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZAPPLICATIONEVENT

  nsDOMMozApplicationEvent();

private:
  ~nsDOMMozApplicationEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozApplicationEvent, nsIDOMMozApplicationEvent)

nsDOMMozApplicationEvent::nsDOMMozApplicationEvent()
{
  /* member initializers and constructor code */
}

nsDOMMozApplicationEvent::~nsDOMMozApplicationEvent()
{
  /* destructor code */
}

/* readonly attribute mozIDOMApplication application; */
NS_IMETHODIMP nsDOMMozApplicationEvent::GetApplication(mozIDOMApplication * *aApplication)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initMozApplicationEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in mozIDOMApplication aApplication); */
NS_IMETHODIMP nsDOMMozApplicationEvent::InitMozApplicationEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, mozIDOMApplication *aApplication)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMozApplicationEvent_h__ */

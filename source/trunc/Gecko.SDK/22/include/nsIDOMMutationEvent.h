/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMMutationEvent.idl
 */

#ifndef __gen_nsIDOMMutationEvent_h__
#define __gen_nsIDOMMutationEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMutationEvent */
#define NS_IDOMMUTATIONEVENT_IID_STR "982d9800-1402-46e5-8ad2-56fb0f4905ef"

#define NS_IDOMMUTATIONEVENT_IID \
  {0x982d9800, 0x1402, 0x46e5, \
    { 0x8a, 0xd2, 0x56, 0xfb, 0x0f, 0x49, 0x05, 0xef }}

class NS_NO_VTABLE nsIDOMMutationEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMUTATIONEVENT_IID)

  enum {
    MODIFICATION = 1U,
    ADDITION = 2U,
    REMOVAL = 3U
  };

  /* readonly attribute nsIDOMNode relatedNode; */
  NS_IMETHOD GetRelatedNode(nsIDOMNode * *aRelatedNode) = 0;

  /* readonly attribute DOMString prevValue; */
  NS_IMETHOD GetPrevValue(nsAString & aPrevValue) = 0;

  /* readonly attribute DOMString newValue; */
  NS_IMETHOD GetNewValue(nsAString & aNewValue) = 0;

  /* readonly attribute DOMString attrName; */
  NS_IMETHOD GetAttrName(nsAString & aAttrName) = 0;

  /* readonly attribute unsigned short attrChange; */
  NS_IMETHOD GetAttrChange(uint16_t *aAttrChange) = 0;

  /* void initMutationEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMNode relatedNodeArg, in DOMString prevValueArg, in DOMString newValueArg, in DOMString attrNameArg, in unsigned short attrChangeArg); */
  NS_IMETHOD InitMutationEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMNode *relatedNodeArg, const nsAString & prevValueArg, const nsAString & newValueArg, const nsAString & attrNameArg, uint16_t attrChangeArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMutationEvent, NS_IDOMMUTATIONEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMUTATIONEVENT \
  NS_IMETHOD GetRelatedNode(nsIDOMNode * *aRelatedNode); \
  NS_IMETHOD GetPrevValue(nsAString & aPrevValue); \
  NS_IMETHOD GetNewValue(nsAString & aNewValue); \
  NS_IMETHOD GetAttrName(nsAString & aAttrName); \
  NS_IMETHOD GetAttrChange(uint16_t *aAttrChange); \
  NS_IMETHOD InitMutationEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMNode *relatedNodeArg, const nsAString & prevValueArg, const nsAString & newValueArg, const nsAString & attrNameArg, uint16_t attrChangeArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMUTATIONEVENT(_to) \
  NS_IMETHOD GetRelatedNode(nsIDOMNode * *aRelatedNode) { return _to GetRelatedNode(aRelatedNode); } \
  NS_IMETHOD GetPrevValue(nsAString & aPrevValue) { return _to GetPrevValue(aPrevValue); } \
  NS_IMETHOD GetNewValue(nsAString & aNewValue) { return _to GetNewValue(aNewValue); } \
  NS_IMETHOD GetAttrName(nsAString & aAttrName) { return _to GetAttrName(aAttrName); } \
  NS_IMETHOD GetAttrChange(uint16_t *aAttrChange) { return _to GetAttrChange(aAttrChange); } \
  NS_IMETHOD InitMutationEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMNode *relatedNodeArg, const nsAString & prevValueArg, const nsAString & newValueArg, const nsAString & attrNameArg, uint16_t attrChangeArg) { return _to InitMutationEvent(typeArg, canBubbleArg, cancelableArg, relatedNodeArg, prevValueArg, newValueArg, attrNameArg, attrChangeArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMUTATIONEVENT(_to) \
  NS_IMETHOD GetRelatedNode(nsIDOMNode * *aRelatedNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRelatedNode(aRelatedNode); } \
  NS_IMETHOD GetPrevValue(nsAString & aPrevValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrevValue(aPrevValue); } \
  NS_IMETHOD GetNewValue(nsAString & aNewValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNewValue(aNewValue); } \
  NS_IMETHOD GetAttrName(nsAString & aAttrName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttrName(aAttrName); } \
  NS_IMETHOD GetAttrChange(uint16_t *aAttrChange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttrChange(aAttrChange); } \
  NS_IMETHOD InitMutationEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMNode *relatedNodeArg, const nsAString & prevValueArg, const nsAString & newValueArg, const nsAString & attrNameArg, uint16_t attrChangeArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitMutationEvent(typeArg, canBubbleArg, cancelableArg, relatedNodeArg, prevValueArg, newValueArg, attrNameArg, attrChangeArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMutationEvent : public nsIDOMMutationEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMUTATIONEVENT

  nsDOMMutationEvent();

private:
  ~nsDOMMutationEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMutationEvent, nsIDOMMutationEvent)

nsDOMMutationEvent::nsDOMMutationEvent()
{
  /* member initializers and constructor code */
}

nsDOMMutationEvent::~nsDOMMutationEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMNode relatedNode; */
NS_IMETHODIMP nsDOMMutationEvent::GetRelatedNode(nsIDOMNode * *aRelatedNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString prevValue; */
NS_IMETHODIMP nsDOMMutationEvent::GetPrevValue(nsAString & aPrevValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString newValue; */
NS_IMETHODIMP nsDOMMutationEvent::GetNewValue(nsAString & aNewValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString attrName; */
NS_IMETHODIMP nsDOMMutationEvent::GetAttrName(nsAString & aAttrName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short attrChange; */
NS_IMETHODIMP nsDOMMutationEvent::GetAttrChange(uint16_t *aAttrChange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initMutationEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMNode relatedNodeArg, in DOMString prevValueArg, in DOMString newValueArg, in DOMString attrNameArg, in unsigned short attrChangeArg); */
NS_IMETHODIMP nsDOMMutationEvent::InitMutationEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMNode *relatedNodeArg, const nsAString & prevValueArg, const nsAString & newValueArg, const nsAString & attrNameArg, uint16_t attrChangeArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMutationEvent_h__ */

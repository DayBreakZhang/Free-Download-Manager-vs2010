/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMWheelEvent.idl
 */

#ifndef __gen_nsIDOMWheelEvent_h__
#define __gen_nsIDOMWheelEvent_h__


#ifndef __gen_nsIDOMMouseEvent_h__
#include "nsIDOMMouseEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMWheelEvent */
#define NS_IDOMWHEELEVENT_IID_STR "86e2b577-7e61-4ed5-8ddd-c1533bf07137"

#define NS_IDOMWHEELEVENT_IID \
  {0x86e2b577, 0x7e61, 0x4ed5, \
    { 0x8d, 0xdd, 0xc1, 0x53, 0x3b, 0xf0, 0x71, 0x37 }}

class NS_NO_VTABLE nsIDOMWheelEvent : public nsIDOMMouseEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMWHEELEVENT_IID)

  enum {
    DOM_DELTA_PIXEL = 0U,
    DOM_DELTA_LINE = 1U,
    DOM_DELTA_PAGE = 2U
  };

  /* readonly attribute double deltaX; */
  NS_IMETHOD GetDeltaX(double *aDeltaX) = 0;

  /* readonly attribute double deltaY; */
  NS_IMETHOD GetDeltaY(double *aDeltaY) = 0;

  /* readonly attribute double deltaZ; */
  NS_IMETHOD GetDeltaZ(double *aDeltaZ) = 0;

  /* readonly attribute unsigned long deltaMode; */
  NS_IMETHOD GetDeltaMode(uint32_t *aDeltaMode) = 0;

  /* [noscript] void initWheelEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow viewArg, in long detailArg, in long screenXArg, in long screenYArg, in long clientXArg, in long clientYArg, in unsigned short buttonArg, in nsIDOMEventTarget relatedTargetArg, in DOMString modifiersListArg, in double deltaXArg, in double deltaYArg, in double deltaZArg, in unsigned long deltaMode); */
  NS_IMETHOD InitWheelEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg, int32_t screenXArg, int32_t screenYArg, int32_t clientXArg, int32_t clientYArg, uint16_t buttonArg, nsIDOMEventTarget *relatedTargetArg, const nsAString & modifiersListArg, double deltaXArg, double deltaYArg, double deltaZArg, uint32_t deltaMode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMWheelEvent, NS_IDOMWHEELEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMWHEELEVENT \
  NS_IMETHOD GetDeltaX(double *aDeltaX); \
  NS_IMETHOD GetDeltaY(double *aDeltaY); \
  NS_IMETHOD GetDeltaZ(double *aDeltaZ); \
  NS_IMETHOD GetDeltaMode(uint32_t *aDeltaMode); \
  NS_IMETHOD InitWheelEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg, int32_t screenXArg, int32_t screenYArg, int32_t clientXArg, int32_t clientYArg, uint16_t buttonArg, nsIDOMEventTarget *relatedTargetArg, const nsAString & modifiersListArg, double deltaXArg, double deltaYArg, double deltaZArg, uint32_t deltaMode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMWHEELEVENT(_to) \
  NS_IMETHOD GetDeltaX(double *aDeltaX) { return _to GetDeltaX(aDeltaX); } \
  NS_IMETHOD GetDeltaY(double *aDeltaY) { return _to GetDeltaY(aDeltaY); } \
  NS_IMETHOD GetDeltaZ(double *aDeltaZ) { return _to GetDeltaZ(aDeltaZ); } \
  NS_IMETHOD GetDeltaMode(uint32_t *aDeltaMode) { return _to GetDeltaMode(aDeltaMode); } \
  NS_IMETHOD InitWheelEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg, int32_t screenXArg, int32_t screenYArg, int32_t clientXArg, int32_t clientYArg, uint16_t buttonArg, nsIDOMEventTarget *relatedTargetArg, const nsAString & modifiersListArg, double deltaXArg, double deltaYArg, double deltaZArg, uint32_t deltaMode) { return _to InitWheelEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg, screenXArg, screenYArg, clientXArg, clientYArg, buttonArg, relatedTargetArg, modifiersListArg, deltaXArg, deltaYArg, deltaZArg, deltaMode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMWHEELEVENT(_to) \
  NS_IMETHOD GetDeltaX(double *aDeltaX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDeltaX(aDeltaX); } \
  NS_IMETHOD GetDeltaY(double *aDeltaY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDeltaY(aDeltaY); } \
  NS_IMETHOD GetDeltaZ(double *aDeltaZ) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDeltaZ(aDeltaZ); } \
  NS_IMETHOD GetDeltaMode(uint32_t *aDeltaMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDeltaMode(aDeltaMode); } \
  NS_IMETHOD InitWheelEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg, int32_t screenXArg, int32_t screenYArg, int32_t clientXArg, int32_t clientYArg, uint16_t buttonArg, nsIDOMEventTarget *relatedTargetArg, const nsAString & modifiersListArg, double deltaXArg, double deltaYArg, double deltaZArg, uint32_t deltaMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitWheelEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg, screenXArg, screenYArg, clientXArg, clientYArg, buttonArg, relatedTargetArg, modifiersListArg, deltaXArg, deltaYArg, deltaZArg, deltaMode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMWheelEvent : public nsIDOMWheelEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMWHEELEVENT

  nsDOMWheelEvent();

private:
  ~nsDOMWheelEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMWheelEvent, nsIDOMWheelEvent)

nsDOMWheelEvent::nsDOMWheelEvent()
{
  /* member initializers and constructor code */
}

nsDOMWheelEvent::~nsDOMWheelEvent()
{
  /* destructor code */
}

/* readonly attribute double deltaX; */
NS_IMETHODIMP nsDOMWheelEvent::GetDeltaX(double *aDeltaX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double deltaY; */
NS_IMETHODIMP nsDOMWheelEvent::GetDeltaY(double *aDeltaY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double deltaZ; */
NS_IMETHODIMP nsDOMWheelEvent::GetDeltaZ(double *aDeltaZ)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long deltaMode; */
NS_IMETHODIMP nsDOMWheelEvent::GetDeltaMode(uint32_t *aDeltaMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initWheelEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow viewArg, in long detailArg, in long screenXArg, in long screenYArg, in long clientXArg, in long clientYArg, in unsigned short buttonArg, in nsIDOMEventTarget relatedTargetArg, in DOMString modifiersListArg, in double deltaXArg, in double deltaYArg, in double deltaZArg, in unsigned long deltaMode); */
NS_IMETHODIMP nsDOMWheelEvent::InitWheelEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg, int32_t screenXArg, int32_t screenYArg, int32_t clientXArg, int32_t clientYArg, uint16_t buttonArg, nsIDOMEventTarget *relatedTargetArg, const nsAString & modifiersListArg, double deltaXArg, double deltaYArg, double deltaZArg, uint32_t deltaMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMWheelEvent_h__ */

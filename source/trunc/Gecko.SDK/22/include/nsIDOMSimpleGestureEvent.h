/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMSimpleGestureEvent.idl
 */

#ifndef __gen_nsIDOMSimpleGestureEvent_h__
#define __gen_nsIDOMSimpleGestureEvent_h__


#ifndef __gen_nsIDOMMouseEvent_h__
#include "nsIDOMMouseEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSimpleGestureEvent */
#define NS_IDOMSIMPLEGESTUREEVENT_IID_STR "0cd3fde1-0c99-49cc-a74e-9a9348864307"

#define NS_IDOMSIMPLEGESTUREEVENT_IID \
  {0x0cd3fde1, 0x0c99, 0x49cc, \
    { 0xa7, 0x4e, 0x9a, 0x93, 0x48, 0x86, 0x43, 0x07 }}

class NS_NO_VTABLE nsIDOMSimpleGestureEvent : public nsIDOMMouseEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSIMPLEGESTUREEVENT_IID)

  enum {
    DIRECTION_UP = 1U,
    DIRECTION_DOWN = 2U,
    DIRECTION_LEFT = 4U,
    DIRECTION_RIGHT = 8U,
    ROTATION_COUNTERCLOCKWISE = 1U,
    ROTATION_CLOCKWISE = 2U
  };

  /* readonly attribute unsigned long direction; */
  NS_IMETHOD GetDirection(uint32_t *aDirection) = 0;

  /* readonly attribute double delta; */
  NS_IMETHOD GetDelta(double *aDelta) = 0;

  /* readonly attribute unsigned long clickCount; */
  NS_IMETHOD GetClickCount(uint32_t *aClickCount) = 0;

  /* void initSimpleGestureEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow viewArg, in long detailArg, in long screenXArg, in long screenYArg, in long clientXArg, in long clientYArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in unsigned short buttonArg, in nsIDOMEventTarget relatedTargetArg, in unsigned long directionArg, in double deltaArg, in unsigned long clickCount); */
  NS_IMETHOD InitSimpleGestureEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg, int32_t screenXArg, int32_t screenYArg, int32_t clientXArg, int32_t clientYArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, uint16_t buttonArg, nsIDOMEventTarget *relatedTargetArg, uint32_t directionArg, double deltaArg, uint32_t clickCount) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSimpleGestureEvent, NS_IDOMSIMPLEGESTUREEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSIMPLEGESTUREEVENT \
  NS_IMETHOD GetDirection(uint32_t *aDirection); \
  NS_IMETHOD GetDelta(double *aDelta); \
  NS_IMETHOD GetClickCount(uint32_t *aClickCount); \
  NS_IMETHOD InitSimpleGestureEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg, int32_t screenXArg, int32_t screenYArg, int32_t clientXArg, int32_t clientYArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, uint16_t buttonArg, nsIDOMEventTarget *relatedTargetArg, uint32_t directionArg, double deltaArg, uint32_t clickCount); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSIMPLEGESTUREEVENT(_to) \
  NS_IMETHOD GetDirection(uint32_t *aDirection) { return _to GetDirection(aDirection); } \
  NS_IMETHOD GetDelta(double *aDelta) { return _to GetDelta(aDelta); } \
  NS_IMETHOD GetClickCount(uint32_t *aClickCount) { return _to GetClickCount(aClickCount); } \
  NS_IMETHOD InitSimpleGestureEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg, int32_t screenXArg, int32_t screenYArg, int32_t clientXArg, int32_t clientYArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, uint16_t buttonArg, nsIDOMEventTarget *relatedTargetArg, uint32_t directionArg, double deltaArg, uint32_t clickCount) { return _to InitSimpleGestureEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg, screenXArg, screenYArg, clientXArg, clientYArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, buttonArg, relatedTargetArg, directionArg, deltaArg, clickCount); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSIMPLEGESTUREEVENT(_to) \
  NS_IMETHOD GetDirection(uint32_t *aDirection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDirection(aDirection); } \
  NS_IMETHOD GetDelta(double *aDelta) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDelta(aDelta); } \
  NS_IMETHOD GetClickCount(uint32_t *aClickCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClickCount(aClickCount); } \
  NS_IMETHOD InitSimpleGestureEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg, int32_t screenXArg, int32_t screenYArg, int32_t clientXArg, int32_t clientYArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, uint16_t buttonArg, nsIDOMEventTarget *relatedTargetArg, uint32_t directionArg, double deltaArg, uint32_t clickCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitSimpleGestureEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg, screenXArg, screenYArg, clientXArg, clientYArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, buttonArg, relatedTargetArg, directionArg, deltaArg, clickCount); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSimpleGestureEvent : public nsIDOMSimpleGestureEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSIMPLEGESTUREEVENT

  nsDOMSimpleGestureEvent();

private:
  ~nsDOMSimpleGestureEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSimpleGestureEvent, nsIDOMSimpleGestureEvent)

nsDOMSimpleGestureEvent::nsDOMSimpleGestureEvent()
{
  /* member initializers and constructor code */
}

nsDOMSimpleGestureEvent::~nsDOMSimpleGestureEvent()
{
  /* destructor code */
}

/* readonly attribute unsigned long direction; */
NS_IMETHODIMP nsDOMSimpleGestureEvent::GetDirection(uint32_t *aDirection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double delta; */
NS_IMETHODIMP nsDOMSimpleGestureEvent::GetDelta(double *aDelta)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long clickCount; */
NS_IMETHODIMP nsDOMSimpleGestureEvent::GetClickCount(uint32_t *aClickCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initSimpleGestureEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow viewArg, in long detailArg, in long screenXArg, in long screenYArg, in long clientXArg, in long clientYArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in unsigned short buttonArg, in nsIDOMEventTarget relatedTargetArg, in unsigned long directionArg, in double deltaArg, in unsigned long clickCount); */
NS_IMETHODIMP nsDOMSimpleGestureEvent::InitSimpleGestureEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg, int32_t screenXArg, int32_t screenYArg, int32_t clientXArg, int32_t clientYArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, uint16_t buttonArg, nsIDOMEventTarget *relatedTargetArg, uint32_t directionArg, double deltaArg, uint32_t clickCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSimpleGestureEvent_h__ */

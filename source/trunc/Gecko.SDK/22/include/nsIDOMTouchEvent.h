/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMTouchEvent.idl
 */

#ifndef __gen_nsIDOMTouchEvent_h__
#define __gen_nsIDOMTouchEvent_h__


#ifndef __gen_nsIDOMUIEvent_h__
#include "nsIDOMUIEvent.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsWeakPtr.h"
#include "nsPoint.h"
class nsIVariant; /* forward declaration */


/* starting interface:    nsIDOMTouch */
#define NS_IDOMTOUCH_IID_STR "98bc0f7d-5bff-4387-9c42-58af54b48dd5"

#define NS_IDOMTOUCH_IID \
  {0x98bc0f7d, 0x5bff, 0x4387, \
    { 0x9c, 0x42, 0x58, 0xaf, 0x54, 0xb4, 0x8d, 0xd5 }}

class nsIDOMTouch : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMTOUCH_IID)

  /* readonly attribute long identifier; */
  NS_IMETHOD GetIdentifier(int32_t *aIdentifier) = 0;

  /* readonly attribute nsIDOMEventTarget target; */
  NS_IMETHOD GetTarget(nsIDOMEventTarget * *aTarget) = 0;

  /* readonly attribute long pageX; */
  NS_IMETHOD GetPageX(int32_t *aPageX) = 0;

  /* readonly attribute long pageY; */
  NS_IMETHOD GetPageY(int32_t *aPageY) = 0;

  /* readonly attribute long screenX; */
  NS_IMETHOD GetScreenX(int32_t *aScreenX) = 0;

  /* readonly attribute long screenY; */
  NS_IMETHOD GetScreenY(int32_t *aScreenY) = 0;

  /* readonly attribute long clientX; */
  NS_IMETHOD GetClientX(int32_t *aClientX) = 0;

  /* readonly attribute long clientY; */
  NS_IMETHOD GetClientY(int32_t *aClientY) = 0;

  /* readonly attribute long radiusX; */
  NS_IMETHOD GetRadiusX(int32_t *aRadiusX) = 0;

  /* readonly attribute long radiusY; */
  NS_IMETHOD GetRadiusY(int32_t *aRadiusY) = 0;

  /* readonly attribute float rotationAngle; */
  NS_IMETHOD GetRotationAngle(float *aRotationAngle) = 0;

  /* readonly attribute float force; */
  NS_IMETHOD GetForce(float *aForce) = 0;

     nsCOMPtr<nsIDOMEventTarget> mTarget;
    nsIDOMEventTarget *GetTarget() { return mTarget; }
    void SetTarget(nsIDOMEventTarget *target) { mTarget = target; }
    nsIntPoint mRefPoint;
    bool mChanged;
    uint32_t mMessage;
  };

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMTouch, NS_IDOMTOUCH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMTOUCH \
  NS_IMETHOD GetIdentifier(int32_t *aIdentifier); \
  NS_IMETHOD GetTarget(nsIDOMEventTarget * *aTarget); \
  NS_IMETHOD GetPageX(int32_t *aPageX); \
  NS_IMETHOD GetPageY(int32_t *aPageY); \
  NS_IMETHOD GetScreenX(int32_t *aScreenX); \
  NS_IMETHOD GetScreenY(int32_t *aScreenY); \
  NS_IMETHOD GetClientX(int32_t *aClientX); \
  NS_IMETHOD GetClientY(int32_t *aClientY); \
  NS_IMETHOD GetRadiusX(int32_t *aRadiusX); \
  NS_IMETHOD GetRadiusY(int32_t *aRadiusY); \
  NS_IMETHOD GetRotationAngle(float *aRotationAngle); \
  NS_IMETHOD GetForce(float *aForce); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMTOUCH(_to) \
  NS_IMETHOD GetIdentifier(int32_t *aIdentifier) { return _to GetIdentifier(aIdentifier); } \
  NS_IMETHOD GetTarget(nsIDOMEventTarget * *aTarget) { return _to GetTarget(aTarget); } \
  NS_IMETHOD GetPageX(int32_t *aPageX) { return _to GetPageX(aPageX); } \
  NS_IMETHOD GetPageY(int32_t *aPageY) { return _to GetPageY(aPageY); } \
  NS_IMETHOD GetScreenX(int32_t *aScreenX) { return _to GetScreenX(aScreenX); } \
  NS_IMETHOD GetScreenY(int32_t *aScreenY) { return _to GetScreenY(aScreenY); } \
  NS_IMETHOD GetClientX(int32_t *aClientX) { return _to GetClientX(aClientX); } \
  NS_IMETHOD GetClientY(int32_t *aClientY) { return _to GetClientY(aClientY); } \
  NS_IMETHOD GetRadiusX(int32_t *aRadiusX) { return _to GetRadiusX(aRadiusX); } \
  NS_IMETHOD GetRadiusY(int32_t *aRadiusY) { return _to GetRadiusY(aRadiusY); } \
  NS_IMETHOD GetRotationAngle(float *aRotationAngle) { return _to GetRotationAngle(aRotationAngle); } \
  NS_IMETHOD GetForce(float *aForce) { return _to GetForce(aForce); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMTOUCH(_to) \
  NS_IMETHOD GetIdentifier(int32_t *aIdentifier) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIdentifier(aIdentifier); } \
  NS_IMETHOD GetTarget(nsIDOMEventTarget * *aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTarget(aTarget); } \
  NS_IMETHOD GetPageX(int32_t *aPageX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageX(aPageX); } \
  NS_IMETHOD GetPageY(int32_t *aPageY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageY(aPageY); } \
  NS_IMETHOD GetScreenX(int32_t *aScreenX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenX(aScreenX); } \
  NS_IMETHOD GetScreenY(int32_t *aScreenY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenY(aScreenY); } \
  NS_IMETHOD GetClientX(int32_t *aClientX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientX(aClientX); } \
  NS_IMETHOD GetClientY(int32_t *aClientY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientY(aClientY); } \
  NS_IMETHOD GetRadiusX(int32_t *aRadiusX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRadiusX(aRadiusX); } \
  NS_IMETHOD GetRadiusY(int32_t *aRadiusY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRadiusY(aRadiusY); } \
  NS_IMETHOD GetRotationAngle(float *aRotationAngle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRotationAngle(aRotationAngle); } \
  NS_IMETHOD GetForce(float *aForce) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForce(aForce); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMTouch : public nsIDOMTouch
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMTOUCH

  nsDOMTouch();

private:
  ~nsDOMTouch();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMTouch, nsIDOMTouch)

nsDOMTouch::nsDOMTouch()
{
  /* member initializers and constructor code */
}

nsDOMTouch::~nsDOMTouch()
{
  /* destructor code */
}

/* readonly attribute long identifier; */
NS_IMETHODIMP nsDOMTouch::GetIdentifier(int32_t *aIdentifier)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMEventTarget target; */
NS_IMETHODIMP nsDOMTouch::GetTarget(nsIDOMEventTarget * *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long pageX; */
NS_IMETHODIMP nsDOMTouch::GetPageX(int32_t *aPageX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long pageY; */
NS_IMETHODIMP nsDOMTouch::GetPageY(int32_t *aPageY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long screenX; */
NS_IMETHODIMP nsDOMTouch::GetScreenX(int32_t *aScreenX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long screenY; */
NS_IMETHODIMP nsDOMTouch::GetScreenY(int32_t *aScreenY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long clientX; */
NS_IMETHODIMP nsDOMTouch::GetClientX(int32_t *aClientX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long clientY; */
NS_IMETHODIMP nsDOMTouch::GetClientY(int32_t *aClientY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long radiusX; */
NS_IMETHODIMP nsDOMTouch::GetRadiusX(int32_t *aRadiusX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long radiusY; */
NS_IMETHODIMP nsDOMTouch::GetRadiusY(int32_t *aRadiusY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float rotationAngle; */
NS_IMETHODIMP nsDOMTouch::GetRotationAngle(float *aRotationAngle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float force; */
NS_IMETHODIMP nsDOMTouch::GetForce(float *aForce)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMTouchList */
#define NS_IDOMTOUCHLIST_IID_STR "60706eb7-d50d-4379-b01c-e78e6af84213"

#define NS_IDOMTOUCHLIST_IID \
  {0x60706eb7, 0xd50d, 0x4379, \
    { 0xb0, 0x1c, 0xe7, 0x8e, 0x6a, 0xf8, 0x42, 0x13 }}

class NS_NO_VTABLE nsIDOMTouchList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMTOUCHLIST_IID)

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

  /* nsIDOMTouch item (in unsigned long index); */
  NS_IMETHOD Item(uint32_t index, nsIDOMTouch * *_retval) = 0;

  /* nsIDOMTouch identifiedTouch (in long identifier); */
  NS_IMETHOD IdentifiedTouch(int32_t identifier, nsIDOMTouch * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMTouchList, NS_IDOMTOUCHLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMTOUCHLIST \
  NS_IMETHOD GetLength(uint32_t *aLength); \
  NS_IMETHOD Item(uint32_t index, nsIDOMTouch * *_retval); \
  NS_IMETHOD IdentifiedTouch(int32_t identifier, nsIDOMTouch * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMTOUCHLIST(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) { return _to GetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsIDOMTouch * *_retval) { return _to Item(index, _retval); } \
  NS_IMETHOD IdentifiedTouch(int32_t identifier, nsIDOMTouch * *_retval) { return _to IdentifiedTouch(identifier, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMTOUCHLIST(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsIDOMTouch * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } \
  NS_IMETHOD IdentifiedTouch(int32_t identifier, nsIDOMTouch * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IdentifiedTouch(identifier, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMTouchList : public nsIDOMTouchList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMTOUCHLIST

  nsDOMTouchList();

private:
  ~nsDOMTouchList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMTouchList, nsIDOMTouchList)

nsDOMTouchList::nsDOMTouchList()
{
  /* member initializers and constructor code */
}

nsDOMTouchList::~nsDOMTouchList()
{
  /* destructor code */
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMTouchList::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMTouch item (in unsigned long index); */
NS_IMETHODIMP nsDOMTouchList::Item(uint32_t index, nsIDOMTouch * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMTouch identifiedTouch (in long identifier); */
NS_IMETHODIMP nsDOMTouchList::IdentifiedTouch(int32_t identifier, nsIDOMTouch * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMTouchEvent */
#define NS_IDOMTOUCHEVENT_IID_STR "9a043d55-f59e-4790-8fc7-1fab1c727732"

#define NS_IDOMTOUCHEVENT_IID \
  {0x9a043d55, 0xf59e, 0x4790, \
    { 0x8f, 0xc7, 0x1f, 0xab, 0x1c, 0x72, 0x77, 0x32 }}

class NS_NO_VTABLE nsIDOMTouchEvent : public nsIDOMUIEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMTOUCHEVENT_IID)

  /* readonly attribute nsIDOMTouchList touches; */
  NS_IMETHOD GetTouches(nsIDOMTouchList * *aTouches) = 0;

  /* readonly attribute nsIDOMTouchList targetTouches; */
  NS_IMETHOD GetTargetTouches(nsIDOMTouchList * *aTargetTouches) = 0;

  /* readonly attribute nsIDOMTouchList changedTouches; */
  NS_IMETHOD GetChangedTouches(nsIDOMTouchList * *aChangedTouches) = 0;

  /* readonly attribute boolean altKey; */
  NS_IMETHOD GetAltKey(bool *aAltKey) = 0;

  /* readonly attribute boolean metaKey; */
  NS_IMETHOD GetMetaKey(bool *aMetaKey) = 0;

  /* readonly attribute boolean ctrlKey; */
  NS_IMETHOD GetCtrlKey(bool *aCtrlKey) = 0;

  /* readonly attribute boolean shiftKey; */
  NS_IMETHOD GetShiftKey(bool *aShiftKey) = 0;

  /* void initTouchEvent (in DOMString type, in boolean canBubble, in boolean cancelable, in nsIDOMWindow view, in long detail, in boolean ctrlKey, in boolean altKey, in boolean shiftKey, in boolean metaKey, in nsIDOMTouchList touches, in nsIDOMTouchList targetTouches, in nsIDOMTouchList changedTouches); */
  NS_IMETHOD InitTouchEvent(const nsAString & type, bool canBubble, bool cancelable, nsIDOMWindow *view, int32_t detail, bool ctrlKey, bool altKey, bool shiftKey, bool metaKey, nsIDOMTouchList *touches, nsIDOMTouchList *targetTouches, nsIDOMTouchList *changedTouches) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMTouchEvent, NS_IDOMTOUCHEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMTOUCHEVENT \
  NS_IMETHOD GetTouches(nsIDOMTouchList * *aTouches); \
  NS_IMETHOD GetTargetTouches(nsIDOMTouchList * *aTargetTouches); \
  NS_IMETHOD GetChangedTouches(nsIDOMTouchList * *aChangedTouches); \
  NS_IMETHOD GetAltKey(bool *aAltKey); \
  NS_IMETHOD GetMetaKey(bool *aMetaKey); \
  NS_IMETHOD GetCtrlKey(bool *aCtrlKey); \
  NS_IMETHOD GetShiftKey(bool *aShiftKey); \
  NS_IMETHOD InitTouchEvent(const nsAString & type, bool canBubble, bool cancelable, nsIDOMWindow *view, int32_t detail, bool ctrlKey, bool altKey, bool shiftKey, bool metaKey, nsIDOMTouchList *touches, nsIDOMTouchList *targetTouches, nsIDOMTouchList *changedTouches); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMTOUCHEVENT(_to) \
  NS_IMETHOD GetTouches(nsIDOMTouchList * *aTouches) { return _to GetTouches(aTouches); } \
  NS_IMETHOD GetTargetTouches(nsIDOMTouchList * *aTargetTouches) { return _to GetTargetTouches(aTargetTouches); } \
  NS_IMETHOD GetChangedTouches(nsIDOMTouchList * *aChangedTouches) { return _to GetChangedTouches(aChangedTouches); } \
  NS_IMETHOD GetAltKey(bool *aAltKey) { return _to GetAltKey(aAltKey); } \
  NS_IMETHOD GetMetaKey(bool *aMetaKey) { return _to GetMetaKey(aMetaKey); } \
  NS_IMETHOD GetCtrlKey(bool *aCtrlKey) { return _to GetCtrlKey(aCtrlKey); } \
  NS_IMETHOD GetShiftKey(bool *aShiftKey) { return _to GetShiftKey(aShiftKey); } \
  NS_IMETHOD InitTouchEvent(const nsAString & type, bool canBubble, bool cancelable, nsIDOMWindow *view, int32_t detail, bool ctrlKey, bool altKey, bool shiftKey, bool metaKey, nsIDOMTouchList *touches, nsIDOMTouchList *targetTouches, nsIDOMTouchList *changedTouches) { return _to InitTouchEvent(type, canBubble, cancelable, view, detail, ctrlKey, altKey, shiftKey, metaKey, touches, targetTouches, changedTouches); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMTOUCHEVENT(_to) \
  NS_IMETHOD GetTouches(nsIDOMTouchList * *aTouches) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTouches(aTouches); } \
  NS_IMETHOD GetTargetTouches(nsIDOMTouchList * *aTargetTouches) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetTouches(aTargetTouches); } \
  NS_IMETHOD GetChangedTouches(nsIDOMTouchList * *aChangedTouches) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChangedTouches(aChangedTouches); } \
  NS_IMETHOD GetAltKey(bool *aAltKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAltKey(aAltKey); } \
  NS_IMETHOD GetMetaKey(bool *aMetaKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMetaKey(aMetaKey); } \
  NS_IMETHOD GetCtrlKey(bool *aCtrlKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCtrlKey(aCtrlKey); } \
  NS_IMETHOD GetShiftKey(bool *aShiftKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShiftKey(aShiftKey); } \
  NS_IMETHOD InitTouchEvent(const nsAString & type, bool canBubble, bool cancelable, nsIDOMWindow *view, int32_t detail, bool ctrlKey, bool altKey, bool shiftKey, bool metaKey, nsIDOMTouchList *touches, nsIDOMTouchList *targetTouches, nsIDOMTouchList *changedTouches) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitTouchEvent(type, canBubble, cancelable, view, detail, ctrlKey, altKey, shiftKey, metaKey, touches, targetTouches, changedTouches); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMTouchEvent : public nsIDOMTouchEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMTOUCHEVENT

  nsDOMTouchEvent();

private:
  ~nsDOMTouchEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMTouchEvent, nsIDOMTouchEvent)

nsDOMTouchEvent::nsDOMTouchEvent()
{
  /* member initializers and constructor code */
}

nsDOMTouchEvent::~nsDOMTouchEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMTouchList touches; */
NS_IMETHODIMP nsDOMTouchEvent::GetTouches(nsIDOMTouchList * *aTouches)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMTouchList targetTouches; */
NS_IMETHODIMP nsDOMTouchEvent::GetTargetTouches(nsIDOMTouchList * *aTargetTouches)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMTouchList changedTouches; */
NS_IMETHODIMP nsDOMTouchEvent::GetChangedTouches(nsIDOMTouchList * *aChangedTouches)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean altKey; */
NS_IMETHODIMP nsDOMTouchEvent::GetAltKey(bool *aAltKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean metaKey; */
NS_IMETHODIMP nsDOMTouchEvent::GetMetaKey(bool *aMetaKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean ctrlKey; */
NS_IMETHODIMP nsDOMTouchEvent::GetCtrlKey(bool *aCtrlKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean shiftKey; */
NS_IMETHODIMP nsDOMTouchEvent::GetShiftKey(bool *aShiftKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initTouchEvent (in DOMString type, in boolean canBubble, in boolean cancelable, in nsIDOMWindow view, in long detail, in boolean ctrlKey, in boolean altKey, in boolean shiftKey, in boolean metaKey, in nsIDOMTouchList touches, in nsIDOMTouchList targetTouches, in nsIDOMTouchList changedTouches); */
NS_IMETHODIMP nsDOMTouchEvent::InitTouchEvent(const nsAString & type, bool canBubble, bool cancelable, nsIDOMWindow *view, int32_t detail, bool ctrlKey, bool altKey, bool shiftKey, bool metaKey, nsIDOMTouchList *touches, nsIDOMTouchList *targetTouches, nsIDOMTouchList *changedTouches)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITouchEventReceiver */
#define NS_ITOUCHEVENTRECEIVER_IID_STR "6d5484f7-92ac-45f8-9388-39b5bad055ce"

#define NS_ITOUCHEVENTRECEIVER_IID \
  {0x6d5484f7, 0x92ac, 0x45f8, \
    { 0x93, 0x88, 0x39, 0xb5, 0xba, 0xd0, 0x55, 0xce }}

class NS_NO_VTABLE nsITouchEventReceiver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITOUCHEVENTRECEIVER_IID)

  /* [implicit_jscontext] attribute jsval ontouchstart; */
  NS_IMETHOD GetOntouchstart(JSContext* cx, JS::Value *aOntouchstart) = 0;
  NS_IMETHOD SetOntouchstart(JSContext* cx, const JS::Value & aOntouchstart) = 0;

  /* [implicit_jscontext] attribute jsval ontouchend; */
  NS_IMETHOD GetOntouchend(JSContext* cx, JS::Value *aOntouchend) = 0;
  NS_IMETHOD SetOntouchend(JSContext* cx, const JS::Value & aOntouchend) = 0;

  /* [implicit_jscontext] attribute jsval ontouchmove; */
  NS_IMETHOD GetOntouchmove(JSContext* cx, JS::Value *aOntouchmove) = 0;
  NS_IMETHOD SetOntouchmove(JSContext* cx, const JS::Value & aOntouchmove) = 0;

  /* [implicit_jscontext] attribute jsval ontouchenter; */
  NS_IMETHOD GetOntouchenter(JSContext* cx, JS::Value *aOntouchenter) = 0;
  NS_IMETHOD SetOntouchenter(JSContext* cx, const JS::Value & aOntouchenter) = 0;

  /* [implicit_jscontext] attribute jsval ontouchleave; */
  NS_IMETHOD GetOntouchleave(JSContext* cx, JS::Value *aOntouchleave) = 0;
  NS_IMETHOD SetOntouchleave(JSContext* cx, const JS::Value & aOntouchleave) = 0;

  /* [implicit_jscontext] attribute jsval ontouchcancel; */
  NS_IMETHOD GetOntouchcancel(JSContext* cx, JS::Value *aOntouchcancel) = 0;
  NS_IMETHOD SetOntouchcancel(JSContext* cx, const JS::Value & aOntouchcancel) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITouchEventReceiver, NS_ITOUCHEVENTRECEIVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITOUCHEVENTRECEIVER \
  NS_IMETHOD GetOntouchstart(JSContext* cx, JS::Value *aOntouchstart); \
  NS_IMETHOD SetOntouchstart(JSContext* cx, const JS::Value & aOntouchstart); \
  NS_IMETHOD GetOntouchend(JSContext* cx, JS::Value *aOntouchend); \
  NS_IMETHOD SetOntouchend(JSContext* cx, const JS::Value & aOntouchend); \
  NS_IMETHOD GetOntouchmove(JSContext* cx, JS::Value *aOntouchmove); \
  NS_IMETHOD SetOntouchmove(JSContext* cx, const JS::Value & aOntouchmove); \
  NS_IMETHOD GetOntouchenter(JSContext* cx, JS::Value *aOntouchenter); \
  NS_IMETHOD SetOntouchenter(JSContext* cx, const JS::Value & aOntouchenter); \
  NS_IMETHOD GetOntouchleave(JSContext* cx, JS::Value *aOntouchleave); \
  NS_IMETHOD SetOntouchleave(JSContext* cx, const JS::Value & aOntouchleave); \
  NS_IMETHOD GetOntouchcancel(JSContext* cx, JS::Value *aOntouchcancel); \
  NS_IMETHOD SetOntouchcancel(JSContext* cx, const JS::Value & aOntouchcancel); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITOUCHEVENTRECEIVER(_to) \
  NS_IMETHOD GetOntouchstart(JSContext* cx, JS::Value *aOntouchstart) { return _to GetOntouchstart(cx, aOntouchstart); } \
  NS_IMETHOD SetOntouchstart(JSContext* cx, const JS::Value & aOntouchstart) { return _to SetOntouchstart(cx, aOntouchstart); } \
  NS_IMETHOD GetOntouchend(JSContext* cx, JS::Value *aOntouchend) { return _to GetOntouchend(cx, aOntouchend); } \
  NS_IMETHOD SetOntouchend(JSContext* cx, const JS::Value & aOntouchend) { return _to SetOntouchend(cx, aOntouchend); } \
  NS_IMETHOD GetOntouchmove(JSContext* cx, JS::Value *aOntouchmove) { return _to GetOntouchmove(cx, aOntouchmove); } \
  NS_IMETHOD SetOntouchmove(JSContext* cx, const JS::Value & aOntouchmove) { return _to SetOntouchmove(cx, aOntouchmove); } \
  NS_IMETHOD GetOntouchenter(JSContext* cx, JS::Value *aOntouchenter) { return _to GetOntouchenter(cx, aOntouchenter); } \
  NS_IMETHOD SetOntouchenter(JSContext* cx, const JS::Value & aOntouchenter) { return _to SetOntouchenter(cx, aOntouchenter); } \
  NS_IMETHOD GetOntouchleave(JSContext* cx, JS::Value *aOntouchleave) { return _to GetOntouchleave(cx, aOntouchleave); } \
  NS_IMETHOD SetOntouchleave(JSContext* cx, const JS::Value & aOntouchleave) { return _to SetOntouchleave(cx, aOntouchleave); } \
  NS_IMETHOD GetOntouchcancel(JSContext* cx, JS::Value *aOntouchcancel) { return _to GetOntouchcancel(cx, aOntouchcancel); } \
  NS_IMETHOD SetOntouchcancel(JSContext* cx, const JS::Value & aOntouchcancel) { return _to SetOntouchcancel(cx, aOntouchcancel); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITOUCHEVENTRECEIVER(_to) \
  NS_IMETHOD GetOntouchstart(JSContext* cx, JS::Value *aOntouchstart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOntouchstart(cx, aOntouchstart); } \
  NS_IMETHOD SetOntouchstart(JSContext* cx, const JS::Value & aOntouchstart) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOntouchstart(cx, aOntouchstart); } \
  NS_IMETHOD GetOntouchend(JSContext* cx, JS::Value *aOntouchend) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOntouchend(cx, aOntouchend); } \
  NS_IMETHOD SetOntouchend(JSContext* cx, const JS::Value & aOntouchend) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOntouchend(cx, aOntouchend); } \
  NS_IMETHOD GetOntouchmove(JSContext* cx, JS::Value *aOntouchmove) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOntouchmove(cx, aOntouchmove); } \
  NS_IMETHOD SetOntouchmove(JSContext* cx, const JS::Value & aOntouchmove) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOntouchmove(cx, aOntouchmove); } \
  NS_IMETHOD GetOntouchenter(JSContext* cx, JS::Value *aOntouchenter) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOntouchenter(cx, aOntouchenter); } \
  NS_IMETHOD SetOntouchenter(JSContext* cx, const JS::Value & aOntouchenter) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOntouchenter(cx, aOntouchenter); } \
  NS_IMETHOD GetOntouchleave(JSContext* cx, JS::Value *aOntouchleave) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOntouchleave(cx, aOntouchleave); } \
  NS_IMETHOD SetOntouchleave(JSContext* cx, const JS::Value & aOntouchleave) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOntouchleave(cx, aOntouchleave); } \
  NS_IMETHOD GetOntouchcancel(JSContext* cx, JS::Value *aOntouchcancel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOntouchcancel(cx, aOntouchcancel); } \
  NS_IMETHOD SetOntouchcancel(JSContext* cx, const JS::Value & aOntouchcancel) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOntouchcancel(cx, aOntouchcancel); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTouchEventReceiver : public nsITouchEventReceiver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITOUCHEVENTRECEIVER

  nsTouchEventReceiver();

private:
  ~nsTouchEventReceiver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTouchEventReceiver, nsITouchEventReceiver)

nsTouchEventReceiver::nsTouchEventReceiver()
{
  /* member initializers and constructor code */
}

nsTouchEventReceiver::~nsTouchEventReceiver()
{
  /* destructor code */
}

/* [implicit_jscontext] attribute jsval ontouchstart; */
NS_IMETHODIMP nsTouchEventReceiver::GetOntouchstart(JSContext* cx, JS::Value *aOntouchstart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTouchEventReceiver::SetOntouchstart(JSContext* cx, const JS::Value & aOntouchstart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ontouchend; */
NS_IMETHODIMP nsTouchEventReceiver::GetOntouchend(JSContext* cx, JS::Value *aOntouchend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTouchEventReceiver::SetOntouchend(JSContext* cx, const JS::Value & aOntouchend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ontouchmove; */
NS_IMETHODIMP nsTouchEventReceiver::GetOntouchmove(JSContext* cx, JS::Value *aOntouchmove)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTouchEventReceiver::SetOntouchmove(JSContext* cx, const JS::Value & aOntouchmove)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ontouchenter; */
NS_IMETHODIMP nsTouchEventReceiver::GetOntouchenter(JSContext* cx, JS::Value *aOntouchenter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTouchEventReceiver::SetOntouchenter(JSContext* cx, const JS::Value & aOntouchenter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ontouchleave; */
NS_IMETHODIMP nsTouchEventReceiver::GetOntouchleave(JSContext* cx, JS::Value *aOntouchleave)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTouchEventReceiver::SetOntouchleave(JSContext* cx, const JS::Value & aOntouchleave)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ontouchcancel; */
NS_IMETHODIMP nsTouchEventReceiver::GetOntouchcancel(JSContext* cx, JS::Value *aOntouchcancel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTouchEventReceiver::SetOntouchcancel(JSContext* cx, const JS::Value & aOntouchcancel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMDocumentTouch */
#define NS_IDOMDOCUMENTTOUCH_IID_STR "974cff68-6f0b-4520-8523-fa68b2754656"

#define NS_IDOMDOCUMENTTOUCH_IID \
  {0x974cff68, 0x6f0b, 0x4520, \
    { 0x85, 0x23, 0xfa, 0x68, 0xb2, 0x75, 0x46, 0x56 }}

class NS_NO_VTABLE nsIDOMDocumentTouch : public nsITouchEventReceiver {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOCUMENTTOUCH_IID)

  /* nsIDOMTouch createTouch ([optional] in nsIDOMWindow view, [optional] in nsIDOMEventTarget target, [optional] in long identifier, [optional] in long pageX, [optional] in long pageY, [optional] in long screenX, [optional] in long screenY, [optional] in long clientX, [optional] in long clientY, [optional] in long radiusX, [optional] in long radiusY, [optional] in float rotationAngle, [optional] in float force); */
  NS_IMETHOD CreateTouch(nsIDOMWindow *view, nsIDOMEventTarget *target, int32_t identifier, int32_t pageX, int32_t pageY, int32_t screenX, int32_t screenY, int32_t clientX, int32_t clientY, int32_t radiusX, int32_t radiusY, float rotationAngle, float force, nsIDOMTouch * *_retval) = 0;

  /* nsIDOMTouchList createTouchList ([optional] in nsIVariant aPoints); */
  NS_IMETHOD CreateTouchList(nsIVariant *aPoints, nsIDOMTouchList * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDocumentTouch, NS_IDOMDOCUMENTTOUCH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOCUMENTTOUCH \
  NS_IMETHOD CreateTouch(nsIDOMWindow *view, nsIDOMEventTarget *target, int32_t identifier, int32_t pageX, int32_t pageY, int32_t screenX, int32_t screenY, int32_t clientX, int32_t clientY, int32_t radiusX, int32_t radiusY, float rotationAngle, float force, nsIDOMTouch * *_retval); \
  NS_IMETHOD CreateTouchList(nsIVariant *aPoints, nsIDOMTouchList * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOCUMENTTOUCH(_to) \
  NS_IMETHOD CreateTouch(nsIDOMWindow *view, nsIDOMEventTarget *target, int32_t identifier, int32_t pageX, int32_t pageY, int32_t screenX, int32_t screenY, int32_t clientX, int32_t clientY, int32_t radiusX, int32_t radiusY, float rotationAngle, float force, nsIDOMTouch * *_retval) { return _to CreateTouch(view, target, identifier, pageX, pageY, screenX, screenY, clientX, clientY, radiusX, radiusY, rotationAngle, force, _retval); } \
  NS_IMETHOD CreateTouchList(nsIVariant *aPoints, nsIDOMTouchList * *_retval) { return _to CreateTouchList(aPoints, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOCUMENTTOUCH(_to) \
  NS_IMETHOD CreateTouch(nsIDOMWindow *view, nsIDOMEventTarget *target, int32_t identifier, int32_t pageX, int32_t pageY, int32_t screenX, int32_t screenY, int32_t clientX, int32_t clientY, int32_t radiusX, int32_t radiusY, float rotationAngle, float force, nsIDOMTouch * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateTouch(view, target, identifier, pageX, pageY, screenX, screenY, clientX, clientY, radiusX, radiusY, rotationAngle, force, _retval); } \
  NS_IMETHOD CreateTouchList(nsIVariant *aPoints, nsIDOMTouchList * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateTouchList(aPoints, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDocumentTouch : public nsIDOMDocumentTouch
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOCUMENTTOUCH

  nsDOMDocumentTouch();

private:
  ~nsDOMDocumentTouch();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDocumentTouch, nsIDOMDocumentTouch)

nsDOMDocumentTouch::nsDOMDocumentTouch()
{
  /* member initializers and constructor code */
}

nsDOMDocumentTouch::~nsDOMDocumentTouch()
{
  /* destructor code */
}

/* nsIDOMTouch createTouch ([optional] in nsIDOMWindow view, [optional] in nsIDOMEventTarget target, [optional] in long identifier, [optional] in long pageX, [optional] in long pageY, [optional] in long screenX, [optional] in long screenY, [optional] in long clientX, [optional] in long clientY, [optional] in long radiusX, [optional] in long radiusY, [optional] in float rotationAngle, [optional] in float force); */
NS_IMETHODIMP nsDOMDocumentTouch::CreateTouch(nsIDOMWindow *view, nsIDOMEventTarget *target, int32_t identifier, int32_t pageX, int32_t pageY, int32_t screenX, int32_t screenY, int32_t clientX, int32_t clientY, int32_t radiusX, int32_t radiusY, float rotationAngle, float force, nsIDOMTouch * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMTouchList createTouchList ([optional] in nsIVariant aPoints); */
NS_IMETHODIMP nsDOMDocumentTouch::CreateTouchList(nsIVariant *aPoints, nsIDOMTouchList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMTouchEvent_h__ */

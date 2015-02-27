/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMEvent.idl
 */

#ifndef __gen_nsIDOMEvent_h__
#define __gen_nsIDOMEvent_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMEventTarget; /* forward declaration */

#ifdef ERROR
#undef ERROR
#endif
#include "mozilla/EventForwards.h"
class nsPresContext;
class nsInvalidateRequestList;
namespace IPC {
class Message;
}
namespace mozilla {
namespace dom {
class Event;
class EventTarget;
} // namespace dom
} // namespace mozilla

/* starting interface:    nsIDOMEvent */
#define NS_IDOMEVENT_IID_STR "02d54f52-a1f5-4ad2-b560-36f14012935e"

#define NS_IDOMEVENT_IID \
  {0x02d54f52, 0xa1f5, 0x4ad2, \
    { 0xb5, 0x60, 0x36, 0xf1, 0x40, 0x12, 0x93, 0x5e }}

class NS_NO_VTABLE nsIDOMEvent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMEVENT_IID)

  enum {
    NONE = 0U,
    CAPTURING_PHASE = 1U,
    AT_TARGET = 2U,
    BUBBLING_PHASE = 3U
  };

  /* readonly attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;

  /* readonly attribute nsIDOMEventTarget target; */
  NS_IMETHOD GetTarget(nsIDOMEventTarget * *aTarget) = 0;

  /* readonly attribute nsIDOMEventTarget currentTarget; */
  NS_IMETHOD GetCurrentTarget(nsIDOMEventTarget * *aCurrentTarget) = 0;

  /* readonly attribute unsigned short eventPhase; */
  NS_IMETHOD GetEventPhase(uint16_t *aEventPhase) = 0;

  /* readonly attribute boolean bubbles; */
  NS_IMETHOD GetBubbles(bool *aBubbles) = 0;

  /* readonly attribute boolean cancelable; */
  NS_IMETHOD GetCancelable(bool *aCancelable) = 0;

  /* readonly attribute DOMTimeStamp timeStamp; */
  NS_IMETHOD GetTimeStamp(DOMTimeStamp *aTimeStamp) = 0;

  /* void stopPropagation (); */
  NS_IMETHOD StopPropagation(void) = 0;

  /* void preventDefault (); */
  NS_IMETHOD PreventDefault(void) = 0;

  /* void initEvent (in DOMString eventTypeArg, in boolean canBubbleArg, in boolean cancelableArg); */
  NS_IMETHOD InitEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg) = 0;

  /* readonly attribute boolean defaultPrevented; */
  NS_IMETHOD GetDefaultPrevented(bool *aDefaultPrevented) = 0;

  /* void stopImmediatePropagation (); */
  NS_IMETHOD StopImmediatePropagation(void) = 0;

  enum {
    ALT_MASK = 1,
    CONTROL_MASK = 2,
    SHIFT_MASK = 4,
    META_MASK = 8
  };

  /* readonly attribute nsIDOMEventTarget originalTarget; */
  NS_IMETHOD GetOriginalTarget(nsIDOMEventTarget * *aOriginalTarget) = 0;

  /* readonly attribute nsIDOMEventTarget explicitOriginalTarget; */
  NS_IMETHOD GetExplicitOriginalTarget(nsIDOMEventTarget * *aExplicitOriginalTarget) = 0;

  /* boolean getPreventDefault (); */
  NS_IMETHOD GetPreventDefault(bool *_retval) = 0;

  /* readonly attribute boolean isTrusted; */
  NS_IMETHOD GetIsTrusted(bool *aIsTrusted) = 0;

  /* [noscript] void duplicatePrivateData (); */
  NS_IMETHOD DuplicatePrivateData(void) = 0;

  /* [noscript] void setTarget (in nsIDOMEventTarget aTarget); */
  NS_IMETHOD SetTarget(nsIDOMEventTarget *aTarget) = 0;

  /* [notxpcom] boolean IsDispatchStopped (); */
  NS_IMETHOD_(bool) IsDispatchStopped(void) = 0;

  /* [notxpcom] WidgetEventPtr GetInternalNSEvent (); */
  NS_IMETHOD_(mozilla::WidgetEvent *) GetInternalNSEvent(void) = 0;

  /* [noscript,notxpcom] void SetTrusted (in boolean aTrusted); */
  NS_IMETHOD_(void) SetTrusted(bool aTrusted) = 0;

  /* [notxpcom] void Serialize (in IPCMessagePtr aMsg, in boolean aSerializeInterfaceType); */
  NS_IMETHOD_(void) Serialize(IPC::Message *aMsg, bool aSerializeInterfaceType) = 0;

  /* [notxpcom] boolean Deserialize (in ConstIPCMessagePtr aMsg, out voidPtr aIter); */
  NS_IMETHOD_(bool) Deserialize(const IPC::Message *aMsg, void **aIter) = 0;

  /* [noscript,notxpcom] void SetOwner (in EventTargetPtr aOwner); */
  NS_IMETHOD_(void) SetOwner(mozilla::dom::EventTarget *aOwner) = 0;

  /* [notxpcom] DOMEventPtr InternalDOMEvent (); */
  NS_IMETHOD_(mozilla::dom::Event *) InternalDOMEvent(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMEvent, NS_IDOMEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMEVENT \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD GetTarget(nsIDOMEventTarget * *aTarget); \
  NS_IMETHOD GetCurrentTarget(nsIDOMEventTarget * *aCurrentTarget); \
  NS_IMETHOD GetEventPhase(uint16_t *aEventPhase); \
  NS_IMETHOD GetBubbles(bool *aBubbles); \
  NS_IMETHOD GetCancelable(bool *aCancelable); \
  NS_IMETHOD GetTimeStamp(DOMTimeStamp *aTimeStamp); \
  NS_IMETHOD StopPropagation(void); \
  NS_IMETHOD PreventDefault(void); \
  NS_IMETHOD InitEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg); \
  NS_IMETHOD GetDefaultPrevented(bool *aDefaultPrevented); \
  NS_IMETHOD StopImmediatePropagation(void); \
  NS_IMETHOD GetOriginalTarget(nsIDOMEventTarget * *aOriginalTarget); \
  NS_IMETHOD GetExplicitOriginalTarget(nsIDOMEventTarget * *aExplicitOriginalTarget); \
  NS_IMETHOD GetPreventDefault(bool *_retval); \
  NS_IMETHOD GetIsTrusted(bool *aIsTrusted); \
  NS_IMETHOD DuplicatePrivateData(void); \
  NS_IMETHOD SetTarget(nsIDOMEventTarget *aTarget); \
  NS_IMETHOD_(bool) IsDispatchStopped(void); \
  NS_IMETHOD_(mozilla::WidgetEvent *) GetInternalNSEvent(void); \
  NS_IMETHOD_(void) SetTrusted(bool aTrusted); \
  NS_IMETHOD_(void) Serialize(IPC::Message *aMsg, bool aSerializeInterfaceType); \
  NS_IMETHOD_(bool) Deserialize(const IPC::Message *aMsg, void **aIter); \
  NS_IMETHOD_(void) SetOwner(mozilla::dom::EventTarget *aOwner); \
  NS_IMETHOD_(mozilla::dom::Event *) InternalDOMEvent(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMEVENT(_to) \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD GetTarget(nsIDOMEventTarget * *aTarget) { return _to GetTarget(aTarget); } \
  NS_IMETHOD GetCurrentTarget(nsIDOMEventTarget * *aCurrentTarget) { return _to GetCurrentTarget(aCurrentTarget); } \
  NS_IMETHOD GetEventPhase(uint16_t *aEventPhase) { return _to GetEventPhase(aEventPhase); } \
  NS_IMETHOD GetBubbles(bool *aBubbles) { return _to GetBubbles(aBubbles); } \
  NS_IMETHOD GetCancelable(bool *aCancelable) { return _to GetCancelable(aCancelable); } \
  NS_IMETHOD GetTimeStamp(DOMTimeStamp *aTimeStamp) { return _to GetTimeStamp(aTimeStamp); } \
  NS_IMETHOD StopPropagation(void) { return _to StopPropagation(); } \
  NS_IMETHOD PreventDefault(void) { return _to PreventDefault(); } \
  NS_IMETHOD InitEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg) { return _to InitEvent(eventTypeArg, canBubbleArg, cancelableArg); } \
  NS_IMETHOD GetDefaultPrevented(bool *aDefaultPrevented) { return _to GetDefaultPrevented(aDefaultPrevented); } \
  NS_IMETHOD StopImmediatePropagation(void) { return _to StopImmediatePropagation(); } \
  NS_IMETHOD GetOriginalTarget(nsIDOMEventTarget * *aOriginalTarget) { return _to GetOriginalTarget(aOriginalTarget); } \
  NS_IMETHOD GetExplicitOriginalTarget(nsIDOMEventTarget * *aExplicitOriginalTarget) { return _to GetExplicitOriginalTarget(aExplicitOriginalTarget); } \
  NS_IMETHOD GetPreventDefault(bool *_retval) { return _to GetPreventDefault(_retval); } \
  NS_IMETHOD GetIsTrusted(bool *aIsTrusted) { return _to GetIsTrusted(aIsTrusted); } \
  NS_IMETHOD DuplicatePrivateData(void) { return _to DuplicatePrivateData(); } \
  NS_IMETHOD SetTarget(nsIDOMEventTarget *aTarget) { return _to SetTarget(aTarget); } \
  NS_IMETHOD_(bool) IsDispatchStopped(void) { return _to IsDispatchStopped(); } \
  NS_IMETHOD_(mozilla::WidgetEvent *) GetInternalNSEvent(void) { return _to GetInternalNSEvent(); } \
  NS_IMETHOD_(void) SetTrusted(bool aTrusted) { return _to SetTrusted(aTrusted); } \
  NS_IMETHOD_(void) Serialize(IPC::Message *aMsg, bool aSerializeInterfaceType) { return _to Serialize(aMsg, aSerializeInterfaceType); } \
  NS_IMETHOD_(bool) Deserialize(const IPC::Message *aMsg, void **aIter) { return _to Deserialize(aMsg, aIter); } \
  NS_IMETHOD_(void) SetOwner(mozilla::dom::EventTarget *aOwner) { return _to SetOwner(aOwner); } \
  NS_IMETHOD_(mozilla::dom::Event *) InternalDOMEvent(void) { return _to InternalDOMEvent(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMEVENT(_to) \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetTarget(nsIDOMEventTarget * *aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTarget(aTarget); } \
  NS_IMETHOD GetCurrentTarget(nsIDOMEventTarget * *aCurrentTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentTarget(aCurrentTarget); } \
  NS_IMETHOD GetEventPhase(uint16_t *aEventPhase) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEventPhase(aEventPhase); } \
  NS_IMETHOD GetBubbles(bool *aBubbles) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBubbles(aBubbles); } \
  NS_IMETHOD GetCancelable(bool *aCancelable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCancelable(aCancelable); } \
  NS_IMETHOD GetTimeStamp(DOMTimeStamp *aTimeStamp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimeStamp(aTimeStamp); } \
  NS_IMETHOD StopPropagation(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StopPropagation(); } \
  NS_IMETHOD PreventDefault(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PreventDefault(); } \
  NS_IMETHOD InitEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitEvent(eventTypeArg, canBubbleArg, cancelableArg); } \
  NS_IMETHOD GetDefaultPrevented(bool *aDefaultPrevented) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultPrevented(aDefaultPrevented); } \
  NS_IMETHOD StopImmediatePropagation(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StopImmediatePropagation(); } \
  NS_IMETHOD GetOriginalTarget(nsIDOMEventTarget * *aOriginalTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOriginalTarget(aOriginalTarget); } \
  NS_IMETHOD GetExplicitOriginalTarget(nsIDOMEventTarget * *aExplicitOriginalTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExplicitOriginalTarget(aExplicitOriginalTarget); } \
  NS_IMETHOD GetPreventDefault(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreventDefault(_retval); } \
  NS_IMETHOD GetIsTrusted(bool *aIsTrusted) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsTrusted(aIsTrusted); } \
  NS_IMETHOD DuplicatePrivateData(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DuplicatePrivateData(); } \
  NS_IMETHOD SetTarget(nsIDOMEventTarget *aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTarget(aTarget); } \
  NS_IMETHOD_(bool) IsDispatchStopped(void); \
  NS_IMETHOD_(mozilla::WidgetEvent *) GetInternalNSEvent(void); \
  NS_IMETHOD_(void) SetTrusted(bool aTrusted); \
  NS_IMETHOD_(void) Serialize(IPC::Message *aMsg, bool aSerializeInterfaceType); \
  NS_IMETHOD_(bool) Deserialize(const IPC::Message *aMsg, void **aIter); \
  NS_IMETHOD_(void) SetOwner(mozilla::dom::EventTarget *aOwner); \
  NS_IMETHOD_(mozilla::dom::Event *) InternalDOMEvent(void); 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMEvent : public nsIDOMEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMEVENT

  nsDOMEvent();

private:
  ~nsDOMEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMEvent, nsIDOMEvent)

nsDOMEvent::nsDOMEvent()
{
  /* member initializers and constructor code */
}

nsDOMEvent::~nsDOMEvent()
{
  /* destructor code */
}

/* readonly attribute DOMString type; */
NS_IMETHODIMP nsDOMEvent::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMEventTarget target; */
NS_IMETHODIMP nsDOMEvent::GetTarget(nsIDOMEventTarget * *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMEventTarget currentTarget; */
NS_IMETHODIMP nsDOMEvent::GetCurrentTarget(nsIDOMEventTarget * *aCurrentTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short eventPhase; */
NS_IMETHODIMP nsDOMEvent::GetEventPhase(uint16_t *aEventPhase)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean bubbles; */
NS_IMETHODIMP nsDOMEvent::GetBubbles(bool *aBubbles)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean cancelable; */
NS_IMETHODIMP nsDOMEvent::GetCancelable(bool *aCancelable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMTimeStamp timeStamp; */
NS_IMETHODIMP nsDOMEvent::GetTimeStamp(DOMTimeStamp *aTimeStamp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stopPropagation (); */
NS_IMETHODIMP nsDOMEvent::StopPropagation()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void preventDefault (); */
NS_IMETHODIMP nsDOMEvent::PreventDefault()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initEvent (in DOMString eventTypeArg, in boolean canBubbleArg, in boolean cancelableArg); */
NS_IMETHODIMP nsDOMEvent::InitEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean defaultPrevented; */
NS_IMETHODIMP nsDOMEvent::GetDefaultPrevented(bool *aDefaultPrevented)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stopImmediatePropagation (); */
NS_IMETHODIMP nsDOMEvent::StopImmediatePropagation()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMEventTarget originalTarget; */
NS_IMETHODIMP nsDOMEvent::GetOriginalTarget(nsIDOMEventTarget * *aOriginalTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMEventTarget explicitOriginalTarget; */
NS_IMETHODIMP nsDOMEvent::GetExplicitOriginalTarget(nsIDOMEventTarget * *aExplicitOriginalTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getPreventDefault (); */
NS_IMETHODIMP nsDOMEvent::GetPreventDefault(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isTrusted; */
NS_IMETHODIMP nsDOMEvent::GetIsTrusted(bool *aIsTrusted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void duplicatePrivateData (); */
NS_IMETHODIMP nsDOMEvent::DuplicatePrivateData()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setTarget (in nsIDOMEventTarget aTarget); */
NS_IMETHODIMP nsDOMEvent::SetTarget(nsIDOMEventTarget *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean IsDispatchStopped (); */
NS_IMETHODIMP_(bool) nsDOMEvent::IsDispatchStopped()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] WidgetEventPtr GetInternalNSEvent (); */
NS_IMETHODIMP_(mozilla::WidgetEvent *) nsDOMEvent::GetInternalNSEvent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] void SetTrusted (in boolean aTrusted); */
NS_IMETHODIMP_(void) nsDOMEvent::SetTrusted(bool aTrusted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] void Serialize (in IPCMessagePtr aMsg, in boolean aSerializeInterfaceType); */
NS_IMETHODIMP_(void) nsDOMEvent::Serialize(IPC::Message *aMsg, bool aSerializeInterfaceType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean Deserialize (in ConstIPCMessagePtr aMsg, out voidPtr aIter); */
NS_IMETHODIMP_(bool) nsDOMEvent::Deserialize(const IPC::Message *aMsg, void **aIter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] void SetOwner (in EventTargetPtr aOwner); */
NS_IMETHODIMP_(void) nsDOMEvent::SetOwner(mozilla::dom::EventTarget *aOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] DOMEventPtr InternalDOMEvent (); */
NS_IMETHODIMP_(mozilla::dom::Event *) nsDOMEvent::InternalDOMEvent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


nsresult
NS_NewDOMEvent(nsIDOMEvent** aInstancePtrResult,
               mozilla::dom::EventTarget* aOwner,
               nsPresContext* aPresContext,
               mozilla::WidgetEvent* aEvent);
nsresult
NS_NewDOMDataContainerEvent(nsIDOMEvent** aInstancePtrResult,
                            mozilla::dom::EventTarget* aOwner,
                            nsPresContext* aPresContext,
                            mozilla::WidgetEvent* aEvent);
nsresult
NS_NewDOMUIEvent(nsIDOMEvent** aInstancePtrResult,
                 mozilla::dom::EventTarget* aOwner,
                 nsPresContext* aPresContext,
                 mozilla::WidgetGUIEvent* aEvent);
nsresult
NS_NewDOMMouseEvent(nsIDOMEvent** aInstancePtrResult,
                    mozilla::dom::EventTarget* aOwner,
                    nsPresContext* aPresContext,
                    mozilla::WidgetMouseEvent* aEvent);
nsresult
NS_NewDOMFocusEvent(nsIDOMEvent** aInstancePtrResult,
                    mozilla::dom::EventTarget* aOwner,
                    nsPresContext* aPresContext,
                    mozilla::InternalFocusEvent* aEvent);
nsresult
NS_NewDOMMouseScrollEvent(nsIDOMEvent** aInstancePtrResult,
                          mozilla::dom::EventTarget* aOwner,
                          nsPresContext* aPresContext,
                          mozilla::WidgetMouseScrollEvent* aEvent);
nsresult
NS_NewDOMWheelEvent(nsIDOMEvent** aInstancePtrResult,
                    mozilla::dom::EventTarget* aOwner,
                    nsPresContext* aPresContext,
                    mozilla::WidgetWheelEvent* aEvent);
nsresult
NS_NewDOMDragEvent(nsIDOMEvent** aInstancePtrResult,
                   mozilla::dom::EventTarget* aOwner,
                   nsPresContext* aPresContext,
                   mozilla::WidgetDragEvent* aEvent);
nsresult
NS_NewDOMClipboardEvent(nsIDOMEvent** aInstancePtrResult,
                        mozilla::dom::EventTarget* aOwner,
                        nsPresContext* aPresContext,
                        mozilla::InternalClipboardEvent* aEvent);
nsresult
NS_NewDOMKeyboardEvent(nsIDOMEvent** aInstancePtrResult,
                       mozilla::dom::EventTarget* aOwner,
                       nsPresContext* aPresContext,
                       mozilla::WidgetKeyboardEvent* aEvent);
nsresult
NS_NewDOMCompositionEvent(nsIDOMEvent** aInstancePtrResult,
                          mozilla::dom::EventTarget* aOwner,
                          nsPresContext* aPresContext,
                          mozilla::WidgetCompositionEvent* aEvent);
nsresult
NS_NewDOMMutationEvent(nsIDOMEvent** aResult,
                       mozilla::dom::EventTarget* aOwner,
                       nsPresContext* aPresContext,
                       mozilla::InternalMutationEvent* aEvent);
nsresult
NS_NewDOMDeviceMotionEvent(nsIDOMEvent** aResult,
                           mozilla::dom::EventTarget* aOwner,
                           nsPresContext* aPresContext,
                           mozilla::WidgetEvent* aEvent);
nsresult
NS_NewDOMTextEvent(nsIDOMEvent** aResult,
                   mozilla::dom::EventTarget* aOwner,
                   nsPresContext* aPresContext,
                   mozilla::WidgetTextEvent* aEvent);
nsresult
NS_NewDOMBeforeUnloadEvent(nsIDOMEvent** aResult,
                           mozilla::dom::EventTarget* aOwner,
                           nsPresContext* aPresContext,
                           mozilla::WidgetEvent* aEvent);
nsresult
NS_NewDOMSVGEvent(nsIDOMEvent** aResult,
                  mozilla::dom::EventTarget* aOwner,
                  nsPresContext* aPresContext,
                  mozilla::WidgetEvent* aEvent);
nsresult
NS_NewDOMSVGZoomEvent(nsIDOMEvent** aResult,
                      mozilla::dom::EventTarget* aOwner,
                      nsPresContext* aPresContext,
                      mozilla::WidgetGUIEvent* aEvent);
nsresult
NS_NewDOMTimeEvent(nsIDOMEvent** aResult,
                   mozilla::dom::EventTarget* aOwner,
                   nsPresContext* aPresContext,
                   mozilla::WidgetEvent* aEvent);
nsresult
NS_NewDOMXULCommandEvent(nsIDOMEvent** aResult,
                         mozilla::dom::EventTarget* aOwner,
                         nsPresContext* aPresContext,
                         mozilla::WidgetInputEvent* aEvent);
nsresult
NS_NewDOMCommandEvent(nsIDOMEvent** aInstancePtrResult,
                      mozilla::dom::EventTarget* aOwner,
                      nsPresContext* aPresContext,
                      mozilla::WidgetCommandEvent* aEvent);
nsresult
NS_NewDOMMessageEvent(nsIDOMEvent** aInstancePtrResult,
                      mozilla::dom::EventTarget* aOwner,
                      nsPresContext* aPresContext,
                      mozilla::WidgetEvent* aEvent);
nsresult
NS_NewDOMProgressEvent(nsIDOMEvent** aInstancePtrResult,
                       mozilla::dom::EventTarget* aOwner,
                       nsPresContext* aPresContext,
                       mozilla::WidgetEvent* aEvent);
// This empties aInvalidateRequests.
nsresult
NS_NewDOMNotifyPaintEvent(nsIDOMEvent** aResult,
                          mozilla::dom::EventTarget* aOwner,
                          nsPresContext* aPresContext,
                          mozilla::WidgetEvent* aEvent,
                          uint32_t aEventType = 0,
                          nsInvalidateRequestList* aInvalidateRequests = nullptr);
nsresult
NS_NewDOMAudioAvailableEvent(nsIDOMEvent** aResult,
                             mozilla::dom::EventTarget* aOwner,
                             nsPresContext* aPresContext,
                             mozilla::WidgetEvent* aEvent,
                             uint32_t aEventType = 0,
                             float* aFrameBuffer = nullptr,
                             uint32_t aFrameBufferLength = 0,
                             float aTime = 0);
nsresult
NS_NewDOMSimpleGestureEvent(nsIDOMEvent** aInstancePtrResult,
                            mozilla::dom::EventTarget* aOwner,
                            nsPresContext* aPresContext,
                            mozilla::WidgetSimpleGestureEvent* aEvent);
nsresult
NS_NewDOMScrollAreaEvent(nsIDOMEvent** aInstancePtrResult,
                         mozilla::dom::EventTarget* aOwner,
                         nsPresContext* aPresContext,
                         mozilla::InternalScrollAreaEvent* aEvent);
nsresult
NS_NewDOMTransitionEvent(nsIDOMEvent** aInstancePtrResult,
                         mozilla::dom::EventTarget* aOwner,
                         nsPresContext* aPresContext,
                         mozilla::InternalTransitionEvent* aEvent);
nsresult
NS_NewDOMAnimationEvent(nsIDOMEvent** aInstancePtrResult,
                        mozilla::dom::EventTarget* aOwner,
                        nsPresContext* aPresContext,
                        mozilla::InternalAnimationEvent* aEvent);
nsresult
NS_NewDOMPointerEvent(nsIDOMEvent** aInstancePtrResult,
                      mozilla::dom::EventTarget* aOwner,
                      nsPresContext* aPresContext,
                      mozilla::WidgetPointerEvent* aEvent);
nsresult
NS_NewDOMTouchEvent(nsIDOMEvent** aInstancePtrResult,
                    mozilla::dom::EventTarget* aOwner,
                    nsPresContext* aPresContext,
                    mozilla::WidgetTouchEvent* aEvent);
nsresult
NS_NewDOMMozSettingsEvent(nsIDOMEvent** aInstancePtrResult,
                          mozilla::dom::EventTarget* aOwner,
                          nsPresContext* aPresContext,
                          mozilla::WidgetEvent* aEvent);
nsresult
NS_NewDOMMozApplicationEvent(nsIDOMEvent** aInstancePtrResult,
                             mozilla::dom::EventTarget* aOwner,
                             nsPresContext* aPresContext,
                             mozilla::WidgetEvent* aEvent);

#endif /* __gen_nsIDOMEvent_h__ */

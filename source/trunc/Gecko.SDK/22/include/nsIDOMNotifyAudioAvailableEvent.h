/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMNotifyAudioAvailableEvent.idl
 */

#ifndef __gen_nsIDOMNotifyAudioAvailableEvent_h__
#define __gen_nsIDOMNotifyAudioAvailableEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

#ifndef __gen_nsIVariant_h__
#include "nsIVariant.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNotifyAudioAvailableEvent */
#define NS_IDOMNOTIFYAUDIOAVAILABLEEVENT_IID_STR "2345d43d-197a-4589-a4b7-983b41b76c25"

#define NS_IDOMNOTIFYAUDIOAVAILABLEEVENT_IID \
  {0x2345d43d, 0x197a, 0x4589, \
    { 0xa4, 0xb7, 0x98, 0x3b, 0x41, 0xb7, 0x6c, 0x25 }}

class NS_NO_VTABLE nsIDOMNotifyAudioAvailableEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNOTIFYAUDIOAVAILABLEEVENT_IID)

  /* [implicit_jscontext] readonly attribute jsval frameBuffer; */
  NS_IMETHOD GetFrameBuffer(JSContext* cx, JS::Value *aFrameBuffer) = 0;

  /* readonly attribute float time; */
  NS_IMETHOD GetTime(float *aTime) = 0;

  /* void initAudioAvailableEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, [array, size_is (frameBufferLength)] in float frameBufferPtr, in unsigned long frameBufferLength, in float time, in boolean allowAudioData); */
  NS_IMETHOD InitAudioAvailableEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, float *frameBufferPtr, uint32_t frameBufferLength, float time, bool allowAudioData) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNotifyAudioAvailableEvent, NS_IDOMNOTIFYAUDIOAVAILABLEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNOTIFYAUDIOAVAILABLEEVENT \
  NS_IMETHOD GetFrameBuffer(JSContext* cx, JS::Value *aFrameBuffer); \
  NS_IMETHOD GetTime(float *aTime); \
  NS_IMETHOD InitAudioAvailableEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, float *frameBufferPtr, uint32_t frameBufferLength, float time, bool allowAudioData); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNOTIFYAUDIOAVAILABLEEVENT(_to) \
  NS_IMETHOD GetFrameBuffer(JSContext* cx, JS::Value *aFrameBuffer) { return _to GetFrameBuffer(cx, aFrameBuffer); } \
  NS_IMETHOD GetTime(float *aTime) { return _to GetTime(aTime); } \
  NS_IMETHOD InitAudioAvailableEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, float *frameBufferPtr, uint32_t frameBufferLength, float time, bool allowAudioData) { return _to InitAudioAvailableEvent(typeArg, canBubbleArg, cancelableArg, frameBufferPtr, frameBufferLength, time, allowAudioData); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNOTIFYAUDIOAVAILABLEEVENT(_to) \
  NS_IMETHOD GetFrameBuffer(JSContext* cx, JS::Value *aFrameBuffer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFrameBuffer(cx, aFrameBuffer); } \
  NS_IMETHOD GetTime(float *aTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTime(aTime); } \
  NS_IMETHOD InitAudioAvailableEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, float *frameBufferPtr, uint32_t frameBufferLength, float time, bool allowAudioData) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitAudioAvailableEvent(typeArg, canBubbleArg, cancelableArg, frameBufferPtr, frameBufferLength, time, allowAudioData); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNotifyAudioAvailableEvent : public nsIDOMNotifyAudioAvailableEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNOTIFYAUDIOAVAILABLEEVENT

  nsDOMNotifyAudioAvailableEvent();

private:
  ~nsDOMNotifyAudioAvailableEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNotifyAudioAvailableEvent, nsIDOMNotifyAudioAvailableEvent)

nsDOMNotifyAudioAvailableEvent::nsDOMNotifyAudioAvailableEvent()
{
  /* member initializers and constructor code */
}

nsDOMNotifyAudioAvailableEvent::~nsDOMNotifyAudioAvailableEvent()
{
  /* destructor code */
}

/* [implicit_jscontext] readonly attribute jsval frameBuffer; */
NS_IMETHODIMP nsDOMNotifyAudioAvailableEvent::GetFrameBuffer(JSContext* cx, JS::Value *aFrameBuffer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float time; */
NS_IMETHODIMP nsDOMNotifyAudioAvailableEvent::GetTime(float *aTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initAudioAvailableEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, [array, size_is (frameBufferLength)] in float frameBufferPtr, in unsigned long frameBufferLength, in float time, in boolean allowAudioData); */
NS_IMETHODIMP nsDOMNotifyAudioAvailableEvent::InitAudioAvailableEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, float *frameBufferPtr, uint32_t frameBufferLength, float time, bool allowAudioData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNotifyAudioAvailableEvent_h__ */

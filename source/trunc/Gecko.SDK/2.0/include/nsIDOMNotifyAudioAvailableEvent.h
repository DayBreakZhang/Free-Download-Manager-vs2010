/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/events/nsIDOMNotifyAudioAvailableEvent.idl
 */

#ifndef __gen_nsIDOMNotifyAudioAvailableEvent_h__
#define __gen_nsIDOMNotifyAudioAvailableEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

#ifndef __gen_nsIVariant_h__
#include "nsIVariant.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "jspubtd.h"

/* starting interface:    nsIDOMNotifyAudioAvailableEvent */
#define NS_IDOMNOTIFYAUDIOAVAILABLEEVENT_IID_STR "6250652d-7a6a-49a4-a2ee-9114e1e83427"

#define NS_IDOMNOTIFYAUDIOAVAILABLEEVENT_IID \
  {0x6250652d, 0x7a6a, 0x49a4, \
    { 0xa2, 0xee, 0x91, 0x14, 0xe1, 0xe8, 0x34, 0x27 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNotifyAudioAvailableEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNOTIFYAUDIOAVAILABLEEVENT_IID)

  /* [implicit_jscontext] readonly attribute jsval frameBuffer; */
  NS_SCRIPTABLE NS_IMETHOD GetFrameBuffer(JSContext *cx, jsval *aFrameBuffer) = 0;

  /* readonly attribute float time; */
  NS_SCRIPTABLE NS_IMETHOD GetTime(float *aTime) = 0;

  /* void initAudioAvailableEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, [array, size_is (frameBufferLength)] in float frameBufferPtr, in unsigned long frameBufferLength, in float time, in boolean allowAudioData); */
  NS_SCRIPTABLE NS_IMETHOD InitAudioAvailableEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, float *frameBufferPtr, PRUint32 frameBufferLength, float time, PRBool allowAudioData) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNotifyAudioAvailableEvent, NS_IDOMNOTIFYAUDIOAVAILABLEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNOTIFYAUDIOAVAILABLEEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetFrameBuffer(JSContext *cx, jsval *aFrameBuffer); \
  NS_SCRIPTABLE NS_IMETHOD GetTime(float *aTime); \
  NS_SCRIPTABLE NS_IMETHOD InitAudioAvailableEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, float *frameBufferPtr, PRUint32 frameBufferLength, float time, PRBool allowAudioData); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNOTIFYAUDIOAVAILABLEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFrameBuffer(JSContext *cx, jsval *aFrameBuffer) { return _to GetFrameBuffer(cx, aFrameBuffer); } \
  NS_SCRIPTABLE NS_IMETHOD GetTime(float *aTime) { return _to GetTime(aTime); } \
  NS_SCRIPTABLE NS_IMETHOD InitAudioAvailableEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, float *frameBufferPtr, PRUint32 frameBufferLength, float time, PRBool allowAudioData) { return _to InitAudioAvailableEvent(typeArg, canBubbleArg, cancelableArg, frameBufferPtr, frameBufferLength, time, allowAudioData); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNOTIFYAUDIOAVAILABLEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFrameBuffer(JSContext *cx, jsval *aFrameBuffer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFrameBuffer(cx, aFrameBuffer); } \
  NS_SCRIPTABLE NS_IMETHOD GetTime(float *aTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTime(aTime); } \
  NS_SCRIPTABLE NS_IMETHOD InitAudioAvailableEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, float *frameBufferPtr, PRUint32 frameBufferLength, float time, PRBool allowAudioData) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitAudioAvailableEvent(typeArg, canBubbleArg, cancelableArg, frameBufferPtr, frameBufferLength, time, allowAudioData); } 

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
NS_IMETHODIMP nsDOMNotifyAudioAvailableEvent::GetFrameBuffer(JSContext *cx, jsval *aFrameBuffer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float time; */
NS_IMETHODIMP nsDOMNotifyAudioAvailableEvent::GetTime(float *aTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initAudioAvailableEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, [array, size_is (frameBufferLength)] in float frameBufferPtr, in unsigned long frameBufferLength, in float time, in boolean allowAudioData); */
NS_IMETHODIMP nsDOMNotifyAudioAvailableEvent::InitAudioAvailableEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, float *frameBufferPtr, PRUint32 frameBufferLength, float time, PRBool allowAudioData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNotifyAudioAvailableEvent_h__ */

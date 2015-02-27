/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMDragEvent.idl
 */

#ifndef __gen_nsIDOMDragEvent_h__
#define __gen_nsIDOMDragEvent_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDOMMouseEvent_h__
#include "nsIDOMMouseEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDataTransfer; /* forward declaration */


/* starting interface:    nsIDOMDragEvent */
#define NS_IDOMDRAGEVENT_IID_STR "4d0fe952-7ca7-4730-a163-4454e39ed187"

#define NS_IDOMDRAGEVENT_IID \
  {0x4d0fe952, 0x7ca7, 0x4730, \
    { 0xa1, 0x63, 0x44, 0x54, 0xe3, 0x9e, 0xd1, 0x87 }}

class NS_NO_VTABLE nsIDOMDragEvent : public nsIDOMMouseEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDRAGEVENT_IID)

  /* readonly attribute nsIDOMDataTransfer dataTransfer; */
  NS_IMETHOD GetDataTransfer(nsIDOMDataTransfer * *aDataTransfer) = 0;

  /* void initDragEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow aView, in long aDetail, in long aScreenX, in long aScreenY, in long aClientX, in long aClientY, in boolean aCtrlKey, in boolean aAltKey, in boolean aShiftKey, in boolean aMetaKey, in unsigned short aButton, in nsIDOMEventTarget aRelatedTarget, in nsIDOMDataTransfer aDataTransfer); */
  NS_IMETHOD InitDragEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *aView, int32_t aDetail, int32_t aScreenX, int32_t aScreenY, int32_t aClientX, int32_t aClientY, bool aCtrlKey, bool aAltKey, bool aShiftKey, bool aMetaKey, uint16_t aButton, nsIDOMEventTarget *aRelatedTarget, nsIDOMDataTransfer *aDataTransfer) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDragEvent, NS_IDOMDRAGEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDRAGEVENT \
  NS_IMETHOD GetDataTransfer(nsIDOMDataTransfer * *aDataTransfer); \
  NS_IMETHOD InitDragEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *aView, int32_t aDetail, int32_t aScreenX, int32_t aScreenY, int32_t aClientX, int32_t aClientY, bool aCtrlKey, bool aAltKey, bool aShiftKey, bool aMetaKey, uint16_t aButton, nsIDOMEventTarget *aRelatedTarget, nsIDOMDataTransfer *aDataTransfer); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDRAGEVENT(_to) \
  NS_IMETHOD GetDataTransfer(nsIDOMDataTransfer * *aDataTransfer) { return _to GetDataTransfer(aDataTransfer); } \
  NS_IMETHOD InitDragEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *aView, int32_t aDetail, int32_t aScreenX, int32_t aScreenY, int32_t aClientX, int32_t aClientY, bool aCtrlKey, bool aAltKey, bool aShiftKey, bool aMetaKey, uint16_t aButton, nsIDOMEventTarget *aRelatedTarget, nsIDOMDataTransfer *aDataTransfer) { return _to InitDragEvent(typeArg, canBubbleArg, cancelableArg, aView, aDetail, aScreenX, aScreenY, aClientX, aClientY, aCtrlKey, aAltKey, aShiftKey, aMetaKey, aButton, aRelatedTarget, aDataTransfer); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDRAGEVENT(_to) \
  NS_IMETHOD GetDataTransfer(nsIDOMDataTransfer * *aDataTransfer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataTransfer(aDataTransfer); } \
  NS_IMETHOD InitDragEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *aView, int32_t aDetail, int32_t aScreenX, int32_t aScreenY, int32_t aClientX, int32_t aClientY, bool aCtrlKey, bool aAltKey, bool aShiftKey, bool aMetaKey, uint16_t aButton, nsIDOMEventTarget *aRelatedTarget, nsIDOMDataTransfer *aDataTransfer) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitDragEvent(typeArg, canBubbleArg, cancelableArg, aView, aDetail, aScreenX, aScreenY, aClientX, aClientY, aCtrlKey, aAltKey, aShiftKey, aMetaKey, aButton, aRelatedTarget, aDataTransfer); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDragEvent : public nsIDOMDragEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDRAGEVENT

  nsDOMDragEvent();

private:
  ~nsDOMDragEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDragEvent, nsIDOMDragEvent)

nsDOMDragEvent::nsDOMDragEvent()
{
  /* member initializers and constructor code */
}

nsDOMDragEvent::~nsDOMDragEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMDataTransfer dataTransfer; */
NS_IMETHODIMP nsDOMDragEvent::GetDataTransfer(nsIDOMDataTransfer * *aDataTransfer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initDragEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow aView, in long aDetail, in long aScreenX, in long aScreenY, in long aClientX, in long aClientY, in boolean aCtrlKey, in boolean aAltKey, in boolean aShiftKey, in boolean aMetaKey, in unsigned short aButton, in nsIDOMEventTarget aRelatedTarget, in nsIDOMDataTransfer aDataTransfer); */
NS_IMETHODIMP nsDOMDragEvent::InitDragEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *aView, int32_t aDetail, int32_t aScreenX, int32_t aScreenY, int32_t aClientX, int32_t aClientY, bool aCtrlKey, bool aAltKey, bool aShiftKey, bool aMetaKey, uint16_t aButton, nsIDOMEventTarget *aRelatedTarget, nsIDOMDataTransfer *aDataTransfer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDragEvent_h__ */

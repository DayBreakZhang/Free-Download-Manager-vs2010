/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/xul/nsIDOMXULCommandEvent.idl
 */

#ifndef __gen_nsIDOMXULCommandEvent_h__
#define __gen_nsIDOMXULCommandEvent_h__


#ifndef __gen_nsIDOMUIEvent_h__
#include "nsIDOMUIEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMXULCommandEvent */
#define NS_IDOMXULCOMMANDEVENT_IID_STR "2d5b6e19-74bb-40af-9aac-59a1e53e3fcc"

#define NS_IDOMXULCOMMANDEVENT_IID \
  {0x2d5b6e19, 0x74bb, 0x40af, \
    { 0x9a, 0xac, 0x59, 0xa1, 0xe5, 0x3e, 0x3f, 0xcc }}

class NS_NO_VTABLE nsIDOMXULCommandEvent : public nsIDOMUIEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULCOMMANDEVENT_IID)

  /* readonly attribute boolean ctrlKey; */
  NS_IMETHOD GetCtrlKey(bool *aCtrlKey) = 0;

  /* readonly attribute boolean shiftKey; */
  NS_IMETHOD GetShiftKey(bool *aShiftKey) = 0;

  /* readonly attribute boolean altKey; */
  NS_IMETHOD GetAltKey(bool *aAltKey) = 0;

  /* readonly attribute boolean metaKey; */
  NS_IMETHOD GetMetaKey(bool *aMetaKey) = 0;

  /* readonly attribute nsIDOMEvent sourceEvent; */
  NS_IMETHOD GetSourceEvent(nsIDOMEvent * *aSourceEvent) = 0;

  /* void initCommandEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow viewArg, in long detailArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in nsIDOMEvent sourceEvent); */
  NS_IMETHOD InitCommandEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, nsIDOMEvent *sourceEvent) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULCommandEvent, NS_IDOMXULCOMMANDEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULCOMMANDEVENT \
  NS_IMETHOD GetCtrlKey(bool *aCtrlKey); \
  NS_IMETHOD GetShiftKey(bool *aShiftKey); \
  NS_IMETHOD GetAltKey(bool *aAltKey); \
  NS_IMETHOD GetMetaKey(bool *aMetaKey); \
  NS_IMETHOD GetSourceEvent(nsIDOMEvent * *aSourceEvent); \
  NS_IMETHOD InitCommandEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, nsIDOMEvent *sourceEvent); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULCOMMANDEVENT(_to) \
  NS_IMETHOD GetCtrlKey(bool *aCtrlKey) { return _to GetCtrlKey(aCtrlKey); } \
  NS_IMETHOD GetShiftKey(bool *aShiftKey) { return _to GetShiftKey(aShiftKey); } \
  NS_IMETHOD GetAltKey(bool *aAltKey) { return _to GetAltKey(aAltKey); } \
  NS_IMETHOD GetMetaKey(bool *aMetaKey) { return _to GetMetaKey(aMetaKey); } \
  NS_IMETHOD GetSourceEvent(nsIDOMEvent * *aSourceEvent) { return _to GetSourceEvent(aSourceEvent); } \
  NS_IMETHOD InitCommandEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, nsIDOMEvent *sourceEvent) { return _to InitCommandEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, sourceEvent); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULCOMMANDEVENT(_to) \
  NS_IMETHOD GetCtrlKey(bool *aCtrlKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCtrlKey(aCtrlKey); } \
  NS_IMETHOD GetShiftKey(bool *aShiftKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShiftKey(aShiftKey); } \
  NS_IMETHOD GetAltKey(bool *aAltKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAltKey(aAltKey); } \
  NS_IMETHOD GetMetaKey(bool *aMetaKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMetaKey(aMetaKey); } \
  NS_IMETHOD GetSourceEvent(nsIDOMEvent * *aSourceEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceEvent(aSourceEvent); } \
  NS_IMETHOD InitCommandEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, nsIDOMEvent *sourceEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitCommandEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, sourceEvent); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULCommandEvent : public nsIDOMXULCommandEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULCOMMANDEVENT

  nsDOMXULCommandEvent();

private:
  ~nsDOMXULCommandEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULCommandEvent, nsIDOMXULCommandEvent)

nsDOMXULCommandEvent::nsDOMXULCommandEvent()
{
  /* member initializers and constructor code */
}

nsDOMXULCommandEvent::~nsDOMXULCommandEvent()
{
  /* destructor code */
}

/* readonly attribute boolean ctrlKey; */
NS_IMETHODIMP nsDOMXULCommandEvent::GetCtrlKey(bool *aCtrlKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean shiftKey; */
NS_IMETHODIMP nsDOMXULCommandEvent::GetShiftKey(bool *aShiftKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean altKey; */
NS_IMETHODIMP nsDOMXULCommandEvent::GetAltKey(bool *aAltKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean metaKey; */
NS_IMETHODIMP nsDOMXULCommandEvent::GetMetaKey(bool *aMetaKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMEvent sourceEvent; */
NS_IMETHODIMP nsDOMXULCommandEvent::GetSourceEvent(nsIDOMEvent * *aSourceEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initCommandEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow viewArg, in long detailArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in nsIDOMEvent sourceEvent); */
NS_IMETHODIMP nsDOMXULCommandEvent::InitCommandEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, nsIDOMEvent *sourceEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULCommandEvent_h__ */

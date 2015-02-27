/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMUIEvent.idl
 */

#ifndef __gen_nsIDOMUIEvent_h__
#define __gen_nsIDOMUIEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMUIEvent */
#define NS_IDOMUIEVENT_IID_STR "d73852f8-7bd6-477d-8233-117dbf83860b"

#define NS_IDOMUIEVENT_IID \
  {0xd73852f8, 0x7bd6, 0x477d, \
    { 0x82, 0x33, 0x11, 0x7d, 0xbf, 0x83, 0x86, 0x0b }}

class NS_NO_VTABLE nsIDOMUIEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMUIEVENT_IID)

  /* readonly attribute nsIDOMWindow view; */
  NS_IMETHOD GetView(nsIDOMWindow * *aView) = 0;

  /* readonly attribute long detail; */
  NS_IMETHOD GetDetail(int32_t *aDetail) = 0;

  /* void initUIEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow viewArg, in long detailArg); */
  NS_IMETHOD InitUIEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg) = 0;

  enum {
    SCROLL_PAGE_UP = -32768,
    SCROLL_PAGE_DOWN = 32768
  };

  /* readonly attribute long layerX; */
  NS_IMETHOD GetLayerX(int32_t *aLayerX) = 0;

  /* readonly attribute long layerY; */
  NS_IMETHOD GetLayerY(int32_t *aLayerY) = 0;

  /* readonly attribute long pageX; */
  NS_IMETHOD GetPageX(int32_t *aPageX) = 0;

  /* readonly attribute long pageY; */
  NS_IMETHOD GetPageY(int32_t *aPageY) = 0;

  /* readonly attribute unsigned long which; */
  NS_IMETHOD GetWhich(uint32_t *aWhich) = 0;

  /* readonly attribute nsIDOMNode rangeParent; */
  NS_IMETHOD GetRangeParent(nsIDOMNode * *aRangeParent) = 0;

  /* readonly attribute long rangeOffset; */
  NS_IMETHOD GetRangeOffset(int32_t *aRangeOffset) = 0;

  /* attribute boolean cancelBubble; */
  NS_IMETHOD GetCancelBubble(bool *aCancelBubble) = 0;
  NS_IMETHOD SetCancelBubble(bool aCancelBubble) = 0;

  /* readonly attribute boolean isChar; */
  NS_IMETHOD GetIsChar(bool *aIsChar) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMUIEvent, NS_IDOMUIEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMUIEVENT \
  NS_IMETHOD GetView(nsIDOMWindow * *aView); \
  NS_IMETHOD GetDetail(int32_t *aDetail); \
  NS_IMETHOD InitUIEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg); \
  NS_IMETHOD GetLayerX(int32_t *aLayerX); \
  NS_IMETHOD GetLayerY(int32_t *aLayerY); \
  NS_IMETHOD GetPageX(int32_t *aPageX); \
  NS_IMETHOD GetPageY(int32_t *aPageY); \
  NS_IMETHOD GetWhich(uint32_t *aWhich); \
  NS_IMETHOD GetRangeParent(nsIDOMNode * *aRangeParent); \
  NS_IMETHOD GetRangeOffset(int32_t *aRangeOffset); \
  NS_IMETHOD GetCancelBubble(bool *aCancelBubble); \
  NS_IMETHOD SetCancelBubble(bool aCancelBubble); \
  NS_IMETHOD GetIsChar(bool *aIsChar); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMUIEVENT(_to) \
  NS_IMETHOD GetView(nsIDOMWindow * *aView) { return _to GetView(aView); } \
  NS_IMETHOD GetDetail(int32_t *aDetail) { return _to GetDetail(aDetail); } \
  NS_IMETHOD InitUIEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg) { return _to InitUIEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg); } \
  NS_IMETHOD GetLayerX(int32_t *aLayerX) { return _to GetLayerX(aLayerX); } \
  NS_IMETHOD GetLayerY(int32_t *aLayerY) { return _to GetLayerY(aLayerY); } \
  NS_IMETHOD GetPageX(int32_t *aPageX) { return _to GetPageX(aPageX); } \
  NS_IMETHOD GetPageY(int32_t *aPageY) { return _to GetPageY(aPageY); } \
  NS_IMETHOD GetWhich(uint32_t *aWhich) { return _to GetWhich(aWhich); } \
  NS_IMETHOD GetRangeParent(nsIDOMNode * *aRangeParent) { return _to GetRangeParent(aRangeParent); } \
  NS_IMETHOD GetRangeOffset(int32_t *aRangeOffset) { return _to GetRangeOffset(aRangeOffset); } \
  NS_IMETHOD GetCancelBubble(bool *aCancelBubble) { return _to GetCancelBubble(aCancelBubble); } \
  NS_IMETHOD SetCancelBubble(bool aCancelBubble) { return _to SetCancelBubble(aCancelBubble); } \
  NS_IMETHOD GetIsChar(bool *aIsChar) { return _to GetIsChar(aIsChar); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMUIEVENT(_to) \
  NS_IMETHOD GetView(nsIDOMWindow * *aView) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetView(aView); } \
  NS_IMETHOD GetDetail(int32_t *aDetail) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDetail(aDetail); } \
  NS_IMETHOD InitUIEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitUIEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg); } \
  NS_IMETHOD GetLayerX(int32_t *aLayerX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLayerX(aLayerX); } \
  NS_IMETHOD GetLayerY(int32_t *aLayerY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLayerY(aLayerY); } \
  NS_IMETHOD GetPageX(int32_t *aPageX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageX(aPageX); } \
  NS_IMETHOD GetPageY(int32_t *aPageY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageY(aPageY); } \
  NS_IMETHOD GetWhich(uint32_t *aWhich) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWhich(aWhich); } \
  NS_IMETHOD GetRangeParent(nsIDOMNode * *aRangeParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRangeParent(aRangeParent); } \
  NS_IMETHOD GetRangeOffset(int32_t *aRangeOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRangeOffset(aRangeOffset); } \
  NS_IMETHOD GetCancelBubble(bool *aCancelBubble) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCancelBubble(aCancelBubble); } \
  NS_IMETHOD SetCancelBubble(bool aCancelBubble) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCancelBubble(aCancelBubble); } \
  NS_IMETHOD GetIsChar(bool *aIsChar) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsChar(aIsChar); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMUIEvent : public nsIDOMUIEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMUIEVENT

  nsDOMUIEvent();

private:
  ~nsDOMUIEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMUIEvent, nsIDOMUIEvent)

nsDOMUIEvent::nsDOMUIEvent()
{
  /* member initializers and constructor code */
}

nsDOMUIEvent::~nsDOMUIEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMWindow view; */
NS_IMETHODIMP nsDOMUIEvent::GetView(nsIDOMWindow * *aView)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long detail; */
NS_IMETHODIMP nsDOMUIEvent::GetDetail(int32_t *aDetail)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initUIEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow viewArg, in long detailArg); */
NS_IMETHODIMP nsDOMUIEvent::InitUIEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long layerX; */
NS_IMETHODIMP nsDOMUIEvent::GetLayerX(int32_t *aLayerX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long layerY; */
NS_IMETHODIMP nsDOMUIEvent::GetLayerY(int32_t *aLayerY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long pageX; */
NS_IMETHODIMP nsDOMUIEvent::GetPageX(int32_t *aPageX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long pageY; */
NS_IMETHODIMP nsDOMUIEvent::GetPageY(int32_t *aPageY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long which; */
NS_IMETHODIMP nsDOMUIEvent::GetWhich(uint32_t *aWhich)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode rangeParent; */
NS_IMETHODIMP nsDOMUIEvent::GetRangeParent(nsIDOMNode * *aRangeParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long rangeOffset; */
NS_IMETHODIMP nsDOMUIEvent::GetRangeOffset(int32_t *aRangeOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean cancelBubble; */
NS_IMETHODIMP nsDOMUIEvent::GetCancelBubble(bool *aCancelBubble)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMUIEvent::SetCancelBubble(bool aCancelBubble)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isChar; */
NS_IMETHODIMP nsDOMUIEvent::GetIsChar(bool *aIsChar)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMUIEvent_h__ */

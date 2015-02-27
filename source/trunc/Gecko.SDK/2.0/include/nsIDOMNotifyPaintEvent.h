/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/events/nsIDOMNotifyPaintEvent.idl
 */

#ifndef __gen_nsIDOMNotifyPaintEvent_h__
#define __gen_nsIDOMNotifyPaintEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMPaintRequestList; /* forward declaration */


/* starting interface:    nsIDOMNotifyPaintEvent */
#define NS_IDOMNOTIFYPAINTEVENT_IID_STR "792e5779-7c39-4817-91a7-fdb3fba6428f"

#define NS_IDOMNOTIFYPAINTEVENT_IID \
  {0x792e5779, 0x7c39, 0x4817, \
    { 0x91, 0xa7, 0xfd, 0xb3, 0xfb, 0xa6, 0x42, 0x8f }}

/**
 * The nsIDOMNotifyPaintEvent interface is used for the MozDOMAfterPaint
 * event, which fires at a window when painting has happened in
 * that window.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNotifyPaintEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNOTIFYPAINTEVENT_IID)

  /**
   * Get a list of rectangles which are affected. The rectangles are in CSS pixels
   * relative to the viewport origin.
   * If the caller is not trusted (e.g., regular Web content) then only painting
   * caused by the current document is reported; in particular, painting in subdocuments
   * is not reported.
   */
  /* readonly attribute nsIDOMClientRectList clientRects; */
  NS_SCRIPTABLE NS_IMETHOD GetClientRects(nsIDOMClientRectList **aClientRects) = 0;

  /**
   * Get the bounding box of the rectangles which are affected. The rectangle
   * is in CSS pixels relative to the viewport origin.
   * If the caller is not trusted (e.g., regular Web content) then only painting
   * caused by the current document is reported; in particular, painting in subdocuments
   * is not reported.
   */
  /* readonly attribute nsIDOMClientRect boundingClientRect; */
  NS_SCRIPTABLE NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect **aBoundingClientRect) = 0;

  /* readonly attribute nsIDOMPaintRequestList paintRequests; */
  NS_SCRIPTABLE NS_IMETHOD GetPaintRequests(nsIDOMPaintRequestList **aPaintRequests) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNotifyPaintEvent, NS_IDOMNOTIFYPAINTEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNOTIFYPAINTEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetClientRects(nsIDOMClientRectList **aClientRects); \
  NS_SCRIPTABLE NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect **aBoundingClientRect); \
  NS_SCRIPTABLE NS_IMETHOD GetPaintRequests(nsIDOMPaintRequestList **aPaintRequests); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNOTIFYPAINTEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetClientRects(nsIDOMClientRectList **aClientRects) { return _to GetClientRects(aClientRects); } \
  NS_SCRIPTABLE NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect **aBoundingClientRect) { return _to GetBoundingClientRect(aBoundingClientRect); } \
  NS_SCRIPTABLE NS_IMETHOD GetPaintRequests(nsIDOMPaintRequestList **aPaintRequests) { return _to GetPaintRequests(aPaintRequests); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNOTIFYPAINTEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetClientRects(nsIDOMClientRectList **aClientRects) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientRects(aClientRects); } \
  NS_SCRIPTABLE NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect **aBoundingClientRect) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBoundingClientRect(aBoundingClientRect); } \
  NS_SCRIPTABLE NS_IMETHOD GetPaintRequests(nsIDOMPaintRequestList **aPaintRequests) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPaintRequests(aPaintRequests); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNotifyPaintEvent : public nsIDOMNotifyPaintEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNOTIFYPAINTEVENT

  nsDOMNotifyPaintEvent();

private:
  ~nsDOMNotifyPaintEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNotifyPaintEvent, nsIDOMNotifyPaintEvent)

nsDOMNotifyPaintEvent::nsDOMNotifyPaintEvent()
{
  /* member initializers and constructor code */
}

nsDOMNotifyPaintEvent::~nsDOMNotifyPaintEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMClientRectList clientRects; */
NS_IMETHODIMP nsDOMNotifyPaintEvent::GetClientRects(nsIDOMClientRectList **aClientRects)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMClientRect boundingClientRect; */
NS_IMETHODIMP nsDOMNotifyPaintEvent::GetBoundingClientRect(nsIDOMClientRect **aBoundingClientRect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMPaintRequestList paintRequests; */
NS_IMETHODIMP nsDOMNotifyPaintEvent::GetPaintRequests(nsIDOMPaintRequestList **aPaintRequests)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNotifyPaintEvent_h__ */

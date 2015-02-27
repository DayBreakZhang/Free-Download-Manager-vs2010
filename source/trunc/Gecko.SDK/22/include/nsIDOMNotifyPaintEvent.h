/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMNotifyPaintEvent.idl
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
#define NS_IDOMNOTIFYPAINTEVENT_IID_STR "e3560df8-0926-48da-b13a-36d3938c95af"

#define NS_IDOMNOTIFYPAINTEVENT_IID \
  {0xe3560df8, 0x0926, 0x48da, \
    { 0xb1, 0x3a, 0x36, 0xd3, 0x93, 0x8c, 0x95, 0xaf }}

class NS_NO_VTABLE nsIDOMNotifyPaintEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNOTIFYPAINTEVENT_IID)

  /* readonly attribute nsIDOMClientRectList clientRects; */
  NS_IMETHOD GetClientRects(nsIDOMClientRectList * *aClientRects) = 0;

  /* readonly attribute nsIDOMClientRect boundingClientRect; */
  NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect * *aBoundingClientRect) = 0;

  /* readonly attribute nsIDOMPaintRequestList paintRequests; */
  NS_IMETHOD GetPaintRequests(nsIDOMPaintRequestList * *aPaintRequests) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNotifyPaintEvent, NS_IDOMNOTIFYPAINTEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNOTIFYPAINTEVENT \
  NS_IMETHOD GetClientRects(nsIDOMClientRectList * *aClientRects); \
  NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect * *aBoundingClientRect); \
  NS_IMETHOD GetPaintRequests(nsIDOMPaintRequestList * *aPaintRequests); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNOTIFYPAINTEVENT(_to) \
  NS_IMETHOD GetClientRects(nsIDOMClientRectList * *aClientRects) { return _to GetClientRects(aClientRects); } \
  NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect * *aBoundingClientRect) { return _to GetBoundingClientRect(aBoundingClientRect); } \
  NS_IMETHOD GetPaintRequests(nsIDOMPaintRequestList * *aPaintRequests) { return _to GetPaintRequests(aPaintRequests); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNOTIFYPAINTEVENT(_to) \
  NS_IMETHOD GetClientRects(nsIDOMClientRectList * *aClientRects) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientRects(aClientRects); } \
  NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect * *aBoundingClientRect) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBoundingClientRect(aBoundingClientRect); } \
  NS_IMETHOD GetPaintRequests(nsIDOMPaintRequestList * *aPaintRequests) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPaintRequests(aPaintRequests); } 

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
NS_IMETHODIMP nsDOMNotifyPaintEvent::GetClientRects(nsIDOMClientRectList * *aClientRects)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMClientRect boundingClientRect; */
NS_IMETHODIMP nsDOMNotifyPaintEvent::GetBoundingClientRect(nsIDOMClientRect * *aBoundingClientRect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMPaintRequestList paintRequests; */
NS_IMETHODIMP nsDOMNotifyPaintEvent::GetPaintRequests(nsIDOMPaintRequestList * *aPaintRequests)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNotifyPaintEvent_h__ */

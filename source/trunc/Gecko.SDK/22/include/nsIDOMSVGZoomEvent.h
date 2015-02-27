/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/svg/nsIDOMSVGZoomEvent.idl
 */

#ifndef __gen_nsIDOMSVGZoomEvent_h__
#define __gen_nsIDOMSVGZoomEvent_h__


#ifndef __gen_nsIDOMUIEvent_h__
#include "nsIDOMUIEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGRect; /* forward declaration */


/* starting interface:    nsIDOMSVGZoomEvent */
#define NS_IDOMSVGZOOMEVENT_IID_STR "9cf032c6-8485-4bde-90d4-0c8bbff27a12"

#define NS_IDOMSVGZOOMEVENT_IID \
  {0x9cf032c6, 0x8485, 0x4bde, \
    { 0x90, 0xd4, 0x0c, 0x8b, 0xbf, 0xf2, 0x7a, 0x12 }}

class NS_NO_VTABLE nsIDOMSVGZoomEvent : public nsIDOMUIEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGZOOMEVENT_IID)

  /* readonly attribute float previousScale; */
  NS_IMETHOD GetPreviousScale(float *aPreviousScale) = 0;

  /* readonly attribute nsISupports previousTranslate; */
  NS_IMETHOD GetPreviousTranslate(nsISupports * *aPreviousTranslate) = 0;

  /* readonly attribute float newScale; */
  NS_IMETHOD GetNewScale(float *aNewScale) = 0;

  /* readonly attribute nsISupports newTranslate; */
  NS_IMETHOD GetNewTranslate(nsISupports * *aNewTranslate) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGZoomEvent, NS_IDOMSVGZOOMEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGZOOMEVENT \
  NS_IMETHOD GetPreviousScale(float *aPreviousScale); \
  NS_IMETHOD GetPreviousTranslate(nsISupports * *aPreviousTranslate); \
  NS_IMETHOD GetNewScale(float *aNewScale); \
  NS_IMETHOD GetNewTranslate(nsISupports * *aNewTranslate); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGZOOMEVENT(_to) \
  NS_IMETHOD GetPreviousScale(float *aPreviousScale) { return _to GetPreviousScale(aPreviousScale); } \
  NS_IMETHOD GetPreviousTranslate(nsISupports * *aPreviousTranslate) { return _to GetPreviousTranslate(aPreviousTranslate); } \
  NS_IMETHOD GetNewScale(float *aNewScale) { return _to GetNewScale(aNewScale); } \
  NS_IMETHOD GetNewTranslate(nsISupports * *aNewTranslate) { return _to GetNewTranslate(aNewTranslate); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGZOOMEVENT(_to) \
  NS_IMETHOD GetPreviousScale(float *aPreviousScale) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreviousScale(aPreviousScale); } \
  NS_IMETHOD GetPreviousTranslate(nsISupports * *aPreviousTranslate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreviousTranslate(aPreviousTranslate); } \
  NS_IMETHOD GetNewScale(float *aNewScale) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNewScale(aNewScale); } \
  NS_IMETHOD GetNewTranslate(nsISupports * *aNewTranslate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNewTranslate(aNewTranslate); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGZoomEvent : public nsIDOMSVGZoomEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGZOOMEVENT

  nsDOMSVGZoomEvent();

private:
  ~nsDOMSVGZoomEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGZoomEvent, nsIDOMSVGZoomEvent)

nsDOMSVGZoomEvent::nsDOMSVGZoomEvent()
{
  /* member initializers and constructor code */
}

nsDOMSVGZoomEvent::~nsDOMSVGZoomEvent()
{
  /* destructor code */
}

/* readonly attribute float previousScale; */
NS_IMETHODIMP nsDOMSVGZoomEvent::GetPreviousScale(float *aPreviousScale)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports previousTranslate; */
NS_IMETHODIMP nsDOMSVGZoomEvent::GetPreviousTranslate(nsISupports * *aPreviousTranslate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float newScale; */
NS_IMETHODIMP nsDOMSVGZoomEvent::GetNewScale(float *aNewScale)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports newTranslate; */
NS_IMETHODIMP nsDOMSVGZoomEvent::GetNewTranslate(nsISupports * *aNewTranslate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGZoomEvent_h__ */

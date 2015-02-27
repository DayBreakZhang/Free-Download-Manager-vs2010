/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/events/nsIDOMScrollAreaEvent.idl
 */

#ifndef __gen_nsIDOMScrollAreaEvent_h__
#define __gen_nsIDOMScrollAreaEvent_h__


#ifndef __gen_nsIDOMUIEvent_h__
#include "nsIDOMUIEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMScrollAreaEvent */
#define NS_IDOMSCROLLAREAEVENT_IID_STR "b2f49035-4a2f-4e62-8fb0-deb68b0de4d9"

#define NS_IDOMSCROLLAREAEVENT_IID \
  {0xb2f49035, 0x4a2f, 0x4e62, \
    { 0x8f, 0xb0, 0xde, 0xb6, 0x8b, 0x0d, 0xe4, 0xd9 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMScrollAreaEvent : public nsIDOMUIEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSCROLLAREAEVENT_IID)

  /* readonly attribute float x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) = 0;

  /* readonly attribute float y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) = 0;

  /* readonly attribute float width; */
  NS_SCRIPTABLE NS_IMETHOD GetWidth(float *aWidth) = 0;

  /* readonly attribute float height; */
  NS_SCRIPTABLE NS_IMETHOD GetHeight(float *aHeight) = 0;

  /* void initScrollAreaEvent (in DOMString aEventType, in boolean aCanBubble, in boolean aCancelable, in nsIDOMAbstractView aView, in long aDetail, in float x, in float y, in float width, in float height); */
  NS_SCRIPTABLE NS_IMETHOD InitScrollAreaEvent(const nsAString & aEventType, PRBool aCanBubble, PRBool aCancelable, nsIDOMAbstractView *aView, PRInt32 aDetail, float x, float y, float width, float height) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMScrollAreaEvent, NS_IDOMSCROLLAREAEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSCROLLAREAEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY); \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(float *aWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(float *aHeight); \
  NS_SCRIPTABLE NS_IMETHOD InitScrollAreaEvent(const nsAString & aEventType, PRBool aCanBubble, PRBool aCancelable, nsIDOMAbstractView *aView, PRInt32 aDetail, float x, float y, float width, float height); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSCROLLAREAEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(float *aWidth) { return _to GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(float *aHeight) { return _to GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD InitScrollAreaEvent(const nsAString & aEventType, PRBool aCanBubble, PRBool aCancelable, nsIDOMAbstractView *aView, PRInt32 aDetail, float x, float y, float width, float height) { return _to InitScrollAreaEvent(aEventType, aCanBubble, aCancelable, aView, aDetail, x, y, width, height); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSCROLLAREAEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(float *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(float *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD InitScrollAreaEvent(const nsAString & aEventType, PRBool aCanBubble, PRBool aCancelable, nsIDOMAbstractView *aView, PRInt32 aDetail, float x, float y, float width, float height) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitScrollAreaEvent(aEventType, aCanBubble, aCancelable, aView, aDetail, x, y, width, height); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMScrollAreaEvent : public nsIDOMScrollAreaEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSCROLLAREAEVENT

  nsDOMScrollAreaEvent();

private:
  ~nsDOMScrollAreaEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMScrollAreaEvent, nsIDOMScrollAreaEvent)

nsDOMScrollAreaEvent::nsDOMScrollAreaEvent()
{
  /* member initializers and constructor code */
}

nsDOMScrollAreaEvent::~nsDOMScrollAreaEvent()
{
  /* destructor code */
}

/* readonly attribute float x; */
NS_IMETHODIMP nsDOMScrollAreaEvent::GetX(float *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float y; */
NS_IMETHODIMP nsDOMScrollAreaEvent::GetY(float *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float width; */
NS_IMETHODIMP nsDOMScrollAreaEvent::GetWidth(float *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float height; */
NS_IMETHODIMP nsDOMScrollAreaEvent::GetHeight(float *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initScrollAreaEvent (in DOMString aEventType, in boolean aCanBubble, in boolean aCancelable, in nsIDOMAbstractView aView, in long aDetail, in float x, in float y, in float width, in float height); */
NS_IMETHODIMP nsDOMScrollAreaEvent::InitScrollAreaEvent(const nsAString & aEventType, PRBool aCanBubble, PRBool aCancelable, nsIDOMAbstractView *aView, PRInt32 aDetail, float x, float y, float width, float height)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMScrollAreaEvent_h__ */

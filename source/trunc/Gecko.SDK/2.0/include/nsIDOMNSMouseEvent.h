/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/events/nsIDOMNSMouseEvent.idl
 */

#ifndef __gen_nsIDOMNSMouseEvent_h__
#define __gen_nsIDOMNSMouseEvent_h__


#ifndef __gen_nsIDOMMouseEvent_h__
#include "nsIDOMMouseEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNSMouseEvent */
#define NS_IDOMNSMOUSEEVENT_IID_STR "f5dd5fbb-f4ff-4277-819c-f31aa1dafc32"

#define NS_IDOMNSMOUSEEVENT_IID \
  {0xf5dd5fbb, 0xf4ff, 0x4277, \
    { 0x81, 0x9c, 0xf3, 0x1a, 0xa1, 0xda, 0xfc, 0x32 }}

/**
 * The nsIDOMNSMouseEvent interface extends nsIDOMMouseEvent
 * by providing various information related to the mouse event.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSMouseEvent : public nsIDOMMouseEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSMOUSEEVENT_IID)

  /* readonly attribute float mozPressure; */
  NS_SCRIPTABLE NS_IMETHOD GetMozPressure(float *aMozPressure) = 0;

  enum { MOZ_SOURCE_UNKNOWN = 0U };

  enum { MOZ_SOURCE_MOUSE = 1U };

  enum { MOZ_SOURCE_PEN = 2U };

  enum { MOZ_SOURCE_ERASER = 3U };

  enum { MOZ_SOURCE_CURSOR = 4U };

  enum { MOZ_SOURCE_TOUCH = 5U };

  enum { MOZ_SOURCE_KEYBOARD = 6U };

  /* readonly attribute unsigned short mozInputSource; */
  NS_SCRIPTABLE NS_IMETHOD GetMozInputSource(PRUint16 *aMozInputSource) = 0;

  /* void initNSMouseEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMAbstractView viewArg, in long detailArg, in long screenXArg, in long screenYArg, in long clientXArg, in long clientYArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in unsigned short buttonArg, in nsIDOMEventTarget relatedTargetArg, in float pressure, in unsigned short inputSourceArg); */
  NS_SCRIPTABLE NS_IMETHOD InitNSMouseEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg, float pressure, PRUint16 inputSourceArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSMouseEvent, NS_IDOMNSMOUSEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSMOUSEEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetMozPressure(float *aMozPressure); \
  NS_SCRIPTABLE NS_IMETHOD GetMozInputSource(PRUint16 *aMozInputSource); \
  NS_SCRIPTABLE NS_IMETHOD InitNSMouseEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg, float pressure, PRUint16 inputSourceArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSMOUSEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMozPressure(float *aMozPressure) { return _to GetMozPressure(aMozPressure); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozInputSource(PRUint16 *aMozInputSource) { return _to GetMozInputSource(aMozInputSource); } \
  NS_SCRIPTABLE NS_IMETHOD InitNSMouseEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg, float pressure, PRUint16 inputSourceArg) { return _to InitNSMouseEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg, screenXArg, screenYArg, clientXArg, clientYArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, buttonArg, relatedTargetArg, pressure, inputSourceArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSMOUSEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMozPressure(float *aMozPressure) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozPressure(aMozPressure); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozInputSource(PRUint16 *aMozInputSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozInputSource(aMozInputSource); } \
  NS_SCRIPTABLE NS_IMETHOD InitNSMouseEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg, float pressure, PRUint16 inputSourceArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitNSMouseEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg, screenXArg, screenYArg, clientXArg, clientYArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, buttonArg, relatedTargetArg, pressure, inputSourceArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSMouseEvent : public nsIDOMNSMouseEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSMOUSEEVENT

  nsDOMNSMouseEvent();

private:
  ~nsDOMNSMouseEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSMouseEvent, nsIDOMNSMouseEvent)

nsDOMNSMouseEvent::nsDOMNSMouseEvent()
{
  /* member initializers and constructor code */
}

nsDOMNSMouseEvent::~nsDOMNSMouseEvent()
{
  /* destructor code */
}

/* readonly attribute float mozPressure; */
NS_IMETHODIMP nsDOMNSMouseEvent::GetMozPressure(float *aMozPressure)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short mozInputSource; */
NS_IMETHODIMP nsDOMNSMouseEvent::GetMozInputSource(PRUint16 *aMozInputSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initNSMouseEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMAbstractView viewArg, in long detailArg, in long screenXArg, in long screenYArg, in long clientXArg, in long clientYArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in unsigned short buttonArg, in nsIDOMEventTarget relatedTargetArg, in float pressure, in unsigned short inputSourceArg); */
NS_IMETHODIMP nsDOMNSMouseEvent::InitNSMouseEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg, float pressure, PRUint16 inputSourceArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSMouseEvent_h__ */

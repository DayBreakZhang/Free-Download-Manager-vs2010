/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMMouseScrollEvent.idl
 */

#ifndef __gen_nsIDOMMouseScrollEvent_h__
#define __gen_nsIDOMMouseScrollEvent_h__


#ifndef __gen_nsIDOMMouseEvent_h__
#include "nsIDOMMouseEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMouseScrollEvent */
#define NS_IDOMMOUSESCROLLEVENT_IID_STR "2bce5c03-5bed-4c22-8a6a-a3ac8f5563d7"

#define NS_IDOMMOUSESCROLLEVENT_IID \
  {0x2bce5c03, 0x5bed, 0x4c22, \
    { 0x8a, 0x6a, 0xa3, 0xac, 0x8f, 0x55, 0x63, 0xd7 }}

class NS_NO_VTABLE nsIDOMMouseScrollEvent : public nsIDOMMouseEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOUSESCROLLEVENT_IID)

  enum {
    HORIZONTAL_AXIS = 1,
    VERTICAL_AXIS = 2
  };

  /* readonly attribute long axis; */
  NS_IMETHOD GetAxis(int32_t *aAxis) = 0;

  /* void initMouseScrollEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow viewArg, in long detailArg, in long screenXArg, in long screenYArg, in long clientXArg, in long clientYArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in unsigned short buttonArg, in nsIDOMEventTarget relatedTargetArg, in long axis); */
  NS_IMETHOD InitMouseScrollEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg, int32_t screenXArg, int32_t screenYArg, int32_t clientXArg, int32_t clientYArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, uint16_t buttonArg, nsIDOMEventTarget *relatedTargetArg, int32_t axis) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMouseScrollEvent, NS_IDOMMOUSESCROLLEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOUSESCROLLEVENT \
  NS_IMETHOD GetAxis(int32_t *aAxis); \
  NS_IMETHOD InitMouseScrollEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg, int32_t screenXArg, int32_t screenYArg, int32_t clientXArg, int32_t clientYArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, uint16_t buttonArg, nsIDOMEventTarget *relatedTargetArg, int32_t axis); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOUSESCROLLEVENT(_to) \
  NS_IMETHOD GetAxis(int32_t *aAxis) { return _to GetAxis(aAxis); } \
  NS_IMETHOD InitMouseScrollEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg, int32_t screenXArg, int32_t screenYArg, int32_t clientXArg, int32_t clientYArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, uint16_t buttonArg, nsIDOMEventTarget *relatedTargetArg, int32_t axis) { return _to InitMouseScrollEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg, screenXArg, screenYArg, clientXArg, clientYArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, buttonArg, relatedTargetArg, axis); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOUSESCROLLEVENT(_to) \
  NS_IMETHOD GetAxis(int32_t *aAxis) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAxis(aAxis); } \
  NS_IMETHOD InitMouseScrollEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg, int32_t screenXArg, int32_t screenYArg, int32_t clientXArg, int32_t clientYArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, uint16_t buttonArg, nsIDOMEventTarget *relatedTargetArg, int32_t axis) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitMouseScrollEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg, screenXArg, screenYArg, clientXArg, clientYArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, buttonArg, relatedTargetArg, axis); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMouseScrollEvent : public nsIDOMMouseScrollEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOUSESCROLLEVENT

  nsDOMMouseScrollEvent();

private:
  ~nsDOMMouseScrollEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMouseScrollEvent, nsIDOMMouseScrollEvent)

nsDOMMouseScrollEvent::nsDOMMouseScrollEvent()
{
  /* member initializers and constructor code */
}

nsDOMMouseScrollEvent::~nsDOMMouseScrollEvent()
{
  /* destructor code */
}

/* readonly attribute long axis; */
NS_IMETHODIMP nsDOMMouseScrollEvent::GetAxis(int32_t *aAxis)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initMouseScrollEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow viewArg, in long detailArg, in long screenXArg, in long screenYArg, in long clientXArg, in long clientYArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in unsigned short buttonArg, in nsIDOMEventTarget relatedTargetArg, in long axis); */
NS_IMETHODIMP nsDOMMouseScrollEvent::InitMouseScrollEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, int32_t detailArg, int32_t screenXArg, int32_t screenYArg, int32_t clientXArg, int32_t clientYArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, uint16_t buttonArg, nsIDOMEventTarget *relatedTargetArg, int32_t axis)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMouseScrollEvent_h__ */

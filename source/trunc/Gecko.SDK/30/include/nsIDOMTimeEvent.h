/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMTimeEvent.idl
 */

#ifndef __gen_nsIDOMTimeEvent_h__
#define __gen_nsIDOMTimeEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMTimeEvent */
#define NS_IDOMTIMEEVENT_IID_STR "4a5a5fa6-2783-4171-b8bb-cae4ab06e6ff"

#define NS_IDOMTIMEEVENT_IID \
  {0x4a5a5fa6, 0x2783, 0x4171, \
    { 0xb8, 0xbb, 0xca, 0xe4, 0xab, 0x06, 0xe6, 0xff }}

class NS_NO_VTABLE nsIDOMTimeEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMTIMEEVENT_IID)

  /* readonly attribute long detail; */
  NS_IMETHOD GetDetail(int32_t *aDetail) = 0;

  /* readonly attribute nsIDOMWindow view; */
  NS_IMETHOD GetView(nsIDOMWindow * *aView) = 0;

  /* void initTimeEvent (in DOMString typeArg, in nsIDOMWindow viewArg, in long detailArg); */
  NS_IMETHOD InitTimeEvent(const nsAString & typeArg, nsIDOMWindow *viewArg, int32_t detailArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMTimeEvent, NS_IDOMTIMEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMTIMEEVENT \
  NS_IMETHOD GetDetail(int32_t *aDetail); \
  NS_IMETHOD GetView(nsIDOMWindow * *aView); \
  NS_IMETHOD InitTimeEvent(const nsAString & typeArg, nsIDOMWindow *viewArg, int32_t detailArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMTIMEEVENT(_to) \
  NS_IMETHOD GetDetail(int32_t *aDetail) { return _to GetDetail(aDetail); } \
  NS_IMETHOD GetView(nsIDOMWindow * *aView) { return _to GetView(aView); } \
  NS_IMETHOD InitTimeEvent(const nsAString & typeArg, nsIDOMWindow *viewArg, int32_t detailArg) { return _to InitTimeEvent(typeArg, viewArg, detailArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMTIMEEVENT(_to) \
  NS_IMETHOD GetDetail(int32_t *aDetail) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDetail(aDetail); } \
  NS_IMETHOD GetView(nsIDOMWindow * *aView) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetView(aView); } \
  NS_IMETHOD InitTimeEvent(const nsAString & typeArg, nsIDOMWindow *viewArg, int32_t detailArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitTimeEvent(typeArg, viewArg, detailArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMTimeEvent : public nsIDOMTimeEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMTIMEEVENT

  nsDOMTimeEvent();

private:
  ~nsDOMTimeEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMTimeEvent, nsIDOMTimeEvent)

nsDOMTimeEvent::nsDOMTimeEvent()
{
  /* member initializers and constructor code */
}

nsDOMTimeEvent::~nsDOMTimeEvent()
{
  /* destructor code */
}

/* readonly attribute long detail; */
NS_IMETHODIMP nsDOMTimeEvent::GetDetail(int32_t *aDetail)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow view; */
NS_IMETHODIMP nsDOMTimeEvent::GetView(nsIDOMWindow * *aView)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initTimeEvent (in DOMString typeArg, in nsIDOMWindow viewArg, in long detailArg); */
NS_IMETHODIMP nsDOMTimeEvent::InitTimeEvent(const nsAString & typeArg, nsIDOMWindow *viewArg, int32_t detailArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMTimeEvent_h__ */

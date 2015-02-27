/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMBeforeUnloadEvent.idl
 */

#ifndef __gen_nsIDOMBeforeUnloadEvent_h__
#define __gen_nsIDOMBeforeUnloadEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMBeforeUnloadEvent */
#define NS_IDOMBEFOREUNLOADEVENT_IID_STR "ee7b8943-440e-4cc3-b25e-c17c8a821d8b"

#define NS_IDOMBEFOREUNLOADEVENT_IID \
  {0xee7b8943, 0x440e, 0x4cc3, \
    { 0xb2, 0x5e, 0xc1, 0x7c, 0x8a, 0x82, 0x1d, 0x8b }}

class NS_NO_VTABLE nsIDOMBeforeUnloadEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMBEFOREUNLOADEVENT_IID)

  /* attribute DOMString returnValue; */
  NS_IMETHOD GetReturnValue(nsAString & aReturnValue) = 0;
  NS_IMETHOD SetReturnValue(const nsAString & aReturnValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMBeforeUnloadEvent, NS_IDOMBEFOREUNLOADEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMBEFOREUNLOADEVENT \
  NS_IMETHOD GetReturnValue(nsAString & aReturnValue); \
  NS_IMETHOD SetReturnValue(const nsAString & aReturnValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMBEFOREUNLOADEVENT(_to) \
  NS_IMETHOD GetReturnValue(nsAString & aReturnValue) { return _to GetReturnValue(aReturnValue); } \
  NS_IMETHOD SetReturnValue(const nsAString & aReturnValue) { return _to SetReturnValue(aReturnValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMBEFOREUNLOADEVENT(_to) \
  NS_IMETHOD GetReturnValue(nsAString & aReturnValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReturnValue(aReturnValue); } \
  NS_IMETHOD SetReturnValue(const nsAString & aReturnValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReturnValue(aReturnValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMBeforeUnloadEvent : public nsIDOMBeforeUnloadEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMBEFOREUNLOADEVENT

  nsDOMBeforeUnloadEvent();

private:
  ~nsDOMBeforeUnloadEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMBeforeUnloadEvent, nsIDOMBeforeUnloadEvent)

nsDOMBeforeUnloadEvent::nsDOMBeforeUnloadEvent()
{
  /* member initializers and constructor code */
}

nsDOMBeforeUnloadEvent::~nsDOMBeforeUnloadEvent()
{
  /* destructor code */
}

/* attribute DOMString returnValue; */
NS_IMETHODIMP nsDOMBeforeUnloadEvent::GetReturnValue(nsAString & aReturnValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMBeforeUnloadEvent::SetReturnValue(const nsAString & aReturnValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMBeforeUnloadEvent_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/accessible/public/nsIAccessibleTextChangeEvent.idl
 */

#ifndef __gen_nsIAccessibleTextChangeEvent_h__
#define __gen_nsIAccessibleTextChangeEvent_h__


#ifndef __gen_nsIAccessibleEvent_h__
#include "nsIAccessibleEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAccessibleTextChangeEvent */
#define NS_IACCESSIBLETEXTCHANGEEVENT_IID_STR "21e0f8bd-5638-4964-870b-3c8e944ac4c4"

#define NS_IACCESSIBLETEXTCHANGEEVENT_IID \
  {0x21e0f8bd, 0x5638, 0x4964, \
    { 0x87, 0x0b, 0x3c, 0x8e, 0x94, 0x4a, 0xc4, 0xc4 }}

class NS_NO_VTABLE nsIAccessibleTextChangeEvent : public nsIAccessibleEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLETEXTCHANGEEVENT_IID)

  /* readonly attribute long start; */
  NS_IMETHOD GetStart(int32_t *aStart) = 0;

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

  /* readonly attribute boolean isInserted; */
  NS_IMETHOD GetIsInserted(bool *aIsInserted) = 0;

  /* readonly attribute DOMString modifiedText; */
  NS_IMETHOD GetModifiedText(nsAString & aModifiedText) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleTextChangeEvent, NS_IACCESSIBLETEXTCHANGEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLETEXTCHANGEEVENT \
  NS_IMETHOD GetStart(int32_t *aStart); \
  NS_IMETHOD GetLength(uint32_t *aLength); \
  NS_IMETHOD GetIsInserted(bool *aIsInserted); \
  NS_IMETHOD GetModifiedText(nsAString & aModifiedText); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLETEXTCHANGEEVENT(_to) \
  NS_IMETHOD GetStart(int32_t *aStart) { return _to GetStart(aStart); } \
  NS_IMETHOD GetLength(uint32_t *aLength) { return _to GetLength(aLength); } \
  NS_IMETHOD GetIsInserted(bool *aIsInserted) { return _to GetIsInserted(aIsInserted); } \
  NS_IMETHOD GetModifiedText(nsAString & aModifiedText) { return _to GetModifiedText(aModifiedText); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLETEXTCHANGEEVENT(_to) \
  NS_IMETHOD GetStart(int32_t *aStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStart(aStart); } \
  NS_IMETHOD GetLength(uint32_t *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD GetIsInserted(bool *aIsInserted) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsInserted(aIsInserted); } \
  NS_IMETHOD GetModifiedText(nsAString & aModifiedText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetModifiedText(aModifiedText); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleTextChangeEvent : public nsIAccessibleTextChangeEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLETEXTCHANGEEVENT

  nsAccessibleTextChangeEvent();

private:
  ~nsAccessibleTextChangeEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleTextChangeEvent, nsIAccessibleTextChangeEvent)

nsAccessibleTextChangeEvent::nsAccessibleTextChangeEvent()
{
  /* member initializers and constructor code */
}

nsAccessibleTextChangeEvent::~nsAccessibleTextChangeEvent()
{
  /* destructor code */
}

/* readonly attribute long start; */
NS_IMETHODIMP nsAccessibleTextChangeEvent::GetStart(int32_t *aStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsAccessibleTextChangeEvent::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isInserted; */
NS_IMETHODIMP nsAccessibleTextChangeEvent::GetIsInserted(bool *aIsInserted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString modifiedText; */
NS_IMETHODIMP nsAccessibleTextChangeEvent::GetModifiedText(nsAString & aModifiedText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleTextChangeEvent_h__ */

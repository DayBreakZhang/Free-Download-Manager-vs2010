/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/accessible/public/nsIAccessibleVirtualCursorChangeEvent.idl
 */

#ifndef __gen_nsIAccessibleVirtualCursorChangeEvent_h__
#define __gen_nsIAccessibleVirtualCursorChangeEvent_h__


#ifndef __gen_nsIAccessibleEvent_h__
#include "nsIAccessibleEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAccessibleVirtualCursorChangeEvent */
#define NS_IACCESSIBLEVIRTUALCURSORCHANGEEVENT_IID_STR "370e8b9b-2bbc-4bff-a9c7-16ddc54aea21"

#define NS_IACCESSIBLEVIRTUALCURSORCHANGEEVENT_IID \
  {0x370e8b9b, 0x2bbc, 0x4bff, \
    { 0xa9, 0xc7, 0x16, 0xdd, 0xc5, 0x4a, 0xea, 0x21 }}

class NS_NO_VTABLE nsIAccessibleVirtualCursorChangeEvent : public nsIAccessibleEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEVIRTUALCURSORCHANGEEVENT_IID)

  /* readonly attribute nsIAccessible oldAccessible; */
  NS_IMETHOD GetOldAccessible(nsIAccessible * *aOldAccessible) = 0;

  /* readonly attribute long oldStartOffset; */
  NS_IMETHOD GetOldStartOffset(int32_t *aOldStartOffset) = 0;

  /* readonly attribute long oldEndOffset; */
  NS_IMETHOD GetOldEndOffset(int32_t *aOldEndOffset) = 0;

  /* readonly attribute short reason; */
  NS_IMETHOD GetReason(int16_t *aReason) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleVirtualCursorChangeEvent, NS_IACCESSIBLEVIRTUALCURSORCHANGEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEVIRTUALCURSORCHANGEEVENT \
  NS_IMETHOD GetOldAccessible(nsIAccessible * *aOldAccessible); \
  NS_IMETHOD GetOldStartOffset(int32_t *aOldStartOffset); \
  NS_IMETHOD GetOldEndOffset(int32_t *aOldEndOffset); \
  NS_IMETHOD GetReason(int16_t *aReason); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEVIRTUALCURSORCHANGEEVENT(_to) \
  NS_IMETHOD GetOldAccessible(nsIAccessible * *aOldAccessible) { return _to GetOldAccessible(aOldAccessible); } \
  NS_IMETHOD GetOldStartOffset(int32_t *aOldStartOffset) { return _to GetOldStartOffset(aOldStartOffset); } \
  NS_IMETHOD GetOldEndOffset(int32_t *aOldEndOffset) { return _to GetOldEndOffset(aOldEndOffset); } \
  NS_IMETHOD GetReason(int16_t *aReason) { return _to GetReason(aReason); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEVIRTUALCURSORCHANGEEVENT(_to) \
  NS_IMETHOD GetOldAccessible(nsIAccessible * *aOldAccessible) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOldAccessible(aOldAccessible); } \
  NS_IMETHOD GetOldStartOffset(int32_t *aOldStartOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOldStartOffset(aOldStartOffset); } \
  NS_IMETHOD GetOldEndOffset(int32_t *aOldEndOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOldEndOffset(aOldEndOffset); } \
  NS_IMETHOD GetReason(int16_t *aReason) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReason(aReason); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleVirtualCursorChangeEvent : public nsIAccessibleVirtualCursorChangeEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEVIRTUALCURSORCHANGEEVENT

  nsAccessibleVirtualCursorChangeEvent();

private:
  ~nsAccessibleVirtualCursorChangeEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleVirtualCursorChangeEvent, nsIAccessibleVirtualCursorChangeEvent)

nsAccessibleVirtualCursorChangeEvent::nsAccessibleVirtualCursorChangeEvent()
{
  /* member initializers and constructor code */
}

nsAccessibleVirtualCursorChangeEvent::~nsAccessibleVirtualCursorChangeEvent()
{
  /* destructor code */
}

/* readonly attribute nsIAccessible oldAccessible; */
NS_IMETHODIMP nsAccessibleVirtualCursorChangeEvent::GetOldAccessible(nsIAccessible * *aOldAccessible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long oldStartOffset; */
NS_IMETHODIMP nsAccessibleVirtualCursorChangeEvent::GetOldStartOffset(int32_t *aOldStartOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long oldEndOffset; */
NS_IMETHODIMP nsAccessibleVirtualCursorChangeEvent::GetOldEndOffset(int32_t *aOldEndOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute short reason; */
NS_IMETHODIMP nsAccessibleVirtualCursorChangeEvent::GetReason(int16_t *aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleVirtualCursorChangeEvent_h__ */

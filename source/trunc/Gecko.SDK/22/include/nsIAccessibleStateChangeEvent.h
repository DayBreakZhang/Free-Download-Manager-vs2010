/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/accessible/public/nsIAccessibleStateChangeEvent.idl
 */

#ifndef __gen_nsIAccessibleStateChangeEvent_h__
#define __gen_nsIAccessibleStateChangeEvent_h__


#ifndef __gen_nsIAccessibleEvent_h__
#include "nsIAccessibleEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAccessibleStateChangeEvent */
#define NS_IACCESSIBLESTATECHANGEEVENT_IID_STR "0d2d77c5-7b16-4a15-8b20-c484ceb5ac0d"

#define NS_IACCESSIBLESTATECHANGEEVENT_IID \
  {0x0d2d77c5, 0x7b16, 0x4a15, \
    { 0x8b, 0x20, 0xc4, 0x84, 0xce, 0xb5, 0xac, 0x0d }}

class NS_NO_VTABLE nsIAccessibleStateChangeEvent : public nsIAccessibleEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLESTATECHANGEEVENT_IID)

  /* readonly attribute unsigned long state; */
  NS_IMETHOD GetState(uint32_t *aState) = 0;

  /* readonly attribute boolean isExtraState; */
  NS_IMETHOD GetIsExtraState(bool *aIsExtraState) = 0;

  /* readonly attribute boolean isEnabled; */
  NS_IMETHOD GetIsEnabled(bool *aIsEnabled) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleStateChangeEvent, NS_IACCESSIBLESTATECHANGEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLESTATECHANGEEVENT \
  NS_IMETHOD GetState(uint32_t *aState); \
  NS_IMETHOD GetIsExtraState(bool *aIsExtraState); \
  NS_IMETHOD GetIsEnabled(bool *aIsEnabled); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLESTATECHANGEEVENT(_to) \
  NS_IMETHOD GetState(uint32_t *aState) { return _to GetState(aState); } \
  NS_IMETHOD GetIsExtraState(bool *aIsExtraState) { return _to GetIsExtraState(aIsExtraState); } \
  NS_IMETHOD GetIsEnabled(bool *aIsEnabled) { return _to GetIsEnabled(aIsEnabled); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLESTATECHANGEEVENT(_to) \
  NS_IMETHOD GetState(uint32_t *aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_IMETHOD GetIsExtraState(bool *aIsExtraState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsExtraState(aIsExtraState); } \
  NS_IMETHOD GetIsEnabled(bool *aIsEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsEnabled(aIsEnabled); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleStateChangeEvent : public nsIAccessibleStateChangeEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLESTATECHANGEEVENT

  nsAccessibleStateChangeEvent();

private:
  ~nsAccessibleStateChangeEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleStateChangeEvent, nsIAccessibleStateChangeEvent)

nsAccessibleStateChangeEvent::nsAccessibleStateChangeEvent()
{
  /* member initializers and constructor code */
}

nsAccessibleStateChangeEvent::~nsAccessibleStateChangeEvent()
{
  /* destructor code */
}

/* readonly attribute unsigned long state; */
NS_IMETHODIMP nsAccessibleStateChangeEvent::GetState(uint32_t *aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isExtraState; */
NS_IMETHODIMP nsAccessibleStateChangeEvent::GetIsExtraState(bool *aIsExtraState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isEnabled; */
NS_IMETHODIMP nsAccessibleStateChangeEvent::GetIsEnabled(bool *aIsEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleStateChangeEvent_h__ */

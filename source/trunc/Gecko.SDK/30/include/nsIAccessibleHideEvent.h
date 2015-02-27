/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAccessibleHideEvent.idl
 */

#ifndef __gen_nsIAccessibleHideEvent_h__
#define __gen_nsIAccessibleHideEvent_h__


#ifndef __gen_nsIAccessibleEvent_h__
#include "nsIAccessibleEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAccessibleHideEvent */
#define NS_IACCESSIBLEHIDEEVENT_IID_STR "a2bd2eca-3afa-489b-afb2-f93ef32ad99c"

#define NS_IACCESSIBLEHIDEEVENT_IID \
  {0xa2bd2eca, 0x3afa, 0x489b, \
    { 0xaf, 0xb2, 0xf9, 0x3e, 0xf3, 0x2a, 0xd9, 0x9c }}

class NS_NO_VTABLE nsIAccessibleHideEvent : public nsIAccessibleEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEHIDEEVENT_IID)

  /* readonly attribute nsIAccessible targetParent; */
  NS_IMETHOD GetTargetParent(nsIAccessible * *aTargetParent) = 0;

  /* readonly attribute nsIAccessible targetNextSibling; */
  NS_IMETHOD GetTargetNextSibling(nsIAccessible * *aTargetNextSibling) = 0;

  /* readonly attribute nsIAccessible targetPrevSibling; */
  NS_IMETHOD GetTargetPrevSibling(nsIAccessible * *aTargetPrevSibling) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleHideEvent, NS_IACCESSIBLEHIDEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEHIDEEVENT \
  NS_IMETHOD GetTargetParent(nsIAccessible * *aTargetParent); \
  NS_IMETHOD GetTargetNextSibling(nsIAccessible * *aTargetNextSibling); \
  NS_IMETHOD GetTargetPrevSibling(nsIAccessible * *aTargetPrevSibling); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEHIDEEVENT(_to) \
  NS_IMETHOD GetTargetParent(nsIAccessible * *aTargetParent) { return _to GetTargetParent(aTargetParent); } \
  NS_IMETHOD GetTargetNextSibling(nsIAccessible * *aTargetNextSibling) { return _to GetTargetNextSibling(aTargetNextSibling); } \
  NS_IMETHOD GetTargetPrevSibling(nsIAccessible * *aTargetPrevSibling) { return _to GetTargetPrevSibling(aTargetPrevSibling); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEHIDEEVENT(_to) \
  NS_IMETHOD GetTargetParent(nsIAccessible * *aTargetParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetParent(aTargetParent); } \
  NS_IMETHOD GetTargetNextSibling(nsIAccessible * *aTargetNextSibling) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetNextSibling(aTargetNextSibling); } \
  NS_IMETHOD GetTargetPrevSibling(nsIAccessible * *aTargetPrevSibling) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetPrevSibling(aTargetPrevSibling); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleHideEvent : public nsIAccessibleHideEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEHIDEEVENT

  nsAccessibleHideEvent();

private:
  ~nsAccessibleHideEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleHideEvent, nsIAccessibleHideEvent)

nsAccessibleHideEvent::nsAccessibleHideEvent()
{
  /* member initializers and constructor code */
}

nsAccessibleHideEvent::~nsAccessibleHideEvent()
{
  /* destructor code */
}

/* readonly attribute nsIAccessible targetParent; */
NS_IMETHODIMP nsAccessibleHideEvent::GetTargetParent(nsIAccessible * *aTargetParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessible targetNextSibling; */
NS_IMETHODIMP nsAccessibleHideEvent::GetTargetNextSibling(nsIAccessible * *aTargetNextSibling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessible targetPrevSibling; */
NS_IMETHODIMP nsAccessibleHideEvent::GetTargetPrevSibling(nsIAccessible * *aTargetPrevSibling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleHideEvent_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIEventTarget.idl
 */

#ifndef __gen_nsIEventTarget_h__
#define __gen_nsIEventTarget_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIRunnable; /* forward declaration */


/* starting interface:    nsIEventTarget */
#define NS_IEVENTTARGET_IID_STR "4e8febe4-6631-49dc-8ac9-308c1cb9b09c"

#define NS_IEVENTTARGET_IID \
  {0x4e8febe4, 0x6631, 0x49dc, \
    { 0x8a, 0xc9, 0x30, 0x8c, 0x1c, 0xb9, 0xb0, 0x9c }}

class NS_NO_VTABLE nsIEventTarget : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEVENTTARGET_IID)

  /* void dispatch (in nsIRunnable event, in unsigned long flags); */
  NS_IMETHOD Dispatch(nsIRunnable *event, uint32_t flags) = 0;

  enum {
    DISPATCH_NORMAL = 0U,
    DISPATCH_SYNC = 1U
  };

  /* boolean isOnCurrentThread (); */
  NS_IMETHOD IsOnCurrentThread(bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEventTarget, NS_IEVENTTARGET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEVENTTARGET \
  NS_IMETHOD Dispatch(nsIRunnable *event, uint32_t flags); \
  NS_IMETHOD IsOnCurrentThread(bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEVENTTARGET(_to) \
  NS_IMETHOD Dispatch(nsIRunnable *event, uint32_t flags) { return _to Dispatch(event, flags); } \
  NS_IMETHOD IsOnCurrentThread(bool *_retval) { return _to IsOnCurrentThread(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEVENTTARGET(_to) \
  NS_IMETHOD Dispatch(nsIRunnable *event, uint32_t flags) { return !_to ? NS_ERROR_NULL_POINTER : _to->Dispatch(event, flags); } \
  NS_IMETHOD IsOnCurrentThread(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsOnCurrentThread(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEventTarget : public nsIEventTarget
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEVENTTARGET

  nsEventTarget();

private:
  ~nsEventTarget();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEventTarget, nsIEventTarget)

nsEventTarget::nsEventTarget()
{
  /* member initializers and constructor code */
}

nsEventTarget::~nsEventTarget()
{
  /* destructor code */
}

/* void dispatch (in nsIRunnable event, in unsigned long flags); */
NS_IMETHODIMP nsEventTarget::Dispatch(nsIRunnable *event, uint32_t flags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isOnCurrentThread (); */
NS_IMETHODIMP nsEventTarget::IsOnCurrentThread(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// convenient aliases:
#define NS_DISPATCH_NORMAL nsIEventTarget::DISPATCH_NORMAL
#define NS_DISPATCH_SYNC   nsIEventTarget::DISPATCH_SYNC

#endif /* __gen_nsIEventTarget_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICancelableRunnable.idl
 */

#ifndef __gen_nsICancelableRunnable_h__
#define __gen_nsICancelableRunnable_h__


#ifndef __gen_nsIRunnable_h__
#include "nsIRunnable.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsICancelableRunnable */
#define NS_ICANCELABLERUNNABLE_IID_STR "de93dc4c-5eea-4eb7-b6d1-dbf1e0cef65c"

#define NS_ICANCELABLERUNNABLE_IID \
  {0xde93dc4c, 0x5eea, 0x4eb7, \
    { 0xb6, 0xd1, 0xdb, 0xf1, 0xe0, 0xce, 0xf6, 0x5c }}

class NS_NO_VTABLE nsICancelableRunnable : public nsIRunnable {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICANCELABLERUNNABLE_IID)

  /* void cancel (); */
  NS_IMETHOD Cancel(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICancelableRunnable, NS_ICANCELABLERUNNABLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICANCELABLERUNNABLE \
  NS_IMETHOD Cancel(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICANCELABLERUNNABLE(_to) \
  NS_IMETHOD Cancel(void) { return _to Cancel(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICANCELABLERUNNABLE(_to) \
  NS_IMETHOD Cancel(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Cancel(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCancelableRunnable : public nsICancelableRunnable
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICANCELABLERUNNABLE

  nsCancelableRunnable();

private:
  ~nsCancelableRunnable();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCancelableRunnable, nsICancelableRunnable)

nsCancelableRunnable::nsCancelableRunnable()
{
  /* member initializers and constructor code */
}

nsCancelableRunnable::~nsCancelableRunnable()
{
  /* destructor code */
}

/* void cancel (); */
NS_IMETHODIMP nsCancelableRunnable::Cancel()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICancelableRunnable_h__ */

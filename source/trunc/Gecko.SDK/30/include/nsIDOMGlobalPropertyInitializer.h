/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMGlobalPropertyInitializer.idl
 */

#ifndef __gen_nsIDOMGlobalPropertyInitializer_h__
#define __gen_nsIDOMGlobalPropertyInitializer_h__


#ifndef __gen_nsIDOMWindow_h__
#include "nsIDOMWindow.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMGlobalPropertyInitializer */
#define NS_IDOMGLOBALPROPERTYINITIALIZER_IID_STR "6368a821-d3e2-4cbd-9699-5a8ba569e2f3"

#define NS_IDOMGLOBALPROPERTYINITIALIZER_IID \
  {0x6368a821, 0xd3e2, 0x4cbd, \
    { 0x96, 0x99, 0x5a, 0x8b, 0xa5, 0x69, 0xe2, 0xf3 }}

class NS_NO_VTABLE nsIDOMGlobalPropertyInitializer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGLOBALPROPERTYINITIALIZER_IID)

  /* jsval init (in nsIDOMWindow window); */
  NS_IMETHOD Init(nsIDOMWindow *window, JS::MutableHandleValue _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGlobalPropertyInitializer, NS_IDOMGLOBALPROPERTYINITIALIZER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGLOBALPROPERTYINITIALIZER \
  NS_IMETHOD Init(nsIDOMWindow *window, JS::MutableHandleValue _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGLOBALPROPERTYINITIALIZER(_to) \
  NS_IMETHOD Init(nsIDOMWindow *window, JS::MutableHandleValue _retval) { return _to Init(window, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGLOBALPROPERTYINITIALIZER(_to) \
  NS_IMETHOD Init(nsIDOMWindow *window, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(window, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGlobalPropertyInitializer : public nsIDOMGlobalPropertyInitializer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGLOBALPROPERTYINITIALIZER

  nsDOMGlobalPropertyInitializer();

private:
  ~nsDOMGlobalPropertyInitializer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMGlobalPropertyInitializer, nsIDOMGlobalPropertyInitializer)

nsDOMGlobalPropertyInitializer::nsDOMGlobalPropertyInitializer()
{
  /* member initializers and constructor code */
}

nsDOMGlobalPropertyInitializer::~nsDOMGlobalPropertyInitializer()
{
  /* destructor code */
}

/* jsval init (in nsIDOMWindow window); */
NS_IMETHODIMP nsDOMGlobalPropertyInitializer::Init(nsIDOMWindow *window, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMGlobalPropertyInitializer_h__ */

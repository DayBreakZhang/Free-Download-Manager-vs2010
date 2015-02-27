/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\mozIStorageCompletionCallback.idl
 */

#ifndef __gen_mozIStorageCompletionCallback_h__
#define __gen_mozIStorageCompletionCallback_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    mozIStorageCompletionCallback */
#define MOZISTORAGECOMPLETIONCALLBACK_IID_STR "8cbf2dc2-91e0-44bc-984f-553638412071"

#define MOZISTORAGECOMPLETIONCALLBACK_IID \
  {0x8cbf2dc2, 0x91e0, 0x44bc, \
    { 0x98, 0x4f, 0x55, 0x36, 0x38, 0x41, 0x20, 0x71 }}

class NS_NO_VTABLE mozIStorageCompletionCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGECOMPLETIONCALLBACK_IID)

  /* void complete (in nsresult status, [optional] in nsISupports value); */
  NS_IMETHOD Complete(nsresult status, nsISupports *value) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageCompletionCallback, MOZISTORAGECOMPLETIONCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGECOMPLETIONCALLBACK \
  NS_IMETHOD Complete(nsresult status, nsISupports *value); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGECOMPLETIONCALLBACK(_to) \
  NS_IMETHOD Complete(nsresult status, nsISupports *value) { return _to Complete(status, value); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGECOMPLETIONCALLBACK(_to) \
  NS_IMETHOD Complete(nsresult status, nsISupports *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->Complete(status, value); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageCompletionCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGECOMPLETIONCALLBACK

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageCompletionCallback)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void complete (in nsresult status, [optional] in nsISupports value); */
NS_IMETHODIMP _MYCLASS_::Complete(nsresult status, nsISupports *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageCompletionCallback_h__ */

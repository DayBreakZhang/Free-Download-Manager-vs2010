/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/storage/public/mozIStorageCompletionCallback.idl
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
#define MOZISTORAGECOMPLETIONCALLBACK_IID_STR "0bfee0c4-2c24-400e-b18e-b5bb41a032c8"

#define MOZISTORAGECOMPLETIONCALLBACK_IID \
  {0x0bfee0c4, 0x2c24, 0x400e, \
    { 0xb1, 0x8e, 0xb5, 0xbb, 0x41, 0xa0, 0x32, 0xc8 }}

class NS_NO_VTABLE mozIStorageCompletionCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGECOMPLETIONCALLBACK_IID)

  /* void complete (); */
  NS_IMETHOD Complete(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageCompletionCallback, MOZISTORAGECOMPLETIONCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGECOMPLETIONCALLBACK \
  NS_IMETHOD Complete(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGECOMPLETIONCALLBACK(_to) \
  NS_IMETHOD Complete(void) { return _to Complete(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGECOMPLETIONCALLBACK(_to) \
  NS_IMETHOD Complete(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Complete(); } 

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

/* void complete (); */
NS_IMETHODIMP _MYCLASS_::Complete()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageCompletionCallback_h__ */

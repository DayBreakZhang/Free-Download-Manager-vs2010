/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/storage/public/mozIStorageBindingParamsArray.idl
 */

#ifndef __gen_mozIStorageBindingParamsArray_h__
#define __gen_mozIStorageBindingParamsArray_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class mozIStorageBindingParams; /* forward declaration */


/* starting interface:    mozIStorageBindingParamsArray */
#define MOZISTORAGEBINDINGPARAMSARRAY_IID_STR "67eea5c3-4881-41ff-b0fe-09f2356aeadb"

#define MOZISTORAGEBINDINGPARAMSARRAY_IID \
  {0x67eea5c3, 0x4881, 0x41ff, \
    { 0xb0, 0xfe, 0x09, 0xf2, 0x35, 0x6a, 0xea, 0xdb }}

class NS_NO_VTABLE mozIStorageBindingParamsArray : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGEBINDINGPARAMSARRAY_IID)

  /* mozIStorageBindingParams newBindingParams (); */
  NS_IMETHOD NewBindingParams(mozIStorageBindingParams * *_retval) = 0;

  /* void addParams (in mozIStorageBindingParams aParameters); */
  NS_IMETHOD AddParams(mozIStorageBindingParams *aParameters) = 0;

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageBindingParamsArray, MOZISTORAGEBINDINGPARAMSARRAY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGEBINDINGPARAMSARRAY \
  NS_IMETHOD NewBindingParams(mozIStorageBindingParams * *_retval); \
  NS_IMETHOD AddParams(mozIStorageBindingParams *aParameters); \
  NS_IMETHOD GetLength(uint32_t *aLength); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGEBINDINGPARAMSARRAY(_to) \
  NS_IMETHOD NewBindingParams(mozIStorageBindingParams * *_retval) { return _to NewBindingParams(_retval); } \
  NS_IMETHOD AddParams(mozIStorageBindingParams *aParameters) { return _to AddParams(aParameters); } \
  NS_IMETHOD GetLength(uint32_t *aLength) { return _to GetLength(aLength); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGEBINDINGPARAMSARRAY(_to) \
  NS_IMETHOD NewBindingParams(mozIStorageBindingParams * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewBindingParams(_retval); } \
  NS_IMETHOD AddParams(mozIStorageBindingParams *aParameters) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddParams(aParameters); } \
  NS_IMETHOD GetLength(uint32_t *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageBindingParamsArray
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGEBINDINGPARAMSARRAY

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageBindingParamsArray)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* mozIStorageBindingParams newBindingParams (); */
NS_IMETHODIMP _MYCLASS_::NewBindingParams(mozIStorageBindingParams * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addParams (in mozIStorageBindingParams aParameters); */
NS_IMETHODIMP _MYCLASS_::AddParams(mozIStorageBindingParams *aParameters)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP _MYCLASS_::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageBindingParamsArray_h__ */

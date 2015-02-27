/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/storage/public/mozIStorageFunction.idl
 */

#ifndef __gen_mozIStorageFunction_h__
#define __gen_mozIStorageFunction_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_mozIStorageValueArray_h__
#include "mozIStorageValueArray.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class mozIStorageConnection; /* forward declaration */

class nsIArray; /* forward declaration */

class nsIVariant; /* forward declaration */


/* starting interface:    mozIStorageFunction */
#define MOZISTORAGEFUNCTION_IID_STR "9ff02465-21cb-49f3-b975-7d5b38ceec73"

#define MOZISTORAGEFUNCTION_IID \
  {0x9ff02465, 0x21cb, 0x49f3, \
    { 0xb9, 0x75, 0x7d, 0x5b, 0x38, 0xce, 0xec, 0x73 }}

class NS_NO_VTABLE mozIStorageFunction : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGEFUNCTION_IID)

  /* nsIVariant onFunctionCall (in mozIStorageValueArray aFunctionArguments); */
  NS_IMETHOD OnFunctionCall(mozIStorageValueArray *aFunctionArguments, nsIVariant * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageFunction, MOZISTORAGEFUNCTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGEFUNCTION \
  NS_IMETHOD OnFunctionCall(mozIStorageValueArray *aFunctionArguments, nsIVariant * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGEFUNCTION(_to) \
  NS_IMETHOD OnFunctionCall(mozIStorageValueArray *aFunctionArguments, nsIVariant * *_retval) { return _to OnFunctionCall(aFunctionArguments, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGEFUNCTION(_to) \
  NS_IMETHOD OnFunctionCall(mozIStorageValueArray *aFunctionArguments, nsIVariant * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnFunctionCall(aFunctionArguments, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageFunction
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGEFUNCTION

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageFunction)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* nsIVariant onFunctionCall (in mozIStorageValueArray aFunctionArguments); */
NS_IMETHODIMP _MYCLASS_::OnFunctionCall(mozIStorageValueArray *aFunctionArguments, nsIVariant * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageFunction_h__ */

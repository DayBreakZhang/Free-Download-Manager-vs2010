/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/storage/public/mozIStorageError.idl
 */

#ifndef __gen_mozIStorageError_h__
#define __gen_mozIStorageError_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#ifdef ERROR
#undef ERROR
#endif

/* starting interface:    mozIStorageError */
#define MOZISTORAGEERROR_IID_STR "1f350f96-7023-434a-8864-40a1c493aac1"

#define MOZISTORAGEERROR_IID \
  {0x1f350f96, 0x7023, 0x434a, \
    { 0x88, 0x64, 0x40, 0xa1, 0xc4, 0x93, 0xaa, 0xc1 }}

class NS_NO_VTABLE mozIStorageError : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGEERROR_IID)

  enum {
    ERROR = 1,
    INTERNAL = 2,
    PERM = 3,
    ABORT = 4,
    BUSY = 5,
    LOCKED = 6,
    NOMEM = 7,
    READONLY = 8,
    INTERRUPT = 9,
    IOERR = 10,
    CORRUPT = 11,
    FULL = 13,
    CANTOPEN = 14,
    EMPTY = 16,
    SCHEMA = 17,
    TOOBIG = 18,
    CONSTRAINT = 19,
    MISMATCH = 20,
    MISUSE = 21,
    NOLFS = 22,
    AUTH = 23,
    FORMAT = 24,
    RANGE = 25,
    NOTADB = 26
  };

  /* readonly attribute long result; */
  NS_IMETHOD GetResult(int32_t *aResult) = 0;

  /* readonly attribute AUTF8String message; */
  NS_IMETHOD GetMessage(nsACString & aMessage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageError, MOZISTORAGEERROR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGEERROR \
  NS_IMETHOD GetResult(int32_t *aResult); \
  NS_IMETHOD GetMessage(nsACString & aMessage); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGEERROR(_to) \
  NS_IMETHOD GetResult(int32_t *aResult) { return _to GetResult(aResult); } \
  NS_IMETHOD GetMessage(nsACString & aMessage) { return _to GetMessage(aMessage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGEERROR(_to) \
  NS_IMETHOD GetResult(int32_t *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResult(aResult); } \
  NS_IMETHOD GetMessage(nsACString & aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessage(aMessage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageError
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGEERROR

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageError)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute long result; */
NS_IMETHODIMP _MYCLASS_::GetResult(int32_t *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String message; */
NS_IMETHODIMP _MYCLASS_::GetMessage(nsACString & aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageError_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\mozIStorageStatementParams.idl
 */

#ifndef __gen_mozIStorageStatementParams_h__
#define __gen_mozIStorageStatementParams_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    mozIStorageStatementParams */
#define MOZISTORAGESTATEMENTPARAMS_IID_STR "e65fe6e2-2643-463c-97e2-27665efe2386"

#define MOZISTORAGESTATEMENTPARAMS_IID \
  {0xe65fe6e2, 0x2643, 0x463c, \
    { 0x97, 0xe2, 0x27, 0x66, 0x5e, 0xfe, 0x23, 0x86 }}

class NS_NO_VTABLE mozIStorageStatementParams : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGESTATEMENTPARAMS_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageStatementParams, MOZISTORAGESTATEMENTPARAMS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGESTATEMENTPARAMS \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGESTATEMENTPARAMS(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGESTATEMENTPARAMS(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageStatementParams
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGESTATEMENTPARAMS

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageStatementParams)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageStatementParams_h__ */

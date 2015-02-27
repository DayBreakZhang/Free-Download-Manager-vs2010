/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\mozIStorageAsyncStatement.idl
 */

#ifndef __gen_mozIStorageAsyncStatement_h__
#define __gen_mozIStorageAsyncStatement_h__


#ifndef __gen_mozIStorageBaseStatement_h__
#include "mozIStorageBaseStatement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    mozIStorageAsyncStatement */
#define MOZISTORAGEASYNCSTATEMENT_IID_STR "52e49370-3b2e-4a27-a3fc-79e20ad4056b"

#define MOZISTORAGEASYNCSTATEMENT_IID \
  {0x52e49370, 0x3b2e, 0x4a27, \
    { 0xa3, 0xfc, 0x79, 0xe2, 0x0a, 0xd4, 0x05, 0x6b }}

class NS_NO_VTABLE mozIStorageAsyncStatement : public mozIStorageBaseStatement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGEASYNCSTATEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageAsyncStatement, MOZISTORAGEASYNCSTATEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGEASYNCSTATEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGEASYNCSTATEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGEASYNCSTATEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageAsyncStatement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGEASYNCSTATEMENT

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageAsyncStatement)

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


#endif /* __gen_mozIStorageAsyncStatement_h__ */

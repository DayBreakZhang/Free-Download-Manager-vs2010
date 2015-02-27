/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/storage/public/mozIStorageAsyncStatement.idl
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
#define MOZISTORAGEASYNCSTATEMENT_IID_STR "2400f64d-2cb3-49a9-b01e-f03cacb8aa6e"

#define MOZISTORAGEASYNCSTATEMENT_IID \
  {0x2400f64d, 0x2cb3, 0x49a9, \
    { 0xb0, 0x1e, 0xf0, 0x3c, 0xac, 0xb8, 0xaa, 0x6e }}

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

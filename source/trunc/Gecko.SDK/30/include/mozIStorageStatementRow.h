/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\mozIStorageStatementRow.idl
 */

#ifndef __gen_mozIStorageStatementRow_h__
#define __gen_mozIStorageStatementRow_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    mozIStorageStatementRow */
#define MOZISTORAGESTATEMENTROW_IID_STR "02eeaf95-c3db-4182-9340-222c29f68f02"

#define MOZISTORAGESTATEMENTROW_IID \
  {0x02eeaf95, 0xc3db, 0x4182, \
    { 0x93, 0x40, 0x22, 0x2c, 0x29, 0xf6, 0x8f, 0x02 }}

class NS_NO_VTABLE mozIStorageStatementRow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGESTATEMENTROW_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageStatementRow, MOZISTORAGESTATEMENTROW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGESTATEMENTROW \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGESTATEMENTROW(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGESTATEMENTROW(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageStatementRow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGESTATEMENTROW

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageStatementRow)

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


#endif /* __gen_mozIStorageStatementRow_h__ */

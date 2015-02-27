/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/storage/public/mozIStoragePendingStatement.idl
 */

#ifndef __gen_mozIStoragePendingStatement_h__
#define __gen_mozIStoragePendingStatement_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    mozIStoragePendingStatement */
#define MOZISTORAGEPENDINGSTATEMENT_IID_STR "00da7d20-3768-4398-bedc-e310c324b3f0"

#define MOZISTORAGEPENDINGSTATEMENT_IID \
  {0x00da7d20, 0x3768, 0x4398, \
    { 0xbe, 0xdc, 0xe3, 0x10, 0xc3, 0x24, 0xb3, 0xf0 }}

class NS_NO_VTABLE mozIStoragePendingStatement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGEPENDINGSTATEMENT_IID)

  /* void cancel (); */
  NS_IMETHOD Cancel(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStoragePendingStatement, MOZISTORAGEPENDINGSTATEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGEPENDINGSTATEMENT \
  NS_IMETHOD Cancel(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGEPENDINGSTATEMENT(_to) \
  NS_IMETHOD Cancel(void) { return _to Cancel(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGEPENDINGSTATEMENT(_to) \
  NS_IMETHOD Cancel(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Cancel(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStoragePendingStatement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGEPENDINGSTATEMENT

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStoragePendingStatement)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void cancel (); */
NS_IMETHODIMP _MYCLASS_::Cancel()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStoragePendingStatement_h__ */

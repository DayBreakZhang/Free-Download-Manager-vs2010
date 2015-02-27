/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/storage/public/mozIStorageRow.idl
 */

#ifndef __gen_mozIStorageRow_h__
#define __gen_mozIStorageRow_h__


#ifndef __gen_mozIStorageValueArray_h__
#include "mozIStorageValueArray.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */


/* starting interface:    mozIStorageRow */
#define MOZISTORAGEROW_IID_STR "62d1b6bd-cbfe-4f9b-aee1-0ead4af4e6dc"

#define MOZISTORAGEROW_IID \
  {0x62d1b6bd, 0xcbfe, 0x4f9b, \
    { 0xae, 0xe1, 0x0e, 0xad, 0x4a, 0xf4, 0xe6, 0xdc }}

class NS_NO_VTABLE mozIStorageRow : public mozIStorageValueArray {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGEROW_IID)

  /* nsIVariant getResultByIndex (in unsigned long aIndex); */
  NS_IMETHOD GetResultByIndex(uint32_t aIndex, nsIVariant * *_retval) = 0;

  /* nsIVariant getResultByName (in AUTF8String aName); */
  NS_IMETHOD GetResultByName(const nsACString & aName, nsIVariant * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageRow, MOZISTORAGEROW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGEROW \
  NS_IMETHOD GetResultByIndex(uint32_t aIndex, nsIVariant * *_retval); \
  NS_IMETHOD GetResultByName(const nsACString & aName, nsIVariant * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGEROW(_to) \
  NS_IMETHOD GetResultByIndex(uint32_t aIndex, nsIVariant * *_retval) { return _to GetResultByIndex(aIndex, _retval); } \
  NS_IMETHOD GetResultByName(const nsACString & aName, nsIVariant * *_retval) { return _to GetResultByName(aName, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGEROW(_to) \
  NS_IMETHOD GetResultByIndex(uint32_t aIndex, nsIVariant * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResultByIndex(aIndex, _retval); } \
  NS_IMETHOD GetResultByName(const nsACString & aName, nsIVariant * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResultByName(aName, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageRow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGEROW

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageRow)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* nsIVariant getResultByIndex (in unsigned long aIndex); */
NS_IMETHODIMP _MYCLASS_::GetResultByIndex(uint32_t aIndex, nsIVariant * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getResultByName (in AUTF8String aName); */
NS_IMETHODIMP _MYCLASS_::GetResultByName(const nsACString & aName, nsIVariant * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageRow_h__ */

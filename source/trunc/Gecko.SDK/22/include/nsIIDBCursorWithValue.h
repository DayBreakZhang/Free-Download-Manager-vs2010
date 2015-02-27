/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/indexedDB/nsIIDBCursorWithValue.idl
 */

#ifndef __gen_nsIIDBCursorWithValue_h__
#define __gen_nsIIDBCursorWithValue_h__


#ifndef __gen_nsIIDBCursor_h__
#include "nsIIDBCursor.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIIDBCursorWithValue */
#define NS_IIDBCURSORWITHVALUE_IID_STR "b6b7e08a-4379-4441-a176-447c5c96df69"

#define NS_IIDBCURSORWITHVALUE_IID \
  {0xb6b7e08a, 0x4379, 0x4441, \
    { 0xa1, 0x76, 0x44, 0x7c, 0x5c, 0x96, 0xdf, 0x69 }}

class NS_NO_VTABLE nsIIDBCursorWithValue : public nsIIDBCursor {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBCURSORWITHVALUE_IID)

  /* [implicit_jscontext] readonly attribute jsval value; */
  NS_IMETHOD GetValue(JSContext* cx, JS::Value *aValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBCursorWithValue, NS_IIDBCURSORWITHVALUE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBCURSORWITHVALUE \
  NS_IMETHOD GetValue(JSContext* cx, JS::Value *aValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBCURSORWITHVALUE(_to) \
  NS_IMETHOD GetValue(JSContext* cx, JS::Value *aValue) { return _to GetValue(cx, aValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBCURSORWITHVALUE(_to) \
  NS_IMETHOD GetValue(JSContext* cx, JS::Value *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(cx, aValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIDBCursorWithValue : public nsIIDBCursorWithValue
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDBCURSORWITHVALUE

  nsIDBCursorWithValue();

private:
  ~nsIDBCursorWithValue();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIDBCursorWithValue, nsIIDBCursorWithValue)

nsIDBCursorWithValue::nsIDBCursorWithValue()
{
  /* member initializers and constructor code */
}

nsIDBCursorWithValue::~nsIDBCursorWithValue()
{
  /* destructor code */
}

/* [implicit_jscontext] readonly attribute jsval value; */
NS_IMETHODIMP nsIDBCursorWithValue::GetValue(JSContext* cx, JS::Value *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBCursorWithValue_h__ */

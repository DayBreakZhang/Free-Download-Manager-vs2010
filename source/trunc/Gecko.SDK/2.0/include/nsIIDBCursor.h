/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/indexedDB/nsIIDBCursor.idl
 */

#ifndef __gen_nsIIDBCursor_h__
#define __gen_nsIIDBCursor_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIIDBRequest; /* forward declaration */

class nsIVariant; /* forward declaration */

#include "jsapi.h"

/* starting interface:    nsIIDBCursor */
#define NS_IIDBCURSOR_IID_STR "adee4085-68cd-4568-9d74-e3d32b6dc5c5"

#define NS_IIDBCURSOR_IID \
  {0xadee4085, 0x68cd, 0x4568, \
    { 0x9d, 0x74, 0xe3, 0xd3, 0x2b, 0x6d, 0xc5, 0xc5 }}

/**
 * IDBCursor interface.  See
 * http://dev.w3.org/2006/webapi/WebSimpleDB/#idl-def-IDBCursor for more
 * information.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIIDBCursor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBCURSOR_IID)

  enum { NEXT = 0U };

  enum { NEXT_NO_DUPLICATE = 1U };

  enum { PREV = 2U };

  enum { PREV_NO_DUPLICATE = 3U };

  /* readonly attribute unsigned short direction; */
  NS_SCRIPTABLE NS_IMETHOD GetDirection(PRUint16 *aDirection) = 0;

  /* readonly attribute nsISupports source; */
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsISupports **aSource) = 0;

  /* readonly attribute nsIVariant key; */
  NS_SCRIPTABLE NS_IMETHOD GetKey(nsIVariant **aKey) = 0;

  /* [implicit_jscontext] readonly attribute jsval primaryKey; */
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryKey(JSContext *cx, jsval *aPrimaryKey) = 0;

  /* [implicit_jscontext] void continue ([optional] in jsval key); */
  NS_SCRIPTABLE NS_IMETHOD Continue(const jsval & key, JSContext *cx) = 0;

  /* [implicit_jscontext] nsIIDBRequest update (in jsval value); */
  NS_SCRIPTABLE NS_IMETHOD Update(const jsval & value, JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM) = 0;

  /* [implicit_jscontext] nsIIDBRequest delete (); */
  NS_SCRIPTABLE NS_IMETHOD Delete(JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBCursor, NS_IIDBCURSOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBCURSOR \
  NS_SCRIPTABLE NS_IMETHOD GetDirection(PRUint16 *aDirection); \
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsISupports **aSource); \
  NS_SCRIPTABLE NS_IMETHOD GetKey(nsIVariant **aKey); \
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryKey(JSContext *cx, jsval *aPrimaryKey); \
  NS_SCRIPTABLE NS_IMETHOD Continue(const jsval & key, JSContext *cx); \
  NS_SCRIPTABLE NS_IMETHOD Update(const jsval & value, JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Delete(JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBCURSOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDirection(PRUint16 *aDirection) { return _to GetDirection(aDirection); } \
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsISupports **aSource) { return _to GetSource(aSource); } \
  NS_SCRIPTABLE NS_IMETHOD GetKey(nsIVariant **aKey) { return _to GetKey(aKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryKey(JSContext *cx, jsval *aPrimaryKey) { return _to GetPrimaryKey(cx, aPrimaryKey); } \
  NS_SCRIPTABLE NS_IMETHOD Continue(const jsval & key, JSContext *cx) { return _to Continue(key, cx); } \
  NS_SCRIPTABLE NS_IMETHOD Update(const jsval & value, JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM) { return _to Update(value, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Delete(JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM) { return _to Delete(cx, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBCURSOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDirection(PRUint16 *aDirection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDirection(aDirection); } \
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsISupports **aSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSource(aSource); } \
  NS_SCRIPTABLE NS_IMETHOD GetKey(nsIVariant **aKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKey(aKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryKey(JSContext *cx, jsval *aPrimaryKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrimaryKey(cx, aPrimaryKey); } \
  NS_SCRIPTABLE NS_IMETHOD Continue(const jsval & key, JSContext *cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->Continue(key, cx); } \
  NS_SCRIPTABLE NS_IMETHOD Update(const jsval & value, JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Update(value, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Delete(JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Delete(cx, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIDBCursor : public nsIIDBCursor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDBCURSOR

  nsIDBCursor();

private:
  ~nsIDBCursor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIDBCursor, nsIIDBCursor)

nsIDBCursor::nsIDBCursor()
{
  /* member initializers and constructor code */
}

nsIDBCursor::~nsIDBCursor()
{
  /* destructor code */
}

/* readonly attribute unsigned short direction; */
NS_IMETHODIMP nsIDBCursor::GetDirection(PRUint16 *aDirection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports source; */
NS_IMETHODIMP nsIDBCursor::GetSource(nsISupports **aSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIVariant key; */
NS_IMETHODIMP nsIDBCursor::GetKey(nsIVariant **aKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval primaryKey; */
NS_IMETHODIMP nsIDBCursor::GetPrimaryKey(JSContext *cx, jsval *aPrimaryKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void continue ([optional] in jsval key); */
NS_IMETHODIMP nsIDBCursor::Continue(const jsval & key, JSContext *cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIIDBRequest update (in jsval value); */
NS_IMETHODIMP nsIDBCursor::Update(const jsval & value, JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIIDBRequest delete (); */
NS_IMETHODIMP nsIDBCursor::Delete(JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBCursor_h__ */

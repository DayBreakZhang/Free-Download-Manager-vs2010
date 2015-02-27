/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/indexedDB/nsIIDBIndex.idl
 */

#ifndef __gen_nsIIDBIndex_h__
#define __gen_nsIIDBIndex_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIIDBKeyRange; /* forward declaration */

class nsIIDBObjectStore; /* forward declaration */

class nsIIDBRequest; /* forward declaration */

class nsIVariant; /* forward declaration */


/* starting interface:    nsIIDBIndex */
#define NS_IIDBINDEX_IID_STR "9df1ac24-06cf-47d1-9159-3b3d65975b80"

#define NS_IIDBINDEX_IID \
  {0x9df1ac24, 0x06cf, 0x47d1, \
    { 0x91, 0x59, 0x3b, 0x3d, 0x65, 0x97, 0x5b, 0x80 }}

/**
 * IDBIndex interface.  See
 * http://dev.w3.org/2006/webapi/WebSimpleDB/#idl-def-IDBIndex for more
 * information.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIIDBIndex : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBINDEX_IID)

  /* readonly attribute DOMString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute DOMString storeName; */
  NS_SCRIPTABLE NS_IMETHOD GetStoreName(nsAString & aStoreName) = 0;

  /* readonly attribute DOMString keyPath; */
  NS_SCRIPTABLE NS_IMETHOD GetKeyPath(nsAString & aKeyPath) = 0;

  /* readonly attribute boolean unique; */
  NS_SCRIPTABLE NS_IMETHOD GetUnique(PRBool *aUnique) = 0;

  /* readonly attribute nsIIDBObjectStore objectStore; */
  NS_SCRIPTABLE NS_IMETHOD GetObjectStore(nsIIDBObjectStore **aObjectStore) = 0;

  /* nsIIDBRequest get (in nsIVariant key); */
  NS_SCRIPTABLE NS_IMETHOD Get(nsIVariant *key, nsIIDBRequest **_retval NS_OUTPARAM) = 0;

  /* nsIIDBRequest getKey (in nsIVariant key); */
  NS_SCRIPTABLE NS_IMETHOD GetKey(nsIVariant *key, nsIIDBRequest **_retval NS_OUTPARAM) = 0;

  /* [optional_argc] nsIIDBRequest getAll ([optional] in nsIVariant key, [optional] in unsigned long limit); */
  NS_SCRIPTABLE NS_IMETHOD GetAll(nsIVariant *key, PRUint32 limit, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) = 0;

  /* [optional_argc] nsIIDBRequest getAllKeys ([optional] in nsIVariant key, [optional] in unsigned long limit); */
  NS_SCRIPTABLE NS_IMETHOD GetAllKeys(nsIVariant *key, PRUint32 limit, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) = 0;

  /* [optional_argc] nsIIDBRequest openCursor ([optional] in nsIIDBKeyRange range, [optional] in unsigned short direction); */
  NS_SCRIPTABLE NS_IMETHOD OpenCursor(nsIIDBKeyRange *range, PRUint16 direction, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) = 0;

  /* [optional_argc] nsIIDBRequest openKeyCursor ([optional] in nsIIDBKeyRange range, [optional] in unsigned short direction); */
  NS_SCRIPTABLE NS_IMETHOD OpenKeyCursor(nsIIDBKeyRange *range, PRUint16 direction, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBIndex, NS_IIDBINDEX_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBINDEX \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetStoreName(nsAString & aStoreName); \
  NS_SCRIPTABLE NS_IMETHOD GetKeyPath(nsAString & aKeyPath); \
  NS_SCRIPTABLE NS_IMETHOD GetUnique(PRBool *aUnique); \
  NS_SCRIPTABLE NS_IMETHOD GetObjectStore(nsIIDBObjectStore **aObjectStore); \
  NS_SCRIPTABLE NS_IMETHOD Get(nsIVariant *key, nsIIDBRequest **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetKey(nsIVariant *key, nsIIDBRequest **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAll(nsIVariant *key, PRUint32 limit, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAllKeys(nsIVariant *key, PRUint32 limit, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD OpenCursor(nsIIDBKeyRange *range, PRUint16 direction, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD OpenKeyCursor(nsIIDBKeyRange *range, PRUint16 direction, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBINDEX(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetStoreName(nsAString & aStoreName) { return _to GetStoreName(aStoreName); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeyPath(nsAString & aKeyPath) { return _to GetKeyPath(aKeyPath); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnique(PRBool *aUnique) { return _to GetUnique(aUnique); } \
  NS_SCRIPTABLE NS_IMETHOD GetObjectStore(nsIIDBObjectStore **aObjectStore) { return _to GetObjectStore(aObjectStore); } \
  NS_SCRIPTABLE NS_IMETHOD Get(nsIVariant *key, nsIIDBRequest **_retval NS_OUTPARAM) { return _to Get(key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetKey(nsIVariant *key, nsIIDBRequest **_retval NS_OUTPARAM) { return _to GetKey(key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAll(nsIVariant *key, PRUint32 limit, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) { return _to GetAll(key, limit, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllKeys(nsIVariant *key, PRUint32 limit, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) { return _to GetAllKeys(key, limit, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OpenCursor(nsIIDBKeyRange *range, PRUint16 direction, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) { return _to OpenCursor(range, direction, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OpenKeyCursor(nsIIDBKeyRange *range, PRUint16 direction, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) { return _to OpenKeyCursor(range, direction, _argc, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBINDEX(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetStoreName(nsAString & aStoreName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStoreName(aStoreName); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeyPath(nsAString & aKeyPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeyPath(aKeyPath); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnique(PRBool *aUnique) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnique(aUnique); } \
  NS_SCRIPTABLE NS_IMETHOD GetObjectStore(nsIIDBObjectStore **aObjectStore) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObjectStore(aObjectStore); } \
  NS_SCRIPTABLE NS_IMETHOD Get(nsIVariant *key, nsIIDBRequest **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetKey(nsIVariant *key, nsIIDBRequest **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKey(key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAll(nsIVariant *key, PRUint32 limit, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAll(key, limit, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllKeys(nsIVariant *key, PRUint32 limit, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllKeys(key, limit, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OpenCursor(nsIIDBKeyRange *range, PRUint16 direction, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenCursor(range, direction, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OpenKeyCursor(nsIIDBKeyRange *range, PRUint16 direction, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenKeyCursor(range, direction, _argc, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIDBIndex : public nsIIDBIndex
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDBINDEX

  nsIDBIndex();

private:
  ~nsIDBIndex();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIDBIndex, nsIIDBIndex)

nsIDBIndex::nsIDBIndex()
{
  /* member initializers and constructor code */
}

nsIDBIndex::~nsIDBIndex()
{
  /* destructor code */
}

/* readonly attribute DOMString name; */
NS_IMETHODIMP nsIDBIndex::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString storeName; */
NS_IMETHODIMP nsIDBIndex::GetStoreName(nsAString & aStoreName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString keyPath; */
NS_IMETHODIMP nsIDBIndex::GetKeyPath(nsAString & aKeyPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean unique; */
NS_IMETHODIMP nsIDBIndex::GetUnique(PRBool *aUnique)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIIDBObjectStore objectStore; */
NS_IMETHODIMP nsIDBIndex::GetObjectStore(nsIIDBObjectStore **aObjectStore)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIIDBRequest get (in nsIVariant key); */
NS_IMETHODIMP nsIDBIndex::Get(nsIVariant *key, nsIIDBRequest **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIIDBRequest getKey (in nsIVariant key); */
NS_IMETHODIMP nsIDBIndex::GetKey(nsIVariant *key, nsIIDBRequest **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] nsIIDBRequest getAll ([optional] in nsIVariant key, [optional] in unsigned long limit); */
NS_IMETHODIMP nsIDBIndex::GetAll(nsIVariant *key, PRUint32 limit, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] nsIIDBRequest getAllKeys ([optional] in nsIVariant key, [optional] in unsigned long limit); */
NS_IMETHODIMP nsIDBIndex::GetAllKeys(nsIVariant *key, PRUint32 limit, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] nsIIDBRequest openCursor ([optional] in nsIIDBKeyRange range, [optional] in unsigned short direction); */
NS_IMETHODIMP nsIDBIndex::OpenCursor(nsIIDBKeyRange *range, PRUint16 direction, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] nsIIDBRequest openKeyCursor ([optional] in nsIIDBKeyRange range, [optional] in unsigned short direction); */
NS_IMETHODIMP nsIDBIndex::OpenKeyCursor(nsIIDBKeyRange *range, PRUint16 direction, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBIndex_h__ */

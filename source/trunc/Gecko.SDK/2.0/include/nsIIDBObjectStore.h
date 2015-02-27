/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/indexedDB/nsIIDBObjectStore.idl
 */

#ifndef __gen_nsIIDBObjectStore_h__
#define __gen_nsIIDBObjectStore_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIIDBIndex; /* forward declaration */

class nsIIDBKeyRange; /* forward declaration */

class nsIIDBRequest; /* forward declaration */

class nsIIDBTransaction; /* forward declaration */

class nsIVariant; /* forward declaration */

class nsIDOMDOMStringList; /* forward declaration */

#include "jsapi.h"

/* starting interface:    nsIIDBObjectStore */
#define NS_IIDBOBJECTSTORE_IID_STR "6a65dc92-66e3-407a-a370-590a6c54664a"

#define NS_IIDBOBJECTSTORE_IID \
  {0x6a65dc92, 0x66e3, 0x407a, \
    { 0xa3, 0x70, 0x59, 0x0a, 0x6c, 0x54, 0x66, 0x4a }}

/**
 * nsIIDBObjectStore interface.  See
 * http://dev.w3.org/2006/webapi/WebSimpleDB/#idl-def-nsIIDBObjectStore
 * for more information.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIIDBObjectStore : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBOBJECTSTORE_IID)

  /* readonly attribute DOMString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute DOMString keyPath; */
  NS_SCRIPTABLE NS_IMETHOD GetKeyPath(nsAString & aKeyPath) = 0;

  /* readonly attribute nsIDOMDOMStringList indexNames; */
  NS_SCRIPTABLE NS_IMETHOD GetIndexNames(nsIDOMDOMStringList **aIndexNames) = 0;

  /* readonly attribute nsIIDBTransaction transaction; */
  NS_SCRIPTABLE NS_IMETHOD GetTransaction(nsIIDBTransaction **aTransaction) = 0;

  /* nsIIDBRequest get (in nsIVariant key); */
  NS_SCRIPTABLE NS_IMETHOD Get(nsIVariant *key, nsIIDBRequest **_retval NS_OUTPARAM) = 0;

  /* [optional_argc] nsIIDBRequest getAll ([optional] in nsIIDBKeyRange key, [optional] in unsigned long limit); */
  NS_SCRIPTABLE NS_IMETHOD GetAll(nsIIDBKeyRange *key, PRUint32 limit, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) = 0;

  /* [optional_argc, implicit_jscontext] nsIIDBRequest add (in jsval value, [optional] in jsval key); */
  NS_SCRIPTABLE NS_IMETHOD Add(const jsval & value, const jsval & key, JSContext *cx, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) = 0;

  /* [optional_argc, implicit_jscontext] nsIIDBRequest put (in jsval value, [optional] in jsval key); */
  NS_SCRIPTABLE NS_IMETHOD Put(const jsval & value, const jsval & key, JSContext *cx, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) = 0;

  /* [implicit_jscontext] nsIIDBRequest delete (in jsval key); */
  NS_SCRIPTABLE NS_IMETHOD Delete(const jsval & key, JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM) = 0;

  /* nsIIDBRequest clear (); */
  NS_SCRIPTABLE NS_IMETHOD Clear(nsIIDBRequest **_retval NS_OUTPARAM) = 0;

  /* [optional_argc] nsIIDBRequest openCursor ([optional] in nsIIDBKeyRange range, [optional] in unsigned short direction); */
  NS_SCRIPTABLE NS_IMETHOD OpenCursor(nsIIDBKeyRange *range, PRUint16 direction, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) = 0;

  /**
   * Optional arguments:
   *   - unique (boolean):
   *       Specifies whether values in the index must be unique. Defaults to
   *       false.
   */
  /* [implicit_jscontext] nsIIDBIndex createIndex (in AString name, in AString keyPath, [optional] in jsval options); */
  NS_SCRIPTABLE NS_IMETHOD CreateIndex(const nsAString & name, const nsAString & keyPath, const jsval & options, JSContext *cx, nsIIDBIndex **_retval NS_OUTPARAM) = 0;

  /* nsIIDBIndex index (in AString name); */
  NS_SCRIPTABLE NS_IMETHOD Index(const nsAString & name, nsIIDBIndex **_retval NS_OUTPARAM) = 0;

  /* void deleteIndex (in AString name); */
  NS_SCRIPTABLE NS_IMETHOD DeleteIndex(const nsAString & name) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBObjectStore, NS_IIDBOBJECTSTORE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBOBJECTSTORE \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetKeyPath(nsAString & aKeyPath); \
  NS_SCRIPTABLE NS_IMETHOD GetIndexNames(nsIDOMDOMStringList **aIndexNames); \
  NS_SCRIPTABLE NS_IMETHOD GetTransaction(nsIIDBTransaction **aTransaction); \
  NS_SCRIPTABLE NS_IMETHOD Get(nsIVariant *key, nsIIDBRequest **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAll(nsIIDBKeyRange *key, PRUint32 limit, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Add(const jsval & value, const jsval & key, JSContext *cx, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Put(const jsval & value, const jsval & key, JSContext *cx, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Delete(const jsval & key, JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Clear(nsIIDBRequest **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD OpenCursor(nsIIDBKeyRange *range, PRUint16 direction, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateIndex(const nsAString & name, const nsAString & keyPath, const jsval & options, JSContext *cx, nsIIDBIndex **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Index(const nsAString & name, nsIIDBIndex **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DeleteIndex(const nsAString & name); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBOBJECTSTORE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeyPath(nsAString & aKeyPath) { return _to GetKeyPath(aKeyPath); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexNames(nsIDOMDOMStringList **aIndexNames) { return _to GetIndexNames(aIndexNames); } \
  NS_SCRIPTABLE NS_IMETHOD GetTransaction(nsIIDBTransaction **aTransaction) { return _to GetTransaction(aTransaction); } \
  NS_SCRIPTABLE NS_IMETHOD Get(nsIVariant *key, nsIIDBRequest **_retval NS_OUTPARAM) { return _to Get(key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAll(nsIIDBKeyRange *key, PRUint32 limit, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) { return _to GetAll(key, limit, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Add(const jsval & value, const jsval & key, JSContext *cx, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) { return _to Add(value, key, cx, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Put(const jsval & value, const jsval & key, JSContext *cx, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) { return _to Put(value, key, cx, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Delete(const jsval & key, JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM) { return _to Delete(key, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(nsIIDBRequest **_retval NS_OUTPARAM) { return _to Clear(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD OpenCursor(nsIIDBKeyRange *range, PRUint16 direction, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) { return _to OpenCursor(range, direction, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateIndex(const nsAString & name, const nsAString & keyPath, const jsval & options, JSContext *cx, nsIIDBIndex **_retval NS_OUTPARAM) { return _to CreateIndex(name, keyPath, options, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Index(const nsAString & name, nsIIDBIndex **_retval NS_OUTPARAM) { return _to Index(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteIndex(const nsAString & name) { return _to DeleteIndex(name); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBOBJECTSTORE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeyPath(nsAString & aKeyPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeyPath(aKeyPath); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexNames(nsIDOMDOMStringList **aIndexNames) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexNames(aIndexNames); } \
  NS_SCRIPTABLE NS_IMETHOD GetTransaction(nsIIDBTransaction **aTransaction) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransaction(aTransaction); } \
  NS_SCRIPTABLE NS_IMETHOD Get(nsIVariant *key, nsIIDBRequest **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAll(nsIIDBKeyRange *key, PRUint32 limit, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAll(key, limit, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Add(const jsval & value, const jsval & key, JSContext *cx, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(value, key, cx, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Put(const jsval & value, const jsval & key, JSContext *cx, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Put(value, key, cx, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Delete(const jsval & key, JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Delete(key, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(nsIIDBRequest **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD OpenCursor(nsIIDBKeyRange *range, PRUint16 direction, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenCursor(range, direction, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateIndex(const nsAString & name, const nsAString & keyPath, const jsval & options, JSContext *cx, nsIIDBIndex **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateIndex(name, keyPath, options, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Index(const nsAString & name, nsIIDBIndex **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Index(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteIndex(const nsAString & name) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteIndex(name); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIDBObjectStore : public nsIIDBObjectStore
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDBOBJECTSTORE

  nsIDBObjectStore();

private:
  ~nsIDBObjectStore();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIDBObjectStore, nsIIDBObjectStore)

nsIDBObjectStore::nsIDBObjectStore()
{
  /* member initializers and constructor code */
}

nsIDBObjectStore::~nsIDBObjectStore()
{
  /* destructor code */
}

/* readonly attribute DOMString name; */
NS_IMETHODIMP nsIDBObjectStore::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString keyPath; */
NS_IMETHODIMP nsIDBObjectStore::GetKeyPath(nsAString & aKeyPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDOMStringList indexNames; */
NS_IMETHODIMP nsIDBObjectStore::GetIndexNames(nsIDOMDOMStringList **aIndexNames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIIDBTransaction transaction; */
NS_IMETHODIMP nsIDBObjectStore::GetTransaction(nsIIDBTransaction **aTransaction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIIDBRequest get (in nsIVariant key); */
NS_IMETHODIMP nsIDBObjectStore::Get(nsIVariant *key, nsIIDBRequest **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] nsIIDBRequest getAll ([optional] in nsIIDBKeyRange key, [optional] in unsigned long limit); */
NS_IMETHODIMP nsIDBObjectStore::GetAll(nsIIDBKeyRange *key, PRUint32 limit, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc, implicit_jscontext] nsIIDBRequest add (in jsval value, [optional] in jsval key); */
NS_IMETHODIMP nsIDBObjectStore::Add(const jsval & value, const jsval & key, JSContext *cx, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc, implicit_jscontext] nsIIDBRequest put (in jsval value, [optional] in jsval key); */
NS_IMETHODIMP nsIDBObjectStore::Put(const jsval & value, const jsval & key, JSContext *cx, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIIDBRequest delete (in jsval key); */
NS_IMETHODIMP nsIDBObjectStore::Delete(const jsval & key, JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIIDBRequest clear (); */
NS_IMETHODIMP nsIDBObjectStore::Clear(nsIIDBRequest **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] nsIIDBRequest openCursor ([optional] in nsIIDBKeyRange range, [optional] in unsigned short direction); */
NS_IMETHODIMP nsIDBObjectStore::OpenCursor(nsIIDBKeyRange *range, PRUint16 direction, PRUint8 _argc, nsIIDBRequest **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIIDBIndex createIndex (in AString name, in AString keyPath, [optional] in jsval options); */
NS_IMETHODIMP nsIDBObjectStore::CreateIndex(const nsAString & name, const nsAString & keyPath, const jsval & options, JSContext *cx, nsIIDBIndex **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIIDBIndex index (in AString name); */
NS_IMETHODIMP nsIDBObjectStore::Index(const nsAString & name, nsIIDBIndex **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteIndex (in AString name); */
NS_IMETHODIMP nsIDBObjectStore::DeleteIndex(const nsAString & name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBObjectStore_h__ */

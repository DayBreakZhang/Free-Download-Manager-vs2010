/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/indexedDB/nsIIDBObjectStore.idl
 */

#ifndef __gen_nsIIDBObjectStore_h__
#define __gen_nsIIDBObjectStore_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIIDBIndex; /* forward declaration */

class nsIIDBKeyRange; /* forward declaration */

class nsIIDBRequest; /* forward declaration */

class nsIIDBTransaction; /* forward declaration */

class nsIDOMDOMStringList; /* forward declaration */


/* starting interface:    nsIIDBObjectStore */
#define NS_IIDBOBJECTSTORE_IID_STR "dd189afd-e1b7-4496-bf8d-629c58709595"

#define NS_IIDBOBJECTSTORE_IID \
  {0xdd189afd, 0xe1b7, 0x4496, \
    { 0xbf, 0x8d, 0x62, 0x9c, 0x58, 0x70, 0x95, 0x95 }}

class NS_NO_VTABLE nsIIDBObjectStore : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBOBJECTSTORE_IID)

  /* readonly attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* [implicit_jscontext] readonly attribute jsval keyPath; */
  NS_IMETHOD GetKeyPath(JSContext* cx, JS::Value *aKeyPath) = 0;

  /* readonly attribute nsIDOMDOMStringList indexNames; */
  NS_IMETHOD GetIndexNames(nsIDOMDOMStringList * *aIndexNames) = 0;

  /* readonly attribute nsIIDBTransaction transaction; */
  NS_IMETHOD GetTransaction(nsIIDBTransaction * *aTransaction) = 0;

  /* readonly attribute boolean autoIncrement; */
  NS_IMETHOD GetAutoIncrement(bool *aAutoIncrement) = 0;

  /* [implicit_jscontext] nsIIDBRequest get (in jsval key); */
  NS_IMETHOD Get(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval) = 0;

  /* [binaryname(GetAll),implicit_jscontext,optional_argc] nsIIDBRequest mozGetAll ([optional] in jsval key, [optional] in unsigned long limit); */
  NS_IMETHOD GetAll(const JS::Value & key, uint32_t limit, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval) = 0;

  /* [implicit_jscontext,optional_argc] nsIIDBRequest add (in jsval value, [optional] in jsval key); */
  NS_IMETHOD Add(const JS::Value & value, const JS::Value & key, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval) = 0;

  /* [implicit_jscontext,optional_argc] nsIIDBRequest put (in jsval value, [optional] in jsval key); */
  NS_IMETHOD Put(const JS::Value & value, const JS::Value & key, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval) = 0;

  /* [implicit_jscontext] nsIIDBRequest delete (in jsval key); */
  NS_IMETHOD Delete(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval) = 0;

  /* [implicit_jscontext] nsIIDBRequest clear (); */
  NS_IMETHOD Clear(JSContext* cx, nsIIDBRequest * *_retval) = 0;

  /* [implicit_jscontext,optional_argc] nsIIDBRequest openCursor ([optional] in jsval range, [optional] in DOMString direction); */
  NS_IMETHOD OpenCursor(const JS::Value & range, const nsAString & direction, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval) = 0;

  /* [implicit_jscontext] nsIIDBIndex createIndex ([Null (Stringify)] in DOMString name, in jsval keyPath, [optional] in jsval options); */
  NS_IMETHOD CreateIndex(const nsAString & name, const JS::Value & keyPath, const JS::Value & options, JSContext* cx, nsIIDBIndex * *_retval) = 0;

  /* nsIIDBIndex index ([Null (Stringify)] in DOMString name); */
  NS_IMETHOD Index(const nsAString & name, nsIIDBIndex * *_retval) = 0;

  /* void deleteIndex ([Null (Stringify)] in DOMString name); */
  NS_IMETHOD DeleteIndex(const nsAString & name) = 0;

  /* [implicit_jscontext,optional_argc] nsIIDBRequest count ([optional] in jsval key); */
  NS_IMETHOD Count(const JS::Value & key, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBObjectStore, NS_IIDBOBJECTSTORE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBOBJECTSTORE \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD GetKeyPath(JSContext* cx, JS::Value *aKeyPath); \
  NS_IMETHOD GetIndexNames(nsIDOMDOMStringList * *aIndexNames); \
  NS_IMETHOD GetTransaction(nsIIDBTransaction * *aTransaction); \
  NS_IMETHOD GetAutoIncrement(bool *aAutoIncrement); \
  NS_IMETHOD Get(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval); \
  NS_IMETHOD GetAll(const JS::Value & key, uint32_t limit, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval); \
  NS_IMETHOD Add(const JS::Value & value, const JS::Value & key, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval); \
  NS_IMETHOD Put(const JS::Value & value, const JS::Value & key, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval); \
  NS_IMETHOD Delete(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval); \
  NS_IMETHOD Clear(JSContext* cx, nsIIDBRequest * *_retval); \
  NS_IMETHOD OpenCursor(const JS::Value & range, const nsAString & direction, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval); \
  NS_IMETHOD CreateIndex(const nsAString & name, const JS::Value & keyPath, const JS::Value & options, JSContext* cx, nsIIDBIndex * *_retval); \
  NS_IMETHOD Index(const nsAString & name, nsIIDBIndex * *_retval); \
  NS_IMETHOD DeleteIndex(const nsAString & name); \
  NS_IMETHOD Count(const JS::Value & key, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBOBJECTSTORE(_to) \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD GetKeyPath(JSContext* cx, JS::Value *aKeyPath) { return _to GetKeyPath(cx, aKeyPath); } \
  NS_IMETHOD GetIndexNames(nsIDOMDOMStringList * *aIndexNames) { return _to GetIndexNames(aIndexNames); } \
  NS_IMETHOD GetTransaction(nsIIDBTransaction * *aTransaction) { return _to GetTransaction(aTransaction); } \
  NS_IMETHOD GetAutoIncrement(bool *aAutoIncrement) { return _to GetAutoIncrement(aAutoIncrement); } \
  NS_IMETHOD Get(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval) { return _to Get(key, cx, _retval); } \
  NS_IMETHOD GetAll(const JS::Value & key, uint32_t limit, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval) { return _to GetAll(key, limit, cx, _argc, _retval); } \
  NS_IMETHOD Add(const JS::Value & value, const JS::Value & key, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval) { return _to Add(value, key, cx, _argc, _retval); } \
  NS_IMETHOD Put(const JS::Value & value, const JS::Value & key, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval) { return _to Put(value, key, cx, _argc, _retval); } \
  NS_IMETHOD Delete(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval) { return _to Delete(key, cx, _retval); } \
  NS_IMETHOD Clear(JSContext* cx, nsIIDBRequest * *_retval) { return _to Clear(cx, _retval); } \
  NS_IMETHOD OpenCursor(const JS::Value & range, const nsAString & direction, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval) { return _to OpenCursor(range, direction, cx, _argc, _retval); } \
  NS_IMETHOD CreateIndex(const nsAString & name, const JS::Value & keyPath, const JS::Value & options, JSContext* cx, nsIIDBIndex * *_retval) { return _to CreateIndex(name, keyPath, options, cx, _retval); } \
  NS_IMETHOD Index(const nsAString & name, nsIIDBIndex * *_retval) { return _to Index(name, _retval); } \
  NS_IMETHOD DeleteIndex(const nsAString & name) { return _to DeleteIndex(name); } \
  NS_IMETHOD Count(const JS::Value & key, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval) { return _to Count(key, cx, _argc, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBOBJECTSTORE(_to) \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetKeyPath(JSContext* cx, JS::Value *aKeyPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeyPath(cx, aKeyPath); } \
  NS_IMETHOD GetIndexNames(nsIDOMDOMStringList * *aIndexNames) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexNames(aIndexNames); } \
  NS_IMETHOD GetTransaction(nsIIDBTransaction * *aTransaction) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransaction(aTransaction); } \
  NS_IMETHOD GetAutoIncrement(bool *aAutoIncrement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAutoIncrement(aAutoIncrement); } \
  NS_IMETHOD Get(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(key, cx, _retval); } \
  NS_IMETHOD GetAll(const JS::Value & key, uint32_t limit, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAll(key, limit, cx, _argc, _retval); } \
  NS_IMETHOD Add(const JS::Value & value, const JS::Value & key, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(value, key, cx, _argc, _retval); } \
  NS_IMETHOD Put(const JS::Value & value, const JS::Value & key, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Put(value, key, cx, _argc, _retval); } \
  NS_IMETHOD Delete(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Delete(key, cx, _retval); } \
  NS_IMETHOD Clear(JSContext* cx, nsIIDBRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(cx, _retval); } \
  NS_IMETHOD OpenCursor(const JS::Value & range, const nsAString & direction, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenCursor(range, direction, cx, _argc, _retval); } \
  NS_IMETHOD CreateIndex(const nsAString & name, const JS::Value & keyPath, const JS::Value & options, JSContext* cx, nsIIDBIndex * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateIndex(name, keyPath, options, cx, _retval); } \
  NS_IMETHOD Index(const nsAString & name, nsIIDBIndex * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Index(name, _retval); } \
  NS_IMETHOD DeleteIndex(const nsAString & name) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteIndex(name); } \
  NS_IMETHOD Count(const JS::Value & key, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Count(key, cx, _argc, _retval); } 

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

/* [implicit_jscontext] readonly attribute jsval keyPath; */
NS_IMETHODIMP nsIDBObjectStore::GetKeyPath(JSContext* cx, JS::Value *aKeyPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDOMStringList indexNames; */
NS_IMETHODIMP nsIDBObjectStore::GetIndexNames(nsIDOMDOMStringList * *aIndexNames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIIDBTransaction transaction; */
NS_IMETHODIMP nsIDBObjectStore::GetTransaction(nsIIDBTransaction * *aTransaction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean autoIncrement; */
NS_IMETHODIMP nsIDBObjectStore::GetAutoIncrement(bool *aAutoIncrement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIIDBRequest get (in jsval key); */
NS_IMETHODIMP nsIDBObjectStore::Get(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(GetAll),implicit_jscontext,optional_argc] nsIIDBRequest mozGetAll ([optional] in jsval key, [optional] in unsigned long limit); */
NS_IMETHODIMP nsIDBObjectStore::GetAll(const JS::Value & key, uint32_t limit, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] nsIIDBRequest add (in jsval value, [optional] in jsval key); */
NS_IMETHODIMP nsIDBObjectStore::Add(const JS::Value & value, const JS::Value & key, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] nsIIDBRequest put (in jsval value, [optional] in jsval key); */
NS_IMETHODIMP nsIDBObjectStore::Put(const JS::Value & value, const JS::Value & key, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIIDBRequest delete (in jsval key); */
NS_IMETHODIMP nsIDBObjectStore::Delete(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIIDBRequest clear (); */
NS_IMETHODIMP nsIDBObjectStore::Clear(JSContext* cx, nsIIDBRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] nsIIDBRequest openCursor ([optional] in jsval range, [optional] in DOMString direction); */
NS_IMETHODIMP nsIDBObjectStore::OpenCursor(const JS::Value & range, const nsAString & direction, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIIDBIndex createIndex ([Null (Stringify)] in DOMString name, in jsval keyPath, [optional] in jsval options); */
NS_IMETHODIMP nsIDBObjectStore::CreateIndex(const nsAString & name, const JS::Value & keyPath, const JS::Value & options, JSContext* cx, nsIIDBIndex * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIIDBIndex index ([Null (Stringify)] in DOMString name); */
NS_IMETHODIMP nsIDBObjectStore::Index(const nsAString & name, nsIIDBIndex * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteIndex ([Null (Stringify)] in DOMString name); */
NS_IMETHODIMP nsIDBObjectStore::DeleteIndex(const nsAString & name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] nsIIDBRequest count ([optional] in jsval key); */
NS_IMETHODIMP nsIDBObjectStore::Count(const JS::Value & key, JSContext* cx, uint8_t _argc, nsIIDBRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBObjectStore_h__ */

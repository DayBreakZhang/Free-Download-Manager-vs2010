/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/indexedDB/nsIIDBDatabase.idl
 */

#ifndef __gen_nsIIDBDatabase_h__
#define __gen_nsIIDBDatabase_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIIDBObjectStore; /* forward declaration */

class nsIIDBRequest; /* forward declaration */

class nsIIDBTransaction; /* forward declaration */

class nsIDOMDOMStringList; /* forward declaration */

class nsIDOMEventListener; /* forward declaration */


/* starting interface:    nsIIDBDatabase */
#define NS_IIDBDATABASE_IID_STR "89299bf8-e078-4ebc-abda-d97fe5618602"

#define NS_IIDBDATABASE_IID \
  {0x89299bf8, 0xe078, 0x4ebc, \
    { 0xab, 0xda, 0xd9, 0x7f, 0xe5, 0x61, 0x86, 0x02 }}

class NS_NO_VTABLE nsIIDBDatabase : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBDATABASE_IID)

  /* readonly attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute unsigned long long version; */
  NS_IMETHOD GetVersion(uint64_t *aVersion) = 0;

  /* readonly attribute nsIDOMDOMStringList objectStoreNames; */
  NS_IMETHOD GetObjectStoreNames(nsIDOMDOMStringList * *aObjectStoreNames) = 0;

  /* [implicit_jscontext] nsIIDBObjectStore createObjectStore ([Null (Stringify)] in DOMString name, [optional] in jsval options); */
  NS_IMETHOD CreateObjectStore(const nsAString & name, const JS::Value & options, JSContext* cx, nsIIDBObjectStore * *_retval) = 0;

  /* void deleteObjectStore ([Null (Stringify)] in DOMString name); */
  NS_IMETHOD DeleteObjectStore(const nsAString & name) = 0;

  /* [implicit_jscontext,optional_argc] nsIIDBTransaction transaction (in jsval storeNames, [optional] in DOMString mode); */
  NS_IMETHOD Transaction(const JS::Value & storeNames, const nsAString & mode, JSContext* cx, uint8_t _argc, nsIIDBTransaction * *_retval) = 0;

  /* [implicit_jscontext] nsIIDBRequest mozCreateFileHandle (in DOMString name, [optional] in DOMString type); */
  NS_IMETHOD MozCreateFileHandle(const nsAString & name, const nsAString & type, JSContext* cx, nsIIDBRequest * *_retval) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

  /* [implicit_jscontext] attribute jsval onabort; */
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort) = 0;
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort) = 0;

  /* [implicit_jscontext] attribute jsval onerror; */
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) = 0;
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) = 0;

  /* [implicit_jscontext] attribute jsval onversionchange; */
  NS_IMETHOD GetOnversionchange(JSContext* cx, JS::Value *aOnversionchange) = 0;
  NS_IMETHOD SetOnversionchange(JSContext* cx, const JS::Value & aOnversionchange) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBDatabase, NS_IIDBDATABASE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBDATABASE \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD GetVersion(uint64_t *aVersion); \
  NS_IMETHOD GetObjectStoreNames(nsIDOMDOMStringList * *aObjectStoreNames); \
  NS_IMETHOD CreateObjectStore(const nsAString & name, const JS::Value & options, JSContext* cx, nsIIDBObjectStore * *_retval); \
  NS_IMETHOD DeleteObjectStore(const nsAString & name); \
  NS_IMETHOD Transaction(const JS::Value & storeNames, const nsAString & mode, JSContext* cx, uint8_t _argc, nsIIDBTransaction * *_retval); \
  NS_IMETHOD MozCreateFileHandle(const nsAString & name, const nsAString & type, JSContext* cx, nsIIDBRequest * *_retval); \
  NS_IMETHOD Close(void); \
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort); \
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort); \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror); \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror); \
  NS_IMETHOD GetOnversionchange(JSContext* cx, JS::Value *aOnversionchange); \
  NS_IMETHOD SetOnversionchange(JSContext* cx, const JS::Value & aOnversionchange); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBDATABASE(_to) \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD GetVersion(uint64_t *aVersion) { return _to GetVersion(aVersion); } \
  NS_IMETHOD GetObjectStoreNames(nsIDOMDOMStringList * *aObjectStoreNames) { return _to GetObjectStoreNames(aObjectStoreNames); } \
  NS_IMETHOD CreateObjectStore(const nsAString & name, const JS::Value & options, JSContext* cx, nsIIDBObjectStore * *_retval) { return _to CreateObjectStore(name, options, cx, _retval); } \
  NS_IMETHOD DeleteObjectStore(const nsAString & name) { return _to DeleteObjectStore(name); } \
  NS_IMETHOD Transaction(const JS::Value & storeNames, const nsAString & mode, JSContext* cx, uint8_t _argc, nsIIDBTransaction * *_retval) { return _to Transaction(storeNames, mode, cx, _argc, _retval); } \
  NS_IMETHOD MozCreateFileHandle(const nsAString & name, const nsAString & type, JSContext* cx, nsIIDBRequest * *_retval) { return _to MozCreateFileHandle(name, type, cx, _retval); } \
  NS_IMETHOD Close(void) { return _to Close(); } \
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort) { return _to GetOnabort(cx, aOnabort); } \
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort) { return _to SetOnabort(cx, aOnabort); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) { return _to GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) { return _to SetOnerror(cx, aOnerror); } \
  NS_IMETHOD GetOnversionchange(JSContext* cx, JS::Value *aOnversionchange) { return _to GetOnversionchange(cx, aOnversionchange); } \
  NS_IMETHOD SetOnversionchange(JSContext* cx, const JS::Value & aOnversionchange) { return _to SetOnversionchange(cx, aOnversionchange); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBDATABASE(_to) \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetVersion(uint64_t *aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_IMETHOD GetObjectStoreNames(nsIDOMDOMStringList * *aObjectStoreNames) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObjectStoreNames(aObjectStoreNames); } \
  NS_IMETHOD CreateObjectStore(const nsAString & name, const JS::Value & options, JSContext* cx, nsIIDBObjectStore * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateObjectStore(name, options, cx, _retval); } \
  NS_IMETHOD DeleteObjectStore(const nsAString & name) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteObjectStore(name); } \
  NS_IMETHOD Transaction(const JS::Value & storeNames, const nsAString & mode, JSContext* cx, uint8_t _argc, nsIIDBTransaction * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Transaction(storeNames, mode, cx, _argc, _retval); } \
  NS_IMETHOD MozCreateFileHandle(const nsAString & name, const nsAString & type, JSContext* cx, nsIIDBRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozCreateFileHandle(name, type, cx, _retval); } \
  NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnabort(cx, aOnabort); } \
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnabort(cx, aOnabort); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnerror(cx, aOnerror); } \
  NS_IMETHOD GetOnversionchange(JSContext* cx, JS::Value *aOnversionchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnversionchange(cx, aOnversionchange); } \
  NS_IMETHOD SetOnversionchange(JSContext* cx, const JS::Value & aOnversionchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnversionchange(cx, aOnversionchange); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIDBDatabase : public nsIIDBDatabase
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDBDATABASE

  nsIDBDatabase();

private:
  ~nsIDBDatabase();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIDBDatabase, nsIIDBDatabase)

nsIDBDatabase::nsIDBDatabase()
{
  /* member initializers and constructor code */
}

nsIDBDatabase::~nsIDBDatabase()
{
  /* destructor code */
}

/* readonly attribute DOMString name; */
NS_IMETHODIMP nsIDBDatabase::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long version; */
NS_IMETHODIMP nsIDBDatabase::GetVersion(uint64_t *aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDOMStringList objectStoreNames; */
NS_IMETHODIMP nsIDBDatabase::GetObjectStoreNames(nsIDOMDOMStringList * *aObjectStoreNames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIIDBObjectStore createObjectStore ([Null (Stringify)] in DOMString name, [optional] in jsval options); */
NS_IMETHODIMP nsIDBDatabase::CreateObjectStore(const nsAString & name, const JS::Value & options, JSContext* cx, nsIIDBObjectStore * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteObjectStore ([Null (Stringify)] in DOMString name); */
NS_IMETHODIMP nsIDBDatabase::DeleteObjectStore(const nsAString & name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] nsIIDBTransaction transaction (in jsval storeNames, [optional] in DOMString mode); */
NS_IMETHODIMP nsIDBDatabase::Transaction(const JS::Value & storeNames, const nsAString & mode, JSContext* cx, uint8_t _argc, nsIIDBTransaction * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIIDBRequest mozCreateFileHandle (in DOMString name, [optional] in DOMString type); */
NS_IMETHODIMP nsIDBDatabase::MozCreateFileHandle(const nsAString & name, const nsAString & type, JSContext* cx, nsIIDBRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsIDBDatabase::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onabort; */
NS_IMETHODIMP nsIDBDatabase::GetOnabort(JSContext* cx, JS::Value *aOnabort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIDBDatabase::SetOnabort(JSContext* cx, const JS::Value & aOnabort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onerror; */
NS_IMETHODIMP nsIDBDatabase::GetOnerror(JSContext* cx, JS::Value *aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIDBDatabase::SetOnerror(JSContext* cx, const JS::Value & aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onversionchange; */
NS_IMETHODIMP nsIDBDatabase::GetOnversionchange(JSContext* cx, JS::Value *aOnversionchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIDBDatabase::SetOnversionchange(JSContext* cx, const JS::Value & aOnversionchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBDatabase_h__ */

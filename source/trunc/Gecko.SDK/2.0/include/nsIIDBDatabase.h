/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/indexedDB/nsIIDBDatabase.idl
 */

#ifndef __gen_nsIIDBDatabase_h__
#define __gen_nsIIDBDatabase_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */

class nsIIDBObjectStore; /* forward declaration */

class nsIIDBRequest; /* forward declaration */

class nsIIDBTransaction; /* forward declaration */

class nsIDOMDOMStringList; /* forward declaration */

class nsIDOMEventListener; /* forward declaration */

#include "jsapi.h"

/* starting interface:    nsIIDBDatabase */
#define NS_IIDBDATABASE_IID_STR "42b38d02-1a29-45f0-99ef-04fd5b441270"

#define NS_IIDBDATABASE_IID \
  {0x42b38d02, 0x1a29, 0x45f0, \
    { 0x99, 0xef, 0x04, 0xfd, 0x5b, 0x44, 0x12, 0x70 }}

/**
 * IDBDatabase interface.  See
 * http://dvcs.w3.org/hg/IndexedDB/raw-file/tip/Overview.html#idl-def-IDBDatabase
 * for more information.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIIDBDatabase : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBDATABASE_IID)

  /* readonly attribute DOMString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute DOMString version; */
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) = 0;

  /* readonly attribute nsIDOMDOMStringList objectStoreNames; */
  NS_SCRIPTABLE NS_IMETHOD GetObjectStoreNames(nsIDOMDOMStringList **aObjectStoreNames) = 0;

  /**
   * Optional arguments:
   *   - keyPath (string):
   *       Specifies key path on objects in the objectStore. Defaults to no key
   *       path.
   *   - autoIncrement (boolean):
   *       Specifies if the objectStore has a key generator. Defaults to false.
   */
  /* [implicit_jscontext] nsIIDBObjectStore createObjectStore (in AString name, [optional] in jsval options); */
  NS_SCRIPTABLE NS_IMETHOD CreateObjectStore(const nsAString & name, const jsval & options, JSContext *cx, nsIIDBObjectStore **_retval NS_OUTPARAM) = 0;

  /* void deleteObjectStore (in AString name); */
  NS_SCRIPTABLE NS_IMETHOD DeleteObjectStore(const nsAString & name) = 0;

  /* [implicit_jscontext] nsIIDBRequest setVersion (in AString version); */
  NS_SCRIPTABLE NS_IMETHOD SetVersion(const nsAString & version, JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM) = 0;

  /* [optional_argc, implicit_jscontext] nsIIDBTransaction transaction (in nsIVariant storeNames, [optional] in unsigned short mode, [optional] in unsigned long timeout); */
  NS_SCRIPTABLE NS_IMETHOD Transaction(nsIVariant *storeNames, PRUint16 mode, PRUint32 timeout, JSContext *cx, PRUint8 _argc, nsIIDBTransaction **_retval NS_OUTPARAM) = 0;

  /* void close (); */
  NS_SCRIPTABLE NS_IMETHOD Close(void) = 0;

  /* attribute nsIDOMEventListener onerror; */
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener **aOnerror) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror) = 0;

  /* attribute nsIDOMEventListener onversionchange; */
  NS_SCRIPTABLE NS_IMETHOD GetOnversionchange(nsIDOMEventListener **aOnversionchange) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnversionchange(nsIDOMEventListener *aOnversionchange) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBDatabase, NS_IIDBDATABASE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBDATABASE \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetObjectStoreNames(nsIDOMDOMStringList **aObjectStoreNames); \
  NS_SCRIPTABLE NS_IMETHOD CreateObjectStore(const nsAString & name, const jsval & options, JSContext *cx, nsIIDBObjectStore **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DeleteObjectStore(const nsAString & name); \
  NS_SCRIPTABLE NS_IMETHOD SetVersion(const nsAString & version, JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Transaction(nsIVariant *storeNames, PRUint16 mode, PRUint32 timeout, JSContext *cx, PRUint8 _argc, nsIIDBTransaction **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Close(void); \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener **aOnerror); \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror); \
  NS_SCRIPTABLE NS_IMETHOD GetOnversionchange(nsIDOMEventListener **aOnversionchange); \
  NS_SCRIPTABLE NS_IMETHOD SetOnversionchange(nsIDOMEventListener *aOnversionchange); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBDATABASE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) { return _to GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetObjectStoreNames(nsIDOMDOMStringList **aObjectStoreNames) { return _to GetObjectStoreNames(aObjectStoreNames); } \
  NS_SCRIPTABLE NS_IMETHOD CreateObjectStore(const nsAString & name, const jsval & options, JSContext *cx, nsIIDBObjectStore **_retval NS_OUTPARAM) { return _to CreateObjectStore(name, options, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteObjectStore(const nsAString & name) { return _to DeleteObjectStore(name); } \
  NS_SCRIPTABLE NS_IMETHOD SetVersion(const nsAString & version, JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM) { return _to SetVersion(version, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Transaction(nsIVariant *storeNames, PRUint16 mode, PRUint32 timeout, JSContext *cx, PRUint8 _argc, nsIIDBTransaction **_retval NS_OUTPARAM) { return _to Transaction(storeNames, mode, timeout, cx, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return _to Close(); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener **aOnerror) { return _to GetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror) { return _to SetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnversionchange(nsIDOMEventListener **aOnversionchange) { return _to GetOnversionchange(aOnversionchange); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnversionchange(nsIDOMEventListener *aOnversionchange) { return _to SetOnversionchange(aOnversionchange); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBDATABASE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetObjectStoreNames(nsIDOMDOMStringList **aObjectStoreNames) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObjectStoreNames(aObjectStoreNames); } \
  NS_SCRIPTABLE NS_IMETHOD CreateObjectStore(const nsAString & name, const jsval & options, JSContext *cx, nsIIDBObjectStore **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateObjectStore(name, options, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteObjectStore(const nsAString & name) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteObjectStore(name); } \
  NS_SCRIPTABLE NS_IMETHOD SetVersion(const nsAString & version, JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVersion(version, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Transaction(nsIVariant *storeNames, PRUint16 mode, PRUint32 timeout, JSContext *cx, PRUint8 _argc, nsIIDBTransaction **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Transaction(storeNames, mode, timeout, cx, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener **aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnversionchange(nsIDOMEventListener **aOnversionchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnversionchange(aOnversionchange); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnversionchange(nsIDOMEventListener *aOnversionchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnversionchange(aOnversionchange); } 

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

/* readonly attribute DOMString version; */
NS_IMETHODIMP nsIDBDatabase::GetVersion(nsAString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDOMStringList objectStoreNames; */
NS_IMETHODIMP nsIDBDatabase::GetObjectStoreNames(nsIDOMDOMStringList **aObjectStoreNames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIIDBObjectStore createObjectStore (in AString name, [optional] in jsval options); */
NS_IMETHODIMP nsIDBDatabase::CreateObjectStore(const nsAString & name, const jsval & options, JSContext *cx, nsIIDBObjectStore **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteObjectStore (in AString name); */
NS_IMETHODIMP nsIDBDatabase::DeleteObjectStore(const nsAString & name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIIDBRequest setVersion (in AString version); */
NS_IMETHODIMP nsIDBDatabase::SetVersion(const nsAString & version, JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc, implicit_jscontext] nsIIDBTransaction transaction (in nsIVariant storeNames, [optional] in unsigned short mode, [optional] in unsigned long timeout); */
NS_IMETHODIMP nsIDBDatabase::Transaction(nsIVariant *storeNames, PRUint16 mode, PRUint32 timeout, JSContext *cx, PRUint8 _argc, nsIIDBTransaction **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsIDBDatabase::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onerror; */
NS_IMETHODIMP nsIDBDatabase::GetOnerror(nsIDOMEventListener **aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIDBDatabase::SetOnerror(nsIDOMEventListener *aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onversionchange; */
NS_IMETHODIMP nsIDBDatabase::GetOnversionchange(nsIDOMEventListener **aOnversionchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIDBDatabase::SetOnversionchange(nsIDOMEventListener *aOnversionchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBDatabase_h__ */

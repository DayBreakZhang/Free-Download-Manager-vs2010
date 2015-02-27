/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/indexedDB/nsIIDBTransaction.idl
 */

#ifndef __gen_nsIIDBTransaction_h__
#define __gen_nsIIDBTransaction_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMEventListener; /* forward declaration */

class nsIIDBObjectStore; /* forward declaration */

class nsIIDBRequest; /* forward declaration */

class nsIIDBDatabase; /* forward declaration */

class nsIDOMDOMStringList; /* forward declaration */


/* starting interface:    nsIIDBTransaction */
#define NS_IIDBTRANSACTION_IID_STR "13e551a1-1a58-42ec-b0bd-7102ec0f64d6"

#define NS_IIDBTRANSACTION_IID \
  {0x13e551a1, 0x1a58, 0x42ec, \
    { 0xb0, 0xbd, 0x71, 0x02, 0xec, 0x0f, 0x64, 0xd6 }}

/**
 * IDBDTransaction interface.  See
 * http://dvcs.w3.org/hg/IndexedDB/raw-file/tip/Overview.html#idl-def-IDBTransaction
 * for more information.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIIDBTransaction : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBTRANSACTION_IID)

  /* readonly attribute nsIIDBDatabase db; */
  NS_SCRIPTABLE NS_IMETHOD GetDb(nsIIDBDatabase **aDb) = 0;

  enum { INITIAL = 0U };

  enum { LOADING = 1U };

  enum { COMMITTING = 2U };

  enum { DONE = 3U };

  /* readonly attribute unsigned short readyState; */
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(PRUint16 *aReadyState) = 0;

  enum { READ_ONLY = 0U };

  enum { READ_WRITE = 1U };

  enum { VERSION_CHANGE = 2U };

  /* readonly attribute unsigned short mode; */
  NS_SCRIPTABLE NS_IMETHOD GetMode(PRUint16 *aMode) = 0;

  /* readonly attribute nsIDOMDOMStringList objectStoreNames; */
  NS_SCRIPTABLE NS_IMETHOD GetObjectStoreNames(nsIDOMDOMStringList **aObjectStoreNames) = 0;

  /* nsIIDBObjectStore objectStore (in AString name); */
  NS_SCRIPTABLE NS_IMETHOD ObjectStore(const nsAString & name, nsIIDBObjectStore **_retval NS_OUTPARAM) = 0;

  /* void abort (); */
  NS_SCRIPTABLE NS_IMETHOD Abort(void) = 0;

  /* attribute nsIDOMEventListener onerror; */
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener **aOnerror) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror) = 0;

  /* attribute nsIDOMEventListener oncomplete; */
  NS_SCRIPTABLE NS_IMETHOD GetOncomplete(nsIDOMEventListener **aOncomplete) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOncomplete(nsIDOMEventListener *aOncomplete) = 0;

  /* attribute nsIDOMEventListener onabort; */
  NS_SCRIPTABLE NS_IMETHOD GetOnabort(nsIDOMEventListener **aOnabort) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnabort(nsIDOMEventListener *aOnabort) = 0;

  /* attribute nsIDOMEventListener ontimeout; */
  NS_SCRIPTABLE NS_IMETHOD GetOntimeout(nsIDOMEventListener **aOntimeout) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOntimeout(nsIDOMEventListener *aOntimeout) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBTransaction, NS_IIDBTRANSACTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBTRANSACTION \
  NS_SCRIPTABLE NS_IMETHOD GetDb(nsIIDBDatabase **aDb); \
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(PRUint16 *aReadyState); \
  NS_SCRIPTABLE NS_IMETHOD GetMode(PRUint16 *aMode); \
  NS_SCRIPTABLE NS_IMETHOD GetObjectStoreNames(nsIDOMDOMStringList **aObjectStoreNames); \
  NS_SCRIPTABLE NS_IMETHOD ObjectStore(const nsAString & name, nsIIDBObjectStore **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Abort(void); \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener **aOnerror); \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror); \
  NS_SCRIPTABLE NS_IMETHOD GetOncomplete(nsIDOMEventListener **aOncomplete); \
  NS_SCRIPTABLE NS_IMETHOD SetOncomplete(nsIDOMEventListener *aOncomplete); \
  NS_SCRIPTABLE NS_IMETHOD GetOnabort(nsIDOMEventListener **aOnabort); \
  NS_SCRIPTABLE NS_IMETHOD SetOnabort(nsIDOMEventListener *aOnabort); \
  NS_SCRIPTABLE NS_IMETHOD GetOntimeout(nsIDOMEventListener **aOntimeout); \
  NS_SCRIPTABLE NS_IMETHOD SetOntimeout(nsIDOMEventListener *aOntimeout); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBTRANSACTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDb(nsIIDBDatabase **aDb) { return _to GetDb(aDb); } \
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(PRUint16 *aReadyState) { return _to GetReadyState(aReadyState); } \
  NS_SCRIPTABLE NS_IMETHOD GetMode(PRUint16 *aMode) { return _to GetMode(aMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetObjectStoreNames(nsIDOMDOMStringList **aObjectStoreNames) { return _to GetObjectStoreNames(aObjectStoreNames); } \
  NS_SCRIPTABLE NS_IMETHOD ObjectStore(const nsAString & name, nsIIDBObjectStore **_retval NS_OUTPARAM) { return _to ObjectStore(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Abort(void) { return _to Abort(); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener **aOnerror) { return _to GetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror) { return _to SetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD GetOncomplete(nsIDOMEventListener **aOncomplete) { return _to GetOncomplete(aOncomplete); } \
  NS_SCRIPTABLE NS_IMETHOD SetOncomplete(nsIDOMEventListener *aOncomplete) { return _to SetOncomplete(aOncomplete); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnabort(nsIDOMEventListener **aOnabort) { return _to GetOnabort(aOnabort); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnabort(nsIDOMEventListener *aOnabort) { return _to SetOnabort(aOnabort); } \
  NS_SCRIPTABLE NS_IMETHOD GetOntimeout(nsIDOMEventListener **aOntimeout) { return _to GetOntimeout(aOntimeout); } \
  NS_SCRIPTABLE NS_IMETHOD SetOntimeout(nsIDOMEventListener *aOntimeout) { return _to SetOntimeout(aOntimeout); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBTRANSACTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDb(nsIIDBDatabase **aDb) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDb(aDb); } \
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(PRUint16 *aReadyState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReadyState(aReadyState); } \
  NS_SCRIPTABLE NS_IMETHOD GetMode(PRUint16 *aMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMode(aMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetObjectStoreNames(nsIDOMDOMStringList **aObjectStoreNames) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObjectStoreNames(aObjectStoreNames); } \
  NS_SCRIPTABLE NS_IMETHOD ObjectStore(const nsAString & name, nsIIDBObjectStore **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ObjectStore(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Abort(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Abort(); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener **aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD GetOncomplete(nsIDOMEventListener **aOncomplete) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOncomplete(aOncomplete); } \
  NS_SCRIPTABLE NS_IMETHOD SetOncomplete(nsIDOMEventListener *aOncomplete) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOncomplete(aOncomplete); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnabort(nsIDOMEventListener **aOnabort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnabort(aOnabort); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnabort(nsIDOMEventListener *aOnabort) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnabort(aOnabort); } \
  NS_SCRIPTABLE NS_IMETHOD GetOntimeout(nsIDOMEventListener **aOntimeout) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOntimeout(aOntimeout); } \
  NS_SCRIPTABLE NS_IMETHOD SetOntimeout(nsIDOMEventListener *aOntimeout) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOntimeout(aOntimeout); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIDBTransaction : public nsIIDBTransaction
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDBTRANSACTION

  nsIDBTransaction();

private:
  ~nsIDBTransaction();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIDBTransaction, nsIIDBTransaction)

nsIDBTransaction::nsIDBTransaction()
{
  /* member initializers and constructor code */
}

nsIDBTransaction::~nsIDBTransaction()
{
  /* destructor code */
}

/* readonly attribute nsIIDBDatabase db; */
NS_IMETHODIMP nsIDBTransaction::GetDb(nsIIDBDatabase **aDb)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short readyState; */
NS_IMETHODIMP nsIDBTransaction::GetReadyState(PRUint16 *aReadyState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short mode; */
NS_IMETHODIMP nsIDBTransaction::GetMode(PRUint16 *aMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDOMStringList objectStoreNames; */
NS_IMETHODIMP nsIDBTransaction::GetObjectStoreNames(nsIDOMDOMStringList **aObjectStoreNames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIIDBObjectStore objectStore (in AString name); */
NS_IMETHODIMP nsIDBTransaction::ObjectStore(const nsAString & name, nsIIDBObjectStore **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void abort (); */
NS_IMETHODIMP nsIDBTransaction::Abort()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onerror; */
NS_IMETHODIMP nsIDBTransaction::GetOnerror(nsIDOMEventListener **aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIDBTransaction::SetOnerror(nsIDOMEventListener *aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener oncomplete; */
NS_IMETHODIMP nsIDBTransaction::GetOncomplete(nsIDOMEventListener **aOncomplete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIDBTransaction::SetOncomplete(nsIDOMEventListener *aOncomplete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onabort; */
NS_IMETHODIMP nsIDBTransaction::GetOnabort(nsIDOMEventListener **aOnabort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIDBTransaction::SetOnabort(nsIDOMEventListener *aOnabort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener ontimeout; */
NS_IMETHODIMP nsIDBTransaction::GetOntimeout(nsIDOMEventListener **aOntimeout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIDBTransaction::SetOntimeout(nsIDOMEventListener *aOntimeout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBTransaction_h__ */

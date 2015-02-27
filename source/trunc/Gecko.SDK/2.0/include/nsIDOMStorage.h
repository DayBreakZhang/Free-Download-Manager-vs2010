/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/storage/nsIDOMStorage.idl
 */

#ifndef __gen_nsIDOMStorage_h__
#define __gen_nsIDOMStorage_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMStorage */
#define NS_IDOMSTORAGE_IID_STR "43e5edad-1e02-42c4-9d99-c3d9dee22a20"

#define NS_IDOMSTORAGE_IID \
  {0x43e5edad, 0x1e02, 0x42c4, \
    { 0x9d, 0x99, 0xc3, 0xd9, 0xde, 0xe2, 0x2a, 0x20 }}

/**
 * Interface for client side storage. See
 * http://www.whatwg.org/specs/web-apps/current-work/multipage/structured.html#storage0
 * for more information.
 *
 * A storage object stores an arbitrary set of key-value pairs, which
 * may be retrieved, modified and removed as needed. A key may only
 * exist once within a storage object, and only one value may be
 * associated with a particular key. Keys are stored in a particular
 * order with the condition that this order not change by merely changing
 * the value associated with a key, but the order may change when a
 * key is added or removed.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMStorage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTORAGE_IID)

  /**
   * The number of keys stored.
   */
  /* readonly attribute unsigned long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) = 0;

  /**
   * Retrieve the name of the key at a particular index.
   *
   * @param index index of the item to retrieve
   * @returns the key at index
   * @throws INDEX_SIZE_ERR if there is no key at that index
   */
  /* DOMString key (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD Key(PRUint32 index, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Retrieve an item with a given key
   *
   * @param key key to retrieve
   * @returns found data or empty string if the key was not found
   */
  /* DOMString getItem (in DOMString key); */
  NS_SCRIPTABLE NS_IMETHOD GetItem(const nsAString & key, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Assign a value with a key. If the key does not exist already, a new
   * key is added associated with that value. If the key already exists,
   * then the existing value is replaced with a new value.
   *
   * @param key key to set
   * @param data data to associate with the key
   */
  /* void setItem (in DOMString key, in DOMString data); */
  NS_SCRIPTABLE NS_IMETHOD SetItem(const nsAString & key, const nsAString & data) = 0;

  /**
   * Remove a key and its corresponding value.
   *
   * @param key key to remove
   */
  /* void removeItem (in DOMString key); */
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(const nsAString & key) = 0;

  /**
   * Clear the content of this storage bound to a domain
   * or an origin.
   */
  /* void clear (); */
  NS_SCRIPTABLE NS_IMETHOD Clear(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStorage, NS_IDOMSTORAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTORAGE \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength); \
  NS_SCRIPTABLE NS_IMETHOD Key(PRUint32 index, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItem(const nsAString & key, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetItem(const nsAString & key, const nsAString & data); \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(const nsAString & key); \
  NS_SCRIPTABLE NS_IMETHOD Clear(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTORAGE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return _to GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Key(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return _to Key(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItem(const nsAString & key, nsAString & _retval NS_OUTPARAM) { return _to GetItem(key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetItem(const nsAString & key, const nsAString & data) { return _to SetItem(key, data); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(const nsAString & key) { return _to RemoveItem(key); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(void) { return _to Clear(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTORAGE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Key(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Key(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItem(const nsAString & key, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItem(key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetItem(const nsAString & key, const nsAString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItem(key, data); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(const nsAString & key) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItem(key); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMStorage : public nsIDOMStorage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSTORAGE

  nsDOMStorage();

private:
  ~nsDOMStorage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMStorage, nsIDOMStorage)

nsDOMStorage::nsDOMStorage()
{
  /* member initializers and constructor code */
}

nsDOMStorage::~nsDOMStorage()
{
  /* destructor code */
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMStorage::GetLength(PRUint32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString key (in unsigned long index); */
NS_IMETHODIMP nsDOMStorage::Key(PRUint32 index, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getItem (in DOMString key); */
NS_IMETHODIMP nsDOMStorage::GetItem(const nsAString & key, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setItem (in DOMString key, in DOMString data); */
NS_IMETHODIMP nsDOMStorage::SetItem(const nsAString & key, const nsAString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeItem (in DOMString key); */
NS_IMETHODIMP nsDOMStorage::RemoveItem(const nsAString & key)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clear (); */
NS_IMETHODIMP nsDOMStorage::Clear()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMStorage_h__ */

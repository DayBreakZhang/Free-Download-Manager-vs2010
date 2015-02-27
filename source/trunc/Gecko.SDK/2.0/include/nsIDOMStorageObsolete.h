/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/storage/nsIDOMStorageObsolete.idl
 */

#ifndef __gen_nsIDOMStorageObsolete_h__
#define __gen_nsIDOMStorageObsolete_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMStorageItem; /* forward declaration */


/* starting interface:    nsIDOMStorageObsolete */
#define NS_IDOMSTORAGEOBSOLETE_IID_STR "18013cf9-b104-49cf-9484-c2a7a845457e"

#define NS_IDOMSTORAGEOBSOLETE_IID \
  {0x18013cf9, 0xb104, 0x49cf, \
    { 0x94, 0x84, 0xc2, 0xa7, 0xa8, 0x45, 0x45, 0x7e }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMStorageObsolete : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTORAGEOBSOLETE_IID)

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
   * @returns found item or null if the key was not found
   */
  /* nsIDOMStorageItem getItem (in DOMString key); */
  NS_SCRIPTABLE NS_IMETHOD GetItem(const nsAString & key, nsIDOMStorageItem **_retval NS_OUTPARAM) = 0;

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

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStorageObsolete, NS_IDOMSTORAGEOBSOLETE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTORAGEOBSOLETE \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength); \
  NS_SCRIPTABLE NS_IMETHOD Key(PRUint32 index, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItem(const nsAString & key, nsIDOMStorageItem **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetItem(const nsAString & key, const nsAString & data); \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(const nsAString & key); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTORAGEOBSOLETE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return _to GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Key(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return _to Key(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItem(const nsAString & key, nsIDOMStorageItem **_retval NS_OUTPARAM) { return _to GetItem(key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetItem(const nsAString & key, const nsAString & data) { return _to SetItem(key, data); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(const nsAString & key) { return _to RemoveItem(key); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTORAGEOBSOLETE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Key(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Key(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItem(const nsAString & key, nsIDOMStorageItem **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItem(key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetItem(const nsAString & key, const nsAString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItem(key, data); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(const nsAString & key) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItem(key); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMStorageObsolete : public nsIDOMStorageObsolete
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSTORAGEOBSOLETE

  nsDOMStorageObsolete();

private:
  ~nsDOMStorageObsolete();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMStorageObsolete, nsIDOMStorageObsolete)

nsDOMStorageObsolete::nsDOMStorageObsolete()
{
  /* member initializers and constructor code */
}

nsDOMStorageObsolete::~nsDOMStorageObsolete()
{
  /* destructor code */
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMStorageObsolete::GetLength(PRUint32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString key (in unsigned long index); */
NS_IMETHODIMP nsDOMStorageObsolete::Key(PRUint32 index, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMStorageItem getItem (in DOMString key); */
NS_IMETHODIMP nsDOMStorageObsolete::GetItem(const nsAString & key, nsIDOMStorageItem **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setItem (in DOMString key, in DOMString data); */
NS_IMETHODIMP nsDOMStorageObsolete::SetItem(const nsAString & key, const nsAString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeItem (in DOMString key); */
NS_IMETHODIMP nsDOMStorageObsolete::RemoveItem(const nsAString & key)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMStorageObsolete_h__ */

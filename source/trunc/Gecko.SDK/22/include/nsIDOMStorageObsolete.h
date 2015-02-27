/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/storage/nsIDOMStorageObsolete.idl
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

class NS_NO_VTABLE nsIDOMStorageObsolete : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTORAGEOBSOLETE_IID)

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

  /* DOMString key (in unsigned long index); */
  NS_IMETHOD Key(uint32_t index, nsAString & _retval) = 0;

  /* nsIDOMStorageItem getItem (in DOMString key); */
  NS_IMETHOD GetItem(const nsAString & key, nsIDOMStorageItem * *_retval) = 0;

  /* void setItem (in DOMString key, in DOMString data); */
  NS_IMETHOD SetItem(const nsAString & key, const nsAString & data) = 0;

  /* void removeItem (in DOMString key); */
  NS_IMETHOD RemoveItem(const nsAString & key) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStorageObsolete, NS_IDOMSTORAGEOBSOLETE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTORAGEOBSOLETE \
  NS_IMETHOD GetLength(uint32_t *aLength); \
  NS_IMETHOD Key(uint32_t index, nsAString & _retval); \
  NS_IMETHOD GetItem(const nsAString & key, nsIDOMStorageItem * *_retval); \
  NS_IMETHOD SetItem(const nsAString & key, const nsAString & data); \
  NS_IMETHOD RemoveItem(const nsAString & key); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTORAGEOBSOLETE(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) { return _to GetLength(aLength); } \
  NS_IMETHOD Key(uint32_t index, nsAString & _retval) { return _to Key(index, _retval); } \
  NS_IMETHOD GetItem(const nsAString & key, nsIDOMStorageItem * *_retval) { return _to GetItem(key, _retval); } \
  NS_IMETHOD SetItem(const nsAString & key, const nsAString & data) { return _to SetItem(key, data); } \
  NS_IMETHOD RemoveItem(const nsAString & key) { return _to RemoveItem(key); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTORAGEOBSOLETE(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD Key(uint32_t index, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Key(index, _retval); } \
  NS_IMETHOD GetItem(const nsAString & key, nsIDOMStorageItem * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItem(key, _retval); } \
  NS_IMETHOD SetItem(const nsAString & key, const nsAString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItem(key, data); } \
  NS_IMETHOD RemoveItem(const nsAString & key) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItem(key); } 

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
NS_IMETHODIMP nsDOMStorageObsolete::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString key (in unsigned long index); */
NS_IMETHODIMP nsDOMStorageObsolete::Key(uint32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMStorageItem getItem (in DOMString key); */
NS_IMETHODIMP nsDOMStorageObsolete::GetItem(const nsAString & key, nsIDOMStorageItem * *_retval)
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

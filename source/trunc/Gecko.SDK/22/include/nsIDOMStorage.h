/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/storage/nsIDOMStorage.idl
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

class NS_NO_VTABLE nsIDOMStorage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTORAGE_IID)

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

  /* DOMString key (in unsigned long index); */
  NS_IMETHOD Key(uint32_t index, nsAString & _retval) = 0;

  /* DOMString getItem ([Null (Stringify)] in DOMString key); */
  NS_IMETHOD GetItem(const nsAString & key, nsAString & _retval) = 0;

  /* void setItem ([Null (Stringify)] in DOMString key, [Null (Stringify)] in DOMString data); */
  NS_IMETHOD SetItem(const nsAString & key, const nsAString & data) = 0;

  /* void removeItem ([Null (Stringify)] in DOMString key); */
  NS_IMETHOD RemoveItem(const nsAString & key) = 0;

  /* void clear (); */
  NS_IMETHOD Clear(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStorage, NS_IDOMSTORAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTORAGE \
  NS_IMETHOD GetLength(uint32_t *aLength); \
  NS_IMETHOD Key(uint32_t index, nsAString & _retval); \
  NS_IMETHOD GetItem(const nsAString & key, nsAString & _retval); \
  NS_IMETHOD SetItem(const nsAString & key, const nsAString & data); \
  NS_IMETHOD RemoveItem(const nsAString & key); \
  NS_IMETHOD Clear(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTORAGE(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) { return _to GetLength(aLength); } \
  NS_IMETHOD Key(uint32_t index, nsAString & _retval) { return _to Key(index, _retval); } \
  NS_IMETHOD GetItem(const nsAString & key, nsAString & _retval) { return _to GetItem(key, _retval); } \
  NS_IMETHOD SetItem(const nsAString & key, const nsAString & data) { return _to SetItem(key, data); } \
  NS_IMETHOD RemoveItem(const nsAString & key) { return _to RemoveItem(key); } \
  NS_IMETHOD Clear(void) { return _to Clear(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTORAGE(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD Key(uint32_t index, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Key(index, _retval); } \
  NS_IMETHOD GetItem(const nsAString & key, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItem(key, _retval); } \
  NS_IMETHOD SetItem(const nsAString & key, const nsAString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItem(key, data); } \
  NS_IMETHOD RemoveItem(const nsAString & key) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItem(key); } \
  NS_IMETHOD Clear(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(); } 

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
NS_IMETHODIMP nsDOMStorage::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString key (in unsigned long index); */
NS_IMETHODIMP nsDOMStorage::Key(uint32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getItem ([Null (Stringify)] in DOMString key); */
NS_IMETHODIMP nsDOMStorage::GetItem(const nsAString & key, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setItem ([Null (Stringify)] in DOMString key, [Null (Stringify)] in DOMString data); */
NS_IMETHODIMP nsDOMStorage::SetItem(const nsAString & key, const nsAString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeItem ([Null (Stringify)] in DOMString key); */
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

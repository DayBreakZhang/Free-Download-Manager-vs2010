/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/svg/nsIDOMSVGStringList.idl
 */

#ifndef __gen_nsIDOMSVGStringList_h__
#define __gen_nsIDOMSVGStringList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGStringList */
#define NS_IDOMSVGSTRINGLIST_IID_STR "481f01a5-0bbb-4abf-8623-f3c2fb5642a9"

#define NS_IDOMSVGSTRINGLIST_IID \
  {0x481f01a5, 0x0bbb, 0x4abf, \
    { 0x86, 0x23, 0xf3, 0xc2, 0xfb, 0x56, 0x42, 0xa9 }}

class NS_NO_VTABLE nsIDOMSVGStringList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGSTRINGLIST_IID)

  /* readonly attribute unsigned long numberOfItems; */
  NS_IMETHOD GetNumberOfItems(uint32_t *aNumberOfItems) = 0;

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

  /* void clear (); */
  NS_IMETHOD Clear(void) = 0;

  /* DOMString initialize (in DOMString newItem); */
  NS_IMETHOD Initialize(const nsAString & newItem, nsAString & _retval) = 0;

  /* DOMString getItem (in unsigned long index); */
  NS_IMETHOD GetItem(uint32_t index, nsAString & _retval) = 0;

  /* DOMString insertItemBefore (in DOMString newItem, in unsigned long index); */
  NS_IMETHOD InsertItemBefore(const nsAString & newItem, uint32_t index, nsAString & _retval) = 0;

  /* DOMString replaceItem (in DOMString newItem, in unsigned long index); */
  NS_IMETHOD ReplaceItem(const nsAString & newItem, uint32_t index, nsAString & _retval) = 0;

  /* DOMString removeItem (in unsigned long index); */
  NS_IMETHOD RemoveItem(uint32_t index, nsAString & _retval) = 0;

  /* DOMString appendItem (in DOMString newItem); */
  NS_IMETHOD AppendItem(const nsAString & newItem, nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGStringList, NS_IDOMSVGSTRINGLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGSTRINGLIST \
  NS_IMETHOD GetNumberOfItems(uint32_t *aNumberOfItems); \
  NS_IMETHOD GetLength(uint32_t *aLength); \
  NS_IMETHOD Clear(void); \
  NS_IMETHOD Initialize(const nsAString & newItem, nsAString & _retval); \
  NS_IMETHOD GetItem(uint32_t index, nsAString & _retval); \
  NS_IMETHOD InsertItemBefore(const nsAString & newItem, uint32_t index, nsAString & _retval); \
  NS_IMETHOD ReplaceItem(const nsAString & newItem, uint32_t index, nsAString & _retval); \
  NS_IMETHOD RemoveItem(uint32_t index, nsAString & _retval); \
  NS_IMETHOD AppendItem(const nsAString & newItem, nsAString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGSTRINGLIST(_to) \
  NS_IMETHOD GetNumberOfItems(uint32_t *aNumberOfItems) { return _to GetNumberOfItems(aNumberOfItems); } \
  NS_IMETHOD GetLength(uint32_t *aLength) { return _to GetLength(aLength); } \
  NS_IMETHOD Clear(void) { return _to Clear(); } \
  NS_IMETHOD Initialize(const nsAString & newItem, nsAString & _retval) { return _to Initialize(newItem, _retval); } \
  NS_IMETHOD GetItem(uint32_t index, nsAString & _retval) { return _to GetItem(index, _retval); } \
  NS_IMETHOD InsertItemBefore(const nsAString & newItem, uint32_t index, nsAString & _retval) { return _to InsertItemBefore(newItem, index, _retval); } \
  NS_IMETHOD ReplaceItem(const nsAString & newItem, uint32_t index, nsAString & _retval) { return _to ReplaceItem(newItem, index, _retval); } \
  NS_IMETHOD RemoveItem(uint32_t index, nsAString & _retval) { return _to RemoveItem(index, _retval); } \
  NS_IMETHOD AppendItem(const nsAString & newItem, nsAString & _retval) { return _to AppendItem(newItem, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGSTRINGLIST(_to) \
  NS_IMETHOD GetNumberOfItems(uint32_t *aNumberOfItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumberOfItems(aNumberOfItems); } \
  NS_IMETHOD GetLength(uint32_t *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD Clear(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(); } \
  NS_IMETHOD Initialize(const nsAString & newItem, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Initialize(newItem, _retval); } \
  NS_IMETHOD GetItem(uint32_t index, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItem(index, _retval); } \
  NS_IMETHOD InsertItemBefore(const nsAString & newItem, uint32_t index, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertItemBefore(newItem, index, _retval); } \
  NS_IMETHOD ReplaceItem(const nsAString & newItem, uint32_t index, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceItem(newItem, index, _retval); } \
  NS_IMETHOD RemoveItem(uint32_t index, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItem(index, _retval); } \
  NS_IMETHOD AppendItem(const nsAString & newItem, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendItem(newItem, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGStringList : public nsIDOMSVGStringList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGSTRINGLIST

  nsDOMSVGStringList();

private:
  ~nsDOMSVGStringList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGStringList, nsIDOMSVGStringList)

nsDOMSVGStringList::nsDOMSVGStringList()
{
  /* member initializers and constructor code */
}

nsDOMSVGStringList::~nsDOMSVGStringList()
{
  /* destructor code */
}

/* readonly attribute unsigned long numberOfItems; */
NS_IMETHODIMP nsDOMSVGStringList::GetNumberOfItems(uint32_t *aNumberOfItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMSVGStringList::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clear (); */
NS_IMETHODIMP nsDOMSVGStringList::Clear()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString initialize (in DOMString newItem); */
NS_IMETHODIMP nsDOMSVGStringList::Initialize(const nsAString & newItem, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getItem (in unsigned long index); */
NS_IMETHODIMP nsDOMSVGStringList::GetItem(uint32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString insertItemBefore (in DOMString newItem, in unsigned long index); */
NS_IMETHODIMP nsDOMSVGStringList::InsertItemBefore(const nsAString & newItem, uint32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString replaceItem (in DOMString newItem, in unsigned long index); */
NS_IMETHODIMP nsDOMSVGStringList::ReplaceItem(const nsAString & newItem, uint32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString removeItem (in unsigned long index); */
NS_IMETHODIMP nsDOMSVGStringList::RemoveItem(uint32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString appendItem (in DOMString newItem); */
NS_IMETHODIMP nsDOMSVGStringList::AppendItem(const nsAString & newItem, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGStringList_h__ */

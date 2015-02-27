/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMHTMLCollection.idl
 */

#ifndef __gen_nsIDOMHTMLCollection_h__
#define __gen_nsIDOMHTMLCollection_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLCollection */
#define NS_IDOMHTMLCOLLECTION_IID_STR "bb07f567-5b37-4172-92aa-7d00ceed4809"

#define NS_IDOMHTMLCOLLECTION_IID \
  {0xbb07f567, 0x5b37, 0x4172, \
    { 0x92, 0xaa, 0x7d, 0x00, 0xce, 0xed, 0x48, 0x09 }}

class NS_NO_VTABLE nsIDOMHTMLCollection : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLCOLLECTION_IID)

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

  /* nsIDOMNode item (in unsigned long index); */
  NS_IMETHOD Item(uint32_t index, nsIDOMNode * *_retval) = 0;

  /* nsIDOMNode namedItem (in DOMString name); */
  NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLCollection, NS_IDOMHTMLCOLLECTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLCOLLECTION \
  NS_IMETHOD GetLength(uint32_t *aLength); \
  NS_IMETHOD Item(uint32_t index, nsIDOMNode * *_retval); \
  NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLCOLLECTION(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) { return _to GetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsIDOMNode * *_retval) { return _to Item(index, _retval); } \
  NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode * *_retval) { return _to NamedItem(name, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLCOLLECTION(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsIDOMNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } \
  NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NamedItem(name, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLCollection : public nsIDOMHTMLCollection
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLCOLLECTION

  nsDOMHTMLCollection();

private:
  ~nsDOMHTMLCollection();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLCollection, nsIDOMHTMLCollection)

nsDOMHTMLCollection::nsDOMHTMLCollection()
{
  /* member initializers and constructor code */
}

nsDOMHTMLCollection::~nsDOMHTMLCollection()
{
  /* destructor code */
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMHTMLCollection::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode item (in unsigned long index); */
NS_IMETHODIMP nsDOMHTMLCollection::Item(uint32_t index, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode namedItem (in DOMString name); */
NS_IMETHODIMP nsDOMHTMLCollection::NamedItem(const nsAString & name, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLCollection_h__ */

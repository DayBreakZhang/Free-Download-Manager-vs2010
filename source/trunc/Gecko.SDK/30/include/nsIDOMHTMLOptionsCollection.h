/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMHTMLOptionsCollection.idl
 */

#ifndef __gen_nsIDOMHTMLOptionsCollection_h__
#define __gen_nsIDOMHTMLOptionsCollection_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

#ifndef __gen_nsIDOMHTMLCollection_h__
#include "nsIDOMHTMLCollection.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMHTMLOptionElement; /* forward declaration */

class nsIDOMHTMLSelectElement; /* forward declaration */


/* starting interface:    nsIDOMHTMLOptionsCollection */
#define NS_IDOMHTMLOPTIONSCOLLECTION_IID_STR "4173cc53-30f6-4d12-a770-981ba53164e2"

#define NS_IDOMHTMLOPTIONSCOLLECTION_IID \
  {0x4173cc53, 0x30f6, 0x4d12, \
    { 0xa7, 0x70, 0x98, 0x1b, 0xa5, 0x31, 0x64, 0xe2 }}

class NS_NO_VTABLE nsIDOMHTMLOptionsCollection : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLOPTIONSCOLLECTION_IID)

  /* attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;
  NS_IMETHOD SetLength(uint32_t aLength) = 0;

  /* nsIDOMNode item (in unsigned long index); */
  NS_IMETHOD Item(uint32_t index, nsIDOMNode * *_retval) = 0;

  /* nsIDOMNode namedItem (in DOMString name); */
  NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode * *_retval) = 0;

  /* attribute long selectedIndex; */
  NS_IMETHOD GetSelectedIndex(int32_t *aSelectedIndex) = 0;
  NS_IMETHOD SetSelectedIndex(int32_t aSelectedIndex) = 0;

  /* [noscript] void setOption (in unsigned long index, in nsIDOMHTMLOptionElement option); */
  NS_IMETHOD SetOption(uint32_t index, nsIDOMHTMLOptionElement *option) = 0;

  /* [noscript] readonly attribute nsIDOMHTMLSelectElement select; */
  NS_IMETHOD GetSelect(nsIDOMHTMLSelectElement * *aSelect) = 0;

  /* void add (in nsIDOMHTMLOptionElement option, [optional] in nsIVariant before); */
  NS_IMETHOD Add(nsIDOMHTMLOptionElement *option, nsIVariant *before) = 0;

  /* void remove (in long index); */
  NS_IMETHOD Remove(int32_t index) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLOptionsCollection, NS_IDOMHTMLOPTIONSCOLLECTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLOPTIONSCOLLECTION \
  NS_IMETHOD GetLength(uint32_t *aLength); \
  NS_IMETHOD SetLength(uint32_t aLength); \
  NS_IMETHOD Item(uint32_t index, nsIDOMNode * *_retval); \
  NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode * *_retval); \
  NS_IMETHOD GetSelectedIndex(int32_t *aSelectedIndex); \
  NS_IMETHOD SetSelectedIndex(int32_t aSelectedIndex); \
  NS_IMETHOD SetOption(uint32_t index, nsIDOMHTMLOptionElement *option); \
  NS_IMETHOD GetSelect(nsIDOMHTMLSelectElement * *aSelect); \
  NS_IMETHOD Add(nsIDOMHTMLOptionElement *option, nsIVariant *before); \
  NS_IMETHOD Remove(int32_t index); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLOPTIONSCOLLECTION(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) { return _to GetLength(aLength); } \
  NS_IMETHOD SetLength(uint32_t aLength) { return _to SetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsIDOMNode * *_retval) { return _to Item(index, _retval); } \
  NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode * *_retval) { return _to NamedItem(name, _retval); } \
  NS_IMETHOD GetSelectedIndex(int32_t *aSelectedIndex) { return _to GetSelectedIndex(aSelectedIndex); } \
  NS_IMETHOD SetSelectedIndex(int32_t aSelectedIndex) { return _to SetSelectedIndex(aSelectedIndex); } \
  NS_IMETHOD SetOption(uint32_t index, nsIDOMHTMLOptionElement *option) { return _to SetOption(index, option); } \
  NS_IMETHOD GetSelect(nsIDOMHTMLSelectElement * *aSelect) { return _to GetSelect(aSelect); } \
  NS_IMETHOD Add(nsIDOMHTMLOptionElement *option, nsIVariant *before) { return _to Add(option, before); } \
  NS_IMETHOD Remove(int32_t index) { return _to Remove(index); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLOPTIONSCOLLECTION(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD SetLength(uint32_t aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsIDOMNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } \
  NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NamedItem(name, _retval); } \
  NS_IMETHOD GetSelectedIndex(int32_t *aSelectedIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedIndex(aSelectedIndex); } \
  NS_IMETHOD SetSelectedIndex(int32_t aSelectedIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectedIndex(aSelectedIndex); } \
  NS_IMETHOD SetOption(uint32_t index, nsIDOMHTMLOptionElement *option) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOption(index, option); } \
  NS_IMETHOD GetSelect(nsIDOMHTMLSelectElement * *aSelect) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelect(aSelect); } \
  NS_IMETHOD Add(nsIDOMHTMLOptionElement *option, nsIVariant *before) { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(option, before); } \
  NS_IMETHOD Remove(int32_t index) { return !_to ? NS_ERROR_NULL_POINTER : _to->Remove(index); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLOptionsCollection : public nsIDOMHTMLOptionsCollection
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLOPTIONSCOLLECTION

  nsDOMHTMLOptionsCollection();

private:
  ~nsDOMHTMLOptionsCollection();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLOptionsCollection, nsIDOMHTMLOptionsCollection)

nsDOMHTMLOptionsCollection::nsDOMHTMLOptionsCollection()
{
  /* member initializers and constructor code */
}

nsDOMHTMLOptionsCollection::~nsDOMHTMLOptionsCollection()
{
  /* destructor code */
}

/* attribute unsigned long length; */
NS_IMETHODIMP nsDOMHTMLOptionsCollection::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLOptionsCollection::SetLength(uint32_t aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode item (in unsigned long index); */
NS_IMETHODIMP nsDOMHTMLOptionsCollection::Item(uint32_t index, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode namedItem (in DOMString name); */
NS_IMETHODIMP nsDOMHTMLOptionsCollection::NamedItem(const nsAString & name, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long selectedIndex; */
NS_IMETHODIMP nsDOMHTMLOptionsCollection::GetSelectedIndex(int32_t *aSelectedIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLOptionsCollection::SetSelectedIndex(int32_t aSelectedIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setOption (in unsigned long index, in nsIDOMHTMLOptionElement option); */
NS_IMETHODIMP nsDOMHTMLOptionsCollection::SetOption(uint32_t index, nsIDOMHTMLOptionElement *option)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIDOMHTMLSelectElement select; */
NS_IMETHODIMP nsDOMHTMLOptionsCollection::GetSelect(nsIDOMHTMLSelectElement * *aSelect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void add (in nsIDOMHTMLOptionElement option, [optional] in nsIVariant before); */
NS_IMETHODIMP nsDOMHTMLOptionsCollection::Add(nsIDOMHTMLOptionElement *option, nsIVariant *before)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void remove (in long index); */
NS_IMETHODIMP nsDOMHTMLOptionsCollection::Remove(int32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLOptionsCollection_h__ */

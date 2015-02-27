/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/base/nsIDOMPluginArray.idl
 */

#ifndef __gen_nsIDOMPluginArray_h__
#define __gen_nsIDOMPluginArray_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMPluginArray */
#define NS_IDOMPLUGINARRAY_IID_STR "f6134680-f28b-11d2-8360-c90899049c3c"

#define NS_IDOMPLUGINARRAY_IID \
  {0xf6134680, 0xf28b, 0x11d2, \
    { 0x83, 0x60, 0xc9, 0x08, 0x99, 0x04, 0x9c, 0x3c }}

class NS_NO_VTABLE nsIDOMPluginArray : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMPLUGINARRAY_IID)

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

  /* nsIDOMPlugin item (in unsigned long index); */
  NS_IMETHOD Item(uint32_t index, nsIDOMPlugin * *_retval) = 0;

  /* nsIDOMPlugin namedItem (in DOMString name); */
  NS_IMETHOD NamedItem(const nsAString & name, nsIDOMPlugin * *_retval) = 0;

  /* void refresh ([optional] in boolean reloadDocuments); */
  NS_IMETHOD Refresh(bool reloadDocuments) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMPluginArray, NS_IDOMPLUGINARRAY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMPLUGINARRAY \
  NS_IMETHOD GetLength(uint32_t *aLength); \
  NS_IMETHOD Item(uint32_t index, nsIDOMPlugin * *_retval); \
  NS_IMETHOD NamedItem(const nsAString & name, nsIDOMPlugin * *_retval); \
  NS_IMETHOD Refresh(bool reloadDocuments); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMPLUGINARRAY(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) { return _to GetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsIDOMPlugin * *_retval) { return _to Item(index, _retval); } \
  NS_IMETHOD NamedItem(const nsAString & name, nsIDOMPlugin * *_retval) { return _to NamedItem(name, _retval); } \
  NS_IMETHOD Refresh(bool reloadDocuments) { return _to Refresh(reloadDocuments); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMPLUGINARRAY(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsIDOMPlugin * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } \
  NS_IMETHOD NamedItem(const nsAString & name, nsIDOMPlugin * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NamedItem(name, _retval); } \
  NS_IMETHOD Refresh(bool reloadDocuments) { return !_to ? NS_ERROR_NULL_POINTER : _to->Refresh(reloadDocuments); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMPluginArray : public nsIDOMPluginArray
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMPLUGINARRAY

  nsDOMPluginArray();

private:
  ~nsDOMPluginArray();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMPluginArray, nsIDOMPluginArray)

nsDOMPluginArray::nsDOMPluginArray()
{
  /* member initializers and constructor code */
}

nsDOMPluginArray::~nsDOMPluginArray()
{
  /* destructor code */
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMPluginArray::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMPlugin item (in unsigned long index); */
NS_IMETHODIMP nsDOMPluginArray::Item(uint32_t index, nsIDOMPlugin * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMPlugin namedItem (in DOMString name); */
NS_IMETHODIMP nsDOMPluginArray::NamedItem(const nsAString & name, nsIDOMPlugin * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void refresh ([optional] in boolean reloadDocuments); */
NS_IMETHODIMP nsDOMPluginArray::Refresh(bool reloadDocuments)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMPluginArray_h__ */

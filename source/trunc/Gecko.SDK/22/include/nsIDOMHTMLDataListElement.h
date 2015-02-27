/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLDataListElement.idl
 */

#ifndef __gen_nsIDOMHTMLDataListElement_h__
#define __gen_nsIDOMHTMLDataListElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMHTMLCollection; /* forward declaration */


/* starting interface:    nsIDOMHTMLDataListElement */
#define NS_IDOMHTMLDATALISTELEMENT_IID_STR "87ea361b-fe0f-486b-a891-7686dadd6372"

#define NS_IDOMHTMLDATALISTELEMENT_IID \
  {0x87ea361b, 0xfe0f, 0x486b, \
    { 0xa8, 0x91, 0x76, 0x86, 0xda, 0xdd, 0x63, 0x72 }}

class NS_NO_VTABLE nsIDOMHTMLDataListElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLDATALISTELEMENT_IID)

  /* readonly attribute nsIDOMHTMLCollection options; */
  NS_IMETHOD GetOptions(nsIDOMHTMLCollection * *aOptions) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLDataListElement, NS_IDOMHTMLDATALISTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLDATALISTELEMENT \
  NS_IMETHOD GetOptions(nsIDOMHTMLCollection * *aOptions); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLDATALISTELEMENT(_to) \
  NS_IMETHOD GetOptions(nsIDOMHTMLCollection * *aOptions) { return _to GetOptions(aOptions); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLDATALISTELEMENT(_to) \
  NS_IMETHOD GetOptions(nsIDOMHTMLCollection * *aOptions) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOptions(aOptions); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLDataListElement : public nsIDOMHTMLDataListElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLDATALISTELEMENT

  nsDOMHTMLDataListElement();

private:
  ~nsDOMHTMLDataListElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLDataListElement, nsIDOMHTMLDataListElement)

nsDOMHTMLDataListElement::nsDOMHTMLDataListElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLDataListElement::~nsDOMHTMLDataListElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMHTMLCollection options; */
NS_IMETHODIMP nsDOMHTMLDataListElement::GetOptions(nsIDOMHTMLCollection * *aOptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLDataListElement_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLUListElement.idl
 */

#ifndef __gen_nsIDOMHTMLUListElement_h__
#define __gen_nsIDOMHTMLUListElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLUListElement */
#define NS_IDOMHTMLULISTELEMENT_IID_STR "edb972d4-82b0-4be6-9145-caeb5d99a4ae"

#define NS_IDOMHTMLULISTELEMENT_IID \
  {0xedb972d4, 0x82b0, 0x4be6, \
    { 0x91, 0x45, 0xca, 0xeb, 0x5d, 0x99, 0xa4, 0xae }}

class NS_NO_VTABLE nsIDOMHTMLUListElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLULISTELEMENT_IID)

  /* attribute boolean compact; */
  NS_IMETHOD GetCompact(bool *aCompact) = 0;
  NS_IMETHOD SetCompact(bool aCompact) = 0;

  /* attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_IMETHOD SetType(const nsAString & aType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLUListElement, NS_IDOMHTMLULISTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLULISTELEMENT \
  NS_IMETHOD GetCompact(bool *aCompact); \
  NS_IMETHOD SetCompact(bool aCompact); \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD SetType(const nsAString & aType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLULISTELEMENT(_to) \
  NS_IMETHOD GetCompact(bool *aCompact) { return _to GetCompact(aCompact); } \
  NS_IMETHOD SetCompact(bool aCompact) { return _to SetCompact(aCompact); } \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLULISTELEMENT(_to) \
  NS_IMETHOD GetCompact(bool *aCompact) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCompact(aCompact); } \
  NS_IMETHOD SetCompact(bool aCompact) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCompact(aCompact); } \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLUListElement : public nsIDOMHTMLUListElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLULISTELEMENT

  nsDOMHTMLUListElement();

private:
  ~nsDOMHTMLUListElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLUListElement, nsIDOMHTMLUListElement)

nsDOMHTMLUListElement::nsDOMHTMLUListElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLUListElement::~nsDOMHTMLUListElement()
{
  /* destructor code */
}

/* attribute boolean compact; */
NS_IMETHODIMP nsDOMHTMLUListElement::GetCompact(bool *aCompact)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLUListElement::SetCompact(bool aCompact)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMHTMLUListElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLUListElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLUListElement_h__ */

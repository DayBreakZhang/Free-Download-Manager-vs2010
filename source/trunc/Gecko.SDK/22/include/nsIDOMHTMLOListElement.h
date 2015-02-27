/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLOListElement.idl
 */

#ifndef __gen_nsIDOMHTMLOListElement_h__
#define __gen_nsIDOMHTMLOListElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLOListElement */
#define NS_IDOMHTMLOLISTELEMENT_IID_STR "d94ba4eb-a154-4abf-9868-105905e995e4"

#define NS_IDOMHTMLOLISTELEMENT_IID \
  {0xd94ba4eb, 0xa154, 0x4abf, \
    { 0x98, 0x68, 0x10, 0x59, 0x05, 0xe9, 0x95, 0xe4 }}

class NS_NO_VTABLE nsIDOMHTMLOListElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLOLISTELEMENT_IID)

  /* attribute boolean compact; */
  NS_IMETHOD GetCompact(bool *aCompact) = 0;
  NS_IMETHOD SetCompact(bool aCompact) = 0;

  /* attribute boolean reversed; */
  NS_IMETHOD GetReversed(bool *aReversed) = 0;
  NS_IMETHOD SetReversed(bool aReversed) = 0;

  /* attribute long start; */
  NS_IMETHOD GetStart(int32_t *aStart) = 0;
  NS_IMETHOD SetStart(int32_t aStart) = 0;

  /* attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_IMETHOD SetType(const nsAString & aType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLOListElement, NS_IDOMHTMLOLISTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLOLISTELEMENT \
  NS_IMETHOD GetCompact(bool *aCompact); \
  NS_IMETHOD SetCompact(bool aCompact); \
  NS_IMETHOD GetReversed(bool *aReversed); \
  NS_IMETHOD SetReversed(bool aReversed); \
  NS_IMETHOD GetStart(int32_t *aStart); \
  NS_IMETHOD SetStart(int32_t aStart); \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD SetType(const nsAString & aType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLOLISTELEMENT(_to) \
  NS_IMETHOD GetCompact(bool *aCompact) { return _to GetCompact(aCompact); } \
  NS_IMETHOD SetCompact(bool aCompact) { return _to SetCompact(aCompact); } \
  NS_IMETHOD GetReversed(bool *aReversed) { return _to GetReversed(aReversed); } \
  NS_IMETHOD SetReversed(bool aReversed) { return _to SetReversed(aReversed); } \
  NS_IMETHOD GetStart(int32_t *aStart) { return _to GetStart(aStart); } \
  NS_IMETHOD SetStart(int32_t aStart) { return _to SetStart(aStart); } \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLOLISTELEMENT(_to) \
  NS_IMETHOD GetCompact(bool *aCompact) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCompact(aCompact); } \
  NS_IMETHOD SetCompact(bool aCompact) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCompact(aCompact); } \
  NS_IMETHOD GetReversed(bool *aReversed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReversed(aReversed); } \
  NS_IMETHOD SetReversed(bool aReversed) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReversed(aReversed); } \
  NS_IMETHOD GetStart(int32_t *aStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStart(aStart); } \
  NS_IMETHOD SetStart(int32_t aStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStart(aStart); } \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLOListElement : public nsIDOMHTMLOListElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLOLISTELEMENT

  nsDOMHTMLOListElement();

private:
  ~nsDOMHTMLOListElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLOListElement, nsIDOMHTMLOListElement)

nsDOMHTMLOListElement::nsDOMHTMLOListElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLOListElement::~nsDOMHTMLOListElement()
{
  /* destructor code */
}

/* attribute boolean compact; */
NS_IMETHODIMP nsDOMHTMLOListElement::GetCompact(bool *aCompact)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLOListElement::SetCompact(bool aCompact)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean reversed; */
NS_IMETHODIMP nsDOMHTMLOListElement::GetReversed(bool *aReversed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLOListElement::SetReversed(bool aReversed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long start; */
NS_IMETHODIMP nsDOMHTMLOListElement::GetStart(int32_t *aStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLOListElement::SetStart(int32_t aStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMHTMLOListElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLOListElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLOListElement_h__ */

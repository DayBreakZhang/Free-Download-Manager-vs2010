/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLTableColElement.idl
 */

#ifndef __gen_nsIDOMHTMLTableColElement_h__
#define __gen_nsIDOMHTMLTableColElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLTableColElement */
#define NS_IDOMHTMLTABLECOLELEMENT_IID_STR "f38fe6c8-9dfd-4c24-aeab-352459383d67"

#define NS_IDOMHTMLTABLECOLELEMENT_IID \
  {0xf38fe6c8, 0x9dfd, 0x4c24, \
    { 0xae, 0xab, 0x35, 0x24, 0x59, 0x38, 0x3d, 0x67 }}

class NS_NO_VTABLE nsIDOMHTMLTableColElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLTABLECOLELEMENT_IID)

  /* attribute DOMString align; */
  NS_IMETHOD GetAlign(nsAString & aAlign) = 0;
  NS_IMETHOD SetAlign(const nsAString & aAlign) = 0;

  /* attribute DOMString ch; */
  NS_IMETHOD GetCh(nsAString & aCh) = 0;
  NS_IMETHOD SetCh(const nsAString & aCh) = 0;

  /* attribute DOMString chOff; */
  NS_IMETHOD GetChOff(nsAString & aChOff) = 0;
  NS_IMETHOD SetChOff(const nsAString & aChOff) = 0;

  /* attribute long span; */
  NS_IMETHOD GetSpan(int32_t *aSpan) = 0;
  NS_IMETHOD SetSpan(int32_t aSpan) = 0;

  /* attribute DOMString vAlign; */
  NS_IMETHOD GetVAlign(nsAString & aVAlign) = 0;
  NS_IMETHOD SetVAlign(const nsAString & aVAlign) = 0;

  /* attribute DOMString width; */
  NS_IMETHOD GetWidth(nsAString & aWidth) = 0;
  NS_IMETHOD SetWidth(const nsAString & aWidth) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLTableColElement, NS_IDOMHTMLTABLECOLELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLTABLECOLELEMENT \
  NS_IMETHOD GetAlign(nsAString & aAlign); \
  NS_IMETHOD SetAlign(const nsAString & aAlign); \
  NS_IMETHOD GetCh(nsAString & aCh); \
  NS_IMETHOD SetCh(const nsAString & aCh); \
  NS_IMETHOD GetChOff(nsAString & aChOff); \
  NS_IMETHOD SetChOff(const nsAString & aChOff); \
  NS_IMETHOD GetSpan(int32_t *aSpan); \
  NS_IMETHOD SetSpan(int32_t aSpan); \
  NS_IMETHOD GetVAlign(nsAString & aVAlign); \
  NS_IMETHOD SetVAlign(const nsAString & aVAlign); \
  NS_IMETHOD GetWidth(nsAString & aWidth); \
  NS_IMETHOD SetWidth(const nsAString & aWidth); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLTABLECOLELEMENT(_to) \
  NS_IMETHOD GetAlign(nsAString & aAlign) { return _to GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) { return _to SetAlign(aAlign); } \
  NS_IMETHOD GetCh(nsAString & aCh) { return _to GetCh(aCh); } \
  NS_IMETHOD SetCh(const nsAString & aCh) { return _to SetCh(aCh); } \
  NS_IMETHOD GetChOff(nsAString & aChOff) { return _to GetChOff(aChOff); } \
  NS_IMETHOD SetChOff(const nsAString & aChOff) { return _to SetChOff(aChOff); } \
  NS_IMETHOD GetSpan(int32_t *aSpan) { return _to GetSpan(aSpan); } \
  NS_IMETHOD SetSpan(int32_t aSpan) { return _to SetSpan(aSpan); } \
  NS_IMETHOD GetVAlign(nsAString & aVAlign) { return _to GetVAlign(aVAlign); } \
  NS_IMETHOD SetVAlign(const nsAString & aVAlign) { return _to SetVAlign(aVAlign); } \
  NS_IMETHOD GetWidth(nsAString & aWidth) { return _to GetWidth(aWidth); } \
  NS_IMETHOD SetWidth(const nsAString & aWidth) { return _to SetWidth(aWidth); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLTABLECOLELEMENT(_to) \
  NS_IMETHOD GetAlign(nsAString & aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlign(aAlign); } \
  NS_IMETHOD GetCh(nsAString & aCh) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCh(aCh); } \
  NS_IMETHOD SetCh(const nsAString & aCh) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCh(aCh); } \
  NS_IMETHOD GetChOff(nsAString & aChOff) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChOff(aChOff); } \
  NS_IMETHOD SetChOff(const nsAString & aChOff) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChOff(aChOff); } \
  NS_IMETHOD GetSpan(int32_t *aSpan) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSpan(aSpan); } \
  NS_IMETHOD SetSpan(int32_t aSpan) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSpan(aSpan); } \
  NS_IMETHOD GetVAlign(nsAString & aVAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVAlign(aVAlign); } \
  NS_IMETHOD SetVAlign(const nsAString & aVAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVAlign(aVAlign); } \
  NS_IMETHOD GetWidth(nsAString & aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD SetWidth(const nsAString & aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWidth(aWidth); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLTableColElement : public nsIDOMHTMLTableColElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLTABLECOLELEMENT

  nsDOMHTMLTableColElement();

private:
  ~nsDOMHTMLTableColElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLTableColElement, nsIDOMHTMLTableColElement)

nsDOMHTMLTableColElement::nsDOMHTMLTableColElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLTableColElement::~nsDOMHTMLTableColElement()
{
  /* destructor code */
}

/* attribute DOMString align; */
NS_IMETHODIMP nsDOMHTMLTableColElement::GetAlign(nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLTableColElement::SetAlign(const nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString ch; */
NS_IMETHODIMP nsDOMHTMLTableColElement::GetCh(nsAString & aCh)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLTableColElement::SetCh(const nsAString & aCh)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString chOff; */
NS_IMETHODIMP nsDOMHTMLTableColElement::GetChOff(nsAString & aChOff)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLTableColElement::SetChOff(const nsAString & aChOff)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long span; */
NS_IMETHODIMP nsDOMHTMLTableColElement::GetSpan(int32_t *aSpan)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLTableColElement::SetSpan(int32_t aSpan)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString vAlign; */
NS_IMETHODIMP nsDOMHTMLTableColElement::GetVAlign(nsAString & aVAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLTableColElement::SetVAlign(const nsAString & aVAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString width; */
NS_IMETHODIMP nsDOMHTMLTableColElement::GetWidth(nsAString & aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLTableColElement::SetWidth(const nsAString & aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLTableColElement_h__ */

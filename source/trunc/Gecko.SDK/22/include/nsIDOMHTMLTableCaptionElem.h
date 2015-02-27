/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLTableCaptionElem.idl
 */

#ifndef __gen_nsIDOMHTMLTableCaptionElem_h__
#define __gen_nsIDOMHTMLTableCaptionElem_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLTableCaptionElement */
#define NS_IDOMHTMLTABLECAPTIONELEMENT_IID_STR "310ebe52-7377-4fc4-9546-a6f4dcaafa1f"

#define NS_IDOMHTMLTABLECAPTIONELEMENT_IID \
  {0x310ebe52, 0x7377, 0x4fc4, \
    { 0x95, 0x46, 0xa6, 0xf4, 0xdc, 0xaa, 0xfa, 0x1f }}

class NS_NO_VTABLE nsIDOMHTMLTableCaptionElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLTABLECAPTIONELEMENT_IID)

  /* attribute DOMString align; */
  NS_IMETHOD GetAlign(nsAString & aAlign) = 0;
  NS_IMETHOD SetAlign(const nsAString & aAlign) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLTableCaptionElement, NS_IDOMHTMLTABLECAPTIONELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLTABLECAPTIONELEMENT \
  NS_IMETHOD GetAlign(nsAString & aAlign); \
  NS_IMETHOD SetAlign(const nsAString & aAlign); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLTABLECAPTIONELEMENT(_to) \
  NS_IMETHOD GetAlign(nsAString & aAlign) { return _to GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) { return _to SetAlign(aAlign); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLTABLECAPTIONELEMENT(_to) \
  NS_IMETHOD GetAlign(nsAString & aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlign(aAlign); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLTableCaptionElement : public nsIDOMHTMLTableCaptionElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLTABLECAPTIONELEMENT

  nsDOMHTMLTableCaptionElement();

private:
  ~nsDOMHTMLTableCaptionElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLTableCaptionElement, nsIDOMHTMLTableCaptionElement)

nsDOMHTMLTableCaptionElement::nsDOMHTMLTableCaptionElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLTableCaptionElement::~nsDOMHTMLTableCaptionElement()
{
  /* destructor code */
}

/* attribute DOMString align; */
NS_IMETHODIMP nsDOMHTMLTableCaptionElement::GetAlign(nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLTableCaptionElement::SetAlign(const nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLTableCaptionElem_h__ */

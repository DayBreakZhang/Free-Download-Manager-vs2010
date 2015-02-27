/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLLegendElement.idl
 */

#ifndef __gen_nsIDOMHTMLLegendElement_h__
#define __gen_nsIDOMHTMLLegendElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLLegendElement */
#define NS_IDOMHTMLLEGENDELEMENT_IID_STR "42f1c264-d2b1-4f50-95cf-929ae2ea4c52"

#define NS_IDOMHTMLLEGENDELEMENT_IID \
  {0x42f1c264, 0xd2b1, 0x4f50, \
    { 0x95, 0xcf, 0x92, 0x9a, 0xe2, 0xea, 0x4c, 0x52 }}

class NS_NO_VTABLE nsIDOMHTMLLegendElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLLEGENDELEMENT_IID)

  /* readonly attribute nsIDOMHTMLFormElement form; */
  NS_IMETHOD GetForm(nsIDOMHTMLFormElement * *aForm) = 0;

  /* attribute DOMString align; */
  NS_IMETHOD GetAlign(nsAString & aAlign) = 0;
  NS_IMETHOD SetAlign(const nsAString & aAlign) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLLegendElement, NS_IDOMHTMLLEGENDELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLLEGENDELEMENT \
  NS_IMETHOD GetForm(nsIDOMHTMLFormElement * *aForm); \
  NS_IMETHOD GetAlign(nsAString & aAlign); \
  NS_IMETHOD SetAlign(const nsAString & aAlign); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLLEGENDELEMENT(_to) \
  NS_IMETHOD GetForm(nsIDOMHTMLFormElement * *aForm) { return _to GetForm(aForm); } \
  NS_IMETHOD GetAlign(nsAString & aAlign) { return _to GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) { return _to SetAlign(aAlign); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLLEGENDELEMENT(_to) \
  NS_IMETHOD GetForm(nsIDOMHTMLFormElement * *aForm) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForm(aForm); } \
  NS_IMETHOD GetAlign(nsAString & aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlign(aAlign); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLLegendElement : public nsIDOMHTMLLegendElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLLEGENDELEMENT

  nsDOMHTMLLegendElement();

private:
  ~nsDOMHTMLLegendElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLLegendElement, nsIDOMHTMLLegendElement)

nsDOMHTMLLegendElement::nsDOMHTMLLegendElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLLegendElement::~nsDOMHTMLLegendElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMHTMLFormElement form; */
NS_IMETHODIMP nsDOMHTMLLegendElement::GetForm(nsIDOMHTMLFormElement * *aForm)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString align; */
NS_IMETHODIMP nsDOMHTMLLegendElement::GetAlign(nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLLegendElement::SetAlign(const nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLLegendElement_h__ */

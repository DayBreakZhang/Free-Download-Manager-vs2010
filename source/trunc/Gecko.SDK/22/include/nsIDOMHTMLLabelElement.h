/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLLabelElement.idl
 */

#ifndef __gen_nsIDOMHTMLLabelElement_h__
#define __gen_nsIDOMHTMLLabelElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLLabelElement */
#define NS_IDOMHTMLLABELELEMENT_IID_STR "02024255-6b9e-445f-971e-ac71ed091a64"

#define NS_IDOMHTMLLABELELEMENT_IID \
  {0x02024255, 0x6b9e, 0x445f, \
    { 0x97, 0x1e, 0xac, 0x71, 0xed, 0x09, 0x1a, 0x64 }}

class NS_NO_VTABLE nsIDOMHTMLLabelElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLLABELELEMENT_IID)

  /* readonly attribute nsIDOMHTMLFormElement form; */
  NS_IMETHOD GetForm(nsIDOMHTMLFormElement * *aForm) = 0;

  /* attribute DOMString htmlFor; */
  NS_IMETHOD GetHtmlFor(nsAString & aHtmlFor) = 0;
  NS_IMETHOD SetHtmlFor(const nsAString & aHtmlFor) = 0;

  /* readonly attribute nsIDOMHTMLElement control; */
  NS_IMETHOD GetControl(nsIDOMHTMLElement * *aControl) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLLabelElement, NS_IDOMHTMLLABELELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLLABELELEMENT \
  NS_IMETHOD GetForm(nsIDOMHTMLFormElement * *aForm); \
  NS_IMETHOD GetHtmlFor(nsAString & aHtmlFor); \
  NS_IMETHOD SetHtmlFor(const nsAString & aHtmlFor); \
  NS_IMETHOD GetControl(nsIDOMHTMLElement * *aControl); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLLABELELEMENT(_to) \
  NS_IMETHOD GetForm(nsIDOMHTMLFormElement * *aForm) { return _to GetForm(aForm); } \
  NS_IMETHOD GetHtmlFor(nsAString & aHtmlFor) { return _to GetHtmlFor(aHtmlFor); } \
  NS_IMETHOD SetHtmlFor(const nsAString & aHtmlFor) { return _to SetHtmlFor(aHtmlFor); } \
  NS_IMETHOD GetControl(nsIDOMHTMLElement * *aControl) { return _to GetControl(aControl); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLLABELELEMENT(_to) \
  NS_IMETHOD GetForm(nsIDOMHTMLFormElement * *aForm) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForm(aForm); } \
  NS_IMETHOD GetHtmlFor(nsAString & aHtmlFor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHtmlFor(aHtmlFor); } \
  NS_IMETHOD SetHtmlFor(const nsAString & aHtmlFor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHtmlFor(aHtmlFor); } \
  NS_IMETHOD GetControl(nsIDOMHTMLElement * *aControl) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetControl(aControl); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLLabelElement : public nsIDOMHTMLLabelElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLLABELELEMENT

  nsDOMHTMLLabelElement();

private:
  ~nsDOMHTMLLabelElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLLabelElement, nsIDOMHTMLLabelElement)

nsDOMHTMLLabelElement::nsDOMHTMLLabelElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLLabelElement::~nsDOMHTMLLabelElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMHTMLFormElement form; */
NS_IMETHODIMP nsDOMHTMLLabelElement::GetForm(nsIDOMHTMLFormElement * *aForm)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString htmlFor; */
NS_IMETHODIMP nsDOMHTMLLabelElement::GetHtmlFor(nsAString & aHtmlFor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLLabelElement::SetHtmlFor(const nsAString & aHtmlFor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLElement control; */
NS_IMETHODIMP nsDOMHTMLLabelElement::GetControl(nsIDOMHTMLElement * *aControl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLLabelElement_h__ */

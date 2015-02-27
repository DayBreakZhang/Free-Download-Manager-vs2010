/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/html/nsIDOMHTMLLabelElement.idl
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
#define NS_IDOMHTMLLABELELEMENT_IID_STR "8a207452-e725-4a9e-beb6-9e0c0a65012c"

#define NS_IDOMHTMLLABELELEMENT_IID \
  {0x8a207452, 0xe725, 0x4a9e, \
    { 0xbe, 0xb6, 0x9e, 0x0c, 0x0a, 0x65, 0x01, 0x2c }}

/**
 * The nsIDOMHTMLLabelElement interface is the interface to a [X]HTML
 * label element.
 *
 * This interface is trying to follow the DOM Level 2 HTML specification:
 * http://www.w3.org/TR/DOM-Level-2-HTML/
 *
 * with changes from the work-in-progress WHATWG HTML specification:
 * http://www.whatwg.org/specs/web-apps/current-work/
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLLabelElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLLABELELEMENT_IID)

  /* readonly attribute nsIDOMHTMLFormElement form; */
  NS_SCRIPTABLE NS_IMETHOD GetForm(nsIDOMHTMLFormElement **aForm) = 0;

  /* attribute DOMString htmlFor; */
  NS_SCRIPTABLE NS_IMETHOD GetHtmlFor(nsAString & aHtmlFor) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHtmlFor(const nsAString & aHtmlFor) = 0;

  /* readonly attribute nsIDOMHTMLElement control; */
  NS_SCRIPTABLE NS_IMETHOD GetControl(nsIDOMHTMLElement **aControl) = 0;

  /* attribute DOMString accessKey; */
  NS_SCRIPTABLE NS_IMETHOD GetAccessKey(nsAString & aAccessKey) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLLabelElement, NS_IDOMHTMLLABELELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLLABELELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetForm(nsIDOMHTMLFormElement **aForm); \
  NS_SCRIPTABLE NS_IMETHOD GetHtmlFor(nsAString & aHtmlFor); \
  NS_SCRIPTABLE NS_IMETHOD SetHtmlFor(const nsAString & aHtmlFor); \
  NS_SCRIPTABLE NS_IMETHOD GetControl(nsIDOMHTMLElement **aControl); \
  NS_SCRIPTABLE NS_IMETHOD GetAccessKey(nsAString & aAccessKey); \
  NS_SCRIPTABLE NS_IMETHOD SetAccessKey(const nsAString & aAccessKey); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLLABELELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetForm(nsIDOMHTMLFormElement **aForm) { return _to GetForm(aForm); } \
  NS_SCRIPTABLE NS_IMETHOD GetHtmlFor(nsAString & aHtmlFor) { return _to GetHtmlFor(aHtmlFor); } \
  NS_SCRIPTABLE NS_IMETHOD SetHtmlFor(const nsAString & aHtmlFor) { return _to SetHtmlFor(aHtmlFor); } \
  NS_SCRIPTABLE NS_IMETHOD GetControl(nsIDOMHTMLElement **aControl) { return _to GetControl(aControl); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessKey(nsAString & aAccessKey) { return _to GetAccessKey(aAccessKey); } \
  NS_SCRIPTABLE NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) { return _to SetAccessKey(aAccessKey); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLLABELELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetForm(nsIDOMHTMLFormElement **aForm) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForm(aForm); } \
  NS_SCRIPTABLE NS_IMETHOD GetHtmlFor(nsAString & aHtmlFor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHtmlFor(aHtmlFor); } \
  NS_SCRIPTABLE NS_IMETHOD SetHtmlFor(const nsAString & aHtmlFor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHtmlFor(aHtmlFor); } \
  NS_SCRIPTABLE NS_IMETHOD GetControl(nsIDOMHTMLElement **aControl) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetControl(aControl); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessKey(nsAString & aAccessKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessKey(aAccessKey); } \
  NS_SCRIPTABLE NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAccessKey(aAccessKey); } 

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
NS_IMETHODIMP nsDOMHTMLLabelElement::GetForm(nsIDOMHTMLFormElement **aForm)
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
NS_IMETHODIMP nsDOMHTMLLabelElement::GetControl(nsIDOMHTMLElement **aControl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString accessKey; */
NS_IMETHODIMP nsDOMHTMLLabelElement::GetAccessKey(nsAString & aAccessKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLLabelElement::SetAccessKey(const nsAString & aAccessKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLLabelElement_h__ */

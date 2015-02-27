/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLOutputElement.idl
 */

#ifndef __gen_nsIDOMHTMLOutputElement_h__
#define __gen_nsIDOMHTMLOutputElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMValidityState; /* forward declaration */


/* starting interface:    nsIDOMHTMLOutputElement */
#define NS_IDOMHTMLOUTPUTELEMENT_IID_STR "6d6bf653-3eb4-420f-b1b0-6ad919a06926"

#define NS_IDOMHTMLOUTPUTELEMENT_IID \
  {0x6d6bf653, 0x3eb4, 0x420f, \
    { 0xb1, 0xb0, 0x6a, 0xd9, 0x19, 0xa0, 0x69, 0x26 }}

class NS_NO_VTABLE nsIDOMHTMLOutputElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLOUTPUTELEMENT_IID)

  /* readonly attribute nsISupports htmlFor; */
  NS_IMETHOD GetHtmlFor(nsISupports * *aHtmlFor) = 0;

  /* readonly attribute nsIDOMHTMLFormElement form; */
  NS_IMETHOD GetForm(nsIDOMHTMLFormElement * *aForm) = 0;

  /* attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_IMETHOD SetName(const nsAString & aName) = 0;

  /* readonly attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;

  /* attribute DOMString defaultValue; */
  NS_IMETHOD GetDefaultValue(nsAString & aDefaultValue) = 0;
  NS_IMETHOD SetDefaultValue(const nsAString & aDefaultValue) = 0;

  /* attribute DOMString value; */
  NS_IMETHOD GetValue(nsAString & aValue) = 0;
  NS_IMETHOD SetValue(const nsAString & aValue) = 0;

  /* readonly attribute boolean willValidate; */
  NS_IMETHOD GetWillValidate(bool *aWillValidate) = 0;

  /* readonly attribute nsIDOMValidityState validity; */
  NS_IMETHOD GetValidity(nsIDOMValidityState * *aValidity) = 0;

  /* readonly attribute DOMString validationMessage; */
  NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage) = 0;

  /* boolean checkValidity (); */
  NS_IMETHOD CheckValidity(bool *_retval) = 0;

  /* void setCustomValidity (in DOMString error); */
  NS_IMETHOD SetCustomValidity(const nsAString & error) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLOutputElement, NS_IDOMHTMLOUTPUTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLOUTPUTELEMENT \
  NS_IMETHOD GetHtmlFor(nsISupports * *aHtmlFor); \
  NS_IMETHOD GetForm(nsIDOMHTMLFormElement * *aForm); \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD SetName(const nsAString & aName); \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD GetDefaultValue(nsAString & aDefaultValue); \
  NS_IMETHOD SetDefaultValue(const nsAString & aDefaultValue); \
  NS_IMETHOD GetValue(nsAString & aValue); \
  NS_IMETHOD SetValue(const nsAString & aValue); \
  NS_IMETHOD GetWillValidate(bool *aWillValidate); \
  NS_IMETHOD GetValidity(nsIDOMValidityState * *aValidity); \
  NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage); \
  NS_IMETHOD CheckValidity(bool *_retval); \
  NS_IMETHOD SetCustomValidity(const nsAString & error); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLOUTPUTELEMENT(_to) \
  NS_IMETHOD GetHtmlFor(nsISupports * *aHtmlFor) { return _to GetHtmlFor(aHtmlFor); } \
  NS_IMETHOD GetForm(nsIDOMHTMLFormElement * *aForm) { return _to GetForm(aForm); } \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) { return _to SetName(aName); } \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD GetDefaultValue(nsAString & aDefaultValue) { return _to GetDefaultValue(aDefaultValue); } \
  NS_IMETHOD SetDefaultValue(const nsAString & aDefaultValue) { return _to SetDefaultValue(aDefaultValue); } \
  NS_IMETHOD GetValue(nsAString & aValue) { return _to GetValue(aValue); } \
  NS_IMETHOD SetValue(const nsAString & aValue) { return _to SetValue(aValue); } \
  NS_IMETHOD GetWillValidate(bool *aWillValidate) { return _to GetWillValidate(aWillValidate); } \
  NS_IMETHOD GetValidity(nsIDOMValidityState * *aValidity) { return _to GetValidity(aValidity); } \
  NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage) { return _to GetValidationMessage(aValidationMessage); } \
  NS_IMETHOD CheckValidity(bool *_retval) { return _to CheckValidity(_retval); } \
  NS_IMETHOD SetCustomValidity(const nsAString & error) { return _to SetCustomValidity(error); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLOUTPUTELEMENT(_to) \
  NS_IMETHOD GetHtmlFor(nsISupports * *aHtmlFor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHtmlFor(aHtmlFor); } \
  NS_IMETHOD GetForm(nsIDOMHTMLFormElement * *aForm) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForm(aForm); } \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetDefaultValue(nsAString & aDefaultValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultValue(aDefaultValue); } \
  NS_IMETHOD SetDefaultValue(const nsAString & aDefaultValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultValue(aDefaultValue); } \
  NS_IMETHOD GetValue(nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_IMETHOD SetValue(const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } \
  NS_IMETHOD GetWillValidate(bool *aWillValidate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWillValidate(aWillValidate); } \
  NS_IMETHOD GetValidity(nsIDOMValidityState * *aValidity) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValidity(aValidity); } \
  NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValidationMessage(aValidationMessage); } \
  NS_IMETHOD CheckValidity(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckValidity(_retval); } \
  NS_IMETHOD SetCustomValidity(const nsAString & error) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCustomValidity(error); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLOutputElement : public nsIDOMHTMLOutputElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLOUTPUTELEMENT

  nsDOMHTMLOutputElement();

private:
  ~nsDOMHTMLOutputElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLOutputElement, nsIDOMHTMLOutputElement)

nsDOMHTMLOutputElement::nsDOMHTMLOutputElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLOutputElement::~nsDOMHTMLOutputElement()
{
  /* destructor code */
}

/* readonly attribute nsISupports htmlFor; */
NS_IMETHODIMP nsDOMHTMLOutputElement::GetHtmlFor(nsISupports * *aHtmlFor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLFormElement form; */
NS_IMETHODIMP nsDOMHTMLOutputElement::GetForm(nsIDOMHTMLFormElement * *aForm)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString name; */
NS_IMETHODIMP nsDOMHTMLOutputElement::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLOutputElement::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString type; */
NS_IMETHODIMP nsDOMHTMLOutputElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString defaultValue; */
NS_IMETHODIMP nsDOMHTMLOutputElement::GetDefaultValue(nsAString & aDefaultValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLOutputElement::SetDefaultValue(const nsAString & aDefaultValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString value; */
NS_IMETHODIMP nsDOMHTMLOutputElement::GetValue(nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLOutputElement::SetValue(const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean willValidate; */
NS_IMETHODIMP nsDOMHTMLOutputElement::GetWillValidate(bool *aWillValidate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMValidityState validity; */
NS_IMETHODIMP nsDOMHTMLOutputElement::GetValidity(nsIDOMValidityState * *aValidity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString validationMessage; */
NS_IMETHODIMP nsDOMHTMLOutputElement::GetValidationMessage(nsAString & aValidationMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean checkValidity (); */
NS_IMETHODIMP nsDOMHTMLOutputElement::CheckValidity(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCustomValidity (in DOMString error); */
NS_IMETHODIMP nsDOMHTMLOutputElement::SetCustomValidity(const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLOutputElement_h__ */

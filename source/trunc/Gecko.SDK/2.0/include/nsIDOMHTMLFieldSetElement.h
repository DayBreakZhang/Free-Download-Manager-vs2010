/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/html/nsIDOMHTMLFieldSetElement.idl
 */

#ifndef __gen_nsIDOMHTMLFieldSetElement_h__
#define __gen_nsIDOMHTMLFieldSetElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMValidityState; /* forward declaration */


/* starting interface:    nsIDOMHTMLFieldSetElement */
#define NS_IDOMHTMLFIELDSETELEMENT_IID_STR "58db2166-36fc-482c-a9f8-84ad262537b2"

#define NS_IDOMHTMLFIELDSETELEMENT_IID \
  {0x58db2166, 0x36fc, 0x482c, \
    { 0xa9, 0xf8, 0x84, 0xad, 0x26, 0x25, 0x37, 0xb2 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLFieldSetElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLFIELDSETELEMENT_IID)

  /* attribute boolean disabled; */
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled) = 0;

  /* readonly attribute nsIDOMHTMLFormElement form; */
  NS_SCRIPTABLE NS_IMETHOD GetForm(nsIDOMHTMLFormElement **aForm) = 0;

  /* attribute DOMString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) = 0;

  /* readonly attribute DOMString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) = 0;

  /* readonly attribute nsIDOMHTMLCollection elements; */
  NS_SCRIPTABLE NS_IMETHOD GetElements(nsIDOMHTMLCollection **aElements) = 0;

  /* readonly attribute boolean willValidate; */
  NS_SCRIPTABLE NS_IMETHOD GetWillValidate(PRBool *aWillValidate) = 0;

  /* readonly attribute nsIDOMValidityState validity; */
  NS_SCRIPTABLE NS_IMETHOD GetValidity(nsIDOMValidityState **aValidity) = 0;

  /* readonly attribute DOMString validationMessage; */
  NS_SCRIPTABLE NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage) = 0;

  /* boolean checkValidity (); */
  NS_SCRIPTABLE NS_IMETHOD CheckValidity(PRBool *_retval NS_OUTPARAM) = 0;

  /* void setCustomValidity (in DOMString error); */
  NS_SCRIPTABLE NS_IMETHOD SetCustomValidity(const nsAString & error) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLFieldSetElement, NS_IDOMHTMLFIELDSETELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLFIELDSETELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled); \
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled); \
  NS_SCRIPTABLE NS_IMETHOD GetForm(nsIDOMHTMLFormElement **aForm); \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD GetElements(nsIDOMHTMLCollection **aElements); \
  NS_SCRIPTABLE NS_IMETHOD GetWillValidate(PRBool *aWillValidate); \
  NS_SCRIPTABLE NS_IMETHOD GetValidity(nsIDOMValidityState **aValidity); \
  NS_SCRIPTABLE NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage); \
  NS_SCRIPTABLE NS_IMETHOD CheckValidity(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetCustomValidity(const nsAString & error); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLFIELDSETELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled) { return _to GetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled) { return _to SetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetForm(nsIDOMHTMLFormElement **aForm) { return _to GetForm(aForm); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) { return _to SetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetElements(nsIDOMHTMLCollection **aElements) { return _to GetElements(aElements); } \
  NS_SCRIPTABLE NS_IMETHOD GetWillValidate(PRBool *aWillValidate) { return _to GetWillValidate(aWillValidate); } \
  NS_SCRIPTABLE NS_IMETHOD GetValidity(nsIDOMValidityState **aValidity) { return _to GetValidity(aValidity); } \
  NS_SCRIPTABLE NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage) { return _to GetValidationMessage(aValidationMessage); } \
  NS_SCRIPTABLE NS_IMETHOD CheckValidity(PRBool *_retval NS_OUTPARAM) { return _to CheckValidity(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetCustomValidity(const nsAString & error) { return _to SetCustomValidity(error); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLFIELDSETELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetForm(nsIDOMHTMLFormElement **aForm) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForm(aForm); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetElements(nsIDOMHTMLCollection **aElements) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElements(aElements); } \
  NS_SCRIPTABLE NS_IMETHOD GetWillValidate(PRBool *aWillValidate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWillValidate(aWillValidate); } \
  NS_SCRIPTABLE NS_IMETHOD GetValidity(nsIDOMValidityState **aValidity) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValidity(aValidity); } \
  NS_SCRIPTABLE NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValidationMessage(aValidationMessage); } \
  NS_SCRIPTABLE NS_IMETHOD CheckValidity(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckValidity(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetCustomValidity(const nsAString & error) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCustomValidity(error); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLFieldSetElement : public nsIDOMHTMLFieldSetElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLFIELDSETELEMENT

  nsDOMHTMLFieldSetElement();

private:
  ~nsDOMHTMLFieldSetElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLFieldSetElement, nsIDOMHTMLFieldSetElement)

nsDOMHTMLFieldSetElement::nsDOMHTMLFieldSetElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLFieldSetElement::~nsDOMHTMLFieldSetElement()
{
  /* destructor code */
}

/* attribute boolean disabled; */
NS_IMETHODIMP nsDOMHTMLFieldSetElement::GetDisabled(PRBool *aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFieldSetElement::SetDisabled(PRBool aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLFormElement form; */
NS_IMETHODIMP nsDOMHTMLFieldSetElement::GetForm(nsIDOMHTMLFormElement **aForm)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString name; */
NS_IMETHODIMP nsDOMHTMLFieldSetElement::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFieldSetElement::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString type; */
NS_IMETHODIMP nsDOMHTMLFieldSetElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLCollection elements; */
NS_IMETHODIMP nsDOMHTMLFieldSetElement::GetElements(nsIDOMHTMLCollection **aElements)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean willValidate; */
NS_IMETHODIMP nsDOMHTMLFieldSetElement::GetWillValidate(PRBool *aWillValidate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMValidityState validity; */
NS_IMETHODIMP nsDOMHTMLFieldSetElement::GetValidity(nsIDOMValidityState **aValidity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString validationMessage; */
NS_IMETHODIMP nsDOMHTMLFieldSetElement::GetValidationMessage(nsAString & aValidationMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean checkValidity (); */
NS_IMETHODIMP nsDOMHTMLFieldSetElement::CheckValidity(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCustomValidity (in DOMString error); */
NS_IMETHODIMP nsDOMHTMLFieldSetElement::SetCustomValidity(const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLFieldSetElement_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/html/nsIDOMHTMLButtonElement.idl
 */

#ifndef __gen_nsIDOMHTMLButtonElement_h__
#define __gen_nsIDOMHTMLButtonElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMValidityState; /* forward declaration */


/* starting interface:    nsIDOMHTMLButtonElement */
#define NS_IDOMHTMLBUTTONELEMENT_IID_STR "bcae78a1-9f9b-46bf-abb5-a3fe410d97ae"

#define NS_IDOMHTMLBUTTONELEMENT_IID \
  {0xbcae78a1, 0x9f9b, 0x46bf, \
    { 0xab, 0xb5, 0xa3, 0xfe, 0x41, 0x0d, 0x97, 0xae }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLButtonElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLBUTTONELEMENT_IID)

  /* attribute boolean autofocus; */
  NS_SCRIPTABLE NS_IMETHOD GetAutofocus(PRBool *aAutofocus) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAutofocus(PRBool aAutofocus) = 0;

  /* attribute boolean disabled; */
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled) = 0;

  /* readonly attribute nsIDOMHTMLFormElement form; */
  NS_SCRIPTABLE NS_IMETHOD GetForm(nsIDOMHTMLFormElement **aForm) = 0;

  /* attribute DOMString formAction; */
  NS_SCRIPTABLE NS_IMETHOD GetFormAction(nsAString & aFormAction) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFormAction(const nsAString & aFormAction) = 0;

  /* attribute DOMString formEnctype; */
  NS_SCRIPTABLE NS_IMETHOD GetFormEnctype(nsAString & aFormEnctype) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFormEnctype(const nsAString & aFormEnctype) = 0;

  /* attribute DOMString formMethod; */
  NS_SCRIPTABLE NS_IMETHOD GetFormMethod(nsAString & aFormMethod) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFormMethod(const nsAString & aFormMethod) = 0;

  /* attribute boolean formNoValidate; */
  NS_SCRIPTABLE NS_IMETHOD GetFormNoValidate(PRBool *aFormNoValidate) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFormNoValidate(PRBool aFormNoValidate) = 0;

  /* attribute DOMString formTarget; */
  NS_SCRIPTABLE NS_IMETHOD GetFormTarget(nsAString & aFormTarget) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFormTarget(const nsAString & aFormTarget) = 0;

  /* attribute DOMString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) = 0;

  /* attribute DOMString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) = 0;

  /* attribute DOMString value; */
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue) = 0;

  /* attribute DOMString accessKey; */
  NS_SCRIPTABLE NS_IMETHOD GetAccessKey(nsAString & aAccessKey) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) = 0;

  /* attribute long tabIndex; */
  NS_SCRIPTABLE NS_IMETHOD GetTabIndex(PRInt32 *aTabIndex) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTabIndex(PRInt32 aTabIndex) = 0;

  /* void blur (); */
  NS_SCRIPTABLE NS_IMETHOD Blur(void) = 0;

  /* void focus (); */
  NS_SCRIPTABLE NS_IMETHOD Focus(void) = 0;

  /* void click (); */
  NS_SCRIPTABLE NS_IMETHOD Click(void) = 0;

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

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLButtonElement, NS_IDOMHTMLBUTTONELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLBUTTONELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetAutofocus(PRBool *aAutofocus); \
  NS_SCRIPTABLE NS_IMETHOD SetAutofocus(PRBool aAutofocus); \
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled); \
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled); \
  NS_SCRIPTABLE NS_IMETHOD GetForm(nsIDOMHTMLFormElement **aForm); \
  NS_SCRIPTABLE NS_IMETHOD GetFormAction(nsAString & aFormAction); \
  NS_SCRIPTABLE NS_IMETHOD SetFormAction(const nsAString & aFormAction); \
  NS_SCRIPTABLE NS_IMETHOD GetFormEnctype(nsAString & aFormEnctype); \
  NS_SCRIPTABLE NS_IMETHOD SetFormEnctype(const nsAString & aFormEnctype); \
  NS_SCRIPTABLE NS_IMETHOD GetFormMethod(nsAString & aFormMethod); \
  NS_SCRIPTABLE NS_IMETHOD SetFormMethod(const nsAString & aFormMethod); \
  NS_SCRIPTABLE NS_IMETHOD GetFormNoValidate(PRBool *aFormNoValidate); \
  NS_SCRIPTABLE NS_IMETHOD SetFormNoValidate(PRBool aFormNoValidate); \
  NS_SCRIPTABLE NS_IMETHOD GetFormTarget(nsAString & aFormTarget); \
  NS_SCRIPTABLE NS_IMETHOD SetFormTarget(const nsAString & aFormTarget); \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD GetAccessKey(nsAString & aAccessKey); \
  NS_SCRIPTABLE NS_IMETHOD SetAccessKey(const nsAString & aAccessKey); \
  NS_SCRIPTABLE NS_IMETHOD GetTabIndex(PRInt32 *aTabIndex); \
  NS_SCRIPTABLE NS_IMETHOD SetTabIndex(PRInt32 aTabIndex); \
  NS_SCRIPTABLE NS_IMETHOD Blur(void); \
  NS_SCRIPTABLE NS_IMETHOD Focus(void); \
  NS_SCRIPTABLE NS_IMETHOD Click(void); \
  NS_SCRIPTABLE NS_IMETHOD GetWillValidate(PRBool *aWillValidate); \
  NS_SCRIPTABLE NS_IMETHOD GetValidity(nsIDOMValidityState **aValidity); \
  NS_SCRIPTABLE NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage); \
  NS_SCRIPTABLE NS_IMETHOD CheckValidity(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetCustomValidity(const nsAString & error); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLBUTTONELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAutofocus(PRBool *aAutofocus) { return _to GetAutofocus(aAutofocus); } \
  NS_SCRIPTABLE NS_IMETHOD SetAutofocus(PRBool aAutofocus) { return _to SetAutofocus(aAutofocus); } \
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled) { return _to GetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled) { return _to SetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetForm(nsIDOMHTMLFormElement **aForm) { return _to GetForm(aForm); } \
  NS_SCRIPTABLE NS_IMETHOD GetFormAction(nsAString & aFormAction) { return _to GetFormAction(aFormAction); } \
  NS_SCRIPTABLE NS_IMETHOD SetFormAction(const nsAString & aFormAction) { return _to SetFormAction(aFormAction); } \
  NS_SCRIPTABLE NS_IMETHOD GetFormEnctype(nsAString & aFormEnctype) { return _to GetFormEnctype(aFormEnctype); } \
  NS_SCRIPTABLE NS_IMETHOD SetFormEnctype(const nsAString & aFormEnctype) { return _to SetFormEnctype(aFormEnctype); } \
  NS_SCRIPTABLE NS_IMETHOD GetFormMethod(nsAString & aFormMethod) { return _to GetFormMethod(aFormMethod); } \
  NS_SCRIPTABLE NS_IMETHOD SetFormMethod(const nsAString & aFormMethod) { return _to SetFormMethod(aFormMethod); } \
  NS_SCRIPTABLE NS_IMETHOD GetFormNoValidate(PRBool *aFormNoValidate) { return _to GetFormNoValidate(aFormNoValidate); } \
  NS_SCRIPTABLE NS_IMETHOD SetFormNoValidate(PRBool aFormNoValidate) { return _to SetFormNoValidate(aFormNoValidate); } \
  NS_SCRIPTABLE NS_IMETHOD GetFormTarget(nsAString & aFormTarget) { return _to GetFormTarget(aFormTarget); } \
  NS_SCRIPTABLE NS_IMETHOD SetFormTarget(const nsAString & aFormTarget) { return _to SetFormTarget(aFormTarget); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) { return _to SetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue) { return _to GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue) { return _to SetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessKey(nsAString & aAccessKey) { return _to GetAccessKey(aAccessKey); } \
  NS_SCRIPTABLE NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) { return _to SetAccessKey(aAccessKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetTabIndex(PRInt32 *aTabIndex) { return _to GetTabIndex(aTabIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetTabIndex(PRInt32 aTabIndex) { return _to SetTabIndex(aTabIndex); } \
  NS_SCRIPTABLE NS_IMETHOD Blur(void) { return _to Blur(); } \
  NS_SCRIPTABLE NS_IMETHOD Focus(void) { return _to Focus(); } \
  NS_SCRIPTABLE NS_IMETHOD Click(void) { return _to Click(); } \
  NS_SCRIPTABLE NS_IMETHOD GetWillValidate(PRBool *aWillValidate) { return _to GetWillValidate(aWillValidate); } \
  NS_SCRIPTABLE NS_IMETHOD GetValidity(nsIDOMValidityState **aValidity) { return _to GetValidity(aValidity); } \
  NS_SCRIPTABLE NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage) { return _to GetValidationMessage(aValidationMessage); } \
  NS_SCRIPTABLE NS_IMETHOD CheckValidity(PRBool *_retval NS_OUTPARAM) { return _to CheckValidity(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetCustomValidity(const nsAString & error) { return _to SetCustomValidity(error); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLBUTTONELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAutofocus(PRBool *aAutofocus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAutofocus(aAutofocus); } \
  NS_SCRIPTABLE NS_IMETHOD SetAutofocus(PRBool aAutofocus) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAutofocus(aAutofocus); } \
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetForm(nsIDOMHTMLFormElement **aForm) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForm(aForm); } \
  NS_SCRIPTABLE NS_IMETHOD GetFormAction(nsAString & aFormAction) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFormAction(aFormAction); } \
  NS_SCRIPTABLE NS_IMETHOD SetFormAction(const nsAString & aFormAction) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFormAction(aFormAction); } \
  NS_SCRIPTABLE NS_IMETHOD GetFormEnctype(nsAString & aFormEnctype) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFormEnctype(aFormEnctype); } \
  NS_SCRIPTABLE NS_IMETHOD SetFormEnctype(const nsAString & aFormEnctype) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFormEnctype(aFormEnctype); } \
  NS_SCRIPTABLE NS_IMETHOD GetFormMethod(nsAString & aFormMethod) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFormMethod(aFormMethod); } \
  NS_SCRIPTABLE NS_IMETHOD SetFormMethod(const nsAString & aFormMethod) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFormMethod(aFormMethod); } \
  NS_SCRIPTABLE NS_IMETHOD GetFormNoValidate(PRBool *aFormNoValidate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFormNoValidate(aFormNoValidate); } \
  NS_SCRIPTABLE NS_IMETHOD SetFormNoValidate(PRBool aFormNoValidate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFormNoValidate(aFormNoValidate); } \
  NS_SCRIPTABLE NS_IMETHOD GetFormTarget(nsAString & aFormTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFormTarget(aFormTarget); } \
  NS_SCRIPTABLE NS_IMETHOD SetFormTarget(const nsAString & aFormTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFormTarget(aFormTarget); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessKey(nsAString & aAccessKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessKey(aAccessKey); } \
  NS_SCRIPTABLE NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAccessKey(aAccessKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetTabIndex(PRInt32 *aTabIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTabIndex(aTabIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetTabIndex(PRInt32 aTabIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTabIndex(aTabIndex); } \
  NS_SCRIPTABLE NS_IMETHOD Blur(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Blur(); } \
  NS_SCRIPTABLE NS_IMETHOD Focus(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Focus(); } \
  NS_SCRIPTABLE NS_IMETHOD Click(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Click(); } \
  NS_SCRIPTABLE NS_IMETHOD GetWillValidate(PRBool *aWillValidate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWillValidate(aWillValidate); } \
  NS_SCRIPTABLE NS_IMETHOD GetValidity(nsIDOMValidityState **aValidity) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValidity(aValidity); } \
  NS_SCRIPTABLE NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValidationMessage(aValidationMessage); } \
  NS_SCRIPTABLE NS_IMETHOD CheckValidity(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckValidity(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetCustomValidity(const nsAString & error) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCustomValidity(error); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLButtonElement : public nsIDOMHTMLButtonElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLBUTTONELEMENT

  nsDOMHTMLButtonElement();

private:
  ~nsDOMHTMLButtonElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLButtonElement, nsIDOMHTMLButtonElement)

nsDOMHTMLButtonElement::nsDOMHTMLButtonElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLButtonElement::~nsDOMHTMLButtonElement()
{
  /* destructor code */
}

/* attribute boolean autofocus; */
NS_IMETHODIMP nsDOMHTMLButtonElement::GetAutofocus(PRBool *aAutofocus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLButtonElement::SetAutofocus(PRBool aAutofocus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean disabled; */
NS_IMETHODIMP nsDOMHTMLButtonElement::GetDisabled(PRBool *aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLButtonElement::SetDisabled(PRBool aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLFormElement form; */
NS_IMETHODIMP nsDOMHTMLButtonElement::GetForm(nsIDOMHTMLFormElement **aForm)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString formAction; */
NS_IMETHODIMP nsDOMHTMLButtonElement::GetFormAction(nsAString & aFormAction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLButtonElement::SetFormAction(const nsAString & aFormAction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString formEnctype; */
NS_IMETHODIMP nsDOMHTMLButtonElement::GetFormEnctype(nsAString & aFormEnctype)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLButtonElement::SetFormEnctype(const nsAString & aFormEnctype)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString formMethod; */
NS_IMETHODIMP nsDOMHTMLButtonElement::GetFormMethod(nsAString & aFormMethod)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLButtonElement::SetFormMethod(const nsAString & aFormMethod)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean formNoValidate; */
NS_IMETHODIMP nsDOMHTMLButtonElement::GetFormNoValidate(PRBool *aFormNoValidate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLButtonElement::SetFormNoValidate(PRBool aFormNoValidate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString formTarget; */
NS_IMETHODIMP nsDOMHTMLButtonElement::GetFormTarget(nsAString & aFormTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLButtonElement::SetFormTarget(const nsAString & aFormTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString name; */
NS_IMETHODIMP nsDOMHTMLButtonElement::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLButtonElement::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMHTMLButtonElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLButtonElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString value; */
NS_IMETHODIMP nsDOMHTMLButtonElement::GetValue(nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLButtonElement::SetValue(const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString accessKey; */
NS_IMETHODIMP nsDOMHTMLButtonElement::GetAccessKey(nsAString & aAccessKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLButtonElement::SetAccessKey(const nsAString & aAccessKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long tabIndex; */
NS_IMETHODIMP nsDOMHTMLButtonElement::GetTabIndex(PRInt32 *aTabIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLButtonElement::SetTabIndex(PRInt32 aTabIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void blur (); */
NS_IMETHODIMP nsDOMHTMLButtonElement::Blur()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void focus (); */
NS_IMETHODIMP nsDOMHTMLButtonElement::Focus()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void click (); */
NS_IMETHODIMP nsDOMHTMLButtonElement::Click()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean willValidate; */
NS_IMETHODIMP nsDOMHTMLButtonElement::GetWillValidate(PRBool *aWillValidate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMValidityState validity; */
NS_IMETHODIMP nsDOMHTMLButtonElement::GetValidity(nsIDOMValidityState **aValidity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString validationMessage; */
NS_IMETHODIMP nsDOMHTMLButtonElement::GetValidationMessage(nsAString & aValidationMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean checkValidity (); */
NS_IMETHODIMP nsDOMHTMLButtonElement::CheckValidity(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCustomValidity (in DOMString error); */
NS_IMETHODIMP nsDOMHTMLButtonElement::SetCustomValidity(const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLButtonElement_h__ */

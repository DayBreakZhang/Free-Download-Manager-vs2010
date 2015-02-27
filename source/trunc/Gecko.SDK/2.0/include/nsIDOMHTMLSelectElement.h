/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/html/nsIDOMHTMLSelectElement.idl
 */

#ifndef __gen_nsIDOMHTMLSelectElement_h__
#define __gen_nsIDOMHTMLSelectElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

#ifndef __gen_nsIDOMHTMLOptionsCollection_h__
#include "nsIDOMHTMLOptionsCollection.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMValidityState; /* forward declaration */


/* starting interface:    nsIDOMHTMLSelectElement */
#define NS_IDOMHTMLSELECTELEMENT_IID_STR "e3c6d960-972c-4a5e-a8f4-6ca65d578abf"

#define NS_IDOMHTMLSELECTELEMENT_IID \
  {0xe3c6d960, 0x972c, 0x4a5e, \
    { 0xa8, 0xf4, 0x6c, 0xa6, 0x5d, 0x57, 0x8a, 0xbf }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLSelectElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLSELECTELEMENT_IID)

  /* attribute boolean autofocus; */
  NS_SCRIPTABLE NS_IMETHOD GetAutofocus(PRBool *aAutofocus) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAutofocus(PRBool aAutofocus) = 0;

  /* attribute boolean disabled; */
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled) = 0;

  /* readonly attribute nsIDOMHTMLFormElement form; */
  NS_SCRIPTABLE NS_IMETHOD GetForm(nsIDOMHTMLFormElement **aForm) = 0;

  /* attribute boolean multiple; */
  NS_SCRIPTABLE NS_IMETHOD GetMultiple(PRBool *aMultiple) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMultiple(PRBool aMultiple) = 0;

  /* attribute DOMString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) = 0;

  /* attribute long size; */
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRInt32 *aSize) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSize(PRInt32 aSize) = 0;

  /* readonly attribute DOMString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) = 0;

  /* readonly attribute nsIDOMHTMLOptionsCollection options; */
  NS_SCRIPTABLE NS_IMETHOD GetOptions(nsIDOMHTMLOptionsCollection **aOptions) = 0;

  /* attribute unsigned long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLength(PRUint32 aLength) = 0;

  /* nsIDOMNode item (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode **_retval NS_OUTPARAM) = 0;

  /* nsIDOMNode namedItem (in DOMString name); */
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode **_retval NS_OUTPARAM) = 0;

  /* void add (in nsIDOMHTMLElement element, in nsIDOMHTMLElement before)  raises (DOMException); */
  NS_SCRIPTABLE NS_IMETHOD Add(nsIDOMHTMLElement *element, nsIDOMHTMLElement *before) = 0;

  /* void remove (in long index); */
  NS_SCRIPTABLE NS_IMETHOD Remove(PRInt32 index) = 0;

  /* attribute long selectedIndex; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedIndex(PRInt32 *aSelectedIndex) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSelectedIndex(PRInt32 aSelectedIndex) = 0;

  /* attribute DOMString value; */
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue) = 0;

  /* attribute long tabIndex; */
  NS_SCRIPTABLE NS_IMETHOD GetTabIndex(PRInt32 *aTabIndex) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTabIndex(PRInt32 aTabIndex) = 0;

  /* void blur (); */
  NS_SCRIPTABLE NS_IMETHOD Blur(void) = 0;

  /* void focus (); */
  NS_SCRIPTABLE NS_IMETHOD Focus(void) = 0;

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

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLSelectElement, NS_IDOMHTMLSELECTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLSELECTELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetAutofocus(PRBool *aAutofocus); \
  NS_SCRIPTABLE NS_IMETHOD SetAutofocus(PRBool aAutofocus); \
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled); \
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled); \
  NS_SCRIPTABLE NS_IMETHOD GetForm(nsIDOMHTMLFormElement **aForm); \
  NS_SCRIPTABLE NS_IMETHOD GetMultiple(PRBool *aMultiple); \
  NS_SCRIPTABLE NS_IMETHOD SetMultiple(PRBool aMultiple); \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRInt32 *aSize); \
  NS_SCRIPTABLE NS_IMETHOD SetSize(PRInt32 aSize); \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD GetOptions(nsIDOMHTMLOptionsCollection **aOptions); \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength); \
  NS_SCRIPTABLE NS_IMETHOD SetLength(PRUint32 aLength); \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Add(nsIDOMHTMLElement *element, nsIDOMHTMLElement *before); \
  NS_SCRIPTABLE NS_IMETHOD Remove(PRInt32 index); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedIndex(PRInt32 *aSelectedIndex); \
  NS_SCRIPTABLE NS_IMETHOD SetSelectedIndex(PRInt32 aSelectedIndex); \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD GetTabIndex(PRInt32 *aTabIndex); \
  NS_SCRIPTABLE NS_IMETHOD SetTabIndex(PRInt32 aTabIndex); \
  NS_SCRIPTABLE NS_IMETHOD Blur(void); \
  NS_SCRIPTABLE NS_IMETHOD Focus(void); \
  NS_SCRIPTABLE NS_IMETHOD GetWillValidate(PRBool *aWillValidate); \
  NS_SCRIPTABLE NS_IMETHOD GetValidity(nsIDOMValidityState **aValidity); \
  NS_SCRIPTABLE NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage); \
  NS_SCRIPTABLE NS_IMETHOD CheckValidity(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetCustomValidity(const nsAString & error); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLSELECTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAutofocus(PRBool *aAutofocus) { return _to GetAutofocus(aAutofocus); } \
  NS_SCRIPTABLE NS_IMETHOD SetAutofocus(PRBool aAutofocus) { return _to SetAutofocus(aAutofocus); } \
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled) { return _to GetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled) { return _to SetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetForm(nsIDOMHTMLFormElement **aForm) { return _to GetForm(aForm); } \
  NS_SCRIPTABLE NS_IMETHOD GetMultiple(PRBool *aMultiple) { return _to GetMultiple(aMultiple); } \
  NS_SCRIPTABLE NS_IMETHOD SetMultiple(PRBool aMultiple) { return _to SetMultiple(aMultiple); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) { return _to SetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRInt32 *aSize) { return _to GetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD SetSize(PRInt32 aSize) { return _to SetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetOptions(nsIDOMHTMLOptionsCollection **aOptions) { return _to GetOptions(aOptions); } \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return _to GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD SetLength(PRUint32 aLength) { return _to SetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode **_retval NS_OUTPARAM) { return _to Item(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode **_retval NS_OUTPARAM) { return _to NamedItem(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Add(nsIDOMHTMLElement *element, nsIDOMHTMLElement *before) { return _to Add(element, before); } \
  NS_SCRIPTABLE NS_IMETHOD Remove(PRInt32 index) { return _to Remove(index); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedIndex(PRInt32 *aSelectedIndex) { return _to GetSelectedIndex(aSelectedIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectedIndex(PRInt32 aSelectedIndex) { return _to SetSelectedIndex(aSelectedIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue) { return _to GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue) { return _to SetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetTabIndex(PRInt32 *aTabIndex) { return _to GetTabIndex(aTabIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetTabIndex(PRInt32 aTabIndex) { return _to SetTabIndex(aTabIndex); } \
  NS_SCRIPTABLE NS_IMETHOD Blur(void) { return _to Blur(); } \
  NS_SCRIPTABLE NS_IMETHOD Focus(void) { return _to Focus(); } \
  NS_SCRIPTABLE NS_IMETHOD GetWillValidate(PRBool *aWillValidate) { return _to GetWillValidate(aWillValidate); } \
  NS_SCRIPTABLE NS_IMETHOD GetValidity(nsIDOMValidityState **aValidity) { return _to GetValidity(aValidity); } \
  NS_SCRIPTABLE NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage) { return _to GetValidationMessage(aValidationMessage); } \
  NS_SCRIPTABLE NS_IMETHOD CheckValidity(PRBool *_retval NS_OUTPARAM) { return _to CheckValidity(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetCustomValidity(const nsAString & error) { return _to SetCustomValidity(error); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLSELECTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAutofocus(PRBool *aAutofocus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAutofocus(aAutofocus); } \
  NS_SCRIPTABLE NS_IMETHOD SetAutofocus(PRBool aAutofocus) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAutofocus(aAutofocus); } \
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetForm(nsIDOMHTMLFormElement **aForm) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForm(aForm); } \
  NS_SCRIPTABLE NS_IMETHOD GetMultiple(PRBool *aMultiple) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMultiple(aMultiple); } \
  NS_SCRIPTABLE NS_IMETHOD SetMultiple(PRBool aMultiple) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMultiple(aMultiple); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRInt32 *aSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD SetSize(PRInt32 aSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetOptions(nsIDOMHTMLOptionsCollection **aOptions) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOptions(aOptions); } \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD SetLength(PRUint32 aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NamedItem(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Add(nsIDOMHTMLElement *element, nsIDOMHTMLElement *before) { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(element, before); } \
  NS_SCRIPTABLE NS_IMETHOD Remove(PRInt32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->Remove(index); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedIndex(PRInt32 *aSelectedIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedIndex(aSelectedIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectedIndex(PRInt32 aSelectedIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectedIndex(aSelectedIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetTabIndex(PRInt32 *aTabIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTabIndex(aTabIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetTabIndex(PRInt32 aTabIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTabIndex(aTabIndex); } \
  NS_SCRIPTABLE NS_IMETHOD Blur(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Blur(); } \
  NS_SCRIPTABLE NS_IMETHOD Focus(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Focus(); } \
  NS_SCRIPTABLE NS_IMETHOD GetWillValidate(PRBool *aWillValidate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWillValidate(aWillValidate); } \
  NS_SCRIPTABLE NS_IMETHOD GetValidity(nsIDOMValidityState **aValidity) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValidity(aValidity); } \
  NS_SCRIPTABLE NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValidationMessage(aValidationMessage); } \
  NS_SCRIPTABLE NS_IMETHOD CheckValidity(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckValidity(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetCustomValidity(const nsAString & error) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCustomValidity(error); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLSelectElement : public nsIDOMHTMLSelectElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLSELECTELEMENT

  nsDOMHTMLSelectElement();

private:
  ~nsDOMHTMLSelectElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLSelectElement, nsIDOMHTMLSelectElement)

nsDOMHTMLSelectElement::nsDOMHTMLSelectElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLSelectElement::~nsDOMHTMLSelectElement()
{
  /* destructor code */
}

/* attribute boolean autofocus; */
NS_IMETHODIMP nsDOMHTMLSelectElement::GetAutofocus(PRBool *aAutofocus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLSelectElement::SetAutofocus(PRBool aAutofocus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean disabled; */
NS_IMETHODIMP nsDOMHTMLSelectElement::GetDisabled(PRBool *aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLSelectElement::SetDisabled(PRBool aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLFormElement form; */
NS_IMETHODIMP nsDOMHTMLSelectElement::GetForm(nsIDOMHTMLFormElement **aForm)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean multiple; */
NS_IMETHODIMP nsDOMHTMLSelectElement::GetMultiple(PRBool *aMultiple)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLSelectElement::SetMultiple(PRBool aMultiple)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString name; */
NS_IMETHODIMP nsDOMHTMLSelectElement::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLSelectElement::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long size; */
NS_IMETHODIMP nsDOMHTMLSelectElement::GetSize(PRInt32 *aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLSelectElement::SetSize(PRInt32 aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString type; */
NS_IMETHODIMP nsDOMHTMLSelectElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLOptionsCollection options; */
NS_IMETHODIMP nsDOMHTMLSelectElement::GetOptions(nsIDOMHTMLOptionsCollection **aOptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long length; */
NS_IMETHODIMP nsDOMHTMLSelectElement::GetLength(PRUint32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLSelectElement::SetLength(PRUint32 aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode item (in unsigned long index); */
NS_IMETHODIMP nsDOMHTMLSelectElement::Item(PRUint32 index, nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode namedItem (in DOMString name); */
NS_IMETHODIMP nsDOMHTMLSelectElement::NamedItem(const nsAString & name, nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void add (in nsIDOMHTMLElement element, in nsIDOMHTMLElement before)  raises (DOMException); */
NS_IMETHODIMP nsDOMHTMLSelectElement::Add(nsIDOMHTMLElement *element, nsIDOMHTMLElement *before)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void remove (in long index); */
NS_IMETHODIMP nsDOMHTMLSelectElement::Remove(PRInt32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long selectedIndex; */
NS_IMETHODIMP nsDOMHTMLSelectElement::GetSelectedIndex(PRInt32 *aSelectedIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLSelectElement::SetSelectedIndex(PRInt32 aSelectedIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString value; */
NS_IMETHODIMP nsDOMHTMLSelectElement::GetValue(nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLSelectElement::SetValue(const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long tabIndex; */
NS_IMETHODIMP nsDOMHTMLSelectElement::GetTabIndex(PRInt32 *aTabIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLSelectElement::SetTabIndex(PRInt32 aTabIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void blur (); */
NS_IMETHODIMP nsDOMHTMLSelectElement::Blur()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void focus (); */
NS_IMETHODIMP nsDOMHTMLSelectElement::Focus()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean willValidate; */
NS_IMETHODIMP nsDOMHTMLSelectElement::GetWillValidate(PRBool *aWillValidate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMValidityState validity; */
NS_IMETHODIMP nsDOMHTMLSelectElement::GetValidity(nsIDOMValidityState **aValidity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString validationMessage; */
NS_IMETHODIMP nsDOMHTMLSelectElement::GetValidationMessage(nsAString & aValidationMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean checkValidity (); */
NS_IMETHODIMP nsDOMHTMLSelectElement::CheckValidity(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCustomValidity (in DOMString error); */
NS_IMETHODIMP nsDOMHTMLSelectElement::SetCustomValidity(const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMHTMLSelectElement_Mozilla_2_0_Branch */
#define NS_IDOMHTMLSELECTELEMENT_MOZILLA_2_0_BRANCH_IID_STR "9b63d2d3-ccb0-4eed-a9e5-d1c142a805b7"

#define NS_IDOMHTMLSELECTELEMENT_MOZILLA_2_0_BRANCH_IID \
  {0x9b63d2d3, 0xccb0, 0x4eed, \
    { 0xa9, 0xe5, 0xd1, 0xc1, 0x42, 0xa8, 0x05, 0xb7 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLSelectElement_Mozilla_2_0_Branch : public nsIDOMHTMLSelectElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLSELECTELEMENT_MOZILLA_2_0_BRANCH_IID)

  /* attribute boolean required; */
  NS_SCRIPTABLE NS_IMETHOD GetRequired(PRBool *aRequired) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetRequired(PRBool aRequired) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLSelectElement_Mozilla_2_0_Branch, NS_IDOMHTMLSELECTELEMENT_MOZILLA_2_0_BRANCH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLSELECTELEMENT_MOZILLA_2_0_BRANCH \
  NS_SCRIPTABLE NS_IMETHOD GetRequired(PRBool *aRequired); \
  NS_SCRIPTABLE NS_IMETHOD SetRequired(PRBool aRequired); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLSELECTELEMENT_MOZILLA_2_0_BRANCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRequired(PRBool *aRequired) { return _to GetRequired(aRequired); } \
  NS_SCRIPTABLE NS_IMETHOD SetRequired(PRBool aRequired) { return _to SetRequired(aRequired); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLSELECTELEMENT_MOZILLA_2_0_BRANCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRequired(PRBool *aRequired) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequired(aRequired); } \
  NS_SCRIPTABLE NS_IMETHOD SetRequired(PRBool aRequired) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRequired(aRequired); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLSelectElement_Mozilla_2_0_Branch : public nsIDOMHTMLSelectElement_Mozilla_2_0_Branch
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLSELECTELEMENT_MOZILLA_2_0_BRANCH

  nsDOMHTMLSelectElement_Mozilla_2_0_Branch();

private:
  ~nsDOMHTMLSelectElement_Mozilla_2_0_Branch();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLSelectElement_Mozilla_2_0_Branch, nsIDOMHTMLSelectElement_Mozilla_2_0_Branch)

nsDOMHTMLSelectElement_Mozilla_2_0_Branch::nsDOMHTMLSelectElement_Mozilla_2_0_Branch()
{
  /* member initializers and constructor code */
}

nsDOMHTMLSelectElement_Mozilla_2_0_Branch::~nsDOMHTMLSelectElement_Mozilla_2_0_Branch()
{
  /* destructor code */
}

/* attribute boolean required; */
NS_IMETHODIMP nsDOMHTMLSelectElement_Mozilla_2_0_Branch::GetRequired(PRBool *aRequired)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLSelectElement_Mozilla_2_0_Branch::SetRequired(PRBool aRequired)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLSelectElement_h__ */

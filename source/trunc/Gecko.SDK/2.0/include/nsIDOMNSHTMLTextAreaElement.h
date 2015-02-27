/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/html/nsIDOMNSHTMLTextAreaElement.idl
 */

#ifndef __gen_nsIDOMNSHTMLTextAreaElement_h__
#define __gen_nsIDOMNSHTMLTextAreaElement_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIControllers; /* forward declaration */

class nsIDOMValidityState; /* forward declaration */


/* starting interface:    nsIDOMNSHTMLTextAreaElement */
#define NS_IDOMNSHTMLTEXTAREAELEMENT_IID_STR "df5dc23d-cf90-443e-bf56-cd3af021ebc7"

#define NS_IDOMNSHTMLTEXTAREAELEMENT_IID \
  {0xdf5dc23d, 0xcf90, 0x443e, \
    { 0xbf, 0x56, 0xcd, 0x3a, 0xf0, 0x21, 0xeb, 0xc7 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSHTMLTextAreaElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSHTMLTEXTAREAELEMENT_IID)

  /* attribute boolean autofocus; */
  NS_SCRIPTABLE NS_IMETHOD GetAutofocus(PRBool *aAutofocus) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAutofocus(PRBool aAutofocus) = 0;

  /* readonly attribute nsIControllers controllers; */
  NS_SCRIPTABLE NS_IMETHOD GetControllers(nsIControllers **aControllers) = 0;

  /* readonly attribute long textLength; */
  NS_SCRIPTABLE NS_IMETHOD GetTextLength(PRInt32 *aTextLength) = 0;

  /* attribute long selectionStart; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectionStart(PRInt32 *aSelectionStart) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSelectionStart(PRInt32 aSelectionStart) = 0;

  /* attribute long selectionEnd; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectionEnd(PRInt32 *aSelectionEnd) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSelectionEnd(PRInt32 aSelectionEnd) = 0;

  /* attribute long maxLength; */
  NS_SCRIPTABLE NS_IMETHOD GetMaxLength(PRInt32 *aMaxLength) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMaxLength(PRInt32 aMaxLength) = 0;

  /* attribute DOMString placeholder; */
  NS_SCRIPTABLE NS_IMETHOD GetPlaceholder(nsAString & aPlaceholder) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPlaceholder(const nsAString & aPlaceholder) = 0;

  /* attribute boolean required; */
  NS_SCRIPTABLE NS_IMETHOD GetRequired(PRBool *aRequired) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetRequired(PRBool aRequired) = 0;

  /**
   * Reflects the wrap content attribute. Possible values are "soft, "hard" and
   * "off". "soft" is the default.
   */
  /* [Null (Stringify)] attribute DOMString wrap; */
  NS_SCRIPTABLE NS_IMETHOD GetWrap(nsAString & aWrap) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetWrap(const nsAString & aWrap) = 0;

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

  /* void setSelectionRange (in long selectionStart, in long selectionEnd); */
  NS_SCRIPTABLE NS_IMETHOD SetSelectionRange(PRInt32 selectionStart, PRInt32 selectionEnd) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSHTMLTextAreaElement, NS_IDOMNSHTMLTEXTAREAELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSHTMLTEXTAREAELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetAutofocus(PRBool *aAutofocus); \
  NS_SCRIPTABLE NS_IMETHOD SetAutofocus(PRBool aAutofocus); \
  NS_SCRIPTABLE NS_IMETHOD GetControllers(nsIControllers **aControllers); \
  NS_SCRIPTABLE NS_IMETHOD GetTextLength(PRInt32 *aTextLength); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionStart(PRInt32 *aSelectionStart); \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionStart(PRInt32 aSelectionStart); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionEnd(PRInt32 *aSelectionEnd); \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionEnd(PRInt32 aSelectionEnd); \
  NS_SCRIPTABLE NS_IMETHOD GetMaxLength(PRInt32 *aMaxLength); \
  NS_SCRIPTABLE NS_IMETHOD SetMaxLength(PRInt32 aMaxLength); \
  NS_SCRIPTABLE NS_IMETHOD GetPlaceholder(nsAString & aPlaceholder); \
  NS_SCRIPTABLE NS_IMETHOD SetPlaceholder(const nsAString & aPlaceholder); \
  NS_SCRIPTABLE NS_IMETHOD GetRequired(PRBool *aRequired); \
  NS_SCRIPTABLE NS_IMETHOD SetRequired(PRBool aRequired); \
  NS_SCRIPTABLE NS_IMETHOD GetWrap(nsAString & aWrap); \
  NS_SCRIPTABLE NS_IMETHOD SetWrap(const nsAString & aWrap); \
  NS_SCRIPTABLE NS_IMETHOD GetWillValidate(PRBool *aWillValidate); \
  NS_SCRIPTABLE NS_IMETHOD GetValidity(nsIDOMValidityState **aValidity); \
  NS_SCRIPTABLE NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage); \
  NS_SCRIPTABLE NS_IMETHOD CheckValidity(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetCustomValidity(const nsAString & error); \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionRange(PRInt32 selectionStart, PRInt32 selectionEnd); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSHTMLTEXTAREAELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAutofocus(PRBool *aAutofocus) { return _to GetAutofocus(aAutofocus); } \
  NS_SCRIPTABLE NS_IMETHOD SetAutofocus(PRBool aAutofocus) { return _to SetAutofocus(aAutofocus); } \
  NS_SCRIPTABLE NS_IMETHOD GetControllers(nsIControllers **aControllers) { return _to GetControllers(aControllers); } \
  NS_SCRIPTABLE NS_IMETHOD GetTextLength(PRInt32 *aTextLength) { return _to GetTextLength(aTextLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionStart(PRInt32 *aSelectionStart) { return _to GetSelectionStart(aSelectionStart); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionStart(PRInt32 aSelectionStart) { return _to SetSelectionStart(aSelectionStart); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionEnd(PRInt32 *aSelectionEnd) { return _to GetSelectionEnd(aSelectionEnd); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionEnd(PRInt32 aSelectionEnd) { return _to SetSelectionEnd(aSelectionEnd); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaxLength(PRInt32 *aMaxLength) { return _to GetMaxLength(aMaxLength); } \
  NS_SCRIPTABLE NS_IMETHOD SetMaxLength(PRInt32 aMaxLength) { return _to SetMaxLength(aMaxLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetPlaceholder(nsAString & aPlaceholder) { return _to GetPlaceholder(aPlaceholder); } \
  NS_SCRIPTABLE NS_IMETHOD SetPlaceholder(const nsAString & aPlaceholder) { return _to SetPlaceholder(aPlaceholder); } \
  NS_SCRIPTABLE NS_IMETHOD GetRequired(PRBool *aRequired) { return _to GetRequired(aRequired); } \
  NS_SCRIPTABLE NS_IMETHOD SetRequired(PRBool aRequired) { return _to SetRequired(aRequired); } \
  NS_SCRIPTABLE NS_IMETHOD GetWrap(nsAString & aWrap) { return _to GetWrap(aWrap); } \
  NS_SCRIPTABLE NS_IMETHOD SetWrap(const nsAString & aWrap) { return _to SetWrap(aWrap); } \
  NS_SCRIPTABLE NS_IMETHOD GetWillValidate(PRBool *aWillValidate) { return _to GetWillValidate(aWillValidate); } \
  NS_SCRIPTABLE NS_IMETHOD GetValidity(nsIDOMValidityState **aValidity) { return _to GetValidity(aValidity); } \
  NS_SCRIPTABLE NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage) { return _to GetValidationMessage(aValidationMessage); } \
  NS_SCRIPTABLE NS_IMETHOD CheckValidity(PRBool *_retval NS_OUTPARAM) { return _to CheckValidity(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetCustomValidity(const nsAString & error) { return _to SetCustomValidity(error); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionRange(PRInt32 selectionStart, PRInt32 selectionEnd) { return _to SetSelectionRange(selectionStart, selectionEnd); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSHTMLTEXTAREAELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAutofocus(PRBool *aAutofocus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAutofocus(aAutofocus); } \
  NS_SCRIPTABLE NS_IMETHOD SetAutofocus(PRBool aAutofocus) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAutofocus(aAutofocus); } \
  NS_SCRIPTABLE NS_IMETHOD GetControllers(nsIControllers **aControllers) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetControllers(aControllers); } \
  NS_SCRIPTABLE NS_IMETHOD GetTextLength(PRInt32 *aTextLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextLength(aTextLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionStart(PRInt32 *aSelectionStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionStart(aSelectionStart); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionStart(PRInt32 aSelectionStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectionStart(aSelectionStart); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionEnd(PRInt32 *aSelectionEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionEnd(aSelectionEnd); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionEnd(PRInt32 aSelectionEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectionEnd(aSelectionEnd); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaxLength(PRInt32 *aMaxLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxLength(aMaxLength); } \
  NS_SCRIPTABLE NS_IMETHOD SetMaxLength(PRInt32 aMaxLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMaxLength(aMaxLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetPlaceholder(nsAString & aPlaceholder) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlaceholder(aPlaceholder); } \
  NS_SCRIPTABLE NS_IMETHOD SetPlaceholder(const nsAString & aPlaceholder) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPlaceholder(aPlaceholder); } \
  NS_SCRIPTABLE NS_IMETHOD GetRequired(PRBool *aRequired) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequired(aRequired); } \
  NS_SCRIPTABLE NS_IMETHOD SetRequired(PRBool aRequired) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRequired(aRequired); } \
  NS_SCRIPTABLE NS_IMETHOD GetWrap(nsAString & aWrap) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWrap(aWrap); } \
  NS_SCRIPTABLE NS_IMETHOD SetWrap(const nsAString & aWrap) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWrap(aWrap); } \
  NS_SCRIPTABLE NS_IMETHOD GetWillValidate(PRBool *aWillValidate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWillValidate(aWillValidate); } \
  NS_SCRIPTABLE NS_IMETHOD GetValidity(nsIDOMValidityState **aValidity) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValidity(aValidity); } \
  NS_SCRIPTABLE NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValidationMessage(aValidationMessage); } \
  NS_SCRIPTABLE NS_IMETHOD CheckValidity(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckValidity(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetCustomValidity(const nsAString & error) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCustomValidity(error); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionRange(PRInt32 selectionStart, PRInt32 selectionEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectionRange(selectionStart, selectionEnd); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSHTMLTextAreaElement : public nsIDOMNSHTMLTextAreaElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSHTMLTEXTAREAELEMENT

  nsDOMNSHTMLTextAreaElement();

private:
  ~nsDOMNSHTMLTextAreaElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSHTMLTextAreaElement, nsIDOMNSHTMLTextAreaElement)

nsDOMNSHTMLTextAreaElement::nsDOMNSHTMLTextAreaElement()
{
  /* member initializers and constructor code */
}

nsDOMNSHTMLTextAreaElement::~nsDOMNSHTMLTextAreaElement()
{
  /* destructor code */
}

/* attribute boolean autofocus; */
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::GetAutofocus(PRBool *aAutofocus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::SetAutofocus(PRBool aAutofocus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIControllers controllers; */
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::GetControllers(nsIControllers **aControllers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long textLength; */
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::GetTextLength(PRInt32 *aTextLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long selectionStart; */
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::GetSelectionStart(PRInt32 *aSelectionStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::SetSelectionStart(PRInt32 aSelectionStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long selectionEnd; */
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::GetSelectionEnd(PRInt32 *aSelectionEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::SetSelectionEnd(PRInt32 aSelectionEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long maxLength; */
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::GetMaxLength(PRInt32 *aMaxLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::SetMaxLength(PRInt32 aMaxLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString placeholder; */
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::GetPlaceholder(nsAString & aPlaceholder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::SetPlaceholder(const nsAString & aPlaceholder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean required; */
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::GetRequired(PRBool *aRequired)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::SetRequired(PRBool aRequired)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [Null (Stringify)] attribute DOMString wrap; */
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::GetWrap(nsAString & aWrap)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::SetWrap(const nsAString & aWrap)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean willValidate; */
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::GetWillValidate(PRBool *aWillValidate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMValidityState validity; */
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::GetValidity(nsIDOMValidityState **aValidity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString validationMessage; */
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::GetValidationMessage(nsAString & aValidationMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean checkValidity (); */
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::CheckValidity(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCustomValidity (in DOMString error); */
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::SetCustomValidity(const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSelectionRange (in long selectionStart, in long selectionEnd); */
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::SetSelectionRange(PRInt32 selectionStart, PRInt32 selectionEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSHTMLTextAreaElement_h__ */

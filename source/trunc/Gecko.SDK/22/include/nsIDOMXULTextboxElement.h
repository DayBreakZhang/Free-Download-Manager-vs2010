/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/xul/nsIDOMXULTextboxElement.idl
 */

#ifndef __gen_nsIDOMXULTextboxElement_h__
#define __gen_nsIDOMXULTextboxElement_h__


#ifndef __gen_nsIDOMXULLabeledControlEl_h__
#include "nsIDOMXULLabeledControlEl.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMHTMLInputElement; /* forward declaration */


/* starting interface:    nsIDOMXULTextBoxElement */
#define NS_IDOMXULTEXTBOXELEMENT_IID_STR "5bab7935-6219-45f8-9f7c-54ac8e9b023b"

#define NS_IDOMXULTEXTBOXELEMENT_IID \
  {0x5bab7935, 0x6219, 0x45f8, \
    { 0x9f, 0x7c, 0x54, 0xac, 0x8e, 0x9b, 0x02, 0x3b }}

class NS_NO_VTABLE nsIDOMXULTextBoxElement : public nsIDOMXULControlElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULTEXTBOXELEMENT_IID)

  /* readonly attribute nsIDOMNode inputField; */
  NS_IMETHOD GetInputField(nsIDOMNode * *aInputField) = 0;

  /* readonly attribute long textLength; */
  NS_IMETHOD GetTextLength(int32_t *aTextLength) = 0;

  /* attribute long maxLength; */
  NS_IMETHOD GetMaxLength(int32_t *aMaxLength) = 0;
  NS_IMETHOD SetMaxLength(int32_t aMaxLength) = 0;

  /* attribute long size; */
  NS_IMETHOD GetSize(int32_t *aSize) = 0;
  NS_IMETHOD SetSize(int32_t aSize) = 0;

  /* attribute long selectionStart; */
  NS_IMETHOD GetSelectionStart(int32_t *aSelectionStart) = 0;
  NS_IMETHOD SetSelectionStart(int32_t aSelectionStart) = 0;

  /* attribute long selectionEnd; */
  NS_IMETHOD GetSelectionEnd(int32_t *aSelectionEnd) = 0;
  NS_IMETHOD SetSelectionEnd(int32_t aSelectionEnd) = 0;

  /* attribute DOMString value; */
  NS_IMETHOD GetValue(nsAString & aValue) = 0;
  NS_IMETHOD SetValue(const nsAString & aValue) = 0;

  /* attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_IMETHOD SetType(const nsAString & aType) = 0;

  /* void select (); */
  NS_IMETHOD Select(void) = 0;

  /* void setSelectionRange (in long selectionStart, in long selectionEnd); */
  NS_IMETHOD SetSelectionRange(int32_t selectionStart, int32_t selectionEnd) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULTextBoxElement, NS_IDOMXULTEXTBOXELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULTEXTBOXELEMENT \
  NS_IMETHOD GetInputField(nsIDOMNode * *aInputField); \
  NS_IMETHOD GetTextLength(int32_t *aTextLength); \
  NS_IMETHOD GetMaxLength(int32_t *aMaxLength); \
  NS_IMETHOD SetMaxLength(int32_t aMaxLength); \
  NS_IMETHOD GetSize(int32_t *aSize); \
  NS_IMETHOD SetSize(int32_t aSize); \
  NS_IMETHOD GetSelectionStart(int32_t *aSelectionStart); \
  NS_IMETHOD SetSelectionStart(int32_t aSelectionStart); \
  NS_IMETHOD GetSelectionEnd(int32_t *aSelectionEnd); \
  NS_IMETHOD SetSelectionEnd(int32_t aSelectionEnd); \
  NS_IMETHOD GetValue(nsAString & aValue); \
  NS_IMETHOD SetValue(const nsAString & aValue); \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD SetType(const nsAString & aType); \
  NS_IMETHOD Select(void); \
  NS_IMETHOD SetSelectionRange(int32_t selectionStart, int32_t selectionEnd); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULTEXTBOXELEMENT(_to) \
  NS_IMETHOD GetInputField(nsIDOMNode * *aInputField) { return _to GetInputField(aInputField); } \
  NS_IMETHOD GetTextLength(int32_t *aTextLength) { return _to GetTextLength(aTextLength); } \
  NS_IMETHOD GetMaxLength(int32_t *aMaxLength) { return _to GetMaxLength(aMaxLength); } \
  NS_IMETHOD SetMaxLength(int32_t aMaxLength) { return _to SetMaxLength(aMaxLength); } \
  NS_IMETHOD GetSize(int32_t *aSize) { return _to GetSize(aSize); } \
  NS_IMETHOD SetSize(int32_t aSize) { return _to SetSize(aSize); } \
  NS_IMETHOD GetSelectionStart(int32_t *aSelectionStart) { return _to GetSelectionStart(aSelectionStart); } \
  NS_IMETHOD SetSelectionStart(int32_t aSelectionStart) { return _to SetSelectionStart(aSelectionStart); } \
  NS_IMETHOD GetSelectionEnd(int32_t *aSelectionEnd) { return _to GetSelectionEnd(aSelectionEnd); } \
  NS_IMETHOD SetSelectionEnd(int32_t aSelectionEnd) { return _to SetSelectionEnd(aSelectionEnd); } \
  NS_IMETHOD GetValue(nsAString & aValue) { return _to GetValue(aValue); } \
  NS_IMETHOD SetValue(const nsAString & aValue) { return _to SetValue(aValue); } \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } \
  NS_IMETHOD Select(void) { return _to Select(); } \
  NS_IMETHOD SetSelectionRange(int32_t selectionStart, int32_t selectionEnd) { return _to SetSelectionRange(selectionStart, selectionEnd); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULTEXTBOXELEMENT(_to) \
  NS_IMETHOD GetInputField(nsIDOMNode * *aInputField) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInputField(aInputField); } \
  NS_IMETHOD GetTextLength(int32_t *aTextLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextLength(aTextLength); } \
  NS_IMETHOD GetMaxLength(int32_t *aMaxLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxLength(aMaxLength); } \
  NS_IMETHOD SetMaxLength(int32_t aMaxLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMaxLength(aMaxLength); } \
  NS_IMETHOD GetSize(int32_t *aSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSize(aSize); } \
  NS_IMETHOD SetSize(int32_t aSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSize(aSize); } \
  NS_IMETHOD GetSelectionStart(int32_t *aSelectionStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionStart(aSelectionStart); } \
  NS_IMETHOD SetSelectionStart(int32_t aSelectionStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectionStart(aSelectionStart); } \
  NS_IMETHOD GetSelectionEnd(int32_t *aSelectionEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionEnd(aSelectionEnd); } \
  NS_IMETHOD SetSelectionEnd(int32_t aSelectionEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectionEnd(aSelectionEnd); } \
  NS_IMETHOD GetValue(nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_IMETHOD SetValue(const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_IMETHOD Select(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Select(); } \
  NS_IMETHOD SetSelectionRange(int32_t selectionStart, int32_t selectionEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectionRange(selectionStart, selectionEnd); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULTextBoxElement : public nsIDOMXULTextBoxElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULTEXTBOXELEMENT

  nsDOMXULTextBoxElement();

private:
  ~nsDOMXULTextBoxElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULTextBoxElement, nsIDOMXULTextBoxElement)

nsDOMXULTextBoxElement::nsDOMXULTextBoxElement()
{
  /* member initializers and constructor code */
}

nsDOMXULTextBoxElement::~nsDOMXULTextBoxElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMNode inputField; */
NS_IMETHODIMP nsDOMXULTextBoxElement::GetInputField(nsIDOMNode * *aInputField)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long textLength; */
NS_IMETHODIMP nsDOMXULTextBoxElement::GetTextLength(int32_t *aTextLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long maxLength; */
NS_IMETHODIMP nsDOMXULTextBoxElement::GetMaxLength(int32_t *aMaxLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULTextBoxElement::SetMaxLength(int32_t aMaxLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long size; */
NS_IMETHODIMP nsDOMXULTextBoxElement::GetSize(int32_t *aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULTextBoxElement::SetSize(int32_t aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long selectionStart; */
NS_IMETHODIMP nsDOMXULTextBoxElement::GetSelectionStart(int32_t *aSelectionStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULTextBoxElement::SetSelectionStart(int32_t aSelectionStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long selectionEnd; */
NS_IMETHODIMP nsDOMXULTextBoxElement::GetSelectionEnd(int32_t *aSelectionEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULTextBoxElement::SetSelectionEnd(int32_t aSelectionEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString value; */
NS_IMETHODIMP nsDOMXULTextBoxElement::GetValue(nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULTextBoxElement::SetValue(const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMXULTextBoxElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULTextBoxElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void select (); */
NS_IMETHODIMP nsDOMXULTextBoxElement::Select()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSelectionRange (in long selectionStart, in long selectionEnd); */
NS_IMETHODIMP nsDOMXULTextBoxElement::SetSelectionRange(int32_t selectionStart, int32_t selectionEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULTextboxElement_h__ */

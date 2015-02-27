/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIB2GKeyboard.idl
 */

#ifndef __gen_nsIB2GKeyboard_h__
#define __gen_nsIB2GKeyboard_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIB2GKeyboard */
#define NS_IB2GKEYBOARD_IID_STR "40ad96b2-9efa-41fb-84c7-fbcec9b153f0"

#define NS_IB2GKEYBOARD_IID \
  {0x40ad96b2, 0x9efa, 0x41fb, \
    { 0x84, 0xc7, 0xfb, 0xce, 0xc9, 0xb1, 0x53, 0xf0 }}

class NS_NO_VTABLE nsIB2GKeyboard : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IB2GKEYBOARD_IID)

  /* void sendKey (in long keyCode, in long charCode); */
  NS_IMETHOD SendKey(int32_t keyCode, int32_t charCode) = 0;

  /* void setSelectedOption (in jsval index); */
  NS_IMETHOD SetSelectedOption(JS::HandleValue index) = 0;

  /* void setSelectedOptions (in jsval indexes); */
  NS_IMETHOD SetSelectedOptions(JS::HandleValue indexes) = 0;

  /* void setValue (in jsval value); */
  NS_IMETHOD SetValue(JS::HandleValue value) = 0;

  /* void removeFocus (); */
  NS_IMETHOD RemoveFocus(void) = 0;

  /* attribute nsIDOMEventListener onfocuschange; */
  NS_IMETHOD GetOnfocuschange(nsIDOMEventListener * *aOnfocuschange) = 0;
  NS_IMETHOD SetOnfocuschange(nsIDOMEventListener *aOnfocuschange) = 0;

  /* attribute nsIDOMEventListener onselectionchange; */
  NS_IMETHOD GetOnselectionchange(nsIDOMEventListener * *aOnselectionchange) = 0;
  NS_IMETHOD SetOnselectionchange(nsIDOMEventListener *aOnselectionchange) = 0;

  /* readonly attribute long selectionStart; */
  NS_IMETHOD GetSelectionStart(int32_t *aSelectionStart) = 0;

  /* readonly attribute long selectionEnd; */
  NS_IMETHOD GetSelectionEnd(int32_t *aSelectionEnd) = 0;

  /* void setSelectionRange (in long start, in long end); */
  NS_IMETHOD SetSelectionRange(int32_t start, int32_t end) = 0;

  /* void replaceSurroundingText (in DOMString text, [optional] in long beforeLength, [optional] in long afterLength); */
  NS_IMETHOD ReplaceSurroundingText(const nsAString & text, int32_t beforeLength, int32_t afterLength) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIB2GKeyboard, NS_IB2GKEYBOARD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIB2GKEYBOARD \
  NS_IMETHOD SendKey(int32_t keyCode, int32_t charCode); \
  NS_IMETHOD SetSelectedOption(JS::HandleValue index); \
  NS_IMETHOD SetSelectedOptions(JS::HandleValue indexes); \
  NS_IMETHOD SetValue(JS::HandleValue value); \
  NS_IMETHOD RemoveFocus(void); \
  NS_IMETHOD GetOnfocuschange(nsIDOMEventListener * *aOnfocuschange); \
  NS_IMETHOD SetOnfocuschange(nsIDOMEventListener *aOnfocuschange); \
  NS_IMETHOD GetOnselectionchange(nsIDOMEventListener * *aOnselectionchange); \
  NS_IMETHOD SetOnselectionchange(nsIDOMEventListener *aOnselectionchange); \
  NS_IMETHOD GetSelectionStart(int32_t *aSelectionStart); \
  NS_IMETHOD GetSelectionEnd(int32_t *aSelectionEnd); \
  NS_IMETHOD SetSelectionRange(int32_t start, int32_t end); \
  NS_IMETHOD ReplaceSurroundingText(const nsAString & text, int32_t beforeLength, int32_t afterLength); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIB2GKEYBOARD(_to) \
  NS_IMETHOD SendKey(int32_t keyCode, int32_t charCode) { return _to SendKey(keyCode, charCode); } \
  NS_IMETHOD SetSelectedOption(JS::HandleValue index) { return _to SetSelectedOption(index); } \
  NS_IMETHOD SetSelectedOptions(JS::HandleValue indexes) { return _to SetSelectedOptions(indexes); } \
  NS_IMETHOD SetValue(JS::HandleValue value) { return _to SetValue(value); } \
  NS_IMETHOD RemoveFocus(void) { return _to RemoveFocus(); } \
  NS_IMETHOD GetOnfocuschange(nsIDOMEventListener * *aOnfocuschange) { return _to GetOnfocuschange(aOnfocuschange); } \
  NS_IMETHOD SetOnfocuschange(nsIDOMEventListener *aOnfocuschange) { return _to SetOnfocuschange(aOnfocuschange); } \
  NS_IMETHOD GetOnselectionchange(nsIDOMEventListener * *aOnselectionchange) { return _to GetOnselectionchange(aOnselectionchange); } \
  NS_IMETHOD SetOnselectionchange(nsIDOMEventListener *aOnselectionchange) { return _to SetOnselectionchange(aOnselectionchange); } \
  NS_IMETHOD GetSelectionStart(int32_t *aSelectionStart) { return _to GetSelectionStart(aSelectionStart); } \
  NS_IMETHOD GetSelectionEnd(int32_t *aSelectionEnd) { return _to GetSelectionEnd(aSelectionEnd); } \
  NS_IMETHOD SetSelectionRange(int32_t start, int32_t end) { return _to SetSelectionRange(start, end); } \
  NS_IMETHOD ReplaceSurroundingText(const nsAString & text, int32_t beforeLength, int32_t afterLength) { return _to ReplaceSurroundingText(text, beforeLength, afterLength); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIB2GKEYBOARD(_to) \
  NS_IMETHOD SendKey(int32_t keyCode, int32_t charCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendKey(keyCode, charCode); } \
  NS_IMETHOD SetSelectedOption(JS::HandleValue index) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectedOption(index); } \
  NS_IMETHOD SetSelectedOptions(JS::HandleValue indexes) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectedOptions(indexes); } \
  NS_IMETHOD SetValue(JS::HandleValue value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(value); } \
  NS_IMETHOD RemoveFocus(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveFocus(); } \
  NS_IMETHOD GetOnfocuschange(nsIDOMEventListener * *aOnfocuschange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnfocuschange(aOnfocuschange); } \
  NS_IMETHOD SetOnfocuschange(nsIDOMEventListener *aOnfocuschange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnfocuschange(aOnfocuschange); } \
  NS_IMETHOD GetOnselectionchange(nsIDOMEventListener * *aOnselectionchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnselectionchange(aOnselectionchange); } \
  NS_IMETHOD SetOnselectionchange(nsIDOMEventListener *aOnselectionchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnselectionchange(aOnselectionchange); } \
  NS_IMETHOD GetSelectionStart(int32_t *aSelectionStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionStart(aSelectionStart); } \
  NS_IMETHOD GetSelectionEnd(int32_t *aSelectionEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionEnd(aSelectionEnd); } \
  NS_IMETHOD SetSelectionRange(int32_t start, int32_t end) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectionRange(start, end); } \
  NS_IMETHOD ReplaceSurroundingText(const nsAString & text, int32_t beforeLength, int32_t afterLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceSurroundingText(text, beforeLength, afterLength); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsB2GKeyboard : public nsIB2GKeyboard
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIB2GKEYBOARD

  nsB2GKeyboard();

private:
  ~nsB2GKeyboard();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsB2GKeyboard, nsIB2GKeyboard)

nsB2GKeyboard::nsB2GKeyboard()
{
  /* member initializers and constructor code */
}

nsB2GKeyboard::~nsB2GKeyboard()
{
  /* destructor code */
}

/* void sendKey (in long keyCode, in long charCode); */
NS_IMETHODIMP nsB2GKeyboard::SendKey(int32_t keyCode, int32_t charCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSelectedOption (in jsval index); */
NS_IMETHODIMP nsB2GKeyboard::SetSelectedOption(JS::HandleValue index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSelectedOptions (in jsval indexes); */
NS_IMETHODIMP nsB2GKeyboard::SetSelectedOptions(JS::HandleValue indexes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setValue (in jsval value); */
NS_IMETHODIMP nsB2GKeyboard::SetValue(JS::HandleValue value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeFocus (); */
NS_IMETHODIMP nsB2GKeyboard::RemoveFocus()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onfocuschange; */
NS_IMETHODIMP nsB2GKeyboard::GetOnfocuschange(nsIDOMEventListener * *aOnfocuschange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsB2GKeyboard::SetOnfocuschange(nsIDOMEventListener *aOnfocuschange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onselectionchange; */
NS_IMETHODIMP nsB2GKeyboard::GetOnselectionchange(nsIDOMEventListener * *aOnselectionchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsB2GKeyboard::SetOnselectionchange(nsIDOMEventListener *aOnselectionchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long selectionStart; */
NS_IMETHODIMP nsB2GKeyboard::GetSelectionStart(int32_t *aSelectionStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long selectionEnd; */
NS_IMETHODIMP nsB2GKeyboard::GetSelectionEnd(int32_t *aSelectionEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSelectionRange (in long start, in long end); */
NS_IMETHODIMP nsB2GKeyboard::SetSelectionRange(int32_t start, int32_t end)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void replaceSurroundingText (in DOMString text, [optional] in long beforeLength, [optional] in long afterLength); */
NS_IMETHODIMP nsB2GKeyboard::ReplaceSurroundingText(const nsAString & text, int32_t beforeLength, int32_t afterLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIB2GKeyboard_h__ */

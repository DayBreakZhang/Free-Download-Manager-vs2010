/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMHTMLTitleElement.idl
 */

#ifndef __gen_nsIDOMHTMLTitleElement_h__
#define __gen_nsIDOMHTMLTitleElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLTitleElement */
#define NS_IDOMHTMLTITLEELEMENT_IID_STR "e8e5168a-e12e-4946-9fa7-5fe0d6932198"

#define NS_IDOMHTMLTITLEELEMENT_IID \
  {0xe8e5168a, 0xe12e, 0x4946, \
    { 0x9f, 0xa7, 0x5f, 0xe0, 0xd6, 0x93, 0x21, 0x98 }}

class NS_NO_VTABLE nsIDOMHTMLTitleElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLTITLEELEMENT_IID)

  /* attribute DOMString text; */
  NS_IMETHOD GetText(nsAString & aText) = 0;
  NS_IMETHOD SetText(const nsAString & aText) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLTitleElement, NS_IDOMHTMLTITLEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLTITLEELEMENT \
  NS_IMETHOD GetText(nsAString & aText); \
  NS_IMETHOD SetText(const nsAString & aText); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLTITLEELEMENT(_to) \
  NS_IMETHOD GetText(nsAString & aText) { return _to GetText(aText); } \
  NS_IMETHOD SetText(const nsAString & aText) { return _to SetText(aText); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLTITLEELEMENT(_to) \
  NS_IMETHOD GetText(nsAString & aText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetText(aText); } \
  NS_IMETHOD SetText(const nsAString & aText) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetText(aText); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLTitleElement : public nsIDOMHTMLTitleElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLTITLEELEMENT

  nsDOMHTMLTitleElement();

private:
  ~nsDOMHTMLTitleElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLTitleElement, nsIDOMHTMLTitleElement)

nsDOMHTMLTitleElement::nsDOMHTMLTitleElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLTitleElement::~nsDOMHTMLTitleElement()
{
  /* destructor code */
}

/* attribute DOMString text; */
NS_IMETHODIMP nsDOMHTMLTitleElement::GetText(nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLTitleElement::SetText(const nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLTitleElement_h__ */

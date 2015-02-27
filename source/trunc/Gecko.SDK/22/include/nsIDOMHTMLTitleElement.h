/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLTitleElement.idl
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
#define NS_IDOMHTMLTITLEELEMENT_IID_STR "5da56fa3-1a87-4931-8411-3f6be1a43178"

#define NS_IDOMHTMLTITLEELEMENT_IID \
  {0x5da56fa3, 0x1a87, 0x4931, \
    { 0x84, 0x11, 0x3f, 0x6b, 0xe1, 0xa4, 0x31, 0x78 }}

class NS_NO_VTABLE nsIDOMHTMLTitleElement : public nsIDOMHTMLElement {
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

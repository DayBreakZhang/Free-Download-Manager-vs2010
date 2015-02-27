/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLParagraphElement.idl
 */

#ifndef __gen_nsIDOMHTMLParagraphElement_h__
#define __gen_nsIDOMHTMLParagraphElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLParagraphElement */
#define NS_IDOMHTMLPARAGRAPHELEMENT_IID_STR "ccc50b61-8e2e-4e0a-be5e-0b30923051b0"

#define NS_IDOMHTMLPARAGRAPHELEMENT_IID \
  {0xccc50b61, 0x8e2e, 0x4e0a, \
    { 0xbe, 0x5e, 0x0b, 0x30, 0x92, 0x30, 0x51, 0xb0 }}

class NS_NO_VTABLE nsIDOMHTMLParagraphElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLPARAGRAPHELEMENT_IID)

  /* attribute DOMString align; */
  NS_IMETHOD GetAlign(nsAString & aAlign) = 0;
  NS_IMETHOD SetAlign(const nsAString & aAlign) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLParagraphElement, NS_IDOMHTMLPARAGRAPHELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLPARAGRAPHELEMENT \
  NS_IMETHOD GetAlign(nsAString & aAlign); \
  NS_IMETHOD SetAlign(const nsAString & aAlign); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLPARAGRAPHELEMENT(_to) \
  NS_IMETHOD GetAlign(nsAString & aAlign) { return _to GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) { return _to SetAlign(aAlign); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLPARAGRAPHELEMENT(_to) \
  NS_IMETHOD GetAlign(nsAString & aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlign(aAlign); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLParagraphElement : public nsIDOMHTMLParagraphElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLPARAGRAPHELEMENT

  nsDOMHTMLParagraphElement();

private:
  ~nsDOMHTMLParagraphElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLParagraphElement, nsIDOMHTMLParagraphElement)

nsDOMHTMLParagraphElement::nsDOMHTMLParagraphElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLParagraphElement::~nsDOMHTMLParagraphElement()
{
  /* destructor code */
}

/* attribute DOMString align; */
NS_IMETHODIMP nsDOMHTMLParagraphElement::GetAlign(nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLParagraphElement::SetAlign(const nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLParagraphElement_h__ */

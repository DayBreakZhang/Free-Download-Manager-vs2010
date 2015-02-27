/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMHTMLQuoteElement.idl
 */

#ifndef __gen_nsIDOMHTMLQuoteElement_h__
#define __gen_nsIDOMHTMLQuoteElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLQuoteElement */
#define NS_IDOMHTMLQUOTEELEMENT_IID_STR "f02502b5-32a6-4df7-8a57-1416553a3188"

#define NS_IDOMHTMLQUOTEELEMENT_IID \
  {0xf02502b5, 0x32a6, 0x4df7, \
    { 0x8a, 0x57, 0x14, 0x16, 0x55, 0x3a, 0x31, 0x88 }}

class NS_NO_VTABLE nsIDOMHTMLQuoteElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLQUOTEELEMENT_IID)

  /* attribute DOMString cite; */
  NS_IMETHOD GetCite(nsAString & aCite) = 0;
  NS_IMETHOD SetCite(const nsAString & aCite) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLQuoteElement, NS_IDOMHTMLQUOTEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLQUOTEELEMENT \
  NS_IMETHOD GetCite(nsAString & aCite); \
  NS_IMETHOD SetCite(const nsAString & aCite); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLQUOTEELEMENT(_to) \
  NS_IMETHOD GetCite(nsAString & aCite) { return _to GetCite(aCite); } \
  NS_IMETHOD SetCite(const nsAString & aCite) { return _to SetCite(aCite); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLQUOTEELEMENT(_to) \
  NS_IMETHOD GetCite(nsAString & aCite) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCite(aCite); } \
  NS_IMETHOD SetCite(const nsAString & aCite) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCite(aCite); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLQuoteElement : public nsIDOMHTMLQuoteElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLQUOTEELEMENT

  nsDOMHTMLQuoteElement();

private:
  ~nsDOMHTMLQuoteElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLQuoteElement, nsIDOMHTMLQuoteElement)

nsDOMHTMLQuoteElement::nsDOMHTMLQuoteElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLQuoteElement::~nsDOMHTMLQuoteElement()
{
  /* destructor code */
}

/* attribute DOMString cite; */
NS_IMETHODIMP nsDOMHTMLQuoteElement::GetCite(nsAString & aCite)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLQuoteElement::SetCite(const nsAString & aCite)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLQuoteElement_h__ */

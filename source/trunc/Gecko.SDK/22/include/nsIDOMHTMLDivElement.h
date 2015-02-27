/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLDivElement.idl
 */

#ifndef __gen_nsIDOMHTMLDivElement_h__
#define __gen_nsIDOMHTMLDivElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLDivElement */
#define NS_IDOMHTMLDIVELEMENT_IID_STR "a4f021dd-9e3b-4a78-a9a0-bae60f9a4cc4"

#define NS_IDOMHTMLDIVELEMENT_IID \
  {0xa4f021dd, 0x9e3b, 0x4a78, \
    { 0xa9, 0xa0, 0xba, 0xe6, 0x0f, 0x9a, 0x4c, 0xc4 }}

class NS_NO_VTABLE nsIDOMHTMLDivElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLDIVELEMENT_IID)

  /* attribute DOMString align; */
  NS_IMETHOD GetAlign(nsAString & aAlign) = 0;
  NS_IMETHOD SetAlign(const nsAString & aAlign) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLDivElement, NS_IDOMHTMLDIVELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLDIVELEMENT \
  NS_IMETHOD GetAlign(nsAString & aAlign); \
  NS_IMETHOD SetAlign(const nsAString & aAlign); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLDIVELEMENT(_to) \
  NS_IMETHOD GetAlign(nsAString & aAlign) { return _to GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) { return _to SetAlign(aAlign); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLDIVELEMENT(_to) \
  NS_IMETHOD GetAlign(nsAString & aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlign(aAlign); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLDivElement : public nsIDOMHTMLDivElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLDIVELEMENT

  nsDOMHTMLDivElement();

private:
  ~nsDOMHTMLDivElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLDivElement, nsIDOMHTMLDivElement)

nsDOMHTMLDivElement::nsDOMHTMLDivElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLDivElement::~nsDOMHTMLDivElement()
{
  /* destructor code */
}

/* attribute DOMString align; */
NS_IMETHODIMP nsDOMHTMLDivElement::GetAlign(nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLDivElement::SetAlign(const nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLDivElement_h__ */

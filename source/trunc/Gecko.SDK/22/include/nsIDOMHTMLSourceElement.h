/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLSourceElement.idl
 */

#ifndef __gen_nsIDOMHTMLSourceElement_h__
#define __gen_nsIDOMHTMLSourceElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLSourceElement */
#define NS_IDOMHTMLSOURCEELEMENT_IID_STR "333faeb7-93dc-439e-a50e-a9df705b8ba6"

#define NS_IDOMHTMLSOURCEELEMENT_IID \
  {0x333faeb7, 0x93dc, 0x439e, \
    { 0xa5, 0x0e, 0xa9, 0xdf, 0x70, 0x5b, 0x8b, 0xa6 }}

class NS_NO_VTABLE nsIDOMHTMLSourceElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLSOURCEELEMENT_IID)

  /* attribute DOMString src; */
  NS_IMETHOD GetSrc(nsAString & aSrc) = 0;
  NS_IMETHOD SetSrc(const nsAString & aSrc) = 0;

  /* attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_IMETHOD SetType(const nsAString & aType) = 0;

  /* attribute DOMString media; */
  NS_IMETHOD GetMedia(nsAString & aMedia) = 0;
  NS_IMETHOD SetMedia(const nsAString & aMedia) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLSourceElement, NS_IDOMHTMLSOURCEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLSOURCEELEMENT \
  NS_IMETHOD GetSrc(nsAString & aSrc); \
  NS_IMETHOD SetSrc(const nsAString & aSrc); \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD SetType(const nsAString & aType); \
  NS_IMETHOD GetMedia(nsAString & aMedia); \
  NS_IMETHOD SetMedia(const nsAString & aMedia); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLSOURCEELEMENT(_to) \
  NS_IMETHOD GetSrc(nsAString & aSrc) { return _to GetSrc(aSrc); } \
  NS_IMETHOD SetSrc(const nsAString & aSrc) { return _to SetSrc(aSrc); } \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } \
  NS_IMETHOD GetMedia(nsAString & aMedia) { return _to GetMedia(aMedia); } \
  NS_IMETHOD SetMedia(const nsAString & aMedia) { return _to SetMedia(aMedia); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLSOURCEELEMENT(_to) \
  NS_IMETHOD GetSrc(nsAString & aSrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSrc(aSrc); } \
  NS_IMETHOD SetSrc(const nsAString & aSrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSrc(aSrc); } \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_IMETHOD GetMedia(nsAString & aMedia) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMedia(aMedia); } \
  NS_IMETHOD SetMedia(const nsAString & aMedia) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMedia(aMedia); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLSourceElement : public nsIDOMHTMLSourceElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLSOURCEELEMENT

  nsDOMHTMLSourceElement();

private:
  ~nsDOMHTMLSourceElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLSourceElement, nsIDOMHTMLSourceElement)

nsDOMHTMLSourceElement::nsDOMHTMLSourceElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLSourceElement::~nsDOMHTMLSourceElement()
{
  /* destructor code */
}

/* attribute DOMString src; */
NS_IMETHODIMP nsDOMHTMLSourceElement::GetSrc(nsAString & aSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLSourceElement::SetSrc(const nsAString & aSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMHTMLSourceElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLSourceElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString media; */
NS_IMETHODIMP nsDOMHTMLSourceElement::GetMedia(nsAString & aMedia)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLSourceElement::SetMedia(const nsAString & aMedia)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLSourceElement_h__ */

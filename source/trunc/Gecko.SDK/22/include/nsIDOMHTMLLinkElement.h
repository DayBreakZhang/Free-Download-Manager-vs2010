/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLLinkElement.idl
 */

#ifndef __gen_nsIDOMHTMLLinkElement_h__
#define __gen_nsIDOMHTMLLinkElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLLinkElement */
#define NS_IDOMHTMLLINKELEMENT_IID_STR "ca856a0b-6786-4123-90fe-dc9c7600274e"

#define NS_IDOMHTMLLINKELEMENT_IID \
  {0xca856a0b, 0x6786, 0x4123, \
    { 0x90, 0xfe, 0xdc, 0x9c, 0x76, 0x00, 0x27, 0x4e }}

class NS_NO_VTABLE nsIDOMHTMLLinkElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLLINKELEMENT_IID)

  /* [binaryname(MozDisabled)] attribute boolean disabled; */
  NS_IMETHOD GetMozDisabled(bool *aDisabled) = 0;
  NS_IMETHOD SetMozDisabled(bool aDisabled) = 0;

  /* attribute DOMString charset; */
  NS_IMETHOD GetCharset(nsAString & aCharset) = 0;
  NS_IMETHOD SetCharset(const nsAString & aCharset) = 0;

  /* attribute DOMString href; */
  NS_IMETHOD GetHref(nsAString & aHref) = 0;
  NS_IMETHOD SetHref(const nsAString & aHref) = 0;

  /* attribute DOMString hreflang; */
  NS_IMETHOD GetHreflang(nsAString & aHreflang) = 0;
  NS_IMETHOD SetHreflang(const nsAString & aHreflang) = 0;

  /* attribute DOMString media; */
  NS_IMETHOD GetMedia(nsAString & aMedia) = 0;
  NS_IMETHOD SetMedia(const nsAString & aMedia) = 0;

  /* attribute DOMString rel; */
  NS_IMETHOD GetRel(nsAString & aRel) = 0;
  NS_IMETHOD SetRel(const nsAString & aRel) = 0;

  /* attribute DOMString rev; */
  NS_IMETHOD GetRev(nsAString & aRev) = 0;
  NS_IMETHOD SetRev(const nsAString & aRev) = 0;

  /* attribute DOMString target; */
  NS_IMETHOD GetTarget(nsAString & aTarget) = 0;
  NS_IMETHOD SetTarget(const nsAString & aTarget) = 0;

  /* attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_IMETHOD SetType(const nsAString & aType) = 0;

  /* attribute DOMString crossOrigin; */
  NS_IMETHOD GetCrossOrigin(nsAString & aCrossOrigin) = 0;
  NS_IMETHOD SetCrossOrigin(const nsAString & aCrossOrigin) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLLinkElement, NS_IDOMHTMLLINKELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLLINKELEMENT \
  NS_IMETHOD GetMozDisabled(bool *aDisabled); \
  NS_IMETHOD SetMozDisabled(bool aDisabled); \
  NS_IMETHOD GetCharset(nsAString & aCharset); \
  NS_IMETHOD SetCharset(const nsAString & aCharset); \
  NS_IMETHOD GetHref(nsAString & aHref); \
  NS_IMETHOD SetHref(const nsAString & aHref); \
  NS_IMETHOD GetHreflang(nsAString & aHreflang); \
  NS_IMETHOD SetHreflang(const nsAString & aHreflang); \
  NS_IMETHOD GetMedia(nsAString & aMedia); \
  NS_IMETHOD SetMedia(const nsAString & aMedia); \
  NS_IMETHOD GetRel(nsAString & aRel); \
  NS_IMETHOD SetRel(const nsAString & aRel); \
  NS_IMETHOD GetRev(nsAString & aRev); \
  NS_IMETHOD SetRev(const nsAString & aRev); \
  NS_IMETHOD GetTarget(nsAString & aTarget); \
  NS_IMETHOD SetTarget(const nsAString & aTarget); \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD SetType(const nsAString & aType); \
  NS_IMETHOD GetCrossOrigin(nsAString & aCrossOrigin); \
  NS_IMETHOD SetCrossOrigin(const nsAString & aCrossOrigin); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLLINKELEMENT(_to) \
  NS_IMETHOD GetMozDisabled(bool *aDisabled) { return _to GetMozDisabled(aDisabled); } \
  NS_IMETHOD SetMozDisabled(bool aDisabled) { return _to SetMozDisabled(aDisabled); } \
  NS_IMETHOD GetCharset(nsAString & aCharset) { return _to GetCharset(aCharset); } \
  NS_IMETHOD SetCharset(const nsAString & aCharset) { return _to SetCharset(aCharset); } \
  NS_IMETHOD GetHref(nsAString & aHref) { return _to GetHref(aHref); } \
  NS_IMETHOD SetHref(const nsAString & aHref) { return _to SetHref(aHref); } \
  NS_IMETHOD GetHreflang(nsAString & aHreflang) { return _to GetHreflang(aHreflang); } \
  NS_IMETHOD SetHreflang(const nsAString & aHreflang) { return _to SetHreflang(aHreflang); } \
  NS_IMETHOD GetMedia(nsAString & aMedia) { return _to GetMedia(aMedia); } \
  NS_IMETHOD SetMedia(const nsAString & aMedia) { return _to SetMedia(aMedia); } \
  NS_IMETHOD GetRel(nsAString & aRel) { return _to GetRel(aRel); } \
  NS_IMETHOD SetRel(const nsAString & aRel) { return _to SetRel(aRel); } \
  NS_IMETHOD GetRev(nsAString & aRev) { return _to GetRev(aRev); } \
  NS_IMETHOD SetRev(const nsAString & aRev) { return _to SetRev(aRev); } \
  NS_IMETHOD GetTarget(nsAString & aTarget) { return _to GetTarget(aTarget); } \
  NS_IMETHOD SetTarget(const nsAString & aTarget) { return _to SetTarget(aTarget); } \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } \
  NS_IMETHOD GetCrossOrigin(nsAString & aCrossOrigin) { return _to GetCrossOrigin(aCrossOrigin); } \
  NS_IMETHOD SetCrossOrigin(const nsAString & aCrossOrigin) { return _to SetCrossOrigin(aCrossOrigin); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLLINKELEMENT(_to) \
  NS_IMETHOD GetMozDisabled(bool *aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozDisabled(aDisabled); } \
  NS_IMETHOD SetMozDisabled(bool aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMozDisabled(aDisabled); } \
  NS_IMETHOD GetCharset(nsAString & aCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharset(aCharset); } \
  NS_IMETHOD SetCharset(const nsAString & aCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCharset(aCharset); } \
  NS_IMETHOD GetHref(nsAString & aHref) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHref(aHref); } \
  NS_IMETHOD SetHref(const nsAString & aHref) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHref(aHref); } \
  NS_IMETHOD GetHreflang(nsAString & aHreflang) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHreflang(aHreflang); } \
  NS_IMETHOD SetHreflang(const nsAString & aHreflang) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHreflang(aHreflang); } \
  NS_IMETHOD GetMedia(nsAString & aMedia) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMedia(aMedia); } \
  NS_IMETHOD SetMedia(const nsAString & aMedia) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMedia(aMedia); } \
  NS_IMETHOD GetRel(nsAString & aRel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRel(aRel); } \
  NS_IMETHOD SetRel(const nsAString & aRel) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRel(aRel); } \
  NS_IMETHOD GetRev(nsAString & aRev) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRev(aRev); } \
  NS_IMETHOD SetRev(const nsAString & aRev) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRev(aRev); } \
  NS_IMETHOD GetTarget(nsAString & aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTarget(aTarget); } \
  NS_IMETHOD SetTarget(const nsAString & aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTarget(aTarget); } \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_IMETHOD GetCrossOrigin(nsAString & aCrossOrigin) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCrossOrigin(aCrossOrigin); } \
  NS_IMETHOD SetCrossOrigin(const nsAString & aCrossOrigin) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCrossOrigin(aCrossOrigin); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLLinkElement : public nsIDOMHTMLLinkElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLLINKELEMENT

  nsDOMHTMLLinkElement();

private:
  ~nsDOMHTMLLinkElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLLinkElement, nsIDOMHTMLLinkElement)

nsDOMHTMLLinkElement::nsDOMHTMLLinkElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLLinkElement::~nsDOMHTMLLinkElement()
{
  /* destructor code */
}

/* [binaryname(MozDisabled)] attribute boolean disabled; */
NS_IMETHODIMP nsDOMHTMLLinkElement::GetMozDisabled(bool *aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLLinkElement::SetMozDisabled(bool aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString charset; */
NS_IMETHODIMP nsDOMHTMLLinkElement::GetCharset(nsAString & aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLLinkElement::SetCharset(const nsAString & aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString href; */
NS_IMETHODIMP nsDOMHTMLLinkElement::GetHref(nsAString & aHref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLLinkElement::SetHref(const nsAString & aHref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString hreflang; */
NS_IMETHODIMP nsDOMHTMLLinkElement::GetHreflang(nsAString & aHreflang)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLLinkElement::SetHreflang(const nsAString & aHreflang)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString media; */
NS_IMETHODIMP nsDOMHTMLLinkElement::GetMedia(nsAString & aMedia)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLLinkElement::SetMedia(const nsAString & aMedia)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString rel; */
NS_IMETHODIMP nsDOMHTMLLinkElement::GetRel(nsAString & aRel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLLinkElement::SetRel(const nsAString & aRel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString rev; */
NS_IMETHODIMP nsDOMHTMLLinkElement::GetRev(nsAString & aRev)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLLinkElement::SetRev(const nsAString & aRev)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString target; */
NS_IMETHODIMP nsDOMHTMLLinkElement::GetTarget(nsAString & aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLLinkElement::SetTarget(const nsAString & aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMHTMLLinkElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLLinkElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString crossOrigin; */
NS_IMETHODIMP nsDOMHTMLLinkElement::GetCrossOrigin(nsAString & aCrossOrigin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLLinkElement::SetCrossOrigin(const nsAString & aCrossOrigin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLLinkElement_h__ */

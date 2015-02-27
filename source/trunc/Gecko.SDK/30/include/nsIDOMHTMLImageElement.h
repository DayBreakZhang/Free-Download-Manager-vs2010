/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMHTMLImageElement.idl
 */

#ifndef __gen_nsIDOMHTMLImageElement_h__
#define __gen_nsIDOMHTMLImageElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLImageElement */
#define NS_IDOMHTMLIMAGEELEMENT_IID_STR "d3e488b9-3b29-410a-bcf4-18fb874c170a"

#define NS_IDOMHTMLIMAGEELEMENT_IID \
  {0xd3e488b9, 0x3b29, 0x410a, \
    { 0xbc, 0xf4, 0x18, 0xfb, 0x87, 0x4c, 0x17, 0x0a }}

class NS_NO_VTABLE nsIDOMHTMLImageElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLIMAGEELEMENT_IID)

  /* attribute DOMString alt; */
  NS_IMETHOD GetAlt(nsAString & aAlt) = 0;
  NS_IMETHOD SetAlt(const nsAString & aAlt) = 0;

  /* attribute DOMString src; */
  NS_IMETHOD GetSrc(nsAString & aSrc) = 0;
  NS_IMETHOD SetSrc(const nsAString & aSrc) = 0;

  /* attribute DOMString crossOrigin; */
  NS_IMETHOD GetCrossOrigin(nsAString & aCrossOrigin) = 0;
  NS_IMETHOD SetCrossOrigin(const nsAString & aCrossOrigin) = 0;

  /* attribute DOMString useMap; */
  NS_IMETHOD GetUseMap(nsAString & aUseMap) = 0;
  NS_IMETHOD SetUseMap(const nsAString & aUseMap) = 0;

  /* attribute boolean isMap; */
  NS_IMETHOD GetIsMap(bool *aIsMap) = 0;
  NS_IMETHOD SetIsMap(bool aIsMap) = 0;

  /* attribute unsigned long width; */
  NS_IMETHOD GetWidth(uint32_t *aWidth) = 0;
  NS_IMETHOD SetWidth(uint32_t aWidth) = 0;

  /* attribute unsigned long height; */
  NS_IMETHOD GetHeight(uint32_t *aHeight) = 0;
  NS_IMETHOD SetHeight(uint32_t aHeight) = 0;

  /* readonly attribute unsigned long naturalWidth; */
  NS_IMETHOD GetNaturalWidth(uint32_t *aNaturalWidth) = 0;

  /* readonly attribute unsigned long naturalHeight; */
  NS_IMETHOD GetNaturalHeight(uint32_t *aNaturalHeight) = 0;

  /* readonly attribute boolean complete; */
  NS_IMETHOD GetComplete(bool *aComplete) = 0;

  /* attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_IMETHOD SetName(const nsAString & aName) = 0;

  /* attribute DOMString align; */
  NS_IMETHOD GetAlign(nsAString & aAlign) = 0;
  NS_IMETHOD SetAlign(const nsAString & aAlign) = 0;

  /* attribute DOMString border; */
  NS_IMETHOD GetBorder(nsAString & aBorder) = 0;
  NS_IMETHOD SetBorder(const nsAString & aBorder) = 0;

  /* attribute long hspace; */
  NS_IMETHOD GetHspace(int32_t *aHspace) = 0;
  NS_IMETHOD SetHspace(int32_t aHspace) = 0;

  /* attribute DOMString longDesc; */
  NS_IMETHOD GetLongDesc(nsAString & aLongDesc) = 0;
  NS_IMETHOD SetLongDesc(const nsAString & aLongDesc) = 0;

  /* attribute long vspace; */
  NS_IMETHOD GetVspace(int32_t *aVspace) = 0;
  NS_IMETHOD SetVspace(int32_t aVspace) = 0;

  /* attribute DOMString lowsrc; */
  NS_IMETHOD GetLowsrc(nsAString & aLowsrc) = 0;
  NS_IMETHOD SetLowsrc(const nsAString & aLowsrc) = 0;

  /* readonly attribute long x; */
  NS_IMETHOD GetX(int32_t *aX) = 0;

  /* readonly attribute long y; */
  NS_IMETHOD GetY(int32_t *aY) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLImageElement, NS_IDOMHTMLIMAGEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLIMAGEELEMENT \
  NS_IMETHOD GetAlt(nsAString & aAlt); \
  NS_IMETHOD SetAlt(const nsAString & aAlt); \
  NS_IMETHOD GetSrc(nsAString & aSrc); \
  NS_IMETHOD SetSrc(const nsAString & aSrc); \
  NS_IMETHOD GetCrossOrigin(nsAString & aCrossOrigin); \
  NS_IMETHOD SetCrossOrigin(const nsAString & aCrossOrigin); \
  NS_IMETHOD GetUseMap(nsAString & aUseMap); \
  NS_IMETHOD SetUseMap(const nsAString & aUseMap); \
  NS_IMETHOD GetIsMap(bool *aIsMap); \
  NS_IMETHOD SetIsMap(bool aIsMap); \
  NS_IMETHOD GetWidth(uint32_t *aWidth); \
  NS_IMETHOD SetWidth(uint32_t aWidth); \
  NS_IMETHOD GetHeight(uint32_t *aHeight); \
  NS_IMETHOD SetHeight(uint32_t aHeight); \
  NS_IMETHOD GetNaturalWidth(uint32_t *aNaturalWidth); \
  NS_IMETHOD GetNaturalHeight(uint32_t *aNaturalHeight); \
  NS_IMETHOD GetComplete(bool *aComplete); \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD SetName(const nsAString & aName); \
  NS_IMETHOD GetAlign(nsAString & aAlign); \
  NS_IMETHOD SetAlign(const nsAString & aAlign); \
  NS_IMETHOD GetBorder(nsAString & aBorder); \
  NS_IMETHOD SetBorder(const nsAString & aBorder); \
  NS_IMETHOD GetHspace(int32_t *aHspace); \
  NS_IMETHOD SetHspace(int32_t aHspace); \
  NS_IMETHOD GetLongDesc(nsAString & aLongDesc); \
  NS_IMETHOD SetLongDesc(const nsAString & aLongDesc); \
  NS_IMETHOD GetVspace(int32_t *aVspace); \
  NS_IMETHOD SetVspace(int32_t aVspace); \
  NS_IMETHOD GetLowsrc(nsAString & aLowsrc); \
  NS_IMETHOD SetLowsrc(const nsAString & aLowsrc); \
  NS_IMETHOD GetX(int32_t *aX); \
  NS_IMETHOD GetY(int32_t *aY); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLIMAGEELEMENT(_to) \
  NS_IMETHOD GetAlt(nsAString & aAlt) { return _to GetAlt(aAlt); } \
  NS_IMETHOD SetAlt(const nsAString & aAlt) { return _to SetAlt(aAlt); } \
  NS_IMETHOD GetSrc(nsAString & aSrc) { return _to GetSrc(aSrc); } \
  NS_IMETHOD SetSrc(const nsAString & aSrc) { return _to SetSrc(aSrc); } \
  NS_IMETHOD GetCrossOrigin(nsAString & aCrossOrigin) { return _to GetCrossOrigin(aCrossOrigin); } \
  NS_IMETHOD SetCrossOrigin(const nsAString & aCrossOrigin) { return _to SetCrossOrigin(aCrossOrigin); } \
  NS_IMETHOD GetUseMap(nsAString & aUseMap) { return _to GetUseMap(aUseMap); } \
  NS_IMETHOD SetUseMap(const nsAString & aUseMap) { return _to SetUseMap(aUseMap); } \
  NS_IMETHOD GetIsMap(bool *aIsMap) { return _to GetIsMap(aIsMap); } \
  NS_IMETHOD SetIsMap(bool aIsMap) { return _to SetIsMap(aIsMap); } \
  NS_IMETHOD GetWidth(uint32_t *aWidth) { return _to GetWidth(aWidth); } \
  NS_IMETHOD SetWidth(uint32_t aWidth) { return _to SetWidth(aWidth); } \
  NS_IMETHOD GetHeight(uint32_t *aHeight) { return _to GetHeight(aHeight); } \
  NS_IMETHOD SetHeight(uint32_t aHeight) { return _to SetHeight(aHeight); } \
  NS_IMETHOD GetNaturalWidth(uint32_t *aNaturalWidth) { return _to GetNaturalWidth(aNaturalWidth); } \
  NS_IMETHOD GetNaturalHeight(uint32_t *aNaturalHeight) { return _to GetNaturalHeight(aNaturalHeight); } \
  NS_IMETHOD GetComplete(bool *aComplete) { return _to GetComplete(aComplete); } \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) { return _to SetName(aName); } \
  NS_IMETHOD GetAlign(nsAString & aAlign) { return _to GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) { return _to SetAlign(aAlign); } \
  NS_IMETHOD GetBorder(nsAString & aBorder) { return _to GetBorder(aBorder); } \
  NS_IMETHOD SetBorder(const nsAString & aBorder) { return _to SetBorder(aBorder); } \
  NS_IMETHOD GetHspace(int32_t *aHspace) { return _to GetHspace(aHspace); } \
  NS_IMETHOD SetHspace(int32_t aHspace) { return _to SetHspace(aHspace); } \
  NS_IMETHOD GetLongDesc(nsAString & aLongDesc) { return _to GetLongDesc(aLongDesc); } \
  NS_IMETHOD SetLongDesc(const nsAString & aLongDesc) { return _to SetLongDesc(aLongDesc); } \
  NS_IMETHOD GetVspace(int32_t *aVspace) { return _to GetVspace(aVspace); } \
  NS_IMETHOD SetVspace(int32_t aVspace) { return _to SetVspace(aVspace); } \
  NS_IMETHOD GetLowsrc(nsAString & aLowsrc) { return _to GetLowsrc(aLowsrc); } \
  NS_IMETHOD SetLowsrc(const nsAString & aLowsrc) { return _to SetLowsrc(aLowsrc); } \
  NS_IMETHOD GetX(int32_t *aX) { return _to GetX(aX); } \
  NS_IMETHOD GetY(int32_t *aY) { return _to GetY(aY); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLIMAGEELEMENT(_to) \
  NS_IMETHOD GetAlt(nsAString & aAlt) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlt(aAlt); } \
  NS_IMETHOD SetAlt(const nsAString & aAlt) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlt(aAlt); } \
  NS_IMETHOD GetSrc(nsAString & aSrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSrc(aSrc); } \
  NS_IMETHOD SetSrc(const nsAString & aSrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSrc(aSrc); } \
  NS_IMETHOD GetCrossOrigin(nsAString & aCrossOrigin) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCrossOrigin(aCrossOrigin); } \
  NS_IMETHOD SetCrossOrigin(const nsAString & aCrossOrigin) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCrossOrigin(aCrossOrigin); } \
  NS_IMETHOD GetUseMap(nsAString & aUseMap) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUseMap(aUseMap); } \
  NS_IMETHOD SetUseMap(const nsAString & aUseMap) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUseMap(aUseMap); } \
  NS_IMETHOD GetIsMap(bool *aIsMap) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsMap(aIsMap); } \
  NS_IMETHOD SetIsMap(bool aIsMap) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsMap(aIsMap); } \
  NS_IMETHOD GetWidth(uint32_t *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD SetWidth(uint32_t aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWidth(aWidth); } \
  NS_IMETHOD GetHeight(uint32_t *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_IMETHOD SetHeight(uint32_t aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHeight(aHeight); } \
  NS_IMETHOD GetNaturalWidth(uint32_t *aNaturalWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNaturalWidth(aNaturalWidth); } \
  NS_IMETHOD GetNaturalHeight(uint32_t *aNaturalHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNaturalHeight(aNaturalHeight); } \
  NS_IMETHOD GetComplete(bool *aComplete) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetComplete(aComplete); } \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_IMETHOD GetAlign(nsAString & aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlign(aAlign); } \
  NS_IMETHOD GetBorder(nsAString & aBorder) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBorder(aBorder); } \
  NS_IMETHOD SetBorder(const nsAString & aBorder) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBorder(aBorder); } \
  NS_IMETHOD GetHspace(int32_t *aHspace) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHspace(aHspace); } \
  NS_IMETHOD SetHspace(int32_t aHspace) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHspace(aHspace); } \
  NS_IMETHOD GetLongDesc(nsAString & aLongDesc) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLongDesc(aLongDesc); } \
  NS_IMETHOD SetLongDesc(const nsAString & aLongDesc) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLongDesc(aLongDesc); } \
  NS_IMETHOD GetVspace(int32_t *aVspace) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVspace(aVspace); } \
  NS_IMETHOD SetVspace(int32_t aVspace) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVspace(aVspace); } \
  NS_IMETHOD GetLowsrc(nsAString & aLowsrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLowsrc(aLowsrc); } \
  NS_IMETHOD SetLowsrc(const nsAString & aLowsrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLowsrc(aLowsrc); } \
  NS_IMETHOD GetX(int32_t *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_IMETHOD GetY(int32_t *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLImageElement : public nsIDOMHTMLImageElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLIMAGEELEMENT

  nsDOMHTMLImageElement();

private:
  ~nsDOMHTMLImageElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLImageElement, nsIDOMHTMLImageElement)

nsDOMHTMLImageElement::nsDOMHTMLImageElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLImageElement::~nsDOMHTMLImageElement()
{
  /* destructor code */
}

/* attribute DOMString alt; */
NS_IMETHODIMP nsDOMHTMLImageElement::GetAlt(nsAString & aAlt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLImageElement::SetAlt(const nsAString & aAlt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString src; */
NS_IMETHODIMP nsDOMHTMLImageElement::GetSrc(nsAString & aSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLImageElement::SetSrc(const nsAString & aSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString crossOrigin; */
NS_IMETHODIMP nsDOMHTMLImageElement::GetCrossOrigin(nsAString & aCrossOrigin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLImageElement::SetCrossOrigin(const nsAString & aCrossOrigin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString useMap; */
NS_IMETHODIMP nsDOMHTMLImageElement::GetUseMap(nsAString & aUseMap)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLImageElement::SetUseMap(const nsAString & aUseMap)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isMap; */
NS_IMETHODIMP nsDOMHTMLImageElement::GetIsMap(bool *aIsMap)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLImageElement::SetIsMap(bool aIsMap)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long width; */
NS_IMETHODIMP nsDOMHTMLImageElement::GetWidth(uint32_t *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLImageElement::SetWidth(uint32_t aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long height; */
NS_IMETHODIMP nsDOMHTMLImageElement::GetHeight(uint32_t *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLImageElement::SetHeight(uint32_t aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long naturalWidth; */
NS_IMETHODIMP nsDOMHTMLImageElement::GetNaturalWidth(uint32_t *aNaturalWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long naturalHeight; */
NS_IMETHODIMP nsDOMHTMLImageElement::GetNaturalHeight(uint32_t *aNaturalHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean complete; */
NS_IMETHODIMP nsDOMHTMLImageElement::GetComplete(bool *aComplete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString name; */
NS_IMETHODIMP nsDOMHTMLImageElement::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLImageElement::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString align; */
NS_IMETHODIMP nsDOMHTMLImageElement::GetAlign(nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLImageElement::SetAlign(const nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString border; */
NS_IMETHODIMP nsDOMHTMLImageElement::GetBorder(nsAString & aBorder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLImageElement::SetBorder(const nsAString & aBorder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long hspace; */
NS_IMETHODIMP nsDOMHTMLImageElement::GetHspace(int32_t *aHspace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLImageElement::SetHspace(int32_t aHspace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString longDesc; */
NS_IMETHODIMP nsDOMHTMLImageElement::GetLongDesc(nsAString & aLongDesc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLImageElement::SetLongDesc(const nsAString & aLongDesc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long vspace; */
NS_IMETHODIMP nsDOMHTMLImageElement::GetVspace(int32_t *aVspace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLImageElement::SetVspace(int32_t aVspace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString lowsrc; */
NS_IMETHODIMP nsDOMHTMLImageElement::GetLowsrc(nsAString & aLowsrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLImageElement::SetLowsrc(const nsAString & aLowsrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long x; */
NS_IMETHODIMP nsDOMHTMLImageElement::GetX(int32_t *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long y; */
NS_IMETHODIMP nsDOMHTMLImageElement::GetY(int32_t *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLImageElement_h__ */

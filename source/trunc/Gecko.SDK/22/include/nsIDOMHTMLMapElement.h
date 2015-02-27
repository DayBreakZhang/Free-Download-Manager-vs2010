/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLMapElement.idl
 */

#ifndef __gen_nsIDOMHTMLMapElement_h__
#define __gen_nsIDOMHTMLMapElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLMapElement */
#define NS_IDOMHTMLMAPELEMENT_IID_STR "4b2136a3-f296-479a-88dc-ed4421eb3a22"

#define NS_IDOMHTMLMAPELEMENT_IID \
  {0x4b2136a3, 0xf296, 0x479a, \
    { 0x88, 0xdc, 0xed, 0x44, 0x21, 0xeb, 0x3a, 0x22 }}

class NS_NO_VTABLE nsIDOMHTMLMapElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLMAPELEMENT_IID)

  /* readonly attribute nsIDOMHTMLCollection areas; */
  NS_IMETHOD GetAreas(nsIDOMHTMLCollection * *aAreas) = 0;

  /* attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_IMETHOD SetName(const nsAString & aName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLMapElement, NS_IDOMHTMLMAPELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLMAPELEMENT \
  NS_IMETHOD GetAreas(nsIDOMHTMLCollection * *aAreas); \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD SetName(const nsAString & aName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLMAPELEMENT(_to) \
  NS_IMETHOD GetAreas(nsIDOMHTMLCollection * *aAreas) { return _to GetAreas(aAreas); } \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) { return _to SetName(aName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLMAPELEMENT(_to) \
  NS_IMETHOD GetAreas(nsIDOMHTMLCollection * *aAreas) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAreas(aAreas); } \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLMapElement : public nsIDOMHTMLMapElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLMAPELEMENT

  nsDOMHTMLMapElement();

private:
  ~nsDOMHTMLMapElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLMapElement, nsIDOMHTMLMapElement)

nsDOMHTMLMapElement::nsDOMHTMLMapElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLMapElement::~nsDOMHTMLMapElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMHTMLCollection areas; */
NS_IMETHODIMP nsDOMHTMLMapElement::GetAreas(nsIDOMHTMLCollection * *aAreas)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString name; */
NS_IMETHODIMP nsDOMHTMLMapElement::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMapElement::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLMapElement_h__ */

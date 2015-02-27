/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLMenuElement.idl
 */

#ifndef __gen_nsIDOMHTMLMenuElement_h__
#define __gen_nsIDOMHTMLMenuElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLMenuElement */
#define NS_IDOMHTMLMENUELEMENT_IID_STR "6790c2f5-01ac-43ba-9145-dd2052e3b0c7"

#define NS_IDOMHTMLMENUELEMENT_IID \
  {0x6790c2f5, 0x01ac, 0x43ba, \
    { 0x91, 0x45, 0xdd, 0x20, 0x52, 0xe3, 0xb0, 0xc7 }}

class NS_NO_VTABLE nsIDOMHTMLMenuElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLMENUELEMENT_IID)

  /* attribute boolean compact; */
  NS_IMETHOD GetCompact(bool *aCompact) = 0;
  NS_IMETHOD SetCompact(bool aCompact) = 0;

  /* attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_IMETHOD SetType(const nsAString & aType) = 0;

  /* attribute DOMString label; */
  NS_IMETHOD GetLabel(nsAString & aLabel) = 0;
  NS_IMETHOD SetLabel(const nsAString & aLabel) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLMenuElement, NS_IDOMHTMLMENUELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLMENUELEMENT \
  NS_IMETHOD GetCompact(bool *aCompact); \
  NS_IMETHOD SetCompact(bool aCompact); \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD SetType(const nsAString & aType); \
  NS_IMETHOD GetLabel(nsAString & aLabel); \
  NS_IMETHOD SetLabel(const nsAString & aLabel); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLMENUELEMENT(_to) \
  NS_IMETHOD GetCompact(bool *aCompact) { return _to GetCompact(aCompact); } \
  NS_IMETHOD SetCompact(bool aCompact) { return _to SetCompact(aCompact); } \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } \
  NS_IMETHOD GetLabel(nsAString & aLabel) { return _to GetLabel(aLabel); } \
  NS_IMETHOD SetLabel(const nsAString & aLabel) { return _to SetLabel(aLabel); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLMENUELEMENT(_to) \
  NS_IMETHOD GetCompact(bool *aCompact) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCompact(aCompact); } \
  NS_IMETHOD SetCompact(bool aCompact) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCompact(aCompact); } \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_IMETHOD GetLabel(nsAString & aLabel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLabel(aLabel); } \
  NS_IMETHOD SetLabel(const nsAString & aLabel) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLabel(aLabel); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLMenuElement : public nsIDOMHTMLMenuElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLMENUELEMENT

  nsDOMHTMLMenuElement();

private:
  ~nsDOMHTMLMenuElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLMenuElement, nsIDOMHTMLMenuElement)

nsDOMHTMLMenuElement::nsDOMHTMLMenuElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLMenuElement::~nsDOMHTMLMenuElement()
{
  /* destructor code */
}

/* attribute boolean compact; */
NS_IMETHODIMP nsDOMHTMLMenuElement::GetCompact(bool *aCompact)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMenuElement::SetCompact(bool aCompact)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMHTMLMenuElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMenuElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString label; */
NS_IMETHODIMP nsDOMHTMLMenuElement::GetLabel(nsAString & aLabel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMenuElement::SetLabel(const nsAString & aLabel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLMenuElement_h__ */

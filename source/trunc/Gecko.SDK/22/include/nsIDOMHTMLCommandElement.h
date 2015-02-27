/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLCommandElement.idl
 */

#ifndef __gen_nsIDOMHTMLCommandElement_h__
#define __gen_nsIDOMHTMLCommandElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLCommandElement */
#define NS_IDOMHTMLCOMMANDELEMENT_IID_STR "97efa08f-8b7f-41bd-8be6-b806eb48b08c"

#define NS_IDOMHTMLCOMMANDELEMENT_IID \
  {0x97efa08f, 0x8b7f, 0x41bd, \
    { 0x8b, 0xe6, 0xb8, 0x06, 0xeb, 0x48, 0xb0, 0x8c }}

class NS_NO_VTABLE nsIDOMHTMLCommandElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLCOMMANDELEMENT_IID)

  /* attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_IMETHOD SetType(const nsAString & aType) = 0;

  /* attribute DOMString label; */
  NS_IMETHOD GetLabel(nsAString & aLabel) = 0;
  NS_IMETHOD SetLabel(const nsAString & aLabel) = 0;

  /* attribute DOMString icon; */
  NS_IMETHOD GetIcon(nsAString & aIcon) = 0;
  NS_IMETHOD SetIcon(const nsAString & aIcon) = 0;

  /* attribute boolean disabled; */
  NS_IMETHOD GetDisabled(bool *aDisabled) = 0;
  NS_IMETHOD SetDisabled(bool aDisabled) = 0;

  /* attribute boolean defaultChecked; */
  NS_IMETHOD GetDefaultChecked(bool *aDefaultChecked) = 0;
  NS_IMETHOD SetDefaultChecked(bool aDefaultChecked) = 0;

  /* attribute boolean checked; */
  NS_IMETHOD GetChecked(bool *aChecked) = 0;
  NS_IMETHOD SetChecked(bool aChecked) = 0;

  /* attribute DOMString radiogroup; */
  NS_IMETHOD GetRadiogroup(nsAString & aRadiogroup) = 0;
  NS_IMETHOD SetRadiogroup(const nsAString & aRadiogroup) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLCommandElement, NS_IDOMHTMLCOMMANDELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLCOMMANDELEMENT \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD SetType(const nsAString & aType); \
  NS_IMETHOD GetLabel(nsAString & aLabel); \
  NS_IMETHOD SetLabel(const nsAString & aLabel); \
  NS_IMETHOD GetIcon(nsAString & aIcon); \
  NS_IMETHOD SetIcon(const nsAString & aIcon); \
  NS_IMETHOD GetDisabled(bool *aDisabled); \
  NS_IMETHOD SetDisabled(bool aDisabled); \
  NS_IMETHOD GetDefaultChecked(bool *aDefaultChecked); \
  NS_IMETHOD SetDefaultChecked(bool aDefaultChecked); \
  NS_IMETHOD GetChecked(bool *aChecked); \
  NS_IMETHOD SetChecked(bool aChecked); \
  NS_IMETHOD GetRadiogroup(nsAString & aRadiogroup); \
  NS_IMETHOD SetRadiogroup(const nsAString & aRadiogroup); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLCOMMANDELEMENT(_to) \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } \
  NS_IMETHOD GetLabel(nsAString & aLabel) { return _to GetLabel(aLabel); } \
  NS_IMETHOD SetLabel(const nsAString & aLabel) { return _to SetLabel(aLabel); } \
  NS_IMETHOD GetIcon(nsAString & aIcon) { return _to GetIcon(aIcon); } \
  NS_IMETHOD SetIcon(const nsAString & aIcon) { return _to SetIcon(aIcon); } \
  NS_IMETHOD GetDisabled(bool *aDisabled) { return _to GetDisabled(aDisabled); } \
  NS_IMETHOD SetDisabled(bool aDisabled) { return _to SetDisabled(aDisabled); } \
  NS_IMETHOD GetDefaultChecked(bool *aDefaultChecked) { return _to GetDefaultChecked(aDefaultChecked); } \
  NS_IMETHOD SetDefaultChecked(bool aDefaultChecked) { return _to SetDefaultChecked(aDefaultChecked); } \
  NS_IMETHOD GetChecked(bool *aChecked) { return _to GetChecked(aChecked); } \
  NS_IMETHOD SetChecked(bool aChecked) { return _to SetChecked(aChecked); } \
  NS_IMETHOD GetRadiogroup(nsAString & aRadiogroup) { return _to GetRadiogroup(aRadiogroup); } \
  NS_IMETHOD SetRadiogroup(const nsAString & aRadiogroup) { return _to SetRadiogroup(aRadiogroup); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLCOMMANDELEMENT(_to) \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_IMETHOD GetLabel(nsAString & aLabel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLabel(aLabel); } \
  NS_IMETHOD SetLabel(const nsAString & aLabel) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLabel(aLabel); } \
  NS_IMETHOD GetIcon(nsAString & aIcon) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIcon(aIcon); } \
  NS_IMETHOD SetIcon(const nsAString & aIcon) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIcon(aIcon); } \
  NS_IMETHOD GetDisabled(bool *aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisabled(aDisabled); } \
  NS_IMETHOD SetDisabled(bool aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisabled(aDisabled); } \
  NS_IMETHOD GetDefaultChecked(bool *aDefaultChecked) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultChecked(aDefaultChecked); } \
  NS_IMETHOD SetDefaultChecked(bool aDefaultChecked) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultChecked(aDefaultChecked); } \
  NS_IMETHOD GetChecked(bool *aChecked) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChecked(aChecked); } \
  NS_IMETHOD SetChecked(bool aChecked) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChecked(aChecked); } \
  NS_IMETHOD GetRadiogroup(nsAString & aRadiogroup) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRadiogroup(aRadiogroup); } \
  NS_IMETHOD SetRadiogroup(const nsAString & aRadiogroup) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRadiogroup(aRadiogroup); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLCommandElement : public nsIDOMHTMLCommandElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLCOMMANDELEMENT

  nsDOMHTMLCommandElement();

private:
  ~nsDOMHTMLCommandElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLCommandElement, nsIDOMHTMLCommandElement)

nsDOMHTMLCommandElement::nsDOMHTMLCommandElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLCommandElement::~nsDOMHTMLCommandElement()
{
  /* destructor code */
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMHTMLCommandElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLCommandElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString label; */
NS_IMETHODIMP nsDOMHTMLCommandElement::GetLabel(nsAString & aLabel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLCommandElement::SetLabel(const nsAString & aLabel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString icon; */
NS_IMETHODIMP nsDOMHTMLCommandElement::GetIcon(nsAString & aIcon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLCommandElement::SetIcon(const nsAString & aIcon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean disabled; */
NS_IMETHODIMP nsDOMHTMLCommandElement::GetDisabled(bool *aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLCommandElement::SetDisabled(bool aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean defaultChecked; */
NS_IMETHODIMP nsDOMHTMLCommandElement::GetDefaultChecked(bool *aDefaultChecked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLCommandElement::SetDefaultChecked(bool aDefaultChecked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean checked; */
NS_IMETHODIMP nsDOMHTMLCommandElement::GetChecked(bool *aChecked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLCommandElement::SetChecked(bool aChecked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString radiogroup; */
NS_IMETHODIMP nsDOMHTMLCommandElement::GetRadiogroup(nsAString & aRadiogroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLCommandElement::SetRadiogroup(const nsAString & aRadiogroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLCommandElement_h__ */

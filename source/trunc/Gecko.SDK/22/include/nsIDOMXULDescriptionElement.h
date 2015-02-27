/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/xul/nsIDOMXULDescriptionElement.idl
 */

#ifndef __gen_nsIDOMXULDescriptionElement_h__
#define __gen_nsIDOMXULDescriptionElement_h__


#ifndef __gen_nsIDOMXULElement_h__
#include "nsIDOMXULElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMXULDescriptionElement */
#define NS_IDOMXULDESCRIPTIONELEMENT_IID_STR "c5e2a24f-3c35-40c0-baf1-c92ecd09d232"

#define NS_IDOMXULDESCRIPTIONELEMENT_IID \
  {0xc5e2a24f, 0x3c35, 0x40c0, \
    { 0xba, 0xf1, 0xc9, 0x2e, 0xcd, 0x09, 0xd2, 0x32 }}

class NS_NO_VTABLE nsIDOMXULDescriptionElement : public nsIDOMXULElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULDESCRIPTIONELEMENT_IID)

  /* attribute boolean disabled; */
  NS_IMETHOD GetDisabled(bool *aDisabled) = 0;
  NS_IMETHOD SetDisabled(bool aDisabled) = 0;

  /* attribute boolean crop; */
  NS_IMETHOD GetCrop(bool *aCrop) = 0;
  NS_IMETHOD SetCrop(bool aCrop) = 0;

  /* attribute DOMString value; */
  NS_IMETHOD GetValue(nsAString & aValue) = 0;
  NS_IMETHOD SetValue(const nsAString & aValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULDescriptionElement, NS_IDOMXULDESCRIPTIONELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULDESCRIPTIONELEMENT \
  NS_IMETHOD GetDisabled(bool *aDisabled); \
  NS_IMETHOD SetDisabled(bool aDisabled); \
  NS_IMETHOD GetCrop(bool *aCrop); \
  NS_IMETHOD SetCrop(bool aCrop); \
  NS_IMETHOD GetValue(nsAString & aValue); \
  NS_IMETHOD SetValue(const nsAString & aValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULDESCRIPTIONELEMENT(_to) \
  NS_IMETHOD GetDisabled(bool *aDisabled) { return _to GetDisabled(aDisabled); } \
  NS_IMETHOD SetDisabled(bool aDisabled) { return _to SetDisabled(aDisabled); } \
  NS_IMETHOD GetCrop(bool *aCrop) { return _to GetCrop(aCrop); } \
  NS_IMETHOD SetCrop(bool aCrop) { return _to SetCrop(aCrop); } \
  NS_IMETHOD GetValue(nsAString & aValue) { return _to GetValue(aValue); } \
  NS_IMETHOD SetValue(const nsAString & aValue) { return _to SetValue(aValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULDESCRIPTIONELEMENT(_to) \
  NS_IMETHOD GetDisabled(bool *aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisabled(aDisabled); } \
  NS_IMETHOD SetDisabled(bool aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisabled(aDisabled); } \
  NS_IMETHOD GetCrop(bool *aCrop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCrop(aCrop); } \
  NS_IMETHOD SetCrop(bool aCrop) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCrop(aCrop); } \
  NS_IMETHOD GetValue(nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_IMETHOD SetValue(const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULDescriptionElement : public nsIDOMXULDescriptionElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULDESCRIPTIONELEMENT

  nsDOMXULDescriptionElement();

private:
  ~nsDOMXULDescriptionElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULDescriptionElement, nsIDOMXULDescriptionElement)

nsDOMXULDescriptionElement::nsDOMXULDescriptionElement()
{
  /* member initializers and constructor code */
}

nsDOMXULDescriptionElement::~nsDOMXULDescriptionElement()
{
  /* destructor code */
}

/* attribute boolean disabled; */
NS_IMETHODIMP nsDOMXULDescriptionElement::GetDisabled(bool *aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULDescriptionElement::SetDisabled(bool aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean crop; */
NS_IMETHODIMP nsDOMXULDescriptionElement::GetCrop(bool *aCrop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULDescriptionElement::SetCrop(bool aCrop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString value; */
NS_IMETHODIMP nsDOMXULDescriptionElement::GetValue(nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULDescriptionElement::SetValue(const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULDescriptionElement_h__ */

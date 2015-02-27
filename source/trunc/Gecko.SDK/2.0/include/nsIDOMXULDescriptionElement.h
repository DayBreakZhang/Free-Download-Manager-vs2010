/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/xul/nsIDOMXULDescriptionElement.idl
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
#define NS_IDOMXULDESCRIPTIONELEMENT_IID_STR "de87d3ef-8780-40e9-8af1-593bc7a24d77"

#define NS_IDOMXULDESCRIPTIONELEMENT_IID \
  {0xde87d3ef, 0x8780, 0x40e9, \
    { 0x8a, 0xf1, 0x59, 0x3b, 0xc7, 0xa2, 0x4d, 0x77 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXULDescriptionElement : public nsIDOMXULElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULDESCRIPTIONELEMENT_IID)

  /* attribute boolean disabled; */
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled) = 0;

  /* attribute boolean crop; */
  NS_SCRIPTABLE NS_IMETHOD GetCrop(PRBool *aCrop) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCrop(PRBool aCrop) = 0;

  /* attribute DOMString value; */
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULDescriptionElement, NS_IDOMXULDESCRIPTIONELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULDESCRIPTIONELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled); \
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled); \
  NS_SCRIPTABLE NS_IMETHOD GetCrop(PRBool *aCrop); \
  NS_SCRIPTABLE NS_IMETHOD SetCrop(PRBool aCrop); \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULDESCRIPTIONELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled) { return _to GetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled) { return _to SetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetCrop(PRBool *aCrop) { return _to GetCrop(aCrop); } \
  NS_SCRIPTABLE NS_IMETHOD SetCrop(PRBool aCrop) { return _to SetCrop(aCrop); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue) { return _to GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue) { return _to SetValue(aValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULDESCRIPTIONELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetCrop(PRBool *aCrop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCrop(aCrop); } \
  NS_SCRIPTABLE NS_IMETHOD SetCrop(PRBool aCrop) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCrop(aCrop); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } 

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
NS_IMETHODIMP nsDOMXULDescriptionElement::GetDisabled(PRBool *aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULDescriptionElement::SetDisabled(PRBool aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean crop; */
NS_IMETHODIMP nsDOMXULDescriptionElement::GetCrop(PRBool *aCrop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULDescriptionElement::SetCrop(PRBool aCrop)
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

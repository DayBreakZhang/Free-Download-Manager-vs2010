/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/xul/nsIDOMXULSelectCntrlItemEl.idl
 */

#ifndef __gen_nsIDOMXULSelectCntrlItemEl_h__
#define __gen_nsIDOMXULSelectCntrlItemEl_h__


#ifndef __gen_nsIDOMXULElement_h__
#include "nsIDOMXULElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMXULSelectControlElement; /* forward declaration */


/* starting interface:    nsIDOMXULSelectControlItemElement */
#define NS_IDOMXULSELECTCONTROLITEMELEMENT_IID_STR "85fa64de-91d9-4b2f-b9fb-28eb718ea436"

#define NS_IDOMXULSELECTCONTROLITEMELEMENT_IID \
  {0x85fa64de, 0x91d9, 0x4b2f, \
    { 0xb9, 0xfb, 0x28, 0xeb, 0x71, 0x8e, 0xa4, 0x36 }}

class NS_NO_VTABLE nsIDOMXULSelectControlItemElement : public nsIDOMXULElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULSELECTCONTROLITEMELEMENT_IID)

  /* attribute boolean disabled; */
  NS_IMETHOD GetDisabled(bool *aDisabled) = 0;
  NS_IMETHOD SetDisabled(bool aDisabled) = 0;

  /* attribute DOMString crop; */
  NS_IMETHOD GetCrop(nsAString & aCrop) = 0;
  NS_IMETHOD SetCrop(const nsAString & aCrop) = 0;

  /* attribute DOMString image; */
  NS_IMETHOD GetImage(nsAString & aImage) = 0;
  NS_IMETHOD SetImage(const nsAString & aImage) = 0;

  /* attribute DOMString label; */
  NS_IMETHOD GetLabel(nsAString & aLabel) = 0;
  NS_IMETHOD SetLabel(const nsAString & aLabel) = 0;

  /* attribute DOMString accessKey; */
  NS_IMETHOD GetAccessKey(nsAString & aAccessKey) = 0;
  NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) = 0;

  /* attribute DOMString command; */
  NS_IMETHOD GetCommand(nsAString & aCommand) = 0;
  NS_IMETHOD SetCommand(const nsAString & aCommand) = 0;

  /* attribute DOMString value; */
  NS_IMETHOD GetValue(nsAString & aValue) = 0;
  NS_IMETHOD SetValue(const nsAString & aValue) = 0;

  /* readonly attribute boolean selected; */
  NS_IMETHOD GetSelected(bool *aSelected) = 0;

  /* readonly attribute nsIDOMXULSelectControlElement control; */
  NS_IMETHOD GetControl(nsIDOMXULSelectControlElement * *aControl) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULSelectControlItemElement, NS_IDOMXULSELECTCONTROLITEMELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULSELECTCONTROLITEMELEMENT \
  NS_IMETHOD GetDisabled(bool *aDisabled); \
  NS_IMETHOD SetDisabled(bool aDisabled); \
  NS_IMETHOD GetCrop(nsAString & aCrop); \
  NS_IMETHOD SetCrop(const nsAString & aCrop); \
  NS_IMETHOD GetImage(nsAString & aImage); \
  NS_IMETHOD SetImage(const nsAString & aImage); \
  NS_IMETHOD GetLabel(nsAString & aLabel); \
  NS_IMETHOD SetLabel(const nsAString & aLabel); \
  NS_IMETHOD GetAccessKey(nsAString & aAccessKey); \
  NS_IMETHOD SetAccessKey(const nsAString & aAccessKey); \
  NS_IMETHOD GetCommand(nsAString & aCommand); \
  NS_IMETHOD SetCommand(const nsAString & aCommand); \
  NS_IMETHOD GetValue(nsAString & aValue); \
  NS_IMETHOD SetValue(const nsAString & aValue); \
  NS_IMETHOD GetSelected(bool *aSelected); \
  NS_IMETHOD GetControl(nsIDOMXULSelectControlElement * *aControl); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULSELECTCONTROLITEMELEMENT(_to) \
  NS_IMETHOD GetDisabled(bool *aDisabled) { return _to GetDisabled(aDisabled); } \
  NS_IMETHOD SetDisabled(bool aDisabled) { return _to SetDisabled(aDisabled); } \
  NS_IMETHOD GetCrop(nsAString & aCrop) { return _to GetCrop(aCrop); } \
  NS_IMETHOD SetCrop(const nsAString & aCrop) { return _to SetCrop(aCrop); } \
  NS_IMETHOD GetImage(nsAString & aImage) { return _to GetImage(aImage); } \
  NS_IMETHOD SetImage(const nsAString & aImage) { return _to SetImage(aImage); } \
  NS_IMETHOD GetLabel(nsAString & aLabel) { return _to GetLabel(aLabel); } \
  NS_IMETHOD SetLabel(const nsAString & aLabel) { return _to SetLabel(aLabel); } \
  NS_IMETHOD GetAccessKey(nsAString & aAccessKey) { return _to GetAccessKey(aAccessKey); } \
  NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) { return _to SetAccessKey(aAccessKey); } \
  NS_IMETHOD GetCommand(nsAString & aCommand) { return _to GetCommand(aCommand); } \
  NS_IMETHOD SetCommand(const nsAString & aCommand) { return _to SetCommand(aCommand); } \
  NS_IMETHOD GetValue(nsAString & aValue) { return _to GetValue(aValue); } \
  NS_IMETHOD SetValue(const nsAString & aValue) { return _to SetValue(aValue); } \
  NS_IMETHOD GetSelected(bool *aSelected) { return _to GetSelected(aSelected); } \
  NS_IMETHOD GetControl(nsIDOMXULSelectControlElement * *aControl) { return _to GetControl(aControl); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULSELECTCONTROLITEMELEMENT(_to) \
  NS_IMETHOD GetDisabled(bool *aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisabled(aDisabled); } \
  NS_IMETHOD SetDisabled(bool aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisabled(aDisabled); } \
  NS_IMETHOD GetCrop(nsAString & aCrop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCrop(aCrop); } \
  NS_IMETHOD SetCrop(const nsAString & aCrop) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCrop(aCrop); } \
  NS_IMETHOD GetImage(nsAString & aImage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImage(aImage); } \
  NS_IMETHOD SetImage(const nsAString & aImage) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetImage(aImage); } \
  NS_IMETHOD GetLabel(nsAString & aLabel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLabel(aLabel); } \
  NS_IMETHOD SetLabel(const nsAString & aLabel) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLabel(aLabel); } \
  NS_IMETHOD GetAccessKey(nsAString & aAccessKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessKey(aAccessKey); } \
  NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAccessKey(aAccessKey); } \
  NS_IMETHOD GetCommand(nsAString & aCommand) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCommand(aCommand); } \
  NS_IMETHOD SetCommand(const nsAString & aCommand) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCommand(aCommand); } \
  NS_IMETHOD GetValue(nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_IMETHOD SetValue(const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } \
  NS_IMETHOD GetSelected(bool *aSelected) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelected(aSelected); } \
  NS_IMETHOD GetControl(nsIDOMXULSelectControlElement * *aControl) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetControl(aControl); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULSelectControlItemElement : public nsIDOMXULSelectControlItemElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULSELECTCONTROLITEMELEMENT

  nsDOMXULSelectControlItemElement();

private:
  ~nsDOMXULSelectControlItemElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULSelectControlItemElement, nsIDOMXULSelectControlItemElement)

nsDOMXULSelectControlItemElement::nsDOMXULSelectControlItemElement()
{
  /* member initializers and constructor code */
}

nsDOMXULSelectControlItemElement::~nsDOMXULSelectControlItemElement()
{
  /* destructor code */
}

/* attribute boolean disabled; */
NS_IMETHODIMP nsDOMXULSelectControlItemElement::GetDisabled(bool *aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULSelectControlItemElement::SetDisabled(bool aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString crop; */
NS_IMETHODIMP nsDOMXULSelectControlItemElement::GetCrop(nsAString & aCrop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULSelectControlItemElement::SetCrop(const nsAString & aCrop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString image; */
NS_IMETHODIMP nsDOMXULSelectControlItemElement::GetImage(nsAString & aImage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULSelectControlItemElement::SetImage(const nsAString & aImage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString label; */
NS_IMETHODIMP nsDOMXULSelectControlItemElement::GetLabel(nsAString & aLabel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULSelectControlItemElement::SetLabel(const nsAString & aLabel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString accessKey; */
NS_IMETHODIMP nsDOMXULSelectControlItemElement::GetAccessKey(nsAString & aAccessKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULSelectControlItemElement::SetAccessKey(const nsAString & aAccessKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString command; */
NS_IMETHODIMP nsDOMXULSelectControlItemElement::GetCommand(nsAString & aCommand)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULSelectControlItemElement::SetCommand(const nsAString & aCommand)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString value; */
NS_IMETHODIMP nsDOMXULSelectControlItemElement::GetValue(nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULSelectControlItemElement::SetValue(const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean selected; */
NS_IMETHODIMP nsDOMXULSelectControlItemElement::GetSelected(bool *aSelected)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMXULSelectControlElement control; */
NS_IMETHODIMP nsDOMXULSelectControlItemElement::GetControl(nsIDOMXULSelectControlElement * *aControl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULSelectCntrlItemEl_h__ */

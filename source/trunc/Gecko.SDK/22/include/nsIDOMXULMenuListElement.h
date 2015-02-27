/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/xul/nsIDOMXULMenuListElement.idl
 */

#ifndef __gen_nsIDOMXULMenuListElement_h__
#define __gen_nsIDOMXULMenuListElement_h__


#ifndef __gen_nsIDOMXULSelectCntrlEl_h__
#include "nsIDOMXULSelectCntrlEl.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMXULTextBoxElement; /* forward declaration */


/* starting interface:    nsIDOMXULMenuListElement */
#define NS_IDOMXULMENULISTELEMENT_IID_STR "df76f885-717a-484b-81f9-76700a04b51d"

#define NS_IDOMXULMENULISTELEMENT_IID \
  {0xdf76f885, 0x717a, 0x484b, \
    { 0x81, 0xf9, 0x76, 0x70, 0x0a, 0x04, 0xb5, 0x1d }}

class NS_NO_VTABLE nsIDOMXULMenuListElement : public nsIDOMXULSelectControlElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULMENULISTELEMENT_IID)

  /* attribute boolean editable; */
  NS_IMETHOD GetEditable(bool *aEditable) = 0;
  NS_IMETHOD SetEditable(bool aEditable) = 0;

  /* attribute boolean open; */
  NS_IMETHOD GetOpen(bool *aOpen) = 0;
  NS_IMETHOD SetOpen(bool aOpen) = 0;

  /* readonly attribute DOMString label; */
  NS_IMETHOD GetLabel(nsAString & aLabel) = 0;

  /* attribute DOMString crop; */
  NS_IMETHOD GetCrop(nsAString & aCrop) = 0;
  NS_IMETHOD SetCrop(const nsAString & aCrop) = 0;

  /* attribute DOMString image; */
  NS_IMETHOD GetImage(nsAString & aImage) = 0;
  NS_IMETHOD SetImage(const nsAString & aImage) = 0;

  /* readonly attribute nsIDOMNode inputField; */
  NS_IMETHOD GetInputField(nsIDOMNode * *aInputField) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULMenuListElement, NS_IDOMXULMENULISTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULMENULISTELEMENT \
  NS_IMETHOD GetEditable(bool *aEditable); \
  NS_IMETHOD SetEditable(bool aEditable); \
  NS_IMETHOD GetOpen(bool *aOpen); \
  NS_IMETHOD SetOpen(bool aOpen); \
  NS_IMETHOD GetLabel(nsAString & aLabel); \
  NS_IMETHOD GetCrop(nsAString & aCrop); \
  NS_IMETHOD SetCrop(const nsAString & aCrop); \
  NS_IMETHOD GetImage(nsAString & aImage); \
  NS_IMETHOD SetImage(const nsAString & aImage); \
  NS_IMETHOD GetInputField(nsIDOMNode * *aInputField); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULMENULISTELEMENT(_to) \
  NS_IMETHOD GetEditable(bool *aEditable) { return _to GetEditable(aEditable); } \
  NS_IMETHOD SetEditable(bool aEditable) { return _to SetEditable(aEditable); } \
  NS_IMETHOD GetOpen(bool *aOpen) { return _to GetOpen(aOpen); } \
  NS_IMETHOD SetOpen(bool aOpen) { return _to SetOpen(aOpen); } \
  NS_IMETHOD GetLabel(nsAString & aLabel) { return _to GetLabel(aLabel); } \
  NS_IMETHOD GetCrop(nsAString & aCrop) { return _to GetCrop(aCrop); } \
  NS_IMETHOD SetCrop(const nsAString & aCrop) { return _to SetCrop(aCrop); } \
  NS_IMETHOD GetImage(nsAString & aImage) { return _to GetImage(aImage); } \
  NS_IMETHOD SetImage(const nsAString & aImage) { return _to SetImage(aImage); } \
  NS_IMETHOD GetInputField(nsIDOMNode * *aInputField) { return _to GetInputField(aInputField); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULMENULISTELEMENT(_to) \
  NS_IMETHOD GetEditable(bool *aEditable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEditable(aEditable); } \
  NS_IMETHOD SetEditable(bool aEditable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEditable(aEditable); } \
  NS_IMETHOD GetOpen(bool *aOpen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOpen(aOpen); } \
  NS_IMETHOD SetOpen(bool aOpen) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOpen(aOpen); } \
  NS_IMETHOD GetLabel(nsAString & aLabel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLabel(aLabel); } \
  NS_IMETHOD GetCrop(nsAString & aCrop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCrop(aCrop); } \
  NS_IMETHOD SetCrop(const nsAString & aCrop) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCrop(aCrop); } \
  NS_IMETHOD GetImage(nsAString & aImage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImage(aImage); } \
  NS_IMETHOD SetImage(const nsAString & aImage) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetImage(aImage); } \
  NS_IMETHOD GetInputField(nsIDOMNode * *aInputField) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInputField(aInputField); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULMenuListElement : public nsIDOMXULMenuListElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULMENULISTELEMENT

  nsDOMXULMenuListElement();

private:
  ~nsDOMXULMenuListElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULMenuListElement, nsIDOMXULMenuListElement)

nsDOMXULMenuListElement::nsDOMXULMenuListElement()
{
  /* member initializers and constructor code */
}

nsDOMXULMenuListElement::~nsDOMXULMenuListElement()
{
  /* destructor code */
}

/* attribute boolean editable; */
NS_IMETHODIMP nsDOMXULMenuListElement::GetEditable(bool *aEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULMenuListElement::SetEditable(bool aEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean open; */
NS_IMETHODIMP nsDOMXULMenuListElement::GetOpen(bool *aOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULMenuListElement::SetOpen(bool aOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString label; */
NS_IMETHODIMP nsDOMXULMenuListElement::GetLabel(nsAString & aLabel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString crop; */
NS_IMETHODIMP nsDOMXULMenuListElement::GetCrop(nsAString & aCrop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULMenuListElement::SetCrop(const nsAString & aCrop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString image; */
NS_IMETHODIMP nsDOMXULMenuListElement::GetImage(nsAString & aImage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULMenuListElement::SetImage(const nsAString & aImage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode inputField; */
NS_IMETHODIMP nsDOMXULMenuListElement::GetInputField(nsIDOMNode * *aInputField)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULMenuListElement_h__ */

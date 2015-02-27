/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/xul/nsIDOMXULLabeledControlEl.idl
 */

#ifndef __gen_nsIDOMXULLabeledControlEl_h__
#define __gen_nsIDOMXULLabeledControlEl_h__


#ifndef __gen_nsIDOMElement_h__
#include "nsIDOMElement.h"
#endif

#ifndef __gen_nsIDOMXULControlElement_h__
#include "nsIDOMXULControlElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMXULLabeledControlElement */
#define NS_IDOMXULLABELEDCONTROLELEMENT_IID_STR "eecd5462-3ead-4caa-9651-0c2b88b39a65"

#define NS_IDOMXULLABELEDCONTROLELEMENT_IID \
  {0xeecd5462, 0x3ead, 0x4caa, \
    { 0x96, 0x51, 0x0c, 0x2b, 0x88, 0xb3, 0x9a, 0x65 }}

class NS_NO_VTABLE nsIDOMXULLabeledControlElement : public nsIDOMXULControlElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULLABELEDCONTROLELEMENT_IID)

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

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULLabeledControlElement, NS_IDOMXULLABELEDCONTROLELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULLABELEDCONTROLELEMENT \
  NS_IMETHOD GetCrop(nsAString & aCrop); \
  NS_IMETHOD SetCrop(const nsAString & aCrop); \
  NS_IMETHOD GetImage(nsAString & aImage); \
  NS_IMETHOD SetImage(const nsAString & aImage); \
  NS_IMETHOD GetLabel(nsAString & aLabel); \
  NS_IMETHOD SetLabel(const nsAString & aLabel); \
  NS_IMETHOD GetAccessKey(nsAString & aAccessKey); \
  NS_IMETHOD SetAccessKey(const nsAString & aAccessKey); \
  NS_IMETHOD GetCommand(nsAString & aCommand); \
  NS_IMETHOD SetCommand(const nsAString & aCommand); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULLABELEDCONTROLELEMENT(_to) \
  NS_IMETHOD GetCrop(nsAString & aCrop) { return _to GetCrop(aCrop); } \
  NS_IMETHOD SetCrop(const nsAString & aCrop) { return _to SetCrop(aCrop); } \
  NS_IMETHOD GetImage(nsAString & aImage) { return _to GetImage(aImage); } \
  NS_IMETHOD SetImage(const nsAString & aImage) { return _to SetImage(aImage); } \
  NS_IMETHOD GetLabel(nsAString & aLabel) { return _to GetLabel(aLabel); } \
  NS_IMETHOD SetLabel(const nsAString & aLabel) { return _to SetLabel(aLabel); } \
  NS_IMETHOD GetAccessKey(nsAString & aAccessKey) { return _to GetAccessKey(aAccessKey); } \
  NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) { return _to SetAccessKey(aAccessKey); } \
  NS_IMETHOD GetCommand(nsAString & aCommand) { return _to GetCommand(aCommand); } \
  NS_IMETHOD SetCommand(const nsAString & aCommand) { return _to SetCommand(aCommand); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULLABELEDCONTROLELEMENT(_to) \
  NS_IMETHOD GetCrop(nsAString & aCrop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCrop(aCrop); } \
  NS_IMETHOD SetCrop(const nsAString & aCrop) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCrop(aCrop); } \
  NS_IMETHOD GetImage(nsAString & aImage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImage(aImage); } \
  NS_IMETHOD SetImage(const nsAString & aImage) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetImage(aImage); } \
  NS_IMETHOD GetLabel(nsAString & aLabel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLabel(aLabel); } \
  NS_IMETHOD SetLabel(const nsAString & aLabel) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLabel(aLabel); } \
  NS_IMETHOD GetAccessKey(nsAString & aAccessKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessKey(aAccessKey); } \
  NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAccessKey(aAccessKey); } \
  NS_IMETHOD GetCommand(nsAString & aCommand) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCommand(aCommand); } \
  NS_IMETHOD SetCommand(const nsAString & aCommand) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCommand(aCommand); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULLabeledControlElement : public nsIDOMXULLabeledControlElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULLABELEDCONTROLELEMENT

  nsDOMXULLabeledControlElement();

private:
  ~nsDOMXULLabeledControlElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULLabeledControlElement, nsIDOMXULLabeledControlElement)

nsDOMXULLabeledControlElement::nsDOMXULLabeledControlElement()
{
  /* member initializers and constructor code */
}

nsDOMXULLabeledControlElement::~nsDOMXULLabeledControlElement()
{
  /* destructor code */
}

/* attribute DOMString crop; */
NS_IMETHODIMP nsDOMXULLabeledControlElement::GetCrop(nsAString & aCrop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULLabeledControlElement::SetCrop(const nsAString & aCrop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString image; */
NS_IMETHODIMP nsDOMXULLabeledControlElement::GetImage(nsAString & aImage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULLabeledControlElement::SetImage(const nsAString & aImage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString label; */
NS_IMETHODIMP nsDOMXULLabeledControlElement::GetLabel(nsAString & aLabel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULLabeledControlElement::SetLabel(const nsAString & aLabel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString accessKey; */
NS_IMETHODIMP nsDOMXULLabeledControlElement::GetAccessKey(nsAString & aAccessKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULLabeledControlElement::SetAccessKey(const nsAString & aAccessKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString command; */
NS_IMETHODIMP nsDOMXULLabeledControlElement::GetCommand(nsAString & aCommand)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULLabeledControlElement::SetCommand(const nsAString & aCommand)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULLabeledControlEl_h__ */

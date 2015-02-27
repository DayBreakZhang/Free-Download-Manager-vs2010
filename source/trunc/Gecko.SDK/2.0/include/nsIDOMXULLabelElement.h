/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/xul/nsIDOMXULLabelElement.idl
 */

#ifndef __gen_nsIDOMXULLabelElement_h__
#define __gen_nsIDOMXULLabelElement_h__


#ifndef __gen_nsIDOMXULDescriptionElement_h__
#include "nsIDOMXULDescriptionElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMXULLabelElement */
#define NS_IDOMXULLABELELEMENT_IID_STR "db431786-d23a-4ee2-a8b4-f952c6f2fa6e"

#define NS_IDOMXULLABELELEMENT_IID \
  {0xdb431786, 0xd23a, 0x4ee2, \
    { 0xa8, 0xb4, 0xf9, 0x52, 0xc6, 0xf2, 0xfa, 0x6e }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXULLabelElement : public nsIDOMXULDescriptionElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULLABELELEMENT_IID)

  /* attribute DOMString accessKey; */
  NS_SCRIPTABLE NS_IMETHOD GetAccessKey(nsAString & aAccessKey) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) = 0;

  /* attribute DOMString control; */
  NS_SCRIPTABLE NS_IMETHOD GetControl(nsAString & aControl) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetControl(const nsAString & aControl) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULLabelElement, NS_IDOMXULLABELELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULLABELELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetAccessKey(nsAString & aAccessKey); \
  NS_SCRIPTABLE NS_IMETHOD SetAccessKey(const nsAString & aAccessKey); \
  NS_SCRIPTABLE NS_IMETHOD GetControl(nsAString & aControl); \
  NS_SCRIPTABLE NS_IMETHOD SetControl(const nsAString & aControl); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULLABELELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAccessKey(nsAString & aAccessKey) { return _to GetAccessKey(aAccessKey); } \
  NS_SCRIPTABLE NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) { return _to SetAccessKey(aAccessKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetControl(nsAString & aControl) { return _to GetControl(aControl); } \
  NS_SCRIPTABLE NS_IMETHOD SetControl(const nsAString & aControl) { return _to SetControl(aControl); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULLABELELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAccessKey(nsAString & aAccessKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessKey(aAccessKey); } \
  NS_SCRIPTABLE NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAccessKey(aAccessKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetControl(nsAString & aControl) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetControl(aControl); } \
  NS_SCRIPTABLE NS_IMETHOD SetControl(const nsAString & aControl) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetControl(aControl); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULLabelElement : public nsIDOMXULLabelElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULLABELELEMENT

  nsDOMXULLabelElement();

private:
  ~nsDOMXULLabelElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULLabelElement, nsIDOMXULLabelElement)

nsDOMXULLabelElement::nsDOMXULLabelElement()
{
  /* member initializers and constructor code */
}

nsDOMXULLabelElement::~nsDOMXULLabelElement()
{
  /* destructor code */
}

/* attribute DOMString accessKey; */
NS_IMETHODIMP nsDOMXULLabelElement::GetAccessKey(nsAString & aAccessKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULLabelElement::SetAccessKey(const nsAString & aAccessKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString control; */
NS_IMETHODIMP nsDOMXULLabelElement::GetControl(nsAString & aControl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULLabelElement::SetControl(const nsAString & aControl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULLabelElement_h__ */

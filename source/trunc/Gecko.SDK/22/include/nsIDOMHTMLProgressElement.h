/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLProgressElement.idl
 */

#ifndef __gen_nsIDOMHTMLProgressElement_h__
#define __gen_nsIDOMHTMLProgressElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLProgressElement */
#define NS_IDOMHTMLPROGRESSELEMENT_IID_STR "e5ba151c-0772-4849-8021-fb30f341fff9"

#define NS_IDOMHTMLPROGRESSELEMENT_IID \
  {0xe5ba151c, 0x0772, 0x4849, \
    { 0x80, 0x21, 0xfb, 0x30, 0xf3, 0x41, 0xff, 0xf9 }}

class NS_NO_VTABLE nsIDOMHTMLProgressElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLPROGRESSELEMENT_IID)

  /* attribute double value; */
  NS_IMETHOD GetValue(double *aValue) = 0;
  NS_IMETHOD SetValue(double aValue) = 0;

  /* attribute double max; */
  NS_IMETHOD GetMax(double *aMax) = 0;
  NS_IMETHOD SetMax(double aMax) = 0;

  /* readonly attribute double position; */
  NS_IMETHOD GetPosition(double *aPosition) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLProgressElement, NS_IDOMHTMLPROGRESSELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLPROGRESSELEMENT \
  NS_IMETHOD GetValue(double *aValue); \
  NS_IMETHOD SetValue(double aValue); \
  NS_IMETHOD GetMax(double *aMax); \
  NS_IMETHOD SetMax(double aMax); \
  NS_IMETHOD GetPosition(double *aPosition); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLPROGRESSELEMENT(_to) \
  NS_IMETHOD GetValue(double *aValue) { return _to GetValue(aValue); } \
  NS_IMETHOD SetValue(double aValue) { return _to SetValue(aValue); } \
  NS_IMETHOD GetMax(double *aMax) { return _to GetMax(aMax); } \
  NS_IMETHOD SetMax(double aMax) { return _to SetMax(aMax); } \
  NS_IMETHOD GetPosition(double *aPosition) { return _to GetPosition(aPosition); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLPROGRESSELEMENT(_to) \
  NS_IMETHOD GetValue(double *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_IMETHOD SetValue(double aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } \
  NS_IMETHOD GetMax(double *aMax) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMax(aMax); } \
  NS_IMETHOD SetMax(double aMax) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMax(aMax); } \
  NS_IMETHOD GetPosition(double *aPosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPosition(aPosition); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLProgressElement : public nsIDOMHTMLProgressElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLPROGRESSELEMENT

  nsDOMHTMLProgressElement();

private:
  ~nsDOMHTMLProgressElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLProgressElement, nsIDOMHTMLProgressElement)

nsDOMHTMLProgressElement::nsDOMHTMLProgressElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLProgressElement::~nsDOMHTMLProgressElement()
{
  /* destructor code */
}

/* attribute double value; */
NS_IMETHODIMP nsDOMHTMLProgressElement::GetValue(double *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLProgressElement::SetValue(double aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double max; */
NS_IMETHODIMP nsDOMHTMLProgressElement::GetMax(double *aMax)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLProgressElement::SetMax(double aMax)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double position; */
NS_IMETHODIMP nsDOMHTMLProgressElement::GetPosition(double *aPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLProgressElement_h__ */

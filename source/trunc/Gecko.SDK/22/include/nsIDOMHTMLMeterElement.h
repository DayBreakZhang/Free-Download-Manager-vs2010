/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLMeterElement.idl
 */

#ifndef __gen_nsIDOMHTMLMeterElement_h__
#define __gen_nsIDOMHTMLMeterElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLMeterElement */
#define NS_IDOMHTMLMETERELEMENT_IID_STR "53b55f04-fd1a-47e5-8181-d059114a3bc9"

#define NS_IDOMHTMLMETERELEMENT_IID \
  {0x53b55f04, 0xfd1a, 0x47e5, \
    { 0x81, 0x81, 0xd0, 0x59, 0x11, 0x4a, 0x3b, 0xc9 }}

class NS_NO_VTABLE nsIDOMHTMLMeterElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLMETERELEMENT_IID)

  /* attribute double value; */
  NS_IMETHOD GetValue(double *aValue) = 0;
  NS_IMETHOD SetValue(double aValue) = 0;

  /* attribute double min; */
  NS_IMETHOD GetMin(double *aMin) = 0;
  NS_IMETHOD SetMin(double aMin) = 0;

  /* attribute double max; */
  NS_IMETHOD GetMax(double *aMax) = 0;
  NS_IMETHOD SetMax(double aMax) = 0;

  /* attribute double low; */
  NS_IMETHOD GetLow(double *aLow) = 0;
  NS_IMETHOD SetLow(double aLow) = 0;

  /* attribute double high; */
  NS_IMETHOD GetHigh(double *aHigh) = 0;
  NS_IMETHOD SetHigh(double aHigh) = 0;

  /* attribute double optimum; */
  NS_IMETHOD GetOptimum(double *aOptimum) = 0;
  NS_IMETHOD SetOptimum(double aOptimum) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLMeterElement, NS_IDOMHTMLMETERELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLMETERELEMENT \
  NS_IMETHOD GetValue(double *aValue); \
  NS_IMETHOD SetValue(double aValue); \
  NS_IMETHOD GetMin(double *aMin); \
  NS_IMETHOD SetMin(double aMin); \
  NS_IMETHOD GetMax(double *aMax); \
  NS_IMETHOD SetMax(double aMax); \
  NS_IMETHOD GetLow(double *aLow); \
  NS_IMETHOD SetLow(double aLow); \
  NS_IMETHOD GetHigh(double *aHigh); \
  NS_IMETHOD SetHigh(double aHigh); \
  NS_IMETHOD GetOptimum(double *aOptimum); \
  NS_IMETHOD SetOptimum(double aOptimum); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLMETERELEMENT(_to) \
  NS_IMETHOD GetValue(double *aValue) { return _to GetValue(aValue); } \
  NS_IMETHOD SetValue(double aValue) { return _to SetValue(aValue); } \
  NS_IMETHOD GetMin(double *aMin) { return _to GetMin(aMin); } \
  NS_IMETHOD SetMin(double aMin) { return _to SetMin(aMin); } \
  NS_IMETHOD GetMax(double *aMax) { return _to GetMax(aMax); } \
  NS_IMETHOD SetMax(double aMax) { return _to SetMax(aMax); } \
  NS_IMETHOD GetLow(double *aLow) { return _to GetLow(aLow); } \
  NS_IMETHOD SetLow(double aLow) { return _to SetLow(aLow); } \
  NS_IMETHOD GetHigh(double *aHigh) { return _to GetHigh(aHigh); } \
  NS_IMETHOD SetHigh(double aHigh) { return _to SetHigh(aHigh); } \
  NS_IMETHOD GetOptimum(double *aOptimum) { return _to GetOptimum(aOptimum); } \
  NS_IMETHOD SetOptimum(double aOptimum) { return _to SetOptimum(aOptimum); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLMETERELEMENT(_to) \
  NS_IMETHOD GetValue(double *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_IMETHOD SetValue(double aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } \
  NS_IMETHOD GetMin(double *aMin) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMin(aMin); } \
  NS_IMETHOD SetMin(double aMin) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMin(aMin); } \
  NS_IMETHOD GetMax(double *aMax) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMax(aMax); } \
  NS_IMETHOD SetMax(double aMax) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMax(aMax); } \
  NS_IMETHOD GetLow(double *aLow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLow(aLow); } \
  NS_IMETHOD SetLow(double aLow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLow(aLow); } \
  NS_IMETHOD GetHigh(double *aHigh) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHigh(aHigh); } \
  NS_IMETHOD SetHigh(double aHigh) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHigh(aHigh); } \
  NS_IMETHOD GetOptimum(double *aOptimum) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOptimum(aOptimum); } \
  NS_IMETHOD SetOptimum(double aOptimum) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOptimum(aOptimum); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLMeterElement : public nsIDOMHTMLMeterElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLMETERELEMENT

  nsDOMHTMLMeterElement();

private:
  ~nsDOMHTMLMeterElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLMeterElement, nsIDOMHTMLMeterElement)

nsDOMHTMLMeterElement::nsDOMHTMLMeterElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLMeterElement::~nsDOMHTMLMeterElement()
{
  /* destructor code */
}

/* attribute double value; */
NS_IMETHODIMP nsDOMHTMLMeterElement::GetValue(double *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMeterElement::SetValue(double aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double min; */
NS_IMETHODIMP nsDOMHTMLMeterElement::GetMin(double *aMin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMeterElement::SetMin(double aMin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double max; */
NS_IMETHODIMP nsDOMHTMLMeterElement::GetMax(double *aMax)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMeterElement::SetMax(double aMax)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double low; */
NS_IMETHODIMP nsDOMHTMLMeterElement::GetLow(double *aLow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMeterElement::SetLow(double aLow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double high; */
NS_IMETHODIMP nsDOMHTMLMeterElement::GetHigh(double *aHigh)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMeterElement::SetHigh(double aHigh)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double optimum; */
NS_IMETHODIMP nsDOMHTMLMeterElement::GetOptimum(double *aOptimum)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMeterElement::SetOptimum(double aOptimum)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLMeterElement_h__ */

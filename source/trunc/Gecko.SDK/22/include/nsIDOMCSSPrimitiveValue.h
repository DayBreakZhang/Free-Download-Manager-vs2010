/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/css/nsIDOMCSSPrimitiveValue.idl
 */

#ifndef __gen_nsIDOMCSSPrimitiveValue_h__
#define __gen_nsIDOMCSSPrimitiveValue_h__


#ifndef __gen_nsIDOMCSSValue_h__
#include "nsIDOMCSSValue.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCSSPrimitiveValue */
#define NS_IDOMCSSPRIMITIVEVALUE_IID_STR "f6df7293-2dc9-4cb9-9531-778caf4370e0"

#define NS_IDOMCSSPRIMITIVEVALUE_IID \
  {0xf6df7293, 0x2dc9, 0x4cb9, \
    { 0x95, 0x31, 0x77, 0x8c, 0xaf, 0x43, 0x70, 0xe0 }}

class NS_NO_VTABLE nsIDOMCSSPrimitiveValue : public nsIDOMCSSValue {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSPRIMITIVEVALUE_IID)

  enum {
    CSS_UNKNOWN = 0U,
    CSS_NUMBER = 1U,
    CSS_PERCENTAGE = 2U,
    CSS_EMS = 3U,
    CSS_EXS = 4U,
    CSS_PX = 5U,
    CSS_CM = 6U,
    CSS_MM = 7U,
    CSS_IN = 8U,
    CSS_PT = 9U,
    CSS_PC = 10U,
    CSS_DEG = 11U,
    CSS_RAD = 12U,
    CSS_GRAD = 13U,
    CSS_MS = 14U,
    CSS_S = 15U,
    CSS_HZ = 16U,
    CSS_KHZ = 17U,
    CSS_DIMENSION = 18U,
    CSS_STRING = 19U,
    CSS_URI = 20U,
    CSS_IDENT = 21U,
    CSS_ATTR = 22U,
    CSS_COUNTER = 23U,
    CSS_RECT = 24U,
    CSS_RGBCOLOR = 25U
  };

  /* readonly attribute unsigned short primitiveType; */
  NS_IMETHOD GetPrimitiveType(uint16_t *aPrimitiveType) = 0;

  /* void setFloatValue (in unsigned short unitType, in float floatValue) raises (DOMException); */
  NS_IMETHOD SetFloatValue(uint16_t unitType, float floatValue) = 0;

  /* float getFloatValue (in unsigned short unitType) raises (DOMException); */
  NS_IMETHOD GetFloatValue(uint16_t unitType, float *_retval) = 0;

  /* void setStringValue (in unsigned short stringType, in DOMString stringValue) raises (DOMException); */
  NS_IMETHOD SetStringValue(uint16_t stringType, const nsAString & stringValue) = 0;

  /* DOMString getStringValue () raises (DOMException); */
  NS_IMETHOD GetStringValue(nsAString & _retval) = 0;

  /* nsIDOMCounter getCounterValue () raises (DOMException); */
  NS_IMETHOD GetCounterValue(nsIDOMCounter * *_retval) = 0;

  /* nsIDOMRect getRectValue () raises (DOMException); */
  NS_IMETHOD GetRectValue(nsIDOMRect * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSPrimitiveValue, NS_IDOMCSSPRIMITIVEVALUE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSPRIMITIVEVALUE \
  NS_IMETHOD GetPrimitiveType(uint16_t *aPrimitiveType); \
  NS_IMETHOD SetFloatValue(uint16_t unitType, float floatValue); \
  NS_IMETHOD GetFloatValue(uint16_t unitType, float *_retval); \
  NS_IMETHOD SetStringValue(uint16_t stringType, const nsAString & stringValue); \
  NS_IMETHOD GetStringValue(nsAString & _retval); \
  NS_IMETHOD GetCounterValue(nsIDOMCounter * *_retval); \
  NS_IMETHOD GetRectValue(nsIDOMRect * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSPRIMITIVEVALUE(_to) \
  NS_IMETHOD GetPrimitiveType(uint16_t *aPrimitiveType) { return _to GetPrimitiveType(aPrimitiveType); } \
  NS_IMETHOD SetFloatValue(uint16_t unitType, float floatValue) { return _to SetFloatValue(unitType, floatValue); } \
  NS_IMETHOD GetFloatValue(uint16_t unitType, float *_retval) { return _to GetFloatValue(unitType, _retval); } \
  NS_IMETHOD SetStringValue(uint16_t stringType, const nsAString & stringValue) { return _to SetStringValue(stringType, stringValue); } \
  NS_IMETHOD GetStringValue(nsAString & _retval) { return _to GetStringValue(_retval); } \
  NS_IMETHOD GetCounterValue(nsIDOMCounter * *_retval) { return _to GetCounterValue(_retval); } \
  NS_IMETHOD GetRectValue(nsIDOMRect * *_retval) { return _to GetRectValue(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSPRIMITIVEVALUE(_to) \
  NS_IMETHOD GetPrimitiveType(uint16_t *aPrimitiveType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrimitiveType(aPrimitiveType); } \
  NS_IMETHOD SetFloatValue(uint16_t unitType, float floatValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFloatValue(unitType, floatValue); } \
  NS_IMETHOD GetFloatValue(uint16_t unitType, float *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFloatValue(unitType, _retval); } \
  NS_IMETHOD SetStringValue(uint16_t stringType, const nsAString & stringValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStringValue(stringType, stringValue); } \
  NS_IMETHOD GetStringValue(nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringValue(_retval); } \
  NS_IMETHOD GetCounterValue(nsIDOMCounter * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCounterValue(_retval); } \
  NS_IMETHOD GetRectValue(nsIDOMRect * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRectValue(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSPrimitiveValue : public nsIDOMCSSPrimitiveValue
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSPRIMITIVEVALUE

  nsDOMCSSPrimitiveValue();

private:
  ~nsDOMCSSPrimitiveValue();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCSSPrimitiveValue, nsIDOMCSSPrimitiveValue)

nsDOMCSSPrimitiveValue::nsDOMCSSPrimitiveValue()
{
  /* member initializers and constructor code */
}

nsDOMCSSPrimitiveValue::~nsDOMCSSPrimitiveValue()
{
  /* destructor code */
}

/* readonly attribute unsigned short primitiveType; */
NS_IMETHODIMP nsDOMCSSPrimitiveValue::GetPrimitiveType(uint16_t *aPrimitiveType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFloatValue (in unsigned short unitType, in float floatValue) raises (DOMException); */
NS_IMETHODIMP nsDOMCSSPrimitiveValue::SetFloatValue(uint16_t unitType, float floatValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* float getFloatValue (in unsigned short unitType) raises (DOMException); */
NS_IMETHODIMP nsDOMCSSPrimitiveValue::GetFloatValue(uint16_t unitType, float *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setStringValue (in unsigned short stringType, in DOMString stringValue) raises (DOMException); */
NS_IMETHODIMP nsDOMCSSPrimitiveValue::SetStringValue(uint16_t stringType, const nsAString & stringValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getStringValue () raises (DOMException); */
NS_IMETHODIMP nsDOMCSSPrimitiveValue::GetStringValue(nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMCounter getCounterValue () raises (DOMException); */
NS_IMETHODIMP nsDOMCSSPrimitiveValue::GetCounterValue(nsIDOMCounter * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMRect getRectValue () raises (DOMException); */
NS_IMETHODIMP nsDOMCSSPrimitiveValue::GetRectValue(nsIDOMRect * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSPrimitiveValue_h__ */

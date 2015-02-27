/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMCSSFontFeatureValuesRule.idl
 */

#ifndef __gen_nsIDOMCSSFontFeatureValuesRule_h__
#define __gen_nsIDOMCSSFontFeatureValuesRule_h__


#ifndef __gen_nsIDOMCSSRule_h__
#include "nsIDOMCSSRule.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCSSFontFeatureValuesRule */
#define NS_IDOMCSSFONTFEATUREVALUESRULE_IID_STR "f4cb1776-389d-4f52-a4d8-68bea5bd00c1"

#define NS_IDOMCSSFONTFEATUREVALUESRULE_IID \
  {0xf4cb1776, 0x389d, 0x4f52, \
    { 0xa4, 0xd8, 0x68, 0xbe, 0xa5, 0xbd, 0x00, 0xc1 }}

class NS_NO_VTABLE nsIDOMCSSFontFeatureValuesRule : public nsIDOMCSSRule {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSFONTFEATUREVALUESRULE_IID)

  /* attribute DOMString fontFamily; */
  NS_IMETHOD GetFontFamily(nsAString & aFontFamily) = 0;
  NS_IMETHOD SetFontFamily(const nsAString & aFontFamily) = 0;

  /* attribute DOMString valueText; */
  NS_IMETHOD GetValueText(nsAString & aValueText) = 0;
  NS_IMETHOD SetValueText(const nsAString & aValueText) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSFontFeatureValuesRule, NS_IDOMCSSFONTFEATUREVALUESRULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSFONTFEATUREVALUESRULE \
  NS_IMETHOD GetFontFamily(nsAString & aFontFamily); \
  NS_IMETHOD SetFontFamily(const nsAString & aFontFamily); \
  NS_IMETHOD GetValueText(nsAString & aValueText); \
  NS_IMETHOD SetValueText(const nsAString & aValueText); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSFONTFEATUREVALUESRULE(_to) \
  NS_IMETHOD GetFontFamily(nsAString & aFontFamily) { return _to GetFontFamily(aFontFamily); } \
  NS_IMETHOD SetFontFamily(const nsAString & aFontFamily) { return _to SetFontFamily(aFontFamily); } \
  NS_IMETHOD GetValueText(nsAString & aValueText) { return _to GetValueText(aValueText); } \
  NS_IMETHOD SetValueText(const nsAString & aValueText) { return _to SetValueText(aValueText); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSFONTFEATUREVALUESRULE(_to) \
  NS_IMETHOD GetFontFamily(nsAString & aFontFamily) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFontFamily(aFontFamily); } \
  NS_IMETHOD SetFontFamily(const nsAString & aFontFamily) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFontFamily(aFontFamily); } \
  NS_IMETHOD GetValueText(nsAString & aValueText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueText(aValueText); } \
  NS_IMETHOD SetValueText(const nsAString & aValueText) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValueText(aValueText); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSFontFeatureValuesRule : public nsIDOMCSSFontFeatureValuesRule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSFONTFEATUREVALUESRULE

  nsDOMCSSFontFeatureValuesRule();

private:
  ~nsDOMCSSFontFeatureValuesRule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCSSFontFeatureValuesRule, nsIDOMCSSFontFeatureValuesRule)

nsDOMCSSFontFeatureValuesRule::nsDOMCSSFontFeatureValuesRule()
{
  /* member initializers and constructor code */
}

nsDOMCSSFontFeatureValuesRule::~nsDOMCSSFontFeatureValuesRule()
{
  /* destructor code */
}

/* attribute DOMString fontFamily; */
NS_IMETHODIMP nsDOMCSSFontFeatureValuesRule::GetFontFamily(nsAString & aFontFamily)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCSSFontFeatureValuesRule::SetFontFamily(const nsAString & aFontFamily)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString valueText; */
NS_IMETHODIMP nsDOMCSSFontFeatureValuesRule::GetValueText(nsAString & aValueText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCSSFontFeatureValuesRule::SetValueText(const nsAString & aValueText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSFontFeatureValuesRule_h__ */

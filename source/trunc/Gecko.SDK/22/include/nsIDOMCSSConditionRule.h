/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/css/nsIDOMCSSConditionRule.idl
 */

#ifndef __gen_nsIDOMCSSConditionRule_h__
#define __gen_nsIDOMCSSConditionRule_h__


#ifndef __gen_nsIDOMCSSGroupingRule_h__
#include "nsIDOMCSSGroupingRule.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCSSConditionRule */
#define NS_IDOMCSSCONDITIONRULE_IID_STR "942754f2-2c0e-461b-9c10-c0e929504fe1"

#define NS_IDOMCSSCONDITIONRULE_IID \
  {0x942754f2, 0x2c0e, 0x461b, \
    { 0x9c, 0x10, 0xc0, 0xe9, 0x29, 0x50, 0x4f, 0xe1 }}

class NS_NO_VTABLE nsIDOMCSSConditionRule : public nsIDOMCSSGroupingRule {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSCONDITIONRULE_IID)

  /* attribute DOMString conditionText; */
  NS_IMETHOD GetConditionText(nsAString & aConditionText) = 0;
  NS_IMETHOD SetConditionText(const nsAString & aConditionText) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSConditionRule, NS_IDOMCSSCONDITIONRULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSCONDITIONRULE \
  NS_IMETHOD GetConditionText(nsAString & aConditionText); \
  NS_IMETHOD SetConditionText(const nsAString & aConditionText); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSCONDITIONRULE(_to) \
  NS_IMETHOD GetConditionText(nsAString & aConditionText) { return _to GetConditionText(aConditionText); } \
  NS_IMETHOD SetConditionText(const nsAString & aConditionText) { return _to SetConditionText(aConditionText); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSCONDITIONRULE(_to) \
  NS_IMETHOD GetConditionText(nsAString & aConditionText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConditionText(aConditionText); } \
  NS_IMETHOD SetConditionText(const nsAString & aConditionText) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetConditionText(aConditionText); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSConditionRule : public nsIDOMCSSConditionRule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSCONDITIONRULE

  nsDOMCSSConditionRule();

private:
  ~nsDOMCSSConditionRule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCSSConditionRule, nsIDOMCSSConditionRule)

nsDOMCSSConditionRule::nsDOMCSSConditionRule()
{
  /* member initializers and constructor code */
}

nsDOMCSSConditionRule::~nsDOMCSSConditionRule()
{
  /* destructor code */
}

/* attribute DOMString conditionText; */
NS_IMETHODIMP nsDOMCSSConditionRule::GetConditionText(nsAString & aConditionText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCSSConditionRule::SetConditionText(const nsAString & aConditionText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSConditionRule_h__ */

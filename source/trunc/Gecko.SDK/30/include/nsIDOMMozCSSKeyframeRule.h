/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMMozCSSKeyframeRule.idl
 */

#ifndef __gen_nsIDOMMozCSSKeyframeRule_h__
#define __gen_nsIDOMMozCSSKeyframeRule_h__


#ifndef __gen_nsIDOMCSSRule_h__
#include "nsIDOMCSSRule.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMozCSSKeyframeRule */
#define NS_IDOMMOZCSSKEYFRAMERULE_IID_STR "38a19612-dc58-414a-954c-233183808484"

#define NS_IDOMMOZCSSKEYFRAMERULE_IID \
  {0x38a19612, 0xdc58, 0x414a, \
    { 0x95, 0x4c, 0x23, 0x31, 0x83, 0x80, 0x84, 0x84 }}

class NS_NO_VTABLE nsIDOMMozCSSKeyframeRule : public nsIDOMCSSRule {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZCSSKEYFRAMERULE_IID)

  /* attribute DOMString keyText; */
  NS_IMETHOD GetKeyText(nsAString & aKeyText) = 0;
  NS_IMETHOD SetKeyText(const nsAString & aKeyText) = 0;

  /* readonly attribute nsIDOMCSSStyleDeclaration style; */
  NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozCSSKeyframeRule, NS_IDOMMOZCSSKEYFRAMERULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZCSSKEYFRAMERULE \
  NS_IMETHOD GetKeyText(nsAString & aKeyText); \
  NS_IMETHOD SetKeyText(const nsAString & aKeyText); \
  NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZCSSKEYFRAMERULE(_to) \
  NS_IMETHOD GetKeyText(nsAString & aKeyText) { return _to GetKeyText(aKeyText); } \
  NS_IMETHOD SetKeyText(const nsAString & aKeyText) { return _to SetKeyText(aKeyText); } \
  NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle) { return _to GetStyle(aStyle); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZCSSKEYFRAMERULE(_to) \
  NS_IMETHOD GetKeyText(nsAString & aKeyText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeyText(aKeyText); } \
  NS_IMETHOD SetKeyText(const nsAString & aKeyText) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetKeyText(aKeyText); } \
  NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStyle(aStyle); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozCSSKeyframeRule : public nsIDOMMozCSSKeyframeRule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZCSSKEYFRAMERULE

  nsDOMMozCSSKeyframeRule();

private:
  ~nsDOMMozCSSKeyframeRule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozCSSKeyframeRule, nsIDOMMozCSSKeyframeRule)

nsDOMMozCSSKeyframeRule::nsDOMMozCSSKeyframeRule()
{
  /* member initializers and constructor code */
}

nsDOMMozCSSKeyframeRule::~nsDOMMozCSSKeyframeRule()
{
  /* destructor code */
}

/* attribute DOMString keyText; */
NS_IMETHODIMP nsDOMMozCSSKeyframeRule::GetKeyText(nsAString & aKeyText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozCSSKeyframeRule::SetKeyText(const nsAString & aKeyText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMCSSStyleDeclaration style; */
NS_IMETHODIMP nsDOMMozCSSKeyframeRule::GetStyle(nsIDOMCSSStyleDeclaration * *aStyle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMozCSSKeyframeRule_h__ */

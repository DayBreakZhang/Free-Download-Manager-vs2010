/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMCSSPageRule.idl
 */

#ifndef __gen_nsIDOMCSSPageRule_h__
#define __gen_nsIDOMCSSPageRule_h__


#ifndef __gen_nsIDOMCSSRule_h__
#include "nsIDOMCSSRule.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCSSPageRule */
#define NS_IDOMCSSPAGERULE_IID_STR "6126024d-d716-4ad8-bc53-24dd6d5846b1"

#define NS_IDOMCSSPAGERULE_IID \
  {0x6126024d, 0xd716, 0x4ad8, \
    { 0xbc, 0x53, 0x24, 0xdd, 0x6d, 0x58, 0x46, 0xb1 }}

class NS_NO_VTABLE nsIDOMCSSPageRule : public nsIDOMCSSRule {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSPAGERULE_IID)

  /* readonly attribute nsIDOMCSSStyleDeclaration style; */
  NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSPageRule, NS_IDOMCSSPAGERULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSPAGERULE \
  NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSPAGERULE(_to) \
  NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle) { return _to GetStyle(aStyle); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSPAGERULE(_to) \
  NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStyle(aStyle); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSPageRule : public nsIDOMCSSPageRule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSPAGERULE

  nsDOMCSSPageRule();

private:
  ~nsDOMCSSPageRule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCSSPageRule, nsIDOMCSSPageRule)

nsDOMCSSPageRule::nsDOMCSSPageRule()
{
  /* member initializers and constructor code */
}

nsDOMCSSPageRule::~nsDOMCSSPageRule()
{
  /* destructor code */
}

/* readonly attribute nsIDOMCSSStyleDeclaration style; */
NS_IMETHODIMP nsDOMCSSPageRule::GetStyle(nsIDOMCSSStyleDeclaration * *aStyle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSPageRule_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMCSSMediaRule.idl
 */

#ifndef __gen_nsIDOMCSSMediaRule_h__
#define __gen_nsIDOMCSSMediaRule_h__


#ifndef __gen_nsIDOMCSSConditionRule_h__
#include "nsIDOMCSSConditionRule.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCSSMediaRule */
#define NS_IDOMCSSMEDIARULE_IID_STR "1f491b05-932b-4aa1-a1f1-466505d70898"

#define NS_IDOMCSSMEDIARULE_IID \
  {0x1f491b05, 0x932b, 0x4aa1, \
    { 0xa1, 0xf1, 0x46, 0x65, 0x05, 0xd7, 0x08, 0x98 }}

class NS_NO_VTABLE nsIDOMCSSMediaRule : public nsIDOMCSSConditionRule {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSMEDIARULE_IID)

  /* readonly attribute nsIDOMMediaList media; */
  NS_IMETHOD GetMedia(nsIDOMMediaList * *aMedia) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSMediaRule, NS_IDOMCSSMEDIARULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSMEDIARULE \
  NS_IMETHOD GetMedia(nsIDOMMediaList * *aMedia); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSMEDIARULE(_to) \
  NS_IMETHOD GetMedia(nsIDOMMediaList * *aMedia) { return _to GetMedia(aMedia); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSMEDIARULE(_to) \
  NS_IMETHOD GetMedia(nsIDOMMediaList * *aMedia) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMedia(aMedia); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSMediaRule : public nsIDOMCSSMediaRule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSMEDIARULE

  nsDOMCSSMediaRule();

private:
  ~nsDOMCSSMediaRule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCSSMediaRule, nsIDOMCSSMediaRule)

nsDOMCSSMediaRule::nsDOMCSSMediaRule()
{
  /* member initializers and constructor code */
}

nsDOMCSSMediaRule::~nsDOMCSSMediaRule()
{
  /* destructor code */
}

/* readonly attribute nsIDOMMediaList media; */
NS_IMETHODIMP nsDOMCSSMediaRule::GetMedia(nsIDOMMediaList * *aMedia)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSMediaRule_h__ */

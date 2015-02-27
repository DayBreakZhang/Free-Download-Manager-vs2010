/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMCSSSupportsRule.idl
 */

#ifndef __gen_nsIDOMCSSSupportsRule_h__
#define __gen_nsIDOMCSSSupportsRule_h__


#ifndef __gen_nsIDOMCSSConditionRule_h__
#include "nsIDOMCSSConditionRule.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCSSSupportsRule */
#define NS_IDOMCSSSUPPORTSRULE_IID_STR "5f409a4d-92f9-4a62-8e8a-cc1c02c32918"

#define NS_IDOMCSSSUPPORTSRULE_IID \
  {0x5f409a4d, 0x92f9, 0x4a62, \
    { 0x8e, 0x8a, 0xcc, 0x1c, 0x02, 0xc3, 0x29, 0x18 }}

class NS_NO_VTABLE nsIDOMCSSSupportsRule : public nsIDOMCSSConditionRule {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSSUPPORTSRULE_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSSupportsRule, NS_IDOMCSSSUPPORTSRULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSSUPPORTSRULE \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSSUPPORTSRULE(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSSUPPORTSRULE(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSSupportsRule : public nsIDOMCSSSupportsRule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSSUPPORTSRULE

  nsDOMCSSSupportsRule();

private:
  ~nsDOMCSSSupportsRule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCSSSupportsRule, nsIDOMCSSSupportsRule)

nsDOMCSSSupportsRule::nsDOMCSSSupportsRule()
{
  /* member initializers and constructor code */
}

nsDOMCSSSupportsRule::~nsDOMCSSSupportsRule()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSSupportsRule_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMCSSMozDocumentRule.idl
 */

#ifndef __gen_nsIDOMCSSMozDocumentRule_h__
#define __gen_nsIDOMCSSMozDocumentRule_h__


#ifndef __gen_nsIDOMCSSConditionRule_h__
#include "nsIDOMCSSConditionRule.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCSSMozDocumentRule */
#define NS_IDOMCSSMOZDOCUMENTRULE_IID_STR "f118a5a8-ac36-464f-b993-18cf6fe76fda"

#define NS_IDOMCSSMOZDOCUMENTRULE_IID \
  {0xf118a5a8, 0xac36, 0x464f, \
    { 0xb9, 0x93, 0x18, 0xcf, 0x6f, 0xe7, 0x6f, 0xda }}

class NS_NO_VTABLE nsIDOMCSSMozDocumentRule : public nsIDOMCSSConditionRule {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSMOZDOCUMENTRULE_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSMozDocumentRule, NS_IDOMCSSMOZDOCUMENTRULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSMOZDOCUMENTRULE \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSMOZDOCUMENTRULE(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSMOZDOCUMENTRULE(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSMozDocumentRule : public nsIDOMCSSMozDocumentRule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSMOZDOCUMENTRULE

  nsDOMCSSMozDocumentRule();

private:
  ~nsDOMCSSMozDocumentRule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCSSMozDocumentRule, nsIDOMCSSMozDocumentRule)

nsDOMCSSMozDocumentRule::nsDOMCSSMozDocumentRule()
{
  /* member initializers and constructor code */
}

nsDOMCSSMozDocumentRule::~nsDOMCSSMozDocumentRule()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSMozDocumentRule_h__ */

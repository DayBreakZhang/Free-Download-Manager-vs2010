/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMHTMLTableElement.idl
 */

#ifndef __gen_nsIDOMHTMLTableElement_h__
#define __gen_nsIDOMHTMLTableElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLTableElement */
#define NS_IDOMHTMLTABLEELEMENT_IID_STR "135a30ee-0374-4ee7-9d36-91736bff5fb1"

#define NS_IDOMHTMLTABLEELEMENT_IID \
  {0x135a30ee, 0x0374, 0x4ee7, \
    { 0x9d, 0x36, 0x91, 0x73, 0x6b, 0xff, 0x5f, 0xb1 }}

class NS_NO_VTABLE nsIDOMHTMLTableElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLTABLEELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLTableElement, NS_IDOMHTMLTABLEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLTABLEELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLTABLEELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLTABLEELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLTableElement : public nsIDOMHTMLTableElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLTABLEELEMENT

  nsDOMHTMLTableElement();

private:
  ~nsDOMHTMLTableElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLTableElement, nsIDOMHTMLTableElement)

nsDOMHTMLTableElement::nsDOMHTMLTableElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLTableElement::~nsDOMHTMLTableElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLTableElement_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMHTMLHeadElement.idl
 */

#ifndef __gen_nsIDOMHTMLHeadElement_h__
#define __gen_nsIDOMHTMLHeadElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLHeadElement */
#define NS_IDOMHTMLHEADELEMENT_IID_STR "59b80014-00f5-412d-846f-725494122d42"

#define NS_IDOMHTMLHEADELEMENT_IID \
  {0x59b80014, 0x00f5, 0x412d, \
    { 0x84, 0x6f, 0x72, 0x54, 0x94, 0x12, 0x2d, 0x42 }}

class NS_NO_VTABLE nsIDOMHTMLHeadElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLHEADELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLHeadElement, NS_IDOMHTMLHEADELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLHEADELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLHEADELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLHEADELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLHeadElement : public nsIDOMHTMLHeadElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLHEADELEMENT

  nsDOMHTMLHeadElement();

private:
  ~nsDOMHTMLHeadElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLHeadElement, nsIDOMHTMLHeadElement)

nsDOMHTMLHeadElement::nsDOMHTMLHeadElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLHeadElement::~nsDOMHTMLHeadElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLHeadElement_h__ */

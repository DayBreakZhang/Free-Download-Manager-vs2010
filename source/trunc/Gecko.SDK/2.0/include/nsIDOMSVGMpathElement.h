/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/svg/nsIDOMSVGMpathElement.idl
 */

#ifndef __gen_nsIDOMSVGMpathElement_h__
#define __gen_nsIDOMSVGMpathElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGMpathElement */
#define NS_IDOMSVGMPATHELEMENT_IID_STR "752f5ec1-eaf6-4cfa-887b-96bc69ec36b8"

#define NS_IDOMSVGMPATHELEMENT_IID \
  {0x752f5ec1, 0xeaf6, 0x4cfa, \
    { 0x88, 0x7b, 0x96, 0xbc, 0x69, 0xec, 0x36, 0xb8 }}

/**
 * For more information on this interface please see
 * http://www.w3.org/TR/SVG/animate.html#mpathElement
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGMpathElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGMPATHELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGMpathElement, NS_IDOMSVGMPATHELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGMPATHELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGMPATHELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGMPATHELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGMpathElement : public nsIDOMSVGMpathElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGMPATHELEMENT

  nsDOMSVGMpathElement();

private:
  ~nsDOMSVGMpathElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGMpathElement, nsIDOMSVGMpathElement)

nsDOMSVGMpathElement::nsDOMSVGMpathElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGMpathElement::~nsDOMSVGMpathElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGMpathElement_h__ */

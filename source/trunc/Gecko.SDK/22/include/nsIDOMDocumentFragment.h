/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/core/nsIDOMDocumentFragment.idl
 */

#ifndef __gen_nsIDOMDocumentFragment_h__
#define __gen_nsIDOMDocumentFragment_h__


#ifndef __gen_nsIDOMNode_h__
#include "nsIDOMNode.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDocumentFragment */
#define NS_IDOMDOCUMENTFRAGMENT_IID_STR "33127aed-9d6a-4b0d-95aa-0529f51bcb9c"

#define NS_IDOMDOCUMENTFRAGMENT_IID \
  {0x33127aed, 0x9d6a, 0x4b0d, \
    { 0x95, 0xaa, 0x05, 0x29, 0xf5, 0x1b, 0xcb, 0x9c }}

class NS_NO_VTABLE nsIDOMDocumentFragment : public nsIDOMNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOCUMENTFRAGMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDocumentFragment, NS_IDOMDOCUMENTFRAGMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOCUMENTFRAGMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOCUMENTFRAGMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOCUMENTFRAGMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDocumentFragment : public nsIDOMDocumentFragment
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOCUMENTFRAGMENT

  nsDOMDocumentFragment();

private:
  ~nsDOMDocumentFragment();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDocumentFragment, nsIDOMDocumentFragment)

nsDOMDocumentFragment::nsDOMDocumentFragment()
{
  /* member initializers and constructor code */
}

nsDOMDocumentFragment::~nsDOMDocumentFragment()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDocumentFragment_h__ */

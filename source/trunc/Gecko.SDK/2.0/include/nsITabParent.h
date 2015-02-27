/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/base/nsITabParent.idl
 */

#ifndef __gen_nsITabParent_h__
#define __gen_nsITabParent_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsITabParent */
#define NS_ITABPARENT_IID_STR "95c7c50b-6677-456f-9f1e-885e1cc272dc"

#define NS_ITABPARENT_IID \
  {0x95c7c50b, 0x6677, 0x456f, \
    { 0x9f, 0x1e, 0x88, 0x5e, 0x1c, 0xc2, 0x72, 0xdc }}

class NS_NO_VTABLE nsITabParent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITABPARENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITabParent, NS_ITABPARENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITABPARENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITABPARENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITABPARENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTabParent : public nsITabParent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITABPARENT

  nsTabParent();

private:
  ~nsTabParent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTabParent, nsITabParent)

nsTabParent::nsTabParent()
{
  /* member initializers and constructor code */
}

nsTabParent::~nsTabParent()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITabParent_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/base/nsITabChild.idl
 */

#ifndef __gen_nsITabChild_h__
#define __gen_nsITabChild_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsITabChild */
#define NS_ITABCHILD_IID_STR "a89f8ab5-ff71-492a-8ed5-71185446fa66"

#define NS_ITABCHILD_IID \
  {0xa89f8ab5, 0xff71, 0x492a, \
    { 0x8e, 0xd5, 0x71, 0x18, 0x54, 0x46, 0xfa, 0x66 }}

class NS_NO_VTABLE nsITabChild : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITABCHILD_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITabChild, NS_ITABCHILD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITABCHILD \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITABCHILD(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITABCHILD(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTabChild : public nsITabChild
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITABCHILD

  nsTabChild();

private:
  ~nsTabChild();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTabChild, nsITabChild)

nsTabChild::nsTabChild()
{
  /* member initializers and constructor code */
}

nsTabChild::~nsTabChild()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITabChild_h__ */

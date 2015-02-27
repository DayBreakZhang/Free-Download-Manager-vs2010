/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/modules/libpref/public/nsIPrefBranch2.idl
 */

#ifndef __gen_nsIPrefBranch2_h__
#define __gen_nsIPrefBranch2_h__


#ifndef __gen_nsIPrefBranch_h__
#include "nsIPrefBranch.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPrefBranch2 */
#define NS_IPREFBRANCH2_IID_STR "8892016d-07f7-4530-b5c1-d73dfcde4a1c"

#define NS_IPREFBRANCH2_IID \
  {0x8892016d, 0x07f7, 0x4530, \
    { 0xb5, 0xc1, 0xd7, 0x3d, 0xfc, 0xde, 0x4a, 0x1c }}

class NS_NO_VTABLE nsIPrefBranch2 : public nsIPrefBranch {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPREFBRANCH2_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrefBranch2, NS_IPREFBRANCH2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPREFBRANCH2 \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPREFBRANCH2(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPREFBRANCH2(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrefBranch2 : public nsIPrefBranch2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPREFBRANCH2

  nsPrefBranch2();

private:
  ~nsPrefBranch2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrefBranch2, nsIPrefBranch2)

nsPrefBranch2::nsPrefBranch2()
{
  /* member initializers and constructor code */
}

nsPrefBranch2::~nsPrefBranch2()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPrefBranch2_h__ */

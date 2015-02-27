/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPrefBranchInternal.idl
 */

#ifndef __gen_nsIPrefBranchInternal_h__
#define __gen_nsIPrefBranchInternal_h__


#ifndef __gen_nsIPrefBranch2_h__
#include "nsIPrefBranch2.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPrefBranchInternal */
#define NS_IPREFBRANCHINTERNAL_IID_STR "355bd1e9-248a-438b-809d-e0db1b287882"

#define NS_IPREFBRANCHINTERNAL_IID \
  {0x355bd1e9, 0x248a, 0x438b, \
    { 0x80, 0x9d, 0xe0, 0xdb, 0x1b, 0x28, 0x78, 0x82 }}

class NS_NO_VTABLE nsIPrefBranchInternal : public nsIPrefBranch2 {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPREFBRANCHINTERNAL_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrefBranchInternal, NS_IPREFBRANCHINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPREFBRANCHINTERNAL \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPREFBRANCHINTERNAL(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPREFBRANCHINTERNAL(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrefBranchInternal : public nsIPrefBranchInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPREFBRANCHINTERNAL

  nsPrefBranchInternal();

private:
  ~nsPrefBranchInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrefBranchInternal, nsIPrefBranchInternal)

nsPrefBranchInternal::nsPrefBranchInternal()
{
  /* member initializers and constructor code */
}

nsPrefBranchInternal::~nsPrefBranchInternal()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPrefBranchInternal_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDebug2.idl
 */

#ifndef __gen_nsIDebug2_h__
#define __gen_nsIDebug2_h__


#ifndef __gen_nsIDebug_h__
#include "nsIDebug.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDebug2 */
#define NS_IDEBUG2_IID_STR "6cb17fec-cdf7-4f7c-b267-37a0acaa9cf1"

#define NS_IDEBUG2_IID \
  {0x6cb17fec, 0xcdf7, 0x4f7c, \
    { 0xb2, 0x67, 0x37, 0xa0, 0xac, 0xaa, 0x9c, 0xf1 }}

class NS_NO_VTABLE nsIDebug2 : public nsIDebug {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDEBUG2_IID)

  /* readonly attribute boolean isDebugBuild; */
  NS_IMETHOD GetIsDebugBuild(bool *aIsDebugBuild) = 0;

  /* readonly attribute long assertionCount; */
  NS_IMETHOD GetAssertionCount(int32_t *aAssertionCount) = 0;

  /* readonly attribute bool isDebuggerAttached; */
  NS_IMETHOD GetIsDebuggerAttached(bool *aIsDebuggerAttached) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDebug2, NS_IDEBUG2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDEBUG2 \
  NS_IMETHOD GetIsDebugBuild(bool *aIsDebugBuild); \
  NS_IMETHOD GetAssertionCount(int32_t *aAssertionCount); \
  NS_IMETHOD GetIsDebuggerAttached(bool *aIsDebuggerAttached); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDEBUG2(_to) \
  NS_IMETHOD GetIsDebugBuild(bool *aIsDebugBuild) { return _to GetIsDebugBuild(aIsDebugBuild); } \
  NS_IMETHOD GetAssertionCount(int32_t *aAssertionCount) { return _to GetAssertionCount(aAssertionCount); } \
  NS_IMETHOD GetIsDebuggerAttached(bool *aIsDebuggerAttached) { return _to GetIsDebuggerAttached(aIsDebuggerAttached); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDEBUG2(_to) \
  NS_IMETHOD GetIsDebugBuild(bool *aIsDebugBuild) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsDebugBuild(aIsDebugBuild); } \
  NS_IMETHOD GetAssertionCount(int32_t *aAssertionCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAssertionCount(aAssertionCount); } \
  NS_IMETHOD GetIsDebuggerAttached(bool *aIsDebuggerAttached) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsDebuggerAttached(aIsDebuggerAttached); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDebug2 : public nsIDebug2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDEBUG2

  nsDebug2();

private:
  ~nsDebug2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDebug2, nsIDebug2)

nsDebug2::nsDebug2()
{
  /* member initializers and constructor code */
}

nsDebug2::~nsDebug2()
{
  /* destructor code */
}

/* readonly attribute boolean isDebugBuild; */
NS_IMETHODIMP nsDebug2::GetIsDebugBuild(bool *aIsDebugBuild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long assertionCount; */
NS_IMETHODIMP nsDebug2::GetAssertionCount(int32_t *aAssertionCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute bool isDebuggerAttached; */
NS_IMETHODIMP nsDebug2::GetIsDebuggerAttached(bool *aIsDebuggerAttached)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDebug2_h__ */

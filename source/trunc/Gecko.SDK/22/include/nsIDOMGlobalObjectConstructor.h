/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/base/nsIDOMGlobalObjectConstructor.idl
 */

#ifndef __gen_nsIDOMGlobalObjectConstructor_h__
#define __gen_nsIDOMGlobalObjectConstructor_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMGlobalObjectConstructor */
#define NS_IDOMGLOBALOBJECTCONSTRUCTOR_IID_STR "cb439c73-0129-4289-a349-c5216e6b912a"

#define NS_IDOMGLOBALOBJECTCONSTRUCTOR_IID \
  {0xcb439c73, 0x0129, 0x4289, \
    { 0xa3, 0x49, 0xc5, 0x21, 0x6e, 0x6b, 0x91, 0x2a }}

class NS_NO_VTABLE nsIDOMGlobalObjectConstructor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGLOBALOBJECTCONSTRUCTOR_IID)

  /* void constructor (); */
  NS_IMETHOD Constructor(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGlobalObjectConstructor, NS_IDOMGLOBALOBJECTCONSTRUCTOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGLOBALOBJECTCONSTRUCTOR \
  NS_IMETHOD Constructor(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGLOBALOBJECTCONSTRUCTOR(_to) \
  NS_IMETHOD Constructor(void) { return _to Constructor(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGLOBALOBJECTCONSTRUCTOR(_to) \
  NS_IMETHOD Constructor(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Constructor(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGlobalObjectConstructor : public nsIDOMGlobalObjectConstructor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGLOBALOBJECTCONSTRUCTOR

  nsDOMGlobalObjectConstructor();

private:
  ~nsDOMGlobalObjectConstructor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMGlobalObjectConstructor, nsIDOMGlobalObjectConstructor)

nsDOMGlobalObjectConstructor::nsDOMGlobalObjectConstructor()
{
  /* member initializers and constructor code */
}

nsDOMGlobalObjectConstructor::~nsDOMGlobalObjectConstructor()
{
  /* destructor code */
}

/* void constructor (); */
NS_IMETHODIMP nsDOMGlobalObjectConstructor::Constructor()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMGlobalObjectConstructor_h__ */

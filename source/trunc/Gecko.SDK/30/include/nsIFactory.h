/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIFactory.idl
 */

#ifndef __gen_nsIFactory_h__
#define __gen_nsIFactory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIFactory */
#define NS_IFACTORY_IID_STR "00000001-0000-0000-c000-000000000046"

#define NS_IFACTORY_IID \
  {0x00000001, 0x0000, 0x0000, \
    { 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46 }}

class NS_NO_VTABLE nsIFactory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFACTORY_IID)

  /* void createInstance (in nsISupports aOuter, in nsIIDRef iid, [iid_is (iid), retval] out nsQIResult result); */
  NS_IMETHOD CreateInstance(nsISupports *aOuter, const nsIID & iid, void **result) = 0;

  /* void lockFactory (in boolean lock); */
  NS_IMETHOD LockFactory(bool lock) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFactory, NS_IFACTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFACTORY \
  NS_IMETHOD CreateInstance(nsISupports *aOuter, const nsIID & iid, void **result); \
  NS_IMETHOD LockFactory(bool lock); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFACTORY(_to) \
  NS_IMETHOD CreateInstance(nsISupports *aOuter, const nsIID & iid, void **result) { return _to CreateInstance(aOuter, iid, result); } \
  NS_IMETHOD LockFactory(bool lock) { return _to LockFactory(lock); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFACTORY(_to) \
  NS_IMETHOD CreateInstance(nsISupports *aOuter, const nsIID & iid, void **result) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateInstance(aOuter, iid, result); } \
  NS_IMETHOD LockFactory(bool lock) { return !_to ? NS_ERROR_NULL_POINTER : _to->LockFactory(lock); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFactory : public nsIFactory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFACTORY

  nsFactory();

private:
  ~nsFactory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFactory, nsIFactory)

nsFactory::nsFactory()
{
  /* member initializers and constructor code */
}

nsFactory::~nsFactory()
{
  /* destructor code */
}

/* void createInstance (in nsISupports aOuter, in nsIIDRef iid, [iid_is (iid), retval] out nsQIResult result); */
NS_IMETHODIMP nsFactory::CreateInstance(nsISupports *aOuter, const nsIID & iid, void **result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void lockFactory (in boolean lock); */
NS_IMETHODIMP nsFactory::LockFactory(bool lock)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFactory_h__ */

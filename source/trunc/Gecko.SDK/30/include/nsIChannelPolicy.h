/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIChannelPolicy.idl
 */

#ifndef __gen_nsIChannelPolicy_h__
#define __gen_nsIChannelPolicy_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIChannelPolicy */
#define NS_ICHANNELPOLICY_IID_STR "18045e96-1afe-4162-837a-04691267158c"

#define NS_ICHANNELPOLICY_IID \
  {0x18045e96, 0x1afe, 0x4162, \
    { 0x83, 0x7a, 0x04, 0x69, 0x12, 0x67, 0x15, 0x8c }}

class NS_NO_VTABLE nsIChannelPolicy : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICHANNELPOLICY_IID)

  /* attribute unsigned long loadType; */
  NS_IMETHOD GetLoadType(uint32_t *aLoadType) = 0;
  NS_IMETHOD SetLoadType(uint32_t aLoadType) = 0;

  /* attribute nsISupports contentSecurityPolicy; */
  NS_IMETHOD GetContentSecurityPolicy(nsISupports * *aContentSecurityPolicy) = 0;
  NS_IMETHOD SetContentSecurityPolicy(nsISupports *aContentSecurityPolicy) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIChannelPolicy, NS_ICHANNELPOLICY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICHANNELPOLICY \
  NS_IMETHOD GetLoadType(uint32_t *aLoadType); \
  NS_IMETHOD SetLoadType(uint32_t aLoadType); \
  NS_IMETHOD GetContentSecurityPolicy(nsISupports * *aContentSecurityPolicy); \
  NS_IMETHOD SetContentSecurityPolicy(nsISupports *aContentSecurityPolicy); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICHANNELPOLICY(_to) \
  NS_IMETHOD GetLoadType(uint32_t *aLoadType) { return _to GetLoadType(aLoadType); } \
  NS_IMETHOD SetLoadType(uint32_t aLoadType) { return _to SetLoadType(aLoadType); } \
  NS_IMETHOD GetContentSecurityPolicy(nsISupports * *aContentSecurityPolicy) { return _to GetContentSecurityPolicy(aContentSecurityPolicy); } \
  NS_IMETHOD SetContentSecurityPolicy(nsISupports *aContentSecurityPolicy) { return _to SetContentSecurityPolicy(aContentSecurityPolicy); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICHANNELPOLICY(_to) \
  NS_IMETHOD GetLoadType(uint32_t *aLoadType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadType(aLoadType); } \
  NS_IMETHOD SetLoadType(uint32_t aLoadType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLoadType(aLoadType); } \
  NS_IMETHOD GetContentSecurityPolicy(nsISupports * *aContentSecurityPolicy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentSecurityPolicy(aContentSecurityPolicy); } \
  NS_IMETHOD SetContentSecurityPolicy(nsISupports *aContentSecurityPolicy) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentSecurityPolicy(aContentSecurityPolicy); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsChannelPolicy : public nsIChannelPolicy
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICHANNELPOLICY

  nsChannelPolicy();

private:
  ~nsChannelPolicy();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsChannelPolicy, nsIChannelPolicy)

nsChannelPolicy::nsChannelPolicy()
{
  /* member initializers and constructor code */
}

nsChannelPolicy::~nsChannelPolicy()
{
  /* destructor code */
}

/* attribute unsigned long loadType; */
NS_IMETHODIMP nsChannelPolicy::GetLoadType(uint32_t *aLoadType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsChannelPolicy::SetLoadType(uint32_t aLoadType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISupports contentSecurityPolicy; */
NS_IMETHODIMP nsChannelPolicy::GetContentSecurityPolicy(nsISupports * *aContentSecurityPolicy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsChannelPolicy::SetContentSecurityPolicy(nsISupports *aContentSecurityPolicy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIChannelPolicy_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/security/manager/boot/public/nsISSLStatusProvider.idl
 */

#ifndef __gen_nsISSLStatusProvider_h__
#define __gen_nsISSLStatusProvider_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISSLStatus; /* forward declaration */


/* starting interface:    nsISSLStatusProvider */
#define NS_ISSLSTATUSPROVIDER_IID_STR "179b1ab1-0950-4427-9556-6f496dc4a27f"

#define NS_ISSLSTATUSPROVIDER_IID \
  {0x179b1ab1, 0x0950, 0x4427, \
    { 0x95, 0x56, 0x6f, 0x49, 0x6d, 0xc4, 0xa2, 0x7f }}

class NS_NO_VTABLE nsISSLStatusProvider : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISSLSTATUSPROVIDER_IID)

  /* readonly attribute nsISSLStatus SSLStatus; */
  NS_IMETHOD GetSSLStatus(nsISSLStatus * *aSSLStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISSLStatusProvider, NS_ISSLSTATUSPROVIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISSLSTATUSPROVIDER \
  NS_IMETHOD GetSSLStatus(nsISSLStatus * *aSSLStatus); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISSLSTATUSPROVIDER(_to) \
  NS_IMETHOD GetSSLStatus(nsISSLStatus * *aSSLStatus) { return _to GetSSLStatus(aSSLStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISSLSTATUSPROVIDER(_to) \
  NS_IMETHOD GetSSLStatus(nsISSLStatus * *aSSLStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSSLStatus(aSSLStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSSLStatusProvider : public nsISSLStatusProvider
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISSLSTATUSPROVIDER

  nsSSLStatusProvider();

private:
  ~nsSSLStatusProvider();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSSLStatusProvider, nsISSLStatusProvider)

nsSSLStatusProvider::nsSSLStatusProvider()
{
  /* member initializers and constructor code */
}

nsSSLStatusProvider::~nsSSLStatusProvider()
{
  /* destructor code */
}

/* readonly attribute nsISSLStatus SSLStatus; */
NS_IMETHODIMP nsSSLStatusProvider::GetSSLStatus(nsISSLStatus * *aSSLStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISSLStatusProvider_h__ */

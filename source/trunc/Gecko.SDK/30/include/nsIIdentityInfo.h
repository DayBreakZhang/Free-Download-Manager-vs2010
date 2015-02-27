/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIIdentityInfo.idl
 */

#ifndef __gen_nsIIdentityInfo_h__
#define __gen_nsIIdentityInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIIdentityInfo */
#define NS_IIDENTITYINFO_IID_STR "e9da87b8-b87c-4bd1-a6bc-5a9a2c7f6d8d"

#define NS_IIDENTITYINFO_IID \
  {0xe9da87b8, 0xb87c, 0x4bd1, \
    { 0xa6, 0xbc, 0x5a, 0x9a, 0x2c, 0x7f, 0x6d, 0x8d }}

class NS_NO_VTABLE nsIIdentityInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDENTITYINFO_IID)

  /* readonly attribute boolean isExtendedValidation; */
  NS_IMETHOD GetIsExtendedValidation(bool *aIsExtendedValidation) = 0;

  /* ACString getValidEVPolicyOid (); */
  NS_IMETHOD GetValidEVPolicyOid(nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIdentityInfo, NS_IIDENTITYINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDENTITYINFO \
  NS_IMETHOD GetIsExtendedValidation(bool *aIsExtendedValidation); \
  NS_IMETHOD GetValidEVPolicyOid(nsACString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDENTITYINFO(_to) \
  NS_IMETHOD GetIsExtendedValidation(bool *aIsExtendedValidation) { return _to GetIsExtendedValidation(aIsExtendedValidation); } \
  NS_IMETHOD GetValidEVPolicyOid(nsACString & _retval) { return _to GetValidEVPolicyOid(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDENTITYINFO(_to) \
  NS_IMETHOD GetIsExtendedValidation(bool *aIsExtendedValidation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsExtendedValidation(aIsExtendedValidation); } \
  NS_IMETHOD GetValidEVPolicyOid(nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValidEVPolicyOid(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIdentityInfo : public nsIIdentityInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDENTITYINFO

  nsIdentityInfo();

private:
  ~nsIdentityInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIdentityInfo, nsIIdentityInfo)

nsIdentityInfo::nsIdentityInfo()
{
  /* member initializers and constructor code */
}

nsIdentityInfo::~nsIdentityInfo()
{
  /* destructor code */
}

/* readonly attribute boolean isExtendedValidation; */
NS_IMETHODIMP nsIdentityInfo::GetIsExtendedValidation(bool *aIsExtendedValidation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getValidEVPolicyOid (); */
NS_IMETHODIMP nsIdentityInfo::GetValidEVPolicyOid(nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIdentityInfo_h__ */

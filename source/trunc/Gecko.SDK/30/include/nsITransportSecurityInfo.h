/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITransportSecurityInfo.idl
 */

#ifndef __gen_nsITransportSecurityInfo_h__
#define __gen_nsITransportSecurityInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsITransportSecurityInfo */
#define NS_ITRANSPORTSECURITYINFO_IID_STR "8813d03b-e76c-4240-9691-d327d9b91e88"

#define NS_ITRANSPORTSECURITYINFO_IID \
  {0x8813d03b, 0xe76c, 0x4240, \
    { 0x96, 0x91, 0xd3, 0x27, 0xd9, 0xb9, 0x1e, 0x88 }}

class NS_NO_VTABLE nsITransportSecurityInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITRANSPORTSECURITYINFO_IID)

  /* readonly attribute unsigned long securityState; */
  NS_IMETHOD GetSecurityState(uint32_t *aSecurityState) = 0;

  /* readonly attribute wstring errorMessage; */
  NS_IMETHOD GetErrorMessage(char16_t * *aErrorMessage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITransportSecurityInfo, NS_ITRANSPORTSECURITYINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITRANSPORTSECURITYINFO \
  NS_IMETHOD GetSecurityState(uint32_t *aSecurityState); \
  NS_IMETHOD GetErrorMessage(char16_t * *aErrorMessage); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITRANSPORTSECURITYINFO(_to) \
  NS_IMETHOD GetSecurityState(uint32_t *aSecurityState) { return _to GetSecurityState(aSecurityState); } \
  NS_IMETHOD GetErrorMessage(char16_t * *aErrorMessage) { return _to GetErrorMessage(aErrorMessage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITRANSPORTSECURITYINFO(_to) \
  NS_IMETHOD GetSecurityState(uint32_t *aSecurityState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSecurityState(aSecurityState); } \
  NS_IMETHOD GetErrorMessage(char16_t * *aErrorMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetErrorMessage(aErrorMessage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTransportSecurityInfo : public nsITransportSecurityInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITRANSPORTSECURITYINFO

  nsTransportSecurityInfo();

private:
  ~nsTransportSecurityInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTransportSecurityInfo, nsITransportSecurityInfo)

nsTransportSecurityInfo::nsTransportSecurityInfo()
{
  /* member initializers and constructor code */
}

nsTransportSecurityInfo::~nsTransportSecurityInfo()
{
  /* destructor code */
}

/* readonly attribute unsigned long securityState; */
NS_IMETHODIMP nsTransportSecurityInfo::GetSecurityState(uint32_t *aSecurityState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring errorMessage; */
NS_IMETHODIMP nsTransportSecurityInfo::GetErrorMessage(char16_t * *aErrorMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITransportSecurityInfo_h__ */

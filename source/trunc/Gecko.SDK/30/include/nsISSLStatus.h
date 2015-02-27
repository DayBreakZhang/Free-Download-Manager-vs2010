/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISSLStatus.idl
 */

#ifndef __gen_nsISSLStatus_h__
#define __gen_nsISSLStatus_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIX509Cert; /* forward declaration */


/* starting interface:    nsISSLStatus */
#define NS_ISSLSTATUS_IID_STR "3f1fcd83-c5a9-4cd1-a250-7676ca7c7e34"

#define NS_ISSLSTATUS_IID \
  {0x3f1fcd83, 0xc5a9, 0x4cd1, \
    { 0xa2, 0x50, 0x76, 0x76, 0xca, 0x7c, 0x7e, 0x34 }}

class NS_NO_VTABLE nsISSLStatus : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISSLSTATUS_IID)

  /* readonly attribute nsIX509Cert serverCert; */
  NS_IMETHOD GetServerCert(nsIX509Cert * *aServerCert) = 0;

  /* readonly attribute string cipherName; */
  NS_IMETHOD GetCipherName(char * *aCipherName) = 0;

  /* readonly attribute unsigned long keyLength; */
  NS_IMETHOD GetKeyLength(uint32_t *aKeyLength) = 0;

  /* readonly attribute unsigned long secretKeyLength; */
  NS_IMETHOD GetSecretKeyLength(uint32_t *aSecretKeyLength) = 0;

  /* readonly attribute boolean isDomainMismatch; */
  NS_IMETHOD GetIsDomainMismatch(bool *aIsDomainMismatch) = 0;

  /* readonly attribute boolean isNotValidAtThisTime; */
  NS_IMETHOD GetIsNotValidAtThisTime(bool *aIsNotValidAtThisTime) = 0;

  /* readonly attribute boolean isUntrusted; */
  NS_IMETHOD GetIsUntrusted(bool *aIsUntrusted) = 0;

  /* readonly attribute boolean isExtendedValidation; */
  NS_IMETHOD GetIsExtendedValidation(bool *aIsExtendedValidation) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISSLStatus, NS_ISSLSTATUS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISSLSTATUS \
  NS_IMETHOD GetServerCert(nsIX509Cert * *aServerCert); \
  NS_IMETHOD GetCipherName(char * *aCipherName); \
  NS_IMETHOD GetKeyLength(uint32_t *aKeyLength); \
  NS_IMETHOD GetSecretKeyLength(uint32_t *aSecretKeyLength); \
  NS_IMETHOD GetIsDomainMismatch(bool *aIsDomainMismatch); \
  NS_IMETHOD GetIsNotValidAtThisTime(bool *aIsNotValidAtThisTime); \
  NS_IMETHOD GetIsUntrusted(bool *aIsUntrusted); \
  NS_IMETHOD GetIsExtendedValidation(bool *aIsExtendedValidation); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISSLSTATUS(_to) \
  NS_IMETHOD GetServerCert(nsIX509Cert * *aServerCert) { return _to GetServerCert(aServerCert); } \
  NS_IMETHOD GetCipherName(char * *aCipherName) { return _to GetCipherName(aCipherName); } \
  NS_IMETHOD GetKeyLength(uint32_t *aKeyLength) { return _to GetKeyLength(aKeyLength); } \
  NS_IMETHOD GetSecretKeyLength(uint32_t *aSecretKeyLength) { return _to GetSecretKeyLength(aSecretKeyLength); } \
  NS_IMETHOD GetIsDomainMismatch(bool *aIsDomainMismatch) { return _to GetIsDomainMismatch(aIsDomainMismatch); } \
  NS_IMETHOD GetIsNotValidAtThisTime(bool *aIsNotValidAtThisTime) { return _to GetIsNotValidAtThisTime(aIsNotValidAtThisTime); } \
  NS_IMETHOD GetIsUntrusted(bool *aIsUntrusted) { return _to GetIsUntrusted(aIsUntrusted); } \
  NS_IMETHOD GetIsExtendedValidation(bool *aIsExtendedValidation) { return _to GetIsExtendedValidation(aIsExtendedValidation); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISSLSTATUS(_to) \
  NS_IMETHOD GetServerCert(nsIX509Cert * *aServerCert) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetServerCert(aServerCert); } \
  NS_IMETHOD GetCipherName(char * *aCipherName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCipherName(aCipherName); } \
  NS_IMETHOD GetKeyLength(uint32_t *aKeyLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeyLength(aKeyLength); } \
  NS_IMETHOD GetSecretKeyLength(uint32_t *aSecretKeyLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSecretKeyLength(aSecretKeyLength); } \
  NS_IMETHOD GetIsDomainMismatch(bool *aIsDomainMismatch) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsDomainMismatch(aIsDomainMismatch); } \
  NS_IMETHOD GetIsNotValidAtThisTime(bool *aIsNotValidAtThisTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsNotValidAtThisTime(aIsNotValidAtThisTime); } \
  NS_IMETHOD GetIsUntrusted(bool *aIsUntrusted) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsUntrusted(aIsUntrusted); } \
  NS_IMETHOD GetIsExtendedValidation(bool *aIsExtendedValidation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsExtendedValidation(aIsExtendedValidation); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSSLStatus : public nsISSLStatus
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISSLSTATUS

  nsSSLStatus();

private:
  ~nsSSLStatus();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSSLStatus, nsISSLStatus)

nsSSLStatus::nsSSLStatus()
{
  /* member initializers and constructor code */
}

nsSSLStatus::~nsSSLStatus()
{
  /* destructor code */
}

/* readonly attribute nsIX509Cert serverCert; */
NS_IMETHODIMP nsSSLStatus::GetServerCert(nsIX509Cert * *aServerCert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string cipherName; */
NS_IMETHODIMP nsSSLStatus::GetCipherName(char * *aCipherName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long keyLength; */
NS_IMETHODIMP nsSSLStatus::GetKeyLength(uint32_t *aKeyLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long secretKeyLength; */
NS_IMETHODIMP nsSSLStatus::GetSecretKeyLength(uint32_t *aSecretKeyLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isDomainMismatch; */
NS_IMETHODIMP nsSSLStatus::GetIsDomainMismatch(bool *aIsDomainMismatch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isNotValidAtThisTime; */
NS_IMETHODIMP nsSSLStatus::GetIsNotValidAtThisTime(bool *aIsNotValidAtThisTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isUntrusted; */
NS_IMETHODIMP nsSSLStatus::GetIsUntrusted(bool *aIsUntrusted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isExtendedValidation; */
NS_IMETHODIMP nsSSLStatus::GetIsExtendedValidation(bool *aIsExtendedValidation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISSLStatus_h__ */

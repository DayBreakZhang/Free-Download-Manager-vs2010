/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsILoginManagerCrypto.idl
 */

#ifndef __gen_nsILoginManagerCrypto_h__
#define __gen_nsILoginManagerCrypto_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsILoginManagerCrypto */
#define NS_ILOGINMANAGERCRYPTO_IID_STR "2030770e-542e-40cd-8061-cd9d4ad4227f"

#define NS_ILOGINMANAGERCRYPTO_IID \
  {0x2030770e, 0x542e, 0x40cd, \
    { 0x80, 0x61, 0xcd, 0x9d, 0x4a, 0xd4, 0x22, 0x7f }}

class NS_NO_VTABLE nsILoginManagerCrypto : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOGINMANAGERCRYPTO_IID)

  enum {
    ENCTYPE_BASE64 = 0U,
    ENCTYPE_SDR = 1U
  };

  /* AString encrypt (in AString plainText); */
  NS_IMETHOD Encrypt(const nsAString & plainText, nsAString & _retval) = 0;

  /* AString decrypt (in AString cipherText); */
  NS_IMETHOD Decrypt(const nsAString & cipherText, nsAString & _retval) = 0;

  /* readonly attribute boolean uiBusy; */
  NS_IMETHOD GetUiBusy(bool *aUiBusy) = 0;

  /* readonly attribute boolean isLoggedIn; */
  NS_IMETHOD GetIsLoggedIn(bool *aIsLoggedIn) = 0;

  /* readonly attribute unsigned long defaultEncType; */
  NS_IMETHOD GetDefaultEncType(uint32_t *aDefaultEncType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILoginManagerCrypto, NS_ILOGINMANAGERCRYPTO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOGINMANAGERCRYPTO \
  NS_IMETHOD Encrypt(const nsAString & plainText, nsAString & _retval); \
  NS_IMETHOD Decrypt(const nsAString & cipherText, nsAString & _retval); \
  NS_IMETHOD GetUiBusy(bool *aUiBusy); \
  NS_IMETHOD GetIsLoggedIn(bool *aIsLoggedIn); \
  NS_IMETHOD GetDefaultEncType(uint32_t *aDefaultEncType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOGINMANAGERCRYPTO(_to) \
  NS_IMETHOD Encrypt(const nsAString & plainText, nsAString & _retval) { return _to Encrypt(plainText, _retval); } \
  NS_IMETHOD Decrypt(const nsAString & cipherText, nsAString & _retval) { return _to Decrypt(cipherText, _retval); } \
  NS_IMETHOD GetUiBusy(bool *aUiBusy) { return _to GetUiBusy(aUiBusy); } \
  NS_IMETHOD GetIsLoggedIn(bool *aIsLoggedIn) { return _to GetIsLoggedIn(aIsLoggedIn); } \
  NS_IMETHOD GetDefaultEncType(uint32_t *aDefaultEncType) { return _to GetDefaultEncType(aDefaultEncType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOGINMANAGERCRYPTO(_to) \
  NS_IMETHOD Encrypt(const nsAString & plainText, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Encrypt(plainText, _retval); } \
  NS_IMETHOD Decrypt(const nsAString & cipherText, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Decrypt(cipherText, _retval); } \
  NS_IMETHOD GetUiBusy(bool *aUiBusy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUiBusy(aUiBusy); } \
  NS_IMETHOD GetIsLoggedIn(bool *aIsLoggedIn) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsLoggedIn(aIsLoggedIn); } \
  NS_IMETHOD GetDefaultEncType(uint32_t *aDefaultEncType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultEncType(aDefaultEncType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLoginManagerCrypto : public nsILoginManagerCrypto
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOGINMANAGERCRYPTO

  nsLoginManagerCrypto();

private:
  ~nsLoginManagerCrypto();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLoginManagerCrypto, nsILoginManagerCrypto)

nsLoginManagerCrypto::nsLoginManagerCrypto()
{
  /* member initializers and constructor code */
}

nsLoginManagerCrypto::~nsLoginManagerCrypto()
{
  /* destructor code */
}

/* AString encrypt (in AString plainText); */
NS_IMETHODIMP nsLoginManagerCrypto::Encrypt(const nsAString & plainText, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString decrypt (in AString cipherText); */
NS_IMETHODIMP nsLoginManagerCrypto::Decrypt(const nsAString & cipherText, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean uiBusy; */
NS_IMETHODIMP nsLoginManagerCrypto::GetUiBusy(bool *aUiBusy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isLoggedIn; */
NS_IMETHODIMP nsLoginManagerCrypto::GetIsLoggedIn(bool *aIsLoggedIn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long defaultEncType; */
NS_IMETHODIMP nsLoginManagerCrypto::GetDefaultEncType(uint32_t *aDefaultEncType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsILoginManagerCrypto_h__ */

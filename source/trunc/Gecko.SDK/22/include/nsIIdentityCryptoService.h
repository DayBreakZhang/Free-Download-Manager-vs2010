/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/toolkit/identity/nsIIdentityCryptoService.idl
 */

#ifndef __gen_nsIIdentityCryptoService_h__
#define __gen_nsIIdentityCryptoService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIIdentityKeyGenCallback; /* forward declaration */

class nsIIdentitySignCallback; /* forward declaration */


/* starting interface:    nsIIdentityCryptoService */
#define NS_IIDENTITYCRYPTOSERVICE_IID_STR "f087e6bc-dd33-4f6c-a106-dd786e052ee9"

#define NS_IIDENTITYCRYPTOSERVICE_IID \
  {0xf087e6bc, 0xdd33, 0x4f6c, \
    { 0xa1, 0x06, 0xdd, 0x78, 0x6e, 0x05, 0x2e, 0xe9 }}

class NS_NO_VTABLE nsIIdentityCryptoService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDENTITYCRYPTOSERVICE_IID)

  /* void generateKeyPair (in AUTF8String algorithm, in nsIIdentityKeyGenCallback callback); */
  NS_IMETHOD GenerateKeyPair(const nsACString & algorithm, nsIIdentityKeyGenCallback *callback) = 0;

  /* ACString base64UrlEncode (in AUTF8String toEncode); */
  NS_IMETHOD Base64UrlEncode(const nsACString & toEncode, nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIdentityCryptoService, NS_IIDENTITYCRYPTOSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDENTITYCRYPTOSERVICE \
  NS_IMETHOD GenerateKeyPair(const nsACString & algorithm, nsIIdentityKeyGenCallback *callback); \
  NS_IMETHOD Base64UrlEncode(const nsACString & toEncode, nsACString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDENTITYCRYPTOSERVICE(_to) \
  NS_IMETHOD GenerateKeyPair(const nsACString & algorithm, nsIIdentityKeyGenCallback *callback) { return _to GenerateKeyPair(algorithm, callback); } \
  NS_IMETHOD Base64UrlEncode(const nsACString & toEncode, nsACString & _retval) { return _to Base64UrlEncode(toEncode, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDENTITYCRYPTOSERVICE(_to) \
  NS_IMETHOD GenerateKeyPair(const nsACString & algorithm, nsIIdentityKeyGenCallback *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->GenerateKeyPair(algorithm, callback); } \
  NS_IMETHOD Base64UrlEncode(const nsACString & toEncode, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Base64UrlEncode(toEncode, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIdentityCryptoService : public nsIIdentityCryptoService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDENTITYCRYPTOSERVICE

  nsIdentityCryptoService();

private:
  ~nsIdentityCryptoService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIdentityCryptoService, nsIIdentityCryptoService)

nsIdentityCryptoService::nsIdentityCryptoService()
{
  /* member initializers and constructor code */
}

nsIdentityCryptoService::~nsIdentityCryptoService()
{
  /* destructor code */
}

/* void generateKeyPair (in AUTF8String algorithm, in nsIIdentityKeyGenCallback callback); */
NS_IMETHODIMP nsIdentityCryptoService::GenerateKeyPair(const nsACString & algorithm, nsIIdentityKeyGenCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString base64UrlEncode (in AUTF8String toEncode); */
NS_IMETHODIMP nsIdentityCryptoService::Base64UrlEncode(const nsACString & toEncode, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIIdentityKeyPair */
#define NS_IIDENTITYKEYPAIR_IID_STR "73962dc7-8ee7-4346-a12b-b039e1d9b54d"

#define NS_IIDENTITYKEYPAIR_IID \
  {0x73962dc7, 0x8ee7, 0x4346, \
    { 0xa1, 0x2b, 0xb0, 0x39, 0xe1, 0xd9, 0xb5, 0x4d }}

class NS_NO_VTABLE nsIIdentityKeyPair : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDENTITYKEYPAIR_IID)

  /* readonly attribute AUTF8String keyType; */
  NS_IMETHOD GetKeyType(nsACString & aKeyType) = 0;

  /* readonly attribute AUTF8String hexRSAPublicKeyExponent; */
  NS_IMETHOD GetHexRSAPublicKeyExponent(nsACString & aHexRSAPublicKeyExponent) = 0;

  /* readonly attribute AUTF8String hexRSAPublicKeyModulus; */
  NS_IMETHOD GetHexRSAPublicKeyModulus(nsACString & aHexRSAPublicKeyModulus) = 0;

  /* readonly attribute AUTF8String hexDSAPrime; */
  NS_IMETHOD GetHexDSAPrime(nsACString & aHexDSAPrime) = 0;

  /* readonly attribute AUTF8String hexDSASubPrime; */
  NS_IMETHOD GetHexDSASubPrime(nsACString & aHexDSASubPrime) = 0;

  /* readonly attribute AUTF8String hexDSAGenerator; */
  NS_IMETHOD GetHexDSAGenerator(nsACString & aHexDSAGenerator) = 0;

  /* readonly attribute AUTF8String hexDSAPublicValue; */
  NS_IMETHOD GetHexDSAPublicValue(nsACString & aHexDSAPublicValue) = 0;

  /* void sign (in AUTF8String aText, in nsIIdentitySignCallback callback); */
  NS_IMETHOD Sign(const nsACString & aText, nsIIdentitySignCallback *callback) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIdentityKeyPair, NS_IIDENTITYKEYPAIR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDENTITYKEYPAIR \
  NS_IMETHOD GetKeyType(nsACString & aKeyType); \
  NS_IMETHOD GetHexRSAPublicKeyExponent(nsACString & aHexRSAPublicKeyExponent); \
  NS_IMETHOD GetHexRSAPublicKeyModulus(nsACString & aHexRSAPublicKeyModulus); \
  NS_IMETHOD GetHexDSAPrime(nsACString & aHexDSAPrime); \
  NS_IMETHOD GetHexDSASubPrime(nsACString & aHexDSASubPrime); \
  NS_IMETHOD GetHexDSAGenerator(nsACString & aHexDSAGenerator); \
  NS_IMETHOD GetHexDSAPublicValue(nsACString & aHexDSAPublicValue); \
  NS_IMETHOD Sign(const nsACString & aText, nsIIdentitySignCallback *callback); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDENTITYKEYPAIR(_to) \
  NS_IMETHOD GetKeyType(nsACString & aKeyType) { return _to GetKeyType(aKeyType); } \
  NS_IMETHOD GetHexRSAPublicKeyExponent(nsACString & aHexRSAPublicKeyExponent) { return _to GetHexRSAPublicKeyExponent(aHexRSAPublicKeyExponent); } \
  NS_IMETHOD GetHexRSAPublicKeyModulus(nsACString & aHexRSAPublicKeyModulus) { return _to GetHexRSAPublicKeyModulus(aHexRSAPublicKeyModulus); } \
  NS_IMETHOD GetHexDSAPrime(nsACString & aHexDSAPrime) { return _to GetHexDSAPrime(aHexDSAPrime); } \
  NS_IMETHOD GetHexDSASubPrime(nsACString & aHexDSASubPrime) { return _to GetHexDSASubPrime(aHexDSASubPrime); } \
  NS_IMETHOD GetHexDSAGenerator(nsACString & aHexDSAGenerator) { return _to GetHexDSAGenerator(aHexDSAGenerator); } \
  NS_IMETHOD GetHexDSAPublicValue(nsACString & aHexDSAPublicValue) { return _to GetHexDSAPublicValue(aHexDSAPublicValue); } \
  NS_IMETHOD Sign(const nsACString & aText, nsIIdentitySignCallback *callback) { return _to Sign(aText, callback); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDENTITYKEYPAIR(_to) \
  NS_IMETHOD GetKeyType(nsACString & aKeyType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeyType(aKeyType); } \
  NS_IMETHOD GetHexRSAPublicKeyExponent(nsACString & aHexRSAPublicKeyExponent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHexRSAPublicKeyExponent(aHexRSAPublicKeyExponent); } \
  NS_IMETHOD GetHexRSAPublicKeyModulus(nsACString & aHexRSAPublicKeyModulus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHexRSAPublicKeyModulus(aHexRSAPublicKeyModulus); } \
  NS_IMETHOD GetHexDSAPrime(nsACString & aHexDSAPrime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHexDSAPrime(aHexDSAPrime); } \
  NS_IMETHOD GetHexDSASubPrime(nsACString & aHexDSASubPrime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHexDSASubPrime(aHexDSASubPrime); } \
  NS_IMETHOD GetHexDSAGenerator(nsACString & aHexDSAGenerator) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHexDSAGenerator(aHexDSAGenerator); } \
  NS_IMETHOD GetHexDSAPublicValue(nsACString & aHexDSAPublicValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHexDSAPublicValue(aHexDSAPublicValue); } \
  NS_IMETHOD Sign(const nsACString & aText, nsIIdentitySignCallback *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->Sign(aText, callback); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIdentityKeyPair : public nsIIdentityKeyPair
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDENTITYKEYPAIR

  nsIdentityKeyPair();

private:
  ~nsIdentityKeyPair();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIdentityKeyPair, nsIIdentityKeyPair)

nsIdentityKeyPair::nsIdentityKeyPair()
{
  /* member initializers and constructor code */
}

nsIdentityKeyPair::~nsIdentityKeyPair()
{
  /* destructor code */
}

/* readonly attribute AUTF8String keyType; */
NS_IMETHODIMP nsIdentityKeyPair::GetKeyType(nsACString & aKeyType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String hexRSAPublicKeyExponent; */
NS_IMETHODIMP nsIdentityKeyPair::GetHexRSAPublicKeyExponent(nsACString & aHexRSAPublicKeyExponent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String hexRSAPublicKeyModulus; */
NS_IMETHODIMP nsIdentityKeyPair::GetHexRSAPublicKeyModulus(nsACString & aHexRSAPublicKeyModulus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String hexDSAPrime; */
NS_IMETHODIMP nsIdentityKeyPair::GetHexDSAPrime(nsACString & aHexDSAPrime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String hexDSASubPrime; */
NS_IMETHODIMP nsIdentityKeyPair::GetHexDSASubPrime(nsACString & aHexDSASubPrime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String hexDSAGenerator; */
NS_IMETHODIMP nsIdentityKeyPair::GetHexDSAGenerator(nsACString & aHexDSAGenerator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String hexDSAPublicValue; */
NS_IMETHODIMP nsIdentityKeyPair::GetHexDSAPublicValue(nsACString & aHexDSAPublicValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sign (in AUTF8String aText, in nsIIdentitySignCallback callback); */
NS_IMETHODIMP nsIdentityKeyPair::Sign(const nsACString & aText, nsIIdentitySignCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIIdentityKeyGenCallback */
#define NS_IIDENTITYKEYGENCALLBACK_IID_STR "90f24ca2-2b05-4ca9-8aec-89d38e2f905a"

#define NS_IIDENTITYKEYGENCALLBACK_IID \
  {0x90f24ca2, 0x2b05, 0x4ca9, \
    { 0x8a, 0xec, 0x89, 0xd3, 0x8e, 0x2f, 0x90, 0x5a }}

class NS_NO_VTABLE nsIIdentityKeyGenCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDENTITYKEYGENCALLBACK_IID)

  /* void generateKeyPairFinished (in nsresult rv, in nsIIdentityKeyPair keyPair); */
  NS_IMETHOD GenerateKeyPairFinished(nsresult rv, nsIIdentityKeyPair *keyPair) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIdentityKeyGenCallback, NS_IIDENTITYKEYGENCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDENTITYKEYGENCALLBACK \
  NS_IMETHOD GenerateKeyPairFinished(nsresult rv, nsIIdentityKeyPair *keyPair); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDENTITYKEYGENCALLBACK(_to) \
  NS_IMETHOD GenerateKeyPairFinished(nsresult rv, nsIIdentityKeyPair *keyPair) { return _to GenerateKeyPairFinished(rv, keyPair); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDENTITYKEYGENCALLBACK(_to) \
  NS_IMETHOD GenerateKeyPairFinished(nsresult rv, nsIIdentityKeyPair *keyPair) { return !_to ? NS_ERROR_NULL_POINTER : _to->GenerateKeyPairFinished(rv, keyPair); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIdentityKeyGenCallback : public nsIIdentityKeyGenCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDENTITYKEYGENCALLBACK

  nsIdentityKeyGenCallback();

private:
  ~nsIdentityKeyGenCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIdentityKeyGenCallback, nsIIdentityKeyGenCallback)

nsIdentityKeyGenCallback::nsIdentityKeyGenCallback()
{
  /* member initializers and constructor code */
}

nsIdentityKeyGenCallback::~nsIdentityKeyGenCallback()
{
  /* destructor code */
}

/* void generateKeyPairFinished (in nsresult rv, in nsIIdentityKeyPair keyPair); */
NS_IMETHODIMP nsIdentityKeyGenCallback::GenerateKeyPairFinished(nsresult rv, nsIIdentityKeyPair *keyPair)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIIdentitySignCallback */
#define NS_IIDENTITYSIGNCALLBACK_IID_STR "2d3e5036-374b-4b47-a430-1196b67b890f"

#define NS_IIDENTITYSIGNCALLBACK_IID \
  {0x2d3e5036, 0x374b, 0x4b47, \
    { 0xa4, 0x30, 0x11, 0x96, 0xb6, 0x7b, 0x89, 0x0f }}

class NS_NO_VTABLE nsIIdentitySignCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDENTITYSIGNCALLBACK_IID)

  /* void signFinished (in nsresult rv, in ACString base64urlSignature); */
  NS_IMETHOD SignFinished(nsresult rv, const nsACString & base64urlSignature) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIdentitySignCallback, NS_IIDENTITYSIGNCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDENTITYSIGNCALLBACK \
  NS_IMETHOD SignFinished(nsresult rv, const nsACString & base64urlSignature); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDENTITYSIGNCALLBACK(_to) \
  NS_IMETHOD SignFinished(nsresult rv, const nsACString & base64urlSignature) { return _to SignFinished(rv, base64urlSignature); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDENTITYSIGNCALLBACK(_to) \
  NS_IMETHOD SignFinished(nsresult rv, const nsACString & base64urlSignature) { return !_to ? NS_ERROR_NULL_POINTER : _to->SignFinished(rv, base64urlSignature); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIdentitySignCallback : public nsIIdentitySignCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDENTITYSIGNCALLBACK

  nsIdentitySignCallback();

private:
  ~nsIdentitySignCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIdentitySignCallback, nsIIdentitySignCallback)

nsIdentitySignCallback::nsIdentitySignCallback()
{
  /* member initializers and constructor code */
}

nsIdentitySignCallback::~nsIdentitySignCallback()
{
  /* destructor code */
}

/* void signFinished (in nsresult rv, in ACString base64urlSignature); */
NS_IMETHODIMP nsIdentitySignCallback::SignFinished(nsresult rv, const nsACString & base64urlSignature)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIdentityCryptoService_h__ */

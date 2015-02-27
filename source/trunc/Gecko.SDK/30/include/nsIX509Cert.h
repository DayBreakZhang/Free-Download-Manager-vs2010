/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIX509Cert.idl
 */

#ifndef __gen_nsIX509Cert_h__
#define __gen_nsIX509Cert_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsIX509CertValidity; /* forward declaration */

class nsIASN1Object; /* forward declaration */


/* starting interface:    nsIX509Cert */
#define NS_IX509CERT_IID_STR "45b24b0a-6189-4b05-af0b-8d4d66d57c59"

#define NS_IX509CERT_IID \
  {0x45b24b0a, 0x6189, 0x4b05, \
    { 0xaf, 0x0b, 0x8d, 0x4d, 0x66, 0xd5, 0x7c, 0x59 }}

class NS_NO_VTABLE nsIX509Cert : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IX509CERT_IID)

  /* readonly attribute AString nickname; */
  NS_IMETHOD GetNickname(nsAString & aNickname) = 0;

  /* readonly attribute AString emailAddress; */
  NS_IMETHOD GetEmailAddress(nsAString & aEmailAddress) = 0;

  /* void getEmailAddresses (out unsigned long length, [array, size_is (length), retval] out wstring addresses); */
  NS_IMETHOD GetEmailAddresses(uint32_t *length, char16_t * **addresses) = 0;

  /* boolean containsEmailAddress (in AString aEmailAddress); */
  NS_IMETHOD ContainsEmailAddress(const nsAString & aEmailAddress, bool *_retval) = 0;

  /* readonly attribute AString subjectName; */
  NS_IMETHOD GetSubjectName(nsAString & aSubjectName) = 0;

  /* readonly attribute AString commonName; */
  NS_IMETHOD GetCommonName(nsAString & aCommonName) = 0;

  /* readonly attribute AString organization; */
  NS_IMETHOD GetOrganization(nsAString & aOrganization) = 0;

  /* readonly attribute AString organizationalUnit; */
  NS_IMETHOD GetOrganizationalUnit(nsAString & aOrganizationalUnit) = 0;

  /* readonly attribute AString sha1Fingerprint; */
  NS_IMETHOD GetSha1Fingerprint(nsAString & aSha1Fingerprint) = 0;

  /* readonly attribute AString md5Fingerprint; */
  NS_IMETHOD GetMd5Fingerprint(nsAString & aMd5Fingerprint) = 0;

  /* readonly attribute AString tokenName; */
  NS_IMETHOD GetTokenName(nsAString & aTokenName) = 0;

  /* readonly attribute AString issuerName; */
  NS_IMETHOD GetIssuerName(nsAString & aIssuerName) = 0;

  /* readonly attribute AString serialNumber; */
  NS_IMETHOD GetSerialNumber(nsAString & aSerialNumber) = 0;

  /* readonly attribute AString issuerCommonName; */
  NS_IMETHOD GetIssuerCommonName(nsAString & aIssuerCommonName) = 0;

  /* readonly attribute AString issuerOrganization; */
  NS_IMETHOD GetIssuerOrganization(nsAString & aIssuerOrganization) = 0;

  /* readonly attribute AString issuerOrganizationUnit; */
  NS_IMETHOD GetIssuerOrganizationUnit(nsAString & aIssuerOrganizationUnit) = 0;

  /* readonly attribute nsIX509Cert issuer; */
  NS_IMETHOD GetIssuer(nsIX509Cert * *aIssuer) = 0;

  /* readonly attribute nsIX509CertValidity validity; */
  NS_IMETHOD GetValidity(nsIX509CertValidity * *aValidity) = 0;

  /* readonly attribute string dbKey; */
  NS_IMETHOD GetDbKey(char * *aDbKey) = 0;

  /* readonly attribute string windowTitle; */
  NS_IMETHOD GetWindowTitle(char * *aWindowTitle) = 0;

  enum {
    UNKNOWN_CERT = 0U,
    CA_CERT = 1U,
    USER_CERT = 2U,
    EMAIL_CERT = 4U,
    SERVER_CERT = 8U,
    VERIFIED_OK = 0U,
    NOT_VERIFIED_UNKNOWN = 1U,
    CERT_REVOKED = 2U,
    CERT_EXPIRED = 4U,
    CERT_NOT_TRUSTED = 8U,
    ISSUER_NOT_TRUSTED = 16U,
    ISSUER_UNKNOWN = 32U,
    INVALID_CA = 64U,
    USAGE_NOT_ALLOWED = 128U,
    SIGNATURE_ALGORITHM_DISABLED = 256U,
    CERT_USAGE_SSLClient = 0U,
    CERT_USAGE_SSLServer = 1U,
    CERT_USAGE_SSLServerWithStepUp = 2U,
    CERT_USAGE_SSLCA = 3U,
    CERT_USAGE_EmailSigner = 4U,
    CERT_USAGE_EmailRecipient = 5U,
    CERT_USAGE_ObjectSigner = 6U,
    CERT_USAGE_UserCertImport = 7U,
    CERT_USAGE_VerifyCA = 8U,
    CERT_USAGE_ProtectedObjectSigner = 9U,
    CERT_USAGE_StatusResponder = 10U,
    CERT_USAGE_AnyCA = 11U
  };

  /* nsIArray getChain (); */
  NS_IMETHOD GetChain(nsIArray * *_retval) = 0;

  /* void getUsagesArray (in boolean localOnly, out uint32_t verified, out uint32_t count, [array, size_is (count)] out wstring usages); */
  NS_IMETHOD GetUsagesArray(bool localOnly, uint32_t *verified, uint32_t *count, char16_t * **usages) = 0;

  /* void getUsagesString (in boolean localOnly, out uint32_t verified, out AString usages); */
  NS_IMETHOD GetUsagesString(bool localOnly, uint32_t *verified, nsAString & usages) = 0;

  /* readonly attribute nsIASN1Object ASN1Structure; */
  NS_IMETHOD GetASN1Structure(nsIASN1Object * *aASN1Structure) = 0;

  /* void getRawDER (out unsigned long length, [array, size_is (length), retval] out octet data); */
  NS_IMETHOD GetRawDER(uint32_t *length, uint8_t **data) = 0;

  /* boolean equals (in nsIX509Cert other); */
  NS_IMETHOD Equals(nsIX509Cert *other, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIX509Cert, NS_IX509CERT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIX509CERT \
  NS_IMETHOD GetNickname(nsAString & aNickname); \
  NS_IMETHOD GetEmailAddress(nsAString & aEmailAddress); \
  NS_IMETHOD GetEmailAddresses(uint32_t *length, char16_t * **addresses); \
  NS_IMETHOD ContainsEmailAddress(const nsAString & aEmailAddress, bool *_retval); \
  NS_IMETHOD GetSubjectName(nsAString & aSubjectName); \
  NS_IMETHOD GetCommonName(nsAString & aCommonName); \
  NS_IMETHOD GetOrganization(nsAString & aOrganization); \
  NS_IMETHOD GetOrganizationalUnit(nsAString & aOrganizationalUnit); \
  NS_IMETHOD GetSha1Fingerprint(nsAString & aSha1Fingerprint); \
  NS_IMETHOD GetMd5Fingerprint(nsAString & aMd5Fingerprint); \
  NS_IMETHOD GetTokenName(nsAString & aTokenName); \
  NS_IMETHOD GetIssuerName(nsAString & aIssuerName); \
  NS_IMETHOD GetSerialNumber(nsAString & aSerialNumber); \
  NS_IMETHOD GetIssuerCommonName(nsAString & aIssuerCommonName); \
  NS_IMETHOD GetIssuerOrganization(nsAString & aIssuerOrganization); \
  NS_IMETHOD GetIssuerOrganizationUnit(nsAString & aIssuerOrganizationUnit); \
  NS_IMETHOD GetIssuer(nsIX509Cert * *aIssuer); \
  NS_IMETHOD GetValidity(nsIX509CertValidity * *aValidity); \
  NS_IMETHOD GetDbKey(char * *aDbKey); \
  NS_IMETHOD GetWindowTitle(char * *aWindowTitle); \
  NS_IMETHOD GetChain(nsIArray * *_retval); \
  NS_IMETHOD GetUsagesArray(bool localOnly, uint32_t *verified, uint32_t *count, char16_t * **usages); \
  NS_IMETHOD GetUsagesString(bool localOnly, uint32_t *verified, nsAString & usages); \
  NS_IMETHOD GetASN1Structure(nsIASN1Object * *aASN1Structure); \
  NS_IMETHOD GetRawDER(uint32_t *length, uint8_t **data); \
  NS_IMETHOD Equals(nsIX509Cert *other, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIX509CERT(_to) \
  NS_IMETHOD GetNickname(nsAString & aNickname) { return _to GetNickname(aNickname); } \
  NS_IMETHOD GetEmailAddress(nsAString & aEmailAddress) { return _to GetEmailAddress(aEmailAddress); } \
  NS_IMETHOD GetEmailAddresses(uint32_t *length, char16_t * **addresses) { return _to GetEmailAddresses(length, addresses); } \
  NS_IMETHOD ContainsEmailAddress(const nsAString & aEmailAddress, bool *_retval) { return _to ContainsEmailAddress(aEmailAddress, _retval); } \
  NS_IMETHOD GetSubjectName(nsAString & aSubjectName) { return _to GetSubjectName(aSubjectName); } \
  NS_IMETHOD GetCommonName(nsAString & aCommonName) { return _to GetCommonName(aCommonName); } \
  NS_IMETHOD GetOrganization(nsAString & aOrganization) { return _to GetOrganization(aOrganization); } \
  NS_IMETHOD GetOrganizationalUnit(nsAString & aOrganizationalUnit) { return _to GetOrganizationalUnit(aOrganizationalUnit); } \
  NS_IMETHOD GetSha1Fingerprint(nsAString & aSha1Fingerprint) { return _to GetSha1Fingerprint(aSha1Fingerprint); } \
  NS_IMETHOD GetMd5Fingerprint(nsAString & aMd5Fingerprint) { return _to GetMd5Fingerprint(aMd5Fingerprint); } \
  NS_IMETHOD GetTokenName(nsAString & aTokenName) { return _to GetTokenName(aTokenName); } \
  NS_IMETHOD GetIssuerName(nsAString & aIssuerName) { return _to GetIssuerName(aIssuerName); } \
  NS_IMETHOD GetSerialNumber(nsAString & aSerialNumber) { return _to GetSerialNumber(aSerialNumber); } \
  NS_IMETHOD GetIssuerCommonName(nsAString & aIssuerCommonName) { return _to GetIssuerCommonName(aIssuerCommonName); } \
  NS_IMETHOD GetIssuerOrganization(nsAString & aIssuerOrganization) { return _to GetIssuerOrganization(aIssuerOrganization); } \
  NS_IMETHOD GetIssuerOrganizationUnit(nsAString & aIssuerOrganizationUnit) { return _to GetIssuerOrganizationUnit(aIssuerOrganizationUnit); } \
  NS_IMETHOD GetIssuer(nsIX509Cert * *aIssuer) { return _to GetIssuer(aIssuer); } \
  NS_IMETHOD GetValidity(nsIX509CertValidity * *aValidity) { return _to GetValidity(aValidity); } \
  NS_IMETHOD GetDbKey(char * *aDbKey) { return _to GetDbKey(aDbKey); } \
  NS_IMETHOD GetWindowTitle(char * *aWindowTitle) { return _to GetWindowTitle(aWindowTitle); } \
  NS_IMETHOD GetChain(nsIArray * *_retval) { return _to GetChain(_retval); } \
  NS_IMETHOD GetUsagesArray(bool localOnly, uint32_t *verified, uint32_t *count, char16_t * **usages) { return _to GetUsagesArray(localOnly, verified, count, usages); } \
  NS_IMETHOD GetUsagesString(bool localOnly, uint32_t *verified, nsAString & usages) { return _to GetUsagesString(localOnly, verified, usages); } \
  NS_IMETHOD GetASN1Structure(nsIASN1Object * *aASN1Structure) { return _to GetASN1Structure(aASN1Structure); } \
  NS_IMETHOD GetRawDER(uint32_t *length, uint8_t **data) { return _to GetRawDER(length, data); } \
  NS_IMETHOD Equals(nsIX509Cert *other, bool *_retval) { return _to Equals(other, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIX509CERT(_to) \
  NS_IMETHOD GetNickname(nsAString & aNickname) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNickname(aNickname); } \
  NS_IMETHOD GetEmailAddress(nsAString & aEmailAddress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEmailAddress(aEmailAddress); } \
  NS_IMETHOD GetEmailAddresses(uint32_t *length, char16_t * **addresses) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEmailAddresses(length, addresses); } \
  NS_IMETHOD ContainsEmailAddress(const nsAString & aEmailAddress, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ContainsEmailAddress(aEmailAddress, _retval); } \
  NS_IMETHOD GetSubjectName(nsAString & aSubjectName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSubjectName(aSubjectName); } \
  NS_IMETHOD GetCommonName(nsAString & aCommonName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCommonName(aCommonName); } \
  NS_IMETHOD GetOrganization(nsAString & aOrganization) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOrganization(aOrganization); } \
  NS_IMETHOD GetOrganizationalUnit(nsAString & aOrganizationalUnit) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOrganizationalUnit(aOrganizationalUnit); } \
  NS_IMETHOD GetSha1Fingerprint(nsAString & aSha1Fingerprint) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSha1Fingerprint(aSha1Fingerprint); } \
  NS_IMETHOD GetMd5Fingerprint(nsAString & aMd5Fingerprint) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMd5Fingerprint(aMd5Fingerprint); } \
  NS_IMETHOD GetTokenName(nsAString & aTokenName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTokenName(aTokenName); } \
  NS_IMETHOD GetIssuerName(nsAString & aIssuerName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIssuerName(aIssuerName); } \
  NS_IMETHOD GetSerialNumber(nsAString & aSerialNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSerialNumber(aSerialNumber); } \
  NS_IMETHOD GetIssuerCommonName(nsAString & aIssuerCommonName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIssuerCommonName(aIssuerCommonName); } \
  NS_IMETHOD GetIssuerOrganization(nsAString & aIssuerOrganization) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIssuerOrganization(aIssuerOrganization); } \
  NS_IMETHOD GetIssuerOrganizationUnit(nsAString & aIssuerOrganizationUnit) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIssuerOrganizationUnit(aIssuerOrganizationUnit); } \
  NS_IMETHOD GetIssuer(nsIX509Cert * *aIssuer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIssuer(aIssuer); } \
  NS_IMETHOD GetValidity(nsIX509CertValidity * *aValidity) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValidity(aValidity); } \
  NS_IMETHOD GetDbKey(char * *aDbKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDbKey(aDbKey); } \
  NS_IMETHOD GetWindowTitle(char * *aWindowTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindowTitle(aWindowTitle); } \
  NS_IMETHOD GetChain(nsIArray * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChain(_retval); } \
  NS_IMETHOD GetUsagesArray(bool localOnly, uint32_t *verified, uint32_t *count, char16_t * **usages) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsagesArray(localOnly, verified, count, usages); } \
  NS_IMETHOD GetUsagesString(bool localOnly, uint32_t *verified, nsAString & usages) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsagesString(localOnly, verified, usages); } \
  NS_IMETHOD GetASN1Structure(nsIASN1Object * *aASN1Structure) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetASN1Structure(aASN1Structure); } \
  NS_IMETHOD GetRawDER(uint32_t *length, uint8_t **data) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRawDER(length, data); } \
  NS_IMETHOD Equals(nsIX509Cert *other, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Equals(other, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsX509Cert : public nsIX509Cert
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIX509CERT

  nsX509Cert();

private:
  ~nsX509Cert();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsX509Cert, nsIX509Cert)

nsX509Cert::nsX509Cert()
{
  /* member initializers and constructor code */
}

nsX509Cert::~nsX509Cert()
{
  /* destructor code */
}

/* readonly attribute AString nickname; */
NS_IMETHODIMP nsX509Cert::GetNickname(nsAString & aNickname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString emailAddress; */
NS_IMETHODIMP nsX509Cert::GetEmailAddress(nsAString & aEmailAddress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getEmailAddresses (out unsigned long length, [array, size_is (length), retval] out wstring addresses); */
NS_IMETHODIMP nsX509Cert::GetEmailAddresses(uint32_t *length, char16_t * **addresses)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean containsEmailAddress (in AString aEmailAddress); */
NS_IMETHODIMP nsX509Cert::ContainsEmailAddress(const nsAString & aEmailAddress, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString subjectName; */
NS_IMETHODIMP nsX509Cert::GetSubjectName(nsAString & aSubjectName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString commonName; */
NS_IMETHODIMP nsX509Cert::GetCommonName(nsAString & aCommonName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString organization; */
NS_IMETHODIMP nsX509Cert::GetOrganization(nsAString & aOrganization)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString organizationalUnit; */
NS_IMETHODIMP nsX509Cert::GetOrganizationalUnit(nsAString & aOrganizationalUnit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString sha1Fingerprint; */
NS_IMETHODIMP nsX509Cert::GetSha1Fingerprint(nsAString & aSha1Fingerprint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString md5Fingerprint; */
NS_IMETHODIMP nsX509Cert::GetMd5Fingerprint(nsAString & aMd5Fingerprint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString tokenName; */
NS_IMETHODIMP nsX509Cert::GetTokenName(nsAString & aTokenName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString issuerName; */
NS_IMETHODIMP nsX509Cert::GetIssuerName(nsAString & aIssuerName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString serialNumber; */
NS_IMETHODIMP nsX509Cert::GetSerialNumber(nsAString & aSerialNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString issuerCommonName; */
NS_IMETHODIMP nsX509Cert::GetIssuerCommonName(nsAString & aIssuerCommonName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString issuerOrganization; */
NS_IMETHODIMP nsX509Cert::GetIssuerOrganization(nsAString & aIssuerOrganization)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString issuerOrganizationUnit; */
NS_IMETHODIMP nsX509Cert::GetIssuerOrganizationUnit(nsAString & aIssuerOrganizationUnit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIX509Cert issuer; */
NS_IMETHODIMP nsX509Cert::GetIssuer(nsIX509Cert * *aIssuer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIX509CertValidity validity; */
NS_IMETHODIMP nsX509Cert::GetValidity(nsIX509CertValidity * *aValidity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string dbKey; */
NS_IMETHODIMP nsX509Cert::GetDbKey(char * *aDbKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string windowTitle; */
NS_IMETHODIMP nsX509Cert::GetWindowTitle(char * *aWindowTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIArray getChain (); */
NS_IMETHODIMP nsX509Cert::GetChain(nsIArray * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getUsagesArray (in boolean localOnly, out uint32_t verified, out uint32_t count, [array, size_is (count)] out wstring usages); */
NS_IMETHODIMP nsX509Cert::GetUsagesArray(bool localOnly, uint32_t *verified, uint32_t *count, char16_t * **usages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getUsagesString (in boolean localOnly, out uint32_t verified, out AString usages); */
NS_IMETHODIMP nsX509Cert::GetUsagesString(bool localOnly, uint32_t *verified, nsAString & usages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIASN1Object ASN1Structure; */
NS_IMETHODIMP nsX509Cert::GetASN1Structure(nsIASN1Object * *aASN1Structure)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getRawDER (out unsigned long length, [array, size_is (length), retval] out octet data); */
NS_IMETHODIMP nsX509Cert::GetRawDER(uint32_t *length, uint8_t **data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean equals (in nsIX509Cert other); */
NS_IMETHODIMP nsX509Cert::Equals(nsIX509Cert *other, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIX509Cert_h__ */

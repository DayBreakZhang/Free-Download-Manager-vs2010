/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIX509CertDB.idl
 */

#ifndef __gen_nsIX509CertDB_h__
#define __gen_nsIX509CertDB_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsIX509Cert; /* forward declaration */

class nsIX509Cert3; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIInterfaceRequestor; /* forward declaration */

class nsIZipReader; /* forward declaration */

class nsIRecentBadCerts; /* forward declaration */

class nsIX509CertList; /* forward declaration */

#define NS_X509CERTDB_CONTRACTID "@mozilla.org/security/x509certdb;1"
typedef uint32_t  AppTrustedRoot;


/* starting interface:    nsIOpenSignedAppFileCallback */
#define NS_IOPENSIGNEDAPPFILECALLBACK_IID_STR "0927baea-622d-4e41-a76d-255af426e7fb"

#define NS_IOPENSIGNEDAPPFILECALLBACK_IID \
  {0x0927baea, 0x622d, 0x4e41, \
    { 0xa7, 0x6d, 0x25, 0x5a, 0xf4, 0x26, 0xe7, 0xfb }}

class NS_NO_VTABLE nsIOpenSignedAppFileCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IOPENSIGNEDAPPFILECALLBACK_IID)

  /* void openSignedAppFileFinished (in nsresult rv, in nsIZipReader aZipReader, in nsIX509Cert3 aSignerCert); */
  NS_IMETHOD OpenSignedAppFileFinished(nsresult rv, nsIZipReader *aZipReader, nsIX509Cert3 *aSignerCert) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIOpenSignedAppFileCallback, NS_IOPENSIGNEDAPPFILECALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIOPENSIGNEDAPPFILECALLBACK \
  NS_IMETHOD OpenSignedAppFileFinished(nsresult rv, nsIZipReader *aZipReader, nsIX509Cert3 *aSignerCert); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIOPENSIGNEDAPPFILECALLBACK(_to) \
  NS_IMETHOD OpenSignedAppFileFinished(nsresult rv, nsIZipReader *aZipReader, nsIX509Cert3 *aSignerCert) { return _to OpenSignedAppFileFinished(rv, aZipReader, aSignerCert); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIOPENSIGNEDAPPFILECALLBACK(_to) \
  NS_IMETHOD OpenSignedAppFileFinished(nsresult rv, nsIZipReader *aZipReader, nsIX509Cert3 *aSignerCert) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenSignedAppFileFinished(rv, aZipReader, aSignerCert); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsOpenSignedAppFileCallback : public nsIOpenSignedAppFileCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIOPENSIGNEDAPPFILECALLBACK

  nsOpenSignedAppFileCallback();

private:
  ~nsOpenSignedAppFileCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsOpenSignedAppFileCallback, nsIOpenSignedAppFileCallback)

nsOpenSignedAppFileCallback::nsOpenSignedAppFileCallback()
{
  /* member initializers and constructor code */
}

nsOpenSignedAppFileCallback::~nsOpenSignedAppFileCallback()
{
  /* destructor code */
}

/* void openSignedAppFileFinished (in nsresult rv, in nsIZipReader aZipReader, in nsIX509Cert3 aSignerCert); */
NS_IMETHODIMP nsOpenSignedAppFileCallback::OpenSignedAppFileFinished(nsresult rv, nsIZipReader *aZipReader, nsIX509Cert3 *aSignerCert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIX509CertDB */
#define NS_IX509CERTDB_IID_STR "7446a5b1-84ca-491f-a2fe-0bc60a71ffa5"

#define NS_IX509CERTDB_IID \
  {0x7446a5b1, 0x84ca, 0x491f, \
    { 0xa2, 0xfe, 0x0b, 0xc6, 0x0a, 0x71, 0xff, 0xa5 }}

class NS_NO_VTABLE nsIX509CertDB : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IX509CERTDB_IID)

  enum {
    UNTRUSTED = 0U,
    TRUSTED_SSL = 1U,
    TRUSTED_EMAIL = 2U,
    TRUSTED_OBJSIGN = 4U
  };

  /* nsIX509Cert findCertByNickname (in nsISupports aToken, in AString aNickname); */
  NS_IMETHOD FindCertByNickname(nsISupports *aToken, const nsAString & aNickname, nsIX509Cert * *_retval) = 0;

  /* nsIX509Cert findCertByDBKey (in string aDBkey, in nsISupports aToken); */
  NS_IMETHOD FindCertByDBKey(const char * aDBkey, nsISupports *aToken, nsIX509Cert * *_retval) = 0;

  /* void findCertNicknames (in nsISupports aToken, in unsigned long aType, out unsigned long count, [array, size_is (count)] out wstring certNameList); */
  NS_IMETHOD FindCertNicknames(nsISupports *aToken, uint32_t aType, uint32_t *count, char16_t * **certNameList) = 0;

  /* nsIX509Cert findEmailEncryptionCert (in AString aNickname); */
  NS_IMETHOD FindEmailEncryptionCert(const nsAString & aNickname, nsIX509Cert * *_retval) = 0;

  /* nsIX509Cert findEmailSigningCert (in AString aNickname); */
  NS_IMETHOD FindEmailSigningCert(const nsAString & aNickname, nsIX509Cert * *_retval) = 0;

  /* nsIX509Cert findCertByEmailAddress (in nsISupports aToken, in string aEmailAddress); */
  NS_IMETHOD FindCertByEmailAddress(nsISupports *aToken, const char * aEmailAddress, nsIX509Cert * *_retval) = 0;

  /* void importCertificates ([array, size_is (length)] in octet data, in unsigned long length, in unsigned long type, in nsIInterfaceRequestor ctx); */
  NS_IMETHOD ImportCertificates(uint8_t *data, uint32_t length, uint32_t type, nsIInterfaceRequestor *ctx) = 0;

  /* void importEmailCertificate ([array, size_is (length)] in octet data, in unsigned long length, in nsIInterfaceRequestor ctx); */
  NS_IMETHOD ImportEmailCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx) = 0;

  /* void importServerCertificate ([array, size_is (length)] in octet data, in unsigned long length, in nsIInterfaceRequestor ctx); */
  NS_IMETHOD ImportServerCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx) = 0;

  /* void importUserCertificate ([array, size_is (length)] in octet data, in unsigned long length, in nsIInterfaceRequestor ctx); */
  NS_IMETHOD ImportUserCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx) = 0;

  /* void deleteCertificate (in nsIX509Cert aCert); */
  NS_IMETHOD DeleteCertificate(nsIX509Cert *aCert) = 0;

  /* void setCertTrust (in nsIX509Cert cert, in unsigned long type, in unsigned long trust); */
  NS_IMETHOD SetCertTrust(nsIX509Cert *cert, uint32_t type, uint32_t trust) = 0;

  /* void setCertTrustFromString (in nsIX509Cert3 cert, in string trustString); */
  NS_IMETHOD SetCertTrustFromString(nsIX509Cert3 *cert, const char * trustString) = 0;

  /* boolean isCertTrusted (in nsIX509Cert cert, in unsigned long certType, in unsigned long trustType); */
  NS_IMETHOD IsCertTrusted(nsIX509Cert *cert, uint32_t certType, uint32_t trustType, bool *_retval) = 0;

  /* void importCertsFromFile (in nsISupports aToken, in nsIFile aFile, in unsigned long aType); */
  NS_IMETHOD ImportCertsFromFile(nsISupports *aToken, nsIFile *aFile, uint32_t aType) = 0;

  /* void importPKCS12File (in nsISupports aToken, in nsIFile aFile); */
  NS_IMETHOD ImportPKCS12File(nsISupports *aToken, nsIFile *aFile) = 0;

  /* void exportPKCS12File (in nsISupports aToken, in nsIFile aFile, in unsigned long count, [array, size_is (count)] in nsIX509Cert aCerts); */
  NS_IMETHOD ExportPKCS12File(nsISupports *aToken, nsIFile *aFile, uint32_t count, nsIX509Cert **aCerts) = 0;

  /* nsIX509Cert constructX509FromBase64 (in string base64); */
  NS_IMETHOD ConstructX509FromBase64(const char * base64, nsIX509Cert * *_retval) = 0;

  /* nsIX509Cert constructX509 (in string certDER, in unsigned long length); */
  NS_IMETHOD ConstructX509(const char * certDER, uint32_t length, nsIX509Cert * *_retval) = 0;

  /* nsIRecentBadCerts getRecentBadCerts (in boolean isPrivate); */
  NS_IMETHOD GetRecentBadCerts(bool isPrivate, nsIRecentBadCerts * *_retval) = 0;

  enum {
    AppMarketplaceProdPublicRoot = 1U,
    AppMarketplaceProdReviewersRoot = 2U,
    AppMarketplaceDevPublicRoot = 3U,
    AppMarketplaceDevReviewersRoot = 4U,
    AppXPCShellRoot = 5U
  };

  /* void openSignedAppFileAsync (in AppTrustedRoot trustedRoot, in nsIFile aJarFile, in nsIOpenSignedAppFileCallback callback); */
  NS_IMETHOD OpenSignedAppFileAsync(AppTrustedRoot trustedRoot, nsIFile *aJarFile, nsIOpenSignedAppFileCallback *callback) = 0;

  /* void addCert (in ACString certDER, in string aTrust, in string aName); */
  NS_IMETHOD AddCert(const nsACString & certDER, const char * aTrust, const char * aName) = 0;

  enum {
    FLAG_LOCAL_ONLY = 1U,
    FLAG_MUST_BE_EV = 2U
  };

  /* int32_t verifyCertNow (in nsIX509Cert aCert, in int64_t aUsage, in uint32_t aFlags, out nsIX509CertList verifiedChain, out bool aHasEVPolicy); */
  NS_IMETHOD VerifyCertNow(nsIX509Cert *aCert, int64_t aUsage, uint32_t aFlags, nsIX509CertList * *verifiedChain, bool *aHasEVPolicy, int32_t *_retval) = 0;

  /* void clearOCSPCache (); */
  NS_IMETHOD ClearOCSPCache(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIX509CertDB, NS_IX509CERTDB_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIX509CERTDB \
  NS_IMETHOD FindCertByNickname(nsISupports *aToken, const nsAString & aNickname, nsIX509Cert * *_retval); \
  NS_IMETHOD FindCertByDBKey(const char * aDBkey, nsISupports *aToken, nsIX509Cert * *_retval); \
  NS_IMETHOD FindCertNicknames(nsISupports *aToken, uint32_t aType, uint32_t *count, char16_t * **certNameList); \
  NS_IMETHOD FindEmailEncryptionCert(const nsAString & aNickname, nsIX509Cert * *_retval); \
  NS_IMETHOD FindEmailSigningCert(const nsAString & aNickname, nsIX509Cert * *_retval); \
  NS_IMETHOD FindCertByEmailAddress(nsISupports *aToken, const char * aEmailAddress, nsIX509Cert * *_retval); \
  NS_IMETHOD ImportCertificates(uint8_t *data, uint32_t length, uint32_t type, nsIInterfaceRequestor *ctx); \
  NS_IMETHOD ImportEmailCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx); \
  NS_IMETHOD ImportServerCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx); \
  NS_IMETHOD ImportUserCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx); \
  NS_IMETHOD DeleteCertificate(nsIX509Cert *aCert); \
  NS_IMETHOD SetCertTrust(nsIX509Cert *cert, uint32_t type, uint32_t trust); \
  NS_IMETHOD SetCertTrustFromString(nsIX509Cert3 *cert, const char * trustString); \
  NS_IMETHOD IsCertTrusted(nsIX509Cert *cert, uint32_t certType, uint32_t trustType, bool *_retval); \
  NS_IMETHOD ImportCertsFromFile(nsISupports *aToken, nsIFile *aFile, uint32_t aType); \
  NS_IMETHOD ImportPKCS12File(nsISupports *aToken, nsIFile *aFile); \
  NS_IMETHOD ExportPKCS12File(nsISupports *aToken, nsIFile *aFile, uint32_t count, nsIX509Cert **aCerts); \
  NS_IMETHOD ConstructX509FromBase64(const char * base64, nsIX509Cert * *_retval); \
  NS_IMETHOD ConstructX509(const char * certDER, uint32_t length, nsIX509Cert * *_retval); \
  NS_IMETHOD GetRecentBadCerts(bool isPrivate, nsIRecentBadCerts * *_retval); \
  NS_IMETHOD OpenSignedAppFileAsync(AppTrustedRoot trustedRoot, nsIFile *aJarFile, nsIOpenSignedAppFileCallback *callback); \
  NS_IMETHOD AddCert(const nsACString & certDER, const char * aTrust, const char * aName); \
  NS_IMETHOD VerifyCertNow(nsIX509Cert *aCert, int64_t aUsage, uint32_t aFlags, nsIX509CertList * *verifiedChain, bool *aHasEVPolicy, int32_t *_retval); \
  NS_IMETHOD ClearOCSPCache(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIX509CERTDB(_to) \
  NS_IMETHOD FindCertByNickname(nsISupports *aToken, const nsAString & aNickname, nsIX509Cert * *_retval) { return _to FindCertByNickname(aToken, aNickname, _retval); } \
  NS_IMETHOD FindCertByDBKey(const char * aDBkey, nsISupports *aToken, nsIX509Cert * *_retval) { return _to FindCertByDBKey(aDBkey, aToken, _retval); } \
  NS_IMETHOD FindCertNicknames(nsISupports *aToken, uint32_t aType, uint32_t *count, char16_t * **certNameList) { return _to FindCertNicknames(aToken, aType, count, certNameList); } \
  NS_IMETHOD FindEmailEncryptionCert(const nsAString & aNickname, nsIX509Cert * *_retval) { return _to FindEmailEncryptionCert(aNickname, _retval); } \
  NS_IMETHOD FindEmailSigningCert(const nsAString & aNickname, nsIX509Cert * *_retval) { return _to FindEmailSigningCert(aNickname, _retval); } \
  NS_IMETHOD FindCertByEmailAddress(nsISupports *aToken, const char * aEmailAddress, nsIX509Cert * *_retval) { return _to FindCertByEmailAddress(aToken, aEmailAddress, _retval); } \
  NS_IMETHOD ImportCertificates(uint8_t *data, uint32_t length, uint32_t type, nsIInterfaceRequestor *ctx) { return _to ImportCertificates(data, length, type, ctx); } \
  NS_IMETHOD ImportEmailCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx) { return _to ImportEmailCertificate(data, length, ctx); } \
  NS_IMETHOD ImportServerCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx) { return _to ImportServerCertificate(data, length, ctx); } \
  NS_IMETHOD ImportUserCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx) { return _to ImportUserCertificate(data, length, ctx); } \
  NS_IMETHOD DeleteCertificate(nsIX509Cert *aCert) { return _to DeleteCertificate(aCert); } \
  NS_IMETHOD SetCertTrust(nsIX509Cert *cert, uint32_t type, uint32_t trust) { return _to SetCertTrust(cert, type, trust); } \
  NS_IMETHOD SetCertTrustFromString(nsIX509Cert3 *cert, const char * trustString) { return _to SetCertTrustFromString(cert, trustString); } \
  NS_IMETHOD IsCertTrusted(nsIX509Cert *cert, uint32_t certType, uint32_t trustType, bool *_retval) { return _to IsCertTrusted(cert, certType, trustType, _retval); } \
  NS_IMETHOD ImportCertsFromFile(nsISupports *aToken, nsIFile *aFile, uint32_t aType) { return _to ImportCertsFromFile(aToken, aFile, aType); } \
  NS_IMETHOD ImportPKCS12File(nsISupports *aToken, nsIFile *aFile) { return _to ImportPKCS12File(aToken, aFile); } \
  NS_IMETHOD ExportPKCS12File(nsISupports *aToken, nsIFile *aFile, uint32_t count, nsIX509Cert **aCerts) { return _to ExportPKCS12File(aToken, aFile, count, aCerts); } \
  NS_IMETHOD ConstructX509FromBase64(const char * base64, nsIX509Cert * *_retval) { return _to ConstructX509FromBase64(base64, _retval); } \
  NS_IMETHOD ConstructX509(const char * certDER, uint32_t length, nsIX509Cert * *_retval) { return _to ConstructX509(certDER, length, _retval); } \
  NS_IMETHOD GetRecentBadCerts(bool isPrivate, nsIRecentBadCerts * *_retval) { return _to GetRecentBadCerts(isPrivate, _retval); } \
  NS_IMETHOD OpenSignedAppFileAsync(AppTrustedRoot trustedRoot, nsIFile *aJarFile, nsIOpenSignedAppFileCallback *callback) { return _to OpenSignedAppFileAsync(trustedRoot, aJarFile, callback); } \
  NS_IMETHOD AddCert(const nsACString & certDER, const char * aTrust, const char * aName) { return _to AddCert(certDER, aTrust, aName); } \
  NS_IMETHOD VerifyCertNow(nsIX509Cert *aCert, int64_t aUsage, uint32_t aFlags, nsIX509CertList * *verifiedChain, bool *aHasEVPolicy, int32_t *_retval) { return _to VerifyCertNow(aCert, aUsage, aFlags, verifiedChain, aHasEVPolicy, _retval); } \
  NS_IMETHOD ClearOCSPCache(void) { return _to ClearOCSPCache(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIX509CERTDB(_to) \
  NS_IMETHOD FindCertByNickname(nsISupports *aToken, const nsAString & aNickname, nsIX509Cert * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindCertByNickname(aToken, aNickname, _retval); } \
  NS_IMETHOD FindCertByDBKey(const char * aDBkey, nsISupports *aToken, nsIX509Cert * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindCertByDBKey(aDBkey, aToken, _retval); } \
  NS_IMETHOD FindCertNicknames(nsISupports *aToken, uint32_t aType, uint32_t *count, char16_t * **certNameList) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindCertNicknames(aToken, aType, count, certNameList); } \
  NS_IMETHOD FindEmailEncryptionCert(const nsAString & aNickname, nsIX509Cert * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindEmailEncryptionCert(aNickname, _retval); } \
  NS_IMETHOD FindEmailSigningCert(const nsAString & aNickname, nsIX509Cert * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindEmailSigningCert(aNickname, _retval); } \
  NS_IMETHOD FindCertByEmailAddress(nsISupports *aToken, const char * aEmailAddress, nsIX509Cert * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindCertByEmailAddress(aToken, aEmailAddress, _retval); } \
  NS_IMETHOD ImportCertificates(uint8_t *data, uint32_t length, uint32_t type, nsIInterfaceRequestor *ctx) { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportCertificates(data, length, type, ctx); } \
  NS_IMETHOD ImportEmailCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx) { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportEmailCertificate(data, length, ctx); } \
  NS_IMETHOD ImportServerCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx) { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportServerCertificate(data, length, ctx); } \
  NS_IMETHOD ImportUserCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx) { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportUserCertificate(data, length, ctx); } \
  NS_IMETHOD DeleteCertificate(nsIX509Cert *aCert) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteCertificate(aCert); } \
  NS_IMETHOD SetCertTrust(nsIX509Cert *cert, uint32_t type, uint32_t trust) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCertTrust(cert, type, trust); } \
  NS_IMETHOD SetCertTrustFromString(nsIX509Cert3 *cert, const char * trustString) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCertTrustFromString(cert, trustString); } \
  NS_IMETHOD IsCertTrusted(nsIX509Cert *cert, uint32_t certType, uint32_t trustType, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCertTrusted(cert, certType, trustType, _retval); } \
  NS_IMETHOD ImportCertsFromFile(nsISupports *aToken, nsIFile *aFile, uint32_t aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportCertsFromFile(aToken, aFile, aType); } \
  NS_IMETHOD ImportPKCS12File(nsISupports *aToken, nsIFile *aFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportPKCS12File(aToken, aFile); } \
  NS_IMETHOD ExportPKCS12File(nsISupports *aToken, nsIFile *aFile, uint32_t count, nsIX509Cert **aCerts) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExportPKCS12File(aToken, aFile, count, aCerts); } \
  NS_IMETHOD ConstructX509FromBase64(const char * base64, nsIX509Cert * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConstructX509FromBase64(base64, _retval); } \
  NS_IMETHOD ConstructX509(const char * certDER, uint32_t length, nsIX509Cert * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConstructX509(certDER, length, _retval); } \
  NS_IMETHOD GetRecentBadCerts(bool isPrivate, nsIRecentBadCerts * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRecentBadCerts(isPrivate, _retval); } \
  NS_IMETHOD OpenSignedAppFileAsync(AppTrustedRoot trustedRoot, nsIFile *aJarFile, nsIOpenSignedAppFileCallback *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenSignedAppFileAsync(trustedRoot, aJarFile, callback); } \
  NS_IMETHOD AddCert(const nsACString & certDER, const char * aTrust, const char * aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddCert(certDER, aTrust, aName); } \
  NS_IMETHOD VerifyCertNow(nsIX509Cert *aCert, int64_t aUsage, uint32_t aFlags, nsIX509CertList * *verifiedChain, bool *aHasEVPolicy, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->VerifyCertNow(aCert, aUsage, aFlags, verifiedChain, aHasEVPolicy, _retval); } \
  NS_IMETHOD ClearOCSPCache(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearOCSPCache(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsX509CertDB : public nsIX509CertDB
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIX509CERTDB

  nsX509CertDB();

private:
  ~nsX509CertDB();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsX509CertDB, nsIX509CertDB)

nsX509CertDB::nsX509CertDB()
{
  /* member initializers and constructor code */
}

nsX509CertDB::~nsX509CertDB()
{
  /* destructor code */
}

/* nsIX509Cert findCertByNickname (in nsISupports aToken, in AString aNickname); */
NS_IMETHODIMP nsX509CertDB::FindCertByNickname(nsISupports *aToken, const nsAString & aNickname, nsIX509Cert * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIX509Cert findCertByDBKey (in string aDBkey, in nsISupports aToken); */
NS_IMETHODIMP nsX509CertDB::FindCertByDBKey(const char * aDBkey, nsISupports *aToken, nsIX509Cert * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void findCertNicknames (in nsISupports aToken, in unsigned long aType, out unsigned long count, [array, size_is (count)] out wstring certNameList); */
NS_IMETHODIMP nsX509CertDB::FindCertNicknames(nsISupports *aToken, uint32_t aType, uint32_t *count, char16_t * **certNameList)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIX509Cert findEmailEncryptionCert (in AString aNickname); */
NS_IMETHODIMP nsX509CertDB::FindEmailEncryptionCert(const nsAString & aNickname, nsIX509Cert * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIX509Cert findEmailSigningCert (in AString aNickname); */
NS_IMETHODIMP nsX509CertDB::FindEmailSigningCert(const nsAString & aNickname, nsIX509Cert * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIX509Cert findCertByEmailAddress (in nsISupports aToken, in string aEmailAddress); */
NS_IMETHODIMP nsX509CertDB::FindCertByEmailAddress(nsISupports *aToken, const char * aEmailAddress, nsIX509Cert * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void importCertificates ([array, size_is (length)] in octet data, in unsigned long length, in unsigned long type, in nsIInterfaceRequestor ctx); */
NS_IMETHODIMP nsX509CertDB::ImportCertificates(uint8_t *data, uint32_t length, uint32_t type, nsIInterfaceRequestor *ctx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void importEmailCertificate ([array, size_is (length)] in octet data, in unsigned long length, in nsIInterfaceRequestor ctx); */
NS_IMETHODIMP nsX509CertDB::ImportEmailCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void importServerCertificate ([array, size_is (length)] in octet data, in unsigned long length, in nsIInterfaceRequestor ctx); */
NS_IMETHODIMP nsX509CertDB::ImportServerCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void importUserCertificate ([array, size_is (length)] in octet data, in unsigned long length, in nsIInterfaceRequestor ctx); */
NS_IMETHODIMP nsX509CertDB::ImportUserCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteCertificate (in nsIX509Cert aCert); */
NS_IMETHODIMP nsX509CertDB::DeleteCertificate(nsIX509Cert *aCert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCertTrust (in nsIX509Cert cert, in unsigned long type, in unsigned long trust); */
NS_IMETHODIMP nsX509CertDB::SetCertTrust(nsIX509Cert *cert, uint32_t type, uint32_t trust)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCertTrustFromString (in nsIX509Cert3 cert, in string trustString); */
NS_IMETHODIMP nsX509CertDB::SetCertTrustFromString(nsIX509Cert3 *cert, const char * trustString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isCertTrusted (in nsIX509Cert cert, in unsigned long certType, in unsigned long trustType); */
NS_IMETHODIMP nsX509CertDB::IsCertTrusted(nsIX509Cert *cert, uint32_t certType, uint32_t trustType, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void importCertsFromFile (in nsISupports aToken, in nsIFile aFile, in unsigned long aType); */
NS_IMETHODIMP nsX509CertDB::ImportCertsFromFile(nsISupports *aToken, nsIFile *aFile, uint32_t aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void importPKCS12File (in nsISupports aToken, in nsIFile aFile); */
NS_IMETHODIMP nsX509CertDB::ImportPKCS12File(nsISupports *aToken, nsIFile *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void exportPKCS12File (in nsISupports aToken, in nsIFile aFile, in unsigned long count, [array, size_is (count)] in nsIX509Cert aCerts); */
NS_IMETHODIMP nsX509CertDB::ExportPKCS12File(nsISupports *aToken, nsIFile *aFile, uint32_t count, nsIX509Cert **aCerts)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIX509Cert constructX509FromBase64 (in string base64); */
NS_IMETHODIMP nsX509CertDB::ConstructX509FromBase64(const char * base64, nsIX509Cert * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIX509Cert constructX509 (in string certDER, in unsigned long length); */
NS_IMETHODIMP nsX509CertDB::ConstructX509(const char * certDER, uint32_t length, nsIX509Cert * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIRecentBadCerts getRecentBadCerts (in boolean isPrivate); */
NS_IMETHODIMP nsX509CertDB::GetRecentBadCerts(bool isPrivate, nsIRecentBadCerts * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void openSignedAppFileAsync (in AppTrustedRoot trustedRoot, in nsIFile aJarFile, in nsIOpenSignedAppFileCallback callback); */
NS_IMETHODIMP nsX509CertDB::OpenSignedAppFileAsync(AppTrustedRoot trustedRoot, nsIFile *aJarFile, nsIOpenSignedAppFileCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addCert (in ACString certDER, in string aTrust, in string aName); */
NS_IMETHODIMP nsX509CertDB::AddCert(const nsACString & certDER, const char * aTrust, const char * aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* int32_t verifyCertNow (in nsIX509Cert aCert, in int64_t aUsage, in uint32_t aFlags, out nsIX509CertList verifiedChain, out bool aHasEVPolicy); */
NS_IMETHODIMP nsX509CertDB::VerifyCertNow(nsIX509Cert *aCert, int64_t aUsage, uint32_t aFlags, nsIX509CertList * *verifiedChain, bool *aHasEVPolicy, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearOCSPCache (); */
NS_IMETHODIMP nsX509CertDB::ClearOCSPCache()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIX509CertDB_h__ */

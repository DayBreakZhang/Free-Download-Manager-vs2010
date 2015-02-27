/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/security/manager/ssl/public/nsISignatureVerifier.idl
 */

#ifndef __gen_nsISignatureVerifier_h__
#define __gen_nsISignatureVerifier_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICertificatePrincipal; /* forward declaration */


/* starting interface:    nsISignatureVerifier */
#define NS_ISIGNATUREVERIFIER_IID_STR "22870b07-b5ef-481b-9f7f-d41787d4e617"

#define NS_ISIGNATUREVERIFIER_IID \
  {0x22870b07, 0xb5ef, 0x481b, \
    { 0x9f, 0x7f, 0xd4, 0x17, 0x87, 0xd4, 0xe6, 0x17 }}

class NS_NO_VTABLE nsISignatureVerifier : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISIGNATUREVERIFIER_IID)

  enum {
    VERIFY_OK = 0,
    VERIFY_ERROR_UNKNOWN_CA = -8172
  };

  /* nsICertificatePrincipal verifySignature (in string aSignature, in unsigned long aSignatureLen, in string plaintext, in unsigned long plaintextLen, out long errorCode); */
  NS_IMETHOD VerifySignature(const char * aSignature, uint32_t aSignatureLen, const char * plaintext, uint32_t plaintextLen, int32_t *errorCode, nsICertificatePrincipal * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISignatureVerifier, NS_ISIGNATUREVERIFIER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISIGNATUREVERIFIER \
  NS_IMETHOD VerifySignature(const char * aSignature, uint32_t aSignatureLen, const char * plaintext, uint32_t plaintextLen, int32_t *errorCode, nsICertificatePrincipal * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISIGNATUREVERIFIER(_to) \
  NS_IMETHOD VerifySignature(const char * aSignature, uint32_t aSignatureLen, const char * plaintext, uint32_t plaintextLen, int32_t *errorCode, nsICertificatePrincipal * *_retval) { return _to VerifySignature(aSignature, aSignatureLen, plaintext, plaintextLen, errorCode, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISIGNATUREVERIFIER(_to) \
  NS_IMETHOD VerifySignature(const char * aSignature, uint32_t aSignatureLen, const char * plaintext, uint32_t plaintextLen, int32_t *errorCode, nsICertificatePrincipal * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->VerifySignature(aSignature, aSignatureLen, plaintext, plaintextLen, errorCode, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSignatureVerifier : public nsISignatureVerifier
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISIGNATUREVERIFIER

  nsSignatureVerifier();

private:
  ~nsSignatureVerifier();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSignatureVerifier, nsISignatureVerifier)

nsSignatureVerifier::nsSignatureVerifier()
{
  /* member initializers and constructor code */
}

nsSignatureVerifier::~nsSignatureVerifier()
{
  /* destructor code */
}

/* nsICertificatePrincipal verifySignature (in string aSignature, in unsigned long aSignatureLen, in string plaintext, in unsigned long plaintextLen, out long errorCode); */
NS_IMETHODIMP nsSignatureVerifier::VerifySignature(const char * aSignature, uint32_t aSignatureLen, const char * plaintext, uint32_t plaintextLen, int32_t *errorCode, nsICertificatePrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define SIGNATURE_VERIFIER_CONTRACTID "@mozilla.org/psm;1"

#endif /* __gen_nsISignatureVerifier_h__ */

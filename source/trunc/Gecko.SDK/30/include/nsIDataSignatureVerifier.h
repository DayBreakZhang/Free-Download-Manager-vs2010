/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDataSignatureVerifier.idl
 */

#ifndef __gen_nsIDataSignatureVerifier_h__
#define __gen_nsIDataSignatureVerifier_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDataSignatureVerifier */
#define NS_IDATASIGNATUREVERIFIER_IID_STR "0a84b3d5-6ba9-432d-89da-4fbd0b0f2aec"

#define NS_IDATASIGNATUREVERIFIER_IID \
  {0x0a84b3d5, 0x6ba9, 0x432d, \
    { 0x89, 0xda, 0x4f, 0xbd, 0x0b, 0x0f, 0x2a, 0xec }}

class NS_NO_VTABLE nsIDataSignatureVerifier : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDATASIGNATUREVERIFIER_IID)

  /* boolean verifyData (in ACString aData, in ACString aSignature, in ACString aPublicKey); */
  NS_IMETHOD VerifyData(const nsACString & aData, const nsACString & aSignature, const nsACString & aPublicKey, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDataSignatureVerifier, NS_IDATASIGNATUREVERIFIER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDATASIGNATUREVERIFIER \
  NS_IMETHOD VerifyData(const nsACString & aData, const nsACString & aSignature, const nsACString & aPublicKey, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDATASIGNATUREVERIFIER(_to) \
  NS_IMETHOD VerifyData(const nsACString & aData, const nsACString & aSignature, const nsACString & aPublicKey, bool *_retval) { return _to VerifyData(aData, aSignature, aPublicKey, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDATASIGNATUREVERIFIER(_to) \
  NS_IMETHOD VerifyData(const nsACString & aData, const nsACString & aSignature, const nsACString & aPublicKey, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->VerifyData(aData, aSignature, aPublicKey, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDataSignatureVerifier : public nsIDataSignatureVerifier
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDATASIGNATUREVERIFIER

  nsDataSignatureVerifier();

private:
  ~nsDataSignatureVerifier();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDataSignatureVerifier, nsIDataSignatureVerifier)

nsDataSignatureVerifier::nsDataSignatureVerifier()
{
  /* member initializers and constructor code */
}

nsDataSignatureVerifier::~nsDataSignatureVerifier()
{
  /* destructor code */
}

/* boolean verifyData (in ACString aData, in ACString aSignature, in ACString aPublicKey); */
NS_IMETHODIMP nsDataSignatureVerifier::VerifyData(const nsACString & aData, const nsACString & aSignature, const nsACString & aPublicKey, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDataSignatureVerifier_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICertificatePrincipal.idl
 */

#ifndef __gen_nsICertificatePrincipal_h__
#define __gen_nsICertificatePrincipal_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsICertificatePrincipal */
#define NS_ICERTIFICATEPRINCIPAL_IID_STR "7cd4af5a-64d3-44a8-9700-804a42a6109a"

#define NS_ICERTIFICATEPRINCIPAL_IID \
  {0x7cd4af5a, 0x64d3, 0x44a8, \
    { 0x97, 0x00, 0x80, 0x4a, 0x42, 0xa6, 0x10, 0x9a }}

class NS_NO_VTABLE nsICertificatePrincipal : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICERTIFICATEPRINCIPAL_IID)

  /* readonly attribute AUTF8String fingerprint; */
  NS_IMETHOD GetFingerprint(nsACString & aFingerprint) = 0;

  /* readonly attribute AUTF8String prettyName; */
  NS_IMETHOD GetPrettyName(nsACString & aPrettyName) = 0;

  /* readonly attribute AUTF8String subjectName; */
  NS_IMETHOD GetSubjectName(nsACString & aSubjectName) = 0;

  /* readonly attribute nsISupports certificate; */
  NS_IMETHOD GetCertificate(nsISupports * *aCertificate) = 0;

  /* readonly attribute boolean hasCertificate; */
  NS_IMETHOD GetHasCertificate(bool *aHasCertificate) = 0;

  /* bool equals (in nsICertificatePrincipal aOther); */
  NS_IMETHOD Equals(nsICertificatePrincipal *aOther, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICertificatePrincipal, NS_ICERTIFICATEPRINCIPAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICERTIFICATEPRINCIPAL \
  NS_IMETHOD GetFingerprint(nsACString & aFingerprint); \
  NS_IMETHOD GetPrettyName(nsACString & aPrettyName); \
  NS_IMETHOD GetSubjectName(nsACString & aSubjectName); \
  NS_IMETHOD GetCertificate(nsISupports * *aCertificate); \
  NS_IMETHOD GetHasCertificate(bool *aHasCertificate); \
  NS_IMETHOD Equals(nsICertificatePrincipal *aOther, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICERTIFICATEPRINCIPAL(_to) \
  NS_IMETHOD GetFingerprint(nsACString & aFingerprint) { return _to GetFingerprint(aFingerprint); } \
  NS_IMETHOD GetPrettyName(nsACString & aPrettyName) { return _to GetPrettyName(aPrettyName); } \
  NS_IMETHOD GetSubjectName(nsACString & aSubjectName) { return _to GetSubjectName(aSubjectName); } \
  NS_IMETHOD GetCertificate(nsISupports * *aCertificate) { return _to GetCertificate(aCertificate); } \
  NS_IMETHOD GetHasCertificate(bool *aHasCertificate) { return _to GetHasCertificate(aHasCertificate); } \
  NS_IMETHOD Equals(nsICertificatePrincipal *aOther, bool *_retval) { return _to Equals(aOther, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICERTIFICATEPRINCIPAL(_to) \
  NS_IMETHOD GetFingerprint(nsACString & aFingerprint) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFingerprint(aFingerprint); } \
  NS_IMETHOD GetPrettyName(nsACString & aPrettyName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrettyName(aPrettyName); } \
  NS_IMETHOD GetSubjectName(nsACString & aSubjectName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSubjectName(aSubjectName); } \
  NS_IMETHOD GetCertificate(nsISupports * *aCertificate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCertificate(aCertificate); } \
  NS_IMETHOD GetHasCertificate(bool *aHasCertificate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasCertificate(aHasCertificate); } \
  NS_IMETHOD Equals(nsICertificatePrincipal *aOther, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Equals(aOther, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCertificatePrincipal : public nsICertificatePrincipal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICERTIFICATEPRINCIPAL

  nsCertificatePrincipal();

private:
  ~nsCertificatePrincipal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCertificatePrincipal, nsICertificatePrincipal)

nsCertificatePrincipal::nsCertificatePrincipal()
{
  /* member initializers and constructor code */
}

nsCertificatePrincipal::~nsCertificatePrincipal()
{
  /* destructor code */
}

/* readonly attribute AUTF8String fingerprint; */
NS_IMETHODIMP nsCertificatePrincipal::GetFingerprint(nsACString & aFingerprint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String prettyName; */
NS_IMETHODIMP nsCertificatePrincipal::GetPrettyName(nsACString & aPrettyName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String subjectName; */
NS_IMETHODIMP nsCertificatePrincipal::GetSubjectName(nsACString & aSubjectName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports certificate; */
NS_IMETHODIMP nsCertificatePrincipal::GetCertificate(nsISupports * *aCertificate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasCertificate; */
NS_IMETHODIMP nsCertificatePrincipal::GetHasCertificate(bool *aHasCertificate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool equals (in nsICertificatePrincipal aOther); */
NS_IMETHODIMP nsCertificatePrincipal::Equals(nsICertificatePrincipal *aOther, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICertificatePrincipal_h__ */

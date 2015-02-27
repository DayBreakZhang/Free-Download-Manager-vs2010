/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/security/manager/ssl/public/nsINSSVersion.idl
 */

#ifndef __gen_nsINSSVersion_h__
#define __gen_nsINSSVersion_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define NS_NSSVERSION_CONTRACTID "@mozilla.org/security/nssversion;1"

/* starting interface:    nsINSSVersion */
#define NS_INSSVERSION_IID_STR "a8a53a2b-75cc-4c68-a9bb-9791dbddaa00"

#define NS_INSSVERSION_IID \
  {0xa8a53a2b, 0x75cc, 0x4c68, \
    { 0xa9, 0xbb, 0x97, 0x91, 0xdb, 0xdd, 0xaa, 0x00 }}

class NS_NO_VTABLE nsINSSVersion : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INSSVERSION_IID)

  /* readonly attribute AString NSPR_MinVersion; */
  NS_IMETHOD GetNSPR_MinVersion(nsAString & aNSPR_MinVersion) = 0;

  /* readonly attribute AString NSS_MinVersion; */
  NS_IMETHOD GetNSS_MinVersion(nsAString & aNSS_MinVersion) = 0;

  /* readonly attribute AString NSSUTIL_MinVersion; */
  NS_IMETHOD GetNSSUTIL_MinVersion(nsAString & aNSSUTIL_MinVersion) = 0;

  /* readonly attribute AString NSSSSL_MinVersion; */
  NS_IMETHOD GetNSSSSL_MinVersion(nsAString & aNSSSSL_MinVersion) = 0;

  /* readonly attribute AString NSSSMIME_MinVersion; */
  NS_IMETHOD GetNSSSMIME_MinVersion(nsAString & aNSSSMIME_MinVersion) = 0;

  /* readonly attribute AString NSPR_Version; */
  NS_IMETHOD GetNSPR_Version(nsAString & aNSPR_Version) = 0;

  /* readonly attribute AString NSS_Version; */
  NS_IMETHOD GetNSS_Version(nsAString & aNSS_Version) = 0;

  /* readonly attribute AString NSSUTIL_Version; */
  NS_IMETHOD GetNSSUTIL_Version(nsAString & aNSSUTIL_Version) = 0;

  /* readonly attribute AString NSSSSL_Version; */
  NS_IMETHOD GetNSSSSL_Version(nsAString & aNSSSSL_Version) = 0;

  /* readonly attribute AString NSSSMIME_Version; */
  NS_IMETHOD GetNSSSMIME_Version(nsAString & aNSSSMIME_Version) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINSSVersion, NS_INSSVERSION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINSSVERSION \
  NS_IMETHOD GetNSPR_MinVersion(nsAString & aNSPR_MinVersion); \
  NS_IMETHOD GetNSS_MinVersion(nsAString & aNSS_MinVersion); \
  NS_IMETHOD GetNSSUTIL_MinVersion(nsAString & aNSSUTIL_MinVersion); \
  NS_IMETHOD GetNSSSSL_MinVersion(nsAString & aNSSSSL_MinVersion); \
  NS_IMETHOD GetNSSSMIME_MinVersion(nsAString & aNSSSMIME_MinVersion); \
  NS_IMETHOD GetNSPR_Version(nsAString & aNSPR_Version); \
  NS_IMETHOD GetNSS_Version(nsAString & aNSS_Version); \
  NS_IMETHOD GetNSSUTIL_Version(nsAString & aNSSUTIL_Version); \
  NS_IMETHOD GetNSSSSL_Version(nsAString & aNSSSSL_Version); \
  NS_IMETHOD GetNSSSMIME_Version(nsAString & aNSSSMIME_Version); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINSSVERSION(_to) \
  NS_IMETHOD GetNSPR_MinVersion(nsAString & aNSPR_MinVersion) { return _to GetNSPR_MinVersion(aNSPR_MinVersion); } \
  NS_IMETHOD GetNSS_MinVersion(nsAString & aNSS_MinVersion) { return _to GetNSS_MinVersion(aNSS_MinVersion); } \
  NS_IMETHOD GetNSSUTIL_MinVersion(nsAString & aNSSUTIL_MinVersion) { return _to GetNSSUTIL_MinVersion(aNSSUTIL_MinVersion); } \
  NS_IMETHOD GetNSSSSL_MinVersion(nsAString & aNSSSSL_MinVersion) { return _to GetNSSSSL_MinVersion(aNSSSSL_MinVersion); } \
  NS_IMETHOD GetNSSSMIME_MinVersion(nsAString & aNSSSMIME_MinVersion) { return _to GetNSSSMIME_MinVersion(aNSSSMIME_MinVersion); } \
  NS_IMETHOD GetNSPR_Version(nsAString & aNSPR_Version) { return _to GetNSPR_Version(aNSPR_Version); } \
  NS_IMETHOD GetNSS_Version(nsAString & aNSS_Version) { return _to GetNSS_Version(aNSS_Version); } \
  NS_IMETHOD GetNSSUTIL_Version(nsAString & aNSSUTIL_Version) { return _to GetNSSUTIL_Version(aNSSUTIL_Version); } \
  NS_IMETHOD GetNSSSSL_Version(nsAString & aNSSSSL_Version) { return _to GetNSSSSL_Version(aNSSSSL_Version); } \
  NS_IMETHOD GetNSSSMIME_Version(nsAString & aNSSSMIME_Version) { return _to GetNSSSMIME_Version(aNSSSMIME_Version); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINSSVERSION(_to) \
  NS_IMETHOD GetNSPR_MinVersion(nsAString & aNSPR_MinVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNSPR_MinVersion(aNSPR_MinVersion); } \
  NS_IMETHOD GetNSS_MinVersion(nsAString & aNSS_MinVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNSS_MinVersion(aNSS_MinVersion); } \
  NS_IMETHOD GetNSSUTIL_MinVersion(nsAString & aNSSUTIL_MinVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNSSUTIL_MinVersion(aNSSUTIL_MinVersion); } \
  NS_IMETHOD GetNSSSSL_MinVersion(nsAString & aNSSSSL_MinVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNSSSSL_MinVersion(aNSSSSL_MinVersion); } \
  NS_IMETHOD GetNSSSMIME_MinVersion(nsAString & aNSSSMIME_MinVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNSSSMIME_MinVersion(aNSSSMIME_MinVersion); } \
  NS_IMETHOD GetNSPR_Version(nsAString & aNSPR_Version) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNSPR_Version(aNSPR_Version); } \
  NS_IMETHOD GetNSS_Version(nsAString & aNSS_Version) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNSS_Version(aNSS_Version); } \
  NS_IMETHOD GetNSSUTIL_Version(nsAString & aNSSUTIL_Version) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNSSUTIL_Version(aNSSUTIL_Version); } \
  NS_IMETHOD GetNSSSSL_Version(nsAString & aNSSSSL_Version) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNSSSSL_Version(aNSSSSL_Version); } \
  NS_IMETHOD GetNSSSMIME_Version(nsAString & aNSSSMIME_Version) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNSSSMIME_Version(aNSSSMIME_Version); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNSSVersion : public nsINSSVersion
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINSSVERSION

  nsNSSVersion();

private:
  ~nsNSSVersion();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNSSVersion, nsINSSVersion)

nsNSSVersion::nsNSSVersion()
{
  /* member initializers and constructor code */
}

nsNSSVersion::~nsNSSVersion()
{
  /* destructor code */
}

/* readonly attribute AString NSPR_MinVersion; */
NS_IMETHODIMP nsNSSVersion::GetNSPR_MinVersion(nsAString & aNSPR_MinVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString NSS_MinVersion; */
NS_IMETHODIMP nsNSSVersion::GetNSS_MinVersion(nsAString & aNSS_MinVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString NSSUTIL_MinVersion; */
NS_IMETHODIMP nsNSSVersion::GetNSSUTIL_MinVersion(nsAString & aNSSUTIL_MinVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString NSSSSL_MinVersion; */
NS_IMETHODIMP nsNSSVersion::GetNSSSSL_MinVersion(nsAString & aNSSSSL_MinVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString NSSSMIME_MinVersion; */
NS_IMETHODIMP nsNSSVersion::GetNSSSMIME_MinVersion(nsAString & aNSSSMIME_MinVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString NSPR_Version; */
NS_IMETHODIMP nsNSSVersion::GetNSPR_Version(nsAString & aNSPR_Version)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString NSS_Version; */
NS_IMETHODIMP nsNSSVersion::GetNSS_Version(nsAString & aNSS_Version)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString NSSUTIL_Version; */
NS_IMETHODIMP nsNSSVersion::GetNSSUTIL_Version(nsAString & aNSSUTIL_Version)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString NSSSSL_Version; */
NS_IMETHODIMP nsNSSVersion::GetNSSSSL_Version(nsAString & aNSSSSL_Version)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString NSSSMIME_Version; */
NS_IMETHODIMP nsNSSVersion::GetNSSSMIME_Version(nsAString & aNSSSMIME_Version)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINSSVersion_h__ */

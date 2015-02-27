/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIURI.idl
 */

#ifndef __gen_nsIURI_h__
#define __gen_nsIURI_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#undef GetPort  // XXX Windows!
#undef SetPort  // XXX Windows!

/* starting interface:    nsIURI */
#define NS_IURI_IID_STR "395fe045-7d18-4adb-a3fd-af98c8a1af11"

#define NS_IURI_IID \
  {0x395fe045, 0x7d18, 0x4adb, \
    { 0xa3, 0xfd, 0xaf, 0x98, 0xc8, 0xa1, 0xaf, 0x11 }}

class NS_NO_VTABLE nsIURI : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURI_IID)

  /* attribute AUTF8String spec; */
  NS_IMETHOD GetSpec(nsACString & aSpec) = 0;
  NS_IMETHOD SetSpec(const nsACString & aSpec) = 0;

  /* readonly attribute AUTF8String prePath; */
  NS_IMETHOD GetPrePath(nsACString & aPrePath) = 0;

  /* attribute ACString scheme; */
  NS_IMETHOD GetScheme(nsACString & aScheme) = 0;
  NS_IMETHOD SetScheme(const nsACString & aScheme) = 0;

  /* attribute AUTF8String userPass; */
  NS_IMETHOD GetUserPass(nsACString & aUserPass) = 0;
  NS_IMETHOD SetUserPass(const nsACString & aUserPass) = 0;

  /* attribute AUTF8String username; */
  NS_IMETHOD GetUsername(nsACString & aUsername) = 0;
  NS_IMETHOD SetUsername(const nsACString & aUsername) = 0;

  /* attribute AUTF8String password; */
  NS_IMETHOD GetPassword(nsACString & aPassword) = 0;
  NS_IMETHOD SetPassword(const nsACString & aPassword) = 0;

  /* attribute AUTF8String hostPort; */
  NS_IMETHOD GetHostPort(nsACString & aHostPort) = 0;
  NS_IMETHOD SetHostPort(const nsACString & aHostPort) = 0;

  /* attribute AUTF8String host; */
  NS_IMETHOD GetHost(nsACString & aHost) = 0;
  NS_IMETHOD SetHost(const nsACString & aHost) = 0;

  /* attribute long port; */
  NS_IMETHOD GetPort(int32_t *aPort) = 0;
  NS_IMETHOD SetPort(int32_t aPort) = 0;

  /* attribute AUTF8String path; */
  NS_IMETHOD GetPath(nsACString & aPath) = 0;
  NS_IMETHOD SetPath(const nsACString & aPath) = 0;

  /* boolean equals (in nsIURI other); */
  NS_IMETHOD Equals(nsIURI *other, bool *_retval) = 0;

  /* boolean schemeIs (in string scheme); */
  NS_IMETHOD SchemeIs(const char * scheme, bool *_retval) = 0;

  /* nsIURI clone (); */
  NS_IMETHOD Clone(nsIURI * *_retval) = 0;

  /* AUTF8String resolve (in AUTF8String relativePath); */
  NS_IMETHOD Resolve(const nsACString & relativePath, nsACString & _retval) = 0;

  /* readonly attribute ACString asciiSpec; */
  NS_IMETHOD GetAsciiSpec(nsACString & aAsciiSpec) = 0;

  /* readonly attribute ACString asciiHost; */
  NS_IMETHOD GetAsciiHost(nsACString & aAsciiHost) = 0;

  /* readonly attribute ACString originCharset; */
  NS_IMETHOD GetOriginCharset(nsACString & aOriginCharset) = 0;

  /* attribute AUTF8String ref; */
  NS_IMETHOD GetRef(nsACString & aRef) = 0;
  NS_IMETHOD SetRef(const nsACString & aRef) = 0;

  /* boolean equalsExceptRef (in nsIURI other); */
  NS_IMETHOD EqualsExceptRef(nsIURI *other, bool *_retval) = 0;

  /* nsIURI cloneIgnoringRef (); */
  NS_IMETHOD CloneIgnoringRef(nsIURI * *_retval) = 0;

  /* readonly attribute AUTF8String specIgnoringRef; */
  NS_IMETHOD GetSpecIgnoringRef(nsACString & aSpecIgnoringRef) = 0;

  /* readonly attribute boolean hasRef; */
  NS_IMETHOD GetHasRef(bool *aHasRef) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIURI, NS_IURI_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURI \
  NS_IMETHOD GetSpec(nsACString & aSpec); \
  NS_IMETHOD SetSpec(const nsACString & aSpec); \
  NS_IMETHOD GetPrePath(nsACString & aPrePath); \
  NS_IMETHOD GetScheme(nsACString & aScheme); \
  NS_IMETHOD SetScheme(const nsACString & aScheme); \
  NS_IMETHOD GetUserPass(nsACString & aUserPass); \
  NS_IMETHOD SetUserPass(const nsACString & aUserPass); \
  NS_IMETHOD GetUsername(nsACString & aUsername); \
  NS_IMETHOD SetUsername(const nsACString & aUsername); \
  NS_IMETHOD GetPassword(nsACString & aPassword); \
  NS_IMETHOD SetPassword(const nsACString & aPassword); \
  NS_IMETHOD GetHostPort(nsACString & aHostPort); \
  NS_IMETHOD SetHostPort(const nsACString & aHostPort); \
  NS_IMETHOD GetHost(nsACString & aHost); \
  NS_IMETHOD SetHost(const nsACString & aHost); \
  NS_IMETHOD GetPort(int32_t *aPort); \
  NS_IMETHOD SetPort(int32_t aPort); \
  NS_IMETHOD GetPath(nsACString & aPath); \
  NS_IMETHOD SetPath(const nsACString & aPath); \
  NS_IMETHOD Equals(nsIURI *other, bool *_retval); \
  NS_IMETHOD SchemeIs(const char * scheme, bool *_retval); \
  NS_IMETHOD Clone(nsIURI * *_retval); \
  NS_IMETHOD Resolve(const nsACString & relativePath, nsACString & _retval); \
  NS_IMETHOD GetAsciiSpec(nsACString & aAsciiSpec); \
  NS_IMETHOD GetAsciiHost(nsACString & aAsciiHost); \
  NS_IMETHOD GetOriginCharset(nsACString & aOriginCharset); \
  NS_IMETHOD GetRef(nsACString & aRef); \
  NS_IMETHOD SetRef(const nsACString & aRef); \
  NS_IMETHOD EqualsExceptRef(nsIURI *other, bool *_retval); \
  NS_IMETHOD CloneIgnoringRef(nsIURI * *_retval); \
  NS_IMETHOD GetSpecIgnoringRef(nsACString & aSpecIgnoringRef); \
  NS_IMETHOD GetHasRef(bool *aHasRef); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURI(_to) \
  NS_IMETHOD GetSpec(nsACString & aSpec) { return _to GetSpec(aSpec); } \
  NS_IMETHOD SetSpec(const nsACString & aSpec) { return _to SetSpec(aSpec); } \
  NS_IMETHOD GetPrePath(nsACString & aPrePath) { return _to GetPrePath(aPrePath); } \
  NS_IMETHOD GetScheme(nsACString & aScheme) { return _to GetScheme(aScheme); } \
  NS_IMETHOD SetScheme(const nsACString & aScheme) { return _to SetScheme(aScheme); } \
  NS_IMETHOD GetUserPass(nsACString & aUserPass) { return _to GetUserPass(aUserPass); } \
  NS_IMETHOD SetUserPass(const nsACString & aUserPass) { return _to SetUserPass(aUserPass); } \
  NS_IMETHOD GetUsername(nsACString & aUsername) { return _to GetUsername(aUsername); } \
  NS_IMETHOD SetUsername(const nsACString & aUsername) { return _to SetUsername(aUsername); } \
  NS_IMETHOD GetPassword(nsACString & aPassword) { return _to GetPassword(aPassword); } \
  NS_IMETHOD SetPassword(const nsACString & aPassword) { return _to SetPassword(aPassword); } \
  NS_IMETHOD GetHostPort(nsACString & aHostPort) { return _to GetHostPort(aHostPort); } \
  NS_IMETHOD SetHostPort(const nsACString & aHostPort) { return _to SetHostPort(aHostPort); } \
  NS_IMETHOD GetHost(nsACString & aHost) { return _to GetHost(aHost); } \
  NS_IMETHOD SetHost(const nsACString & aHost) { return _to SetHost(aHost); } \
  NS_IMETHOD GetPort(int32_t *aPort) { return _to GetPort(aPort); } \
  NS_IMETHOD SetPort(int32_t aPort) { return _to SetPort(aPort); } \
  NS_IMETHOD GetPath(nsACString & aPath) { return _to GetPath(aPath); } \
  NS_IMETHOD SetPath(const nsACString & aPath) { return _to SetPath(aPath); } \
  NS_IMETHOD Equals(nsIURI *other, bool *_retval) { return _to Equals(other, _retval); } \
  NS_IMETHOD SchemeIs(const char * scheme, bool *_retval) { return _to SchemeIs(scheme, _retval); } \
  NS_IMETHOD Clone(nsIURI * *_retval) { return _to Clone(_retval); } \
  NS_IMETHOD Resolve(const nsACString & relativePath, nsACString & _retval) { return _to Resolve(relativePath, _retval); } \
  NS_IMETHOD GetAsciiSpec(nsACString & aAsciiSpec) { return _to GetAsciiSpec(aAsciiSpec); } \
  NS_IMETHOD GetAsciiHost(nsACString & aAsciiHost) { return _to GetAsciiHost(aAsciiHost); } \
  NS_IMETHOD GetOriginCharset(nsACString & aOriginCharset) { return _to GetOriginCharset(aOriginCharset); } \
  NS_IMETHOD GetRef(nsACString & aRef) { return _to GetRef(aRef); } \
  NS_IMETHOD SetRef(const nsACString & aRef) { return _to SetRef(aRef); } \
  NS_IMETHOD EqualsExceptRef(nsIURI *other, bool *_retval) { return _to EqualsExceptRef(other, _retval); } \
  NS_IMETHOD CloneIgnoringRef(nsIURI * *_retval) { return _to CloneIgnoringRef(_retval); } \
  NS_IMETHOD GetSpecIgnoringRef(nsACString & aSpecIgnoringRef) { return _to GetSpecIgnoringRef(aSpecIgnoringRef); } \
  NS_IMETHOD GetHasRef(bool *aHasRef) { return _to GetHasRef(aHasRef); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURI(_to) \
  NS_IMETHOD GetSpec(nsACString & aSpec) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSpec(aSpec); } \
  NS_IMETHOD SetSpec(const nsACString & aSpec) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSpec(aSpec); } \
  NS_IMETHOD GetPrePath(nsACString & aPrePath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrePath(aPrePath); } \
  NS_IMETHOD GetScheme(nsACString & aScheme) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScheme(aScheme); } \
  NS_IMETHOD SetScheme(const nsACString & aScheme) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScheme(aScheme); } \
  NS_IMETHOD GetUserPass(nsACString & aUserPass) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUserPass(aUserPass); } \
  NS_IMETHOD SetUserPass(const nsACString & aUserPass) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUserPass(aUserPass); } \
  NS_IMETHOD GetUsername(nsACString & aUsername) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsername(aUsername); } \
  NS_IMETHOD SetUsername(const nsACString & aUsername) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUsername(aUsername); } \
  NS_IMETHOD GetPassword(nsACString & aPassword) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPassword(aPassword); } \
  NS_IMETHOD SetPassword(const nsACString & aPassword) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPassword(aPassword); } \
  NS_IMETHOD GetHostPort(nsACString & aHostPort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHostPort(aHostPort); } \
  NS_IMETHOD SetHostPort(const nsACString & aHostPort) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHostPort(aHostPort); } \
  NS_IMETHOD GetHost(nsACString & aHost) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHost(aHost); } \
  NS_IMETHOD SetHost(const nsACString & aHost) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHost(aHost); } \
  NS_IMETHOD GetPort(int32_t *aPort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPort(aPort); } \
  NS_IMETHOD SetPort(int32_t aPort) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPort(aPort); } \
  NS_IMETHOD GetPath(nsACString & aPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPath(aPath); } \
  NS_IMETHOD SetPath(const nsACString & aPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPath(aPath); } \
  NS_IMETHOD Equals(nsIURI *other, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Equals(other, _retval); } \
  NS_IMETHOD SchemeIs(const char * scheme, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SchemeIs(scheme, _retval); } \
  NS_IMETHOD Clone(nsIURI * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } \
  NS_IMETHOD Resolve(const nsACString & relativePath, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Resolve(relativePath, _retval); } \
  NS_IMETHOD GetAsciiSpec(nsACString & aAsciiSpec) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsciiSpec(aAsciiSpec); } \
  NS_IMETHOD GetAsciiHost(nsACString & aAsciiHost) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsciiHost(aAsciiHost); } \
  NS_IMETHOD GetOriginCharset(nsACString & aOriginCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOriginCharset(aOriginCharset); } \
  NS_IMETHOD GetRef(nsACString & aRef) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRef(aRef); } \
  NS_IMETHOD SetRef(const nsACString & aRef) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRef(aRef); } \
  NS_IMETHOD EqualsExceptRef(nsIURI *other, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EqualsExceptRef(other, _retval); } \
  NS_IMETHOD CloneIgnoringRef(nsIURI * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloneIgnoringRef(_retval); } \
  NS_IMETHOD GetSpecIgnoringRef(nsACString & aSpecIgnoringRef) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSpecIgnoringRef(aSpecIgnoringRef); } \
  NS_IMETHOD GetHasRef(bool *aHasRef) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasRef(aHasRef); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsURI : public nsIURI
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURI

  nsURI();

private:
  ~nsURI();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsURI, nsIURI)

nsURI::nsURI()
{
  /* member initializers and constructor code */
}

nsURI::~nsURI()
{
  /* destructor code */
}

/* attribute AUTF8String spec; */
NS_IMETHODIMP nsURI::GetSpec(nsACString & aSpec)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsURI::SetSpec(const nsACString & aSpec)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String prePath; */
NS_IMETHODIMP nsURI::GetPrePath(nsACString & aPrePath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString scheme; */
NS_IMETHODIMP nsURI::GetScheme(nsACString & aScheme)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsURI::SetScheme(const nsACString & aScheme)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String userPass; */
NS_IMETHODIMP nsURI::GetUserPass(nsACString & aUserPass)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsURI::SetUserPass(const nsACString & aUserPass)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String username; */
NS_IMETHODIMP nsURI::GetUsername(nsACString & aUsername)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsURI::SetUsername(const nsACString & aUsername)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String password; */
NS_IMETHODIMP nsURI::GetPassword(nsACString & aPassword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsURI::SetPassword(const nsACString & aPassword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String hostPort; */
NS_IMETHODIMP nsURI::GetHostPort(nsACString & aHostPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsURI::SetHostPort(const nsACString & aHostPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String host; */
NS_IMETHODIMP nsURI::GetHost(nsACString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsURI::SetHost(const nsACString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long port; */
NS_IMETHODIMP nsURI::GetPort(int32_t *aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsURI::SetPort(int32_t aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String path; */
NS_IMETHODIMP nsURI::GetPath(nsACString & aPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsURI::SetPath(const nsACString & aPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean equals (in nsIURI other); */
NS_IMETHODIMP nsURI::Equals(nsIURI *other, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean schemeIs (in string scheme); */
NS_IMETHODIMP nsURI::SchemeIs(const char * scheme, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI clone (); */
NS_IMETHODIMP nsURI::Clone(nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String resolve (in AUTF8String relativePath); */
NS_IMETHODIMP nsURI::Resolve(const nsACString & relativePath, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString asciiSpec; */
NS_IMETHODIMP nsURI::GetAsciiSpec(nsACString & aAsciiSpec)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString asciiHost; */
NS_IMETHODIMP nsURI::GetAsciiHost(nsACString & aAsciiHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString originCharset; */
NS_IMETHODIMP nsURI::GetOriginCharset(nsACString & aOriginCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String ref; */
NS_IMETHODIMP nsURI::GetRef(nsACString & aRef)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsURI::SetRef(const nsACString & aRef)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean equalsExceptRef (in nsIURI other); */
NS_IMETHODIMP nsURI::EqualsExceptRef(nsIURI *other, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI cloneIgnoringRef (); */
NS_IMETHODIMP nsURI::CloneIgnoringRef(nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String specIgnoringRef; */
NS_IMETHODIMP nsURI::GetSpecIgnoringRef(nsACString & aSpecIgnoringRef)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasRef; */
NS_IMETHODIMP nsURI::GetHasRef(bool *aHasRef)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIURI_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/toolkit/components/passwordmgr/nsILoginInfo.idl
 */

#ifndef __gen_nsILoginInfo_h__
#define __gen_nsILoginInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsILoginInfo */
#define NS_ILOGININFO_IID_STR "c41b7dff-6b9b-42fe-b78d-113051facb05"

#define NS_ILOGININFO_IID \
  {0xc41b7dff, 0x6b9b, 0x42fe, \
    { 0xb7, 0x8d, 0x11, 0x30, 0x51, 0xfa, 0xcb, 0x05 }}

class NS_NO_VTABLE nsILoginInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOGININFO_IID)

  /* attribute AString hostname; */
  NS_IMETHOD GetHostname(nsAString & aHostname) = 0;
  NS_IMETHOD SetHostname(const nsAString & aHostname) = 0;

  /* attribute AString formSubmitURL; */
  NS_IMETHOD GetFormSubmitURL(nsAString & aFormSubmitURL) = 0;
  NS_IMETHOD SetFormSubmitURL(const nsAString & aFormSubmitURL) = 0;

  /* attribute AString httpRealm; */
  NS_IMETHOD GetHttpRealm(nsAString & aHttpRealm) = 0;
  NS_IMETHOD SetHttpRealm(const nsAString & aHttpRealm) = 0;

  /* attribute AString username; */
  NS_IMETHOD GetUsername(nsAString & aUsername) = 0;
  NS_IMETHOD SetUsername(const nsAString & aUsername) = 0;

  /* attribute AString usernameField; */
  NS_IMETHOD GetUsernameField(nsAString & aUsernameField) = 0;
  NS_IMETHOD SetUsernameField(const nsAString & aUsernameField) = 0;

  /* attribute AString password; */
  NS_IMETHOD GetPassword(nsAString & aPassword) = 0;
  NS_IMETHOD SetPassword(const nsAString & aPassword) = 0;

  /* attribute AString passwordField; */
  NS_IMETHOD GetPasswordField(nsAString & aPasswordField) = 0;
  NS_IMETHOD SetPasswordField(const nsAString & aPasswordField) = 0;

  /* void init (in AString aHostname, in AString aFormSubmitURL, in AString aHttpRealm, in AString aUsername, in AString aPassword, in AString aUsernameField, in AString aPasswordField); */
  NS_IMETHOD Init(const nsAString & aHostname, const nsAString & aFormSubmitURL, const nsAString & aHttpRealm, const nsAString & aUsername, const nsAString & aPassword, const nsAString & aUsernameField, const nsAString & aPasswordField) = 0;

  /* boolean equals (in nsILoginInfo aLoginInfo); */
  NS_IMETHOD Equals(nsILoginInfo *aLoginInfo, bool *_retval) = 0;

  /* boolean matches (in nsILoginInfo aLoginInfo, in boolean ignorePassword); */
  NS_IMETHOD Matches(nsILoginInfo *aLoginInfo, bool ignorePassword, bool *_retval) = 0;

  /* nsILoginInfo clone (); */
  NS_IMETHOD Clone(nsILoginInfo * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILoginInfo, NS_ILOGININFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOGININFO \
  NS_IMETHOD GetHostname(nsAString & aHostname); \
  NS_IMETHOD SetHostname(const nsAString & aHostname); \
  NS_IMETHOD GetFormSubmitURL(nsAString & aFormSubmitURL); \
  NS_IMETHOD SetFormSubmitURL(const nsAString & aFormSubmitURL); \
  NS_IMETHOD GetHttpRealm(nsAString & aHttpRealm); \
  NS_IMETHOD SetHttpRealm(const nsAString & aHttpRealm); \
  NS_IMETHOD GetUsername(nsAString & aUsername); \
  NS_IMETHOD SetUsername(const nsAString & aUsername); \
  NS_IMETHOD GetUsernameField(nsAString & aUsernameField); \
  NS_IMETHOD SetUsernameField(const nsAString & aUsernameField); \
  NS_IMETHOD GetPassword(nsAString & aPassword); \
  NS_IMETHOD SetPassword(const nsAString & aPassword); \
  NS_IMETHOD GetPasswordField(nsAString & aPasswordField); \
  NS_IMETHOD SetPasswordField(const nsAString & aPasswordField); \
  NS_IMETHOD Init(const nsAString & aHostname, const nsAString & aFormSubmitURL, const nsAString & aHttpRealm, const nsAString & aUsername, const nsAString & aPassword, const nsAString & aUsernameField, const nsAString & aPasswordField); \
  NS_IMETHOD Equals(nsILoginInfo *aLoginInfo, bool *_retval); \
  NS_IMETHOD Matches(nsILoginInfo *aLoginInfo, bool ignorePassword, bool *_retval); \
  NS_IMETHOD Clone(nsILoginInfo * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOGININFO(_to) \
  NS_IMETHOD GetHostname(nsAString & aHostname) { return _to GetHostname(aHostname); } \
  NS_IMETHOD SetHostname(const nsAString & aHostname) { return _to SetHostname(aHostname); } \
  NS_IMETHOD GetFormSubmitURL(nsAString & aFormSubmitURL) { return _to GetFormSubmitURL(aFormSubmitURL); } \
  NS_IMETHOD SetFormSubmitURL(const nsAString & aFormSubmitURL) { return _to SetFormSubmitURL(aFormSubmitURL); } \
  NS_IMETHOD GetHttpRealm(nsAString & aHttpRealm) { return _to GetHttpRealm(aHttpRealm); } \
  NS_IMETHOD SetHttpRealm(const nsAString & aHttpRealm) { return _to SetHttpRealm(aHttpRealm); } \
  NS_IMETHOD GetUsername(nsAString & aUsername) { return _to GetUsername(aUsername); } \
  NS_IMETHOD SetUsername(const nsAString & aUsername) { return _to SetUsername(aUsername); } \
  NS_IMETHOD GetUsernameField(nsAString & aUsernameField) { return _to GetUsernameField(aUsernameField); } \
  NS_IMETHOD SetUsernameField(const nsAString & aUsernameField) { return _to SetUsernameField(aUsernameField); } \
  NS_IMETHOD GetPassword(nsAString & aPassword) { return _to GetPassword(aPassword); } \
  NS_IMETHOD SetPassword(const nsAString & aPassword) { return _to SetPassword(aPassword); } \
  NS_IMETHOD GetPasswordField(nsAString & aPasswordField) { return _to GetPasswordField(aPasswordField); } \
  NS_IMETHOD SetPasswordField(const nsAString & aPasswordField) { return _to SetPasswordField(aPasswordField); } \
  NS_IMETHOD Init(const nsAString & aHostname, const nsAString & aFormSubmitURL, const nsAString & aHttpRealm, const nsAString & aUsername, const nsAString & aPassword, const nsAString & aUsernameField, const nsAString & aPasswordField) { return _to Init(aHostname, aFormSubmitURL, aHttpRealm, aUsername, aPassword, aUsernameField, aPasswordField); } \
  NS_IMETHOD Equals(nsILoginInfo *aLoginInfo, bool *_retval) { return _to Equals(aLoginInfo, _retval); } \
  NS_IMETHOD Matches(nsILoginInfo *aLoginInfo, bool ignorePassword, bool *_retval) { return _to Matches(aLoginInfo, ignorePassword, _retval); } \
  NS_IMETHOD Clone(nsILoginInfo * *_retval) { return _to Clone(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOGININFO(_to) \
  NS_IMETHOD GetHostname(nsAString & aHostname) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHostname(aHostname); } \
  NS_IMETHOD SetHostname(const nsAString & aHostname) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHostname(aHostname); } \
  NS_IMETHOD GetFormSubmitURL(nsAString & aFormSubmitURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFormSubmitURL(aFormSubmitURL); } \
  NS_IMETHOD SetFormSubmitURL(const nsAString & aFormSubmitURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFormSubmitURL(aFormSubmitURL); } \
  NS_IMETHOD GetHttpRealm(nsAString & aHttpRealm) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHttpRealm(aHttpRealm); } \
  NS_IMETHOD SetHttpRealm(const nsAString & aHttpRealm) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHttpRealm(aHttpRealm); } \
  NS_IMETHOD GetUsername(nsAString & aUsername) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsername(aUsername); } \
  NS_IMETHOD SetUsername(const nsAString & aUsername) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUsername(aUsername); } \
  NS_IMETHOD GetUsernameField(nsAString & aUsernameField) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsernameField(aUsernameField); } \
  NS_IMETHOD SetUsernameField(const nsAString & aUsernameField) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUsernameField(aUsernameField); } \
  NS_IMETHOD GetPassword(nsAString & aPassword) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPassword(aPassword); } \
  NS_IMETHOD SetPassword(const nsAString & aPassword) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPassword(aPassword); } \
  NS_IMETHOD GetPasswordField(nsAString & aPasswordField) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPasswordField(aPasswordField); } \
  NS_IMETHOD SetPasswordField(const nsAString & aPasswordField) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPasswordField(aPasswordField); } \
  NS_IMETHOD Init(const nsAString & aHostname, const nsAString & aFormSubmitURL, const nsAString & aHttpRealm, const nsAString & aUsername, const nsAString & aPassword, const nsAString & aUsernameField, const nsAString & aPasswordField) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aHostname, aFormSubmitURL, aHttpRealm, aUsername, aPassword, aUsernameField, aPasswordField); } \
  NS_IMETHOD Equals(nsILoginInfo *aLoginInfo, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Equals(aLoginInfo, _retval); } \
  NS_IMETHOD Matches(nsILoginInfo *aLoginInfo, bool ignorePassword, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Matches(aLoginInfo, ignorePassword, _retval); } \
  NS_IMETHOD Clone(nsILoginInfo * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLoginInfo : public nsILoginInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOGININFO

  nsLoginInfo();

private:
  ~nsLoginInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLoginInfo, nsILoginInfo)

nsLoginInfo::nsLoginInfo()
{
  /* member initializers and constructor code */
}

nsLoginInfo::~nsLoginInfo()
{
  /* destructor code */
}

/* attribute AString hostname; */
NS_IMETHODIMP nsLoginInfo::GetHostname(nsAString & aHostname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginInfo::SetHostname(const nsAString & aHostname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString formSubmitURL; */
NS_IMETHODIMP nsLoginInfo::GetFormSubmitURL(nsAString & aFormSubmitURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginInfo::SetFormSubmitURL(const nsAString & aFormSubmitURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString httpRealm; */
NS_IMETHODIMP nsLoginInfo::GetHttpRealm(nsAString & aHttpRealm)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginInfo::SetHttpRealm(const nsAString & aHttpRealm)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString username; */
NS_IMETHODIMP nsLoginInfo::GetUsername(nsAString & aUsername)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginInfo::SetUsername(const nsAString & aUsername)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString usernameField; */
NS_IMETHODIMP nsLoginInfo::GetUsernameField(nsAString & aUsernameField)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginInfo::SetUsernameField(const nsAString & aUsernameField)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString password; */
NS_IMETHODIMP nsLoginInfo::GetPassword(nsAString & aPassword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginInfo::SetPassword(const nsAString & aPassword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString passwordField; */
NS_IMETHODIMP nsLoginInfo::GetPasswordField(nsAString & aPasswordField)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginInfo::SetPasswordField(const nsAString & aPasswordField)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void init (in AString aHostname, in AString aFormSubmitURL, in AString aHttpRealm, in AString aUsername, in AString aPassword, in AString aUsernameField, in AString aPasswordField); */
NS_IMETHODIMP nsLoginInfo::Init(const nsAString & aHostname, const nsAString & aFormSubmitURL, const nsAString & aHttpRealm, const nsAString & aUsername, const nsAString & aPassword, const nsAString & aUsernameField, const nsAString & aPasswordField)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean equals (in nsILoginInfo aLoginInfo); */
NS_IMETHODIMP nsLoginInfo::Equals(nsILoginInfo *aLoginInfo, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean matches (in nsILoginInfo aLoginInfo, in boolean ignorePassword); */
NS_IMETHODIMP nsLoginInfo::Matches(nsILoginInfo *aLoginInfo, bool ignorePassword, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsILoginInfo clone (); */
NS_IMETHODIMP nsLoginInfo::Clone(nsILoginInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define NS_LOGININFO_CONTRACTID "@mozilla.org/login-manager/loginInfo;1"

#endif /* __gen_nsILoginInfo_h__ */

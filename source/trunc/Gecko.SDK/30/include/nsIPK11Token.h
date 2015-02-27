/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPK11Token.idl
 */

#ifndef __gen_nsIPK11Token_h__
#define __gen_nsIPK11Token_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPK11Token */
#define NS_IPK11TOKEN_IID_STR "51191434-1dd2-11b2-a17c-e49c4e99a4e3"

#define NS_IPK11TOKEN_IID \
  {0x51191434, 0x1dd2, 0x11b2, \
    { 0xa1, 0x7c, 0xe4, 0x9c, 0x4e, 0x99, 0xa4, 0xe3 }}

class NS_NO_VTABLE nsIPK11Token : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPK11TOKEN_IID)

  enum {
    ASK_EVERY_TIME = -1,
    ASK_FIRST_TIME = 0,
    ASK_EXPIRE_TIME = 1
  };

  /* readonly attribute wstring tokenName; */
  NS_IMETHOD GetTokenName(char16_t * *aTokenName) = 0;

  /* readonly attribute wstring tokenLabel; */
  NS_IMETHOD GetTokenLabel(char16_t * *aTokenLabel) = 0;

  /* readonly attribute wstring tokenManID; */
  NS_IMETHOD GetTokenManID(char16_t * *aTokenManID) = 0;

  /* readonly attribute wstring tokenHWVersion; */
  NS_IMETHOD GetTokenHWVersion(char16_t * *aTokenHWVersion) = 0;

  /* readonly attribute wstring tokenFWVersion; */
  NS_IMETHOD GetTokenFWVersion(char16_t * *aTokenFWVersion) = 0;

  /* readonly attribute wstring tokenSerialNumber; */
  NS_IMETHOD GetTokenSerialNumber(char16_t * *aTokenSerialNumber) = 0;

  /* boolean isLoggedIn (); */
  NS_IMETHOD IsLoggedIn(bool *_retval) = 0;

  /* void login (in boolean force); */
  NS_IMETHOD Login(bool force) = 0;

  /* void logoutSimple (); */
  NS_IMETHOD LogoutSimple(void) = 0;

  /* void logoutAndDropAuthenticatedResources (); */
  NS_IMETHOD LogoutAndDropAuthenticatedResources(void) = 0;

  /* void reset (); */
  NS_IMETHOD Reset(void) = 0;

  /* readonly attribute long minimumPasswordLength; */
  NS_IMETHOD GetMinimumPasswordLength(int32_t *aMinimumPasswordLength) = 0;

  /* readonly attribute boolean needsUserInit; */
  NS_IMETHOD GetNeedsUserInit(bool *aNeedsUserInit) = 0;

  /* boolean checkPassword (in wstring password); */
  NS_IMETHOD CheckPassword(const char16_t * password, bool *_retval) = 0;

  /* void initPassword (in wstring initialPassword); */
  NS_IMETHOD InitPassword(const char16_t * initialPassword) = 0;

  /* void changePassword (in wstring oldPassword, in wstring newPassword); */
  NS_IMETHOD ChangePassword(const char16_t * oldPassword, const char16_t * newPassword) = 0;

  /* long getAskPasswordTimes (); */
  NS_IMETHOD GetAskPasswordTimes(int32_t *_retval) = 0;

  /* long getAskPasswordTimeout (); */
  NS_IMETHOD GetAskPasswordTimeout(int32_t *_retval) = 0;

  /* void setAskPasswordDefaults ([const] in long askTimes, [const] in long timeout); */
  NS_IMETHOD SetAskPasswordDefaults(const int32_t askTimes, const int32_t timeout) = 0;

  /* boolean isHardwareToken (); */
  NS_IMETHOD IsHardwareToken(bool *_retval) = 0;

  /* boolean needsLogin (); */
  NS_IMETHOD NeedsLogin(bool *_retval) = 0;

  /* boolean isFriendly (); */
  NS_IMETHOD IsFriendly(bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPK11Token, NS_IPK11TOKEN_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPK11TOKEN \
  NS_IMETHOD GetTokenName(char16_t * *aTokenName); \
  NS_IMETHOD GetTokenLabel(char16_t * *aTokenLabel); \
  NS_IMETHOD GetTokenManID(char16_t * *aTokenManID); \
  NS_IMETHOD GetTokenHWVersion(char16_t * *aTokenHWVersion); \
  NS_IMETHOD GetTokenFWVersion(char16_t * *aTokenFWVersion); \
  NS_IMETHOD GetTokenSerialNumber(char16_t * *aTokenSerialNumber); \
  NS_IMETHOD IsLoggedIn(bool *_retval); \
  NS_IMETHOD Login(bool force); \
  NS_IMETHOD LogoutSimple(void); \
  NS_IMETHOD LogoutAndDropAuthenticatedResources(void); \
  NS_IMETHOD Reset(void); \
  NS_IMETHOD GetMinimumPasswordLength(int32_t *aMinimumPasswordLength); \
  NS_IMETHOD GetNeedsUserInit(bool *aNeedsUserInit); \
  NS_IMETHOD CheckPassword(const char16_t * password, bool *_retval); \
  NS_IMETHOD InitPassword(const char16_t * initialPassword); \
  NS_IMETHOD ChangePassword(const char16_t * oldPassword, const char16_t * newPassword); \
  NS_IMETHOD GetAskPasswordTimes(int32_t *_retval); \
  NS_IMETHOD GetAskPasswordTimeout(int32_t *_retval); \
  NS_IMETHOD SetAskPasswordDefaults(const int32_t askTimes, const int32_t timeout); \
  NS_IMETHOD IsHardwareToken(bool *_retval); \
  NS_IMETHOD NeedsLogin(bool *_retval); \
  NS_IMETHOD IsFriendly(bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPK11TOKEN(_to) \
  NS_IMETHOD GetTokenName(char16_t * *aTokenName) { return _to GetTokenName(aTokenName); } \
  NS_IMETHOD GetTokenLabel(char16_t * *aTokenLabel) { return _to GetTokenLabel(aTokenLabel); } \
  NS_IMETHOD GetTokenManID(char16_t * *aTokenManID) { return _to GetTokenManID(aTokenManID); } \
  NS_IMETHOD GetTokenHWVersion(char16_t * *aTokenHWVersion) { return _to GetTokenHWVersion(aTokenHWVersion); } \
  NS_IMETHOD GetTokenFWVersion(char16_t * *aTokenFWVersion) { return _to GetTokenFWVersion(aTokenFWVersion); } \
  NS_IMETHOD GetTokenSerialNumber(char16_t * *aTokenSerialNumber) { return _to GetTokenSerialNumber(aTokenSerialNumber); } \
  NS_IMETHOD IsLoggedIn(bool *_retval) { return _to IsLoggedIn(_retval); } \
  NS_IMETHOD Login(bool force) { return _to Login(force); } \
  NS_IMETHOD LogoutSimple(void) { return _to LogoutSimple(); } \
  NS_IMETHOD LogoutAndDropAuthenticatedResources(void) { return _to LogoutAndDropAuthenticatedResources(); } \
  NS_IMETHOD Reset(void) { return _to Reset(); } \
  NS_IMETHOD GetMinimumPasswordLength(int32_t *aMinimumPasswordLength) { return _to GetMinimumPasswordLength(aMinimumPasswordLength); } \
  NS_IMETHOD GetNeedsUserInit(bool *aNeedsUserInit) { return _to GetNeedsUserInit(aNeedsUserInit); } \
  NS_IMETHOD CheckPassword(const char16_t * password, bool *_retval) { return _to CheckPassword(password, _retval); } \
  NS_IMETHOD InitPassword(const char16_t * initialPassword) { return _to InitPassword(initialPassword); } \
  NS_IMETHOD ChangePassword(const char16_t * oldPassword, const char16_t * newPassword) { return _to ChangePassword(oldPassword, newPassword); } \
  NS_IMETHOD GetAskPasswordTimes(int32_t *_retval) { return _to GetAskPasswordTimes(_retval); } \
  NS_IMETHOD GetAskPasswordTimeout(int32_t *_retval) { return _to GetAskPasswordTimeout(_retval); } \
  NS_IMETHOD SetAskPasswordDefaults(const int32_t askTimes, const int32_t timeout) { return _to SetAskPasswordDefaults(askTimes, timeout); } \
  NS_IMETHOD IsHardwareToken(bool *_retval) { return _to IsHardwareToken(_retval); } \
  NS_IMETHOD NeedsLogin(bool *_retval) { return _to NeedsLogin(_retval); } \
  NS_IMETHOD IsFriendly(bool *_retval) { return _to IsFriendly(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPK11TOKEN(_to) \
  NS_IMETHOD GetTokenName(char16_t * *aTokenName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTokenName(aTokenName); } \
  NS_IMETHOD GetTokenLabel(char16_t * *aTokenLabel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTokenLabel(aTokenLabel); } \
  NS_IMETHOD GetTokenManID(char16_t * *aTokenManID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTokenManID(aTokenManID); } \
  NS_IMETHOD GetTokenHWVersion(char16_t * *aTokenHWVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTokenHWVersion(aTokenHWVersion); } \
  NS_IMETHOD GetTokenFWVersion(char16_t * *aTokenFWVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTokenFWVersion(aTokenFWVersion); } \
  NS_IMETHOD GetTokenSerialNumber(char16_t * *aTokenSerialNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTokenSerialNumber(aTokenSerialNumber); } \
  NS_IMETHOD IsLoggedIn(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsLoggedIn(_retval); } \
  NS_IMETHOD Login(bool force) { return !_to ? NS_ERROR_NULL_POINTER : _to->Login(force); } \
  NS_IMETHOD LogoutSimple(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->LogoutSimple(); } \
  NS_IMETHOD LogoutAndDropAuthenticatedResources(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->LogoutAndDropAuthenticatedResources(); } \
  NS_IMETHOD Reset(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Reset(); } \
  NS_IMETHOD GetMinimumPasswordLength(int32_t *aMinimumPasswordLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMinimumPasswordLength(aMinimumPasswordLength); } \
  NS_IMETHOD GetNeedsUserInit(bool *aNeedsUserInit) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNeedsUserInit(aNeedsUserInit); } \
  NS_IMETHOD CheckPassword(const char16_t * password, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckPassword(password, _retval); } \
  NS_IMETHOD InitPassword(const char16_t * initialPassword) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitPassword(initialPassword); } \
  NS_IMETHOD ChangePassword(const char16_t * oldPassword, const char16_t * newPassword) { return !_to ? NS_ERROR_NULL_POINTER : _to->ChangePassword(oldPassword, newPassword); } \
  NS_IMETHOD GetAskPasswordTimes(int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAskPasswordTimes(_retval); } \
  NS_IMETHOD GetAskPasswordTimeout(int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAskPasswordTimeout(_retval); } \
  NS_IMETHOD SetAskPasswordDefaults(const int32_t askTimes, const int32_t timeout) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAskPasswordDefaults(askTimes, timeout); } \
  NS_IMETHOD IsHardwareToken(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsHardwareToken(_retval); } \
  NS_IMETHOD NeedsLogin(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NeedsLogin(_retval); } \
  NS_IMETHOD IsFriendly(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsFriendly(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPK11Token : public nsIPK11Token
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPK11TOKEN

  nsPK11Token();

private:
  ~nsPK11Token();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPK11Token, nsIPK11Token)

nsPK11Token::nsPK11Token()
{
  /* member initializers and constructor code */
}

nsPK11Token::~nsPK11Token()
{
  /* destructor code */
}

/* readonly attribute wstring tokenName; */
NS_IMETHODIMP nsPK11Token::GetTokenName(char16_t * *aTokenName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring tokenLabel; */
NS_IMETHODIMP nsPK11Token::GetTokenLabel(char16_t * *aTokenLabel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring tokenManID; */
NS_IMETHODIMP nsPK11Token::GetTokenManID(char16_t * *aTokenManID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring tokenHWVersion; */
NS_IMETHODIMP nsPK11Token::GetTokenHWVersion(char16_t * *aTokenHWVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring tokenFWVersion; */
NS_IMETHODIMP nsPK11Token::GetTokenFWVersion(char16_t * *aTokenFWVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring tokenSerialNumber; */
NS_IMETHODIMP nsPK11Token::GetTokenSerialNumber(char16_t * *aTokenSerialNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isLoggedIn (); */
NS_IMETHODIMP nsPK11Token::IsLoggedIn(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void login (in boolean force); */
NS_IMETHODIMP nsPK11Token::Login(bool force)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void logoutSimple (); */
NS_IMETHODIMP nsPK11Token::LogoutSimple()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void logoutAndDropAuthenticatedResources (); */
NS_IMETHODIMP nsPK11Token::LogoutAndDropAuthenticatedResources()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reset (); */
NS_IMETHODIMP nsPK11Token::Reset()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long minimumPasswordLength; */
NS_IMETHODIMP nsPK11Token::GetMinimumPasswordLength(int32_t *aMinimumPasswordLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean needsUserInit; */
NS_IMETHODIMP nsPK11Token::GetNeedsUserInit(bool *aNeedsUserInit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean checkPassword (in wstring password); */
NS_IMETHODIMP nsPK11Token::CheckPassword(const char16_t * password, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initPassword (in wstring initialPassword); */
NS_IMETHODIMP nsPK11Token::InitPassword(const char16_t * initialPassword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void changePassword (in wstring oldPassword, in wstring newPassword); */
NS_IMETHODIMP nsPK11Token::ChangePassword(const char16_t * oldPassword, const char16_t * newPassword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getAskPasswordTimes (); */
NS_IMETHODIMP nsPK11Token::GetAskPasswordTimes(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getAskPasswordTimeout (); */
NS_IMETHODIMP nsPK11Token::GetAskPasswordTimeout(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAskPasswordDefaults ([const] in long askTimes, [const] in long timeout); */
NS_IMETHODIMP nsPK11Token::SetAskPasswordDefaults(const int32_t askTimes, const int32_t timeout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isHardwareToken (); */
NS_IMETHODIMP nsPK11Token::IsHardwareToken(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean needsLogin (); */
NS_IMETHODIMP nsPK11Token::NeedsLogin(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isFriendly (); */
NS_IMETHODIMP nsPK11Token::IsFriendly(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPK11Token_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIHttpAuthManager.idl
 */

#ifndef __gen_nsIHttpAuthManager_h__
#define __gen_nsIHttpAuthManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPrincipal; /* forward declaration */


/* starting interface:    nsIHttpAuthManager */
#define NS_IHTTPAUTHMANAGER_IID_STR "54f90444-c52b-4d2d-8916-c59a2bb25938"

#define NS_IHTTPAUTHMANAGER_IID \
  {0x54f90444, 0xc52b, 0x4d2d, \
    { 0x89, 0x16, 0xc5, 0x9a, 0x2b, 0xb2, 0x59, 0x38 }}

class NS_NO_VTABLE nsIHttpAuthManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPAUTHMANAGER_IID)

  /* void getAuthIdentity (in ACString aScheme, in ACString aHost, in int32_t aPort, in ACString aAuthType, in ACString aRealm, in ACString aPath, out AString aUserDomain, out AString aUserName, out AString aUserPassword, [optional] in bool aIsPrivate, [optional] in nsIPrincipal aPrincipal); */
  NS_IMETHOD GetAuthIdentity(const nsACString & aScheme, const nsACString & aHost, int32_t aPort, const nsACString & aAuthType, const nsACString & aRealm, const nsACString & aPath, nsAString & aUserDomain, nsAString & aUserName, nsAString & aUserPassword, bool aIsPrivate, nsIPrincipal *aPrincipal) = 0;

  /* void setAuthIdentity (in ACString aScheme, in ACString aHost, in int32_t aPort, in ACString aAuthType, in ACString aRealm, in ACString aPath, in AString aUserDomain, in AString aUserName, in AString aUserPassword, [optional] in boolean aIsPrivate, [optional] in nsIPrincipal aPrincipal); */
  NS_IMETHOD SetAuthIdentity(const nsACString & aScheme, const nsACString & aHost, int32_t aPort, const nsACString & aAuthType, const nsACString & aRealm, const nsACString & aPath, const nsAString & aUserDomain, const nsAString & aUserName, const nsAString & aUserPassword, bool aIsPrivate, nsIPrincipal *aPrincipal) = 0;

  /* void clearAll (); */
  NS_IMETHOD ClearAll(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpAuthManager, NS_IHTTPAUTHMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPAUTHMANAGER \
  NS_IMETHOD GetAuthIdentity(const nsACString & aScheme, const nsACString & aHost, int32_t aPort, const nsACString & aAuthType, const nsACString & aRealm, const nsACString & aPath, nsAString & aUserDomain, nsAString & aUserName, nsAString & aUserPassword, bool aIsPrivate, nsIPrincipal *aPrincipal); \
  NS_IMETHOD SetAuthIdentity(const nsACString & aScheme, const nsACString & aHost, int32_t aPort, const nsACString & aAuthType, const nsACString & aRealm, const nsACString & aPath, const nsAString & aUserDomain, const nsAString & aUserName, const nsAString & aUserPassword, bool aIsPrivate, nsIPrincipal *aPrincipal); \
  NS_IMETHOD ClearAll(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPAUTHMANAGER(_to) \
  NS_IMETHOD GetAuthIdentity(const nsACString & aScheme, const nsACString & aHost, int32_t aPort, const nsACString & aAuthType, const nsACString & aRealm, const nsACString & aPath, nsAString & aUserDomain, nsAString & aUserName, nsAString & aUserPassword, bool aIsPrivate, nsIPrincipal *aPrincipal) { return _to GetAuthIdentity(aScheme, aHost, aPort, aAuthType, aRealm, aPath, aUserDomain, aUserName, aUserPassword, aIsPrivate, aPrincipal); } \
  NS_IMETHOD SetAuthIdentity(const nsACString & aScheme, const nsACString & aHost, int32_t aPort, const nsACString & aAuthType, const nsACString & aRealm, const nsACString & aPath, const nsAString & aUserDomain, const nsAString & aUserName, const nsAString & aUserPassword, bool aIsPrivate, nsIPrincipal *aPrincipal) { return _to SetAuthIdentity(aScheme, aHost, aPort, aAuthType, aRealm, aPath, aUserDomain, aUserName, aUserPassword, aIsPrivate, aPrincipal); } \
  NS_IMETHOD ClearAll(void) { return _to ClearAll(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPAUTHMANAGER(_to) \
  NS_IMETHOD GetAuthIdentity(const nsACString & aScheme, const nsACString & aHost, int32_t aPort, const nsACString & aAuthType, const nsACString & aRealm, const nsACString & aPath, nsAString & aUserDomain, nsAString & aUserName, nsAString & aUserPassword, bool aIsPrivate, nsIPrincipal *aPrincipal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAuthIdentity(aScheme, aHost, aPort, aAuthType, aRealm, aPath, aUserDomain, aUserName, aUserPassword, aIsPrivate, aPrincipal); } \
  NS_IMETHOD SetAuthIdentity(const nsACString & aScheme, const nsACString & aHost, int32_t aPort, const nsACString & aAuthType, const nsACString & aRealm, const nsACString & aPath, const nsAString & aUserDomain, const nsAString & aUserName, const nsAString & aUserPassword, bool aIsPrivate, nsIPrincipal *aPrincipal) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAuthIdentity(aScheme, aHost, aPort, aAuthType, aRealm, aPath, aUserDomain, aUserName, aUserPassword, aIsPrivate, aPrincipal); } \
  NS_IMETHOD ClearAll(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearAll(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpAuthManager : public nsIHttpAuthManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPAUTHMANAGER

  nsHttpAuthManager();

private:
  ~nsHttpAuthManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHttpAuthManager, nsIHttpAuthManager)

nsHttpAuthManager::nsHttpAuthManager()
{
  /* member initializers and constructor code */
}

nsHttpAuthManager::~nsHttpAuthManager()
{
  /* destructor code */
}

/* void getAuthIdentity (in ACString aScheme, in ACString aHost, in int32_t aPort, in ACString aAuthType, in ACString aRealm, in ACString aPath, out AString aUserDomain, out AString aUserName, out AString aUserPassword, [optional] in bool aIsPrivate, [optional] in nsIPrincipal aPrincipal); */
NS_IMETHODIMP nsHttpAuthManager::GetAuthIdentity(const nsACString & aScheme, const nsACString & aHost, int32_t aPort, const nsACString & aAuthType, const nsACString & aRealm, const nsACString & aPath, nsAString & aUserDomain, nsAString & aUserName, nsAString & aUserPassword, bool aIsPrivate, nsIPrincipal *aPrincipal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAuthIdentity (in ACString aScheme, in ACString aHost, in int32_t aPort, in ACString aAuthType, in ACString aRealm, in ACString aPath, in AString aUserDomain, in AString aUserName, in AString aUserPassword, [optional] in boolean aIsPrivate, [optional] in nsIPrincipal aPrincipal); */
NS_IMETHODIMP nsHttpAuthManager::SetAuthIdentity(const nsACString & aScheme, const nsACString & aHost, int32_t aPort, const nsACString & aAuthType, const nsACString & aRealm, const nsACString & aPath, const nsAString & aUserDomain, const nsAString & aUserName, const nsAString & aUserPassword, bool aIsPrivate, nsIPrincipal *aPrincipal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearAll (); */
NS_IMETHODIMP nsHttpAuthManager::ClearAll()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHttpAuthManager_h__ */

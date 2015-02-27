/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPermissionManager.idl
 */

#ifndef __gen_nsIPermissionManager_h__
#define __gen_nsIPermissionManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIObserver; /* forward declaration */

class nsIPrincipal; /* forward declaration */

class nsIDOMWindow; /* forward declaration */

class nsIPermission; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */


/* starting interface:    nsIPermissionManager */
#define NS_IPERMISSIONMANAGER_IID_STR "c9fec678-f194-43c9-96b0-7bd9dbdd6bb0"

#define NS_IPERMISSIONMANAGER_IID \
  {0xc9fec678, 0xf194, 0x43c9, \
    { 0x96, 0xb0, 0x7b, 0xd9, 0xdb, 0xdd, 0x6b, 0xb0 }}

class NS_NO_VTABLE nsIPermissionManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPERMISSIONMANAGER_IID)

  enum {
    UNKNOWN_ACTION = 0U,
    ALLOW_ACTION = 1U,
    DENY_ACTION = 2U,
    PROMPT_ACTION = 3U,
    EXPIRE_NEVER = 0U,
    EXPIRE_SESSION = 1U,
    EXPIRE_TIME = 2U
  };

  /* void add (in nsIURI uri, in string type, in uint32_t permission, [optional] in uint32_t expireType, [optional] in int64_t expireTime); */
  NS_IMETHOD Add(nsIURI *uri, const char * type, uint32_t permission, uint32_t expireType, int64_t expireTime) = 0;

  /* void addFromPrincipal (in nsIPrincipal principal, in string typed, in uint32_t permission, [optional] in uint32_t expireType, [optional] in int64_t expireTime); */
  NS_IMETHOD AddFromPrincipal(nsIPrincipal *principal, const char * typed, uint32_t permission, uint32_t expireType, int64_t expireTime) = 0;

  /* void remove (in AUTF8String host, in string type); */
  NS_IMETHOD Remove(const nsACString & host, const char * type) = 0;

  /* void removeFromPrincipal (in nsIPrincipal principal, in string type); */
  NS_IMETHOD RemoveFromPrincipal(nsIPrincipal *principal, const char * type) = 0;

  /* void removeAll (); */
  NS_IMETHOD RemoveAll(void) = 0;

  /* uint32_t testPermission (in nsIURI uri, in string type); */
  NS_IMETHOD TestPermission(nsIURI *uri, const char * type, uint32_t *_retval) = 0;

  /* uint32_t testPermissionFromPrincipal (in nsIPrincipal principal, in string type); */
  NS_IMETHOD TestPermissionFromPrincipal(nsIPrincipal *principal, const char * type, uint32_t *_retval) = 0;

  /* uint32_t testPermissionFromWindow (in nsIDOMWindow window, in string type); */
  NS_IMETHOD TestPermissionFromWindow(nsIDOMWindow *window, const char * type, uint32_t *_retval) = 0;

  /* uint32_t testExactPermission (in nsIURI uri, in string type); */
  NS_IMETHOD TestExactPermission(nsIURI *uri, const char * type, uint32_t *_retval) = 0;

  /* uint32_t testExactPermissionFromPrincipal (in nsIPrincipal principal, in string type); */
  NS_IMETHOD TestExactPermissionFromPrincipal(nsIPrincipal *principal, const char * type, uint32_t *_retval) = 0;

  /* uint32_t testExactPermanentPermission (in nsIPrincipal principal, in string type); */
  NS_IMETHOD TestExactPermanentPermission(nsIPrincipal *principal, const char * type, uint32_t *_retval) = 0;

  /* nsIPermission getPermissionObject (in nsIPrincipal principal, in string type, in boolean exactHost); */
  NS_IMETHOD GetPermissionObject(nsIPrincipal *principal, const char * type, bool exactHost, nsIPermission * *_retval) = 0;

  /* void addrefAppId (in unsigned long appId); */
  NS_IMETHOD AddrefAppId(uint32_t appId) = 0;

  /* void releaseAppId (in unsigned long appId); */
  NS_IMETHOD ReleaseAppId(uint32_t appId) = 0;

  /* readonly attribute nsISimpleEnumerator enumerator; */
  NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *aEnumerator) = 0;

  /* void removePermissionsForApp (in unsigned long appId, in boolean browserOnly); */
  NS_IMETHOD RemovePermissionsForApp(uint32_t appId, bool browserOnly) = 0;

  /* void updateExpireTime (in nsIPrincipal principal, in string type, in boolean exactHost, in uint64_t sessionExpireTime, in uint64_t persistentExpireTime); */
  NS_IMETHOD UpdateExpireTime(nsIPrincipal *principal, const char * type, bool exactHost, uint64_t sessionExpireTime, uint64_t persistentExpireTime) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPermissionManager, NS_IPERMISSIONMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPERMISSIONMANAGER \
  NS_IMETHOD Add(nsIURI *uri, const char * type, uint32_t permission, uint32_t expireType, int64_t expireTime); \
  NS_IMETHOD AddFromPrincipal(nsIPrincipal *principal, const char * typed, uint32_t permission, uint32_t expireType, int64_t expireTime); \
  NS_IMETHOD Remove(const nsACString & host, const char * type); \
  NS_IMETHOD RemoveFromPrincipal(nsIPrincipal *principal, const char * type); \
  NS_IMETHOD RemoveAll(void); \
  NS_IMETHOD TestPermission(nsIURI *uri, const char * type, uint32_t *_retval); \
  NS_IMETHOD TestPermissionFromPrincipal(nsIPrincipal *principal, const char * type, uint32_t *_retval); \
  NS_IMETHOD TestPermissionFromWindow(nsIDOMWindow *window, const char * type, uint32_t *_retval); \
  NS_IMETHOD TestExactPermission(nsIURI *uri, const char * type, uint32_t *_retval); \
  NS_IMETHOD TestExactPermissionFromPrincipal(nsIPrincipal *principal, const char * type, uint32_t *_retval); \
  NS_IMETHOD TestExactPermanentPermission(nsIPrincipal *principal, const char * type, uint32_t *_retval); \
  NS_IMETHOD GetPermissionObject(nsIPrincipal *principal, const char * type, bool exactHost, nsIPermission * *_retval); \
  NS_IMETHOD AddrefAppId(uint32_t appId); \
  NS_IMETHOD ReleaseAppId(uint32_t appId); \
  NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *aEnumerator); \
  NS_IMETHOD RemovePermissionsForApp(uint32_t appId, bool browserOnly); \
  NS_IMETHOD UpdateExpireTime(nsIPrincipal *principal, const char * type, bool exactHost, uint64_t sessionExpireTime, uint64_t persistentExpireTime); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPERMISSIONMANAGER(_to) \
  NS_IMETHOD Add(nsIURI *uri, const char * type, uint32_t permission, uint32_t expireType, int64_t expireTime) { return _to Add(uri, type, permission, expireType, expireTime); } \
  NS_IMETHOD AddFromPrincipal(nsIPrincipal *principal, const char * typed, uint32_t permission, uint32_t expireType, int64_t expireTime) { return _to AddFromPrincipal(principal, typed, permission, expireType, expireTime); } \
  NS_IMETHOD Remove(const nsACString & host, const char * type) { return _to Remove(host, type); } \
  NS_IMETHOD RemoveFromPrincipal(nsIPrincipal *principal, const char * type) { return _to RemoveFromPrincipal(principal, type); } \
  NS_IMETHOD RemoveAll(void) { return _to RemoveAll(); } \
  NS_IMETHOD TestPermission(nsIURI *uri, const char * type, uint32_t *_retval) { return _to TestPermission(uri, type, _retval); } \
  NS_IMETHOD TestPermissionFromPrincipal(nsIPrincipal *principal, const char * type, uint32_t *_retval) { return _to TestPermissionFromPrincipal(principal, type, _retval); } \
  NS_IMETHOD TestPermissionFromWindow(nsIDOMWindow *window, const char * type, uint32_t *_retval) { return _to TestPermissionFromWindow(window, type, _retval); } \
  NS_IMETHOD TestExactPermission(nsIURI *uri, const char * type, uint32_t *_retval) { return _to TestExactPermission(uri, type, _retval); } \
  NS_IMETHOD TestExactPermissionFromPrincipal(nsIPrincipal *principal, const char * type, uint32_t *_retval) { return _to TestExactPermissionFromPrincipal(principal, type, _retval); } \
  NS_IMETHOD TestExactPermanentPermission(nsIPrincipal *principal, const char * type, uint32_t *_retval) { return _to TestExactPermanentPermission(principal, type, _retval); } \
  NS_IMETHOD GetPermissionObject(nsIPrincipal *principal, const char * type, bool exactHost, nsIPermission * *_retval) { return _to GetPermissionObject(principal, type, exactHost, _retval); } \
  NS_IMETHOD AddrefAppId(uint32_t appId) { return _to AddrefAppId(appId); } \
  NS_IMETHOD ReleaseAppId(uint32_t appId) { return _to ReleaseAppId(appId); } \
  NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *aEnumerator) { return _to GetEnumerator(aEnumerator); } \
  NS_IMETHOD RemovePermissionsForApp(uint32_t appId, bool browserOnly) { return _to RemovePermissionsForApp(appId, browserOnly); } \
  NS_IMETHOD UpdateExpireTime(nsIPrincipal *principal, const char * type, bool exactHost, uint64_t sessionExpireTime, uint64_t persistentExpireTime) { return _to UpdateExpireTime(principal, type, exactHost, sessionExpireTime, persistentExpireTime); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPERMISSIONMANAGER(_to) \
  NS_IMETHOD Add(nsIURI *uri, const char * type, uint32_t permission, uint32_t expireType, int64_t expireTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(uri, type, permission, expireType, expireTime); } \
  NS_IMETHOD AddFromPrincipal(nsIPrincipal *principal, const char * typed, uint32_t permission, uint32_t expireType, int64_t expireTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddFromPrincipal(principal, typed, permission, expireType, expireTime); } \
  NS_IMETHOD Remove(const nsACString & host, const char * type) { return !_to ? NS_ERROR_NULL_POINTER : _to->Remove(host, type); } \
  NS_IMETHOD RemoveFromPrincipal(nsIPrincipal *principal, const char * type) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveFromPrincipal(principal, type); } \
  NS_IMETHOD RemoveAll(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAll(); } \
  NS_IMETHOD TestPermission(nsIURI *uri, const char * type, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestPermission(uri, type, _retval); } \
  NS_IMETHOD TestPermissionFromPrincipal(nsIPrincipal *principal, const char * type, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestPermissionFromPrincipal(principal, type, _retval); } \
  NS_IMETHOD TestPermissionFromWindow(nsIDOMWindow *window, const char * type, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestPermissionFromWindow(window, type, _retval); } \
  NS_IMETHOD TestExactPermission(nsIURI *uri, const char * type, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestExactPermission(uri, type, _retval); } \
  NS_IMETHOD TestExactPermissionFromPrincipal(nsIPrincipal *principal, const char * type, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestExactPermissionFromPrincipal(principal, type, _retval); } \
  NS_IMETHOD TestExactPermanentPermission(nsIPrincipal *principal, const char * type, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestExactPermanentPermission(principal, type, _retval); } \
  NS_IMETHOD GetPermissionObject(nsIPrincipal *principal, const char * type, bool exactHost, nsIPermission * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPermissionObject(principal, type, exactHost, _retval); } \
  NS_IMETHOD AddrefAppId(uint32_t appId) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddrefAppId(appId); } \
  NS_IMETHOD ReleaseAppId(uint32_t appId) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReleaseAppId(appId); } \
  NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *aEnumerator) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnumerator(aEnumerator); } \
  NS_IMETHOD RemovePermissionsForApp(uint32_t appId, bool browserOnly) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePermissionsForApp(appId, browserOnly); } \
  NS_IMETHOD UpdateExpireTime(nsIPrincipal *principal, const char * type, bool exactHost, uint64_t sessionExpireTime, uint64_t persistentExpireTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateExpireTime(principal, type, exactHost, sessionExpireTime, persistentExpireTime); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPermissionManager : public nsIPermissionManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPERMISSIONMANAGER

  nsPermissionManager();

private:
  ~nsPermissionManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPermissionManager, nsIPermissionManager)

nsPermissionManager::nsPermissionManager()
{
  /* member initializers and constructor code */
}

nsPermissionManager::~nsPermissionManager()
{
  /* destructor code */
}

/* void add (in nsIURI uri, in string type, in uint32_t permission, [optional] in uint32_t expireType, [optional] in int64_t expireTime); */
NS_IMETHODIMP nsPermissionManager::Add(nsIURI *uri, const char * type, uint32_t permission, uint32_t expireType, int64_t expireTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addFromPrincipal (in nsIPrincipal principal, in string typed, in uint32_t permission, [optional] in uint32_t expireType, [optional] in int64_t expireTime); */
NS_IMETHODIMP nsPermissionManager::AddFromPrincipal(nsIPrincipal *principal, const char * typed, uint32_t permission, uint32_t expireType, int64_t expireTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void remove (in AUTF8String host, in string type); */
NS_IMETHODIMP nsPermissionManager::Remove(const nsACString & host, const char * type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeFromPrincipal (in nsIPrincipal principal, in string type); */
NS_IMETHODIMP nsPermissionManager::RemoveFromPrincipal(nsIPrincipal *principal, const char * type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAll (); */
NS_IMETHODIMP nsPermissionManager::RemoveAll()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* uint32_t testPermission (in nsIURI uri, in string type); */
NS_IMETHODIMP nsPermissionManager::TestPermission(nsIURI *uri, const char * type, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* uint32_t testPermissionFromPrincipal (in nsIPrincipal principal, in string type); */
NS_IMETHODIMP nsPermissionManager::TestPermissionFromPrincipal(nsIPrincipal *principal, const char * type, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* uint32_t testPermissionFromWindow (in nsIDOMWindow window, in string type); */
NS_IMETHODIMP nsPermissionManager::TestPermissionFromWindow(nsIDOMWindow *window, const char * type, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* uint32_t testExactPermission (in nsIURI uri, in string type); */
NS_IMETHODIMP nsPermissionManager::TestExactPermission(nsIURI *uri, const char * type, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* uint32_t testExactPermissionFromPrincipal (in nsIPrincipal principal, in string type); */
NS_IMETHODIMP nsPermissionManager::TestExactPermissionFromPrincipal(nsIPrincipal *principal, const char * type, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* uint32_t testExactPermanentPermission (in nsIPrincipal principal, in string type); */
NS_IMETHODIMP nsPermissionManager::TestExactPermanentPermission(nsIPrincipal *principal, const char * type, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPermission getPermissionObject (in nsIPrincipal principal, in string type, in boolean exactHost); */
NS_IMETHODIMP nsPermissionManager::GetPermissionObject(nsIPrincipal *principal, const char * type, bool exactHost, nsIPermission * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addrefAppId (in unsigned long appId); */
NS_IMETHODIMP nsPermissionManager::AddrefAppId(uint32_t appId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void releaseAppId (in unsigned long appId); */
NS_IMETHODIMP nsPermissionManager::ReleaseAppId(uint32_t appId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISimpleEnumerator enumerator; */
NS_IMETHODIMP nsPermissionManager::GetEnumerator(nsISimpleEnumerator * *aEnumerator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removePermissionsForApp (in unsigned long appId, in boolean browserOnly); */
NS_IMETHODIMP nsPermissionManager::RemovePermissionsForApp(uint32_t appId, bool browserOnly)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateExpireTime (in nsIPrincipal principal, in string type, in boolean exactHost, in uint64_t sessionExpireTime, in uint64_t persistentExpireTime); */
NS_IMETHODIMP nsPermissionManager::UpdateExpireTime(nsIPrincipal *principal, const char * type, bool exactHost, uint64_t sessionExpireTime, uint64_t persistentExpireTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_PERMISSIONMANAGER_CONTRACTID "@mozilla.org/permissionmanager;1"
#define PERM_CHANGE_NOTIFICATION "perm-changed"

#endif /* __gen_nsIPermissionManager_h__ */

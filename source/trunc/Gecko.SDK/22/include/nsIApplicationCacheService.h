/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIApplicationCacheService.idl
 */

#ifndef __gen_nsIApplicationCacheService_h__
#define __gen_nsIApplicationCacheService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIApplicationCache; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIURI; /* forward declaration */

class nsILoadContext; /* forward declaration */


/* starting interface:    nsIApplicationCacheService */
#define NS_IAPPLICATIONCACHESERVICE_IID_STR "9b5b2cde-d5dd-48d3-87f8-8e8b776952a8"

#define NS_IAPPLICATIONCACHESERVICE_IID \
  {0x9b5b2cde, 0xd5dd, 0x48d3, \
    { 0x87, 0xf8, 0x8e, 0x8b, 0x77, 0x69, 0x52, 0xa8 }}

class NS_NO_VTABLE nsIApplicationCacheService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPLICATIONCACHESERVICE_IID)

  /* ACString buildGroupID (in nsIURI aManifestURL, in nsILoadContext aLoadContext); */
  NS_IMETHOD BuildGroupID(nsIURI *aManifestURL, nsILoadContext *aLoadContext, nsACString & _retval) = 0;

  /* ACString buildGroupIDForApp (in nsIURI aManifestURL, in unsigned long aAppID, in boolean aInBrowser); */
  NS_IMETHOD BuildGroupIDForApp(nsIURI *aManifestURL, uint32_t aAppID, bool aInBrowser, nsACString & _retval) = 0;

  /* nsIApplicationCache createApplicationCache (in ACString group); */
  NS_IMETHOD CreateApplicationCache(const nsACString & group, nsIApplicationCache * *_retval) = 0;

  /* nsIApplicationCache createCustomApplicationCache (in ACString group, in nsIFile profileDir, in int32_t quota); */
  NS_IMETHOD CreateCustomApplicationCache(const nsACString & group, nsIFile *profileDir, int32_t quota, nsIApplicationCache * *_retval) = 0;

  /* nsIApplicationCache getApplicationCache (in ACString clientID); */
  NS_IMETHOD GetApplicationCache(const nsACString & clientID, nsIApplicationCache * *_retval) = 0;

  /* nsIApplicationCache getActiveCache (in ACString group); */
  NS_IMETHOD GetActiveCache(const nsACString & group, nsIApplicationCache * *_retval) = 0;

  /* void deactivateGroup (in ACString group); */
  NS_IMETHOD DeactivateGroup(const nsACString & group) = 0;

  /* void discardByAppId (in int32_t appID, in boolean discardOnlyBrowserEntries); */
  NS_IMETHOD DiscardByAppId(int32_t appID, bool discardOnlyBrowserEntries) = 0;

  /* nsIApplicationCache chooseApplicationCache (in ACString key, [optional] in nsILoadContext loadContext); */
  NS_IMETHOD ChooseApplicationCache(const nsACString & key, nsILoadContext *loadContext, nsIApplicationCache * *_retval) = 0;

  /* void cacheOpportunistically (in nsIApplicationCache cache, in ACString key); */
  NS_IMETHOD CacheOpportunistically(nsIApplicationCache *cache, const nsACString & key) = 0;

  /* void getGroups ([optional] out unsigned long count, [array, size_is (count), retval] out string groupIDs); */
  NS_IMETHOD GetGroups(uint32_t *count, char * **groupIDs) = 0;

  /* void getGroupsTimeOrdered ([optional] out unsigned long count, [array, size_is (count), retval] out string groupIDs); */
  NS_IMETHOD GetGroupsTimeOrdered(uint32_t *count, char * **groupIDs) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIApplicationCacheService, NS_IAPPLICATIONCACHESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPLICATIONCACHESERVICE \
  NS_IMETHOD BuildGroupID(nsIURI *aManifestURL, nsILoadContext *aLoadContext, nsACString & _retval); \
  NS_IMETHOD BuildGroupIDForApp(nsIURI *aManifestURL, uint32_t aAppID, bool aInBrowser, nsACString & _retval); \
  NS_IMETHOD CreateApplicationCache(const nsACString & group, nsIApplicationCache * *_retval); \
  NS_IMETHOD CreateCustomApplicationCache(const nsACString & group, nsIFile *profileDir, int32_t quota, nsIApplicationCache * *_retval); \
  NS_IMETHOD GetApplicationCache(const nsACString & clientID, nsIApplicationCache * *_retval); \
  NS_IMETHOD GetActiveCache(const nsACString & group, nsIApplicationCache * *_retval); \
  NS_IMETHOD DeactivateGroup(const nsACString & group); \
  NS_IMETHOD DiscardByAppId(int32_t appID, bool discardOnlyBrowserEntries); \
  NS_IMETHOD ChooseApplicationCache(const nsACString & key, nsILoadContext *loadContext, nsIApplicationCache * *_retval); \
  NS_IMETHOD CacheOpportunistically(nsIApplicationCache *cache, const nsACString & key); \
  NS_IMETHOD GetGroups(uint32_t *count, char * **groupIDs); \
  NS_IMETHOD GetGroupsTimeOrdered(uint32_t *count, char * **groupIDs); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPLICATIONCACHESERVICE(_to) \
  NS_IMETHOD BuildGroupID(nsIURI *aManifestURL, nsILoadContext *aLoadContext, nsACString & _retval) { return _to BuildGroupID(aManifestURL, aLoadContext, _retval); } \
  NS_IMETHOD BuildGroupIDForApp(nsIURI *aManifestURL, uint32_t aAppID, bool aInBrowser, nsACString & _retval) { return _to BuildGroupIDForApp(aManifestURL, aAppID, aInBrowser, _retval); } \
  NS_IMETHOD CreateApplicationCache(const nsACString & group, nsIApplicationCache * *_retval) { return _to CreateApplicationCache(group, _retval); } \
  NS_IMETHOD CreateCustomApplicationCache(const nsACString & group, nsIFile *profileDir, int32_t quota, nsIApplicationCache * *_retval) { return _to CreateCustomApplicationCache(group, profileDir, quota, _retval); } \
  NS_IMETHOD GetApplicationCache(const nsACString & clientID, nsIApplicationCache * *_retval) { return _to GetApplicationCache(clientID, _retval); } \
  NS_IMETHOD GetActiveCache(const nsACString & group, nsIApplicationCache * *_retval) { return _to GetActiveCache(group, _retval); } \
  NS_IMETHOD DeactivateGroup(const nsACString & group) { return _to DeactivateGroup(group); } \
  NS_IMETHOD DiscardByAppId(int32_t appID, bool discardOnlyBrowserEntries) { return _to DiscardByAppId(appID, discardOnlyBrowserEntries); } \
  NS_IMETHOD ChooseApplicationCache(const nsACString & key, nsILoadContext *loadContext, nsIApplicationCache * *_retval) { return _to ChooseApplicationCache(key, loadContext, _retval); } \
  NS_IMETHOD CacheOpportunistically(nsIApplicationCache *cache, const nsACString & key) { return _to CacheOpportunistically(cache, key); } \
  NS_IMETHOD GetGroups(uint32_t *count, char * **groupIDs) { return _to GetGroups(count, groupIDs); } \
  NS_IMETHOD GetGroupsTimeOrdered(uint32_t *count, char * **groupIDs) { return _to GetGroupsTimeOrdered(count, groupIDs); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPLICATIONCACHESERVICE(_to) \
  NS_IMETHOD BuildGroupID(nsIURI *aManifestURL, nsILoadContext *aLoadContext, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->BuildGroupID(aManifestURL, aLoadContext, _retval); } \
  NS_IMETHOD BuildGroupIDForApp(nsIURI *aManifestURL, uint32_t aAppID, bool aInBrowser, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->BuildGroupIDForApp(aManifestURL, aAppID, aInBrowser, _retval); } \
  NS_IMETHOD CreateApplicationCache(const nsACString & group, nsIApplicationCache * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateApplicationCache(group, _retval); } \
  NS_IMETHOD CreateCustomApplicationCache(const nsACString & group, nsIFile *profileDir, int32_t quota, nsIApplicationCache * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateCustomApplicationCache(group, profileDir, quota, _retval); } \
  NS_IMETHOD GetApplicationCache(const nsACString & clientID, nsIApplicationCache * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApplicationCache(clientID, _retval); } \
  NS_IMETHOD GetActiveCache(const nsACString & group, nsIApplicationCache * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActiveCache(group, _retval); } \
  NS_IMETHOD DeactivateGroup(const nsACString & group) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeactivateGroup(group); } \
  NS_IMETHOD DiscardByAppId(int32_t appID, bool discardOnlyBrowserEntries) { return !_to ? NS_ERROR_NULL_POINTER : _to->DiscardByAppId(appID, discardOnlyBrowserEntries); } \
  NS_IMETHOD ChooseApplicationCache(const nsACString & key, nsILoadContext *loadContext, nsIApplicationCache * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ChooseApplicationCache(key, loadContext, _retval); } \
  NS_IMETHOD CacheOpportunistically(nsIApplicationCache *cache, const nsACString & key) { return !_to ? NS_ERROR_NULL_POINTER : _to->CacheOpportunistically(cache, key); } \
  NS_IMETHOD GetGroups(uint32_t *count, char * **groupIDs) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGroups(count, groupIDs); } \
  NS_IMETHOD GetGroupsTimeOrdered(uint32_t *count, char * **groupIDs) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGroupsTimeOrdered(count, groupIDs); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsApplicationCacheService : public nsIApplicationCacheService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPLICATIONCACHESERVICE

  nsApplicationCacheService();

private:
  ~nsApplicationCacheService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsApplicationCacheService, nsIApplicationCacheService)

nsApplicationCacheService::nsApplicationCacheService()
{
  /* member initializers and constructor code */
}

nsApplicationCacheService::~nsApplicationCacheService()
{
  /* destructor code */
}

/* ACString buildGroupID (in nsIURI aManifestURL, in nsILoadContext aLoadContext); */
NS_IMETHODIMP nsApplicationCacheService::BuildGroupID(nsIURI *aManifestURL, nsILoadContext *aLoadContext, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString buildGroupIDForApp (in nsIURI aManifestURL, in unsigned long aAppID, in boolean aInBrowser); */
NS_IMETHODIMP nsApplicationCacheService::BuildGroupIDForApp(nsIURI *aManifestURL, uint32_t aAppID, bool aInBrowser, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIApplicationCache createApplicationCache (in ACString group); */
NS_IMETHODIMP nsApplicationCacheService::CreateApplicationCache(const nsACString & group, nsIApplicationCache * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIApplicationCache createCustomApplicationCache (in ACString group, in nsIFile profileDir, in int32_t quota); */
NS_IMETHODIMP nsApplicationCacheService::CreateCustomApplicationCache(const nsACString & group, nsIFile *profileDir, int32_t quota, nsIApplicationCache * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIApplicationCache getApplicationCache (in ACString clientID); */
NS_IMETHODIMP nsApplicationCacheService::GetApplicationCache(const nsACString & clientID, nsIApplicationCache * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIApplicationCache getActiveCache (in ACString group); */
NS_IMETHODIMP nsApplicationCacheService::GetActiveCache(const nsACString & group, nsIApplicationCache * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deactivateGroup (in ACString group); */
NS_IMETHODIMP nsApplicationCacheService::DeactivateGroup(const nsACString & group)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void discardByAppId (in int32_t appID, in boolean discardOnlyBrowserEntries); */
NS_IMETHODIMP nsApplicationCacheService::DiscardByAppId(int32_t appID, bool discardOnlyBrowserEntries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIApplicationCache chooseApplicationCache (in ACString key, [optional] in nsILoadContext loadContext); */
NS_IMETHODIMP nsApplicationCacheService::ChooseApplicationCache(const nsACString & key, nsILoadContext *loadContext, nsIApplicationCache * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cacheOpportunistically (in nsIApplicationCache cache, in ACString key); */
NS_IMETHODIMP nsApplicationCacheService::CacheOpportunistically(nsIApplicationCache *cache, const nsACString & key)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getGroups ([optional] out unsigned long count, [array, size_is (count), retval] out string groupIDs); */
NS_IMETHODIMP nsApplicationCacheService::GetGroups(uint32_t *count, char * **groupIDs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getGroupsTimeOrdered ([optional] out unsigned long count, [array, size_is (count), retval] out string groupIDs); */
NS_IMETHODIMP nsApplicationCacheService::GetGroupsTimeOrdered(uint32_t *count, char * **groupIDs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIApplicationCacheService_h__ */

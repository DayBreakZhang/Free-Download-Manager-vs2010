/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIApplicationCache.idl
 */

#ifndef __gen_nsIApplicationCache_h__
#define __gen_nsIApplicationCache_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIApplicationCacheNamespace */
#define NS_IAPPLICATIONCACHENAMESPACE_IID_STR "96e4c264-2065-4ce9-93bb-43734c62c4eb"

#define NS_IAPPLICATIONCACHENAMESPACE_IID \
  {0x96e4c264, 0x2065, 0x4ce9, \
    { 0x93, 0xbb, 0x43, 0x73, 0x4c, 0x62, 0xc4, 0xeb }}

class NS_NO_VTABLE nsIApplicationCacheNamespace : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPLICATIONCACHENAMESPACE_IID)

  enum {
    NAMESPACE_BYPASS = 1U,
    NAMESPACE_FALLBACK = 2U,
    NAMESPACE_OPPORTUNISTIC = 4U
  };

  /* void init (in unsigned long itemType, in ACString namespaceSpec, in ACString data); */
  NS_IMETHOD Init(uint32_t itemType, const nsACString & namespaceSpec, const nsACString & data) = 0;

  /* readonly attribute unsigned long itemType; */
  NS_IMETHOD GetItemType(uint32_t *aItemType) = 0;

  /* readonly attribute ACString namespaceSpec; */
  NS_IMETHOD GetNamespaceSpec(nsACString & aNamespaceSpec) = 0;

  /* readonly attribute ACString data; */
  NS_IMETHOD GetData(nsACString & aData) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIApplicationCacheNamespace, NS_IAPPLICATIONCACHENAMESPACE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPLICATIONCACHENAMESPACE \
  NS_IMETHOD Init(uint32_t itemType, const nsACString & namespaceSpec, const nsACString & data); \
  NS_IMETHOD GetItemType(uint32_t *aItemType); \
  NS_IMETHOD GetNamespaceSpec(nsACString & aNamespaceSpec); \
  NS_IMETHOD GetData(nsACString & aData); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPLICATIONCACHENAMESPACE(_to) \
  NS_IMETHOD Init(uint32_t itemType, const nsACString & namespaceSpec, const nsACString & data) { return _to Init(itemType, namespaceSpec, data); } \
  NS_IMETHOD GetItemType(uint32_t *aItemType) { return _to GetItemType(aItemType); } \
  NS_IMETHOD GetNamespaceSpec(nsACString & aNamespaceSpec) { return _to GetNamespaceSpec(aNamespaceSpec); } \
  NS_IMETHOD GetData(nsACString & aData) { return _to GetData(aData); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPLICATIONCACHENAMESPACE(_to) \
  NS_IMETHOD Init(uint32_t itemType, const nsACString & namespaceSpec, const nsACString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(itemType, namespaceSpec, data); } \
  NS_IMETHOD GetItemType(uint32_t *aItemType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemType(aItemType); } \
  NS_IMETHOD GetNamespaceSpec(nsACString & aNamespaceSpec) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNamespaceSpec(aNamespaceSpec); } \
  NS_IMETHOD GetData(nsACString & aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aData); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsApplicationCacheNamespace : public nsIApplicationCacheNamespace
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPLICATIONCACHENAMESPACE

  nsApplicationCacheNamespace();

private:
  ~nsApplicationCacheNamespace();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsApplicationCacheNamespace, nsIApplicationCacheNamespace)

nsApplicationCacheNamespace::nsApplicationCacheNamespace()
{
  /* member initializers and constructor code */
}

nsApplicationCacheNamespace::~nsApplicationCacheNamespace()
{
  /* destructor code */
}

/* void init (in unsigned long itemType, in ACString namespaceSpec, in ACString data); */
NS_IMETHODIMP nsApplicationCacheNamespace::Init(uint32_t itemType, const nsACString & namespaceSpec, const nsACString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long itemType; */
NS_IMETHODIMP nsApplicationCacheNamespace::GetItemType(uint32_t *aItemType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString namespaceSpec; */
NS_IMETHODIMP nsApplicationCacheNamespace::GetNamespaceSpec(nsACString & aNamespaceSpec)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString data; */
NS_IMETHODIMP nsApplicationCacheNamespace::GetData(nsACString & aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIApplicationCache */
#define NS_IAPPLICATIONCACHE_IID_STR "06568dae-c374-4383-a122-0cc96c7177f2"

#define NS_IAPPLICATIONCACHE_IID \
  {0x06568dae, 0xc374, 0x4383, \
    { 0xa1, 0x22, 0x0c, 0xc9, 0x6c, 0x71, 0x77, 0xf2 }}

class NS_NO_VTABLE nsIApplicationCache : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPLICATIONCACHE_IID)

  /* void initAsHandle (in ACString groupId, in ACString clientId); */
  NS_IMETHOD InitAsHandle(const nsACString & groupId, const nsACString & clientId) = 0;

  enum {
    ITEM_MANIFEST = 1U,
    ITEM_EXPLICIT = 2U,
    ITEM_IMPLICIT = 4U,
    ITEM_DYNAMIC = 8U,
    ITEM_FOREIGN = 16U,
    ITEM_FALLBACK = 32U,
    ITEM_OPPORTUNISTIC = 64U
  };

  /* readonly attribute nsIURI manifestURI; */
  NS_IMETHOD GetManifestURI(nsIURI * *aManifestURI) = 0;

  /* readonly attribute ACString groupID; */
  NS_IMETHOD GetGroupID(nsACString & aGroupID) = 0;

  /* readonly attribute ACString clientID; */
  NS_IMETHOD GetClientID(nsACString & aClientID) = 0;

  /* readonly attribute boolean active; */
  NS_IMETHOD GetActive(bool *aActive) = 0;

  /* readonly attribute unsigned long usage; */
  NS_IMETHOD GetUsage(uint32_t *aUsage) = 0;

  /* void activate (); */
  NS_IMETHOD Activate(void) = 0;

  /* void discard (); */
  NS_IMETHOD Discard(void) = 0;

  /* void markEntry (in ACString key, in unsigned long typeBits); */
  NS_IMETHOD MarkEntry(const nsACString & key, uint32_t typeBits) = 0;

  /* void unmarkEntry (in ACString key, in unsigned long typeBits); */
  NS_IMETHOD UnmarkEntry(const nsACString & key, uint32_t typeBits) = 0;

  /* unsigned long getTypes (in ACString key); */
  NS_IMETHOD GetTypes(const nsACString & key, uint32_t *_retval) = 0;

  /* void gatherEntries (in uint32_t typeBits, out unsigned long count, [array, size_is (count)] out string keys); */
  NS_IMETHOD GatherEntries(uint32_t typeBits, uint32_t *count, char * **keys) = 0;

  /* void addNamespaces (in nsIArray namespaces); */
  NS_IMETHOD AddNamespaces(nsIArray *namespaces) = 0;

  /* nsIApplicationCacheNamespace getMatchingNamespace (in ACString key); */
  NS_IMETHOD GetMatchingNamespace(const nsACString & key, nsIApplicationCacheNamespace * *_retval) = 0;

  /* readonly attribute nsIFile profileDirectory; */
  NS_IMETHOD GetProfileDirectory(nsIFile * *aProfileDirectory) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIApplicationCache, NS_IAPPLICATIONCACHE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPLICATIONCACHE \
  NS_IMETHOD InitAsHandle(const nsACString & groupId, const nsACString & clientId); \
  NS_IMETHOD GetManifestURI(nsIURI * *aManifestURI); \
  NS_IMETHOD GetGroupID(nsACString & aGroupID); \
  NS_IMETHOD GetClientID(nsACString & aClientID); \
  NS_IMETHOD GetActive(bool *aActive); \
  NS_IMETHOD GetUsage(uint32_t *aUsage); \
  NS_IMETHOD Activate(void); \
  NS_IMETHOD Discard(void); \
  NS_IMETHOD MarkEntry(const nsACString & key, uint32_t typeBits); \
  NS_IMETHOD UnmarkEntry(const nsACString & key, uint32_t typeBits); \
  NS_IMETHOD GetTypes(const nsACString & key, uint32_t *_retval); \
  NS_IMETHOD GatherEntries(uint32_t typeBits, uint32_t *count, char * **keys); \
  NS_IMETHOD AddNamespaces(nsIArray *namespaces); \
  NS_IMETHOD GetMatchingNamespace(const nsACString & key, nsIApplicationCacheNamespace * *_retval); \
  NS_IMETHOD GetProfileDirectory(nsIFile * *aProfileDirectory); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPLICATIONCACHE(_to) \
  NS_IMETHOD InitAsHandle(const nsACString & groupId, const nsACString & clientId) { return _to InitAsHandle(groupId, clientId); } \
  NS_IMETHOD GetManifestURI(nsIURI * *aManifestURI) { return _to GetManifestURI(aManifestURI); } \
  NS_IMETHOD GetGroupID(nsACString & aGroupID) { return _to GetGroupID(aGroupID); } \
  NS_IMETHOD GetClientID(nsACString & aClientID) { return _to GetClientID(aClientID); } \
  NS_IMETHOD GetActive(bool *aActive) { return _to GetActive(aActive); } \
  NS_IMETHOD GetUsage(uint32_t *aUsage) { return _to GetUsage(aUsage); } \
  NS_IMETHOD Activate(void) { return _to Activate(); } \
  NS_IMETHOD Discard(void) { return _to Discard(); } \
  NS_IMETHOD MarkEntry(const nsACString & key, uint32_t typeBits) { return _to MarkEntry(key, typeBits); } \
  NS_IMETHOD UnmarkEntry(const nsACString & key, uint32_t typeBits) { return _to UnmarkEntry(key, typeBits); } \
  NS_IMETHOD GetTypes(const nsACString & key, uint32_t *_retval) { return _to GetTypes(key, _retval); } \
  NS_IMETHOD GatherEntries(uint32_t typeBits, uint32_t *count, char * **keys) { return _to GatherEntries(typeBits, count, keys); } \
  NS_IMETHOD AddNamespaces(nsIArray *namespaces) { return _to AddNamespaces(namespaces); } \
  NS_IMETHOD GetMatchingNamespace(const nsACString & key, nsIApplicationCacheNamespace * *_retval) { return _to GetMatchingNamespace(key, _retval); } \
  NS_IMETHOD GetProfileDirectory(nsIFile * *aProfileDirectory) { return _to GetProfileDirectory(aProfileDirectory); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPLICATIONCACHE(_to) \
  NS_IMETHOD InitAsHandle(const nsACString & groupId, const nsACString & clientId) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitAsHandle(groupId, clientId); } \
  NS_IMETHOD GetManifestURI(nsIURI * *aManifestURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetManifestURI(aManifestURI); } \
  NS_IMETHOD GetGroupID(nsACString & aGroupID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGroupID(aGroupID); } \
  NS_IMETHOD GetClientID(nsACString & aClientID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientID(aClientID); } \
  NS_IMETHOD GetActive(bool *aActive) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActive(aActive); } \
  NS_IMETHOD GetUsage(uint32_t *aUsage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsage(aUsage); } \
  NS_IMETHOD Activate(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Activate(); } \
  NS_IMETHOD Discard(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Discard(); } \
  NS_IMETHOD MarkEntry(const nsACString & key, uint32_t typeBits) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkEntry(key, typeBits); } \
  NS_IMETHOD UnmarkEntry(const nsACString & key, uint32_t typeBits) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnmarkEntry(key, typeBits); } \
  NS_IMETHOD GetTypes(const nsACString & key, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypes(key, _retval); } \
  NS_IMETHOD GatherEntries(uint32_t typeBits, uint32_t *count, char * **keys) { return !_to ? NS_ERROR_NULL_POINTER : _to->GatherEntries(typeBits, count, keys); } \
  NS_IMETHOD AddNamespaces(nsIArray *namespaces) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddNamespaces(namespaces); } \
  NS_IMETHOD GetMatchingNamespace(const nsACString & key, nsIApplicationCacheNamespace * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMatchingNamespace(key, _retval); } \
  NS_IMETHOD GetProfileDirectory(nsIFile * *aProfileDirectory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProfileDirectory(aProfileDirectory); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsApplicationCache : public nsIApplicationCache
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPLICATIONCACHE

  nsApplicationCache();

private:
  ~nsApplicationCache();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsApplicationCache, nsIApplicationCache)

nsApplicationCache::nsApplicationCache()
{
  /* member initializers and constructor code */
}

nsApplicationCache::~nsApplicationCache()
{
  /* destructor code */
}

/* void initAsHandle (in ACString groupId, in ACString clientId); */
NS_IMETHODIMP nsApplicationCache::InitAsHandle(const nsACString & groupId, const nsACString & clientId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI manifestURI; */
NS_IMETHODIMP nsApplicationCache::GetManifestURI(nsIURI * *aManifestURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString groupID; */
NS_IMETHODIMP nsApplicationCache::GetGroupID(nsACString & aGroupID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString clientID; */
NS_IMETHODIMP nsApplicationCache::GetClientID(nsACString & aClientID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean active; */
NS_IMETHODIMP nsApplicationCache::GetActive(bool *aActive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long usage; */
NS_IMETHODIMP nsApplicationCache::GetUsage(uint32_t *aUsage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void activate (); */
NS_IMETHODIMP nsApplicationCache::Activate()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void discard (); */
NS_IMETHODIMP nsApplicationCache::Discard()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markEntry (in ACString key, in unsigned long typeBits); */
NS_IMETHODIMP nsApplicationCache::MarkEntry(const nsACString & key, uint32_t typeBits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unmarkEntry (in ACString key, in unsigned long typeBits); */
NS_IMETHODIMP nsApplicationCache::UnmarkEntry(const nsACString & key, uint32_t typeBits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getTypes (in ACString key); */
NS_IMETHODIMP nsApplicationCache::GetTypes(const nsACString & key, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void gatherEntries (in uint32_t typeBits, out unsigned long count, [array, size_is (count)] out string keys); */
NS_IMETHODIMP nsApplicationCache::GatherEntries(uint32_t typeBits, uint32_t *count, char * **keys)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addNamespaces (in nsIArray namespaces); */
NS_IMETHODIMP nsApplicationCache::AddNamespaces(nsIArray *namespaces)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIApplicationCacheNamespace getMatchingNamespace (in ACString key); */
NS_IMETHODIMP nsApplicationCache::GetMatchingNamespace(const nsACString & key, nsIApplicationCacheNamespace * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile profileDirectory; */
NS_IMETHODIMP nsApplicationCache::GetProfileDirectory(nsIFile * *aProfileDirectory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIApplicationCache_h__ */

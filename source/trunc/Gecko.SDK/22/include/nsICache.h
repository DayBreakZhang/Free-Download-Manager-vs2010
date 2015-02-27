/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/cache/nsICache.idl
 */

#ifndef __gen_nsICache_h__
#define __gen_nsICache_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
typedef int32_t  nsCacheStoragePolicy;

typedef int32_t  nsCacheAccessMode;


/* starting interface:    nsICache */
#define NS_ICACHE_IID_STR "d6c67f38-b39a-4582-8a48-4c4f8a56dfd0"

#define NS_ICACHE_IID \
  {0xd6c67f38, 0xb39a, 0x4582, \
    { 0x8a, 0x48, 0x4c, 0x4f, 0x8a, 0x56, 0xdf, 0xd0 }}

class NS_NO_VTABLE nsICache {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHE_IID)

  enum {
    ACCESS_NONE = 0,
    ACCESS_READ = 1,
    ACCESS_WRITE = 2,
    ACCESS_READ_WRITE = 3,
    STORE_ANYWHERE = 0,
    STORE_IN_MEMORY = 1,
    STORE_ON_DISK = 2,
    STORE_OFFLINE = 4,
    NOT_STREAM_BASED = 0,
    STREAM_BASED = 1,
    NON_BLOCKING = 0,
    BLOCKING = 1,
    NO_EXPIRATION_TIME = 4294967295U
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICache, NS_ICACHE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHE \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHE(_to) \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHE(_to) \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCache : public nsICache
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHE

  nsCache();

private:
  ~nsCache();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCache, nsICache)

nsCache::nsCache()
{
  /* member initializers and constructor code */
}

nsCache::~nsCache()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif

#include "nsError.h"

#endif /* __gen_nsICache_h__ */

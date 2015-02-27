/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/netwerk/base/public/nsICacheInfoChannel.idl
 */

#ifndef __gen_nsICacheInfoChannel_h__
#define __gen_nsICacheInfoChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsICacheInfoChannel */
#define NS_ICACHEINFOCHANNEL_IID_STR "299d69b4-ee86-4541-802d-7642671ebf97"

#define NS_ICACHEINFOCHANNEL_IID \
  {0x299d69b4, 0xee86, 0x4541, \
    { 0x80, 0x2d, 0x76, 0x42, 0x67, 0x1e, 0xbf, 0x97 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsICacheInfoChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHEINFOCHANNEL_IID)

  /**
   * Get expiration time from cache token. This attribute is equivalent to
   * nsICachingChannel.cacheToken.expirationTime.
   */
  /* readonly attribute PRUint32 cacheTokenExpirationTime; */
  NS_SCRIPTABLE NS_IMETHOD GetCacheTokenExpirationTime(PRUint32 *aCacheTokenExpirationTime) = 0;

  /**
   * Set/get charset of cache entry. Accessing this attribute is equivalent to
   * calling nsICachingChannel.cacheToken.getMetaDataElement("charset") and
   * nsICachingChannel.cacheToken.setMetaDataElement("charset").
   */
  /* attribute ACString cacheTokenCachedCharset; */
  NS_SCRIPTABLE NS_IMETHOD GetCacheTokenCachedCharset(nsACString & aCacheTokenCachedCharset) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCacheTokenCachedCharset(const nsACString & aCacheTokenCachedCharset) = 0;

  /**
   * TRUE if this channel's data is being loaded from the cache.  This value
   * is undefined before the channel fires its OnStartRequest notification
   * and after the channel fires its OnStopRequest notification.
   */
  /* boolean isFromCache (); */
  NS_SCRIPTABLE NS_IMETHOD IsFromCache(PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheInfoChannel, NS_ICACHEINFOCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHEINFOCHANNEL \
  NS_SCRIPTABLE NS_IMETHOD GetCacheTokenExpirationTime(PRUint32 *aCacheTokenExpirationTime); \
  NS_SCRIPTABLE NS_IMETHOD GetCacheTokenCachedCharset(nsACString & aCacheTokenCachedCharset); \
  NS_SCRIPTABLE NS_IMETHOD SetCacheTokenCachedCharset(const nsACString & aCacheTokenCachedCharset); \
  NS_SCRIPTABLE NS_IMETHOD IsFromCache(PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHEINFOCHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCacheTokenExpirationTime(PRUint32 *aCacheTokenExpirationTime) { return _to GetCacheTokenExpirationTime(aCacheTokenExpirationTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetCacheTokenCachedCharset(nsACString & aCacheTokenCachedCharset) { return _to GetCacheTokenCachedCharset(aCacheTokenCachedCharset); } \
  NS_SCRIPTABLE NS_IMETHOD SetCacheTokenCachedCharset(const nsACString & aCacheTokenCachedCharset) { return _to SetCacheTokenCachedCharset(aCacheTokenCachedCharset); } \
  NS_SCRIPTABLE NS_IMETHOD IsFromCache(PRBool *_retval NS_OUTPARAM) { return _to IsFromCache(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHEINFOCHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCacheTokenExpirationTime(PRUint32 *aCacheTokenExpirationTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCacheTokenExpirationTime(aCacheTokenExpirationTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetCacheTokenCachedCharset(nsACString & aCacheTokenCachedCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCacheTokenCachedCharset(aCacheTokenCachedCharset); } \
  NS_SCRIPTABLE NS_IMETHOD SetCacheTokenCachedCharset(const nsACString & aCacheTokenCachedCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCacheTokenCachedCharset(aCacheTokenCachedCharset); } \
  NS_SCRIPTABLE NS_IMETHOD IsFromCache(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsFromCache(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheInfoChannel : public nsICacheInfoChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHEINFOCHANNEL

  nsCacheInfoChannel();

private:
  ~nsCacheInfoChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCacheInfoChannel, nsICacheInfoChannel)

nsCacheInfoChannel::nsCacheInfoChannel()
{
  /* member initializers and constructor code */
}

nsCacheInfoChannel::~nsCacheInfoChannel()
{
  /* destructor code */
}

/* readonly attribute PRUint32 cacheTokenExpirationTime; */
NS_IMETHODIMP nsCacheInfoChannel::GetCacheTokenExpirationTime(PRUint32 *aCacheTokenExpirationTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString cacheTokenCachedCharset; */
NS_IMETHODIMP nsCacheInfoChannel::GetCacheTokenCachedCharset(nsACString & aCacheTokenCachedCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCacheInfoChannel::SetCacheTokenCachedCharset(const nsACString & aCacheTokenCachedCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isFromCache (); */
NS_IMETHODIMP nsCacheInfoChannel::IsFromCache(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICacheInfoChannel_h__ */

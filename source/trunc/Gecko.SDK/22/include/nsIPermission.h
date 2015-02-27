/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIPermission.idl
 */

#ifndef __gen_nsIPermission_h__
#define __gen_nsIPermission_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPermission */
#define NS_IPERMISSION_IID_STR "cfb08e46-193c-4be7-a467-d7775fb2a31e"

#define NS_IPERMISSION_IID \
  {0xcfb08e46, 0x193c, 0x4be7, \
    { 0xa4, 0x67, 0xd7, 0x77, 0x5f, 0xb2, 0xa3, 0x1e }}

class NS_NO_VTABLE nsIPermission : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPERMISSION_IID)

  /* readonly attribute AUTF8String host; */
  NS_IMETHOD GetHost(nsACString & aHost) = 0;

  /* readonly attribute unsigned long appId; */
  NS_IMETHOD GetAppId(uint32_t *aAppId) = 0;

  /* readonly attribute boolean isInBrowserElement; */
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement) = 0;

  /* readonly attribute ACString type; */
  NS_IMETHOD GetType(nsACString & aType) = 0;

  /* readonly attribute uint32_t capability; */
  NS_IMETHOD GetCapability(uint32_t *aCapability) = 0;

  /* readonly attribute uint32_t expireType; */
  NS_IMETHOD GetExpireType(uint32_t *aExpireType) = 0;

  /* readonly attribute int64_t expireTime; */
  NS_IMETHOD GetExpireTime(int64_t *aExpireTime) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPermission, NS_IPERMISSION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPERMISSION \
  NS_IMETHOD GetHost(nsACString & aHost); \
  NS_IMETHOD GetAppId(uint32_t *aAppId); \
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement); \
  NS_IMETHOD GetType(nsACString & aType); \
  NS_IMETHOD GetCapability(uint32_t *aCapability); \
  NS_IMETHOD GetExpireType(uint32_t *aExpireType); \
  NS_IMETHOD GetExpireTime(int64_t *aExpireTime); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPERMISSION(_to) \
  NS_IMETHOD GetHost(nsACString & aHost) { return _to GetHost(aHost); } \
  NS_IMETHOD GetAppId(uint32_t *aAppId) { return _to GetAppId(aAppId); } \
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement) { return _to GetIsInBrowserElement(aIsInBrowserElement); } \
  NS_IMETHOD GetType(nsACString & aType) { return _to GetType(aType); } \
  NS_IMETHOD GetCapability(uint32_t *aCapability) { return _to GetCapability(aCapability); } \
  NS_IMETHOD GetExpireType(uint32_t *aExpireType) { return _to GetExpireType(aExpireType); } \
  NS_IMETHOD GetExpireTime(int64_t *aExpireTime) { return _to GetExpireTime(aExpireTime); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPERMISSION(_to) \
  NS_IMETHOD GetHost(nsACString & aHost) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHost(aHost); } \
  NS_IMETHOD GetAppId(uint32_t *aAppId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppId(aAppId); } \
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsInBrowserElement(aIsInBrowserElement); } \
  NS_IMETHOD GetType(nsACString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetCapability(uint32_t *aCapability) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCapability(aCapability); } \
  NS_IMETHOD GetExpireType(uint32_t *aExpireType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExpireType(aExpireType); } \
  NS_IMETHOD GetExpireTime(int64_t *aExpireTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExpireTime(aExpireTime); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPermission : public nsIPermission
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPERMISSION

  nsPermission();

private:
  ~nsPermission();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPermission, nsIPermission)

nsPermission::nsPermission()
{
  /* member initializers and constructor code */
}

nsPermission::~nsPermission()
{
  /* destructor code */
}

/* readonly attribute AUTF8String host; */
NS_IMETHODIMP nsPermission::GetHost(nsACString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long appId; */
NS_IMETHODIMP nsPermission::GetAppId(uint32_t *aAppId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isInBrowserElement; */
NS_IMETHODIMP nsPermission::GetIsInBrowserElement(bool *aIsInBrowserElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString type; */
NS_IMETHODIMP nsPermission::GetType(nsACString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t capability; */
NS_IMETHODIMP nsPermission::GetCapability(uint32_t *aCapability)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t expireType; */
NS_IMETHODIMP nsPermission::GetExpireType(uint32_t *aExpireType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t expireTime; */
NS_IMETHODIMP nsPermission::GetExpireTime(int64_t *aExpireTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPermission_h__ */

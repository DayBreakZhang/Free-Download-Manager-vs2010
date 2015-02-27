/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/netwerk/base/public/nsIPermission.idl
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
#define NS_IPERMISSION_IID_STR "5036f0f6-f77b-4168-9d57-a1c0dd66cf02"

#define NS_IPERMISSION_IID \
  {0x5036f0f6, 0xf77b, 0x4168, \
    { 0x9d, 0x57, 0xa1, 0xc0, 0xdd, 0x66, 0xcf, 0x02 }}

/**
 * This interface defines a "permission" object,
 * used to specify allowed/blocked objects from
 * user-specified sites (cookies, images etc).
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIPermission : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPERMISSION_IID)

  /**
     * The name of the host for which the permission is set
     */
  /* readonly attribute AUTF8String host; */
  NS_SCRIPTABLE NS_IMETHOD GetHost(nsACString & aHost) = 0;

  /**
     * a case-sensitive ASCII string, indicating the type of permission
     * (e.g., "cookie", "image", etc).
     * This string is specified by the consumer when adding a permission 
     * via nsIPermissionManager.
     * @see nsIPermissionManager
     */
  /* readonly attribute ACString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsACString & aType) = 0;

  /**
     * The permission (see nsIPermissionManager.idl for allowed values)
     */
  /* readonly attribute PRUint32 capability; */
  NS_SCRIPTABLE NS_IMETHOD GetCapability(PRUint32 *aCapability) = 0;

  /**
     * The expiration type of the permission (session, time-based or none).
     * Constants are EXPIRE_*, defined in nsIPermissionManager.
     * @see nsIPermissionManager
     */
  /* readonly attribute PRUint32 expireType; */
  NS_SCRIPTABLE NS_IMETHOD GetExpireType(PRUint32 *aExpireType) = 0;

  /**
     * The expiration time of the permission (milliseconds since Jan 1 1970
     * 0:00:00).
     */
  /* readonly attribute PRInt64 expireTime; */
  NS_SCRIPTABLE NS_IMETHOD GetExpireTime(PRInt64 *aExpireTime) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPermission, NS_IPERMISSION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPERMISSION \
  NS_SCRIPTABLE NS_IMETHOD GetHost(nsACString & aHost); \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsACString & aType); \
  NS_SCRIPTABLE NS_IMETHOD GetCapability(PRUint32 *aCapability); \
  NS_SCRIPTABLE NS_IMETHOD GetExpireType(PRUint32 *aExpireType); \
  NS_SCRIPTABLE NS_IMETHOD GetExpireTime(PRInt64 *aExpireTime); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPERMISSION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetHost(nsACString & aHost) { return _to GetHost(aHost); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsACString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetCapability(PRUint32 *aCapability) { return _to GetCapability(aCapability); } \
  NS_SCRIPTABLE NS_IMETHOD GetExpireType(PRUint32 *aExpireType) { return _to GetExpireType(aExpireType); } \
  NS_SCRIPTABLE NS_IMETHOD GetExpireTime(PRInt64 *aExpireTime) { return _to GetExpireTime(aExpireTime); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPERMISSION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetHost(nsACString & aHost) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHost(aHost); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsACString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetCapability(PRUint32 *aCapability) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCapability(aCapability); } \
  NS_SCRIPTABLE NS_IMETHOD GetExpireType(PRUint32 *aExpireType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExpireType(aExpireType); } \
  NS_SCRIPTABLE NS_IMETHOD GetExpireTime(PRInt64 *aExpireTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExpireTime(aExpireTime); } 

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

/* readonly attribute ACString type; */
NS_IMETHODIMP nsPermission::GetType(nsACString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRUint32 capability; */
NS_IMETHODIMP nsPermission::GetCapability(PRUint32 *aCapability)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRUint32 expireType; */
NS_IMETHODIMP nsPermission::GetExpireType(PRUint32 *aExpireType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRInt64 expireTime; */
NS_IMETHODIMP nsPermission::GetExpireTime(PRInt64 *aExpireTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPermission_h__ */

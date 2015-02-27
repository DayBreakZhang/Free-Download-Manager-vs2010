/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISOCKSSocketInfo.idl
 */

#ifndef __gen_nsISOCKSSocketInfo_h__
#define __gen_nsISOCKSSocketInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
namespace mozilla {
namespace net {
union NetAddr;
}
}

/* starting interface:    nsISOCKSSocketInfo */
#define NS_ISOCKSSOCKETINFO_IID_STR "d5c0d1f9-22d7-47dc-bf91-d9ac6e1251a6"

#define NS_ISOCKSSOCKETINFO_IID \
  {0xd5c0d1f9, 0x22d7, 0x47dc, \
    { 0xbf, 0x91, 0xd9, 0xac, 0x6e, 0x12, 0x51, 0xa6 }}

class NS_NO_VTABLE nsISOCKSSocketInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISOCKSSOCKETINFO_IID)

  /* [noscript] attribute NetAddrPtr destinationAddr; */
  NS_IMETHOD GetDestinationAddr(mozilla::net::NetAddr **aDestinationAddr) = 0;
  NS_IMETHOD SetDestinationAddr(mozilla::net::NetAddr *aDestinationAddr) = 0;

  /* [noscript] attribute NetAddrPtr externalProxyAddr; */
  NS_IMETHOD GetExternalProxyAddr(mozilla::net::NetAddr **aExternalProxyAddr) = 0;
  NS_IMETHOD SetExternalProxyAddr(mozilla::net::NetAddr *aExternalProxyAddr) = 0;

  /* [noscript] attribute NetAddrPtr internalProxyAddr; */
  NS_IMETHOD GetInternalProxyAddr(mozilla::net::NetAddr **aInternalProxyAddr) = 0;
  NS_IMETHOD SetInternalProxyAddr(mozilla::net::NetAddr *aInternalProxyAddr) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISOCKSSocketInfo, NS_ISOCKSSOCKETINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISOCKSSOCKETINFO \
  NS_IMETHOD GetDestinationAddr(mozilla::net::NetAddr **aDestinationAddr); \
  NS_IMETHOD SetDestinationAddr(mozilla::net::NetAddr *aDestinationAddr); \
  NS_IMETHOD GetExternalProxyAddr(mozilla::net::NetAddr **aExternalProxyAddr); \
  NS_IMETHOD SetExternalProxyAddr(mozilla::net::NetAddr *aExternalProxyAddr); \
  NS_IMETHOD GetInternalProxyAddr(mozilla::net::NetAddr **aInternalProxyAddr); \
  NS_IMETHOD SetInternalProxyAddr(mozilla::net::NetAddr *aInternalProxyAddr); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISOCKSSOCKETINFO(_to) \
  NS_IMETHOD GetDestinationAddr(mozilla::net::NetAddr **aDestinationAddr) { return _to GetDestinationAddr(aDestinationAddr); } \
  NS_IMETHOD SetDestinationAddr(mozilla::net::NetAddr *aDestinationAddr) { return _to SetDestinationAddr(aDestinationAddr); } \
  NS_IMETHOD GetExternalProxyAddr(mozilla::net::NetAddr **aExternalProxyAddr) { return _to GetExternalProxyAddr(aExternalProxyAddr); } \
  NS_IMETHOD SetExternalProxyAddr(mozilla::net::NetAddr *aExternalProxyAddr) { return _to SetExternalProxyAddr(aExternalProxyAddr); } \
  NS_IMETHOD GetInternalProxyAddr(mozilla::net::NetAddr **aInternalProxyAddr) { return _to GetInternalProxyAddr(aInternalProxyAddr); } \
  NS_IMETHOD SetInternalProxyAddr(mozilla::net::NetAddr *aInternalProxyAddr) { return _to SetInternalProxyAddr(aInternalProxyAddr); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISOCKSSOCKETINFO(_to) \
  NS_IMETHOD GetDestinationAddr(mozilla::net::NetAddr **aDestinationAddr) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDestinationAddr(aDestinationAddr); } \
  NS_IMETHOD SetDestinationAddr(mozilla::net::NetAddr *aDestinationAddr) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDestinationAddr(aDestinationAddr); } \
  NS_IMETHOD GetExternalProxyAddr(mozilla::net::NetAddr **aExternalProxyAddr) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExternalProxyAddr(aExternalProxyAddr); } \
  NS_IMETHOD SetExternalProxyAddr(mozilla::net::NetAddr *aExternalProxyAddr) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExternalProxyAddr(aExternalProxyAddr); } \
  NS_IMETHOD GetInternalProxyAddr(mozilla::net::NetAddr **aInternalProxyAddr) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInternalProxyAddr(aInternalProxyAddr); } \
  NS_IMETHOD SetInternalProxyAddr(mozilla::net::NetAddr *aInternalProxyAddr) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInternalProxyAddr(aInternalProxyAddr); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSOCKSSocketInfo : public nsISOCKSSocketInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISOCKSSOCKETINFO

  nsSOCKSSocketInfo();

private:
  ~nsSOCKSSocketInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSOCKSSocketInfo, nsISOCKSSocketInfo)

nsSOCKSSocketInfo::nsSOCKSSocketInfo()
{
  /* member initializers and constructor code */
}

nsSOCKSSocketInfo::~nsSOCKSSocketInfo()
{
  /* destructor code */
}

/* [noscript] attribute NetAddrPtr destinationAddr; */
NS_IMETHODIMP nsSOCKSSocketInfo::GetDestinationAddr(mozilla::net::NetAddr **aDestinationAddr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSOCKSSocketInfo::SetDestinationAddr(mozilla::net::NetAddr *aDestinationAddr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute NetAddrPtr externalProxyAddr; */
NS_IMETHODIMP nsSOCKSSocketInfo::GetExternalProxyAddr(mozilla::net::NetAddr **aExternalProxyAddr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSOCKSSocketInfo::SetExternalProxyAddr(mozilla::net::NetAddr *aExternalProxyAddr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute NetAddrPtr internalProxyAddr; */
NS_IMETHODIMP nsSOCKSSocketInfo::GetInternalProxyAddr(mozilla::net::NetAddr **aInternalProxyAddr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSOCKSSocketInfo::SetInternalProxyAddr(mozilla::net::NetAddr *aInternalProxyAddr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISOCKSSocketInfo_h__ */

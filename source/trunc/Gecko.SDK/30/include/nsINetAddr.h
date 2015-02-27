/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsINetAddr.idl
 */

#ifndef __gen_nsINetAddr_h__
#define __gen_nsINetAddr_h__


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

/* starting interface:    nsINetAddr */
#define NS_INETADDR_IID_STR "652b9ec5-d159-45d7-9127-50bb559486cd"

#define NS_INETADDR_IID \
  {0x652b9ec5, 0xd159, 0x45d7, \
    { 0x91, 0x27, 0x50, 0xbb, 0x55, 0x94, 0x86, 0xcd }}

class NS_NO_VTABLE nsINetAddr : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INETADDR_IID)

  /* readonly attribute unsigned short family; */
  NS_IMETHOD GetFamily(uint16_t *aFamily) = 0;

  /* readonly attribute AUTF8String address; */
  NS_IMETHOD GetAddress(nsACString & aAddress) = 0;

  /* readonly attribute unsigned short port; */
  NS_IMETHOD GetPort(uint16_t *aPort) = 0;

  /* readonly attribute unsigned long flow; */
  NS_IMETHOD GetFlow(uint32_t *aFlow) = 0;

  /* readonly attribute unsigned long scope; */
  NS_IMETHOD GetScope(uint32_t *aScope) = 0;

  /* readonly attribute boolean isV4Mapped; */
  NS_IMETHOD GetIsV4Mapped(bool *aIsV4Mapped) = 0;

  enum {
    FAMILY_INET = 1U,
    FAMILY_INET6 = 2U,
    FAMILY_LOCAL = 3U
  };

  /* [noscript] NetAddr getNetAddr (); */
  NS_IMETHOD GetNetAddr(mozilla::net::NetAddr *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINetAddr, NS_INETADDR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINETADDR \
  NS_IMETHOD GetFamily(uint16_t *aFamily); \
  NS_IMETHOD GetAddress(nsACString & aAddress); \
  NS_IMETHOD GetPort(uint16_t *aPort); \
  NS_IMETHOD GetFlow(uint32_t *aFlow); \
  NS_IMETHOD GetScope(uint32_t *aScope); \
  NS_IMETHOD GetIsV4Mapped(bool *aIsV4Mapped); \
  NS_IMETHOD GetNetAddr(mozilla::net::NetAddr *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINETADDR(_to) \
  NS_IMETHOD GetFamily(uint16_t *aFamily) { return _to GetFamily(aFamily); } \
  NS_IMETHOD GetAddress(nsACString & aAddress) { return _to GetAddress(aAddress); } \
  NS_IMETHOD GetPort(uint16_t *aPort) { return _to GetPort(aPort); } \
  NS_IMETHOD GetFlow(uint32_t *aFlow) { return _to GetFlow(aFlow); } \
  NS_IMETHOD GetScope(uint32_t *aScope) { return _to GetScope(aScope); } \
  NS_IMETHOD GetIsV4Mapped(bool *aIsV4Mapped) { return _to GetIsV4Mapped(aIsV4Mapped); } \
  NS_IMETHOD GetNetAddr(mozilla::net::NetAddr *_retval) { return _to GetNetAddr(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINETADDR(_to) \
  NS_IMETHOD GetFamily(uint16_t *aFamily) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFamily(aFamily); } \
  NS_IMETHOD GetAddress(nsACString & aAddress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAddress(aAddress); } \
  NS_IMETHOD GetPort(uint16_t *aPort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPort(aPort); } \
  NS_IMETHOD GetFlow(uint32_t *aFlow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFlow(aFlow); } \
  NS_IMETHOD GetScope(uint32_t *aScope) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScope(aScope); } \
  NS_IMETHOD GetIsV4Mapped(bool *aIsV4Mapped) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsV4Mapped(aIsV4Mapped); } \
  NS_IMETHOD GetNetAddr(mozilla::net::NetAddr *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNetAddr(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNetAddr : public nsINetAddr
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINETADDR

  nsNetAddr();

private:
  ~nsNetAddr();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNetAddr, nsINetAddr)

nsNetAddr::nsNetAddr()
{
  /* member initializers and constructor code */
}

nsNetAddr::~nsNetAddr()
{
  /* destructor code */
}

/* readonly attribute unsigned short family; */
NS_IMETHODIMP nsNetAddr::GetFamily(uint16_t *aFamily)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String address; */
NS_IMETHODIMP nsNetAddr::GetAddress(nsACString & aAddress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short port; */
NS_IMETHODIMP nsNetAddr::GetPort(uint16_t *aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long flow; */
NS_IMETHODIMP nsNetAddr::GetFlow(uint32_t *aFlow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long scope; */
NS_IMETHODIMP nsNetAddr::GetScope(uint32_t *aScope)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isV4Mapped; */
NS_IMETHODIMP nsNetAddr::GetIsV4Mapped(bool *aIsV4Mapped)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] NetAddr getNetAddr (); */
NS_IMETHODIMP nsNetAddr::GetNetAddr(mozilla::net::NetAddr *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINetAddr_h__ */

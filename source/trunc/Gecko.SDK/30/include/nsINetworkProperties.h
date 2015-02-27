/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsINetworkProperties.idl
 */

#ifndef __gen_nsINetworkProperties_h__
#define __gen_nsINetworkProperties_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsINetworkProperties */
#define NS_INETWORKPROPERTIES_IID_STR "0af94dec-7ffc-4301-8937-766c214ac688"

#define NS_INETWORKPROPERTIES_IID \
  {0x0af94dec, 0x7ffc, 0x4301, \
    { 0x89, 0x37, 0x76, 0x6c, 0x21, 0x4a, 0xc6, 0x88 }}

class NS_NO_VTABLE nsINetworkProperties : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INETWORKPROPERTIES_IID)

  /* readonly attribute boolean isWifi; */
  NS_IMETHOD GetIsWifi(bool *aIsWifi) = 0;

  /* readonly attribute unsigned long dhcpGateway; */
  NS_IMETHOD GetDhcpGateway(uint32_t *aDhcpGateway) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINetworkProperties, NS_INETWORKPROPERTIES_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINETWORKPROPERTIES \
  NS_IMETHOD GetIsWifi(bool *aIsWifi); \
  NS_IMETHOD GetDhcpGateway(uint32_t *aDhcpGateway); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINETWORKPROPERTIES(_to) \
  NS_IMETHOD GetIsWifi(bool *aIsWifi) { return _to GetIsWifi(aIsWifi); } \
  NS_IMETHOD GetDhcpGateway(uint32_t *aDhcpGateway) { return _to GetDhcpGateway(aDhcpGateway); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINETWORKPROPERTIES(_to) \
  NS_IMETHOD GetIsWifi(bool *aIsWifi) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsWifi(aIsWifi); } \
  NS_IMETHOD GetDhcpGateway(uint32_t *aDhcpGateway) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDhcpGateway(aDhcpGateway); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNetworkProperties : public nsINetworkProperties
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINETWORKPROPERTIES

  nsNetworkProperties();

private:
  ~nsNetworkProperties();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNetworkProperties, nsINetworkProperties)

nsNetworkProperties::nsNetworkProperties()
{
  /* member initializers and constructor code */
}

nsNetworkProperties::~nsNetworkProperties()
{
  /* destructor code */
}

/* readonly attribute boolean isWifi; */
NS_IMETHODIMP nsNetworkProperties::GetIsWifi(bool *aIsWifi)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long dhcpGateway; */
NS_IMETHODIMP nsNetworkProperties::GetDhcpGateway(uint32_t *aDhcpGateway)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINetworkProperties_h__ */

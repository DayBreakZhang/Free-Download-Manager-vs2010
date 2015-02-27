/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsINetworkLinkService.idl
 */

#ifndef __gen_nsINetworkLinkService_h__
#define __gen_nsINetworkLinkService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsINetworkLinkService */
#define NS_INETWORKLINKSERVICE_IID_STR "f7d3be87-7403-4a1e-b89f-2797776e9b08"

#define NS_INETWORKLINKSERVICE_IID \
  {0xf7d3be87, 0x7403, 0x4a1e, \
    { 0xb8, 0x9f, 0x27, 0x97, 0x77, 0x6e, 0x9b, 0x08 }}

class NS_NO_VTABLE nsINetworkLinkService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INETWORKLINKSERVICE_IID)

  enum {
    LINK_TYPE_UNKNOWN = 0U,
    LINK_TYPE_ETHERNET = 1U,
    LINK_TYPE_USB = 2U,
    LINK_TYPE_WIFI = 3U,
    LINK_TYPE_WIMAX = 4U,
    LINK_TYPE_2G = 5U,
    LINK_TYPE_3G = 6U,
    LINK_TYPE_4G = 7U
  };

  /* readonly attribute boolean isLinkUp; */
  NS_IMETHOD GetIsLinkUp(bool *aIsLinkUp) = 0;

  /* readonly attribute boolean linkStatusKnown; */
  NS_IMETHOD GetLinkStatusKnown(bool *aLinkStatusKnown) = 0;

  /* readonly attribute unsigned long linkType; */
  NS_IMETHOD GetLinkType(uint32_t *aLinkType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINetworkLinkService, NS_INETWORKLINKSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINETWORKLINKSERVICE \
  NS_IMETHOD GetIsLinkUp(bool *aIsLinkUp); \
  NS_IMETHOD GetLinkStatusKnown(bool *aLinkStatusKnown); \
  NS_IMETHOD GetLinkType(uint32_t *aLinkType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINETWORKLINKSERVICE(_to) \
  NS_IMETHOD GetIsLinkUp(bool *aIsLinkUp) { return _to GetIsLinkUp(aIsLinkUp); } \
  NS_IMETHOD GetLinkStatusKnown(bool *aLinkStatusKnown) { return _to GetLinkStatusKnown(aLinkStatusKnown); } \
  NS_IMETHOD GetLinkType(uint32_t *aLinkType) { return _to GetLinkType(aLinkType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINETWORKLINKSERVICE(_to) \
  NS_IMETHOD GetIsLinkUp(bool *aIsLinkUp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsLinkUp(aIsLinkUp); } \
  NS_IMETHOD GetLinkStatusKnown(bool *aLinkStatusKnown) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLinkStatusKnown(aLinkStatusKnown); } \
  NS_IMETHOD GetLinkType(uint32_t *aLinkType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLinkType(aLinkType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNetworkLinkService : public nsINetworkLinkService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINETWORKLINKSERVICE

  nsNetworkLinkService();

private:
  ~nsNetworkLinkService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNetworkLinkService, nsINetworkLinkService)

nsNetworkLinkService::nsNetworkLinkService()
{
  /* member initializers and constructor code */
}

nsNetworkLinkService::~nsNetworkLinkService()
{
  /* destructor code */
}

/* readonly attribute boolean isLinkUp; */
NS_IMETHODIMP nsNetworkLinkService::GetIsLinkUp(bool *aIsLinkUp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean linkStatusKnown; */
NS_IMETHODIMP nsNetworkLinkService::GetLinkStatusKnown(bool *aLinkStatusKnown)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long linkType; */
NS_IMETHODIMP nsNetworkLinkService::GetLinkType(uint32_t *aLinkType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * We send notifications through nsIObserverService with topic
 * NS_NETWORK_LINK_TOPIC whenever one of isLinkUp or linkStatusKnown
 * changes. We pass one of the NS_NETWORK_LINK_DATA_ constants below
 * as the aData parameter of the notification.
 */
#define NS_NETWORK_LINK_TOPIC "network:link-status-changed"
/**
 * isLinkUp is now true, linkStatusKnown is true.
 */
#define NS_NETWORK_LINK_DATA_UP      "up"
/**
 * isLinkUp is now false, linkStatusKnown is true.
 */
#define NS_NETWORK_LINK_DATA_DOWN    "down"
/**
 * linkStatusKnown is now false.
 */
#define NS_NETWORK_LINK_DATA_UNKNOWN "unknown"
/**
 * We send notifications through nsIObserverService with topic
 * NS_NETWORK_LINK_TYPE_TOPIC whenever the network connection type
 * changes. We pass one of the valid connection type constants
 * below as the aData parameter of the notification.
 */
#define NS_NETWORK_LINK_TYPE_TOPIC "network:link-type-changed"
/** We were unable to determine the network connection type */
#define NS_NETWORK_LINK_TYPE_UNKNOWN  "unknown"
/** A standard wired ethernet connection */
#define NS_NETWORK_LINK_TYPE_ETHERNET    "ethernet"
/** A connection via a USB port */
#define NS_NETWORK_LINK_TYPE_USB    "usb"
/** A connection via a WiFi access point (IEEE802.11) */
#define NS_NETWORK_LINK_TYPE_WIFI "wifi"
/** A connection via WiMax (IEEE802.16) */
#define NS_NETWORK_LINK_TYPE_WIMAX "wimax"
/** A '2G' mobile connection (e.g. GSM, GPRS, EDGE) */
#define NS_NETWORK_LINK_TYPE_2G "2g"
/** A '3G' mobile connection (e.g. UMTS, CDMA) */
#define NS_NETWORK_LINK_TYPE_3G "3g"
/** A '4G' mobile connection (e.g. LTE, UMB) */
#define NS_NETWORK_LINK_TYPE_4G "4g"

#endif /* __gen_nsINetworkLinkService_h__ */

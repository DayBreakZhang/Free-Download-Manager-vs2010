/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIUDPSocketFilter.idl
 */

#ifndef __gen_nsIUDPSocketFilter_h__
#define __gen_nsIUDPSocketFilter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsINetAddr_h__
#include "nsINetAddr.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIUDPSocketFilter */
#define NS_IUDPSOCKETFILTER_IID_STR "24f20de4-09e9-42ab-947a-0d6a3d103d59"

#define NS_IUDPSOCKETFILTER_IID \
  {0x24f20de4, 0x09e9, 0x42ab, \
    { 0x94, 0x7a, 0x0d, 0x6a, 0x3d, 0x10, 0x3d, 0x59 }}

class NS_NO_VTABLE nsIUDPSocketFilter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUDPSOCKETFILTER_IID)

  enum {
    SF_INCOMING = 0,
    SF_OUTGOING = 1
  };

  /* bool filterPacket ([const] in NetAddrPtr remote_addr, [array, size_is (len), const] in uint8_t data, in unsigned long len, in long direction); */
  NS_IMETHOD FilterPacket(const mozilla::net::NetAddr *remote_addr, const uint8_t *data, uint32_t len, int32_t direction, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUDPSocketFilter, NS_IUDPSOCKETFILTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUDPSOCKETFILTER \
  NS_IMETHOD FilterPacket(const mozilla::net::NetAddr *remote_addr, const uint8_t *data, uint32_t len, int32_t direction, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUDPSOCKETFILTER(_to) \
  NS_IMETHOD FilterPacket(const mozilla::net::NetAddr *remote_addr, const uint8_t *data, uint32_t len, int32_t direction, bool *_retval) { return _to FilterPacket(remote_addr, data, len, direction, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUDPSOCKETFILTER(_to) \
  NS_IMETHOD FilterPacket(const mozilla::net::NetAddr *remote_addr, const uint8_t *data, uint32_t len, int32_t direction, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FilterPacket(remote_addr, data, len, direction, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUDPSocketFilter : public nsIUDPSocketFilter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUDPSOCKETFILTER

  nsUDPSocketFilter();

private:
  ~nsUDPSocketFilter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUDPSocketFilter, nsIUDPSocketFilter)

nsUDPSocketFilter::nsUDPSocketFilter()
{
  /* member initializers and constructor code */
}

nsUDPSocketFilter::~nsUDPSocketFilter()
{
  /* destructor code */
}

/* bool filterPacket ([const] in NetAddrPtr remote_addr, [array, size_is (len), const] in uint8_t data, in unsigned long len, in long direction); */
NS_IMETHODIMP nsUDPSocketFilter::FilterPacket(const mozilla::net::NetAddr *remote_addr, const uint8_t *data, uint32_t len, int32_t direction, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUDPSocketFilterHandler */
#define NS_IUDPSOCKETFILTERHANDLER_IID_STR "81ee76c6-4753-4125-9c8c-290ed9ba62fb"

#define NS_IUDPSOCKETFILTERHANDLER_IID \
  {0x81ee76c6, 0x4753, 0x4125, \
    { 0x9c, 0x8c, 0x29, 0x0e, 0xd9, 0xba, 0x62, 0xfb }}

class NS_NO_VTABLE nsIUDPSocketFilterHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUDPSOCKETFILTERHANDLER_IID)

  /* nsIUDPSocketFilter newFilter (); */
  NS_IMETHOD NewFilter(nsIUDPSocketFilter * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUDPSocketFilterHandler, NS_IUDPSOCKETFILTERHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUDPSOCKETFILTERHANDLER \
  NS_IMETHOD NewFilter(nsIUDPSocketFilter * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUDPSOCKETFILTERHANDLER(_to) \
  NS_IMETHOD NewFilter(nsIUDPSocketFilter * *_retval) { return _to NewFilter(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUDPSOCKETFILTERHANDLER(_to) \
  NS_IMETHOD NewFilter(nsIUDPSocketFilter * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewFilter(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUDPSocketFilterHandler : public nsIUDPSocketFilterHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUDPSOCKETFILTERHANDLER

  nsUDPSocketFilterHandler();

private:
  ~nsUDPSocketFilterHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUDPSocketFilterHandler, nsIUDPSocketFilterHandler)

nsUDPSocketFilterHandler::nsUDPSocketFilterHandler()
{
  /* member initializers and constructor code */
}

nsUDPSocketFilterHandler::~nsUDPSocketFilterHandler()
{
  /* destructor code */
}

/* nsIUDPSocketFilter newFilter (); */
NS_IMETHODIMP nsUDPSocketFilterHandler::NewFilter(nsIUDPSocketFilter * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * Filter handlers are registered with XPCOM under the following CONTRACTID prefix:
 */
#define NS_NETWORK_UDP_SOCKET_FILTER_HANDLER_PREFIX "@mozilla.org/network/udp-filter-handler;1?name="

#endif /* __gen_nsIUDPSocketFilter_h__ */

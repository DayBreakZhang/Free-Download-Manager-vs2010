/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIDashboard.idl
 */

#ifndef __gen_nsIDashboard_h__
#define __gen_nsIDashboard_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIDashboardEventNotifier_h__
#include "nsIDashboardEventNotifier.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    NetDashboardCallback */
#define NETDASHBOARDCALLBACK_IID_STR "19d7f24f-a95a-4fd9-87e2-d96e9e4b1f6d"

#define NETDASHBOARDCALLBACK_IID \
  {0x19d7f24f, 0xa95a, 0x4fd9, \
    { 0x87, 0xe2, 0xd9, 0x6e, 0x9e, 0x4b, 0x1f, 0x6d }}

class NS_NO_VTABLE NetDashboardCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NETDASHBOARDCALLBACK_IID)

  /* void onDashboardDataAvailable (in jsval data); */
  NS_IMETHOD OnDashboardDataAvailable(const JS::Value & data) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(NetDashboardCallback, NETDASHBOARDCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NETDASHBOARDCALLBACK \
  NS_IMETHOD OnDashboardDataAvailable(const JS::Value & data); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NETDASHBOARDCALLBACK(_to) \
  NS_IMETHOD OnDashboardDataAvailable(const JS::Value & data) { return _to OnDashboardDataAvailable(data); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NETDASHBOARDCALLBACK(_to) \
  NS_IMETHOD OnDashboardDataAvailable(const JS::Value & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDashboardDataAvailable(data); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public NetDashboardCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NETDASHBOARDCALLBACK

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, NetDashboardCallback)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void onDashboardDataAvailable (in jsval data); */
NS_IMETHODIMP _MYCLASS_::OnDashboardDataAvailable(const JS::Value & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDashboard */
#define NS_IDASHBOARD_IID_STR "c79eb3c6-091a-45a6-8544-5a8d1ab79537"

#define NS_IDASHBOARD_IID \
  {0xc79eb3c6, 0x091a, 0x45a6, \
    { 0x85, 0x44, 0x5a, 0x8d, 0x1a, 0xb7, 0x95, 0x37 }}

class NS_NO_VTABLE nsIDashboard : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDASHBOARD_IID)

  /* void requestSockets (in NetDashboardCallback cb); */
  NS_IMETHOD RequestSockets(NetDashboardCallback *cb) = 0;

  /* void requestHttpConnections (in NetDashboardCallback cb); */
  NS_IMETHOD RequestHttpConnections(NetDashboardCallback *cb) = 0;

  /* void requestWebsocketConnections (in NetDashboardCallback cb); */
  NS_IMETHOD RequestWebsocketConnections(NetDashboardCallback *cb) = 0;

  /* void requestDNSInfo (in NetDashboardCallback cb); */
  NS_IMETHOD RequestDNSInfo(NetDashboardCallback *cb) = 0;

  /* attribute boolean enableLogging; */
  NS_IMETHOD GetEnableLogging(bool *aEnableLogging) = 0;
  NS_IMETHOD SetEnableLogging(bool aEnableLogging) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDashboard, NS_IDASHBOARD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDASHBOARD \
  NS_IMETHOD RequestSockets(NetDashboardCallback *cb); \
  NS_IMETHOD RequestHttpConnections(NetDashboardCallback *cb); \
  NS_IMETHOD RequestWebsocketConnections(NetDashboardCallback *cb); \
  NS_IMETHOD RequestDNSInfo(NetDashboardCallback *cb); \
  NS_IMETHOD GetEnableLogging(bool *aEnableLogging); \
  NS_IMETHOD SetEnableLogging(bool aEnableLogging); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDASHBOARD(_to) \
  NS_IMETHOD RequestSockets(NetDashboardCallback *cb) { return _to RequestSockets(cb); } \
  NS_IMETHOD RequestHttpConnections(NetDashboardCallback *cb) { return _to RequestHttpConnections(cb); } \
  NS_IMETHOD RequestWebsocketConnections(NetDashboardCallback *cb) { return _to RequestWebsocketConnections(cb); } \
  NS_IMETHOD RequestDNSInfo(NetDashboardCallback *cb) { return _to RequestDNSInfo(cb); } \
  NS_IMETHOD GetEnableLogging(bool *aEnableLogging) { return _to GetEnableLogging(aEnableLogging); } \
  NS_IMETHOD SetEnableLogging(bool aEnableLogging) { return _to SetEnableLogging(aEnableLogging); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDASHBOARD(_to) \
  NS_IMETHOD RequestSockets(NetDashboardCallback *cb) { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestSockets(cb); } \
  NS_IMETHOD RequestHttpConnections(NetDashboardCallback *cb) { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestHttpConnections(cb); } \
  NS_IMETHOD RequestWebsocketConnections(NetDashboardCallback *cb) { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestWebsocketConnections(cb); } \
  NS_IMETHOD RequestDNSInfo(NetDashboardCallback *cb) { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestDNSInfo(cb); } \
  NS_IMETHOD GetEnableLogging(bool *aEnableLogging) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnableLogging(aEnableLogging); } \
  NS_IMETHOD SetEnableLogging(bool aEnableLogging) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEnableLogging(aEnableLogging); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDashboard : public nsIDashboard
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDASHBOARD

  nsDashboard();

private:
  ~nsDashboard();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDashboard, nsIDashboard)

nsDashboard::nsDashboard()
{
  /* member initializers and constructor code */
}

nsDashboard::~nsDashboard()
{
  /* destructor code */
}

/* void requestSockets (in NetDashboardCallback cb); */
NS_IMETHODIMP nsDashboard::RequestSockets(NetDashboardCallback *cb)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void requestHttpConnections (in NetDashboardCallback cb); */
NS_IMETHODIMP nsDashboard::RequestHttpConnections(NetDashboardCallback *cb)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void requestWebsocketConnections (in NetDashboardCallback cb); */
NS_IMETHODIMP nsDashboard::RequestWebsocketConnections(NetDashboardCallback *cb)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void requestDNSInfo (in NetDashboardCallback cb); */
NS_IMETHODIMP nsDashboard::RequestDNSInfo(NetDashboardCallback *cb)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean enableLogging; */
NS_IMETHODIMP nsDashboard::GetEnableLogging(bool *aEnableLogging)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDashboard::SetEnableLogging(bool aEnableLogging)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDashboard_h__ */

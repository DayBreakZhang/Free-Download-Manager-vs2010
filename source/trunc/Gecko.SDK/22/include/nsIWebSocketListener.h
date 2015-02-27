/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/protocol/websocket/nsIWebSocketListener.idl
 */

#ifndef __gen_nsIWebSocketListener_h__
#define __gen_nsIWebSocketListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIWebSocketListener */
#define NS_IWEBSOCKETLISTENER_IID_STR "d74c96b2-65b3-4e39-9e39-c577de5d7a73"

#define NS_IWEBSOCKETLISTENER_IID \
  {0xd74c96b2, 0x65b3, 0x4e39, \
    { 0x9e, 0x39, 0xc5, 0x77, 0xde, 0x5d, 0x7a, 0x73 }}

class NS_NO_VTABLE nsIWebSocketListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBSOCKETLISTENER_IID)

  /* void onStart (in nsISupports aContext); */
  NS_IMETHOD OnStart(nsISupports *aContext) = 0;

  /* void onStop (in nsISupports aContext, in nsresult aStatusCode); */
  NS_IMETHOD OnStop(nsISupports *aContext, nsresult aStatusCode) = 0;

  /* void onMessageAvailable (in nsISupports aContext, in AUTF8String aMsg); */
  NS_IMETHOD OnMessageAvailable(nsISupports *aContext, const nsACString & aMsg) = 0;

  /* void onBinaryMessageAvailable (in nsISupports aContext, in ACString aMsg); */
  NS_IMETHOD OnBinaryMessageAvailable(nsISupports *aContext, const nsACString & aMsg) = 0;

  /* void onAcknowledge (in nsISupports aContext, in uint32_t aSize); */
  NS_IMETHOD OnAcknowledge(nsISupports *aContext, uint32_t aSize) = 0;

  /* void onServerClose (in nsISupports aContext, in unsigned short aCode, in AUTF8String aReason); */
  NS_IMETHOD OnServerClose(nsISupports *aContext, uint16_t aCode, const nsACString & aReason) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebSocketListener, NS_IWEBSOCKETLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBSOCKETLISTENER \
  NS_IMETHOD OnStart(nsISupports *aContext); \
  NS_IMETHOD OnStop(nsISupports *aContext, nsresult aStatusCode); \
  NS_IMETHOD OnMessageAvailable(nsISupports *aContext, const nsACString & aMsg); \
  NS_IMETHOD OnBinaryMessageAvailable(nsISupports *aContext, const nsACString & aMsg); \
  NS_IMETHOD OnAcknowledge(nsISupports *aContext, uint32_t aSize); \
  NS_IMETHOD OnServerClose(nsISupports *aContext, uint16_t aCode, const nsACString & aReason); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBSOCKETLISTENER(_to) \
  NS_IMETHOD OnStart(nsISupports *aContext) { return _to OnStart(aContext); } \
  NS_IMETHOD OnStop(nsISupports *aContext, nsresult aStatusCode) { return _to OnStop(aContext, aStatusCode); } \
  NS_IMETHOD OnMessageAvailable(nsISupports *aContext, const nsACString & aMsg) { return _to OnMessageAvailable(aContext, aMsg); } \
  NS_IMETHOD OnBinaryMessageAvailable(nsISupports *aContext, const nsACString & aMsg) { return _to OnBinaryMessageAvailable(aContext, aMsg); } \
  NS_IMETHOD OnAcknowledge(nsISupports *aContext, uint32_t aSize) { return _to OnAcknowledge(aContext, aSize); } \
  NS_IMETHOD OnServerClose(nsISupports *aContext, uint16_t aCode, const nsACString & aReason) { return _to OnServerClose(aContext, aCode, aReason); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBSOCKETLISTENER(_to) \
  NS_IMETHOD OnStart(nsISupports *aContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStart(aContext); } \
  NS_IMETHOD OnStop(nsISupports *aContext, nsresult aStatusCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStop(aContext, aStatusCode); } \
  NS_IMETHOD OnMessageAvailable(nsISupports *aContext, const nsACString & aMsg) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnMessageAvailable(aContext, aMsg); } \
  NS_IMETHOD OnBinaryMessageAvailable(nsISupports *aContext, const nsACString & aMsg) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnBinaryMessageAvailable(aContext, aMsg); } \
  NS_IMETHOD OnAcknowledge(nsISupports *aContext, uint32_t aSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnAcknowledge(aContext, aSize); } \
  NS_IMETHOD OnServerClose(nsISupports *aContext, uint16_t aCode, const nsACString & aReason) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnServerClose(aContext, aCode, aReason); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebSocketListener : public nsIWebSocketListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBSOCKETLISTENER

  nsWebSocketListener();

private:
  ~nsWebSocketListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebSocketListener, nsIWebSocketListener)

nsWebSocketListener::nsWebSocketListener()
{
  /* member initializers and constructor code */
}

nsWebSocketListener::~nsWebSocketListener()
{
  /* destructor code */
}

/* void onStart (in nsISupports aContext); */
NS_IMETHODIMP nsWebSocketListener::OnStart(nsISupports *aContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onStop (in nsISupports aContext, in nsresult aStatusCode); */
NS_IMETHODIMP nsWebSocketListener::OnStop(nsISupports *aContext, nsresult aStatusCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onMessageAvailable (in nsISupports aContext, in AUTF8String aMsg); */
NS_IMETHODIMP nsWebSocketListener::OnMessageAvailable(nsISupports *aContext, const nsACString & aMsg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onBinaryMessageAvailable (in nsISupports aContext, in ACString aMsg); */
NS_IMETHODIMP nsWebSocketListener::OnBinaryMessageAvailable(nsISupports *aContext, const nsACString & aMsg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onAcknowledge (in nsISupports aContext, in uint32_t aSize); */
NS_IMETHODIMP nsWebSocketListener::OnAcknowledge(nsISupports *aContext, uint32_t aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onServerClose (in nsISupports aContext, in unsigned short aCode, in AUTF8String aReason); */
NS_IMETHODIMP nsWebSocketListener::OnServerClose(nsISupports *aContext, uint16_t aCode, const nsACString & aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebSocketListener_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIServerSocket.idl
 */

#ifndef __gen_nsIServerSocket_h__
#define __gen_nsIServerSocket_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */

class nsIServerSocketListener; /* forward declaration */

class nsISocketTransport; /* forward declaration */

typedef uint32_t  nsServerSocketFlag;


/* starting interface:    nsIServerSocket */
#define NS_ISERVERSOCKET_IID_STR "7a9c39cb-a13f-4eef-9bdf-a74301628742"

#define NS_ISERVERSOCKET_IID \
  {0x7a9c39cb, 0xa13f, 0x4eef, \
    { 0x9b, 0xdf, 0xa7, 0x43, 0x01, 0x62, 0x87, 0x42 }}

class NS_NO_VTABLE nsIServerSocket : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISERVERSOCKET_IID)

  enum {
    LoopbackOnly = 1U,
    KeepWhenOffline = 2U
  };

  /* void init (in long aPort, in boolean aLoopbackOnly, in long aBackLog); */
  NS_IMETHOD Init(int32_t aPort, bool aLoopbackOnly, int32_t aBackLog) = 0;

  /* void initSpecialConnection (in long aPort, in nsServerSocketFlag aFlags, in long aBackLog); */
  NS_IMETHOD InitSpecialConnection(int32_t aPort, nsServerSocketFlag aFlags, int32_t aBackLog) = 0;

  /* [noscript] void initWithAddress ([const] in PRNetAddrPtr aAddr, in long aBackLog); */
  NS_IMETHOD InitWithAddress(const union PRNetAddr *aAddr, int32_t aBackLog) = 0;

  /* void initWithFilename (in nsIFile aPath, in unsigned long aPermissions, in long aBacklog); */
  NS_IMETHOD InitWithFilename(nsIFile *aPath, uint32_t aPermissions, int32_t aBacklog) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

  /* void asyncListen (in nsIServerSocketListener aListener); */
  NS_IMETHOD AsyncListen(nsIServerSocketListener *aListener) = 0;

  /* readonly attribute long port; */
  NS_IMETHOD GetPort(int32_t *aPort) = 0;

  /* [noscript] PRNetAddr getAddress (); */
  NS_IMETHOD GetAddress(union PRNetAddr *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIServerSocket, NS_ISERVERSOCKET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISERVERSOCKET \
  NS_IMETHOD Init(int32_t aPort, bool aLoopbackOnly, int32_t aBackLog); \
  NS_IMETHOD InitSpecialConnection(int32_t aPort, nsServerSocketFlag aFlags, int32_t aBackLog); \
  NS_IMETHOD InitWithAddress(const union PRNetAddr *aAddr, int32_t aBackLog); \
  NS_IMETHOD InitWithFilename(nsIFile *aPath, uint32_t aPermissions, int32_t aBacklog); \
  NS_IMETHOD Close(void); \
  NS_IMETHOD AsyncListen(nsIServerSocketListener *aListener); \
  NS_IMETHOD GetPort(int32_t *aPort); \
  NS_IMETHOD GetAddress(union PRNetAddr *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISERVERSOCKET(_to) \
  NS_IMETHOD Init(int32_t aPort, bool aLoopbackOnly, int32_t aBackLog) { return _to Init(aPort, aLoopbackOnly, aBackLog); } \
  NS_IMETHOD InitSpecialConnection(int32_t aPort, nsServerSocketFlag aFlags, int32_t aBackLog) { return _to InitSpecialConnection(aPort, aFlags, aBackLog); } \
  NS_IMETHOD InitWithAddress(const union PRNetAddr *aAddr, int32_t aBackLog) { return _to InitWithAddress(aAddr, aBackLog); } \
  NS_IMETHOD InitWithFilename(nsIFile *aPath, uint32_t aPermissions, int32_t aBacklog) { return _to InitWithFilename(aPath, aPermissions, aBacklog); } \
  NS_IMETHOD Close(void) { return _to Close(); } \
  NS_IMETHOD AsyncListen(nsIServerSocketListener *aListener) { return _to AsyncListen(aListener); } \
  NS_IMETHOD GetPort(int32_t *aPort) { return _to GetPort(aPort); } \
  NS_IMETHOD GetAddress(union PRNetAddr *_retval) { return _to GetAddress(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISERVERSOCKET(_to) \
  NS_IMETHOD Init(int32_t aPort, bool aLoopbackOnly, int32_t aBackLog) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aPort, aLoopbackOnly, aBackLog); } \
  NS_IMETHOD InitSpecialConnection(int32_t aPort, nsServerSocketFlag aFlags, int32_t aBackLog) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitSpecialConnection(aPort, aFlags, aBackLog); } \
  NS_IMETHOD InitWithAddress(const union PRNetAddr *aAddr, int32_t aBackLog) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitWithAddress(aAddr, aBackLog); } \
  NS_IMETHOD InitWithFilename(nsIFile *aPath, uint32_t aPermissions, int32_t aBacklog) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitWithFilename(aPath, aPermissions, aBacklog); } \
  NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_IMETHOD AsyncListen(nsIServerSocketListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncListen(aListener); } \
  NS_IMETHOD GetPort(int32_t *aPort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPort(aPort); } \
  NS_IMETHOD GetAddress(union PRNetAddr *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAddress(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsServerSocket : public nsIServerSocket
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISERVERSOCKET

  nsServerSocket();

private:
  ~nsServerSocket();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsServerSocket, nsIServerSocket)

nsServerSocket::nsServerSocket()
{
  /* member initializers and constructor code */
}

nsServerSocket::~nsServerSocket()
{
  /* destructor code */
}

/* void init (in long aPort, in boolean aLoopbackOnly, in long aBackLog); */
NS_IMETHODIMP nsServerSocket::Init(int32_t aPort, bool aLoopbackOnly, int32_t aBackLog)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initSpecialConnection (in long aPort, in nsServerSocketFlag aFlags, in long aBackLog); */
NS_IMETHODIMP nsServerSocket::InitSpecialConnection(int32_t aPort, nsServerSocketFlag aFlags, int32_t aBackLog)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initWithAddress ([const] in PRNetAddrPtr aAddr, in long aBackLog); */
NS_IMETHODIMP nsServerSocket::InitWithAddress(const union PRNetAddr *aAddr, int32_t aBackLog)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initWithFilename (in nsIFile aPath, in unsigned long aPermissions, in long aBacklog); */
NS_IMETHODIMP nsServerSocket::InitWithFilename(nsIFile *aPath, uint32_t aPermissions, int32_t aBacklog)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsServerSocket::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncListen (in nsIServerSocketListener aListener); */
NS_IMETHODIMP nsServerSocket::AsyncListen(nsIServerSocketListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long port; */
NS_IMETHODIMP nsServerSocket::GetPort(int32_t *aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] PRNetAddr getAddress (); */
NS_IMETHODIMP nsServerSocket::GetAddress(union PRNetAddr *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIServerSocketListener */
#define NS_ISERVERSOCKETLISTENER_IID_STR "836d98ec-fee2-4bde-b609-abd5e966eabd"

#define NS_ISERVERSOCKETLISTENER_IID \
  {0x836d98ec, 0xfee2, 0x4bde, \
    { 0xb6, 0x09, 0xab, 0xd5, 0xe9, 0x66, 0xea, 0xbd }}

class NS_NO_VTABLE nsIServerSocketListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISERVERSOCKETLISTENER_IID)

  /* void onSocketAccepted (in nsIServerSocket aServ, in nsISocketTransport aTransport); */
  NS_IMETHOD OnSocketAccepted(nsIServerSocket *aServ, nsISocketTransport *aTransport) = 0;

  /* void onStopListening (in nsIServerSocket aServ, in nsresult aStatus); */
  NS_IMETHOD OnStopListening(nsIServerSocket *aServ, nsresult aStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIServerSocketListener, NS_ISERVERSOCKETLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISERVERSOCKETLISTENER \
  NS_IMETHOD OnSocketAccepted(nsIServerSocket *aServ, nsISocketTransport *aTransport); \
  NS_IMETHOD OnStopListening(nsIServerSocket *aServ, nsresult aStatus); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISERVERSOCKETLISTENER(_to) \
  NS_IMETHOD OnSocketAccepted(nsIServerSocket *aServ, nsISocketTransport *aTransport) { return _to OnSocketAccepted(aServ, aTransport); } \
  NS_IMETHOD OnStopListening(nsIServerSocket *aServ, nsresult aStatus) { return _to OnStopListening(aServ, aStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISERVERSOCKETLISTENER(_to) \
  NS_IMETHOD OnSocketAccepted(nsIServerSocket *aServ, nsISocketTransport *aTransport) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSocketAccepted(aServ, aTransport); } \
  NS_IMETHOD OnStopListening(nsIServerSocket *aServ, nsresult aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStopListening(aServ, aStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsServerSocketListener : public nsIServerSocketListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISERVERSOCKETLISTENER

  nsServerSocketListener();

private:
  ~nsServerSocketListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsServerSocketListener, nsIServerSocketListener)

nsServerSocketListener::nsServerSocketListener()
{
  /* member initializers and constructor code */
}

nsServerSocketListener::~nsServerSocketListener()
{
  /* destructor code */
}

/* void onSocketAccepted (in nsIServerSocket aServ, in nsISocketTransport aTransport); */
NS_IMETHODIMP nsServerSocketListener::OnSocketAccepted(nsIServerSocket *aServ, nsISocketTransport *aTransport)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onStopListening (in nsIServerSocket aServ, in nsresult aStatus); */
NS_IMETHODIMP nsServerSocketListener::OnStopListening(nsIServerSocket *aServ, nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIServerSocket_h__ */

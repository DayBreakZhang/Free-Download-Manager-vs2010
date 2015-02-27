/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMTCPServerSocket.idl
 */

#ifndef __gen_nsIDOMTCPServerSocket_h__
#define __gen_nsIDOMTCPServerSocket_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsITCPSocketChild_h__
#include "nsITCPSocketChild.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMTCPServerSocket */
#define NS_IDOMTCPSERVERSOCKET_IID_STR "821638a1-5327-416d-8031-668764f2ec04"

#define NS_IDOMTCPSERVERSOCKET_IID \
  {0x821638a1, 0x5327, 0x416d, \
    { 0x80, 0x31, 0x66, 0x87, 0x64, 0xf2, 0xec, 0x04 }}

class NS_NO_VTABLE nsIDOMTCPServerSocket : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMTCPSERVERSOCKET_IID)

  /* readonly attribute unsigned short localPort; */
  NS_IMETHOD GetLocalPort(uint16_t *aLocalPort) = 0;

  /* attribute jsval onconnect; */
  NS_IMETHOD GetOnconnect(JS::MutableHandleValue aOnconnect) = 0;
  NS_IMETHOD SetOnconnect(JS::HandleValue aOnconnect) = 0;

  /* attribute jsval onerror; */
  NS_IMETHOD GetOnerror(JS::MutableHandleValue aOnerror) = 0;
  NS_IMETHOD SetOnerror(JS::HandleValue aOnerror) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMTCPServerSocket, NS_IDOMTCPSERVERSOCKET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMTCPSERVERSOCKET \
  NS_IMETHOD GetLocalPort(uint16_t *aLocalPort); \
  NS_IMETHOD GetOnconnect(JS::MutableHandleValue aOnconnect); \
  NS_IMETHOD SetOnconnect(JS::HandleValue aOnconnect); \
  NS_IMETHOD GetOnerror(JS::MutableHandleValue aOnerror); \
  NS_IMETHOD SetOnerror(JS::HandleValue aOnerror); \
  NS_IMETHOD Close(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMTCPSERVERSOCKET(_to) \
  NS_IMETHOD GetLocalPort(uint16_t *aLocalPort) { return _to GetLocalPort(aLocalPort); } \
  NS_IMETHOD GetOnconnect(JS::MutableHandleValue aOnconnect) { return _to GetOnconnect(aOnconnect); } \
  NS_IMETHOD SetOnconnect(JS::HandleValue aOnconnect) { return _to SetOnconnect(aOnconnect); } \
  NS_IMETHOD GetOnerror(JS::MutableHandleValue aOnerror) { return _to GetOnerror(aOnerror); } \
  NS_IMETHOD SetOnerror(JS::HandleValue aOnerror) { return _to SetOnerror(aOnerror); } \
  NS_IMETHOD Close(void) { return _to Close(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMTCPSERVERSOCKET(_to) \
  NS_IMETHOD GetLocalPort(uint16_t *aLocalPort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalPort(aLocalPort); } \
  NS_IMETHOD GetOnconnect(JS::MutableHandleValue aOnconnect) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnconnect(aOnconnect); } \
  NS_IMETHOD SetOnconnect(JS::HandleValue aOnconnect) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnconnect(aOnconnect); } \
  NS_IMETHOD GetOnerror(JS::MutableHandleValue aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnerror(aOnerror); } \
  NS_IMETHOD SetOnerror(JS::HandleValue aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnerror(aOnerror); } \
  NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMTCPServerSocket : public nsIDOMTCPServerSocket
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMTCPSERVERSOCKET

  nsDOMTCPServerSocket();

private:
  ~nsDOMTCPServerSocket();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMTCPServerSocket, nsIDOMTCPServerSocket)

nsDOMTCPServerSocket::nsDOMTCPServerSocket()
{
  /* member initializers and constructor code */
}

nsDOMTCPServerSocket::~nsDOMTCPServerSocket()
{
  /* destructor code */
}

/* readonly attribute unsigned short localPort; */
NS_IMETHODIMP nsDOMTCPServerSocket::GetLocalPort(uint16_t *aLocalPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval onconnect; */
NS_IMETHODIMP nsDOMTCPServerSocket::GetOnconnect(JS::MutableHandleValue aOnconnect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMTCPServerSocket::SetOnconnect(JS::HandleValue aOnconnect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval onerror; */
NS_IMETHODIMP nsDOMTCPServerSocket::GetOnerror(JS::MutableHandleValue aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMTCPServerSocket::SetOnerror(JS::HandleValue aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsDOMTCPServerSocket::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITCPServerSocketInternal */
#define NS_ITCPSERVERSOCKETINTERNAL_IID_STR "b64b1e68-4efa-497c-b0d8-69f067ad5ec8"

#define NS_ITCPSERVERSOCKETINTERNAL_IID \
  {0xb64b1e68, 0x4efa, 0x497c, \
    { 0xb0, 0xd8, 0x69, 0xf0, 0x67, 0xad, 0x5e, 0xc8 }}

class NS_NO_VTABLE nsITCPServerSocketInternal : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITCPSERVERSOCKETINTERNAL_IID)

  /* void init (in jsval windowVal); */
  NS_IMETHOD Init(JS::HandleValue windowVal) = 0;

  /* void listen (in unsigned short localPort, in jsval options, in unsigned short backlog); */
  NS_IMETHOD Listen(uint16_t localPort, JS::HandleValue options, uint16_t backlog) = 0;

  /* void callListenerAccept (in nsITCPSocketChild socketChild); */
  NS_IMETHOD CallListenerAccept(nsITCPSocketChild *socketChild) = 0;

  /* void callListenerError (in DOMString message, in DOMString filename, in uint32_t lineNumber, in uint32_t columnNumber); */
  NS_IMETHOD CallListenerError(const nsAString & message, const nsAString & filename, uint32_t lineNumber, uint32_t columnNumber) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITCPServerSocketInternal, NS_ITCPSERVERSOCKETINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITCPSERVERSOCKETINTERNAL \
  NS_IMETHOD Init(JS::HandleValue windowVal); \
  NS_IMETHOD Listen(uint16_t localPort, JS::HandleValue options, uint16_t backlog); \
  NS_IMETHOD CallListenerAccept(nsITCPSocketChild *socketChild); \
  NS_IMETHOD CallListenerError(const nsAString & message, const nsAString & filename, uint32_t lineNumber, uint32_t columnNumber); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITCPSERVERSOCKETINTERNAL(_to) \
  NS_IMETHOD Init(JS::HandleValue windowVal) { return _to Init(windowVal); } \
  NS_IMETHOD Listen(uint16_t localPort, JS::HandleValue options, uint16_t backlog) { return _to Listen(localPort, options, backlog); } \
  NS_IMETHOD CallListenerAccept(nsITCPSocketChild *socketChild) { return _to CallListenerAccept(socketChild); } \
  NS_IMETHOD CallListenerError(const nsAString & message, const nsAString & filename, uint32_t lineNumber, uint32_t columnNumber) { return _to CallListenerError(message, filename, lineNumber, columnNumber); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITCPSERVERSOCKETINTERNAL(_to) \
  NS_IMETHOD Init(JS::HandleValue windowVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(windowVal); } \
  NS_IMETHOD Listen(uint16_t localPort, JS::HandleValue options, uint16_t backlog) { return !_to ? NS_ERROR_NULL_POINTER : _to->Listen(localPort, options, backlog); } \
  NS_IMETHOD CallListenerAccept(nsITCPSocketChild *socketChild) { return !_to ? NS_ERROR_NULL_POINTER : _to->CallListenerAccept(socketChild); } \
  NS_IMETHOD CallListenerError(const nsAString & message, const nsAString & filename, uint32_t lineNumber, uint32_t columnNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->CallListenerError(message, filename, lineNumber, columnNumber); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTCPServerSocketInternal : public nsITCPServerSocketInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITCPSERVERSOCKETINTERNAL

  nsTCPServerSocketInternal();

private:
  ~nsTCPServerSocketInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTCPServerSocketInternal, nsITCPServerSocketInternal)

nsTCPServerSocketInternal::nsTCPServerSocketInternal()
{
  /* member initializers and constructor code */
}

nsTCPServerSocketInternal::~nsTCPServerSocketInternal()
{
  /* destructor code */
}

/* void init (in jsval windowVal); */
NS_IMETHODIMP nsTCPServerSocketInternal::Init(JS::HandleValue windowVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void listen (in unsigned short localPort, in jsval options, in unsigned short backlog); */
NS_IMETHODIMP nsTCPServerSocketInternal::Listen(uint16_t localPort, JS::HandleValue options, uint16_t backlog)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void callListenerAccept (in nsITCPSocketChild socketChild); */
NS_IMETHODIMP nsTCPServerSocketInternal::CallListenerAccept(nsITCPSocketChild *socketChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void callListenerError (in DOMString message, in DOMString filename, in uint32_t lineNumber, in uint32_t columnNumber); */
NS_IMETHODIMP nsTCPServerSocketInternal::CallListenerError(const nsAString & message, const nsAString & filename, uint32_t lineNumber, uint32_t columnNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMTCPServerSocket_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIUDPSocketChild.idl
 */

#ifndef __gen_nsIUDPSocketChild_h__
#define __gen_nsIUDPSocketChild_h__


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
class nsIUDPSocketInternal; /* forward declaration */

namespace mozilla {
namespace net {
union NetAddr;
}
}

/* starting interface:    nsIUDPSocketChild */
#define NS_IUDPSOCKETCHILD_IID_STR "b47e5a0f-d384-48ef-8885-4259793d9cf0"

#define NS_IUDPSOCKETCHILD_IID \
  {0xb47e5a0f, 0xd384, 0x48ef, \
    { 0x88, 0x85, 0x42, 0x59, 0x79, 0x3d, 0x9c, 0xf0 }}

class NS_NO_VTABLE nsIUDPSocketChild : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUDPSOCKETCHILD_IID)

  /* readonly attribute unsigned short localPort; */
  NS_IMETHOD GetLocalPort(uint16_t *aLocalPort) = 0;

  /* readonly attribute AUTF8String localAddress; */
  NS_IMETHOD GetLocalAddress(nsACString & aLocalAddress) = 0;

  /* attribute AUTF8String filterName; */
  NS_IMETHOD GetFilterName(nsACString & aFilterName) = 0;
  NS_IMETHOD SetFilterName(const nsACString & aFilterName) = 0;

  /* void bind (in nsIUDPSocketInternal socket, in AUTF8String host, in unsigned short port); */
  NS_IMETHOD Bind(nsIUDPSocketInternal *socket, const nsACString & host, uint16_t port) = 0;

  /* void send (in AUTF8String host, in unsigned short port, [array, size_is (byteLength), const] in uint8_t bytes, in unsigned long byteLength); */
  NS_IMETHOD Send(const nsACString & host, uint16_t port, const uint8_t *bytes, uint32_t byteLength) = 0;

  /* void sendWithAddr (in nsINetAddr addr, [array, size_is (byteLength), const] in uint8_t bytes, in unsigned long byteLength); */
  NS_IMETHOD SendWithAddr(nsINetAddr *addr, const uint8_t *bytes, uint32_t byteLength) = 0;

  /* [noscript] void sendWithAddress ([const] in NetAddrPtr addr, [array, size_is (byteLength), const] in uint8_t bytes, in unsigned long byteLength); */
  NS_IMETHOD SendWithAddress(const mozilla::net::NetAddr *addr, const uint8_t *bytes, uint32_t byteLength) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUDPSocketChild, NS_IUDPSOCKETCHILD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUDPSOCKETCHILD \
  NS_IMETHOD GetLocalPort(uint16_t *aLocalPort); \
  NS_IMETHOD GetLocalAddress(nsACString & aLocalAddress); \
  NS_IMETHOD GetFilterName(nsACString & aFilterName); \
  NS_IMETHOD SetFilterName(const nsACString & aFilterName); \
  NS_IMETHOD Bind(nsIUDPSocketInternal *socket, const nsACString & host, uint16_t port); \
  NS_IMETHOD Send(const nsACString & host, uint16_t port, const uint8_t *bytes, uint32_t byteLength); \
  NS_IMETHOD SendWithAddr(nsINetAddr *addr, const uint8_t *bytes, uint32_t byteLength); \
  NS_IMETHOD SendWithAddress(const mozilla::net::NetAddr *addr, const uint8_t *bytes, uint32_t byteLength); \
  NS_IMETHOD Close(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUDPSOCKETCHILD(_to) \
  NS_IMETHOD GetLocalPort(uint16_t *aLocalPort) { return _to GetLocalPort(aLocalPort); } \
  NS_IMETHOD GetLocalAddress(nsACString & aLocalAddress) { return _to GetLocalAddress(aLocalAddress); } \
  NS_IMETHOD GetFilterName(nsACString & aFilterName) { return _to GetFilterName(aFilterName); } \
  NS_IMETHOD SetFilterName(const nsACString & aFilterName) { return _to SetFilterName(aFilterName); } \
  NS_IMETHOD Bind(nsIUDPSocketInternal *socket, const nsACString & host, uint16_t port) { return _to Bind(socket, host, port); } \
  NS_IMETHOD Send(const nsACString & host, uint16_t port, const uint8_t *bytes, uint32_t byteLength) { return _to Send(host, port, bytes, byteLength); } \
  NS_IMETHOD SendWithAddr(nsINetAddr *addr, const uint8_t *bytes, uint32_t byteLength) { return _to SendWithAddr(addr, bytes, byteLength); } \
  NS_IMETHOD SendWithAddress(const mozilla::net::NetAddr *addr, const uint8_t *bytes, uint32_t byteLength) { return _to SendWithAddress(addr, bytes, byteLength); } \
  NS_IMETHOD Close(void) { return _to Close(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUDPSOCKETCHILD(_to) \
  NS_IMETHOD GetLocalPort(uint16_t *aLocalPort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalPort(aLocalPort); } \
  NS_IMETHOD GetLocalAddress(nsACString & aLocalAddress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalAddress(aLocalAddress); } \
  NS_IMETHOD GetFilterName(nsACString & aFilterName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilterName(aFilterName); } \
  NS_IMETHOD SetFilterName(const nsACString & aFilterName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFilterName(aFilterName); } \
  NS_IMETHOD Bind(nsIUDPSocketInternal *socket, const nsACString & host, uint16_t port) { return !_to ? NS_ERROR_NULL_POINTER : _to->Bind(socket, host, port); } \
  NS_IMETHOD Send(const nsACString & host, uint16_t port, const uint8_t *bytes, uint32_t byteLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->Send(host, port, bytes, byteLength); } \
  NS_IMETHOD SendWithAddr(nsINetAddr *addr, const uint8_t *bytes, uint32_t byteLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendWithAddr(addr, bytes, byteLength); } \
  NS_IMETHOD SendWithAddress(const mozilla::net::NetAddr *addr, const uint8_t *bytes, uint32_t byteLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendWithAddress(addr, bytes, byteLength); } \
  NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUDPSocketChild : public nsIUDPSocketChild
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUDPSOCKETCHILD

  nsUDPSocketChild();

private:
  ~nsUDPSocketChild();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUDPSocketChild, nsIUDPSocketChild)

nsUDPSocketChild::nsUDPSocketChild()
{
  /* member initializers and constructor code */
}

nsUDPSocketChild::~nsUDPSocketChild()
{
  /* destructor code */
}

/* readonly attribute unsigned short localPort; */
NS_IMETHODIMP nsUDPSocketChild::GetLocalPort(uint16_t *aLocalPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String localAddress; */
NS_IMETHODIMP nsUDPSocketChild::GetLocalAddress(nsACString & aLocalAddress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String filterName; */
NS_IMETHODIMP nsUDPSocketChild::GetFilterName(nsACString & aFilterName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUDPSocketChild::SetFilterName(const nsACString & aFilterName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void bind (in nsIUDPSocketInternal socket, in AUTF8String host, in unsigned short port); */
NS_IMETHODIMP nsUDPSocketChild::Bind(nsIUDPSocketInternal *socket, const nsACString & host, uint16_t port)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void send (in AUTF8String host, in unsigned short port, [array, size_is (byteLength), const] in uint8_t bytes, in unsigned long byteLength); */
NS_IMETHODIMP nsUDPSocketChild::Send(const nsACString & host, uint16_t port, const uint8_t *bytes, uint32_t byteLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendWithAddr (in nsINetAddr addr, [array, size_is (byteLength), const] in uint8_t bytes, in unsigned long byteLength); */
NS_IMETHODIMP nsUDPSocketChild::SendWithAddr(nsINetAddr *addr, const uint8_t *bytes, uint32_t byteLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void sendWithAddress ([const] in NetAddrPtr addr, [array, size_is (byteLength), const] in uint8_t bytes, in unsigned long byteLength); */
NS_IMETHODIMP nsUDPSocketChild::SendWithAddress(const mozilla::net::NetAddr *addr, const uint8_t *bytes, uint32_t byteLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsUDPSocketChild::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUDPSocketInternal */
#define NS_IUDPSOCKETINTERNAL_IID_STR "1e27e9b3-c1c8-4b05-a415-1a2c1a641c60"

#define NS_IUDPSOCKETINTERNAL_IID \
  {0x1e27e9b3, 0xc1c8, 0x4b05, \
    { 0xa4, 0x15, 0x1a, 0x2c, 0x1a, 0x64, 0x1c, 0x60 }}

class NS_NO_VTABLE nsIUDPSocketInternal : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUDPSOCKETINTERNAL_IID)

  /* void callListenerError (in AUTF8String type, in AUTF8String message, in AUTF8String filename, in uint32_t lineNumber, in uint32_t columnNumber); */
  NS_IMETHOD CallListenerError(const nsACString & type, const nsACString & message, const nsACString & filename, uint32_t lineNumber, uint32_t columnNumber) = 0;

  /* void callListenerReceivedData (in AUTF8String type, in AUTF8String host, in unsigned short port, [array, size_is (dataLength)] in uint8_t data, in unsigned long dataLength); */
  NS_IMETHOD CallListenerReceivedData(const nsACString & type, const nsACString & host, uint16_t port, uint8_t *data, uint32_t dataLength) = 0;

  /* void callListenerVoid (in AUTF8String type); */
  NS_IMETHOD CallListenerVoid(const nsACString & type) = 0;

  /* void callListenerSent (in AUTF8String type, in nsresult status); */
  NS_IMETHOD CallListenerSent(const nsACString & type, nsresult status) = 0;

  /* void updateReadyState (in AUTF8String readyState); */
  NS_IMETHOD UpdateReadyState(const nsACString & readyState) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUDPSocketInternal, NS_IUDPSOCKETINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUDPSOCKETINTERNAL \
  NS_IMETHOD CallListenerError(const nsACString & type, const nsACString & message, const nsACString & filename, uint32_t lineNumber, uint32_t columnNumber); \
  NS_IMETHOD CallListenerReceivedData(const nsACString & type, const nsACString & host, uint16_t port, uint8_t *data, uint32_t dataLength); \
  NS_IMETHOD CallListenerVoid(const nsACString & type); \
  NS_IMETHOD CallListenerSent(const nsACString & type, nsresult status); \
  NS_IMETHOD UpdateReadyState(const nsACString & readyState); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUDPSOCKETINTERNAL(_to) \
  NS_IMETHOD CallListenerError(const nsACString & type, const nsACString & message, const nsACString & filename, uint32_t lineNumber, uint32_t columnNumber) { return _to CallListenerError(type, message, filename, lineNumber, columnNumber); } \
  NS_IMETHOD CallListenerReceivedData(const nsACString & type, const nsACString & host, uint16_t port, uint8_t *data, uint32_t dataLength) { return _to CallListenerReceivedData(type, host, port, data, dataLength); } \
  NS_IMETHOD CallListenerVoid(const nsACString & type) { return _to CallListenerVoid(type); } \
  NS_IMETHOD CallListenerSent(const nsACString & type, nsresult status) { return _to CallListenerSent(type, status); } \
  NS_IMETHOD UpdateReadyState(const nsACString & readyState) { return _to UpdateReadyState(readyState); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUDPSOCKETINTERNAL(_to) \
  NS_IMETHOD CallListenerError(const nsACString & type, const nsACString & message, const nsACString & filename, uint32_t lineNumber, uint32_t columnNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->CallListenerError(type, message, filename, lineNumber, columnNumber); } \
  NS_IMETHOD CallListenerReceivedData(const nsACString & type, const nsACString & host, uint16_t port, uint8_t *data, uint32_t dataLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->CallListenerReceivedData(type, host, port, data, dataLength); } \
  NS_IMETHOD CallListenerVoid(const nsACString & type) { return !_to ? NS_ERROR_NULL_POINTER : _to->CallListenerVoid(type); } \
  NS_IMETHOD CallListenerSent(const nsACString & type, nsresult status) { return !_to ? NS_ERROR_NULL_POINTER : _to->CallListenerSent(type, status); } \
  NS_IMETHOD UpdateReadyState(const nsACString & readyState) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateReadyState(readyState); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUDPSocketInternal : public nsIUDPSocketInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUDPSOCKETINTERNAL

  nsUDPSocketInternal();

private:
  ~nsUDPSocketInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUDPSocketInternal, nsIUDPSocketInternal)

nsUDPSocketInternal::nsUDPSocketInternal()
{
  /* member initializers and constructor code */
}

nsUDPSocketInternal::~nsUDPSocketInternal()
{
  /* destructor code */
}

/* void callListenerError (in AUTF8String type, in AUTF8String message, in AUTF8String filename, in uint32_t lineNumber, in uint32_t columnNumber); */
NS_IMETHODIMP nsUDPSocketInternal::CallListenerError(const nsACString & type, const nsACString & message, const nsACString & filename, uint32_t lineNumber, uint32_t columnNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void callListenerReceivedData (in AUTF8String type, in AUTF8String host, in unsigned short port, [array, size_is (dataLength)] in uint8_t data, in unsigned long dataLength); */
NS_IMETHODIMP nsUDPSocketInternal::CallListenerReceivedData(const nsACString & type, const nsACString & host, uint16_t port, uint8_t *data, uint32_t dataLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void callListenerVoid (in AUTF8String type); */
NS_IMETHODIMP nsUDPSocketInternal::CallListenerVoid(const nsACString & type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void callListenerSent (in AUTF8String type, in nsresult status); */
NS_IMETHODIMP nsUDPSocketInternal::CallListenerSent(const nsACString & type, nsresult status)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateReadyState (in AUTF8String readyState); */
NS_IMETHODIMP nsUDPSocketInternal::UpdateReadyState(const nsACString & readyState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUDPSocketChild_h__ */

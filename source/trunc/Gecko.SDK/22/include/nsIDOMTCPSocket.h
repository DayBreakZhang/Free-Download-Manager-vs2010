/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/network/interfaces/nsIDOMTCPSocket.idl
 */

#ifndef __gen_nsIDOMTCPSocket_h__
#define __gen_nsIDOMTCPSocket_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMTCPSocket */
#define NS_IDOMTCPSOCKET_IID_STR "b82e17da-6476-11e1-8813-57a2ffe9e42c"

#define NS_IDOMTCPSOCKET_IID \
  {0xb82e17da, 0x6476, 0x11e1, \
    { 0x88, 0x13, 0x57, 0xa2, 0xff, 0xe9, 0xe4, 0x2c }}

class NS_NO_VTABLE nsIDOMTCPSocket : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMTCPSOCKET_IID)

  /* nsIDOMTCPSocket open (in DOMString host, in unsigned short port, [optional] in jsval options); */
  NS_IMETHOD Open(const nsAString & host, uint16_t port, const JS::Value & options, nsIDOMTCPSocket * *_retval) = 0;

  /* readonly attribute DOMString host; */
  NS_IMETHOD GetHost(nsAString & aHost) = 0;

  /* readonly attribute unsigned short port; */
  NS_IMETHOD GetPort(uint16_t *aPort) = 0;

  /* readonly attribute boolean ssl; */
  NS_IMETHOD GetSsl(bool *aSsl) = 0;

  /* readonly attribute unsigned long bufferedAmount; */
  NS_IMETHOD GetBufferedAmount(uint32_t *aBufferedAmount) = 0;

  /* void suspend (); */
  NS_IMETHOD Suspend(void) = 0;

  /* void resume (); */
  NS_IMETHOD Resume(void) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

  /* boolean send (in jsval data); */
  NS_IMETHOD Send(const JS::Value & data, bool *_retval) = 0;

  /* readonly attribute DOMString readyState; */
  NS_IMETHOD GetReadyState(nsAString & aReadyState) = 0;

  /* readonly attribute DOMString binaryType; */
  NS_IMETHOD GetBinaryType(nsAString & aBinaryType) = 0;

  /* attribute jsval onopen; */
  NS_IMETHOD GetOnopen(JS::Value *aOnopen) = 0;
  NS_IMETHOD SetOnopen(const JS::Value & aOnopen) = 0;

  /* attribute jsval ondrain; */
  NS_IMETHOD GetOndrain(JS::Value *aOndrain) = 0;
  NS_IMETHOD SetOndrain(const JS::Value & aOndrain) = 0;

  /* attribute jsval ondata; */
  NS_IMETHOD GetOndata(JS::Value *aOndata) = 0;
  NS_IMETHOD SetOndata(const JS::Value & aOndata) = 0;

  /* attribute jsval onerror; */
  NS_IMETHOD GetOnerror(JS::Value *aOnerror) = 0;
  NS_IMETHOD SetOnerror(const JS::Value & aOnerror) = 0;

  /* attribute jsval onclose; */
  NS_IMETHOD GetOnclose(JS::Value *aOnclose) = 0;
  NS_IMETHOD SetOnclose(const JS::Value & aOnclose) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMTCPSocket, NS_IDOMTCPSOCKET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMTCPSOCKET \
  NS_IMETHOD Open(const nsAString & host, uint16_t port, const JS::Value & options, nsIDOMTCPSocket * *_retval); \
  NS_IMETHOD GetHost(nsAString & aHost); \
  NS_IMETHOD GetPort(uint16_t *aPort); \
  NS_IMETHOD GetSsl(bool *aSsl); \
  NS_IMETHOD GetBufferedAmount(uint32_t *aBufferedAmount); \
  NS_IMETHOD Suspend(void); \
  NS_IMETHOD Resume(void); \
  NS_IMETHOD Close(void); \
  NS_IMETHOD Send(const JS::Value & data, bool *_retval); \
  NS_IMETHOD GetReadyState(nsAString & aReadyState); \
  NS_IMETHOD GetBinaryType(nsAString & aBinaryType); \
  NS_IMETHOD GetOnopen(JS::Value *aOnopen); \
  NS_IMETHOD SetOnopen(const JS::Value & aOnopen); \
  NS_IMETHOD GetOndrain(JS::Value *aOndrain); \
  NS_IMETHOD SetOndrain(const JS::Value & aOndrain); \
  NS_IMETHOD GetOndata(JS::Value *aOndata); \
  NS_IMETHOD SetOndata(const JS::Value & aOndata); \
  NS_IMETHOD GetOnerror(JS::Value *aOnerror); \
  NS_IMETHOD SetOnerror(const JS::Value & aOnerror); \
  NS_IMETHOD GetOnclose(JS::Value *aOnclose); \
  NS_IMETHOD SetOnclose(const JS::Value & aOnclose); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMTCPSOCKET(_to) \
  NS_IMETHOD Open(const nsAString & host, uint16_t port, const JS::Value & options, nsIDOMTCPSocket * *_retval) { return _to Open(host, port, options, _retval); } \
  NS_IMETHOD GetHost(nsAString & aHost) { return _to GetHost(aHost); } \
  NS_IMETHOD GetPort(uint16_t *aPort) { return _to GetPort(aPort); } \
  NS_IMETHOD GetSsl(bool *aSsl) { return _to GetSsl(aSsl); } \
  NS_IMETHOD GetBufferedAmount(uint32_t *aBufferedAmount) { return _to GetBufferedAmount(aBufferedAmount); } \
  NS_IMETHOD Suspend(void) { return _to Suspend(); } \
  NS_IMETHOD Resume(void) { return _to Resume(); } \
  NS_IMETHOD Close(void) { return _to Close(); } \
  NS_IMETHOD Send(const JS::Value & data, bool *_retval) { return _to Send(data, _retval); } \
  NS_IMETHOD GetReadyState(nsAString & aReadyState) { return _to GetReadyState(aReadyState); } \
  NS_IMETHOD GetBinaryType(nsAString & aBinaryType) { return _to GetBinaryType(aBinaryType); } \
  NS_IMETHOD GetOnopen(JS::Value *aOnopen) { return _to GetOnopen(aOnopen); } \
  NS_IMETHOD SetOnopen(const JS::Value & aOnopen) { return _to SetOnopen(aOnopen); } \
  NS_IMETHOD GetOndrain(JS::Value *aOndrain) { return _to GetOndrain(aOndrain); } \
  NS_IMETHOD SetOndrain(const JS::Value & aOndrain) { return _to SetOndrain(aOndrain); } \
  NS_IMETHOD GetOndata(JS::Value *aOndata) { return _to GetOndata(aOndata); } \
  NS_IMETHOD SetOndata(const JS::Value & aOndata) { return _to SetOndata(aOndata); } \
  NS_IMETHOD GetOnerror(JS::Value *aOnerror) { return _to GetOnerror(aOnerror); } \
  NS_IMETHOD SetOnerror(const JS::Value & aOnerror) { return _to SetOnerror(aOnerror); } \
  NS_IMETHOD GetOnclose(JS::Value *aOnclose) { return _to GetOnclose(aOnclose); } \
  NS_IMETHOD SetOnclose(const JS::Value & aOnclose) { return _to SetOnclose(aOnclose); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMTCPSOCKET(_to) \
  NS_IMETHOD Open(const nsAString & host, uint16_t port, const JS::Value & options, nsIDOMTCPSocket * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(host, port, options, _retval); } \
  NS_IMETHOD GetHost(nsAString & aHost) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHost(aHost); } \
  NS_IMETHOD GetPort(uint16_t *aPort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPort(aPort); } \
  NS_IMETHOD GetSsl(bool *aSsl) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSsl(aSsl); } \
  NS_IMETHOD GetBufferedAmount(uint32_t *aBufferedAmount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBufferedAmount(aBufferedAmount); } \
  NS_IMETHOD Suspend(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Suspend(); } \
  NS_IMETHOD Resume(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Resume(); } \
  NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_IMETHOD Send(const JS::Value & data, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Send(data, _retval); } \
  NS_IMETHOD GetReadyState(nsAString & aReadyState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReadyState(aReadyState); } \
  NS_IMETHOD GetBinaryType(nsAString & aBinaryType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBinaryType(aBinaryType); } \
  NS_IMETHOD GetOnopen(JS::Value *aOnopen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnopen(aOnopen); } \
  NS_IMETHOD SetOnopen(const JS::Value & aOnopen) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnopen(aOnopen); } \
  NS_IMETHOD GetOndrain(JS::Value *aOndrain) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndrain(aOndrain); } \
  NS_IMETHOD SetOndrain(const JS::Value & aOndrain) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndrain(aOndrain); } \
  NS_IMETHOD GetOndata(JS::Value *aOndata) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndata(aOndata); } \
  NS_IMETHOD SetOndata(const JS::Value & aOndata) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndata(aOndata); } \
  NS_IMETHOD GetOnerror(JS::Value *aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnerror(aOnerror); } \
  NS_IMETHOD SetOnerror(const JS::Value & aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnerror(aOnerror); } \
  NS_IMETHOD GetOnclose(JS::Value *aOnclose) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnclose(aOnclose); } \
  NS_IMETHOD SetOnclose(const JS::Value & aOnclose) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnclose(aOnclose); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMTCPSocket : public nsIDOMTCPSocket
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMTCPSOCKET

  nsDOMTCPSocket();

private:
  ~nsDOMTCPSocket();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMTCPSocket, nsIDOMTCPSocket)

nsDOMTCPSocket::nsDOMTCPSocket()
{
  /* member initializers and constructor code */
}

nsDOMTCPSocket::~nsDOMTCPSocket()
{
  /* destructor code */
}

/* nsIDOMTCPSocket open (in DOMString host, in unsigned short port, [optional] in jsval options); */
NS_IMETHODIMP nsDOMTCPSocket::Open(const nsAString & host, uint16_t port, const JS::Value & options, nsIDOMTCPSocket * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString host; */
NS_IMETHODIMP nsDOMTCPSocket::GetHost(nsAString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short port; */
NS_IMETHODIMP nsDOMTCPSocket::GetPort(uint16_t *aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean ssl; */
NS_IMETHODIMP nsDOMTCPSocket::GetSsl(bool *aSsl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long bufferedAmount; */
NS_IMETHODIMP nsDOMTCPSocket::GetBufferedAmount(uint32_t *aBufferedAmount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void suspend (); */
NS_IMETHODIMP nsDOMTCPSocket::Suspend()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resume (); */
NS_IMETHODIMP nsDOMTCPSocket::Resume()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsDOMTCPSocket::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean send (in jsval data); */
NS_IMETHODIMP nsDOMTCPSocket::Send(const JS::Value & data, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString readyState; */
NS_IMETHODIMP nsDOMTCPSocket::GetReadyState(nsAString & aReadyState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString binaryType; */
NS_IMETHODIMP nsDOMTCPSocket::GetBinaryType(nsAString & aBinaryType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval onopen; */
NS_IMETHODIMP nsDOMTCPSocket::GetOnopen(JS::Value *aOnopen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMTCPSocket::SetOnopen(const JS::Value & aOnopen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval ondrain; */
NS_IMETHODIMP nsDOMTCPSocket::GetOndrain(JS::Value *aOndrain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMTCPSocket::SetOndrain(const JS::Value & aOndrain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval ondata; */
NS_IMETHODIMP nsDOMTCPSocket::GetOndata(JS::Value *aOndata)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMTCPSocket::SetOndata(const JS::Value & aOndata)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval onerror; */
NS_IMETHODIMP nsDOMTCPSocket::GetOnerror(JS::Value *aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMTCPSocket::SetOnerror(const JS::Value & aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval onclose; */
NS_IMETHODIMP nsDOMTCPSocket::GetOnclose(JS::Value *aOnclose)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMTCPSocket::SetOnclose(const JS::Value & aOnclose)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITCPSocketInternal */
#define NS_ITCPSOCKETINTERNAL_IID_STR "fff9ed4a-5e94-4fc0-84e4-7f4d35d0a26c"

#define NS_ITCPSOCKETINTERNAL_IID \
  {0xfff9ed4a, 0x5e94, 0x4fc0, \
    { 0x84, 0xe4, 0x7f, 0x4d, 0x35, 0xd0, 0xa2, 0x6c }}

class NS_NO_VTABLE nsITCPSocketInternal : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITCPSOCKETINTERNAL_IID)

  /* void callListenerError (in DOMString type, in DOMString message, in DOMString filename, in uint32_t lineNumber, in uint32_t columnNumber); */
  NS_IMETHOD CallListenerError(const nsAString & type, const nsAString & message, const nsAString & filename, uint32_t lineNumber, uint32_t columnNumber) = 0;

  /* void callListenerData (in DOMString type, in DOMString data); */
  NS_IMETHOD CallListenerData(const nsAString & type, const nsAString & data) = 0;

  /* void callListenerArrayBuffer (in DOMString type, in jsval data); */
  NS_IMETHOD CallListenerArrayBuffer(const nsAString & type, const JS::Value & data) = 0;

  /* void callListenerVoid (in DOMString type); */
  NS_IMETHOD CallListenerVoid(const nsAString & type) = 0;

  /* void updateReadyStateAndBuffered (in DOMString readyState, in uint32_t bufferedAmount); */
  NS_IMETHOD UpdateReadyStateAndBuffered(const nsAString & readyState, uint32_t bufferedAmount) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITCPSocketInternal, NS_ITCPSOCKETINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITCPSOCKETINTERNAL \
  NS_IMETHOD CallListenerError(const nsAString & type, const nsAString & message, const nsAString & filename, uint32_t lineNumber, uint32_t columnNumber); \
  NS_IMETHOD CallListenerData(const nsAString & type, const nsAString & data); \
  NS_IMETHOD CallListenerArrayBuffer(const nsAString & type, const JS::Value & data); \
  NS_IMETHOD CallListenerVoid(const nsAString & type); \
  NS_IMETHOD UpdateReadyStateAndBuffered(const nsAString & readyState, uint32_t bufferedAmount); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITCPSOCKETINTERNAL(_to) \
  NS_IMETHOD CallListenerError(const nsAString & type, const nsAString & message, const nsAString & filename, uint32_t lineNumber, uint32_t columnNumber) { return _to CallListenerError(type, message, filename, lineNumber, columnNumber); } \
  NS_IMETHOD CallListenerData(const nsAString & type, const nsAString & data) { return _to CallListenerData(type, data); } \
  NS_IMETHOD CallListenerArrayBuffer(const nsAString & type, const JS::Value & data) { return _to CallListenerArrayBuffer(type, data); } \
  NS_IMETHOD CallListenerVoid(const nsAString & type) { return _to CallListenerVoid(type); } \
  NS_IMETHOD UpdateReadyStateAndBuffered(const nsAString & readyState, uint32_t bufferedAmount) { return _to UpdateReadyStateAndBuffered(readyState, bufferedAmount); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITCPSOCKETINTERNAL(_to) \
  NS_IMETHOD CallListenerError(const nsAString & type, const nsAString & message, const nsAString & filename, uint32_t lineNumber, uint32_t columnNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->CallListenerError(type, message, filename, lineNumber, columnNumber); } \
  NS_IMETHOD CallListenerData(const nsAString & type, const nsAString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->CallListenerData(type, data); } \
  NS_IMETHOD CallListenerArrayBuffer(const nsAString & type, const JS::Value & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->CallListenerArrayBuffer(type, data); } \
  NS_IMETHOD CallListenerVoid(const nsAString & type) { return !_to ? NS_ERROR_NULL_POINTER : _to->CallListenerVoid(type); } \
  NS_IMETHOD UpdateReadyStateAndBuffered(const nsAString & readyState, uint32_t bufferedAmount) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateReadyStateAndBuffered(readyState, bufferedAmount); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTCPSocketInternal : public nsITCPSocketInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITCPSOCKETINTERNAL

  nsTCPSocketInternal();

private:
  ~nsTCPSocketInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTCPSocketInternal, nsITCPSocketInternal)

nsTCPSocketInternal::nsTCPSocketInternal()
{
  /* member initializers and constructor code */
}

nsTCPSocketInternal::~nsTCPSocketInternal()
{
  /* destructor code */
}

/* void callListenerError (in DOMString type, in DOMString message, in DOMString filename, in uint32_t lineNumber, in uint32_t columnNumber); */
NS_IMETHODIMP nsTCPSocketInternal::CallListenerError(const nsAString & type, const nsAString & message, const nsAString & filename, uint32_t lineNumber, uint32_t columnNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void callListenerData (in DOMString type, in DOMString data); */
NS_IMETHODIMP nsTCPSocketInternal::CallListenerData(const nsAString & type, const nsAString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void callListenerArrayBuffer (in DOMString type, in jsval data); */
NS_IMETHODIMP nsTCPSocketInternal::CallListenerArrayBuffer(const nsAString & type, const JS::Value & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void callListenerVoid (in DOMString type); */
NS_IMETHODIMP nsTCPSocketInternal::CallListenerVoid(const nsAString & type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateReadyStateAndBuffered (in DOMString readyState, in uint32_t bufferedAmount); */
NS_IMETHODIMP nsTCPSocketInternal::UpdateReadyStateAndBuffered(const nsAString & readyState, uint32_t bufferedAmount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITCPSocketEvent */
#define NS_ITCPSOCKETEVENT_IID_STR "0f2abcca-b483-4539-a3e8-345707f75c44"

#define NS_ITCPSOCKETEVENT_IID \
  {0x0f2abcca, 0xb483, 0x4539, \
    { 0xa3, 0xe8, 0x34, 0x57, 0x07, 0xf7, 0x5c, 0x44 }}

class NS_NO_VTABLE nsITCPSocketEvent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITCPSOCKETEVENT_IID)

  /* readonly attribute nsIDOMTCPSocket target; */
  NS_IMETHOD GetTarget(nsIDOMTCPSocket * *aTarget) = 0;

  /* readonly attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;

  /* readonly attribute jsval data; */
  NS_IMETHOD GetData(JS::Value *aData) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITCPSocketEvent, NS_ITCPSOCKETEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITCPSOCKETEVENT \
  NS_IMETHOD GetTarget(nsIDOMTCPSocket * *aTarget); \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD GetData(JS::Value *aData); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITCPSOCKETEVENT(_to) \
  NS_IMETHOD GetTarget(nsIDOMTCPSocket * *aTarget) { return _to GetTarget(aTarget); } \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD GetData(JS::Value *aData) { return _to GetData(aData); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITCPSOCKETEVENT(_to) \
  NS_IMETHOD GetTarget(nsIDOMTCPSocket * *aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTarget(aTarget); } \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetData(JS::Value *aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aData); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTCPSocketEvent : public nsITCPSocketEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITCPSOCKETEVENT

  nsTCPSocketEvent();

private:
  ~nsTCPSocketEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTCPSocketEvent, nsITCPSocketEvent)

nsTCPSocketEvent::nsTCPSocketEvent()
{
  /* member initializers and constructor code */
}

nsTCPSocketEvent::~nsTCPSocketEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMTCPSocket target; */
NS_IMETHODIMP nsTCPSocketEvent::GetTarget(nsIDOMTCPSocket * *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString type; */
NS_IMETHODIMP nsTCPSocketEvent::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsval data; */
NS_IMETHODIMP nsTCPSocketEvent::GetData(JS::Value *aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMTCPSocket_h__ */

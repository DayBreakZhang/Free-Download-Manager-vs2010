/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/content/base/public/nsIWebSocket.idl
 */

#ifndef __gen_nsIWebSocket_h__
#define __gen_nsIWebSocket_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMEventListener; /* forward declaration */

class nsIPrincipal; /* forward declaration */

class nsIScriptContext; /* forward declaration */

class nsPIDOMWindow; /* forward declaration */


/* starting interface:    nsIWebSocket */
#define NS_IWEBSOCKET_IID_STR "4403cd57-07fc-477f-a062-d6ba7dd0781b"

#define NS_IWEBSOCKET_IID \
  {0x4403cd57, 0x07fc, 0x477f, \
    { 0xa0, 0x62, 0xd6, 0xba, 0x7d, 0xd0, 0x78, 0x1b }}

/**
 * The nsIWebSocket interface enables Web applications to maintain
 * bidirectional communications with server-side processes as described in:
 *
 * http://dev.w3.org/html5/websockets/
 *
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIWebSocket : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBSOCKET_IID)

  /* readonly attribute DOMString url; */
  NS_SCRIPTABLE NS_IMETHOD GetUrl(nsAString & aUrl) = 0;

  enum { CONNECTING = 0U };

  enum { OPEN = 1U };

  enum { CLOSING = 2U };

  enum { CLOSED = 3U };

  /* readonly attribute unsigned short readyState; */
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(PRUint16 *aReadyState) = 0;

  /* readonly attribute unsigned long bufferedAmount; */
  NS_SCRIPTABLE NS_IMETHOD GetBufferedAmount(PRUint32 *aBufferedAmount) = 0;

  /* attribute nsIDOMEventListener onopen; */
  NS_SCRIPTABLE NS_IMETHOD GetOnopen(nsIDOMEventListener **aOnopen) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnopen(nsIDOMEventListener *aOnopen) = 0;

  /* attribute nsIDOMEventListener onmessage; */
  NS_SCRIPTABLE NS_IMETHOD GetOnmessage(nsIDOMEventListener **aOnmessage) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnmessage(nsIDOMEventListener *aOnmessage) = 0;

  /* attribute nsIDOMEventListener onerror; */
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener **aOnerror) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror) = 0;

  /* attribute nsIDOMEventListener onclose; */
  NS_SCRIPTABLE NS_IMETHOD GetOnclose(nsIDOMEventListener **aOnclose) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnclose(nsIDOMEventListener *aOnclose) = 0;

  /**
   * Transmits data using the connection.
   *
   * @param data The data to be transmited.
   * @return if the connection is still established (and the data was queued or
   *         sent successfully).
   */
  /* boolean send (in DOMString data); */
  NS_SCRIPTABLE NS_IMETHOD Send(const nsAString & data, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Closes the Web Socket connection or connection attempt, if any.
   * If the connection is already closed, it does nothing.
   */
  /* void close (); */
  NS_SCRIPTABLE NS_IMETHOD Close(void) = 0;

  /**
   * Initialize the object for use from C++ code with the principal, script
   * context, and owner window that should be used.
   *
   * @param principal The principal to use for the request. This must not be
   *                  null.
   * @param scriptContext The script context to use for the request. May be
   *                      null.
   * @param ownerWindow The associated window for the request. May be null.
   * @param url The url for opening the socket. This must not be empty, and
   *            must have an absolute url, using either the ws or wss schemes.
   * @param protocol  Specifies a sub-protocol that the server must support for
   *                  the connection to be successful. If empty, no protocol is
   *                  specified.
   */
  /* [noscript] void init (in nsIPrincipal principal, in nsIScriptContext scriptContext, in nsPIDOMWindow ownerWindow, in DOMString url, in DOMString protocol); */
  NS_IMETHOD Init(nsIPrincipal *principal, nsIScriptContext *scriptContext, nsPIDOMWindow *ownerWindow, const nsAString & url, const nsAString & protocol) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebSocket, NS_IWEBSOCKET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBSOCKET \
  NS_SCRIPTABLE NS_IMETHOD GetUrl(nsAString & aUrl); \
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(PRUint16 *aReadyState); \
  NS_SCRIPTABLE NS_IMETHOD GetBufferedAmount(PRUint32 *aBufferedAmount); \
  NS_SCRIPTABLE NS_IMETHOD GetOnopen(nsIDOMEventListener **aOnopen); \
  NS_SCRIPTABLE NS_IMETHOD SetOnopen(nsIDOMEventListener *aOnopen); \
  NS_SCRIPTABLE NS_IMETHOD GetOnmessage(nsIDOMEventListener **aOnmessage); \
  NS_SCRIPTABLE NS_IMETHOD SetOnmessage(nsIDOMEventListener *aOnmessage); \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener **aOnerror); \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror); \
  NS_SCRIPTABLE NS_IMETHOD GetOnclose(nsIDOMEventListener **aOnclose); \
  NS_SCRIPTABLE NS_IMETHOD SetOnclose(nsIDOMEventListener *aOnclose); \
  NS_SCRIPTABLE NS_IMETHOD Send(const nsAString & data, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Close(void); \
  NS_IMETHOD Init(nsIPrincipal *principal, nsIScriptContext *scriptContext, nsPIDOMWindow *ownerWindow, const nsAString & url, const nsAString & protocol); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBSOCKET(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetUrl(nsAString & aUrl) { return _to GetUrl(aUrl); } \
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(PRUint16 *aReadyState) { return _to GetReadyState(aReadyState); } \
  NS_SCRIPTABLE NS_IMETHOD GetBufferedAmount(PRUint32 *aBufferedAmount) { return _to GetBufferedAmount(aBufferedAmount); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnopen(nsIDOMEventListener **aOnopen) { return _to GetOnopen(aOnopen); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnopen(nsIDOMEventListener *aOnopen) { return _to SetOnopen(aOnopen); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnmessage(nsIDOMEventListener **aOnmessage) { return _to GetOnmessage(aOnmessage); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnmessage(nsIDOMEventListener *aOnmessage) { return _to SetOnmessage(aOnmessage); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener **aOnerror) { return _to GetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror) { return _to SetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnclose(nsIDOMEventListener **aOnclose) { return _to GetOnclose(aOnclose); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnclose(nsIDOMEventListener *aOnclose) { return _to SetOnclose(aOnclose); } \
  NS_SCRIPTABLE NS_IMETHOD Send(const nsAString & data, PRBool *_retval NS_OUTPARAM) { return _to Send(data, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return _to Close(); } \
  NS_IMETHOD Init(nsIPrincipal *principal, nsIScriptContext *scriptContext, nsPIDOMWindow *ownerWindow, const nsAString & url, const nsAString & protocol) { return _to Init(principal, scriptContext, ownerWindow, url, protocol); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBSOCKET(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetUrl(nsAString & aUrl) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUrl(aUrl); } \
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(PRUint16 *aReadyState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReadyState(aReadyState); } \
  NS_SCRIPTABLE NS_IMETHOD GetBufferedAmount(PRUint32 *aBufferedAmount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBufferedAmount(aBufferedAmount); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnopen(nsIDOMEventListener **aOnopen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnopen(aOnopen); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnopen(nsIDOMEventListener *aOnopen) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnopen(aOnopen); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnmessage(nsIDOMEventListener **aOnmessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmessage(aOnmessage); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnmessage(nsIDOMEventListener *aOnmessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmessage(aOnmessage); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener **aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnclose(nsIDOMEventListener **aOnclose) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnclose(aOnclose); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnclose(nsIDOMEventListener *aOnclose) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnclose(aOnclose); } \
  NS_SCRIPTABLE NS_IMETHOD Send(const nsAString & data, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Send(data, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_IMETHOD Init(nsIPrincipal *principal, nsIScriptContext *scriptContext, nsPIDOMWindow *ownerWindow, const nsAString & url, const nsAString & protocol) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(principal, scriptContext, ownerWindow, url, protocol); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebSocket : public nsIWebSocket
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBSOCKET

  nsWebSocket();

private:
  ~nsWebSocket();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebSocket, nsIWebSocket)

nsWebSocket::nsWebSocket()
{
  /* member initializers and constructor code */
}

nsWebSocket::~nsWebSocket()
{
  /* destructor code */
}

/* readonly attribute DOMString url; */
NS_IMETHODIMP nsWebSocket::GetUrl(nsAString & aUrl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short readyState; */
NS_IMETHODIMP nsWebSocket::GetReadyState(PRUint16 *aReadyState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long bufferedAmount; */
NS_IMETHODIMP nsWebSocket::GetBufferedAmount(PRUint32 *aBufferedAmount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onopen; */
NS_IMETHODIMP nsWebSocket::GetOnopen(nsIDOMEventListener **aOnopen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebSocket::SetOnopen(nsIDOMEventListener *aOnopen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onmessage; */
NS_IMETHODIMP nsWebSocket::GetOnmessage(nsIDOMEventListener **aOnmessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebSocket::SetOnmessage(nsIDOMEventListener *aOnmessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onerror; */
NS_IMETHODIMP nsWebSocket::GetOnerror(nsIDOMEventListener **aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebSocket::SetOnerror(nsIDOMEventListener *aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onclose; */
NS_IMETHODIMP nsWebSocket::GetOnclose(nsIDOMEventListener **aOnclose)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebSocket::SetOnclose(nsIDOMEventListener *aOnclose)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean send (in DOMString data); */
NS_IMETHODIMP nsWebSocket::Send(const nsAString & data, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsWebSocket::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void init (in nsIPrincipal principal, in nsIScriptContext scriptContext, in nsPIDOMWindow ownerWindow, in DOMString url, in DOMString protocol); */
NS_IMETHODIMP nsWebSocket::Init(nsIPrincipal *principal, nsIScriptContext *scriptContext, nsPIDOMWindow *ownerWindow, const nsAString & url, const nsAString & protocol)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebSocket_h__ */

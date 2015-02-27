/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIXMLHttpRequest.idl
 */

#ifndef __gen_nsIXMLHttpRequest_h__
#define __gen_nsIXMLHttpRequest_h__


#ifndef __gen_nsIDOMEventTarget_h__
#include "nsIDOMEventTarget.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIChannel; /* forward declaration */

class nsIDOMDocument; /* forward declaration */

class nsIDOMEventListener; /* forward declaration */

class nsIPrincipal; /* forward declaration */

class nsIScriptContext; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIVariant; /* forward declaration */

class nsIGlobalObject; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIDOMBlob; /* forward declaration */


/* starting interface:    nsIXMLHttpRequestEventTarget */
#define NS_IXMLHTTPREQUESTEVENTTARGET_IID_STR "5ced7e7a-e2c3-4563-a57d-31b97ce64dc5"

#define NS_IXMLHTTPREQUESTEVENTTARGET_IID \
  {0x5ced7e7a, 0xe2c3, 0x4563, \
    { 0xa5, 0x7d, 0x31, 0xb9, 0x7c, 0xe6, 0x4d, 0xc5 }}

class NS_NO_VTABLE nsIXMLHttpRequestEventTarget : public nsIDOMEventTarget {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXMLHTTPREQUESTEVENTTARGET_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXMLHttpRequestEventTarget, NS_IXMLHTTPREQUESTEVENTTARGET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXMLHTTPREQUESTEVENTTARGET \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXMLHTTPREQUESTEVENTTARGET(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXMLHTTPREQUESTEVENTTARGET(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXMLHttpRequestEventTarget : public nsIXMLHttpRequestEventTarget
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXMLHTTPREQUESTEVENTTARGET

  nsXMLHttpRequestEventTarget();

private:
  ~nsXMLHttpRequestEventTarget();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXMLHttpRequestEventTarget, nsIXMLHttpRequestEventTarget)

nsXMLHttpRequestEventTarget::nsXMLHttpRequestEventTarget()
{
  /* member initializers and constructor code */
}

nsXMLHttpRequestEventTarget::~nsXMLHttpRequestEventTarget()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXMLHttpRequestUpload */
#define NS_IXMLHTTPREQUESTUPLOAD_IID_STR "df3796fa-d98a-4185-9dda-d2f2b56a5d38"

#define NS_IXMLHTTPREQUESTUPLOAD_IID \
  {0xdf3796fa, 0xd98a, 0x4185, \
    { 0x9d, 0xda, 0xd2, 0xf2, 0xb5, 0x6a, 0x5d, 0x38 }}

class NS_NO_VTABLE nsIXMLHttpRequestUpload : public nsIXMLHttpRequestEventTarget {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXMLHTTPREQUESTUPLOAD_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXMLHttpRequestUpload, NS_IXMLHTTPREQUESTUPLOAD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXMLHTTPREQUESTUPLOAD \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXMLHTTPREQUESTUPLOAD(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXMLHTTPREQUESTUPLOAD(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXMLHttpRequestUpload : public nsIXMLHttpRequestUpload
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXMLHTTPREQUESTUPLOAD

  nsXMLHttpRequestUpload();

private:
  ~nsXMLHttpRequestUpload();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXMLHttpRequestUpload, nsIXMLHttpRequestUpload)

nsXMLHttpRequestUpload::nsXMLHttpRequestUpload()
{
  /* member initializers and constructor code */
}

nsXMLHttpRequestUpload::~nsXMLHttpRequestUpload()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXMLHttpRequest */
#define NS_IXMLHTTPREQUEST_IID_STR "2e91e088-e9fa-4ba4-9887-2a0b7cf27a3e"

#define NS_IXMLHTTPREQUEST_IID \
  {0x2e91e088, 0xe9fa, 0x4ba4, \
    { 0x98, 0x87, 0x2a, 0x0b, 0x7c, 0xf2, 0x7a, 0x3e }}

class nsIXMLHttpRequest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXMLHTTPREQUEST_IID)

  /* readonly attribute nsIChannel channel; */
  NS_IMETHOD GetChannel(nsIChannel * *aChannel) = 0;

  /* readonly attribute nsIDOMDocument responseXML; */
  NS_IMETHOD GetResponseXML(nsIDOMDocument * *aResponseXML) = 0;

  /* readonly attribute AString responseText; */
  NS_IMETHOD GetResponseText(nsAString & aResponseText) = 0;

  /* attribute AString responseType; */
  NS_IMETHOD GetResponseType(nsAString & aResponseType) = 0;
  NS_IMETHOD SetResponseType(const nsAString & aResponseType) = 0;

  /* [implicit_jscontext] readonly attribute jsval response; */
  NS_IMETHOD GetResponse(JSContext* cx, JS::MutableHandleValue aResponse) = 0;

  /* readonly attribute unsigned long status; */
  NS_IMETHOD GetStatus(uint32_t *aStatus) = 0;

  /* readonly attribute ACString statusText; */
  NS_IMETHOD GetStatusText(nsACString & aStatusText) = 0;

  /* [binaryname(SlowAbort)] void abort (); */
  NS_IMETHOD SlowAbort(void) = 0;

  /* ACString getAllResponseHeaders (); */
  NS_IMETHOD GetAllResponseHeaders(nsACString & _retval) = 0;

  /* ACString getResponseHeader (in ACString header); */
  NS_IMETHOD GetResponseHeader(const nsACString & header, nsACString & _retval) = 0;

   // note this is NOT virtual so this won't muck with the vtable!
  inline nsresult Open(const nsACString& method, const nsACString& url,
                       bool async, const nsAString& user,
                       const nsAString& password) {
    return Open(method, url, async, user, password, 3);
  }
  /* [optional_argc] void open (in ACString method, in AUTF8String url, [optional] in boolean async, [optional, Undefined (Empty)] in DOMString user, [optional, Undefined (Empty)] in DOMString password); */
  NS_IMETHOD Open(const nsACString & method, const nsACString & url, bool async, const nsAString & user, const nsAString & password, uint8_t _argc) = 0;

  /* void send ([optional] in nsIVariant body); */
  NS_IMETHOD Send(nsIVariant *body) = 0;

  /* void sendAsBinary (in DOMString body); */
  NS_IMETHOD SendAsBinary(const nsAString & body) = 0;

  /* void setRequestHeader (in ACString header, in ACString value); */
  NS_IMETHOD SetRequestHeader(const nsACString & header, const nsACString & value) = 0;

  /* attribute unsigned long timeout; */
  NS_IMETHOD GetTimeout(uint32_t *aTimeout) = 0;
  NS_IMETHOD SetTimeout(uint32_t aTimeout) = 0;

  enum {
    UNSENT = 0U,
    OPENED = 1U,
    HEADERS_RECEIVED = 2U,
    LOADING = 3U,
    DONE = 4U
  };

  /* readonly attribute unsigned short readyState; */
  NS_IMETHOD GetReadyState(uint16_t *aReadyState) = 0;

  /* [binaryname(SlowOverrideMimeType)] void overrideMimeType (in DOMString mimetype); */
  NS_IMETHOD SlowOverrideMimeType(const nsAString & mimetype) = 0;

  /* attribute boolean mozBackgroundRequest; */
  NS_IMETHOD GetMozBackgroundRequest(bool *aMozBackgroundRequest) = 0;
  NS_IMETHOD SetMozBackgroundRequest(bool aMozBackgroundRequest) = 0;

  /* attribute boolean withCredentials; */
  NS_IMETHOD GetWithCredentials(bool *aWithCredentials) = 0;
  NS_IMETHOD SetWithCredentials(bool aWithCredentials) = 0;

  /* [noscript] void init (in nsIPrincipal principal, in nsIScriptContext scriptContext, in nsIGlobalObject globalObject, in nsIURI baseURI); */
  NS_IMETHOD Init(nsIPrincipal *principal, nsIScriptContext *scriptContext, nsIGlobalObject *globalObject, nsIURI *baseURI) = 0;

  /* readonly attribute nsIXMLHttpRequestUpload upload; */
  NS_IMETHOD GetUpload(nsIXMLHttpRequestUpload * *aUpload) = 0;

  /* [implicit_jscontext] attribute jsval onreadystatechange; */
  NS_IMETHOD GetOnreadystatechange(JSContext* cx, JS::MutableHandleValue aOnreadystatechange) = 0;
  NS_IMETHOD SetOnreadystatechange(JSContext* cx, JS::HandleValue aOnreadystatechange) = 0;

  /* readonly attribute boolean mozAnon; */
  NS_IMETHOD GetMozAnon(bool *aMozAnon) = 0;

  /* readonly attribute boolean mozSystem; */
  NS_IMETHOD GetMozSystem(bool *aMozSystem) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXMLHttpRequest, NS_IXMLHTTPREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXMLHTTPREQUEST \
  NS_IMETHOD GetChannel(nsIChannel * *aChannel); \
  NS_IMETHOD GetResponseXML(nsIDOMDocument * *aResponseXML); \
  NS_IMETHOD GetResponseText(nsAString & aResponseText); \
  NS_IMETHOD GetResponseType(nsAString & aResponseType); \
  NS_IMETHOD SetResponseType(const nsAString & aResponseType); \
  NS_IMETHOD GetResponse(JSContext* cx, JS::MutableHandleValue aResponse); \
  NS_IMETHOD GetStatus(uint32_t *aStatus); \
  NS_IMETHOD GetStatusText(nsACString & aStatusText); \
  NS_IMETHOD SlowAbort(void); \
  NS_IMETHOD GetAllResponseHeaders(nsACString & _retval); \
  NS_IMETHOD GetResponseHeader(const nsACString & header, nsACString & _retval); \
  NS_IMETHOD Open(const nsACString & method, const nsACString & url, bool async, const nsAString & user, const nsAString & password, uint8_t _argc); \
  NS_IMETHOD Send(nsIVariant *body); \
  NS_IMETHOD SendAsBinary(const nsAString & body); \
  NS_IMETHOD SetRequestHeader(const nsACString & header, const nsACString & value); \
  NS_IMETHOD GetTimeout(uint32_t *aTimeout); \
  NS_IMETHOD SetTimeout(uint32_t aTimeout); \
  NS_IMETHOD GetReadyState(uint16_t *aReadyState); \
  NS_IMETHOD SlowOverrideMimeType(const nsAString & mimetype); \
  NS_IMETHOD GetMozBackgroundRequest(bool *aMozBackgroundRequest); \
  NS_IMETHOD SetMozBackgroundRequest(bool aMozBackgroundRequest); \
  NS_IMETHOD GetWithCredentials(bool *aWithCredentials); \
  NS_IMETHOD SetWithCredentials(bool aWithCredentials); \
  NS_IMETHOD Init(nsIPrincipal *principal, nsIScriptContext *scriptContext, nsIGlobalObject *globalObject, nsIURI *baseURI); \
  NS_IMETHOD GetUpload(nsIXMLHttpRequestUpload * *aUpload); \
  NS_IMETHOD GetOnreadystatechange(JSContext* cx, JS::MutableHandleValue aOnreadystatechange); \
  NS_IMETHOD SetOnreadystatechange(JSContext* cx, JS::HandleValue aOnreadystatechange); \
  NS_IMETHOD GetMozAnon(bool *aMozAnon); \
  NS_IMETHOD GetMozSystem(bool *aMozSystem); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXMLHTTPREQUEST(_to) \
  NS_IMETHOD GetChannel(nsIChannel * *aChannel) { return _to GetChannel(aChannel); } \
  NS_IMETHOD GetResponseXML(nsIDOMDocument * *aResponseXML) { return _to GetResponseXML(aResponseXML); } \
  NS_IMETHOD GetResponseText(nsAString & aResponseText) { return _to GetResponseText(aResponseText); } \
  NS_IMETHOD GetResponseType(nsAString & aResponseType) { return _to GetResponseType(aResponseType); } \
  NS_IMETHOD SetResponseType(const nsAString & aResponseType) { return _to SetResponseType(aResponseType); } \
  NS_IMETHOD GetResponse(JSContext* cx, JS::MutableHandleValue aResponse) { return _to GetResponse(cx, aResponse); } \
  NS_IMETHOD GetStatus(uint32_t *aStatus) { return _to GetStatus(aStatus); } \
  NS_IMETHOD GetStatusText(nsACString & aStatusText) { return _to GetStatusText(aStatusText); } \
  NS_IMETHOD SlowAbort(void) { return _to SlowAbort(); } \
  NS_IMETHOD GetAllResponseHeaders(nsACString & _retval) { return _to GetAllResponseHeaders(_retval); } \
  NS_IMETHOD GetResponseHeader(const nsACString & header, nsACString & _retval) { return _to GetResponseHeader(header, _retval); } \
  NS_IMETHOD Open(const nsACString & method, const nsACString & url, bool async, const nsAString & user, const nsAString & password, uint8_t _argc) { return _to Open(method, url, async, user, password, _argc); } \
  NS_IMETHOD Send(nsIVariant *body) { return _to Send(body); } \
  NS_IMETHOD SendAsBinary(const nsAString & body) { return _to SendAsBinary(body); } \
  NS_IMETHOD SetRequestHeader(const nsACString & header, const nsACString & value) { return _to SetRequestHeader(header, value); } \
  NS_IMETHOD GetTimeout(uint32_t *aTimeout) { return _to GetTimeout(aTimeout); } \
  NS_IMETHOD SetTimeout(uint32_t aTimeout) { return _to SetTimeout(aTimeout); } \
  NS_IMETHOD GetReadyState(uint16_t *aReadyState) { return _to GetReadyState(aReadyState); } \
  NS_IMETHOD SlowOverrideMimeType(const nsAString & mimetype) { return _to SlowOverrideMimeType(mimetype); } \
  NS_IMETHOD GetMozBackgroundRequest(bool *aMozBackgroundRequest) { return _to GetMozBackgroundRequest(aMozBackgroundRequest); } \
  NS_IMETHOD SetMozBackgroundRequest(bool aMozBackgroundRequest) { return _to SetMozBackgroundRequest(aMozBackgroundRequest); } \
  NS_IMETHOD GetWithCredentials(bool *aWithCredentials) { return _to GetWithCredentials(aWithCredentials); } \
  NS_IMETHOD SetWithCredentials(bool aWithCredentials) { return _to SetWithCredentials(aWithCredentials); } \
  NS_IMETHOD Init(nsIPrincipal *principal, nsIScriptContext *scriptContext, nsIGlobalObject *globalObject, nsIURI *baseURI) { return _to Init(principal, scriptContext, globalObject, baseURI); } \
  NS_IMETHOD GetUpload(nsIXMLHttpRequestUpload * *aUpload) { return _to GetUpload(aUpload); } \
  NS_IMETHOD GetOnreadystatechange(JSContext* cx, JS::MutableHandleValue aOnreadystatechange) { return _to GetOnreadystatechange(cx, aOnreadystatechange); } \
  NS_IMETHOD SetOnreadystatechange(JSContext* cx, JS::HandleValue aOnreadystatechange) { return _to SetOnreadystatechange(cx, aOnreadystatechange); } \
  NS_IMETHOD GetMozAnon(bool *aMozAnon) { return _to GetMozAnon(aMozAnon); } \
  NS_IMETHOD GetMozSystem(bool *aMozSystem) { return _to GetMozSystem(aMozSystem); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXMLHTTPREQUEST(_to) \
  NS_IMETHOD GetChannel(nsIChannel * *aChannel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChannel(aChannel); } \
  NS_IMETHOD GetResponseXML(nsIDOMDocument * *aResponseXML) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseXML(aResponseXML); } \
  NS_IMETHOD GetResponseText(nsAString & aResponseText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseText(aResponseText); } \
  NS_IMETHOD GetResponseType(nsAString & aResponseType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseType(aResponseType); } \
  NS_IMETHOD SetResponseType(const nsAString & aResponseType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetResponseType(aResponseType); } \
  NS_IMETHOD GetResponse(JSContext* cx, JS::MutableHandleValue aResponse) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponse(cx, aResponse); } \
  NS_IMETHOD GetStatus(uint32_t *aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatus(aStatus); } \
  NS_IMETHOD GetStatusText(nsACString & aStatusText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatusText(aStatusText); } \
  NS_IMETHOD SlowAbort(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SlowAbort(); } \
  NS_IMETHOD GetAllResponseHeaders(nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllResponseHeaders(_retval); } \
  NS_IMETHOD GetResponseHeader(const nsACString & header, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseHeader(header, _retval); } \
  NS_IMETHOD Open(const nsACString & method, const nsACString & url, bool async, const nsAString & user, const nsAString & password, uint8_t _argc) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(method, url, async, user, password, _argc); } \
  NS_IMETHOD Send(nsIVariant *body) { return !_to ? NS_ERROR_NULL_POINTER : _to->Send(body); } \
  NS_IMETHOD SendAsBinary(const nsAString & body) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendAsBinary(body); } \
  NS_IMETHOD SetRequestHeader(const nsACString & header, const nsACString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRequestHeader(header, value); } \
  NS_IMETHOD GetTimeout(uint32_t *aTimeout) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimeout(aTimeout); } \
  NS_IMETHOD SetTimeout(uint32_t aTimeout) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTimeout(aTimeout); } \
  NS_IMETHOD GetReadyState(uint16_t *aReadyState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReadyState(aReadyState); } \
  NS_IMETHOD SlowOverrideMimeType(const nsAString & mimetype) { return !_to ? NS_ERROR_NULL_POINTER : _to->SlowOverrideMimeType(mimetype); } \
  NS_IMETHOD GetMozBackgroundRequest(bool *aMozBackgroundRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozBackgroundRequest(aMozBackgroundRequest); } \
  NS_IMETHOD SetMozBackgroundRequest(bool aMozBackgroundRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMozBackgroundRequest(aMozBackgroundRequest); } \
  NS_IMETHOD GetWithCredentials(bool *aWithCredentials) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWithCredentials(aWithCredentials); } \
  NS_IMETHOD SetWithCredentials(bool aWithCredentials) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWithCredentials(aWithCredentials); } \
  NS_IMETHOD Init(nsIPrincipal *principal, nsIScriptContext *scriptContext, nsIGlobalObject *globalObject, nsIURI *baseURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(principal, scriptContext, globalObject, baseURI); } \
  NS_IMETHOD GetUpload(nsIXMLHttpRequestUpload * *aUpload) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpload(aUpload); } \
  NS_IMETHOD GetOnreadystatechange(JSContext* cx, JS::MutableHandleValue aOnreadystatechange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnreadystatechange(cx, aOnreadystatechange); } \
  NS_IMETHOD SetOnreadystatechange(JSContext* cx, JS::HandleValue aOnreadystatechange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnreadystatechange(cx, aOnreadystatechange); } \
  NS_IMETHOD GetMozAnon(bool *aMozAnon) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozAnon(aMozAnon); } \
  NS_IMETHOD GetMozSystem(bool *aMozSystem) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozSystem(aMozSystem); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXMLHttpRequest : public nsIXMLHttpRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXMLHTTPREQUEST

  nsXMLHttpRequest();

private:
  ~nsXMLHttpRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXMLHttpRequest, nsIXMLHttpRequest)

nsXMLHttpRequest::nsXMLHttpRequest()
{
  /* member initializers and constructor code */
}

nsXMLHttpRequest::~nsXMLHttpRequest()
{
  /* destructor code */
}

/* readonly attribute nsIChannel channel; */
NS_IMETHODIMP nsXMLHttpRequest::GetChannel(nsIChannel * *aChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDocument responseXML; */
NS_IMETHODIMP nsXMLHttpRequest::GetResponseXML(nsIDOMDocument * *aResponseXML)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString responseText; */
NS_IMETHODIMP nsXMLHttpRequest::GetResponseText(nsAString & aResponseText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString responseType; */
NS_IMETHODIMP nsXMLHttpRequest::GetResponseType(nsAString & aResponseType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXMLHttpRequest::SetResponseType(const nsAString & aResponseType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval response; */
NS_IMETHODIMP nsXMLHttpRequest::GetResponse(JSContext* cx, JS::MutableHandleValue aResponse)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long status; */
NS_IMETHODIMP nsXMLHttpRequest::GetStatus(uint32_t *aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString statusText; */
NS_IMETHODIMP nsXMLHttpRequest::GetStatusText(nsACString & aStatusText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(SlowAbort)] void abort (); */
NS_IMETHODIMP nsXMLHttpRequest::SlowAbort()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getAllResponseHeaders (); */
NS_IMETHODIMP nsXMLHttpRequest::GetAllResponseHeaders(nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getResponseHeader (in ACString header); */
NS_IMETHODIMP nsXMLHttpRequest::GetResponseHeader(const nsACString & header, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] void open (in ACString method, in AUTF8String url, [optional] in boolean async, [optional, Undefined (Empty)] in DOMString user, [optional, Undefined (Empty)] in DOMString password); */
NS_IMETHODIMP nsXMLHttpRequest::Open(const nsACString & method, const nsACString & url, bool async, const nsAString & user, const nsAString & password, uint8_t _argc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void send ([optional] in nsIVariant body); */
NS_IMETHODIMP nsXMLHttpRequest::Send(nsIVariant *body)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendAsBinary (in DOMString body); */
NS_IMETHODIMP nsXMLHttpRequest::SendAsBinary(const nsAString & body)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setRequestHeader (in ACString header, in ACString value); */
NS_IMETHODIMP nsXMLHttpRequest::SetRequestHeader(const nsACString & header, const nsACString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long timeout; */
NS_IMETHODIMP nsXMLHttpRequest::GetTimeout(uint32_t *aTimeout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXMLHttpRequest::SetTimeout(uint32_t aTimeout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short readyState; */
NS_IMETHODIMP nsXMLHttpRequest::GetReadyState(uint16_t *aReadyState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(SlowOverrideMimeType)] void overrideMimeType (in DOMString mimetype); */
NS_IMETHODIMP nsXMLHttpRequest::SlowOverrideMimeType(const nsAString & mimetype)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean mozBackgroundRequest; */
NS_IMETHODIMP nsXMLHttpRequest::GetMozBackgroundRequest(bool *aMozBackgroundRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXMLHttpRequest::SetMozBackgroundRequest(bool aMozBackgroundRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean withCredentials; */
NS_IMETHODIMP nsXMLHttpRequest::GetWithCredentials(bool *aWithCredentials)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXMLHttpRequest::SetWithCredentials(bool aWithCredentials)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void init (in nsIPrincipal principal, in nsIScriptContext scriptContext, in nsIGlobalObject globalObject, in nsIURI baseURI); */
NS_IMETHODIMP nsXMLHttpRequest::Init(nsIPrincipal *principal, nsIScriptContext *scriptContext, nsIGlobalObject *globalObject, nsIURI *baseURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXMLHttpRequestUpload upload; */
NS_IMETHODIMP nsXMLHttpRequest::GetUpload(nsIXMLHttpRequestUpload * *aUpload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onreadystatechange; */
NS_IMETHODIMP nsXMLHttpRequest::GetOnreadystatechange(JSContext* cx, JS::MutableHandleValue aOnreadystatechange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXMLHttpRequest::SetOnreadystatechange(JSContext* cx, JS::HandleValue aOnreadystatechange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean mozAnon; */
NS_IMETHODIMP nsXMLHttpRequest::GetMozAnon(bool *aMozAnon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean mozSystem; */
NS_IMETHODIMP nsXMLHttpRequest::GetMozSystem(bool *aMozSystem)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXHRSendable */
#define NS_IXHRSENDABLE_IID_STR "840d0d00-e83e-4a29-b3c7-67e96e90a499"

#define NS_IXHRSENDABLE_IID \
  {0x840d0d00, 0xe83e, 0x4a29, \
    { 0xb3, 0xc7, 0x67, 0xe9, 0x6e, 0x90, 0xa4, 0x99 }}

class NS_NO_VTABLE nsIXHRSendable : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXHRSENDABLE_IID)

  /* void getSendInfo (out nsIInputStream body, out uint64_t contentLength, out ACString contentType, out ACString charset); */
  NS_IMETHOD GetSendInfo(nsIInputStream * *body, uint64_t *contentLength, nsACString & contentType, nsACString & charset) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXHRSendable, NS_IXHRSENDABLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXHRSENDABLE \
  NS_IMETHOD GetSendInfo(nsIInputStream * *body, uint64_t *contentLength, nsACString & contentType, nsACString & charset); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXHRSENDABLE(_to) \
  NS_IMETHOD GetSendInfo(nsIInputStream * *body, uint64_t *contentLength, nsACString & contentType, nsACString & charset) { return _to GetSendInfo(body, contentLength, contentType, charset); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXHRSENDABLE(_to) \
  NS_IMETHOD GetSendInfo(nsIInputStream * *body, uint64_t *contentLength, nsACString & contentType, nsACString & charset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSendInfo(body, contentLength, contentType, charset); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXHRSendable : public nsIXHRSendable
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXHRSENDABLE

  nsXHRSendable();

private:
  ~nsXHRSendable();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXHRSendable, nsIXHRSendable)

nsXHRSendable::nsXHRSendable()
{
  /* member initializers and constructor code */
}

nsXHRSendable::~nsXHRSendable()
{
  /* destructor code */
}

/* void getSendInfo (out nsIInputStream body, out uint64_t contentLength, out ACString contentType, out ACString charset); */
NS_IMETHODIMP nsXHRSendable::GetSendInfo(nsIInputStream * *body, uint64_t *contentLength, nsACString & contentType, nsACString & charset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIJSXMLHttpRequest */
#define NS_IJSXMLHTTPREQUEST_IID_STR "8ae70a39-edf1-40b4-a992-472d23421c25"

#define NS_IJSXMLHTTPREQUEST_IID \
  {0x8ae70a39, 0xedf1, 0x40b4, \
    { 0xa9, 0x92, 0x47, 0x2d, 0x23, 0x42, 0x1c, 0x25 }}

class NS_NO_VTABLE nsIJSXMLHttpRequest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJSXMLHTTPREQUEST_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJSXMLHttpRequest, NS_IJSXMLHTTPREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJSXMLHTTPREQUEST \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJSXMLHTTPREQUEST(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJSXMLHTTPREQUEST(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJSXMLHttpRequest : public nsIJSXMLHttpRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJSXMLHTTPREQUEST

  nsJSXMLHttpRequest();

private:
  ~nsJSXMLHttpRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJSXMLHttpRequest, nsIJSXMLHttpRequest)

nsJSXMLHttpRequest::nsJSXMLHttpRequest()
{
  /* member initializers and constructor code */
}

nsJSXMLHttpRequest::~nsJSXMLHttpRequest()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif

#define NS_XMLHTTPREQUEST_CID                       \
 { /* d164e770-4157-11d4-9a42-000064657374 */       \
  0xd164e770, 0x4157, 0x11d4,                       \
 {0x9a, 0x42, 0x00, 0x00, 0x64, 0x65, 0x73, 0x74} }
#define NS_XMLHTTPREQUEST_CONTRACTID \
"@mozilla.org/xmlextras/xmlhttprequest;1"

#endif /* __gen_nsIXMLHttpRequest_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMDOMRequest.idl
 */

#ifndef __gen_nsIDOMDOMRequest_h__
#define __gen_nsIDOMDOMRequest_h__


#ifndef __gen_nsIDOMEventTarget_h__
#include "nsIDOMEventTarget.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIDOMDOMCursor; /* forward declaration */

class nsICursorContinueCallback; /* forward declaration */


/* starting interface:    nsIDOMDOMRequest */
#define NS_IDOMDOMREQUEST_IID_STR "d4c7372a-661c-4798-9a13-af48128609e9"

#define NS_IDOMDOMREQUEST_IID \
  {0xd4c7372a, 0x661c, 0x4798, \
    { 0x9a, 0x13, 0xaf, 0x48, 0x12, 0x86, 0x09, 0xe9 }}

class NS_NO_VTABLE nsIDOMDOMRequest : public nsIDOMEventTarget {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOMREQUEST_IID)

  /* readonly attribute DOMString readyState; */
  NS_IMETHOD GetReadyState(nsAString & aReadyState) = 0;

  /* readonly attribute jsval result; */
  NS_IMETHOD GetResult(JS::MutableHandleValue aResult) = 0;

  /* readonly attribute nsISupports error; */
  NS_IMETHOD GetError(nsISupports * *aError) = 0;

  /* [implicit_jscontext] attribute jsval onsuccess; */
  NS_IMETHOD GetOnsuccess(JSContext* cx, JS::MutableHandleValue aOnsuccess) = 0;
  NS_IMETHOD SetOnsuccess(JSContext* cx, JS::HandleValue aOnsuccess) = 0;

  /* [implicit_jscontext] attribute jsval onerror; */
  NS_IMETHOD GetOnerror(JSContext* cx, JS::MutableHandleValue aOnerror) = 0;
  NS_IMETHOD SetOnerror(JSContext* cx, JS::HandleValue aOnerror) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDOMRequest, NS_IDOMDOMREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOMREQUEST \
  NS_IMETHOD GetReadyState(nsAString & aReadyState); \
  NS_IMETHOD GetResult(JS::MutableHandleValue aResult); \
  NS_IMETHOD GetError(nsISupports * *aError); \
  NS_IMETHOD GetOnsuccess(JSContext* cx, JS::MutableHandleValue aOnsuccess); \
  NS_IMETHOD SetOnsuccess(JSContext* cx, JS::HandleValue aOnsuccess); \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::MutableHandleValue aOnerror); \
  NS_IMETHOD SetOnerror(JSContext* cx, JS::HandleValue aOnerror); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOMREQUEST(_to) \
  NS_IMETHOD GetReadyState(nsAString & aReadyState) { return _to GetReadyState(aReadyState); } \
  NS_IMETHOD GetResult(JS::MutableHandleValue aResult) { return _to GetResult(aResult); } \
  NS_IMETHOD GetError(nsISupports * *aError) { return _to GetError(aError); } \
  NS_IMETHOD GetOnsuccess(JSContext* cx, JS::MutableHandleValue aOnsuccess) { return _to GetOnsuccess(cx, aOnsuccess); } \
  NS_IMETHOD SetOnsuccess(JSContext* cx, JS::HandleValue aOnsuccess) { return _to SetOnsuccess(cx, aOnsuccess); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::MutableHandleValue aOnerror) { return _to GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, JS::HandleValue aOnerror) { return _to SetOnerror(cx, aOnerror); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOMREQUEST(_to) \
  NS_IMETHOD GetReadyState(nsAString & aReadyState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReadyState(aReadyState); } \
  NS_IMETHOD GetResult(JS::MutableHandleValue aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResult(aResult); } \
  NS_IMETHOD GetError(nsISupports * *aError) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetError(aError); } \
  NS_IMETHOD GetOnsuccess(JSContext* cx, JS::MutableHandleValue aOnsuccess) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnsuccess(cx, aOnsuccess); } \
  NS_IMETHOD SetOnsuccess(JSContext* cx, JS::HandleValue aOnsuccess) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnsuccess(cx, aOnsuccess); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::MutableHandleValue aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, JS::HandleValue aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnerror(cx, aOnerror); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDOMRequest : public nsIDOMDOMRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOMREQUEST

  nsDOMDOMRequest();

private:
  ~nsDOMDOMRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDOMRequest, nsIDOMDOMRequest)

nsDOMDOMRequest::nsDOMDOMRequest()
{
  /* member initializers and constructor code */
}

nsDOMDOMRequest::~nsDOMDOMRequest()
{
  /* destructor code */
}

/* readonly attribute DOMString readyState; */
NS_IMETHODIMP nsDOMDOMRequest::GetReadyState(nsAString & aReadyState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsval result; */
NS_IMETHODIMP nsDOMDOMRequest::GetResult(JS::MutableHandleValue aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports error; */
NS_IMETHODIMP nsDOMDOMRequest::GetError(nsISupports * *aError)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onsuccess; */
NS_IMETHODIMP nsDOMDOMRequest::GetOnsuccess(JSContext* cx, JS::MutableHandleValue aOnsuccess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDOMRequest::SetOnsuccess(JSContext* cx, JS::HandleValue aOnsuccess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onerror; */
NS_IMETHODIMP nsDOMDOMRequest::GetOnerror(JSContext* cx, JS::MutableHandleValue aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDOMRequest::SetOnerror(JSContext* cx, JS::HandleValue aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMRequestService */
#define NS_IDOMREQUESTSERVICE_IID_STR "df58d5d6-4b02-4e4c-9b29-adbff06c6206"

#define NS_IDOMREQUESTSERVICE_IID \
  {0xdf58d5d6, 0x4b02, 0x4e4c, \
    { 0x9b, 0x29, 0xad, 0xbf, 0xf0, 0x6c, 0x62, 0x06 }}

class NS_NO_VTABLE nsIDOMRequestService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMREQUESTSERVICE_IID)

  /* nsIDOMDOMRequest createRequest (in nsIDOMWindow window); */
  NS_IMETHOD CreateRequest(nsIDOMWindow *window, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMCursor createCursor (in nsIDOMWindow window, in nsICursorContinueCallback aCallback); */
  NS_IMETHOD CreateCursor(nsIDOMWindow *window, nsICursorContinueCallback *aCallback, nsIDOMDOMCursor * *_retval) = 0;

  /* void fireSuccess (in nsIDOMDOMRequest request, in jsval result); */
  NS_IMETHOD FireSuccess(nsIDOMDOMRequest *request, JS::HandleValue result) = 0;

  /* void fireError (in nsIDOMDOMRequest request, in DOMString error); */
  NS_IMETHOD FireError(nsIDOMDOMRequest *request, const nsAString & error) = 0;

  /* void fireDetailedError (in nsIDOMDOMRequest request, in nsISupports error); */
  NS_IMETHOD FireDetailedError(nsIDOMDOMRequest *request, nsISupports *error) = 0;

  /* void fireSuccessAsync (in nsIDOMDOMRequest request, in jsval result); */
  NS_IMETHOD FireSuccessAsync(nsIDOMDOMRequest *request, JS::HandleValue result) = 0;

  /* void fireErrorAsync (in nsIDOMDOMRequest request, in DOMString error); */
  NS_IMETHOD FireErrorAsync(nsIDOMDOMRequest *request, const nsAString & error) = 0;

  /* void fireDone (in nsIDOMDOMCursor cursor); */
  NS_IMETHOD FireDone(nsIDOMDOMCursor *cursor) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMRequestService, NS_IDOMREQUESTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMREQUESTSERVICE \
  NS_IMETHOD CreateRequest(nsIDOMWindow *window, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD CreateCursor(nsIDOMWindow *window, nsICursorContinueCallback *aCallback, nsIDOMDOMCursor * *_retval); \
  NS_IMETHOD FireSuccess(nsIDOMDOMRequest *request, JS::HandleValue result); \
  NS_IMETHOD FireError(nsIDOMDOMRequest *request, const nsAString & error); \
  NS_IMETHOD FireDetailedError(nsIDOMDOMRequest *request, nsISupports *error); \
  NS_IMETHOD FireSuccessAsync(nsIDOMDOMRequest *request, JS::HandleValue result); \
  NS_IMETHOD FireErrorAsync(nsIDOMDOMRequest *request, const nsAString & error); \
  NS_IMETHOD FireDone(nsIDOMDOMCursor *cursor); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMREQUESTSERVICE(_to) \
  NS_IMETHOD CreateRequest(nsIDOMWindow *window, nsIDOMDOMRequest * *_retval) { return _to CreateRequest(window, _retval); } \
  NS_IMETHOD CreateCursor(nsIDOMWindow *window, nsICursorContinueCallback *aCallback, nsIDOMDOMCursor * *_retval) { return _to CreateCursor(window, aCallback, _retval); } \
  NS_IMETHOD FireSuccess(nsIDOMDOMRequest *request, JS::HandleValue result) { return _to FireSuccess(request, result); } \
  NS_IMETHOD FireError(nsIDOMDOMRequest *request, const nsAString & error) { return _to FireError(request, error); } \
  NS_IMETHOD FireDetailedError(nsIDOMDOMRequest *request, nsISupports *error) { return _to FireDetailedError(request, error); } \
  NS_IMETHOD FireSuccessAsync(nsIDOMDOMRequest *request, JS::HandleValue result) { return _to FireSuccessAsync(request, result); } \
  NS_IMETHOD FireErrorAsync(nsIDOMDOMRequest *request, const nsAString & error) { return _to FireErrorAsync(request, error); } \
  NS_IMETHOD FireDone(nsIDOMDOMCursor *cursor) { return _to FireDone(cursor); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMREQUESTSERVICE(_to) \
  NS_IMETHOD CreateRequest(nsIDOMWindow *window, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateRequest(window, _retval); } \
  NS_IMETHOD CreateCursor(nsIDOMWindow *window, nsICursorContinueCallback *aCallback, nsIDOMDOMCursor * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateCursor(window, aCallback, _retval); } \
  NS_IMETHOD FireSuccess(nsIDOMDOMRequest *request, JS::HandleValue result) { return !_to ? NS_ERROR_NULL_POINTER : _to->FireSuccess(request, result); } \
  NS_IMETHOD FireError(nsIDOMDOMRequest *request, const nsAString & error) { return !_to ? NS_ERROR_NULL_POINTER : _to->FireError(request, error); } \
  NS_IMETHOD FireDetailedError(nsIDOMDOMRequest *request, nsISupports *error) { return !_to ? NS_ERROR_NULL_POINTER : _to->FireDetailedError(request, error); } \
  NS_IMETHOD FireSuccessAsync(nsIDOMDOMRequest *request, JS::HandleValue result) { return !_to ? NS_ERROR_NULL_POINTER : _to->FireSuccessAsync(request, result); } \
  NS_IMETHOD FireErrorAsync(nsIDOMDOMRequest *request, const nsAString & error) { return !_to ? NS_ERROR_NULL_POINTER : _to->FireErrorAsync(request, error); } \
  NS_IMETHOD FireDone(nsIDOMDOMCursor *cursor) { return !_to ? NS_ERROR_NULL_POINTER : _to->FireDone(cursor); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMRequestService : public nsIDOMRequestService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMREQUESTSERVICE

  nsDOMRequestService();

private:
  ~nsDOMRequestService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMRequestService, nsIDOMRequestService)

nsDOMRequestService::nsDOMRequestService()
{
  /* member initializers and constructor code */
}

nsDOMRequestService::~nsDOMRequestService()
{
  /* destructor code */
}

/* nsIDOMDOMRequest createRequest (in nsIDOMWindow window); */
NS_IMETHODIMP nsDOMRequestService::CreateRequest(nsIDOMWindow *window, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMCursor createCursor (in nsIDOMWindow window, in nsICursorContinueCallback aCallback); */
NS_IMETHODIMP nsDOMRequestService::CreateCursor(nsIDOMWindow *window, nsICursorContinueCallback *aCallback, nsIDOMDOMCursor * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void fireSuccess (in nsIDOMDOMRequest request, in jsval result); */
NS_IMETHODIMP nsDOMRequestService::FireSuccess(nsIDOMDOMRequest *request, JS::HandleValue result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void fireError (in nsIDOMDOMRequest request, in DOMString error); */
NS_IMETHODIMP nsDOMRequestService::FireError(nsIDOMDOMRequest *request, const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void fireDetailedError (in nsIDOMDOMRequest request, in nsISupports error); */
NS_IMETHODIMP nsDOMRequestService::FireDetailedError(nsIDOMDOMRequest *request, nsISupports *error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void fireSuccessAsync (in nsIDOMDOMRequest request, in jsval result); */
NS_IMETHODIMP nsDOMRequestService::FireSuccessAsync(nsIDOMDOMRequest *request, JS::HandleValue result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void fireErrorAsync (in nsIDOMDOMRequest request, in DOMString error); */
NS_IMETHODIMP nsDOMRequestService::FireErrorAsync(nsIDOMDOMRequest *request, const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void fireDone (in nsIDOMDOMCursor cursor); */
NS_IMETHODIMP nsDOMRequestService::FireDone(nsIDOMDOMCursor *cursor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDOMRequest_h__ */

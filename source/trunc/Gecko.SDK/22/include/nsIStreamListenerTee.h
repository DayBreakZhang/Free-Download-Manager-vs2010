/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIStreamListenerTee.idl
 */

#ifndef __gen_nsIStreamListenerTee_h__
#define __gen_nsIStreamListenerTee_h__


#ifndef __gen_nsIStreamListener_h__
#include "nsIStreamListener.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIOutputStream; /* forward declaration */

class nsIRequestObserver; /* forward declaration */

class nsIEventTarget; /* forward declaration */


/* starting interface:    nsIStreamListenerTee */
#define NS_ISTREAMLISTENERTEE_IID_STR "62b27fc1-6e8c-4225-8ad0-b9d44252973a"

#define NS_ISTREAMLISTENERTEE_IID \
  {0x62b27fc1, 0x6e8c, 0x4225, \
    { 0x8a, 0xd0, 0xb9, 0xd4, 0x42, 0x52, 0x97, 0x3a }}

class NS_NO_VTABLE nsIStreamListenerTee : public nsIStreamListener {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTREAMLISTENERTEE_IID)

  /* void init (in nsIStreamListener listener, in nsIOutputStream sink, [optional] in nsIRequestObserver requestObserver); */
  NS_IMETHOD Init(nsIStreamListener *listener, nsIOutputStream *sink, nsIRequestObserver *requestObserver) = 0;

  /* void initAsync (in nsIStreamListener listener, in nsIEventTarget eventTarget, in nsIOutputStream sink, [optional] in nsIRequestObserver requestObserver); */
  NS_IMETHOD InitAsync(nsIStreamListener *listener, nsIEventTarget *eventTarget, nsIOutputStream *sink, nsIRequestObserver *requestObserver) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStreamListenerTee, NS_ISTREAMLISTENERTEE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTREAMLISTENERTEE \
  NS_IMETHOD Init(nsIStreamListener *listener, nsIOutputStream *sink, nsIRequestObserver *requestObserver); \
  NS_IMETHOD InitAsync(nsIStreamListener *listener, nsIEventTarget *eventTarget, nsIOutputStream *sink, nsIRequestObserver *requestObserver); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTREAMLISTENERTEE(_to) \
  NS_IMETHOD Init(nsIStreamListener *listener, nsIOutputStream *sink, nsIRequestObserver *requestObserver) { return _to Init(listener, sink, requestObserver); } \
  NS_IMETHOD InitAsync(nsIStreamListener *listener, nsIEventTarget *eventTarget, nsIOutputStream *sink, nsIRequestObserver *requestObserver) { return _to InitAsync(listener, eventTarget, sink, requestObserver); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTREAMLISTENERTEE(_to) \
  NS_IMETHOD Init(nsIStreamListener *listener, nsIOutputStream *sink, nsIRequestObserver *requestObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(listener, sink, requestObserver); } \
  NS_IMETHOD InitAsync(nsIStreamListener *listener, nsIEventTarget *eventTarget, nsIOutputStream *sink, nsIRequestObserver *requestObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitAsync(listener, eventTarget, sink, requestObserver); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStreamListenerTee : public nsIStreamListenerTee
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTREAMLISTENERTEE

  nsStreamListenerTee();

private:
  ~nsStreamListenerTee();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStreamListenerTee, nsIStreamListenerTee)

nsStreamListenerTee::nsStreamListenerTee()
{
  /* member initializers and constructor code */
}

nsStreamListenerTee::~nsStreamListenerTee()
{
  /* destructor code */
}

/* void init (in nsIStreamListener listener, in nsIOutputStream sink, [optional] in nsIRequestObserver requestObserver); */
NS_IMETHODIMP nsStreamListenerTee::Init(nsIStreamListener *listener, nsIOutputStream *sink, nsIRequestObserver *requestObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initAsync (in nsIStreamListener listener, in nsIEventTarget eventTarget, in nsIOutputStream sink, [optional] in nsIRequestObserver requestObserver); */
NS_IMETHODIMP nsStreamListenerTee::InitAsync(nsIStreamListener *listener, nsIEventTarget *eventTarget, nsIOutputStream *sink, nsIRequestObserver *requestObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStreamListenerTee_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIRequestObserverProxy.idl
 */

#ifndef __gen_nsIRequestObserverProxy_h__
#define __gen_nsIRequestObserverProxy_h__


#ifndef __gen_nsIRequestObserver_h__
#include "nsIRequestObserver.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIEventTarget; /* forward declaration */


/* starting interface:    nsIRequestObserverProxy */
#define NS_IREQUESTOBSERVERPROXY_IID_STR "c2b06151-1bf8-4eef-aea9-1532f12f5a10"

#define NS_IREQUESTOBSERVERPROXY_IID \
  {0xc2b06151, 0x1bf8, 0x4eef, \
    { 0xae, 0xa9, 0x15, 0x32, 0xf1, 0x2f, 0x5a, 0x10 }}

class NS_NO_VTABLE nsIRequestObserverProxy : public nsIRequestObserver {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IREQUESTOBSERVERPROXY_IID)

  /* void init (in nsIRequestObserver observer, in nsISupports context); */
  NS_IMETHOD Init(nsIRequestObserver *observer, nsISupports *context) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRequestObserverProxy, NS_IREQUESTOBSERVERPROXY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIREQUESTOBSERVERPROXY \
  NS_IMETHOD Init(nsIRequestObserver *observer, nsISupports *context); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIREQUESTOBSERVERPROXY(_to) \
  NS_IMETHOD Init(nsIRequestObserver *observer, nsISupports *context) { return _to Init(observer, context); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIREQUESTOBSERVERPROXY(_to) \
  NS_IMETHOD Init(nsIRequestObserver *observer, nsISupports *context) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(observer, context); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRequestObserverProxy : public nsIRequestObserverProxy
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIREQUESTOBSERVERPROXY

  nsRequestObserverProxy();

private:
  ~nsRequestObserverProxy();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRequestObserverProxy, nsIRequestObserverProxy)

nsRequestObserverProxy::nsRequestObserverProxy()
{
  /* member initializers and constructor code */
}

nsRequestObserverProxy::~nsRequestObserverProxy()
{
  /* destructor code */
}

/* void init (in nsIRequestObserver observer, in nsISupports context); */
NS_IMETHODIMP nsRequestObserverProxy::Init(nsIRequestObserver *observer, nsISupports *context)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRequestObserverProxy_h__ */

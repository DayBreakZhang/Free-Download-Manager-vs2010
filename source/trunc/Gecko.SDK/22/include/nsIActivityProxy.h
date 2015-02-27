/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/activities/interfaces/nsIActivityProxy.idl
 */

#ifndef __gen_nsIActivityProxy_h__
#define __gen_nsIActivityProxy_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMMozActivityOptions; /* forward declaration */

class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIActivityProxy */
#define NS_IACTIVITYPROXY_IID_STR "c7a258f7-26a6-46c6-a887-a6c936034f98"

#define NS_IACTIVITYPROXY_IID \
  {0xc7a258f7, 0x26a6, 0x46c6, \
    { 0xa8, 0x87, 0xa6, 0xc9, 0x36, 0x03, 0x4f, 0x98 }}

class NS_NO_VTABLE nsIActivityProxy : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACTIVITYPROXY_IID)

  /* void startActivity (in nsISupports activity, in nsIDOMMozActivityOptions options, in nsIDOMWindow window); */
  NS_IMETHOD StartActivity(nsISupports *activity, nsIDOMMozActivityOptions *options, nsIDOMWindow *window) = 0;

  /* void cleanup (); */
  NS_IMETHOD Cleanup(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIActivityProxy, NS_IACTIVITYPROXY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACTIVITYPROXY \
  NS_IMETHOD StartActivity(nsISupports *activity, nsIDOMMozActivityOptions *options, nsIDOMWindow *window); \
  NS_IMETHOD Cleanup(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACTIVITYPROXY(_to) \
  NS_IMETHOD StartActivity(nsISupports *activity, nsIDOMMozActivityOptions *options, nsIDOMWindow *window) { return _to StartActivity(activity, options, window); } \
  NS_IMETHOD Cleanup(void) { return _to Cleanup(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACTIVITYPROXY(_to) \
  NS_IMETHOD StartActivity(nsISupports *activity, nsIDOMMozActivityOptions *options, nsIDOMWindow *window) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartActivity(activity, options, window); } \
  NS_IMETHOD Cleanup(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Cleanup(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsActivityProxy : public nsIActivityProxy
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACTIVITYPROXY

  nsActivityProxy();

private:
  ~nsActivityProxy();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsActivityProxy, nsIActivityProxy)

nsActivityProxy::nsActivityProxy()
{
  /* member initializers and constructor code */
}

nsActivityProxy::~nsActivityProxy()
{
  /* destructor code */
}

/* void startActivity (in nsISupports activity, in nsIDOMMozActivityOptions options, in nsIDOMWindow window); */
NS_IMETHODIMP nsActivityProxy::StartActivity(nsISupports *activity, nsIDOMMozActivityOptions *options, nsIDOMWindow *window)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cleanup (); */
NS_IMETHODIMP nsActivityProxy::Cleanup()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIActivityProxy_h__ */

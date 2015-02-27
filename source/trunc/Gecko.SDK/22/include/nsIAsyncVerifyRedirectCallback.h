/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIAsyncVerifyRedirectCallback.idl
 */

#ifndef __gen_nsIAsyncVerifyRedirectCallback_h__
#define __gen_nsIAsyncVerifyRedirectCallback_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAsyncVerifyRedirectCallback */
#define NS_IASYNCVERIFYREDIRECTCALLBACK_IID_STR "8d171460-a716-41f1-92be-8c659db39b45"

#define NS_IASYNCVERIFYREDIRECTCALLBACK_IID \
  {0x8d171460, 0xa716, 0x41f1, \
    { 0x92, 0xbe, 0x8c, 0x65, 0x9d, 0xb3, 0x9b, 0x45 }}

class NS_NO_VTABLE nsIAsyncVerifyRedirectCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IASYNCVERIFYREDIRECTCALLBACK_IID)

  /* void onRedirectVerifyCallback (in nsresult result); */
  NS_IMETHOD OnRedirectVerifyCallback(nsresult result) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAsyncVerifyRedirectCallback, NS_IASYNCVERIFYREDIRECTCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIASYNCVERIFYREDIRECTCALLBACK \
  NS_IMETHOD OnRedirectVerifyCallback(nsresult result); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIASYNCVERIFYREDIRECTCALLBACK(_to) \
  NS_IMETHOD OnRedirectVerifyCallback(nsresult result) { return _to OnRedirectVerifyCallback(result); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIASYNCVERIFYREDIRECTCALLBACK(_to) \
  NS_IMETHOD OnRedirectVerifyCallback(nsresult result) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnRedirectVerifyCallback(result); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAsyncVerifyRedirectCallback : public nsIAsyncVerifyRedirectCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIASYNCVERIFYREDIRECTCALLBACK

  nsAsyncVerifyRedirectCallback();

private:
  ~nsAsyncVerifyRedirectCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAsyncVerifyRedirectCallback, nsIAsyncVerifyRedirectCallback)

nsAsyncVerifyRedirectCallback::nsAsyncVerifyRedirectCallback()
{
  /* member initializers and constructor code */
}

nsAsyncVerifyRedirectCallback::~nsAsyncVerifyRedirectCallback()
{
  /* destructor code */
}

/* void onRedirectVerifyCallback (in nsresult result); */
NS_IMETHODIMP nsAsyncVerifyRedirectCallback::OnRedirectVerifyCallback(nsresult result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAsyncVerifyRedirectCallback_h__ */

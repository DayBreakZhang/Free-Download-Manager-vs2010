/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIStreamListener.idl
 */

#ifndef __gen_nsIStreamListener_h__
#define __gen_nsIStreamListener_h__


#ifndef __gen_nsIRequestObserver_h__
#include "nsIRequestObserver.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */


/* starting interface:    nsIStreamListener */
#define NS_ISTREAMLISTENER_IID_STR "3b4c8a77-76ba-4610-b316-678c73a3b88c"

#define NS_ISTREAMLISTENER_IID \
  {0x3b4c8a77, 0x76ba, 0x4610, \
    { 0xb3, 0x16, 0x67, 0x8c, 0x73, 0xa3, 0xb8, 0x8c }}

class NS_NO_VTABLE nsIStreamListener : public nsIRequestObserver {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTREAMLISTENER_IID)

  /* void onDataAvailable (in nsIRequest aRequest, in nsISupports aContext, in nsIInputStream aInputStream, in unsigned long long aOffset, in unsigned long aCount); */
  NS_IMETHOD OnDataAvailable(nsIRequest *aRequest, nsISupports *aContext, nsIInputStream *aInputStream, uint64_t aOffset, uint32_t aCount) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStreamListener, NS_ISTREAMLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTREAMLISTENER \
  NS_IMETHOD OnDataAvailable(nsIRequest *aRequest, nsISupports *aContext, nsIInputStream *aInputStream, uint64_t aOffset, uint32_t aCount); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTREAMLISTENER(_to) \
  NS_IMETHOD OnDataAvailable(nsIRequest *aRequest, nsISupports *aContext, nsIInputStream *aInputStream, uint64_t aOffset, uint32_t aCount) { return _to OnDataAvailable(aRequest, aContext, aInputStream, aOffset, aCount); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTREAMLISTENER(_to) \
  NS_IMETHOD OnDataAvailable(nsIRequest *aRequest, nsISupports *aContext, nsIInputStream *aInputStream, uint64_t aOffset, uint32_t aCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDataAvailable(aRequest, aContext, aInputStream, aOffset, aCount); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStreamListener : public nsIStreamListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTREAMLISTENER

  nsStreamListener();

private:
  ~nsStreamListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStreamListener, nsIStreamListener)

nsStreamListener::nsStreamListener()
{
  /* member initializers and constructor code */
}

nsStreamListener::~nsStreamListener()
{
  /* destructor code */
}

/* void onDataAvailable (in nsIRequest aRequest, in nsISupports aContext, in nsIInputStream aInputStream, in unsigned long long aOffset, in unsigned long aCount); */
NS_IMETHODIMP nsStreamListener::OnDataAvailable(nsIRequest *aRequest, nsISupports *aContext, nsIInputStream *aInputStream, uint64_t aOffset, uint32_t aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStreamListener_h__ */

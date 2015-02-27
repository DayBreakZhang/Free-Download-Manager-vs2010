/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/netwerk/base/public/nsIChildChannel.idl
 */

#ifndef __gen_nsIChildChannel_h__
#define __gen_nsIChildChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIStreamListener; /* forward declaration */


/* starting interface:    nsIChildChannel */
#define NS_ICHILDCHANNEL_IID_STR "c45b92ae-4f07-41dd-b0ef-aa044eeabb1e"

#define NS_ICHILDCHANNEL_IID \
  {0xc45b92ae, 0x4f07, 0x41dd, \
    { 0xb0, 0xef, 0xaa, 0x04, 0x4e, 0xea, 0xbb, 0x1e }}

/**
 * Implemented by content side of IPC protocols.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIChildChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICHILDCHANNEL_IID)

  /**
   * Create the chrome side of the IPC protocol and join an existing 'real'
   * channel on the parent process.  The id is provided by
   * nsIRedirectChannelRegistrar on the chrome process and pushed to the child
   * protocol as an argument to event starting a redirect.
   *
   * Primarilly used in HttpChannelChild::Redirect1Begin on a newly created
   * child channel, where the new channel is intended to be created on the
   * child process.
   */
  /* void connectParent (in PRUint32 id); */
  NS_SCRIPTABLE NS_IMETHOD ConnectParent(PRUint32 id) = 0;

  /**
   * As AsyncOpen is called on the chrome process for redirect target channels,
   * we have to inform the child side of the protocol of that fact by a special
   * method.
   */
  /* void completeRedirectSetup (in nsIStreamListener aListener, in nsISupports aContext); */
  NS_SCRIPTABLE NS_IMETHOD CompleteRedirectSetup(nsIStreamListener *aListener, nsISupports *aContext) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIChildChannel, NS_ICHILDCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICHILDCHANNEL \
  NS_SCRIPTABLE NS_IMETHOD ConnectParent(PRUint32 id); \
  NS_SCRIPTABLE NS_IMETHOD CompleteRedirectSetup(nsIStreamListener *aListener, nsISupports *aContext); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICHILDCHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD ConnectParent(PRUint32 id) { return _to ConnectParent(id); } \
  NS_SCRIPTABLE NS_IMETHOD CompleteRedirectSetup(nsIStreamListener *aListener, nsISupports *aContext) { return _to CompleteRedirectSetup(aListener, aContext); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICHILDCHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD ConnectParent(PRUint32 id) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConnectParent(id); } \
  NS_SCRIPTABLE NS_IMETHOD CompleteRedirectSetup(nsIStreamListener *aListener, nsISupports *aContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->CompleteRedirectSetup(aListener, aContext); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsChildChannel : public nsIChildChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICHILDCHANNEL

  nsChildChannel();

private:
  ~nsChildChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsChildChannel, nsIChildChannel)

nsChildChannel::nsChildChannel()
{
  /* member initializers and constructor code */
}

nsChildChannel::~nsChildChannel()
{
  /* destructor code */
}

/* void connectParent (in PRUint32 id); */
NS_IMETHODIMP nsChildChannel::ConnectParent(PRUint32 id)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void completeRedirectSetup (in nsIStreamListener aListener, in nsISupports aContext); */
NS_IMETHODIMP nsChildChannel::CompleteRedirectSetup(nsIStreamListener *aListener, nsISupports *aContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIChildChannel_h__ */

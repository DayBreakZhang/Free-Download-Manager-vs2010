/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIParentRedirectingChannel.idl
 */

#ifndef __gen_nsIParentRedirectingChannel_h__
#define __gen_nsIParentRedirectingChannel_h__


#ifndef __gen_nsIParentChannel_h__
#include "nsIParentChannel.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITabParent; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsIAsyncVerifyRedirectCallback; /* forward declaration */


/* starting interface:    nsIParentRedirectingChannel */
#define NS_IPARENTREDIRECTINGCHANNEL_IID_STR "cb7edc1c-096f-44de-957c-cb93de1545f6"

#define NS_IPARENTREDIRECTINGCHANNEL_IID \
  {0xcb7edc1c, 0x096f, 0x44de, \
    { 0x95, 0x7c, 0xcb, 0x93, 0xde, 0x15, 0x45, 0xf6 }}

class NS_NO_VTABLE nsIParentRedirectingChannel : public nsIParentChannel {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPARENTREDIRECTINGCHANNEL_IID)

  /* void startRedirect (in uint32_t newChannelId, in nsIChannel newChannel, in uint32_t redirectFlags, in nsIAsyncVerifyRedirectCallback callback); */
  NS_IMETHOD StartRedirect(uint32_t newChannelId, nsIChannel *newChannel, uint32_t redirectFlags, nsIAsyncVerifyRedirectCallback *callback) = 0;

  /* void completeRedirect (in boolean succeeded); */
  NS_IMETHOD CompleteRedirect(bool succeeded) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIParentRedirectingChannel, NS_IPARENTREDIRECTINGCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPARENTREDIRECTINGCHANNEL \
  NS_IMETHOD StartRedirect(uint32_t newChannelId, nsIChannel *newChannel, uint32_t redirectFlags, nsIAsyncVerifyRedirectCallback *callback); \
  NS_IMETHOD CompleteRedirect(bool succeeded); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPARENTREDIRECTINGCHANNEL(_to) \
  NS_IMETHOD StartRedirect(uint32_t newChannelId, nsIChannel *newChannel, uint32_t redirectFlags, nsIAsyncVerifyRedirectCallback *callback) { return _to StartRedirect(newChannelId, newChannel, redirectFlags, callback); } \
  NS_IMETHOD CompleteRedirect(bool succeeded) { return _to CompleteRedirect(succeeded); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPARENTREDIRECTINGCHANNEL(_to) \
  NS_IMETHOD StartRedirect(uint32_t newChannelId, nsIChannel *newChannel, uint32_t redirectFlags, nsIAsyncVerifyRedirectCallback *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartRedirect(newChannelId, newChannel, redirectFlags, callback); } \
  NS_IMETHOD CompleteRedirect(bool succeeded) { return !_to ? NS_ERROR_NULL_POINTER : _to->CompleteRedirect(succeeded); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsParentRedirectingChannel : public nsIParentRedirectingChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPARENTREDIRECTINGCHANNEL

  nsParentRedirectingChannel();

private:
  ~nsParentRedirectingChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsParentRedirectingChannel, nsIParentRedirectingChannel)

nsParentRedirectingChannel::nsParentRedirectingChannel()
{
  /* member initializers and constructor code */
}

nsParentRedirectingChannel::~nsParentRedirectingChannel()
{
  /* destructor code */
}

/* void startRedirect (in uint32_t newChannelId, in nsIChannel newChannel, in uint32_t redirectFlags, in nsIAsyncVerifyRedirectCallback callback); */
NS_IMETHODIMP nsParentRedirectingChannel::StartRedirect(uint32_t newChannelId, nsIChannel *newChannel, uint32_t redirectFlags, nsIAsyncVerifyRedirectCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void completeRedirect (in boolean succeeded); */
NS_IMETHODIMP nsParentRedirectingChannel::CompleteRedirect(bool succeeded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIParentRedirectingChannel_h__ */

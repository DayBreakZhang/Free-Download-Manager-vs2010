/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIPrivateBrowsingChannel.idl
 */

#ifndef __gen_nsIPrivateBrowsingChannel_h__
#define __gen_nsIPrivateBrowsingChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPrivateBrowsingChannel */
#define NS_IPRIVATEBROWSINGCHANNEL_IID_STR "df702bb0-55b8-11e2-bcfd-0800200c9a66"

#define NS_IPRIVATEBROWSINGCHANNEL_IID \
  {0xdf702bb0, 0x55b8, 0x11e2, \
    { 0xbc, 0xfd, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIPrivateBrowsingChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRIVATEBROWSINGCHANNEL_IID)

  /* void setPrivate (in boolean aPrivate); */
  NS_IMETHOD SetPrivate(bool aPrivate) = 0;

  /* readonly attribute boolean isChannelPrivate; */
  NS_IMETHOD GetIsChannelPrivate(bool *aIsChannelPrivate) = 0;

  /* [noscript] boolean isPrivateModeOverriden (out boolean aValue); */
  NS_IMETHOD IsPrivateModeOverriden(bool *aValue, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrivateBrowsingChannel, NS_IPRIVATEBROWSINGCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRIVATEBROWSINGCHANNEL \
  NS_IMETHOD SetPrivate(bool aPrivate); \
  NS_IMETHOD GetIsChannelPrivate(bool *aIsChannelPrivate); \
  NS_IMETHOD IsPrivateModeOverriden(bool *aValue, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRIVATEBROWSINGCHANNEL(_to) \
  NS_IMETHOD SetPrivate(bool aPrivate) { return _to SetPrivate(aPrivate); } \
  NS_IMETHOD GetIsChannelPrivate(bool *aIsChannelPrivate) { return _to GetIsChannelPrivate(aIsChannelPrivate); } \
  NS_IMETHOD IsPrivateModeOverriden(bool *aValue, bool *_retval) { return _to IsPrivateModeOverriden(aValue, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRIVATEBROWSINGCHANNEL(_to) \
  NS_IMETHOD SetPrivate(bool aPrivate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrivate(aPrivate); } \
  NS_IMETHOD GetIsChannelPrivate(bool *aIsChannelPrivate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsChannelPrivate(aIsChannelPrivate); } \
  NS_IMETHOD IsPrivateModeOverriden(bool *aValue, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsPrivateModeOverriden(aValue, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrivateBrowsingChannel : public nsIPrivateBrowsingChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRIVATEBROWSINGCHANNEL

  nsPrivateBrowsingChannel();

private:
  ~nsPrivateBrowsingChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrivateBrowsingChannel, nsIPrivateBrowsingChannel)

nsPrivateBrowsingChannel::nsPrivateBrowsingChannel()
{
  /* member initializers and constructor code */
}

nsPrivateBrowsingChannel::~nsPrivateBrowsingChannel()
{
  /* destructor code */
}

/* void setPrivate (in boolean aPrivate); */
NS_IMETHODIMP nsPrivateBrowsingChannel::SetPrivate(bool aPrivate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isChannelPrivate; */
NS_IMETHODIMP nsPrivateBrowsingChannel::GetIsChannelPrivate(bool *aIsChannelPrivate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] boolean isPrivateModeOverriden (out boolean aValue); */
NS_IMETHODIMP nsPrivateBrowsingChannel::IsPrivateModeOverriden(bool *aValue, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPrivateBrowsingChannel_h__ */

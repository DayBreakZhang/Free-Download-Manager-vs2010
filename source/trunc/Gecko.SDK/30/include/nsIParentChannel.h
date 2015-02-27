/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIParentChannel.idl
 */

#ifndef __gen_nsIParentChannel_h__
#define __gen_nsIParentChannel_h__


#ifndef __gen_nsIStreamListener_h__
#include "nsIStreamListener.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITabParent; /* forward declaration */

namespace mozilla {
namespace net {
class HttpChannelParentListener;
}
}

/* starting interface:    nsIParentChannel */
#define NS_IPARENTCHANNEL_IID_STR "8bf3aa90-ec5d-4977-bd03-197274befc78"

#define NS_IPARENTCHANNEL_IID \
  {0x8bf3aa90, 0xec5d, 0x4977, \
    { 0xbd, 0x03, 0x19, 0x72, 0x74, 0xbe, 0xfc, 0x78 }}

class NS_NO_VTABLE nsIParentChannel : public nsIStreamListener {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPARENTCHANNEL_IID)

  /* [noscript] void setParentListener (in HttpChannelParentListener listener); */
  NS_IMETHOD SetParentListener(mozilla::net::HttpChannelParentListener *listener) = 0;

  /* void delete (); */
  NS_IMETHOD Delete(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIParentChannel, NS_IPARENTCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPARENTCHANNEL \
  NS_IMETHOD SetParentListener(mozilla::net::HttpChannelParentListener *listener); \
  NS_IMETHOD Delete(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPARENTCHANNEL(_to) \
  NS_IMETHOD SetParentListener(mozilla::net::HttpChannelParentListener *listener) { return _to SetParentListener(listener); } \
  NS_IMETHOD Delete(void) { return _to Delete(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPARENTCHANNEL(_to) \
  NS_IMETHOD SetParentListener(mozilla::net::HttpChannelParentListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetParentListener(listener); } \
  NS_IMETHOD Delete(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Delete(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsParentChannel : public nsIParentChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPARENTCHANNEL

  nsParentChannel();

private:
  ~nsParentChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsParentChannel, nsIParentChannel)

nsParentChannel::nsParentChannel()
{
  /* member initializers and constructor code */
}

nsParentChannel::~nsParentChannel()
{
  /* destructor code */
}

/* [noscript] void setParentListener (in HttpChannelParentListener listener); */
NS_IMETHODIMP nsParentChannel::SetParentListener(mozilla::net::HttpChannelParentListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void delete (); */
NS_IMETHODIMP nsParentChannel::Delete()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIParentChannel_h__ */

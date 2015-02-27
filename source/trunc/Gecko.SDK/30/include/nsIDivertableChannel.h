/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDivertableChannel.idl
 */

#ifndef __gen_nsIDivertableChannel_h__
#define __gen_nsIDivertableChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
namespace mozilla {
namespace net {
class ChannelDiverterChild;
}
}
class nsIStreamListener; /* forward declaration */


/* starting interface:    nsIDivertableChannel */
#define NS_IDIVERTABLECHANNEL_IID_STR "4430e0d0-ff70-45f5-99dc-b5fd06943fc1"

#define NS_IDIVERTABLECHANNEL_IID \
  {0x4430e0d0, 0xff70, 0x45f5, \
    { 0x99, 0xdc, 0xb5, 0xfd, 0x06, 0x94, 0x3f, 0xc1 }}

class NS_NO_VTABLE nsIDivertableChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDIVERTABLECHANNEL_IID)

  /* ChannelDiverterChild divertToParent (); */
  NS_IMETHOD DivertToParent(mozilla::net::ChannelDiverterChild **_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDivertableChannel, NS_IDIVERTABLECHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDIVERTABLECHANNEL \
  NS_IMETHOD DivertToParent(mozilla::net::ChannelDiverterChild **_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDIVERTABLECHANNEL(_to) \
  NS_IMETHOD DivertToParent(mozilla::net::ChannelDiverterChild **_retval) { return _to DivertToParent(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDIVERTABLECHANNEL(_to) \
  NS_IMETHOD DivertToParent(mozilla::net::ChannelDiverterChild **_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->DivertToParent(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDivertableChannel : public nsIDivertableChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDIVERTABLECHANNEL

  nsDivertableChannel();

private:
  ~nsDivertableChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDivertableChannel, nsIDivertableChannel)

nsDivertableChannel::nsDivertableChannel()
{
  /* member initializers and constructor code */
}

nsDivertableChannel::~nsDivertableChannel()
{
  /* destructor code */
}

/* ChannelDiverterChild divertToParent (); */
NS_IMETHODIMP nsDivertableChannel::DivertToParent(mozilla::net::ChannelDiverterChild **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDivertableChannel_h__ */

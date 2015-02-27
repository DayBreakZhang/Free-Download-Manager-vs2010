/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIRedirectChannelRegistrar.idl
 */

#ifndef __gen_nsIRedirectChannelRegistrar_h__
#define __gen_nsIRedirectChannelRegistrar_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIChannel; /* forward declaration */

class nsIParentChannel; /* forward declaration */


/* starting interface:    nsIRedirectChannelRegistrar */
#define NS_IREDIRECTCHANNELREGISTRAR_IID_STR "efa36ea2-5b07-46fc-9534-a5acb8b77b72"

#define NS_IREDIRECTCHANNELREGISTRAR_IID \
  {0xefa36ea2, 0x5b07, 0x46fc, \
    { 0x95, 0x34, 0xa5, 0xac, 0xb8, 0xb7, 0x7b, 0x72 }}

class NS_NO_VTABLE nsIRedirectChannelRegistrar : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IREDIRECTCHANNELREGISTRAR_IID)

  /* uint32_t registerChannel (in nsIChannel channel); */
  NS_IMETHOD RegisterChannel(nsIChannel *channel, uint32_t *_retval) = 0;

  /* nsIChannel linkChannels (in uint32_t id, in nsIParentChannel channel); */
  NS_IMETHOD LinkChannels(uint32_t id, nsIParentChannel *channel, nsIChannel * *_retval) = 0;

  /* nsIChannel getRegisteredChannel (in uint32_t id); */
  NS_IMETHOD GetRegisteredChannel(uint32_t id, nsIChannel * *_retval) = 0;

  /* nsIParentChannel getParentChannel (in uint32_t id); */
  NS_IMETHOD GetParentChannel(uint32_t id, nsIParentChannel * *_retval) = 0;

  /* void deregisterChannels (in uint32_t id); */
  NS_IMETHOD DeregisterChannels(uint32_t id) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRedirectChannelRegistrar, NS_IREDIRECTCHANNELREGISTRAR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIREDIRECTCHANNELREGISTRAR \
  NS_IMETHOD RegisterChannel(nsIChannel *channel, uint32_t *_retval); \
  NS_IMETHOD LinkChannels(uint32_t id, nsIParentChannel *channel, nsIChannel * *_retval); \
  NS_IMETHOD GetRegisteredChannel(uint32_t id, nsIChannel * *_retval); \
  NS_IMETHOD GetParentChannel(uint32_t id, nsIParentChannel * *_retval); \
  NS_IMETHOD DeregisterChannels(uint32_t id); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIREDIRECTCHANNELREGISTRAR(_to) \
  NS_IMETHOD RegisterChannel(nsIChannel *channel, uint32_t *_retval) { return _to RegisterChannel(channel, _retval); } \
  NS_IMETHOD LinkChannels(uint32_t id, nsIParentChannel *channel, nsIChannel * *_retval) { return _to LinkChannels(id, channel, _retval); } \
  NS_IMETHOD GetRegisteredChannel(uint32_t id, nsIChannel * *_retval) { return _to GetRegisteredChannel(id, _retval); } \
  NS_IMETHOD GetParentChannel(uint32_t id, nsIParentChannel * *_retval) { return _to GetParentChannel(id, _retval); } \
  NS_IMETHOD DeregisterChannels(uint32_t id) { return _to DeregisterChannels(id); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIREDIRECTCHANNELREGISTRAR(_to) \
  NS_IMETHOD RegisterChannel(nsIChannel *channel, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterChannel(channel, _retval); } \
  NS_IMETHOD LinkChannels(uint32_t id, nsIParentChannel *channel, nsIChannel * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->LinkChannels(id, channel, _retval); } \
  NS_IMETHOD GetRegisteredChannel(uint32_t id, nsIChannel * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRegisteredChannel(id, _retval); } \
  NS_IMETHOD GetParentChannel(uint32_t id, nsIParentChannel * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentChannel(id, _retval); } \
  NS_IMETHOD DeregisterChannels(uint32_t id) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeregisterChannels(id); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRedirectChannelRegistrar : public nsIRedirectChannelRegistrar
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIREDIRECTCHANNELREGISTRAR

  nsRedirectChannelRegistrar();

private:
  ~nsRedirectChannelRegistrar();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRedirectChannelRegistrar, nsIRedirectChannelRegistrar)

nsRedirectChannelRegistrar::nsRedirectChannelRegistrar()
{
  /* member initializers and constructor code */
}

nsRedirectChannelRegistrar::~nsRedirectChannelRegistrar()
{
  /* destructor code */
}

/* uint32_t registerChannel (in nsIChannel channel); */
NS_IMETHODIMP nsRedirectChannelRegistrar::RegisterChannel(nsIChannel *channel, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIChannel linkChannels (in uint32_t id, in nsIParentChannel channel); */
NS_IMETHODIMP nsRedirectChannelRegistrar::LinkChannels(uint32_t id, nsIParentChannel *channel, nsIChannel * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIChannel getRegisteredChannel (in uint32_t id); */
NS_IMETHODIMP nsRedirectChannelRegistrar::GetRegisteredChannel(uint32_t id, nsIChannel * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIParentChannel getParentChannel (in uint32_t id); */
NS_IMETHODIMP nsRedirectChannelRegistrar::GetParentChannel(uint32_t id, nsIParentChannel * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deregisterChannels (in uint32_t id); */
NS_IMETHODIMP nsRedirectChannelRegistrar::DeregisterChannels(uint32_t id)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRedirectChannelRegistrar_h__ */

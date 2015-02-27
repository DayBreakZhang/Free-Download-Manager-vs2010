/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/netwerk/base/public/nsIParentChannel.idl
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


/* starting interface:    nsIParentChannel */
#define NS_IPARENTCHANNEL_IID_STR "723188c3-fff8-4d27-b657-a256e7209be0"

#define NS_IPARENTCHANNEL_IID \
  {0x723188c3, 0xfff8, 0x4d27, \
    { 0xb6, 0x57, 0xa2, 0x56, 0xe7, 0x20, 0x9b, 0xe0 }}

/**
 * Implemented by chrome side of IPC protocols.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIParentChannel : public nsIStreamListener {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPARENTCHANNEL_IID)

  /**
   * Called to invoke deletion of the IPC protocol.
   */
  /* void delete (); */
  NS_SCRIPTABLE NS_IMETHOD Delete(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIParentChannel, NS_IPARENTCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPARENTCHANNEL \
  NS_SCRIPTABLE NS_IMETHOD Delete(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPARENTCHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD Delete(void) { return _to Delete(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPARENTCHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD Delete(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Delete(); } 

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

/* void delete (); */
NS_IMETHODIMP nsParentChannel::Delete()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIParentChannel_h__ */

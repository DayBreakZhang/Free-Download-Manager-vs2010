/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/protocol/http/nsIHttpChannelAuthProvider.idl
 */

#ifndef __gen_nsIHttpChannelAuthProvider_h__
#define __gen_nsIHttpChannelAuthProvider_h__


#ifndef __gen_nsICancelable_h__
#include "nsICancelable.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIHttpChannel; /* forward declaration */

class nsIHttpAuthenticableChannel; /* forward declaration */


/* starting interface:    nsIHttpChannelAuthProvider */
#define NS_IHTTPCHANNELAUTHPROVIDER_IID_STR "c68f3def-c7c8-4ee8-861c-eef49a48b702"

#define NS_IHTTPCHANNELAUTHPROVIDER_IID \
  {0xc68f3def, 0xc7c8, 0x4ee8, \
    { 0x86, 0x1c, 0xee, 0xf4, 0x9a, 0x48, 0xb7, 0x02 }}

class NS_NO_VTABLE nsIHttpChannelAuthProvider : public nsICancelable {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPCHANNELAUTHPROVIDER_IID)

  /* void init (in nsIHttpAuthenticableChannel channel); */
  NS_IMETHOD Init(nsIHttpAuthenticableChannel *channel) = 0;

  /* void processAuthentication (in unsigned long httpStatus, in boolean sslConnectFailed); */
  NS_IMETHOD ProcessAuthentication(uint32_t httpStatus, bool sslConnectFailed) = 0;

  /* void addAuthorizationHeaders (); */
  NS_IMETHOD AddAuthorizationHeaders(void) = 0;

  /* void checkForSuperfluousAuth (); */
  NS_IMETHOD CheckForSuperfluousAuth(void) = 0;

  /* void disconnect (in nsresult status); */
  NS_IMETHOD Disconnect(nsresult status) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpChannelAuthProvider, NS_IHTTPCHANNELAUTHPROVIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPCHANNELAUTHPROVIDER \
  NS_IMETHOD Init(nsIHttpAuthenticableChannel *channel); \
  NS_IMETHOD ProcessAuthentication(uint32_t httpStatus, bool sslConnectFailed); \
  NS_IMETHOD AddAuthorizationHeaders(void); \
  NS_IMETHOD CheckForSuperfluousAuth(void); \
  NS_IMETHOD Disconnect(nsresult status); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPCHANNELAUTHPROVIDER(_to) \
  NS_IMETHOD Init(nsIHttpAuthenticableChannel *channel) { return _to Init(channel); } \
  NS_IMETHOD ProcessAuthentication(uint32_t httpStatus, bool sslConnectFailed) { return _to ProcessAuthentication(httpStatus, sslConnectFailed); } \
  NS_IMETHOD AddAuthorizationHeaders(void) { return _to AddAuthorizationHeaders(); } \
  NS_IMETHOD CheckForSuperfluousAuth(void) { return _to CheckForSuperfluousAuth(); } \
  NS_IMETHOD Disconnect(nsresult status) { return _to Disconnect(status); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPCHANNELAUTHPROVIDER(_to) \
  NS_IMETHOD Init(nsIHttpAuthenticableChannel *channel) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(channel); } \
  NS_IMETHOD ProcessAuthentication(uint32_t httpStatus, bool sslConnectFailed) { return !_to ? NS_ERROR_NULL_POINTER : _to->ProcessAuthentication(httpStatus, sslConnectFailed); } \
  NS_IMETHOD AddAuthorizationHeaders(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddAuthorizationHeaders(); } \
  NS_IMETHOD CheckForSuperfluousAuth(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckForSuperfluousAuth(); } \
  NS_IMETHOD Disconnect(nsresult status) { return !_to ? NS_ERROR_NULL_POINTER : _to->Disconnect(status); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpChannelAuthProvider : public nsIHttpChannelAuthProvider
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPCHANNELAUTHPROVIDER

  nsHttpChannelAuthProvider();

private:
  ~nsHttpChannelAuthProvider();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHttpChannelAuthProvider, nsIHttpChannelAuthProvider)

nsHttpChannelAuthProvider::nsHttpChannelAuthProvider()
{
  /* member initializers and constructor code */
}

nsHttpChannelAuthProvider::~nsHttpChannelAuthProvider()
{
  /* destructor code */
}

/* void init (in nsIHttpAuthenticableChannel channel); */
NS_IMETHODIMP nsHttpChannelAuthProvider::Init(nsIHttpAuthenticableChannel *channel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void processAuthentication (in unsigned long httpStatus, in boolean sslConnectFailed); */
NS_IMETHODIMP nsHttpChannelAuthProvider::ProcessAuthentication(uint32_t httpStatus, bool sslConnectFailed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addAuthorizationHeaders (); */
NS_IMETHODIMP nsHttpChannelAuthProvider::AddAuthorizationHeaders()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void checkForSuperfluousAuth (); */
NS_IMETHODIMP nsHttpChannelAuthProvider::CheckForSuperfluousAuth()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void disconnect (in nsresult status); */
NS_IMETHODIMP nsHttpChannelAuthProvider::Disconnect(nsresult status)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHttpChannelAuthProvider_h__ */

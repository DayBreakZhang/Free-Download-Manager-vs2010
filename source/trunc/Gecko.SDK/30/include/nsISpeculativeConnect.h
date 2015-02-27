/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISpeculativeConnect.idl
 */

#ifndef __gen_nsISpeculativeConnect_h__
#define __gen_nsISpeculativeConnect_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "mozilla/Assertions.h"
#include "mozilla/DebugOnly.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIInterfaceRequestor; /* forward declaration */


/* starting interface:    nsISpeculativeConnect */
#define NS_ISPECULATIVECONNECT_IID_STR "fa580a8d-f4a4-47c5-8ade-4f9786e8d1de"

#define NS_ISPECULATIVECONNECT_IID \
  {0xfa580a8d, 0xf4a4, 0x47c5, \
    { 0x8a, 0xde, 0x4f, 0x97, 0x86, 0xe8, 0xd1, 0xde }}

class NS_NO_VTABLE nsISpeculativeConnect : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISPECULATIVECONNECT_IID)

  /* void speculativeConnect (in nsIURI aURI, in nsIInterfaceRequestor aCallbacks); */
  NS_IMETHOD SpeculativeConnect(nsIURI *aURI, nsIInterfaceRequestor *aCallbacks) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISpeculativeConnect, NS_ISPECULATIVECONNECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISPECULATIVECONNECT \
  NS_IMETHOD SpeculativeConnect(nsIURI *aURI, nsIInterfaceRequestor *aCallbacks); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISPECULATIVECONNECT(_to) \
  NS_IMETHOD SpeculativeConnect(nsIURI *aURI, nsIInterfaceRequestor *aCallbacks) { return _to SpeculativeConnect(aURI, aCallbacks); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISPECULATIVECONNECT(_to) \
  NS_IMETHOD SpeculativeConnect(nsIURI *aURI, nsIInterfaceRequestor *aCallbacks) { return !_to ? NS_ERROR_NULL_POINTER : _to->SpeculativeConnect(aURI, aCallbacks); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSpeculativeConnect : public nsISpeculativeConnect
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISPECULATIVECONNECT

  nsSpeculativeConnect();

private:
  ~nsSpeculativeConnect();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSpeculativeConnect, nsISpeculativeConnect)

nsSpeculativeConnect::nsSpeculativeConnect()
{
  /* member initializers and constructor code */
}

nsSpeculativeConnect::~nsSpeculativeConnect()
{
  /* destructor code */
}

/* void speculativeConnect (in nsIURI aURI, in nsIInterfaceRequestor aCallbacks); */
NS_IMETHODIMP nsSpeculativeConnect::SpeculativeConnect(nsIURI *aURI, nsIInterfaceRequestor *aCallbacks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISpeculativeConnectionOverrider */
#define NS_ISPECULATIVECONNECTIONOVERRIDER_IID_STR "2b6d6fb6-ab28-4f4c-af84-bfdbb7866d72"

#define NS_ISPECULATIVECONNECTIONOVERRIDER_IID \
  {0x2b6d6fb6, 0xab28, 0x4f4c, \
    { 0xaf, 0x84, 0xbf, 0xdb, 0xb7, 0x86, 0x6d, 0x72 }}

class NS_NO_VTABLE nsISpeculativeConnectionOverrider : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISPECULATIVECONNECTIONOVERRIDER_IID)

  /* [infallible] readonly attribute unsigned long parallelSpeculativeConnectLimit; */
  NS_IMETHOD GetParallelSpeculativeConnectLimit(uint32_t *aParallelSpeculativeConnectLimit) = 0;
  inline uint32_t GetParallelSpeculativeConnectLimit()
  {
    uint32_t result;
    mozilla::DebugOnly<nsresult> rv = GetParallelSpeculativeConnectLimit(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean ignorePossibleSpdyConnections; */
  NS_IMETHOD GetIgnorePossibleSpdyConnections(bool *aIgnorePossibleSpdyConnections) = 0;
  inline bool GetIgnorePossibleSpdyConnections()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetIgnorePossibleSpdyConnections(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean ignoreIdle; */
  NS_IMETHOD GetIgnoreIdle(bool *aIgnoreIdle) = 0;
  inline bool GetIgnoreIdle()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetIgnoreIdle(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISpeculativeConnectionOverrider, NS_ISPECULATIVECONNECTIONOVERRIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISPECULATIVECONNECTIONOVERRIDER \
  NS_IMETHOD GetParallelSpeculativeConnectLimit(uint32_t *aParallelSpeculativeConnectLimit); \
  NS_IMETHOD GetIgnorePossibleSpdyConnections(bool *aIgnorePossibleSpdyConnections); \
  NS_IMETHOD GetIgnoreIdle(bool *aIgnoreIdle); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISPECULATIVECONNECTIONOVERRIDER(_to) \
  NS_IMETHOD GetParallelSpeculativeConnectLimit(uint32_t *aParallelSpeculativeConnectLimit) { return _to GetParallelSpeculativeConnectLimit(aParallelSpeculativeConnectLimit); } \
  NS_IMETHOD GetIgnorePossibleSpdyConnections(bool *aIgnorePossibleSpdyConnections) { return _to GetIgnorePossibleSpdyConnections(aIgnorePossibleSpdyConnections); } \
  NS_IMETHOD GetIgnoreIdle(bool *aIgnoreIdle) { return _to GetIgnoreIdle(aIgnoreIdle); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISPECULATIVECONNECTIONOVERRIDER(_to) \
  NS_IMETHOD GetParallelSpeculativeConnectLimit(uint32_t *aParallelSpeculativeConnectLimit) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParallelSpeculativeConnectLimit(aParallelSpeculativeConnectLimit); } \
  NS_IMETHOD GetIgnorePossibleSpdyConnections(bool *aIgnorePossibleSpdyConnections) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIgnorePossibleSpdyConnections(aIgnorePossibleSpdyConnections); } \
  NS_IMETHOD GetIgnoreIdle(bool *aIgnoreIdle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIgnoreIdle(aIgnoreIdle); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSpeculativeConnectionOverrider : public nsISpeculativeConnectionOverrider
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISPECULATIVECONNECTIONOVERRIDER

  nsSpeculativeConnectionOverrider();

private:
  ~nsSpeculativeConnectionOverrider();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSpeculativeConnectionOverrider, nsISpeculativeConnectionOverrider)

nsSpeculativeConnectionOverrider::nsSpeculativeConnectionOverrider()
{
  /* member initializers and constructor code */
}

nsSpeculativeConnectionOverrider::~nsSpeculativeConnectionOverrider()
{
  /* destructor code */
}

/* [infallible] readonly attribute unsigned long parallelSpeculativeConnectLimit; */
NS_IMETHODIMP nsSpeculativeConnectionOverrider::GetParallelSpeculativeConnectLimit(uint32_t *aParallelSpeculativeConnectLimit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean ignorePossibleSpdyConnections; */
NS_IMETHODIMP nsSpeculativeConnectionOverrider::GetIgnorePossibleSpdyConnections(bool *aIgnorePossibleSpdyConnections)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean ignoreIdle; */
NS_IMETHODIMP nsSpeculativeConnectionOverrider::GetIgnoreIdle(bool *aIgnoreIdle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISpeculativeConnect_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsISpeculativeConnect.idl
 */

#ifndef __gen_nsISpeculativeConnect_h__
#define __gen_nsISpeculativeConnect_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

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


#endif /* __gen_nsISpeculativeConnect_h__ */

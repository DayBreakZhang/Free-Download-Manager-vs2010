/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/network/interfaces/nsIDOMNavigatorNetwork.idl
 */

#ifndef __gen_nsIDOMNavigatorNetwork_h__
#define __gen_nsIDOMNavigatorNetwork_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMMozConnection; /* forward declaration */


/* starting interface:    nsIDOMMozNavigatorNetwork */
#define NS_IDOMMOZNAVIGATORNETWORK_IID_STR "c1685d27-f2e2-4ed9-998f-ff5b1442058f"

#define NS_IDOMMOZNAVIGATORNETWORK_IID \
  {0xc1685d27, 0xf2e2, 0x4ed9, \
    { 0x99, 0x8f, 0xff, 0x5b, 0x14, 0x42, 0x05, 0x8f }}

class NS_NO_VTABLE nsIDOMMozNavigatorNetwork : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZNAVIGATORNETWORK_IID)

  /* readonly attribute nsIDOMMozConnection mozConnection; */
  NS_IMETHOD GetMozConnection(nsIDOMMozConnection * *aMozConnection) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozNavigatorNetwork, NS_IDOMMOZNAVIGATORNETWORK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZNAVIGATORNETWORK \
  NS_IMETHOD GetMozConnection(nsIDOMMozConnection * *aMozConnection); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZNAVIGATORNETWORK(_to) \
  NS_IMETHOD GetMozConnection(nsIDOMMozConnection * *aMozConnection) { return _to GetMozConnection(aMozConnection); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZNAVIGATORNETWORK(_to) \
  NS_IMETHOD GetMozConnection(nsIDOMMozConnection * *aMozConnection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozConnection(aMozConnection); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozNavigatorNetwork : public nsIDOMMozNavigatorNetwork
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZNAVIGATORNETWORK

  nsDOMMozNavigatorNetwork();

private:
  ~nsDOMMozNavigatorNetwork();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozNavigatorNetwork, nsIDOMMozNavigatorNetwork)

nsDOMMozNavigatorNetwork::nsDOMMozNavigatorNetwork()
{
  /* member initializers and constructor code */
}

nsDOMMozNavigatorNetwork::~nsDOMMozNavigatorNetwork()
{
  /* destructor code */
}

/* readonly attribute nsIDOMMozConnection mozConnection; */
NS_IMETHODIMP nsDOMMozNavigatorNetwork::GetMozConnection(nsIDOMMozConnection * *aMozConnection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNavigatorNetwork_h__ */

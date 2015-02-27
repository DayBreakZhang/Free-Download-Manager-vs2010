/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMozNavigatorNetwork.idl
 */

#ifndef __gen_nsIMozNavigatorNetwork_h__
#define __gen_nsIMozNavigatorNetwork_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMozNavigatorNetwork */
#define NS_IMOZNAVIGATORNETWORK_IID_STR "7f021f5d-f704-4a29-b166-829595169aaf"

#define NS_IMOZNAVIGATORNETWORK_IID \
  {0x7f021f5d, 0xf704, 0x4a29, \
    { 0xb1, 0x66, 0x82, 0x95, 0x95, 0x16, 0x9a, 0xaf }}

class NS_NO_VTABLE nsIMozNavigatorNetwork : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOZNAVIGATORNETWORK_IID)

  /* readonly attribute nsISupports mozConnection; */
  NS_IMETHOD GetMozConnection(nsISupports * *aMozConnection) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMozNavigatorNetwork, NS_IMOZNAVIGATORNETWORK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOZNAVIGATORNETWORK \
  NS_IMETHOD GetMozConnection(nsISupports * *aMozConnection); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOZNAVIGATORNETWORK(_to) \
  NS_IMETHOD GetMozConnection(nsISupports * *aMozConnection) { return _to GetMozConnection(aMozConnection); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOZNAVIGATORNETWORK(_to) \
  NS_IMETHOD GetMozConnection(nsISupports * *aMozConnection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozConnection(aMozConnection); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMozNavigatorNetwork : public nsIMozNavigatorNetwork
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOZNAVIGATORNETWORK

  nsMozNavigatorNetwork();

private:
  ~nsMozNavigatorNetwork();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMozNavigatorNetwork, nsIMozNavigatorNetwork)

nsMozNavigatorNetwork::nsMozNavigatorNetwork()
{
  /* member initializers and constructor code */
}

nsMozNavigatorNetwork::~nsMozNavigatorNetwork()
{
  /* destructor code */
}

/* readonly attribute nsISupports mozConnection; */
NS_IMETHODIMP nsMozNavigatorNetwork::GetMozConnection(nsISupports * *aMozConnection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMozNavigatorNetwork_h__ */

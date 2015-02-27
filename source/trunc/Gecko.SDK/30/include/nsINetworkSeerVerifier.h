/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsINetworkSeerVerifier.idl
 */

#ifndef __gen_nsINetworkSeerVerifier_h__
#define __gen_nsINetworkSeerVerifier_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsINetworkSeerVerifier */
#define NS_INETWORKSEERVERIFIER_IID_STR "ea273653-43a8-4632-8b30-4032e0918e8b"

#define NS_INETWORKSEERVERIFIER_IID \
  {0xea273653, 0x43a8, 0x4632, \
    { 0x8b, 0x30, 0x40, 0x32, 0xe0, 0x91, 0x8e, 0x8b }}

class NS_NO_VTABLE nsINetworkSeerVerifier : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INETWORKSEERVERIFIER_IID)

  /* void onPredictPreconnect (in nsIURI uri); */
  NS_IMETHOD OnPredictPreconnect(nsIURI *uri) = 0;

  /* void onPredictDNS (in nsIURI uri); */
  NS_IMETHOD OnPredictDNS(nsIURI *uri) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINetworkSeerVerifier, NS_INETWORKSEERVERIFIER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINETWORKSEERVERIFIER \
  NS_IMETHOD OnPredictPreconnect(nsIURI *uri); \
  NS_IMETHOD OnPredictDNS(nsIURI *uri); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINETWORKSEERVERIFIER(_to) \
  NS_IMETHOD OnPredictPreconnect(nsIURI *uri) { return _to OnPredictPreconnect(uri); } \
  NS_IMETHOD OnPredictDNS(nsIURI *uri) { return _to OnPredictDNS(uri); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINETWORKSEERVERIFIER(_to) \
  NS_IMETHOD OnPredictPreconnect(nsIURI *uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnPredictPreconnect(uri); } \
  NS_IMETHOD OnPredictDNS(nsIURI *uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnPredictDNS(uri); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNetworkSeerVerifier : public nsINetworkSeerVerifier
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINETWORKSEERVERIFIER

  nsNetworkSeerVerifier();

private:
  ~nsNetworkSeerVerifier();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNetworkSeerVerifier, nsINetworkSeerVerifier)

nsNetworkSeerVerifier::nsNetworkSeerVerifier()
{
  /* member initializers and constructor code */
}

nsNetworkSeerVerifier::~nsNetworkSeerVerifier()
{
  /* destructor code */
}

/* void onPredictPreconnect (in nsIURI uri); */
NS_IMETHODIMP nsNetworkSeerVerifier::OnPredictPreconnect(nsIURI *uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onPredictDNS (in nsIURI uri); */
NS_IMETHODIMP nsNetworkSeerVerifier::OnPredictDNS(nsIURI *uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINetworkSeerVerifier_h__ */

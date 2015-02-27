/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsINetworkSeer.idl
 */

#ifndef __gen_nsINetworkSeer_h__
#define __gen_nsINetworkSeer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsILoadContext; /* forward declaration */

class nsINetworkSeerVerifier; /* forward declaration */

typedef uint32_t  SeerPredictReason;

typedef uint32_t  SeerLearnReason;


/* starting interface:    nsINetworkSeer */
#define NS_INETWORKSEER_IID_STR "25e323b6-99e0-4274-b5b3-1a9eb56e28ac"

#define NS_INETWORKSEER_IID \
  {0x25e323b6, 0x99e0, 0x4274, \
    { 0xb5, 0xb3, 0x1a, 0x9e, 0xb5, 0x6e, 0x28, 0xac }}

class NS_NO_VTABLE nsINetworkSeer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INETWORKSEER_IID)

  enum {
    PREDICT_LINK = 0U,
    PREDICT_LOAD = 1U,
    PREDICT_STARTUP = 2U
  };

  /* void predict (in nsIURI targetURI, in nsIURI sourceURI, in SeerPredictReason reason, in nsILoadContext loadContext, in nsINetworkSeerVerifier verifier); */
  NS_IMETHOD Predict(nsIURI *targetURI, nsIURI *sourceURI, SeerPredictReason reason, nsILoadContext *loadContext, nsINetworkSeerVerifier *verifier) = 0;

  enum {
    LEARN_LOAD_TOPLEVEL = 0U,
    LEARN_LOAD_SUBRESOURCE = 1U,
    LEARN_LOAD_REDIRECT = 2U,
    LEARN_STARTUP = 3U
  };

  /* void learn (in nsIURI targetURI, in nsIURI sourceURI, in SeerLearnReason reason, in nsILoadContext loadContext); */
  NS_IMETHOD Learn(nsIURI *targetURI, nsIURI *sourceURI, SeerLearnReason reason, nsILoadContext *loadContext) = 0;

  /* void reset (); */
  NS_IMETHOD Reset(void) = 0;

  /* void prepareForDnsTest (in long long timestamp, in string uri); */
  NS_IMETHOD PrepareForDnsTest(int64_t timestamp, const char * uri) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINetworkSeer, NS_INETWORKSEER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINETWORKSEER \
  NS_IMETHOD Predict(nsIURI *targetURI, nsIURI *sourceURI, SeerPredictReason reason, nsILoadContext *loadContext, nsINetworkSeerVerifier *verifier); \
  NS_IMETHOD Learn(nsIURI *targetURI, nsIURI *sourceURI, SeerLearnReason reason, nsILoadContext *loadContext); \
  NS_IMETHOD Reset(void); \
  NS_IMETHOD PrepareForDnsTest(int64_t timestamp, const char * uri); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINETWORKSEER(_to) \
  NS_IMETHOD Predict(nsIURI *targetURI, nsIURI *sourceURI, SeerPredictReason reason, nsILoadContext *loadContext, nsINetworkSeerVerifier *verifier) { return _to Predict(targetURI, sourceURI, reason, loadContext, verifier); } \
  NS_IMETHOD Learn(nsIURI *targetURI, nsIURI *sourceURI, SeerLearnReason reason, nsILoadContext *loadContext) { return _to Learn(targetURI, sourceURI, reason, loadContext); } \
  NS_IMETHOD Reset(void) { return _to Reset(); } \
  NS_IMETHOD PrepareForDnsTest(int64_t timestamp, const char * uri) { return _to PrepareForDnsTest(timestamp, uri); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINETWORKSEER(_to) \
  NS_IMETHOD Predict(nsIURI *targetURI, nsIURI *sourceURI, SeerPredictReason reason, nsILoadContext *loadContext, nsINetworkSeerVerifier *verifier) { return !_to ? NS_ERROR_NULL_POINTER : _to->Predict(targetURI, sourceURI, reason, loadContext, verifier); } \
  NS_IMETHOD Learn(nsIURI *targetURI, nsIURI *sourceURI, SeerLearnReason reason, nsILoadContext *loadContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->Learn(targetURI, sourceURI, reason, loadContext); } \
  NS_IMETHOD Reset(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Reset(); } \
  NS_IMETHOD PrepareForDnsTest(int64_t timestamp, const char * uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->PrepareForDnsTest(timestamp, uri); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNetworkSeer : public nsINetworkSeer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINETWORKSEER

  nsNetworkSeer();

private:
  ~nsNetworkSeer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNetworkSeer, nsINetworkSeer)

nsNetworkSeer::nsNetworkSeer()
{
  /* member initializers and constructor code */
}

nsNetworkSeer::~nsNetworkSeer()
{
  /* destructor code */
}

/* void predict (in nsIURI targetURI, in nsIURI sourceURI, in SeerPredictReason reason, in nsILoadContext loadContext, in nsINetworkSeerVerifier verifier); */
NS_IMETHODIMP nsNetworkSeer::Predict(nsIURI *targetURI, nsIURI *sourceURI, SeerPredictReason reason, nsILoadContext *loadContext, nsINetworkSeerVerifier *verifier)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void learn (in nsIURI targetURI, in nsIURI sourceURI, in SeerLearnReason reason, in nsILoadContext loadContext); */
NS_IMETHODIMP nsNetworkSeer::Learn(nsIURI *targetURI, nsIURI *sourceURI, SeerLearnReason reason, nsILoadContext *loadContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reset (); */
NS_IMETHODIMP nsNetworkSeer::Reset()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void prepareForDnsTest (in long long timestamp, in string uri); */
NS_IMETHODIMP nsNetworkSeer::PrepareForDnsTest(int64_t timestamp, const char * uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// Wrapper functions to make use of the seer easier and less invasive
class nsIChannel;
class nsIDocument;
class nsILoadContext;
class nsILoadGroup;
class nsINetworkSeerVerifier;
namespace mozilla {
namespace net {
nsresult SeerPredict(nsIURI *targetURI,
                     nsIURI *sourceURI,
                     SeerPredictReason reason,
                     nsILoadContext *loadContext,
                     nsINetworkSeerVerifier *verifier);
nsresult SeerLearn(nsIURI *targetURI,
                   nsIURI *sourceURI,
                   SeerLearnReason reason,
                   nsILoadContext *loadContext);
nsresult SeerLearn(nsIURI *targetURI,
                   nsIURI *sourceURI,
                   SeerLearnReason reason,
                   nsILoadGroup *loadGroup);
nsresult SeerLearn(nsIURI *targetURI,
                   nsIURI *sourceURI,
                   SeerLearnReason reason,
                   nsIDocument *document);
nsresult SeerLearnRedirect(nsIURI *targetURI,
                           nsIChannel *channel,
                           nsILoadContext *loadContext);
} // mozilla::net
} // mozilla

#endif /* __gen_nsINetworkSeer_h__ */

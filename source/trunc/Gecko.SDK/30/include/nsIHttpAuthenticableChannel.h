/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIHttpAuthenticableChannel.idl
 */

#ifndef __gen_nsIHttpAuthenticableChannel_h__
#define __gen_nsIHttpAuthenticableChannel_h__


#ifndef __gen_nsIProxiedChannel_h__
#include "nsIProxiedChannel.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsILoadGroup; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIInterfaceRequestor; /* forward declaration */

typedef uint32_t  nsLoadFlags;


/* starting interface:    nsIHttpAuthenticableChannel */
#define NS_IHTTPAUTHENTICABLECHANNEL_IID_STR "701093ac-5c7f-429c-99e3-423b041fccb4"

#define NS_IHTTPAUTHENTICABLECHANNEL_IID \
  {0x701093ac, 0x5c7f, 0x429c, \
    { 0x99, 0xe3, 0x42, 0x3b, 0x04, 0x1f, 0xcc, 0xb4 }}

class NS_NO_VTABLE nsIHttpAuthenticableChannel : public nsIProxiedChannel {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPAUTHENTICABLECHANNEL_IID)

  /* readonly attribute boolean isSSL; */
  NS_IMETHOD GetIsSSL(bool *aIsSSL) = 0;

  /* readonly attribute boolean proxyMethodIsConnect; */
  NS_IMETHOD GetProxyMethodIsConnect(bool *aProxyMethodIsConnect) = 0;

  /* void cancel (in nsresult aStatus); */
  NS_IMETHOD Cancel(nsresult aStatus) = 0;

  /* readonly attribute nsLoadFlags loadFlags; */
  NS_IMETHOD GetLoadFlags(nsLoadFlags *aLoadFlags) = 0;

  /* readonly attribute nsIURI URI; */
  NS_IMETHOD GetURI(nsIURI * *aURI) = 0;

  /* readonly attribute nsILoadGroup loadGroup; */
  NS_IMETHOD GetLoadGroup(nsILoadGroup * *aLoadGroup) = 0;

  /* readonly attribute nsIInterfaceRequestor notificationCallbacks; */
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks) = 0;

  /* readonly attribute ACString requestMethod; */
  NS_IMETHOD GetRequestMethod(nsACString & aRequestMethod) = 0;

  /* readonly attribute ACString serverResponseHeader; */
  NS_IMETHOD GetServerResponseHeader(nsACString & aServerResponseHeader) = 0;

  /* readonly attribute ACString proxyChallenges; */
  NS_IMETHOD GetProxyChallenges(nsACString & aProxyChallenges) = 0;

  /* readonly attribute ACString WWWChallenges; */
  NS_IMETHOD GetWWWChallenges(nsACString & aWWWChallenges) = 0;

  /* void setProxyCredentials (in ACString credentials); */
  NS_IMETHOD SetProxyCredentials(const nsACString & credentials) = 0;

  /* void setWWWCredentials (in ACString credentials); */
  NS_IMETHOD SetWWWCredentials(const nsACString & credentials) = 0;

  /* void onAuthAvailable (); */
  NS_IMETHOD OnAuthAvailable(void) = 0;

  /* void onAuthCancelled (in boolean userCancel); */
  NS_IMETHOD OnAuthCancelled(bool userCancel) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpAuthenticableChannel, NS_IHTTPAUTHENTICABLECHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPAUTHENTICABLECHANNEL \
  NS_IMETHOD GetIsSSL(bool *aIsSSL); \
  NS_IMETHOD GetProxyMethodIsConnect(bool *aProxyMethodIsConnect); \
  NS_IMETHOD Cancel(nsresult aStatus); \
  NS_IMETHOD GetLoadFlags(nsLoadFlags *aLoadFlags); \
  NS_IMETHOD GetURI(nsIURI * *aURI); \
  NS_IMETHOD GetLoadGroup(nsILoadGroup * *aLoadGroup); \
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks); \
  NS_IMETHOD GetRequestMethod(nsACString & aRequestMethod); \
  NS_IMETHOD GetServerResponseHeader(nsACString & aServerResponseHeader); \
  NS_IMETHOD GetProxyChallenges(nsACString & aProxyChallenges); \
  NS_IMETHOD GetWWWChallenges(nsACString & aWWWChallenges); \
  NS_IMETHOD SetProxyCredentials(const nsACString & credentials); \
  NS_IMETHOD SetWWWCredentials(const nsACString & credentials); \
  NS_IMETHOD OnAuthAvailable(void); \
  NS_IMETHOD OnAuthCancelled(bool userCancel); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPAUTHENTICABLECHANNEL(_to) \
  NS_IMETHOD GetIsSSL(bool *aIsSSL) { return _to GetIsSSL(aIsSSL); } \
  NS_IMETHOD GetProxyMethodIsConnect(bool *aProxyMethodIsConnect) { return _to GetProxyMethodIsConnect(aProxyMethodIsConnect); } \
  NS_IMETHOD Cancel(nsresult aStatus) { return _to Cancel(aStatus); } \
  NS_IMETHOD GetLoadFlags(nsLoadFlags *aLoadFlags) { return _to GetLoadFlags(aLoadFlags); } \
  NS_IMETHOD GetURI(nsIURI * *aURI) { return _to GetURI(aURI); } \
  NS_IMETHOD GetLoadGroup(nsILoadGroup * *aLoadGroup) { return _to GetLoadGroup(aLoadGroup); } \
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks) { return _to GetNotificationCallbacks(aNotificationCallbacks); } \
  NS_IMETHOD GetRequestMethod(nsACString & aRequestMethod) { return _to GetRequestMethod(aRequestMethod); } \
  NS_IMETHOD GetServerResponseHeader(nsACString & aServerResponseHeader) { return _to GetServerResponseHeader(aServerResponseHeader); } \
  NS_IMETHOD GetProxyChallenges(nsACString & aProxyChallenges) { return _to GetProxyChallenges(aProxyChallenges); } \
  NS_IMETHOD GetWWWChallenges(nsACString & aWWWChallenges) { return _to GetWWWChallenges(aWWWChallenges); } \
  NS_IMETHOD SetProxyCredentials(const nsACString & credentials) { return _to SetProxyCredentials(credentials); } \
  NS_IMETHOD SetWWWCredentials(const nsACString & credentials) { return _to SetWWWCredentials(credentials); } \
  NS_IMETHOD OnAuthAvailable(void) { return _to OnAuthAvailable(); } \
  NS_IMETHOD OnAuthCancelled(bool userCancel) { return _to OnAuthCancelled(userCancel); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPAUTHENTICABLECHANNEL(_to) \
  NS_IMETHOD GetIsSSL(bool *aIsSSL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsSSL(aIsSSL); } \
  NS_IMETHOD GetProxyMethodIsConnect(bool *aProxyMethodIsConnect) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProxyMethodIsConnect(aProxyMethodIsConnect); } \
  NS_IMETHOD Cancel(nsresult aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->Cancel(aStatus); } \
  NS_IMETHOD GetLoadFlags(nsLoadFlags *aLoadFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadFlags(aLoadFlags); } \
  NS_IMETHOD GetURI(nsIURI * *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURI(aURI); } \
  NS_IMETHOD GetLoadGroup(nsILoadGroup * *aLoadGroup) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadGroup(aLoadGroup); } \
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNotificationCallbacks(aNotificationCallbacks); } \
  NS_IMETHOD GetRequestMethod(nsACString & aRequestMethod) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequestMethod(aRequestMethod); } \
  NS_IMETHOD GetServerResponseHeader(nsACString & aServerResponseHeader) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetServerResponseHeader(aServerResponseHeader); } \
  NS_IMETHOD GetProxyChallenges(nsACString & aProxyChallenges) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProxyChallenges(aProxyChallenges); } \
  NS_IMETHOD GetWWWChallenges(nsACString & aWWWChallenges) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWWWChallenges(aWWWChallenges); } \
  NS_IMETHOD SetProxyCredentials(const nsACString & credentials) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProxyCredentials(credentials); } \
  NS_IMETHOD SetWWWCredentials(const nsACString & credentials) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWWWCredentials(credentials); } \
  NS_IMETHOD OnAuthAvailable(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnAuthAvailable(); } \
  NS_IMETHOD OnAuthCancelled(bool userCancel) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnAuthCancelled(userCancel); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpAuthenticableChannel : public nsIHttpAuthenticableChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPAUTHENTICABLECHANNEL

  nsHttpAuthenticableChannel();

private:
  ~nsHttpAuthenticableChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHttpAuthenticableChannel, nsIHttpAuthenticableChannel)

nsHttpAuthenticableChannel::nsHttpAuthenticableChannel()
{
  /* member initializers and constructor code */
}

nsHttpAuthenticableChannel::~nsHttpAuthenticableChannel()
{
  /* destructor code */
}

/* readonly attribute boolean isSSL; */
NS_IMETHODIMP nsHttpAuthenticableChannel::GetIsSSL(bool *aIsSSL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean proxyMethodIsConnect; */
NS_IMETHODIMP nsHttpAuthenticableChannel::GetProxyMethodIsConnect(bool *aProxyMethodIsConnect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancel (in nsresult aStatus); */
NS_IMETHODIMP nsHttpAuthenticableChannel::Cancel(nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsLoadFlags loadFlags; */
NS_IMETHODIMP nsHttpAuthenticableChannel::GetLoadFlags(nsLoadFlags *aLoadFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI URI; */
NS_IMETHODIMP nsHttpAuthenticableChannel::GetURI(nsIURI * *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsILoadGroup loadGroup; */
NS_IMETHODIMP nsHttpAuthenticableChannel::GetLoadGroup(nsILoadGroup * *aLoadGroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIInterfaceRequestor notificationCallbacks; */
NS_IMETHODIMP nsHttpAuthenticableChannel::GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString requestMethod; */
NS_IMETHODIMP nsHttpAuthenticableChannel::GetRequestMethod(nsACString & aRequestMethod)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString serverResponseHeader; */
NS_IMETHODIMP nsHttpAuthenticableChannel::GetServerResponseHeader(nsACString & aServerResponseHeader)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString proxyChallenges; */
NS_IMETHODIMP nsHttpAuthenticableChannel::GetProxyChallenges(nsACString & aProxyChallenges)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString WWWChallenges; */
NS_IMETHODIMP nsHttpAuthenticableChannel::GetWWWChallenges(nsACString & aWWWChallenges)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setProxyCredentials (in ACString credentials); */
NS_IMETHODIMP nsHttpAuthenticableChannel::SetProxyCredentials(const nsACString & credentials)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setWWWCredentials (in ACString credentials); */
NS_IMETHODIMP nsHttpAuthenticableChannel::SetWWWCredentials(const nsACString & credentials)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onAuthAvailable (); */
NS_IMETHODIMP nsHttpAuthenticableChannel::OnAuthAvailable()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onAuthCancelled (in boolean userCancel); */
NS_IMETHODIMP nsHttpAuthenticableChannel::OnAuthCancelled(bool userCancel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHttpAuthenticableChannel_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISSLSocketControl.idl
 */

#ifndef __gen_nsISSLSocketControl_h__
#define __gen_nsISSLSocketControl_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "mozilla/Assertions.h"
#include "mozilla/DebugOnly.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInterfaceRequestor; /* forward declaration */

template<class T> class nsTArray;
class nsCString;

/* starting interface:    nsISSLSocketControl */
#define NS_ISSLSOCKETCONTROL_IID_STR "4080f700-9c16-4884-8f8d-e28094377084"

#define NS_ISSLSOCKETCONTROL_IID \
  {0x4080f700, 0x9c16, 0x4884, \
    { 0x8f, 0x8d, 0xe2, 0x80, 0x94, 0x37, 0x70, 0x84 }}

class NS_NO_VTABLE nsISSLSocketControl : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISSLSOCKETCONTROL_IID)

  /* attribute nsIInterfaceRequestor notificationCallbacks; */
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks) = 0;
  NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks) = 0;

  /* void proxyStartSSL (); */
  NS_IMETHOD ProxyStartSSL(void) = 0;

  /* void StartTLS (); */
  NS_IMETHOD StartTLS(void) = 0;

  /* [noscript] void setNPNList (in nsCStringTArrayRef aNPNList); */
  NS_IMETHOD SetNPNList(nsTArray<nsCString> & aNPNList) = 0;

  /* readonly attribute ACString negotiatedNPN; */
  NS_IMETHOD GetNegotiatedNPN(nsACString & aNegotiatedNPN) = 0;

  /* boolean joinConnection (in ACString npnProtocol, in ACString hostname, in long port); */
  NS_IMETHOD JoinConnection(const nsACString & npnProtocol, const nsACString & hostname, int32_t port, bool *_retval) = 0;

  /* [infallible] readonly attribute short KEAUsed; */
  NS_IMETHOD GetKEAUsed(int16_t *aKEAUsed) = 0;
  inline int16_t GetKEAUsed()
  {
    int16_t result;
    mozilla::DebugOnly<nsresult> rv = GetKEAUsed(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] attribute short KEAExpected; */
  NS_IMETHOD GetKEAExpected(int16_t *aKEAExpected) = 0;
  inline int16_t GetKEAExpected()
  {
    int16_t result;
    mozilla::DebugOnly<nsresult> rv = GetKEAExpected(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }
  NS_IMETHOD SetKEAExpected(int16_t aKEAExpected) = 0;

  enum {
    KEY_EXCHANGE_UNKNOWN = -1
  };

  /* readonly attribute uint32_t providerFlags; */
  NS_IMETHOD GetProviderFlags(uint32_t *aProviderFlags) = 0;

  enum {
    SSL_VERSION_3 = 768,
    TLS_VERSION_1 = 769,
    TLS_VERSION_1_1 = 770,
    TLS_VERSION_1_2 = 771,
    SSL_VERSION_UNKNOWN = -1
  };

  /* [infallible] readonly attribute short SSLVersionUsed; */
  NS_IMETHOD GetSSLVersionUsed(int16_t *aSSLVersionUsed) = 0;
  inline int16_t GetSSLVersionUsed()
  {
    int16_t result;
    mozilla::DebugOnly<nsresult> rv = GetSSLVersionUsed(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISSLSocketControl, NS_ISSLSOCKETCONTROL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISSLSOCKETCONTROL \
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks); \
  NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks); \
  NS_IMETHOD ProxyStartSSL(void); \
  NS_IMETHOD StartTLS(void); \
  NS_IMETHOD SetNPNList(nsTArray<nsCString> & aNPNList); \
  NS_IMETHOD GetNegotiatedNPN(nsACString & aNegotiatedNPN); \
  NS_IMETHOD JoinConnection(const nsACString & npnProtocol, const nsACString & hostname, int32_t port, bool *_retval); \
  NS_IMETHOD GetKEAUsed(int16_t *aKEAUsed); \
  NS_IMETHOD GetKEAExpected(int16_t *aKEAExpected); \
  NS_IMETHOD SetKEAExpected(int16_t aKEAExpected); \
  NS_IMETHOD GetProviderFlags(uint32_t *aProviderFlags); \
  NS_IMETHOD GetSSLVersionUsed(int16_t *aSSLVersionUsed); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISSLSOCKETCONTROL(_to) \
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks) { return _to GetNotificationCallbacks(aNotificationCallbacks); } \
  NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks) { return _to SetNotificationCallbacks(aNotificationCallbacks); } \
  NS_IMETHOD ProxyStartSSL(void) { return _to ProxyStartSSL(); } \
  NS_IMETHOD StartTLS(void) { return _to StartTLS(); } \
  NS_IMETHOD SetNPNList(nsTArray<nsCString> & aNPNList) { return _to SetNPNList(aNPNList); } \
  NS_IMETHOD GetNegotiatedNPN(nsACString & aNegotiatedNPN) { return _to GetNegotiatedNPN(aNegotiatedNPN); } \
  NS_IMETHOD JoinConnection(const nsACString & npnProtocol, const nsACString & hostname, int32_t port, bool *_retval) { return _to JoinConnection(npnProtocol, hostname, port, _retval); } \
  NS_IMETHOD GetKEAUsed(int16_t *aKEAUsed) { return _to GetKEAUsed(aKEAUsed); } \
  NS_IMETHOD GetKEAExpected(int16_t *aKEAExpected) { return _to GetKEAExpected(aKEAExpected); } \
  NS_IMETHOD SetKEAExpected(int16_t aKEAExpected) { return _to SetKEAExpected(aKEAExpected); } \
  NS_IMETHOD GetProviderFlags(uint32_t *aProviderFlags) { return _to GetProviderFlags(aProviderFlags); } \
  NS_IMETHOD GetSSLVersionUsed(int16_t *aSSLVersionUsed) { return _to GetSSLVersionUsed(aSSLVersionUsed); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISSLSOCKETCONTROL(_to) \
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNotificationCallbacks(aNotificationCallbacks); } \
  NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNotificationCallbacks(aNotificationCallbacks); } \
  NS_IMETHOD ProxyStartSSL(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ProxyStartSSL(); } \
  NS_IMETHOD StartTLS(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartTLS(); } \
  NS_IMETHOD SetNPNList(nsTArray<nsCString> & aNPNList) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNPNList(aNPNList); } \
  NS_IMETHOD GetNegotiatedNPN(nsACString & aNegotiatedNPN) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNegotiatedNPN(aNegotiatedNPN); } \
  NS_IMETHOD JoinConnection(const nsACString & npnProtocol, const nsACString & hostname, int32_t port, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->JoinConnection(npnProtocol, hostname, port, _retval); } \
  NS_IMETHOD GetKEAUsed(int16_t *aKEAUsed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKEAUsed(aKEAUsed); } \
  NS_IMETHOD GetKEAExpected(int16_t *aKEAExpected) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKEAExpected(aKEAExpected); } \
  NS_IMETHOD SetKEAExpected(int16_t aKEAExpected) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetKEAExpected(aKEAExpected); } \
  NS_IMETHOD GetProviderFlags(uint32_t *aProviderFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProviderFlags(aProviderFlags); } \
  NS_IMETHOD GetSSLVersionUsed(int16_t *aSSLVersionUsed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSSLVersionUsed(aSSLVersionUsed); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSSLSocketControl : public nsISSLSocketControl
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISSLSOCKETCONTROL

  nsSSLSocketControl();

private:
  ~nsSSLSocketControl();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSSLSocketControl, nsISSLSocketControl)

nsSSLSocketControl::nsSSLSocketControl()
{
  /* member initializers and constructor code */
}

nsSSLSocketControl::~nsSSLSocketControl()
{
  /* destructor code */
}

/* attribute nsIInterfaceRequestor notificationCallbacks; */
NS_IMETHODIMP nsSSLSocketControl::GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSSLSocketControl::SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void proxyStartSSL (); */
NS_IMETHODIMP nsSSLSocketControl::ProxyStartSSL()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void StartTLS (); */
NS_IMETHODIMP nsSSLSocketControl::StartTLS()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setNPNList (in nsCStringTArrayRef aNPNList); */
NS_IMETHODIMP nsSSLSocketControl::SetNPNList(nsTArray<nsCString> & aNPNList)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString negotiatedNPN; */
NS_IMETHODIMP nsSSLSocketControl::GetNegotiatedNPN(nsACString & aNegotiatedNPN)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean joinConnection (in ACString npnProtocol, in ACString hostname, in long port); */
NS_IMETHODIMP nsSSLSocketControl::JoinConnection(const nsACString & npnProtocol, const nsACString & hostname, int32_t port, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute short KEAUsed; */
NS_IMETHODIMP nsSSLSocketControl::GetKEAUsed(int16_t *aKEAUsed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] attribute short KEAExpected; */
NS_IMETHODIMP nsSSLSocketControl::GetKEAExpected(int16_t *aKEAExpected)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSSLSocketControl::SetKEAExpected(int16_t aKEAExpected)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t providerFlags; */
NS_IMETHODIMP nsSSLSocketControl::GetProviderFlags(uint32_t *aProviderFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute short SSLVersionUsed; */
NS_IMETHODIMP nsSSLSocketControl::GetSSLVersionUsed(int16_t *aSSLVersionUsed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISSLSocketControl_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIChannel.idl
 */

#ifndef __gen_nsIChannel_h__
#define __gen_nsIChannel_h__


#ifndef __gen_nsIRequest_h__
#include "nsIRequest.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIInterfaceRequestor; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIStreamListener; /* forward declaration */


/* starting interface:    nsIChannel */
#define NS_ICHANNEL_IID_STR "2a8a7237-c1e2-4de7-b669-2002af29e42d"

#define NS_ICHANNEL_IID \
  {0x2a8a7237, 0xc1e2, 0x4de7, \
    { 0xb6, 0x69, 0x20, 0x02, 0xaf, 0x29, 0xe4, 0x2d }}

class NS_NO_VTABLE nsIChannel : public nsIRequest {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICHANNEL_IID)

  /* attribute nsIURI originalURI; */
  NS_IMETHOD GetOriginalURI(nsIURI * *aOriginalURI) = 0;
  NS_IMETHOD SetOriginalURI(nsIURI *aOriginalURI) = 0;

  /* readonly attribute nsIURI URI; */
  NS_IMETHOD GetURI(nsIURI * *aURI) = 0;

  /* attribute nsISupports owner; */
  NS_IMETHOD GetOwner(nsISupports * *aOwner) = 0;
  NS_IMETHOD SetOwner(nsISupports *aOwner) = 0;

  /* attribute nsIInterfaceRequestor notificationCallbacks; */
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks) = 0;
  NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks) = 0;

  /* readonly attribute nsISupports securityInfo; */
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) = 0;

  /* attribute ACString contentType; */
  NS_IMETHOD GetContentType(nsACString & aContentType) = 0;
  NS_IMETHOD SetContentType(const nsACString & aContentType) = 0;

  /* attribute ACString contentCharset; */
  NS_IMETHOD GetContentCharset(nsACString & aContentCharset) = 0;
  NS_IMETHOD SetContentCharset(const nsACString & aContentCharset) = 0;

  /* attribute int64_t contentLength; */
  NS_IMETHOD GetContentLength(int64_t *aContentLength) = 0;
  NS_IMETHOD SetContentLength(int64_t aContentLength) = 0;

  /* nsIInputStream open (); */
  NS_IMETHOD Open(nsIInputStream * *_retval) = 0;

  /* void asyncOpen (in nsIStreamListener aListener, in nsISupports aContext); */
  NS_IMETHOD AsyncOpen(nsIStreamListener *aListener, nsISupports *aContext) = 0;

  enum {
    LOAD_DOCUMENT_URI = 65536U,
    LOAD_RETARGETED_DOCUMENT_URI = 131072U,
    LOAD_REPLACE = 262144U,
    LOAD_INITIAL_DOCUMENT_URI = 524288U,
    LOAD_TARGETED = 1048576U,
    LOAD_CALL_CONTENT_SNIFFERS = 2097152U,
    LOAD_CLASSIFY_URI = 4194304U,
    LOAD_TREAT_APPLICATION_OCTET_STREAM_AS_UNKNOWN = 8388608U,
    LOAD_EXPLICIT_CREDENTIALS = 16777216U
  };

  /* attribute unsigned long contentDisposition; */
  NS_IMETHOD GetContentDisposition(uint32_t *aContentDisposition) = 0;
  NS_IMETHOD SetContentDisposition(uint32_t aContentDisposition) = 0;

  enum {
    DISPOSITION_INLINE = 0U,
    DISPOSITION_ATTACHMENT = 1U
  };

  /* attribute AString contentDispositionFilename; */
  NS_IMETHOD GetContentDispositionFilename(nsAString & aContentDispositionFilename) = 0;
  NS_IMETHOD SetContentDispositionFilename(const nsAString & aContentDispositionFilename) = 0;

  /* readonly attribute ACString contentDispositionHeader; */
  NS_IMETHOD GetContentDispositionHeader(nsACString & aContentDispositionHeader) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIChannel, NS_ICHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICHANNEL \
  NS_IMETHOD GetOriginalURI(nsIURI * *aOriginalURI); \
  NS_IMETHOD SetOriginalURI(nsIURI *aOriginalURI); \
  NS_IMETHOD GetURI(nsIURI * *aURI); \
  NS_IMETHOD GetOwner(nsISupports * *aOwner); \
  NS_IMETHOD SetOwner(nsISupports *aOwner); \
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks); \
  NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks); \
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo); \
  NS_IMETHOD GetContentType(nsACString & aContentType); \
  NS_IMETHOD SetContentType(const nsACString & aContentType); \
  NS_IMETHOD GetContentCharset(nsACString & aContentCharset); \
  NS_IMETHOD SetContentCharset(const nsACString & aContentCharset); \
  NS_IMETHOD GetContentLength(int64_t *aContentLength); \
  NS_IMETHOD SetContentLength(int64_t aContentLength); \
  NS_IMETHOD Open(nsIInputStream * *_retval); \
  NS_IMETHOD AsyncOpen(nsIStreamListener *aListener, nsISupports *aContext); \
  NS_IMETHOD GetContentDisposition(uint32_t *aContentDisposition); \
  NS_IMETHOD SetContentDisposition(uint32_t aContentDisposition); \
  NS_IMETHOD GetContentDispositionFilename(nsAString & aContentDispositionFilename); \
  NS_IMETHOD SetContentDispositionFilename(const nsAString & aContentDispositionFilename); \
  NS_IMETHOD GetContentDispositionHeader(nsACString & aContentDispositionHeader); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICHANNEL(_to) \
  NS_IMETHOD GetOriginalURI(nsIURI * *aOriginalURI) { return _to GetOriginalURI(aOriginalURI); } \
  NS_IMETHOD SetOriginalURI(nsIURI *aOriginalURI) { return _to SetOriginalURI(aOriginalURI); } \
  NS_IMETHOD GetURI(nsIURI * *aURI) { return _to GetURI(aURI); } \
  NS_IMETHOD GetOwner(nsISupports * *aOwner) { return _to GetOwner(aOwner); } \
  NS_IMETHOD SetOwner(nsISupports *aOwner) { return _to SetOwner(aOwner); } \
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks) { return _to GetNotificationCallbacks(aNotificationCallbacks); } \
  NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks) { return _to SetNotificationCallbacks(aNotificationCallbacks); } \
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) { return _to GetSecurityInfo(aSecurityInfo); } \
  NS_IMETHOD GetContentType(nsACString & aContentType) { return _to GetContentType(aContentType); } \
  NS_IMETHOD SetContentType(const nsACString & aContentType) { return _to SetContentType(aContentType); } \
  NS_IMETHOD GetContentCharset(nsACString & aContentCharset) { return _to GetContentCharset(aContentCharset); } \
  NS_IMETHOD SetContentCharset(const nsACString & aContentCharset) { return _to SetContentCharset(aContentCharset); } \
  NS_IMETHOD GetContentLength(int64_t *aContentLength) { return _to GetContentLength(aContentLength); } \
  NS_IMETHOD SetContentLength(int64_t aContentLength) { return _to SetContentLength(aContentLength); } \
  NS_IMETHOD Open(nsIInputStream * *_retval) { return _to Open(_retval); } \
  NS_IMETHOD AsyncOpen(nsIStreamListener *aListener, nsISupports *aContext) { return _to AsyncOpen(aListener, aContext); } \
  NS_IMETHOD GetContentDisposition(uint32_t *aContentDisposition) { return _to GetContentDisposition(aContentDisposition); } \
  NS_IMETHOD SetContentDisposition(uint32_t aContentDisposition) { return _to SetContentDisposition(aContentDisposition); } \
  NS_IMETHOD GetContentDispositionFilename(nsAString & aContentDispositionFilename) { return _to GetContentDispositionFilename(aContentDispositionFilename); } \
  NS_IMETHOD SetContentDispositionFilename(const nsAString & aContentDispositionFilename) { return _to SetContentDispositionFilename(aContentDispositionFilename); } \
  NS_IMETHOD GetContentDispositionHeader(nsACString & aContentDispositionHeader) { return _to GetContentDispositionHeader(aContentDispositionHeader); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICHANNEL(_to) \
  NS_IMETHOD GetOriginalURI(nsIURI * *aOriginalURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOriginalURI(aOriginalURI); } \
  NS_IMETHOD SetOriginalURI(nsIURI *aOriginalURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOriginalURI(aOriginalURI); } \
  NS_IMETHOD GetURI(nsIURI * *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURI(aURI); } \
  NS_IMETHOD GetOwner(nsISupports * *aOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOwner(aOwner); } \
  NS_IMETHOD SetOwner(nsISupports *aOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOwner(aOwner); } \
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNotificationCallbacks(aNotificationCallbacks); } \
  NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNotificationCallbacks(aNotificationCallbacks); } \
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSecurityInfo(aSecurityInfo); } \
  NS_IMETHOD GetContentType(nsACString & aContentType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentType(aContentType); } \
  NS_IMETHOD SetContentType(const nsACString & aContentType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentType(aContentType); } \
  NS_IMETHOD GetContentCharset(nsACString & aContentCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentCharset(aContentCharset); } \
  NS_IMETHOD SetContentCharset(const nsACString & aContentCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentCharset(aContentCharset); } \
  NS_IMETHOD GetContentLength(int64_t *aContentLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentLength(aContentLength); } \
  NS_IMETHOD SetContentLength(int64_t aContentLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentLength(aContentLength); } \
  NS_IMETHOD Open(nsIInputStream * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(_retval); } \
  NS_IMETHOD AsyncOpen(nsIStreamListener *aListener, nsISupports *aContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncOpen(aListener, aContext); } \
  NS_IMETHOD GetContentDisposition(uint32_t *aContentDisposition) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentDisposition(aContentDisposition); } \
  NS_IMETHOD SetContentDisposition(uint32_t aContentDisposition) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentDisposition(aContentDisposition); } \
  NS_IMETHOD GetContentDispositionFilename(nsAString & aContentDispositionFilename) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentDispositionFilename(aContentDispositionFilename); } \
  NS_IMETHOD SetContentDispositionFilename(const nsAString & aContentDispositionFilename) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentDispositionFilename(aContentDispositionFilename); } \
  NS_IMETHOD GetContentDispositionHeader(nsACString & aContentDispositionHeader) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentDispositionHeader(aContentDispositionHeader); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsChannel : public nsIChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICHANNEL

  nsChannel();

private:
  ~nsChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsChannel, nsIChannel)

nsChannel::nsChannel()
{
  /* member initializers and constructor code */
}

nsChannel::~nsChannel()
{
  /* destructor code */
}

/* attribute nsIURI originalURI; */
NS_IMETHODIMP nsChannel::GetOriginalURI(nsIURI * *aOriginalURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsChannel::SetOriginalURI(nsIURI *aOriginalURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI URI; */
NS_IMETHODIMP nsChannel::GetURI(nsIURI * *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISupports owner; */
NS_IMETHODIMP nsChannel::GetOwner(nsISupports * *aOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsChannel::SetOwner(nsISupports *aOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIInterfaceRequestor notificationCallbacks; */
NS_IMETHODIMP nsChannel::GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsChannel::SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports securityInfo; */
NS_IMETHODIMP nsChannel::GetSecurityInfo(nsISupports * *aSecurityInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString contentType; */
NS_IMETHODIMP nsChannel::GetContentType(nsACString & aContentType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsChannel::SetContentType(const nsACString & aContentType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString contentCharset; */
NS_IMETHODIMP nsChannel::GetContentCharset(nsACString & aContentCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsChannel::SetContentCharset(const nsACString & aContentCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute int64_t contentLength; */
NS_IMETHODIMP nsChannel::GetContentLength(int64_t *aContentLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsChannel::SetContentLength(int64_t aContentLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream open (); */
NS_IMETHODIMP nsChannel::Open(nsIInputStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncOpen (in nsIStreamListener aListener, in nsISupports aContext); */
NS_IMETHODIMP nsChannel::AsyncOpen(nsIStreamListener *aListener, nsISupports *aContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long contentDisposition; */
NS_IMETHODIMP nsChannel::GetContentDisposition(uint32_t *aContentDisposition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsChannel::SetContentDisposition(uint32_t aContentDisposition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString contentDispositionFilename; */
NS_IMETHODIMP nsChannel::GetContentDispositionFilename(nsAString & aContentDispositionFilename)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsChannel::SetContentDispositionFilename(const nsAString & aContentDispositionFilename)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString contentDispositionHeader; */
NS_IMETHODIMP nsChannel::GetContentDispositionHeader(nsACString & aContentDispositionHeader)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIChannel_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIFaviconService.idl
 */

#ifndef __gen_nsIFaviconService_h__
#define __gen_nsIFaviconService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsIFaviconService */
#define NS_IFAVICONSERVICE_IID_STR "e81e0b0c-b9f1-4c2e-8f3c-b809933cf73c"

#define NS_IFAVICONSERVICE_IID \
  {0xe81e0b0c, 0xb9f1, 0x4c2e, \
    { 0x8f, 0x3c, 0xb8, 0x09, 0x93, 0x3c, 0xf7, 0x3c }}

class NS_NO_VTABLE nsIFaviconService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFAVICONSERVICE_IID)

  enum {
    FAVICON_LOAD_PRIVATE = 1U,
    FAVICON_LOAD_NON_PRIVATE = 2U
  };

  /* nsIURI getFaviconLinkForIcon (in nsIURI aFaviconURI); */
  NS_IMETHOD GetFaviconLinkForIcon(nsIURI *aFaviconURI, nsIURI * *_retval) = 0;

  /* void expireAllFavicons (); */
  NS_IMETHOD ExpireAllFavicons(void) = 0;

  /* void addFailedFavicon (in nsIURI aFaviconURI); */
  NS_IMETHOD AddFailedFavicon(nsIURI *aFaviconURI) = 0;

  /* void removeFailedFavicon (in nsIURI aFaviconURI); */
  NS_IMETHOD RemoveFailedFavicon(nsIURI *aFaviconURI) = 0;

  /* boolean isFailedFavicon (in nsIURI aFaviconURI); */
  NS_IMETHOD IsFailedFavicon(nsIURI *aFaviconURI, bool *_retval) = 0;

  /* readonly attribute nsIURI defaultFavicon; */
  NS_IMETHOD GetDefaultFavicon(nsIURI * *aDefaultFavicon) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFaviconService, NS_IFAVICONSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFAVICONSERVICE \
  NS_IMETHOD GetFaviconLinkForIcon(nsIURI *aFaviconURI, nsIURI * *_retval); \
  NS_IMETHOD ExpireAllFavicons(void); \
  NS_IMETHOD AddFailedFavicon(nsIURI *aFaviconURI); \
  NS_IMETHOD RemoveFailedFavicon(nsIURI *aFaviconURI); \
  NS_IMETHOD IsFailedFavicon(nsIURI *aFaviconURI, bool *_retval); \
  NS_IMETHOD GetDefaultFavicon(nsIURI * *aDefaultFavicon); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFAVICONSERVICE(_to) \
  NS_IMETHOD GetFaviconLinkForIcon(nsIURI *aFaviconURI, nsIURI * *_retval) { return _to GetFaviconLinkForIcon(aFaviconURI, _retval); } \
  NS_IMETHOD ExpireAllFavicons(void) { return _to ExpireAllFavicons(); } \
  NS_IMETHOD AddFailedFavicon(nsIURI *aFaviconURI) { return _to AddFailedFavicon(aFaviconURI); } \
  NS_IMETHOD RemoveFailedFavicon(nsIURI *aFaviconURI) { return _to RemoveFailedFavicon(aFaviconURI); } \
  NS_IMETHOD IsFailedFavicon(nsIURI *aFaviconURI, bool *_retval) { return _to IsFailedFavicon(aFaviconURI, _retval); } \
  NS_IMETHOD GetDefaultFavicon(nsIURI * *aDefaultFavicon) { return _to GetDefaultFavicon(aDefaultFavicon); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFAVICONSERVICE(_to) \
  NS_IMETHOD GetFaviconLinkForIcon(nsIURI *aFaviconURI, nsIURI * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFaviconLinkForIcon(aFaviconURI, _retval); } \
  NS_IMETHOD ExpireAllFavicons(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExpireAllFavicons(); } \
  NS_IMETHOD AddFailedFavicon(nsIURI *aFaviconURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddFailedFavicon(aFaviconURI); } \
  NS_IMETHOD RemoveFailedFavicon(nsIURI *aFaviconURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveFailedFavicon(aFaviconURI); } \
  NS_IMETHOD IsFailedFavicon(nsIURI *aFaviconURI, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsFailedFavicon(aFaviconURI, _retval); } \
  NS_IMETHOD GetDefaultFavicon(nsIURI * *aDefaultFavicon) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultFavicon(aDefaultFavicon); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFaviconService : public nsIFaviconService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFAVICONSERVICE

  nsFaviconService();

private:
  ~nsFaviconService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFaviconService, nsIFaviconService)

nsFaviconService::nsFaviconService()
{
  /* member initializers and constructor code */
}

nsFaviconService::~nsFaviconService()
{
  /* destructor code */
}

/* nsIURI getFaviconLinkForIcon (in nsIURI aFaviconURI); */
NS_IMETHODIMP nsFaviconService::GetFaviconLinkForIcon(nsIURI *aFaviconURI, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void expireAllFavicons (); */
NS_IMETHODIMP nsFaviconService::ExpireAllFavicons()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addFailedFavicon (in nsIURI aFaviconURI); */
NS_IMETHODIMP nsFaviconService::AddFailedFavicon(nsIURI *aFaviconURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeFailedFavicon (in nsIURI aFaviconURI); */
NS_IMETHODIMP nsFaviconService::RemoveFailedFavicon(nsIURI *aFaviconURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isFailedFavicon (in nsIURI aFaviconURI); */
NS_IMETHODIMP nsFaviconService::IsFailedFavicon(nsIURI *aFaviconURI, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI defaultFavicon; */
NS_IMETHODIMP nsFaviconService::GetDefaultFavicon(nsIURI * *aDefaultFavicon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIFaviconDataCallback */
#define NS_IFAVICONDATACALLBACK_IID_STR "c85e5c82-b70f-4621-9528-beb2aa47fb44"

#define NS_IFAVICONDATACALLBACK_IID \
  {0xc85e5c82, 0xb70f, 0x4621, \
    { 0x95, 0x28, 0xbe, 0xb2, 0xaa, 0x47, 0xfb, 0x44 }}

class NS_NO_VTABLE nsIFaviconDataCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFAVICONDATACALLBACK_IID)

  /* void onComplete (in nsIURI aFaviconURI, in unsigned long aDataLen, [array, size_is (aDataLen), const] in octet aData, in AUTF8String aMimeType); */
  NS_IMETHOD OnComplete(nsIURI *aFaviconURI, uint32_t aDataLen, const uint8_t *aData, const nsACString & aMimeType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFaviconDataCallback, NS_IFAVICONDATACALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFAVICONDATACALLBACK \
  NS_IMETHOD OnComplete(nsIURI *aFaviconURI, uint32_t aDataLen, const uint8_t *aData, const nsACString & aMimeType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFAVICONDATACALLBACK(_to) \
  NS_IMETHOD OnComplete(nsIURI *aFaviconURI, uint32_t aDataLen, const uint8_t *aData, const nsACString & aMimeType) { return _to OnComplete(aFaviconURI, aDataLen, aData, aMimeType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFAVICONDATACALLBACK(_to) \
  NS_IMETHOD OnComplete(nsIURI *aFaviconURI, uint32_t aDataLen, const uint8_t *aData, const nsACString & aMimeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnComplete(aFaviconURI, aDataLen, aData, aMimeType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFaviconDataCallback : public nsIFaviconDataCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFAVICONDATACALLBACK

  nsFaviconDataCallback();

private:
  ~nsFaviconDataCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFaviconDataCallback, nsIFaviconDataCallback)

nsFaviconDataCallback::nsFaviconDataCallback()
{
  /* member initializers and constructor code */
}

nsFaviconDataCallback::~nsFaviconDataCallback()
{
  /* destructor code */
}

/* void onComplete (in nsIURI aFaviconURI, in unsigned long aDataLen, [array, size_is (aDataLen), const] in octet aData, in AUTF8String aMimeType); */
NS_IMETHODIMP nsFaviconDataCallback::OnComplete(nsIURI *aFaviconURI, uint32_t aDataLen, const uint8_t *aData, const nsACString & aMimeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/**
 * Notification sent when all favicons are expired.
 */
#define NS_PLACES_FAVICONS_EXPIRED_TOPIC_ID "places-favicons-expired"
#define FAVICON_DEFAULT_URL "chrome://mozapps/skin/places/defaultFavicon.png"
#define FAVICON_ERRORPAGE_URL "chrome://global/skin/icons/warning-16.png"

#endif /* __gen_nsIFaviconService_h__ */

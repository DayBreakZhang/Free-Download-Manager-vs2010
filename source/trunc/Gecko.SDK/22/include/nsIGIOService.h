/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/system/nsIGIOService.idl
 */

#ifndef __gen_nsIGIOService_h__
#define __gen_nsIGIOService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIUTF8StringEnumerator; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIGIOMimeApp */
#define NS_IGIOMIMEAPP_IID_STR "ca6bad0c-8a48-48ac-82c7-27bb8f510fbe"

#define NS_IGIOMIMEAPP_IID \
  {0xca6bad0c, 0x8a48, 0x48ac, \
    { 0x82, 0xc7, 0x27, 0xbb, 0x8f, 0x51, 0x0f, 0xbe }}

class NS_NO_VTABLE nsIGIOMimeApp : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGIOMIMEAPP_IID)

  enum {
    EXPECTS_URIS = 0,
    EXPECTS_PATHS = 1,
    EXPECTS_URIS_FOR_NON_FILES = 2
  };

  /* readonly attribute AUTF8String id; */
  NS_IMETHOD GetId(nsACString & aId) = 0;

  /* readonly attribute AUTF8String name; */
  NS_IMETHOD GetName(nsACString & aName) = 0;

  /* readonly attribute AUTF8String command; */
  NS_IMETHOD GetCommand(nsACString & aCommand) = 0;

  /* readonly attribute long expectsURIs; */
  NS_IMETHOD GetExpectsURIs(int32_t *aExpectsURIs) = 0;

  /* readonly attribute nsIUTF8StringEnumerator supportedURISchemes; */
  NS_IMETHOD GetSupportedURISchemes(nsIUTF8StringEnumerator * *aSupportedURISchemes) = 0;

  /* void launch (in AUTF8String uri); */
  NS_IMETHOD Launch(const nsACString & uri) = 0;

  /* void setAsDefaultForMimeType (in AUTF8String mimeType); */
  NS_IMETHOD SetAsDefaultForMimeType(const nsACString & mimeType) = 0;

  /* void setAsDefaultForFileExtensions (in AUTF8String extensions); */
  NS_IMETHOD SetAsDefaultForFileExtensions(const nsACString & extensions) = 0;

  /* void setAsDefaultForURIScheme (in AUTF8String uriScheme); */
  NS_IMETHOD SetAsDefaultForURIScheme(const nsACString & uriScheme) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGIOMimeApp, NS_IGIOMIMEAPP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGIOMIMEAPP \
  NS_IMETHOD GetId(nsACString & aId); \
  NS_IMETHOD GetName(nsACString & aName); \
  NS_IMETHOD GetCommand(nsACString & aCommand); \
  NS_IMETHOD GetExpectsURIs(int32_t *aExpectsURIs); \
  NS_IMETHOD GetSupportedURISchemes(nsIUTF8StringEnumerator * *aSupportedURISchemes); \
  NS_IMETHOD Launch(const nsACString & uri); \
  NS_IMETHOD SetAsDefaultForMimeType(const nsACString & mimeType); \
  NS_IMETHOD SetAsDefaultForFileExtensions(const nsACString & extensions); \
  NS_IMETHOD SetAsDefaultForURIScheme(const nsACString & uriScheme); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGIOMIMEAPP(_to) \
  NS_IMETHOD GetId(nsACString & aId) { return _to GetId(aId); } \
  NS_IMETHOD GetName(nsACString & aName) { return _to GetName(aName); } \
  NS_IMETHOD GetCommand(nsACString & aCommand) { return _to GetCommand(aCommand); } \
  NS_IMETHOD GetExpectsURIs(int32_t *aExpectsURIs) { return _to GetExpectsURIs(aExpectsURIs); } \
  NS_IMETHOD GetSupportedURISchemes(nsIUTF8StringEnumerator * *aSupportedURISchemes) { return _to GetSupportedURISchemes(aSupportedURISchemes); } \
  NS_IMETHOD Launch(const nsACString & uri) { return _to Launch(uri); } \
  NS_IMETHOD SetAsDefaultForMimeType(const nsACString & mimeType) { return _to SetAsDefaultForMimeType(mimeType); } \
  NS_IMETHOD SetAsDefaultForFileExtensions(const nsACString & extensions) { return _to SetAsDefaultForFileExtensions(extensions); } \
  NS_IMETHOD SetAsDefaultForURIScheme(const nsACString & uriScheme) { return _to SetAsDefaultForURIScheme(uriScheme); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGIOMIMEAPP(_to) \
  NS_IMETHOD GetId(nsACString & aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_IMETHOD GetName(nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetCommand(nsACString & aCommand) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCommand(aCommand); } \
  NS_IMETHOD GetExpectsURIs(int32_t *aExpectsURIs) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExpectsURIs(aExpectsURIs); } \
  NS_IMETHOD GetSupportedURISchemes(nsIUTF8StringEnumerator * *aSupportedURISchemes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSupportedURISchemes(aSupportedURISchemes); } \
  NS_IMETHOD Launch(const nsACString & uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->Launch(uri); } \
  NS_IMETHOD SetAsDefaultForMimeType(const nsACString & mimeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsDefaultForMimeType(mimeType); } \
  NS_IMETHOD SetAsDefaultForFileExtensions(const nsACString & extensions) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsDefaultForFileExtensions(extensions); } \
  NS_IMETHOD SetAsDefaultForURIScheme(const nsACString & uriScheme) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsDefaultForURIScheme(uriScheme); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGIOMimeApp : public nsIGIOMimeApp
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGIOMIMEAPP

  nsGIOMimeApp();

private:
  ~nsGIOMimeApp();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsGIOMimeApp, nsIGIOMimeApp)

nsGIOMimeApp::nsGIOMimeApp()
{
  /* member initializers and constructor code */
}

nsGIOMimeApp::~nsGIOMimeApp()
{
  /* destructor code */
}

/* readonly attribute AUTF8String id; */
NS_IMETHODIMP nsGIOMimeApp::GetId(nsACString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String name; */
NS_IMETHODIMP nsGIOMimeApp::GetName(nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String command; */
NS_IMETHODIMP nsGIOMimeApp::GetCommand(nsACString & aCommand)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long expectsURIs; */
NS_IMETHODIMP nsGIOMimeApp::GetExpectsURIs(int32_t *aExpectsURIs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIUTF8StringEnumerator supportedURISchemes; */
NS_IMETHODIMP nsGIOMimeApp::GetSupportedURISchemes(nsIUTF8StringEnumerator * *aSupportedURISchemes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void launch (in AUTF8String uri); */
NS_IMETHODIMP nsGIOMimeApp::Launch(const nsACString & uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsDefaultForMimeType (in AUTF8String mimeType); */
NS_IMETHODIMP nsGIOMimeApp::SetAsDefaultForMimeType(const nsACString & mimeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsDefaultForFileExtensions (in AUTF8String extensions); */
NS_IMETHODIMP nsGIOMimeApp::SetAsDefaultForFileExtensions(const nsACString & extensions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsDefaultForURIScheme (in AUTF8String uriScheme); */
NS_IMETHODIMP nsGIOMimeApp::SetAsDefaultForURIScheme(const nsACString & uriScheme)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIGIOService */
#define NS_IGIOSERVICE_IID_STR "eda22a30-84e1-4e16-9ca0-cd1553c2b34a"

#define NS_IGIOSERVICE_IID \
  {0xeda22a30, 0x84e1, 0x4e16, \
    { 0x9c, 0xa0, 0xcd, 0x15, 0x53, 0xc2, 0xb3, 0x4a }}

class NS_NO_VTABLE nsIGIOService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGIOSERVICE_IID)

  /* AUTF8String getMimeTypeFromExtension (in AUTF8String extension); */
  NS_IMETHOD GetMimeTypeFromExtension(const nsACString & extension, nsACString & _retval) = 0;

  /* nsIGIOMimeApp getAppForURIScheme (in AUTF8String aURIScheme); */
  NS_IMETHOD GetAppForURIScheme(const nsACString & aURIScheme, nsIGIOMimeApp * *_retval) = 0;

  /* nsIGIOMimeApp getAppForMimeType (in AUTF8String mimeType); */
  NS_IMETHOD GetAppForMimeType(const nsACString & mimeType, nsIGIOMimeApp * *_retval) = 0;

  /* nsIGIOMimeApp createAppFromCommand (in AUTF8String cmd, in AUTF8String appName); */
  NS_IMETHOD CreateAppFromCommand(const nsACString & cmd, const nsACString & appName, nsIGIOMimeApp * *_retval) = 0;

  /* AUTF8String getDescriptionForMimeType (in AUTF8String mimeType); */
  NS_IMETHOD GetDescriptionForMimeType(const nsACString & mimeType, nsACString & _retval) = 0;

  /* void showURI (in nsIURI uri); */
  NS_IMETHOD ShowURI(nsIURI *uri) = 0;

  /* [noscript] void showURIForInput (in ACString uri); */
  NS_IMETHOD ShowURIForInput(const nsACString & uri) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGIOService, NS_IGIOSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGIOSERVICE \
  NS_IMETHOD GetMimeTypeFromExtension(const nsACString & extension, nsACString & _retval); \
  NS_IMETHOD GetAppForURIScheme(const nsACString & aURIScheme, nsIGIOMimeApp * *_retval); \
  NS_IMETHOD GetAppForMimeType(const nsACString & mimeType, nsIGIOMimeApp * *_retval); \
  NS_IMETHOD CreateAppFromCommand(const nsACString & cmd, const nsACString & appName, nsIGIOMimeApp * *_retval); \
  NS_IMETHOD GetDescriptionForMimeType(const nsACString & mimeType, nsACString & _retval); \
  NS_IMETHOD ShowURI(nsIURI *uri); \
  NS_IMETHOD ShowURIForInput(const nsACString & uri); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGIOSERVICE(_to) \
  NS_IMETHOD GetMimeTypeFromExtension(const nsACString & extension, nsACString & _retval) { return _to GetMimeTypeFromExtension(extension, _retval); } \
  NS_IMETHOD GetAppForURIScheme(const nsACString & aURIScheme, nsIGIOMimeApp * *_retval) { return _to GetAppForURIScheme(aURIScheme, _retval); } \
  NS_IMETHOD GetAppForMimeType(const nsACString & mimeType, nsIGIOMimeApp * *_retval) { return _to GetAppForMimeType(mimeType, _retval); } \
  NS_IMETHOD CreateAppFromCommand(const nsACString & cmd, const nsACString & appName, nsIGIOMimeApp * *_retval) { return _to CreateAppFromCommand(cmd, appName, _retval); } \
  NS_IMETHOD GetDescriptionForMimeType(const nsACString & mimeType, nsACString & _retval) { return _to GetDescriptionForMimeType(mimeType, _retval); } \
  NS_IMETHOD ShowURI(nsIURI *uri) { return _to ShowURI(uri); } \
  NS_IMETHOD ShowURIForInput(const nsACString & uri) { return _to ShowURIForInput(uri); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGIOSERVICE(_to) \
  NS_IMETHOD GetMimeTypeFromExtension(const nsACString & extension, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMimeTypeFromExtension(extension, _retval); } \
  NS_IMETHOD GetAppForURIScheme(const nsACString & aURIScheme, nsIGIOMimeApp * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppForURIScheme(aURIScheme, _retval); } \
  NS_IMETHOD GetAppForMimeType(const nsACString & mimeType, nsIGIOMimeApp * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppForMimeType(mimeType, _retval); } \
  NS_IMETHOD CreateAppFromCommand(const nsACString & cmd, const nsACString & appName, nsIGIOMimeApp * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateAppFromCommand(cmd, appName, _retval); } \
  NS_IMETHOD GetDescriptionForMimeType(const nsACString & mimeType, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDescriptionForMimeType(mimeType, _retval); } \
  NS_IMETHOD ShowURI(nsIURI *uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowURI(uri); } \
  NS_IMETHOD ShowURIForInput(const nsACString & uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowURIForInput(uri); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGIOService : public nsIGIOService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGIOSERVICE

  nsGIOService();

private:
  ~nsGIOService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsGIOService, nsIGIOService)

nsGIOService::nsGIOService()
{
  /* member initializers and constructor code */
}

nsGIOService::~nsGIOService()
{
  /* destructor code */
}

/* AUTF8String getMimeTypeFromExtension (in AUTF8String extension); */
NS_IMETHODIMP nsGIOService::GetMimeTypeFromExtension(const nsACString & extension, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIGIOMimeApp getAppForURIScheme (in AUTF8String aURIScheme); */
NS_IMETHODIMP nsGIOService::GetAppForURIScheme(const nsACString & aURIScheme, nsIGIOMimeApp * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIGIOMimeApp getAppForMimeType (in AUTF8String mimeType); */
NS_IMETHODIMP nsGIOService::GetAppForMimeType(const nsACString & mimeType, nsIGIOMimeApp * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIGIOMimeApp createAppFromCommand (in AUTF8String cmd, in AUTF8String appName); */
NS_IMETHODIMP nsGIOService::CreateAppFromCommand(const nsACString & cmd, const nsACString & appName, nsIGIOMimeApp * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getDescriptionForMimeType (in AUTF8String mimeType); */
NS_IMETHODIMP nsGIOService::GetDescriptionForMimeType(const nsACString & mimeType, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showURI (in nsIURI uri); */
NS_IMETHODIMP nsGIOService::ShowURI(nsIURI *uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void showURIForInput (in ACString uri); */
NS_IMETHODIMP nsGIOService::ShowURIForInput(const nsACString & uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_GIOSERVICE_CONTRACTID "@mozilla.org/gio-service;1"

#endif /* __gen_nsIGIOService_h__ */

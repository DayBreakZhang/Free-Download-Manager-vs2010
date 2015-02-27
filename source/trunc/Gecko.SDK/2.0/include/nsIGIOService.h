/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/xpcom/system/nsIGIOService.idl
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
#define NS_IGIOMIMEAPP_IID_STR "e77021b4-4012-407d-b686-7a1f18050109"

#define NS_IGIOMIMEAPP_IID \
  {0xe77021b4, 0x4012, 0x407d, \
    { 0xb6, 0x86, 0x7a, 0x1f, 0x18, 0x05, 0x01, 0x09 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIGIOMimeApp : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGIOMIMEAPP_IID)

  enum { EXPECTS_URIS = 0 };

  enum { EXPECTS_PATHS = 1 };

  enum { EXPECTS_URIS_FOR_NON_FILES = 2 };

  /* readonly attribute AUTF8String id; */
  NS_SCRIPTABLE NS_IMETHOD GetId(nsACString & aId) = 0;

  /* readonly attribute AUTF8String name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsACString & aName) = 0;

  /* readonly attribute AUTF8String command; */
  NS_SCRIPTABLE NS_IMETHOD GetCommand(nsACString & aCommand) = 0;

  /* readonly attribute long expectsURIs; */
  NS_SCRIPTABLE NS_IMETHOD GetExpectsURIs(PRInt32 *aExpectsURIs) = 0;

  /* readonly attribute nsIUTF8StringEnumerator supportedURISchemes; */
  NS_SCRIPTABLE NS_IMETHOD GetSupportedURISchemes(nsIUTF8StringEnumerator **aSupportedURISchemes) = 0;

  /* void launch (in AUTF8String uri); */
  NS_SCRIPTABLE NS_IMETHOD Launch(const nsACString & uri) = 0;

  /* void setAsDefaultForMimeType (in AUTF8String mimeType); */
  NS_SCRIPTABLE NS_IMETHOD SetAsDefaultForMimeType(const nsACString & mimeType) = 0;

  /* void setAsDefaultForFileExtensions (in AUTF8String extensions); */
  NS_SCRIPTABLE NS_IMETHOD SetAsDefaultForFileExtensions(const nsACString & extensions) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGIOMimeApp, NS_IGIOMIMEAPP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGIOMIMEAPP \
  NS_SCRIPTABLE NS_IMETHOD GetId(nsACString & aId); \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsACString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetCommand(nsACString & aCommand); \
  NS_SCRIPTABLE NS_IMETHOD GetExpectsURIs(PRInt32 *aExpectsURIs); \
  NS_SCRIPTABLE NS_IMETHOD GetSupportedURISchemes(nsIUTF8StringEnumerator **aSupportedURISchemes); \
  NS_SCRIPTABLE NS_IMETHOD Launch(const nsACString & uri); \
  NS_SCRIPTABLE NS_IMETHOD SetAsDefaultForMimeType(const nsACString & mimeType); \
  NS_SCRIPTABLE NS_IMETHOD SetAsDefaultForFileExtensions(const nsACString & extensions); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGIOMIMEAPP(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetId(nsACString & aId) { return _to GetId(aId); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsACString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetCommand(nsACString & aCommand) { return _to GetCommand(aCommand); } \
  NS_SCRIPTABLE NS_IMETHOD GetExpectsURIs(PRInt32 *aExpectsURIs) { return _to GetExpectsURIs(aExpectsURIs); } \
  NS_SCRIPTABLE NS_IMETHOD GetSupportedURISchemes(nsIUTF8StringEnumerator **aSupportedURISchemes) { return _to GetSupportedURISchemes(aSupportedURISchemes); } \
  NS_SCRIPTABLE NS_IMETHOD Launch(const nsACString & uri) { return _to Launch(uri); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsDefaultForMimeType(const nsACString & mimeType) { return _to SetAsDefaultForMimeType(mimeType); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsDefaultForFileExtensions(const nsACString & extensions) { return _to SetAsDefaultForFileExtensions(extensions); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGIOMIMEAPP(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetId(nsACString & aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetCommand(nsACString & aCommand) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCommand(aCommand); } \
  NS_SCRIPTABLE NS_IMETHOD GetExpectsURIs(PRInt32 *aExpectsURIs) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExpectsURIs(aExpectsURIs); } \
  NS_SCRIPTABLE NS_IMETHOD GetSupportedURISchemes(nsIUTF8StringEnumerator **aSupportedURISchemes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSupportedURISchemes(aSupportedURISchemes); } \
  NS_SCRIPTABLE NS_IMETHOD Launch(const nsACString & uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->Launch(uri); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsDefaultForMimeType(const nsACString & mimeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsDefaultForMimeType(mimeType); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsDefaultForFileExtensions(const nsACString & extensions) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsDefaultForFileExtensions(extensions); } 

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
NS_IMETHODIMP nsGIOMimeApp::GetExpectsURIs(PRInt32 *aExpectsURIs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIUTF8StringEnumerator supportedURISchemes; */
NS_IMETHODIMP nsGIOMimeApp::GetSupportedURISchemes(nsIUTF8StringEnumerator **aSupportedURISchemes)
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

/* End of implementation class template. */
#endif


/* starting interface:    nsIGIOService */
#define NS_IGIOSERVICE_IID_STR "47e372c2-78bb-4899-8114-56aa7d9cdac5"

#define NS_IGIOSERVICE_IID \
  {0x47e372c2, 0x78bb, 0x4899, \
    { 0x81, 0x14, 0x56, 0xaa, 0x7d, 0x9c, 0xda, 0xc5 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIGIOService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGIOSERVICE_IID)

  /*** MIME registry methods ***/
  /* AUTF8String getMimeTypeFromExtension (in AUTF8String extension); */
  NS_SCRIPTABLE NS_IMETHOD GetMimeTypeFromExtension(const nsACString & extension, nsACString & _retval NS_OUTPARAM) = 0;

  /* nsIGIOMimeApp getAppForMimeType (in AUTF8String mimeType); */
  NS_SCRIPTABLE NS_IMETHOD GetAppForMimeType(const nsACString & mimeType, nsIGIOMimeApp **_retval NS_OUTPARAM) = 0;

  /* nsIGIOMimeApp createAppFromCommand (in AUTF8String cmd, in AUTF8String appName); */
  NS_SCRIPTABLE NS_IMETHOD CreateAppFromCommand(const nsACString & cmd, const nsACString & appName, nsIGIOMimeApp **_retval NS_OUTPARAM) = 0;

  /* AUTF8String getDescriptionForMimeType (in AUTF8String mimeType); */
  NS_SCRIPTABLE NS_IMETHOD GetDescriptionForMimeType(const nsACString & mimeType, nsACString & _retval NS_OUTPARAM) = 0;

  /*** Misc. methods ***/
  /* void showURI (in nsIURI uri); */
  NS_SCRIPTABLE NS_IMETHOD ShowURI(nsIURI *uri) = 0;

  /* [noscript] void showURIForInput (in ACString uri); */
  NS_IMETHOD ShowURIForInput(const nsACString & uri) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGIOService, NS_IGIOSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGIOSERVICE \
  NS_SCRIPTABLE NS_IMETHOD GetMimeTypeFromExtension(const nsACString & extension, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAppForMimeType(const nsACString & mimeType, nsIGIOMimeApp **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateAppFromCommand(const nsACString & cmd, const nsACString & appName, nsIGIOMimeApp **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetDescriptionForMimeType(const nsACString & mimeType, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ShowURI(nsIURI *uri); \
  NS_IMETHOD ShowURIForInput(const nsACString & uri); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGIOSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMimeTypeFromExtension(const nsACString & extension, nsACString & _retval NS_OUTPARAM) { return _to GetMimeTypeFromExtension(extension, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAppForMimeType(const nsACString & mimeType, nsIGIOMimeApp **_retval NS_OUTPARAM) { return _to GetAppForMimeType(mimeType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateAppFromCommand(const nsACString & cmd, const nsACString & appName, nsIGIOMimeApp **_retval NS_OUTPARAM) { return _to CreateAppFromCommand(cmd, appName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDescriptionForMimeType(const nsACString & mimeType, nsACString & _retval NS_OUTPARAM) { return _to GetDescriptionForMimeType(mimeType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ShowURI(nsIURI *uri) { return _to ShowURI(uri); } \
  NS_IMETHOD ShowURIForInput(const nsACString & uri) { return _to ShowURIForInput(uri); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGIOSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMimeTypeFromExtension(const nsACString & extension, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMimeTypeFromExtension(extension, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAppForMimeType(const nsACString & mimeType, nsIGIOMimeApp **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppForMimeType(mimeType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateAppFromCommand(const nsACString & cmd, const nsACString & appName, nsIGIOMimeApp **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateAppFromCommand(cmd, appName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDescriptionForMimeType(const nsACString & mimeType, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDescriptionForMimeType(mimeType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ShowURI(nsIURI *uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowURI(uri); } \
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
NS_IMETHODIMP nsGIOService::GetMimeTypeFromExtension(const nsACString & extension, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIGIOMimeApp getAppForMimeType (in AUTF8String mimeType); */
NS_IMETHODIMP nsGIOService::GetAppForMimeType(const nsACString & mimeType, nsIGIOMimeApp **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIGIOMimeApp createAppFromCommand (in AUTF8String cmd, in AUTF8String appName); */
NS_IMETHODIMP nsGIOService::CreateAppFromCommand(const nsACString & cmd, const nsACString & appName, nsIGIOMimeApp **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getDescriptionForMimeType (in AUTF8String mimeType); */
NS_IMETHODIMP nsGIOService::GetDescriptionForMimeType(const nsACString & mimeType, nsACString & _retval NS_OUTPARAM)
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

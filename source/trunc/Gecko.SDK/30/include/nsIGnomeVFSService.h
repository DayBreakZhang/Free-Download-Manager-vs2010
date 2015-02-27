/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIGnomeVFSService.idl
 */

#ifndef __gen_nsIGnomeVFSService_h__
#define __gen_nsIGnomeVFSService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIUTF8StringEnumerator; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIGnomeVFSMimeApp */
#define NS_IGNOMEVFSMIMEAPP_IID_STR "66009894-9877-405b-9321-bf30420e34e6"

#define NS_IGNOMEVFSMIMEAPP_IID \
  {0x66009894, 0x9877, 0x405b, \
    { 0x93, 0x21, 0xbf, 0x30, 0x42, 0x0e, 0x34, 0xe6 }}

class NS_NO_VTABLE nsIGnomeVFSMimeApp : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGNOMEVFSMIMEAPP_IID)

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

  /* readonly attribute boolean canOpenMultipleFiles; */
  NS_IMETHOD GetCanOpenMultipleFiles(bool *aCanOpenMultipleFiles) = 0;

  /* readonly attribute long expectsURIs; */
  NS_IMETHOD GetExpectsURIs(int32_t *aExpectsURIs) = 0;

  /* readonly attribute nsIUTF8StringEnumerator supportedURISchemes; */
  NS_IMETHOD GetSupportedURISchemes(nsIUTF8StringEnumerator * *aSupportedURISchemes) = 0;

  /* readonly attribute boolean requiresTerminal; */
  NS_IMETHOD GetRequiresTerminal(bool *aRequiresTerminal) = 0;

  /* void launch (in AUTF8String uri); */
  NS_IMETHOD Launch(const nsACString & uri) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGnomeVFSMimeApp, NS_IGNOMEVFSMIMEAPP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGNOMEVFSMIMEAPP \
  NS_IMETHOD GetId(nsACString & aId); \
  NS_IMETHOD GetName(nsACString & aName); \
  NS_IMETHOD GetCommand(nsACString & aCommand); \
  NS_IMETHOD GetCanOpenMultipleFiles(bool *aCanOpenMultipleFiles); \
  NS_IMETHOD GetExpectsURIs(int32_t *aExpectsURIs); \
  NS_IMETHOD GetSupportedURISchemes(nsIUTF8StringEnumerator * *aSupportedURISchemes); \
  NS_IMETHOD GetRequiresTerminal(bool *aRequiresTerminal); \
  NS_IMETHOD Launch(const nsACString & uri); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGNOMEVFSMIMEAPP(_to) \
  NS_IMETHOD GetId(nsACString & aId) { return _to GetId(aId); } \
  NS_IMETHOD GetName(nsACString & aName) { return _to GetName(aName); } \
  NS_IMETHOD GetCommand(nsACString & aCommand) { return _to GetCommand(aCommand); } \
  NS_IMETHOD GetCanOpenMultipleFiles(bool *aCanOpenMultipleFiles) { return _to GetCanOpenMultipleFiles(aCanOpenMultipleFiles); } \
  NS_IMETHOD GetExpectsURIs(int32_t *aExpectsURIs) { return _to GetExpectsURIs(aExpectsURIs); } \
  NS_IMETHOD GetSupportedURISchemes(nsIUTF8StringEnumerator * *aSupportedURISchemes) { return _to GetSupportedURISchemes(aSupportedURISchemes); } \
  NS_IMETHOD GetRequiresTerminal(bool *aRequiresTerminal) { return _to GetRequiresTerminal(aRequiresTerminal); } \
  NS_IMETHOD Launch(const nsACString & uri) { return _to Launch(uri); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGNOMEVFSMIMEAPP(_to) \
  NS_IMETHOD GetId(nsACString & aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_IMETHOD GetName(nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetCommand(nsACString & aCommand) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCommand(aCommand); } \
  NS_IMETHOD GetCanOpenMultipleFiles(bool *aCanOpenMultipleFiles) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanOpenMultipleFiles(aCanOpenMultipleFiles); } \
  NS_IMETHOD GetExpectsURIs(int32_t *aExpectsURIs) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExpectsURIs(aExpectsURIs); } \
  NS_IMETHOD GetSupportedURISchemes(nsIUTF8StringEnumerator * *aSupportedURISchemes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSupportedURISchemes(aSupportedURISchemes); } \
  NS_IMETHOD GetRequiresTerminal(bool *aRequiresTerminal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequiresTerminal(aRequiresTerminal); } \
  NS_IMETHOD Launch(const nsACString & uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->Launch(uri); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGnomeVFSMimeApp : public nsIGnomeVFSMimeApp
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGNOMEVFSMIMEAPP

  nsGnomeVFSMimeApp();

private:
  ~nsGnomeVFSMimeApp();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsGnomeVFSMimeApp, nsIGnomeVFSMimeApp)

nsGnomeVFSMimeApp::nsGnomeVFSMimeApp()
{
  /* member initializers and constructor code */
}

nsGnomeVFSMimeApp::~nsGnomeVFSMimeApp()
{
  /* destructor code */
}

/* readonly attribute AUTF8String id; */
NS_IMETHODIMP nsGnomeVFSMimeApp::GetId(nsACString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String name; */
NS_IMETHODIMP nsGnomeVFSMimeApp::GetName(nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String command; */
NS_IMETHODIMP nsGnomeVFSMimeApp::GetCommand(nsACString & aCommand)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean canOpenMultipleFiles; */
NS_IMETHODIMP nsGnomeVFSMimeApp::GetCanOpenMultipleFiles(bool *aCanOpenMultipleFiles)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long expectsURIs; */
NS_IMETHODIMP nsGnomeVFSMimeApp::GetExpectsURIs(int32_t *aExpectsURIs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIUTF8StringEnumerator supportedURISchemes; */
NS_IMETHODIMP nsGnomeVFSMimeApp::GetSupportedURISchemes(nsIUTF8StringEnumerator * *aSupportedURISchemes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean requiresTerminal; */
NS_IMETHODIMP nsGnomeVFSMimeApp::GetRequiresTerminal(bool *aRequiresTerminal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void launch (in AUTF8String uri); */
NS_IMETHODIMP nsGnomeVFSMimeApp::Launch(const nsACString & uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIGnomeVFSService */
#define NS_IGNOMEVFSSERVICE_IID_STR "d1ac73a6-2ceb-4164-8142-215afe7fe8a6"

#define NS_IGNOMEVFSSERVICE_IID \
  {0xd1ac73a6, 0x2ceb, 0x4164, \
    { 0x81, 0x42, 0x21, 0x5a, 0xfe, 0x7f, 0xe8, 0xa6 }}

class NS_NO_VTABLE nsIGnomeVFSService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGNOMEVFSSERVICE_IID)

  /* AUTF8String getMimeTypeFromExtension (in AUTF8String extension); */
  NS_IMETHOD GetMimeTypeFromExtension(const nsACString & extension, nsACString & _retval) = 0;

  /* nsIGnomeVFSMimeApp getAppForMimeType (in AUTF8String mimeType); */
  NS_IMETHOD GetAppForMimeType(const nsACString & mimeType, nsIGnomeVFSMimeApp * *_retval) = 0;

  /* AUTF8String getDescriptionForMimeType (in AUTF8String mimeType); */
  NS_IMETHOD GetDescriptionForMimeType(const nsACString & mimeType, nsACString & _retval) = 0;

  /* void showURI (in nsIURI uri); */
  NS_IMETHOD ShowURI(nsIURI *uri) = 0;

  /* [noscript] void showURIForInput (in ACString uri); */
  NS_IMETHOD ShowURIForInput(const nsACString & uri) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGnomeVFSService, NS_IGNOMEVFSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGNOMEVFSSERVICE \
  NS_IMETHOD GetMimeTypeFromExtension(const nsACString & extension, nsACString & _retval); \
  NS_IMETHOD GetAppForMimeType(const nsACString & mimeType, nsIGnomeVFSMimeApp * *_retval); \
  NS_IMETHOD GetDescriptionForMimeType(const nsACString & mimeType, nsACString & _retval); \
  NS_IMETHOD ShowURI(nsIURI *uri); \
  NS_IMETHOD ShowURIForInput(const nsACString & uri); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGNOMEVFSSERVICE(_to) \
  NS_IMETHOD GetMimeTypeFromExtension(const nsACString & extension, nsACString & _retval) { return _to GetMimeTypeFromExtension(extension, _retval); } \
  NS_IMETHOD GetAppForMimeType(const nsACString & mimeType, nsIGnomeVFSMimeApp * *_retval) { return _to GetAppForMimeType(mimeType, _retval); } \
  NS_IMETHOD GetDescriptionForMimeType(const nsACString & mimeType, nsACString & _retval) { return _to GetDescriptionForMimeType(mimeType, _retval); } \
  NS_IMETHOD ShowURI(nsIURI *uri) { return _to ShowURI(uri); } \
  NS_IMETHOD ShowURIForInput(const nsACString & uri) { return _to ShowURIForInput(uri); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGNOMEVFSSERVICE(_to) \
  NS_IMETHOD GetMimeTypeFromExtension(const nsACString & extension, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMimeTypeFromExtension(extension, _retval); } \
  NS_IMETHOD GetAppForMimeType(const nsACString & mimeType, nsIGnomeVFSMimeApp * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppForMimeType(mimeType, _retval); } \
  NS_IMETHOD GetDescriptionForMimeType(const nsACString & mimeType, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDescriptionForMimeType(mimeType, _retval); } \
  NS_IMETHOD ShowURI(nsIURI *uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowURI(uri); } \
  NS_IMETHOD ShowURIForInput(const nsACString & uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowURIForInput(uri); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGnomeVFSService : public nsIGnomeVFSService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGNOMEVFSSERVICE

  nsGnomeVFSService();

private:
  ~nsGnomeVFSService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsGnomeVFSService, nsIGnomeVFSService)

nsGnomeVFSService::nsGnomeVFSService()
{
  /* member initializers and constructor code */
}

nsGnomeVFSService::~nsGnomeVFSService()
{
  /* destructor code */
}

/* AUTF8String getMimeTypeFromExtension (in AUTF8String extension); */
NS_IMETHODIMP nsGnomeVFSService::GetMimeTypeFromExtension(const nsACString & extension, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIGnomeVFSMimeApp getAppForMimeType (in AUTF8String mimeType); */
NS_IMETHODIMP nsGnomeVFSService::GetAppForMimeType(const nsACString & mimeType, nsIGnomeVFSMimeApp * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getDescriptionForMimeType (in AUTF8String mimeType); */
NS_IMETHODIMP nsGnomeVFSService::GetDescriptionForMimeType(const nsACString & mimeType, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showURI (in nsIURI uri); */
NS_IMETHODIMP nsGnomeVFSService::ShowURI(nsIURI *uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void showURIForInput (in ACString uri); */
NS_IMETHODIMP nsGnomeVFSService::ShowURIForInput(const nsACString & uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_GNOMEVFSSERVICE_CONTRACTID "@mozilla.org/gnome-vfs-service;1"

#endif /* __gen_nsIGnomeVFSService_h__ */

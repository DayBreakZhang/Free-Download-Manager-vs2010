/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDocumentLoaderFactory.idl
 */

#ifndef __gen_nsIDocumentLoaderFactory_h__
#define __gen_nsIDocumentLoaderFactory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIChannel; /* forward declaration */

class nsIContentViewer; /* forward declaration */

class nsIStreamListener; /* forward declaration */

class nsIDocShell; /* forward declaration */

class nsIDocument; /* forward declaration */

class nsILoadGroup; /* forward declaration */

class nsIPrincipal; /* forward declaration */


/* starting interface:    nsIDocumentLoaderFactory */
#define NS_IDOCUMENTLOADERFACTORY_IID_STR "70905274-8494-4e39-b011-d559adde3733"

#define NS_IDOCUMENTLOADERFACTORY_IID \
  {0x70905274, 0x8494, 0x4e39, \
    { 0xb0, 0x11, 0xd5, 0x59, 0xad, 0xde, 0x37, 0x33 }}

class NS_NO_VTABLE nsIDocumentLoaderFactory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCUMENTLOADERFACTORY_IID)

  /* nsIContentViewer createInstance (in string aCommand, in nsIChannel aChannel, in nsILoadGroup aLoadGroup, in string aContentType, in nsIDocShell aContainer, in nsISupports aExtraInfo, out nsIStreamListener aDocListenerResult); */
  NS_IMETHOD CreateInstance(const char * aCommand, nsIChannel *aChannel, nsILoadGroup *aLoadGroup, const char * aContentType, nsIDocShell *aContainer, nsISupports *aExtraInfo, nsIStreamListener * *aDocListenerResult, nsIContentViewer * *_retval) = 0;

  /* nsIContentViewer createInstanceForDocument (in nsISupports aContainer, in nsIDocument aDocument, in string aCommand); */
  NS_IMETHOD CreateInstanceForDocument(nsISupports *aContainer, nsIDocument *aDocument, const char * aCommand, nsIContentViewer * *_retval) = 0;

  /* nsIDocument createBlankDocument (in nsILoadGroup aLoadGroup, in nsIPrincipal aPrincipal); */
  NS_IMETHOD CreateBlankDocument(nsILoadGroup *aLoadGroup, nsIPrincipal *aPrincipal, nsIDocument * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocumentLoaderFactory, NS_IDOCUMENTLOADERFACTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCUMENTLOADERFACTORY \
  NS_IMETHOD CreateInstance(const char * aCommand, nsIChannel *aChannel, nsILoadGroup *aLoadGroup, const char * aContentType, nsIDocShell *aContainer, nsISupports *aExtraInfo, nsIStreamListener * *aDocListenerResult, nsIContentViewer * *_retval); \
  NS_IMETHOD CreateInstanceForDocument(nsISupports *aContainer, nsIDocument *aDocument, const char * aCommand, nsIContentViewer * *_retval); \
  NS_IMETHOD CreateBlankDocument(nsILoadGroup *aLoadGroup, nsIPrincipal *aPrincipal, nsIDocument * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCUMENTLOADERFACTORY(_to) \
  NS_IMETHOD CreateInstance(const char * aCommand, nsIChannel *aChannel, nsILoadGroup *aLoadGroup, const char * aContentType, nsIDocShell *aContainer, nsISupports *aExtraInfo, nsIStreamListener * *aDocListenerResult, nsIContentViewer * *_retval) { return _to CreateInstance(aCommand, aChannel, aLoadGroup, aContentType, aContainer, aExtraInfo, aDocListenerResult, _retval); } \
  NS_IMETHOD CreateInstanceForDocument(nsISupports *aContainer, nsIDocument *aDocument, const char * aCommand, nsIContentViewer * *_retval) { return _to CreateInstanceForDocument(aContainer, aDocument, aCommand, _retval); } \
  NS_IMETHOD CreateBlankDocument(nsILoadGroup *aLoadGroup, nsIPrincipal *aPrincipal, nsIDocument * *_retval) { return _to CreateBlankDocument(aLoadGroup, aPrincipal, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCUMENTLOADERFACTORY(_to) \
  NS_IMETHOD CreateInstance(const char * aCommand, nsIChannel *aChannel, nsILoadGroup *aLoadGroup, const char * aContentType, nsIDocShell *aContainer, nsISupports *aExtraInfo, nsIStreamListener * *aDocListenerResult, nsIContentViewer * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateInstance(aCommand, aChannel, aLoadGroup, aContentType, aContainer, aExtraInfo, aDocListenerResult, _retval); } \
  NS_IMETHOD CreateInstanceForDocument(nsISupports *aContainer, nsIDocument *aDocument, const char * aCommand, nsIContentViewer * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateInstanceForDocument(aContainer, aDocument, aCommand, _retval); } \
  NS_IMETHOD CreateBlankDocument(nsILoadGroup *aLoadGroup, nsIPrincipal *aPrincipal, nsIDocument * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateBlankDocument(aLoadGroup, aPrincipal, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocumentLoaderFactory : public nsIDocumentLoaderFactory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCUMENTLOADERFACTORY

  nsDocumentLoaderFactory();

private:
  ~nsDocumentLoaderFactory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocumentLoaderFactory, nsIDocumentLoaderFactory)

nsDocumentLoaderFactory::nsDocumentLoaderFactory()
{
  /* member initializers and constructor code */
}

nsDocumentLoaderFactory::~nsDocumentLoaderFactory()
{
  /* destructor code */
}

/* nsIContentViewer createInstance (in string aCommand, in nsIChannel aChannel, in nsILoadGroup aLoadGroup, in string aContentType, in nsIDocShell aContainer, in nsISupports aExtraInfo, out nsIStreamListener aDocListenerResult); */
NS_IMETHODIMP nsDocumentLoaderFactory::CreateInstance(const char * aCommand, nsIChannel *aChannel, nsILoadGroup *aLoadGroup, const char * aContentType, nsIDocShell *aContainer, nsISupports *aExtraInfo, nsIStreamListener * *aDocListenerResult, nsIContentViewer * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIContentViewer createInstanceForDocument (in nsISupports aContainer, in nsIDocument aDocument, in string aCommand); */
NS_IMETHODIMP nsDocumentLoaderFactory::CreateInstanceForDocument(nsISupports *aContainer, nsIDocument *aDocument, const char * aCommand, nsIContentViewer * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDocument createBlankDocument (in nsILoadGroup aLoadGroup, in nsIPrincipal aPrincipal); */
NS_IMETHODIMP nsDocumentLoaderFactory::CreateBlankDocument(nsILoadGroup *aLoadGroup, nsIPrincipal *aPrincipal, nsIDocument * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDocumentLoaderFactory_h__ */

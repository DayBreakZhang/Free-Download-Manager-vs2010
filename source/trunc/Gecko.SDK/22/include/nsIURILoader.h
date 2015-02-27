/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/uriloader/base/nsIURILoader.idl
 */

#ifndef __gen_nsIURILoader_h__
#define __gen_nsIURILoader_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURIContentListener; /* forward declaration */

class nsIURI; /* forward declaration */

class nsILoadGroup; /* forward declaration */

class nsIProgressEventSink; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsIRequest; /* forward declaration */

class nsIStreamListener; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIInterfaceRequestor; /* forward declaration */


/* starting interface:    nsIURILoader */
#define NS_IURILOADER_IID_STR "2f7e8051-f1c9-4bcc-8584-9cfd5849e343"

#define NS_IURILOADER_IID \
  {0x2f7e8051, 0xf1c9, 0x4bcc, \
    { 0x85, 0x84, 0x9c, 0xfd, 0x58, 0x49, 0xe3, 0x43 }}

class NS_NO_VTABLE nsIURILoader : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURILOADER_IID)

  enum {
    IS_CONTENT_PREFERRED = 1U,
    DONT_RETARGET = 2U
  };

  /* void registerContentListener (in nsIURIContentListener aContentListener); */
  NS_IMETHOD RegisterContentListener(nsIURIContentListener *aContentListener) = 0;

  /* void unRegisterContentListener (in nsIURIContentListener aContentListener); */
  NS_IMETHOD UnRegisterContentListener(nsIURIContentListener *aContentListener) = 0;

  /* void openURI (in nsIChannel aChannel, in boolean aIsContentPreferred, in nsIInterfaceRequestor aWindowContext); */
  NS_IMETHOD OpenURI(nsIChannel *aChannel, bool aIsContentPreferred, nsIInterfaceRequestor *aWindowContext) = 0;

  /* nsIStreamListener openChannel (in nsIChannel aChannel, in unsigned long aFlags, in nsIInterfaceRequestor aWindowContext); */
  NS_IMETHOD OpenChannel(nsIChannel *aChannel, uint32_t aFlags, nsIInterfaceRequestor *aWindowContext, nsIStreamListener * *_retval) = 0;

  /* void stop (in nsISupports aLoadCookie); */
  NS_IMETHOD Stop(nsISupports *aLoadCookie) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIURILoader, NS_IURILOADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURILOADER \
  NS_IMETHOD RegisterContentListener(nsIURIContentListener *aContentListener); \
  NS_IMETHOD UnRegisterContentListener(nsIURIContentListener *aContentListener); \
  NS_IMETHOD OpenURI(nsIChannel *aChannel, bool aIsContentPreferred, nsIInterfaceRequestor *aWindowContext); \
  NS_IMETHOD OpenChannel(nsIChannel *aChannel, uint32_t aFlags, nsIInterfaceRequestor *aWindowContext, nsIStreamListener * *_retval); \
  NS_IMETHOD Stop(nsISupports *aLoadCookie); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURILOADER(_to) \
  NS_IMETHOD RegisterContentListener(nsIURIContentListener *aContentListener) { return _to RegisterContentListener(aContentListener); } \
  NS_IMETHOD UnRegisterContentListener(nsIURIContentListener *aContentListener) { return _to UnRegisterContentListener(aContentListener); } \
  NS_IMETHOD OpenURI(nsIChannel *aChannel, bool aIsContentPreferred, nsIInterfaceRequestor *aWindowContext) { return _to OpenURI(aChannel, aIsContentPreferred, aWindowContext); } \
  NS_IMETHOD OpenChannel(nsIChannel *aChannel, uint32_t aFlags, nsIInterfaceRequestor *aWindowContext, nsIStreamListener * *_retval) { return _to OpenChannel(aChannel, aFlags, aWindowContext, _retval); } \
  NS_IMETHOD Stop(nsISupports *aLoadCookie) { return _to Stop(aLoadCookie); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURILOADER(_to) \
  NS_IMETHOD RegisterContentListener(nsIURIContentListener *aContentListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterContentListener(aContentListener); } \
  NS_IMETHOD UnRegisterContentListener(nsIURIContentListener *aContentListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnRegisterContentListener(aContentListener); } \
  NS_IMETHOD OpenURI(nsIChannel *aChannel, bool aIsContentPreferred, nsIInterfaceRequestor *aWindowContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenURI(aChannel, aIsContentPreferred, aWindowContext); } \
  NS_IMETHOD OpenChannel(nsIChannel *aChannel, uint32_t aFlags, nsIInterfaceRequestor *aWindowContext, nsIStreamListener * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenChannel(aChannel, aFlags, aWindowContext, _retval); } \
  NS_IMETHOD Stop(nsISupports *aLoadCookie) { return !_to ? NS_ERROR_NULL_POINTER : _to->Stop(aLoadCookie); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsURILoader : public nsIURILoader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURILOADER

  nsURILoader();

private:
  ~nsURILoader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsURILoader, nsIURILoader)

nsURILoader::nsURILoader()
{
  /* member initializers and constructor code */
}

nsURILoader::~nsURILoader()
{
  /* destructor code */
}

/* void registerContentListener (in nsIURIContentListener aContentListener); */
NS_IMETHODIMP nsURILoader::RegisterContentListener(nsIURIContentListener *aContentListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unRegisterContentListener (in nsIURIContentListener aContentListener); */
NS_IMETHODIMP nsURILoader::UnRegisterContentListener(nsIURIContentListener *aContentListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void openURI (in nsIChannel aChannel, in boolean aIsContentPreferred, in nsIInterfaceRequestor aWindowContext); */
NS_IMETHODIMP nsURILoader::OpenURI(nsIChannel *aChannel, bool aIsContentPreferred, nsIInterfaceRequestor *aWindowContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIStreamListener openChannel (in nsIChannel aChannel, in unsigned long aFlags, in nsIInterfaceRequestor aWindowContext); */
NS_IMETHODIMP nsURILoader::OpenChannel(nsIChannel *aChannel, uint32_t aFlags, nsIInterfaceRequestor *aWindowContext, nsIStreamListener * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stop (in nsISupports aLoadCookie); */
NS_IMETHODIMP nsURILoader::Stop(nsISupports *aLoadCookie)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIURILoader_h__ */

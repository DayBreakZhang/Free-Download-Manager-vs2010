/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/image/public/imgILoader.idl
 */

#ifndef __gen_imgILoader_h__
#define __gen_imgILoader_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIRequest_h__
#include "nsIRequest.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class imgINotificationObserver; /* forward declaration */

class imgIRequest; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsILoadGroup; /* forward declaration */

class nsIPrincipal; /* forward declaration */

class nsIStreamListener; /* forward declaration */

class nsIURI; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */

class nsIChannelPolicy; /* forward declaration */


/* starting interface:    imgILoader */
#define IMGILOADER_IID_STR "c8126129-8dac-43cd-b1ba-3896fba2dd01"

#define IMGILOADER_IID \
  {0xc8126129, 0x8dac, 0x43cd, \
    { 0xb1, 0xba, 0x38, 0x96, 0xfb, 0xa2, 0xdd, 0x01 }}

class NS_NO_VTABLE imgILoader : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMGILOADER_IID)

  enum {
    LOAD_CORS_ANONYMOUS = 65536U,
    LOAD_CORS_USE_CREDENTIALS = 131072U
  };

  /* imgIRequest loadImageXPCOM (in nsIURI aURI, in nsIURI aInitialDocumentURL, in nsIURI aReferrerURI, in nsIPrincipal aLoadingPrincipal, in nsILoadGroup aLoadGroup, in imgINotificationObserver aObserver, in nsISupports aCX, in nsLoadFlags aLoadFlags, in nsISupports cacheKey, in nsIChannelPolicy channelPolicy); */
  NS_IMETHOD LoadImageXPCOM(nsIURI *aURI, nsIURI *aInitialDocumentURL, nsIURI *aReferrerURI, nsIPrincipal *aLoadingPrincipal, nsILoadGroup *aLoadGroup, imgINotificationObserver *aObserver, nsISupports *aCX, nsLoadFlags aLoadFlags, nsISupports *cacheKey, nsIChannelPolicy *channelPolicy, imgIRequest * *_retval) = 0;

  /* imgIRequest loadImageWithChannelXPCOM (in nsIChannel aChannel, in imgINotificationObserver aObserver, in nsISupports cx, out nsIStreamListener aListener); */
  NS_IMETHOD LoadImageWithChannelXPCOM(nsIChannel *aChannel, imgINotificationObserver *aObserver, nsISupports *cx, nsIStreamListener * *aListener, imgIRequest * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(imgILoader, IMGILOADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMGILOADER \
  NS_IMETHOD LoadImageXPCOM(nsIURI *aURI, nsIURI *aInitialDocumentURL, nsIURI *aReferrerURI, nsIPrincipal *aLoadingPrincipal, nsILoadGroup *aLoadGroup, imgINotificationObserver *aObserver, nsISupports *aCX, nsLoadFlags aLoadFlags, nsISupports *cacheKey, nsIChannelPolicy *channelPolicy, imgIRequest * *_retval); \
  NS_IMETHOD LoadImageWithChannelXPCOM(nsIChannel *aChannel, imgINotificationObserver *aObserver, nsISupports *cx, nsIStreamListener * *aListener, imgIRequest * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMGILOADER(_to) \
  NS_IMETHOD LoadImageXPCOM(nsIURI *aURI, nsIURI *aInitialDocumentURL, nsIURI *aReferrerURI, nsIPrincipal *aLoadingPrincipal, nsILoadGroup *aLoadGroup, imgINotificationObserver *aObserver, nsISupports *aCX, nsLoadFlags aLoadFlags, nsISupports *cacheKey, nsIChannelPolicy *channelPolicy, imgIRequest * *_retval) { return _to LoadImageXPCOM(aURI, aInitialDocumentURL, aReferrerURI, aLoadingPrincipal, aLoadGroup, aObserver, aCX, aLoadFlags, cacheKey, channelPolicy, _retval); } \
  NS_IMETHOD LoadImageWithChannelXPCOM(nsIChannel *aChannel, imgINotificationObserver *aObserver, nsISupports *cx, nsIStreamListener * *aListener, imgIRequest * *_retval) { return _to LoadImageWithChannelXPCOM(aChannel, aObserver, cx, aListener, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMGILOADER(_to) \
  NS_IMETHOD LoadImageXPCOM(nsIURI *aURI, nsIURI *aInitialDocumentURL, nsIURI *aReferrerURI, nsIPrincipal *aLoadingPrincipal, nsILoadGroup *aLoadGroup, imgINotificationObserver *aObserver, nsISupports *aCX, nsLoadFlags aLoadFlags, nsISupports *cacheKey, nsIChannelPolicy *channelPolicy, imgIRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadImageXPCOM(aURI, aInitialDocumentURL, aReferrerURI, aLoadingPrincipal, aLoadGroup, aObserver, aCX, aLoadFlags, cacheKey, channelPolicy, _retval); } \
  NS_IMETHOD LoadImageWithChannelXPCOM(nsIChannel *aChannel, imgINotificationObserver *aObserver, nsISupports *cx, nsIStreamListener * *aListener, imgIRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadImageWithChannelXPCOM(aChannel, aObserver, cx, aListener, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public imgILoader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMGILOADER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, imgILoader)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* imgIRequest loadImageXPCOM (in nsIURI aURI, in nsIURI aInitialDocumentURL, in nsIURI aReferrerURI, in nsIPrincipal aLoadingPrincipal, in nsILoadGroup aLoadGroup, in imgINotificationObserver aObserver, in nsISupports aCX, in nsLoadFlags aLoadFlags, in nsISupports cacheKey, in nsIChannelPolicy channelPolicy); */
NS_IMETHODIMP _MYCLASS_::LoadImageXPCOM(nsIURI *aURI, nsIURI *aInitialDocumentURL, nsIURI *aReferrerURI, nsIPrincipal *aLoadingPrincipal, nsILoadGroup *aLoadGroup, imgINotificationObserver *aObserver, nsISupports *aCX, nsLoadFlags aLoadFlags, nsISupports *cacheKey, nsIChannelPolicy *channelPolicy, imgIRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* imgIRequest loadImageWithChannelXPCOM (in nsIChannel aChannel, in imgINotificationObserver aObserver, in nsISupports cx, out nsIStreamListener aListener); */
NS_IMETHODIMP _MYCLASS_::LoadImageWithChannelXPCOM(nsIChannel *aChannel, imgINotificationObserver *aObserver, nsISupports *cx, nsIStreamListener * *aListener, imgIRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_imgILoader_h__ */

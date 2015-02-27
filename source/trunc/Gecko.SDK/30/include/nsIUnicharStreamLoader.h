/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIUnicharStreamLoader.idl
 */

#ifndef __gen_nsIUnicharStreamLoader_h__
#define __gen_nsIUnicharStreamLoader_h__


#ifndef __gen_nsIStreamListener_h__
#include "nsIStreamListener.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIUnicharInputStream; /* forward declaration */

class nsIUnicharStreamLoader; /* forward declaration */

class nsIChannel; /* forward declaration */


/* starting interface:    nsIUnicharStreamLoaderObserver */
#define NS_IUNICHARSTREAMLOADEROBSERVER_IID_STR "c2982b39-2e48-429e-92b7-99348a1633c5"

#define NS_IUNICHARSTREAMLOADEROBSERVER_IID \
  {0xc2982b39, 0x2e48, 0x429e, \
    { 0x92, 0xb7, 0x99, 0x34, 0x8a, 0x16, 0x33, 0xc5 }}

class NS_NO_VTABLE nsIUnicharStreamLoaderObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUNICHARSTREAMLOADEROBSERVER_IID)

  /* ACString onDetermineCharset (in nsIUnicharStreamLoader aLoader, in nsISupports aContext, in ACString aSegment); */
  NS_IMETHOD OnDetermineCharset(nsIUnicharStreamLoader *aLoader, nsISupports *aContext, const nsACString & aSegment, nsACString & _retval) = 0;

  /* void onStreamComplete (in nsIUnicharStreamLoader aLoader, in nsISupports aContext, in nsresult aStatus, in AString aBuffer); */
  NS_IMETHOD OnStreamComplete(nsIUnicharStreamLoader *aLoader, nsISupports *aContext, nsresult aStatus, const nsAString & aBuffer) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUnicharStreamLoaderObserver, NS_IUNICHARSTREAMLOADEROBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUNICHARSTREAMLOADEROBSERVER \
  NS_IMETHOD OnDetermineCharset(nsIUnicharStreamLoader *aLoader, nsISupports *aContext, const nsACString & aSegment, nsACString & _retval); \
  NS_IMETHOD OnStreamComplete(nsIUnicharStreamLoader *aLoader, nsISupports *aContext, nsresult aStatus, const nsAString & aBuffer); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUNICHARSTREAMLOADEROBSERVER(_to) \
  NS_IMETHOD OnDetermineCharset(nsIUnicharStreamLoader *aLoader, nsISupports *aContext, const nsACString & aSegment, nsACString & _retval) { return _to OnDetermineCharset(aLoader, aContext, aSegment, _retval); } \
  NS_IMETHOD OnStreamComplete(nsIUnicharStreamLoader *aLoader, nsISupports *aContext, nsresult aStatus, const nsAString & aBuffer) { return _to OnStreamComplete(aLoader, aContext, aStatus, aBuffer); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUNICHARSTREAMLOADEROBSERVER(_to) \
  NS_IMETHOD OnDetermineCharset(nsIUnicharStreamLoader *aLoader, nsISupports *aContext, const nsACString & aSegment, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDetermineCharset(aLoader, aContext, aSegment, _retval); } \
  NS_IMETHOD OnStreamComplete(nsIUnicharStreamLoader *aLoader, nsISupports *aContext, nsresult aStatus, const nsAString & aBuffer) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStreamComplete(aLoader, aContext, aStatus, aBuffer); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUnicharStreamLoaderObserver : public nsIUnicharStreamLoaderObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUNICHARSTREAMLOADEROBSERVER

  nsUnicharStreamLoaderObserver();

private:
  ~nsUnicharStreamLoaderObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUnicharStreamLoaderObserver, nsIUnicharStreamLoaderObserver)

nsUnicharStreamLoaderObserver::nsUnicharStreamLoaderObserver()
{
  /* member initializers and constructor code */
}

nsUnicharStreamLoaderObserver::~nsUnicharStreamLoaderObserver()
{
  /* destructor code */
}

/* ACString onDetermineCharset (in nsIUnicharStreamLoader aLoader, in nsISupports aContext, in ACString aSegment); */
NS_IMETHODIMP nsUnicharStreamLoaderObserver::OnDetermineCharset(nsIUnicharStreamLoader *aLoader, nsISupports *aContext, const nsACString & aSegment, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onStreamComplete (in nsIUnicharStreamLoader aLoader, in nsISupports aContext, in nsresult aStatus, in AString aBuffer); */
NS_IMETHODIMP nsUnicharStreamLoaderObserver::OnStreamComplete(nsIUnicharStreamLoader *aLoader, nsISupports *aContext, nsresult aStatus, const nsAString & aBuffer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUnicharStreamLoader */
#define NS_IUNICHARSTREAMLOADER_IID_STR "afb62060-37c7-4713-8a84-4a0c1199ba5c"

#define NS_IUNICHARSTREAMLOADER_IID \
  {0xafb62060, 0x37c7, 0x4713, \
    { 0x8a, 0x84, 0x4a, 0x0c, 0x11, 0x99, 0xba, 0x5c }}

class NS_NO_VTABLE nsIUnicharStreamLoader : public nsIStreamListener {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUNICHARSTREAMLOADER_IID)

  /* void init (in nsIUnicharStreamLoaderObserver aObserver); */
  NS_IMETHOD Init(nsIUnicharStreamLoaderObserver *aObserver) = 0;

  /* readonly attribute nsIChannel channel; */
  NS_IMETHOD GetChannel(nsIChannel * *aChannel) = 0;

  /* readonly attribute ACString charset; */
  NS_IMETHOD GetCharset(nsACString & aCharset) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUnicharStreamLoader, NS_IUNICHARSTREAMLOADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUNICHARSTREAMLOADER \
  NS_IMETHOD Init(nsIUnicharStreamLoaderObserver *aObserver); \
  NS_IMETHOD GetChannel(nsIChannel * *aChannel); \
  NS_IMETHOD GetCharset(nsACString & aCharset); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUNICHARSTREAMLOADER(_to) \
  NS_IMETHOD Init(nsIUnicharStreamLoaderObserver *aObserver) { return _to Init(aObserver); } \
  NS_IMETHOD GetChannel(nsIChannel * *aChannel) { return _to GetChannel(aChannel); } \
  NS_IMETHOD GetCharset(nsACString & aCharset) { return _to GetCharset(aCharset); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUNICHARSTREAMLOADER(_to) \
  NS_IMETHOD Init(nsIUnicharStreamLoaderObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aObserver); } \
  NS_IMETHOD GetChannel(nsIChannel * *aChannel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChannel(aChannel); } \
  NS_IMETHOD GetCharset(nsACString & aCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharset(aCharset); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUnicharStreamLoader : public nsIUnicharStreamLoader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUNICHARSTREAMLOADER

  nsUnicharStreamLoader();

private:
  ~nsUnicharStreamLoader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUnicharStreamLoader, nsIUnicharStreamLoader)

nsUnicharStreamLoader::nsUnicharStreamLoader()
{
  /* member initializers and constructor code */
}

nsUnicharStreamLoader::~nsUnicharStreamLoader()
{
  /* destructor code */
}

/* void init (in nsIUnicharStreamLoaderObserver aObserver); */
NS_IMETHODIMP nsUnicharStreamLoader::Init(nsIUnicharStreamLoaderObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIChannel channel; */
NS_IMETHODIMP nsUnicharStreamLoader::GetChannel(nsIChannel * *aChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString charset; */
NS_IMETHODIMP nsUnicharStreamLoader::GetCharset(nsACString & aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUnicharStreamLoader_h__ */

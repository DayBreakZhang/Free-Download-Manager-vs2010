/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/content/base/public/nsIImageLoadingContent.idl
 */

#ifndef __gen_nsIImageLoadingContent_h__
#define __gen_nsIImageLoadingContent_h__


#ifndef __gen_imgINotificationObserver_h__
#include "imgINotificationObserver.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class imgIRequest; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsIStreamListener; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIDocument; /* forward declaration */

class nsIFrame; /* forward declaration */


/* starting interface:    nsIImageLoadingContent */
#define NS_IIMAGELOADINGCONTENT_IID_STR "e3968acd-b796-4ca3-aec0-e7f0880f2219"

#define NS_IIMAGELOADINGCONTENT_IID \
  {0xe3968acd, 0xb796, 0x4ca3, \
    { 0xae, 0xc0, 0xe7, 0xf0, 0x88, 0x0f, 0x22, 0x19 }}

class NS_NO_VTABLE nsIImageLoadingContent : public imgINotificationObserver {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIMAGELOADINGCONTENT_IID)

  enum {
    UNKNOWN_REQUEST = -1,
    CURRENT_REQUEST = 0,
    PENDING_REQUEST = 1
  };

  /* attribute boolean loadingEnabled; */
  NS_IMETHOD GetLoadingEnabled(bool *aLoadingEnabled) = 0;
  NS_IMETHOD SetLoadingEnabled(bool aLoadingEnabled) = 0;

  /* readonly attribute short imageBlockingStatus; */
  NS_IMETHOD GetImageBlockingStatus(int16_t *aImageBlockingStatus) = 0;

  /* void addObserver (in imgINotificationObserver aObserver); */
  NS_IMETHOD AddObserver(imgINotificationObserver *aObserver) = 0;

  /* void removeObserver (in imgINotificationObserver aObserver); */
  NS_IMETHOD RemoveObserver(imgINotificationObserver *aObserver) = 0;

  /* imgIRequest getRequest (in long aRequestType); */
  NS_IMETHOD GetRequest(int32_t aRequestType, imgIRequest * *_retval) = 0;

  /* [notxpcom] void frameCreated (in nsIFrame aFrame); */
  NS_IMETHOD_(void) FrameCreated(nsIFrame *aFrame) = 0;

  /* [notxpcom] void frameDestroyed (in nsIFrame aFrame); */
  NS_IMETHOD_(void) FrameDestroyed(nsIFrame *aFrame) = 0;

  /* long getRequestType (in imgIRequest aRequest); */
  NS_IMETHOD GetRequestType(imgIRequest *aRequest, int32_t *_retval) = 0;

  /* readonly attribute nsIURI currentURI; */
  NS_IMETHOD GetCurrentURI(nsIURI * *aCurrentURI) = 0;

  /* nsIStreamListener loadImageWithChannel (in nsIChannel aChannel); */
  NS_IMETHOD LoadImageWithChannel(nsIChannel *aChannel, nsIStreamListener * *_retval) = 0;

  /* void forceReload (); */
  NS_IMETHOD ForceReload(void) = 0;

  /* void forceImageState (in boolean aForce, in unsigned long long aState); */
  NS_IMETHOD ForceImageState(bool aForce, uint64_t aState) = 0;

  /* [noscript,notxpcom] void IncrementVisibleCount (); */
  NS_IMETHOD_(void) IncrementVisibleCount(void) = 0;

  /* [noscript,notxpcom] void DecrementVisibleCount (); */
  NS_IMETHOD_(void) DecrementVisibleCount(void) = 0;

  /* [noscript,notxpcom] uint32_t GetVisibleCount (); */
  NS_IMETHOD_(uint32_t) GetVisibleCount(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIImageLoadingContent, NS_IIMAGELOADINGCONTENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIMAGELOADINGCONTENT \
  NS_IMETHOD GetLoadingEnabled(bool *aLoadingEnabled); \
  NS_IMETHOD SetLoadingEnabled(bool aLoadingEnabled); \
  NS_IMETHOD GetImageBlockingStatus(int16_t *aImageBlockingStatus); \
  NS_IMETHOD AddObserver(imgINotificationObserver *aObserver); \
  NS_IMETHOD RemoveObserver(imgINotificationObserver *aObserver); \
  NS_IMETHOD GetRequest(int32_t aRequestType, imgIRequest * *_retval); \
  NS_IMETHOD_(void) FrameCreated(nsIFrame *aFrame); \
  NS_IMETHOD_(void) FrameDestroyed(nsIFrame *aFrame); \
  NS_IMETHOD GetRequestType(imgIRequest *aRequest, int32_t *_retval); \
  NS_IMETHOD GetCurrentURI(nsIURI * *aCurrentURI); \
  NS_IMETHOD LoadImageWithChannel(nsIChannel *aChannel, nsIStreamListener * *_retval); \
  NS_IMETHOD ForceReload(void); \
  NS_IMETHOD ForceImageState(bool aForce, uint64_t aState); \
  NS_IMETHOD_(void) IncrementVisibleCount(void); \
  NS_IMETHOD_(void) DecrementVisibleCount(void); \
  NS_IMETHOD_(uint32_t) GetVisibleCount(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIMAGELOADINGCONTENT(_to) \
  NS_IMETHOD GetLoadingEnabled(bool *aLoadingEnabled) { return _to GetLoadingEnabled(aLoadingEnabled); } \
  NS_IMETHOD SetLoadingEnabled(bool aLoadingEnabled) { return _to SetLoadingEnabled(aLoadingEnabled); } \
  NS_IMETHOD GetImageBlockingStatus(int16_t *aImageBlockingStatus) { return _to GetImageBlockingStatus(aImageBlockingStatus); } \
  NS_IMETHOD AddObserver(imgINotificationObserver *aObserver) { return _to AddObserver(aObserver); } \
  NS_IMETHOD RemoveObserver(imgINotificationObserver *aObserver) { return _to RemoveObserver(aObserver); } \
  NS_IMETHOD GetRequest(int32_t aRequestType, imgIRequest * *_retval) { return _to GetRequest(aRequestType, _retval); } \
  NS_IMETHOD_(void) FrameCreated(nsIFrame *aFrame) { return _to FrameCreated(aFrame); } \
  NS_IMETHOD_(void) FrameDestroyed(nsIFrame *aFrame) { return _to FrameDestroyed(aFrame); } \
  NS_IMETHOD GetRequestType(imgIRequest *aRequest, int32_t *_retval) { return _to GetRequestType(aRequest, _retval); } \
  NS_IMETHOD GetCurrentURI(nsIURI * *aCurrentURI) { return _to GetCurrentURI(aCurrentURI); } \
  NS_IMETHOD LoadImageWithChannel(nsIChannel *aChannel, nsIStreamListener * *_retval) { return _to LoadImageWithChannel(aChannel, _retval); } \
  NS_IMETHOD ForceReload(void) { return _to ForceReload(); } \
  NS_IMETHOD ForceImageState(bool aForce, uint64_t aState) { return _to ForceImageState(aForce, aState); } \
  NS_IMETHOD_(void) IncrementVisibleCount(void) { return _to IncrementVisibleCount(); } \
  NS_IMETHOD_(void) DecrementVisibleCount(void) { return _to DecrementVisibleCount(); } \
  NS_IMETHOD_(uint32_t) GetVisibleCount(void) { return _to GetVisibleCount(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIMAGELOADINGCONTENT(_to) \
  NS_IMETHOD GetLoadingEnabled(bool *aLoadingEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadingEnabled(aLoadingEnabled); } \
  NS_IMETHOD SetLoadingEnabled(bool aLoadingEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLoadingEnabled(aLoadingEnabled); } \
  NS_IMETHOD GetImageBlockingStatus(int16_t *aImageBlockingStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageBlockingStatus(aImageBlockingStatus); } \
  NS_IMETHOD AddObserver(imgINotificationObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(aObserver); } \
  NS_IMETHOD RemoveObserver(imgINotificationObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(aObserver); } \
  NS_IMETHOD GetRequest(int32_t aRequestType, imgIRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequest(aRequestType, _retval); } \
  NS_IMETHOD_(void) FrameCreated(nsIFrame *aFrame); \
  NS_IMETHOD_(void) FrameDestroyed(nsIFrame *aFrame); \
  NS_IMETHOD GetRequestType(imgIRequest *aRequest, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequestType(aRequest, _retval); } \
  NS_IMETHOD GetCurrentURI(nsIURI * *aCurrentURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentURI(aCurrentURI); } \
  NS_IMETHOD LoadImageWithChannel(nsIChannel *aChannel, nsIStreamListener * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadImageWithChannel(aChannel, _retval); } \
  NS_IMETHOD ForceReload(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceReload(); } \
  NS_IMETHOD ForceImageState(bool aForce, uint64_t aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceImageState(aForce, aState); } \
  NS_IMETHOD_(void) IncrementVisibleCount(void); \
  NS_IMETHOD_(void) DecrementVisibleCount(void); \
  NS_IMETHOD_(uint32_t) GetVisibleCount(void); 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsImageLoadingContent : public nsIImageLoadingContent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIMAGELOADINGCONTENT

  nsImageLoadingContent();

private:
  ~nsImageLoadingContent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsImageLoadingContent, nsIImageLoadingContent)

nsImageLoadingContent::nsImageLoadingContent()
{
  /* member initializers and constructor code */
}

nsImageLoadingContent::~nsImageLoadingContent()
{
  /* destructor code */
}

/* attribute boolean loadingEnabled; */
NS_IMETHODIMP nsImageLoadingContent::GetLoadingEnabled(bool *aLoadingEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsImageLoadingContent::SetLoadingEnabled(bool aLoadingEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute short imageBlockingStatus; */
NS_IMETHODIMP nsImageLoadingContent::GetImageBlockingStatus(int16_t *aImageBlockingStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserver (in imgINotificationObserver aObserver); */
NS_IMETHODIMP nsImageLoadingContent::AddObserver(imgINotificationObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in imgINotificationObserver aObserver); */
NS_IMETHODIMP nsImageLoadingContent::RemoveObserver(imgINotificationObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* imgIRequest getRequest (in long aRequestType); */
NS_IMETHODIMP nsImageLoadingContent::GetRequest(int32_t aRequestType, imgIRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] void frameCreated (in nsIFrame aFrame); */
NS_IMETHODIMP_(void) nsImageLoadingContent::FrameCreated(nsIFrame *aFrame)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] void frameDestroyed (in nsIFrame aFrame); */
NS_IMETHODIMP_(void) nsImageLoadingContent::FrameDestroyed(nsIFrame *aFrame)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getRequestType (in imgIRequest aRequest); */
NS_IMETHODIMP nsImageLoadingContent::GetRequestType(imgIRequest *aRequest, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI currentURI; */
NS_IMETHODIMP nsImageLoadingContent::GetCurrentURI(nsIURI * *aCurrentURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIStreamListener loadImageWithChannel (in nsIChannel aChannel); */
NS_IMETHODIMP nsImageLoadingContent::LoadImageWithChannel(nsIChannel *aChannel, nsIStreamListener * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forceReload (); */
NS_IMETHODIMP nsImageLoadingContent::ForceReload()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forceImageState (in boolean aForce, in unsigned long long aState); */
NS_IMETHODIMP nsImageLoadingContent::ForceImageState(bool aForce, uint64_t aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] void IncrementVisibleCount (); */
NS_IMETHODIMP_(void) nsImageLoadingContent::IncrementVisibleCount()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] void DecrementVisibleCount (); */
NS_IMETHODIMP_(void) nsImageLoadingContent::DecrementVisibleCount()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] uint32_t GetVisibleCount (); */
NS_IMETHODIMP_(uint32_t) nsImageLoadingContent::GetVisibleCount()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIImageLoadingContent_h__ */

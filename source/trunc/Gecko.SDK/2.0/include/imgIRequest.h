/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/modules/libpr0n/public/imgIRequest.idl
 */

#ifndef __gen_imgIRequest_h__
#define __gen_imgIRequest_h__


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
class imgIContainer; /* forward declaration */

class imgIDecoderObserver; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIPrincipal; /* forward declaration */


/* starting interface:    imgIRequest */
#define IMGIREQUEST_IID_STR "62f58f12-3076-44fc-a742-5b648dac21bc"

#define IMGIREQUEST_IID \
  {0x62f58f12, 0x3076, 0x44fc, \
    { 0xa7, 0x42, 0x5b, 0x64, 0x8d, 0xac, 0x21, 0xbc }}

/**
 * imgIRequest interface
 *
 * @author Stuart Parmenter <stuart@mozilla.com>
 * @version 0.1
 * @see imagelib2
 */
class NS_NO_VTABLE NS_SCRIPTABLE imgIRequest : public nsIRequest {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMGIREQUEST_IID)

  /**
   * the image container...
   * @return the image object associated with the request.
   * @attention NEED DOCS
   */
  /* readonly attribute imgIContainer image; */
  NS_SCRIPTABLE NS_IMETHOD GetImage(imgIContainer **aImage) = 0;

  /**
   * Bits set in the return value from imageStatus
   * @name statusflags
   *
   * Meanings:
   *
   * STATUS_NONE: Nothing to report.
   *
   * STATUS_SIZE_AVAILABLE: We received enough image data
   * from the network or filesystem that we know the width
   * and height of the image, and have thus called SetSize()
   * on the container.
   *
   * STATUS_LOAD_PARTIAL: Used internally by imgRequest to
   * flag that a request is being cancelled as a result of
   * a failure of a proxy holder and not an internal failure.
   * At least I think that's what it does. Regardless, there's
   * no reason for this flag to be public, and it should either
   * go away or become a private state flag within imgRequest.
   * Don't rely on it.
   *
   * STATUS_LOAD_COMPLETE: The data has been fully loaded
   * to memory, but not necessarily fully decoded.
   *
   * STATUS_ERROR: An error occurred loading the image.
   *
   * STATUS_FRAME_COMPLETE: The first frame has been
   * completely decoded.
   *
   * STATUS_DECODE_COMPLETE: The whole image has been decoded.
   */
  enum { STATUS_NONE = 0 };

  enum { STATUS_SIZE_AVAILABLE = 1 };

  enum { STATUS_LOAD_PARTIAL = 2 };

  enum { STATUS_LOAD_COMPLETE = 4 };

  enum { STATUS_ERROR = 8 };

  enum { STATUS_FRAME_COMPLETE = 16 };

  enum { STATUS_DECODE_COMPLETE = 32 };

  /**
   * Status flags of the STATUS_* variety.
   */
  /* readonly attribute unsigned long imageStatus; */
  NS_SCRIPTABLE NS_IMETHOD GetImageStatus(PRUint32 *aImageStatus) = 0;

  /**
   * The URI the image load was started with.  Note that this might not be the
   * actual URI for the image (e.g. if HTTP redirects happened during the
   * load).
   */
  /* readonly attribute nsIURI URI; */
  NS_SCRIPTABLE NS_IMETHOD GetURI(nsIURI **aURI) = 0;

  /* readonly attribute imgIDecoderObserver decoderObserver; */
  NS_SCRIPTABLE NS_IMETHOD GetDecoderObserver(imgIDecoderObserver **aDecoderObserver) = 0;

  /* readonly attribute string mimeType; */
  NS_SCRIPTABLE NS_IMETHOD GetMimeType(char **aMimeType) = 0;

  /**
   * Clone this request; the returned request will have aObserver as the
   * observer.  aObserver will be notified synchronously (before the clone()
   * call returns) with all the notifications that have already been dispatched
   * for this image load.
   */
  /* imgIRequest clone (in imgIDecoderObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD Clone(imgIDecoderObserver *aObserver, imgIRequest **_retval NS_OUTPARAM) = 0;

  /**
   * The principal gotten from the channel the image was loaded from.
   */
  /* readonly attribute nsIPrincipal imagePrincipal; */
  NS_SCRIPTABLE NS_IMETHOD GetImagePrincipal(nsIPrincipal **aImagePrincipal) = 0;

  /**
   * Cancels this request as in nsIRequest::Cancel(); further, also nulls out
   * decoderObserver so it gets no further notifications from us.
   *
   * NOTE: You should not use this in any new code; instead, use cancel(). Note
   * that cancel() is asynchronous, which means that some time after you call
   * it, the listener/observer will get an OnStopRequest(). This means that, if
   * you're the observer, you can't call cancel() from your destructor.
   */
  /* void cancelAndForgetObserver (in nsresult aStatus); */
  NS_SCRIPTABLE NS_IMETHOD CancelAndForgetObserver(nsresult aStatus) = 0;

  /**
   * Requests a decode for the image.
   *
   * imgIContainer has a requestDecode() method, but callers may want to request
   * a decode before the container has necessarily been instantiated. Calling
   * requestDecode() on the imgIRequest simply forwards along the request if the
   * container already exists, or calls it once it gets OnStartContainer if the
   * container does not yet exist.
   */
  /* void requestDecode (); */
  NS_SCRIPTABLE NS_IMETHOD RequestDecode(void) = 0;

  /**
   * Locks an image. If the image does not exist yet, locks it once it becomes
   * available. The lock persists for the lifetime of the imgIRequest (until
   * unlockImage is called) even if the underlying image changes.
   *
   * If you don't call unlockImage() by the time this imgIRequest goes away, it
   * will be called for you automatically.
   *
   * @see imgIContainer::lockImage for documentation of the underlying call.
   */
  /* void lockImage (); */
  NS_SCRIPTABLE NS_IMETHOD LockImage(void) = 0;

  /**
   * Unlocks an image.
   *
   * @see imgIContainer::unlockImage for documentation of the underlying call.
   */
  /* void unlockImage (); */
  NS_SCRIPTABLE NS_IMETHOD UnlockImage(void) = 0;

  /**
   * If this request is for an animated image, the method creates a new
   * request which contains the current frame of the image.
   * Otherwise returns the same request.
   */
  /* imgIRequest getStaticRequest (); */
  NS_SCRIPTABLE NS_IMETHOD GetStaticRequest(imgIRequest **_retval NS_OUTPARAM) = 0;

  /**
   * Requests that the image animate (if it has an animation).
   *
   * @see Image::IncrementAnimationConsumers for documentation of the underlying call.
   */
  /* void incrementAnimationConsumers (); */
  NS_SCRIPTABLE NS_IMETHOD IncrementAnimationConsumers(void) = 0;

  /**
   * Tell the image it can forget about a request that the image animate.
   *
   * @see Image::DecrementAnimationConsumers for documentation of the underlying call.
   */
  /* void decrementAnimationConsumers (); */
  NS_SCRIPTABLE NS_IMETHOD DecrementAnimationConsumers(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(imgIRequest, IMGIREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMGIREQUEST \
  NS_SCRIPTABLE NS_IMETHOD GetImage(imgIContainer **aImage); \
  NS_SCRIPTABLE NS_IMETHOD GetImageStatus(PRUint32 *aImageStatus); \
  NS_SCRIPTABLE NS_IMETHOD GetURI(nsIURI **aURI); \
  NS_SCRIPTABLE NS_IMETHOD GetDecoderObserver(imgIDecoderObserver **aDecoderObserver); \
  NS_SCRIPTABLE NS_IMETHOD GetMimeType(char **aMimeType); \
  NS_SCRIPTABLE NS_IMETHOD Clone(imgIDecoderObserver *aObserver, imgIRequest **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetImagePrincipal(nsIPrincipal **aImagePrincipal); \
  NS_SCRIPTABLE NS_IMETHOD CancelAndForgetObserver(nsresult aStatus); \
  NS_SCRIPTABLE NS_IMETHOD RequestDecode(void); \
  NS_SCRIPTABLE NS_IMETHOD LockImage(void); \
  NS_SCRIPTABLE NS_IMETHOD UnlockImage(void); \
  NS_SCRIPTABLE NS_IMETHOD GetStaticRequest(imgIRequest **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IncrementAnimationConsumers(void); \
  NS_SCRIPTABLE NS_IMETHOD DecrementAnimationConsumers(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMGIREQUEST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetImage(imgIContainer **aImage) { return _to GetImage(aImage); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageStatus(PRUint32 *aImageStatus) { return _to GetImageStatus(aImageStatus); } \
  NS_SCRIPTABLE NS_IMETHOD GetURI(nsIURI **aURI) { return _to GetURI(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetDecoderObserver(imgIDecoderObserver **aDecoderObserver) { return _to GetDecoderObserver(aDecoderObserver); } \
  NS_SCRIPTABLE NS_IMETHOD GetMimeType(char **aMimeType) { return _to GetMimeType(aMimeType); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(imgIDecoderObserver *aObserver, imgIRequest **_retval NS_OUTPARAM) { return _to Clone(aObserver, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetImagePrincipal(nsIPrincipal **aImagePrincipal) { return _to GetImagePrincipal(aImagePrincipal); } \
  NS_SCRIPTABLE NS_IMETHOD CancelAndForgetObserver(nsresult aStatus) { return _to CancelAndForgetObserver(aStatus); } \
  NS_SCRIPTABLE NS_IMETHOD RequestDecode(void) { return _to RequestDecode(); } \
  NS_SCRIPTABLE NS_IMETHOD LockImage(void) { return _to LockImage(); } \
  NS_SCRIPTABLE NS_IMETHOD UnlockImage(void) { return _to UnlockImage(); } \
  NS_SCRIPTABLE NS_IMETHOD GetStaticRequest(imgIRequest **_retval NS_OUTPARAM) { return _to GetStaticRequest(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD IncrementAnimationConsumers(void) { return _to IncrementAnimationConsumers(); } \
  NS_SCRIPTABLE NS_IMETHOD DecrementAnimationConsumers(void) { return _to DecrementAnimationConsumers(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMGIREQUEST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetImage(imgIContainer **aImage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImage(aImage); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageStatus(PRUint32 *aImageStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageStatus(aImageStatus); } \
  NS_SCRIPTABLE NS_IMETHOD GetURI(nsIURI **aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURI(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetDecoderObserver(imgIDecoderObserver **aDecoderObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDecoderObserver(aDecoderObserver); } \
  NS_SCRIPTABLE NS_IMETHOD GetMimeType(char **aMimeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMimeType(aMimeType); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(imgIDecoderObserver *aObserver, imgIRequest **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(aObserver, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetImagePrincipal(nsIPrincipal **aImagePrincipal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImagePrincipal(aImagePrincipal); } \
  NS_SCRIPTABLE NS_IMETHOD CancelAndForgetObserver(nsresult aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->CancelAndForgetObserver(aStatus); } \
  NS_SCRIPTABLE NS_IMETHOD RequestDecode(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestDecode(); } \
  NS_SCRIPTABLE NS_IMETHOD LockImage(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->LockImage(); } \
  NS_SCRIPTABLE NS_IMETHOD UnlockImage(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnlockImage(); } \
  NS_SCRIPTABLE NS_IMETHOD GetStaticRequest(imgIRequest **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStaticRequest(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD IncrementAnimationConsumers(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->IncrementAnimationConsumers(); } \
  NS_SCRIPTABLE NS_IMETHOD DecrementAnimationConsumers(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DecrementAnimationConsumers(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public imgIRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMGIREQUEST

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, imgIRequest)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute imgIContainer image; */
NS_IMETHODIMP _MYCLASS_::GetImage(imgIContainer **aImage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long imageStatus; */
NS_IMETHODIMP _MYCLASS_::GetImageStatus(PRUint32 *aImageStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI URI; */
NS_IMETHODIMP _MYCLASS_::GetURI(nsIURI **aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute imgIDecoderObserver decoderObserver; */
NS_IMETHODIMP _MYCLASS_::GetDecoderObserver(imgIDecoderObserver **aDecoderObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string mimeType; */
NS_IMETHODIMP _MYCLASS_::GetMimeType(char **aMimeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* imgIRequest clone (in imgIDecoderObserver aObserver); */
NS_IMETHODIMP _MYCLASS_::Clone(imgIDecoderObserver *aObserver, imgIRequest **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIPrincipal imagePrincipal; */
NS_IMETHODIMP _MYCLASS_::GetImagePrincipal(nsIPrincipal **aImagePrincipal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancelAndForgetObserver (in nsresult aStatus); */
NS_IMETHODIMP _MYCLASS_::CancelAndForgetObserver(nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void requestDecode (); */
NS_IMETHODIMP _MYCLASS_::RequestDecode()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void lockImage (); */
NS_IMETHODIMP _MYCLASS_::LockImage()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unlockImage (); */
NS_IMETHODIMP _MYCLASS_::UnlockImage()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* imgIRequest getStaticRequest (); */
NS_IMETHODIMP _MYCLASS_::GetStaticRequest(imgIRequest **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void incrementAnimationConsumers (); */
NS_IMETHODIMP _MYCLASS_::IncrementAnimationConsumers()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void decrementAnimationConsumers (); */
NS_IMETHODIMP _MYCLASS_::DecrementAnimationConsumers()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_imgIRequest_h__ */

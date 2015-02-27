/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\imgIRequest.idl
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

class imgINotificationObserver; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIPrincipal; /* forward declaration */


/* starting interface:    imgIRequest */
#define IMGIREQUEST_IID_STR "9c709b50-bd1a-476d-b313-d64db874f80a"

#define IMGIREQUEST_IID \
  {0x9c709b50, 0xbd1a, 0x476d, \
    { 0xb3, 0x13, 0xd6, 0x4d, 0xb8, 0x74, 0xf8, 0x0a }}

class NS_NO_VTABLE imgIRequest : public nsIRequest {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMGIREQUEST_IID)

  /* readonly attribute imgIContainer image; */
  NS_IMETHOD GetImage(imgIContainer * *aImage) = 0;

  enum {
    STATUS_NONE = 0,
    STATUS_SIZE_AVAILABLE = 1,
    STATUS_LOAD_PARTIAL = 2,
    STATUS_LOAD_COMPLETE = 4,
    STATUS_ERROR = 8,
    STATUS_DECODE_STARTED = 16,
    STATUS_FRAME_COMPLETE = 32,
    STATUS_DECODE_COMPLETE = 64
  };

  /* readonly attribute unsigned long imageStatus; */
  NS_IMETHOD GetImageStatus(uint32_t *aImageStatus) = 0;

  /* readonly attribute nsIURI URI; */
  NS_IMETHOD GetURI(nsIURI * *aURI) = 0;

  /* readonly attribute imgINotificationObserver notificationObserver; */
  NS_IMETHOD GetNotificationObserver(imgINotificationObserver * *aNotificationObserver) = 0;

  /* readonly attribute string mimeType; */
  NS_IMETHOD GetMimeType(char * *aMimeType) = 0;

  /* imgIRequest clone (in imgINotificationObserver aObserver); */
  NS_IMETHOD Clone(imgINotificationObserver *aObserver, imgIRequest * *_retval) = 0;

  /* readonly attribute nsIPrincipal imagePrincipal; */
  NS_IMETHOD GetImagePrincipal(nsIPrincipal * *aImagePrincipal) = 0;

  /* readonly attribute bool multipart; */
  NS_IMETHOD GetMultipart(bool *aMultipart) = 0;

  enum {
    CORS_NONE = 1,
    CORS_ANONYMOUS = 2,
    CORS_USE_CREDENTIALS = 3
  };

  /* readonly attribute long CORSMode; */
  NS_IMETHOD GetCORSMode(int32_t *aCORSMode) = 0;

  /* void cancelAndForgetObserver (in nsresult aStatus); */
  NS_IMETHOD CancelAndForgetObserver(nsresult aStatus) = 0;

  /* void requestDecode (); */
  NS_IMETHOD RequestDecode(void) = 0;

  /* void startDecoding (); */
  NS_IMETHOD StartDecoding(void) = 0;

  /* void lockImage (); */
  NS_IMETHOD LockImage(void) = 0;

  /* void unlockImage (); */
  NS_IMETHOD UnlockImage(void) = 0;

  /* void requestDiscard (); */
  NS_IMETHOD RequestDiscard(void) = 0;

  /* imgIRequest getStaticRequest (); */
  NS_IMETHOD GetStaticRequest(imgIRequest * *_retval) = 0;

  /* void incrementAnimationConsumers (); */
  NS_IMETHOD IncrementAnimationConsumers(void) = 0;

  /* void decrementAnimationConsumers (); */
  NS_IMETHOD DecrementAnimationConsumers(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(imgIRequest, IMGIREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMGIREQUEST \
  NS_IMETHOD GetImage(imgIContainer * *aImage); \
  NS_IMETHOD GetImageStatus(uint32_t *aImageStatus); \
  NS_IMETHOD GetURI(nsIURI * *aURI); \
  NS_IMETHOD GetNotificationObserver(imgINotificationObserver * *aNotificationObserver); \
  NS_IMETHOD GetMimeType(char * *aMimeType); \
  NS_IMETHOD Clone(imgINotificationObserver *aObserver, imgIRequest * *_retval); \
  NS_IMETHOD GetImagePrincipal(nsIPrincipal * *aImagePrincipal); \
  NS_IMETHOD GetMultipart(bool *aMultipart); \
  NS_IMETHOD GetCORSMode(int32_t *aCORSMode); \
  NS_IMETHOD CancelAndForgetObserver(nsresult aStatus); \
  NS_IMETHOD RequestDecode(void); \
  NS_IMETHOD StartDecoding(void); \
  NS_IMETHOD LockImage(void); \
  NS_IMETHOD UnlockImage(void); \
  NS_IMETHOD RequestDiscard(void); \
  NS_IMETHOD GetStaticRequest(imgIRequest * *_retval); \
  NS_IMETHOD IncrementAnimationConsumers(void); \
  NS_IMETHOD DecrementAnimationConsumers(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMGIREQUEST(_to) \
  NS_IMETHOD GetImage(imgIContainer * *aImage) { return _to GetImage(aImage); } \
  NS_IMETHOD GetImageStatus(uint32_t *aImageStatus) { return _to GetImageStatus(aImageStatus); } \
  NS_IMETHOD GetURI(nsIURI * *aURI) { return _to GetURI(aURI); } \
  NS_IMETHOD GetNotificationObserver(imgINotificationObserver * *aNotificationObserver) { return _to GetNotificationObserver(aNotificationObserver); } \
  NS_IMETHOD GetMimeType(char * *aMimeType) { return _to GetMimeType(aMimeType); } \
  NS_IMETHOD Clone(imgINotificationObserver *aObserver, imgIRequest * *_retval) { return _to Clone(aObserver, _retval); } \
  NS_IMETHOD GetImagePrincipal(nsIPrincipal * *aImagePrincipal) { return _to GetImagePrincipal(aImagePrincipal); } \
  NS_IMETHOD GetMultipart(bool *aMultipart) { return _to GetMultipart(aMultipart); } \
  NS_IMETHOD GetCORSMode(int32_t *aCORSMode) { return _to GetCORSMode(aCORSMode); } \
  NS_IMETHOD CancelAndForgetObserver(nsresult aStatus) { return _to CancelAndForgetObserver(aStatus); } \
  NS_IMETHOD RequestDecode(void) { return _to RequestDecode(); } \
  NS_IMETHOD StartDecoding(void) { return _to StartDecoding(); } \
  NS_IMETHOD LockImage(void) { return _to LockImage(); } \
  NS_IMETHOD UnlockImage(void) { return _to UnlockImage(); } \
  NS_IMETHOD RequestDiscard(void) { return _to RequestDiscard(); } \
  NS_IMETHOD GetStaticRequest(imgIRequest * *_retval) { return _to GetStaticRequest(_retval); } \
  NS_IMETHOD IncrementAnimationConsumers(void) { return _to IncrementAnimationConsumers(); } \
  NS_IMETHOD DecrementAnimationConsumers(void) { return _to DecrementAnimationConsumers(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMGIREQUEST(_to) \
  NS_IMETHOD GetImage(imgIContainer * *aImage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImage(aImage); } \
  NS_IMETHOD GetImageStatus(uint32_t *aImageStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageStatus(aImageStatus); } \
  NS_IMETHOD GetURI(nsIURI * *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURI(aURI); } \
  NS_IMETHOD GetNotificationObserver(imgINotificationObserver * *aNotificationObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNotificationObserver(aNotificationObserver); } \
  NS_IMETHOD GetMimeType(char * *aMimeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMimeType(aMimeType); } \
  NS_IMETHOD Clone(imgINotificationObserver *aObserver, imgIRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(aObserver, _retval); } \
  NS_IMETHOD GetImagePrincipal(nsIPrincipal * *aImagePrincipal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImagePrincipal(aImagePrincipal); } \
  NS_IMETHOD GetMultipart(bool *aMultipart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMultipart(aMultipart); } \
  NS_IMETHOD GetCORSMode(int32_t *aCORSMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCORSMode(aCORSMode); } \
  NS_IMETHOD CancelAndForgetObserver(nsresult aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->CancelAndForgetObserver(aStatus); } \
  NS_IMETHOD RequestDecode(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestDecode(); } \
  NS_IMETHOD StartDecoding(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartDecoding(); } \
  NS_IMETHOD LockImage(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->LockImage(); } \
  NS_IMETHOD UnlockImage(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnlockImage(); } \
  NS_IMETHOD RequestDiscard(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestDiscard(); } \
  NS_IMETHOD GetStaticRequest(imgIRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStaticRequest(_retval); } \
  NS_IMETHOD IncrementAnimationConsumers(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->IncrementAnimationConsumers(); } \
  NS_IMETHOD DecrementAnimationConsumers(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DecrementAnimationConsumers(); } 

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
NS_IMETHODIMP _MYCLASS_::GetImage(imgIContainer * *aImage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long imageStatus; */
NS_IMETHODIMP _MYCLASS_::GetImageStatus(uint32_t *aImageStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI URI; */
NS_IMETHODIMP _MYCLASS_::GetURI(nsIURI * *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute imgINotificationObserver notificationObserver; */
NS_IMETHODIMP _MYCLASS_::GetNotificationObserver(imgINotificationObserver * *aNotificationObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string mimeType; */
NS_IMETHODIMP _MYCLASS_::GetMimeType(char * *aMimeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* imgIRequest clone (in imgINotificationObserver aObserver); */
NS_IMETHODIMP _MYCLASS_::Clone(imgINotificationObserver *aObserver, imgIRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIPrincipal imagePrincipal; */
NS_IMETHODIMP _MYCLASS_::GetImagePrincipal(nsIPrincipal * *aImagePrincipal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute bool multipart; */
NS_IMETHODIMP _MYCLASS_::GetMultipart(bool *aMultipart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long CORSMode; */
NS_IMETHODIMP _MYCLASS_::GetCORSMode(int32_t *aCORSMode)
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

/* void startDecoding (); */
NS_IMETHODIMP _MYCLASS_::StartDecoding()
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

/* void requestDiscard (); */
NS_IMETHODIMP _MYCLASS_::RequestDiscard()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* imgIRequest getStaticRequest (); */
NS_IMETHODIMP _MYCLASS_::GetStaticRequest(imgIRequest * *_retval)
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

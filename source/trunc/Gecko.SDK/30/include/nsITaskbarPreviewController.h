/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITaskbarPreviewController.idl
 */

#ifndef __gen_nsITaskbarPreviewController_h__
#define __gen_nsITaskbarPreviewController_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDocShell; /* forward declaration */

class nsITaskbarPreview; /* forward declaration */

class nsITaskbarPreviewButton; /* forward declaration */


/* starting interface:    nsITaskbarPreviewController */
#define NS_ITASKBARPREVIEWCONTROLLER_IID_STR "4fc0afbb-3e22-4fba-ac21-953350af0411"

#define NS_ITASKBARPREVIEWCONTROLLER_IID \
  {0x4fc0afbb, 0x3e22, 0x4fba, \
    { 0xac, 0x21, 0x95, 0x33, 0x50, 0xaf, 0x04, 0x11 }}

class NS_NO_VTABLE nsITaskbarPreviewController : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITASKBARPREVIEWCONTROLLER_IID)

  /* readonly attribute unsigned long width; */
  NS_IMETHOD GetWidth(uint32_t *aWidth) = 0;

  /* readonly attribute unsigned long height; */
  NS_IMETHOD GetHeight(uint32_t *aHeight) = 0;

  /* readonly attribute float thumbnailAspectRatio; */
  NS_IMETHOD GetThumbnailAspectRatio(float *aThumbnailAspectRatio) = 0;

  /* boolean drawPreview (in nsISupports ctx); */
  NS_IMETHOD DrawPreview(nsISupports *ctx, bool *_retval) = 0;

  /* boolean drawThumbnail (in nsISupports ctx, in unsigned long width, in unsigned long height); */
  NS_IMETHOD DrawThumbnail(nsISupports *ctx, uint32_t width, uint32_t height, bool *_retval) = 0;

  /* void onClose (); */
  NS_IMETHOD OnClose(void) = 0;

  /* boolean onActivate (); */
  NS_IMETHOD OnActivate(bool *_retval) = 0;

  /* void onClick (in nsITaskbarPreviewButton button); */
  NS_IMETHOD OnClick(nsITaskbarPreviewButton *button) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITaskbarPreviewController, NS_ITASKBARPREVIEWCONTROLLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITASKBARPREVIEWCONTROLLER \
  NS_IMETHOD GetWidth(uint32_t *aWidth); \
  NS_IMETHOD GetHeight(uint32_t *aHeight); \
  NS_IMETHOD GetThumbnailAspectRatio(float *aThumbnailAspectRatio); \
  NS_IMETHOD DrawPreview(nsISupports *ctx, bool *_retval); \
  NS_IMETHOD DrawThumbnail(nsISupports *ctx, uint32_t width, uint32_t height, bool *_retval); \
  NS_IMETHOD OnClose(void); \
  NS_IMETHOD OnActivate(bool *_retval); \
  NS_IMETHOD OnClick(nsITaskbarPreviewButton *button); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITASKBARPREVIEWCONTROLLER(_to) \
  NS_IMETHOD GetWidth(uint32_t *aWidth) { return _to GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(uint32_t *aHeight) { return _to GetHeight(aHeight); } \
  NS_IMETHOD GetThumbnailAspectRatio(float *aThumbnailAspectRatio) { return _to GetThumbnailAspectRatio(aThumbnailAspectRatio); } \
  NS_IMETHOD DrawPreview(nsISupports *ctx, bool *_retval) { return _to DrawPreview(ctx, _retval); } \
  NS_IMETHOD DrawThumbnail(nsISupports *ctx, uint32_t width, uint32_t height, bool *_retval) { return _to DrawThumbnail(ctx, width, height, _retval); } \
  NS_IMETHOD OnClose(void) { return _to OnClose(); } \
  NS_IMETHOD OnActivate(bool *_retval) { return _to OnActivate(_retval); } \
  NS_IMETHOD OnClick(nsITaskbarPreviewButton *button) { return _to OnClick(button); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITASKBARPREVIEWCONTROLLER(_to) \
  NS_IMETHOD GetWidth(uint32_t *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(uint32_t *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_IMETHOD GetThumbnailAspectRatio(float *aThumbnailAspectRatio) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetThumbnailAspectRatio(aThumbnailAspectRatio); } \
  NS_IMETHOD DrawPreview(nsISupports *ctx, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->DrawPreview(ctx, _retval); } \
  NS_IMETHOD DrawThumbnail(nsISupports *ctx, uint32_t width, uint32_t height, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->DrawThumbnail(ctx, width, height, _retval); } \
  NS_IMETHOD OnClose(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnClose(); } \
  NS_IMETHOD OnActivate(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnActivate(_retval); } \
  NS_IMETHOD OnClick(nsITaskbarPreviewButton *button) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnClick(button); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTaskbarPreviewController : public nsITaskbarPreviewController
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITASKBARPREVIEWCONTROLLER

  nsTaskbarPreviewController();

private:
  ~nsTaskbarPreviewController();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTaskbarPreviewController, nsITaskbarPreviewController)

nsTaskbarPreviewController::nsTaskbarPreviewController()
{
  /* member initializers and constructor code */
}

nsTaskbarPreviewController::~nsTaskbarPreviewController()
{
  /* destructor code */
}

/* readonly attribute unsigned long width; */
NS_IMETHODIMP nsTaskbarPreviewController::GetWidth(uint32_t *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long height; */
NS_IMETHODIMP nsTaskbarPreviewController::GetHeight(uint32_t *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float thumbnailAspectRatio; */
NS_IMETHODIMP nsTaskbarPreviewController::GetThumbnailAspectRatio(float *aThumbnailAspectRatio)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean drawPreview (in nsISupports ctx); */
NS_IMETHODIMP nsTaskbarPreviewController::DrawPreview(nsISupports *ctx, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean drawThumbnail (in nsISupports ctx, in unsigned long width, in unsigned long height); */
NS_IMETHODIMP nsTaskbarPreviewController::DrawThumbnail(nsISupports *ctx, uint32_t width, uint32_t height, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onClose (); */
NS_IMETHODIMP nsTaskbarPreviewController::OnClose()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean onActivate (); */
NS_IMETHODIMP nsTaskbarPreviewController::OnActivate(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onClick (in nsITaskbarPreviewButton button); */
NS_IMETHODIMP nsTaskbarPreviewController::OnClick(nsITaskbarPreviewButton *button)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITaskbarPreviewController_h__ */

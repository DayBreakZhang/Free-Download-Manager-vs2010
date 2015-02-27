/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIImageDocument.idl
 */

#ifndef __gen_nsIImageDocument_h__
#define __gen_nsIImageDocument_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class imgIRequest; /* forward declaration */


/* starting interface:    nsIImageDocument */
#define NS_IIMAGEDOCUMENT_IID_STR "87c27f98-37dc-4b64-a8cd-92003624bcee"

#define NS_IIMAGEDOCUMENT_IID \
  {0x87c27f98, 0x37dc, 0x4b64, \
    { 0xa8, 0xcd, 0x92, 0x00, 0x36, 0x24, 0xbc, 0xee }}

class NS_NO_VTABLE nsIImageDocument : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIMAGEDOCUMENT_IID)

  /* readonly attribute boolean imageResizingEnabled; */
  NS_IMETHOD GetImageResizingEnabled(bool *aImageResizingEnabled) = 0;

  /* readonly attribute boolean imageIsOverflowing; */
  NS_IMETHOD GetImageIsOverflowing(bool *aImageIsOverflowing) = 0;

  /* readonly attribute boolean imageIsResized; */
  NS_IMETHOD GetImageIsResized(bool *aImageIsResized) = 0;

  /* readonly attribute imgIRequest imageRequest; */
  NS_IMETHOD GetImageRequest(imgIRequest * *aImageRequest) = 0;

  /* [binaryname(DOMShrinkToFit)] void shrinkToFit (); */
  NS_IMETHOD DOMShrinkToFit(void) = 0;

  /* [binaryname(DOMRestoreImage)] void restoreImage (); */
  NS_IMETHOD DOMRestoreImage(void) = 0;

  /* [binaryname(DOMRestoreImageTo)] void restoreImageTo (in long x, in long y); */
  NS_IMETHOD DOMRestoreImageTo(int32_t x, int32_t y) = 0;

  /* [binaryname(DOMToggleImageSize)] void toggleImageSize (); */
  NS_IMETHOD DOMToggleImageSize(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIImageDocument, NS_IIMAGEDOCUMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIMAGEDOCUMENT \
  NS_IMETHOD GetImageResizingEnabled(bool *aImageResizingEnabled); \
  NS_IMETHOD GetImageIsOverflowing(bool *aImageIsOverflowing); \
  NS_IMETHOD GetImageIsResized(bool *aImageIsResized); \
  NS_IMETHOD GetImageRequest(imgIRequest * *aImageRequest); \
  NS_IMETHOD DOMShrinkToFit(void); \
  NS_IMETHOD DOMRestoreImage(void); \
  NS_IMETHOD DOMRestoreImageTo(int32_t x, int32_t y); \
  NS_IMETHOD DOMToggleImageSize(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIMAGEDOCUMENT(_to) \
  NS_IMETHOD GetImageResizingEnabled(bool *aImageResizingEnabled) { return _to GetImageResizingEnabled(aImageResizingEnabled); } \
  NS_IMETHOD GetImageIsOverflowing(bool *aImageIsOverflowing) { return _to GetImageIsOverflowing(aImageIsOverflowing); } \
  NS_IMETHOD GetImageIsResized(bool *aImageIsResized) { return _to GetImageIsResized(aImageIsResized); } \
  NS_IMETHOD GetImageRequest(imgIRequest * *aImageRequest) { return _to GetImageRequest(aImageRequest); } \
  NS_IMETHOD DOMShrinkToFit(void) { return _to DOMShrinkToFit(); } \
  NS_IMETHOD DOMRestoreImage(void) { return _to DOMRestoreImage(); } \
  NS_IMETHOD DOMRestoreImageTo(int32_t x, int32_t y) { return _to DOMRestoreImageTo(x, y); } \
  NS_IMETHOD DOMToggleImageSize(void) { return _to DOMToggleImageSize(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIMAGEDOCUMENT(_to) \
  NS_IMETHOD GetImageResizingEnabled(bool *aImageResizingEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageResizingEnabled(aImageResizingEnabled); } \
  NS_IMETHOD GetImageIsOverflowing(bool *aImageIsOverflowing) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageIsOverflowing(aImageIsOverflowing); } \
  NS_IMETHOD GetImageIsResized(bool *aImageIsResized) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageIsResized(aImageIsResized); } \
  NS_IMETHOD GetImageRequest(imgIRequest * *aImageRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageRequest(aImageRequest); } \
  NS_IMETHOD DOMShrinkToFit(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DOMShrinkToFit(); } \
  NS_IMETHOD DOMRestoreImage(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DOMRestoreImage(); } \
  NS_IMETHOD DOMRestoreImageTo(int32_t x, int32_t y) { return !_to ? NS_ERROR_NULL_POINTER : _to->DOMRestoreImageTo(x, y); } \
  NS_IMETHOD DOMToggleImageSize(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DOMToggleImageSize(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsImageDocument : public nsIImageDocument
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIMAGEDOCUMENT

  nsImageDocument();

private:
  ~nsImageDocument();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsImageDocument, nsIImageDocument)

nsImageDocument::nsImageDocument()
{
  /* member initializers and constructor code */
}

nsImageDocument::~nsImageDocument()
{
  /* destructor code */
}

/* readonly attribute boolean imageResizingEnabled; */
NS_IMETHODIMP nsImageDocument::GetImageResizingEnabled(bool *aImageResizingEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean imageIsOverflowing; */
NS_IMETHODIMP nsImageDocument::GetImageIsOverflowing(bool *aImageIsOverflowing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean imageIsResized; */
NS_IMETHODIMP nsImageDocument::GetImageIsResized(bool *aImageIsResized)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute imgIRequest imageRequest; */
NS_IMETHODIMP nsImageDocument::GetImageRequest(imgIRequest * *aImageRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(DOMShrinkToFit)] void shrinkToFit (); */
NS_IMETHODIMP nsImageDocument::DOMShrinkToFit()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(DOMRestoreImage)] void restoreImage (); */
NS_IMETHODIMP nsImageDocument::DOMRestoreImage()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(DOMRestoreImageTo)] void restoreImageTo (in long x, in long y); */
NS_IMETHODIMP nsImageDocument::DOMRestoreImageTo(int32_t x, int32_t y)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(DOMToggleImageSize)] void toggleImageSize (); */
NS_IMETHODIMP nsImageDocument::DOMToggleImageSize()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIImageDocument_h__ */

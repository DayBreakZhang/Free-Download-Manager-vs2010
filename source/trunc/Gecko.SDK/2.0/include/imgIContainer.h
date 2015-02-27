/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/modules/libpr0n/public/imgIContainer.idl
 */

#ifndef __gen_imgIContainer_h__
#define __gen_imgIContainer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class imgIDecoderObserver; /* forward declaration */

#include "gfxImageSurface.h"
#include "gfxContext.h"
#include "gfxMatrix.h"
#include "gfxRect.h"
#include "gfxPattern.h"
#include "gfxASurface.h"
#include "nsRect.h"
#include "nsSize.h"
#include "limits.h"
class nsIFrame;

/* starting interface:    imgIContainer */
#define IMGICONTAINER_IID_STR "239dfa70-2285-4d63-99cd-e9b7ff9555c7"

#define IMGICONTAINER_IID \
  {0x239dfa70, 0x2285, 0x4d63, \
    { 0x99, 0xcd, 0xe9, 0xb7, 0xff, 0x95, 0x55, 0xc7 }}

/**
 * imgIContainer is the interface that represents an image. It allows
 * access to frames as Thebes surfaces, and permits users to extract subregions
 * as other imgIContainers. It also allows drawing of images on to Thebes
 * contexts.
 *
 * Internally, imgIContainer also manages animation of images.
 */
class NS_NO_VTABLE NS_SCRIPTABLE imgIContainer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMGICONTAINER_IID)

  /**
   * The width of the container rectangle.  In the case of any error,
   * zero is returned, and an exception will be thrown.
   */
  /* readonly attribute PRInt32 width; */
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) = 0;

  /**
   * The height of the container rectangle.  In the case of any error,
   * zero is returned, and an exception will be thrown.
   */
  /* readonly attribute PRInt32 height; */
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) = 0;

  /**
    * Enumerated values for the 'type' attribute (below).
    */
  enum { TYPE_RASTER = 0U };

  enum { TYPE_VECTOR = 1U };

  /**
   * The type of this image (one of the TYPE_* values above).
   */
  /* readonly attribute unsigned short type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint16 *aType) = 0;

  /**
   * Direct C++ accessor for 'type' attribute, for convenience.
   */
  /* [noscript, notxpcom] PRUint16 GetType (); */
  NS_IMETHOD_(PRUint16 ) GetType(void) = 0;

  /**
   * Whether this image is animated. You can only be guaranteed that querying
   * this will not throw if STATUS_DECODE_COMPLETE is set on the imgIRequest.
   *
   * @throws NS_ERROR_NOT_AVAILABLE if the animated state cannot be determined.
   */
  /* readonly attribute boolean animated; */
  NS_SCRIPTABLE NS_IMETHOD GetAnimated(PRBool *aAnimated) = 0;

  /**
   * Whether the current frame is opaque; that is, needs the background painted
   * behind it.
   */
  /* readonly attribute boolean currentFrameIsOpaque; */
  NS_SCRIPTABLE NS_IMETHOD GetCurrentFrameIsOpaque(PRBool *aCurrentFrameIsOpaque) = 0;

  /**
   * Flags for imgIContainer operations.
   *
   * Meanings:
   *
   * FLAG_NONE: Lack of flags
   *
   * FLAG_SYNC_DECODE: Forces synchronous/non-progressive decode of all
   * available data before the call returns. It is an error to pass this flag
   * from a call stack that originates in a decoder (ie, from a decoder
   * observer event).
   *
   * FLAG_DECODE_NO_PREMULTIPLY_ALPHA: Do not premultiply alpha if
   * it's not already premultiplied in the image data.
   *
   * FLAG_DECODE_NO_COLORSPACE_CONVERSION: Do not do any colorspace conversion;
   * ignore any embedded profiles, and don't convert to any particular destination
   * space.
   */
  enum { FLAG_NONE = 0 };

  enum { FLAG_SYNC_DECODE = 1 };

  enum { FLAG_DECODE_NO_PREMULTIPLY_ALPHA = 2 };

  enum { FLAG_DECODE_NO_COLORSPACE_CONVERSION = 4 };

  /**
    * Constants for specifying various "special" frames.
    *
    * FRAME_FIRST: The first frame
    * FRAME_CURRENT: The current frame
    *
    * FRAME_MAX_VALUE should be set to the value of the maximum constant above,
    * as it is used for ensuring that a valid value was passed in.
    */
  enum { FRAME_FIRST = 0U };

  enum { FRAME_CURRENT = 1U };

  enum { FRAME_MAX_VALUE = 1U };

  /**
   * Get a surface for the given frame. This may be a platform-native,
   * optimized surface, so you cannot inspect its pixel data.
   *
   * @param aWhichFrame Frame specifier of the FRAME_* variety.
   * @param aFlags Flags of the FLAG_* variety
   */
  /* [noscript] gfxASurface getFrame (in PRUint32 aWhichFrame, in PRUint32 aFlags); */
  NS_IMETHOD GetFrame(PRUint32 aWhichFrame, PRUint32 aFlags, gfxASurface **_retval NS_OUTPARAM) = 0;

  /**
   * Create and return a new copy of the given frame that you can write to
   * and otherwise inspect the pixels of.
   *
   * @param aWhichFrame Frame specifier of the FRAME_* variety.
   * @param aFlags Flags of the FLAG_* variety
   */
  /* [noscript] gfxImageSurface copyFrame (in PRUint32 aWhichFrame, in PRUint32 aFlags); */
  NS_IMETHOD CopyFrame(PRUint32 aWhichFrame, PRUint32 aFlags, gfxImageSurface **_retval NS_OUTPARAM) = 0;

  /**
   * Create a new imgContainer that contains only a single frame, which itself
   * contains a subregion of the given frame.
   *
   * @param aWhichFrame Frame specifier of the FRAME_* variety.
   * @param aRect the area of the current frame to be duplicated in the
   *              returned imgContainer's frame.
   * @param aFlags Flags of the FLAG_* variety
   */
  /* [noscript] imgIContainer extractFrame (in PRUint32 aWhichFrame, [const] in nsIntRect aRect, in PRUint32 aFlags); */
  NS_IMETHOD ExtractFrame(PRUint32 aWhichFrame, const nsIntRect & aRect, PRUint32 aFlags, imgIContainer **_retval NS_OUTPARAM) = 0;

  /**
   * Draw the current frame on to the context specified.
   *
   * @param aContext The Thebes context to draw the image to.
   * @param aFilter The filter to be used if we're scaling the image.
   * @param aUserSpaceToImageSpace The transformation from user space (e.g.,
   *                               appunits) to image space.
   * @param aFill The area in the context to draw pixels to. Image will be
   *              automatically tiled as necessary.
   * @param aSubimage The area of the image, in pixels, that we are allowed to
   *                  sample from.
   * @param aViewportSize
   *          The size (in CSS pixels) of the viewport that would be available
   *          for the full image to occupy, if we were drawing the full image.
   *          (Note that we might not actually be drawing the full image -- we
   *          might be restricted by aSubimage -- but we still need the full
   *          image's viewport-size in order for SVG images with the "viewBox"
   *          attribute to position their content correctly.)
   * @param aFlags Flags of the FLAG_* variety
   */
  /* [noscript] void draw (in gfxContext aContext, in gfxGraphicsFilter aFilter, [const] in gfxMatrix aUserSpaceToImageSpace, [const] in gfxRect aFill, [const] in nsIntRect aSubimage, [const] in nsIntSize aViewportSize, in PRUint32 aFlags); */
  NS_IMETHOD Draw(gfxContext *aContext, gfxPattern::GraphicsFilter aFilter, const gfxMatrix & aUserSpaceToImageSpace, const gfxRect & aFill, const nsIntRect & aSubimage, const nsIntSize & aViewportSize, PRUint32 aFlags) = 0;

  /**
   * If this image is TYPE_VECTOR, i.e. is really an embedded SVG document,
   * this method returns a pointer to the root nsIFrame of that document. If
   * not (or if the root nsIFrame isn't available for some reason), this method
   * returns nsnull.
   *
   * "notxpcom" for convenience, since we have no need for nsresult return-val.
   */
  /* [notxpcom] nsIFrame GetRootLayoutFrame (); */
  NS_IMETHOD_(nsIFrame *) GetRootLayoutFrame(void) = 0;

  /* void requestDecode (); */
  NS_SCRIPTABLE NS_IMETHOD RequestDecode(void) = 0;

  /**
    * Increments the lock count on the image. An image will not be discarded
    * as long as the lock count is nonzero. Note that it is still possible for
    * the image to be undecoded if decode-on-draw is enabled and the image
    * was never drawn.
    *
    * Upon instantiation images have a lock count of zero.
    */
  /* void lockImage (); */
  NS_SCRIPTABLE NS_IMETHOD LockImage(void) = 0;

  /**
    * Decreases the lock count on the image. If the lock count drops to zero,
    * the image is allowed to discard its frame data to save memory.
    *
    * Upon instantiation images have a lock count of zero. It is an error to
    * call this method without first having made a matching lockImage() call.
    * In other words, the lock count is not allowed to be negative.
    */
  /* void unlockImage (); */
  NS_SCRIPTABLE NS_IMETHOD UnlockImage(void) = 0;

  /**
   * Animation mode Constants
   *   0 = normal
   *   1 = don't animate
   *   2 = loop once
   */
  enum { kNormalAnimMode = 0 };

  enum { kDontAnimMode = 1 };

  enum { kLoopOnceAnimMode = 2 };

  /* attribute unsigned short animationMode; */
  NS_SCRIPTABLE NS_IMETHOD GetAnimationMode(PRUint16 *aAnimationMode) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAnimationMode(PRUint16 aAnimationMode) = 0;

  /* void resetAnimation (); */
  NS_SCRIPTABLE NS_IMETHOD ResetAnimation(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(imgIContainer, IMGICONTAINER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMGICONTAINER \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight); \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint16 *aType); \
  NS_IMETHOD_(PRUint16 ) GetType(void); \
  NS_SCRIPTABLE NS_IMETHOD GetAnimated(PRBool *aAnimated); \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentFrameIsOpaque(PRBool *aCurrentFrameIsOpaque); \
  NS_IMETHOD GetFrame(PRUint32 aWhichFrame, PRUint32 aFlags, gfxASurface **_retval NS_OUTPARAM); \
  NS_IMETHOD CopyFrame(PRUint32 aWhichFrame, PRUint32 aFlags, gfxImageSurface **_retval NS_OUTPARAM); \
  NS_IMETHOD ExtractFrame(PRUint32 aWhichFrame, const nsIntRect & aRect, PRUint32 aFlags, imgIContainer **_retval NS_OUTPARAM); \
  NS_IMETHOD Draw(gfxContext *aContext, gfxPattern::GraphicsFilter aFilter, const gfxMatrix & aUserSpaceToImageSpace, const gfxRect & aFill, const nsIntRect & aSubimage, const nsIntSize & aViewportSize, PRUint32 aFlags); \
  NS_IMETHOD_(nsIFrame *) GetRootLayoutFrame(void); \
  NS_SCRIPTABLE NS_IMETHOD RequestDecode(void); \
  NS_SCRIPTABLE NS_IMETHOD LockImage(void); \
  NS_SCRIPTABLE NS_IMETHOD UnlockImage(void); \
  NS_SCRIPTABLE NS_IMETHOD GetAnimationMode(PRUint16 *aAnimationMode); \
  NS_SCRIPTABLE NS_IMETHOD SetAnimationMode(PRUint16 aAnimationMode); \
  NS_SCRIPTABLE NS_IMETHOD ResetAnimation(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMGICONTAINER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return _to GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) { return _to GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint16 *aType) { return _to GetType(aType); } \
  NS_IMETHOD_(PRUint16 ) GetType(void) { return _to GetType(); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimated(PRBool *aAnimated) { return _to GetAnimated(aAnimated); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentFrameIsOpaque(PRBool *aCurrentFrameIsOpaque) { return _to GetCurrentFrameIsOpaque(aCurrentFrameIsOpaque); } \
  NS_IMETHOD GetFrame(PRUint32 aWhichFrame, PRUint32 aFlags, gfxASurface **_retval NS_OUTPARAM) { return _to GetFrame(aWhichFrame, aFlags, _retval); } \
  NS_IMETHOD CopyFrame(PRUint32 aWhichFrame, PRUint32 aFlags, gfxImageSurface **_retval NS_OUTPARAM) { return _to CopyFrame(aWhichFrame, aFlags, _retval); } \
  NS_IMETHOD ExtractFrame(PRUint32 aWhichFrame, const nsIntRect & aRect, PRUint32 aFlags, imgIContainer **_retval NS_OUTPARAM) { return _to ExtractFrame(aWhichFrame, aRect, aFlags, _retval); } \
  NS_IMETHOD Draw(gfxContext *aContext, gfxPattern::GraphicsFilter aFilter, const gfxMatrix & aUserSpaceToImageSpace, const gfxRect & aFill, const nsIntRect & aSubimage, const nsIntSize & aViewportSize, PRUint32 aFlags) { return _to Draw(aContext, aFilter, aUserSpaceToImageSpace, aFill, aSubimage, aViewportSize, aFlags); } \
  NS_IMETHOD_(nsIFrame *) GetRootLayoutFrame(void) { return _to GetRootLayoutFrame(); } \
  NS_SCRIPTABLE NS_IMETHOD RequestDecode(void) { return _to RequestDecode(); } \
  NS_SCRIPTABLE NS_IMETHOD LockImage(void) { return _to LockImage(); } \
  NS_SCRIPTABLE NS_IMETHOD UnlockImage(void) { return _to UnlockImage(); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimationMode(PRUint16 *aAnimationMode) { return _to GetAnimationMode(aAnimationMode); } \
  NS_SCRIPTABLE NS_IMETHOD SetAnimationMode(PRUint16 aAnimationMode) { return _to SetAnimationMode(aAnimationMode); } \
  NS_SCRIPTABLE NS_IMETHOD ResetAnimation(void) { return _to ResetAnimation(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMGICONTAINER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint16 *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD_(PRUint16 ) GetType(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimated(PRBool *aAnimated) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnimated(aAnimated); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentFrameIsOpaque(PRBool *aCurrentFrameIsOpaque) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentFrameIsOpaque(aCurrentFrameIsOpaque); } \
  NS_IMETHOD GetFrame(PRUint32 aWhichFrame, PRUint32 aFlags, gfxASurface **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFrame(aWhichFrame, aFlags, _retval); } \
  NS_IMETHOD CopyFrame(PRUint32 aWhichFrame, PRUint32 aFlags, gfxImageSurface **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyFrame(aWhichFrame, aFlags, _retval); } \
  NS_IMETHOD ExtractFrame(PRUint32 aWhichFrame, const nsIntRect & aRect, PRUint32 aFlags, imgIContainer **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExtractFrame(aWhichFrame, aRect, aFlags, _retval); } \
  NS_IMETHOD Draw(gfxContext *aContext, gfxPattern::GraphicsFilter aFilter, const gfxMatrix & aUserSpaceToImageSpace, const gfxRect & aFill, const nsIntRect & aSubimage, const nsIntSize & aViewportSize, PRUint32 aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->Draw(aContext, aFilter, aUserSpaceToImageSpace, aFill, aSubimage, aViewportSize, aFlags); } \
  NS_IMETHOD_(nsIFrame *) GetRootLayoutFrame(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootLayoutFrame(); } \
  NS_SCRIPTABLE NS_IMETHOD RequestDecode(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestDecode(); } \
  NS_SCRIPTABLE NS_IMETHOD LockImage(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->LockImage(); } \
  NS_SCRIPTABLE NS_IMETHOD UnlockImage(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnlockImage(); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimationMode(PRUint16 *aAnimationMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnimationMode(aAnimationMode); } \
  NS_SCRIPTABLE NS_IMETHOD SetAnimationMode(PRUint16 aAnimationMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAnimationMode(aAnimationMode); } \
  NS_SCRIPTABLE NS_IMETHOD ResetAnimation(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResetAnimation(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public imgIContainer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMGICONTAINER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, imgIContainer)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute PRInt32 width; */
NS_IMETHODIMP _MYCLASS_::GetWidth(PRInt32 *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRInt32 height; */
NS_IMETHODIMP _MYCLASS_::GetHeight(PRInt32 *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short type; */
NS_IMETHODIMP _MYCLASS_::GetType(PRUint16 *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript, notxpcom] PRUint16 GetType (); */
NS_IMETHODIMP_(PRUint16 ) _MYCLASS_::GetType()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean animated; */
NS_IMETHODIMP _MYCLASS_::GetAnimated(PRBool *aAnimated)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean currentFrameIsOpaque; */
NS_IMETHODIMP _MYCLASS_::GetCurrentFrameIsOpaque(PRBool *aCurrentFrameIsOpaque)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] gfxASurface getFrame (in PRUint32 aWhichFrame, in PRUint32 aFlags); */
NS_IMETHODIMP _MYCLASS_::GetFrame(PRUint32 aWhichFrame, PRUint32 aFlags, gfxASurface **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] gfxImageSurface copyFrame (in PRUint32 aWhichFrame, in PRUint32 aFlags); */
NS_IMETHODIMP _MYCLASS_::CopyFrame(PRUint32 aWhichFrame, PRUint32 aFlags, gfxImageSurface **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] imgIContainer extractFrame (in PRUint32 aWhichFrame, [const] in nsIntRect aRect, in PRUint32 aFlags); */
NS_IMETHODIMP _MYCLASS_::ExtractFrame(PRUint32 aWhichFrame, const nsIntRect & aRect, PRUint32 aFlags, imgIContainer **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void draw (in gfxContext aContext, in gfxGraphicsFilter aFilter, [const] in gfxMatrix aUserSpaceToImageSpace, [const] in gfxRect aFill, [const] in nsIntRect aSubimage, [const] in nsIntSize aViewportSize, in PRUint32 aFlags); */
NS_IMETHODIMP _MYCLASS_::Draw(gfxContext *aContext, gfxPattern::GraphicsFilter aFilter, const gfxMatrix & aUserSpaceToImageSpace, const gfxRect & aFill, const nsIntRect & aSubimage, const nsIntSize & aViewportSize, PRUint32 aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] nsIFrame GetRootLayoutFrame (); */
NS_IMETHODIMP_(nsIFrame *) _MYCLASS_::GetRootLayoutFrame()
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

/* attribute unsigned short animationMode; */
NS_IMETHODIMP _MYCLASS_::GetAnimationMode(PRUint16 *aAnimationMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetAnimationMode(PRUint16 aAnimationMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resetAnimation (); */
NS_IMETHODIMP _MYCLASS_::ResetAnimation()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_imgIContainer_h__ */

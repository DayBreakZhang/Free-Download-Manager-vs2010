/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMHTMLVideoElement.idl
 */

#ifndef __gen_nsIDOMHTMLVideoElement_h__
#define __gen_nsIDOMHTMLVideoElement_h__


#ifndef __gen_nsIDOMHTMLMediaElement_h__
#include "nsIDOMHTMLMediaElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLVideoElement */
#define NS_IDOMHTMLVIDEOELEMENT_IID_STR "185a3e8f-56a7-4bda-8dc7-2cff6ed07d1d"

#define NS_IDOMHTMLVIDEOELEMENT_IID \
  {0x185a3e8f, 0x56a7, 0x4bda, \
    { 0x8d, 0xc7, 0x2c, 0xff, 0x6e, 0xd0, 0x7d, 0x1d }}

class NS_NO_VTABLE nsIDOMHTMLVideoElement : public nsIDOMHTMLMediaElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLVIDEOELEMENT_IID)

  /* attribute long width; */
  NS_IMETHOD GetWidth(int32_t *aWidth) = 0;
  NS_IMETHOD SetWidth(int32_t aWidth) = 0;

  /* attribute long height; */
  NS_IMETHOD GetHeight(int32_t *aHeight) = 0;
  NS_IMETHOD SetHeight(int32_t aHeight) = 0;

  /* readonly attribute unsigned long videoWidth; */
  NS_IMETHOD GetVideoWidth(uint32_t *aVideoWidth) = 0;

  /* readonly attribute unsigned long videoHeight; */
  NS_IMETHOD GetVideoHeight(uint32_t *aVideoHeight) = 0;

  /* attribute DOMString poster; */
  NS_IMETHOD GetPoster(nsAString & aPoster) = 0;
  NS_IMETHOD SetPoster(const nsAString & aPoster) = 0;

  /* readonly attribute unsigned long mozParsedFrames; */
  NS_IMETHOD GetMozParsedFrames(uint32_t *aMozParsedFrames) = 0;

  /* readonly attribute unsigned long mozDecodedFrames; */
  NS_IMETHOD GetMozDecodedFrames(uint32_t *aMozDecodedFrames) = 0;

  /* readonly attribute unsigned long mozPresentedFrames; */
  NS_IMETHOD GetMozPresentedFrames(uint32_t *aMozPresentedFrames) = 0;

  /* readonly attribute unsigned long mozPaintedFrames; */
  NS_IMETHOD GetMozPaintedFrames(uint32_t *aMozPaintedFrames) = 0;

  /* readonly attribute double mozFrameDelay; */
  NS_IMETHOD GetMozFrameDelay(double *aMozFrameDelay) = 0;

  /* readonly attribute bool mozHasAudio; */
  NS_IMETHOD GetMozHasAudio(bool *aMozHasAudio) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLVideoElement, NS_IDOMHTMLVIDEOELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLVIDEOELEMENT \
  NS_IMETHOD GetWidth(int32_t *aWidth); \
  NS_IMETHOD SetWidth(int32_t aWidth); \
  NS_IMETHOD GetHeight(int32_t *aHeight); \
  NS_IMETHOD SetHeight(int32_t aHeight); \
  NS_IMETHOD GetVideoWidth(uint32_t *aVideoWidth); \
  NS_IMETHOD GetVideoHeight(uint32_t *aVideoHeight); \
  NS_IMETHOD GetPoster(nsAString & aPoster); \
  NS_IMETHOD SetPoster(const nsAString & aPoster); \
  NS_IMETHOD GetMozParsedFrames(uint32_t *aMozParsedFrames); \
  NS_IMETHOD GetMozDecodedFrames(uint32_t *aMozDecodedFrames); \
  NS_IMETHOD GetMozPresentedFrames(uint32_t *aMozPresentedFrames); \
  NS_IMETHOD GetMozPaintedFrames(uint32_t *aMozPaintedFrames); \
  NS_IMETHOD GetMozFrameDelay(double *aMozFrameDelay); \
  NS_IMETHOD GetMozHasAudio(bool *aMozHasAudio); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLVIDEOELEMENT(_to) \
  NS_IMETHOD GetWidth(int32_t *aWidth) { return _to GetWidth(aWidth); } \
  NS_IMETHOD SetWidth(int32_t aWidth) { return _to SetWidth(aWidth); } \
  NS_IMETHOD GetHeight(int32_t *aHeight) { return _to GetHeight(aHeight); } \
  NS_IMETHOD SetHeight(int32_t aHeight) { return _to SetHeight(aHeight); } \
  NS_IMETHOD GetVideoWidth(uint32_t *aVideoWidth) { return _to GetVideoWidth(aVideoWidth); } \
  NS_IMETHOD GetVideoHeight(uint32_t *aVideoHeight) { return _to GetVideoHeight(aVideoHeight); } \
  NS_IMETHOD GetPoster(nsAString & aPoster) { return _to GetPoster(aPoster); } \
  NS_IMETHOD SetPoster(const nsAString & aPoster) { return _to SetPoster(aPoster); } \
  NS_IMETHOD GetMozParsedFrames(uint32_t *aMozParsedFrames) { return _to GetMozParsedFrames(aMozParsedFrames); } \
  NS_IMETHOD GetMozDecodedFrames(uint32_t *aMozDecodedFrames) { return _to GetMozDecodedFrames(aMozDecodedFrames); } \
  NS_IMETHOD GetMozPresentedFrames(uint32_t *aMozPresentedFrames) { return _to GetMozPresentedFrames(aMozPresentedFrames); } \
  NS_IMETHOD GetMozPaintedFrames(uint32_t *aMozPaintedFrames) { return _to GetMozPaintedFrames(aMozPaintedFrames); } \
  NS_IMETHOD GetMozFrameDelay(double *aMozFrameDelay) { return _to GetMozFrameDelay(aMozFrameDelay); } \
  NS_IMETHOD GetMozHasAudio(bool *aMozHasAudio) { return _to GetMozHasAudio(aMozHasAudio); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLVIDEOELEMENT(_to) \
  NS_IMETHOD GetWidth(int32_t *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD SetWidth(int32_t aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWidth(aWidth); } \
  NS_IMETHOD GetHeight(int32_t *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_IMETHOD SetHeight(int32_t aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHeight(aHeight); } \
  NS_IMETHOD GetVideoWidth(uint32_t *aVideoWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVideoWidth(aVideoWidth); } \
  NS_IMETHOD GetVideoHeight(uint32_t *aVideoHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVideoHeight(aVideoHeight); } \
  NS_IMETHOD GetPoster(nsAString & aPoster) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPoster(aPoster); } \
  NS_IMETHOD SetPoster(const nsAString & aPoster) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPoster(aPoster); } \
  NS_IMETHOD GetMozParsedFrames(uint32_t *aMozParsedFrames) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozParsedFrames(aMozParsedFrames); } \
  NS_IMETHOD GetMozDecodedFrames(uint32_t *aMozDecodedFrames) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozDecodedFrames(aMozDecodedFrames); } \
  NS_IMETHOD GetMozPresentedFrames(uint32_t *aMozPresentedFrames) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozPresentedFrames(aMozPresentedFrames); } \
  NS_IMETHOD GetMozPaintedFrames(uint32_t *aMozPaintedFrames) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozPaintedFrames(aMozPaintedFrames); } \
  NS_IMETHOD GetMozFrameDelay(double *aMozFrameDelay) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozFrameDelay(aMozFrameDelay); } \
  NS_IMETHOD GetMozHasAudio(bool *aMozHasAudio) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozHasAudio(aMozHasAudio); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLVideoElement : public nsIDOMHTMLVideoElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLVIDEOELEMENT

  nsDOMHTMLVideoElement();

private:
  ~nsDOMHTMLVideoElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLVideoElement, nsIDOMHTMLVideoElement)

nsDOMHTMLVideoElement::nsDOMHTMLVideoElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLVideoElement::~nsDOMHTMLVideoElement()
{
  /* destructor code */
}

/* attribute long width; */
NS_IMETHODIMP nsDOMHTMLVideoElement::GetWidth(int32_t *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLVideoElement::SetWidth(int32_t aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long height; */
NS_IMETHODIMP nsDOMHTMLVideoElement::GetHeight(int32_t *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLVideoElement::SetHeight(int32_t aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long videoWidth; */
NS_IMETHODIMP nsDOMHTMLVideoElement::GetVideoWidth(uint32_t *aVideoWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long videoHeight; */
NS_IMETHODIMP nsDOMHTMLVideoElement::GetVideoHeight(uint32_t *aVideoHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString poster; */
NS_IMETHODIMP nsDOMHTMLVideoElement::GetPoster(nsAString & aPoster)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLVideoElement::SetPoster(const nsAString & aPoster)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long mozParsedFrames; */
NS_IMETHODIMP nsDOMHTMLVideoElement::GetMozParsedFrames(uint32_t *aMozParsedFrames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long mozDecodedFrames; */
NS_IMETHODIMP nsDOMHTMLVideoElement::GetMozDecodedFrames(uint32_t *aMozDecodedFrames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long mozPresentedFrames; */
NS_IMETHODIMP nsDOMHTMLVideoElement::GetMozPresentedFrames(uint32_t *aMozPresentedFrames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long mozPaintedFrames; */
NS_IMETHODIMP nsDOMHTMLVideoElement::GetMozPaintedFrames(uint32_t *aMozPaintedFrames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double mozFrameDelay; */
NS_IMETHODIMP nsDOMHTMLVideoElement::GetMozFrameDelay(double *aMozFrameDelay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute bool mozHasAudio; */
NS_IMETHODIMP nsDOMHTMLVideoElement::GetMozHasAudio(bool *aMozHasAudio)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLVideoElement_h__ */

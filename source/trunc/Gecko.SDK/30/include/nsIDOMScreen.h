/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMScreen.idl
 */

#ifndef __gen_nsIDOMScreen_h__
#define __gen_nsIDOMScreen_h__


#ifndef __gen_nsIDOMEventTarget_h__
#include "nsIDOMEventTarget.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMScreen */
#define NS_IDOMSCREEN_IID_STR "e732649a-4f78-4ded-abe1-dbdc36fd59d3"

#define NS_IDOMSCREEN_IID \
  {0xe732649a, 0x4f78, 0x4ded, \
    { 0xab, 0xe1, 0xdb, 0xdc, 0x36, 0xfd, 0x59, 0xd3 }}

class NS_NO_VTABLE nsIDOMScreen : public nsIDOMEventTarget {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSCREEN_IID)

  /* readonly attribute long top; */
  NS_IMETHOD GetTop(int32_t *aTop) = 0;

  /* readonly attribute long left; */
  NS_IMETHOD GetLeft(int32_t *aLeft) = 0;

  /* readonly attribute long width; */
  NS_IMETHOD GetWidth(int32_t *aWidth) = 0;

  /* readonly attribute long height; */
  NS_IMETHOD GetHeight(int32_t *aHeight) = 0;

  /* readonly attribute long pixelDepth; */
  NS_IMETHOD GetPixelDepth(int32_t *aPixelDepth) = 0;

  /* readonly attribute long colorDepth; */
  NS_IMETHOD GetColorDepth(int32_t *aColorDepth) = 0;

  /* readonly attribute long availWidth; */
  NS_IMETHOD GetAvailWidth(int32_t *aAvailWidth) = 0;

  /* readonly attribute long availHeight; */
  NS_IMETHOD GetAvailHeight(int32_t *aAvailHeight) = 0;

  /* readonly attribute long availLeft; */
  NS_IMETHOD GetAvailLeft(int32_t *aAvailLeft) = 0;

  /* readonly attribute long availTop; */
  NS_IMETHOD GetAvailTop(int32_t *aAvailTop) = 0;

  /* [binaryname(SlowMozOrientation)] readonly attribute DOMString mozOrientation; */
  NS_IMETHOD GetSlowMozOrientation(nsAString & aMozOrientation) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMScreen, NS_IDOMSCREEN_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSCREEN \
  NS_IMETHOD GetTop(int32_t *aTop); \
  NS_IMETHOD GetLeft(int32_t *aLeft); \
  NS_IMETHOD GetWidth(int32_t *aWidth); \
  NS_IMETHOD GetHeight(int32_t *aHeight); \
  NS_IMETHOD GetPixelDepth(int32_t *aPixelDepth); \
  NS_IMETHOD GetColorDepth(int32_t *aColorDepth); \
  NS_IMETHOD GetAvailWidth(int32_t *aAvailWidth); \
  NS_IMETHOD GetAvailHeight(int32_t *aAvailHeight); \
  NS_IMETHOD GetAvailLeft(int32_t *aAvailLeft); \
  NS_IMETHOD GetAvailTop(int32_t *aAvailTop); \
  NS_IMETHOD GetSlowMozOrientation(nsAString & aMozOrientation); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSCREEN(_to) \
  NS_IMETHOD GetTop(int32_t *aTop) { return _to GetTop(aTop); } \
  NS_IMETHOD GetLeft(int32_t *aLeft) { return _to GetLeft(aLeft); } \
  NS_IMETHOD GetWidth(int32_t *aWidth) { return _to GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(int32_t *aHeight) { return _to GetHeight(aHeight); } \
  NS_IMETHOD GetPixelDepth(int32_t *aPixelDepth) { return _to GetPixelDepth(aPixelDepth); } \
  NS_IMETHOD GetColorDepth(int32_t *aColorDepth) { return _to GetColorDepth(aColorDepth); } \
  NS_IMETHOD GetAvailWidth(int32_t *aAvailWidth) { return _to GetAvailWidth(aAvailWidth); } \
  NS_IMETHOD GetAvailHeight(int32_t *aAvailHeight) { return _to GetAvailHeight(aAvailHeight); } \
  NS_IMETHOD GetAvailLeft(int32_t *aAvailLeft) { return _to GetAvailLeft(aAvailLeft); } \
  NS_IMETHOD GetAvailTop(int32_t *aAvailTop) { return _to GetAvailTop(aAvailTop); } \
  NS_IMETHOD GetSlowMozOrientation(nsAString & aMozOrientation) { return _to GetSlowMozOrientation(aMozOrientation); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSCREEN(_to) \
  NS_IMETHOD GetTop(int32_t *aTop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTop(aTop); } \
  NS_IMETHOD GetLeft(int32_t *aLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLeft(aLeft); } \
  NS_IMETHOD GetWidth(int32_t *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(int32_t *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_IMETHOD GetPixelDepth(int32_t *aPixelDepth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPixelDepth(aPixelDepth); } \
  NS_IMETHOD GetColorDepth(int32_t *aColorDepth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColorDepth(aColorDepth); } \
  NS_IMETHOD GetAvailWidth(int32_t *aAvailWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAvailWidth(aAvailWidth); } \
  NS_IMETHOD GetAvailHeight(int32_t *aAvailHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAvailHeight(aAvailHeight); } \
  NS_IMETHOD GetAvailLeft(int32_t *aAvailLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAvailLeft(aAvailLeft); } \
  NS_IMETHOD GetAvailTop(int32_t *aAvailTop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAvailTop(aAvailTop); } \
  NS_IMETHOD GetSlowMozOrientation(nsAString & aMozOrientation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSlowMozOrientation(aMozOrientation); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMScreen : public nsIDOMScreen
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSCREEN

  nsDOMScreen();

private:
  ~nsDOMScreen();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMScreen, nsIDOMScreen)

nsDOMScreen::nsDOMScreen()
{
  /* member initializers and constructor code */
}

nsDOMScreen::~nsDOMScreen()
{
  /* destructor code */
}

/* readonly attribute long top; */
NS_IMETHODIMP nsDOMScreen::GetTop(int32_t *aTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long left; */
NS_IMETHODIMP nsDOMScreen::GetLeft(int32_t *aLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long width; */
NS_IMETHODIMP nsDOMScreen::GetWidth(int32_t *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long height; */
NS_IMETHODIMP nsDOMScreen::GetHeight(int32_t *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long pixelDepth; */
NS_IMETHODIMP nsDOMScreen::GetPixelDepth(int32_t *aPixelDepth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long colorDepth; */
NS_IMETHODIMP nsDOMScreen::GetColorDepth(int32_t *aColorDepth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long availWidth; */
NS_IMETHODIMP nsDOMScreen::GetAvailWidth(int32_t *aAvailWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long availHeight; */
NS_IMETHODIMP nsDOMScreen::GetAvailHeight(int32_t *aAvailHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long availLeft; */
NS_IMETHODIMP nsDOMScreen::GetAvailLeft(int32_t *aAvailLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long availTop; */
NS_IMETHODIMP nsDOMScreen::GetAvailTop(int32_t *aAvailTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(SlowMozOrientation)] readonly attribute DOMString mozOrientation; */
NS_IMETHODIMP nsDOMScreen::GetSlowMozOrientation(nsAString & aMozOrientation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMScreen_h__ */

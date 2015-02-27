/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/base/nsIDOMScreen.idl
 */

#ifndef __gen_nsIDOMScreen_h__
#define __gen_nsIDOMScreen_h__


#ifndef __gen_nsIDOMEventTarget_h__
#include "nsIDOMEventTarget.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMScreen */
#define NS_IDOMSCREEN_IID_STR "310a1d9a-4271-4d85-9e35-9dae6683b2c1"

#define NS_IDOMSCREEN_IID \
  {0x310a1d9a, 0x4271, 0x4d85, \
    { 0x9e, 0x35, 0x9d, 0xae, 0x66, 0x83, 0xb2, 0xc1 }}

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

  /* [implicit_jscontext] attribute jsval onmozorientationchange; */
  NS_IMETHOD GetOnmozorientationchange(JSContext* cx, JS::Value *aOnmozorientationchange) = 0;
  NS_IMETHOD SetOnmozorientationchange(JSContext* cx, const JS::Value & aOnmozorientationchange) = 0;

  /* [implicit_jscontext] boolean mozLockOrientation (in jsval orientation); */
  NS_IMETHOD MozLockOrientation(const JS::Value & orientation, JSContext* cx, bool *_retval) = 0;

  /* [binaryname(SlowMozUnlockOrientation)] void mozUnlockOrientation (); */
  NS_IMETHOD SlowMozUnlockOrientation(void) = 0;

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
  NS_IMETHOD GetSlowMozOrientation(nsAString & aMozOrientation); \
  NS_IMETHOD GetOnmozorientationchange(JSContext* cx, JS::Value *aOnmozorientationchange); \
  NS_IMETHOD SetOnmozorientationchange(JSContext* cx, const JS::Value & aOnmozorientationchange); \
  NS_IMETHOD MozLockOrientation(const JS::Value & orientation, JSContext* cx, bool *_retval); \
  NS_IMETHOD SlowMozUnlockOrientation(void); 

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
  NS_IMETHOD GetSlowMozOrientation(nsAString & aMozOrientation) { return _to GetSlowMozOrientation(aMozOrientation); } \
  NS_IMETHOD GetOnmozorientationchange(JSContext* cx, JS::Value *aOnmozorientationchange) { return _to GetOnmozorientationchange(cx, aOnmozorientationchange); } \
  NS_IMETHOD SetOnmozorientationchange(JSContext* cx, const JS::Value & aOnmozorientationchange) { return _to SetOnmozorientationchange(cx, aOnmozorientationchange); } \
  NS_IMETHOD MozLockOrientation(const JS::Value & orientation, JSContext* cx, bool *_retval) { return _to MozLockOrientation(orientation, cx, _retval); } \
  NS_IMETHOD SlowMozUnlockOrientation(void) { return _to SlowMozUnlockOrientation(); } 

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
  NS_IMETHOD GetSlowMozOrientation(nsAString & aMozOrientation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSlowMozOrientation(aMozOrientation); } \
  NS_IMETHOD GetOnmozorientationchange(JSContext* cx, JS::Value *aOnmozorientationchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmozorientationchange(cx, aOnmozorientationchange); } \
  NS_IMETHOD SetOnmozorientationchange(JSContext* cx, const JS::Value & aOnmozorientationchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmozorientationchange(cx, aOnmozorientationchange); } \
  NS_IMETHOD MozLockOrientation(const JS::Value & orientation, JSContext* cx, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozLockOrientation(orientation, cx, _retval); } \
  NS_IMETHOD SlowMozUnlockOrientation(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SlowMozUnlockOrientation(); } 

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

/* [implicit_jscontext] attribute jsval onmozorientationchange; */
NS_IMETHODIMP nsDOMScreen::GetOnmozorientationchange(JSContext* cx, JS::Value *aOnmozorientationchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMScreen::SetOnmozorientationchange(JSContext* cx, const JS::Value & aOnmozorientationchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] boolean mozLockOrientation (in jsval orientation); */
NS_IMETHODIMP nsDOMScreen::MozLockOrientation(const JS::Value & orientation, JSContext* cx, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(SlowMozUnlockOrientation)] void mozUnlockOrientation (); */
NS_IMETHODIMP nsDOMScreen::SlowMozUnlockOrientation()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMScreen_h__ */

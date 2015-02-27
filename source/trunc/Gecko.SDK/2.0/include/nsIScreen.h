/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/widget/public/nsIScreen.idl
 */

#ifndef __gen_nsIScreen_h__
#define __gen_nsIScreen_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIScreen */
#define NS_ISCREEN_IID_STR "f728830e-1dd1-11b2-9598-fb9f414f2465"

#define NS_ISCREEN_IID \
  {0xf728830e, 0x1dd1, 0x11b2, \
    { 0x95, 0x98, 0xfb, 0x9f, 0x41, 0x4f, 0x24, 0x65 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIScreen : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCREEN_IID)

  /* void GetRect (out long left, out long top, out long width, out long height); */
  NS_SCRIPTABLE NS_IMETHOD GetRect(PRInt32 *left NS_OUTPARAM, PRInt32 *top NS_OUTPARAM, PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM) = 0;

  /* void GetAvailRect (out long left, out long top, out long width, out long height); */
  NS_SCRIPTABLE NS_IMETHOD GetAvailRect(PRInt32 *left NS_OUTPARAM, PRInt32 *top NS_OUTPARAM, PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM) = 0;

  /* readonly attribute long pixelDepth; */
  NS_SCRIPTABLE NS_IMETHOD GetPixelDepth(PRInt32 *aPixelDepth) = 0;

  /* readonly attribute long colorDepth; */
  NS_SCRIPTABLE NS_IMETHOD GetColorDepth(PRInt32 *aColorDepth) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScreen, NS_ISCREEN_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCREEN \
  NS_SCRIPTABLE NS_IMETHOD GetRect(PRInt32 *left NS_OUTPARAM, PRInt32 *top NS_OUTPARAM, PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAvailRect(PRInt32 *left NS_OUTPARAM, PRInt32 *top NS_OUTPARAM, PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPixelDepth(PRInt32 *aPixelDepth); \
  NS_SCRIPTABLE NS_IMETHOD GetColorDepth(PRInt32 *aColorDepth); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCREEN(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRect(PRInt32 *left NS_OUTPARAM, PRInt32 *top NS_OUTPARAM, PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM) { return _to GetRect(left, top, width, height); } \
  NS_SCRIPTABLE NS_IMETHOD GetAvailRect(PRInt32 *left NS_OUTPARAM, PRInt32 *top NS_OUTPARAM, PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM) { return _to GetAvailRect(left, top, width, height); } \
  NS_SCRIPTABLE NS_IMETHOD GetPixelDepth(PRInt32 *aPixelDepth) { return _to GetPixelDepth(aPixelDepth); } \
  NS_SCRIPTABLE NS_IMETHOD GetColorDepth(PRInt32 *aColorDepth) { return _to GetColorDepth(aColorDepth); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCREEN(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRect(PRInt32 *left NS_OUTPARAM, PRInt32 *top NS_OUTPARAM, PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRect(left, top, width, height); } \
  NS_SCRIPTABLE NS_IMETHOD GetAvailRect(PRInt32 *left NS_OUTPARAM, PRInt32 *top NS_OUTPARAM, PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAvailRect(left, top, width, height); } \
  NS_SCRIPTABLE NS_IMETHOD GetPixelDepth(PRInt32 *aPixelDepth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPixelDepth(aPixelDepth); } \
  NS_SCRIPTABLE NS_IMETHOD GetColorDepth(PRInt32 *aColorDepth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColorDepth(aColorDepth); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScreen : public nsIScreen
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCREEN

  nsScreen();

private:
  ~nsScreen();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScreen, nsIScreen)

nsScreen::nsScreen()
{
  /* member initializers and constructor code */
}

nsScreen::~nsScreen()
{
  /* destructor code */
}

/* void GetRect (out long left, out long top, out long width, out long height); */
NS_IMETHODIMP nsScreen::GetRect(PRInt32 *left NS_OUTPARAM, PRInt32 *top NS_OUTPARAM, PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void GetAvailRect (out long left, out long top, out long width, out long height); */
NS_IMETHODIMP nsScreen::GetAvailRect(PRInt32 *left NS_OUTPARAM, PRInt32 *top NS_OUTPARAM, PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long pixelDepth; */
NS_IMETHODIMP nsScreen::GetPixelDepth(PRInt32 *aPixelDepth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long colorDepth; */
NS_IMETHODIMP nsScreen::GetColorDepth(PRInt32 *aColorDepth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIScreen_MOZILLA_2_0_BRANCH */
#define NS_ISCREEN_MOZILLA_2_0_BRANCH_IID_STR "f7c93d20-c4e4-4628-b343-cb5530b04f15"

#define NS_ISCREEN_MOZILLA_2_0_BRANCH_IID \
  {0xf7c93d20, 0xc4e4, 0x4628, \
    { 0xb3, 0x43, 0xcb, 0x55, 0x30, 0xb0, 0x4f, 0x15 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIScreen_MOZILLA_2_0_BRANCH : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCREEN_MOZILLA_2_0_BRANCH_IID)

  /**
   * Levels of brightness for the screen, from off to full brightness.
   */
  enum { BRIGHTNESS_DIM = 0U };

  enum { BRIGHTNESS_FULL = 1U };

  enum { BRIGHTNESS_LEVELS = 2U };

  /**
   * Locks the minimum brightness of the screen, forcing it to be at
   * least as bright as a certain brightness level. Each call to this
   * function must eventually be followed by a corresponding call to
   * unlockMinimumBrightness, with the same brightness level.
   *
   * @param brightness A brightness level, one of the above constants.
   */
  /* void lockMinimumBrightness (in unsigned long brightness); */
  NS_SCRIPTABLE NS_IMETHOD LockMinimumBrightness(PRUint32 brightness) = 0;

  /**
   * Releases a lock on the screen brightness. This must be called
   * (eventually) after a corresponding call to lockMinimumBrightness.
   *
   * @param brightness A brightness level, one of the above constants.
   */
  /* void unlockMinimumBrightness (in unsigned long brightness); */
  NS_SCRIPTABLE NS_IMETHOD UnlockMinimumBrightness(PRUint32 brightness) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScreen_MOZILLA_2_0_BRANCH, NS_ISCREEN_MOZILLA_2_0_BRANCH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCREEN_MOZILLA_2_0_BRANCH \
  NS_SCRIPTABLE NS_IMETHOD LockMinimumBrightness(PRUint32 brightness); \
  NS_SCRIPTABLE NS_IMETHOD UnlockMinimumBrightness(PRUint32 brightness); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCREEN_MOZILLA_2_0_BRANCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD LockMinimumBrightness(PRUint32 brightness) { return _to LockMinimumBrightness(brightness); } \
  NS_SCRIPTABLE NS_IMETHOD UnlockMinimumBrightness(PRUint32 brightness) { return _to UnlockMinimumBrightness(brightness); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCREEN_MOZILLA_2_0_BRANCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD LockMinimumBrightness(PRUint32 brightness) { return !_to ? NS_ERROR_NULL_POINTER : _to->LockMinimumBrightness(brightness); } \
  NS_SCRIPTABLE NS_IMETHOD UnlockMinimumBrightness(PRUint32 brightness) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnlockMinimumBrightness(brightness); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScreen_MOZILLA_2_0_BRANCH : public nsIScreen_MOZILLA_2_0_BRANCH
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCREEN_MOZILLA_2_0_BRANCH

  nsScreen_MOZILLA_2_0_BRANCH();

private:
  ~nsScreen_MOZILLA_2_0_BRANCH();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScreen_MOZILLA_2_0_BRANCH, nsIScreen_MOZILLA_2_0_BRANCH)

nsScreen_MOZILLA_2_0_BRANCH::nsScreen_MOZILLA_2_0_BRANCH()
{
  /* member initializers and constructor code */
}

nsScreen_MOZILLA_2_0_BRANCH::~nsScreen_MOZILLA_2_0_BRANCH()
{
  /* destructor code */
}

/* void lockMinimumBrightness (in unsigned long brightness); */
NS_IMETHODIMP nsScreen_MOZILLA_2_0_BRANCH::LockMinimumBrightness(PRUint32 brightness)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unlockMinimumBrightness (in unsigned long brightness); */
NS_IMETHODIMP nsScreen_MOZILLA_2_0_BRANCH::UnlockMinimumBrightness(PRUint32 brightness)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIScreen_h__ */

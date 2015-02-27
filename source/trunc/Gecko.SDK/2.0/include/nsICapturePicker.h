/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/layout/forms/nsICapturePicker.idl
 */

#ifndef __gen_nsICapturePicker_h__
#define __gen_nsICapturePicker_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIDOMFile; /* forward declaration */


/* starting interface:    nsICapturePicker */
#define NS_ICAPTUREPICKER_IID_STR "a4e2b2de-5712-4f80-aabb-7de3a747f227"

#define NS_ICAPTUREPICKER_IID \
  {0xa4e2b2de, 0x5712, 0x4f80, \
    { 0xaa, 0xbb, 0x7d, 0xe3, 0xa7, 0x47, 0xf2, 0x27 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsICapturePicker : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICAPTUREPICKER_IID)

  enum { MODE_STILL = 1 };

  enum { MODE_AUDIO_CLIP = 2 };

  enum { MODE_VIDEO_CLIP = 3 };

  enum { MODE_VIDEO_NO_SOUND_CLIP = 4 };

  enum { RETURN_OK = 0 };

  enum { RETURN_CANCEL = 1 };

  /**
   * Initialize the camera picker widget.  The camera picker is not valid until this
   * method is called.
   *
   * @param      parent     nsIDOMWindow parent.  This dialog will be dependent
   *                        on this parent.  This must not be null.
   * @param      title      The title for the file widget
   * @param      flags      Mode and type flags for what to capture
   *
   */
  /* void init (in nsIDOMWindow parent, in AString title, in unsigned long mode); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMWindow *parent, const nsAString & title, PRUint32 mode) = 0;

  /**
   * Show file dialog.  The dialog is displayed modally.
   *
   * @return returnOK if the user captures the requested content, returnCancel if
   *         the user cancels the capture process
   */
  /* unsigned long show (); */
  NS_SCRIPTABLE NS_IMETHOD Show(PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
   * Determine if the given mode might be available.  Consumers should take a
   * true value to be a hint of what might be available, not a guarantee.
   *
   * @param      mode       Mode to examine
   *
   * @return false if the requested mode can definitely not be captured,
   *         true otherwise.
   */
  /* boolean modeMayBeAvailable (in unsigned long mode); */
  NS_SCRIPTABLE NS_IMETHOD ModeMayBeAvailable(PRUint32 mode, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Get the captured image/video/audio.  This may be a data URI, file URI,
   * or a moz-filedata reference URI.
   */
  /* readonly attribute nsIDOMFile file; */
  NS_SCRIPTABLE NS_IMETHOD GetFile(nsIDOMFile **aFile) = 0;

  /* attribute AString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICapturePicker, NS_ICAPTUREPICKER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICAPTUREPICKER \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMWindow *parent, const nsAString & title, PRUint32 mode); \
  NS_SCRIPTABLE NS_IMETHOD Show(PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ModeMayBeAvailable(PRUint32 mode, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetFile(nsIDOMFile **aFile); \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICAPTUREPICKER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMWindow *parent, const nsAString & title, PRUint32 mode) { return _to Init(parent, title, mode); } \
  NS_SCRIPTABLE NS_IMETHOD Show(PRUint32 *_retval NS_OUTPARAM) { return _to Show(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ModeMayBeAvailable(PRUint32 mode, PRBool *_retval NS_OUTPARAM) { return _to ModeMayBeAvailable(mode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFile(nsIDOMFile **aFile) { return _to GetFile(aFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICAPTUREPICKER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMWindow *parent, const nsAString & title, PRUint32 mode) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(parent, title, mode); } \
  NS_SCRIPTABLE NS_IMETHOD Show(PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Show(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ModeMayBeAvailable(PRUint32 mode, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ModeMayBeAvailable(mode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFile(nsIDOMFile **aFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFile(aFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCapturePicker : public nsICapturePicker
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICAPTUREPICKER

  nsCapturePicker();

private:
  ~nsCapturePicker();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCapturePicker, nsICapturePicker)

nsCapturePicker::nsCapturePicker()
{
  /* member initializers and constructor code */
}

nsCapturePicker::~nsCapturePicker()
{
  /* destructor code */
}

/* void init (in nsIDOMWindow parent, in AString title, in unsigned long mode); */
NS_IMETHODIMP nsCapturePicker::Init(nsIDOMWindow *parent, const nsAString & title, PRUint32 mode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long show (); */
NS_IMETHODIMP nsCapturePicker::Show(PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean modeMayBeAvailable (in unsigned long mode); */
NS_IMETHODIMP nsCapturePicker::ModeMayBeAvailable(PRUint32 mode, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMFile file; */
NS_IMETHODIMP nsCapturePicker::GetFile(nsIDOMFile **aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString type; */
NS_IMETHODIMP nsCapturePicker::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCapturePicker::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICapturePicker_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/widget/public/nsITaskbarWindowPreview.idl
 */

#ifndef __gen_nsITaskbarWindowPreview_h__
#define __gen_nsITaskbarWindowPreview_h__


#ifndef __gen_nsITaskbarPreview_h__
#include "nsITaskbarPreview.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITaskbarPreviewButton; /* forward declaration */


/* starting interface:    nsITaskbarWindowPreview */
#define NS_ITASKBARWINDOWPREVIEW_IID_STR "ec67cc57-342d-4064-b4c6-74a375e07b10"

#define NS_ITASKBARWINDOWPREVIEW_IID \
  {0xec67cc57, 0x342d, 0x4064, \
    { 0xb4, 0xc6, 0x74, 0xa3, 0x75, 0xe0, 0x7b, 0x10 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsITaskbarWindowPreview : public nsITaskbarPreview {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITASKBARWINDOWPREVIEW_IID)

  /**
   * Max 7 buttons per preview per the Windows Taskbar API
   */
  enum { NUM_TOOLBAR_BUTTONS = 7 };

  /**
   * Gets the nth button for the preview image. By default, all of the buttons
   * are invisible.
   *
   * @see nsITaskbarPreviewButton
   *
   * @param index The index into the button array. Must be >= 0 and <
   *              MAX_TOOLBAR_BUTTONS.
   */
  /* nsITaskbarPreviewButton getButton (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD GetButton(PRUint32 index, nsITaskbarPreviewButton **_retval NS_OUTPARAM) = 0;

  /**
   * Enables/disables custom drawing of thumbnails and previews
   *
   * Default value: false
   */
  /* attribute boolean enableCustomDrawing; */
  NS_SCRIPTABLE NS_IMETHOD GetEnableCustomDrawing(PRBool *aEnableCustomDrawing) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEnableCustomDrawing(PRBool aEnableCustomDrawing) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITaskbarWindowPreview, NS_ITASKBARWINDOWPREVIEW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITASKBARWINDOWPREVIEW \
  NS_SCRIPTABLE NS_IMETHOD GetButton(PRUint32 index, nsITaskbarPreviewButton **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetEnableCustomDrawing(PRBool *aEnableCustomDrawing); \
  NS_SCRIPTABLE NS_IMETHOD SetEnableCustomDrawing(PRBool aEnableCustomDrawing); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITASKBARWINDOWPREVIEW(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetButton(PRUint32 index, nsITaskbarPreviewButton **_retval NS_OUTPARAM) { return _to GetButton(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetEnableCustomDrawing(PRBool *aEnableCustomDrawing) { return _to GetEnableCustomDrawing(aEnableCustomDrawing); } \
  NS_SCRIPTABLE NS_IMETHOD SetEnableCustomDrawing(PRBool aEnableCustomDrawing) { return _to SetEnableCustomDrawing(aEnableCustomDrawing); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITASKBARWINDOWPREVIEW(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetButton(PRUint32 index, nsITaskbarPreviewButton **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetButton(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetEnableCustomDrawing(PRBool *aEnableCustomDrawing) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnableCustomDrawing(aEnableCustomDrawing); } \
  NS_SCRIPTABLE NS_IMETHOD SetEnableCustomDrawing(PRBool aEnableCustomDrawing) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEnableCustomDrawing(aEnableCustomDrawing); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTaskbarWindowPreview : public nsITaskbarWindowPreview
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITASKBARWINDOWPREVIEW

  nsTaskbarWindowPreview();

private:
  ~nsTaskbarWindowPreview();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTaskbarWindowPreview, nsITaskbarWindowPreview)

nsTaskbarWindowPreview::nsTaskbarWindowPreview()
{
  /* member initializers and constructor code */
}

nsTaskbarWindowPreview::~nsTaskbarWindowPreview()
{
  /* destructor code */
}

/* nsITaskbarPreviewButton getButton (in unsigned long index); */
NS_IMETHODIMP nsTaskbarWindowPreview::GetButton(PRUint32 index, nsITaskbarPreviewButton **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean enableCustomDrawing; */
NS_IMETHODIMP nsTaskbarWindowPreview::GetEnableCustomDrawing(PRBool *aEnableCustomDrawing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTaskbarWindowPreview::SetEnableCustomDrawing(PRBool aEnableCustomDrawing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITaskbarWindowPreview_h__ */

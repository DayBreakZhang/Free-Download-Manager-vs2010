/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITaskbarWindowPreview.idl
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

class NS_NO_VTABLE nsITaskbarWindowPreview : public nsITaskbarPreview {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITASKBARWINDOWPREVIEW_IID)

  enum {
    NUM_TOOLBAR_BUTTONS = 7
  };

  /* nsITaskbarPreviewButton getButton (in unsigned long index); */
  NS_IMETHOD GetButton(uint32_t index, nsITaskbarPreviewButton * *_retval) = 0;

  /* attribute boolean enableCustomDrawing; */
  NS_IMETHOD GetEnableCustomDrawing(bool *aEnableCustomDrawing) = 0;
  NS_IMETHOD SetEnableCustomDrawing(bool aEnableCustomDrawing) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITaskbarWindowPreview, NS_ITASKBARWINDOWPREVIEW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITASKBARWINDOWPREVIEW \
  NS_IMETHOD GetButton(uint32_t index, nsITaskbarPreviewButton * *_retval); \
  NS_IMETHOD GetEnableCustomDrawing(bool *aEnableCustomDrawing); \
  NS_IMETHOD SetEnableCustomDrawing(bool aEnableCustomDrawing); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITASKBARWINDOWPREVIEW(_to) \
  NS_IMETHOD GetButton(uint32_t index, nsITaskbarPreviewButton * *_retval) { return _to GetButton(index, _retval); } \
  NS_IMETHOD GetEnableCustomDrawing(bool *aEnableCustomDrawing) { return _to GetEnableCustomDrawing(aEnableCustomDrawing); } \
  NS_IMETHOD SetEnableCustomDrawing(bool aEnableCustomDrawing) { return _to SetEnableCustomDrawing(aEnableCustomDrawing); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITASKBARWINDOWPREVIEW(_to) \
  NS_IMETHOD GetButton(uint32_t index, nsITaskbarPreviewButton * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetButton(index, _retval); } \
  NS_IMETHOD GetEnableCustomDrawing(bool *aEnableCustomDrawing) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnableCustomDrawing(aEnableCustomDrawing); } \
  NS_IMETHOD SetEnableCustomDrawing(bool aEnableCustomDrawing) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEnableCustomDrawing(aEnableCustomDrawing); } 

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
NS_IMETHODIMP nsTaskbarWindowPreview::GetButton(uint32_t index, nsITaskbarPreviewButton * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean enableCustomDrawing; */
NS_IMETHODIMP nsTaskbarWindowPreview::GetEnableCustomDrawing(bool *aEnableCustomDrawing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTaskbarWindowPreview::SetEnableCustomDrawing(bool aEnableCustomDrawing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITaskbarWindowPreview_h__ */

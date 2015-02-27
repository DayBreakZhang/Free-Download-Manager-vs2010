/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIEmbeddingSiteWindow.idl
 */

#ifndef __gen_nsIEmbeddingSiteWindow_h__
#define __gen_nsIEmbeddingSiteWindow_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIEmbeddingSiteWindow */
#define NS_IEMBEDDINGSITEWINDOW_IID_STR "0b976267-4aaa-4f36-a2d4-27b5ca8d73bb"

#define NS_IEMBEDDINGSITEWINDOW_IID \
  {0x0b976267, 0x4aaa, 0x4f36, \
    { 0xa2, 0xd4, 0x27, 0xb5, 0xca, 0x8d, 0x73, 0xbb }}

class NS_NO_VTABLE nsIEmbeddingSiteWindow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEMBEDDINGSITEWINDOW_IID)

  enum {
    DIM_FLAGS_POSITION = 1U,
    DIM_FLAGS_SIZE_INNER = 2U,
    DIM_FLAGS_SIZE_OUTER = 4U
  };

  /* void setDimensions (in unsigned long flags, in long x, in long y, in long cx, in long cy); */
  NS_IMETHOD SetDimensions(uint32_t flags, int32_t x, int32_t y, int32_t cx, int32_t cy) = 0;

  /* void getDimensions (in unsigned long flags, out long x, out long y, out long cx, out long cy); */
  NS_IMETHOD GetDimensions(uint32_t flags, int32_t *x, int32_t *y, int32_t *cx, int32_t *cy) = 0;

  /* void setFocus (); */
  NS_IMETHOD SetFocus(void) = 0;

  /* attribute boolean visibility; */
  NS_IMETHOD GetVisibility(bool *aVisibility) = 0;
  NS_IMETHOD SetVisibility(bool aVisibility) = 0;

  /* attribute wstring title; */
  NS_IMETHOD GetTitle(char16_t * *aTitle) = 0;
  NS_IMETHOD SetTitle(const char16_t * aTitle) = 0;

  /* [noscript] readonly attribute voidPtr siteWindow; */
  NS_IMETHOD GetSiteWindow(void **aSiteWindow) = 0;

  /* void blur (); */
  NS_IMETHOD Blur(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEmbeddingSiteWindow, NS_IEMBEDDINGSITEWINDOW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEMBEDDINGSITEWINDOW \
  NS_IMETHOD SetDimensions(uint32_t flags, int32_t x, int32_t y, int32_t cx, int32_t cy); \
  NS_IMETHOD GetDimensions(uint32_t flags, int32_t *x, int32_t *y, int32_t *cx, int32_t *cy); \
  NS_IMETHOD SetFocus(void); \
  NS_IMETHOD GetVisibility(bool *aVisibility); \
  NS_IMETHOD SetVisibility(bool aVisibility); \
  NS_IMETHOD GetTitle(char16_t * *aTitle); \
  NS_IMETHOD SetTitle(const char16_t * aTitle); \
  NS_IMETHOD GetSiteWindow(void **aSiteWindow); \
  NS_IMETHOD Blur(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEMBEDDINGSITEWINDOW(_to) \
  NS_IMETHOD SetDimensions(uint32_t flags, int32_t x, int32_t y, int32_t cx, int32_t cy) { return _to SetDimensions(flags, x, y, cx, cy); } \
  NS_IMETHOD GetDimensions(uint32_t flags, int32_t *x, int32_t *y, int32_t *cx, int32_t *cy) { return _to GetDimensions(flags, x, y, cx, cy); } \
  NS_IMETHOD SetFocus(void) { return _to SetFocus(); } \
  NS_IMETHOD GetVisibility(bool *aVisibility) { return _to GetVisibility(aVisibility); } \
  NS_IMETHOD SetVisibility(bool aVisibility) { return _to SetVisibility(aVisibility); } \
  NS_IMETHOD GetTitle(char16_t * *aTitle) { return _to GetTitle(aTitle); } \
  NS_IMETHOD SetTitle(const char16_t * aTitle) { return _to SetTitle(aTitle); } \
  NS_IMETHOD GetSiteWindow(void **aSiteWindow) { return _to GetSiteWindow(aSiteWindow); } \
  NS_IMETHOD Blur(void) { return _to Blur(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEMBEDDINGSITEWINDOW(_to) \
  NS_IMETHOD SetDimensions(uint32_t flags, int32_t x, int32_t y, int32_t cx, int32_t cy) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDimensions(flags, x, y, cx, cy); } \
  NS_IMETHOD GetDimensions(uint32_t flags, int32_t *x, int32_t *y, int32_t *cx, int32_t *cy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDimensions(flags, x, y, cx, cy); } \
  NS_IMETHOD SetFocus(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFocus(); } \
  NS_IMETHOD GetVisibility(bool *aVisibility) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisibility(aVisibility); } \
  NS_IMETHOD SetVisibility(bool aVisibility) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVisibility(aVisibility); } \
  NS_IMETHOD GetTitle(char16_t * *aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_IMETHOD SetTitle(const char16_t * aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTitle(aTitle); } \
  NS_IMETHOD GetSiteWindow(void **aSiteWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSiteWindow(aSiteWindow); } \
  NS_IMETHOD Blur(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Blur(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEmbeddingSiteWindow : public nsIEmbeddingSiteWindow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEMBEDDINGSITEWINDOW

  nsEmbeddingSiteWindow();

private:
  ~nsEmbeddingSiteWindow();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEmbeddingSiteWindow, nsIEmbeddingSiteWindow)

nsEmbeddingSiteWindow::nsEmbeddingSiteWindow()
{
  /* member initializers and constructor code */
}

nsEmbeddingSiteWindow::~nsEmbeddingSiteWindow()
{
  /* destructor code */
}

/* void setDimensions (in unsigned long flags, in long x, in long y, in long cx, in long cy); */
NS_IMETHODIMP nsEmbeddingSiteWindow::SetDimensions(uint32_t flags, int32_t x, int32_t y, int32_t cx, int32_t cy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getDimensions (in unsigned long flags, out long x, out long y, out long cx, out long cy); */
NS_IMETHODIMP nsEmbeddingSiteWindow::GetDimensions(uint32_t flags, int32_t *x, int32_t *y, int32_t *cx, int32_t *cy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFocus (); */
NS_IMETHODIMP nsEmbeddingSiteWindow::SetFocus()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean visibility; */
NS_IMETHODIMP nsEmbeddingSiteWindow::GetVisibility(bool *aVisibility)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsEmbeddingSiteWindow::SetVisibility(bool aVisibility)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring title; */
NS_IMETHODIMP nsEmbeddingSiteWindow::GetTitle(char16_t * *aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsEmbeddingSiteWindow::SetTitle(const char16_t * aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute voidPtr siteWindow; */
NS_IMETHODIMP nsEmbeddingSiteWindow::GetSiteWindow(void **aSiteWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void blur (); */
NS_IMETHODIMP nsEmbeddingSiteWindow::Blur()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEmbeddingSiteWindow_h__ */

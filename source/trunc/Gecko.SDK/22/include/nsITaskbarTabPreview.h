/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/widget/nsITaskbarTabPreview.idl
 */

#ifndef __gen_nsITaskbarTabPreview_h__
#define __gen_nsITaskbarTabPreview_h__


#ifndef __gen_nsITaskbarPreview_h__
#include "nsITaskbarPreview.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class imgIContainer; /* forward declaration */


/* starting interface:    nsITaskbarTabPreview */
#define NS_ITASKBARTABPREVIEW_IID_STR "11e4c8bd-5c2d-4e1a-a9a1-79dd5b0fe544"

#define NS_ITASKBARTABPREVIEW_IID \
  {0x11e4c8bd, 0x5c2d, 0x4e1a, \
    { 0xa9, 0xa1, 0x79, 0xdd, 0x5b, 0x0f, 0xe5, 0x44 }}

class NS_NO_VTABLE nsITaskbarTabPreview : public nsITaskbarPreview {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITASKBARTABPREVIEW_IID)

  /* attribute DOMString title; */
  NS_IMETHOD GetTitle(nsAString & aTitle) = 0;
  NS_IMETHOD SetTitle(const nsAString & aTitle) = 0;

  /* attribute imgIContainer icon; */
  NS_IMETHOD GetIcon(imgIContainer * *aIcon) = 0;
  NS_IMETHOD SetIcon(imgIContainer *aIcon) = 0;

  /* void move (in nsITaskbarTabPreview aNext); */
  NS_IMETHOD Move(nsITaskbarTabPreview *aNext) = 0;

  /* [notxpcom] nativeWindow GetHWND (); */
  NS_IMETHOD_(nativeWindow) GetHWND(void) = 0;

  /* [notxpcom] void EnsureRegistration (); */
  NS_IMETHOD_(void) EnsureRegistration(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITaskbarTabPreview, NS_ITASKBARTABPREVIEW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITASKBARTABPREVIEW \
  NS_IMETHOD GetTitle(nsAString & aTitle); \
  NS_IMETHOD SetTitle(const nsAString & aTitle); \
  NS_IMETHOD GetIcon(imgIContainer * *aIcon); \
  NS_IMETHOD SetIcon(imgIContainer *aIcon); \
  NS_IMETHOD Move(nsITaskbarTabPreview *aNext); \
  NS_IMETHOD_(nativeWindow) GetHWND(void); \
  NS_IMETHOD_(void) EnsureRegistration(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITASKBARTABPREVIEW(_to) \
  NS_IMETHOD GetTitle(nsAString & aTitle) { return _to GetTitle(aTitle); } \
  NS_IMETHOD SetTitle(const nsAString & aTitle) { return _to SetTitle(aTitle); } \
  NS_IMETHOD GetIcon(imgIContainer * *aIcon) { return _to GetIcon(aIcon); } \
  NS_IMETHOD SetIcon(imgIContainer *aIcon) { return _to SetIcon(aIcon); } \
  NS_IMETHOD Move(nsITaskbarTabPreview *aNext) { return _to Move(aNext); } \
  NS_IMETHOD_(nativeWindow) GetHWND(void) { return _to GetHWND(); } \
  NS_IMETHOD_(void) EnsureRegistration(void) { return _to EnsureRegistration(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITASKBARTABPREVIEW(_to) \
  NS_IMETHOD GetTitle(nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_IMETHOD SetTitle(const nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTitle(aTitle); } \
  NS_IMETHOD GetIcon(imgIContainer * *aIcon) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIcon(aIcon); } \
  NS_IMETHOD SetIcon(imgIContainer *aIcon) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIcon(aIcon); } \
  NS_IMETHOD Move(nsITaskbarTabPreview *aNext) { return !_to ? NS_ERROR_NULL_POINTER : _to->Move(aNext); } \
  NS_IMETHOD_(nativeWindow) GetHWND(void); \
  NS_IMETHOD_(void) EnsureRegistration(void); 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTaskbarTabPreview : public nsITaskbarTabPreview
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITASKBARTABPREVIEW

  nsTaskbarTabPreview();

private:
  ~nsTaskbarTabPreview();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTaskbarTabPreview, nsITaskbarTabPreview)

nsTaskbarTabPreview::nsTaskbarTabPreview()
{
  /* member initializers and constructor code */
}

nsTaskbarTabPreview::~nsTaskbarTabPreview()
{
  /* destructor code */
}

/* attribute DOMString title; */
NS_IMETHODIMP nsTaskbarTabPreview::GetTitle(nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTaskbarTabPreview::SetTitle(const nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute imgIContainer icon; */
NS_IMETHODIMP nsTaskbarTabPreview::GetIcon(imgIContainer * *aIcon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTaskbarTabPreview::SetIcon(imgIContainer *aIcon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void move (in nsITaskbarTabPreview aNext); */
NS_IMETHODIMP nsTaskbarTabPreview::Move(nsITaskbarTabPreview *aNext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] nativeWindow GetHWND (); */
NS_IMETHODIMP_(nativeWindow) nsTaskbarTabPreview::GetHWND()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] void EnsureRegistration (); */
NS_IMETHODIMP_(void) nsTaskbarTabPreview::EnsureRegistration()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITaskbarTabPreview_h__ */

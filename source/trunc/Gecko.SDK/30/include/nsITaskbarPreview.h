/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITaskbarPreview.idl
 */

#ifndef __gen_nsITaskbarPreview_h__
#define __gen_nsITaskbarPreview_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIBaseWindow_h__
#include "nsIBaseWindow.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITaskbarPreviewController; /* forward declaration */


/* starting interface:    nsITaskbarPreview */
#define NS_ITASKBARPREVIEW_IID_STR "cbfdf766-d002-403b-a3d9-b091c9ad465b"

#define NS_ITASKBARPREVIEW_IID \
  {0xcbfdf766, 0xd002, 0x403b, \
    { 0xa3, 0xd9, 0xb0, 0x91, 0xc9, 0xad, 0x46, 0x5b }}

class NS_NO_VTABLE nsITaskbarPreview : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITASKBARPREVIEW_IID)

  /* attribute nsITaskbarPreviewController controller; */
  NS_IMETHOD GetController(nsITaskbarPreviewController * *aController) = 0;
  NS_IMETHOD SetController(nsITaskbarPreviewController *aController) = 0;

  /* attribute DOMString tooltip; */
  NS_IMETHOD GetTooltip(nsAString & aTooltip) = 0;
  NS_IMETHOD SetTooltip(const nsAString & aTooltip) = 0;

  /* attribute boolean visible; */
  NS_IMETHOD GetVisible(bool *aVisible) = 0;
  NS_IMETHOD SetVisible(bool aVisible) = 0;

  /* attribute boolean active; */
  NS_IMETHOD GetActive(bool *aActive) = 0;
  NS_IMETHOD SetActive(bool aActive) = 0;

  /* void invalidate (); */
  NS_IMETHOD Invalidate(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITaskbarPreview, NS_ITASKBARPREVIEW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITASKBARPREVIEW \
  NS_IMETHOD GetController(nsITaskbarPreviewController * *aController); \
  NS_IMETHOD SetController(nsITaskbarPreviewController *aController); \
  NS_IMETHOD GetTooltip(nsAString & aTooltip); \
  NS_IMETHOD SetTooltip(const nsAString & aTooltip); \
  NS_IMETHOD GetVisible(bool *aVisible); \
  NS_IMETHOD SetVisible(bool aVisible); \
  NS_IMETHOD GetActive(bool *aActive); \
  NS_IMETHOD SetActive(bool aActive); \
  NS_IMETHOD Invalidate(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITASKBARPREVIEW(_to) \
  NS_IMETHOD GetController(nsITaskbarPreviewController * *aController) { return _to GetController(aController); } \
  NS_IMETHOD SetController(nsITaskbarPreviewController *aController) { return _to SetController(aController); } \
  NS_IMETHOD GetTooltip(nsAString & aTooltip) { return _to GetTooltip(aTooltip); } \
  NS_IMETHOD SetTooltip(const nsAString & aTooltip) { return _to SetTooltip(aTooltip); } \
  NS_IMETHOD GetVisible(bool *aVisible) { return _to GetVisible(aVisible); } \
  NS_IMETHOD SetVisible(bool aVisible) { return _to SetVisible(aVisible); } \
  NS_IMETHOD GetActive(bool *aActive) { return _to GetActive(aActive); } \
  NS_IMETHOD SetActive(bool aActive) { return _to SetActive(aActive); } \
  NS_IMETHOD Invalidate(void) { return _to Invalidate(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITASKBARPREVIEW(_to) \
  NS_IMETHOD GetController(nsITaskbarPreviewController * *aController) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetController(aController); } \
  NS_IMETHOD SetController(nsITaskbarPreviewController *aController) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetController(aController); } \
  NS_IMETHOD GetTooltip(nsAString & aTooltip) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTooltip(aTooltip); } \
  NS_IMETHOD SetTooltip(const nsAString & aTooltip) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTooltip(aTooltip); } \
  NS_IMETHOD GetVisible(bool *aVisible) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisible(aVisible); } \
  NS_IMETHOD SetVisible(bool aVisible) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVisible(aVisible); } \
  NS_IMETHOD GetActive(bool *aActive) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActive(aActive); } \
  NS_IMETHOD SetActive(bool aActive) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetActive(aActive); } \
  NS_IMETHOD Invalidate(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Invalidate(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTaskbarPreview : public nsITaskbarPreview
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITASKBARPREVIEW

  nsTaskbarPreview();

private:
  ~nsTaskbarPreview();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTaskbarPreview, nsITaskbarPreview)

nsTaskbarPreview::nsTaskbarPreview()
{
  /* member initializers and constructor code */
}

nsTaskbarPreview::~nsTaskbarPreview()
{
  /* destructor code */
}

/* attribute nsITaskbarPreviewController controller; */
NS_IMETHODIMP nsTaskbarPreview::GetController(nsITaskbarPreviewController * *aController)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTaskbarPreview::SetController(nsITaskbarPreviewController *aController)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString tooltip; */
NS_IMETHODIMP nsTaskbarPreview::GetTooltip(nsAString & aTooltip)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTaskbarPreview::SetTooltip(const nsAString & aTooltip)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean visible; */
NS_IMETHODIMP nsTaskbarPreview::GetVisible(bool *aVisible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTaskbarPreview::SetVisible(bool aVisible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean active; */
NS_IMETHODIMP nsTaskbarPreview::GetActive(bool *aActive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTaskbarPreview::SetActive(bool aActive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidate (); */
NS_IMETHODIMP nsTaskbarPreview::Invalidate()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITaskbarPreview_h__ */

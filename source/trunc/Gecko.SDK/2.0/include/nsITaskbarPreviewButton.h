/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/widget/public/nsITaskbarPreviewButton.idl
 */

#ifndef __gen_nsITaskbarPreviewButton_h__
#define __gen_nsITaskbarPreviewButton_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class imgIContainer; /* forward declaration */


/* starting interface:    nsITaskbarPreviewButton */
#define NS_ITASKBARPREVIEWBUTTON_IID_STR "ced8842d-fe37-4767-9a8e-fdfa56510c75"

#define NS_ITASKBARPREVIEWBUTTON_IID \
  {0xced8842d, 0xfe37, 0x4767, \
    { 0x9a, 0x8e, 0xfd, 0xfa, 0x56, 0x51, 0x0c, 0x75 }}

/**
 * nsITaskbarPreviewButton
 *
 * Provides access to a window preview's toolbar button's properties.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsITaskbarPreviewButton : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITASKBARPREVIEWBUTTON_IID)

  /**
   * The button's tooltip.
   *
   * Default: an empty string
   */
  /* attribute DOMString tooltip; */
  NS_SCRIPTABLE NS_IMETHOD GetTooltip(nsAString & aTooltip) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTooltip(const nsAString & aTooltip) = 0;

  /**
   * True if the array of previews should be dismissed when this button is clicked.
   *
   * Default: false
   */
  /* attribute boolean dismissOnClick; */
  NS_SCRIPTABLE NS_IMETHOD GetDismissOnClick(PRBool *aDismissOnClick) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDismissOnClick(PRBool aDismissOnClick) = 0;

  /**
   * True if the taskbar should draw a border around this button's image.
   *
   * Default: true
   */
  /* attribute boolean hasBorder; */
  NS_SCRIPTABLE NS_IMETHOD GetHasBorder(PRBool *aHasBorder) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHasBorder(PRBool aHasBorder) = 0;

  /**
   * True if the button is disabled. This is not the same as visible.
   *
   * Default: false
   */
  /* attribute boolean disabled; */
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled) = 0;

  /**
   * The icon used for the button.
   *
   * Default: null
   */
  /* attribute imgIContainer image; */
  NS_SCRIPTABLE NS_IMETHOD GetImage(imgIContainer **aImage) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetImage(imgIContainer *aImage) = 0;

  /**
   * True if the button is shown. Buttons that are invisible do not
   * participate in the layout of buttons underneath the preview.
   *
   * Default: false
   */
  /* attribute boolean visible; */
  NS_SCRIPTABLE NS_IMETHOD GetVisible(PRBool *aVisible) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetVisible(PRBool aVisible) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITaskbarPreviewButton, NS_ITASKBARPREVIEWBUTTON_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITASKBARPREVIEWBUTTON \
  NS_SCRIPTABLE NS_IMETHOD GetTooltip(nsAString & aTooltip); \
  NS_SCRIPTABLE NS_IMETHOD SetTooltip(const nsAString & aTooltip); \
  NS_SCRIPTABLE NS_IMETHOD GetDismissOnClick(PRBool *aDismissOnClick); \
  NS_SCRIPTABLE NS_IMETHOD SetDismissOnClick(PRBool aDismissOnClick); \
  NS_SCRIPTABLE NS_IMETHOD GetHasBorder(PRBool *aHasBorder); \
  NS_SCRIPTABLE NS_IMETHOD SetHasBorder(PRBool aHasBorder); \
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled); \
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled); \
  NS_SCRIPTABLE NS_IMETHOD GetImage(imgIContainer **aImage); \
  NS_SCRIPTABLE NS_IMETHOD SetImage(imgIContainer *aImage); \
  NS_SCRIPTABLE NS_IMETHOD GetVisible(PRBool *aVisible); \
  NS_SCRIPTABLE NS_IMETHOD SetVisible(PRBool aVisible); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITASKBARPREVIEWBUTTON(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTooltip(nsAString & aTooltip) { return _to GetTooltip(aTooltip); } \
  NS_SCRIPTABLE NS_IMETHOD SetTooltip(const nsAString & aTooltip) { return _to SetTooltip(aTooltip); } \
  NS_SCRIPTABLE NS_IMETHOD GetDismissOnClick(PRBool *aDismissOnClick) { return _to GetDismissOnClick(aDismissOnClick); } \
  NS_SCRIPTABLE NS_IMETHOD SetDismissOnClick(PRBool aDismissOnClick) { return _to SetDismissOnClick(aDismissOnClick); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasBorder(PRBool *aHasBorder) { return _to GetHasBorder(aHasBorder); } \
  NS_SCRIPTABLE NS_IMETHOD SetHasBorder(PRBool aHasBorder) { return _to SetHasBorder(aHasBorder); } \
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled) { return _to GetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled) { return _to SetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetImage(imgIContainer **aImage) { return _to GetImage(aImage); } \
  NS_SCRIPTABLE NS_IMETHOD SetImage(imgIContainer *aImage) { return _to SetImage(aImage); } \
  NS_SCRIPTABLE NS_IMETHOD GetVisible(PRBool *aVisible) { return _to GetVisible(aVisible); } \
  NS_SCRIPTABLE NS_IMETHOD SetVisible(PRBool aVisible) { return _to SetVisible(aVisible); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITASKBARPREVIEWBUTTON(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTooltip(nsAString & aTooltip) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTooltip(aTooltip); } \
  NS_SCRIPTABLE NS_IMETHOD SetTooltip(const nsAString & aTooltip) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTooltip(aTooltip); } \
  NS_SCRIPTABLE NS_IMETHOD GetDismissOnClick(PRBool *aDismissOnClick) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDismissOnClick(aDismissOnClick); } \
  NS_SCRIPTABLE NS_IMETHOD SetDismissOnClick(PRBool aDismissOnClick) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDismissOnClick(aDismissOnClick); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasBorder(PRBool *aHasBorder) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasBorder(aHasBorder); } \
  NS_SCRIPTABLE NS_IMETHOD SetHasBorder(PRBool aHasBorder) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHasBorder(aHasBorder); } \
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetImage(imgIContainer **aImage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImage(aImage); } \
  NS_SCRIPTABLE NS_IMETHOD SetImage(imgIContainer *aImage) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetImage(aImage); } \
  NS_SCRIPTABLE NS_IMETHOD GetVisible(PRBool *aVisible) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisible(aVisible); } \
  NS_SCRIPTABLE NS_IMETHOD SetVisible(PRBool aVisible) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVisible(aVisible); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTaskbarPreviewButton : public nsITaskbarPreviewButton
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITASKBARPREVIEWBUTTON

  nsTaskbarPreviewButton();

private:
  ~nsTaskbarPreviewButton();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTaskbarPreviewButton, nsITaskbarPreviewButton)

nsTaskbarPreviewButton::nsTaskbarPreviewButton()
{
  /* member initializers and constructor code */
}

nsTaskbarPreviewButton::~nsTaskbarPreviewButton()
{
  /* destructor code */
}

/* attribute DOMString tooltip; */
NS_IMETHODIMP nsTaskbarPreviewButton::GetTooltip(nsAString & aTooltip)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTaskbarPreviewButton::SetTooltip(const nsAString & aTooltip)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean dismissOnClick; */
NS_IMETHODIMP nsTaskbarPreviewButton::GetDismissOnClick(PRBool *aDismissOnClick)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTaskbarPreviewButton::SetDismissOnClick(PRBool aDismissOnClick)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean hasBorder; */
NS_IMETHODIMP nsTaskbarPreviewButton::GetHasBorder(PRBool *aHasBorder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTaskbarPreviewButton::SetHasBorder(PRBool aHasBorder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean disabled; */
NS_IMETHODIMP nsTaskbarPreviewButton::GetDisabled(PRBool *aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTaskbarPreviewButton::SetDisabled(PRBool aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute imgIContainer image; */
NS_IMETHODIMP nsTaskbarPreviewButton::GetImage(imgIContainer **aImage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTaskbarPreviewButton::SetImage(imgIContainer *aImage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean visible; */
NS_IMETHODIMP nsTaskbarPreviewButton::GetVisible(PRBool *aVisible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTaskbarPreviewButton::SetVisible(PRBool aVisible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITaskbarPreviewButton_h__ */

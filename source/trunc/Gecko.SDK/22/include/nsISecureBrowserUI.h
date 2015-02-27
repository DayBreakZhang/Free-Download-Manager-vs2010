/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsISecureBrowserUI.idl
 */

#ifndef __gen_nsISecureBrowserUI_h__
#define __gen_nsISecureBrowserUI_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIDocShell; /* forward declaration */


/* starting interface:    nsISecureBrowserUI */
#define NS_ISECUREBROWSERUI_IID_STR "e97e5688-add2-4a1d-acae-396d7702e382"

#define NS_ISECUREBROWSERUI_IID \
  {0xe97e5688, 0xadd2, 0x4a1d, \
    { 0xac, 0xae, 0x39, 0x6d, 0x77, 0x02, 0xe3, 0x82 }}

class NS_NO_VTABLE nsISecureBrowserUI : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISECUREBROWSERUI_IID)

  /* void init (in nsIDOMWindow window); */
  NS_IMETHOD Init(nsIDOMWindow *window) = 0;

  /* void setDocShell (in nsIDocShell docShell); */
  NS_IMETHOD SetDocShell(nsIDocShell *docShell) = 0;

  /* readonly attribute unsigned long state; */
  NS_IMETHOD GetState(uint32_t *aState) = 0;

  /* readonly attribute AString tooltipText; */
  NS_IMETHOD GetTooltipText(nsAString & aTooltipText) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISecureBrowserUI, NS_ISECUREBROWSERUI_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISECUREBROWSERUI \
  NS_IMETHOD Init(nsIDOMWindow *window); \
  NS_IMETHOD SetDocShell(nsIDocShell *docShell); \
  NS_IMETHOD GetState(uint32_t *aState); \
  NS_IMETHOD GetTooltipText(nsAString & aTooltipText); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISECUREBROWSERUI(_to) \
  NS_IMETHOD Init(nsIDOMWindow *window) { return _to Init(window); } \
  NS_IMETHOD SetDocShell(nsIDocShell *docShell) { return _to SetDocShell(docShell); } \
  NS_IMETHOD GetState(uint32_t *aState) { return _to GetState(aState); } \
  NS_IMETHOD GetTooltipText(nsAString & aTooltipText) { return _to GetTooltipText(aTooltipText); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISECUREBROWSERUI(_to) \
  NS_IMETHOD Init(nsIDOMWindow *window) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(window); } \
  NS_IMETHOD SetDocShell(nsIDocShell *docShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocShell(docShell); } \
  NS_IMETHOD GetState(uint32_t *aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_IMETHOD GetTooltipText(nsAString & aTooltipText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTooltipText(aTooltipText); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSecureBrowserUI : public nsISecureBrowserUI
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISECUREBROWSERUI

  nsSecureBrowserUI();

private:
  ~nsSecureBrowserUI();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSecureBrowserUI, nsISecureBrowserUI)

nsSecureBrowserUI::nsSecureBrowserUI()
{
  /* member initializers and constructor code */
}

nsSecureBrowserUI::~nsSecureBrowserUI()
{
  /* destructor code */
}

/* void init (in nsIDOMWindow window); */
NS_IMETHODIMP nsSecureBrowserUI::Init(nsIDOMWindow *window)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDocShell (in nsIDocShell docShell); */
NS_IMETHODIMP nsSecureBrowserUI::SetDocShell(nsIDocShell *docShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long state; */
NS_IMETHODIMP nsSecureBrowserUI::GetState(uint32_t *aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString tooltipText; */
NS_IMETHODIMP nsSecureBrowserUI::GetTooltipText(nsAString & aTooltipText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_SECURE_BROWSER_UI_CONTRACTID "@mozilla.org/secure_browser_ui;1"

#endif /* __gen_nsISecureBrowserUI_h__ */

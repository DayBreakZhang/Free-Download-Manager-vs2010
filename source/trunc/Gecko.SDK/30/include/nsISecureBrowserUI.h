/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISecureBrowserUI.idl
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
#define NS_ISECUREBROWSERUI_IID_STR "62f6c5be-ea8c-4fab-8e5c-d1580b50ec3f"

#define NS_ISECUREBROWSERUI_IID \
  {0x62f6c5be, 0xea8c, 0x4fab, \
    { 0x8e, 0x5c, 0xd1, 0x58, 0x0b, 0x50, 0xec, 0x3f }}

class NS_NO_VTABLE nsISecureBrowserUI : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISECUREBROWSERUI_IID)

  /* void init (in nsIDOMWindow window); */
  NS_IMETHOD Init(nsIDOMWindow *window) = 0;

  /* void setDocShell (in nsIDocShell docShell); */
  NS_IMETHOD SetDocShell(nsIDocShell *docShell) = 0;

  /* readonly attribute unsigned long state; */
  NS_IMETHOD GetState(uint32_t *aState) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISecureBrowserUI, NS_ISECUREBROWSERUI_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISECUREBROWSERUI \
  NS_IMETHOD Init(nsIDOMWindow *window); \
  NS_IMETHOD SetDocShell(nsIDocShell *docShell); \
  NS_IMETHOD GetState(uint32_t *aState); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISECUREBROWSERUI(_to) \
  NS_IMETHOD Init(nsIDOMWindow *window) { return _to Init(window); } \
  NS_IMETHOD SetDocShell(nsIDocShell *docShell) { return _to SetDocShell(docShell); } \
  NS_IMETHOD GetState(uint32_t *aState) { return _to GetState(aState); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISECUREBROWSERUI(_to) \
  NS_IMETHOD Init(nsIDOMWindow *window) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(window); } \
  NS_IMETHOD SetDocShell(nsIDocShell *docShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocShell(docShell); } \
  NS_IMETHOD GetState(uint32_t *aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } 

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

/* End of implementation class template. */
#endif

#define NS_SECURE_BROWSER_UI_CONTRACTID "@mozilla.org/secure_browser_ui;1"

#endif /* __gen_nsISecureBrowserUI_h__ */

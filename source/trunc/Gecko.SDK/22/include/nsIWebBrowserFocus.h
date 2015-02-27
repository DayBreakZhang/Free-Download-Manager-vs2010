/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/embedding/browser/webBrowser/nsIWebBrowserFocus.idl
 */

#ifndef __gen_nsIWebBrowserFocus_h__
#define __gen_nsIWebBrowserFocus_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIDOMElement; /* forward declaration */


/* starting interface:    nsIWebBrowserFocus */
#define NS_IWEBBROWSERFOCUS_IID_STR "9c5d3c58-1dd1-11b2-a1c9-f3699284657a"

#define NS_IWEBBROWSERFOCUS_IID \
  {0x9c5d3c58, 0x1dd1, 0x11b2, \
    { 0xa1, 0xc9, 0xf3, 0x69, 0x92, 0x84, 0x65, 0x7a }}

class NS_NO_VTABLE nsIWebBrowserFocus : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBBROWSERFOCUS_IID)

  /* void activate (); */
  NS_IMETHOD Activate(void) = 0;

  /* void deactivate (); */
  NS_IMETHOD Deactivate(void) = 0;

  /* void setFocusAtFirstElement (); */
  NS_IMETHOD SetFocusAtFirstElement(void) = 0;

  /* void setFocusAtLastElement (); */
  NS_IMETHOD SetFocusAtLastElement(void) = 0;

  /* attribute nsIDOMWindow focusedWindow; */
  NS_IMETHOD GetFocusedWindow(nsIDOMWindow * *aFocusedWindow) = 0;
  NS_IMETHOD SetFocusedWindow(nsIDOMWindow *aFocusedWindow) = 0;

  /* attribute nsIDOMElement focusedElement; */
  NS_IMETHOD GetFocusedElement(nsIDOMElement * *aFocusedElement) = 0;
  NS_IMETHOD SetFocusedElement(nsIDOMElement *aFocusedElement) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebBrowserFocus, NS_IWEBBROWSERFOCUS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBBROWSERFOCUS \
  NS_IMETHOD Activate(void); \
  NS_IMETHOD Deactivate(void); \
  NS_IMETHOD SetFocusAtFirstElement(void); \
  NS_IMETHOD SetFocusAtLastElement(void); \
  NS_IMETHOD GetFocusedWindow(nsIDOMWindow * *aFocusedWindow); \
  NS_IMETHOD SetFocusedWindow(nsIDOMWindow *aFocusedWindow); \
  NS_IMETHOD GetFocusedElement(nsIDOMElement * *aFocusedElement); \
  NS_IMETHOD SetFocusedElement(nsIDOMElement *aFocusedElement); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBBROWSERFOCUS(_to) \
  NS_IMETHOD Activate(void) { return _to Activate(); } \
  NS_IMETHOD Deactivate(void) { return _to Deactivate(); } \
  NS_IMETHOD SetFocusAtFirstElement(void) { return _to SetFocusAtFirstElement(); } \
  NS_IMETHOD SetFocusAtLastElement(void) { return _to SetFocusAtLastElement(); } \
  NS_IMETHOD GetFocusedWindow(nsIDOMWindow * *aFocusedWindow) { return _to GetFocusedWindow(aFocusedWindow); } \
  NS_IMETHOD SetFocusedWindow(nsIDOMWindow *aFocusedWindow) { return _to SetFocusedWindow(aFocusedWindow); } \
  NS_IMETHOD GetFocusedElement(nsIDOMElement * *aFocusedElement) { return _to GetFocusedElement(aFocusedElement); } \
  NS_IMETHOD SetFocusedElement(nsIDOMElement *aFocusedElement) { return _to SetFocusedElement(aFocusedElement); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBBROWSERFOCUS(_to) \
  NS_IMETHOD Activate(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Activate(); } \
  NS_IMETHOD Deactivate(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Deactivate(); } \
  NS_IMETHOD SetFocusAtFirstElement(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFocusAtFirstElement(); } \
  NS_IMETHOD SetFocusAtLastElement(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFocusAtLastElement(); } \
  NS_IMETHOD GetFocusedWindow(nsIDOMWindow * *aFocusedWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocusedWindow(aFocusedWindow); } \
  NS_IMETHOD SetFocusedWindow(nsIDOMWindow *aFocusedWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFocusedWindow(aFocusedWindow); } \
  NS_IMETHOD GetFocusedElement(nsIDOMElement * *aFocusedElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocusedElement(aFocusedElement); } \
  NS_IMETHOD SetFocusedElement(nsIDOMElement *aFocusedElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFocusedElement(aFocusedElement); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebBrowserFocus : public nsIWebBrowserFocus
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBBROWSERFOCUS

  nsWebBrowserFocus();

private:
  ~nsWebBrowserFocus();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebBrowserFocus, nsIWebBrowserFocus)

nsWebBrowserFocus::nsWebBrowserFocus()
{
  /* member initializers and constructor code */
}

nsWebBrowserFocus::~nsWebBrowserFocus()
{
  /* destructor code */
}

/* void activate (); */
NS_IMETHODIMP nsWebBrowserFocus::Activate()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deactivate (); */
NS_IMETHODIMP nsWebBrowserFocus::Deactivate()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFocusAtFirstElement (); */
NS_IMETHODIMP nsWebBrowserFocus::SetFocusAtFirstElement()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFocusAtLastElement (); */
NS_IMETHODIMP nsWebBrowserFocus::SetFocusAtLastElement()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMWindow focusedWindow; */
NS_IMETHODIMP nsWebBrowserFocus::GetFocusedWindow(nsIDOMWindow * *aFocusedWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebBrowserFocus::SetFocusedWindow(nsIDOMWindow *aFocusedWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMElement focusedElement; */
NS_IMETHODIMP nsWebBrowserFocus::GetFocusedElement(nsIDOMElement * *aFocusedElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebBrowserFocus::SetFocusedElement(nsIDOMElement *aFocusedElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebBrowserFocus_h__ */

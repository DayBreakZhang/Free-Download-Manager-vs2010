/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIWindowWatcher.idl
 */

#ifndef __gen_nsIWindowWatcher_h__
#define __gen_nsIWindowWatcher_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIObserver; /* forward declaration */

class nsIPrompt; /* forward declaration */

class nsIAuthPrompt; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */

class nsIWebBrowserChrome; /* forward declaration */

class nsIWindowCreator; /* forward declaration */


/* starting interface:    nsIWindowWatcher */
#define NS_IWINDOWWATCHER_IID_STR "67bc1691-fbaf-484a-a15b-c96212b45034"

#define NS_IWINDOWWATCHER_IID \
  {0x67bc1691, 0xfbaf, 0x484a, \
    { 0xa1, 0x5b, 0xc9, 0x62, 0x12, 0xb4, 0x50, 0x34 }}

class NS_NO_VTABLE nsIWindowWatcher : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWINDOWWATCHER_IID)

  /* nsIDOMWindow openWindow (in nsIDOMWindow aParent, in string aUrl, in string aName, in string aFeatures, in nsISupports aArguments); */
  NS_IMETHOD OpenWindow(nsIDOMWindow *aParent, const char * aUrl, const char * aName, const char * aFeatures, nsISupports *aArguments, nsIDOMWindow * *_retval) = 0;

  /* void registerNotification (in nsIObserver aObserver); */
  NS_IMETHOD RegisterNotification(nsIObserver *aObserver) = 0;

  /* void unregisterNotification (in nsIObserver aObserver); */
  NS_IMETHOD UnregisterNotification(nsIObserver *aObserver) = 0;

  /* nsISimpleEnumerator getWindowEnumerator (); */
  NS_IMETHOD GetWindowEnumerator(nsISimpleEnumerator * *_retval) = 0;

  /* nsIPrompt getNewPrompter (in nsIDOMWindow aParent); */
  NS_IMETHOD GetNewPrompter(nsIDOMWindow *aParent, nsIPrompt * *_retval) = 0;

  /* nsIAuthPrompt getNewAuthPrompter (in nsIDOMWindow aParent); */
  NS_IMETHOD GetNewAuthPrompter(nsIDOMWindow *aParent, nsIAuthPrompt * *_retval) = 0;

  /* void setWindowCreator (in nsIWindowCreator creator); */
  NS_IMETHOD SetWindowCreator(nsIWindowCreator *creator) = 0;

  /* boolean hasWindowCreator (); */
  NS_IMETHOD HasWindowCreator(bool *_retval) = 0;

  /* nsIWebBrowserChrome getChromeForWindow (in nsIDOMWindow aWindow); */
  NS_IMETHOD GetChromeForWindow(nsIDOMWindow *aWindow, nsIWebBrowserChrome * *_retval) = 0;

  /* nsIDOMWindow getWindowByName (in wstring aTargetName, in nsIDOMWindow aCurrentWindow); */
  NS_IMETHOD GetWindowByName(const char16_t * aTargetName, nsIDOMWindow *aCurrentWindow, nsIDOMWindow * *_retval) = 0;

  /* attribute nsIDOMWindow activeWindow; */
  NS_IMETHOD GetActiveWindow(nsIDOMWindow * *aActiveWindow) = 0;
  NS_IMETHOD SetActiveWindow(nsIDOMWindow *aActiveWindow) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWindowWatcher, NS_IWINDOWWATCHER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWINDOWWATCHER \
  NS_IMETHOD OpenWindow(nsIDOMWindow *aParent, const char * aUrl, const char * aName, const char * aFeatures, nsISupports *aArguments, nsIDOMWindow * *_retval); \
  NS_IMETHOD RegisterNotification(nsIObserver *aObserver); \
  NS_IMETHOD UnregisterNotification(nsIObserver *aObserver); \
  NS_IMETHOD GetWindowEnumerator(nsISimpleEnumerator * *_retval); \
  NS_IMETHOD GetNewPrompter(nsIDOMWindow *aParent, nsIPrompt * *_retval); \
  NS_IMETHOD GetNewAuthPrompter(nsIDOMWindow *aParent, nsIAuthPrompt * *_retval); \
  NS_IMETHOD SetWindowCreator(nsIWindowCreator *creator); \
  NS_IMETHOD HasWindowCreator(bool *_retval); \
  NS_IMETHOD GetChromeForWindow(nsIDOMWindow *aWindow, nsIWebBrowserChrome * *_retval); \
  NS_IMETHOD GetWindowByName(const char16_t * aTargetName, nsIDOMWindow *aCurrentWindow, nsIDOMWindow * *_retval); \
  NS_IMETHOD GetActiveWindow(nsIDOMWindow * *aActiveWindow); \
  NS_IMETHOD SetActiveWindow(nsIDOMWindow *aActiveWindow); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWINDOWWATCHER(_to) \
  NS_IMETHOD OpenWindow(nsIDOMWindow *aParent, const char * aUrl, const char * aName, const char * aFeatures, nsISupports *aArguments, nsIDOMWindow * *_retval) { return _to OpenWindow(aParent, aUrl, aName, aFeatures, aArguments, _retval); } \
  NS_IMETHOD RegisterNotification(nsIObserver *aObserver) { return _to RegisterNotification(aObserver); } \
  NS_IMETHOD UnregisterNotification(nsIObserver *aObserver) { return _to UnregisterNotification(aObserver); } \
  NS_IMETHOD GetWindowEnumerator(nsISimpleEnumerator * *_retval) { return _to GetWindowEnumerator(_retval); } \
  NS_IMETHOD GetNewPrompter(nsIDOMWindow *aParent, nsIPrompt * *_retval) { return _to GetNewPrompter(aParent, _retval); } \
  NS_IMETHOD GetNewAuthPrompter(nsIDOMWindow *aParent, nsIAuthPrompt * *_retval) { return _to GetNewAuthPrompter(aParent, _retval); } \
  NS_IMETHOD SetWindowCreator(nsIWindowCreator *creator) { return _to SetWindowCreator(creator); } \
  NS_IMETHOD HasWindowCreator(bool *_retval) { return _to HasWindowCreator(_retval); } \
  NS_IMETHOD GetChromeForWindow(nsIDOMWindow *aWindow, nsIWebBrowserChrome * *_retval) { return _to GetChromeForWindow(aWindow, _retval); } \
  NS_IMETHOD GetWindowByName(const char16_t * aTargetName, nsIDOMWindow *aCurrentWindow, nsIDOMWindow * *_retval) { return _to GetWindowByName(aTargetName, aCurrentWindow, _retval); } \
  NS_IMETHOD GetActiveWindow(nsIDOMWindow * *aActiveWindow) { return _to GetActiveWindow(aActiveWindow); } \
  NS_IMETHOD SetActiveWindow(nsIDOMWindow *aActiveWindow) { return _to SetActiveWindow(aActiveWindow); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWINDOWWATCHER(_to) \
  NS_IMETHOD OpenWindow(nsIDOMWindow *aParent, const char * aUrl, const char * aName, const char * aFeatures, nsISupports *aArguments, nsIDOMWindow * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenWindow(aParent, aUrl, aName, aFeatures, aArguments, _retval); } \
  NS_IMETHOD RegisterNotification(nsIObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterNotification(aObserver); } \
  NS_IMETHOD UnregisterNotification(nsIObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterNotification(aObserver); } \
  NS_IMETHOD GetWindowEnumerator(nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindowEnumerator(_retval); } \
  NS_IMETHOD GetNewPrompter(nsIDOMWindow *aParent, nsIPrompt * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNewPrompter(aParent, _retval); } \
  NS_IMETHOD GetNewAuthPrompter(nsIDOMWindow *aParent, nsIAuthPrompt * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNewAuthPrompter(aParent, _retval); } \
  NS_IMETHOD SetWindowCreator(nsIWindowCreator *creator) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWindowCreator(creator); } \
  NS_IMETHOD HasWindowCreator(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasWindowCreator(_retval); } \
  NS_IMETHOD GetChromeForWindow(nsIDOMWindow *aWindow, nsIWebBrowserChrome * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChromeForWindow(aWindow, _retval); } \
  NS_IMETHOD GetWindowByName(const char16_t * aTargetName, nsIDOMWindow *aCurrentWindow, nsIDOMWindow * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindowByName(aTargetName, aCurrentWindow, _retval); } \
  NS_IMETHOD GetActiveWindow(nsIDOMWindow * *aActiveWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActiveWindow(aActiveWindow); } \
  NS_IMETHOD SetActiveWindow(nsIDOMWindow *aActiveWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetActiveWindow(aActiveWindow); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWindowWatcher : public nsIWindowWatcher
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWINDOWWATCHER

  nsWindowWatcher();

private:
  ~nsWindowWatcher();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWindowWatcher, nsIWindowWatcher)

nsWindowWatcher::nsWindowWatcher()
{
  /* member initializers and constructor code */
}

nsWindowWatcher::~nsWindowWatcher()
{
  /* destructor code */
}

/* nsIDOMWindow openWindow (in nsIDOMWindow aParent, in string aUrl, in string aName, in string aFeatures, in nsISupports aArguments); */
NS_IMETHODIMP nsWindowWatcher::OpenWindow(nsIDOMWindow *aParent, const char * aUrl, const char * aName, const char * aFeatures, nsISupports *aArguments, nsIDOMWindow * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerNotification (in nsIObserver aObserver); */
NS_IMETHODIMP nsWindowWatcher::RegisterNotification(nsIObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterNotification (in nsIObserver aObserver); */
NS_IMETHODIMP nsWindowWatcher::UnregisterNotification(nsIObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator getWindowEnumerator (); */
NS_IMETHODIMP nsWindowWatcher::GetWindowEnumerator(nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrompt getNewPrompter (in nsIDOMWindow aParent); */
NS_IMETHODIMP nsWindowWatcher::GetNewPrompter(nsIDOMWindow *aParent, nsIPrompt * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAuthPrompt getNewAuthPrompter (in nsIDOMWindow aParent); */
NS_IMETHODIMP nsWindowWatcher::GetNewAuthPrompter(nsIDOMWindow *aParent, nsIAuthPrompt * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setWindowCreator (in nsIWindowCreator creator); */
NS_IMETHODIMP nsWindowWatcher::SetWindowCreator(nsIWindowCreator *creator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasWindowCreator (); */
NS_IMETHODIMP nsWindowWatcher::HasWindowCreator(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIWebBrowserChrome getChromeForWindow (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsWindowWatcher::GetChromeForWindow(nsIDOMWindow *aWindow, nsIWebBrowserChrome * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMWindow getWindowByName (in wstring aTargetName, in nsIDOMWindow aCurrentWindow); */
NS_IMETHODIMP nsWindowWatcher::GetWindowByName(const char16_t * aTargetName, nsIDOMWindow *aCurrentWindow, nsIDOMWindow * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMWindow activeWindow; */
NS_IMETHODIMP nsWindowWatcher::GetActiveWindow(nsIDOMWindow * *aActiveWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWindowWatcher::SetActiveWindow(nsIDOMWindow *aActiveWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_WINDOWWATCHER_CONTRACTID "@mozilla.org/embedcomp/window-watcher;1"

#endif /* __gen_nsIWindowWatcher_h__ */

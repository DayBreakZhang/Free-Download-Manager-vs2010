/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsPIWindowWatcher.idl
 */

#ifndef __gen_nsPIWindowWatcher_h__
#define __gen_nsPIWindowWatcher_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */

class nsIWebBrowserChrome; /* forward declaration */

class nsIDocShellTreeItem; /* forward declaration */

class nsIArray; /* forward declaration */


/* starting interface:    nsPIWindowWatcher */
#define NS_PIWINDOWWATCHER_IID_STR "00788a84-152f-4bd8-a814-fd8eb545db29"

#define NS_PIWINDOWWATCHER_IID \
  {0x00788a84, 0x152f, 0x4bd8, \
    { 0xa8, 0x14, 0xfd, 0x8e, 0xb5, 0x45, 0xdb, 0x29 }}

class NS_NO_VTABLE nsPIWindowWatcher : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PIWINDOWWATCHER_IID)

  /* void addWindow (in nsIDOMWindow aWindow, in nsIWebBrowserChrome aChrome); */
  NS_IMETHOD AddWindow(nsIDOMWindow *aWindow, nsIWebBrowserChrome *aChrome) = 0;

  /* void removeWindow (in nsIDOMWindow aWindow); */
  NS_IMETHOD RemoveWindow(nsIDOMWindow *aWindow) = 0;

  /* nsIDOMWindow openWindow2 (in nsIDOMWindow aParent, in string aUrl, in string aName, in string aFeatures, in boolean aCalledFromScript, in boolean aDialog, in boolean aNavigate, in nsISupports aArgs); */
  NS_IMETHOD OpenWindow2(nsIDOMWindow *aParent, const char * aUrl, const char * aName, const char * aFeatures, bool aCalledFromScript, bool aDialog, bool aNavigate, nsISupports *aArgs, nsIDOMWindow * *_retval) = 0;

  /* nsIDocShellTreeItem findItemWithName (in wstring aName, in nsIDocShellTreeItem aRequestor, in nsIDocShellTreeItem aOriginalRequestor); */
  NS_IMETHOD FindItemWithName(const char16_t * aName, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPIWindowWatcher, NS_PIWINDOWWATCHER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPIWINDOWWATCHER \
  NS_IMETHOD AddWindow(nsIDOMWindow *aWindow, nsIWebBrowserChrome *aChrome); \
  NS_IMETHOD RemoveWindow(nsIDOMWindow *aWindow); \
  NS_IMETHOD OpenWindow2(nsIDOMWindow *aParent, const char * aUrl, const char * aName, const char * aFeatures, bool aCalledFromScript, bool aDialog, bool aNavigate, nsISupports *aArgs, nsIDOMWindow * *_retval); \
  NS_IMETHOD FindItemWithName(const char16_t * aName, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPIWINDOWWATCHER(_to) \
  NS_IMETHOD AddWindow(nsIDOMWindow *aWindow, nsIWebBrowserChrome *aChrome) { return _to AddWindow(aWindow, aChrome); } \
  NS_IMETHOD RemoveWindow(nsIDOMWindow *aWindow) { return _to RemoveWindow(aWindow); } \
  NS_IMETHOD OpenWindow2(nsIDOMWindow *aParent, const char * aUrl, const char * aName, const char * aFeatures, bool aCalledFromScript, bool aDialog, bool aNavigate, nsISupports *aArgs, nsIDOMWindow * *_retval) { return _to OpenWindow2(aParent, aUrl, aName, aFeatures, aCalledFromScript, aDialog, aNavigate, aArgs, _retval); } \
  NS_IMETHOD FindItemWithName(const char16_t * aName, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval) { return _to FindItemWithName(aName, aRequestor, aOriginalRequestor, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPIWINDOWWATCHER(_to) \
  NS_IMETHOD AddWindow(nsIDOMWindow *aWindow, nsIWebBrowserChrome *aChrome) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddWindow(aWindow, aChrome); } \
  NS_IMETHOD RemoveWindow(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveWindow(aWindow); } \
  NS_IMETHOD OpenWindow2(nsIDOMWindow *aParent, const char * aUrl, const char * aName, const char * aFeatures, bool aCalledFromScript, bool aDialog, bool aNavigate, nsISupports *aArgs, nsIDOMWindow * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenWindow2(aParent, aUrl, aName, aFeatures, aCalledFromScript, aDialog, aNavigate, aArgs, _retval); } \
  NS_IMETHOD FindItemWithName(const char16_t * aName, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindItemWithName(aName, aRequestor, aOriginalRequestor, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPIWindowWatcher
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPIWINDOWWATCHER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, nsPIWindowWatcher)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void addWindow (in nsIDOMWindow aWindow, in nsIWebBrowserChrome aChrome); */
NS_IMETHODIMP _MYCLASS_::AddWindow(nsIDOMWindow *aWindow, nsIWebBrowserChrome *aChrome)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeWindow (in nsIDOMWindow aWindow); */
NS_IMETHODIMP _MYCLASS_::RemoveWindow(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMWindow openWindow2 (in nsIDOMWindow aParent, in string aUrl, in string aName, in string aFeatures, in boolean aCalledFromScript, in boolean aDialog, in boolean aNavigate, in nsISupports aArgs); */
NS_IMETHODIMP _MYCLASS_::OpenWindow2(nsIDOMWindow *aParent, const char * aUrl, const char * aName, const char * aFeatures, bool aCalledFromScript, bool aDialog, bool aNavigate, nsISupports *aArgs, nsIDOMWindow * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDocShellTreeItem findItemWithName (in wstring aName, in nsIDocShellTreeItem aRequestor, in nsIDocShellTreeItem aOriginalRequestor); */
NS_IMETHODIMP _MYCLASS_::FindItemWithName(const char16_t * aName, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsPIWindowWatcher_h__ */

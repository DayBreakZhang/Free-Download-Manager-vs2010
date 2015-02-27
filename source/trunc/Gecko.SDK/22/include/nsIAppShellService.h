/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpfe/appshell/public/nsIAppShellService.idl
 */

#ifndef __gen_nsIAppShellService_h__
#define __gen_nsIAppShellService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIXULWindow; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIDOMWindow; /* forward declaration */

class nsIAppShell; /* forward declaration */

struct JSContext;

/* starting interface:    nsIAppShellService */
#define NS_IAPPSHELLSERVICE_IID_STR "5c19ab54-67bf-46d0-ac5b-21abd9050c3b"

#define NS_IAPPSHELLSERVICE_IID \
  {0x5c19ab54, 0x67bf, 0x46d0, \
    { 0xac, 0x5b, 0x21, 0xab, 0xd9, 0x05, 0x0c, 0x3b }}

class NS_NO_VTABLE nsIAppShellService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPSHELLSERVICE_IID)

  enum {
    SIZE_TO_CONTENT = -1
  };

  /* nsIXULWindow createTopLevelWindow (in nsIXULWindow aParent, in nsIURI aUrl, in uint32_t aChromeMask, in long aInitialWidth, in long aInitialHeight); */
  NS_IMETHOD CreateTopLevelWindow(nsIXULWindow *aParent, nsIURI *aUrl, uint32_t aChromeMask, int32_t aInitialWidth, int32_t aInitialHeight, nsIXULWindow * *_retval) = 0;

  /* [noscript] void createHiddenWindow (); */
  NS_IMETHOD CreateHiddenWindow(void) = 0;

  /* void destroyHiddenWindow (); */
  NS_IMETHOD DestroyHiddenWindow(void) = 0;

  /* readonly attribute nsIXULWindow hiddenWindow; */
  NS_IMETHOD GetHiddenWindow(nsIXULWindow * *aHiddenWindow) = 0;

  /* readonly attribute nsIDOMWindow hiddenDOMWindow; */
  NS_IMETHOD GetHiddenDOMWindow(nsIDOMWindow * *aHiddenDOMWindow) = 0;

  /* readonly attribute nsIXULWindow hiddenPrivateWindow; */
  NS_IMETHOD GetHiddenPrivateWindow(nsIXULWindow * *aHiddenPrivateWindow) = 0;

  /* readonly attribute nsIDOMWindow hiddenPrivateDOMWindow; */
  NS_IMETHOD GetHiddenPrivateDOMWindow(nsIDOMWindow * *aHiddenPrivateDOMWindow) = 0;

  /* [noscript] void getHiddenWindowAndJSContext (out nsIDOMWindow aHiddenDOMWindow, out JSContext aJSContext); */
  NS_IMETHOD GetHiddenWindowAndJSContext(nsIDOMWindow * *aHiddenDOMWindow, JSContext **aJSContext) = 0;

  /* readonly attribute boolean applicationProvidedHiddenWindow; */
  NS_IMETHOD GetApplicationProvidedHiddenWindow(bool *aApplicationProvidedHiddenWindow) = 0;

  /* void registerTopLevelWindow (in nsIXULWindow aWindow); */
  NS_IMETHOD RegisterTopLevelWindow(nsIXULWindow *aWindow) = 0;

  /* void unregisterTopLevelWindow (in nsIXULWindow aWindow); */
  NS_IMETHOD UnregisterTopLevelWindow(nsIXULWindow *aWindow) = 0;

  /* [noscript] readonly attribute boolean hasHiddenPrivateWindow; */
  NS_IMETHOD GetHasHiddenPrivateWindow(bool *aHasHiddenPrivateWindow) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAppShellService, NS_IAPPSHELLSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPSHELLSERVICE \
  NS_IMETHOD CreateTopLevelWindow(nsIXULWindow *aParent, nsIURI *aUrl, uint32_t aChromeMask, int32_t aInitialWidth, int32_t aInitialHeight, nsIXULWindow * *_retval); \
  NS_IMETHOD CreateHiddenWindow(void); \
  NS_IMETHOD DestroyHiddenWindow(void); \
  NS_IMETHOD GetHiddenWindow(nsIXULWindow * *aHiddenWindow); \
  NS_IMETHOD GetHiddenDOMWindow(nsIDOMWindow * *aHiddenDOMWindow); \
  NS_IMETHOD GetHiddenPrivateWindow(nsIXULWindow * *aHiddenPrivateWindow); \
  NS_IMETHOD GetHiddenPrivateDOMWindow(nsIDOMWindow * *aHiddenPrivateDOMWindow); \
  NS_IMETHOD GetHiddenWindowAndJSContext(nsIDOMWindow * *aHiddenDOMWindow, JSContext **aJSContext); \
  NS_IMETHOD GetApplicationProvidedHiddenWindow(bool *aApplicationProvidedHiddenWindow); \
  NS_IMETHOD RegisterTopLevelWindow(nsIXULWindow *aWindow); \
  NS_IMETHOD UnregisterTopLevelWindow(nsIXULWindow *aWindow); \
  NS_IMETHOD GetHasHiddenPrivateWindow(bool *aHasHiddenPrivateWindow); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPSHELLSERVICE(_to) \
  NS_IMETHOD CreateTopLevelWindow(nsIXULWindow *aParent, nsIURI *aUrl, uint32_t aChromeMask, int32_t aInitialWidth, int32_t aInitialHeight, nsIXULWindow * *_retval) { return _to CreateTopLevelWindow(aParent, aUrl, aChromeMask, aInitialWidth, aInitialHeight, _retval); } \
  NS_IMETHOD CreateHiddenWindow(void) { return _to CreateHiddenWindow(); } \
  NS_IMETHOD DestroyHiddenWindow(void) { return _to DestroyHiddenWindow(); } \
  NS_IMETHOD GetHiddenWindow(nsIXULWindow * *aHiddenWindow) { return _to GetHiddenWindow(aHiddenWindow); } \
  NS_IMETHOD GetHiddenDOMWindow(nsIDOMWindow * *aHiddenDOMWindow) { return _to GetHiddenDOMWindow(aHiddenDOMWindow); } \
  NS_IMETHOD GetHiddenPrivateWindow(nsIXULWindow * *aHiddenPrivateWindow) { return _to GetHiddenPrivateWindow(aHiddenPrivateWindow); } \
  NS_IMETHOD GetHiddenPrivateDOMWindow(nsIDOMWindow * *aHiddenPrivateDOMWindow) { return _to GetHiddenPrivateDOMWindow(aHiddenPrivateDOMWindow); } \
  NS_IMETHOD GetHiddenWindowAndJSContext(nsIDOMWindow * *aHiddenDOMWindow, JSContext **aJSContext) { return _to GetHiddenWindowAndJSContext(aHiddenDOMWindow, aJSContext); } \
  NS_IMETHOD GetApplicationProvidedHiddenWindow(bool *aApplicationProvidedHiddenWindow) { return _to GetApplicationProvidedHiddenWindow(aApplicationProvidedHiddenWindow); } \
  NS_IMETHOD RegisterTopLevelWindow(nsIXULWindow *aWindow) { return _to RegisterTopLevelWindow(aWindow); } \
  NS_IMETHOD UnregisterTopLevelWindow(nsIXULWindow *aWindow) { return _to UnregisterTopLevelWindow(aWindow); } \
  NS_IMETHOD GetHasHiddenPrivateWindow(bool *aHasHiddenPrivateWindow) { return _to GetHasHiddenPrivateWindow(aHasHiddenPrivateWindow); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPSHELLSERVICE(_to) \
  NS_IMETHOD CreateTopLevelWindow(nsIXULWindow *aParent, nsIURI *aUrl, uint32_t aChromeMask, int32_t aInitialWidth, int32_t aInitialHeight, nsIXULWindow * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateTopLevelWindow(aParent, aUrl, aChromeMask, aInitialWidth, aInitialHeight, _retval); } \
  NS_IMETHOD CreateHiddenWindow(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateHiddenWindow(); } \
  NS_IMETHOD DestroyHiddenWindow(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DestroyHiddenWindow(); } \
  NS_IMETHOD GetHiddenWindow(nsIXULWindow * *aHiddenWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHiddenWindow(aHiddenWindow); } \
  NS_IMETHOD GetHiddenDOMWindow(nsIDOMWindow * *aHiddenDOMWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHiddenDOMWindow(aHiddenDOMWindow); } \
  NS_IMETHOD GetHiddenPrivateWindow(nsIXULWindow * *aHiddenPrivateWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHiddenPrivateWindow(aHiddenPrivateWindow); } \
  NS_IMETHOD GetHiddenPrivateDOMWindow(nsIDOMWindow * *aHiddenPrivateDOMWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHiddenPrivateDOMWindow(aHiddenPrivateDOMWindow); } \
  NS_IMETHOD GetHiddenWindowAndJSContext(nsIDOMWindow * *aHiddenDOMWindow, JSContext **aJSContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHiddenWindowAndJSContext(aHiddenDOMWindow, aJSContext); } \
  NS_IMETHOD GetApplicationProvidedHiddenWindow(bool *aApplicationProvidedHiddenWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApplicationProvidedHiddenWindow(aApplicationProvidedHiddenWindow); } \
  NS_IMETHOD RegisterTopLevelWindow(nsIXULWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterTopLevelWindow(aWindow); } \
  NS_IMETHOD UnregisterTopLevelWindow(nsIXULWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterTopLevelWindow(aWindow); } \
  NS_IMETHOD GetHasHiddenPrivateWindow(bool *aHasHiddenPrivateWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasHiddenPrivateWindow(aHasHiddenPrivateWindow); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAppShellService : public nsIAppShellService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPSHELLSERVICE

  nsAppShellService();

private:
  ~nsAppShellService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAppShellService, nsIAppShellService)

nsAppShellService::nsAppShellService()
{
  /* member initializers and constructor code */
}

nsAppShellService::~nsAppShellService()
{
  /* destructor code */
}

/* nsIXULWindow createTopLevelWindow (in nsIXULWindow aParent, in nsIURI aUrl, in uint32_t aChromeMask, in long aInitialWidth, in long aInitialHeight); */
NS_IMETHODIMP nsAppShellService::CreateTopLevelWindow(nsIXULWindow *aParent, nsIURI *aUrl, uint32_t aChromeMask, int32_t aInitialWidth, int32_t aInitialHeight, nsIXULWindow * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void createHiddenWindow (); */
NS_IMETHODIMP nsAppShellService::CreateHiddenWindow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void destroyHiddenWindow (); */
NS_IMETHODIMP nsAppShellService::DestroyHiddenWindow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXULWindow hiddenWindow; */
NS_IMETHODIMP nsAppShellService::GetHiddenWindow(nsIXULWindow * *aHiddenWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow hiddenDOMWindow; */
NS_IMETHODIMP nsAppShellService::GetHiddenDOMWindow(nsIDOMWindow * *aHiddenDOMWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXULWindow hiddenPrivateWindow; */
NS_IMETHODIMP nsAppShellService::GetHiddenPrivateWindow(nsIXULWindow * *aHiddenPrivateWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow hiddenPrivateDOMWindow; */
NS_IMETHODIMP nsAppShellService::GetHiddenPrivateDOMWindow(nsIDOMWindow * *aHiddenPrivateDOMWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getHiddenWindowAndJSContext (out nsIDOMWindow aHiddenDOMWindow, out JSContext aJSContext); */
NS_IMETHODIMP nsAppShellService::GetHiddenWindowAndJSContext(nsIDOMWindow * *aHiddenDOMWindow, JSContext **aJSContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean applicationProvidedHiddenWindow; */
NS_IMETHODIMP nsAppShellService::GetApplicationProvidedHiddenWindow(bool *aApplicationProvidedHiddenWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerTopLevelWindow (in nsIXULWindow aWindow); */
NS_IMETHODIMP nsAppShellService::RegisterTopLevelWindow(nsIXULWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterTopLevelWindow (in nsIXULWindow aWindow); */
NS_IMETHODIMP nsAppShellService::UnregisterTopLevelWindow(nsIXULWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute boolean hasHiddenPrivateWindow; */
NS_IMETHODIMP nsAppShellService::GetHasHiddenPrivateWindow(bool *aHasHiddenPrivateWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAppShellService_h__ */

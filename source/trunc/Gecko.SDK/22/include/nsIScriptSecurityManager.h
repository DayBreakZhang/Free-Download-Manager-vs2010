/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/caps/idl/nsIScriptSecurityManager.idl
 */

#ifndef __gen_nsIScriptSecurityManager_h__
#define __gen_nsIScriptSecurityManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIPrincipal_h__
#include "nsIPrincipal.h"
#endif

#ifndef __gen_nsIXPCSecurityManager_h__
#include "nsIXPCSecurityManager.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsIDocShell; /* forward declaration */


/* starting interface:    nsIScriptSecurityManager */
#define NS_ISCRIPTSECURITYMANAGER_IID_STR "ae486501-ec57-4ec8-a565-6880ca4ae6c4"

#define NS_ISCRIPTSECURITYMANAGER_IID \
  {0xae486501, 0xec57, 0x4ec8, \
    { 0xa5, 0x65, 0x68, 0x80, 0xca, 0x4a, 0xe6, 0xc4 }}

class NS_NO_VTABLE nsIScriptSecurityManager : public nsIXPCSecurityManager {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTSECURITYMANAGER_IID)

  /* [noscript] void checkPropertyAccess (in JSContextPtr aJSContext, in JSObjectPtr aJSObject, in string aClassName, in jsid aProperty, in uint32_t aAction); */
  NS_IMETHOD CheckPropertyAccess(JSContext *aJSContext, JSObject *aJSObject, const char * aClassName, jsid aProperty, uint32_t aAction) = 0;

  /* [noscript] void checkLoadURIFromScript (in JSContextPtr cx, in nsIURI uri); */
  NS_IMETHOD CheckLoadURIFromScript(JSContext *cx, nsIURI *uri) = 0;

  enum {
    STANDARD = 0U,
    LOAD_IS_AUTOMATIC_DOCUMENT_REPLACEMENT = 1U,
    ALLOW_CHROME = 2U,
    DISALLOW_INHERIT_PRINCIPAL = 4U,
    DISALLOW_SCRIPT_OR_DATA = 4U,
    DISALLOW_SCRIPT = 8U,
    DONT_REPORT_ERRORS = 16U
  };

  /* void checkLoadURIWithPrincipal (in nsIPrincipal aPrincipal, in nsIURI uri, in unsigned long flags); */
  NS_IMETHOD CheckLoadURIWithPrincipal(nsIPrincipal *aPrincipal, nsIURI *uri, uint32_t flags) = 0;

  /* void checkLoadURIStrWithPrincipal (in nsIPrincipal aPrincipal, in AUTF8String uri, in unsigned long flags); */
  NS_IMETHOD CheckLoadURIStrWithPrincipal(nsIPrincipal *aPrincipal, const nsACString & uri, uint32_t flags) = 0;

  /* [noscript] void checkFunctionAccess (in JSContextPtr cx, in voidPtr funObj, in voidPtr targetObj); */
  NS_IMETHOD CheckFunctionAccess(JSContext *cx, void *funObj, void *targetObj) = 0;

  /* [noscript] boolean canExecuteScripts (in JSContextPtr cx, in nsIPrincipal principal); */
  NS_IMETHOD CanExecuteScripts(JSContext *cx, nsIPrincipal *principal, bool *_retval) = 0;

  /* [noscript] nsIPrincipal getSubjectPrincipal (); */
  NS_IMETHOD GetSubjectPrincipal(nsIPrincipal * *_retval) = 0;

  /* nsIPrincipal getSystemPrincipal (); */
  NS_IMETHOD GetSystemPrincipal(nsIPrincipal * *_retval) = 0;

  /* nsIPrincipal getSimpleCodebasePrincipal (in nsIURI aURI); */
  NS_IMETHOD GetSimpleCodebasePrincipal(nsIURI *aURI, nsIPrincipal * *_retval) = 0;

  /* nsIPrincipal getAppCodebasePrincipal (in nsIURI uri, in unsigned long appId, in boolean inMozBrowser); */
  NS_IMETHOD GetAppCodebasePrincipal(nsIURI *uri, uint32_t appId, bool inMozBrowser, nsIPrincipal * *_retval) = 0;

  /* nsIPrincipal getDocShellCodebasePrincipal (in nsIURI uri, in nsIDocShell docShell); */
  NS_IMETHOD GetDocShellCodebasePrincipal(nsIURI *uri, nsIDocShell *docShell, nsIPrincipal * *_retval) = 0;

  /* nsIPrincipal getNoAppCodebasePrincipal (in nsIURI uri); */
  NS_IMETHOD GetNoAppCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval) = 0;

  /* [deprecated] nsIPrincipal getCodebasePrincipal (in nsIURI uri); */
  NS_IMETHOD GetCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval) = 0;

  /* [noscript] nsIPrincipal getObjectPrincipal (in JSContextPtr cx, in JSObjectPtr obj); */
  NS_IMETHOD GetObjectPrincipal(JSContext *cx, JSObject *obj, nsIPrincipal * *_retval) = 0;

  /* [noscript] boolean subjectPrincipalIsSystem (); */
  NS_IMETHOD SubjectPrincipalIsSystem(bool *_retval) = 0;

  /* [noscript] void checkSameOrigin (in JSContextPtr aJSContext, in nsIURI aTargetURI); */
  NS_IMETHOD CheckSameOrigin(JSContext *aJSContext, nsIURI *aTargetURI) = 0;

  /* void checkSameOriginURI (in nsIURI aSourceURI, in nsIURI aTargetURI, in boolean reportError); */
  NS_IMETHOD CheckSameOriginURI(nsIURI *aSourceURI, nsIURI *aTargetURI, bool reportError) = 0;

  /* nsIPrincipal getChannelPrincipal (in nsIChannel aChannel); */
  NS_IMETHOD GetChannelPrincipal(nsIChannel *aChannel, nsIPrincipal * *_retval) = 0;

  /* boolean isSystemPrincipal (in nsIPrincipal aPrincipal); */
  NS_IMETHOD IsSystemPrincipal(nsIPrincipal *aPrincipal, bool *_retval) = 0;

  /* [noscript,notxpcom] nsIPrincipal getCxSubjectPrincipal (in JSContextPtr cx); */
  NS_IMETHOD_(nsIPrincipal *) GetCxSubjectPrincipal(JSContext *cx) = 0;

  enum {
    NO_APP_ID = 0U,
    UNKNOWN_APP_ID = 4294967295U
  };

  /* AUTF8String getExtendedOrigin (in nsIURI uri, in unsigned long appId, in boolean inMozBrowser); */
  NS_IMETHOD GetExtendedOrigin(nsIURI *uri, uint32_t appId, bool inMozBrowser, nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptSecurityManager, NS_ISCRIPTSECURITYMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTSECURITYMANAGER \
  NS_IMETHOD CheckPropertyAccess(JSContext *aJSContext, JSObject *aJSObject, const char * aClassName, jsid aProperty, uint32_t aAction); \
  NS_IMETHOD CheckLoadURIFromScript(JSContext *cx, nsIURI *uri); \
  NS_IMETHOD CheckLoadURIWithPrincipal(nsIPrincipal *aPrincipal, nsIURI *uri, uint32_t flags); \
  NS_IMETHOD CheckLoadURIStrWithPrincipal(nsIPrincipal *aPrincipal, const nsACString & uri, uint32_t flags); \
  NS_IMETHOD CheckFunctionAccess(JSContext *cx, void *funObj, void *targetObj); \
  NS_IMETHOD CanExecuteScripts(JSContext *cx, nsIPrincipal *principal, bool *_retval); \
  NS_IMETHOD GetSubjectPrincipal(nsIPrincipal * *_retval); \
  NS_IMETHOD GetSystemPrincipal(nsIPrincipal * *_retval); \
  NS_IMETHOD GetSimpleCodebasePrincipal(nsIURI *aURI, nsIPrincipal * *_retval); \
  NS_IMETHOD GetAppCodebasePrincipal(nsIURI *uri, uint32_t appId, bool inMozBrowser, nsIPrincipal * *_retval); \
  NS_IMETHOD GetDocShellCodebasePrincipal(nsIURI *uri, nsIDocShell *docShell, nsIPrincipal * *_retval); \
  NS_IMETHOD GetNoAppCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval); \
  NS_IMETHOD GetCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval); \
  NS_IMETHOD GetObjectPrincipal(JSContext *cx, JSObject *obj, nsIPrincipal * *_retval); \
  NS_IMETHOD SubjectPrincipalIsSystem(bool *_retval); \
  NS_IMETHOD CheckSameOrigin(JSContext *aJSContext, nsIURI *aTargetURI); \
  NS_IMETHOD CheckSameOriginURI(nsIURI *aSourceURI, nsIURI *aTargetURI, bool reportError); \
  NS_IMETHOD GetChannelPrincipal(nsIChannel *aChannel, nsIPrincipal * *_retval); \
  NS_IMETHOD IsSystemPrincipal(nsIPrincipal *aPrincipal, bool *_retval); \
  NS_IMETHOD_(nsIPrincipal *) GetCxSubjectPrincipal(JSContext *cx); \
  NS_IMETHOD GetExtendedOrigin(nsIURI *uri, uint32_t appId, bool inMozBrowser, nsACString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTSECURITYMANAGER(_to) \
  NS_IMETHOD CheckPropertyAccess(JSContext *aJSContext, JSObject *aJSObject, const char * aClassName, jsid aProperty, uint32_t aAction) { return _to CheckPropertyAccess(aJSContext, aJSObject, aClassName, aProperty, aAction); } \
  NS_IMETHOD CheckLoadURIFromScript(JSContext *cx, nsIURI *uri) { return _to CheckLoadURIFromScript(cx, uri); } \
  NS_IMETHOD CheckLoadURIWithPrincipal(nsIPrincipal *aPrincipal, nsIURI *uri, uint32_t flags) { return _to CheckLoadURIWithPrincipal(aPrincipal, uri, flags); } \
  NS_IMETHOD CheckLoadURIStrWithPrincipal(nsIPrincipal *aPrincipal, const nsACString & uri, uint32_t flags) { return _to CheckLoadURIStrWithPrincipal(aPrincipal, uri, flags); } \
  NS_IMETHOD CheckFunctionAccess(JSContext *cx, void *funObj, void *targetObj) { return _to CheckFunctionAccess(cx, funObj, targetObj); } \
  NS_IMETHOD CanExecuteScripts(JSContext *cx, nsIPrincipal *principal, bool *_retval) { return _to CanExecuteScripts(cx, principal, _retval); } \
  NS_IMETHOD GetSubjectPrincipal(nsIPrincipal * *_retval) { return _to GetSubjectPrincipal(_retval); } \
  NS_IMETHOD GetSystemPrincipal(nsIPrincipal * *_retval) { return _to GetSystemPrincipal(_retval); } \
  NS_IMETHOD GetSimpleCodebasePrincipal(nsIURI *aURI, nsIPrincipal * *_retval) { return _to GetSimpleCodebasePrincipal(aURI, _retval); } \
  NS_IMETHOD GetAppCodebasePrincipal(nsIURI *uri, uint32_t appId, bool inMozBrowser, nsIPrincipal * *_retval) { return _to GetAppCodebasePrincipal(uri, appId, inMozBrowser, _retval); } \
  NS_IMETHOD GetDocShellCodebasePrincipal(nsIURI *uri, nsIDocShell *docShell, nsIPrincipal * *_retval) { return _to GetDocShellCodebasePrincipal(uri, docShell, _retval); } \
  NS_IMETHOD GetNoAppCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval) { return _to GetNoAppCodebasePrincipal(uri, _retval); } \
  NS_IMETHOD GetCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval) { return _to GetCodebasePrincipal(uri, _retval); } \
  NS_IMETHOD GetObjectPrincipal(JSContext *cx, JSObject *obj, nsIPrincipal * *_retval) { return _to GetObjectPrincipal(cx, obj, _retval); } \
  NS_IMETHOD SubjectPrincipalIsSystem(bool *_retval) { return _to SubjectPrincipalIsSystem(_retval); } \
  NS_IMETHOD CheckSameOrigin(JSContext *aJSContext, nsIURI *aTargetURI) { return _to CheckSameOrigin(aJSContext, aTargetURI); } \
  NS_IMETHOD CheckSameOriginURI(nsIURI *aSourceURI, nsIURI *aTargetURI, bool reportError) { return _to CheckSameOriginURI(aSourceURI, aTargetURI, reportError); } \
  NS_IMETHOD GetChannelPrincipal(nsIChannel *aChannel, nsIPrincipal * *_retval) { return _to GetChannelPrincipal(aChannel, _retval); } \
  NS_IMETHOD IsSystemPrincipal(nsIPrincipal *aPrincipal, bool *_retval) { return _to IsSystemPrincipal(aPrincipal, _retval); } \
  NS_IMETHOD_(nsIPrincipal *) GetCxSubjectPrincipal(JSContext *cx) { return _to GetCxSubjectPrincipal(cx); } \
  NS_IMETHOD GetExtendedOrigin(nsIURI *uri, uint32_t appId, bool inMozBrowser, nsACString & _retval) { return _to GetExtendedOrigin(uri, appId, inMozBrowser, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTSECURITYMANAGER(_to) \
  NS_IMETHOD CheckPropertyAccess(JSContext *aJSContext, JSObject *aJSObject, const char * aClassName, jsid aProperty, uint32_t aAction) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckPropertyAccess(aJSContext, aJSObject, aClassName, aProperty, aAction); } \
  NS_IMETHOD CheckLoadURIFromScript(JSContext *cx, nsIURI *uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckLoadURIFromScript(cx, uri); } \
  NS_IMETHOD CheckLoadURIWithPrincipal(nsIPrincipal *aPrincipal, nsIURI *uri, uint32_t flags) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckLoadURIWithPrincipal(aPrincipal, uri, flags); } \
  NS_IMETHOD CheckLoadURIStrWithPrincipal(nsIPrincipal *aPrincipal, const nsACString & uri, uint32_t flags) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckLoadURIStrWithPrincipal(aPrincipal, uri, flags); } \
  NS_IMETHOD CheckFunctionAccess(JSContext *cx, void *funObj, void *targetObj) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckFunctionAccess(cx, funObj, targetObj); } \
  NS_IMETHOD CanExecuteScripts(JSContext *cx, nsIPrincipal *principal, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanExecuteScripts(cx, principal, _retval); } \
  NS_IMETHOD GetSubjectPrincipal(nsIPrincipal * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSubjectPrincipal(_retval); } \
  NS_IMETHOD GetSystemPrincipal(nsIPrincipal * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSystemPrincipal(_retval); } \
  NS_IMETHOD GetSimpleCodebasePrincipal(nsIURI *aURI, nsIPrincipal * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSimpleCodebasePrincipal(aURI, _retval); } \
  NS_IMETHOD GetAppCodebasePrincipal(nsIURI *uri, uint32_t appId, bool inMozBrowser, nsIPrincipal * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppCodebasePrincipal(uri, appId, inMozBrowser, _retval); } \
  NS_IMETHOD GetDocShellCodebasePrincipal(nsIURI *uri, nsIDocShell *docShell, nsIPrincipal * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocShellCodebasePrincipal(uri, docShell, _retval); } \
  NS_IMETHOD GetNoAppCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNoAppCodebasePrincipal(uri, _retval); } \
  NS_IMETHOD GetCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCodebasePrincipal(uri, _retval); } \
  NS_IMETHOD GetObjectPrincipal(JSContext *cx, JSObject *obj, nsIPrincipal * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObjectPrincipal(cx, obj, _retval); } \
  NS_IMETHOD SubjectPrincipalIsSystem(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SubjectPrincipalIsSystem(_retval); } \
  NS_IMETHOD CheckSameOrigin(JSContext *aJSContext, nsIURI *aTargetURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckSameOrigin(aJSContext, aTargetURI); } \
  NS_IMETHOD CheckSameOriginURI(nsIURI *aSourceURI, nsIURI *aTargetURI, bool reportError) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckSameOriginURI(aSourceURI, aTargetURI, reportError); } \
  NS_IMETHOD GetChannelPrincipal(nsIChannel *aChannel, nsIPrincipal * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChannelPrincipal(aChannel, _retval); } \
  NS_IMETHOD IsSystemPrincipal(nsIPrincipal *aPrincipal, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsSystemPrincipal(aPrincipal, _retval); } \
  NS_IMETHOD_(nsIPrincipal *) GetCxSubjectPrincipal(JSContext *cx); \
  NS_IMETHOD GetExtendedOrigin(nsIURI *uri, uint32_t appId, bool inMozBrowser, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExtendedOrigin(uri, appId, inMozBrowser, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptSecurityManager : public nsIScriptSecurityManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTSECURITYMANAGER

  nsScriptSecurityManager();

private:
  ~nsScriptSecurityManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScriptSecurityManager, nsIScriptSecurityManager)

nsScriptSecurityManager::nsScriptSecurityManager()
{
  /* member initializers and constructor code */
}

nsScriptSecurityManager::~nsScriptSecurityManager()
{
  /* destructor code */
}

/* [noscript] void checkPropertyAccess (in JSContextPtr aJSContext, in JSObjectPtr aJSObject, in string aClassName, in jsid aProperty, in uint32_t aAction); */
NS_IMETHODIMP nsScriptSecurityManager::CheckPropertyAccess(JSContext *aJSContext, JSObject *aJSObject, const char * aClassName, jsid aProperty, uint32_t aAction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void checkLoadURIFromScript (in JSContextPtr cx, in nsIURI uri); */
NS_IMETHODIMP nsScriptSecurityManager::CheckLoadURIFromScript(JSContext *cx, nsIURI *uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void checkLoadURIWithPrincipal (in nsIPrincipal aPrincipal, in nsIURI uri, in unsigned long flags); */
NS_IMETHODIMP nsScriptSecurityManager::CheckLoadURIWithPrincipal(nsIPrincipal *aPrincipal, nsIURI *uri, uint32_t flags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void checkLoadURIStrWithPrincipal (in nsIPrincipal aPrincipal, in AUTF8String uri, in unsigned long flags); */
NS_IMETHODIMP nsScriptSecurityManager::CheckLoadURIStrWithPrincipal(nsIPrincipal *aPrincipal, const nsACString & uri, uint32_t flags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void checkFunctionAccess (in JSContextPtr cx, in voidPtr funObj, in voidPtr targetObj); */
NS_IMETHODIMP nsScriptSecurityManager::CheckFunctionAccess(JSContext *cx, void *funObj, void *targetObj)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] boolean canExecuteScripts (in JSContextPtr cx, in nsIPrincipal principal); */
NS_IMETHODIMP nsScriptSecurityManager::CanExecuteScripts(JSContext *cx, nsIPrincipal *principal, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIPrincipal getSubjectPrincipal (); */
NS_IMETHODIMP nsScriptSecurityManager::GetSubjectPrincipal(nsIPrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrincipal getSystemPrincipal (); */
NS_IMETHODIMP nsScriptSecurityManager::GetSystemPrincipal(nsIPrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrincipal getSimpleCodebasePrincipal (in nsIURI aURI); */
NS_IMETHODIMP nsScriptSecurityManager::GetSimpleCodebasePrincipal(nsIURI *aURI, nsIPrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrincipal getAppCodebasePrincipal (in nsIURI uri, in unsigned long appId, in boolean inMozBrowser); */
NS_IMETHODIMP nsScriptSecurityManager::GetAppCodebasePrincipal(nsIURI *uri, uint32_t appId, bool inMozBrowser, nsIPrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrincipal getDocShellCodebasePrincipal (in nsIURI uri, in nsIDocShell docShell); */
NS_IMETHODIMP nsScriptSecurityManager::GetDocShellCodebasePrincipal(nsIURI *uri, nsIDocShell *docShell, nsIPrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrincipal getNoAppCodebasePrincipal (in nsIURI uri); */
NS_IMETHODIMP nsScriptSecurityManager::GetNoAppCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [deprecated] nsIPrincipal getCodebasePrincipal (in nsIURI uri); */
NS_IMETHODIMP nsScriptSecurityManager::GetCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIPrincipal getObjectPrincipal (in JSContextPtr cx, in JSObjectPtr obj); */
NS_IMETHODIMP nsScriptSecurityManager::GetObjectPrincipal(JSContext *cx, JSObject *obj, nsIPrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] boolean subjectPrincipalIsSystem (); */
NS_IMETHODIMP nsScriptSecurityManager::SubjectPrincipalIsSystem(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void checkSameOrigin (in JSContextPtr aJSContext, in nsIURI aTargetURI); */
NS_IMETHODIMP nsScriptSecurityManager::CheckSameOrigin(JSContext *aJSContext, nsIURI *aTargetURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void checkSameOriginURI (in nsIURI aSourceURI, in nsIURI aTargetURI, in boolean reportError); */
NS_IMETHODIMP nsScriptSecurityManager::CheckSameOriginURI(nsIURI *aSourceURI, nsIURI *aTargetURI, bool reportError)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrincipal getChannelPrincipal (in nsIChannel aChannel); */
NS_IMETHODIMP nsScriptSecurityManager::GetChannelPrincipal(nsIChannel *aChannel, nsIPrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isSystemPrincipal (in nsIPrincipal aPrincipal); */
NS_IMETHODIMP nsScriptSecurityManager::IsSystemPrincipal(nsIPrincipal *aPrincipal, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] nsIPrincipal getCxSubjectPrincipal (in JSContextPtr cx); */
NS_IMETHODIMP_(nsIPrincipal *) nsScriptSecurityManager::GetCxSubjectPrincipal(JSContext *cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getExtendedOrigin (in nsIURI uri, in unsigned long appId, in boolean inMozBrowser); */
NS_IMETHODIMP nsScriptSecurityManager::GetExtendedOrigin(nsIURI *uri, uint32_t appId, bool inMozBrowser, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_SCRIPTSECURITYMANAGER_CONTRACTID "@mozilla.org/scriptsecuritymanager;1"

#endif /* __gen_nsIScriptSecurityManager_h__ */

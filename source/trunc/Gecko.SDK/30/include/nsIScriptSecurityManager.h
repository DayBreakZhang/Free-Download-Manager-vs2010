/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIScriptSecurityManager.idl
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

class nsIDomainPolicy; /* forward declaration */


/* starting interface:    nsIScriptSecurityManager */
#define NS_ISCRIPTSECURITYMANAGER_IID_STR "4c087cc3-e0cc-4ec3-88df-8d68f3023b45"

#define NS_ISCRIPTSECURITYMANAGER_IID \
  {0x4c087cc3, 0xe0cc, 0x4ec3, \
    { 0x88, 0xdf, 0x8d, 0x68, 0xf3, 0x02, 0x3b, 0x45 }}

class nsIScriptSecurityManager : public nsIXPCSecurityManager {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTSECURITYMANAGER_IID)

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

  /* [noscript,notxpcom] boolean scriptAllowed (in JSObjectPtr aGlobal); */
  NS_IMETHOD_(bool) ScriptAllowed(JSObject *aGlobal) = 0;

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

     bool IsSystemPrincipal(nsIPrincipal* aPrincipal) {
      bool isSystem = false;
      IsSystemPrincipal(aPrincipal, &isSystem);
      return isSystem;
    }
  /* [noscript,notxpcom] nsIPrincipal getCxSubjectPrincipal (in JSContextPtr cx); */
  NS_IMETHOD_(nsIPrincipal *) GetCxSubjectPrincipal(JSContext *cx) = 0;

  enum {
    NO_APP_ID = 0U,
    UNKNOWN_APP_ID = 4294967295U,
    SAFEBROWSING_APP_ID = 4294967294U
  };

  /* AUTF8String getJarPrefix (in unsigned long appId, in boolean inMozBrowser); */
  NS_IMETHOD GetJarPrefix(uint32_t appId, bool inMozBrowser, nsACString & _retval) = 0;

  /* nsIDomainPolicy activateDomainPolicy (); */
  NS_IMETHOD ActivateDomainPolicy(nsIDomainPolicy * *_retval) = 0;

  /* readonly attribute boolean domainPolicyActive; */
  NS_IMETHOD GetDomainPolicyActive(bool *aDomainPolicyActive) = 0;

  /* bool policyAllowsScript (in nsIURI aDomain); */
  NS_IMETHOD PolicyAllowsScript(nsIURI *aDomain, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptSecurityManager, NS_ISCRIPTSECURITYMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTSECURITYMANAGER \
  NS_IMETHOD CheckLoadURIFromScript(JSContext *cx, nsIURI *uri); \
  NS_IMETHOD CheckLoadURIWithPrincipal(nsIPrincipal *aPrincipal, nsIURI *uri, uint32_t flags); \
  NS_IMETHOD CheckLoadURIStrWithPrincipal(nsIPrincipal *aPrincipal, const nsACString & uri, uint32_t flags); \
  NS_IMETHOD_(bool) ScriptAllowed(JSObject *aGlobal); \
  NS_IMETHOD GetSubjectPrincipal(nsIPrincipal * *_retval); \
  NS_IMETHOD GetSystemPrincipal(nsIPrincipal * *_retval); \
  NS_IMETHOD GetSimpleCodebasePrincipal(nsIURI *aURI, nsIPrincipal * *_retval); \
  NS_IMETHOD GetAppCodebasePrincipal(nsIURI *uri, uint32_t appId, bool inMozBrowser, nsIPrincipal * *_retval); \
  NS_IMETHOD GetDocShellCodebasePrincipal(nsIURI *uri, nsIDocShell *docShell, nsIPrincipal * *_retval); \
  NS_IMETHOD GetNoAppCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval); \
  NS_IMETHOD GetCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval); \
  NS_IMETHOD SubjectPrincipalIsSystem(bool *_retval); \
  NS_IMETHOD CheckSameOrigin(JSContext *aJSContext, nsIURI *aTargetURI); \
  NS_IMETHOD CheckSameOriginURI(nsIURI *aSourceURI, nsIURI *aTargetURI, bool reportError); \
  NS_IMETHOD GetChannelPrincipal(nsIChannel *aChannel, nsIPrincipal * *_retval); \
  NS_IMETHOD IsSystemPrincipal(nsIPrincipal *aPrincipal, bool *_retval); \
  NS_IMETHOD_(nsIPrincipal *) GetCxSubjectPrincipal(JSContext *cx); \
  NS_IMETHOD GetJarPrefix(uint32_t appId, bool inMozBrowser, nsACString & _retval); \
  NS_IMETHOD ActivateDomainPolicy(nsIDomainPolicy * *_retval); \
  NS_IMETHOD GetDomainPolicyActive(bool *aDomainPolicyActive); \
  NS_IMETHOD PolicyAllowsScript(nsIURI *aDomain, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTSECURITYMANAGER(_to) \
  NS_IMETHOD CheckLoadURIFromScript(JSContext *cx, nsIURI *uri) { return _to CheckLoadURIFromScript(cx, uri); } \
  NS_IMETHOD CheckLoadURIWithPrincipal(nsIPrincipal *aPrincipal, nsIURI *uri, uint32_t flags) { return _to CheckLoadURIWithPrincipal(aPrincipal, uri, flags); } \
  NS_IMETHOD CheckLoadURIStrWithPrincipal(nsIPrincipal *aPrincipal, const nsACString & uri, uint32_t flags) { return _to CheckLoadURIStrWithPrincipal(aPrincipal, uri, flags); } \
  NS_IMETHOD_(bool) ScriptAllowed(JSObject *aGlobal) { return _to ScriptAllowed(aGlobal); } \
  NS_IMETHOD GetSubjectPrincipal(nsIPrincipal * *_retval) { return _to GetSubjectPrincipal(_retval); } \
  NS_IMETHOD GetSystemPrincipal(nsIPrincipal * *_retval) { return _to GetSystemPrincipal(_retval); } \
  NS_IMETHOD GetSimpleCodebasePrincipal(nsIURI *aURI, nsIPrincipal * *_retval) { return _to GetSimpleCodebasePrincipal(aURI, _retval); } \
  NS_IMETHOD GetAppCodebasePrincipal(nsIURI *uri, uint32_t appId, bool inMozBrowser, nsIPrincipal * *_retval) { return _to GetAppCodebasePrincipal(uri, appId, inMozBrowser, _retval); } \
  NS_IMETHOD GetDocShellCodebasePrincipal(nsIURI *uri, nsIDocShell *docShell, nsIPrincipal * *_retval) { return _to GetDocShellCodebasePrincipal(uri, docShell, _retval); } \
  NS_IMETHOD GetNoAppCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval) { return _to GetNoAppCodebasePrincipal(uri, _retval); } \
  NS_IMETHOD GetCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval) { return _to GetCodebasePrincipal(uri, _retval); } \
  NS_IMETHOD SubjectPrincipalIsSystem(bool *_retval) { return _to SubjectPrincipalIsSystem(_retval); } \
  NS_IMETHOD CheckSameOrigin(JSContext *aJSContext, nsIURI *aTargetURI) { return _to CheckSameOrigin(aJSContext, aTargetURI); } \
  NS_IMETHOD CheckSameOriginURI(nsIURI *aSourceURI, nsIURI *aTargetURI, bool reportError) { return _to CheckSameOriginURI(aSourceURI, aTargetURI, reportError); } \
  NS_IMETHOD GetChannelPrincipal(nsIChannel *aChannel, nsIPrincipal * *_retval) { return _to GetChannelPrincipal(aChannel, _retval); } \
  NS_IMETHOD IsSystemPrincipal(nsIPrincipal *aPrincipal, bool *_retval) { return _to IsSystemPrincipal(aPrincipal, _retval); } \
  NS_IMETHOD_(nsIPrincipal *) GetCxSubjectPrincipal(JSContext *cx) { return _to GetCxSubjectPrincipal(cx); } \
  NS_IMETHOD GetJarPrefix(uint32_t appId, bool inMozBrowser, nsACString & _retval) { return _to GetJarPrefix(appId, inMozBrowser, _retval); } \
  NS_IMETHOD ActivateDomainPolicy(nsIDomainPolicy * *_retval) { return _to ActivateDomainPolicy(_retval); } \
  NS_IMETHOD GetDomainPolicyActive(bool *aDomainPolicyActive) { return _to GetDomainPolicyActive(aDomainPolicyActive); } \
  NS_IMETHOD PolicyAllowsScript(nsIURI *aDomain, bool *_retval) { return _to PolicyAllowsScript(aDomain, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTSECURITYMANAGER(_to) \
  NS_IMETHOD CheckLoadURIFromScript(JSContext *cx, nsIURI *uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckLoadURIFromScript(cx, uri); } \
  NS_IMETHOD CheckLoadURIWithPrincipal(nsIPrincipal *aPrincipal, nsIURI *uri, uint32_t flags) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckLoadURIWithPrincipal(aPrincipal, uri, flags); } \
  NS_IMETHOD CheckLoadURIStrWithPrincipal(nsIPrincipal *aPrincipal, const nsACString & uri, uint32_t flags) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckLoadURIStrWithPrincipal(aPrincipal, uri, flags); } \
  NS_IMETHOD_(bool) ScriptAllowed(JSObject *aGlobal); \
  NS_IMETHOD GetSubjectPrincipal(nsIPrincipal * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSubjectPrincipal(_retval); } \
  NS_IMETHOD GetSystemPrincipal(nsIPrincipal * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSystemPrincipal(_retval); } \
  NS_IMETHOD GetSimpleCodebasePrincipal(nsIURI *aURI, nsIPrincipal * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSimpleCodebasePrincipal(aURI, _retval); } \
  NS_IMETHOD GetAppCodebasePrincipal(nsIURI *uri, uint32_t appId, bool inMozBrowser, nsIPrincipal * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppCodebasePrincipal(uri, appId, inMozBrowser, _retval); } \
  NS_IMETHOD GetDocShellCodebasePrincipal(nsIURI *uri, nsIDocShell *docShell, nsIPrincipal * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocShellCodebasePrincipal(uri, docShell, _retval); } \
  NS_IMETHOD GetNoAppCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNoAppCodebasePrincipal(uri, _retval); } \
  NS_IMETHOD GetCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCodebasePrincipal(uri, _retval); } \
  NS_IMETHOD SubjectPrincipalIsSystem(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SubjectPrincipalIsSystem(_retval); } \
  NS_IMETHOD CheckSameOrigin(JSContext *aJSContext, nsIURI *aTargetURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckSameOrigin(aJSContext, aTargetURI); } \
  NS_IMETHOD CheckSameOriginURI(nsIURI *aSourceURI, nsIURI *aTargetURI, bool reportError) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckSameOriginURI(aSourceURI, aTargetURI, reportError); } \
  NS_IMETHOD GetChannelPrincipal(nsIChannel *aChannel, nsIPrincipal * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChannelPrincipal(aChannel, _retval); } \
  NS_IMETHOD IsSystemPrincipal(nsIPrincipal *aPrincipal, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsSystemPrincipal(aPrincipal, _retval); } \
  NS_IMETHOD_(nsIPrincipal *) GetCxSubjectPrincipal(JSContext *cx); \
  NS_IMETHOD GetJarPrefix(uint32_t appId, bool inMozBrowser, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJarPrefix(appId, inMozBrowser, _retval); } \
  NS_IMETHOD ActivateDomainPolicy(nsIDomainPolicy * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ActivateDomainPolicy(_retval); } \
  NS_IMETHOD GetDomainPolicyActive(bool *aDomainPolicyActive) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomainPolicyActive(aDomainPolicyActive); } \
  NS_IMETHOD PolicyAllowsScript(nsIURI *aDomain, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->PolicyAllowsScript(aDomain, _retval); } 

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

/* [noscript,notxpcom] boolean scriptAllowed (in JSObjectPtr aGlobal); */
NS_IMETHODIMP_(bool) nsScriptSecurityManager::ScriptAllowed(JSObject *aGlobal)
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

/* AUTF8String getJarPrefix (in unsigned long appId, in boolean inMozBrowser); */
NS_IMETHODIMP nsScriptSecurityManager::GetJarPrefix(uint32_t appId, bool inMozBrowser, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDomainPolicy activateDomainPolicy (); */
NS_IMETHODIMP nsScriptSecurityManager::ActivateDomainPolicy(nsIDomainPolicy * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean domainPolicyActive; */
NS_IMETHODIMP nsScriptSecurityManager::GetDomainPolicyActive(bool *aDomainPolicyActive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool policyAllowsScript (in nsIURI aDomain); */
NS_IMETHODIMP nsScriptSecurityManager::PolicyAllowsScript(nsIURI *aDomain, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_SCRIPTSECURITYMANAGER_CONTRACTID "@mozilla.org/scriptsecuritymanager;1"

#endif /* __gen_nsIScriptSecurityManager_h__ */

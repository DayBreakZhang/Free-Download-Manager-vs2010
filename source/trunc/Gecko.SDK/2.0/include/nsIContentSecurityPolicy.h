/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/content/base/public/nsIContentSecurityPolicy.idl
 */

#ifndef __gen_nsIContentSecurityPolicy_h__
#define __gen_nsIContentSecurityPolicy_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIHttpChannel; /* forward declaration */

class nsIDocShell; /* forward declaration */


/* starting interface:    nsIContentSecurityPolicy */
#define NS_ICONTENTSECURITYPOLICY_IID_STR "ab36a2bf-cb32-4aa6-ab41-6b4e4444a221"

#define NS_ICONTENTSECURITYPOLICY_IID \
  {0xab36a2bf, 0xcb32, 0x4aa6, \
    { 0xab, 0x41, 0x6b, 0x4e, 0x44, 0x44, 0xa2, 0x21 }}

/**
 * nsIContentSecurityPolicy  
 * Describes an XPCOM component used to model an enforce CSPs.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIContentSecurityPolicy : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTSECURITYPOLICY_IID)

  /**
   * Set to true when the CSP has been read in and parsed and is ready to
   * enforce.  This is a barrier for the nsDocument so it doesn't load any
   * sub-content until either it knows that a CSP is ready or will not be used.
   */
  /* attribute boolean isInitialized; */
  NS_SCRIPTABLE NS_IMETHOD GetIsInitialized(PRBool *aIsInitialized) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetIsInitialized(PRBool aIsInitialized) = 0;

  /**
   * When set to true, content load-blocking and fail-closed are disabled: CSP
   * will ONLY send reports, and not modify behavior.
   */
  /* attribute boolean reportOnlyMode; */
  NS_SCRIPTABLE NS_IMETHOD GetReportOnlyMode(PRBool *aReportOnlyMode) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetReportOnlyMode(PRBool aReportOnlyMode) = 0;

  /**
   * A read-only string version of the policy for debugging.
   */
  /* readonly attribute AString policy; */
  NS_SCRIPTABLE NS_IMETHOD GetPolicy(nsAString & aPolicy) = 0;

  /**
   * Whether this policy allows in-page script.
   */
  /* readonly attribute boolean allowsInlineScript; */
  NS_SCRIPTABLE NS_IMETHOD GetAllowsInlineScript(PRBool *aAllowsInlineScript) = 0;

  /**
   * whether this policy allows eval and eval-like functions
   * such as setTimeout("code string", time).
   */
  /* readonly attribute boolean allowsEval; */
  NS_SCRIPTABLE NS_IMETHOD GetAllowsEval(PRBool *aAllowsEval) = 0;

  /**
   * Log policy violation on the Error Console and send a report if a report-uri
   * is present in the policy
   *
   * @param violationType
   *     one of the VIOLATION_TYPE_* constants, e.g. inline-script or eval
   * @param sourceFile
   *     name of the source file containing the violation (if available)
   * @param contentSample
   *     sample of the violating content (to aid debugging)
   * @param lineNum
   *     source line number of the violation (if available)
   */
  /* void logViolationDetails (in unsigned short violationType, in AString sourceFile, in AString scriptSample, in PRInt32 lineNum); */
  NS_SCRIPTABLE NS_IMETHOD LogViolationDetails(PRUint16 violationType, const nsAString & sourceFile, const nsAString & scriptSample, PRInt32 lineNum) = 0;

  enum { VIOLATION_TYPE_INLINE_SCRIPT = 1U };

  enum { VIOLATION_TYPE_EVAL = 2U };

  /**
   * Manually triggers violation report sending given a URI and reason.
   * The URI may be null, in which case "self" is sent.
   * @param blockedURI
   *     the URI that violated the policy
   * @param violatedDirective
   *     the directive that was violated.
   * @param scriptSample
   *     a sample of the violating inline script
   * @param lineNum
   *     source line number of the violation (if available)
   * @return 
   *     nothing.
   */
  /* void sendReports (in AString blockedURI, in AString violatedDirective, in AString scriptSample, in PRInt32 lineNum); */
  NS_SCRIPTABLE NS_IMETHOD SendReports(const nsAString & blockedURI, const nsAString & violatedDirective, const nsAString & scriptSample, PRInt32 lineNum) = 0;

  /**
   * Called after the CSP object is created to fill in the appropriate request
   * and request header information needed in case a report needs to be sent.
   */
  /* void scanRequestData (in nsIHttpChannel aChannel); */
  NS_SCRIPTABLE NS_IMETHOD ScanRequestData(nsIHttpChannel *aChannel) = 0;

  /**
   * Updates the policy currently stored in the CSP to be "refined" or
   * tightened by the one specified in the string policyString.
   */
  /* void refinePolicy (in AString policyString, in nsIURI selfURI); */
  NS_SCRIPTABLE NS_IMETHOD RefinePolicy(const nsAString & policyString, nsIURI *selfURI) = 0;

  /**
   * Verifies ancestry as permitted by the policy.
   *
   * Calls to this may trigger violation reports when queried, so
   * this value should not be cached.
   *
   * @param docShell
   *    containing the protected resource
   * @return
   *    true if the frame's ancestors are all permitted by policy
   */
  /* boolean permitsAncestry (in nsIDocShell docShell); */
  NS_SCRIPTABLE NS_IMETHOD PermitsAncestry(nsIDocShell *docShell, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Delegate method called by the service when sub-elements of the protected
   * document are being loaded.  Given a bit of information about the request,
   * decides whether or not the policy is satisfied.
   *
   * Calls to this may trigger violation reports when queried, so
   * this value should not be cached.
   */
  /* short shouldLoad (in unsigned long aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsISupports aContext, in ACString aMimeTypeGuess, in nsISupports aExtra); */
  NS_SCRIPTABLE NS_IMETHOD ShouldLoad(PRUint32 aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, PRInt16 *_retval NS_OUTPARAM) = 0;

  /**
   * Delegate method called by the service when sub-elements of the protected
   * document are being processed.  Given a bit of information about the request,
   * decides whether or not the policy is satisfied.
   */
  /* short shouldProcess (in unsigned long aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsISupports aContext, in ACString aMimeType, in nsISupports aExtra); */
  NS_SCRIPTABLE NS_IMETHOD ShouldProcess(PRUint32 aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, PRInt16 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentSecurityPolicy, NS_ICONTENTSECURITYPOLICY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTSECURITYPOLICY \
  NS_SCRIPTABLE NS_IMETHOD GetIsInitialized(PRBool *aIsInitialized); \
  NS_SCRIPTABLE NS_IMETHOD SetIsInitialized(PRBool aIsInitialized); \
  NS_SCRIPTABLE NS_IMETHOD GetReportOnlyMode(PRBool *aReportOnlyMode); \
  NS_SCRIPTABLE NS_IMETHOD SetReportOnlyMode(PRBool aReportOnlyMode); \
  NS_SCRIPTABLE NS_IMETHOD GetPolicy(nsAString & aPolicy); \
  NS_SCRIPTABLE NS_IMETHOD GetAllowsInlineScript(PRBool *aAllowsInlineScript); \
  NS_SCRIPTABLE NS_IMETHOD GetAllowsEval(PRBool *aAllowsEval); \
  NS_SCRIPTABLE NS_IMETHOD LogViolationDetails(PRUint16 violationType, const nsAString & sourceFile, const nsAString & scriptSample, PRInt32 lineNum); \
  NS_SCRIPTABLE NS_IMETHOD SendReports(const nsAString & blockedURI, const nsAString & violatedDirective, const nsAString & scriptSample, PRInt32 lineNum); \
  NS_SCRIPTABLE NS_IMETHOD ScanRequestData(nsIHttpChannel *aChannel); \
  NS_SCRIPTABLE NS_IMETHOD RefinePolicy(const nsAString & policyString, nsIURI *selfURI); \
  NS_SCRIPTABLE NS_IMETHOD PermitsAncestry(nsIDocShell *docShell, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ShouldLoad(PRUint32 aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, PRInt16 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ShouldProcess(PRUint32 aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, PRInt16 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTSECURITYPOLICY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIsInitialized(PRBool *aIsInitialized) { return _to GetIsInitialized(aIsInitialized); } \
  NS_SCRIPTABLE NS_IMETHOD SetIsInitialized(PRBool aIsInitialized) { return _to SetIsInitialized(aIsInitialized); } \
  NS_SCRIPTABLE NS_IMETHOD GetReportOnlyMode(PRBool *aReportOnlyMode) { return _to GetReportOnlyMode(aReportOnlyMode); } \
  NS_SCRIPTABLE NS_IMETHOD SetReportOnlyMode(PRBool aReportOnlyMode) { return _to SetReportOnlyMode(aReportOnlyMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetPolicy(nsAString & aPolicy) { return _to GetPolicy(aPolicy); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllowsInlineScript(PRBool *aAllowsInlineScript) { return _to GetAllowsInlineScript(aAllowsInlineScript); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllowsEval(PRBool *aAllowsEval) { return _to GetAllowsEval(aAllowsEval); } \
  NS_SCRIPTABLE NS_IMETHOD LogViolationDetails(PRUint16 violationType, const nsAString & sourceFile, const nsAString & scriptSample, PRInt32 lineNum) { return _to LogViolationDetails(violationType, sourceFile, scriptSample, lineNum); } \
  NS_SCRIPTABLE NS_IMETHOD SendReports(const nsAString & blockedURI, const nsAString & violatedDirective, const nsAString & scriptSample, PRInt32 lineNum) { return _to SendReports(blockedURI, violatedDirective, scriptSample, lineNum); } \
  NS_SCRIPTABLE NS_IMETHOD ScanRequestData(nsIHttpChannel *aChannel) { return _to ScanRequestData(aChannel); } \
  NS_SCRIPTABLE NS_IMETHOD RefinePolicy(const nsAString & policyString, nsIURI *selfURI) { return _to RefinePolicy(policyString, selfURI); } \
  NS_SCRIPTABLE NS_IMETHOD PermitsAncestry(nsIDocShell *docShell, PRBool *_retval NS_OUTPARAM) { return _to PermitsAncestry(docShell, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ShouldLoad(PRUint32 aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, PRInt16 *_retval NS_OUTPARAM) { return _to ShouldLoad(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeTypeGuess, aExtra, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ShouldProcess(PRUint32 aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, PRInt16 *_retval NS_OUTPARAM) { return _to ShouldProcess(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeType, aExtra, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTSECURITYPOLICY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIsInitialized(PRBool *aIsInitialized) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsInitialized(aIsInitialized); } \
  NS_SCRIPTABLE NS_IMETHOD SetIsInitialized(PRBool aIsInitialized) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsInitialized(aIsInitialized); } \
  NS_SCRIPTABLE NS_IMETHOD GetReportOnlyMode(PRBool *aReportOnlyMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReportOnlyMode(aReportOnlyMode); } \
  NS_SCRIPTABLE NS_IMETHOD SetReportOnlyMode(PRBool aReportOnlyMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReportOnlyMode(aReportOnlyMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetPolicy(nsAString & aPolicy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPolicy(aPolicy); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllowsInlineScript(PRBool *aAllowsInlineScript) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowsInlineScript(aAllowsInlineScript); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllowsEval(PRBool *aAllowsEval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowsEval(aAllowsEval); } \
  NS_SCRIPTABLE NS_IMETHOD LogViolationDetails(PRUint16 violationType, const nsAString & sourceFile, const nsAString & scriptSample, PRInt32 lineNum) { return !_to ? NS_ERROR_NULL_POINTER : _to->LogViolationDetails(violationType, sourceFile, scriptSample, lineNum); } \
  NS_SCRIPTABLE NS_IMETHOD SendReports(const nsAString & blockedURI, const nsAString & violatedDirective, const nsAString & scriptSample, PRInt32 lineNum) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendReports(blockedURI, violatedDirective, scriptSample, lineNum); } \
  NS_SCRIPTABLE NS_IMETHOD ScanRequestData(nsIHttpChannel *aChannel) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScanRequestData(aChannel); } \
  NS_SCRIPTABLE NS_IMETHOD RefinePolicy(const nsAString & policyString, nsIURI *selfURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->RefinePolicy(policyString, selfURI); } \
  NS_SCRIPTABLE NS_IMETHOD PermitsAncestry(nsIDocShell *docShell, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->PermitsAncestry(docShell, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ShouldLoad(PRUint32 aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, PRInt16 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShouldLoad(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeTypeGuess, aExtra, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ShouldProcess(PRUint32 aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, PRInt16 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShouldProcess(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeType, aExtra, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentSecurityPolicy : public nsIContentSecurityPolicy
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTSECURITYPOLICY

  nsContentSecurityPolicy();

private:
  ~nsContentSecurityPolicy();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentSecurityPolicy, nsIContentSecurityPolicy)

nsContentSecurityPolicy::nsContentSecurityPolicy()
{
  /* member initializers and constructor code */
}

nsContentSecurityPolicy::~nsContentSecurityPolicy()
{
  /* destructor code */
}

/* attribute boolean isInitialized; */
NS_IMETHODIMP nsContentSecurityPolicy::GetIsInitialized(PRBool *aIsInitialized)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentSecurityPolicy::SetIsInitialized(PRBool aIsInitialized)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean reportOnlyMode; */
NS_IMETHODIMP nsContentSecurityPolicy::GetReportOnlyMode(PRBool *aReportOnlyMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentSecurityPolicy::SetReportOnlyMode(PRBool aReportOnlyMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString policy; */
NS_IMETHODIMP nsContentSecurityPolicy::GetPolicy(nsAString & aPolicy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean allowsInlineScript; */
NS_IMETHODIMP nsContentSecurityPolicy::GetAllowsInlineScript(PRBool *aAllowsInlineScript)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean allowsEval; */
NS_IMETHODIMP nsContentSecurityPolicy::GetAllowsEval(PRBool *aAllowsEval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void logViolationDetails (in unsigned short violationType, in AString sourceFile, in AString scriptSample, in PRInt32 lineNum); */
NS_IMETHODIMP nsContentSecurityPolicy::LogViolationDetails(PRUint16 violationType, const nsAString & sourceFile, const nsAString & scriptSample, PRInt32 lineNum)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendReports (in AString blockedURI, in AString violatedDirective, in AString scriptSample, in PRInt32 lineNum); */
NS_IMETHODIMP nsContentSecurityPolicy::SendReports(const nsAString & blockedURI, const nsAString & violatedDirective, const nsAString & scriptSample, PRInt32 lineNum)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scanRequestData (in nsIHttpChannel aChannel); */
NS_IMETHODIMP nsContentSecurityPolicy::ScanRequestData(nsIHttpChannel *aChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void refinePolicy (in AString policyString, in nsIURI selfURI); */
NS_IMETHODIMP nsContentSecurityPolicy::RefinePolicy(const nsAString & policyString, nsIURI *selfURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean permitsAncestry (in nsIDocShell docShell); */
NS_IMETHODIMP nsContentSecurityPolicy::PermitsAncestry(nsIDocShell *docShell, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* short shouldLoad (in unsigned long aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsISupports aContext, in ACString aMimeTypeGuess, in nsISupports aExtra); */
NS_IMETHODIMP nsContentSecurityPolicy::ShouldLoad(PRUint32 aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, PRInt16 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* short shouldProcess (in unsigned long aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsISupports aContext, in ACString aMimeType, in nsISupports aExtra); */
NS_IMETHODIMP nsContentSecurityPolicy::ShouldProcess(PRUint32 aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, PRInt16 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContentSecurityPolicy_h__ */

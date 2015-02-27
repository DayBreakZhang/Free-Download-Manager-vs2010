/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/content/base/public/nsIContentSecurityPolicy.idl
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
#define NS_ICONTENTSECURITYPOLICY_IID_STR "91e1f257-914c-4d4f-902c-f67f772839ab"

#define NS_ICONTENTSECURITYPOLICY_IID \
  {0x91e1f257, 0x914c, 0x4d4f, \
    { 0x90, 0x2c, 0xf6, 0x7f, 0x77, 0x28, 0x39, 0xab }}

class NS_NO_VTABLE nsIContentSecurityPolicy : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTSECURITYPOLICY_IID)

  /* attribute boolean isInitialized; */
  NS_IMETHOD GetIsInitialized(bool *aIsInitialized) = 0;
  NS_IMETHOD SetIsInitialized(bool aIsInitialized) = 0;

  /* attribute boolean reportOnlyMode; */
  NS_IMETHOD GetReportOnlyMode(bool *aReportOnlyMode) = 0;
  NS_IMETHOD SetReportOnlyMode(bool aReportOnlyMode) = 0;

  /* readonly attribute AString policy; */
  NS_IMETHOD GetPolicy(nsAString & aPolicy) = 0;

  /* boolean getAllowsInlineScript (out boolean shouldReportViolation); */
  NS_IMETHOD GetAllowsInlineScript(bool *shouldReportViolation, bool *_retval) = 0;

  /* boolean getAllowsEval (out boolean shouldReportViolation); */
  NS_IMETHOD GetAllowsEval(bool *shouldReportViolation, bool *_retval) = 0;

  /* void logViolationDetails (in unsigned short violationType, in AString sourceFile, in AString scriptSample, in int32_t lineNum); */
  NS_IMETHOD LogViolationDetails(uint16_t violationType, const nsAString & sourceFile, const nsAString & scriptSample, int32_t lineNum) = 0;

  enum {
    VIOLATION_TYPE_INLINE_SCRIPT = 1U,
    VIOLATION_TYPE_EVAL = 2U
  };

  /* void sendReports (in AString blockedURI, in AString violatedDirective, in AString scriptSample, in int32_t lineNum); */
  NS_IMETHOD SendReports(const nsAString & blockedURI, const nsAString & violatedDirective, const nsAString & scriptSample, int32_t lineNum) = 0;

  /* void scanRequestData (in nsIHttpChannel aChannel); */
  NS_IMETHOD ScanRequestData(nsIHttpChannel *aChannel) = 0;

  /* void refinePolicy (in AString policyString, in nsIURI selfURI, in boolean specCompliant); */
  NS_IMETHOD RefinePolicy(const nsAString & policyString, nsIURI *selfURI, bool specCompliant) = 0;

  /* boolean permitsAncestry (in nsIDocShell docShell); */
  NS_IMETHOD PermitsAncestry(nsIDocShell *docShell, bool *_retval) = 0;

  /* short shouldLoad (in unsigned long aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsISupports aContext, in ACString aMimeTypeGuess, in nsISupports aExtra); */
  NS_IMETHOD ShouldLoad(uint32_t aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, int16_t *_retval) = 0;

  /* short shouldProcess (in unsigned long aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsISupports aContext, in ACString aMimeType, in nsISupports aExtra); */
  NS_IMETHOD ShouldProcess(uint32_t aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, int16_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentSecurityPolicy, NS_ICONTENTSECURITYPOLICY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTSECURITYPOLICY \
  NS_IMETHOD GetIsInitialized(bool *aIsInitialized); \
  NS_IMETHOD SetIsInitialized(bool aIsInitialized); \
  NS_IMETHOD GetReportOnlyMode(bool *aReportOnlyMode); \
  NS_IMETHOD SetReportOnlyMode(bool aReportOnlyMode); \
  NS_IMETHOD GetPolicy(nsAString & aPolicy); \
  NS_IMETHOD GetAllowsInlineScript(bool *shouldReportViolation, bool *_retval); \
  NS_IMETHOD GetAllowsEval(bool *shouldReportViolation, bool *_retval); \
  NS_IMETHOD LogViolationDetails(uint16_t violationType, const nsAString & sourceFile, const nsAString & scriptSample, int32_t lineNum); \
  NS_IMETHOD SendReports(const nsAString & blockedURI, const nsAString & violatedDirective, const nsAString & scriptSample, int32_t lineNum); \
  NS_IMETHOD ScanRequestData(nsIHttpChannel *aChannel); \
  NS_IMETHOD RefinePolicy(const nsAString & policyString, nsIURI *selfURI, bool specCompliant); \
  NS_IMETHOD PermitsAncestry(nsIDocShell *docShell, bool *_retval); \
  NS_IMETHOD ShouldLoad(uint32_t aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, int16_t *_retval); \
  NS_IMETHOD ShouldProcess(uint32_t aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, int16_t *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTSECURITYPOLICY(_to) \
  NS_IMETHOD GetIsInitialized(bool *aIsInitialized) { return _to GetIsInitialized(aIsInitialized); } \
  NS_IMETHOD SetIsInitialized(bool aIsInitialized) { return _to SetIsInitialized(aIsInitialized); } \
  NS_IMETHOD GetReportOnlyMode(bool *aReportOnlyMode) { return _to GetReportOnlyMode(aReportOnlyMode); } \
  NS_IMETHOD SetReportOnlyMode(bool aReportOnlyMode) { return _to SetReportOnlyMode(aReportOnlyMode); } \
  NS_IMETHOD GetPolicy(nsAString & aPolicy) { return _to GetPolicy(aPolicy); } \
  NS_IMETHOD GetAllowsInlineScript(bool *shouldReportViolation, bool *_retval) { return _to GetAllowsInlineScript(shouldReportViolation, _retval); } \
  NS_IMETHOD GetAllowsEval(bool *shouldReportViolation, bool *_retval) { return _to GetAllowsEval(shouldReportViolation, _retval); } \
  NS_IMETHOD LogViolationDetails(uint16_t violationType, const nsAString & sourceFile, const nsAString & scriptSample, int32_t lineNum) { return _to LogViolationDetails(violationType, sourceFile, scriptSample, lineNum); } \
  NS_IMETHOD SendReports(const nsAString & blockedURI, const nsAString & violatedDirective, const nsAString & scriptSample, int32_t lineNum) { return _to SendReports(blockedURI, violatedDirective, scriptSample, lineNum); } \
  NS_IMETHOD ScanRequestData(nsIHttpChannel *aChannel) { return _to ScanRequestData(aChannel); } \
  NS_IMETHOD RefinePolicy(const nsAString & policyString, nsIURI *selfURI, bool specCompliant) { return _to RefinePolicy(policyString, selfURI, specCompliant); } \
  NS_IMETHOD PermitsAncestry(nsIDocShell *docShell, bool *_retval) { return _to PermitsAncestry(docShell, _retval); } \
  NS_IMETHOD ShouldLoad(uint32_t aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, int16_t *_retval) { return _to ShouldLoad(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeTypeGuess, aExtra, _retval); } \
  NS_IMETHOD ShouldProcess(uint32_t aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, int16_t *_retval) { return _to ShouldProcess(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeType, aExtra, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTSECURITYPOLICY(_to) \
  NS_IMETHOD GetIsInitialized(bool *aIsInitialized) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsInitialized(aIsInitialized); } \
  NS_IMETHOD SetIsInitialized(bool aIsInitialized) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsInitialized(aIsInitialized); } \
  NS_IMETHOD GetReportOnlyMode(bool *aReportOnlyMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReportOnlyMode(aReportOnlyMode); } \
  NS_IMETHOD SetReportOnlyMode(bool aReportOnlyMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReportOnlyMode(aReportOnlyMode); } \
  NS_IMETHOD GetPolicy(nsAString & aPolicy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPolicy(aPolicy); } \
  NS_IMETHOD GetAllowsInlineScript(bool *shouldReportViolation, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowsInlineScript(shouldReportViolation, _retval); } \
  NS_IMETHOD GetAllowsEval(bool *shouldReportViolation, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowsEval(shouldReportViolation, _retval); } \
  NS_IMETHOD LogViolationDetails(uint16_t violationType, const nsAString & sourceFile, const nsAString & scriptSample, int32_t lineNum) { return !_to ? NS_ERROR_NULL_POINTER : _to->LogViolationDetails(violationType, sourceFile, scriptSample, lineNum); } \
  NS_IMETHOD SendReports(const nsAString & blockedURI, const nsAString & violatedDirective, const nsAString & scriptSample, int32_t lineNum) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendReports(blockedURI, violatedDirective, scriptSample, lineNum); } \
  NS_IMETHOD ScanRequestData(nsIHttpChannel *aChannel) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScanRequestData(aChannel); } \
  NS_IMETHOD RefinePolicy(const nsAString & policyString, nsIURI *selfURI, bool specCompliant) { return !_to ? NS_ERROR_NULL_POINTER : _to->RefinePolicy(policyString, selfURI, specCompliant); } \
  NS_IMETHOD PermitsAncestry(nsIDocShell *docShell, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->PermitsAncestry(docShell, _retval); } \
  NS_IMETHOD ShouldLoad(uint32_t aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, int16_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShouldLoad(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeTypeGuess, aExtra, _retval); } \
  NS_IMETHOD ShouldProcess(uint32_t aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, int16_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShouldProcess(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeType, aExtra, _retval); } 

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
NS_IMETHODIMP nsContentSecurityPolicy::GetIsInitialized(bool *aIsInitialized)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentSecurityPolicy::SetIsInitialized(bool aIsInitialized)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean reportOnlyMode; */
NS_IMETHODIMP nsContentSecurityPolicy::GetReportOnlyMode(bool *aReportOnlyMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentSecurityPolicy::SetReportOnlyMode(bool aReportOnlyMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString policy; */
NS_IMETHODIMP nsContentSecurityPolicy::GetPolicy(nsAString & aPolicy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getAllowsInlineScript (out boolean shouldReportViolation); */
NS_IMETHODIMP nsContentSecurityPolicy::GetAllowsInlineScript(bool *shouldReportViolation, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getAllowsEval (out boolean shouldReportViolation); */
NS_IMETHODIMP nsContentSecurityPolicy::GetAllowsEval(bool *shouldReportViolation, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void logViolationDetails (in unsigned short violationType, in AString sourceFile, in AString scriptSample, in int32_t lineNum); */
NS_IMETHODIMP nsContentSecurityPolicy::LogViolationDetails(uint16_t violationType, const nsAString & sourceFile, const nsAString & scriptSample, int32_t lineNum)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendReports (in AString blockedURI, in AString violatedDirective, in AString scriptSample, in int32_t lineNum); */
NS_IMETHODIMP nsContentSecurityPolicy::SendReports(const nsAString & blockedURI, const nsAString & violatedDirective, const nsAString & scriptSample, int32_t lineNum)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scanRequestData (in nsIHttpChannel aChannel); */
NS_IMETHODIMP nsContentSecurityPolicy::ScanRequestData(nsIHttpChannel *aChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void refinePolicy (in AString policyString, in nsIURI selfURI, in boolean specCompliant); */
NS_IMETHODIMP nsContentSecurityPolicy::RefinePolicy(const nsAString & policyString, nsIURI *selfURI, bool specCompliant)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean permitsAncestry (in nsIDocShell docShell); */
NS_IMETHODIMP nsContentSecurityPolicy::PermitsAncestry(nsIDocShell *docShell, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* short shouldLoad (in unsigned long aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsISupports aContext, in ACString aMimeTypeGuess, in nsISupports aExtra); */
NS_IMETHODIMP nsContentSecurityPolicy::ShouldLoad(uint32_t aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, int16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* short shouldProcess (in unsigned long aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsISupports aContext, in ACString aMimeType, in nsISupports aExtra); */
NS_IMETHODIMP nsContentSecurityPolicy::ShouldProcess(uint32_t aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, int16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContentSecurityPolicy_h__ */

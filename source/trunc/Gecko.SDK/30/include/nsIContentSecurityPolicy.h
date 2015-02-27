/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIContentSecurityPolicy.idl
 */

#ifndef __gen_nsIContentSecurityPolicy_h__
#define __gen_nsIContentSecurityPolicy_h__


#ifndef __gen_nsISerializable_h__
#include "nsISerializable.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsIDocShell; /* forward declaration */

class nsIPrincipal; /* forward declaration */


/* starting interface:    nsIContentSecurityPolicy */
#define NS_ICONTENTSECURITYPOLICY_IID_STR "8b91f829-b1bf-4327-8ece-4000aa823394"

#define NS_ICONTENTSECURITYPOLICY_IID \
  {0x8b91f829, 0xb1bf, 0x4327, \
    { 0x8e, 0xce, 0x40, 0x00, 0xaa, 0x82, 0x33, 0x94 }}

class NS_NO_VTABLE nsIContentSecurityPolicy : public nsISerializable {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTSECURITYPOLICY_IID)

  /* attribute boolean isInitialized; */
  NS_IMETHOD GetIsInitialized(bool *aIsInitialized) = 0;
  NS_IMETHOD SetIsInitialized(bool aIsInitialized) = 0;

  /* AString getPolicy (in unsigned long index); */
  NS_IMETHOD GetPolicy(uint32_t index, nsAString & _retval) = 0;

  /* attribute long policyCount; */
  NS_IMETHOD GetPolicyCount(int32_t *aPolicyCount) = 0;
  NS_IMETHOD SetPolicyCount(int32_t aPolicyCount) = 0;

  /* void removePolicy (in unsigned long index); */
  NS_IMETHOD RemovePolicy(uint32_t index) = 0;

  /* void appendPolicy (in AString policyString, in nsIURI selfURI, in boolean reportOnly, in boolean specCompliant); */
  NS_IMETHOD AppendPolicy(const nsAString & policyString, nsIURI *selfURI, bool reportOnly, bool specCompliant) = 0;

  /* boolean getAllowsInlineScript (out boolean shouldReportViolations); */
  NS_IMETHOD GetAllowsInlineScript(bool *shouldReportViolations, bool *_retval) = 0;

  /* boolean getAllowsEval (out boolean shouldReportViolations); */
  NS_IMETHOD GetAllowsEval(bool *shouldReportViolations, bool *_retval) = 0;

  /* boolean getAllowsInlineStyle (out boolean shouldReportViolations); */
  NS_IMETHOD GetAllowsInlineStyle(bool *shouldReportViolations, bool *_retval) = 0;

  /* boolean getAllowsNonce (in AString aNonce, in unsigned long aContentType, out boolean shouldReportViolation); */
  NS_IMETHOD GetAllowsNonce(const nsAString & aNonce, uint32_t aContentType, bool *shouldReportViolation, bool *_retval) = 0;

  /* boolean getAllowsHash (in AString aContent, in unsigned short aContentType, out boolean shouldReportViolation); */
  NS_IMETHOD GetAllowsHash(const nsAString & aContent, uint16_t aContentType, bool *shouldReportViolation, bool *_retval) = 0;

  /* void logViolationDetails (in unsigned short violationType, in AString sourceFile, in AString scriptSample, in int32_t lineNum, [optional] in AString nonce, [optional] in AString content); */
  NS_IMETHOD LogViolationDetails(uint16_t violationType, const nsAString & sourceFile, const nsAString & scriptSample, int32_t lineNum, const nsAString & nonce, const nsAString & content) = 0;

  enum {
    VIOLATION_TYPE_INLINE_SCRIPT = 1U,
    VIOLATION_TYPE_EVAL = 2U,
    VIOLATION_TYPE_INLINE_STYLE = 3U,
    VIOLATION_TYPE_NONCE_SCRIPT = 4U,
    VIOLATION_TYPE_NONCE_STYLE = 5U,
    VIOLATION_TYPE_HASH_SCRIPT = 6U,
    VIOLATION_TYPE_HASH_STYLE = 7U
  };

  /* void setRequestContext (in nsIURI selfURI, in nsIURI referrer, in nsIPrincipal documentPrincipal, in nsIChannel aChannel); */
  NS_IMETHOD SetRequestContext(nsIURI *selfURI, nsIURI *referrer, nsIPrincipal *documentPrincipal, nsIChannel *aChannel) = 0;

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
  NS_IMETHOD GetPolicy(uint32_t index, nsAString & _retval); \
  NS_IMETHOD GetPolicyCount(int32_t *aPolicyCount); \
  NS_IMETHOD SetPolicyCount(int32_t aPolicyCount); \
  NS_IMETHOD RemovePolicy(uint32_t index); \
  NS_IMETHOD AppendPolicy(const nsAString & policyString, nsIURI *selfURI, bool reportOnly, bool specCompliant); \
  NS_IMETHOD GetAllowsInlineScript(bool *shouldReportViolations, bool *_retval); \
  NS_IMETHOD GetAllowsEval(bool *shouldReportViolations, bool *_retval); \
  NS_IMETHOD GetAllowsInlineStyle(bool *shouldReportViolations, bool *_retval); \
  NS_IMETHOD GetAllowsNonce(const nsAString & aNonce, uint32_t aContentType, bool *shouldReportViolation, bool *_retval); \
  NS_IMETHOD GetAllowsHash(const nsAString & aContent, uint16_t aContentType, bool *shouldReportViolation, bool *_retval); \
  NS_IMETHOD LogViolationDetails(uint16_t violationType, const nsAString & sourceFile, const nsAString & scriptSample, int32_t lineNum, const nsAString & nonce, const nsAString & content); \
  NS_IMETHOD SetRequestContext(nsIURI *selfURI, nsIURI *referrer, nsIPrincipal *documentPrincipal, nsIChannel *aChannel); \
  NS_IMETHOD PermitsAncestry(nsIDocShell *docShell, bool *_retval); \
  NS_IMETHOD ShouldLoad(uint32_t aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, int16_t *_retval); \
  NS_IMETHOD ShouldProcess(uint32_t aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, int16_t *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTSECURITYPOLICY(_to) \
  NS_IMETHOD GetIsInitialized(bool *aIsInitialized) { return _to GetIsInitialized(aIsInitialized); } \
  NS_IMETHOD SetIsInitialized(bool aIsInitialized) { return _to SetIsInitialized(aIsInitialized); } \
  NS_IMETHOD GetPolicy(uint32_t index, nsAString & _retval) { return _to GetPolicy(index, _retval); } \
  NS_IMETHOD GetPolicyCount(int32_t *aPolicyCount) { return _to GetPolicyCount(aPolicyCount); } \
  NS_IMETHOD SetPolicyCount(int32_t aPolicyCount) { return _to SetPolicyCount(aPolicyCount); } \
  NS_IMETHOD RemovePolicy(uint32_t index) { return _to RemovePolicy(index); } \
  NS_IMETHOD AppendPolicy(const nsAString & policyString, nsIURI *selfURI, bool reportOnly, bool specCompliant) { return _to AppendPolicy(policyString, selfURI, reportOnly, specCompliant); } \
  NS_IMETHOD GetAllowsInlineScript(bool *shouldReportViolations, bool *_retval) { return _to GetAllowsInlineScript(shouldReportViolations, _retval); } \
  NS_IMETHOD GetAllowsEval(bool *shouldReportViolations, bool *_retval) { return _to GetAllowsEval(shouldReportViolations, _retval); } \
  NS_IMETHOD GetAllowsInlineStyle(bool *shouldReportViolations, bool *_retval) { return _to GetAllowsInlineStyle(shouldReportViolations, _retval); } \
  NS_IMETHOD GetAllowsNonce(const nsAString & aNonce, uint32_t aContentType, bool *shouldReportViolation, bool *_retval) { return _to GetAllowsNonce(aNonce, aContentType, shouldReportViolation, _retval); } \
  NS_IMETHOD GetAllowsHash(const nsAString & aContent, uint16_t aContentType, bool *shouldReportViolation, bool *_retval) { return _to GetAllowsHash(aContent, aContentType, shouldReportViolation, _retval); } \
  NS_IMETHOD LogViolationDetails(uint16_t violationType, const nsAString & sourceFile, const nsAString & scriptSample, int32_t lineNum, const nsAString & nonce, const nsAString & content) { return _to LogViolationDetails(violationType, sourceFile, scriptSample, lineNum, nonce, content); } \
  NS_IMETHOD SetRequestContext(nsIURI *selfURI, nsIURI *referrer, nsIPrincipal *documentPrincipal, nsIChannel *aChannel) { return _to SetRequestContext(selfURI, referrer, documentPrincipal, aChannel); } \
  NS_IMETHOD PermitsAncestry(nsIDocShell *docShell, bool *_retval) { return _to PermitsAncestry(docShell, _retval); } \
  NS_IMETHOD ShouldLoad(uint32_t aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, int16_t *_retval) { return _to ShouldLoad(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeTypeGuess, aExtra, _retval); } \
  NS_IMETHOD ShouldProcess(uint32_t aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, int16_t *_retval) { return _to ShouldProcess(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeType, aExtra, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTSECURITYPOLICY(_to) \
  NS_IMETHOD GetIsInitialized(bool *aIsInitialized) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsInitialized(aIsInitialized); } \
  NS_IMETHOD SetIsInitialized(bool aIsInitialized) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsInitialized(aIsInitialized); } \
  NS_IMETHOD GetPolicy(uint32_t index, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPolicy(index, _retval); } \
  NS_IMETHOD GetPolicyCount(int32_t *aPolicyCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPolicyCount(aPolicyCount); } \
  NS_IMETHOD SetPolicyCount(int32_t aPolicyCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPolicyCount(aPolicyCount); } \
  NS_IMETHOD RemovePolicy(uint32_t index) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePolicy(index); } \
  NS_IMETHOD AppendPolicy(const nsAString & policyString, nsIURI *selfURI, bool reportOnly, bool specCompliant) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendPolicy(policyString, selfURI, reportOnly, specCompliant); } \
  NS_IMETHOD GetAllowsInlineScript(bool *shouldReportViolations, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowsInlineScript(shouldReportViolations, _retval); } \
  NS_IMETHOD GetAllowsEval(bool *shouldReportViolations, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowsEval(shouldReportViolations, _retval); } \
  NS_IMETHOD GetAllowsInlineStyle(bool *shouldReportViolations, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowsInlineStyle(shouldReportViolations, _retval); } \
  NS_IMETHOD GetAllowsNonce(const nsAString & aNonce, uint32_t aContentType, bool *shouldReportViolation, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowsNonce(aNonce, aContentType, shouldReportViolation, _retval); } \
  NS_IMETHOD GetAllowsHash(const nsAString & aContent, uint16_t aContentType, bool *shouldReportViolation, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowsHash(aContent, aContentType, shouldReportViolation, _retval); } \
  NS_IMETHOD LogViolationDetails(uint16_t violationType, const nsAString & sourceFile, const nsAString & scriptSample, int32_t lineNum, const nsAString & nonce, const nsAString & content) { return !_to ? NS_ERROR_NULL_POINTER : _to->LogViolationDetails(violationType, sourceFile, scriptSample, lineNum, nonce, content); } \
  NS_IMETHOD SetRequestContext(nsIURI *selfURI, nsIURI *referrer, nsIPrincipal *documentPrincipal, nsIChannel *aChannel) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRequestContext(selfURI, referrer, documentPrincipal, aChannel); } \
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

/* AString getPolicy (in unsigned long index); */
NS_IMETHODIMP nsContentSecurityPolicy::GetPolicy(uint32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long policyCount; */
NS_IMETHODIMP nsContentSecurityPolicy::GetPolicyCount(int32_t *aPolicyCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentSecurityPolicy::SetPolicyCount(int32_t aPolicyCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removePolicy (in unsigned long index); */
NS_IMETHODIMP nsContentSecurityPolicy::RemovePolicy(uint32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void appendPolicy (in AString policyString, in nsIURI selfURI, in boolean reportOnly, in boolean specCompliant); */
NS_IMETHODIMP nsContentSecurityPolicy::AppendPolicy(const nsAString & policyString, nsIURI *selfURI, bool reportOnly, bool specCompliant)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getAllowsInlineScript (out boolean shouldReportViolations); */
NS_IMETHODIMP nsContentSecurityPolicy::GetAllowsInlineScript(bool *shouldReportViolations, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getAllowsEval (out boolean shouldReportViolations); */
NS_IMETHODIMP nsContentSecurityPolicy::GetAllowsEval(bool *shouldReportViolations, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getAllowsInlineStyle (out boolean shouldReportViolations); */
NS_IMETHODIMP nsContentSecurityPolicy::GetAllowsInlineStyle(bool *shouldReportViolations, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getAllowsNonce (in AString aNonce, in unsigned long aContentType, out boolean shouldReportViolation); */
NS_IMETHODIMP nsContentSecurityPolicy::GetAllowsNonce(const nsAString & aNonce, uint32_t aContentType, bool *shouldReportViolation, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getAllowsHash (in AString aContent, in unsigned short aContentType, out boolean shouldReportViolation); */
NS_IMETHODIMP nsContentSecurityPolicy::GetAllowsHash(const nsAString & aContent, uint16_t aContentType, bool *shouldReportViolation, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void logViolationDetails (in unsigned short violationType, in AString sourceFile, in AString scriptSample, in int32_t lineNum, [optional] in AString nonce, [optional] in AString content); */
NS_IMETHODIMP nsContentSecurityPolicy::LogViolationDetails(uint16_t violationType, const nsAString & sourceFile, const nsAString & scriptSample, int32_t lineNum, const nsAString & nonce, const nsAString & content)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setRequestContext (in nsIURI selfURI, in nsIURI referrer, in nsIPrincipal documentPrincipal, in nsIChannel aChannel); */
NS_IMETHODIMP nsContentSecurityPolicy::SetRequestContext(nsIURI *selfURI, nsIURI *referrer, nsIPrincipal *documentPrincipal, nsIChannel *aChannel)
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

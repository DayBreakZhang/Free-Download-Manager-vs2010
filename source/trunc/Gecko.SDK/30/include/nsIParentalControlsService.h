/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIParentalControlsService.idl
 */

#ifndef __gen_nsIParentalControlsService_h__
#define __gen_nsIParentalControlsService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIInterfaceRequestor; /* forward declaration */

class nsIArray; /* forward declaration */


/* starting interface:    nsIParentalControlsService */
#define NS_IPARENTALCONTROLSSERVICE_IID_STR "871cf229-2b21-4f04-b24d-e08061f14815"

#define NS_IPARENTALCONTROLSSERVICE_IID \
  {0x871cf229, 0x2b21, 0x4f04, \
    { 0xb2, 0x4d, 0xe0, 0x80, 0x61, 0xf1, 0x48, 0x15 }}

class NS_NO_VTABLE nsIParentalControlsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPARENTALCONTROLSSERVICE_IID)

  /* readonly attribute boolean parentalControlsEnabled; */
  NS_IMETHOD GetParentalControlsEnabled(bool *aParentalControlsEnabled) = 0;

  /* readonly attribute boolean blockFileDownloadsEnabled; */
  NS_IMETHOD GetBlockFileDownloadsEnabled(bool *aBlockFileDownloadsEnabled) = 0;

  /* boolean requestURIOverride (in nsIURI aTarget, [optional] in nsIInterfaceRequestor aWindowContext); */
  NS_IMETHOD RequestURIOverride(nsIURI *aTarget, nsIInterfaceRequestor *aWindowContext, bool *_retval) = 0;

  /* boolean requestURIOverrides (in nsIArray aTargets, [optional] in nsIInterfaceRequestor aWindowContext); */
  NS_IMETHOD RequestURIOverrides(nsIArray *aTargets, nsIInterfaceRequestor *aWindowContext, bool *_retval) = 0;

  /* readonly attribute boolean loggingEnabled; */
  NS_IMETHOD GetLoggingEnabled(bool *aLoggingEnabled) = 0;

  enum {
    ePCLog_URIVisit = 1,
    ePCLog_FileDownload = 2
  };

  /* void log (in short aEntryType, in boolean aFlag, in nsIURI aSource, [optional] in nsIFile aTarget); */
  NS_IMETHOD Log(int16_t aEntryType, bool aFlag, nsIURI *aSource, nsIFile *aTarget) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIParentalControlsService, NS_IPARENTALCONTROLSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPARENTALCONTROLSSERVICE \
  NS_IMETHOD GetParentalControlsEnabled(bool *aParentalControlsEnabled); \
  NS_IMETHOD GetBlockFileDownloadsEnabled(bool *aBlockFileDownloadsEnabled); \
  NS_IMETHOD RequestURIOverride(nsIURI *aTarget, nsIInterfaceRequestor *aWindowContext, bool *_retval); \
  NS_IMETHOD RequestURIOverrides(nsIArray *aTargets, nsIInterfaceRequestor *aWindowContext, bool *_retval); \
  NS_IMETHOD GetLoggingEnabled(bool *aLoggingEnabled); \
  NS_IMETHOD Log(int16_t aEntryType, bool aFlag, nsIURI *aSource, nsIFile *aTarget); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPARENTALCONTROLSSERVICE(_to) \
  NS_IMETHOD GetParentalControlsEnabled(bool *aParentalControlsEnabled) { return _to GetParentalControlsEnabled(aParentalControlsEnabled); } \
  NS_IMETHOD GetBlockFileDownloadsEnabled(bool *aBlockFileDownloadsEnabled) { return _to GetBlockFileDownloadsEnabled(aBlockFileDownloadsEnabled); } \
  NS_IMETHOD RequestURIOverride(nsIURI *aTarget, nsIInterfaceRequestor *aWindowContext, bool *_retval) { return _to RequestURIOverride(aTarget, aWindowContext, _retval); } \
  NS_IMETHOD RequestURIOverrides(nsIArray *aTargets, nsIInterfaceRequestor *aWindowContext, bool *_retval) { return _to RequestURIOverrides(aTargets, aWindowContext, _retval); } \
  NS_IMETHOD GetLoggingEnabled(bool *aLoggingEnabled) { return _to GetLoggingEnabled(aLoggingEnabled); } \
  NS_IMETHOD Log(int16_t aEntryType, bool aFlag, nsIURI *aSource, nsIFile *aTarget) { return _to Log(aEntryType, aFlag, aSource, aTarget); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPARENTALCONTROLSSERVICE(_to) \
  NS_IMETHOD GetParentalControlsEnabled(bool *aParentalControlsEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentalControlsEnabled(aParentalControlsEnabled); } \
  NS_IMETHOD GetBlockFileDownloadsEnabled(bool *aBlockFileDownloadsEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBlockFileDownloadsEnabled(aBlockFileDownloadsEnabled); } \
  NS_IMETHOD RequestURIOverride(nsIURI *aTarget, nsIInterfaceRequestor *aWindowContext, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestURIOverride(aTarget, aWindowContext, _retval); } \
  NS_IMETHOD RequestURIOverrides(nsIArray *aTargets, nsIInterfaceRequestor *aWindowContext, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestURIOverrides(aTargets, aWindowContext, _retval); } \
  NS_IMETHOD GetLoggingEnabled(bool *aLoggingEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoggingEnabled(aLoggingEnabled); } \
  NS_IMETHOD Log(int16_t aEntryType, bool aFlag, nsIURI *aSource, nsIFile *aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->Log(aEntryType, aFlag, aSource, aTarget); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsParentalControlsService : public nsIParentalControlsService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPARENTALCONTROLSSERVICE

  nsParentalControlsService();

private:
  ~nsParentalControlsService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsParentalControlsService, nsIParentalControlsService)

nsParentalControlsService::nsParentalControlsService()
{
  /* member initializers and constructor code */
}

nsParentalControlsService::~nsParentalControlsService()
{
  /* destructor code */
}

/* readonly attribute boolean parentalControlsEnabled; */
NS_IMETHODIMP nsParentalControlsService::GetParentalControlsEnabled(bool *aParentalControlsEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean blockFileDownloadsEnabled; */
NS_IMETHODIMP nsParentalControlsService::GetBlockFileDownloadsEnabled(bool *aBlockFileDownloadsEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean requestURIOverride (in nsIURI aTarget, [optional] in nsIInterfaceRequestor aWindowContext); */
NS_IMETHODIMP nsParentalControlsService::RequestURIOverride(nsIURI *aTarget, nsIInterfaceRequestor *aWindowContext, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean requestURIOverrides (in nsIArray aTargets, [optional] in nsIInterfaceRequestor aWindowContext); */
NS_IMETHODIMP nsParentalControlsService::RequestURIOverrides(nsIArray *aTargets, nsIInterfaceRequestor *aWindowContext, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean loggingEnabled; */
NS_IMETHODIMP nsParentalControlsService::GetLoggingEnabled(bool *aLoggingEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void log (in short aEntryType, in boolean aFlag, in nsIURI aSource, [optional] in nsIFile aTarget); */
NS_IMETHODIMP nsParentalControlsService::Log(int16_t aEntryType, bool aFlag, nsIURI *aSource, nsIFile *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIParentalControlsService_h__ */

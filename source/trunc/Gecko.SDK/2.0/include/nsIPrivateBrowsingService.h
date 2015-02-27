/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/netwerk/base/public/nsIPrivateBrowsingService.idl
 */

#ifndef __gen_nsIPrivateBrowsingService_h__
#define __gen_nsIPrivateBrowsingService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPrivateBrowsingService */
#define NS_IPRIVATEBROWSINGSERVICE_IID_STR "4b731983-9542-49f4-b16b-de68ad1c2068"

#define NS_IPRIVATEBROWSINGSERVICE_IID \
  {0x4b731983, 0x9542, 0x49f4, \
    { 0xb1, 0x6b, 0xde, 0x68, 0xad, 0x1c, 0x20, 0x68 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIPrivateBrowsingService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRIVATEBROWSINGSERVICE_IID)

  /* attribute boolean privateBrowsingEnabled; */
  NS_SCRIPTABLE NS_IMETHOD GetPrivateBrowsingEnabled(PRBool *aPrivateBrowsingEnabled) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPrivateBrowsingEnabled(PRBool aPrivateBrowsingEnabled) = 0;

  /* readonly attribute boolean autoStarted; */
  NS_SCRIPTABLE NS_IMETHOD GetAutoStarted(PRBool *aAutoStarted) = 0;

  /* readonly attribute boolean lastChangedByCommandLine; */
  NS_SCRIPTABLE NS_IMETHOD GetLastChangedByCommandLine(PRBool *aLastChangedByCommandLine) = 0;

  /**
     * Removes all data stored for a given domain.  This includes all data for
     * subdomains of the given domain.
     *
     * @param aDomain
     *        The domain that will have its data removed.
     */
  /* void removeDataFromDomain (in AUTF8String aDomain); */
  NS_SCRIPTABLE NS_IMETHOD RemoveDataFromDomain(const nsACString & aDomain) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrivateBrowsingService, NS_IPRIVATEBROWSINGSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRIVATEBROWSINGSERVICE \
  NS_SCRIPTABLE NS_IMETHOD GetPrivateBrowsingEnabled(PRBool *aPrivateBrowsingEnabled); \
  NS_SCRIPTABLE NS_IMETHOD SetPrivateBrowsingEnabled(PRBool aPrivateBrowsingEnabled); \
  NS_SCRIPTABLE NS_IMETHOD GetAutoStarted(PRBool *aAutoStarted); \
  NS_SCRIPTABLE NS_IMETHOD GetLastChangedByCommandLine(PRBool *aLastChangedByCommandLine); \
  NS_SCRIPTABLE NS_IMETHOD RemoveDataFromDomain(const nsACString & aDomain); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRIVATEBROWSINGSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPrivateBrowsingEnabled(PRBool *aPrivateBrowsingEnabled) { return _to GetPrivateBrowsingEnabled(aPrivateBrowsingEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrivateBrowsingEnabled(PRBool aPrivateBrowsingEnabled) { return _to SetPrivateBrowsingEnabled(aPrivateBrowsingEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetAutoStarted(PRBool *aAutoStarted) { return _to GetAutoStarted(aAutoStarted); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastChangedByCommandLine(PRBool *aLastChangedByCommandLine) { return _to GetLastChangedByCommandLine(aLastChangedByCommandLine); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveDataFromDomain(const nsACString & aDomain) { return _to RemoveDataFromDomain(aDomain); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRIVATEBROWSINGSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPrivateBrowsingEnabled(PRBool *aPrivateBrowsingEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrivateBrowsingEnabled(aPrivateBrowsingEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrivateBrowsingEnabled(PRBool aPrivateBrowsingEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrivateBrowsingEnabled(aPrivateBrowsingEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetAutoStarted(PRBool *aAutoStarted) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAutoStarted(aAutoStarted); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastChangedByCommandLine(PRBool *aLastChangedByCommandLine) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastChangedByCommandLine(aLastChangedByCommandLine); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveDataFromDomain(const nsACString & aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveDataFromDomain(aDomain); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrivateBrowsingService : public nsIPrivateBrowsingService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRIVATEBROWSINGSERVICE

  nsPrivateBrowsingService();

private:
  ~nsPrivateBrowsingService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrivateBrowsingService, nsIPrivateBrowsingService)

nsPrivateBrowsingService::nsPrivateBrowsingService()
{
  /* member initializers and constructor code */
}

nsPrivateBrowsingService::~nsPrivateBrowsingService()
{
  /* destructor code */
}

/* attribute boolean privateBrowsingEnabled; */
NS_IMETHODIMP nsPrivateBrowsingService::GetPrivateBrowsingEnabled(PRBool *aPrivateBrowsingEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrivateBrowsingService::SetPrivateBrowsingEnabled(PRBool aPrivateBrowsingEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean autoStarted; */
NS_IMETHODIMP nsPrivateBrowsingService::GetAutoStarted(PRBool *aAutoStarted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean lastChangedByCommandLine; */
NS_IMETHODIMP nsPrivateBrowsingService::GetLastChangedByCommandLine(PRBool *aLastChangedByCommandLine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeDataFromDomain (in AUTF8String aDomain); */
NS_IMETHODIMP nsPrivateBrowsingService::RemoveDataFromDomain(const nsACString & aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * Private Browsing service notifications:
 *
 * - NS_PRIVATE_BROWSING_REQUEST_TOPIC:
 *   The data parameter determines which kind of request this represents:
 * --- NS_PRIVATE_BROWSING_ENTER:
 *     We send this notification before switching to the private browsing mode.
 *     The subject parameter is set to a nsISupportsPRBool, which observers can
 *     set to true to prevent the switch to the private browsing mode.
 * --- NS_PRIVATE_BROWSING_LEAVE:
 *     We send this notification before leaving the private browsing mode.
 *     The subject parameter is set to a nsISupportsPRBool, which observers can
 *     set to true to prevent leaving the private browsing mode.
 *
 * - NS_PRIVATE_BROWSING_SWITCH_TOPIC:
 *   The data parameter determines which kind of switch this represents:
 * --- NS_PRIVATE_BROWSING_ENTER:
 *     We send this notification while switching to the private browsing mode.
 * --- NS_PRIVATE_BROWSING_LEAVE:
 *     We send this notification while leaving the private browsing mode.
 */
#define NS_PRIVATE_BROWSING_SWITCH_TOPIC  "private-browsing"
#define NS_PRIVATE_BROWSING_REQUEST_TOPIC "private-browsing-cancel-vote"
#define NS_PRIVATE_BROWSING_ENTER         "enter"
#define NS_PRIVATE_BROWSING_LEAVE         "exit"

#endif /* __gen_nsIPrivateBrowsingService_h__ */

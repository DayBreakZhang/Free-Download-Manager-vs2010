/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/netwerk/protocol/http/nsIHttpChannelInternal.idl
 */

#ifndef __gen_nsIHttpChannelInternal_h__
#define __gen_nsIHttpChannelInternal_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIProxyInfo; /* forward declaration */


/* starting interface:    nsIHttpChannelInternal */
#define NS_IHTTPCHANNELINTERNAL_IID_STR "9fb2a161-d075-4bf2-b07a-26bac650cc81"

#define NS_IHTTPCHANNELINTERNAL_IID \
  {0x9fb2a161, 0xd075, 0x4bf2, \
    { 0xb0, 0x7a, 0x26, 0xba, 0xc6, 0x50, 0xcc, 0x81 }}

/** 
 * Dumping ground for http.  This interface will never be frozen.  If you are 
 * using any feature exposed by this interface, be aware that this interface 
 * will change and you will be broken.  You have been warned.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIHttpChannelInternal : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPCHANNELINTERNAL_IID)

  /**
     * An http channel can own a reference to the document URI
     */
  /* attribute nsIURI documentURI; */
  NS_SCRIPTABLE NS_IMETHOD GetDocumentURI(nsIURI **aDocumentURI) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDocumentURI(nsIURI *aDocumentURI) = 0;

  /**
     * Get the major/minor version numbers for the request
     */
  /* void getRequestVersion (out unsigned long major, out unsigned long minor); */
  NS_SCRIPTABLE NS_IMETHOD GetRequestVersion(PRUint32 *major NS_OUTPARAM, PRUint32 *minor NS_OUTPARAM) = 0;

  /**
     * Get the major/minor version numbers for the response
     */
  /* void getResponseVersion (out unsigned long major, out unsigned long minor); */
  NS_SCRIPTABLE NS_IMETHOD GetResponseVersion(PRUint32 *major NS_OUTPARAM, PRUint32 *minor NS_OUTPARAM) = 0;

  /**
     * Helper method to set a cookie with a consumer-provided
     * cookie header, _but_ using the channel's other information
     * (URI's, prompters, date headers etc).
     *
     * @param aCookieHeader
     *        The cookie header to be parsed.
     */
  /* void setCookie (in string aCookieHeader); */
  NS_SCRIPTABLE NS_IMETHOD SetCookie(const char *aCookieHeader) = 0;

  /**
     * Setup this channel as an application cache fallback channel.
     */
  /* void setupFallbackChannel (in string aFallbackKey); */
  NS_SCRIPTABLE NS_IMETHOD SetupFallbackChannel(const char *aFallbackKey) = 0;

  /**
     * Force relevant cookies to be sent with this load even if normally they
     * wouldn't be.
     */
  /* attribute boolean forceAllowThirdPartyCookie; */
  NS_SCRIPTABLE NS_IMETHOD GetForceAllowThirdPartyCookie(PRBool *aForceAllowThirdPartyCookie) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetForceAllowThirdPartyCookie(PRBool aForceAllowThirdPartyCookie) = 0;

  /**
     * Returns true iff the channel has been canceled.
     */
  /* readonly attribute boolean canceled; */
  NS_SCRIPTABLE NS_IMETHOD GetCanceled(PRBool *aCanceled) = 0;

  /**
     * Lets externalhandler tell the channel it is open on behalf of a download
     */
  /* attribute boolean channelIsForDownload; */
  NS_SCRIPTABLE NS_IMETHOD GetChannelIsForDownload(PRBool *aChannelIsForDownload) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetChannelIsForDownload(PRBool aChannelIsForDownload) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpChannelInternal, NS_IHTTPCHANNELINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPCHANNELINTERNAL \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentURI(nsIURI **aDocumentURI); \
  NS_SCRIPTABLE NS_IMETHOD SetDocumentURI(nsIURI *aDocumentURI); \
  NS_SCRIPTABLE NS_IMETHOD GetRequestVersion(PRUint32 *major NS_OUTPARAM, PRUint32 *minor NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetResponseVersion(PRUint32 *major NS_OUTPARAM, PRUint32 *minor NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetCookie(const char *aCookieHeader); \
  NS_SCRIPTABLE NS_IMETHOD SetupFallbackChannel(const char *aFallbackKey); \
  NS_SCRIPTABLE NS_IMETHOD GetForceAllowThirdPartyCookie(PRBool *aForceAllowThirdPartyCookie); \
  NS_SCRIPTABLE NS_IMETHOD SetForceAllowThirdPartyCookie(PRBool aForceAllowThirdPartyCookie); \
  NS_SCRIPTABLE NS_IMETHOD GetCanceled(PRBool *aCanceled); \
  NS_SCRIPTABLE NS_IMETHOD GetChannelIsForDownload(PRBool *aChannelIsForDownload); \
  NS_SCRIPTABLE NS_IMETHOD SetChannelIsForDownload(PRBool aChannelIsForDownload); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPCHANNELINTERNAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentURI(nsIURI **aDocumentURI) { return _to GetDocumentURI(aDocumentURI); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocumentURI(nsIURI *aDocumentURI) { return _to SetDocumentURI(aDocumentURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetRequestVersion(PRUint32 *major NS_OUTPARAM, PRUint32 *minor NS_OUTPARAM) { return _to GetRequestVersion(major, minor); } \
  NS_SCRIPTABLE NS_IMETHOD GetResponseVersion(PRUint32 *major NS_OUTPARAM, PRUint32 *minor NS_OUTPARAM) { return _to GetResponseVersion(major, minor); } \
  NS_SCRIPTABLE NS_IMETHOD SetCookie(const char *aCookieHeader) { return _to SetCookie(aCookieHeader); } \
  NS_SCRIPTABLE NS_IMETHOD SetupFallbackChannel(const char *aFallbackKey) { return _to SetupFallbackChannel(aFallbackKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetForceAllowThirdPartyCookie(PRBool *aForceAllowThirdPartyCookie) { return _to GetForceAllowThirdPartyCookie(aForceAllowThirdPartyCookie); } \
  NS_SCRIPTABLE NS_IMETHOD SetForceAllowThirdPartyCookie(PRBool aForceAllowThirdPartyCookie) { return _to SetForceAllowThirdPartyCookie(aForceAllowThirdPartyCookie); } \
  NS_SCRIPTABLE NS_IMETHOD GetCanceled(PRBool *aCanceled) { return _to GetCanceled(aCanceled); } \
  NS_SCRIPTABLE NS_IMETHOD GetChannelIsForDownload(PRBool *aChannelIsForDownload) { return _to GetChannelIsForDownload(aChannelIsForDownload); } \
  NS_SCRIPTABLE NS_IMETHOD SetChannelIsForDownload(PRBool aChannelIsForDownload) { return _to SetChannelIsForDownload(aChannelIsForDownload); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPCHANNELINTERNAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentURI(nsIURI **aDocumentURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentURI(aDocumentURI); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocumentURI(nsIURI *aDocumentURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocumentURI(aDocumentURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetRequestVersion(PRUint32 *major NS_OUTPARAM, PRUint32 *minor NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequestVersion(major, minor); } \
  NS_SCRIPTABLE NS_IMETHOD GetResponseVersion(PRUint32 *major NS_OUTPARAM, PRUint32 *minor NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseVersion(major, minor); } \
  NS_SCRIPTABLE NS_IMETHOD SetCookie(const char *aCookieHeader) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCookie(aCookieHeader); } \
  NS_SCRIPTABLE NS_IMETHOD SetupFallbackChannel(const char *aFallbackKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetupFallbackChannel(aFallbackKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetForceAllowThirdPartyCookie(PRBool *aForceAllowThirdPartyCookie) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForceAllowThirdPartyCookie(aForceAllowThirdPartyCookie); } \
  NS_SCRIPTABLE NS_IMETHOD SetForceAllowThirdPartyCookie(PRBool aForceAllowThirdPartyCookie) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetForceAllowThirdPartyCookie(aForceAllowThirdPartyCookie); } \
  NS_SCRIPTABLE NS_IMETHOD GetCanceled(PRBool *aCanceled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanceled(aCanceled); } \
  NS_SCRIPTABLE NS_IMETHOD GetChannelIsForDownload(PRBool *aChannelIsForDownload) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChannelIsForDownload(aChannelIsForDownload); } \
  NS_SCRIPTABLE NS_IMETHOD SetChannelIsForDownload(PRBool aChannelIsForDownload) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChannelIsForDownload(aChannelIsForDownload); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpChannelInternal : public nsIHttpChannelInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPCHANNELINTERNAL

  nsHttpChannelInternal();

private:
  ~nsHttpChannelInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHttpChannelInternal, nsIHttpChannelInternal)

nsHttpChannelInternal::nsHttpChannelInternal()
{
  /* member initializers and constructor code */
}

nsHttpChannelInternal::~nsHttpChannelInternal()
{
  /* destructor code */
}

/* attribute nsIURI documentURI; */
NS_IMETHODIMP nsHttpChannelInternal::GetDocumentURI(nsIURI **aDocumentURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHttpChannelInternal::SetDocumentURI(nsIURI *aDocumentURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getRequestVersion (out unsigned long major, out unsigned long minor); */
NS_IMETHODIMP nsHttpChannelInternal::GetRequestVersion(PRUint32 *major NS_OUTPARAM, PRUint32 *minor NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getResponseVersion (out unsigned long major, out unsigned long minor); */
NS_IMETHODIMP nsHttpChannelInternal::GetResponseVersion(PRUint32 *major NS_OUTPARAM, PRUint32 *minor NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCookie (in string aCookieHeader); */
NS_IMETHODIMP nsHttpChannelInternal::SetCookie(const char *aCookieHeader)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setupFallbackChannel (in string aFallbackKey); */
NS_IMETHODIMP nsHttpChannelInternal::SetupFallbackChannel(const char *aFallbackKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean forceAllowThirdPartyCookie; */
NS_IMETHODIMP nsHttpChannelInternal::GetForceAllowThirdPartyCookie(PRBool *aForceAllowThirdPartyCookie)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHttpChannelInternal::SetForceAllowThirdPartyCookie(PRBool aForceAllowThirdPartyCookie)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean canceled; */
NS_IMETHODIMP nsHttpChannelInternal::GetCanceled(PRBool *aCanceled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean channelIsForDownload; */
NS_IMETHODIMP nsHttpChannelInternal::GetChannelIsForDownload(PRBool *aChannelIsForDownload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHttpChannelInternal::SetChannelIsForDownload(PRBool aChannelIsForDownload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHttpChannelInternal_h__ */

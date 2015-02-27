/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIHttpChannel.idl
 */

#ifndef __gen_nsIHttpChannel_h__
#define __gen_nsIHttpChannel_h__


#ifndef __gen_nsIChannel_h__
#include "nsIChannel.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIHttpHeaderVisitor; /* forward declaration */


/* starting interface:    nsIHttpChannel */
#define NS_IHTTPCHANNEL_IID_STR "a01362a0-5c45-11e2-bcfd-0800200c9a66"

#define NS_IHTTPCHANNEL_IID \
  {0xa01362a0, 0x5c45, 0x11e2, \
    { 0xbc, 0xfd, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIHttpChannel : public nsIChannel {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPCHANNEL_IID)

  /* attribute ACString requestMethod; */
  NS_IMETHOD GetRequestMethod(nsACString & aRequestMethod) = 0;
  NS_IMETHOD SetRequestMethod(const nsACString & aRequestMethod) = 0;

  /* attribute nsIURI referrer; */
  NS_IMETHOD GetReferrer(nsIURI * *aReferrer) = 0;
  NS_IMETHOD SetReferrer(nsIURI *aReferrer) = 0;

  /* ACString getRequestHeader (in ACString aHeader); */
  NS_IMETHOD GetRequestHeader(const nsACString & aHeader, nsACString & _retval) = 0;

  /* void setRequestHeader (in ACString aHeader, in ACString aValue, in boolean aMerge); */
  NS_IMETHOD SetRequestHeader(const nsACString & aHeader, const nsACString & aValue, bool aMerge) = 0;

  /* void visitRequestHeaders (in nsIHttpHeaderVisitor aVisitor); */
  NS_IMETHOD VisitRequestHeaders(nsIHttpHeaderVisitor *aVisitor) = 0;

  /* attribute boolean allowPipelining; */
  NS_IMETHOD GetAllowPipelining(bool *aAllowPipelining) = 0;
  NS_IMETHOD SetAllowPipelining(bool aAllowPipelining) = 0;

  /* attribute unsigned long redirectionLimit; */
  NS_IMETHOD GetRedirectionLimit(uint32_t *aRedirectionLimit) = 0;
  NS_IMETHOD SetRedirectionLimit(uint32_t aRedirectionLimit) = 0;

  /* readonly attribute unsigned long responseStatus; */
  NS_IMETHOD GetResponseStatus(uint32_t *aResponseStatus) = 0;

  /* readonly attribute ACString responseStatusText; */
  NS_IMETHOD GetResponseStatusText(nsACString & aResponseStatusText) = 0;

  /* readonly attribute boolean requestSucceeded; */
  NS_IMETHOD GetRequestSucceeded(bool *aRequestSucceeded) = 0;

  /* ACString getResponseHeader (in ACString header); */
  NS_IMETHOD GetResponseHeader(const nsACString & header, nsACString & _retval) = 0;

  /* void setResponseHeader (in ACString header, in ACString value, in boolean merge); */
  NS_IMETHOD SetResponseHeader(const nsACString & header, const nsACString & value, bool merge) = 0;

  /* void visitResponseHeaders (in nsIHttpHeaderVisitor aVisitor); */
  NS_IMETHOD VisitResponseHeaders(nsIHttpHeaderVisitor *aVisitor) = 0;

  /* boolean isNoStoreResponse (); */
  NS_IMETHOD IsNoStoreResponse(bool *_retval) = 0;

  /* boolean isNoCacheResponse (); */
  NS_IMETHOD IsNoCacheResponse(bool *_retval) = 0;

  /* void redirectTo (in nsIURI aNewURI); */
  NS_IMETHOD RedirectTo(nsIURI *aNewURI) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpChannel, NS_IHTTPCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPCHANNEL \
  NS_IMETHOD GetRequestMethod(nsACString & aRequestMethod); \
  NS_IMETHOD SetRequestMethod(const nsACString & aRequestMethod); \
  NS_IMETHOD GetReferrer(nsIURI * *aReferrer); \
  NS_IMETHOD SetReferrer(nsIURI *aReferrer); \
  NS_IMETHOD GetRequestHeader(const nsACString & aHeader, nsACString & _retval); \
  NS_IMETHOD SetRequestHeader(const nsACString & aHeader, const nsACString & aValue, bool aMerge); \
  NS_IMETHOD VisitRequestHeaders(nsIHttpHeaderVisitor *aVisitor); \
  NS_IMETHOD GetAllowPipelining(bool *aAllowPipelining); \
  NS_IMETHOD SetAllowPipelining(bool aAllowPipelining); \
  NS_IMETHOD GetRedirectionLimit(uint32_t *aRedirectionLimit); \
  NS_IMETHOD SetRedirectionLimit(uint32_t aRedirectionLimit); \
  NS_IMETHOD GetResponseStatus(uint32_t *aResponseStatus); \
  NS_IMETHOD GetResponseStatusText(nsACString & aResponseStatusText); \
  NS_IMETHOD GetRequestSucceeded(bool *aRequestSucceeded); \
  NS_IMETHOD GetResponseHeader(const nsACString & header, nsACString & _retval); \
  NS_IMETHOD SetResponseHeader(const nsACString & header, const nsACString & value, bool merge); \
  NS_IMETHOD VisitResponseHeaders(nsIHttpHeaderVisitor *aVisitor); \
  NS_IMETHOD IsNoStoreResponse(bool *_retval); \
  NS_IMETHOD IsNoCacheResponse(bool *_retval); \
  NS_IMETHOD RedirectTo(nsIURI *aNewURI); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPCHANNEL(_to) \
  NS_IMETHOD GetRequestMethod(nsACString & aRequestMethod) { return _to GetRequestMethod(aRequestMethod); } \
  NS_IMETHOD SetRequestMethod(const nsACString & aRequestMethod) { return _to SetRequestMethod(aRequestMethod); } \
  NS_IMETHOD GetReferrer(nsIURI * *aReferrer) { return _to GetReferrer(aReferrer); } \
  NS_IMETHOD SetReferrer(nsIURI *aReferrer) { return _to SetReferrer(aReferrer); } \
  NS_IMETHOD GetRequestHeader(const nsACString & aHeader, nsACString & _retval) { return _to GetRequestHeader(aHeader, _retval); } \
  NS_IMETHOD SetRequestHeader(const nsACString & aHeader, const nsACString & aValue, bool aMerge) { return _to SetRequestHeader(aHeader, aValue, aMerge); } \
  NS_IMETHOD VisitRequestHeaders(nsIHttpHeaderVisitor *aVisitor) { return _to VisitRequestHeaders(aVisitor); } \
  NS_IMETHOD GetAllowPipelining(bool *aAllowPipelining) { return _to GetAllowPipelining(aAllowPipelining); } \
  NS_IMETHOD SetAllowPipelining(bool aAllowPipelining) { return _to SetAllowPipelining(aAllowPipelining); } \
  NS_IMETHOD GetRedirectionLimit(uint32_t *aRedirectionLimit) { return _to GetRedirectionLimit(aRedirectionLimit); } \
  NS_IMETHOD SetRedirectionLimit(uint32_t aRedirectionLimit) { return _to SetRedirectionLimit(aRedirectionLimit); } \
  NS_IMETHOD GetResponseStatus(uint32_t *aResponseStatus) { return _to GetResponseStatus(aResponseStatus); } \
  NS_IMETHOD GetResponseStatusText(nsACString & aResponseStatusText) { return _to GetResponseStatusText(aResponseStatusText); } \
  NS_IMETHOD GetRequestSucceeded(bool *aRequestSucceeded) { return _to GetRequestSucceeded(aRequestSucceeded); } \
  NS_IMETHOD GetResponseHeader(const nsACString & header, nsACString & _retval) { return _to GetResponseHeader(header, _retval); } \
  NS_IMETHOD SetResponseHeader(const nsACString & header, const nsACString & value, bool merge) { return _to SetResponseHeader(header, value, merge); } \
  NS_IMETHOD VisitResponseHeaders(nsIHttpHeaderVisitor *aVisitor) { return _to VisitResponseHeaders(aVisitor); } \
  NS_IMETHOD IsNoStoreResponse(bool *_retval) { return _to IsNoStoreResponse(_retval); } \
  NS_IMETHOD IsNoCacheResponse(bool *_retval) { return _to IsNoCacheResponse(_retval); } \
  NS_IMETHOD RedirectTo(nsIURI *aNewURI) { return _to RedirectTo(aNewURI); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPCHANNEL(_to) \
  NS_IMETHOD GetRequestMethod(nsACString & aRequestMethod) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequestMethod(aRequestMethod); } \
  NS_IMETHOD SetRequestMethod(const nsACString & aRequestMethod) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRequestMethod(aRequestMethod); } \
  NS_IMETHOD GetReferrer(nsIURI * *aReferrer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReferrer(aReferrer); } \
  NS_IMETHOD SetReferrer(nsIURI *aReferrer) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReferrer(aReferrer); } \
  NS_IMETHOD GetRequestHeader(const nsACString & aHeader, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequestHeader(aHeader, _retval); } \
  NS_IMETHOD SetRequestHeader(const nsACString & aHeader, const nsACString & aValue, bool aMerge) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRequestHeader(aHeader, aValue, aMerge); } \
  NS_IMETHOD VisitRequestHeaders(nsIHttpHeaderVisitor *aVisitor) { return !_to ? NS_ERROR_NULL_POINTER : _to->VisitRequestHeaders(aVisitor); } \
  NS_IMETHOD GetAllowPipelining(bool *aAllowPipelining) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowPipelining(aAllowPipelining); } \
  NS_IMETHOD SetAllowPipelining(bool aAllowPipelining) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowPipelining(aAllowPipelining); } \
  NS_IMETHOD GetRedirectionLimit(uint32_t *aRedirectionLimit) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRedirectionLimit(aRedirectionLimit); } \
  NS_IMETHOD SetRedirectionLimit(uint32_t aRedirectionLimit) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRedirectionLimit(aRedirectionLimit); } \
  NS_IMETHOD GetResponseStatus(uint32_t *aResponseStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseStatus(aResponseStatus); } \
  NS_IMETHOD GetResponseStatusText(nsACString & aResponseStatusText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseStatusText(aResponseStatusText); } \
  NS_IMETHOD GetRequestSucceeded(bool *aRequestSucceeded) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequestSucceeded(aRequestSucceeded); } \
  NS_IMETHOD GetResponseHeader(const nsACString & header, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseHeader(header, _retval); } \
  NS_IMETHOD SetResponseHeader(const nsACString & header, const nsACString & value, bool merge) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetResponseHeader(header, value, merge); } \
  NS_IMETHOD VisitResponseHeaders(nsIHttpHeaderVisitor *aVisitor) { return !_to ? NS_ERROR_NULL_POINTER : _to->VisitResponseHeaders(aVisitor); } \
  NS_IMETHOD IsNoStoreResponse(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsNoStoreResponse(_retval); } \
  NS_IMETHOD IsNoCacheResponse(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsNoCacheResponse(_retval); } \
  NS_IMETHOD RedirectTo(nsIURI *aNewURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->RedirectTo(aNewURI); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpChannel : public nsIHttpChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPCHANNEL

  nsHttpChannel();

private:
  ~nsHttpChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHttpChannel, nsIHttpChannel)

nsHttpChannel::nsHttpChannel()
{
  /* member initializers and constructor code */
}

nsHttpChannel::~nsHttpChannel()
{
  /* destructor code */
}

/* attribute ACString requestMethod; */
NS_IMETHODIMP nsHttpChannel::GetRequestMethod(nsACString & aRequestMethod)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHttpChannel::SetRequestMethod(const nsACString & aRequestMethod)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIURI referrer; */
NS_IMETHODIMP nsHttpChannel::GetReferrer(nsIURI * *aReferrer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHttpChannel::SetReferrer(nsIURI *aReferrer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getRequestHeader (in ACString aHeader); */
NS_IMETHODIMP nsHttpChannel::GetRequestHeader(const nsACString & aHeader, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setRequestHeader (in ACString aHeader, in ACString aValue, in boolean aMerge); */
NS_IMETHODIMP nsHttpChannel::SetRequestHeader(const nsACString & aHeader, const nsACString & aValue, bool aMerge)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void visitRequestHeaders (in nsIHttpHeaderVisitor aVisitor); */
NS_IMETHODIMP nsHttpChannel::VisitRequestHeaders(nsIHttpHeaderVisitor *aVisitor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean allowPipelining; */
NS_IMETHODIMP nsHttpChannel::GetAllowPipelining(bool *aAllowPipelining)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHttpChannel::SetAllowPipelining(bool aAllowPipelining)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long redirectionLimit; */
NS_IMETHODIMP nsHttpChannel::GetRedirectionLimit(uint32_t *aRedirectionLimit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHttpChannel::SetRedirectionLimit(uint32_t aRedirectionLimit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long responseStatus; */
NS_IMETHODIMP nsHttpChannel::GetResponseStatus(uint32_t *aResponseStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString responseStatusText; */
NS_IMETHODIMP nsHttpChannel::GetResponseStatusText(nsACString & aResponseStatusText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean requestSucceeded; */
NS_IMETHODIMP nsHttpChannel::GetRequestSucceeded(bool *aRequestSucceeded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getResponseHeader (in ACString header); */
NS_IMETHODIMP nsHttpChannel::GetResponseHeader(const nsACString & header, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setResponseHeader (in ACString header, in ACString value, in boolean merge); */
NS_IMETHODIMP nsHttpChannel::SetResponseHeader(const nsACString & header, const nsACString & value, bool merge)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void visitResponseHeaders (in nsIHttpHeaderVisitor aVisitor); */
NS_IMETHODIMP nsHttpChannel::VisitResponseHeaders(nsIHttpHeaderVisitor *aVisitor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isNoStoreResponse (); */
NS_IMETHODIMP nsHttpChannel::IsNoStoreResponse(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isNoCacheResponse (); */
NS_IMETHODIMP nsHttpChannel::IsNoCacheResponse(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void redirectTo (in nsIURI aNewURI); */
NS_IMETHODIMP nsHttpChannel::RedirectTo(nsIURI *aNewURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHttpChannel_h__ */

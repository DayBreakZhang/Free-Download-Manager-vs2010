/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/docshell/base/nsIDocShellLoadInfo.idl
 */

#ifndef __gen_nsIDocShellLoadInfo_h__
#define __gen_nsIDocShellLoadInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsISHEntry; /* forward declaration */

typedef int32_t  nsDocShellInfoLoadType;


/* starting interface:    nsIDocShellLoadInfo */
#define NS_IDOCSHELLLOADINFO_IID_STR "5b041ea4-6655-434c-b3d3-cbbc9441f86a"

#define NS_IDOCSHELLLOADINFO_IID \
  {0x5b041ea4, 0x6655, 0x434c, \
    { 0xb3, 0xd3, 0xcb, 0xbc, 0x94, 0x41, 0xf8, 0x6a }}

class NS_NO_VTABLE nsIDocShellLoadInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCSHELLLOADINFO_IID)

  /* attribute nsIURI referrer; */
  NS_IMETHOD GetReferrer(nsIURI * *aReferrer) = 0;
  NS_IMETHOD SetReferrer(nsIURI *aReferrer) = 0;

  /* attribute nsISupports owner; */
  NS_IMETHOD GetOwner(nsISupports * *aOwner) = 0;
  NS_IMETHOD SetOwner(nsISupports *aOwner) = 0;

  /* attribute boolean inheritOwner; */
  NS_IMETHOD GetInheritOwner(bool *aInheritOwner) = 0;
  NS_IMETHOD SetInheritOwner(bool aInheritOwner) = 0;

  /* attribute boolean ownerIsExplicit; */
  NS_IMETHOD GetOwnerIsExplicit(bool *aOwnerIsExplicit) = 0;
  NS_IMETHOD SetOwnerIsExplicit(bool aOwnerIsExplicit) = 0;

  enum {
    loadNormal = 0,
    loadNormalReplace = 1,
    loadHistory = 2,
    loadReloadNormal = 3,
    loadReloadBypassCache = 4,
    loadReloadBypassProxy = 5,
    loadReloadBypassProxyAndCache = 6,
    loadLink = 7,
    loadRefresh = 8,
    loadReloadCharsetChange = 9,
    loadBypassHistory = 10,
    loadStopContent = 11,
    loadStopContentAndReplace = 12,
    loadNormalExternal = 13,
    loadNormalBypassCache = 14,
    loadNormalBypassProxy = 15,
    loadNormalBypassProxyAndCache = 16,
    loadPushState = 17,
    loadReplaceBypassCache = 18,
    loadMixedContent = 19
  };

  /* attribute nsDocShellInfoLoadType loadType; */
  NS_IMETHOD GetLoadType(nsDocShellInfoLoadType *aLoadType) = 0;
  NS_IMETHOD SetLoadType(nsDocShellInfoLoadType aLoadType) = 0;

  /* attribute nsISHEntry SHEntry; */
  NS_IMETHOD GetSHEntry(nsISHEntry * *aSHEntry) = 0;
  NS_IMETHOD SetSHEntry(nsISHEntry *aSHEntry) = 0;

  /* attribute wstring target; */
  NS_IMETHOD GetTarget(PRUnichar * *aTarget) = 0;
  NS_IMETHOD SetTarget(const PRUnichar * aTarget) = 0;

  /* attribute nsIInputStream postDataStream; */
  NS_IMETHOD GetPostDataStream(nsIInputStream * *aPostDataStream) = 0;
  NS_IMETHOD SetPostDataStream(nsIInputStream *aPostDataStream) = 0;

  /* attribute nsIInputStream headersStream; */
  NS_IMETHOD GetHeadersStream(nsIInputStream * *aHeadersStream) = 0;
  NS_IMETHOD SetHeadersStream(nsIInputStream *aHeadersStream) = 0;

  /* attribute boolean sendReferrer; */
  NS_IMETHOD GetSendReferrer(bool *aSendReferrer) = 0;
  NS_IMETHOD SetSendReferrer(bool aSendReferrer) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocShellLoadInfo, NS_IDOCSHELLLOADINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCSHELLLOADINFO \
  NS_IMETHOD GetReferrer(nsIURI * *aReferrer); \
  NS_IMETHOD SetReferrer(nsIURI *aReferrer); \
  NS_IMETHOD GetOwner(nsISupports * *aOwner); \
  NS_IMETHOD SetOwner(nsISupports *aOwner); \
  NS_IMETHOD GetInheritOwner(bool *aInheritOwner); \
  NS_IMETHOD SetInheritOwner(bool aInheritOwner); \
  NS_IMETHOD GetOwnerIsExplicit(bool *aOwnerIsExplicit); \
  NS_IMETHOD SetOwnerIsExplicit(bool aOwnerIsExplicit); \
  NS_IMETHOD GetLoadType(nsDocShellInfoLoadType *aLoadType); \
  NS_IMETHOD SetLoadType(nsDocShellInfoLoadType aLoadType); \
  NS_IMETHOD GetSHEntry(nsISHEntry * *aSHEntry); \
  NS_IMETHOD SetSHEntry(nsISHEntry *aSHEntry); \
  NS_IMETHOD GetTarget(PRUnichar * *aTarget); \
  NS_IMETHOD SetTarget(const PRUnichar * aTarget); \
  NS_IMETHOD GetPostDataStream(nsIInputStream * *aPostDataStream); \
  NS_IMETHOD SetPostDataStream(nsIInputStream *aPostDataStream); \
  NS_IMETHOD GetHeadersStream(nsIInputStream * *aHeadersStream); \
  NS_IMETHOD SetHeadersStream(nsIInputStream *aHeadersStream); \
  NS_IMETHOD GetSendReferrer(bool *aSendReferrer); \
  NS_IMETHOD SetSendReferrer(bool aSendReferrer); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCSHELLLOADINFO(_to) \
  NS_IMETHOD GetReferrer(nsIURI * *aReferrer) { return _to GetReferrer(aReferrer); } \
  NS_IMETHOD SetReferrer(nsIURI *aReferrer) { return _to SetReferrer(aReferrer); } \
  NS_IMETHOD GetOwner(nsISupports * *aOwner) { return _to GetOwner(aOwner); } \
  NS_IMETHOD SetOwner(nsISupports *aOwner) { return _to SetOwner(aOwner); } \
  NS_IMETHOD GetInheritOwner(bool *aInheritOwner) { return _to GetInheritOwner(aInheritOwner); } \
  NS_IMETHOD SetInheritOwner(bool aInheritOwner) { return _to SetInheritOwner(aInheritOwner); } \
  NS_IMETHOD GetOwnerIsExplicit(bool *aOwnerIsExplicit) { return _to GetOwnerIsExplicit(aOwnerIsExplicit); } \
  NS_IMETHOD SetOwnerIsExplicit(bool aOwnerIsExplicit) { return _to SetOwnerIsExplicit(aOwnerIsExplicit); } \
  NS_IMETHOD GetLoadType(nsDocShellInfoLoadType *aLoadType) { return _to GetLoadType(aLoadType); } \
  NS_IMETHOD SetLoadType(nsDocShellInfoLoadType aLoadType) { return _to SetLoadType(aLoadType); } \
  NS_IMETHOD GetSHEntry(nsISHEntry * *aSHEntry) { return _to GetSHEntry(aSHEntry); } \
  NS_IMETHOD SetSHEntry(nsISHEntry *aSHEntry) { return _to SetSHEntry(aSHEntry); } \
  NS_IMETHOD GetTarget(PRUnichar * *aTarget) { return _to GetTarget(aTarget); } \
  NS_IMETHOD SetTarget(const PRUnichar * aTarget) { return _to SetTarget(aTarget); } \
  NS_IMETHOD GetPostDataStream(nsIInputStream * *aPostDataStream) { return _to GetPostDataStream(aPostDataStream); } \
  NS_IMETHOD SetPostDataStream(nsIInputStream *aPostDataStream) { return _to SetPostDataStream(aPostDataStream); } \
  NS_IMETHOD GetHeadersStream(nsIInputStream * *aHeadersStream) { return _to GetHeadersStream(aHeadersStream); } \
  NS_IMETHOD SetHeadersStream(nsIInputStream *aHeadersStream) { return _to SetHeadersStream(aHeadersStream); } \
  NS_IMETHOD GetSendReferrer(bool *aSendReferrer) { return _to GetSendReferrer(aSendReferrer); } \
  NS_IMETHOD SetSendReferrer(bool aSendReferrer) { return _to SetSendReferrer(aSendReferrer); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCSHELLLOADINFO(_to) \
  NS_IMETHOD GetReferrer(nsIURI * *aReferrer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReferrer(aReferrer); } \
  NS_IMETHOD SetReferrer(nsIURI *aReferrer) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReferrer(aReferrer); } \
  NS_IMETHOD GetOwner(nsISupports * *aOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOwner(aOwner); } \
  NS_IMETHOD SetOwner(nsISupports *aOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOwner(aOwner); } \
  NS_IMETHOD GetInheritOwner(bool *aInheritOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInheritOwner(aInheritOwner); } \
  NS_IMETHOD SetInheritOwner(bool aInheritOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInheritOwner(aInheritOwner); } \
  NS_IMETHOD GetOwnerIsExplicit(bool *aOwnerIsExplicit) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOwnerIsExplicit(aOwnerIsExplicit); } \
  NS_IMETHOD SetOwnerIsExplicit(bool aOwnerIsExplicit) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOwnerIsExplicit(aOwnerIsExplicit); } \
  NS_IMETHOD GetLoadType(nsDocShellInfoLoadType *aLoadType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadType(aLoadType); } \
  NS_IMETHOD SetLoadType(nsDocShellInfoLoadType aLoadType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLoadType(aLoadType); } \
  NS_IMETHOD GetSHEntry(nsISHEntry * *aSHEntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSHEntry(aSHEntry); } \
  NS_IMETHOD SetSHEntry(nsISHEntry *aSHEntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSHEntry(aSHEntry); } \
  NS_IMETHOD GetTarget(PRUnichar * *aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTarget(aTarget); } \
  NS_IMETHOD SetTarget(const PRUnichar * aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTarget(aTarget); } \
  NS_IMETHOD GetPostDataStream(nsIInputStream * *aPostDataStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPostDataStream(aPostDataStream); } \
  NS_IMETHOD SetPostDataStream(nsIInputStream *aPostDataStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPostDataStream(aPostDataStream); } \
  NS_IMETHOD GetHeadersStream(nsIInputStream * *aHeadersStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeadersStream(aHeadersStream); } \
  NS_IMETHOD SetHeadersStream(nsIInputStream *aHeadersStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHeadersStream(aHeadersStream); } \
  NS_IMETHOD GetSendReferrer(bool *aSendReferrer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSendReferrer(aSendReferrer); } \
  NS_IMETHOD SetSendReferrer(bool aSendReferrer) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSendReferrer(aSendReferrer); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocShellLoadInfo : public nsIDocShellLoadInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCSHELLLOADINFO

  nsDocShellLoadInfo();

private:
  ~nsDocShellLoadInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocShellLoadInfo, nsIDocShellLoadInfo)

nsDocShellLoadInfo::nsDocShellLoadInfo()
{
  /* member initializers and constructor code */
}

nsDocShellLoadInfo::~nsDocShellLoadInfo()
{
  /* destructor code */
}

/* attribute nsIURI referrer; */
NS_IMETHODIMP nsDocShellLoadInfo::GetReferrer(nsIURI * *aReferrer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetReferrer(nsIURI *aReferrer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISupports owner; */
NS_IMETHODIMP nsDocShellLoadInfo::GetOwner(nsISupports * *aOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetOwner(nsISupports *aOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean inheritOwner; */
NS_IMETHODIMP nsDocShellLoadInfo::GetInheritOwner(bool *aInheritOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetInheritOwner(bool aInheritOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean ownerIsExplicit; */
NS_IMETHODIMP nsDocShellLoadInfo::GetOwnerIsExplicit(bool *aOwnerIsExplicit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetOwnerIsExplicit(bool aOwnerIsExplicit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsDocShellInfoLoadType loadType; */
NS_IMETHODIMP nsDocShellLoadInfo::GetLoadType(nsDocShellInfoLoadType *aLoadType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetLoadType(nsDocShellInfoLoadType aLoadType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISHEntry SHEntry; */
NS_IMETHODIMP nsDocShellLoadInfo::GetSHEntry(nsISHEntry * *aSHEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetSHEntry(nsISHEntry *aSHEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring target; */
NS_IMETHODIMP nsDocShellLoadInfo::GetTarget(PRUnichar * *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetTarget(const PRUnichar * aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIInputStream postDataStream; */
NS_IMETHODIMP nsDocShellLoadInfo::GetPostDataStream(nsIInputStream * *aPostDataStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetPostDataStream(nsIInputStream *aPostDataStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIInputStream headersStream; */
NS_IMETHODIMP nsDocShellLoadInfo::GetHeadersStream(nsIInputStream * *aHeadersStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetHeadersStream(nsIInputStream *aHeadersStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean sendReferrer; */
NS_IMETHODIMP nsDocShellLoadInfo::GetSendReferrer(bool *aSendReferrer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetSendReferrer(bool aSendReferrer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDocShellLoadInfo_h__ */

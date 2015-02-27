/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/plugins/base/nsIPluginHost.idl
 */

#ifndef __gen_nsIPluginHost_h__
#define __gen_nsIPluginHost_h__


#ifndef __gen_nspluginroot_h__
#include "nspluginroot.h"
#endif

#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIPluginTag_h__
#include "nsIPluginTag.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define MOZ_PLUGIN_HOST_CONTRACTID \
  "@mozilla.org/plugin/host;1"

/* starting interface:    nsIPluginPlayPreviewInfo */
#define NS_IPLUGINPLAYPREVIEWINFO_IID_STR "f89e7679-0adf-4a30-bda9-1afe1ee270d6"

#define NS_IPLUGINPLAYPREVIEWINFO_IID \
  {0xf89e7679, 0x0adf, 0x4a30, \
    { 0xbd, 0xa9, 0x1a, 0xfe, 0x1e, 0xe2, 0x70, 0xd6 }}

class NS_NO_VTABLE nsIPluginPlayPreviewInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGINPLAYPREVIEWINFO_IID)

  /* readonly attribute AUTF8String mimeType; */
  NS_IMETHOD GetMimeType(nsACString & aMimeType) = 0;

  /* readonly attribute boolean ignoreCTP; */
  NS_IMETHOD GetIgnoreCTP(bool *aIgnoreCTP) = 0;

  /* readonly attribute AUTF8String redirectURL; */
  NS_IMETHOD GetRedirectURL(nsACString & aRedirectURL) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPluginPlayPreviewInfo, NS_IPLUGINPLAYPREVIEWINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGINPLAYPREVIEWINFO \
  NS_IMETHOD GetMimeType(nsACString & aMimeType); \
  NS_IMETHOD GetIgnoreCTP(bool *aIgnoreCTP); \
  NS_IMETHOD GetRedirectURL(nsACString & aRedirectURL); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGINPLAYPREVIEWINFO(_to) \
  NS_IMETHOD GetMimeType(nsACString & aMimeType) { return _to GetMimeType(aMimeType); } \
  NS_IMETHOD GetIgnoreCTP(bool *aIgnoreCTP) { return _to GetIgnoreCTP(aIgnoreCTP); } \
  NS_IMETHOD GetRedirectURL(nsACString & aRedirectURL) { return _to GetRedirectURL(aRedirectURL); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGINPLAYPREVIEWINFO(_to) \
  NS_IMETHOD GetMimeType(nsACString & aMimeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMimeType(aMimeType); } \
  NS_IMETHOD GetIgnoreCTP(bool *aIgnoreCTP) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIgnoreCTP(aIgnoreCTP); } \
  NS_IMETHOD GetRedirectURL(nsACString & aRedirectURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRedirectURL(aRedirectURL); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPluginPlayPreviewInfo : public nsIPluginPlayPreviewInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPLUGINPLAYPREVIEWINFO

  nsPluginPlayPreviewInfo();

private:
  ~nsPluginPlayPreviewInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPluginPlayPreviewInfo, nsIPluginPlayPreviewInfo)

nsPluginPlayPreviewInfo::nsPluginPlayPreviewInfo()
{
  /* member initializers and constructor code */
}

nsPluginPlayPreviewInfo::~nsPluginPlayPreviewInfo()
{
  /* destructor code */
}

/* readonly attribute AUTF8String mimeType; */
NS_IMETHODIMP nsPluginPlayPreviewInfo::GetMimeType(nsACString & aMimeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean ignoreCTP; */
NS_IMETHODIMP nsPluginPlayPreviewInfo::GetIgnoreCTP(bool *aIgnoreCTP)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String redirectURL; */
NS_IMETHODIMP nsPluginPlayPreviewInfo::GetRedirectURL(nsACString & aRedirectURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIPluginHost */
#define NS_IPLUGINHOST_IID_STR "15f97490-7bdf-4947-885c-9258072af878"

#define NS_IPLUGINHOST_IID \
  {0x15f97490, 0x7bdf, 0x4947, \
    { 0x88, 0x5c, 0x92, 0x58, 0x07, 0x2a, 0xf8, 0x78 }}

class NS_NO_VTABLE nsIPluginHost : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGINHOST_IID)

  /* void reloadPlugins (); */
  NS_IMETHOD ReloadPlugins(void) = 0;

  /* void getPluginTags ([optional] out unsigned long aPluginCount, [array, size_is (aPluginCount), retval] out nsIPluginTag aResults); */
  NS_IMETHOD GetPluginTags(uint32_t *aPluginCount, nsIPluginTag * **aResults) = 0;

  enum {
    FLAG_CLEAR_ALL = 0U,
    FLAG_CLEAR_CACHE = 1U
  };

  /* void clearSiteData (in nsIPluginTag plugin, in AUTF8String domain, in uint64_t flags, in int64_t maxAge); */
  NS_IMETHOD ClearSiteData(nsIPluginTag *plugin, const nsACString & domain, uint64_t flags, int64_t maxAge) = 0;

  /* boolean siteHasData (in nsIPluginTag plugin, in AUTF8String domain); */
  NS_IMETHOD SiteHasData(nsIPluginTag *plugin, const nsACString & domain, bool *_retval) = 0;

  /* void registerPlayPreviewMimeType (in AUTF8String mimeType, [optional] in boolean ignoreCTP, [optional] in AUTF8String redirectURL); */
  NS_IMETHOD RegisterPlayPreviewMimeType(const nsACString & mimeType, bool ignoreCTP, const nsACString & redirectURL) = 0;

  /* void unregisterPlayPreviewMimeType (in AUTF8String mimeType); */
  NS_IMETHOD UnregisterPlayPreviewMimeType(const nsACString & mimeType) = 0;

  /* nsIPluginPlayPreviewInfo getPlayPreviewInfo (in AUTF8String mimeType); */
  NS_IMETHOD GetPlayPreviewInfo(const nsACString & mimeType, nsIPluginPlayPreviewInfo * *_retval) = 0;

  /* ACString getPermissionStringForType (in AUTF8String mimeType); */
  NS_IMETHOD GetPermissionStringForType(const nsACString & mimeType, nsACString & _retval) = 0;

  /* bool isPluginClickToPlayForType (in AUTF8String mimeType); */
  NS_IMETHOD IsPluginClickToPlayForType(const nsACString & mimeType, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPluginHost, NS_IPLUGINHOST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGINHOST \
  NS_IMETHOD ReloadPlugins(void); \
  NS_IMETHOD GetPluginTags(uint32_t *aPluginCount, nsIPluginTag * **aResults); \
  NS_IMETHOD ClearSiteData(nsIPluginTag *plugin, const nsACString & domain, uint64_t flags, int64_t maxAge); \
  NS_IMETHOD SiteHasData(nsIPluginTag *plugin, const nsACString & domain, bool *_retval); \
  NS_IMETHOD RegisterPlayPreviewMimeType(const nsACString & mimeType, bool ignoreCTP, const nsACString & redirectURL); \
  NS_IMETHOD UnregisterPlayPreviewMimeType(const nsACString & mimeType); \
  NS_IMETHOD GetPlayPreviewInfo(const nsACString & mimeType, nsIPluginPlayPreviewInfo * *_retval); \
  NS_IMETHOD GetPermissionStringForType(const nsACString & mimeType, nsACString & _retval); \
  NS_IMETHOD IsPluginClickToPlayForType(const nsACString & mimeType, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGINHOST(_to) \
  NS_IMETHOD ReloadPlugins(void) { return _to ReloadPlugins(); } \
  NS_IMETHOD GetPluginTags(uint32_t *aPluginCount, nsIPluginTag * **aResults) { return _to GetPluginTags(aPluginCount, aResults); } \
  NS_IMETHOD ClearSiteData(nsIPluginTag *plugin, const nsACString & domain, uint64_t flags, int64_t maxAge) { return _to ClearSiteData(plugin, domain, flags, maxAge); } \
  NS_IMETHOD SiteHasData(nsIPluginTag *plugin, const nsACString & domain, bool *_retval) { return _to SiteHasData(plugin, domain, _retval); } \
  NS_IMETHOD RegisterPlayPreviewMimeType(const nsACString & mimeType, bool ignoreCTP, const nsACString & redirectURL) { return _to RegisterPlayPreviewMimeType(mimeType, ignoreCTP, redirectURL); } \
  NS_IMETHOD UnregisterPlayPreviewMimeType(const nsACString & mimeType) { return _to UnregisterPlayPreviewMimeType(mimeType); } \
  NS_IMETHOD GetPlayPreviewInfo(const nsACString & mimeType, nsIPluginPlayPreviewInfo * *_retval) { return _to GetPlayPreviewInfo(mimeType, _retval); } \
  NS_IMETHOD GetPermissionStringForType(const nsACString & mimeType, nsACString & _retval) { return _to GetPermissionStringForType(mimeType, _retval); } \
  NS_IMETHOD IsPluginClickToPlayForType(const nsACString & mimeType, bool *_retval) { return _to IsPluginClickToPlayForType(mimeType, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGINHOST(_to) \
  NS_IMETHOD ReloadPlugins(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReloadPlugins(); } \
  NS_IMETHOD GetPluginTags(uint32_t *aPluginCount, nsIPluginTag * **aResults) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPluginTags(aPluginCount, aResults); } \
  NS_IMETHOD ClearSiteData(nsIPluginTag *plugin, const nsACString & domain, uint64_t flags, int64_t maxAge) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearSiteData(plugin, domain, flags, maxAge); } \
  NS_IMETHOD SiteHasData(nsIPluginTag *plugin, const nsACString & domain, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SiteHasData(plugin, domain, _retval); } \
  NS_IMETHOD RegisterPlayPreviewMimeType(const nsACString & mimeType, bool ignoreCTP, const nsACString & redirectURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterPlayPreviewMimeType(mimeType, ignoreCTP, redirectURL); } \
  NS_IMETHOD UnregisterPlayPreviewMimeType(const nsACString & mimeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterPlayPreviewMimeType(mimeType); } \
  NS_IMETHOD GetPlayPreviewInfo(const nsACString & mimeType, nsIPluginPlayPreviewInfo * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlayPreviewInfo(mimeType, _retval); } \
  NS_IMETHOD GetPermissionStringForType(const nsACString & mimeType, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPermissionStringForType(mimeType, _retval); } \
  NS_IMETHOD IsPluginClickToPlayForType(const nsACString & mimeType, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsPluginClickToPlayForType(mimeType, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPluginHost : public nsIPluginHost
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPLUGINHOST

  nsPluginHost();

private:
  ~nsPluginHost();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPluginHost, nsIPluginHost)

nsPluginHost::nsPluginHost()
{
  /* member initializers and constructor code */
}

nsPluginHost::~nsPluginHost()
{
  /* destructor code */
}

/* void reloadPlugins (); */
NS_IMETHODIMP nsPluginHost::ReloadPlugins()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPluginTags ([optional] out unsigned long aPluginCount, [array, size_is (aPluginCount), retval] out nsIPluginTag aResults); */
NS_IMETHODIMP nsPluginHost::GetPluginTags(uint32_t *aPluginCount, nsIPluginTag * **aResults)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearSiteData (in nsIPluginTag plugin, in AUTF8String domain, in uint64_t flags, in int64_t maxAge); */
NS_IMETHODIMP nsPluginHost::ClearSiteData(nsIPluginTag *plugin, const nsACString & domain, uint64_t flags, int64_t maxAge)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean siteHasData (in nsIPluginTag plugin, in AUTF8String domain); */
NS_IMETHODIMP nsPluginHost::SiteHasData(nsIPluginTag *plugin, const nsACString & domain, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerPlayPreviewMimeType (in AUTF8String mimeType, [optional] in boolean ignoreCTP, [optional] in AUTF8String redirectURL); */
NS_IMETHODIMP nsPluginHost::RegisterPlayPreviewMimeType(const nsACString & mimeType, bool ignoreCTP, const nsACString & redirectURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterPlayPreviewMimeType (in AUTF8String mimeType); */
NS_IMETHODIMP nsPluginHost::UnregisterPlayPreviewMimeType(const nsACString & mimeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPluginPlayPreviewInfo getPlayPreviewInfo (in AUTF8String mimeType); */
NS_IMETHODIMP nsPluginHost::GetPlayPreviewInfo(const nsACString & mimeType, nsIPluginPlayPreviewInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getPermissionStringForType (in AUTF8String mimeType); */
NS_IMETHODIMP nsPluginHost::GetPermissionStringForType(const nsACString & mimeType, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool isPluginClickToPlayForType (in AUTF8String mimeType); */
NS_IMETHODIMP nsPluginHost::IsPluginClickToPlayForType(const nsACString & mimeType, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPluginHost_h__ */

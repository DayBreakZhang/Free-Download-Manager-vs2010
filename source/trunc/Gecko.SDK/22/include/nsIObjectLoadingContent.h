/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/content/base/public/nsIObjectLoadingContent.idl
 */

#ifndef __gen_nsIObjectLoadingContent_h__
#define __gen_nsIObjectLoadingContent_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIRequest; /* forward declaration */

class nsIFrame; /* forward declaration */

class nsIObjectFrame; /* forward declaration */

class nsIPluginTag; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIDOMClientRect; /* forward declaration */

class nsIURI; /* forward declaration */

#include "nsNPAPIPluginInstance.h"

/* starting interface:    nsIObjectLoadingContent */
#define NS_IOBJECTLOADINGCONTENT_IID_STR "e2ef99fe-f7d3-422f-a7b4-834e8bdde710"

#define NS_IOBJECTLOADINGCONTENT_IID \
  {0xe2ef99fe, 0xf7d3, 0x422f, \
    { 0xa7, 0xb4, 0x83, 0x4e, 0x8b, 0xdd, 0xe7, 0x10 }}

class NS_NO_VTABLE nsIObjectLoadingContent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IOBJECTLOADINGCONTENT_IID)

  enum {
    TYPE_LOADING = 0U,
    TYPE_IMAGE = 1U,
    TYPE_PLUGIN = 2U,
    TYPE_DOCUMENT = 3U,
    TYPE_NULL = 4U,
    PLUGIN_UNSUPPORTED = 0U,
    PLUGIN_ALTERNATE = 1U,
    PLUGIN_DISABLED = 2U,
    PLUGIN_BLOCKLISTED = 3U,
    PLUGIN_OUTDATED = 4U,
    PLUGIN_CRASHED = 5U,
    PLUGIN_SUPPRESSED = 6U,
    PLUGIN_USER_DISABLED = 7U,
    PLUGIN_CLICK_TO_PLAY = 8U,
    PLUGIN_VULNERABLE_UPDATABLE = 9U,
    PLUGIN_VULNERABLE_NO_UPDATE = 10U,
    PLUGIN_PLAY_PREVIEW = 11U
  };

  /* readonly attribute ACString actualType; */
  NS_IMETHOD GetActualType(nsACString & aActualType) = 0;

  /* readonly attribute unsigned long displayedType; */
  NS_IMETHOD GetDisplayedType(uint32_t *aDisplayedType) = 0;

  /* unsigned long getContentTypeForMIMEType (in AUTF8String aMimeType); */
  NS_IMETHOD GetContentTypeForMIMEType(const nsACString & aMimeType, uint32_t *_retval) = 0;

  /* [noscript] readonly attribute nsNPAPIPluginInstancePtr pluginInstance; */
  NS_IMETHOD GetPluginInstance(nsNPAPIPluginInstance **aPluginInstance) = 0;

  /* [noscript] void hasNewFrame (in nsIObjectFrame aFrame); */
  NS_IMETHOD HasNewFrame(nsIObjectFrame *aFrame) = 0;

  /* [noscript] nsIFrame getPrintFrame (); */
  NS_IMETHOD GetPrintFrame(nsIFrame * *_retval) = 0;

  /* [noscript] void pluginDestroyed (); */
  NS_IMETHOD PluginDestroyed(void) = 0;

  /* [noscript] void pluginCrashed (in nsIPluginTag pluginTag, in AString pluginDumpID, in AString browserDumpID, in boolean submittedCrashReport); */
  NS_IMETHOD PluginCrashed(nsIPluginTag *pluginTag, const nsAString & pluginDumpID, const nsAString & browserDumpID, bool submittedCrashReport) = 0;

  /* void playPlugin (); */
  NS_IMETHOD PlayPlugin(void) = 0;

  /* readonly attribute boolean activated; */
  NS_IMETHOD GetActivated(bool *aActivated) = 0;

  /* [noscript] void stopPluginInstance (); */
  NS_IMETHOD StopPluginInstance(void) = 0;

  /* [noscript] void syncStartPluginInstance (); */
  NS_IMETHOD SyncStartPluginInstance(void) = 0;

  /* [noscript] void asyncStartPluginInstance (); */
  NS_IMETHOD AsyncStartPluginInstance(void) = 0;

  /* [noscript] void initializeFromChannel (in nsIRequest request); */
  NS_IMETHOD InitializeFromChannel(nsIRequest *request) = 0;

  /* [noscript] nsNPAPIPluginInstancePtr scriptRequestPluginInstance (in bool callerIsContentJS); */
  NS_IMETHOD ScriptRequestPluginInstance(bool callerIsContentJS, nsNPAPIPluginInstance **_retval) = 0;

  /* readonly attribute nsIURI srcURI; */
  NS_IMETHOD GetSrcURI(nsIURI * *aSrcURI) = 0;

  /* readonly attribute unsigned long pluginFallbackType; */
  NS_IMETHOD GetPluginFallbackType(uint32_t *aPluginFallbackType) = 0;

  /* readonly attribute bool hasRunningPlugin; */
  NS_IMETHOD GetHasRunningPlugin(bool *aHasRunningPlugin) = 0;

  /* void cancelPlayPreview (); */
  NS_IMETHOD CancelPlayPreview(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIObjectLoadingContent, NS_IOBJECTLOADINGCONTENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIOBJECTLOADINGCONTENT \
  NS_IMETHOD GetActualType(nsACString & aActualType); \
  NS_IMETHOD GetDisplayedType(uint32_t *aDisplayedType); \
  NS_IMETHOD GetContentTypeForMIMEType(const nsACString & aMimeType, uint32_t *_retval); \
  NS_IMETHOD GetPluginInstance(nsNPAPIPluginInstance **aPluginInstance); \
  NS_IMETHOD HasNewFrame(nsIObjectFrame *aFrame); \
  NS_IMETHOD GetPrintFrame(nsIFrame * *_retval); \
  NS_IMETHOD PluginDestroyed(void); \
  NS_IMETHOD PluginCrashed(nsIPluginTag *pluginTag, const nsAString & pluginDumpID, const nsAString & browserDumpID, bool submittedCrashReport); \
  NS_IMETHOD PlayPlugin(void); \
  NS_IMETHOD GetActivated(bool *aActivated); \
  NS_IMETHOD StopPluginInstance(void); \
  NS_IMETHOD SyncStartPluginInstance(void); \
  NS_IMETHOD AsyncStartPluginInstance(void); \
  NS_IMETHOD InitializeFromChannel(nsIRequest *request); \
  NS_IMETHOD ScriptRequestPluginInstance(bool callerIsContentJS, nsNPAPIPluginInstance **_retval); \
  NS_IMETHOD GetSrcURI(nsIURI * *aSrcURI); \
  NS_IMETHOD GetPluginFallbackType(uint32_t *aPluginFallbackType); \
  NS_IMETHOD GetHasRunningPlugin(bool *aHasRunningPlugin); \
  NS_IMETHOD CancelPlayPreview(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIOBJECTLOADINGCONTENT(_to) \
  NS_IMETHOD GetActualType(nsACString & aActualType) { return _to GetActualType(aActualType); } \
  NS_IMETHOD GetDisplayedType(uint32_t *aDisplayedType) { return _to GetDisplayedType(aDisplayedType); } \
  NS_IMETHOD GetContentTypeForMIMEType(const nsACString & aMimeType, uint32_t *_retval) { return _to GetContentTypeForMIMEType(aMimeType, _retval); } \
  NS_IMETHOD GetPluginInstance(nsNPAPIPluginInstance **aPluginInstance) { return _to GetPluginInstance(aPluginInstance); } \
  NS_IMETHOD HasNewFrame(nsIObjectFrame *aFrame) { return _to HasNewFrame(aFrame); } \
  NS_IMETHOD GetPrintFrame(nsIFrame * *_retval) { return _to GetPrintFrame(_retval); } \
  NS_IMETHOD PluginDestroyed(void) { return _to PluginDestroyed(); } \
  NS_IMETHOD PluginCrashed(nsIPluginTag *pluginTag, const nsAString & pluginDumpID, const nsAString & browserDumpID, bool submittedCrashReport) { return _to PluginCrashed(pluginTag, pluginDumpID, browserDumpID, submittedCrashReport); } \
  NS_IMETHOD PlayPlugin(void) { return _to PlayPlugin(); } \
  NS_IMETHOD GetActivated(bool *aActivated) { return _to GetActivated(aActivated); } \
  NS_IMETHOD StopPluginInstance(void) { return _to StopPluginInstance(); } \
  NS_IMETHOD SyncStartPluginInstance(void) { return _to SyncStartPluginInstance(); } \
  NS_IMETHOD AsyncStartPluginInstance(void) { return _to AsyncStartPluginInstance(); } \
  NS_IMETHOD InitializeFromChannel(nsIRequest *request) { return _to InitializeFromChannel(request); } \
  NS_IMETHOD ScriptRequestPluginInstance(bool callerIsContentJS, nsNPAPIPluginInstance **_retval) { return _to ScriptRequestPluginInstance(callerIsContentJS, _retval); } \
  NS_IMETHOD GetSrcURI(nsIURI * *aSrcURI) { return _to GetSrcURI(aSrcURI); } \
  NS_IMETHOD GetPluginFallbackType(uint32_t *aPluginFallbackType) { return _to GetPluginFallbackType(aPluginFallbackType); } \
  NS_IMETHOD GetHasRunningPlugin(bool *aHasRunningPlugin) { return _to GetHasRunningPlugin(aHasRunningPlugin); } \
  NS_IMETHOD CancelPlayPreview(void) { return _to CancelPlayPreview(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIOBJECTLOADINGCONTENT(_to) \
  NS_IMETHOD GetActualType(nsACString & aActualType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActualType(aActualType); } \
  NS_IMETHOD GetDisplayedType(uint32_t *aDisplayedType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisplayedType(aDisplayedType); } \
  NS_IMETHOD GetContentTypeForMIMEType(const nsACString & aMimeType, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentTypeForMIMEType(aMimeType, _retval); } \
  NS_IMETHOD GetPluginInstance(nsNPAPIPluginInstance **aPluginInstance) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPluginInstance(aPluginInstance); } \
  NS_IMETHOD HasNewFrame(nsIObjectFrame *aFrame) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasNewFrame(aFrame); } \
  NS_IMETHOD GetPrintFrame(nsIFrame * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintFrame(_retval); } \
  NS_IMETHOD PluginDestroyed(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PluginDestroyed(); } \
  NS_IMETHOD PluginCrashed(nsIPluginTag *pluginTag, const nsAString & pluginDumpID, const nsAString & browserDumpID, bool submittedCrashReport) { return !_to ? NS_ERROR_NULL_POINTER : _to->PluginCrashed(pluginTag, pluginDumpID, browserDumpID, submittedCrashReport); } \
  NS_IMETHOD PlayPlugin(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PlayPlugin(); } \
  NS_IMETHOD GetActivated(bool *aActivated) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActivated(aActivated); } \
  NS_IMETHOD StopPluginInstance(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StopPluginInstance(); } \
  NS_IMETHOD SyncStartPluginInstance(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SyncStartPluginInstance(); } \
  NS_IMETHOD AsyncStartPluginInstance(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncStartPluginInstance(); } \
  NS_IMETHOD InitializeFromChannel(nsIRequest *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitializeFromChannel(request); } \
  NS_IMETHOD ScriptRequestPluginInstance(bool callerIsContentJS, nsNPAPIPluginInstance **_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScriptRequestPluginInstance(callerIsContentJS, _retval); } \
  NS_IMETHOD GetSrcURI(nsIURI * *aSrcURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSrcURI(aSrcURI); } \
  NS_IMETHOD GetPluginFallbackType(uint32_t *aPluginFallbackType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPluginFallbackType(aPluginFallbackType); } \
  NS_IMETHOD GetHasRunningPlugin(bool *aHasRunningPlugin) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasRunningPlugin(aHasRunningPlugin); } \
  NS_IMETHOD CancelPlayPreview(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CancelPlayPreview(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsObjectLoadingContent : public nsIObjectLoadingContent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIOBJECTLOADINGCONTENT

  nsObjectLoadingContent();

private:
  ~nsObjectLoadingContent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsObjectLoadingContent, nsIObjectLoadingContent)

nsObjectLoadingContent::nsObjectLoadingContent()
{
  /* member initializers and constructor code */
}

nsObjectLoadingContent::~nsObjectLoadingContent()
{
  /* destructor code */
}

/* readonly attribute ACString actualType; */
NS_IMETHODIMP nsObjectLoadingContent::GetActualType(nsACString & aActualType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long displayedType; */
NS_IMETHODIMP nsObjectLoadingContent::GetDisplayedType(uint32_t *aDisplayedType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getContentTypeForMIMEType (in AUTF8String aMimeType); */
NS_IMETHODIMP nsObjectLoadingContent::GetContentTypeForMIMEType(const nsACString & aMimeType, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsNPAPIPluginInstancePtr pluginInstance; */
NS_IMETHODIMP nsObjectLoadingContent::GetPluginInstance(nsNPAPIPluginInstance **aPluginInstance)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void hasNewFrame (in nsIObjectFrame aFrame); */
NS_IMETHODIMP nsObjectLoadingContent::HasNewFrame(nsIObjectFrame *aFrame)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIFrame getPrintFrame (); */
NS_IMETHODIMP nsObjectLoadingContent::GetPrintFrame(nsIFrame * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void pluginDestroyed (); */
NS_IMETHODIMP nsObjectLoadingContent::PluginDestroyed()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void pluginCrashed (in nsIPluginTag pluginTag, in AString pluginDumpID, in AString browserDumpID, in boolean submittedCrashReport); */
NS_IMETHODIMP nsObjectLoadingContent::PluginCrashed(nsIPluginTag *pluginTag, const nsAString & pluginDumpID, const nsAString & browserDumpID, bool submittedCrashReport)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void playPlugin (); */
NS_IMETHODIMP nsObjectLoadingContent::PlayPlugin()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean activated; */
NS_IMETHODIMP nsObjectLoadingContent::GetActivated(bool *aActivated)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void stopPluginInstance (); */
NS_IMETHODIMP nsObjectLoadingContent::StopPluginInstance()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void syncStartPluginInstance (); */
NS_IMETHODIMP nsObjectLoadingContent::SyncStartPluginInstance()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void asyncStartPluginInstance (); */
NS_IMETHODIMP nsObjectLoadingContent::AsyncStartPluginInstance()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initializeFromChannel (in nsIRequest request); */
NS_IMETHODIMP nsObjectLoadingContent::InitializeFromChannel(nsIRequest *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsNPAPIPluginInstancePtr scriptRequestPluginInstance (in bool callerIsContentJS); */
NS_IMETHODIMP nsObjectLoadingContent::ScriptRequestPluginInstance(bool callerIsContentJS, nsNPAPIPluginInstance **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI srcURI; */
NS_IMETHODIMP nsObjectLoadingContent::GetSrcURI(nsIURI * *aSrcURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long pluginFallbackType; */
NS_IMETHODIMP nsObjectLoadingContent::GetPluginFallbackType(uint32_t *aPluginFallbackType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute bool hasRunningPlugin; */
NS_IMETHODIMP nsObjectLoadingContent::GetHasRunningPlugin(bool *aHasRunningPlugin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancelPlayPreview (); */
NS_IMETHODIMP nsObjectLoadingContent::CancelPlayPreview()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIObjectLoadingContent_h__ */

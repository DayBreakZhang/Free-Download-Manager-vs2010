/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/modules/plugin/base/public/nsIPluginHost.idl
 */

#ifndef __gen_nsIPluginHost_h__
#define __gen_nsIPluginHost_h__


#ifndef __gen_nspluginroot_h__
#include "nspluginroot.h"
#endif

#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIPluginInstanceOwner_h__
#include "nsIPluginInstanceOwner.h"
#endif

#ifndef __gen_nsIStreamListener_h__
#include "nsIStreamListener.h"
#endif

#ifndef __gen_nsIStringStream_h__
#include "nsIStringStream.h"
#endif

#ifndef __gen_nsIPluginTag_h__
#include "nsIPluginTag.h"
#endif

#ifndef __gen_nsIFile_h__
#include "nsIFile.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsPluginNativeWindow.h"
#ifdef MOZILLA_INTERNAL_API
#include "nsString.h"
#include "nsNetUtil.h"
#endif
#include "prlink.h"  // for PRLibrary
#define MOZ_PLUGIN_HOST_CONTRACTID \
  "@mozilla.org/plugin/host;1"
class nsIPlugin; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIDOMPlugin; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsIPluginStreamListener; /* forward declaration */


/* starting interface:    nsIPluginHost */
#define NS_IPLUGINHOST_IID_STR "c198deaa-3f93-482d-a47c-85ff6514fe07"

#define NS_IPLUGINHOST_IID \
  {0xc198deaa, 0x3f93, 0x482d, \
    { 0xa4, 0x7c, 0x85, 0xff, 0x65, 0x14, 0xfe, 0x07 }}

class NS_SCRIPTABLE nsIPluginHost : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGINHOST_IID)

  /* [noscript] void init (); */
  NS_IMETHOD Init(void) = 0;

  /* [noscript] void destroy (); */
  NS_IMETHOD Destroy(void) = 0;

  /* [noscript] void loadPlugins (); */
  NS_IMETHOD LoadPlugins(void) = 0;

  /**
   * Causes the plugins directory to be searched again for new plugin 
   * libraries.
   *
   * @param reloadPages - indicates whether currently visible pages should 
   * also be reloaded
   */
  /* void reloadPlugins (in boolean reloadPages); */
  NS_SCRIPTABLE NS_IMETHOD ReloadPlugins(PRBool reloadPages) = 0;

  /* [noscript] nsIPlugin getPlugin (in string aMimeType); */
  NS_IMETHOD GetPlugin(const char *aMimeType, nsIPlugin **_retval NS_OUTPARAM) = 0;

  /* [noscript] void instantiateEmbeddedPlugin (in string aMimeType, in nsIURI aURL, in nsIPluginInstanceOwner aOwner); */
  NS_IMETHOD InstantiateEmbeddedPlugin(const char *aMimeType, nsIURI *aURL, nsIPluginInstanceOwner *aOwner) = 0;

  /* [noscript] void instantiateFullPagePlugin (in string aMimeType, in nsIURI aURI, in nsIPluginInstanceOwner aOwner, out nsIStreamListener aStreamListener); */
  NS_IMETHOD InstantiateFullPagePlugin(const char *aMimeType, nsIURI *aURI, nsIPluginInstanceOwner *aOwner, nsIStreamListener **aStreamListener NS_OUTPARAM) = 0;

  /**
   * Instantiate an embedded plugin for an existing channel. The caller is
   * responsible for opening the channel. It may or may not be already opened
   * when this function is called.
   */
  /* [noscript] nsIStreamListener instantiatePluginForChannel (in nsIChannel aChannel, in nsIPluginInstanceOwner aOwner); */
  NS_IMETHOD InstantiatePluginForChannel(nsIChannel *aChannel, nsIPluginInstanceOwner *aOwner, nsIStreamListener **_retval NS_OUTPARAM) = 0;

  /* [noscript] void setUpPluginInstance (in string aMimeType, in nsIURI aURL, in nsIPluginInstanceOwner aOwner); */
  NS_IMETHOD SetUpPluginInstance(const char *aMimeType, nsIURI *aURL, nsIPluginInstanceOwner *aOwner) = 0;

  /* [noscript] void isPluginEnabledForType (in string aMimeType); */
  NS_IMETHOD IsPluginEnabledForType(const char *aMimeType) = 0;

  /* [noscript] void isPluginEnabledForExtension (in string aExtension, in constCharStarRef aMimeType); */
  NS_IMETHOD IsPluginEnabledForExtension(const char *aExtension, const char * & aMimeType) = 0;

  /* [noscript] readonly attribute unsigned long pluginCount; */
  NS_IMETHOD GetPluginCount(PRUint32 *aPluginCount) = 0;

  /* [noscript] void getPlugins (in unsigned long aPluginCount, out nsIDOMPlugin aPluginArray); */
  NS_IMETHOD GetPlugins(PRUint32 aPluginCount, nsIDOMPlugin **aPluginArray NS_OUTPARAM) = 0;

  /* void getPluginTags ([optional] out unsigned long aPluginCount, [array, size_is (aPluginCount), retval] out nsIPluginTag aResults); */
  NS_SCRIPTABLE NS_IMETHOD GetPluginTags(PRUint32 *aPluginCount NS_OUTPARAM, nsIPluginTag ***aResults NS_OUTPARAM) = 0;

  /* [noscript] void stopPluginInstance (in nsIPluginInstance aInstance); */
  NS_IMETHOD StopPluginInstance(nsIPluginInstance *aInstance) = 0;

  /* [noscript] void handleBadPlugin (in PRLibraryPtr aLibrary, in nsIPluginInstance instance); */
  NS_IMETHOD HandleBadPlugin(PRLibrary *aLibrary, nsIPluginInstance *instance) = 0;

  NS_IMETHOD
  GetURL(nsISupports* pluginInst,
         const char* url,
         const char* target = NULL,
         nsIPluginStreamListener* streamListener = NULL,
         const char* altHost = NULL,
         const char* referrer = NULL,
         PRBool forceJSEnabled = PR_FALSE) = 0;
  NS_IMETHOD
  PostURL(nsISupports* pluginInst,
          const char* url,
          PRUint32 postDataLen,
          const char* postData,
          PRBool isFile = PR_FALSE,
          const char* target = NULL,
          nsIPluginStreamListener* streamListener = NULL,
          const char* altHost = NULL,
          const char* referrer = NULL,
          PRBool forceJSEnabled = PR_FALSE,
          PRUint32 postHeadersLength = 0,
          const char* postHeaders = NULL) = 0;
  /**
   * Fetches a URL.
   *
   * (Corresponds to NPN_GetURL and NPN_GetURLNotify.)
   *
   * @param pluginInst - the plugin making the request. If NULL, the URL
   *  is fetched in the background.
   * @param url - the URL to fetch
   * @param target - the target window into which to load the URL, or NULL if
   *  the data should be returned to the plugin via streamListener.
   * @param streamListener - a stream listener to be used to return data to
   *  the plugin. May be NULL if target is not NULL.
   * @param altHost - an IP-address string that will be used instead of the 
   *  host specified in the URL. This is used to prevent DNS-spoofing 
   *  attacks. Can be defaulted to NULL meaning use the host in the URL.
   * @param referrer - the referring URL (may be NULL)
   * @param forceJSEnabled - forces JavaScript to be enabled for 'javascript:'
   *  URLs, even if the user currently has JavaScript disabled (usually 
   *  specify PR_FALSE) 
   * @result - NS_OK if this operation was successful
   */
/**
   * Posts to a URL with post data and/or post headers.
   *
   * (Corresponds to NPN_PostURL and NPN_PostURLNotify.)
   *
   * @param pluginInst - the plugin making the request. If NULL, the URL
   *  is fetched in the background.
   * @param url - the URL to fetch
   * @param postDataLength - the length of postData (if non-NULL)
   * @param postData - the data to POST. NULL specifies that there is not post
   *  data
   * @param isFile - whether the postData specifies the name of a file to 
   *  post instead of data. The file will be deleted afterwards.
   * @param target - the target window into which to load the URL, or NULL if
   *  the data should be returned to the plugin via streamListener.
   * @param streamListener - a stream listener to be used to return data to
   *  the plugin. May be NULL if target is not NULL.
   * @param altHost - an IP-address string that will be used instead of the 
   *  host specified in the URL. This is used to prevent DNS-spoofing 
   *  attacks. Can be defaulted to NULL meaning use the host in the URL.
   * @param referrer - the referring URL (may be NULL)
   * @param forceJSEnabled - forces JavaScript to be enabled for 'javascript:'
   *  URLs, even if the user currently has JavaScript disabled (usually 
   *  specify PR_FALSE) 
   * @param postHeadersLength - the length of postHeaders (if non-NULL)
   * @param postHeaders - the headers to POST. Must be in the form of
   * "HeaderName: HeaderValue\r\n".  Each header, including the last,
   * must be followed by "\r\n".  NULL specifies that there are no
   * post headers
   * @result - NS_OK if this operation was successful
   */
/**
   * Returns the proxy info for a given URL. The caller is required to
   * free the resulting memory with nsIMalloc::Free. The result will be in the
   * following format
   * 
   *   i)   "DIRECT"  -- no proxy
   *   ii)  "PROXY xxx.xxx.xxx.xxx"   -- use proxy
   *   iii) "SOCKS xxx.xxx.xxx.xxx"  -- use SOCKS
   *   iv)  Mixed. e.g. "PROXY 111.111.111.111;PROXY 112.112.112.112",
   *                    "PROXY 111.111.111.111;SOCKS 112.112.112.112"....
   *
   * Which proxy/SOCKS to use is determined by the plugin.
   */
  /* [noscript] void findProxyForURL (in string aURL, out string aResult); */
  NS_IMETHOD FindProxyForURL(const char *aURL, char **aResult NS_OUTPARAM) = 0;

  /* [noscript] void UserAgent (in nativeChar resultingAgentString); */
  NS_IMETHOD UserAgent(const char * * resultingAgentString) = 0;

  /**
   * This method parses post buffer to find out case insensitive "Content-length" string
   * and CR or LF some where after that, then it assumes there is http headers in
   * the input buffer and continue to search for end of headers (CRLFCRLF or LFLF).
   * It will *always malloc()* output buffer (caller is responsible to free it) 
   * if input buffer starts with LF, which comes from 4.x spec 
   * http://developer.netscape.com/docs/manuals/communicator/plugin/pgfn2.htm#1007754
   * "If no custom headers are required, simply add a blank
   * line ('\n') to the beginning of the file or buffer.",
   * it skips that '\n' and considers rest of the input buffer as data.
   * If "Content-length" string and end of headers is found 
   *   it substitutes single LF with CRLF in the headers, so the end of headers
   *   always will be CRLFCRLF (single CR in headers, if any, remain untouched)
   * else
   *   it puts "Content-length: "+size_of_data+CRLFCRLF at the beginning of the output buffer
   * and memcpy data to the output buffer 
   *
   * On failure outPostData and outPostDataLen will be set in 0.  
   * @param aInPostData      - the post data
   * @param aInPostDataLen   - the length aInPostData
   * @param aOutPostData     - the buffer
   * @param aOutPostDataLen  - the length of aOutPostData
   */
  /* [noscript] void parsePostBufferToFixHeaders (in string aInPostData, in unsigned long aInPostDataLen, out string aOutPostData, out unsigned long aOutPostDataLen); */
  NS_IMETHOD ParsePostBufferToFixHeaders(const char *aInPostData, PRUint32 aInPostDataLen, char **aOutPostData NS_OUTPARAM, PRUint32 *aOutPostDataLen NS_OUTPARAM) = 0;

  /**
   * To create temp file with Content len header in, it will use by http POST
   */
  /* [noscript] nsIFile createTempFileToPost (in string aPostDataURL); */
  NS_IMETHOD CreateTempFileToPost(const char *aPostDataURL, nsIFile **_retval NS_OUTPARAM) = 0;

  /**
   *  Creates a new plugin native window object
   */
  /* [noscript] void newPluginNativeWindow (out nsPluginNativeWindowPtr aPluginNativeWindow); */
  NS_IMETHOD NewPluginNativeWindow(nsPluginNativeWindow **aPluginNativeWindow NS_OUTPARAM) = 0;

  /**
   *  Deletes plugin native window object created by NewPluginNativeWindow
   */
  /* [noscript] void deletePluginNativeWindow (in nsPluginNativeWindowPtr aPluginNativeWindow); */
  NS_IMETHOD DeletePluginNativeWindow(nsPluginNativeWindow *aPluginNativeWindow) = 0;

  /**
   * Instantiate a "dummy" java plugin if a java plugin that supports
   * NPRuntime is installed. This plugin is used for exposing
   * window.java and window.Packages. If the java plugin supports
   * NPRuntime and instantiation was successful, aOwners instance will
   * be non-null, if not, it will be null.
   */
  /* [noscript] void instantiateDummyJavaPlugin (in nsIPluginInstanceOwner aOwner); */
  NS_IMETHOD InstantiateDummyJavaPlugin(nsIPluginInstanceOwner *aOwner) = 0;

  /**
   * Get the plugin name for the plugin instance.
   * @param aInstance the plugin instance object
   * @param aPluginName returns a pointer to a shared readonly string value,
   *        it's only valid for the lifetime of the plugin instance - you must
   *        copy the string value if you need it longer than that.
   */
  /* [noscript] void getPluginName (in nsIPluginInstance aInstance, [shared] out string aPluginName); */
  NS_IMETHOD GetPluginName(nsIPluginInstance *aInstance, const char **aPluginName NS_OUTPARAM) = 0;

  /**
   * Get the plugin tag associated with a given plugin instance.
   * @param aInstance the plugin instance object
   * @return plugin tag object
   */
  /* [noscript] nsIPluginTag getPluginTagForInstance (in nsIPluginInstance aInstance); */
  NS_IMETHOD GetPluginTagForInstance(nsIPluginInstance *aInstance, nsIPluginTag **_retval NS_OUTPARAM) = 0;

  virtual void AddIdleTimeTarget(nsIPluginInstanceOwner* objectFrame, PRBool isVisible) = 0;
  virtual void RemoveIdleTimeTarget(nsIPluginInstanceOwner* objectFrame) = 0;
};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPluginHost, NS_IPLUGINHOST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGINHOST \
  NS_IMETHOD Init(void); \
  NS_IMETHOD Destroy(void); \
  NS_IMETHOD LoadPlugins(void); \
  NS_SCRIPTABLE NS_IMETHOD ReloadPlugins(PRBool reloadPages); \
  NS_IMETHOD GetPlugin(const char *aMimeType, nsIPlugin **_retval NS_OUTPARAM); \
  NS_IMETHOD InstantiateEmbeddedPlugin(const char *aMimeType, nsIURI *aURL, nsIPluginInstanceOwner *aOwner); \
  NS_IMETHOD InstantiateFullPagePlugin(const char *aMimeType, nsIURI *aURI, nsIPluginInstanceOwner *aOwner, nsIStreamListener **aStreamListener NS_OUTPARAM); \
  NS_IMETHOD InstantiatePluginForChannel(nsIChannel *aChannel, nsIPluginInstanceOwner *aOwner, nsIStreamListener **_retval NS_OUTPARAM); \
  NS_IMETHOD SetUpPluginInstance(const char *aMimeType, nsIURI *aURL, nsIPluginInstanceOwner *aOwner); \
  NS_IMETHOD IsPluginEnabledForType(const char *aMimeType); \
  NS_IMETHOD IsPluginEnabledForExtension(const char *aExtension, const char * & aMimeType); \
  NS_IMETHOD GetPluginCount(PRUint32 *aPluginCount); \
  NS_IMETHOD GetPlugins(PRUint32 aPluginCount, nsIDOMPlugin **aPluginArray NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPluginTags(PRUint32 *aPluginCount NS_OUTPARAM, nsIPluginTag ***aResults NS_OUTPARAM); \
  NS_IMETHOD StopPluginInstance(nsIPluginInstance *aInstance); \
  NS_IMETHOD HandleBadPlugin(PRLibrary *aLibrary, nsIPluginInstance *instance); \
  NS_IMETHOD FindProxyForURL(const char *aURL, char **aResult NS_OUTPARAM); \
  NS_IMETHOD UserAgent(const char * * resultingAgentString); \
  NS_IMETHOD ParsePostBufferToFixHeaders(const char *aInPostData, PRUint32 aInPostDataLen, char **aOutPostData NS_OUTPARAM, PRUint32 *aOutPostDataLen NS_OUTPARAM); \
  NS_IMETHOD CreateTempFileToPost(const char *aPostDataURL, nsIFile **_retval NS_OUTPARAM); \
  NS_IMETHOD NewPluginNativeWindow(nsPluginNativeWindow **aPluginNativeWindow NS_OUTPARAM); \
  NS_IMETHOD DeletePluginNativeWindow(nsPluginNativeWindow *aPluginNativeWindow); \
  NS_IMETHOD InstantiateDummyJavaPlugin(nsIPluginInstanceOwner *aOwner); \
  NS_IMETHOD GetPluginName(nsIPluginInstance *aInstance, const char **aPluginName NS_OUTPARAM); \
  NS_IMETHOD GetPluginTagForInstance(nsIPluginInstance *aInstance, nsIPluginTag **_retval NS_OUTPARAM); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGINHOST(_to) \
  NS_IMETHOD Init(void) { return _to Init(); } \
  NS_IMETHOD Destroy(void) { return _to Destroy(); } \
  NS_IMETHOD LoadPlugins(void) { return _to LoadPlugins(); } \
  NS_SCRIPTABLE NS_IMETHOD ReloadPlugins(PRBool reloadPages) { return _to ReloadPlugins(reloadPages); } \
  NS_IMETHOD GetPlugin(const char *aMimeType, nsIPlugin **_retval NS_OUTPARAM) { return _to GetPlugin(aMimeType, _retval); } \
  NS_IMETHOD InstantiateEmbeddedPlugin(const char *aMimeType, nsIURI *aURL, nsIPluginInstanceOwner *aOwner) { return _to InstantiateEmbeddedPlugin(aMimeType, aURL, aOwner); } \
  NS_IMETHOD InstantiateFullPagePlugin(const char *aMimeType, nsIURI *aURI, nsIPluginInstanceOwner *aOwner, nsIStreamListener **aStreamListener NS_OUTPARAM) { return _to InstantiateFullPagePlugin(aMimeType, aURI, aOwner, aStreamListener); } \
  NS_IMETHOD InstantiatePluginForChannel(nsIChannel *aChannel, nsIPluginInstanceOwner *aOwner, nsIStreamListener **_retval NS_OUTPARAM) { return _to InstantiatePluginForChannel(aChannel, aOwner, _retval); } \
  NS_IMETHOD SetUpPluginInstance(const char *aMimeType, nsIURI *aURL, nsIPluginInstanceOwner *aOwner) { return _to SetUpPluginInstance(aMimeType, aURL, aOwner); } \
  NS_IMETHOD IsPluginEnabledForType(const char *aMimeType) { return _to IsPluginEnabledForType(aMimeType); } \
  NS_IMETHOD IsPluginEnabledForExtension(const char *aExtension, const char * & aMimeType) { return _to IsPluginEnabledForExtension(aExtension, aMimeType); } \
  NS_IMETHOD GetPluginCount(PRUint32 *aPluginCount) { return _to GetPluginCount(aPluginCount); } \
  NS_IMETHOD GetPlugins(PRUint32 aPluginCount, nsIDOMPlugin **aPluginArray NS_OUTPARAM) { return _to GetPlugins(aPluginCount, aPluginArray); } \
  NS_SCRIPTABLE NS_IMETHOD GetPluginTags(PRUint32 *aPluginCount NS_OUTPARAM, nsIPluginTag ***aResults NS_OUTPARAM) { return _to GetPluginTags(aPluginCount, aResults); } \
  NS_IMETHOD StopPluginInstance(nsIPluginInstance *aInstance) { return _to StopPluginInstance(aInstance); } \
  NS_IMETHOD HandleBadPlugin(PRLibrary *aLibrary, nsIPluginInstance *instance) { return _to HandleBadPlugin(aLibrary, instance); } \
  NS_IMETHOD FindProxyForURL(const char *aURL, char **aResult NS_OUTPARAM) { return _to FindProxyForURL(aURL, aResult); } \
  NS_IMETHOD UserAgent(const char * * resultingAgentString) { return _to UserAgent(resultingAgentString); } \
  NS_IMETHOD ParsePostBufferToFixHeaders(const char *aInPostData, PRUint32 aInPostDataLen, char **aOutPostData NS_OUTPARAM, PRUint32 *aOutPostDataLen NS_OUTPARAM) { return _to ParsePostBufferToFixHeaders(aInPostData, aInPostDataLen, aOutPostData, aOutPostDataLen); } \
  NS_IMETHOD CreateTempFileToPost(const char *aPostDataURL, nsIFile **_retval NS_OUTPARAM) { return _to CreateTempFileToPost(aPostDataURL, _retval); } \
  NS_IMETHOD NewPluginNativeWindow(nsPluginNativeWindow **aPluginNativeWindow NS_OUTPARAM) { return _to NewPluginNativeWindow(aPluginNativeWindow); } \
  NS_IMETHOD DeletePluginNativeWindow(nsPluginNativeWindow *aPluginNativeWindow) { return _to DeletePluginNativeWindow(aPluginNativeWindow); } \
  NS_IMETHOD InstantiateDummyJavaPlugin(nsIPluginInstanceOwner *aOwner) { return _to InstantiateDummyJavaPlugin(aOwner); } \
  NS_IMETHOD GetPluginName(nsIPluginInstance *aInstance, const char **aPluginName NS_OUTPARAM) { return _to GetPluginName(aInstance, aPluginName); } \
  NS_IMETHOD GetPluginTagForInstance(nsIPluginInstance *aInstance, nsIPluginTag **_retval NS_OUTPARAM) { return _to GetPluginTagForInstance(aInstance, _retval); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGINHOST(_to) \
  NS_IMETHOD Init(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(); } \
  NS_IMETHOD Destroy(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Destroy(); } \
  NS_IMETHOD LoadPlugins(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadPlugins(); } \
  NS_SCRIPTABLE NS_IMETHOD ReloadPlugins(PRBool reloadPages) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReloadPlugins(reloadPages); } \
  NS_IMETHOD GetPlugin(const char *aMimeType, nsIPlugin **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlugin(aMimeType, _retval); } \
  NS_IMETHOD InstantiateEmbeddedPlugin(const char *aMimeType, nsIURI *aURL, nsIPluginInstanceOwner *aOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->InstantiateEmbeddedPlugin(aMimeType, aURL, aOwner); } \
  NS_IMETHOD InstantiateFullPagePlugin(const char *aMimeType, nsIURI *aURI, nsIPluginInstanceOwner *aOwner, nsIStreamListener **aStreamListener NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->InstantiateFullPagePlugin(aMimeType, aURI, aOwner, aStreamListener); } \
  NS_IMETHOD InstantiatePluginForChannel(nsIChannel *aChannel, nsIPluginInstanceOwner *aOwner, nsIStreamListener **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->InstantiatePluginForChannel(aChannel, aOwner, _retval); } \
  NS_IMETHOD SetUpPluginInstance(const char *aMimeType, nsIURI *aURL, nsIPluginInstanceOwner *aOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUpPluginInstance(aMimeType, aURL, aOwner); } \
  NS_IMETHOD IsPluginEnabledForType(const char *aMimeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsPluginEnabledForType(aMimeType); } \
  NS_IMETHOD IsPluginEnabledForExtension(const char *aExtension, const char * & aMimeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsPluginEnabledForExtension(aExtension, aMimeType); } \
  NS_IMETHOD GetPluginCount(PRUint32 *aPluginCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPluginCount(aPluginCount); } \
  NS_IMETHOD GetPlugins(PRUint32 aPluginCount, nsIDOMPlugin **aPluginArray NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlugins(aPluginCount, aPluginArray); } \
  NS_SCRIPTABLE NS_IMETHOD GetPluginTags(PRUint32 *aPluginCount NS_OUTPARAM, nsIPluginTag ***aResults NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPluginTags(aPluginCount, aResults); } \
  NS_IMETHOD StopPluginInstance(nsIPluginInstance *aInstance) { return !_to ? NS_ERROR_NULL_POINTER : _to->StopPluginInstance(aInstance); } \
  NS_IMETHOD HandleBadPlugin(PRLibrary *aLibrary, nsIPluginInstance *instance) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleBadPlugin(aLibrary, instance); } \
  NS_IMETHOD FindProxyForURL(const char *aURL, char **aResult NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindProxyForURL(aURL, aResult); } \
  NS_IMETHOD UserAgent(const char * * resultingAgentString) { return !_to ? NS_ERROR_NULL_POINTER : _to->UserAgent(resultingAgentString); } \
  NS_IMETHOD ParsePostBufferToFixHeaders(const char *aInPostData, PRUint32 aInPostDataLen, char **aOutPostData NS_OUTPARAM, PRUint32 *aOutPostDataLen NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParsePostBufferToFixHeaders(aInPostData, aInPostDataLen, aOutPostData, aOutPostDataLen); } \
  NS_IMETHOD CreateTempFileToPost(const char *aPostDataURL, nsIFile **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateTempFileToPost(aPostDataURL, _retval); } \
  NS_IMETHOD NewPluginNativeWindow(nsPluginNativeWindow **aPluginNativeWindow NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewPluginNativeWindow(aPluginNativeWindow); } \
  NS_IMETHOD DeletePluginNativeWindow(nsPluginNativeWindow *aPluginNativeWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeletePluginNativeWindow(aPluginNativeWindow); } \
  NS_IMETHOD InstantiateDummyJavaPlugin(nsIPluginInstanceOwner *aOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->InstantiateDummyJavaPlugin(aOwner); } \
  NS_IMETHOD GetPluginName(nsIPluginInstance *aInstance, const char **aPluginName NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPluginName(aInstance, aPluginName); } \
  NS_IMETHOD GetPluginTagForInstance(nsIPluginInstance *aInstance, nsIPluginTag **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPluginTagForInstance(aInstance, _retval); } \

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

/* [noscript] void init (); */
NS_IMETHODIMP nsPluginHost::Init()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void destroy (); */
NS_IMETHODIMP nsPluginHost::Destroy()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void loadPlugins (); */
NS_IMETHODIMP nsPluginHost::LoadPlugins()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reloadPlugins (in boolean reloadPages); */
NS_IMETHODIMP nsPluginHost::ReloadPlugins(PRBool reloadPages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIPlugin getPlugin (in string aMimeType); */
NS_IMETHODIMP nsPluginHost::GetPlugin(const char *aMimeType, nsIPlugin **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void instantiateEmbeddedPlugin (in string aMimeType, in nsIURI aURL, in nsIPluginInstanceOwner aOwner); */
NS_IMETHODIMP nsPluginHost::InstantiateEmbeddedPlugin(const char *aMimeType, nsIURI *aURL, nsIPluginInstanceOwner *aOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void instantiateFullPagePlugin (in string aMimeType, in nsIURI aURI, in nsIPluginInstanceOwner aOwner, out nsIStreamListener aStreamListener); */
NS_IMETHODIMP nsPluginHost::InstantiateFullPagePlugin(const char *aMimeType, nsIURI *aURI, nsIPluginInstanceOwner *aOwner, nsIStreamListener **aStreamListener NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIStreamListener instantiatePluginForChannel (in nsIChannel aChannel, in nsIPluginInstanceOwner aOwner); */
NS_IMETHODIMP nsPluginHost::InstantiatePluginForChannel(nsIChannel *aChannel, nsIPluginInstanceOwner *aOwner, nsIStreamListener **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setUpPluginInstance (in string aMimeType, in nsIURI aURL, in nsIPluginInstanceOwner aOwner); */
NS_IMETHODIMP nsPluginHost::SetUpPluginInstance(const char *aMimeType, nsIURI *aURL, nsIPluginInstanceOwner *aOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void isPluginEnabledForType (in string aMimeType); */
NS_IMETHODIMP nsPluginHost::IsPluginEnabledForType(const char *aMimeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void isPluginEnabledForExtension (in string aExtension, in constCharStarRef aMimeType); */
NS_IMETHODIMP nsPluginHost::IsPluginEnabledForExtension(const char *aExtension, const char * & aMimeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute unsigned long pluginCount; */
NS_IMETHODIMP nsPluginHost::GetPluginCount(PRUint32 *aPluginCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getPlugins (in unsigned long aPluginCount, out nsIDOMPlugin aPluginArray); */
NS_IMETHODIMP nsPluginHost::GetPlugins(PRUint32 aPluginCount, nsIDOMPlugin **aPluginArray NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPluginTags ([optional] out unsigned long aPluginCount, [array, size_is (aPluginCount), retval] out nsIPluginTag aResults); */
NS_IMETHODIMP nsPluginHost::GetPluginTags(PRUint32 *aPluginCount NS_OUTPARAM, nsIPluginTag ***aResults NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void stopPluginInstance (in nsIPluginInstance aInstance); */
NS_IMETHODIMP nsPluginHost::StopPluginInstance(nsIPluginInstance *aInstance)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void handleBadPlugin (in PRLibraryPtr aLibrary, in nsIPluginInstance instance); */
NS_IMETHODIMP nsPluginHost::HandleBadPlugin(PRLibrary *aLibrary, nsIPluginInstance *instance)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void findProxyForURL (in string aURL, out string aResult); */
NS_IMETHODIMP nsPluginHost::FindProxyForURL(const char *aURL, char **aResult NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void UserAgent (in nativeChar resultingAgentString); */
NS_IMETHODIMP nsPluginHost::UserAgent(const char * * resultingAgentString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void parsePostBufferToFixHeaders (in string aInPostData, in unsigned long aInPostDataLen, out string aOutPostData, out unsigned long aOutPostDataLen); */
NS_IMETHODIMP nsPluginHost::ParsePostBufferToFixHeaders(const char *aInPostData, PRUint32 aInPostDataLen, char **aOutPostData NS_OUTPARAM, PRUint32 *aOutPostDataLen NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIFile createTempFileToPost (in string aPostDataURL); */
NS_IMETHODIMP nsPluginHost::CreateTempFileToPost(const char *aPostDataURL, nsIFile **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void newPluginNativeWindow (out nsPluginNativeWindowPtr aPluginNativeWindow); */
NS_IMETHODIMP nsPluginHost::NewPluginNativeWindow(nsPluginNativeWindow **aPluginNativeWindow NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void deletePluginNativeWindow (in nsPluginNativeWindowPtr aPluginNativeWindow); */
NS_IMETHODIMP nsPluginHost::DeletePluginNativeWindow(nsPluginNativeWindow *aPluginNativeWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void instantiateDummyJavaPlugin (in nsIPluginInstanceOwner aOwner); */
NS_IMETHODIMP nsPluginHost::InstantiateDummyJavaPlugin(nsIPluginInstanceOwner *aOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getPluginName (in nsIPluginInstance aInstance, [shared] out string aPluginName); */
NS_IMETHODIMP nsPluginHost::GetPluginName(nsIPluginInstance *aInstance, const char **aPluginName NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIPluginTag getPluginTagForInstance (in nsIPluginInstance aInstance); */
NS_IMETHODIMP nsPluginHost::GetPluginTagForInstance(nsIPluginInstance *aInstance, nsIPluginTag **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIPluginHost_MOZILLA_2_0_BRANCH */
#define NS_IPLUGINHOST_MOZILLA_2_0_BRANCH_IID_STR "0b0a2fb8-dc2b-4df2-b721-4b7a4008df6c"

#define NS_IPLUGINHOST_MOZILLA_2_0_BRANCH_IID \
  {0x0b0a2fb8, 0xdc2b, 0x4df2, \
    { 0xb7, 0x21, 0x4b, 0x7a, 0x40, 0x08, 0xdf, 0x6c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIPluginHost_MOZILLA_2_0_BRANCH : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGINHOST_MOZILLA_2_0_BRANCH_IID)

  enum { FLAG_CLEAR_ALL = 0U };

  enum { FLAG_CLEAR_CACHE = 1U };

  /* void clearSiteData (in nsIPluginTag plugin, in AUTF8String domain, in PRUint64 flags, in PRInt64 maxAge); */
  NS_SCRIPTABLE NS_IMETHOD ClearSiteData(nsIPluginTag *plugin, const nsACString & domain, PRUint64 flags, PRInt64 maxAge) = 0;

  /* boolean siteHasData (in nsIPluginTag plugin, in AUTF8String domain); */
  NS_SCRIPTABLE NS_IMETHOD SiteHasData(nsIPluginTag *plugin, const nsACString & domain, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPluginHost_MOZILLA_2_0_BRANCH, NS_IPLUGINHOST_MOZILLA_2_0_BRANCH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGINHOST_MOZILLA_2_0_BRANCH \
  NS_SCRIPTABLE NS_IMETHOD ClearSiteData(nsIPluginTag *plugin, const nsACString & domain, PRUint64 flags, PRInt64 maxAge); \
  NS_SCRIPTABLE NS_IMETHOD SiteHasData(nsIPluginTag *plugin, const nsACString & domain, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGINHOST_MOZILLA_2_0_BRANCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD ClearSiteData(nsIPluginTag *plugin, const nsACString & domain, PRUint64 flags, PRInt64 maxAge) { return _to ClearSiteData(plugin, domain, flags, maxAge); } \
  NS_SCRIPTABLE NS_IMETHOD SiteHasData(nsIPluginTag *plugin, const nsACString & domain, PRBool *_retval NS_OUTPARAM) { return _to SiteHasData(plugin, domain, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGINHOST_MOZILLA_2_0_BRANCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD ClearSiteData(nsIPluginTag *plugin, const nsACString & domain, PRUint64 flags, PRInt64 maxAge) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearSiteData(plugin, domain, flags, maxAge); } \
  NS_SCRIPTABLE NS_IMETHOD SiteHasData(nsIPluginTag *plugin, const nsACString & domain, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SiteHasData(plugin, domain, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPluginHost_MOZILLA_2_0_BRANCH : public nsIPluginHost_MOZILLA_2_0_BRANCH
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPLUGINHOST_MOZILLA_2_0_BRANCH

  nsPluginHost_MOZILLA_2_0_BRANCH();

private:
  ~nsPluginHost_MOZILLA_2_0_BRANCH();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPluginHost_MOZILLA_2_0_BRANCH, nsIPluginHost_MOZILLA_2_0_BRANCH)

nsPluginHost_MOZILLA_2_0_BRANCH::nsPluginHost_MOZILLA_2_0_BRANCH()
{
  /* member initializers and constructor code */
}

nsPluginHost_MOZILLA_2_0_BRANCH::~nsPluginHost_MOZILLA_2_0_BRANCH()
{
  /* destructor code */
}

/* void clearSiteData (in nsIPluginTag plugin, in AUTF8String domain, in PRUint64 flags, in PRInt64 maxAge); */
NS_IMETHODIMP nsPluginHost_MOZILLA_2_0_BRANCH::ClearSiteData(nsIPluginTag *plugin, const nsACString & domain, PRUint64 flags, PRInt64 maxAge)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean siteHasData (in nsIPluginTag plugin, in AUTF8String domain); */
NS_IMETHODIMP nsPluginHost_MOZILLA_2_0_BRANCH::SiteHasData(nsIPluginTag *plugin, const nsACString & domain, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPluginHost_h__ */

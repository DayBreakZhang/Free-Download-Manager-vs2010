/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/modules/plugin/base/public/nsIPluginInstance.idl
 */

#ifndef __gen_nsIPluginInstance_h__
#define __gen_nsIPluginInstance_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIPluginStreamListener_h__
#include "nsIPluginStreamListener.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPluginInstanceOwner; /* forward declaration */

class nsIOutputStream; /* forward declaration */

#include "npapi.h"
#include "nsStringGlue.h"
#include "gfxASurface.h"
#include "ImageLayers.h"
struct JSContext;
struct JSObject;
class gfxASurface;
class gfxContext;
struct nsIntRect;
namespace mozilla {
namespace layers {
class Image;
class ImageContainer;
}
}
#define NPRUNTIME_JSCLASS_NAME "NPObject JS wrapper class"

/* starting interface:    nsIPluginInstance */
#define NS_IPLUGININSTANCE_IID_STR "84994340-e120-4051-824f-d4ee8aef1a3e"

#define NS_IPLUGININSTANCE_IID \
  {0x84994340, 0xe120, 0x4051, \
    { 0x82, 0x4f, 0xd4, 0xee, 0x8a, 0xef, 0x1a, 0x3e }}

class NS_NO_VTABLE nsIPluginInstance : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGININSTANCE_IID)

  /**
     * Initializes a newly created plugin instance.
     * 
     * @param aOwner - the plugin instance owner
     * @param aMime - the mime type for the instance
     * @result      - NS_OK if this operation was successful
     */
  /* void initialize (in nsIPluginInstanceOwner aOwner, in string aMIMEType); */
  NS_IMETHOD Initialize(nsIPluginInstanceOwner *aOwner, const char *aMIMEType) = 0;

  /**
     * Called to instruct the plugin instance to start. This will be
     * called after the plugin is first created and initialized, and
     * may be called after the plugin is stopped (via the Stop method)
     * if the plugin instance is returned to in the browser window's
     * history.
     *
     * @result - NS_OK if this operation was successful
     */
  /* void start (); */
  NS_IMETHOD Start(void) = 0;

  /**
     * Called to instruct the plugin instance to stop, thereby
     * suspending its state.  This method will be called whenever the
     * browser window goes on to display another page and the page
     * containing the plugin goes into the window's history list.
     *
     * @result - NS_OK if this operation was successful
     */
  /* void stop (); */
  NS_IMETHOD Stop(void) = 0;

  /**
     * Called when the window containing the plugin instance changes.
     *
     * (Corresponds to NPP_SetWindow.)
     *
     * @param aWindow - the plugin window structure
     * @result        - NS_OK if this operation was successful
     */
  /* void setWindow (in NPWindowPtr aWindow); */
  NS_IMETHOD SetWindow(NPWindow *aWindow) = 0;

  /**
     * Called to tell the plugin that the initial src/data stream is
     * ready.  Expects the plugin to return a nsIPluginStreamListener.
     *
     * (Corresponds to NPP_NewStream.)
     *
     * @param aListener - listener the browser will use to give the plugin the data
     * @result          - NS_OK if this operation was successful
     */
  /* void newStreamToPlugin (out nsIPluginStreamListener aListener); */
  NS_IMETHOD NewStreamToPlugin(nsIPluginStreamListener **aListener NS_OUTPARAM) = 0;

  /**
     * This operation is called by the plugin instance when it wishes to send
     * a stream of data to the browser. It constructs a new output stream to which
     * the plugin may send the data. When complete, the Close and Release methods
     * should be called on the output stream.
     *
     * (Corresponds to NPN_NewStream.)
     *
     * @param aType   - MIME type of the stream to create
     * @param aTarget - the target window name to receive the data
     * @param aResult - the resulting output stream
     * @result        - NS_OK if this operation was successful
     */
  /* void newStreamFromPlugin (in string aType, in string aTarget, out nsIOutputStream aResult); */
  NS_IMETHOD NewStreamFromPlugin(const char *aType, const char *aTarget, nsIOutputStream **aResult NS_OUTPARAM) = 0;

  /**
     * Called to instruct the plugin instance to print itself to a printer.
     *
     * (Corresponds to NPP_Print.)
     *
     * @param aPlatformPrint - platform-specific printing information
     * @result               - NS_OK if this operation was successful
     */
  /* void print (in NPPrintPtr aPlatformPrint); */
  NS_IMETHOD Print(NPPrint *aPlatformPrint) = 0;

  /**
     * Handles an event.
     *
     * Note that for Unix and Mac the nsPluginEvent structure is different
     * from the old NPEvent structure -- it's no longer the native event
     * record, but is instead a struct. This was done for future extensibility,
     * and so that the Mac could receive the window argument too. For Windows
     * and OS2, it's always been a struct, so there's no change for them.
     *
     * (Corresponds to NPP_HandleEvent.)
     *
     * @param aEvent   - the event to be handled
     * @param aHandled - if non-NULL, set to the NPAPI NPP_HandleEvent
     *                   return value
     * @result - NS_OK if this operation was successful
     */
  /* void handleEvent (in voidPtr aEvent, out PRInt16 aHandled); */
  NS_IMETHOD HandleEvent(void *aEvent, PRInt16 *aHandled NS_OUTPARAM) = 0;

  /** 
     * Corresponds to NPN_InvalidateRect
     */
  /* void invalidateRect (in NPRectPtr aRect); */
  NS_IMETHOD InvalidateRect(NPRect *aRect) = 0;

  /** 
     * Corresponds to NPN_InvalidateRegion
     */
  /* void invalidateRegion (in NPRegion aRegion); */
  NS_IMETHOD InvalidateRegion(NPRegion aRegion) = 0;

  /** 
     * Corresponds to NPN_ForceRedraw
     */
  /* void forceRedraw (); */
  NS_IMETHOD ForceRedraw(void) = 0;

  /**
     * Returns the MIME type of the plugin instance. 
     *
     * (Corresponds to NPP_New's MIMEType argument.)
     *
     * @param aMIMEType - resulting MIME type
     * @result          - NS_OK if this operation was successful
     */
  /* void getMIMEType ([shared, const] out string aValue); */
  NS_IMETHOD GetMIMEType(const char **aValue NS_OUTPARAM) = 0;

  /**
     * Get the JavaScript context to this plugin instance.
     *
     * @param aJSContext - the resulting JavaScript context
     * @result           - NS_OK if this operation was successful
     */
  /* readonly attribute JSContextPtr JSContext; */
  NS_IMETHOD GetJSContext(JSContext **aJSContext) = 0;

  /* attribute nsIPluginInstanceOwner owner; */
  NS_IMETHOD GetOwner(nsIPluginInstanceOwner **aOwner) = 0;
  NS_IMETHOD SetOwner(nsIPluginInstanceOwner *aOwner) = 0;

  /**
     * This operation causes status information to be displayed on the window
     * associated with the plugin instance. 
     *
     * (Corresponds to NPN_Status.)
     *
     * @param aMessage - the status message to display
     * @result         - NS_OK if this operation was successful
     */
  /* void showStatus (in string aMessage); */
  NS_IMETHOD ShowStatus(const char *aMessage) = 0;

  /**
     * Drop our reference to our owner.
     */
  /* void invalidateOwner (); */
  NS_IMETHOD InvalidateOwner(void) = 0;

  /* JSObjectPtr GetJSObject (in JSContextPtr cx); */
  NS_IMETHOD GetJSObject(JSContext *cx, JSObject **_retval NS_OUTPARAM) = 0;

  /* readonly attribute AString formValue; */
  NS_IMETHOD GetFormValue(nsAString & aFormValue) = 0;

  /* void pushPopupsEnabledState (in boolean aEnabled); */
  NS_IMETHOD PushPopupsEnabledState(PRBool aEnabled) = 0;

  /* void popPopupsEnabledState (); */
  NS_IMETHOD PopPopupsEnabledState(void) = 0;

  /* readonly attribute PRUint16 pluginAPIVersion; */
  NS_IMETHOD GetPluginAPIVersion(PRUint16 *aPluginAPIVersion) = 0;

  /* void defineJavaProperties (); */
  NS_IMETHOD DefineJavaProperties(void) = 0;

  /* PRBool shouldCache (); */
  NS_IMETHOD ShouldCache(PRBool *_retval NS_OUTPARAM) = 0;

  /* PRBool isWindowless (); */
  NS_IMETHOD IsWindowless(PRBool *_retval NS_OUTPARAM) = 0;

  /* PRBool isTransparent (); */
  NS_IMETHOD IsTransparent(PRBool *_retval NS_OUTPARAM) = 0;

  /* void getValueFromPlugin (in NPPVariable variable, in voidPtr aValue); */
  NS_IMETHOD GetValueFromPlugin(NPPVariable variable, void *aValue) = 0;

  /* PRInt32 getDrawingModel (); */
  NS_IMETHOD GetDrawingModel(PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
     * async version of SetWindow call
     *
     * @param aWindow  - the plugin window structure
     */
  /* void asyncSetWindow (in NPWindowPtr aWindow); */
  NS_IMETHOD AsyncSetWindow(NPWindow *aWindow) = 0;

  /**
     * Call this each time after the plugin has been painted to the screen
     */
  /* void notifyPainted (); */
  NS_IMETHOD NotifyPainted(void) = 0;

  /**
     * This should return a valid gfxASurface pointer, or null if there is nothing to render yet.
     */
  /* void getSurface (out gfxASurfacePtr aSurface); */
  NS_IMETHOD GetSurface(gfxASurface **aSurface NS_OUTPARAM) = 0;

  /**
     * @return true if plugin module supports async rendering
     */
  /* PRBool useAsyncPainting (); */
  NS_IMETHOD UseAsyncPainting(PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPluginInstance, NS_IPLUGININSTANCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGININSTANCE \
  NS_IMETHOD Initialize(nsIPluginInstanceOwner *aOwner, const char *aMIMEType); \
  NS_IMETHOD Start(void); \
  NS_IMETHOD Stop(void); \
  NS_IMETHOD SetWindow(NPWindow *aWindow); \
  NS_IMETHOD NewStreamToPlugin(nsIPluginStreamListener **aListener NS_OUTPARAM); \
  NS_IMETHOD NewStreamFromPlugin(const char *aType, const char *aTarget, nsIOutputStream **aResult NS_OUTPARAM); \
  NS_IMETHOD Print(NPPrint *aPlatformPrint); \
  NS_IMETHOD HandleEvent(void *aEvent, PRInt16 *aHandled NS_OUTPARAM); \
  NS_IMETHOD InvalidateRect(NPRect *aRect); \
  NS_IMETHOD InvalidateRegion(NPRegion aRegion); \
  NS_IMETHOD ForceRedraw(void); \
  NS_IMETHOD GetMIMEType(const char **aValue NS_OUTPARAM); \
  NS_IMETHOD GetJSContext(JSContext **aJSContext); \
  NS_IMETHOD GetOwner(nsIPluginInstanceOwner **aOwner); \
  NS_IMETHOD SetOwner(nsIPluginInstanceOwner *aOwner); \
  NS_IMETHOD ShowStatus(const char *aMessage); \
  NS_IMETHOD InvalidateOwner(void); \
  NS_IMETHOD GetJSObject(JSContext *cx, JSObject **_retval NS_OUTPARAM); \
  NS_IMETHOD GetFormValue(nsAString & aFormValue); \
  NS_IMETHOD PushPopupsEnabledState(PRBool aEnabled); \
  NS_IMETHOD PopPopupsEnabledState(void); \
  NS_IMETHOD GetPluginAPIVersion(PRUint16 *aPluginAPIVersion); \
  NS_IMETHOD DefineJavaProperties(void); \
  NS_IMETHOD ShouldCache(PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD IsWindowless(PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD IsTransparent(PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD GetValueFromPlugin(NPPVariable variable, void *aValue); \
  NS_IMETHOD GetDrawingModel(PRInt32 *_retval NS_OUTPARAM); \
  NS_IMETHOD AsyncSetWindow(NPWindow *aWindow); \
  NS_IMETHOD NotifyPainted(void); \
  NS_IMETHOD GetSurface(gfxASurface **aSurface NS_OUTPARAM); \
  NS_IMETHOD UseAsyncPainting(PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGININSTANCE(_to) \
  NS_IMETHOD Initialize(nsIPluginInstanceOwner *aOwner, const char *aMIMEType) { return _to Initialize(aOwner, aMIMEType); } \
  NS_IMETHOD Start(void) { return _to Start(); } \
  NS_IMETHOD Stop(void) { return _to Stop(); } \
  NS_IMETHOD SetWindow(NPWindow *aWindow) { return _to SetWindow(aWindow); } \
  NS_IMETHOD NewStreamToPlugin(nsIPluginStreamListener **aListener NS_OUTPARAM) { return _to NewStreamToPlugin(aListener); } \
  NS_IMETHOD NewStreamFromPlugin(const char *aType, const char *aTarget, nsIOutputStream **aResult NS_OUTPARAM) { return _to NewStreamFromPlugin(aType, aTarget, aResult); } \
  NS_IMETHOD Print(NPPrint *aPlatformPrint) { return _to Print(aPlatformPrint); } \
  NS_IMETHOD HandleEvent(void *aEvent, PRInt16 *aHandled NS_OUTPARAM) { return _to HandleEvent(aEvent, aHandled); } \
  NS_IMETHOD InvalidateRect(NPRect *aRect) { return _to InvalidateRect(aRect); } \
  NS_IMETHOD InvalidateRegion(NPRegion aRegion) { return _to InvalidateRegion(aRegion); } \
  NS_IMETHOD ForceRedraw(void) { return _to ForceRedraw(); } \
  NS_IMETHOD GetMIMEType(const char **aValue NS_OUTPARAM) { return _to GetMIMEType(aValue); } \
  NS_IMETHOD GetJSContext(JSContext **aJSContext) { return _to GetJSContext(aJSContext); } \
  NS_IMETHOD GetOwner(nsIPluginInstanceOwner **aOwner) { return _to GetOwner(aOwner); } \
  NS_IMETHOD SetOwner(nsIPluginInstanceOwner *aOwner) { return _to SetOwner(aOwner); } \
  NS_IMETHOD ShowStatus(const char *aMessage) { return _to ShowStatus(aMessage); } \
  NS_IMETHOD InvalidateOwner(void) { return _to InvalidateOwner(); } \
  NS_IMETHOD GetJSObject(JSContext *cx, JSObject **_retval NS_OUTPARAM) { return _to GetJSObject(cx, _retval); } \
  NS_IMETHOD GetFormValue(nsAString & aFormValue) { return _to GetFormValue(aFormValue); } \
  NS_IMETHOD PushPopupsEnabledState(PRBool aEnabled) { return _to PushPopupsEnabledState(aEnabled); } \
  NS_IMETHOD PopPopupsEnabledState(void) { return _to PopPopupsEnabledState(); } \
  NS_IMETHOD GetPluginAPIVersion(PRUint16 *aPluginAPIVersion) { return _to GetPluginAPIVersion(aPluginAPIVersion); } \
  NS_IMETHOD DefineJavaProperties(void) { return _to DefineJavaProperties(); } \
  NS_IMETHOD ShouldCache(PRBool *_retval NS_OUTPARAM) { return _to ShouldCache(_retval); } \
  NS_IMETHOD IsWindowless(PRBool *_retval NS_OUTPARAM) { return _to IsWindowless(_retval); } \
  NS_IMETHOD IsTransparent(PRBool *_retval NS_OUTPARAM) { return _to IsTransparent(_retval); } \
  NS_IMETHOD GetValueFromPlugin(NPPVariable variable, void *aValue) { return _to GetValueFromPlugin(variable, aValue); } \
  NS_IMETHOD GetDrawingModel(PRInt32 *_retval NS_OUTPARAM) { return _to GetDrawingModel(_retval); } \
  NS_IMETHOD AsyncSetWindow(NPWindow *aWindow) { return _to AsyncSetWindow(aWindow); } \
  NS_IMETHOD NotifyPainted(void) { return _to NotifyPainted(); } \
  NS_IMETHOD GetSurface(gfxASurface **aSurface NS_OUTPARAM) { return _to GetSurface(aSurface); } \
  NS_IMETHOD UseAsyncPainting(PRBool *_retval NS_OUTPARAM) { return _to UseAsyncPainting(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGININSTANCE(_to) \
  NS_IMETHOD Initialize(nsIPluginInstanceOwner *aOwner, const char *aMIMEType) { return !_to ? NS_ERROR_NULL_POINTER : _to->Initialize(aOwner, aMIMEType); } \
  NS_IMETHOD Start(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Start(); } \
  NS_IMETHOD Stop(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Stop(); } \
  NS_IMETHOD SetWindow(NPWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWindow(aWindow); } \
  NS_IMETHOD NewStreamToPlugin(nsIPluginStreamListener **aListener NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewStreamToPlugin(aListener); } \
  NS_IMETHOD NewStreamFromPlugin(const char *aType, const char *aTarget, nsIOutputStream **aResult NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewStreamFromPlugin(aType, aTarget, aResult); } \
  NS_IMETHOD Print(NPPrint *aPlatformPrint) { return !_to ? NS_ERROR_NULL_POINTER : _to->Print(aPlatformPrint); } \
  NS_IMETHOD HandleEvent(void *aEvent, PRInt16 *aHandled NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEvent(aEvent, aHandled); } \
  NS_IMETHOD InvalidateRect(NPRect *aRect) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateRect(aRect); } \
  NS_IMETHOD InvalidateRegion(NPRegion aRegion) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateRegion(aRegion); } \
  NS_IMETHOD ForceRedraw(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceRedraw(); } \
  NS_IMETHOD GetMIMEType(const char **aValue NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMIMEType(aValue); } \
  NS_IMETHOD GetJSContext(JSContext **aJSContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSContext(aJSContext); } \
  NS_IMETHOD GetOwner(nsIPluginInstanceOwner **aOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOwner(aOwner); } \
  NS_IMETHOD SetOwner(nsIPluginInstanceOwner *aOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOwner(aOwner); } \
  NS_IMETHOD ShowStatus(const char *aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowStatus(aMessage); } \
  NS_IMETHOD InvalidateOwner(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateOwner(); } \
  NS_IMETHOD GetJSObject(JSContext *cx, JSObject **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSObject(cx, _retval); } \
  NS_IMETHOD GetFormValue(nsAString & aFormValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFormValue(aFormValue); } \
  NS_IMETHOD PushPopupsEnabledState(PRBool aEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->PushPopupsEnabledState(aEnabled); } \
  NS_IMETHOD PopPopupsEnabledState(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PopPopupsEnabledState(); } \
  NS_IMETHOD GetPluginAPIVersion(PRUint16 *aPluginAPIVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPluginAPIVersion(aPluginAPIVersion); } \
  NS_IMETHOD DefineJavaProperties(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DefineJavaProperties(); } \
  NS_IMETHOD ShouldCache(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShouldCache(_retval); } \
  NS_IMETHOD IsWindowless(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsWindowless(_retval); } \
  NS_IMETHOD IsTransparent(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsTransparent(_retval); } \
  NS_IMETHOD GetValueFromPlugin(NPPVariable variable, void *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueFromPlugin(variable, aValue); } \
  NS_IMETHOD GetDrawingModel(PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDrawingModel(_retval); } \
  NS_IMETHOD AsyncSetWindow(NPWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncSetWindow(aWindow); } \
  NS_IMETHOD NotifyPainted(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyPainted(); } \
  NS_IMETHOD GetSurface(gfxASurface **aSurface NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSurface(aSurface); } \
  NS_IMETHOD UseAsyncPainting(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->UseAsyncPainting(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPluginInstance : public nsIPluginInstance
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPLUGININSTANCE

  nsPluginInstance();

private:
  ~nsPluginInstance();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPluginInstance, nsIPluginInstance)

nsPluginInstance::nsPluginInstance()
{
  /* member initializers and constructor code */
}

nsPluginInstance::~nsPluginInstance()
{
  /* destructor code */
}

/* void initialize (in nsIPluginInstanceOwner aOwner, in string aMIMEType); */
NS_IMETHODIMP nsPluginInstance::Initialize(nsIPluginInstanceOwner *aOwner, const char *aMIMEType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void start (); */
NS_IMETHODIMP nsPluginInstance::Start()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stop (); */
NS_IMETHODIMP nsPluginInstance::Stop()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setWindow (in NPWindowPtr aWindow); */
NS_IMETHODIMP nsPluginInstance::SetWindow(NPWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void newStreamToPlugin (out nsIPluginStreamListener aListener); */
NS_IMETHODIMP nsPluginInstance::NewStreamToPlugin(nsIPluginStreamListener **aListener NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void newStreamFromPlugin (in string aType, in string aTarget, out nsIOutputStream aResult); */
NS_IMETHODIMP nsPluginInstance::NewStreamFromPlugin(const char *aType, const char *aTarget, nsIOutputStream **aResult NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void print (in NPPrintPtr aPlatformPrint); */
NS_IMETHODIMP nsPluginInstance::Print(NPPrint *aPlatformPrint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleEvent (in voidPtr aEvent, out PRInt16 aHandled); */
NS_IMETHODIMP nsPluginInstance::HandleEvent(void *aEvent, PRInt16 *aHandled NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateRect (in NPRectPtr aRect); */
NS_IMETHODIMP nsPluginInstance::InvalidateRect(NPRect *aRect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateRegion (in NPRegion aRegion); */
NS_IMETHODIMP nsPluginInstance::InvalidateRegion(NPRegion aRegion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forceRedraw (); */
NS_IMETHODIMP nsPluginInstance::ForceRedraw()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getMIMEType ([shared, const] out string aValue); */
NS_IMETHODIMP nsPluginInstance::GetMIMEType(const char **aValue NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute JSContextPtr JSContext; */
NS_IMETHODIMP nsPluginInstance::GetJSContext(JSContext **aJSContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIPluginInstanceOwner owner; */
NS_IMETHODIMP nsPluginInstance::GetOwner(nsIPluginInstanceOwner **aOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPluginInstance::SetOwner(nsIPluginInstanceOwner *aOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showStatus (in string aMessage); */
NS_IMETHODIMP nsPluginInstance::ShowStatus(const char *aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateOwner (); */
NS_IMETHODIMP nsPluginInstance::InvalidateOwner()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* JSObjectPtr GetJSObject (in JSContextPtr cx); */
NS_IMETHODIMP nsPluginInstance::GetJSObject(JSContext *cx, JSObject **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString formValue; */
NS_IMETHODIMP nsPluginInstance::GetFormValue(nsAString & aFormValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void pushPopupsEnabledState (in boolean aEnabled); */
NS_IMETHODIMP nsPluginInstance::PushPopupsEnabledState(PRBool aEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void popPopupsEnabledState (); */
NS_IMETHODIMP nsPluginInstance::PopPopupsEnabledState()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRUint16 pluginAPIVersion; */
NS_IMETHODIMP nsPluginInstance::GetPluginAPIVersion(PRUint16 *aPluginAPIVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void defineJavaProperties (); */
NS_IMETHODIMP nsPluginInstance::DefineJavaProperties()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRBool shouldCache (); */
NS_IMETHODIMP nsPluginInstance::ShouldCache(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRBool isWindowless (); */
NS_IMETHODIMP nsPluginInstance::IsWindowless(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRBool isTransparent (); */
NS_IMETHODIMP nsPluginInstance::IsTransparent(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getValueFromPlugin (in NPPVariable variable, in voidPtr aValue); */
NS_IMETHODIMP nsPluginInstance::GetValueFromPlugin(NPPVariable variable, void *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRInt32 getDrawingModel (); */
NS_IMETHODIMP nsPluginInstance::GetDrawingModel(PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncSetWindow (in NPWindowPtr aWindow); */
NS_IMETHODIMP nsPluginInstance::AsyncSetWindow(NPWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyPainted (); */
NS_IMETHODIMP nsPluginInstance::NotifyPainted()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSurface (out gfxASurfacePtr aSurface); */
NS_IMETHODIMP nsPluginInstance::GetSurface(gfxASurface **aSurface NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRBool useAsyncPainting (); */
NS_IMETHODIMP nsPluginInstance::UseAsyncPainting(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIPluginInstance_MOZILLA_2_0_BRANCH */
#define NS_IPLUGININSTANCE_MOZILLA_2_0_BRANCH_IID_STR "324f3c02-4fbd-430b-8afa-db083d3867fc"

#define NS_IPLUGININSTANCE_MOZILLA_2_0_BRANCH_IID \
  {0x324f3c02, 0x4fbd, 0x430b, \
    { 0x8a, 0xfa, 0xdb, 0x08, 0x3d, 0x38, 0x67, 0xfc }}

class NS_NO_VTABLE nsIPluginInstance_MOZILLA_2_0_BRANCH : public nsIPluginInstance {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGININSTANCE_MOZILLA_2_0_BRANCH_IID)

  /* PRBool isRemoteDrawingCoreAnimation (); */
  NS_IMETHOD IsRemoteDrawingCoreAnimation(PRBool *_retval NS_OUTPARAM) = 0;

  /* void getImage (in ImageContainerPtr aContainer, out ImagePtr aImage); */
  NS_IMETHOD GetImage(mozilla::layers::ImageContainer *aContainer, mozilla::layers::Image **aImage NS_OUTPARAM) = 0;

  /**
     * This is the second leg in the trip to PluginInstanceParent.  It
     * approximately follows the ReadbackSink API.
     */
  /* void setBackgroundUnknown (); */
  NS_IMETHOD SetBackgroundUnknown(void) = 0;

  /* void beginUpdateBackground (in nsIntRectPtr rect, out gfxContextPtr ctx); */
  NS_IMETHOD BeginUpdateBackground(nsIntRect *rect, gfxContext **ctx NS_OUTPARAM) = 0;

  /* void endUpdateBackground (in gfxContextPtr ctx, in nsIntRectPtr rect); */
  NS_IMETHOD EndUpdateBackground(gfxContext *ctx, nsIntRect *rect) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPluginInstance_MOZILLA_2_0_BRANCH, NS_IPLUGININSTANCE_MOZILLA_2_0_BRANCH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGININSTANCE_MOZILLA_2_0_BRANCH \
  NS_IMETHOD IsRemoteDrawingCoreAnimation(PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD GetImage(mozilla::layers::ImageContainer *aContainer, mozilla::layers::Image **aImage NS_OUTPARAM); \
  NS_IMETHOD SetBackgroundUnknown(void); \
  NS_IMETHOD BeginUpdateBackground(nsIntRect *rect, gfxContext **ctx NS_OUTPARAM); \
  NS_IMETHOD EndUpdateBackground(gfxContext *ctx, nsIntRect *rect); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGININSTANCE_MOZILLA_2_0_BRANCH(_to) \
  NS_IMETHOD IsRemoteDrawingCoreAnimation(PRBool *_retval NS_OUTPARAM) { return _to IsRemoteDrawingCoreAnimation(_retval); } \
  NS_IMETHOD GetImage(mozilla::layers::ImageContainer *aContainer, mozilla::layers::Image **aImage NS_OUTPARAM) { return _to GetImage(aContainer, aImage); } \
  NS_IMETHOD SetBackgroundUnknown(void) { return _to SetBackgroundUnknown(); } \
  NS_IMETHOD BeginUpdateBackground(nsIntRect *rect, gfxContext **ctx NS_OUTPARAM) { return _to BeginUpdateBackground(rect, ctx); } \
  NS_IMETHOD EndUpdateBackground(gfxContext *ctx, nsIntRect *rect) { return _to EndUpdateBackground(ctx, rect); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGININSTANCE_MOZILLA_2_0_BRANCH(_to) \
  NS_IMETHOD IsRemoteDrawingCoreAnimation(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsRemoteDrawingCoreAnimation(_retval); } \
  NS_IMETHOD GetImage(mozilla::layers::ImageContainer *aContainer, mozilla::layers::Image **aImage NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImage(aContainer, aImage); } \
  NS_IMETHOD SetBackgroundUnknown(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBackgroundUnknown(); } \
  NS_IMETHOD BeginUpdateBackground(nsIntRect *rect, gfxContext **ctx NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginUpdateBackground(rect, ctx); } \
  NS_IMETHOD EndUpdateBackground(gfxContext *ctx, nsIntRect *rect) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndUpdateBackground(ctx, rect); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPluginInstance_MOZILLA_2_0_BRANCH : public nsIPluginInstance_MOZILLA_2_0_BRANCH
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPLUGININSTANCE_MOZILLA_2_0_BRANCH

  nsPluginInstance_MOZILLA_2_0_BRANCH();

private:
  ~nsPluginInstance_MOZILLA_2_0_BRANCH();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPluginInstance_MOZILLA_2_0_BRANCH, nsIPluginInstance_MOZILLA_2_0_BRANCH)

nsPluginInstance_MOZILLA_2_0_BRANCH::nsPluginInstance_MOZILLA_2_0_BRANCH()
{
  /* member initializers and constructor code */
}

nsPluginInstance_MOZILLA_2_0_BRANCH::~nsPluginInstance_MOZILLA_2_0_BRANCH()
{
  /* destructor code */
}

/* PRBool isRemoteDrawingCoreAnimation (); */
NS_IMETHODIMP nsPluginInstance_MOZILLA_2_0_BRANCH::IsRemoteDrawingCoreAnimation(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getImage (in ImageContainerPtr aContainer, out ImagePtr aImage); */
NS_IMETHODIMP nsPluginInstance_MOZILLA_2_0_BRANCH::GetImage(mozilla::layers::ImageContainer *aContainer, mozilla::layers::Image **aImage NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setBackgroundUnknown (); */
NS_IMETHODIMP nsPluginInstance_MOZILLA_2_0_BRANCH::SetBackgroundUnknown()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginUpdateBackground (in nsIntRectPtr rect, out gfxContextPtr ctx); */
NS_IMETHODIMP nsPluginInstance_MOZILLA_2_0_BRANCH::BeginUpdateBackground(nsIntRect *rect, gfxContext **ctx NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endUpdateBackground (in gfxContextPtr ctx, in nsIntRectPtr rect); */
NS_IMETHODIMP nsPluginInstance_MOZILLA_2_0_BRANCH::EndUpdateBackground(gfxContext *ctx, nsIntRect *rect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPluginInstance_h__ */

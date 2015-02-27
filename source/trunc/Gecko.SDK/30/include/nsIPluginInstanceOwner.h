/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPluginInstanceOwner.idl
 */

#ifndef __gen_nsIPluginInstanceOwner_h__
#define __gen_nsIPluginInstanceOwner_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nspluginroot_h__
#include "nspluginroot.h"
#endif

#ifndef __gen_nsIInputStream_h__
#include "nsIInputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDocument; /* forward declaration */

#include "npapi.h"
#include "mozilla/EventForwards.h"
class nsNPAPIPluginInstance;
enum nsPluginTagType {
  nsPluginTagType_Unknown,
  nsPluginTagType_Embed,
  nsPluginTagType_Object,
  nsPluginTagType_Applet
};

/* starting interface:    nsIPluginInstanceOwner */
#define NS_IPLUGININSTANCEOWNER_IID_STR "59be4ca5-3cb0-40e6-a111-9a88c8477610"

#define NS_IPLUGININSTANCEOWNER_IID \
  {0x59be4ca5, 0x3cb0, 0x40e6, \
    { 0xa1, 0x11, 0x9a, 0x88, 0xc8, 0x47, 0x76, 0x10 }}

class nsIPluginInstanceOwner : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGININSTANCEOWNER_IID)

  /* void setInstance (in nsNPAPIPluginInstancePtr aInstance); */
  NS_IMETHOD SetInstance(nsNPAPIPluginInstance *aInstance) = 0;

  /* nsNPAPIPluginInstancePtr getInstance (); */
  NS_IMETHOD GetInstance(nsNPAPIPluginInstance **_retval) = 0;

  /* void getWindow (in NPWindowStarRef aWindow); */
  NS_IMETHOD GetWindow(NPWindow * & aWindow) = 0;

  /* readonly attribute int32_t mode; */
  NS_IMETHOD GetMode(int32_t *aMode) = 0;

  /* void createWidget (); */
  NS_IMETHOD CreateWidget(void) = 0;

   /**
   * Called when there is a valid target so that the proper
   * frame can be updated with new content. will not be called
   * with nullptr aTarget.
   */
  NS_IMETHOD
  GetURL(const char *aURL, const char *aTarget, 
         nsIInputStream *aPostStream,
         void *aHeadersData, uint32_t aHeadersDataLen) = 0;
  /* void showStatus (in string aStatusMsg); */
  NS_IMETHOD ShowStatus(const char * aStatusMsg) = 0;

   NS_IMETHOD ShowStatus(const char16_t *aStatusMsg) = 0;
  /* readonly attribute nsIDocument document; */
  NS_IMETHOD GetDocument(nsIDocument * *aDocument) = 0;

  /* void invalidateRect (in NPRectPtr aRect); */
  NS_IMETHOD InvalidateRect(NPRect *aRect) = 0;

  /* void invalidateRegion (in NPRegion aRegion); */
  NS_IMETHOD InvalidateRegion(NPRegion aRegion) = 0;

  /* void redrawPlugin (); */
  NS_IMETHOD RedrawPlugin(void) = 0;

  /* void getNetscapeWindow (in voidPtr aValue); */
  NS_IMETHOD GetNetscapeWindow(void *aValue) = 0;

   virtual NPError ShowNativeContextMenu(NPMenu* menu, void* event) = 0;
  virtual NPBool  ConvertPoint(double sourceX, double sourceY, NPCoordinateSpace sourceSpace,
                               double *destX, double *destY, NPCoordinateSpace destSpace) = 0;
  virtual NPError InitAsyncSurface(NPSize *size, NPImageFormat format,
                                   void *initData, NPAsyncSurface *surface) = 0;
  virtual NPError FinalizeAsyncSurface(NPAsyncSurface *surface) = 0;
  virtual void SetCurrentAsyncSurface(NPAsyncSurface *surface, NPRect *changed) = 0;
  /* void setEventModel (in int32_t eventModel); */
  NS_IMETHOD SetEventModel(int32_t eventModel) = 0;

  /* void callSetWindow (); */
  NS_IMETHOD CallSetWindow(void) = 0;

  /* double getContentsScaleFactor (); */
  NS_IMETHOD GetContentsScaleFactor(double *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPluginInstanceOwner, NS_IPLUGININSTANCEOWNER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGININSTANCEOWNER \
  NS_IMETHOD SetInstance(nsNPAPIPluginInstance *aInstance); \
  NS_IMETHOD GetInstance(nsNPAPIPluginInstance **_retval); \
  NS_IMETHOD GetWindow(NPWindow * & aWindow); \
  NS_IMETHOD GetMode(int32_t *aMode); \
  NS_IMETHOD CreateWidget(void); \
  NS_IMETHOD ShowStatus(const char * aStatusMsg); \
  NS_IMETHOD GetDocument(nsIDocument * *aDocument); \
  NS_IMETHOD InvalidateRect(NPRect *aRect); \
  NS_IMETHOD InvalidateRegion(NPRegion aRegion); \
  NS_IMETHOD RedrawPlugin(void); \
  NS_IMETHOD GetNetscapeWindow(void *aValue); \
  NS_IMETHOD SetEventModel(int32_t eventModel); \
  NS_IMETHOD CallSetWindow(void); \
  NS_IMETHOD GetContentsScaleFactor(double *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGININSTANCEOWNER(_to) \
  NS_IMETHOD SetInstance(nsNPAPIPluginInstance *aInstance) { return _to SetInstance(aInstance); } \
  NS_IMETHOD GetInstance(nsNPAPIPluginInstance **_retval) { return _to GetInstance(_retval); } \
  NS_IMETHOD GetWindow(NPWindow * & aWindow) { return _to GetWindow(aWindow); } \
  NS_IMETHOD GetMode(int32_t *aMode) { return _to GetMode(aMode); } \
  NS_IMETHOD CreateWidget(void) { return _to CreateWidget(); } \
  NS_IMETHOD ShowStatus(const char * aStatusMsg) { return _to ShowStatus(aStatusMsg); } \
  NS_IMETHOD GetDocument(nsIDocument * *aDocument) { return _to GetDocument(aDocument); } \
  NS_IMETHOD InvalidateRect(NPRect *aRect) { return _to InvalidateRect(aRect); } \
  NS_IMETHOD InvalidateRegion(NPRegion aRegion) { return _to InvalidateRegion(aRegion); } \
  NS_IMETHOD RedrawPlugin(void) { return _to RedrawPlugin(); } \
  NS_IMETHOD GetNetscapeWindow(void *aValue) { return _to GetNetscapeWindow(aValue); } \
  NS_IMETHOD SetEventModel(int32_t eventModel) { return _to SetEventModel(eventModel); } \
  NS_IMETHOD CallSetWindow(void) { return _to CallSetWindow(); } \
  NS_IMETHOD GetContentsScaleFactor(double *_retval) { return _to GetContentsScaleFactor(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGININSTANCEOWNER(_to) \
  NS_IMETHOD SetInstance(nsNPAPIPluginInstance *aInstance) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInstance(aInstance); } \
  NS_IMETHOD GetInstance(nsNPAPIPluginInstance **_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInstance(_retval); } \
  NS_IMETHOD GetWindow(NPWindow * & aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindow(aWindow); } \
  NS_IMETHOD GetMode(int32_t *aMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMode(aMode); } \
  NS_IMETHOD CreateWidget(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateWidget(); } \
  NS_IMETHOD ShowStatus(const char * aStatusMsg) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowStatus(aStatusMsg); } \
  NS_IMETHOD GetDocument(nsIDocument * *aDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocument(aDocument); } \
  NS_IMETHOD InvalidateRect(NPRect *aRect) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateRect(aRect); } \
  NS_IMETHOD InvalidateRegion(NPRegion aRegion) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateRegion(aRegion); } \
  NS_IMETHOD RedrawPlugin(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RedrawPlugin(); } \
  NS_IMETHOD GetNetscapeWindow(void *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNetscapeWindow(aValue); } \
  NS_IMETHOD SetEventModel(int32_t eventModel) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEventModel(eventModel); } \
  NS_IMETHOD CallSetWindow(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CallSetWindow(); } \
  NS_IMETHOD GetContentsScaleFactor(double *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentsScaleFactor(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPluginInstanceOwner : public nsIPluginInstanceOwner
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPLUGININSTANCEOWNER

  nsPluginInstanceOwner();

private:
  ~nsPluginInstanceOwner();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPluginInstanceOwner, nsIPluginInstanceOwner)

nsPluginInstanceOwner::nsPluginInstanceOwner()
{
  /* member initializers and constructor code */
}

nsPluginInstanceOwner::~nsPluginInstanceOwner()
{
  /* destructor code */
}

/* void setInstance (in nsNPAPIPluginInstancePtr aInstance); */
NS_IMETHODIMP nsPluginInstanceOwner::SetInstance(nsNPAPIPluginInstance *aInstance)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsNPAPIPluginInstancePtr getInstance (); */
NS_IMETHODIMP nsPluginInstanceOwner::GetInstance(nsNPAPIPluginInstance **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getWindow (in NPWindowStarRef aWindow); */
NS_IMETHODIMP nsPluginInstanceOwner::GetWindow(NPWindow * & aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int32_t mode; */
NS_IMETHODIMP nsPluginInstanceOwner::GetMode(int32_t *aMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void createWidget (); */
NS_IMETHODIMP nsPluginInstanceOwner::CreateWidget()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showStatus (in string aStatusMsg); */
NS_IMETHODIMP nsPluginInstanceOwner::ShowStatus(const char * aStatusMsg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocument document; */
NS_IMETHODIMP nsPluginInstanceOwner::GetDocument(nsIDocument * *aDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateRect (in NPRectPtr aRect); */
NS_IMETHODIMP nsPluginInstanceOwner::InvalidateRect(NPRect *aRect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateRegion (in NPRegion aRegion); */
NS_IMETHODIMP nsPluginInstanceOwner::InvalidateRegion(NPRegion aRegion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void redrawPlugin (); */
NS_IMETHODIMP nsPluginInstanceOwner::RedrawPlugin()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getNetscapeWindow (in voidPtr aValue); */
NS_IMETHODIMP nsPluginInstanceOwner::GetNetscapeWindow(void *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setEventModel (in int32_t eventModel); */
NS_IMETHODIMP nsPluginInstanceOwner::SetEventModel(int32_t eventModel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void callSetWindow (); */
NS_IMETHODIMP nsPluginInstanceOwner::CallSetWindow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* double getContentsScaleFactor (); */
NS_IMETHODIMP nsPluginInstanceOwner::GetContentsScaleFactor(double *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPluginInstanceOwner_h__ */

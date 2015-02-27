/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/modules/plugin/base/public/nsIPluginInstanceOwner.idl
 */

#ifndef __gen_nsIPluginInstanceOwner_h__
#define __gen_nsIPluginInstanceOwner_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nspluginroot_h__
#include "nspluginroot.h"
#endif

#ifndef __gen_nsIPlugin_h__
#include "nsIPlugin.h"
#endif

#ifndef __gen_nsIInputStream_h__
#include "nsIInputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPluginInstance; /* forward declaration */

class nsIDocument; /* forward declaration */

#include "npapi.h"
class nsPluginEvent;

/* starting interface:    nsIPluginInstanceOwner */
#define NS_IPLUGININSTANCEOWNER_IID_STR "b48dc23e-c20b-4292-974e-e8ff97b9f1cc"

#define NS_IPLUGININSTANCEOWNER_IID \
  {0xb48dc23e, 0xc20b, 0x4292, \
    { 0x97, 0x4e, 0xe8, 0xff, 0x97, 0xb9, 0xf1, 0xcc }}

class nsIPluginInstanceOwner : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGININSTANCEOWNER_IID)

  /**
   * Let the owner know what its instance is
   */
  /* void setInstance (in nsIPluginInstance aInstance); */
  NS_IMETHOD SetInstance(nsIPluginInstance *aInstance) = 0;

  /**
   * Get the instance associated with this owner.
   */
  /* void getInstance (in nsIPluginInstanceRef aInstance); */
  NS_IMETHOD GetInstance(nsIPluginInstance* & aInstance) = 0;

  // make getter_AddRefs work
  inline nsresult GetInstance(nsIPluginInstance** aInstance) {
    return GetInstance(*aInstance);
  }
  /**
   * Get a handle to the window structure of the owner.
   * This pointer cannot be made persistent by the caller.
   */
  /* void getWindow (in NPWindowStarRef aWindow); */
  NS_IMETHOD GetWindow(NPWindow * & aWindow) = 0;

  /**
   * Get the display mode for the plugin instance.
   */
  /* readonly attribute PRInt32 mode; */
  NS_IMETHOD GetMode(PRInt32 *aMode) = 0;

  /**
   * Create a place for the plugin to live in the owner's
   * environment. this may or may not create a window
   * depending on the windowless state of the plugin instance.
   */
  /* void createWidget (); */
  NS_IMETHOD CreateWidget(void) = 0;

  /**
   * Called when there is a valid target so that the proper
   * frame can be updated with new content. will not be called
   * with nsnull aTarget.
   */
  NS_IMETHOD
  GetURL(const char *aURL, const char *aTarget, 
         nsIInputStream *aPostStream,
         void *aHeadersData, PRUint32 aHeadersDataLen) = 0;
  /**
   * Show a status message in the host environment.
   */
  /* void showStatus (in string aStatusMsg); */
  NS_IMETHOD ShowStatus(const char *aStatusMsg) = 0;

  NS_IMETHOD ShowStatus(const PRUnichar *aStatusMsg) = 0;
  /**
   * Get the associated document.
   */
  /* readonly attribute nsIDocument document; */
  NS_IMETHOD GetDocument(nsIDocument **aDocument) = 0;

  /**
   * Invalidate the rectangle
   */
  /* void invalidateRect (in NPRectPtr aRect); */
  NS_IMETHOD InvalidateRect(NPRect *aRect) = 0;

  /**
   * Invalidate the region
   */
  /* void invalidateRegion (in NPRegion aRegion); */
  NS_IMETHOD InvalidateRegion(NPRegion aRegion) = 0;

  /**
   * Force a redraw
   */
  /* void forceRedraw (); */
  NS_IMETHOD ForceRedraw(void) = 0;

  /**
   * Get NetscapeWindow, corresponds to NPNVnetscapeWindow
   */
  /* void getNetscapeWindow (in voidPtr aValue); */
  NS_IMETHOD GetNetscapeWindow(void *aValue) = 0;

  virtual NPError ShowNativeContextMenu(NPMenu* menu, void* event) = 0;
  virtual NPBool  ConvertPoint(double sourceX, double sourceY, NPCoordinateSpace sourceSpace,
                               double *destX, double *destY, NPCoordinateSpace destSpace) = 0;
  /**
   * Show native context menu
   */
  /* void setEventModel (in PRInt32 eventModel); */
  NS_IMETHOD SetEventModel(PRInt32 eventModel) = 0;

  virtual void SendIdleEvent() = 0;
};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPluginInstanceOwner, NS_IPLUGININSTANCEOWNER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGININSTANCEOWNER \
  NS_IMETHOD SetInstance(nsIPluginInstance *aInstance); \
  NS_IMETHOD GetInstance(nsIPluginInstance* & aInstance); \
  NS_IMETHOD GetWindow(NPWindow * & aWindow); \
  NS_IMETHOD GetMode(PRInt32 *aMode); \
  NS_IMETHOD CreateWidget(void); \
  NS_IMETHOD ShowStatus(const char *aStatusMsg); \
  NS_IMETHOD GetDocument(nsIDocument **aDocument); \
  NS_IMETHOD InvalidateRect(NPRect *aRect); \
  NS_IMETHOD InvalidateRegion(NPRegion aRegion); \
  NS_IMETHOD ForceRedraw(void); \
  NS_IMETHOD GetNetscapeWindow(void *aValue); \
  NS_IMETHOD SetEventModel(PRInt32 eventModel); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGININSTANCEOWNER(_to) \
  NS_IMETHOD SetInstance(nsIPluginInstance *aInstance) { return _to SetInstance(aInstance); } \
  NS_IMETHOD GetInstance(nsIPluginInstance* & aInstance) { return _to GetInstance(aInstance); } \
  NS_IMETHOD GetWindow(NPWindow * & aWindow) { return _to GetWindow(aWindow); } \
  NS_IMETHOD GetMode(PRInt32 *aMode) { return _to GetMode(aMode); } \
  NS_IMETHOD CreateWidget(void) { return _to CreateWidget(); } \
  NS_IMETHOD ShowStatus(const char *aStatusMsg) { return _to ShowStatus(aStatusMsg); } \
  NS_IMETHOD GetDocument(nsIDocument **aDocument) { return _to GetDocument(aDocument); } \
  NS_IMETHOD InvalidateRect(NPRect *aRect) { return _to InvalidateRect(aRect); } \
  NS_IMETHOD InvalidateRegion(NPRegion aRegion) { return _to InvalidateRegion(aRegion); } \
  NS_IMETHOD ForceRedraw(void) { return _to ForceRedraw(); } \
  NS_IMETHOD GetNetscapeWindow(void *aValue) { return _to GetNetscapeWindow(aValue); } \
  NS_IMETHOD SetEventModel(PRInt32 eventModel) { return _to SetEventModel(eventModel); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGININSTANCEOWNER(_to) \
  NS_IMETHOD SetInstance(nsIPluginInstance *aInstance) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInstance(aInstance); } \
  NS_IMETHOD GetInstance(nsIPluginInstance* & aInstance) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInstance(aInstance); } \
  NS_IMETHOD GetWindow(NPWindow * & aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindow(aWindow); } \
  NS_IMETHOD GetMode(PRInt32 *aMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMode(aMode); } \
  NS_IMETHOD CreateWidget(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateWidget(); } \
  NS_IMETHOD ShowStatus(const char *aStatusMsg) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowStatus(aStatusMsg); } \
  NS_IMETHOD GetDocument(nsIDocument **aDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocument(aDocument); } \
  NS_IMETHOD InvalidateRect(NPRect *aRect) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateRect(aRect); } \
  NS_IMETHOD InvalidateRegion(NPRegion aRegion) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateRegion(aRegion); } \
  NS_IMETHOD ForceRedraw(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceRedraw(); } \
  NS_IMETHOD GetNetscapeWindow(void *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNetscapeWindow(aValue); } \
  NS_IMETHOD SetEventModel(PRInt32 eventModel) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEventModel(eventModel); } \

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

/* void setInstance (in nsIPluginInstance aInstance); */
NS_IMETHODIMP nsPluginInstanceOwner::SetInstance(nsIPluginInstance *aInstance)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getInstance (in nsIPluginInstanceRef aInstance); */
NS_IMETHODIMP nsPluginInstanceOwner::GetInstance(nsIPluginInstance* & aInstance)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getWindow (in NPWindowStarRef aWindow); */
NS_IMETHODIMP nsPluginInstanceOwner::GetWindow(NPWindow * & aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRInt32 mode; */
NS_IMETHODIMP nsPluginInstanceOwner::GetMode(PRInt32 *aMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void createWidget (); */
NS_IMETHODIMP nsPluginInstanceOwner::CreateWidget()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showStatus (in string aStatusMsg); */
NS_IMETHODIMP nsPluginInstanceOwner::ShowStatus(const char *aStatusMsg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocument document; */
NS_IMETHODIMP nsPluginInstanceOwner::GetDocument(nsIDocument **aDocument)
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

/* void forceRedraw (); */
NS_IMETHODIMP nsPluginInstanceOwner::ForceRedraw()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getNetscapeWindow (in voidPtr aValue); */
NS_IMETHODIMP nsPluginInstanceOwner::GetNetscapeWindow(void *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setEventModel (in PRInt32 eventModel); */
NS_IMETHODIMP nsPluginInstanceOwner::SetEventModel(PRInt32 eventModel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIPluginInstanceOwner_MOZILLA_2_0_BRANCH */
#define NS_IPLUGININSTANCEOWNER_MOZILLA_2_0_BRANCH_IID_STR "20504739-4519-45f3-a8f7-fc8afba7ea87"

#define NS_IPLUGININSTANCEOWNER_MOZILLA_2_0_BRANCH_IID \
  {0x20504739, 0x4519, 0x45f3, \
    { 0xa8, 0xf7, 0xfc, 0x8a, 0xfb, 0xa7, 0xea, 0x87 }}

/**
 * This interface extends nsIPluginInstanceOwner for the 2.0 branch
 */
class NS_NO_VTABLE nsIPluginInstanceOwner_MOZILLA_2_0_BRANCH : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGININSTANCEOWNER_MOZILLA_2_0_BRANCH_IID)

  /**
   * Call NPP_SetWindow on the plugin.
   */
  /* void setWindow (); */
  NS_IMETHOD SetWindow(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPluginInstanceOwner_MOZILLA_2_0_BRANCH, NS_IPLUGININSTANCEOWNER_MOZILLA_2_0_BRANCH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGININSTANCEOWNER_MOZILLA_2_0_BRANCH \
  NS_IMETHOD SetWindow(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGININSTANCEOWNER_MOZILLA_2_0_BRANCH(_to) \
  NS_IMETHOD SetWindow(void) { return _to SetWindow(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGININSTANCEOWNER_MOZILLA_2_0_BRANCH(_to) \
  NS_IMETHOD SetWindow(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWindow(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPluginInstanceOwner_MOZILLA_2_0_BRANCH : public nsIPluginInstanceOwner_MOZILLA_2_0_BRANCH
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPLUGININSTANCEOWNER_MOZILLA_2_0_BRANCH

  nsPluginInstanceOwner_MOZILLA_2_0_BRANCH();

private:
  ~nsPluginInstanceOwner_MOZILLA_2_0_BRANCH();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPluginInstanceOwner_MOZILLA_2_0_BRANCH, nsIPluginInstanceOwner_MOZILLA_2_0_BRANCH)

nsPluginInstanceOwner_MOZILLA_2_0_BRANCH::nsPluginInstanceOwner_MOZILLA_2_0_BRANCH()
{
  /* member initializers and constructor code */
}

nsPluginInstanceOwner_MOZILLA_2_0_BRANCH::~nsPluginInstanceOwner_MOZILLA_2_0_BRANCH()
{
  /* destructor code */
}

/* void setWindow (); */
NS_IMETHODIMP nsPluginInstanceOwner_MOZILLA_2_0_BRANCH::SetWindow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPluginInstanceOwner_h__ */

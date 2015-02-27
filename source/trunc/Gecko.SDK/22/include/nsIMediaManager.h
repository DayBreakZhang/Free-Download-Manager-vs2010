/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/media/nsIMediaManager.idl
 */

#ifndef __gen_nsIMediaManager_h__
#define __gen_nsIMediaManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISupportsArray; /* forward declaration */

class nsIDOMWindow; /* forward declaration */

#define NS_MEDIAMANAGERSERVICE_CID {0xabc622ea, 0x9655, 0x4123, {0x80, 0xd9, 0x22, 0x62, 0x1b, 0xdd, 0x54, 0x65}}
#define MEDIAMANAGERSERVICE_CONTRACTID "@mozilla.org/mediaManagerService;1"

/* starting interface:    nsIMediaManagerService */
#define NS_IMEDIAMANAGERSERVICE_IID_STR "2efff6ab-0e3e-4cc4-8f9b-4aaca59a1140"

#define NS_IMEDIAMANAGERSERVICE_IID \
  {0x2efff6ab, 0x0e3e, 0x4cc4, \
    { 0x8f, 0x9b, 0x4a, 0xac, 0xa5, 0x9a, 0x11, 0x40 }}

class NS_NO_VTABLE nsIMediaManagerService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMEDIAMANAGERSERVICE_IID)

  /* readonly attribute nsISupportsArray activeMediaCaptureWindows; */
  NS_IMETHOD GetActiveMediaCaptureWindows(nsISupportsArray * *aActiveMediaCaptureWindows) = 0;

  /* void mediaCaptureWindowState (in nsIDOMWindow aWindow, out boolean aVideo, out boolean aAudio); */
  NS_IMETHOD MediaCaptureWindowState(nsIDOMWindow *aWindow, bool *aVideo, bool *aAudio) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMediaManagerService, NS_IMEDIAMANAGERSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMEDIAMANAGERSERVICE \
  NS_IMETHOD GetActiveMediaCaptureWindows(nsISupportsArray * *aActiveMediaCaptureWindows); \
  NS_IMETHOD MediaCaptureWindowState(nsIDOMWindow *aWindow, bool *aVideo, bool *aAudio); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMEDIAMANAGERSERVICE(_to) \
  NS_IMETHOD GetActiveMediaCaptureWindows(nsISupportsArray * *aActiveMediaCaptureWindows) { return _to GetActiveMediaCaptureWindows(aActiveMediaCaptureWindows); } \
  NS_IMETHOD MediaCaptureWindowState(nsIDOMWindow *aWindow, bool *aVideo, bool *aAudio) { return _to MediaCaptureWindowState(aWindow, aVideo, aAudio); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMEDIAMANAGERSERVICE(_to) \
  NS_IMETHOD GetActiveMediaCaptureWindows(nsISupportsArray * *aActiveMediaCaptureWindows) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActiveMediaCaptureWindows(aActiveMediaCaptureWindows); } \
  NS_IMETHOD MediaCaptureWindowState(nsIDOMWindow *aWindow, bool *aVideo, bool *aAudio) { return !_to ? NS_ERROR_NULL_POINTER : _to->MediaCaptureWindowState(aWindow, aVideo, aAudio); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMediaManagerService : public nsIMediaManagerService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMEDIAMANAGERSERVICE

  nsMediaManagerService();

private:
  ~nsMediaManagerService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMediaManagerService, nsIMediaManagerService)

nsMediaManagerService::nsMediaManagerService()
{
  /* member initializers and constructor code */
}

nsMediaManagerService::~nsMediaManagerService()
{
  /* destructor code */
}

/* readonly attribute nsISupportsArray activeMediaCaptureWindows; */
NS_IMETHODIMP nsMediaManagerService::GetActiveMediaCaptureWindows(nsISupportsArray * *aActiveMediaCaptureWindows)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mediaCaptureWindowState (in nsIDOMWindow aWindow, out boolean aVideo, out boolean aAudio); */
NS_IMETHODIMP nsMediaManagerService::MediaCaptureWindowState(nsIDOMWindow *aWindow, bool *aVideo, bool *aAudio)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMediaManager_h__ */

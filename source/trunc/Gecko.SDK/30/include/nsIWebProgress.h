/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIWebProgress.idl
 */

#ifndef __gen_nsIWebProgress_h__
#define __gen_nsIWebProgress_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIWebProgressListener; /* forward declaration */


/* starting interface:    nsIWebProgress */
#define NS_IWEBPROGRESS_IID_STR "bd0efb3b-1c81-4fb0-b16d-576a2be48a95"

#define NS_IWEBPROGRESS_IID \
  {0xbd0efb3b, 0x1c81, 0x4fb0, \
    { 0xb1, 0x6d, 0x57, 0x6a, 0x2b, 0xe4, 0x8a, 0x95 }}

class NS_NO_VTABLE nsIWebProgress : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBPROGRESS_IID)

  enum {
    NOTIFY_STATE_REQUEST = 1U,
    NOTIFY_STATE_DOCUMENT = 2U,
    NOTIFY_STATE_NETWORK = 4U,
    NOTIFY_STATE_WINDOW = 8U,
    NOTIFY_STATE_ALL = 15U,
    NOTIFY_PROGRESS = 16U,
    NOTIFY_STATUS = 32U,
    NOTIFY_SECURITY = 64U,
    NOTIFY_LOCATION = 128U,
    NOTIFY_REFRESH = 256U,
    NOTIFY_ALL = 511U
  };

  /* void addProgressListener (in nsIWebProgressListener aListener, in unsigned long aNotifyMask); */
  NS_IMETHOD AddProgressListener(nsIWebProgressListener *aListener, uint32_t aNotifyMask) = 0;

  /* void removeProgressListener (in nsIWebProgressListener aListener); */
  NS_IMETHOD RemoveProgressListener(nsIWebProgressListener *aListener) = 0;

  /* readonly attribute nsIDOMWindow DOMWindow; */
  NS_IMETHOD GetDOMWindow(nsIDOMWindow * *aDOMWindow) = 0;

  /* readonly attribute uint64_t DOMWindowID; */
  NS_IMETHOD GetDOMWindowID(uint64_t *aDOMWindowID) = 0;

  /* readonly attribute boolean isTopLevel; */
  NS_IMETHOD GetIsTopLevel(bool *aIsTopLevel) = 0;

  /* readonly attribute boolean isLoadingDocument; */
  NS_IMETHOD GetIsLoadingDocument(bool *aIsLoadingDocument) = 0;

  /* readonly attribute unsigned long loadType; */
  NS_IMETHOD GetLoadType(uint32_t *aLoadType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebProgress, NS_IWEBPROGRESS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBPROGRESS \
  NS_IMETHOD AddProgressListener(nsIWebProgressListener *aListener, uint32_t aNotifyMask); \
  NS_IMETHOD RemoveProgressListener(nsIWebProgressListener *aListener); \
  NS_IMETHOD GetDOMWindow(nsIDOMWindow * *aDOMWindow); \
  NS_IMETHOD GetDOMWindowID(uint64_t *aDOMWindowID); \
  NS_IMETHOD GetIsTopLevel(bool *aIsTopLevel); \
  NS_IMETHOD GetIsLoadingDocument(bool *aIsLoadingDocument); \
  NS_IMETHOD GetLoadType(uint32_t *aLoadType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBPROGRESS(_to) \
  NS_IMETHOD AddProgressListener(nsIWebProgressListener *aListener, uint32_t aNotifyMask) { return _to AddProgressListener(aListener, aNotifyMask); } \
  NS_IMETHOD RemoveProgressListener(nsIWebProgressListener *aListener) { return _to RemoveProgressListener(aListener); } \
  NS_IMETHOD GetDOMWindow(nsIDOMWindow * *aDOMWindow) { return _to GetDOMWindow(aDOMWindow); } \
  NS_IMETHOD GetDOMWindowID(uint64_t *aDOMWindowID) { return _to GetDOMWindowID(aDOMWindowID); } \
  NS_IMETHOD GetIsTopLevel(bool *aIsTopLevel) { return _to GetIsTopLevel(aIsTopLevel); } \
  NS_IMETHOD GetIsLoadingDocument(bool *aIsLoadingDocument) { return _to GetIsLoadingDocument(aIsLoadingDocument); } \
  NS_IMETHOD GetLoadType(uint32_t *aLoadType) { return _to GetLoadType(aLoadType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBPROGRESS(_to) \
  NS_IMETHOD AddProgressListener(nsIWebProgressListener *aListener, uint32_t aNotifyMask) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddProgressListener(aListener, aNotifyMask); } \
  NS_IMETHOD RemoveProgressListener(nsIWebProgressListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveProgressListener(aListener); } \
  NS_IMETHOD GetDOMWindow(nsIDOMWindow * *aDOMWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDOMWindow(aDOMWindow); } \
  NS_IMETHOD GetDOMWindowID(uint64_t *aDOMWindowID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDOMWindowID(aDOMWindowID); } \
  NS_IMETHOD GetIsTopLevel(bool *aIsTopLevel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsTopLevel(aIsTopLevel); } \
  NS_IMETHOD GetIsLoadingDocument(bool *aIsLoadingDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsLoadingDocument(aIsLoadingDocument); } \
  NS_IMETHOD GetLoadType(uint32_t *aLoadType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadType(aLoadType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebProgress : public nsIWebProgress
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBPROGRESS

  nsWebProgress();

private:
  ~nsWebProgress();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebProgress, nsIWebProgress)

nsWebProgress::nsWebProgress()
{
  /* member initializers and constructor code */
}

nsWebProgress::~nsWebProgress()
{
  /* destructor code */
}

/* void addProgressListener (in nsIWebProgressListener aListener, in unsigned long aNotifyMask); */
NS_IMETHODIMP nsWebProgress::AddProgressListener(nsIWebProgressListener *aListener, uint32_t aNotifyMask)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeProgressListener (in nsIWebProgressListener aListener); */
NS_IMETHODIMP nsWebProgress::RemoveProgressListener(nsIWebProgressListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow DOMWindow; */
NS_IMETHODIMP nsWebProgress::GetDOMWindow(nsIDOMWindow * *aDOMWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint64_t DOMWindowID; */
NS_IMETHODIMP nsWebProgress::GetDOMWindowID(uint64_t *aDOMWindowID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isTopLevel; */
NS_IMETHODIMP nsWebProgress::GetIsTopLevel(bool *aIsTopLevel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isLoadingDocument; */
NS_IMETHODIMP nsWebProgress::GetIsLoadingDocument(bool *aIsLoadingDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long loadType; */
NS_IMETHODIMP nsWebProgress::GetLoadType(uint32_t *aLoadType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebProgress_h__ */

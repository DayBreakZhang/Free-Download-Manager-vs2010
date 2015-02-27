/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/layout/printing/nsIPrintProgress.idl
 */

#ifndef __gen_nsIPrintProgress_h__
#define __gen_nsIPrintProgress_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIWebProgressListener_h__
#include "nsIWebProgressListener.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIObserver; /* forward declaration */

class nsIPrompt; /* forward declaration */


/* starting interface:    nsIPrintProgress */
#define NS_IPRINTPROGRESS_IID_STR "594fd36d-5b1b-412f-a74e-ab72099a5bb2"

#define NS_IPRINTPROGRESS_IID \
  {0x594fd36d, 0x5b1b, 0x412f, \
    { 0xa7, 0x4e, 0xab, 0x72, 0x09, 0x9a, 0x5b, 0xb2 }}

class NS_NO_VTABLE nsIPrintProgress : public nsIWebProgressListener {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRINTPROGRESS_IID)

  /* void openProgressDialog (in nsIDOMWindow parent, in string dialogURL, in nsISupports parameters, in nsIObserver openDialogObserver, out boolean notifyOnOpen); */
  NS_IMETHOD OpenProgressDialog(nsIDOMWindow *parent, const char * dialogURL, nsISupports *parameters, nsIObserver *openDialogObserver, bool *notifyOnOpen) = 0;

  /* void closeProgressDialog (in boolean forceClose); */
  NS_IMETHOD CloseProgressDialog(bool forceClose) = 0;

  /* void registerListener (in nsIWebProgressListener listener); */
  NS_IMETHOD RegisterListener(nsIWebProgressListener *listener) = 0;

  /* void unregisterListener (in nsIWebProgressListener listener); */
  NS_IMETHOD UnregisterListener(nsIWebProgressListener *listener) = 0;

  /* void doneIniting (); */
  NS_IMETHOD DoneIniting(void) = 0;

  /* nsIPrompt getPrompter (); */
  NS_IMETHOD GetPrompter(nsIPrompt * *_retval) = 0;

  /* attribute boolean processCanceledByUser; */
  NS_IMETHOD GetProcessCanceledByUser(bool *aProcessCanceledByUser) = 0;
  NS_IMETHOD SetProcessCanceledByUser(bool aProcessCanceledByUser) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrintProgress, NS_IPRINTPROGRESS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRINTPROGRESS \
  NS_IMETHOD OpenProgressDialog(nsIDOMWindow *parent, const char * dialogURL, nsISupports *parameters, nsIObserver *openDialogObserver, bool *notifyOnOpen); \
  NS_IMETHOD CloseProgressDialog(bool forceClose); \
  NS_IMETHOD RegisterListener(nsIWebProgressListener *listener); \
  NS_IMETHOD UnregisterListener(nsIWebProgressListener *listener); \
  NS_IMETHOD DoneIniting(void); \
  NS_IMETHOD GetPrompter(nsIPrompt * *_retval); \
  NS_IMETHOD GetProcessCanceledByUser(bool *aProcessCanceledByUser); \
  NS_IMETHOD SetProcessCanceledByUser(bool aProcessCanceledByUser); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRINTPROGRESS(_to) \
  NS_IMETHOD OpenProgressDialog(nsIDOMWindow *parent, const char * dialogURL, nsISupports *parameters, nsIObserver *openDialogObserver, bool *notifyOnOpen) { return _to OpenProgressDialog(parent, dialogURL, parameters, openDialogObserver, notifyOnOpen); } \
  NS_IMETHOD CloseProgressDialog(bool forceClose) { return _to CloseProgressDialog(forceClose); } \
  NS_IMETHOD RegisterListener(nsIWebProgressListener *listener) { return _to RegisterListener(listener); } \
  NS_IMETHOD UnregisterListener(nsIWebProgressListener *listener) { return _to UnregisterListener(listener); } \
  NS_IMETHOD DoneIniting(void) { return _to DoneIniting(); } \
  NS_IMETHOD GetPrompter(nsIPrompt * *_retval) { return _to GetPrompter(_retval); } \
  NS_IMETHOD GetProcessCanceledByUser(bool *aProcessCanceledByUser) { return _to GetProcessCanceledByUser(aProcessCanceledByUser); } \
  NS_IMETHOD SetProcessCanceledByUser(bool aProcessCanceledByUser) { return _to SetProcessCanceledByUser(aProcessCanceledByUser); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRINTPROGRESS(_to) \
  NS_IMETHOD OpenProgressDialog(nsIDOMWindow *parent, const char * dialogURL, nsISupports *parameters, nsIObserver *openDialogObserver, bool *notifyOnOpen) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenProgressDialog(parent, dialogURL, parameters, openDialogObserver, notifyOnOpen); } \
  NS_IMETHOD CloseProgressDialog(bool forceClose) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloseProgressDialog(forceClose); } \
  NS_IMETHOD RegisterListener(nsIWebProgressListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterListener(listener); } \
  NS_IMETHOD UnregisterListener(nsIWebProgressListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterListener(listener); } \
  NS_IMETHOD DoneIniting(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoneIniting(); } \
  NS_IMETHOD GetPrompter(nsIPrompt * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrompter(_retval); } \
  NS_IMETHOD GetProcessCanceledByUser(bool *aProcessCanceledByUser) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProcessCanceledByUser(aProcessCanceledByUser); } \
  NS_IMETHOD SetProcessCanceledByUser(bool aProcessCanceledByUser) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProcessCanceledByUser(aProcessCanceledByUser); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrintProgress : public nsIPrintProgress
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRINTPROGRESS

  nsPrintProgress();

private:
  ~nsPrintProgress();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrintProgress, nsIPrintProgress)

nsPrintProgress::nsPrintProgress()
{
  /* member initializers and constructor code */
}

nsPrintProgress::~nsPrintProgress()
{
  /* destructor code */
}

/* void openProgressDialog (in nsIDOMWindow parent, in string dialogURL, in nsISupports parameters, in nsIObserver openDialogObserver, out boolean notifyOnOpen); */
NS_IMETHODIMP nsPrintProgress::OpenProgressDialog(nsIDOMWindow *parent, const char * dialogURL, nsISupports *parameters, nsIObserver *openDialogObserver, bool *notifyOnOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void closeProgressDialog (in boolean forceClose); */
NS_IMETHODIMP nsPrintProgress::CloseProgressDialog(bool forceClose)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerListener (in nsIWebProgressListener listener); */
NS_IMETHODIMP nsPrintProgress::RegisterListener(nsIWebProgressListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterListener (in nsIWebProgressListener listener); */
NS_IMETHODIMP nsPrintProgress::UnregisterListener(nsIWebProgressListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doneIniting (); */
NS_IMETHODIMP nsPrintProgress::DoneIniting()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrompt getPrompter (); */
NS_IMETHODIMP nsPrintProgress::GetPrompter(nsIPrompt * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean processCanceledByUser; */
NS_IMETHODIMP nsPrintProgress::GetProcessCanceledByUser(bool *aProcessCanceledByUser)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintProgress::SetProcessCanceledByUser(bool aProcessCanceledByUser)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPrintProgress_h__ */

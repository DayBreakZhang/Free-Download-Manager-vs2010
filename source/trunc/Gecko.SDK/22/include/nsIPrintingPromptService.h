/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/embedding/browser/webBrowser/nsIPrintingPromptService.idl
 */

#ifndef __gen_nsIPrintingPromptService_h__
#define __gen_nsIPrintingPromptService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIWebBrowserPrint_h__
#include "nsIWebBrowserPrint.h"
#endif

#ifndef __gen_nsIWebProgressListener_h__
#include "nsIWebProgressListener.h"
#endif

#ifndef __gen_nsIPrintProgressParams_h__
#include "nsIPrintProgressParams.h"
#endif

#ifndef __gen_nsIPrintSettings_h__
#include "nsIPrintSettings.h"
#endif

#ifndef __gen_nsIObserver_h__
#include "nsIObserver.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIPrintingPromptService */
#define NS_IPRINTINGPROMPTSERVICE_IID_STR "75d1553d-63bf-4b5d-a8f7-e4e4cac21ba4"

#define NS_IPRINTINGPROMPTSERVICE_IID \
  {0x75d1553d, 0x63bf, 0x4b5d, \
    { 0xa8, 0xf7, 0xe4, 0xe4, 0xca, 0xc2, 0x1b, 0xa4 }}

class NS_NO_VTABLE nsIPrintingPromptService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRINTINGPROMPTSERVICE_IID)

  /* void showPrintDialog (in nsIDOMWindow parent, in nsIWebBrowserPrint webBrowserPrint, in nsIPrintSettings printSettings); */
  NS_IMETHOD ShowPrintDialog(nsIDOMWindow *parent, nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings) = 0;

  /* void showProgress (in nsIDOMWindow parent, in nsIWebBrowserPrint webBrowserPrint, in nsIPrintSettings printSettings, in nsIObserver openDialogObserver, in boolean isForPrinting, out nsIWebProgressListener webProgressListener, out nsIPrintProgressParams printProgressParams, out boolean notifyOnOpen); */
  NS_IMETHOD ShowProgress(nsIDOMWindow *parent, nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings, nsIObserver *openDialogObserver, bool isForPrinting, nsIWebProgressListener * *webProgressListener, nsIPrintProgressParams * *printProgressParams, bool *notifyOnOpen) = 0;

  /* void showPageSetup (in nsIDOMWindow parent, in nsIPrintSettings printSettings, in nsIObserver aObs); */
  NS_IMETHOD ShowPageSetup(nsIDOMWindow *parent, nsIPrintSettings *printSettings, nsIObserver *aObs) = 0;

  /* void showPrinterProperties (in nsIDOMWindow parent, in wstring printerName, in nsIPrintSettings printSettings); */
  NS_IMETHOD ShowPrinterProperties(nsIDOMWindow *parent, const PRUnichar * printerName, nsIPrintSettings *printSettings) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrintingPromptService, NS_IPRINTINGPROMPTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRINTINGPROMPTSERVICE \
  NS_IMETHOD ShowPrintDialog(nsIDOMWindow *parent, nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings); \
  NS_IMETHOD ShowProgress(nsIDOMWindow *parent, nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings, nsIObserver *openDialogObserver, bool isForPrinting, nsIWebProgressListener * *webProgressListener, nsIPrintProgressParams * *printProgressParams, bool *notifyOnOpen); \
  NS_IMETHOD ShowPageSetup(nsIDOMWindow *parent, nsIPrintSettings *printSettings, nsIObserver *aObs); \
  NS_IMETHOD ShowPrinterProperties(nsIDOMWindow *parent, const PRUnichar * printerName, nsIPrintSettings *printSettings); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRINTINGPROMPTSERVICE(_to) \
  NS_IMETHOD ShowPrintDialog(nsIDOMWindow *parent, nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings) { return _to ShowPrintDialog(parent, webBrowserPrint, printSettings); } \
  NS_IMETHOD ShowProgress(nsIDOMWindow *parent, nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings, nsIObserver *openDialogObserver, bool isForPrinting, nsIWebProgressListener * *webProgressListener, nsIPrintProgressParams * *printProgressParams, bool *notifyOnOpen) { return _to ShowProgress(parent, webBrowserPrint, printSettings, openDialogObserver, isForPrinting, webProgressListener, printProgressParams, notifyOnOpen); } \
  NS_IMETHOD ShowPageSetup(nsIDOMWindow *parent, nsIPrintSettings *printSettings, nsIObserver *aObs) { return _to ShowPageSetup(parent, printSettings, aObs); } \
  NS_IMETHOD ShowPrinterProperties(nsIDOMWindow *parent, const PRUnichar * printerName, nsIPrintSettings *printSettings) { return _to ShowPrinterProperties(parent, printerName, printSettings); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRINTINGPROMPTSERVICE(_to) \
  NS_IMETHOD ShowPrintDialog(nsIDOMWindow *parent, nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowPrintDialog(parent, webBrowserPrint, printSettings); } \
  NS_IMETHOD ShowProgress(nsIDOMWindow *parent, nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings, nsIObserver *openDialogObserver, bool isForPrinting, nsIWebProgressListener * *webProgressListener, nsIPrintProgressParams * *printProgressParams, bool *notifyOnOpen) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowProgress(parent, webBrowserPrint, printSettings, openDialogObserver, isForPrinting, webProgressListener, printProgressParams, notifyOnOpen); } \
  NS_IMETHOD ShowPageSetup(nsIDOMWindow *parent, nsIPrintSettings *printSettings, nsIObserver *aObs) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowPageSetup(parent, printSettings, aObs); } \
  NS_IMETHOD ShowPrinterProperties(nsIDOMWindow *parent, const PRUnichar * printerName, nsIPrintSettings *printSettings) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowPrinterProperties(parent, printerName, printSettings); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrintingPromptService : public nsIPrintingPromptService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRINTINGPROMPTSERVICE

  nsPrintingPromptService();

private:
  ~nsPrintingPromptService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrintingPromptService, nsIPrintingPromptService)

nsPrintingPromptService::nsPrintingPromptService()
{
  /* member initializers and constructor code */
}

nsPrintingPromptService::~nsPrintingPromptService()
{
  /* destructor code */
}

/* void showPrintDialog (in nsIDOMWindow parent, in nsIWebBrowserPrint webBrowserPrint, in nsIPrintSettings printSettings); */
NS_IMETHODIMP nsPrintingPromptService::ShowPrintDialog(nsIDOMWindow *parent, nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showProgress (in nsIDOMWindow parent, in nsIWebBrowserPrint webBrowserPrint, in nsIPrintSettings printSettings, in nsIObserver openDialogObserver, in boolean isForPrinting, out nsIWebProgressListener webProgressListener, out nsIPrintProgressParams printProgressParams, out boolean notifyOnOpen); */
NS_IMETHODIMP nsPrintingPromptService::ShowProgress(nsIDOMWindow *parent, nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings, nsIObserver *openDialogObserver, bool isForPrinting, nsIWebProgressListener * *webProgressListener, nsIPrintProgressParams * *printProgressParams, bool *notifyOnOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showPageSetup (in nsIDOMWindow parent, in nsIPrintSettings printSettings, in nsIObserver aObs); */
NS_IMETHODIMP nsPrintingPromptService::ShowPageSetup(nsIDOMWindow *parent, nsIPrintSettings *printSettings, nsIObserver *aObs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showPrinterProperties (in nsIDOMWindow parent, in wstring printerName, in nsIPrintSettings printSettings); */
NS_IMETHODIMP nsPrintingPromptService::ShowPrinterProperties(nsIDOMWindow *parent, const PRUnichar * printerName, nsIPrintSettings *printSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// {260FEDC5-524D-4aa6-9A41-E829F4C78B92}
#define NS_PRINTINGPROMPTSERVICE_IID \
 {0x260fedc5, 0x524d, 0x4aa6, { 0x9a, 0x41, 0xe8, 0x29, 0xf4, 0xc7, 0x8b, 0x92}}

#endif /* __gen_nsIPrintingPromptService_h__ */

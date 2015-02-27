/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPrintingPrompt.idl
 */

#ifndef __gen_nsIPrintingPrompt_h__
#define __gen_nsIPrintingPrompt_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIWebBrowserPrint_h__
#include "nsIWebBrowserPrint.h"
#endif

#ifndef __gen_nsIWebProgressListener_h__
#include "nsIWebProgressListener.h"
#endif

#ifndef __gen_nsIPrintSettings_h__
#include "nsIPrintSettings.h"
#endif

#ifndef __gen_nsIPrintProgressParams_h__
#include "nsIPrintProgressParams.h"
#endif

#ifndef __gen_nsIObserver_h__
#include "nsIObserver.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPrintingPrompt */
#define NS_IPRINTINGPROMPT_IID_STR "44e314ca-75b1-4f3d-9553-9b3507912108"

#define NS_IPRINTINGPROMPT_IID \
  {0x44e314ca, 0x75b1, 0x4f3d, \
    { 0x95, 0x53, 0x9b, 0x35, 0x07, 0x91, 0x21, 0x08 }}

class NS_NO_VTABLE nsIPrintingPrompt : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRINTINGPROMPT_IID)

  /* void showPrintDialog (in nsIWebBrowserPrint webBrowserPrint, in nsIPrintSettings printSettings); */
  NS_IMETHOD ShowPrintDialog(nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings) = 0;

  /* void showProgress (in nsIWebBrowserPrint webBrowserPrint, in nsIPrintSettings printSettings, in nsIObserver openDialogObserver, in boolean isForPrinting, out nsIWebProgressListener webProgressListener, out nsIPrintProgressParams printProgressParams, out boolean notifyOnOpen); */
  NS_IMETHOD ShowProgress(nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings, nsIObserver *openDialogObserver, bool isForPrinting, nsIWebProgressListener * *webProgressListener, nsIPrintProgressParams * *printProgressParams, bool *notifyOnOpen) = 0;

  /* void showPageSetup (in nsIPrintSettings printSettings, in nsIObserver aObs); */
  NS_IMETHOD ShowPageSetup(nsIPrintSettings *printSettings, nsIObserver *aObs) = 0;

  /* void showPrinterProperties (in wstring printerName, in nsIPrintSettings printSettings); */
  NS_IMETHOD ShowPrinterProperties(const char16_t * printerName, nsIPrintSettings *printSettings) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrintingPrompt, NS_IPRINTINGPROMPT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRINTINGPROMPT \
  NS_IMETHOD ShowPrintDialog(nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings); \
  NS_IMETHOD ShowProgress(nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings, nsIObserver *openDialogObserver, bool isForPrinting, nsIWebProgressListener * *webProgressListener, nsIPrintProgressParams * *printProgressParams, bool *notifyOnOpen); \
  NS_IMETHOD ShowPageSetup(nsIPrintSettings *printSettings, nsIObserver *aObs); \
  NS_IMETHOD ShowPrinterProperties(const char16_t * printerName, nsIPrintSettings *printSettings); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRINTINGPROMPT(_to) \
  NS_IMETHOD ShowPrintDialog(nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings) { return _to ShowPrintDialog(webBrowserPrint, printSettings); } \
  NS_IMETHOD ShowProgress(nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings, nsIObserver *openDialogObserver, bool isForPrinting, nsIWebProgressListener * *webProgressListener, nsIPrintProgressParams * *printProgressParams, bool *notifyOnOpen) { return _to ShowProgress(webBrowserPrint, printSettings, openDialogObserver, isForPrinting, webProgressListener, printProgressParams, notifyOnOpen); } \
  NS_IMETHOD ShowPageSetup(nsIPrintSettings *printSettings, nsIObserver *aObs) { return _to ShowPageSetup(printSettings, aObs); } \
  NS_IMETHOD ShowPrinterProperties(const char16_t * printerName, nsIPrintSettings *printSettings) { return _to ShowPrinterProperties(printerName, printSettings); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRINTINGPROMPT(_to) \
  NS_IMETHOD ShowPrintDialog(nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowPrintDialog(webBrowserPrint, printSettings); } \
  NS_IMETHOD ShowProgress(nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings, nsIObserver *openDialogObserver, bool isForPrinting, nsIWebProgressListener * *webProgressListener, nsIPrintProgressParams * *printProgressParams, bool *notifyOnOpen) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowProgress(webBrowserPrint, printSettings, openDialogObserver, isForPrinting, webProgressListener, printProgressParams, notifyOnOpen); } \
  NS_IMETHOD ShowPageSetup(nsIPrintSettings *printSettings, nsIObserver *aObs) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowPageSetup(printSettings, aObs); } \
  NS_IMETHOD ShowPrinterProperties(const char16_t * printerName, nsIPrintSettings *printSettings) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowPrinterProperties(printerName, printSettings); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrintingPrompt : public nsIPrintingPrompt
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRINTINGPROMPT

  nsPrintingPrompt();

private:
  ~nsPrintingPrompt();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrintingPrompt, nsIPrintingPrompt)

nsPrintingPrompt::nsPrintingPrompt()
{
  /* member initializers and constructor code */
}

nsPrintingPrompt::~nsPrintingPrompt()
{
  /* destructor code */
}

/* void showPrintDialog (in nsIWebBrowserPrint webBrowserPrint, in nsIPrintSettings printSettings); */
NS_IMETHODIMP nsPrintingPrompt::ShowPrintDialog(nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showProgress (in nsIWebBrowserPrint webBrowserPrint, in nsIPrintSettings printSettings, in nsIObserver openDialogObserver, in boolean isForPrinting, out nsIWebProgressListener webProgressListener, out nsIPrintProgressParams printProgressParams, out boolean notifyOnOpen); */
NS_IMETHODIMP nsPrintingPrompt::ShowProgress(nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings, nsIObserver *openDialogObserver, bool isForPrinting, nsIWebProgressListener * *webProgressListener, nsIPrintProgressParams * *printProgressParams, bool *notifyOnOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showPageSetup (in nsIPrintSettings printSettings, in nsIObserver aObs); */
NS_IMETHODIMP nsPrintingPrompt::ShowPageSetup(nsIPrintSettings *printSettings, nsIObserver *aObs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showPrinterProperties (in wstring printerName, in nsIPrintSettings printSettings); */
NS_IMETHODIMP nsPrintingPrompt::ShowPrinterProperties(const char16_t * printerName, nsIPrintSettings *printSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPrintingPrompt_h__ */

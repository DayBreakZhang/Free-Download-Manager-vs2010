/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/embedding/browser/webBrowser/nsIWebBrowserPrint.idl
 */

#ifndef __gen_nsIWebBrowserPrint_h__
#define __gen_nsIWebBrowserPrint_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIPrintSettings; /* forward declaration */

class nsIWebProgressListener; /* forward declaration */


/* starting interface:    nsIWebBrowserPrint */
#define NS_IWEBBROWSERPRINT_IID_STR "9a7ca4b0-fbba-11d4-a869-00105a183419"

#define NS_IWEBBROWSERPRINT_IID \
  {0x9a7ca4b0, 0xfbba, 0x11d4, \
    { 0xa8, 0x69, 0x00, 0x10, 0x5a, 0x18, 0x34, 0x19 }}

class NS_NO_VTABLE nsIWebBrowserPrint : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBBROWSERPRINT_IID)

  enum {
    PRINTPREVIEW_GOTO_PAGENUM = 0,
    PRINTPREVIEW_PREV_PAGE = 1,
    PRINTPREVIEW_NEXT_PAGE = 2,
    PRINTPREVIEW_HOME = 3,
    PRINTPREVIEW_END = 4
  };

  /* readonly attribute nsIPrintSettings globalPrintSettings; */
  NS_IMETHOD GetGlobalPrintSettings(nsIPrintSettings * *aGlobalPrintSettings) = 0;

  /* readonly attribute nsIPrintSettings currentPrintSettings; */
  NS_IMETHOD GetCurrentPrintSettings(nsIPrintSettings * *aCurrentPrintSettings) = 0;

  /* readonly attribute nsIDOMWindow currentChildDOMWindow; */
  NS_IMETHOD GetCurrentChildDOMWindow(nsIDOMWindow * *aCurrentChildDOMWindow) = 0;

  /* readonly attribute boolean doingPrint; */
  NS_IMETHOD GetDoingPrint(bool *aDoingPrint) = 0;

  /* readonly attribute boolean doingPrintPreview; */
  NS_IMETHOD GetDoingPrintPreview(bool *aDoingPrintPreview) = 0;

  /* readonly attribute boolean isFramesetDocument; */
  NS_IMETHOD GetIsFramesetDocument(bool *aIsFramesetDocument) = 0;

  /* readonly attribute boolean isFramesetFrameSelected; */
  NS_IMETHOD GetIsFramesetFrameSelected(bool *aIsFramesetFrameSelected) = 0;

  /* readonly attribute boolean isIFrameSelected; */
  NS_IMETHOD GetIsIFrameSelected(bool *aIsIFrameSelected) = 0;

  /* readonly attribute boolean isRangeSelection; */
  NS_IMETHOD GetIsRangeSelection(bool *aIsRangeSelection) = 0;

  /* readonly attribute long printPreviewNumPages; */
  NS_IMETHOD GetPrintPreviewNumPages(int32_t *aPrintPreviewNumPages) = 0;

  /* void print (in nsIPrintSettings aThePrintSettings, in nsIWebProgressListener aWPListener); */
  NS_IMETHOD Print(nsIPrintSettings *aThePrintSettings, nsIWebProgressListener *aWPListener) = 0;

  /* void printPreview (in nsIPrintSettings aThePrintSettings, in nsIDOMWindow aChildDOMWin, in nsIWebProgressListener aWPListener); */
  NS_IMETHOD PrintPreview(nsIPrintSettings *aThePrintSettings, nsIDOMWindow *aChildDOMWin, nsIWebProgressListener *aWPListener) = 0;

  /* void printPreviewNavigate (in short aNavType, in long aPageNum); */
  NS_IMETHOD PrintPreviewNavigate(int16_t aNavType, int32_t aPageNum) = 0;

  /* void cancel (); */
  NS_IMETHOD Cancel(void) = 0;

  /* void enumerateDocumentNames (out uint32_t aCount, [array, size_is (aCount), retval] out wstring aResult); */
  NS_IMETHOD EnumerateDocumentNames(uint32_t *aCount, PRUnichar * **aResult) = 0;

  /* void exitPrintPreview (); */
  NS_IMETHOD ExitPrintPreview(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebBrowserPrint, NS_IWEBBROWSERPRINT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBBROWSERPRINT \
  NS_IMETHOD GetGlobalPrintSettings(nsIPrintSettings * *aGlobalPrintSettings); \
  NS_IMETHOD GetCurrentPrintSettings(nsIPrintSettings * *aCurrentPrintSettings); \
  NS_IMETHOD GetCurrentChildDOMWindow(nsIDOMWindow * *aCurrentChildDOMWindow); \
  NS_IMETHOD GetDoingPrint(bool *aDoingPrint); \
  NS_IMETHOD GetDoingPrintPreview(bool *aDoingPrintPreview); \
  NS_IMETHOD GetIsFramesetDocument(bool *aIsFramesetDocument); \
  NS_IMETHOD GetIsFramesetFrameSelected(bool *aIsFramesetFrameSelected); \
  NS_IMETHOD GetIsIFrameSelected(bool *aIsIFrameSelected); \
  NS_IMETHOD GetIsRangeSelection(bool *aIsRangeSelection); \
  NS_IMETHOD GetPrintPreviewNumPages(int32_t *aPrintPreviewNumPages); \
  NS_IMETHOD Print(nsIPrintSettings *aThePrintSettings, nsIWebProgressListener *aWPListener); \
  NS_IMETHOD PrintPreview(nsIPrintSettings *aThePrintSettings, nsIDOMWindow *aChildDOMWin, nsIWebProgressListener *aWPListener); \
  NS_IMETHOD PrintPreviewNavigate(int16_t aNavType, int32_t aPageNum); \
  NS_IMETHOD Cancel(void); \
  NS_IMETHOD EnumerateDocumentNames(uint32_t *aCount, PRUnichar * **aResult); \
  NS_IMETHOD ExitPrintPreview(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBBROWSERPRINT(_to) \
  NS_IMETHOD GetGlobalPrintSettings(nsIPrintSettings * *aGlobalPrintSettings) { return _to GetGlobalPrintSettings(aGlobalPrintSettings); } \
  NS_IMETHOD GetCurrentPrintSettings(nsIPrintSettings * *aCurrentPrintSettings) { return _to GetCurrentPrintSettings(aCurrentPrintSettings); } \
  NS_IMETHOD GetCurrentChildDOMWindow(nsIDOMWindow * *aCurrentChildDOMWindow) { return _to GetCurrentChildDOMWindow(aCurrentChildDOMWindow); } \
  NS_IMETHOD GetDoingPrint(bool *aDoingPrint) { return _to GetDoingPrint(aDoingPrint); } \
  NS_IMETHOD GetDoingPrintPreview(bool *aDoingPrintPreview) { return _to GetDoingPrintPreview(aDoingPrintPreview); } \
  NS_IMETHOD GetIsFramesetDocument(bool *aIsFramesetDocument) { return _to GetIsFramesetDocument(aIsFramesetDocument); } \
  NS_IMETHOD GetIsFramesetFrameSelected(bool *aIsFramesetFrameSelected) { return _to GetIsFramesetFrameSelected(aIsFramesetFrameSelected); } \
  NS_IMETHOD GetIsIFrameSelected(bool *aIsIFrameSelected) { return _to GetIsIFrameSelected(aIsIFrameSelected); } \
  NS_IMETHOD GetIsRangeSelection(bool *aIsRangeSelection) { return _to GetIsRangeSelection(aIsRangeSelection); } \
  NS_IMETHOD GetPrintPreviewNumPages(int32_t *aPrintPreviewNumPages) { return _to GetPrintPreviewNumPages(aPrintPreviewNumPages); } \
  NS_IMETHOD Print(nsIPrintSettings *aThePrintSettings, nsIWebProgressListener *aWPListener) { return _to Print(aThePrintSettings, aWPListener); } \
  NS_IMETHOD PrintPreview(nsIPrintSettings *aThePrintSettings, nsIDOMWindow *aChildDOMWin, nsIWebProgressListener *aWPListener) { return _to PrintPreview(aThePrintSettings, aChildDOMWin, aWPListener); } \
  NS_IMETHOD PrintPreviewNavigate(int16_t aNavType, int32_t aPageNum) { return _to PrintPreviewNavigate(aNavType, aPageNum); } \
  NS_IMETHOD Cancel(void) { return _to Cancel(); } \
  NS_IMETHOD EnumerateDocumentNames(uint32_t *aCount, PRUnichar * **aResult) { return _to EnumerateDocumentNames(aCount, aResult); } \
  NS_IMETHOD ExitPrintPreview(void) { return _to ExitPrintPreview(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBBROWSERPRINT(_to) \
  NS_IMETHOD GetGlobalPrintSettings(nsIPrintSettings * *aGlobalPrintSettings) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGlobalPrintSettings(aGlobalPrintSettings); } \
  NS_IMETHOD GetCurrentPrintSettings(nsIPrintSettings * *aCurrentPrintSettings) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentPrintSettings(aCurrentPrintSettings); } \
  NS_IMETHOD GetCurrentChildDOMWindow(nsIDOMWindow * *aCurrentChildDOMWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentChildDOMWindow(aCurrentChildDOMWindow); } \
  NS_IMETHOD GetDoingPrint(bool *aDoingPrint) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDoingPrint(aDoingPrint); } \
  NS_IMETHOD GetDoingPrintPreview(bool *aDoingPrintPreview) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDoingPrintPreview(aDoingPrintPreview); } \
  NS_IMETHOD GetIsFramesetDocument(bool *aIsFramesetDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsFramesetDocument(aIsFramesetDocument); } \
  NS_IMETHOD GetIsFramesetFrameSelected(bool *aIsFramesetFrameSelected) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsFramesetFrameSelected(aIsFramesetFrameSelected); } \
  NS_IMETHOD GetIsIFrameSelected(bool *aIsIFrameSelected) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsIFrameSelected(aIsIFrameSelected); } \
  NS_IMETHOD GetIsRangeSelection(bool *aIsRangeSelection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsRangeSelection(aIsRangeSelection); } \
  NS_IMETHOD GetPrintPreviewNumPages(int32_t *aPrintPreviewNumPages) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintPreviewNumPages(aPrintPreviewNumPages); } \
  NS_IMETHOD Print(nsIPrintSettings *aThePrintSettings, nsIWebProgressListener *aWPListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->Print(aThePrintSettings, aWPListener); } \
  NS_IMETHOD PrintPreview(nsIPrintSettings *aThePrintSettings, nsIDOMWindow *aChildDOMWin, nsIWebProgressListener *aWPListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->PrintPreview(aThePrintSettings, aChildDOMWin, aWPListener); } \
  NS_IMETHOD PrintPreviewNavigate(int16_t aNavType, int32_t aPageNum) { return !_to ? NS_ERROR_NULL_POINTER : _to->PrintPreviewNavigate(aNavType, aPageNum); } \
  NS_IMETHOD Cancel(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Cancel(); } \
  NS_IMETHOD EnumerateDocumentNames(uint32_t *aCount, PRUnichar * **aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateDocumentNames(aCount, aResult); } \
  NS_IMETHOD ExitPrintPreview(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExitPrintPreview(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebBrowserPrint : public nsIWebBrowserPrint
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBBROWSERPRINT

  nsWebBrowserPrint();

private:
  ~nsWebBrowserPrint();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebBrowserPrint, nsIWebBrowserPrint)

nsWebBrowserPrint::nsWebBrowserPrint()
{
  /* member initializers and constructor code */
}

nsWebBrowserPrint::~nsWebBrowserPrint()
{
  /* destructor code */
}

/* readonly attribute nsIPrintSettings globalPrintSettings; */
NS_IMETHODIMP nsWebBrowserPrint::GetGlobalPrintSettings(nsIPrintSettings * *aGlobalPrintSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIPrintSettings currentPrintSettings; */
NS_IMETHODIMP nsWebBrowserPrint::GetCurrentPrintSettings(nsIPrintSettings * *aCurrentPrintSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow currentChildDOMWindow; */
NS_IMETHODIMP nsWebBrowserPrint::GetCurrentChildDOMWindow(nsIDOMWindow * *aCurrentChildDOMWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean doingPrint; */
NS_IMETHODIMP nsWebBrowserPrint::GetDoingPrint(bool *aDoingPrint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean doingPrintPreview; */
NS_IMETHODIMP nsWebBrowserPrint::GetDoingPrintPreview(bool *aDoingPrintPreview)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isFramesetDocument; */
NS_IMETHODIMP nsWebBrowserPrint::GetIsFramesetDocument(bool *aIsFramesetDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isFramesetFrameSelected; */
NS_IMETHODIMP nsWebBrowserPrint::GetIsFramesetFrameSelected(bool *aIsFramesetFrameSelected)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isIFrameSelected; */
NS_IMETHODIMP nsWebBrowserPrint::GetIsIFrameSelected(bool *aIsIFrameSelected)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isRangeSelection; */
NS_IMETHODIMP nsWebBrowserPrint::GetIsRangeSelection(bool *aIsRangeSelection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long printPreviewNumPages; */
NS_IMETHODIMP nsWebBrowserPrint::GetPrintPreviewNumPages(int32_t *aPrintPreviewNumPages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void print (in nsIPrintSettings aThePrintSettings, in nsIWebProgressListener aWPListener); */
NS_IMETHODIMP nsWebBrowserPrint::Print(nsIPrintSettings *aThePrintSettings, nsIWebProgressListener *aWPListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void printPreview (in nsIPrintSettings aThePrintSettings, in nsIDOMWindow aChildDOMWin, in nsIWebProgressListener aWPListener); */
NS_IMETHODIMP nsWebBrowserPrint::PrintPreview(nsIPrintSettings *aThePrintSettings, nsIDOMWindow *aChildDOMWin, nsIWebProgressListener *aWPListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void printPreviewNavigate (in short aNavType, in long aPageNum); */
NS_IMETHODIMP nsWebBrowserPrint::PrintPreviewNavigate(int16_t aNavType, int32_t aPageNum)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancel (); */
NS_IMETHODIMP nsWebBrowserPrint::Cancel()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enumerateDocumentNames (out uint32_t aCount, [array, size_is (aCount), retval] out wstring aResult); */
NS_IMETHODIMP nsWebBrowserPrint::EnumerateDocumentNames(uint32_t *aCount, PRUnichar * **aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void exitPrintPreview (); */
NS_IMETHODIMP nsWebBrowserPrint::ExitPrintPreview()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebBrowserPrint_h__ */

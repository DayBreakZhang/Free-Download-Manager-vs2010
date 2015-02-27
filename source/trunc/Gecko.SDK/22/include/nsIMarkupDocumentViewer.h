/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/docshell/base/nsIMarkupDocumentViewer.idl
 */

#ifndef __gen_nsIMarkupDocumentViewer_h__
#define __gen_nsIMarkupDocumentViewer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNode; /* forward declaration */

#include "nsCOMPtr.h"
#include "nsTArray.h"
class nsIMarkupDocumentViewer; /* forward declaration */


/* starting interface:    nsIMarkupDocumentViewer */
#define NS_IMARKUPDOCUMENTVIEWER_IID_STR "02d37b31-e654-4b74-9bc3-14dfe0020bb3"

#define NS_IMARKUPDOCUMENTVIEWER_IID \
  {0x02d37b31, 0xe654, 0x4b74, \
    { 0x9b, 0xc3, 0x14, 0xdf, 0xe0, 0x02, 0x0b, 0xb3 }}

class NS_NO_VTABLE nsIMarkupDocumentViewer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMARKUPDOCUMENTVIEWER_IID)

  /* void scrollToNode (in nsIDOMNode node); */
  NS_IMETHOD ScrollToNode(nsIDOMNode *node) = 0;

  /* attribute float textZoom; */
  NS_IMETHOD GetTextZoom(float *aTextZoom) = 0;
  NS_IMETHOD SetTextZoom(float aTextZoom) = 0;

  /* attribute float fullZoom; */
  NS_IMETHOD GetFullZoom(float *aFullZoom) = 0;
  NS_IMETHOD SetFullZoom(float aFullZoom) = 0;

  /* attribute boolean authorStyleDisabled; */
  NS_IMETHOD GetAuthorStyleDisabled(bool *aAuthorStyleDisabled) = 0;
  NS_IMETHOD SetAuthorStyleDisabled(bool aAuthorStyleDisabled) = 0;

  /* attribute ACString defaultCharacterSet; */
  NS_IMETHOD GetDefaultCharacterSet(nsACString & aDefaultCharacterSet) = 0;
  NS_IMETHOD SetDefaultCharacterSet(const nsACString & aDefaultCharacterSet) = 0;

  /* attribute ACString forceCharacterSet; */
  NS_IMETHOD GetForceCharacterSet(nsACString & aForceCharacterSet) = 0;
  NS_IMETHOD SetForceCharacterSet(const nsACString & aForceCharacterSet) = 0;

  /* attribute ACString hintCharacterSet; */
  NS_IMETHOD GetHintCharacterSet(nsACString & aHintCharacterSet) = 0;
  NS_IMETHOD SetHintCharacterSet(const nsACString & aHintCharacterSet) = 0;

  /* attribute int32_t hintCharacterSetSource; */
  NS_IMETHOD GetHintCharacterSetSource(int32_t *aHintCharacterSetSource) = 0;
  NS_IMETHOD SetHintCharacterSetSource(int32_t aHintCharacterSetSource) = 0;

  /* attribute ACString prevDocCharacterSet; */
  NS_IMETHOD GetPrevDocCharacterSet(nsACString & aPrevDocCharacterSet) = 0;
  NS_IMETHOD SetPrevDocCharacterSet(const nsACString & aPrevDocCharacterSet) = 0;

  /* void getContentSize (out long width, out long height); */
  NS_IMETHOD GetContentSize(int32_t *width, int32_t *height) = 0;

  /* attribute octet bidiTextDirection; */
  NS_IMETHOD GetBidiTextDirection(uint8_t *aBidiTextDirection) = 0;
  NS_IMETHOD SetBidiTextDirection(uint8_t aBidiTextDirection) = 0;

  /* attribute octet bidiTextType; */
  NS_IMETHOD GetBidiTextType(uint8_t *aBidiTextType) = 0;
  NS_IMETHOD SetBidiTextType(uint8_t aBidiTextType) = 0;

  /* attribute octet bidiNumeral; */
  NS_IMETHOD GetBidiNumeral(uint8_t *aBidiNumeral) = 0;
  NS_IMETHOD SetBidiNumeral(uint8_t aBidiNumeral) = 0;

  /* attribute octet bidiSupport; */
  NS_IMETHOD GetBidiSupport(uint8_t *aBidiSupport) = 0;
  NS_IMETHOD SetBidiSupport(uint8_t aBidiSupport) = 0;

  /* attribute uint32_t bidiOptions; */
  NS_IMETHOD GetBidiOptions(uint32_t *aBidiOptions) = 0;
  NS_IMETHOD SetBidiOptions(uint32_t aBidiOptions) = 0;

  /* attribute long minFontSize; */
  NS_IMETHOD GetMinFontSize(int32_t *aMinFontSize) = 0;
  NS_IMETHOD SetMinFontSize(int32_t aMinFontSize) = 0;

  /* [noscript] void appendSubtree (in nsIMarkupDocumentViewerTArray array); */
  NS_IMETHOD AppendSubtree(nsTArray<nsCOMPtr<nsIMarkupDocumentViewer> > & array) = 0;

  /* void changeMaxLineBoxWidth (in int32_t maxLineBoxWidth); */
  NS_IMETHOD ChangeMaxLineBoxWidth(int32_t maxLineBoxWidth) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMarkupDocumentViewer, NS_IMARKUPDOCUMENTVIEWER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMARKUPDOCUMENTVIEWER \
  NS_IMETHOD ScrollToNode(nsIDOMNode *node); \
  NS_IMETHOD GetTextZoom(float *aTextZoom); \
  NS_IMETHOD SetTextZoom(float aTextZoom); \
  NS_IMETHOD GetFullZoom(float *aFullZoom); \
  NS_IMETHOD SetFullZoom(float aFullZoom); \
  NS_IMETHOD GetAuthorStyleDisabled(bool *aAuthorStyleDisabled); \
  NS_IMETHOD SetAuthorStyleDisabled(bool aAuthorStyleDisabled); \
  NS_IMETHOD GetDefaultCharacterSet(nsACString & aDefaultCharacterSet); \
  NS_IMETHOD SetDefaultCharacterSet(const nsACString & aDefaultCharacterSet); \
  NS_IMETHOD GetForceCharacterSet(nsACString & aForceCharacterSet); \
  NS_IMETHOD SetForceCharacterSet(const nsACString & aForceCharacterSet); \
  NS_IMETHOD GetHintCharacterSet(nsACString & aHintCharacterSet); \
  NS_IMETHOD SetHintCharacterSet(const nsACString & aHintCharacterSet); \
  NS_IMETHOD GetHintCharacterSetSource(int32_t *aHintCharacterSetSource); \
  NS_IMETHOD SetHintCharacterSetSource(int32_t aHintCharacterSetSource); \
  NS_IMETHOD GetPrevDocCharacterSet(nsACString & aPrevDocCharacterSet); \
  NS_IMETHOD SetPrevDocCharacterSet(const nsACString & aPrevDocCharacterSet); \
  NS_IMETHOD GetContentSize(int32_t *width, int32_t *height); \
  NS_IMETHOD GetBidiTextDirection(uint8_t *aBidiTextDirection); \
  NS_IMETHOD SetBidiTextDirection(uint8_t aBidiTextDirection); \
  NS_IMETHOD GetBidiTextType(uint8_t *aBidiTextType); \
  NS_IMETHOD SetBidiTextType(uint8_t aBidiTextType); \
  NS_IMETHOD GetBidiNumeral(uint8_t *aBidiNumeral); \
  NS_IMETHOD SetBidiNumeral(uint8_t aBidiNumeral); \
  NS_IMETHOD GetBidiSupport(uint8_t *aBidiSupport); \
  NS_IMETHOD SetBidiSupport(uint8_t aBidiSupport); \
  NS_IMETHOD GetBidiOptions(uint32_t *aBidiOptions); \
  NS_IMETHOD SetBidiOptions(uint32_t aBidiOptions); \
  NS_IMETHOD GetMinFontSize(int32_t *aMinFontSize); \
  NS_IMETHOD SetMinFontSize(int32_t aMinFontSize); \
  NS_IMETHOD AppendSubtree(nsTArray<nsCOMPtr<nsIMarkupDocumentViewer> > & array); \
  NS_IMETHOD ChangeMaxLineBoxWidth(int32_t maxLineBoxWidth); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMARKUPDOCUMENTVIEWER(_to) \
  NS_IMETHOD ScrollToNode(nsIDOMNode *node) { return _to ScrollToNode(node); } \
  NS_IMETHOD GetTextZoom(float *aTextZoom) { return _to GetTextZoom(aTextZoom); } \
  NS_IMETHOD SetTextZoom(float aTextZoom) { return _to SetTextZoom(aTextZoom); } \
  NS_IMETHOD GetFullZoom(float *aFullZoom) { return _to GetFullZoom(aFullZoom); } \
  NS_IMETHOD SetFullZoom(float aFullZoom) { return _to SetFullZoom(aFullZoom); } \
  NS_IMETHOD GetAuthorStyleDisabled(bool *aAuthorStyleDisabled) { return _to GetAuthorStyleDisabled(aAuthorStyleDisabled); } \
  NS_IMETHOD SetAuthorStyleDisabled(bool aAuthorStyleDisabled) { return _to SetAuthorStyleDisabled(aAuthorStyleDisabled); } \
  NS_IMETHOD GetDefaultCharacterSet(nsACString & aDefaultCharacterSet) { return _to GetDefaultCharacterSet(aDefaultCharacterSet); } \
  NS_IMETHOD SetDefaultCharacterSet(const nsACString & aDefaultCharacterSet) { return _to SetDefaultCharacterSet(aDefaultCharacterSet); } \
  NS_IMETHOD GetForceCharacterSet(nsACString & aForceCharacterSet) { return _to GetForceCharacterSet(aForceCharacterSet); } \
  NS_IMETHOD SetForceCharacterSet(const nsACString & aForceCharacterSet) { return _to SetForceCharacterSet(aForceCharacterSet); } \
  NS_IMETHOD GetHintCharacterSet(nsACString & aHintCharacterSet) { return _to GetHintCharacterSet(aHintCharacterSet); } \
  NS_IMETHOD SetHintCharacterSet(const nsACString & aHintCharacterSet) { return _to SetHintCharacterSet(aHintCharacterSet); } \
  NS_IMETHOD GetHintCharacterSetSource(int32_t *aHintCharacterSetSource) { return _to GetHintCharacterSetSource(aHintCharacterSetSource); } \
  NS_IMETHOD SetHintCharacterSetSource(int32_t aHintCharacterSetSource) { return _to SetHintCharacterSetSource(aHintCharacterSetSource); } \
  NS_IMETHOD GetPrevDocCharacterSet(nsACString & aPrevDocCharacterSet) { return _to GetPrevDocCharacterSet(aPrevDocCharacterSet); } \
  NS_IMETHOD SetPrevDocCharacterSet(const nsACString & aPrevDocCharacterSet) { return _to SetPrevDocCharacterSet(aPrevDocCharacterSet); } \
  NS_IMETHOD GetContentSize(int32_t *width, int32_t *height) { return _to GetContentSize(width, height); } \
  NS_IMETHOD GetBidiTextDirection(uint8_t *aBidiTextDirection) { return _to GetBidiTextDirection(aBidiTextDirection); } \
  NS_IMETHOD SetBidiTextDirection(uint8_t aBidiTextDirection) { return _to SetBidiTextDirection(aBidiTextDirection); } \
  NS_IMETHOD GetBidiTextType(uint8_t *aBidiTextType) { return _to GetBidiTextType(aBidiTextType); } \
  NS_IMETHOD SetBidiTextType(uint8_t aBidiTextType) { return _to SetBidiTextType(aBidiTextType); } \
  NS_IMETHOD GetBidiNumeral(uint8_t *aBidiNumeral) { return _to GetBidiNumeral(aBidiNumeral); } \
  NS_IMETHOD SetBidiNumeral(uint8_t aBidiNumeral) { return _to SetBidiNumeral(aBidiNumeral); } \
  NS_IMETHOD GetBidiSupport(uint8_t *aBidiSupport) { return _to GetBidiSupport(aBidiSupport); } \
  NS_IMETHOD SetBidiSupport(uint8_t aBidiSupport) { return _to SetBidiSupport(aBidiSupport); } \
  NS_IMETHOD GetBidiOptions(uint32_t *aBidiOptions) { return _to GetBidiOptions(aBidiOptions); } \
  NS_IMETHOD SetBidiOptions(uint32_t aBidiOptions) { return _to SetBidiOptions(aBidiOptions); } \
  NS_IMETHOD GetMinFontSize(int32_t *aMinFontSize) { return _to GetMinFontSize(aMinFontSize); } \
  NS_IMETHOD SetMinFontSize(int32_t aMinFontSize) { return _to SetMinFontSize(aMinFontSize); } \
  NS_IMETHOD AppendSubtree(nsTArray<nsCOMPtr<nsIMarkupDocumentViewer> > & array) { return _to AppendSubtree(array); } \
  NS_IMETHOD ChangeMaxLineBoxWidth(int32_t maxLineBoxWidth) { return _to ChangeMaxLineBoxWidth(maxLineBoxWidth); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMARKUPDOCUMENTVIEWER(_to) \
  NS_IMETHOD ScrollToNode(nsIDOMNode *node) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollToNode(node); } \
  NS_IMETHOD GetTextZoom(float *aTextZoom) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextZoom(aTextZoom); } \
  NS_IMETHOD SetTextZoom(float aTextZoom) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTextZoom(aTextZoom); } \
  NS_IMETHOD GetFullZoom(float *aFullZoom) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFullZoom(aFullZoom); } \
  NS_IMETHOD SetFullZoom(float aFullZoom) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFullZoom(aFullZoom); } \
  NS_IMETHOD GetAuthorStyleDisabled(bool *aAuthorStyleDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAuthorStyleDisabled(aAuthorStyleDisabled); } \
  NS_IMETHOD SetAuthorStyleDisabled(bool aAuthorStyleDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAuthorStyleDisabled(aAuthorStyleDisabled); } \
  NS_IMETHOD GetDefaultCharacterSet(nsACString & aDefaultCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultCharacterSet(aDefaultCharacterSet); } \
  NS_IMETHOD SetDefaultCharacterSet(const nsACString & aDefaultCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultCharacterSet(aDefaultCharacterSet); } \
  NS_IMETHOD GetForceCharacterSet(nsACString & aForceCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForceCharacterSet(aForceCharacterSet); } \
  NS_IMETHOD SetForceCharacterSet(const nsACString & aForceCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetForceCharacterSet(aForceCharacterSet); } \
  NS_IMETHOD GetHintCharacterSet(nsACString & aHintCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHintCharacterSet(aHintCharacterSet); } \
  NS_IMETHOD SetHintCharacterSet(const nsACString & aHintCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHintCharacterSet(aHintCharacterSet); } \
  NS_IMETHOD GetHintCharacterSetSource(int32_t *aHintCharacterSetSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHintCharacterSetSource(aHintCharacterSetSource); } \
  NS_IMETHOD SetHintCharacterSetSource(int32_t aHintCharacterSetSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHintCharacterSetSource(aHintCharacterSetSource); } \
  NS_IMETHOD GetPrevDocCharacterSet(nsACString & aPrevDocCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrevDocCharacterSet(aPrevDocCharacterSet); } \
  NS_IMETHOD SetPrevDocCharacterSet(const nsACString & aPrevDocCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrevDocCharacterSet(aPrevDocCharacterSet); } \
  NS_IMETHOD GetContentSize(int32_t *width, int32_t *height) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentSize(width, height); } \
  NS_IMETHOD GetBidiTextDirection(uint8_t *aBidiTextDirection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBidiTextDirection(aBidiTextDirection); } \
  NS_IMETHOD SetBidiTextDirection(uint8_t aBidiTextDirection) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBidiTextDirection(aBidiTextDirection); } \
  NS_IMETHOD GetBidiTextType(uint8_t *aBidiTextType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBidiTextType(aBidiTextType); } \
  NS_IMETHOD SetBidiTextType(uint8_t aBidiTextType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBidiTextType(aBidiTextType); } \
  NS_IMETHOD GetBidiNumeral(uint8_t *aBidiNumeral) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBidiNumeral(aBidiNumeral); } \
  NS_IMETHOD SetBidiNumeral(uint8_t aBidiNumeral) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBidiNumeral(aBidiNumeral); } \
  NS_IMETHOD GetBidiSupport(uint8_t *aBidiSupport) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBidiSupport(aBidiSupport); } \
  NS_IMETHOD SetBidiSupport(uint8_t aBidiSupport) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBidiSupport(aBidiSupport); } \
  NS_IMETHOD GetBidiOptions(uint32_t *aBidiOptions) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBidiOptions(aBidiOptions); } \
  NS_IMETHOD SetBidiOptions(uint32_t aBidiOptions) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBidiOptions(aBidiOptions); } \
  NS_IMETHOD GetMinFontSize(int32_t *aMinFontSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMinFontSize(aMinFontSize); } \
  NS_IMETHOD SetMinFontSize(int32_t aMinFontSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMinFontSize(aMinFontSize); } \
  NS_IMETHOD AppendSubtree(nsTArray<nsCOMPtr<nsIMarkupDocumentViewer> > & array) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendSubtree(array); } \
  NS_IMETHOD ChangeMaxLineBoxWidth(int32_t maxLineBoxWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->ChangeMaxLineBoxWidth(maxLineBoxWidth); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMarkupDocumentViewer : public nsIMarkupDocumentViewer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMARKUPDOCUMENTVIEWER

  nsMarkupDocumentViewer();

private:
  ~nsMarkupDocumentViewer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMarkupDocumentViewer, nsIMarkupDocumentViewer)

nsMarkupDocumentViewer::nsMarkupDocumentViewer()
{
  /* member initializers and constructor code */
}

nsMarkupDocumentViewer::~nsMarkupDocumentViewer()
{
  /* destructor code */
}

/* void scrollToNode (in nsIDOMNode node); */
NS_IMETHODIMP nsMarkupDocumentViewer::ScrollToNode(nsIDOMNode *node)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float textZoom; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetTextZoom(float *aTextZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetTextZoom(float aTextZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float fullZoom; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetFullZoom(float *aFullZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetFullZoom(float aFullZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean authorStyleDisabled; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetAuthorStyleDisabled(bool *aAuthorStyleDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetAuthorStyleDisabled(bool aAuthorStyleDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString defaultCharacterSet; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetDefaultCharacterSet(nsACString & aDefaultCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetDefaultCharacterSet(const nsACString & aDefaultCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString forceCharacterSet; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetForceCharacterSet(nsACString & aForceCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetForceCharacterSet(const nsACString & aForceCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString hintCharacterSet; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetHintCharacterSet(nsACString & aHintCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetHintCharacterSet(const nsACString & aHintCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute int32_t hintCharacterSetSource; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetHintCharacterSetSource(int32_t *aHintCharacterSetSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetHintCharacterSetSource(int32_t aHintCharacterSetSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString prevDocCharacterSet; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetPrevDocCharacterSet(nsACString & aPrevDocCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetPrevDocCharacterSet(const nsACString & aPrevDocCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getContentSize (out long width, out long height); */
NS_IMETHODIMP nsMarkupDocumentViewer::GetContentSize(int32_t *width, int32_t *height)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute octet bidiTextDirection; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetBidiTextDirection(uint8_t *aBidiTextDirection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetBidiTextDirection(uint8_t aBidiTextDirection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute octet bidiTextType; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetBidiTextType(uint8_t *aBidiTextType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetBidiTextType(uint8_t aBidiTextType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute octet bidiNumeral; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetBidiNumeral(uint8_t *aBidiNumeral)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetBidiNumeral(uint8_t aBidiNumeral)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute octet bidiSupport; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetBidiSupport(uint8_t *aBidiSupport)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetBidiSupport(uint8_t aBidiSupport)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute uint32_t bidiOptions; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetBidiOptions(uint32_t *aBidiOptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetBidiOptions(uint32_t aBidiOptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long minFontSize; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetMinFontSize(int32_t *aMinFontSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetMinFontSize(int32_t aMinFontSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void appendSubtree (in nsIMarkupDocumentViewerTArray array); */
NS_IMETHODIMP nsMarkupDocumentViewer::AppendSubtree(nsTArray<nsCOMPtr<nsIMarkupDocumentViewer> > & array)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void changeMaxLineBoxWidth (in int32_t maxLineBoxWidth); */
NS_IMETHODIMP nsMarkupDocumentViewer::ChangeMaxLineBoxWidth(int32_t maxLineBoxWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMarkupDocumentViewer_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMarkupDocumentViewer.idl
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

template<class T> class nsCOMPtr;
template<class T> class nsTArray;
class nsIMarkupDocumentViewer; /* forward declaration */


/* starting interface:    nsIMarkupDocumentViewer */
#define NS_IMARKUPDOCUMENTVIEWER_IID_STR "7aea9561-5346-401c-b40e-418688da2d0d"

#define NS_IMARKUPDOCUMENTVIEWER_IID \
  {0x7aea9561, 0x5346, 0x401c, \
    { 0xb4, 0x0e, 0x41, 0x86, 0x88, 0xda, 0x2d, 0x0d }}

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

  /* attribute ACString forceCharacterSet; */
  NS_IMETHOD GetForceCharacterSet(nsACString & aForceCharacterSet) = 0;
  NS_IMETHOD SetForceCharacterSet(const nsACString & aForceCharacterSet) = 0;

  /* attribute ACString hintCharacterSet; */
  NS_IMETHOD GetHintCharacterSet(nsACString & aHintCharacterSet) = 0;
  NS_IMETHOD SetHintCharacterSet(const nsACString & aHintCharacterSet) = 0;

  /* attribute int32_t hintCharacterSetSource; */
  NS_IMETHOD GetHintCharacterSetSource(int32_t *aHintCharacterSetSource) = 0;
  NS_IMETHOD SetHintCharacterSetSource(int32_t aHintCharacterSetSource) = 0;

  /* void getContentSize (out long width, out long height); */
  NS_IMETHOD GetContentSize(int32_t *width, int32_t *height) = 0;

  /* attribute long minFontSize; */
  NS_IMETHOD GetMinFontSize(int32_t *aMinFontSize) = 0;
  NS_IMETHOD SetMinFontSize(int32_t aMinFontSize) = 0;

  /* [noscript] void appendSubtree (in nsIMarkupDocumentViewerTArray array); */
  NS_IMETHOD AppendSubtree(nsTArray<nsCOMPtr<nsIMarkupDocumentViewer> > & array) = 0;

  /* void changeMaxLineBoxWidth (in int32_t maxLineBoxWidth); */
  NS_IMETHOD ChangeMaxLineBoxWidth(int32_t maxLineBoxWidth) = 0;

  /* void pausePainting (); */
  NS_IMETHOD PausePainting(void) = 0;

  /* void resumePainting (); */
  NS_IMETHOD ResumePainting(void) = 0;

  /* void emulateMedium (in AString aMediaType); */
  NS_IMETHOD EmulateMedium(const nsAString & aMediaType) = 0;

  /* void stopEmulatingMedium (); */
  NS_IMETHOD StopEmulatingMedium(void) = 0;

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
  NS_IMETHOD GetForceCharacterSet(nsACString & aForceCharacterSet); \
  NS_IMETHOD SetForceCharacterSet(const nsACString & aForceCharacterSet); \
  NS_IMETHOD GetHintCharacterSet(nsACString & aHintCharacterSet); \
  NS_IMETHOD SetHintCharacterSet(const nsACString & aHintCharacterSet); \
  NS_IMETHOD GetHintCharacterSetSource(int32_t *aHintCharacterSetSource); \
  NS_IMETHOD SetHintCharacterSetSource(int32_t aHintCharacterSetSource); \
  NS_IMETHOD GetContentSize(int32_t *width, int32_t *height); \
  NS_IMETHOD GetMinFontSize(int32_t *aMinFontSize); \
  NS_IMETHOD SetMinFontSize(int32_t aMinFontSize); \
  NS_IMETHOD AppendSubtree(nsTArray<nsCOMPtr<nsIMarkupDocumentViewer> > & array); \
  NS_IMETHOD ChangeMaxLineBoxWidth(int32_t maxLineBoxWidth); \
  NS_IMETHOD PausePainting(void); \
  NS_IMETHOD ResumePainting(void); \
  NS_IMETHOD EmulateMedium(const nsAString & aMediaType); \
  NS_IMETHOD StopEmulatingMedium(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMARKUPDOCUMENTVIEWER(_to) \
  NS_IMETHOD ScrollToNode(nsIDOMNode *node) { return _to ScrollToNode(node); } \
  NS_IMETHOD GetTextZoom(float *aTextZoom) { return _to GetTextZoom(aTextZoom); } \
  NS_IMETHOD SetTextZoom(float aTextZoom) { return _to SetTextZoom(aTextZoom); } \
  NS_IMETHOD GetFullZoom(float *aFullZoom) { return _to GetFullZoom(aFullZoom); } \
  NS_IMETHOD SetFullZoom(float aFullZoom) { return _to SetFullZoom(aFullZoom); } \
  NS_IMETHOD GetAuthorStyleDisabled(bool *aAuthorStyleDisabled) { return _to GetAuthorStyleDisabled(aAuthorStyleDisabled); } \
  NS_IMETHOD SetAuthorStyleDisabled(bool aAuthorStyleDisabled) { return _to SetAuthorStyleDisabled(aAuthorStyleDisabled); } \
  NS_IMETHOD GetForceCharacterSet(nsACString & aForceCharacterSet) { return _to GetForceCharacterSet(aForceCharacterSet); } \
  NS_IMETHOD SetForceCharacterSet(const nsACString & aForceCharacterSet) { return _to SetForceCharacterSet(aForceCharacterSet); } \
  NS_IMETHOD GetHintCharacterSet(nsACString & aHintCharacterSet) { return _to GetHintCharacterSet(aHintCharacterSet); } \
  NS_IMETHOD SetHintCharacterSet(const nsACString & aHintCharacterSet) { return _to SetHintCharacterSet(aHintCharacterSet); } \
  NS_IMETHOD GetHintCharacterSetSource(int32_t *aHintCharacterSetSource) { return _to GetHintCharacterSetSource(aHintCharacterSetSource); } \
  NS_IMETHOD SetHintCharacterSetSource(int32_t aHintCharacterSetSource) { return _to SetHintCharacterSetSource(aHintCharacterSetSource); } \
  NS_IMETHOD GetContentSize(int32_t *width, int32_t *height) { return _to GetContentSize(width, height); } \
  NS_IMETHOD GetMinFontSize(int32_t *aMinFontSize) { return _to GetMinFontSize(aMinFontSize); } \
  NS_IMETHOD SetMinFontSize(int32_t aMinFontSize) { return _to SetMinFontSize(aMinFontSize); } \
  NS_IMETHOD AppendSubtree(nsTArray<nsCOMPtr<nsIMarkupDocumentViewer> > & array) { return _to AppendSubtree(array); } \
  NS_IMETHOD ChangeMaxLineBoxWidth(int32_t maxLineBoxWidth) { return _to ChangeMaxLineBoxWidth(maxLineBoxWidth); } \
  NS_IMETHOD PausePainting(void) { return _to PausePainting(); } \
  NS_IMETHOD ResumePainting(void) { return _to ResumePainting(); } \
  NS_IMETHOD EmulateMedium(const nsAString & aMediaType) { return _to EmulateMedium(aMediaType); } \
  NS_IMETHOD StopEmulatingMedium(void) { return _to StopEmulatingMedium(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMARKUPDOCUMENTVIEWER(_to) \
  NS_IMETHOD ScrollToNode(nsIDOMNode *node) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollToNode(node); } \
  NS_IMETHOD GetTextZoom(float *aTextZoom) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextZoom(aTextZoom); } \
  NS_IMETHOD SetTextZoom(float aTextZoom) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTextZoom(aTextZoom); } \
  NS_IMETHOD GetFullZoom(float *aFullZoom) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFullZoom(aFullZoom); } \
  NS_IMETHOD SetFullZoom(float aFullZoom) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFullZoom(aFullZoom); } \
  NS_IMETHOD GetAuthorStyleDisabled(bool *aAuthorStyleDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAuthorStyleDisabled(aAuthorStyleDisabled); } \
  NS_IMETHOD SetAuthorStyleDisabled(bool aAuthorStyleDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAuthorStyleDisabled(aAuthorStyleDisabled); } \
  NS_IMETHOD GetForceCharacterSet(nsACString & aForceCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForceCharacterSet(aForceCharacterSet); } \
  NS_IMETHOD SetForceCharacterSet(const nsACString & aForceCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetForceCharacterSet(aForceCharacterSet); } \
  NS_IMETHOD GetHintCharacterSet(nsACString & aHintCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHintCharacterSet(aHintCharacterSet); } \
  NS_IMETHOD SetHintCharacterSet(const nsACString & aHintCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHintCharacterSet(aHintCharacterSet); } \
  NS_IMETHOD GetHintCharacterSetSource(int32_t *aHintCharacterSetSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHintCharacterSetSource(aHintCharacterSetSource); } \
  NS_IMETHOD SetHintCharacterSetSource(int32_t aHintCharacterSetSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHintCharacterSetSource(aHintCharacterSetSource); } \
  NS_IMETHOD GetContentSize(int32_t *width, int32_t *height) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentSize(width, height); } \
  NS_IMETHOD GetMinFontSize(int32_t *aMinFontSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMinFontSize(aMinFontSize); } \
  NS_IMETHOD SetMinFontSize(int32_t aMinFontSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMinFontSize(aMinFontSize); } \
  NS_IMETHOD AppendSubtree(nsTArray<nsCOMPtr<nsIMarkupDocumentViewer> > & array) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendSubtree(array); } \
  NS_IMETHOD ChangeMaxLineBoxWidth(int32_t maxLineBoxWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->ChangeMaxLineBoxWidth(maxLineBoxWidth); } \
  NS_IMETHOD PausePainting(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PausePainting(); } \
  NS_IMETHOD ResumePainting(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResumePainting(); } \
  NS_IMETHOD EmulateMedium(const nsAString & aMediaType) { return !_to ? NS_ERROR_NULL_POINTER : _to->EmulateMedium(aMediaType); } \
  NS_IMETHOD StopEmulatingMedium(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StopEmulatingMedium(); } 

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

/* void getContentSize (out long width, out long height); */
NS_IMETHODIMP nsMarkupDocumentViewer::GetContentSize(int32_t *width, int32_t *height)
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

/* void pausePainting (); */
NS_IMETHODIMP nsMarkupDocumentViewer::PausePainting()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resumePainting (); */
NS_IMETHODIMP nsMarkupDocumentViewer::ResumePainting()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void emulateMedium (in AString aMediaType); */
NS_IMETHODIMP nsMarkupDocumentViewer::EmulateMedium(const nsAString & aMediaType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stopEmulatingMedium (); */
NS_IMETHODIMP nsMarkupDocumentViewer::StopEmulatingMedium()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMarkupDocumentViewer_h__ */

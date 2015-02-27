/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/layout/inspector/public/inIDOMView.idl
 */

#ifndef __gen_inIDOMView_h__
#define __gen_inIDOMView_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNode; /* forward declaration */


/* starting interface:    inIDOMView */
#define INIDOMVIEW_IID_STR "fbb67442-27a3-483c-8eb2-29c3eed7514c"

#define INIDOMVIEW_IID \
  {0xfbb67442, 0x27a3, 0x483c, \
    { 0x8e, 0xb2, 0x29, 0xc3, 0xee, 0xd7, 0x51, 0x4c }}

class NS_NO_VTABLE inIDOMView : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(INIDOMVIEW_IID)

  /* attribute nsIDOMNode rootNode; */
  NS_IMETHOD GetRootNode(nsIDOMNode * *aRootNode) = 0;
  NS_IMETHOD SetRootNode(nsIDOMNode *aRootNode) = 0;

  /* attribute boolean showAnonymousContent; */
  NS_IMETHOD GetShowAnonymousContent(bool *aShowAnonymousContent) = 0;
  NS_IMETHOD SetShowAnonymousContent(bool aShowAnonymousContent) = 0;

  /* attribute boolean showSubDocuments; */
  NS_IMETHOD GetShowSubDocuments(bool *aShowSubDocuments) = 0;
  NS_IMETHOD SetShowSubDocuments(bool aShowSubDocuments) = 0;

  /* attribute boolean showWhitespaceNodes; */
  NS_IMETHOD GetShowWhitespaceNodes(bool *aShowWhitespaceNodes) = 0;
  NS_IMETHOD SetShowWhitespaceNodes(bool aShowWhitespaceNodes) = 0;

  /* attribute boolean showAccessibleNodes; */
  NS_IMETHOD GetShowAccessibleNodes(bool *aShowAccessibleNodes) = 0;
  NS_IMETHOD SetShowAccessibleNodes(bool aShowAccessibleNodes) = 0;

  /* attribute unsigned long whatToShow; */
  NS_IMETHOD GetWhatToShow(uint32_t *aWhatToShow) = 0;
  NS_IMETHOD SetWhatToShow(uint32_t aWhatToShow) = 0;

  /* nsIDOMNode getNodeFromRowIndex (in long rowIndex); */
  NS_IMETHOD GetNodeFromRowIndex(int32_t rowIndex, nsIDOMNode * *_retval) = 0;

  /* long getRowIndexFromNode (in nsIDOMNode node); */
  NS_IMETHOD GetRowIndexFromNode(nsIDOMNode *node, int32_t *_retval) = 0;

  /* void rebuild (); */
  NS_IMETHOD Rebuild(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(inIDOMView, INIDOMVIEW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_INIDOMVIEW \
  NS_IMETHOD GetRootNode(nsIDOMNode * *aRootNode); \
  NS_IMETHOD SetRootNode(nsIDOMNode *aRootNode); \
  NS_IMETHOD GetShowAnonymousContent(bool *aShowAnonymousContent); \
  NS_IMETHOD SetShowAnonymousContent(bool aShowAnonymousContent); \
  NS_IMETHOD GetShowSubDocuments(bool *aShowSubDocuments); \
  NS_IMETHOD SetShowSubDocuments(bool aShowSubDocuments); \
  NS_IMETHOD GetShowWhitespaceNodes(bool *aShowWhitespaceNodes); \
  NS_IMETHOD SetShowWhitespaceNodes(bool aShowWhitespaceNodes); \
  NS_IMETHOD GetShowAccessibleNodes(bool *aShowAccessibleNodes); \
  NS_IMETHOD SetShowAccessibleNodes(bool aShowAccessibleNodes); \
  NS_IMETHOD GetWhatToShow(uint32_t *aWhatToShow); \
  NS_IMETHOD SetWhatToShow(uint32_t aWhatToShow); \
  NS_IMETHOD GetNodeFromRowIndex(int32_t rowIndex, nsIDOMNode * *_retval); \
  NS_IMETHOD GetRowIndexFromNode(nsIDOMNode *node, int32_t *_retval); \
  NS_IMETHOD Rebuild(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_INIDOMVIEW(_to) \
  NS_IMETHOD GetRootNode(nsIDOMNode * *aRootNode) { return _to GetRootNode(aRootNode); } \
  NS_IMETHOD SetRootNode(nsIDOMNode *aRootNode) { return _to SetRootNode(aRootNode); } \
  NS_IMETHOD GetShowAnonymousContent(bool *aShowAnonymousContent) { return _to GetShowAnonymousContent(aShowAnonymousContent); } \
  NS_IMETHOD SetShowAnonymousContent(bool aShowAnonymousContent) { return _to SetShowAnonymousContent(aShowAnonymousContent); } \
  NS_IMETHOD GetShowSubDocuments(bool *aShowSubDocuments) { return _to GetShowSubDocuments(aShowSubDocuments); } \
  NS_IMETHOD SetShowSubDocuments(bool aShowSubDocuments) { return _to SetShowSubDocuments(aShowSubDocuments); } \
  NS_IMETHOD GetShowWhitespaceNodes(bool *aShowWhitespaceNodes) { return _to GetShowWhitespaceNodes(aShowWhitespaceNodes); } \
  NS_IMETHOD SetShowWhitespaceNodes(bool aShowWhitespaceNodes) { return _to SetShowWhitespaceNodes(aShowWhitespaceNodes); } \
  NS_IMETHOD GetShowAccessibleNodes(bool *aShowAccessibleNodes) { return _to GetShowAccessibleNodes(aShowAccessibleNodes); } \
  NS_IMETHOD SetShowAccessibleNodes(bool aShowAccessibleNodes) { return _to SetShowAccessibleNodes(aShowAccessibleNodes); } \
  NS_IMETHOD GetWhatToShow(uint32_t *aWhatToShow) { return _to GetWhatToShow(aWhatToShow); } \
  NS_IMETHOD SetWhatToShow(uint32_t aWhatToShow) { return _to SetWhatToShow(aWhatToShow); } \
  NS_IMETHOD GetNodeFromRowIndex(int32_t rowIndex, nsIDOMNode * *_retval) { return _to GetNodeFromRowIndex(rowIndex, _retval); } \
  NS_IMETHOD GetRowIndexFromNode(nsIDOMNode *node, int32_t *_retval) { return _to GetRowIndexFromNode(node, _retval); } \
  NS_IMETHOD Rebuild(void) { return _to Rebuild(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_INIDOMVIEW(_to) \
  NS_IMETHOD GetRootNode(nsIDOMNode * *aRootNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootNode(aRootNode); } \
  NS_IMETHOD SetRootNode(nsIDOMNode *aRootNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRootNode(aRootNode); } \
  NS_IMETHOD GetShowAnonymousContent(bool *aShowAnonymousContent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShowAnonymousContent(aShowAnonymousContent); } \
  NS_IMETHOD SetShowAnonymousContent(bool aShowAnonymousContent) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShowAnonymousContent(aShowAnonymousContent); } \
  NS_IMETHOD GetShowSubDocuments(bool *aShowSubDocuments) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShowSubDocuments(aShowSubDocuments); } \
  NS_IMETHOD SetShowSubDocuments(bool aShowSubDocuments) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShowSubDocuments(aShowSubDocuments); } \
  NS_IMETHOD GetShowWhitespaceNodes(bool *aShowWhitespaceNodes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShowWhitespaceNodes(aShowWhitespaceNodes); } \
  NS_IMETHOD SetShowWhitespaceNodes(bool aShowWhitespaceNodes) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShowWhitespaceNodes(aShowWhitespaceNodes); } \
  NS_IMETHOD GetShowAccessibleNodes(bool *aShowAccessibleNodes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShowAccessibleNodes(aShowAccessibleNodes); } \
  NS_IMETHOD SetShowAccessibleNodes(bool aShowAccessibleNodes) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShowAccessibleNodes(aShowAccessibleNodes); } \
  NS_IMETHOD GetWhatToShow(uint32_t *aWhatToShow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWhatToShow(aWhatToShow); } \
  NS_IMETHOD SetWhatToShow(uint32_t aWhatToShow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWhatToShow(aWhatToShow); } \
  NS_IMETHOD GetNodeFromRowIndex(int32_t rowIndex, nsIDOMNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNodeFromRowIndex(rowIndex, _retval); } \
  NS_IMETHOD GetRowIndexFromNode(nsIDOMNode *node, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowIndexFromNode(node, _retval); } \
  NS_IMETHOD Rebuild(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Rebuild(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class inDOMView : public inIDOMView
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_INIDOMVIEW

  inDOMView();

private:
  ~inDOMView();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(inDOMView, inIDOMView)

inDOMView::inDOMView()
{
  /* member initializers and constructor code */
}

inDOMView::~inDOMView()
{
  /* destructor code */
}

/* attribute nsIDOMNode rootNode; */
NS_IMETHODIMP inDOMView::GetRootNode(nsIDOMNode * *aRootNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inDOMView::SetRootNode(nsIDOMNode *aRootNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean showAnonymousContent; */
NS_IMETHODIMP inDOMView::GetShowAnonymousContent(bool *aShowAnonymousContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inDOMView::SetShowAnonymousContent(bool aShowAnonymousContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean showSubDocuments; */
NS_IMETHODIMP inDOMView::GetShowSubDocuments(bool *aShowSubDocuments)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inDOMView::SetShowSubDocuments(bool aShowSubDocuments)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean showWhitespaceNodes; */
NS_IMETHODIMP inDOMView::GetShowWhitespaceNodes(bool *aShowWhitespaceNodes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inDOMView::SetShowWhitespaceNodes(bool aShowWhitespaceNodes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean showAccessibleNodes; */
NS_IMETHODIMP inDOMView::GetShowAccessibleNodes(bool *aShowAccessibleNodes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inDOMView::SetShowAccessibleNodes(bool aShowAccessibleNodes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long whatToShow; */
NS_IMETHODIMP inDOMView::GetWhatToShow(uint32_t *aWhatToShow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inDOMView::SetWhatToShow(uint32_t aWhatToShow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode getNodeFromRowIndex (in long rowIndex); */
NS_IMETHODIMP inDOMView::GetNodeFromRowIndex(int32_t rowIndex, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getRowIndexFromNode (in nsIDOMNode node); */
NS_IMETHODIMP inDOMView::GetRowIndexFromNode(nsIDOMNode *node, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void rebuild (); */
NS_IMETHODIMP inDOMView::Rebuild()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_inIDOMView_h__ */

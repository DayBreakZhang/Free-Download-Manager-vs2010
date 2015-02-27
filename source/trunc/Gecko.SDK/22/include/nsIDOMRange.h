/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/range/nsIDOMRange.idl
 */

#ifndef __gen_nsIDOMRange_h__
#define __gen_nsIDOMRange_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMRange */
#define NS_IDOMRANGE_IID_STR "1f94055c-42e7-4a30-96a1-6a804f1c2d1e"

#define NS_IDOMRANGE_IID \
  {0x1f94055c, 0x42e7, 0x4a30, \
    { 0x96, 0xa1, 0x6a, 0x80, 0x4f, 0x1c, 0x2d, 0x1e }}

class NS_NO_VTABLE nsIDOMRange : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMRANGE_IID)

  /* readonly attribute nsIDOMNode startContainer; */
  NS_IMETHOD GetStartContainer(nsIDOMNode * *aStartContainer) = 0;

  /* readonly attribute long startOffset; */
  NS_IMETHOD GetStartOffset(int32_t *aStartOffset) = 0;

  /* readonly attribute nsIDOMNode endContainer; */
  NS_IMETHOD GetEndContainer(nsIDOMNode * *aEndContainer) = 0;

  /* readonly attribute long endOffset; */
  NS_IMETHOD GetEndOffset(int32_t *aEndOffset) = 0;

  /* readonly attribute boolean collapsed; */
  NS_IMETHOD GetCollapsed(bool *aCollapsed) = 0;

  /* readonly attribute nsIDOMNode commonAncestorContainer; */
  NS_IMETHOD GetCommonAncestorContainer(nsIDOMNode * *aCommonAncestorContainer) = 0;

  /* void setStart (in nsIDOMNode refNode, in long offset); */
  NS_IMETHOD SetStart(nsIDOMNode *refNode, int32_t offset) = 0;

  /* void setEnd (in nsIDOMNode refNode, in long offset); */
  NS_IMETHOD SetEnd(nsIDOMNode *refNode, int32_t offset) = 0;

  /* void setStartBefore (in nsIDOMNode refNode); */
  NS_IMETHOD SetStartBefore(nsIDOMNode *refNode) = 0;

  /* void setStartAfter (in nsIDOMNode refNode); */
  NS_IMETHOD SetStartAfter(nsIDOMNode *refNode) = 0;

  /* void setEndBefore (in nsIDOMNode refNode); */
  NS_IMETHOD SetEndBefore(nsIDOMNode *refNode) = 0;

  /* void setEndAfter (in nsIDOMNode refNode); */
  NS_IMETHOD SetEndAfter(nsIDOMNode *refNode) = 0;

  /* void collapse (in boolean toStart); */
  NS_IMETHOD Collapse(bool toStart) = 0;

  /* void selectNode (in nsIDOMNode refNode); */
  NS_IMETHOD SelectNode(nsIDOMNode *refNode) = 0;

  /* void selectNodeContents (in nsIDOMNode refNode); */
  NS_IMETHOD SelectNodeContents(nsIDOMNode *refNode) = 0;

  enum {
    START_TO_START = 0U,
    START_TO_END = 1U,
    END_TO_END = 2U,
    END_TO_START = 3U
  };

  /* short compareBoundaryPoints (in unsigned short how, in nsIDOMRange sourceRange); */
  NS_IMETHOD CompareBoundaryPoints(uint16_t how, nsIDOMRange *sourceRange, int16_t *_retval) = 0;

  /* void deleteContents (); */
  NS_IMETHOD DeleteContents(void) = 0;

  /* nsIDOMDocumentFragment extractContents (); */
  NS_IMETHOD ExtractContents(nsIDOMDocumentFragment * *_retval) = 0;

  /* nsIDOMDocumentFragment cloneContents (); */
  NS_IMETHOD CloneContents(nsIDOMDocumentFragment * *_retval) = 0;

  /* void insertNode (in nsIDOMNode newNode); */
  NS_IMETHOD InsertNode(nsIDOMNode *newNode) = 0;

  /* void surroundContents (in nsIDOMNode newParent); */
  NS_IMETHOD SurroundContents(nsIDOMNode *newParent) = 0;

  /* nsIDOMRange cloneRange (); */
  NS_IMETHOD CloneRange(nsIDOMRange * *_retval) = 0;

  /* DOMString toString (); */
  NS_IMETHOD ToString(nsAString & _retval) = 0;

  /* void detach (); */
  NS_IMETHOD Detach(void) = 0;

  /* nsIDOMDocumentFragment createContextualFragment (in DOMString fragment); */
  NS_IMETHOD CreateContextualFragment(const nsAString & fragment, nsIDOMDocumentFragment * *_retval) = 0;

  /* boolean isPointInRange (in nsIDOMNode parent, in long offset); */
  NS_IMETHOD IsPointInRange(nsIDOMNode *parent, int32_t offset, bool *_retval) = 0;

  /* short comparePoint (in nsIDOMNode parent, in long offset); */
  NS_IMETHOD ComparePoint(nsIDOMNode *parent, int32_t offset, int16_t *_retval) = 0;

  /* boolean intersectsNode (in nsIDOMNode node); */
  NS_IMETHOD IntersectsNode(nsIDOMNode *node, bool *_retval) = 0;

  /* nsIDOMClientRectList getClientRects (); */
  NS_IMETHOD GetClientRects(nsIDOMClientRectList * *_retval) = 0;

  /* nsIDOMClientRect getBoundingClientRect (); */
  NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMRange, NS_IDOMRANGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMRANGE \
  NS_IMETHOD GetStartContainer(nsIDOMNode * *aStartContainer); \
  NS_IMETHOD GetStartOffset(int32_t *aStartOffset); \
  NS_IMETHOD GetEndContainer(nsIDOMNode * *aEndContainer); \
  NS_IMETHOD GetEndOffset(int32_t *aEndOffset); \
  NS_IMETHOD GetCollapsed(bool *aCollapsed); \
  NS_IMETHOD GetCommonAncestorContainer(nsIDOMNode * *aCommonAncestorContainer); \
  NS_IMETHOD SetStart(nsIDOMNode *refNode, int32_t offset); \
  NS_IMETHOD SetEnd(nsIDOMNode *refNode, int32_t offset); \
  NS_IMETHOD SetStartBefore(nsIDOMNode *refNode); \
  NS_IMETHOD SetStartAfter(nsIDOMNode *refNode); \
  NS_IMETHOD SetEndBefore(nsIDOMNode *refNode); \
  NS_IMETHOD SetEndAfter(nsIDOMNode *refNode); \
  NS_IMETHOD Collapse(bool toStart); \
  NS_IMETHOD SelectNode(nsIDOMNode *refNode); \
  NS_IMETHOD SelectNodeContents(nsIDOMNode *refNode); \
  NS_IMETHOD CompareBoundaryPoints(uint16_t how, nsIDOMRange *sourceRange, int16_t *_retval); \
  NS_IMETHOD DeleteContents(void); \
  NS_IMETHOD ExtractContents(nsIDOMDocumentFragment * *_retval); \
  NS_IMETHOD CloneContents(nsIDOMDocumentFragment * *_retval); \
  NS_IMETHOD InsertNode(nsIDOMNode *newNode); \
  NS_IMETHOD SurroundContents(nsIDOMNode *newParent); \
  NS_IMETHOD CloneRange(nsIDOMRange * *_retval); \
  NS_IMETHOD ToString(nsAString & _retval); \
  NS_IMETHOD Detach(void); \
  NS_IMETHOD CreateContextualFragment(const nsAString & fragment, nsIDOMDocumentFragment * *_retval); \
  NS_IMETHOD IsPointInRange(nsIDOMNode *parent, int32_t offset, bool *_retval); \
  NS_IMETHOD ComparePoint(nsIDOMNode *parent, int32_t offset, int16_t *_retval); \
  NS_IMETHOD IntersectsNode(nsIDOMNode *node, bool *_retval); \
  NS_IMETHOD GetClientRects(nsIDOMClientRectList * *_retval); \
  NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMRANGE(_to) \
  NS_IMETHOD GetStartContainer(nsIDOMNode * *aStartContainer) { return _to GetStartContainer(aStartContainer); } \
  NS_IMETHOD GetStartOffset(int32_t *aStartOffset) { return _to GetStartOffset(aStartOffset); } \
  NS_IMETHOD GetEndContainer(nsIDOMNode * *aEndContainer) { return _to GetEndContainer(aEndContainer); } \
  NS_IMETHOD GetEndOffset(int32_t *aEndOffset) { return _to GetEndOffset(aEndOffset); } \
  NS_IMETHOD GetCollapsed(bool *aCollapsed) { return _to GetCollapsed(aCollapsed); } \
  NS_IMETHOD GetCommonAncestorContainer(nsIDOMNode * *aCommonAncestorContainer) { return _to GetCommonAncestorContainer(aCommonAncestorContainer); } \
  NS_IMETHOD SetStart(nsIDOMNode *refNode, int32_t offset) { return _to SetStart(refNode, offset); } \
  NS_IMETHOD SetEnd(nsIDOMNode *refNode, int32_t offset) { return _to SetEnd(refNode, offset); } \
  NS_IMETHOD SetStartBefore(nsIDOMNode *refNode) { return _to SetStartBefore(refNode); } \
  NS_IMETHOD SetStartAfter(nsIDOMNode *refNode) { return _to SetStartAfter(refNode); } \
  NS_IMETHOD SetEndBefore(nsIDOMNode *refNode) { return _to SetEndBefore(refNode); } \
  NS_IMETHOD SetEndAfter(nsIDOMNode *refNode) { return _to SetEndAfter(refNode); } \
  NS_IMETHOD Collapse(bool toStart) { return _to Collapse(toStart); } \
  NS_IMETHOD SelectNode(nsIDOMNode *refNode) { return _to SelectNode(refNode); } \
  NS_IMETHOD SelectNodeContents(nsIDOMNode *refNode) { return _to SelectNodeContents(refNode); } \
  NS_IMETHOD CompareBoundaryPoints(uint16_t how, nsIDOMRange *sourceRange, int16_t *_retval) { return _to CompareBoundaryPoints(how, sourceRange, _retval); } \
  NS_IMETHOD DeleteContents(void) { return _to DeleteContents(); } \
  NS_IMETHOD ExtractContents(nsIDOMDocumentFragment * *_retval) { return _to ExtractContents(_retval); } \
  NS_IMETHOD CloneContents(nsIDOMDocumentFragment * *_retval) { return _to CloneContents(_retval); } \
  NS_IMETHOD InsertNode(nsIDOMNode *newNode) { return _to InsertNode(newNode); } \
  NS_IMETHOD SurroundContents(nsIDOMNode *newParent) { return _to SurroundContents(newParent); } \
  NS_IMETHOD CloneRange(nsIDOMRange * *_retval) { return _to CloneRange(_retval); } \
  NS_IMETHOD ToString(nsAString & _retval) { return _to ToString(_retval); } \
  NS_IMETHOD Detach(void) { return _to Detach(); } \
  NS_IMETHOD CreateContextualFragment(const nsAString & fragment, nsIDOMDocumentFragment * *_retval) { return _to CreateContextualFragment(fragment, _retval); } \
  NS_IMETHOD IsPointInRange(nsIDOMNode *parent, int32_t offset, bool *_retval) { return _to IsPointInRange(parent, offset, _retval); } \
  NS_IMETHOD ComparePoint(nsIDOMNode *parent, int32_t offset, int16_t *_retval) { return _to ComparePoint(parent, offset, _retval); } \
  NS_IMETHOD IntersectsNode(nsIDOMNode *node, bool *_retval) { return _to IntersectsNode(node, _retval); } \
  NS_IMETHOD GetClientRects(nsIDOMClientRectList * *_retval) { return _to GetClientRects(_retval); } \
  NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect * *_retval) { return _to GetBoundingClientRect(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMRANGE(_to) \
  NS_IMETHOD GetStartContainer(nsIDOMNode * *aStartContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartContainer(aStartContainer); } \
  NS_IMETHOD GetStartOffset(int32_t *aStartOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartOffset(aStartOffset); } \
  NS_IMETHOD GetEndContainer(nsIDOMNode * *aEndContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndContainer(aEndContainer); } \
  NS_IMETHOD GetEndOffset(int32_t *aEndOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndOffset(aEndOffset); } \
  NS_IMETHOD GetCollapsed(bool *aCollapsed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCollapsed(aCollapsed); } \
  NS_IMETHOD GetCommonAncestorContainer(nsIDOMNode * *aCommonAncestorContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCommonAncestorContainer(aCommonAncestorContainer); } \
  NS_IMETHOD SetStart(nsIDOMNode *refNode, int32_t offset) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStart(refNode, offset); } \
  NS_IMETHOD SetEnd(nsIDOMNode *refNode, int32_t offset) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEnd(refNode, offset); } \
  NS_IMETHOD SetStartBefore(nsIDOMNode *refNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStartBefore(refNode); } \
  NS_IMETHOD SetStartAfter(nsIDOMNode *refNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStartAfter(refNode); } \
  NS_IMETHOD SetEndBefore(nsIDOMNode *refNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEndBefore(refNode); } \
  NS_IMETHOD SetEndAfter(nsIDOMNode *refNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEndAfter(refNode); } \
  NS_IMETHOD Collapse(bool toStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->Collapse(toStart); } \
  NS_IMETHOD SelectNode(nsIDOMNode *refNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectNode(refNode); } \
  NS_IMETHOD SelectNodeContents(nsIDOMNode *refNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectNodeContents(refNode); } \
  NS_IMETHOD CompareBoundaryPoints(uint16_t how, nsIDOMRange *sourceRange, int16_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CompareBoundaryPoints(how, sourceRange, _retval); } \
  NS_IMETHOD DeleteContents(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteContents(); } \
  NS_IMETHOD ExtractContents(nsIDOMDocumentFragment * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExtractContents(_retval); } \
  NS_IMETHOD CloneContents(nsIDOMDocumentFragment * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloneContents(_retval); } \
  NS_IMETHOD InsertNode(nsIDOMNode *newNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertNode(newNode); } \
  NS_IMETHOD SurroundContents(nsIDOMNode *newParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->SurroundContents(newParent); } \
  NS_IMETHOD CloneRange(nsIDOMRange * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloneRange(_retval); } \
  NS_IMETHOD ToString(nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToString(_retval); } \
  NS_IMETHOD Detach(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Detach(); } \
  NS_IMETHOD CreateContextualFragment(const nsAString & fragment, nsIDOMDocumentFragment * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateContextualFragment(fragment, _retval); } \
  NS_IMETHOD IsPointInRange(nsIDOMNode *parent, int32_t offset, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsPointInRange(parent, offset, _retval); } \
  NS_IMETHOD ComparePoint(nsIDOMNode *parent, int32_t offset, int16_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ComparePoint(parent, offset, _retval); } \
  NS_IMETHOD IntersectsNode(nsIDOMNode *node, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IntersectsNode(node, _retval); } \
  NS_IMETHOD GetClientRects(nsIDOMClientRectList * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientRects(_retval); } \
  NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBoundingClientRect(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMRange : public nsIDOMRange
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMRANGE

  nsDOMRange();

private:
  ~nsDOMRange();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMRange, nsIDOMRange)

nsDOMRange::nsDOMRange()
{
  /* member initializers and constructor code */
}

nsDOMRange::~nsDOMRange()
{
  /* destructor code */
}

/* readonly attribute nsIDOMNode startContainer; */
NS_IMETHODIMP nsDOMRange::GetStartContainer(nsIDOMNode * *aStartContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long startOffset; */
NS_IMETHODIMP nsDOMRange::GetStartOffset(int32_t *aStartOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode endContainer; */
NS_IMETHODIMP nsDOMRange::GetEndContainer(nsIDOMNode * *aEndContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long endOffset; */
NS_IMETHODIMP nsDOMRange::GetEndOffset(int32_t *aEndOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean collapsed; */
NS_IMETHODIMP nsDOMRange::GetCollapsed(bool *aCollapsed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode commonAncestorContainer; */
NS_IMETHODIMP nsDOMRange::GetCommonAncestorContainer(nsIDOMNode * *aCommonAncestorContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setStart (in nsIDOMNode refNode, in long offset); */
NS_IMETHODIMP nsDOMRange::SetStart(nsIDOMNode *refNode, int32_t offset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setEnd (in nsIDOMNode refNode, in long offset); */
NS_IMETHODIMP nsDOMRange::SetEnd(nsIDOMNode *refNode, int32_t offset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setStartBefore (in nsIDOMNode refNode); */
NS_IMETHODIMP nsDOMRange::SetStartBefore(nsIDOMNode *refNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setStartAfter (in nsIDOMNode refNode); */
NS_IMETHODIMP nsDOMRange::SetStartAfter(nsIDOMNode *refNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setEndBefore (in nsIDOMNode refNode); */
NS_IMETHODIMP nsDOMRange::SetEndBefore(nsIDOMNode *refNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setEndAfter (in nsIDOMNode refNode); */
NS_IMETHODIMP nsDOMRange::SetEndAfter(nsIDOMNode *refNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void collapse (in boolean toStart); */
NS_IMETHODIMP nsDOMRange::Collapse(bool toStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectNode (in nsIDOMNode refNode); */
NS_IMETHODIMP nsDOMRange::SelectNode(nsIDOMNode *refNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectNodeContents (in nsIDOMNode refNode); */
NS_IMETHODIMP nsDOMRange::SelectNodeContents(nsIDOMNode *refNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* short compareBoundaryPoints (in unsigned short how, in nsIDOMRange sourceRange); */
NS_IMETHODIMP nsDOMRange::CompareBoundaryPoints(uint16_t how, nsIDOMRange *sourceRange, int16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteContents (); */
NS_IMETHODIMP nsDOMRange::DeleteContents()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocumentFragment extractContents (); */
NS_IMETHODIMP nsDOMRange::ExtractContents(nsIDOMDocumentFragment * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocumentFragment cloneContents (); */
NS_IMETHODIMP nsDOMRange::CloneContents(nsIDOMDocumentFragment * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertNode (in nsIDOMNode newNode); */
NS_IMETHODIMP nsDOMRange::InsertNode(nsIDOMNode *newNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void surroundContents (in nsIDOMNode newParent); */
NS_IMETHODIMP nsDOMRange::SurroundContents(nsIDOMNode *newParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMRange cloneRange (); */
NS_IMETHODIMP nsDOMRange::CloneRange(nsIDOMRange * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString toString (); */
NS_IMETHODIMP nsDOMRange::ToString(nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void detach (); */
NS_IMETHODIMP nsDOMRange::Detach()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocumentFragment createContextualFragment (in DOMString fragment); */
NS_IMETHODIMP nsDOMRange::CreateContextualFragment(const nsAString & fragment, nsIDOMDocumentFragment * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isPointInRange (in nsIDOMNode parent, in long offset); */
NS_IMETHODIMP nsDOMRange::IsPointInRange(nsIDOMNode *parent, int32_t offset, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* short comparePoint (in nsIDOMNode parent, in long offset); */
NS_IMETHODIMP nsDOMRange::ComparePoint(nsIDOMNode *parent, int32_t offset, int16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean intersectsNode (in nsIDOMNode node); */
NS_IMETHODIMP nsDOMRange::IntersectsNode(nsIDOMNode *node, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMClientRectList getClientRects (); */
NS_IMETHODIMP nsDOMRange::GetClientRects(nsIDOMClientRectList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMClientRect getBoundingClientRect (); */
NS_IMETHODIMP nsDOMRange::GetBoundingClientRect(nsIDOMClientRect * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMRange_h__ */

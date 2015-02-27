/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITreeBoxObject.idl
 */

#ifndef __gen_nsITreeBoxObject_h__
#define __gen_nsITreeBoxObject_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */

class nsITreeView; /* forward declaration */

class nsITreeSelection; /* forward declaration */

class nsITreeColumn; /* forward declaration */

class nsITreeColumns; /* forward declaration */

class nsIScriptableRegion; /* forward declaration */


/* starting interface:    nsITreeBoxObject */
#define NS_ITREEBOXOBJECT_IID_STR "64ba5199-c4f4-4498-bbdc-f8e4c369086c"

#define NS_ITREEBOXOBJECT_IID \
  {0x64ba5199, 0xc4f4, 0x4498, \
    { 0xbb, 0xdc, 0xf8, 0xe4, 0xc3, 0x69, 0x08, 0x6c }}

class NS_NO_VTABLE nsITreeBoxObject : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITREEBOXOBJECT_IID)

  /* readonly attribute nsITreeColumns columns; */
  NS_IMETHOD GetColumns(nsITreeColumns * *aColumns) = 0;

  /* attribute nsITreeView view; */
  NS_IMETHOD GetView(nsITreeView * *aView) = 0;
  NS_IMETHOD SetView(nsITreeView *aView) = 0;

  /* attribute boolean focused; */
  NS_IMETHOD GetFocused(bool *aFocused) = 0;
  NS_IMETHOD SetFocused(bool aFocused) = 0;

  /* readonly attribute nsIDOMElement treeBody; */
  NS_IMETHOD GetTreeBody(nsIDOMElement * *aTreeBody) = 0;

  /* readonly attribute long rowHeight; */
  NS_IMETHOD GetRowHeight(int32_t *aRowHeight) = 0;

  /* readonly attribute long rowWidth; */
  NS_IMETHOD GetRowWidth(int32_t *aRowWidth) = 0;

  /* readonly attribute long horizontalPosition; */
  NS_IMETHOD GetHorizontalPosition(int32_t *aHorizontalPosition) = 0;

  /* readonly attribute nsIScriptableRegion selectionRegion; */
  NS_IMETHOD GetSelectionRegion(nsIScriptableRegion * *aSelectionRegion) = 0;

  /* long getFirstVisibleRow (); */
  NS_IMETHOD GetFirstVisibleRow(int32_t *_retval) = 0;

  /* long getLastVisibleRow (); */
  NS_IMETHOD GetLastVisibleRow(int32_t *_retval) = 0;

  /* long getPageLength (); */
  NS_IMETHOD GetPageLength(int32_t *_retval) = 0;

  /* void ensureRowIsVisible (in long index); */
  NS_IMETHOD EnsureRowIsVisible(int32_t index) = 0;

  /* void ensureCellIsVisible (in long row, in nsITreeColumn col); */
  NS_IMETHOD EnsureCellIsVisible(int32_t row, nsITreeColumn *col) = 0;

  /* void scrollToRow (in long index); */
  NS_IMETHOD ScrollToRow(int32_t index) = 0;

  /* void scrollByLines (in long numLines); */
  NS_IMETHOD ScrollByLines(int32_t numLines) = 0;

  /* void scrollByPages (in long numPages); */
  NS_IMETHOD ScrollByPages(int32_t numPages) = 0;

  /* void scrollToCell (in long row, in nsITreeColumn col); */
  NS_IMETHOD ScrollToCell(int32_t row, nsITreeColumn *col) = 0;

  /* void scrollToColumn (in nsITreeColumn col); */
  NS_IMETHOD ScrollToColumn(nsITreeColumn *col) = 0;

  /* void scrollToHorizontalPosition (in long horizontalPosition); */
  NS_IMETHOD ScrollToHorizontalPosition(int32_t horizontalPosition) = 0;

  /* void invalidate (); */
  NS_IMETHOD Invalidate(void) = 0;

  /* void invalidateColumn (in nsITreeColumn col); */
  NS_IMETHOD InvalidateColumn(nsITreeColumn *col) = 0;

  /* void invalidateRow (in long index); */
  NS_IMETHOD InvalidateRow(int32_t index) = 0;

  /* void invalidateCell (in long row, in nsITreeColumn col); */
  NS_IMETHOD InvalidateCell(int32_t row, nsITreeColumn *col) = 0;

  /* void invalidateRange (in long startIndex, in long endIndex); */
  NS_IMETHOD InvalidateRange(int32_t startIndex, int32_t endIndex) = 0;

  /* void invalidateColumnRange (in long startIndex, in long endIndex, in nsITreeColumn col); */
  NS_IMETHOD InvalidateColumnRange(int32_t startIndex, int32_t endIndex, nsITreeColumn *col) = 0;

  /* long getRowAt (in long x, in long y); */
  NS_IMETHOD GetRowAt(int32_t x, int32_t y, int32_t *_retval) = 0;

  /* void getCellAt (in long x, in long y, out long row, out nsITreeColumn col, out ACString childElt); */
  NS_IMETHOD GetCellAt(int32_t x, int32_t y, int32_t *row, nsITreeColumn * *col, nsACString & childElt) = 0;

  /* void getCoordsForCellItem (in long row, in nsITreeColumn col, in ACString element, out long x, out long y, out long width, out long height); */
  NS_IMETHOD GetCoordsForCellItem(int32_t row, nsITreeColumn *col, const nsACString & element, int32_t *x, int32_t *y, int32_t *width, int32_t *height) = 0;

  /* boolean isCellCropped (in long row, in nsITreeColumn col); */
  NS_IMETHOD IsCellCropped(int32_t row, nsITreeColumn *col, bool *_retval) = 0;

  /* void rowCountChanged (in long index, in long count); */
  NS_IMETHOD RowCountChanged(int32_t index, int32_t count) = 0;

  /* void beginUpdateBatch (); */
  NS_IMETHOD BeginUpdateBatch(void) = 0;

  /* void endUpdateBatch (); */
  NS_IMETHOD EndUpdateBatch(void) = 0;

  /* void clearStyleAndImageCaches (); */
  NS_IMETHOD ClearStyleAndImageCaches(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITreeBoxObject, NS_ITREEBOXOBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITREEBOXOBJECT \
  NS_IMETHOD GetColumns(nsITreeColumns * *aColumns); \
  NS_IMETHOD GetView(nsITreeView * *aView); \
  NS_IMETHOD SetView(nsITreeView *aView); \
  NS_IMETHOD GetFocused(bool *aFocused); \
  NS_IMETHOD SetFocused(bool aFocused); \
  NS_IMETHOD GetTreeBody(nsIDOMElement * *aTreeBody); \
  NS_IMETHOD GetRowHeight(int32_t *aRowHeight); \
  NS_IMETHOD GetRowWidth(int32_t *aRowWidth); \
  NS_IMETHOD GetHorizontalPosition(int32_t *aHorizontalPosition); \
  NS_IMETHOD GetSelectionRegion(nsIScriptableRegion * *aSelectionRegion); \
  NS_IMETHOD GetFirstVisibleRow(int32_t *_retval); \
  NS_IMETHOD GetLastVisibleRow(int32_t *_retval); \
  NS_IMETHOD GetPageLength(int32_t *_retval); \
  NS_IMETHOD EnsureRowIsVisible(int32_t index); \
  NS_IMETHOD EnsureCellIsVisible(int32_t row, nsITreeColumn *col); \
  NS_IMETHOD ScrollToRow(int32_t index); \
  NS_IMETHOD ScrollByLines(int32_t numLines); \
  NS_IMETHOD ScrollByPages(int32_t numPages); \
  NS_IMETHOD ScrollToCell(int32_t row, nsITreeColumn *col); \
  NS_IMETHOD ScrollToColumn(nsITreeColumn *col); \
  NS_IMETHOD ScrollToHorizontalPosition(int32_t horizontalPosition); \
  NS_IMETHOD Invalidate(void); \
  NS_IMETHOD InvalidateColumn(nsITreeColumn *col); \
  NS_IMETHOD InvalidateRow(int32_t index); \
  NS_IMETHOD InvalidateCell(int32_t row, nsITreeColumn *col); \
  NS_IMETHOD InvalidateRange(int32_t startIndex, int32_t endIndex); \
  NS_IMETHOD InvalidateColumnRange(int32_t startIndex, int32_t endIndex, nsITreeColumn *col); \
  NS_IMETHOD GetRowAt(int32_t x, int32_t y, int32_t *_retval); \
  NS_IMETHOD GetCellAt(int32_t x, int32_t y, int32_t *row, nsITreeColumn * *col, nsACString & childElt); \
  NS_IMETHOD GetCoordsForCellItem(int32_t row, nsITreeColumn *col, const nsACString & element, int32_t *x, int32_t *y, int32_t *width, int32_t *height); \
  NS_IMETHOD IsCellCropped(int32_t row, nsITreeColumn *col, bool *_retval); \
  NS_IMETHOD RowCountChanged(int32_t index, int32_t count); \
  NS_IMETHOD BeginUpdateBatch(void); \
  NS_IMETHOD EndUpdateBatch(void); \
  NS_IMETHOD ClearStyleAndImageCaches(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITREEBOXOBJECT(_to) \
  NS_IMETHOD GetColumns(nsITreeColumns * *aColumns) { return _to GetColumns(aColumns); } \
  NS_IMETHOD GetView(nsITreeView * *aView) { return _to GetView(aView); } \
  NS_IMETHOD SetView(nsITreeView *aView) { return _to SetView(aView); } \
  NS_IMETHOD GetFocused(bool *aFocused) { return _to GetFocused(aFocused); } \
  NS_IMETHOD SetFocused(bool aFocused) { return _to SetFocused(aFocused); } \
  NS_IMETHOD GetTreeBody(nsIDOMElement * *aTreeBody) { return _to GetTreeBody(aTreeBody); } \
  NS_IMETHOD GetRowHeight(int32_t *aRowHeight) { return _to GetRowHeight(aRowHeight); } \
  NS_IMETHOD GetRowWidth(int32_t *aRowWidth) { return _to GetRowWidth(aRowWidth); } \
  NS_IMETHOD GetHorizontalPosition(int32_t *aHorizontalPosition) { return _to GetHorizontalPosition(aHorizontalPosition); } \
  NS_IMETHOD GetSelectionRegion(nsIScriptableRegion * *aSelectionRegion) { return _to GetSelectionRegion(aSelectionRegion); } \
  NS_IMETHOD GetFirstVisibleRow(int32_t *_retval) { return _to GetFirstVisibleRow(_retval); } \
  NS_IMETHOD GetLastVisibleRow(int32_t *_retval) { return _to GetLastVisibleRow(_retval); } \
  NS_IMETHOD GetPageLength(int32_t *_retval) { return _to GetPageLength(_retval); } \
  NS_IMETHOD EnsureRowIsVisible(int32_t index) { return _to EnsureRowIsVisible(index); } \
  NS_IMETHOD EnsureCellIsVisible(int32_t row, nsITreeColumn *col) { return _to EnsureCellIsVisible(row, col); } \
  NS_IMETHOD ScrollToRow(int32_t index) { return _to ScrollToRow(index); } \
  NS_IMETHOD ScrollByLines(int32_t numLines) { return _to ScrollByLines(numLines); } \
  NS_IMETHOD ScrollByPages(int32_t numPages) { return _to ScrollByPages(numPages); } \
  NS_IMETHOD ScrollToCell(int32_t row, nsITreeColumn *col) { return _to ScrollToCell(row, col); } \
  NS_IMETHOD ScrollToColumn(nsITreeColumn *col) { return _to ScrollToColumn(col); } \
  NS_IMETHOD ScrollToHorizontalPosition(int32_t horizontalPosition) { return _to ScrollToHorizontalPosition(horizontalPosition); } \
  NS_IMETHOD Invalidate(void) { return _to Invalidate(); } \
  NS_IMETHOD InvalidateColumn(nsITreeColumn *col) { return _to InvalidateColumn(col); } \
  NS_IMETHOD InvalidateRow(int32_t index) { return _to InvalidateRow(index); } \
  NS_IMETHOD InvalidateCell(int32_t row, nsITreeColumn *col) { return _to InvalidateCell(row, col); } \
  NS_IMETHOD InvalidateRange(int32_t startIndex, int32_t endIndex) { return _to InvalidateRange(startIndex, endIndex); } \
  NS_IMETHOD InvalidateColumnRange(int32_t startIndex, int32_t endIndex, nsITreeColumn *col) { return _to InvalidateColumnRange(startIndex, endIndex, col); } \
  NS_IMETHOD GetRowAt(int32_t x, int32_t y, int32_t *_retval) { return _to GetRowAt(x, y, _retval); } \
  NS_IMETHOD GetCellAt(int32_t x, int32_t y, int32_t *row, nsITreeColumn * *col, nsACString & childElt) { return _to GetCellAt(x, y, row, col, childElt); } \
  NS_IMETHOD GetCoordsForCellItem(int32_t row, nsITreeColumn *col, const nsACString & element, int32_t *x, int32_t *y, int32_t *width, int32_t *height) { return _to GetCoordsForCellItem(row, col, element, x, y, width, height); } \
  NS_IMETHOD IsCellCropped(int32_t row, nsITreeColumn *col, bool *_retval) { return _to IsCellCropped(row, col, _retval); } \
  NS_IMETHOD RowCountChanged(int32_t index, int32_t count) { return _to RowCountChanged(index, count); } \
  NS_IMETHOD BeginUpdateBatch(void) { return _to BeginUpdateBatch(); } \
  NS_IMETHOD EndUpdateBatch(void) { return _to EndUpdateBatch(); } \
  NS_IMETHOD ClearStyleAndImageCaches(void) { return _to ClearStyleAndImageCaches(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITREEBOXOBJECT(_to) \
  NS_IMETHOD GetColumns(nsITreeColumns * *aColumns) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumns(aColumns); } \
  NS_IMETHOD GetView(nsITreeView * *aView) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetView(aView); } \
  NS_IMETHOD SetView(nsITreeView *aView) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetView(aView); } \
  NS_IMETHOD GetFocused(bool *aFocused) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocused(aFocused); } \
  NS_IMETHOD SetFocused(bool aFocused) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFocused(aFocused); } \
  NS_IMETHOD GetTreeBody(nsIDOMElement * *aTreeBody) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTreeBody(aTreeBody); } \
  NS_IMETHOD GetRowHeight(int32_t *aRowHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowHeight(aRowHeight); } \
  NS_IMETHOD GetRowWidth(int32_t *aRowWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowWidth(aRowWidth); } \
  NS_IMETHOD GetHorizontalPosition(int32_t *aHorizontalPosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHorizontalPosition(aHorizontalPosition); } \
  NS_IMETHOD GetSelectionRegion(nsIScriptableRegion * *aSelectionRegion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionRegion(aSelectionRegion); } \
  NS_IMETHOD GetFirstVisibleRow(int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFirstVisibleRow(_retval); } \
  NS_IMETHOD GetLastVisibleRow(int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastVisibleRow(_retval); } \
  NS_IMETHOD GetPageLength(int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageLength(_retval); } \
  NS_IMETHOD EnsureRowIsVisible(int32_t index) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnsureRowIsVisible(index); } \
  NS_IMETHOD EnsureCellIsVisible(int32_t row, nsITreeColumn *col) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnsureCellIsVisible(row, col); } \
  NS_IMETHOD ScrollToRow(int32_t index) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollToRow(index); } \
  NS_IMETHOD ScrollByLines(int32_t numLines) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollByLines(numLines); } \
  NS_IMETHOD ScrollByPages(int32_t numPages) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollByPages(numPages); } \
  NS_IMETHOD ScrollToCell(int32_t row, nsITreeColumn *col) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollToCell(row, col); } \
  NS_IMETHOD ScrollToColumn(nsITreeColumn *col) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollToColumn(col); } \
  NS_IMETHOD ScrollToHorizontalPosition(int32_t horizontalPosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollToHorizontalPosition(horizontalPosition); } \
  NS_IMETHOD Invalidate(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Invalidate(); } \
  NS_IMETHOD InvalidateColumn(nsITreeColumn *col) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateColumn(col); } \
  NS_IMETHOD InvalidateRow(int32_t index) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateRow(index); } \
  NS_IMETHOD InvalidateCell(int32_t row, nsITreeColumn *col) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateCell(row, col); } \
  NS_IMETHOD InvalidateRange(int32_t startIndex, int32_t endIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateRange(startIndex, endIndex); } \
  NS_IMETHOD InvalidateColumnRange(int32_t startIndex, int32_t endIndex, nsITreeColumn *col) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateColumnRange(startIndex, endIndex, col); } \
  NS_IMETHOD GetRowAt(int32_t x, int32_t y, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowAt(x, y, _retval); } \
  NS_IMETHOD GetCellAt(int32_t x, int32_t y, int32_t *row, nsITreeColumn * *col, nsACString & childElt) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCellAt(x, y, row, col, childElt); } \
  NS_IMETHOD GetCoordsForCellItem(int32_t row, nsITreeColumn *col, const nsACString & element, int32_t *x, int32_t *y, int32_t *width, int32_t *height) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCoordsForCellItem(row, col, element, x, y, width, height); } \
  NS_IMETHOD IsCellCropped(int32_t row, nsITreeColumn *col, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCellCropped(row, col, _retval); } \
  NS_IMETHOD RowCountChanged(int32_t index, int32_t count) { return !_to ? NS_ERROR_NULL_POINTER : _to->RowCountChanged(index, count); } \
  NS_IMETHOD BeginUpdateBatch(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginUpdateBatch(); } \
  NS_IMETHOD EndUpdateBatch(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndUpdateBatch(); } \
  NS_IMETHOD ClearStyleAndImageCaches(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearStyleAndImageCaches(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTreeBoxObject : public nsITreeBoxObject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITREEBOXOBJECT

  nsTreeBoxObject();

private:
  ~nsTreeBoxObject();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTreeBoxObject, nsITreeBoxObject)

nsTreeBoxObject::nsTreeBoxObject()
{
  /* member initializers and constructor code */
}

nsTreeBoxObject::~nsTreeBoxObject()
{
  /* destructor code */
}

/* readonly attribute nsITreeColumns columns; */
NS_IMETHODIMP nsTreeBoxObject::GetColumns(nsITreeColumns * *aColumns)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsITreeView view; */
NS_IMETHODIMP nsTreeBoxObject::GetView(nsITreeView * *aView)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTreeBoxObject::SetView(nsITreeView *aView)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean focused; */
NS_IMETHODIMP nsTreeBoxObject::GetFocused(bool *aFocused)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTreeBoxObject::SetFocused(bool aFocused)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement treeBody; */
NS_IMETHODIMP nsTreeBoxObject::GetTreeBody(nsIDOMElement * *aTreeBody)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long rowHeight; */
NS_IMETHODIMP nsTreeBoxObject::GetRowHeight(int32_t *aRowHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long rowWidth; */
NS_IMETHODIMP nsTreeBoxObject::GetRowWidth(int32_t *aRowWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long horizontalPosition; */
NS_IMETHODIMP nsTreeBoxObject::GetHorizontalPosition(int32_t *aHorizontalPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIScriptableRegion selectionRegion; */
NS_IMETHODIMP nsTreeBoxObject::GetSelectionRegion(nsIScriptableRegion * *aSelectionRegion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getFirstVisibleRow (); */
NS_IMETHODIMP nsTreeBoxObject::GetFirstVisibleRow(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getLastVisibleRow (); */
NS_IMETHODIMP nsTreeBoxObject::GetLastVisibleRow(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getPageLength (); */
NS_IMETHODIMP nsTreeBoxObject::GetPageLength(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ensureRowIsVisible (in long index); */
NS_IMETHODIMP nsTreeBoxObject::EnsureRowIsVisible(int32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ensureCellIsVisible (in long row, in nsITreeColumn col); */
NS_IMETHODIMP nsTreeBoxObject::EnsureCellIsVisible(int32_t row, nsITreeColumn *col)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollToRow (in long index); */
NS_IMETHODIMP nsTreeBoxObject::ScrollToRow(int32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollByLines (in long numLines); */
NS_IMETHODIMP nsTreeBoxObject::ScrollByLines(int32_t numLines)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollByPages (in long numPages); */
NS_IMETHODIMP nsTreeBoxObject::ScrollByPages(int32_t numPages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollToCell (in long row, in nsITreeColumn col); */
NS_IMETHODIMP nsTreeBoxObject::ScrollToCell(int32_t row, nsITreeColumn *col)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollToColumn (in nsITreeColumn col); */
NS_IMETHODIMP nsTreeBoxObject::ScrollToColumn(nsITreeColumn *col)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollToHorizontalPosition (in long horizontalPosition); */
NS_IMETHODIMP nsTreeBoxObject::ScrollToHorizontalPosition(int32_t horizontalPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidate (); */
NS_IMETHODIMP nsTreeBoxObject::Invalidate()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateColumn (in nsITreeColumn col); */
NS_IMETHODIMP nsTreeBoxObject::InvalidateColumn(nsITreeColumn *col)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateRow (in long index); */
NS_IMETHODIMP nsTreeBoxObject::InvalidateRow(int32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateCell (in long row, in nsITreeColumn col); */
NS_IMETHODIMP nsTreeBoxObject::InvalidateCell(int32_t row, nsITreeColumn *col)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateRange (in long startIndex, in long endIndex); */
NS_IMETHODIMP nsTreeBoxObject::InvalidateRange(int32_t startIndex, int32_t endIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateColumnRange (in long startIndex, in long endIndex, in nsITreeColumn col); */
NS_IMETHODIMP nsTreeBoxObject::InvalidateColumnRange(int32_t startIndex, int32_t endIndex, nsITreeColumn *col)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getRowAt (in long x, in long y); */
NS_IMETHODIMP nsTreeBoxObject::GetRowAt(int32_t x, int32_t y, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCellAt (in long x, in long y, out long row, out nsITreeColumn col, out ACString childElt); */
NS_IMETHODIMP nsTreeBoxObject::GetCellAt(int32_t x, int32_t y, int32_t *row, nsITreeColumn * *col, nsACString & childElt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCoordsForCellItem (in long row, in nsITreeColumn col, in ACString element, out long x, out long y, out long width, out long height); */
NS_IMETHODIMP nsTreeBoxObject::GetCoordsForCellItem(int32_t row, nsITreeColumn *col, const nsACString & element, int32_t *x, int32_t *y, int32_t *width, int32_t *height)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isCellCropped (in long row, in nsITreeColumn col); */
NS_IMETHODIMP nsTreeBoxObject::IsCellCropped(int32_t row, nsITreeColumn *col, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void rowCountChanged (in long index, in long count); */
NS_IMETHODIMP nsTreeBoxObject::RowCountChanged(int32_t index, int32_t count)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginUpdateBatch (); */
NS_IMETHODIMP nsTreeBoxObject::BeginUpdateBatch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endUpdateBatch (); */
NS_IMETHODIMP nsTreeBoxObject::EndUpdateBatch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearStyleAndImageCaches (); */
NS_IMETHODIMP nsTreeBoxObject::ClearStyleAndImageCaches()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITreeBoxObject_h__ */

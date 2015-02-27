/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/layout/xul/tree/nsITreeView.idl
 */

#ifndef __gen_nsITreeView_h__
#define __gen_nsITreeView_h__


#ifndef __gen_nsITreeBoxObject_h__
#include "nsITreeBoxObject.h"
#endif

#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITreeSelection; /* forward declaration */

class nsITreeColumn; /* forward declaration */

class nsIDOMDataTransfer; /* forward declaration */


/* starting interface:    nsITreeView */
#define NS_ITREEVIEW_IID_STR "091116f0-0bdc-4b32-b9c8-c8d5a37cb088"

#define NS_ITREEVIEW_IID \
  {0x091116f0, 0x0bdc, 0x4b32, \
    { 0xb9, 0xc8, 0xc8, 0xd5, 0xa3, 0x7c, 0xb0, 0x88 }}

class NS_NO_VTABLE nsITreeView : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITREEVIEW_IID)

  /* readonly attribute long rowCount; */
  NS_IMETHOD GetRowCount(int32_t *aRowCount) = 0;

  /* attribute nsITreeSelection selection; */
  NS_IMETHOD GetSelection(nsITreeSelection * *aSelection) = 0;
  NS_IMETHOD SetSelection(nsITreeSelection *aSelection) = 0;

  /* AString getRowProperties (in long index); */
  NS_IMETHOD GetRowProperties(int32_t index, nsAString & _retval) = 0;

  /* AString getCellProperties (in long row, in nsITreeColumn col); */
  NS_IMETHOD GetCellProperties(int32_t row, nsITreeColumn *col, nsAString & _retval) = 0;

  /* AString getColumnProperties (in nsITreeColumn col); */
  NS_IMETHOD GetColumnProperties(nsITreeColumn *col, nsAString & _retval) = 0;

  /* boolean isContainer (in long index); */
  NS_IMETHOD IsContainer(int32_t index, bool *_retval) = 0;

  /* boolean isContainerOpen (in long index); */
  NS_IMETHOD IsContainerOpen(int32_t index, bool *_retval) = 0;

  /* boolean isContainerEmpty (in long index); */
  NS_IMETHOD IsContainerEmpty(int32_t index, bool *_retval) = 0;

  /* boolean isSeparator (in long index); */
  NS_IMETHOD IsSeparator(int32_t index, bool *_retval) = 0;

  /* boolean isSorted (); */
  NS_IMETHOD IsSorted(bool *_retval) = 0;

  enum {
    DROP_BEFORE = -1,
    DROP_ON = 0,
    DROP_AFTER = 1
  };

  /* boolean canDrop (in long index, in long orientation, in nsIDOMDataTransfer dataTransfer); */
  NS_IMETHOD CanDrop(int32_t index, int32_t orientation, nsIDOMDataTransfer *dataTransfer, bool *_retval) = 0;

  /* void drop (in long row, in long orientation, in nsIDOMDataTransfer dataTransfer); */
  NS_IMETHOD Drop(int32_t row, int32_t orientation, nsIDOMDataTransfer *dataTransfer) = 0;

  /* long getParentIndex (in long rowIndex); */
  NS_IMETHOD GetParentIndex(int32_t rowIndex, int32_t *_retval) = 0;

  /* boolean hasNextSibling (in long rowIndex, in long afterIndex); */
  NS_IMETHOD HasNextSibling(int32_t rowIndex, int32_t afterIndex, bool *_retval) = 0;

  /* long getLevel (in long index); */
  NS_IMETHOD GetLevel(int32_t index, int32_t *_retval) = 0;

  /* AString getImageSrc (in long row, in nsITreeColumn col); */
  NS_IMETHOD GetImageSrc(int32_t row, nsITreeColumn *col, nsAString & _retval) = 0;

  enum {
    PROGRESS_NORMAL = 1,
    PROGRESS_UNDETERMINED = 2,
    PROGRESS_NONE = 3
  };

  /* long getProgressMode (in long row, in nsITreeColumn col); */
  NS_IMETHOD GetProgressMode(int32_t row, nsITreeColumn *col, int32_t *_retval) = 0;

  /* AString getCellValue (in long row, in nsITreeColumn col); */
  NS_IMETHOD GetCellValue(int32_t row, nsITreeColumn *col, nsAString & _retval) = 0;

  /* AString getCellText (in long row, in nsITreeColumn col); */
  NS_IMETHOD GetCellText(int32_t row, nsITreeColumn *col, nsAString & _retval) = 0;

  /* void setTree (in nsITreeBoxObject tree); */
  NS_IMETHOD SetTree(nsITreeBoxObject *tree) = 0;

  /* void toggleOpenState (in long index); */
  NS_IMETHOD ToggleOpenState(int32_t index) = 0;

  /* void cycleHeader (in nsITreeColumn col); */
  NS_IMETHOD CycleHeader(nsITreeColumn *col) = 0;

  /* void selectionChanged (); */
  NS_IMETHOD SelectionChanged(void) = 0;

  /* void cycleCell (in long row, in nsITreeColumn col); */
  NS_IMETHOD CycleCell(int32_t row, nsITreeColumn *col) = 0;

  /* boolean isEditable (in long row, in nsITreeColumn col); */
  NS_IMETHOD IsEditable(int32_t row, nsITreeColumn *col, bool *_retval) = 0;

  /* boolean isSelectable (in long row, in nsITreeColumn col); */
  NS_IMETHOD IsSelectable(int32_t row, nsITreeColumn *col, bool *_retval) = 0;

  /* void setCellValue (in long row, in nsITreeColumn col, in AString value); */
  NS_IMETHOD SetCellValue(int32_t row, nsITreeColumn *col, const nsAString & value) = 0;

  /* void setCellText (in long row, in nsITreeColumn col, in AString value); */
  NS_IMETHOD SetCellText(int32_t row, nsITreeColumn *col, const nsAString & value) = 0;

  /* void performAction (in wstring action); */
  NS_IMETHOD PerformAction(const PRUnichar * action) = 0;

  /* void performActionOnRow (in wstring action, in long row); */
  NS_IMETHOD PerformActionOnRow(const PRUnichar * action, int32_t row) = 0;

  /* void performActionOnCell (in wstring action, in long row, in nsITreeColumn col); */
  NS_IMETHOD PerformActionOnCell(const PRUnichar * action, int32_t row, nsITreeColumn *col) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITreeView, NS_ITREEVIEW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITREEVIEW \
  NS_IMETHOD GetRowCount(int32_t *aRowCount); \
  NS_IMETHOD GetSelection(nsITreeSelection * *aSelection); \
  NS_IMETHOD SetSelection(nsITreeSelection *aSelection); \
  NS_IMETHOD GetRowProperties(int32_t index, nsAString & _retval); \
  NS_IMETHOD GetCellProperties(int32_t row, nsITreeColumn *col, nsAString & _retval); \
  NS_IMETHOD GetColumnProperties(nsITreeColumn *col, nsAString & _retval); \
  NS_IMETHOD IsContainer(int32_t index, bool *_retval); \
  NS_IMETHOD IsContainerOpen(int32_t index, bool *_retval); \
  NS_IMETHOD IsContainerEmpty(int32_t index, bool *_retval); \
  NS_IMETHOD IsSeparator(int32_t index, bool *_retval); \
  NS_IMETHOD IsSorted(bool *_retval); \
  NS_IMETHOD CanDrop(int32_t index, int32_t orientation, nsIDOMDataTransfer *dataTransfer, bool *_retval); \
  NS_IMETHOD Drop(int32_t row, int32_t orientation, nsIDOMDataTransfer *dataTransfer); \
  NS_IMETHOD GetParentIndex(int32_t rowIndex, int32_t *_retval); \
  NS_IMETHOD HasNextSibling(int32_t rowIndex, int32_t afterIndex, bool *_retval); \
  NS_IMETHOD GetLevel(int32_t index, int32_t *_retval); \
  NS_IMETHOD GetImageSrc(int32_t row, nsITreeColumn *col, nsAString & _retval); \
  NS_IMETHOD GetProgressMode(int32_t row, nsITreeColumn *col, int32_t *_retval); \
  NS_IMETHOD GetCellValue(int32_t row, nsITreeColumn *col, nsAString & _retval); \
  NS_IMETHOD GetCellText(int32_t row, nsITreeColumn *col, nsAString & _retval); \
  NS_IMETHOD SetTree(nsITreeBoxObject *tree); \
  NS_IMETHOD ToggleOpenState(int32_t index); \
  NS_IMETHOD CycleHeader(nsITreeColumn *col); \
  NS_IMETHOD SelectionChanged(void); \
  NS_IMETHOD CycleCell(int32_t row, nsITreeColumn *col); \
  NS_IMETHOD IsEditable(int32_t row, nsITreeColumn *col, bool *_retval); \
  NS_IMETHOD IsSelectable(int32_t row, nsITreeColumn *col, bool *_retval); \
  NS_IMETHOD SetCellValue(int32_t row, nsITreeColumn *col, const nsAString & value); \
  NS_IMETHOD SetCellText(int32_t row, nsITreeColumn *col, const nsAString & value); \
  NS_IMETHOD PerformAction(const PRUnichar * action); \
  NS_IMETHOD PerformActionOnRow(const PRUnichar * action, int32_t row); \
  NS_IMETHOD PerformActionOnCell(const PRUnichar * action, int32_t row, nsITreeColumn *col); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITREEVIEW(_to) \
  NS_IMETHOD GetRowCount(int32_t *aRowCount) { return _to GetRowCount(aRowCount); } \
  NS_IMETHOD GetSelection(nsITreeSelection * *aSelection) { return _to GetSelection(aSelection); } \
  NS_IMETHOD SetSelection(nsITreeSelection *aSelection) { return _to SetSelection(aSelection); } \
  NS_IMETHOD GetRowProperties(int32_t index, nsAString & _retval) { return _to GetRowProperties(index, _retval); } \
  NS_IMETHOD GetCellProperties(int32_t row, nsITreeColumn *col, nsAString & _retval) { return _to GetCellProperties(row, col, _retval); } \
  NS_IMETHOD GetColumnProperties(nsITreeColumn *col, nsAString & _retval) { return _to GetColumnProperties(col, _retval); } \
  NS_IMETHOD IsContainer(int32_t index, bool *_retval) { return _to IsContainer(index, _retval); } \
  NS_IMETHOD IsContainerOpen(int32_t index, bool *_retval) { return _to IsContainerOpen(index, _retval); } \
  NS_IMETHOD IsContainerEmpty(int32_t index, bool *_retval) { return _to IsContainerEmpty(index, _retval); } \
  NS_IMETHOD IsSeparator(int32_t index, bool *_retval) { return _to IsSeparator(index, _retval); } \
  NS_IMETHOD IsSorted(bool *_retval) { return _to IsSorted(_retval); } \
  NS_IMETHOD CanDrop(int32_t index, int32_t orientation, nsIDOMDataTransfer *dataTransfer, bool *_retval) { return _to CanDrop(index, orientation, dataTransfer, _retval); } \
  NS_IMETHOD Drop(int32_t row, int32_t orientation, nsIDOMDataTransfer *dataTransfer) { return _to Drop(row, orientation, dataTransfer); } \
  NS_IMETHOD GetParentIndex(int32_t rowIndex, int32_t *_retval) { return _to GetParentIndex(rowIndex, _retval); } \
  NS_IMETHOD HasNextSibling(int32_t rowIndex, int32_t afterIndex, bool *_retval) { return _to HasNextSibling(rowIndex, afterIndex, _retval); } \
  NS_IMETHOD GetLevel(int32_t index, int32_t *_retval) { return _to GetLevel(index, _retval); } \
  NS_IMETHOD GetImageSrc(int32_t row, nsITreeColumn *col, nsAString & _retval) { return _to GetImageSrc(row, col, _retval); } \
  NS_IMETHOD GetProgressMode(int32_t row, nsITreeColumn *col, int32_t *_retval) { return _to GetProgressMode(row, col, _retval); } \
  NS_IMETHOD GetCellValue(int32_t row, nsITreeColumn *col, nsAString & _retval) { return _to GetCellValue(row, col, _retval); } \
  NS_IMETHOD GetCellText(int32_t row, nsITreeColumn *col, nsAString & _retval) { return _to GetCellText(row, col, _retval); } \
  NS_IMETHOD SetTree(nsITreeBoxObject *tree) { return _to SetTree(tree); } \
  NS_IMETHOD ToggleOpenState(int32_t index) { return _to ToggleOpenState(index); } \
  NS_IMETHOD CycleHeader(nsITreeColumn *col) { return _to CycleHeader(col); } \
  NS_IMETHOD SelectionChanged(void) { return _to SelectionChanged(); } \
  NS_IMETHOD CycleCell(int32_t row, nsITreeColumn *col) { return _to CycleCell(row, col); } \
  NS_IMETHOD IsEditable(int32_t row, nsITreeColumn *col, bool *_retval) { return _to IsEditable(row, col, _retval); } \
  NS_IMETHOD IsSelectable(int32_t row, nsITreeColumn *col, bool *_retval) { return _to IsSelectable(row, col, _retval); } \
  NS_IMETHOD SetCellValue(int32_t row, nsITreeColumn *col, const nsAString & value) { return _to SetCellValue(row, col, value); } \
  NS_IMETHOD SetCellText(int32_t row, nsITreeColumn *col, const nsAString & value) { return _to SetCellText(row, col, value); } \
  NS_IMETHOD PerformAction(const PRUnichar * action) { return _to PerformAction(action); } \
  NS_IMETHOD PerformActionOnRow(const PRUnichar * action, int32_t row) { return _to PerformActionOnRow(action, row); } \
  NS_IMETHOD PerformActionOnCell(const PRUnichar * action, int32_t row, nsITreeColumn *col) { return _to PerformActionOnCell(action, row, col); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITREEVIEW(_to) \
  NS_IMETHOD GetRowCount(int32_t *aRowCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowCount(aRowCount); } \
  NS_IMETHOD GetSelection(nsITreeSelection * *aSelection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelection(aSelection); } \
  NS_IMETHOD SetSelection(nsITreeSelection *aSelection) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelection(aSelection); } \
  NS_IMETHOD GetRowProperties(int32_t index, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowProperties(index, _retval); } \
  NS_IMETHOD GetCellProperties(int32_t row, nsITreeColumn *col, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCellProperties(row, col, _retval); } \
  NS_IMETHOD GetColumnProperties(nsITreeColumn *col, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnProperties(col, _retval); } \
  NS_IMETHOD IsContainer(int32_t index, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsContainer(index, _retval); } \
  NS_IMETHOD IsContainerOpen(int32_t index, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsContainerOpen(index, _retval); } \
  NS_IMETHOD IsContainerEmpty(int32_t index, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsContainerEmpty(index, _retval); } \
  NS_IMETHOD IsSeparator(int32_t index, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsSeparator(index, _retval); } \
  NS_IMETHOD IsSorted(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsSorted(_retval); } \
  NS_IMETHOD CanDrop(int32_t index, int32_t orientation, nsIDOMDataTransfer *dataTransfer, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanDrop(index, orientation, dataTransfer, _retval); } \
  NS_IMETHOD Drop(int32_t row, int32_t orientation, nsIDOMDataTransfer *dataTransfer) { return !_to ? NS_ERROR_NULL_POINTER : _to->Drop(row, orientation, dataTransfer); } \
  NS_IMETHOD GetParentIndex(int32_t rowIndex, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentIndex(rowIndex, _retval); } \
  NS_IMETHOD HasNextSibling(int32_t rowIndex, int32_t afterIndex, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasNextSibling(rowIndex, afterIndex, _retval); } \
  NS_IMETHOD GetLevel(int32_t index, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLevel(index, _retval); } \
  NS_IMETHOD GetImageSrc(int32_t row, nsITreeColumn *col, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageSrc(row, col, _retval); } \
  NS_IMETHOD GetProgressMode(int32_t row, nsITreeColumn *col, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProgressMode(row, col, _retval); } \
  NS_IMETHOD GetCellValue(int32_t row, nsITreeColumn *col, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCellValue(row, col, _retval); } \
  NS_IMETHOD GetCellText(int32_t row, nsITreeColumn *col, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCellText(row, col, _retval); } \
  NS_IMETHOD SetTree(nsITreeBoxObject *tree) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTree(tree); } \
  NS_IMETHOD ToggleOpenState(int32_t index) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToggleOpenState(index); } \
  NS_IMETHOD CycleHeader(nsITreeColumn *col) { return !_to ? NS_ERROR_NULL_POINTER : _to->CycleHeader(col); } \
  NS_IMETHOD SelectionChanged(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectionChanged(); } \
  NS_IMETHOD CycleCell(int32_t row, nsITreeColumn *col) { return !_to ? NS_ERROR_NULL_POINTER : _to->CycleCell(row, col); } \
  NS_IMETHOD IsEditable(int32_t row, nsITreeColumn *col, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsEditable(row, col, _retval); } \
  NS_IMETHOD IsSelectable(int32_t row, nsITreeColumn *col, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsSelectable(row, col, _retval); } \
  NS_IMETHOD SetCellValue(int32_t row, nsITreeColumn *col, const nsAString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCellValue(row, col, value); } \
  NS_IMETHOD SetCellText(int32_t row, nsITreeColumn *col, const nsAString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCellText(row, col, value); } \
  NS_IMETHOD PerformAction(const PRUnichar * action) { return !_to ? NS_ERROR_NULL_POINTER : _to->PerformAction(action); } \
  NS_IMETHOD PerformActionOnRow(const PRUnichar * action, int32_t row) { return !_to ? NS_ERROR_NULL_POINTER : _to->PerformActionOnRow(action, row); } \
  NS_IMETHOD PerformActionOnCell(const PRUnichar * action, int32_t row, nsITreeColumn *col) { return !_to ? NS_ERROR_NULL_POINTER : _to->PerformActionOnCell(action, row, col); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTreeView : public nsITreeView
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITREEVIEW

  nsTreeView();

private:
  ~nsTreeView();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTreeView, nsITreeView)

nsTreeView::nsTreeView()
{
  /* member initializers and constructor code */
}

nsTreeView::~nsTreeView()
{
  /* destructor code */
}

/* readonly attribute long rowCount; */
NS_IMETHODIMP nsTreeView::GetRowCount(int32_t *aRowCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsITreeSelection selection; */
NS_IMETHODIMP nsTreeView::GetSelection(nsITreeSelection * *aSelection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTreeView::SetSelection(nsITreeSelection *aSelection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getRowProperties (in long index); */
NS_IMETHODIMP nsTreeView::GetRowProperties(int32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getCellProperties (in long row, in nsITreeColumn col); */
NS_IMETHODIMP nsTreeView::GetCellProperties(int32_t row, nsITreeColumn *col, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getColumnProperties (in nsITreeColumn col); */
NS_IMETHODIMP nsTreeView::GetColumnProperties(nsITreeColumn *col, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isContainer (in long index); */
NS_IMETHODIMP nsTreeView::IsContainer(int32_t index, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isContainerOpen (in long index); */
NS_IMETHODIMP nsTreeView::IsContainerOpen(int32_t index, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isContainerEmpty (in long index); */
NS_IMETHODIMP nsTreeView::IsContainerEmpty(int32_t index, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isSeparator (in long index); */
NS_IMETHODIMP nsTreeView::IsSeparator(int32_t index, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isSorted (); */
NS_IMETHODIMP nsTreeView::IsSorted(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canDrop (in long index, in long orientation, in nsIDOMDataTransfer dataTransfer); */
NS_IMETHODIMP nsTreeView::CanDrop(int32_t index, int32_t orientation, nsIDOMDataTransfer *dataTransfer, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void drop (in long row, in long orientation, in nsIDOMDataTransfer dataTransfer); */
NS_IMETHODIMP nsTreeView::Drop(int32_t row, int32_t orientation, nsIDOMDataTransfer *dataTransfer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getParentIndex (in long rowIndex); */
NS_IMETHODIMP nsTreeView::GetParentIndex(int32_t rowIndex, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasNextSibling (in long rowIndex, in long afterIndex); */
NS_IMETHODIMP nsTreeView::HasNextSibling(int32_t rowIndex, int32_t afterIndex, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getLevel (in long index); */
NS_IMETHODIMP nsTreeView::GetLevel(int32_t index, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getImageSrc (in long row, in nsITreeColumn col); */
NS_IMETHODIMP nsTreeView::GetImageSrc(int32_t row, nsITreeColumn *col, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getProgressMode (in long row, in nsITreeColumn col); */
NS_IMETHODIMP nsTreeView::GetProgressMode(int32_t row, nsITreeColumn *col, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getCellValue (in long row, in nsITreeColumn col); */
NS_IMETHODIMP nsTreeView::GetCellValue(int32_t row, nsITreeColumn *col, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getCellText (in long row, in nsITreeColumn col); */
NS_IMETHODIMP nsTreeView::GetCellText(int32_t row, nsITreeColumn *col, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setTree (in nsITreeBoxObject tree); */
NS_IMETHODIMP nsTreeView::SetTree(nsITreeBoxObject *tree)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void toggleOpenState (in long index); */
NS_IMETHODIMP nsTreeView::ToggleOpenState(int32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cycleHeader (in nsITreeColumn col); */
NS_IMETHODIMP nsTreeView::CycleHeader(nsITreeColumn *col)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectionChanged (); */
NS_IMETHODIMP nsTreeView::SelectionChanged()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cycleCell (in long row, in nsITreeColumn col); */
NS_IMETHODIMP nsTreeView::CycleCell(int32_t row, nsITreeColumn *col)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isEditable (in long row, in nsITreeColumn col); */
NS_IMETHODIMP nsTreeView::IsEditable(int32_t row, nsITreeColumn *col, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isSelectable (in long row, in nsITreeColumn col); */
NS_IMETHODIMP nsTreeView::IsSelectable(int32_t row, nsITreeColumn *col, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCellValue (in long row, in nsITreeColumn col, in AString value); */
NS_IMETHODIMP nsTreeView::SetCellValue(int32_t row, nsITreeColumn *col, const nsAString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCellText (in long row, in nsITreeColumn col, in AString value); */
NS_IMETHODIMP nsTreeView::SetCellText(int32_t row, nsITreeColumn *col, const nsAString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void performAction (in wstring action); */
NS_IMETHODIMP nsTreeView::PerformAction(const PRUnichar * action)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void performActionOnRow (in wstring action, in long row); */
NS_IMETHODIMP nsTreeView::PerformActionOnRow(const PRUnichar * action, int32_t row)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void performActionOnCell (in wstring action, in long row, in nsITreeColumn col); */
NS_IMETHODIMP nsTreeView::PerformActionOnCell(const PRUnichar * action, int32_t row, nsITreeColumn *col)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINativeTreeView */
#define NS_INATIVETREEVIEW_IID_STR "46c90265-6553-41ae-8d39-7022e7d09145"

#define NS_INATIVETREEVIEW_IID \
  {0x46c90265, 0x6553, 0x41ae, \
    { 0x8d, 0x39, 0x70, 0x22, 0xe7, 0xd0, 0x91, 0x45 }}

class NS_NO_VTABLE nsINativeTreeView : public nsITreeView {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INATIVETREEVIEW_IID)

  /* [noscript] void ensureNative (); */
  NS_IMETHOD EnsureNative(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINativeTreeView, NS_INATIVETREEVIEW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINATIVETREEVIEW \
  NS_IMETHOD EnsureNative(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINATIVETREEVIEW(_to) \
  NS_IMETHOD EnsureNative(void) { return _to EnsureNative(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINATIVETREEVIEW(_to) \
  NS_IMETHOD EnsureNative(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnsureNative(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNativeTreeView : public nsINativeTreeView
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINATIVETREEVIEW

  nsNativeTreeView();

private:
  ~nsNativeTreeView();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNativeTreeView, nsINativeTreeView)

nsNativeTreeView::nsNativeTreeView()
{
  /* member initializers and constructor code */
}

nsNativeTreeView::~nsNativeTreeView()
{
  /* destructor code */
}

/* [noscript] void ensureNative (); */
NS_IMETHODIMP nsNativeTreeView::EnsureNative()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITreeView_h__ */

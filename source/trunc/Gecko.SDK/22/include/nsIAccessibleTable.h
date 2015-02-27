/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/accessible/public/nsIAccessibleTable.idl
 */

#ifndef __gen_nsIAccessibleTable_h__
#define __gen_nsIAccessibleTable_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAccessible; /* forward declaration */

class nsIArray; /* forward declaration */


/* starting interface:    nsIAccessibleTable */
#define NS_IACCESSIBLETABLE_IID_STR "cb0bf7b9-117e-40e2-9e46-189c3d43ce4a"

#define NS_IACCESSIBLETABLE_IID \
  {0xcb0bf7b9, 0x117e, 0x40e2, \
    { 0x9e, 0x46, 0x18, 0x9c, 0x3d, 0x43, 0xce, 0x4a }}

class NS_NO_VTABLE nsIAccessibleTable : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLETABLE_IID)

  /* readonly attribute nsIAccessible caption; */
  NS_IMETHOD GetCaption(nsIAccessible * *aCaption) = 0;

  /* readonly attribute AString summary; */
  NS_IMETHOD GetSummary(nsAString & aSummary) = 0;

  /* readonly attribute long columnCount; */
  NS_IMETHOD GetColumnCount(int32_t *aColumnCount) = 0;

  /* readonly attribute long rowCount; */
  NS_IMETHOD GetRowCount(int32_t *aRowCount) = 0;

  /* nsIAccessible getCellAt (in long rowIndex, in long columnIndex); */
  NS_IMETHOD GetCellAt(int32_t rowIndex, int32_t columnIndex, nsIAccessible * *_retval) = 0;

  /* long getCellIndexAt (in long rowIndex, in long columnIndex); */
  NS_IMETHOD GetCellIndexAt(int32_t rowIndex, int32_t columnIndex, int32_t *_retval) = 0;

  /* long getColumnIndexAt (in long cellIndex); */
  NS_IMETHOD GetColumnIndexAt(int32_t cellIndex, int32_t *_retval) = 0;

  /* long getRowIndexAt (in long cellIndex); */
  NS_IMETHOD GetRowIndexAt(int32_t cellIndex, int32_t *_retval) = 0;

  /* void getRowAndColumnIndicesAt (in long cellIndex, out long rowIndex, out long columnIndex); */
  NS_IMETHOD GetRowAndColumnIndicesAt(int32_t cellIndex, int32_t *rowIndex, int32_t *columnIndex) = 0;

  /* long getColumnExtentAt (in long row, in long column); */
  NS_IMETHOD GetColumnExtentAt(int32_t row, int32_t column, int32_t *_retval) = 0;

  /* long getRowExtentAt (in long row, in long column); */
  NS_IMETHOD GetRowExtentAt(int32_t row, int32_t column, int32_t *_retval) = 0;

  /* AString getColumnDescription (in long columnIndex); */
  NS_IMETHOD GetColumnDescription(int32_t columnIndex, nsAString & _retval) = 0;

  /* AString getRowDescription (in long rowIndex); */
  NS_IMETHOD GetRowDescription(int32_t rowIndex, nsAString & _retval) = 0;

  /* boolean isColumnSelected (in long columnIndex); */
  NS_IMETHOD IsColumnSelected(int32_t columnIndex, bool *_retval) = 0;

  /* boolean isRowSelected (in long rowIndex); */
  NS_IMETHOD IsRowSelected(int32_t rowIndex, bool *_retval) = 0;

  /* boolean isCellSelected (in long rowIndex, in long columnIndex); */
  NS_IMETHOD IsCellSelected(int32_t rowIndex, int32_t columnIndex, bool *_retval) = 0;

  /* readonly attribute unsigned long selectedCellCount; */
  NS_IMETHOD GetSelectedCellCount(uint32_t *aSelectedCellCount) = 0;

  /* readonly attribute unsigned long selectedColumnCount; */
  NS_IMETHOD GetSelectedColumnCount(uint32_t *aSelectedColumnCount) = 0;

  /* readonly attribute unsigned long selectedRowCount; */
  NS_IMETHOD GetSelectedRowCount(uint32_t *aSelectedRowCount) = 0;

  /* readonly attribute nsIArray selectedCells; */
  NS_IMETHOD GetSelectedCells(nsIArray * *aSelectedCells) = 0;

  /* void getSelectedCellIndices (out unsigned long cellsArraySize, [array, size_is (cellsArraySize), retval] out long cellsArray); */
  NS_IMETHOD GetSelectedCellIndices(uint32_t *cellsArraySize, int32_t **cellsArray) = 0;

  /* void getSelectedColumnIndices (out unsigned long columnsArraySize, [array, size_is (columnsArraySize), retval] out long columnsArray); */
  NS_IMETHOD GetSelectedColumnIndices(uint32_t *columnsArraySize, int32_t **columnsArray) = 0;

  /* void getSelectedRowIndices (out unsigned long rowsArraySize, [array, size_is (rowsArraySize), retval] out long rowsArray); */
  NS_IMETHOD GetSelectedRowIndices(uint32_t *rowsArraySize, int32_t **rowsArray) = 0;

  /* void selectRow (in long rowIndex); */
  NS_IMETHOD SelectRow(int32_t rowIndex) = 0;

  /* void selectColumn (in long columnIndex); */
  NS_IMETHOD SelectColumn(int32_t columnIndex) = 0;

  /* void unselectRow (in long rowIndex); */
  NS_IMETHOD UnselectRow(int32_t rowIndex) = 0;

  /* void unselectColumn (in long columnIndex); */
  NS_IMETHOD UnselectColumn(int32_t columnIndex) = 0;

  /* boolean isProbablyForLayout (); */
  NS_IMETHOD IsProbablyForLayout(bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleTable, NS_IACCESSIBLETABLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLETABLE \
  NS_IMETHOD GetCaption(nsIAccessible * *aCaption); \
  NS_IMETHOD GetSummary(nsAString & aSummary); \
  NS_IMETHOD GetColumnCount(int32_t *aColumnCount); \
  NS_IMETHOD GetRowCount(int32_t *aRowCount); \
  NS_IMETHOD GetCellAt(int32_t rowIndex, int32_t columnIndex, nsIAccessible * *_retval); \
  NS_IMETHOD GetCellIndexAt(int32_t rowIndex, int32_t columnIndex, int32_t *_retval); \
  NS_IMETHOD GetColumnIndexAt(int32_t cellIndex, int32_t *_retval); \
  NS_IMETHOD GetRowIndexAt(int32_t cellIndex, int32_t *_retval); \
  NS_IMETHOD GetRowAndColumnIndicesAt(int32_t cellIndex, int32_t *rowIndex, int32_t *columnIndex); \
  NS_IMETHOD GetColumnExtentAt(int32_t row, int32_t column, int32_t *_retval); \
  NS_IMETHOD GetRowExtentAt(int32_t row, int32_t column, int32_t *_retval); \
  NS_IMETHOD GetColumnDescription(int32_t columnIndex, nsAString & _retval); \
  NS_IMETHOD GetRowDescription(int32_t rowIndex, nsAString & _retval); \
  NS_IMETHOD IsColumnSelected(int32_t columnIndex, bool *_retval); \
  NS_IMETHOD IsRowSelected(int32_t rowIndex, bool *_retval); \
  NS_IMETHOD IsCellSelected(int32_t rowIndex, int32_t columnIndex, bool *_retval); \
  NS_IMETHOD GetSelectedCellCount(uint32_t *aSelectedCellCount); \
  NS_IMETHOD GetSelectedColumnCount(uint32_t *aSelectedColumnCount); \
  NS_IMETHOD GetSelectedRowCount(uint32_t *aSelectedRowCount); \
  NS_IMETHOD GetSelectedCells(nsIArray * *aSelectedCells); \
  NS_IMETHOD GetSelectedCellIndices(uint32_t *cellsArraySize, int32_t **cellsArray); \
  NS_IMETHOD GetSelectedColumnIndices(uint32_t *columnsArraySize, int32_t **columnsArray); \
  NS_IMETHOD GetSelectedRowIndices(uint32_t *rowsArraySize, int32_t **rowsArray); \
  NS_IMETHOD SelectRow(int32_t rowIndex); \
  NS_IMETHOD SelectColumn(int32_t columnIndex); \
  NS_IMETHOD UnselectRow(int32_t rowIndex); \
  NS_IMETHOD UnselectColumn(int32_t columnIndex); \
  NS_IMETHOD IsProbablyForLayout(bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLETABLE(_to) \
  NS_IMETHOD GetCaption(nsIAccessible * *aCaption) { return _to GetCaption(aCaption); } \
  NS_IMETHOD GetSummary(nsAString & aSummary) { return _to GetSummary(aSummary); } \
  NS_IMETHOD GetColumnCount(int32_t *aColumnCount) { return _to GetColumnCount(aColumnCount); } \
  NS_IMETHOD GetRowCount(int32_t *aRowCount) { return _to GetRowCount(aRowCount); } \
  NS_IMETHOD GetCellAt(int32_t rowIndex, int32_t columnIndex, nsIAccessible * *_retval) { return _to GetCellAt(rowIndex, columnIndex, _retval); } \
  NS_IMETHOD GetCellIndexAt(int32_t rowIndex, int32_t columnIndex, int32_t *_retval) { return _to GetCellIndexAt(rowIndex, columnIndex, _retval); } \
  NS_IMETHOD GetColumnIndexAt(int32_t cellIndex, int32_t *_retval) { return _to GetColumnIndexAt(cellIndex, _retval); } \
  NS_IMETHOD GetRowIndexAt(int32_t cellIndex, int32_t *_retval) { return _to GetRowIndexAt(cellIndex, _retval); } \
  NS_IMETHOD GetRowAndColumnIndicesAt(int32_t cellIndex, int32_t *rowIndex, int32_t *columnIndex) { return _to GetRowAndColumnIndicesAt(cellIndex, rowIndex, columnIndex); } \
  NS_IMETHOD GetColumnExtentAt(int32_t row, int32_t column, int32_t *_retval) { return _to GetColumnExtentAt(row, column, _retval); } \
  NS_IMETHOD GetRowExtentAt(int32_t row, int32_t column, int32_t *_retval) { return _to GetRowExtentAt(row, column, _retval); } \
  NS_IMETHOD GetColumnDescription(int32_t columnIndex, nsAString & _retval) { return _to GetColumnDescription(columnIndex, _retval); } \
  NS_IMETHOD GetRowDescription(int32_t rowIndex, nsAString & _retval) { return _to GetRowDescription(rowIndex, _retval); } \
  NS_IMETHOD IsColumnSelected(int32_t columnIndex, bool *_retval) { return _to IsColumnSelected(columnIndex, _retval); } \
  NS_IMETHOD IsRowSelected(int32_t rowIndex, bool *_retval) { return _to IsRowSelected(rowIndex, _retval); } \
  NS_IMETHOD IsCellSelected(int32_t rowIndex, int32_t columnIndex, bool *_retval) { return _to IsCellSelected(rowIndex, columnIndex, _retval); } \
  NS_IMETHOD GetSelectedCellCount(uint32_t *aSelectedCellCount) { return _to GetSelectedCellCount(aSelectedCellCount); } \
  NS_IMETHOD GetSelectedColumnCount(uint32_t *aSelectedColumnCount) { return _to GetSelectedColumnCount(aSelectedColumnCount); } \
  NS_IMETHOD GetSelectedRowCount(uint32_t *aSelectedRowCount) { return _to GetSelectedRowCount(aSelectedRowCount); } \
  NS_IMETHOD GetSelectedCells(nsIArray * *aSelectedCells) { return _to GetSelectedCells(aSelectedCells); } \
  NS_IMETHOD GetSelectedCellIndices(uint32_t *cellsArraySize, int32_t **cellsArray) { return _to GetSelectedCellIndices(cellsArraySize, cellsArray); } \
  NS_IMETHOD GetSelectedColumnIndices(uint32_t *columnsArraySize, int32_t **columnsArray) { return _to GetSelectedColumnIndices(columnsArraySize, columnsArray); } \
  NS_IMETHOD GetSelectedRowIndices(uint32_t *rowsArraySize, int32_t **rowsArray) { return _to GetSelectedRowIndices(rowsArraySize, rowsArray); } \
  NS_IMETHOD SelectRow(int32_t rowIndex) { return _to SelectRow(rowIndex); } \
  NS_IMETHOD SelectColumn(int32_t columnIndex) { return _to SelectColumn(columnIndex); } \
  NS_IMETHOD UnselectRow(int32_t rowIndex) { return _to UnselectRow(rowIndex); } \
  NS_IMETHOD UnselectColumn(int32_t columnIndex) { return _to UnselectColumn(columnIndex); } \
  NS_IMETHOD IsProbablyForLayout(bool *_retval) { return _to IsProbablyForLayout(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLETABLE(_to) \
  NS_IMETHOD GetCaption(nsIAccessible * *aCaption) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCaption(aCaption); } \
  NS_IMETHOD GetSummary(nsAString & aSummary) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSummary(aSummary); } \
  NS_IMETHOD GetColumnCount(int32_t *aColumnCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnCount(aColumnCount); } \
  NS_IMETHOD GetRowCount(int32_t *aRowCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowCount(aRowCount); } \
  NS_IMETHOD GetCellAt(int32_t rowIndex, int32_t columnIndex, nsIAccessible * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCellAt(rowIndex, columnIndex, _retval); } \
  NS_IMETHOD GetCellIndexAt(int32_t rowIndex, int32_t columnIndex, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCellIndexAt(rowIndex, columnIndex, _retval); } \
  NS_IMETHOD GetColumnIndexAt(int32_t cellIndex, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnIndexAt(cellIndex, _retval); } \
  NS_IMETHOD GetRowIndexAt(int32_t cellIndex, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowIndexAt(cellIndex, _retval); } \
  NS_IMETHOD GetRowAndColumnIndicesAt(int32_t cellIndex, int32_t *rowIndex, int32_t *columnIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowAndColumnIndicesAt(cellIndex, rowIndex, columnIndex); } \
  NS_IMETHOD GetColumnExtentAt(int32_t row, int32_t column, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnExtentAt(row, column, _retval); } \
  NS_IMETHOD GetRowExtentAt(int32_t row, int32_t column, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowExtentAt(row, column, _retval); } \
  NS_IMETHOD GetColumnDescription(int32_t columnIndex, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnDescription(columnIndex, _retval); } \
  NS_IMETHOD GetRowDescription(int32_t rowIndex, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowDescription(rowIndex, _retval); } \
  NS_IMETHOD IsColumnSelected(int32_t columnIndex, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsColumnSelected(columnIndex, _retval); } \
  NS_IMETHOD IsRowSelected(int32_t rowIndex, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsRowSelected(rowIndex, _retval); } \
  NS_IMETHOD IsCellSelected(int32_t rowIndex, int32_t columnIndex, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCellSelected(rowIndex, columnIndex, _retval); } \
  NS_IMETHOD GetSelectedCellCount(uint32_t *aSelectedCellCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedCellCount(aSelectedCellCount); } \
  NS_IMETHOD GetSelectedColumnCount(uint32_t *aSelectedColumnCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedColumnCount(aSelectedColumnCount); } \
  NS_IMETHOD GetSelectedRowCount(uint32_t *aSelectedRowCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedRowCount(aSelectedRowCount); } \
  NS_IMETHOD GetSelectedCells(nsIArray * *aSelectedCells) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedCells(aSelectedCells); } \
  NS_IMETHOD GetSelectedCellIndices(uint32_t *cellsArraySize, int32_t **cellsArray) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedCellIndices(cellsArraySize, cellsArray); } \
  NS_IMETHOD GetSelectedColumnIndices(uint32_t *columnsArraySize, int32_t **columnsArray) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedColumnIndices(columnsArraySize, columnsArray); } \
  NS_IMETHOD GetSelectedRowIndices(uint32_t *rowsArraySize, int32_t **rowsArray) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedRowIndices(rowsArraySize, rowsArray); } \
  NS_IMETHOD SelectRow(int32_t rowIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectRow(rowIndex); } \
  NS_IMETHOD SelectColumn(int32_t columnIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectColumn(columnIndex); } \
  NS_IMETHOD UnselectRow(int32_t rowIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnselectRow(rowIndex); } \
  NS_IMETHOD UnselectColumn(int32_t columnIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnselectColumn(columnIndex); } \
  NS_IMETHOD IsProbablyForLayout(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsProbablyForLayout(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleTable : public nsIAccessibleTable
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLETABLE

  nsAccessibleTable();

private:
  ~nsAccessibleTable();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleTable, nsIAccessibleTable)

nsAccessibleTable::nsAccessibleTable()
{
  /* member initializers and constructor code */
}

nsAccessibleTable::~nsAccessibleTable()
{
  /* destructor code */
}

/* readonly attribute nsIAccessible caption; */
NS_IMETHODIMP nsAccessibleTable::GetCaption(nsIAccessible * *aCaption)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString summary; */
NS_IMETHODIMP nsAccessibleTable::GetSummary(nsAString & aSummary)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long columnCount; */
NS_IMETHODIMP nsAccessibleTable::GetColumnCount(int32_t *aColumnCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long rowCount; */
NS_IMETHODIMP nsAccessibleTable::GetRowCount(int32_t *aRowCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getCellAt (in long rowIndex, in long columnIndex); */
NS_IMETHODIMP nsAccessibleTable::GetCellAt(int32_t rowIndex, int32_t columnIndex, nsIAccessible * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getCellIndexAt (in long rowIndex, in long columnIndex); */
NS_IMETHODIMP nsAccessibleTable::GetCellIndexAt(int32_t rowIndex, int32_t columnIndex, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getColumnIndexAt (in long cellIndex); */
NS_IMETHODIMP nsAccessibleTable::GetColumnIndexAt(int32_t cellIndex, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getRowIndexAt (in long cellIndex); */
NS_IMETHODIMP nsAccessibleTable::GetRowIndexAt(int32_t cellIndex, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getRowAndColumnIndicesAt (in long cellIndex, out long rowIndex, out long columnIndex); */
NS_IMETHODIMP nsAccessibleTable::GetRowAndColumnIndicesAt(int32_t cellIndex, int32_t *rowIndex, int32_t *columnIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getColumnExtentAt (in long row, in long column); */
NS_IMETHODIMP nsAccessibleTable::GetColumnExtentAt(int32_t row, int32_t column, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getRowExtentAt (in long row, in long column); */
NS_IMETHODIMP nsAccessibleTable::GetRowExtentAt(int32_t row, int32_t column, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getColumnDescription (in long columnIndex); */
NS_IMETHODIMP nsAccessibleTable::GetColumnDescription(int32_t columnIndex, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getRowDescription (in long rowIndex); */
NS_IMETHODIMP nsAccessibleTable::GetRowDescription(int32_t rowIndex, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isColumnSelected (in long columnIndex); */
NS_IMETHODIMP nsAccessibleTable::IsColumnSelected(int32_t columnIndex, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isRowSelected (in long rowIndex); */
NS_IMETHODIMP nsAccessibleTable::IsRowSelected(int32_t rowIndex, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isCellSelected (in long rowIndex, in long columnIndex); */
NS_IMETHODIMP nsAccessibleTable::IsCellSelected(int32_t rowIndex, int32_t columnIndex, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long selectedCellCount; */
NS_IMETHODIMP nsAccessibleTable::GetSelectedCellCount(uint32_t *aSelectedCellCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long selectedColumnCount; */
NS_IMETHODIMP nsAccessibleTable::GetSelectedColumnCount(uint32_t *aSelectedColumnCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long selectedRowCount; */
NS_IMETHODIMP nsAccessibleTable::GetSelectedRowCount(uint32_t *aSelectedRowCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIArray selectedCells; */
NS_IMETHODIMP nsAccessibleTable::GetSelectedCells(nsIArray * *aSelectedCells)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSelectedCellIndices (out unsigned long cellsArraySize, [array, size_is (cellsArraySize), retval] out long cellsArray); */
NS_IMETHODIMP nsAccessibleTable::GetSelectedCellIndices(uint32_t *cellsArraySize, int32_t **cellsArray)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSelectedColumnIndices (out unsigned long columnsArraySize, [array, size_is (columnsArraySize), retval] out long columnsArray); */
NS_IMETHODIMP nsAccessibleTable::GetSelectedColumnIndices(uint32_t *columnsArraySize, int32_t **columnsArray)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSelectedRowIndices (out unsigned long rowsArraySize, [array, size_is (rowsArraySize), retval] out long rowsArray); */
NS_IMETHODIMP nsAccessibleTable::GetSelectedRowIndices(uint32_t *rowsArraySize, int32_t **rowsArray)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectRow (in long rowIndex); */
NS_IMETHODIMP nsAccessibleTable::SelectRow(int32_t rowIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectColumn (in long columnIndex); */
NS_IMETHODIMP nsAccessibleTable::SelectColumn(int32_t columnIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unselectRow (in long rowIndex); */
NS_IMETHODIMP nsAccessibleTable::UnselectRow(int32_t rowIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unselectColumn (in long columnIndex); */
NS_IMETHODIMP nsAccessibleTable::UnselectColumn(int32_t columnIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isProbablyForLayout (); */
NS_IMETHODIMP nsAccessibleTable::IsProbablyForLayout(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAccessibleTableCell */
#define NS_IACCESSIBLETABLECELL_IID_STR "654e296d-fae6-452b-987d-746b20b9514b"

#define NS_IACCESSIBLETABLECELL_IID \
  {0x654e296d, 0xfae6, 0x452b, \
    { 0x98, 0x7d, 0x74, 0x6b, 0x20, 0xb9, 0x51, 0x4b }}

class NS_NO_VTABLE nsIAccessibleTableCell : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLETABLECELL_IID)

  /* readonly attribute nsIAccessibleTable table; */
  NS_IMETHOD GetTable(nsIAccessibleTable * *aTable) = 0;

  /* readonly attribute long columnIndex; */
  NS_IMETHOD GetColumnIndex(int32_t *aColumnIndex) = 0;

  /* readonly attribute long rowIndex; */
  NS_IMETHOD GetRowIndex(int32_t *aRowIndex) = 0;

  /* readonly attribute long columnExtent; */
  NS_IMETHOD GetColumnExtent(int32_t *aColumnExtent) = 0;

  /* readonly attribute long rowExtent; */
  NS_IMETHOD GetRowExtent(int32_t *aRowExtent) = 0;

  /* readonly attribute nsIArray columnHeaderCells; */
  NS_IMETHOD GetColumnHeaderCells(nsIArray * *aColumnHeaderCells) = 0;

  /* readonly attribute nsIArray rowHeaderCells; */
  NS_IMETHOD GetRowHeaderCells(nsIArray * *aRowHeaderCells) = 0;

  /* boolean isSelected (); */
  NS_IMETHOD IsSelected(bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleTableCell, NS_IACCESSIBLETABLECELL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLETABLECELL \
  NS_IMETHOD GetTable(nsIAccessibleTable * *aTable); \
  NS_IMETHOD GetColumnIndex(int32_t *aColumnIndex); \
  NS_IMETHOD GetRowIndex(int32_t *aRowIndex); \
  NS_IMETHOD GetColumnExtent(int32_t *aColumnExtent); \
  NS_IMETHOD GetRowExtent(int32_t *aRowExtent); \
  NS_IMETHOD GetColumnHeaderCells(nsIArray * *aColumnHeaderCells); \
  NS_IMETHOD GetRowHeaderCells(nsIArray * *aRowHeaderCells); \
  NS_IMETHOD IsSelected(bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLETABLECELL(_to) \
  NS_IMETHOD GetTable(nsIAccessibleTable * *aTable) { return _to GetTable(aTable); } \
  NS_IMETHOD GetColumnIndex(int32_t *aColumnIndex) { return _to GetColumnIndex(aColumnIndex); } \
  NS_IMETHOD GetRowIndex(int32_t *aRowIndex) { return _to GetRowIndex(aRowIndex); } \
  NS_IMETHOD GetColumnExtent(int32_t *aColumnExtent) { return _to GetColumnExtent(aColumnExtent); } \
  NS_IMETHOD GetRowExtent(int32_t *aRowExtent) { return _to GetRowExtent(aRowExtent); } \
  NS_IMETHOD GetColumnHeaderCells(nsIArray * *aColumnHeaderCells) { return _to GetColumnHeaderCells(aColumnHeaderCells); } \
  NS_IMETHOD GetRowHeaderCells(nsIArray * *aRowHeaderCells) { return _to GetRowHeaderCells(aRowHeaderCells); } \
  NS_IMETHOD IsSelected(bool *_retval) { return _to IsSelected(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLETABLECELL(_to) \
  NS_IMETHOD GetTable(nsIAccessibleTable * *aTable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTable(aTable); } \
  NS_IMETHOD GetColumnIndex(int32_t *aColumnIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnIndex(aColumnIndex); } \
  NS_IMETHOD GetRowIndex(int32_t *aRowIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowIndex(aRowIndex); } \
  NS_IMETHOD GetColumnExtent(int32_t *aColumnExtent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnExtent(aColumnExtent); } \
  NS_IMETHOD GetRowExtent(int32_t *aRowExtent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowExtent(aRowExtent); } \
  NS_IMETHOD GetColumnHeaderCells(nsIArray * *aColumnHeaderCells) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnHeaderCells(aColumnHeaderCells); } \
  NS_IMETHOD GetRowHeaderCells(nsIArray * *aRowHeaderCells) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowHeaderCells(aRowHeaderCells); } \
  NS_IMETHOD IsSelected(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsSelected(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleTableCell : public nsIAccessibleTableCell
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLETABLECELL

  nsAccessibleTableCell();

private:
  ~nsAccessibleTableCell();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleTableCell, nsIAccessibleTableCell)

nsAccessibleTableCell::nsAccessibleTableCell()
{
  /* member initializers and constructor code */
}

nsAccessibleTableCell::~nsAccessibleTableCell()
{
  /* destructor code */
}

/* readonly attribute nsIAccessibleTable table; */
NS_IMETHODIMP nsAccessibleTableCell::GetTable(nsIAccessibleTable * *aTable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long columnIndex; */
NS_IMETHODIMP nsAccessibleTableCell::GetColumnIndex(int32_t *aColumnIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long rowIndex; */
NS_IMETHODIMP nsAccessibleTableCell::GetRowIndex(int32_t *aRowIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long columnExtent; */
NS_IMETHODIMP nsAccessibleTableCell::GetColumnExtent(int32_t *aColumnExtent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long rowExtent; */
NS_IMETHODIMP nsAccessibleTableCell::GetRowExtent(int32_t *aRowExtent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIArray columnHeaderCells; */
NS_IMETHODIMP nsAccessibleTableCell::GetColumnHeaderCells(nsIArray * *aColumnHeaderCells)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIArray rowHeaderCells; */
NS_IMETHODIMP nsAccessibleTableCell::GetRowHeaderCells(nsIArray * *aRowHeaderCells)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isSelected (); */
NS_IMETHODIMP nsAccessibleTableCell::IsSelected(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleTable_h__ */

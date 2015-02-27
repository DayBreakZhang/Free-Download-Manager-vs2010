/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/accessible/public/nsIAccessibleTable.idl
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

class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessibleTable : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLETABLE_IID)

  /**
   * Return the caption accessible for the table. For example, html:caption
   * element of html:table element.
   */
  /* readonly attribute nsIAccessible caption; */
  NS_SCRIPTABLE NS_IMETHOD GetCaption(nsIAccessible **aCaption) = 0;

  /**
   * Return summary description for the table. For example, @summary attribute
   * on html:table element.
   */
  /* readonly attribute AString summary; */
  NS_SCRIPTABLE NS_IMETHOD GetSummary(nsAString & aSummary) = 0;

  /**
   * Return columns count in the table.
   */
  /* readonly attribute long columnCount; */
  NS_SCRIPTABLE NS_IMETHOD GetColumnCount(PRInt32 *aColumnCount) = 0;

  /**
   * Return rows count in the table.
   */
  /* readonly attribute long rowCount; */
  NS_SCRIPTABLE NS_IMETHOD GetRowCount(PRInt32 *aRowCount) = 0;

  /**
   * Return the accessible object at the specified row and column in the table.
   * If both row and column index are valid then the corresponding accessible
   * object is returned that represents the requested cell regardless of whether
   * the cell is currently visible (on the screen).
   *
   * @param  rowIndex     [in] the row index to retrieve the cell at
   * @param  columnIndex  [in] the column index to retrieve the cell at
   */
  /* nsIAccessible getCellAt (in long rowIndex, in long columnIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetCellAt(PRInt32 rowIndex, PRInt32 columnIndex, nsIAccessible **_retval NS_OUTPARAM) = 0;

  /**
   * Translate the given row and column indices into the corresponding cell
   * index.
   *
   * @param  rowIndex    [in] the row index to return cell index at
   * @param  columnIndex [in] the column index to return cell index at
   */
  /* long getCellIndexAt (in long rowIndex, in long columnIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetCellIndexAt(PRInt32 rowIndex, PRInt32 columnIndex, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Translate the given cell index into the corresponding column index.
   *
   * @param  cellIndex  [in] index of the table cell to return column index for
   */
  /* long getColumnIndexAt (in long cellIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetColumnIndexAt(PRInt32 cellIndex, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Translate the given cell index into the corresponding row index.
   *
   * @param cellIndex  [in] index of the table cell to return row index for
   */
  /* long getRowIndexAt (in long cellIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetRowIndexAt(PRInt32 cellIndex, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Translate the given cell index into the corresponding row and column
   * indices.
   *
   * @param cellIndex    [in] cell index to return row and column indices for
   * @param rowIndex     [out] row index at the given cell index
   * @param columnIndex  [out] column index at the given cell index
   */
  /* void getRowAndColumnIndicesAt (in long cellIndex, out long rowIndex, out long columnIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetRowAndColumnIndicesAt(PRInt32 cellIndex, PRInt32 *rowIndex NS_OUTPARAM, PRInt32 *columnIndex NS_OUTPARAM) = 0;

  /**
   * Return the number of columns occupied by the accessible cell at
   * the specified row and column in the table. The result differs from 1 if
   * the specified cell spans multiple columns.
   *
   * @param  row     [in] row index of the cell to return the column extent for
   * @param  column  [in] column index of the cell to return the column extent
   *                  for
   */
  /* long getColumnExtentAt (in long row, in long column); */
  NS_SCRIPTABLE NS_IMETHOD GetColumnExtentAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Return the number of rows occupied by the accessible cell at the specified
   * row and column in the table. The result differs from 1 if the specified
   * cell spans multiple rows.
   *
   * @param  row     [in] row index of the cell to return the column extent for
   * @param  column  [in] column index of the cell to return the column extent
   *                  for
   */
  /* long getRowExtentAt (in long row, in long column); */
  NS_SCRIPTABLE NS_IMETHOD GetRowExtentAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Return the description text of the specified column in the table.
   *
   * @param  columnIndex  [in] the column index to retrieve description for
   */
  /* AString getColumnDescription (in long columnIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetColumnDescription(PRInt32 columnIndex, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Return the description text of the specified row in the table.
   *
   * @param  rowIndex  [in] the row index to retrieve description for
   */
  /* AString getRowDescription (in long rowIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetRowDescription(PRInt32 rowIndex, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Return a boolean value indicating whether the specified column is
   * selected, i.e. all cells within the column are selected.
   *
   * @param  columnIndex  [in] the column index to determine if it's selected
   */
  /* boolean isColumnSelected (in long columnIndex); */
  NS_SCRIPTABLE NS_IMETHOD IsColumnSelected(PRInt32 columnIndex, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Return a boolean value indicating whether the specified row is selected,
   * i.e. all cells within the row are selected.
   *
   * @param  rowIndex  [in] the row index to determine whether it's selected
   */
  /* boolean isRowSelected (in long rowIndex); */
  NS_SCRIPTABLE NS_IMETHOD IsRowSelected(PRInt32 rowIndex, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Return a boolean value indicating whether the specified cell is selected.
   *
   * @param  rowIndex     [in] the row index of the cell
   * @param  columnIndex  [in] the column index of the cell
   */
  /* boolean isCellSelected (in long rowIndex, in long columnIndex); */
  NS_SCRIPTABLE NS_IMETHOD IsCellSelected(PRInt32 rowIndex, PRInt32 columnIndex, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Return the total number of selected cells.
   */
  /* readonly attribute unsigned long selectedCellCount; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCellCount(PRUint32 *aSelectedCellCount) = 0;

  /**
   * Return the total number of selected columns.
   */
  /* readonly attribute unsigned long selectedColumnCount; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedColumnCount(PRUint32 *aSelectedColumnCount) = 0;

  /**
   * Return the total number of selected rows.
   */
  /* readonly attribute unsigned long selectedRowCount; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedRowCount(PRUint32 *aSelectedRowCount) = 0;

  /**
   * Return an array of selected cells.
   */
  /* readonly attribute nsIArray selectedCells; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCells(nsIArray **aSelectedCells) = 0;

  /**
   * Return an array of cell indices currently selected.
   *
   * @param  cellsArraySize  [in] length of array
   * @param  cellsArray      [in] array of indexes of selected cells
   */
  /* void getSelectedCellIndices (out unsigned long cellsArraySize, [array, size_is (cellsArraySize), retval] out long cellsArray); */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCellIndices(PRUint32 *cellsArraySize NS_OUTPARAM, PRInt32 **cellsArray NS_OUTPARAM) = 0;

  /**
   * Return an array of column indices currently selected.
   *
   * @param  columnsArraySize  [in] length of array
   * @param  columnsArray      [in] array of indices of selected columns
   */
  /* void getSelectedColumnIndices (out unsigned long columnsArraySize, [array, size_is (columnsArraySize), retval] out long columnsArray); */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedColumnIndices(PRUint32 *columnsArraySize NS_OUTPARAM, PRInt32 **columnsArray NS_OUTPARAM) = 0;

  /**
   * Return an array of row indices currently selected.
   *
   * @param  rowsArraySize  [in] Length of array
   * @param  rowsArray      [in] array of indices of selected rows
   */
  /* void getSelectedRowIndices (out unsigned long rowsArraySize, [array, size_is (rowsArraySize), retval] out long rowsArray); */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedRowIndices(PRUint32 *rowsArraySize NS_OUTPARAM, PRInt32 **rowsArray NS_OUTPARAM) = 0;

  /**
   * Select a row and unselects all previously selected rows.
   *
   * @param  rowIndex  [in] the row index to select
   */
  /* void selectRow (in long rowIndex); */
  NS_SCRIPTABLE NS_IMETHOD SelectRow(PRInt32 rowIndex) = 0;

  /**
   * Select a column and unselects all previously selected columns.
   *
   * @param  columnIndex  [in] the column index to select
   */
  /* void selectColumn (in long columnIndex); */
  NS_SCRIPTABLE NS_IMETHOD SelectColumn(PRInt32 columnIndex) = 0;

  /**
   * Unselect the given row, leaving other selected rows selected (if any).
   *
   * @param  rowIndex  [in] the row index to select
  */
  /* void unselectRow (in long rowIndex); */
  NS_SCRIPTABLE NS_IMETHOD UnselectRow(PRInt32 rowIndex) = 0;

  /**
   * Unselect the given column, leaving other selected columns selected (if any).
   *
   * @param  columnIndex  [in] the column index to select
   */
  /* void unselectColumn (in long columnIndex); */
  NS_SCRIPTABLE NS_IMETHOD UnselectColumn(PRInt32 columnIndex) = 0;

  /**
   * Use heuristics to determine if table is most likely used for layout.
   */
  /* boolean isProbablyForLayout (); */
  NS_SCRIPTABLE NS_IMETHOD IsProbablyForLayout(PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleTable, NS_IACCESSIBLETABLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLETABLE \
  NS_SCRIPTABLE NS_IMETHOD GetCaption(nsIAccessible **aCaption); \
  NS_SCRIPTABLE NS_IMETHOD GetSummary(nsAString & aSummary); \
  NS_SCRIPTABLE NS_IMETHOD GetColumnCount(PRInt32 *aColumnCount); \
  NS_SCRIPTABLE NS_IMETHOD GetRowCount(PRInt32 *aRowCount); \
  NS_SCRIPTABLE NS_IMETHOD GetCellAt(PRInt32 rowIndex, PRInt32 columnIndex, nsIAccessible **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCellIndexAt(PRInt32 rowIndex, PRInt32 columnIndex, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetColumnIndexAt(PRInt32 cellIndex, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetRowIndexAt(PRInt32 cellIndex, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetRowAndColumnIndicesAt(PRInt32 cellIndex, PRInt32 *rowIndex NS_OUTPARAM, PRInt32 *columnIndex NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetColumnExtentAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetRowExtentAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetColumnDescription(PRInt32 columnIndex, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetRowDescription(PRInt32 rowIndex, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsColumnSelected(PRInt32 columnIndex, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsRowSelected(PRInt32 rowIndex, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsCellSelected(PRInt32 rowIndex, PRInt32 columnIndex, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCellCount(PRUint32 *aSelectedCellCount); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedColumnCount(PRUint32 *aSelectedColumnCount); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedRowCount(PRUint32 *aSelectedRowCount); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCells(nsIArray **aSelectedCells); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCellIndices(PRUint32 *cellsArraySize NS_OUTPARAM, PRInt32 **cellsArray NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedColumnIndices(PRUint32 *columnsArraySize NS_OUTPARAM, PRInt32 **columnsArray NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedRowIndices(PRUint32 *rowsArraySize NS_OUTPARAM, PRInt32 **rowsArray NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SelectRow(PRInt32 rowIndex); \
  NS_SCRIPTABLE NS_IMETHOD SelectColumn(PRInt32 columnIndex); \
  NS_SCRIPTABLE NS_IMETHOD UnselectRow(PRInt32 rowIndex); \
  NS_SCRIPTABLE NS_IMETHOD UnselectColumn(PRInt32 columnIndex); \
  NS_SCRIPTABLE NS_IMETHOD IsProbablyForLayout(PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLETABLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCaption(nsIAccessible **aCaption) { return _to GetCaption(aCaption); } \
  NS_SCRIPTABLE NS_IMETHOD GetSummary(nsAString & aSummary) { return _to GetSummary(aSummary); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnCount(PRInt32 *aColumnCount) { return _to GetColumnCount(aColumnCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowCount(PRInt32 *aRowCount) { return _to GetRowCount(aRowCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetCellAt(PRInt32 rowIndex, PRInt32 columnIndex, nsIAccessible **_retval NS_OUTPARAM) { return _to GetCellAt(rowIndex, columnIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCellIndexAt(PRInt32 rowIndex, PRInt32 columnIndex, PRInt32 *_retval NS_OUTPARAM) { return _to GetCellIndexAt(rowIndex, columnIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnIndexAt(PRInt32 cellIndex, PRInt32 *_retval NS_OUTPARAM) { return _to GetColumnIndexAt(cellIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowIndexAt(PRInt32 cellIndex, PRInt32 *_retval NS_OUTPARAM) { return _to GetRowIndexAt(cellIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowAndColumnIndicesAt(PRInt32 cellIndex, PRInt32 *rowIndex NS_OUTPARAM, PRInt32 *columnIndex NS_OUTPARAM) { return _to GetRowAndColumnIndicesAt(cellIndex, rowIndex, columnIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnExtentAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM) { return _to GetColumnExtentAt(row, column, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowExtentAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM) { return _to GetRowExtentAt(row, column, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnDescription(PRInt32 columnIndex, nsAString & _retval NS_OUTPARAM) { return _to GetColumnDescription(columnIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowDescription(PRInt32 rowIndex, nsAString & _retval NS_OUTPARAM) { return _to GetRowDescription(rowIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsColumnSelected(PRInt32 columnIndex, PRBool *_retval NS_OUTPARAM) { return _to IsColumnSelected(columnIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsRowSelected(PRInt32 rowIndex, PRBool *_retval NS_OUTPARAM) { return _to IsRowSelected(rowIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsCellSelected(PRInt32 rowIndex, PRInt32 columnIndex, PRBool *_retval NS_OUTPARAM) { return _to IsCellSelected(rowIndex, columnIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCellCount(PRUint32 *aSelectedCellCount) { return _to GetSelectedCellCount(aSelectedCellCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedColumnCount(PRUint32 *aSelectedColumnCount) { return _to GetSelectedColumnCount(aSelectedColumnCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedRowCount(PRUint32 *aSelectedRowCount) { return _to GetSelectedRowCount(aSelectedRowCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCells(nsIArray **aSelectedCells) { return _to GetSelectedCells(aSelectedCells); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCellIndices(PRUint32 *cellsArraySize NS_OUTPARAM, PRInt32 **cellsArray NS_OUTPARAM) { return _to GetSelectedCellIndices(cellsArraySize, cellsArray); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedColumnIndices(PRUint32 *columnsArraySize NS_OUTPARAM, PRInt32 **columnsArray NS_OUTPARAM) { return _to GetSelectedColumnIndices(columnsArraySize, columnsArray); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedRowIndices(PRUint32 *rowsArraySize NS_OUTPARAM, PRInt32 **rowsArray NS_OUTPARAM) { return _to GetSelectedRowIndices(rowsArraySize, rowsArray); } \
  NS_SCRIPTABLE NS_IMETHOD SelectRow(PRInt32 rowIndex) { return _to SelectRow(rowIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SelectColumn(PRInt32 columnIndex) { return _to SelectColumn(columnIndex); } \
  NS_SCRIPTABLE NS_IMETHOD UnselectRow(PRInt32 rowIndex) { return _to UnselectRow(rowIndex); } \
  NS_SCRIPTABLE NS_IMETHOD UnselectColumn(PRInt32 columnIndex) { return _to UnselectColumn(columnIndex); } \
  NS_SCRIPTABLE NS_IMETHOD IsProbablyForLayout(PRBool *_retval NS_OUTPARAM) { return _to IsProbablyForLayout(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLETABLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCaption(nsIAccessible **aCaption) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCaption(aCaption); } \
  NS_SCRIPTABLE NS_IMETHOD GetSummary(nsAString & aSummary) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSummary(aSummary); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnCount(PRInt32 *aColumnCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnCount(aColumnCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowCount(PRInt32 *aRowCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowCount(aRowCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetCellAt(PRInt32 rowIndex, PRInt32 columnIndex, nsIAccessible **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCellAt(rowIndex, columnIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCellIndexAt(PRInt32 rowIndex, PRInt32 columnIndex, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCellIndexAt(rowIndex, columnIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnIndexAt(PRInt32 cellIndex, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnIndexAt(cellIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowIndexAt(PRInt32 cellIndex, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowIndexAt(cellIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowAndColumnIndicesAt(PRInt32 cellIndex, PRInt32 *rowIndex NS_OUTPARAM, PRInt32 *columnIndex NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowAndColumnIndicesAt(cellIndex, rowIndex, columnIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnExtentAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnExtentAt(row, column, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowExtentAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowExtentAt(row, column, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnDescription(PRInt32 columnIndex, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnDescription(columnIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowDescription(PRInt32 rowIndex, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowDescription(rowIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsColumnSelected(PRInt32 columnIndex, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsColumnSelected(columnIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsRowSelected(PRInt32 rowIndex, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsRowSelected(rowIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsCellSelected(PRInt32 rowIndex, PRInt32 columnIndex, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCellSelected(rowIndex, columnIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCellCount(PRUint32 *aSelectedCellCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedCellCount(aSelectedCellCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedColumnCount(PRUint32 *aSelectedColumnCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedColumnCount(aSelectedColumnCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedRowCount(PRUint32 *aSelectedRowCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedRowCount(aSelectedRowCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCells(nsIArray **aSelectedCells) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedCells(aSelectedCells); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCellIndices(PRUint32 *cellsArraySize NS_OUTPARAM, PRInt32 **cellsArray NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedCellIndices(cellsArraySize, cellsArray); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedColumnIndices(PRUint32 *columnsArraySize NS_OUTPARAM, PRInt32 **columnsArray NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedColumnIndices(columnsArraySize, columnsArray); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedRowIndices(PRUint32 *rowsArraySize NS_OUTPARAM, PRInt32 **rowsArray NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedRowIndices(rowsArraySize, rowsArray); } \
  NS_SCRIPTABLE NS_IMETHOD SelectRow(PRInt32 rowIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectRow(rowIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SelectColumn(PRInt32 columnIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectColumn(columnIndex); } \
  NS_SCRIPTABLE NS_IMETHOD UnselectRow(PRInt32 rowIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnselectRow(rowIndex); } \
  NS_SCRIPTABLE NS_IMETHOD UnselectColumn(PRInt32 columnIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnselectColumn(columnIndex); } \
  NS_SCRIPTABLE NS_IMETHOD IsProbablyForLayout(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsProbablyForLayout(_retval); } 

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
NS_IMETHODIMP nsAccessibleTable::GetCaption(nsIAccessible **aCaption)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString summary; */
NS_IMETHODIMP nsAccessibleTable::GetSummary(nsAString & aSummary)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long columnCount; */
NS_IMETHODIMP nsAccessibleTable::GetColumnCount(PRInt32 *aColumnCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long rowCount; */
NS_IMETHODIMP nsAccessibleTable::GetRowCount(PRInt32 *aRowCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getCellAt (in long rowIndex, in long columnIndex); */
NS_IMETHODIMP nsAccessibleTable::GetCellAt(PRInt32 rowIndex, PRInt32 columnIndex, nsIAccessible **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getCellIndexAt (in long rowIndex, in long columnIndex); */
NS_IMETHODIMP nsAccessibleTable::GetCellIndexAt(PRInt32 rowIndex, PRInt32 columnIndex, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getColumnIndexAt (in long cellIndex); */
NS_IMETHODIMP nsAccessibleTable::GetColumnIndexAt(PRInt32 cellIndex, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getRowIndexAt (in long cellIndex); */
NS_IMETHODIMP nsAccessibleTable::GetRowIndexAt(PRInt32 cellIndex, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getRowAndColumnIndicesAt (in long cellIndex, out long rowIndex, out long columnIndex); */
NS_IMETHODIMP nsAccessibleTable::GetRowAndColumnIndicesAt(PRInt32 cellIndex, PRInt32 *rowIndex NS_OUTPARAM, PRInt32 *columnIndex NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getColumnExtentAt (in long row, in long column); */
NS_IMETHODIMP nsAccessibleTable::GetColumnExtentAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getRowExtentAt (in long row, in long column); */
NS_IMETHODIMP nsAccessibleTable::GetRowExtentAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getColumnDescription (in long columnIndex); */
NS_IMETHODIMP nsAccessibleTable::GetColumnDescription(PRInt32 columnIndex, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getRowDescription (in long rowIndex); */
NS_IMETHODIMP nsAccessibleTable::GetRowDescription(PRInt32 rowIndex, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isColumnSelected (in long columnIndex); */
NS_IMETHODIMP nsAccessibleTable::IsColumnSelected(PRInt32 columnIndex, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isRowSelected (in long rowIndex); */
NS_IMETHODIMP nsAccessibleTable::IsRowSelected(PRInt32 rowIndex, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isCellSelected (in long rowIndex, in long columnIndex); */
NS_IMETHODIMP nsAccessibleTable::IsCellSelected(PRInt32 rowIndex, PRInt32 columnIndex, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long selectedCellCount; */
NS_IMETHODIMP nsAccessibleTable::GetSelectedCellCount(PRUint32 *aSelectedCellCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long selectedColumnCount; */
NS_IMETHODIMP nsAccessibleTable::GetSelectedColumnCount(PRUint32 *aSelectedColumnCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long selectedRowCount; */
NS_IMETHODIMP nsAccessibleTable::GetSelectedRowCount(PRUint32 *aSelectedRowCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIArray selectedCells; */
NS_IMETHODIMP nsAccessibleTable::GetSelectedCells(nsIArray **aSelectedCells)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSelectedCellIndices (out unsigned long cellsArraySize, [array, size_is (cellsArraySize), retval] out long cellsArray); */
NS_IMETHODIMP nsAccessibleTable::GetSelectedCellIndices(PRUint32 *cellsArraySize NS_OUTPARAM, PRInt32 **cellsArray NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSelectedColumnIndices (out unsigned long columnsArraySize, [array, size_is (columnsArraySize), retval] out long columnsArray); */
NS_IMETHODIMP nsAccessibleTable::GetSelectedColumnIndices(PRUint32 *columnsArraySize NS_OUTPARAM, PRInt32 **columnsArray NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSelectedRowIndices (out unsigned long rowsArraySize, [array, size_is (rowsArraySize), retval] out long rowsArray); */
NS_IMETHODIMP nsAccessibleTable::GetSelectedRowIndices(PRUint32 *rowsArraySize NS_OUTPARAM, PRInt32 **rowsArray NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectRow (in long rowIndex); */
NS_IMETHODIMP nsAccessibleTable::SelectRow(PRInt32 rowIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectColumn (in long columnIndex); */
NS_IMETHODIMP nsAccessibleTable::SelectColumn(PRInt32 columnIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unselectRow (in long rowIndex); */
NS_IMETHODIMP nsAccessibleTable::UnselectRow(PRInt32 rowIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unselectColumn (in long columnIndex); */
NS_IMETHODIMP nsAccessibleTable::UnselectColumn(PRInt32 columnIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isProbablyForLayout (); */
NS_IMETHODIMP nsAccessibleTable::IsProbablyForLayout(PRBool *_retval NS_OUTPARAM)
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

class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessibleTableCell : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLETABLECELL_IID)

  /**
   * Return host table accessible.
   */
  /* readonly attribute nsIAccessibleTable table; */
  NS_SCRIPTABLE NS_IMETHOD GetTable(nsIAccessibleTable **aTable) = 0;

  /**
   * Return column index of this cell.
   */
  /* readonly attribute long columnIndex; */
  NS_SCRIPTABLE NS_IMETHOD GetColumnIndex(PRInt32 *aColumnIndex) = 0;

  /**
   * Return row index of this cell.
   */
  /* readonly attribute long rowIndex; */
  NS_SCRIPTABLE NS_IMETHOD GetRowIndex(PRInt32 *aRowIndex) = 0;

  /**
   * Return the number of columns occupied by this cell. The result differs
   * from 1 if the specified cell spans multiple columns.
   */
  /* readonly attribute long columnExtent; */
  NS_SCRIPTABLE NS_IMETHOD GetColumnExtent(PRInt32 *aColumnExtent) = 0;

  /**
   * Return the number of rows occupied by this accessible cell. The result
   * differs from 1 if the specified cell spans multiple rows.
   */
  /* readonly attribute long rowExtent; */
  NS_SCRIPTABLE NS_IMETHOD GetRowExtent(PRInt32 *aRowExtent) = 0;

  /**
   * Return an array of column header cells for this cell.
   */
  /* readonly attribute nsIArray columnHeaderCells; */
  NS_SCRIPTABLE NS_IMETHOD GetColumnHeaderCells(nsIArray **aColumnHeaderCells) = 0;

  /**
   * Return an array of row header cells for this cell.
   */
  /* readonly attribute nsIArray rowHeaderCells; */
  NS_SCRIPTABLE NS_IMETHOD GetRowHeaderCells(nsIArray **aRowHeaderCells) = 0;

  /**
   * Return a boolean value indicating whether this cell is selected.
   */
  /* boolean isSelected (); */
  NS_SCRIPTABLE NS_IMETHOD IsSelected(PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleTableCell, NS_IACCESSIBLETABLECELL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLETABLECELL \
  NS_SCRIPTABLE NS_IMETHOD GetTable(nsIAccessibleTable **aTable); \
  NS_SCRIPTABLE NS_IMETHOD GetColumnIndex(PRInt32 *aColumnIndex); \
  NS_SCRIPTABLE NS_IMETHOD GetRowIndex(PRInt32 *aRowIndex); \
  NS_SCRIPTABLE NS_IMETHOD GetColumnExtent(PRInt32 *aColumnExtent); \
  NS_SCRIPTABLE NS_IMETHOD GetRowExtent(PRInt32 *aRowExtent); \
  NS_SCRIPTABLE NS_IMETHOD GetColumnHeaderCells(nsIArray **aColumnHeaderCells); \
  NS_SCRIPTABLE NS_IMETHOD GetRowHeaderCells(nsIArray **aRowHeaderCells); \
  NS_SCRIPTABLE NS_IMETHOD IsSelected(PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLETABLECELL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTable(nsIAccessibleTable **aTable) { return _to GetTable(aTable); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnIndex(PRInt32 *aColumnIndex) { return _to GetColumnIndex(aColumnIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowIndex(PRInt32 *aRowIndex) { return _to GetRowIndex(aRowIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnExtent(PRInt32 *aColumnExtent) { return _to GetColumnExtent(aColumnExtent); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowExtent(PRInt32 *aRowExtent) { return _to GetRowExtent(aRowExtent); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnHeaderCells(nsIArray **aColumnHeaderCells) { return _to GetColumnHeaderCells(aColumnHeaderCells); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowHeaderCells(nsIArray **aRowHeaderCells) { return _to GetRowHeaderCells(aRowHeaderCells); } \
  NS_SCRIPTABLE NS_IMETHOD IsSelected(PRBool *_retval NS_OUTPARAM) { return _to IsSelected(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLETABLECELL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTable(nsIAccessibleTable **aTable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTable(aTable); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnIndex(PRInt32 *aColumnIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnIndex(aColumnIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowIndex(PRInt32 *aRowIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowIndex(aRowIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnExtent(PRInt32 *aColumnExtent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnExtent(aColumnExtent); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowExtent(PRInt32 *aRowExtent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowExtent(aRowExtent); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnHeaderCells(nsIArray **aColumnHeaderCells) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnHeaderCells(aColumnHeaderCells); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowHeaderCells(nsIArray **aRowHeaderCells) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowHeaderCells(aRowHeaderCells); } \
  NS_SCRIPTABLE NS_IMETHOD IsSelected(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsSelected(_retval); } 

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
NS_IMETHODIMP nsAccessibleTableCell::GetTable(nsIAccessibleTable **aTable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long columnIndex; */
NS_IMETHODIMP nsAccessibleTableCell::GetColumnIndex(PRInt32 *aColumnIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long rowIndex; */
NS_IMETHODIMP nsAccessibleTableCell::GetRowIndex(PRInt32 *aRowIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long columnExtent; */
NS_IMETHODIMP nsAccessibleTableCell::GetColumnExtent(PRInt32 *aColumnExtent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long rowExtent; */
NS_IMETHODIMP nsAccessibleTableCell::GetRowExtent(PRInt32 *aRowExtent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIArray columnHeaderCells; */
NS_IMETHODIMP nsAccessibleTableCell::GetColumnHeaderCells(nsIArray **aColumnHeaderCells)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIArray rowHeaderCells; */
NS_IMETHODIMP nsAccessibleTableCell::GetRowHeaderCells(nsIArray **aRowHeaderCells)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isSelected (); */
NS_IMETHODIMP nsAccessibleTableCell::IsSelected(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleTable_h__ */

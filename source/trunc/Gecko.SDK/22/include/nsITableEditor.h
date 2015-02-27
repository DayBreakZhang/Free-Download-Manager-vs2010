/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/editor/idl/nsITableEditor.idl
 */

#ifndef __gen_nsITableEditor_h__
#define __gen_nsITableEditor_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNode; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIDOMRange; /* forward declaration */


/* starting interface:    nsITableEditor */
#define NS_ITABLEEDITOR_IID_STR "4805e684-49b9-11d3-9ce4-ed60bd6cb5bc"

#define NS_ITABLEEDITOR_IID \
  {0x4805e684, 0x49b9, 0x11d3, \
    { 0x9c, 0xe4, 0xed, 0x60, 0xbd, 0x6c, 0xb5, 0xbc }}

class NS_NO_VTABLE nsITableEditor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITABLEEDITOR_IID)

  enum {
    eNoSearch = 0,
    ePreviousColumn = 1,
    ePreviousRow = 2
  };

  /* void insertTableCell (in long aNumber, in boolean aAfter); */
  NS_IMETHOD InsertTableCell(int32_t aNumber, bool aAfter) = 0;

  /* void insertTableColumn (in long aNumber, in boolean aAfter); */
  NS_IMETHOD InsertTableColumn(int32_t aNumber, bool aAfter) = 0;

  /* void insertTableRow (in long aNumber, in boolean aAfter); */
  NS_IMETHOD InsertTableRow(int32_t aNumber, bool aAfter) = 0;

  /* void deleteTable (); */
  NS_IMETHOD DeleteTable(void) = 0;

  /* void deleteTableCellContents (); */
  NS_IMETHOD DeleteTableCellContents(void) = 0;

  /* void deleteTableCell (in long aNumber); */
  NS_IMETHOD DeleteTableCell(int32_t aNumber) = 0;

  /* void deleteTableColumn (in long aNumber); */
  NS_IMETHOD DeleteTableColumn(int32_t aNumber) = 0;

  /* void deleteTableRow (in long aNumber); */
  NS_IMETHOD DeleteTableRow(int32_t aNumber) = 0;

  /* void selectTableCell (); */
  NS_IMETHOD SelectTableCell(void) = 0;

  /* void selectBlockOfCells (in nsIDOMElement aStartCell, in nsIDOMElement aEndCell); */
  NS_IMETHOD SelectBlockOfCells(nsIDOMElement *aStartCell, nsIDOMElement *aEndCell) = 0;

  /* void selectTableRow (); */
  NS_IMETHOD SelectTableRow(void) = 0;

  /* void selectTableColumn (); */
  NS_IMETHOD SelectTableColumn(void) = 0;

  /* void selectTable (); */
  NS_IMETHOD SelectTable(void) = 0;

  /* void selectAllTableCells (); */
  NS_IMETHOD SelectAllTableCells(void) = 0;

  /* nsIDOMElement switchTableCellHeaderType (in nsIDOMElement aSourceCell); */
  NS_IMETHOD SwitchTableCellHeaderType(nsIDOMElement *aSourceCell, nsIDOMElement * *_retval) = 0;

  /* void joinTableCells (in boolean aMergeNonContiguousContents); */
  NS_IMETHOD JoinTableCells(bool aMergeNonContiguousContents) = 0;

  /* void splitTableCell (); */
  NS_IMETHOD SplitTableCell(void) = 0;

  /* void normalizeTable (in nsIDOMElement aTable); */
  NS_IMETHOD NormalizeTable(nsIDOMElement *aTable) = 0;

  /* void getCellIndexes (in nsIDOMElement aCell, out long aRowIndex, out long aColIndex); */
  NS_IMETHOD GetCellIndexes(nsIDOMElement *aCell, int32_t *aRowIndex, int32_t *aColIndex) = 0;

  /* void getTableSize (in nsIDOMElement aTable, out long aRowCount, out long aColCount); */
  NS_IMETHOD GetTableSize(nsIDOMElement *aTable, int32_t *aRowCount, int32_t *aColCount) = 0;

  /* nsIDOMElement getCellAt (in nsIDOMElement aTable, in long aRowIndex, in long aColIndex); */
  NS_IMETHOD GetCellAt(nsIDOMElement *aTable, int32_t aRowIndex, int32_t aColIndex, nsIDOMElement * *_retval) = 0;

  /* void getCellDataAt (in nsIDOMElement aTable, in long aRowIndex, in long aColIndex, out nsIDOMElement aCell, out long aStartRowIndex, out long aStartColIndex, out long aRowSpan, out long aColSpan, out long aActualRowSpan, out long aActualColSpan, out boolean aIsSelected); */
  NS_IMETHOD GetCellDataAt(nsIDOMElement *aTable, int32_t aRowIndex, int32_t aColIndex, nsIDOMElement * *aCell, int32_t *aStartRowIndex, int32_t *aStartColIndex, int32_t *aRowSpan, int32_t *aColSpan, int32_t *aActualRowSpan, int32_t *aActualColSpan, bool *aIsSelected) = 0;

  /* nsIDOMNode getFirstRow (in nsIDOMElement aTableElement); */
  NS_IMETHOD GetFirstRow(nsIDOMElement *aTableElement, nsIDOMNode * *_retval) = 0;

  /* nsIDOMNode getNextRow (in nsIDOMNode aTableElement); */
  NS_IMETHOD GetNextRow(nsIDOMNode *aTableElement, nsIDOMNode * *_retval) = 0;

  /* void setSelectionAfterTableEdit (in nsIDOMElement aTable, in long aRow, in long aCol, in long aDirection, in boolean aSelected); */
  NS_IMETHOD SetSelectionAfterTableEdit(nsIDOMElement *aTable, int32_t aRow, int32_t aCol, int32_t aDirection, bool aSelected) = 0;

  /* nsIDOMElement getSelectedOrParentTableElement (out AString aTagName, out long aCount); */
  NS_IMETHOD GetSelectedOrParentTableElement(nsAString & aTagName, int32_t *aCount, nsIDOMElement * *_retval) = 0;

  /* uint32_t getSelectedCellsType (in nsIDOMElement aElement); */
  NS_IMETHOD GetSelectedCellsType(nsIDOMElement *aElement, uint32_t *_retval) = 0;

  /* nsIDOMElement getFirstSelectedCell (out nsIDOMRange aRange); */
  NS_IMETHOD GetFirstSelectedCell(nsIDOMRange * *aRange, nsIDOMElement * *_retval) = 0;

  /* nsIDOMElement getFirstSelectedCellInTable (out long aRowIndex, out long aColIndex); */
  NS_IMETHOD GetFirstSelectedCellInTable(int32_t *aRowIndex, int32_t *aColIndex, nsIDOMElement * *_retval) = 0;

  /* nsIDOMElement getNextSelectedCell (out nsIDOMRange aRange); */
  NS_IMETHOD GetNextSelectedCell(nsIDOMRange * *aRange, nsIDOMElement * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITableEditor, NS_ITABLEEDITOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITABLEEDITOR \
  NS_IMETHOD InsertTableCell(int32_t aNumber, bool aAfter); \
  NS_IMETHOD InsertTableColumn(int32_t aNumber, bool aAfter); \
  NS_IMETHOD InsertTableRow(int32_t aNumber, bool aAfter); \
  NS_IMETHOD DeleteTable(void); \
  NS_IMETHOD DeleteTableCellContents(void); \
  NS_IMETHOD DeleteTableCell(int32_t aNumber); \
  NS_IMETHOD DeleteTableColumn(int32_t aNumber); \
  NS_IMETHOD DeleteTableRow(int32_t aNumber); \
  NS_IMETHOD SelectTableCell(void); \
  NS_IMETHOD SelectBlockOfCells(nsIDOMElement *aStartCell, nsIDOMElement *aEndCell); \
  NS_IMETHOD SelectTableRow(void); \
  NS_IMETHOD SelectTableColumn(void); \
  NS_IMETHOD SelectTable(void); \
  NS_IMETHOD SelectAllTableCells(void); \
  NS_IMETHOD SwitchTableCellHeaderType(nsIDOMElement *aSourceCell, nsIDOMElement * *_retval); \
  NS_IMETHOD JoinTableCells(bool aMergeNonContiguousContents); \
  NS_IMETHOD SplitTableCell(void); \
  NS_IMETHOD NormalizeTable(nsIDOMElement *aTable); \
  NS_IMETHOD GetCellIndexes(nsIDOMElement *aCell, int32_t *aRowIndex, int32_t *aColIndex); \
  NS_IMETHOD GetTableSize(nsIDOMElement *aTable, int32_t *aRowCount, int32_t *aColCount); \
  NS_IMETHOD GetCellAt(nsIDOMElement *aTable, int32_t aRowIndex, int32_t aColIndex, nsIDOMElement * *_retval); \
  NS_IMETHOD GetCellDataAt(nsIDOMElement *aTable, int32_t aRowIndex, int32_t aColIndex, nsIDOMElement * *aCell, int32_t *aStartRowIndex, int32_t *aStartColIndex, int32_t *aRowSpan, int32_t *aColSpan, int32_t *aActualRowSpan, int32_t *aActualColSpan, bool *aIsSelected); \
  NS_IMETHOD GetFirstRow(nsIDOMElement *aTableElement, nsIDOMNode * *_retval); \
  NS_IMETHOD GetNextRow(nsIDOMNode *aTableElement, nsIDOMNode * *_retval); \
  NS_IMETHOD SetSelectionAfterTableEdit(nsIDOMElement *aTable, int32_t aRow, int32_t aCol, int32_t aDirection, bool aSelected); \
  NS_IMETHOD GetSelectedOrParentTableElement(nsAString & aTagName, int32_t *aCount, nsIDOMElement * *_retval); \
  NS_IMETHOD GetSelectedCellsType(nsIDOMElement *aElement, uint32_t *_retval); \
  NS_IMETHOD GetFirstSelectedCell(nsIDOMRange * *aRange, nsIDOMElement * *_retval); \
  NS_IMETHOD GetFirstSelectedCellInTable(int32_t *aRowIndex, int32_t *aColIndex, nsIDOMElement * *_retval); \
  NS_IMETHOD GetNextSelectedCell(nsIDOMRange * *aRange, nsIDOMElement * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITABLEEDITOR(_to) \
  NS_IMETHOD InsertTableCell(int32_t aNumber, bool aAfter) { return _to InsertTableCell(aNumber, aAfter); } \
  NS_IMETHOD InsertTableColumn(int32_t aNumber, bool aAfter) { return _to InsertTableColumn(aNumber, aAfter); } \
  NS_IMETHOD InsertTableRow(int32_t aNumber, bool aAfter) { return _to InsertTableRow(aNumber, aAfter); } \
  NS_IMETHOD DeleteTable(void) { return _to DeleteTable(); } \
  NS_IMETHOD DeleteTableCellContents(void) { return _to DeleteTableCellContents(); } \
  NS_IMETHOD DeleteTableCell(int32_t aNumber) { return _to DeleteTableCell(aNumber); } \
  NS_IMETHOD DeleteTableColumn(int32_t aNumber) { return _to DeleteTableColumn(aNumber); } \
  NS_IMETHOD DeleteTableRow(int32_t aNumber) { return _to DeleteTableRow(aNumber); } \
  NS_IMETHOD SelectTableCell(void) { return _to SelectTableCell(); } \
  NS_IMETHOD SelectBlockOfCells(nsIDOMElement *aStartCell, nsIDOMElement *aEndCell) { return _to SelectBlockOfCells(aStartCell, aEndCell); } \
  NS_IMETHOD SelectTableRow(void) { return _to SelectTableRow(); } \
  NS_IMETHOD SelectTableColumn(void) { return _to SelectTableColumn(); } \
  NS_IMETHOD SelectTable(void) { return _to SelectTable(); } \
  NS_IMETHOD SelectAllTableCells(void) { return _to SelectAllTableCells(); } \
  NS_IMETHOD SwitchTableCellHeaderType(nsIDOMElement *aSourceCell, nsIDOMElement * *_retval) { return _to SwitchTableCellHeaderType(aSourceCell, _retval); } \
  NS_IMETHOD JoinTableCells(bool aMergeNonContiguousContents) { return _to JoinTableCells(aMergeNonContiguousContents); } \
  NS_IMETHOD SplitTableCell(void) { return _to SplitTableCell(); } \
  NS_IMETHOD NormalizeTable(nsIDOMElement *aTable) { return _to NormalizeTable(aTable); } \
  NS_IMETHOD GetCellIndexes(nsIDOMElement *aCell, int32_t *aRowIndex, int32_t *aColIndex) { return _to GetCellIndexes(aCell, aRowIndex, aColIndex); } \
  NS_IMETHOD GetTableSize(nsIDOMElement *aTable, int32_t *aRowCount, int32_t *aColCount) { return _to GetTableSize(aTable, aRowCount, aColCount); } \
  NS_IMETHOD GetCellAt(nsIDOMElement *aTable, int32_t aRowIndex, int32_t aColIndex, nsIDOMElement * *_retval) { return _to GetCellAt(aTable, aRowIndex, aColIndex, _retval); } \
  NS_IMETHOD GetCellDataAt(nsIDOMElement *aTable, int32_t aRowIndex, int32_t aColIndex, nsIDOMElement * *aCell, int32_t *aStartRowIndex, int32_t *aStartColIndex, int32_t *aRowSpan, int32_t *aColSpan, int32_t *aActualRowSpan, int32_t *aActualColSpan, bool *aIsSelected) { return _to GetCellDataAt(aTable, aRowIndex, aColIndex, aCell, aStartRowIndex, aStartColIndex, aRowSpan, aColSpan, aActualRowSpan, aActualColSpan, aIsSelected); } \
  NS_IMETHOD GetFirstRow(nsIDOMElement *aTableElement, nsIDOMNode * *_retval) { return _to GetFirstRow(aTableElement, _retval); } \
  NS_IMETHOD GetNextRow(nsIDOMNode *aTableElement, nsIDOMNode * *_retval) { return _to GetNextRow(aTableElement, _retval); } \
  NS_IMETHOD SetSelectionAfterTableEdit(nsIDOMElement *aTable, int32_t aRow, int32_t aCol, int32_t aDirection, bool aSelected) { return _to SetSelectionAfterTableEdit(aTable, aRow, aCol, aDirection, aSelected); } \
  NS_IMETHOD GetSelectedOrParentTableElement(nsAString & aTagName, int32_t *aCount, nsIDOMElement * *_retval) { return _to GetSelectedOrParentTableElement(aTagName, aCount, _retval); } \
  NS_IMETHOD GetSelectedCellsType(nsIDOMElement *aElement, uint32_t *_retval) { return _to GetSelectedCellsType(aElement, _retval); } \
  NS_IMETHOD GetFirstSelectedCell(nsIDOMRange * *aRange, nsIDOMElement * *_retval) { return _to GetFirstSelectedCell(aRange, _retval); } \
  NS_IMETHOD GetFirstSelectedCellInTable(int32_t *aRowIndex, int32_t *aColIndex, nsIDOMElement * *_retval) { return _to GetFirstSelectedCellInTable(aRowIndex, aColIndex, _retval); } \
  NS_IMETHOD GetNextSelectedCell(nsIDOMRange * *aRange, nsIDOMElement * *_retval) { return _to GetNextSelectedCell(aRange, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITABLEEDITOR(_to) \
  NS_IMETHOD InsertTableCell(int32_t aNumber, bool aAfter) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertTableCell(aNumber, aAfter); } \
  NS_IMETHOD InsertTableColumn(int32_t aNumber, bool aAfter) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertTableColumn(aNumber, aAfter); } \
  NS_IMETHOD InsertTableRow(int32_t aNumber, bool aAfter) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertTableRow(aNumber, aAfter); } \
  NS_IMETHOD DeleteTable(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteTable(); } \
  NS_IMETHOD DeleteTableCellContents(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteTableCellContents(); } \
  NS_IMETHOD DeleteTableCell(int32_t aNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteTableCell(aNumber); } \
  NS_IMETHOD DeleteTableColumn(int32_t aNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteTableColumn(aNumber); } \
  NS_IMETHOD DeleteTableRow(int32_t aNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteTableRow(aNumber); } \
  NS_IMETHOD SelectTableCell(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectTableCell(); } \
  NS_IMETHOD SelectBlockOfCells(nsIDOMElement *aStartCell, nsIDOMElement *aEndCell) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectBlockOfCells(aStartCell, aEndCell); } \
  NS_IMETHOD SelectTableRow(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectTableRow(); } \
  NS_IMETHOD SelectTableColumn(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectTableColumn(); } \
  NS_IMETHOD SelectTable(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectTable(); } \
  NS_IMETHOD SelectAllTableCells(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectAllTableCells(); } \
  NS_IMETHOD SwitchTableCellHeaderType(nsIDOMElement *aSourceCell, nsIDOMElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SwitchTableCellHeaderType(aSourceCell, _retval); } \
  NS_IMETHOD JoinTableCells(bool aMergeNonContiguousContents) { return !_to ? NS_ERROR_NULL_POINTER : _to->JoinTableCells(aMergeNonContiguousContents); } \
  NS_IMETHOD SplitTableCell(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SplitTableCell(); } \
  NS_IMETHOD NormalizeTable(nsIDOMElement *aTable) { return !_to ? NS_ERROR_NULL_POINTER : _to->NormalizeTable(aTable); } \
  NS_IMETHOD GetCellIndexes(nsIDOMElement *aCell, int32_t *aRowIndex, int32_t *aColIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCellIndexes(aCell, aRowIndex, aColIndex); } \
  NS_IMETHOD GetTableSize(nsIDOMElement *aTable, int32_t *aRowCount, int32_t *aColCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTableSize(aTable, aRowCount, aColCount); } \
  NS_IMETHOD GetCellAt(nsIDOMElement *aTable, int32_t aRowIndex, int32_t aColIndex, nsIDOMElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCellAt(aTable, aRowIndex, aColIndex, _retval); } \
  NS_IMETHOD GetCellDataAt(nsIDOMElement *aTable, int32_t aRowIndex, int32_t aColIndex, nsIDOMElement * *aCell, int32_t *aStartRowIndex, int32_t *aStartColIndex, int32_t *aRowSpan, int32_t *aColSpan, int32_t *aActualRowSpan, int32_t *aActualColSpan, bool *aIsSelected) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCellDataAt(aTable, aRowIndex, aColIndex, aCell, aStartRowIndex, aStartColIndex, aRowSpan, aColSpan, aActualRowSpan, aActualColSpan, aIsSelected); } \
  NS_IMETHOD GetFirstRow(nsIDOMElement *aTableElement, nsIDOMNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFirstRow(aTableElement, _retval); } \
  NS_IMETHOD GetNextRow(nsIDOMNode *aTableElement, nsIDOMNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNextRow(aTableElement, _retval); } \
  NS_IMETHOD SetSelectionAfterTableEdit(nsIDOMElement *aTable, int32_t aRow, int32_t aCol, int32_t aDirection, bool aSelected) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectionAfterTableEdit(aTable, aRow, aCol, aDirection, aSelected); } \
  NS_IMETHOD GetSelectedOrParentTableElement(nsAString & aTagName, int32_t *aCount, nsIDOMElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedOrParentTableElement(aTagName, aCount, _retval); } \
  NS_IMETHOD GetSelectedCellsType(nsIDOMElement *aElement, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedCellsType(aElement, _retval); } \
  NS_IMETHOD GetFirstSelectedCell(nsIDOMRange * *aRange, nsIDOMElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFirstSelectedCell(aRange, _retval); } \
  NS_IMETHOD GetFirstSelectedCellInTable(int32_t *aRowIndex, int32_t *aColIndex, nsIDOMElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFirstSelectedCellInTable(aRowIndex, aColIndex, _retval); } \
  NS_IMETHOD GetNextSelectedCell(nsIDOMRange * *aRange, nsIDOMElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNextSelectedCell(aRange, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTableEditor : public nsITableEditor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITABLEEDITOR

  nsTableEditor();

private:
  ~nsTableEditor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTableEditor, nsITableEditor)

nsTableEditor::nsTableEditor()
{
  /* member initializers and constructor code */
}

nsTableEditor::~nsTableEditor()
{
  /* destructor code */
}

/* void insertTableCell (in long aNumber, in boolean aAfter); */
NS_IMETHODIMP nsTableEditor::InsertTableCell(int32_t aNumber, bool aAfter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertTableColumn (in long aNumber, in boolean aAfter); */
NS_IMETHODIMP nsTableEditor::InsertTableColumn(int32_t aNumber, bool aAfter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertTableRow (in long aNumber, in boolean aAfter); */
NS_IMETHODIMP nsTableEditor::InsertTableRow(int32_t aNumber, bool aAfter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteTable (); */
NS_IMETHODIMP nsTableEditor::DeleteTable()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteTableCellContents (); */
NS_IMETHODIMP nsTableEditor::DeleteTableCellContents()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteTableCell (in long aNumber); */
NS_IMETHODIMP nsTableEditor::DeleteTableCell(int32_t aNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteTableColumn (in long aNumber); */
NS_IMETHODIMP nsTableEditor::DeleteTableColumn(int32_t aNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteTableRow (in long aNumber); */
NS_IMETHODIMP nsTableEditor::DeleteTableRow(int32_t aNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectTableCell (); */
NS_IMETHODIMP nsTableEditor::SelectTableCell()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectBlockOfCells (in nsIDOMElement aStartCell, in nsIDOMElement aEndCell); */
NS_IMETHODIMP nsTableEditor::SelectBlockOfCells(nsIDOMElement *aStartCell, nsIDOMElement *aEndCell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectTableRow (); */
NS_IMETHODIMP nsTableEditor::SelectTableRow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectTableColumn (); */
NS_IMETHODIMP nsTableEditor::SelectTableColumn()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectTable (); */
NS_IMETHODIMP nsTableEditor::SelectTable()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectAllTableCells (); */
NS_IMETHODIMP nsTableEditor::SelectAllTableCells()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement switchTableCellHeaderType (in nsIDOMElement aSourceCell); */
NS_IMETHODIMP nsTableEditor::SwitchTableCellHeaderType(nsIDOMElement *aSourceCell, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void joinTableCells (in boolean aMergeNonContiguousContents); */
NS_IMETHODIMP nsTableEditor::JoinTableCells(bool aMergeNonContiguousContents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void splitTableCell (); */
NS_IMETHODIMP nsTableEditor::SplitTableCell()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void normalizeTable (in nsIDOMElement aTable); */
NS_IMETHODIMP nsTableEditor::NormalizeTable(nsIDOMElement *aTable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCellIndexes (in nsIDOMElement aCell, out long aRowIndex, out long aColIndex); */
NS_IMETHODIMP nsTableEditor::GetCellIndexes(nsIDOMElement *aCell, int32_t *aRowIndex, int32_t *aColIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getTableSize (in nsIDOMElement aTable, out long aRowCount, out long aColCount); */
NS_IMETHODIMP nsTableEditor::GetTableSize(nsIDOMElement *aTable, int32_t *aRowCount, int32_t *aColCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getCellAt (in nsIDOMElement aTable, in long aRowIndex, in long aColIndex); */
NS_IMETHODIMP nsTableEditor::GetCellAt(nsIDOMElement *aTable, int32_t aRowIndex, int32_t aColIndex, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCellDataAt (in nsIDOMElement aTable, in long aRowIndex, in long aColIndex, out nsIDOMElement aCell, out long aStartRowIndex, out long aStartColIndex, out long aRowSpan, out long aColSpan, out long aActualRowSpan, out long aActualColSpan, out boolean aIsSelected); */
NS_IMETHODIMP nsTableEditor::GetCellDataAt(nsIDOMElement *aTable, int32_t aRowIndex, int32_t aColIndex, nsIDOMElement * *aCell, int32_t *aStartRowIndex, int32_t *aStartColIndex, int32_t *aRowSpan, int32_t *aColSpan, int32_t *aActualRowSpan, int32_t *aActualColSpan, bool *aIsSelected)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode getFirstRow (in nsIDOMElement aTableElement); */
NS_IMETHODIMP nsTableEditor::GetFirstRow(nsIDOMElement *aTableElement, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode getNextRow (in nsIDOMNode aTableElement); */
NS_IMETHODIMP nsTableEditor::GetNextRow(nsIDOMNode *aTableElement, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSelectionAfterTableEdit (in nsIDOMElement aTable, in long aRow, in long aCol, in long aDirection, in boolean aSelected); */
NS_IMETHODIMP nsTableEditor::SetSelectionAfterTableEdit(nsIDOMElement *aTable, int32_t aRow, int32_t aCol, int32_t aDirection, bool aSelected)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getSelectedOrParentTableElement (out AString aTagName, out long aCount); */
NS_IMETHODIMP nsTableEditor::GetSelectedOrParentTableElement(nsAString & aTagName, int32_t *aCount, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* uint32_t getSelectedCellsType (in nsIDOMElement aElement); */
NS_IMETHODIMP nsTableEditor::GetSelectedCellsType(nsIDOMElement *aElement, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getFirstSelectedCell (out nsIDOMRange aRange); */
NS_IMETHODIMP nsTableEditor::GetFirstSelectedCell(nsIDOMRange * *aRange, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getFirstSelectedCellInTable (out long aRowIndex, out long aColIndex); */
NS_IMETHODIMP nsTableEditor::GetFirstSelectedCellInTable(int32_t *aRowIndex, int32_t *aColIndex, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getNextSelectedCell (out nsIDOMRange aRange); */
NS_IMETHODIMP nsTableEditor::GetNextSelectedCell(nsIDOMRange * *aRange, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITableEditor_h__ */

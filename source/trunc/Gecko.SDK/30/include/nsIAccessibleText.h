/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAccessibleText.idl
 */

#ifndef __gen_nsIAccessibleText_h__
#define __gen_nsIAccessibleText_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
typedef int32_t  AccessibleTextBoundary;

class nsIAccessible; /* forward declaration */

class nsIArray; /* forward declaration */

class nsIPersistentProperties; /* forward declaration */

class nsIAccessibleTextRange; /* forward declaration */


/* starting interface:    nsIAccessibleText */
#define NS_IACCESSIBLETEXT_IID_STR "88789f40-54c9-494a-846d-3acaaf4cf46a"

#define NS_IACCESSIBLETEXT_IID \
  {0x88789f40, 0x54c9, 0x494a, \
    { 0x84, 0x6d, 0x3a, 0xca, 0xaf, 0x4c, 0xf4, 0x6a }}

class NS_NO_VTABLE nsIAccessibleText : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLETEXT_IID)

  enum {
    TEXT_OFFSET_END_OF_TEXT = -1,
    TEXT_OFFSET_CARET = -2,
    BOUNDARY_CHAR = 0,
    BOUNDARY_WORD_START = 1,
    BOUNDARY_WORD_END = 2,
    BOUNDARY_SENTENCE_START = 3,
    BOUNDARY_SENTENCE_END = 4,
    BOUNDARY_LINE_START = 5,
    BOUNDARY_LINE_END = 6
  };

  /* [binaryname(ScriptableCaretOffset)] attribute long caretOffset; */
  NS_IMETHOD GetScriptableCaretOffset(int32_t *aCaretOffset) = 0;
  NS_IMETHOD SetScriptableCaretOffset(int32_t aCaretOffset) = 0;

  /* readonly attribute long characterCount; */
  NS_IMETHOD GetCharacterCount(int32_t *aCharacterCount) = 0;

  /* readonly attribute long selectionCount; */
  NS_IMETHOD GetSelectionCount(int32_t *aSelectionCount) = 0;

  /* AString getText (in long startOffset, in long endOffset); */
  NS_IMETHOD GetText(int32_t startOffset, int32_t endOffset, nsAString & _retval) = 0;

  /* AString getTextAfterOffset (in long offset, in AccessibleTextBoundary boundaryType, out long startOffset, out long endOffset); */
  NS_IMETHOD GetTextAfterOffset(int32_t offset, AccessibleTextBoundary boundaryType, int32_t *startOffset, int32_t *endOffset, nsAString & _retval) = 0;

  /* AString getTextAtOffset (in long offset, in AccessibleTextBoundary boundaryType, out long startOffset, out long endOffset); */
  NS_IMETHOD GetTextAtOffset(int32_t offset, AccessibleTextBoundary boundaryType, int32_t *startOffset, int32_t *endOffset, nsAString & _retval) = 0;

  /* AString getTextBeforeOffset (in long offset, in AccessibleTextBoundary boundaryType, out long startOffset, out long endOffset); */
  NS_IMETHOD GetTextBeforeOffset(int32_t offset, AccessibleTextBoundary boundaryType, int32_t *startOffset, int32_t *endOffset, nsAString & _retval) = 0;

  /* wchar getCharacterAtOffset (in long offset); */
  NS_IMETHOD GetCharacterAtOffset(int32_t offset, char16_t *_retval) = 0;

  /* nsIPersistentProperties getTextAttributes (in boolean includeDefAttrs, in long offset, out long rangeStartOffset, out long rangeEndOffset); */
  NS_IMETHOD GetTextAttributes(bool includeDefAttrs, int32_t offset, int32_t *rangeStartOffset, int32_t *rangeEndOffset, nsIPersistentProperties * *_retval) = 0;

  /* readonly attribute nsIPersistentProperties defaultTextAttributes; */
  NS_IMETHOD GetDefaultTextAttributes(nsIPersistentProperties * *aDefaultTextAttributes) = 0;

  /* void getCharacterExtents (in long offset, out long x, out long y, out long width, out long height, in unsigned long coordType); */
  NS_IMETHOD GetCharacterExtents(int32_t offset, int32_t *x, int32_t *y, int32_t *width, int32_t *height, uint32_t coordType) = 0;

  /* void getRangeExtents (in long startOffset, in long endOffset, out long x, out long y, out long width, out long height, in unsigned long coordType); */
  NS_IMETHOD GetRangeExtents(int32_t startOffset, int32_t endOffset, int32_t *x, int32_t *y, int32_t *width, int32_t *height, uint32_t coordType) = 0;

  /* long getOffsetAtPoint (in long x, in long y, in unsigned long coordType); */
  NS_IMETHOD GetOffsetAtPoint(int32_t x, int32_t y, uint32_t coordType, int32_t *_retval) = 0;

  /* void getSelectionBounds (in long selectionNum, out long startOffset, out long endOffset); */
  NS_IMETHOD GetSelectionBounds(int32_t selectionNum, int32_t *startOffset, int32_t *endOffset) = 0;

  /* void setSelectionBounds (in long selectionNum, in long startOffset, in long endOffset); */
  NS_IMETHOD SetSelectionBounds(int32_t selectionNum, int32_t startOffset, int32_t endOffset) = 0;

  /* void addSelection (in long startOffset, in long endOffset); */
  NS_IMETHOD AddSelection(int32_t startOffset, int32_t endOffset) = 0;

  /* void removeSelection (in long selectionNum); */
  NS_IMETHOD RemoveSelection(int32_t selectionNum) = 0;

  /* [binaryname(ScriptableScrollSubstringTo)] void scrollSubstringTo (in long startIndex, in long endIndex, in unsigned long scrollType); */
  NS_IMETHOD ScriptableScrollSubstringTo(int32_t startIndex, int32_t endIndex, uint32_t scrollType) = 0;

  /* [binaryname(ScriptableScrollSubstringToPoint)] void scrollSubstringToPoint (in long startIndex, in long endIndex, in unsigned long coordinateType, in long x, in long y); */
  NS_IMETHOD ScriptableScrollSubstringToPoint(int32_t startIndex, int32_t endIndex, uint32_t coordinateType, int32_t x, int32_t y) = 0;

  /* readonly attribute nsIAccessibleTextRange enclosingRange; */
  NS_IMETHOD GetEnclosingRange(nsIAccessibleTextRange * *aEnclosingRange) = 0;

  /* readonly attribute nsIArray selectionRanges; */
  NS_IMETHOD GetSelectionRanges(nsIArray * *aSelectionRanges) = 0;

  /* readonly attribute nsIArray visibleRanges; */
  NS_IMETHOD GetVisibleRanges(nsIArray * *aVisibleRanges) = 0;

  /* nsIAccessibleTextRange getRangeByChild (in nsIAccessible child); */
  NS_IMETHOD GetRangeByChild(nsIAccessible *child, nsIAccessibleTextRange * *_retval) = 0;

  /* nsIAccessibleTextRange getRangeAtPoint (in long x, in long y); */
  NS_IMETHOD GetRangeAtPoint(int32_t x, int32_t y, nsIAccessibleTextRange * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleText, NS_IACCESSIBLETEXT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLETEXT \
  NS_IMETHOD GetScriptableCaretOffset(int32_t *aCaretOffset); \
  NS_IMETHOD SetScriptableCaretOffset(int32_t aCaretOffset); \
  NS_IMETHOD GetCharacterCount(int32_t *aCharacterCount); \
  NS_IMETHOD GetSelectionCount(int32_t *aSelectionCount); \
  NS_IMETHOD GetText(int32_t startOffset, int32_t endOffset, nsAString & _retval); \
  NS_IMETHOD GetTextAfterOffset(int32_t offset, AccessibleTextBoundary boundaryType, int32_t *startOffset, int32_t *endOffset, nsAString & _retval); \
  NS_IMETHOD GetTextAtOffset(int32_t offset, AccessibleTextBoundary boundaryType, int32_t *startOffset, int32_t *endOffset, nsAString & _retval); \
  NS_IMETHOD GetTextBeforeOffset(int32_t offset, AccessibleTextBoundary boundaryType, int32_t *startOffset, int32_t *endOffset, nsAString & _retval); \
  NS_IMETHOD GetCharacterAtOffset(int32_t offset, char16_t *_retval); \
  NS_IMETHOD GetTextAttributes(bool includeDefAttrs, int32_t offset, int32_t *rangeStartOffset, int32_t *rangeEndOffset, nsIPersistentProperties * *_retval); \
  NS_IMETHOD GetDefaultTextAttributes(nsIPersistentProperties * *aDefaultTextAttributes); \
  NS_IMETHOD GetCharacterExtents(int32_t offset, int32_t *x, int32_t *y, int32_t *width, int32_t *height, uint32_t coordType); \
  NS_IMETHOD GetRangeExtents(int32_t startOffset, int32_t endOffset, int32_t *x, int32_t *y, int32_t *width, int32_t *height, uint32_t coordType); \
  NS_IMETHOD GetOffsetAtPoint(int32_t x, int32_t y, uint32_t coordType, int32_t *_retval); \
  NS_IMETHOD GetSelectionBounds(int32_t selectionNum, int32_t *startOffset, int32_t *endOffset); \
  NS_IMETHOD SetSelectionBounds(int32_t selectionNum, int32_t startOffset, int32_t endOffset); \
  NS_IMETHOD AddSelection(int32_t startOffset, int32_t endOffset); \
  NS_IMETHOD RemoveSelection(int32_t selectionNum); \
  NS_IMETHOD ScriptableScrollSubstringTo(int32_t startIndex, int32_t endIndex, uint32_t scrollType); \
  NS_IMETHOD ScriptableScrollSubstringToPoint(int32_t startIndex, int32_t endIndex, uint32_t coordinateType, int32_t x, int32_t y); \
  NS_IMETHOD GetEnclosingRange(nsIAccessibleTextRange * *aEnclosingRange); \
  NS_IMETHOD GetSelectionRanges(nsIArray * *aSelectionRanges); \
  NS_IMETHOD GetVisibleRanges(nsIArray * *aVisibleRanges); \
  NS_IMETHOD GetRangeByChild(nsIAccessible *child, nsIAccessibleTextRange * *_retval); \
  NS_IMETHOD GetRangeAtPoint(int32_t x, int32_t y, nsIAccessibleTextRange * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLETEXT(_to) \
  NS_IMETHOD GetScriptableCaretOffset(int32_t *aCaretOffset) { return _to GetScriptableCaretOffset(aCaretOffset); } \
  NS_IMETHOD SetScriptableCaretOffset(int32_t aCaretOffset) { return _to SetScriptableCaretOffset(aCaretOffset); } \
  NS_IMETHOD GetCharacterCount(int32_t *aCharacterCount) { return _to GetCharacterCount(aCharacterCount); } \
  NS_IMETHOD GetSelectionCount(int32_t *aSelectionCount) { return _to GetSelectionCount(aSelectionCount); } \
  NS_IMETHOD GetText(int32_t startOffset, int32_t endOffset, nsAString & _retval) { return _to GetText(startOffset, endOffset, _retval); } \
  NS_IMETHOD GetTextAfterOffset(int32_t offset, AccessibleTextBoundary boundaryType, int32_t *startOffset, int32_t *endOffset, nsAString & _retval) { return _to GetTextAfterOffset(offset, boundaryType, startOffset, endOffset, _retval); } \
  NS_IMETHOD GetTextAtOffset(int32_t offset, AccessibleTextBoundary boundaryType, int32_t *startOffset, int32_t *endOffset, nsAString & _retval) { return _to GetTextAtOffset(offset, boundaryType, startOffset, endOffset, _retval); } \
  NS_IMETHOD GetTextBeforeOffset(int32_t offset, AccessibleTextBoundary boundaryType, int32_t *startOffset, int32_t *endOffset, nsAString & _retval) { return _to GetTextBeforeOffset(offset, boundaryType, startOffset, endOffset, _retval); } \
  NS_IMETHOD GetCharacterAtOffset(int32_t offset, char16_t *_retval) { return _to GetCharacterAtOffset(offset, _retval); } \
  NS_IMETHOD GetTextAttributes(bool includeDefAttrs, int32_t offset, int32_t *rangeStartOffset, int32_t *rangeEndOffset, nsIPersistentProperties * *_retval) { return _to GetTextAttributes(includeDefAttrs, offset, rangeStartOffset, rangeEndOffset, _retval); } \
  NS_IMETHOD GetDefaultTextAttributes(nsIPersistentProperties * *aDefaultTextAttributes) { return _to GetDefaultTextAttributes(aDefaultTextAttributes); } \
  NS_IMETHOD GetCharacterExtents(int32_t offset, int32_t *x, int32_t *y, int32_t *width, int32_t *height, uint32_t coordType) { return _to GetCharacterExtents(offset, x, y, width, height, coordType); } \
  NS_IMETHOD GetRangeExtents(int32_t startOffset, int32_t endOffset, int32_t *x, int32_t *y, int32_t *width, int32_t *height, uint32_t coordType) { return _to GetRangeExtents(startOffset, endOffset, x, y, width, height, coordType); } \
  NS_IMETHOD GetOffsetAtPoint(int32_t x, int32_t y, uint32_t coordType, int32_t *_retval) { return _to GetOffsetAtPoint(x, y, coordType, _retval); } \
  NS_IMETHOD GetSelectionBounds(int32_t selectionNum, int32_t *startOffset, int32_t *endOffset) { return _to GetSelectionBounds(selectionNum, startOffset, endOffset); } \
  NS_IMETHOD SetSelectionBounds(int32_t selectionNum, int32_t startOffset, int32_t endOffset) { return _to SetSelectionBounds(selectionNum, startOffset, endOffset); } \
  NS_IMETHOD AddSelection(int32_t startOffset, int32_t endOffset) { return _to AddSelection(startOffset, endOffset); } \
  NS_IMETHOD RemoveSelection(int32_t selectionNum) { return _to RemoveSelection(selectionNum); } \
  NS_IMETHOD ScriptableScrollSubstringTo(int32_t startIndex, int32_t endIndex, uint32_t scrollType) { return _to ScriptableScrollSubstringTo(startIndex, endIndex, scrollType); } \
  NS_IMETHOD ScriptableScrollSubstringToPoint(int32_t startIndex, int32_t endIndex, uint32_t coordinateType, int32_t x, int32_t y) { return _to ScriptableScrollSubstringToPoint(startIndex, endIndex, coordinateType, x, y); } \
  NS_IMETHOD GetEnclosingRange(nsIAccessibleTextRange * *aEnclosingRange) { return _to GetEnclosingRange(aEnclosingRange); } \
  NS_IMETHOD GetSelectionRanges(nsIArray * *aSelectionRanges) { return _to GetSelectionRanges(aSelectionRanges); } \
  NS_IMETHOD GetVisibleRanges(nsIArray * *aVisibleRanges) { return _to GetVisibleRanges(aVisibleRanges); } \
  NS_IMETHOD GetRangeByChild(nsIAccessible *child, nsIAccessibleTextRange * *_retval) { return _to GetRangeByChild(child, _retval); } \
  NS_IMETHOD GetRangeAtPoint(int32_t x, int32_t y, nsIAccessibleTextRange * *_retval) { return _to GetRangeAtPoint(x, y, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLETEXT(_to) \
  NS_IMETHOD GetScriptableCaretOffset(int32_t *aCaretOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScriptableCaretOffset(aCaretOffset); } \
  NS_IMETHOD SetScriptableCaretOffset(int32_t aCaretOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScriptableCaretOffset(aCaretOffset); } \
  NS_IMETHOD GetCharacterCount(int32_t *aCharacterCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharacterCount(aCharacterCount); } \
  NS_IMETHOD GetSelectionCount(int32_t *aSelectionCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionCount(aSelectionCount); } \
  NS_IMETHOD GetText(int32_t startOffset, int32_t endOffset, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetText(startOffset, endOffset, _retval); } \
  NS_IMETHOD GetTextAfterOffset(int32_t offset, AccessibleTextBoundary boundaryType, int32_t *startOffset, int32_t *endOffset, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextAfterOffset(offset, boundaryType, startOffset, endOffset, _retval); } \
  NS_IMETHOD GetTextAtOffset(int32_t offset, AccessibleTextBoundary boundaryType, int32_t *startOffset, int32_t *endOffset, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextAtOffset(offset, boundaryType, startOffset, endOffset, _retval); } \
  NS_IMETHOD GetTextBeforeOffset(int32_t offset, AccessibleTextBoundary boundaryType, int32_t *startOffset, int32_t *endOffset, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextBeforeOffset(offset, boundaryType, startOffset, endOffset, _retval); } \
  NS_IMETHOD GetCharacterAtOffset(int32_t offset, char16_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharacterAtOffset(offset, _retval); } \
  NS_IMETHOD GetTextAttributes(bool includeDefAttrs, int32_t offset, int32_t *rangeStartOffset, int32_t *rangeEndOffset, nsIPersistentProperties * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextAttributes(includeDefAttrs, offset, rangeStartOffset, rangeEndOffset, _retval); } \
  NS_IMETHOD GetDefaultTextAttributes(nsIPersistentProperties * *aDefaultTextAttributes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultTextAttributes(aDefaultTextAttributes); } \
  NS_IMETHOD GetCharacterExtents(int32_t offset, int32_t *x, int32_t *y, int32_t *width, int32_t *height, uint32_t coordType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharacterExtents(offset, x, y, width, height, coordType); } \
  NS_IMETHOD GetRangeExtents(int32_t startOffset, int32_t endOffset, int32_t *x, int32_t *y, int32_t *width, int32_t *height, uint32_t coordType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRangeExtents(startOffset, endOffset, x, y, width, height, coordType); } \
  NS_IMETHOD GetOffsetAtPoint(int32_t x, int32_t y, uint32_t coordType, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffsetAtPoint(x, y, coordType, _retval); } \
  NS_IMETHOD GetSelectionBounds(int32_t selectionNum, int32_t *startOffset, int32_t *endOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionBounds(selectionNum, startOffset, endOffset); } \
  NS_IMETHOD SetSelectionBounds(int32_t selectionNum, int32_t startOffset, int32_t endOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectionBounds(selectionNum, startOffset, endOffset); } \
  NS_IMETHOD AddSelection(int32_t startOffset, int32_t endOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddSelection(startOffset, endOffset); } \
  NS_IMETHOD RemoveSelection(int32_t selectionNum) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveSelection(selectionNum); } \
  NS_IMETHOD ScriptableScrollSubstringTo(int32_t startIndex, int32_t endIndex, uint32_t scrollType) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScriptableScrollSubstringTo(startIndex, endIndex, scrollType); } \
  NS_IMETHOD ScriptableScrollSubstringToPoint(int32_t startIndex, int32_t endIndex, uint32_t coordinateType, int32_t x, int32_t y) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScriptableScrollSubstringToPoint(startIndex, endIndex, coordinateType, x, y); } \
  NS_IMETHOD GetEnclosingRange(nsIAccessibleTextRange * *aEnclosingRange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnclosingRange(aEnclosingRange); } \
  NS_IMETHOD GetSelectionRanges(nsIArray * *aSelectionRanges) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionRanges(aSelectionRanges); } \
  NS_IMETHOD GetVisibleRanges(nsIArray * *aVisibleRanges) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisibleRanges(aVisibleRanges); } \
  NS_IMETHOD GetRangeByChild(nsIAccessible *child, nsIAccessibleTextRange * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRangeByChild(child, _retval); } \
  NS_IMETHOD GetRangeAtPoint(int32_t x, int32_t y, nsIAccessibleTextRange * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRangeAtPoint(x, y, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleText : public nsIAccessibleText
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLETEXT

  nsAccessibleText();

private:
  ~nsAccessibleText();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleText, nsIAccessibleText)

nsAccessibleText::nsAccessibleText()
{
  /* member initializers and constructor code */
}

nsAccessibleText::~nsAccessibleText()
{
  /* destructor code */
}

/* [binaryname(ScriptableCaretOffset)] attribute long caretOffset; */
NS_IMETHODIMP nsAccessibleText::GetScriptableCaretOffset(int32_t *aCaretOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAccessibleText::SetScriptableCaretOffset(int32_t aCaretOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long characterCount; */
NS_IMETHODIMP nsAccessibleText::GetCharacterCount(int32_t *aCharacterCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long selectionCount; */
NS_IMETHODIMP nsAccessibleText::GetSelectionCount(int32_t *aSelectionCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getText (in long startOffset, in long endOffset); */
NS_IMETHODIMP nsAccessibleText::GetText(int32_t startOffset, int32_t endOffset, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getTextAfterOffset (in long offset, in AccessibleTextBoundary boundaryType, out long startOffset, out long endOffset); */
NS_IMETHODIMP nsAccessibleText::GetTextAfterOffset(int32_t offset, AccessibleTextBoundary boundaryType, int32_t *startOffset, int32_t *endOffset, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getTextAtOffset (in long offset, in AccessibleTextBoundary boundaryType, out long startOffset, out long endOffset); */
NS_IMETHODIMP nsAccessibleText::GetTextAtOffset(int32_t offset, AccessibleTextBoundary boundaryType, int32_t *startOffset, int32_t *endOffset, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getTextBeforeOffset (in long offset, in AccessibleTextBoundary boundaryType, out long startOffset, out long endOffset); */
NS_IMETHODIMP nsAccessibleText::GetTextBeforeOffset(int32_t offset, AccessibleTextBoundary boundaryType, int32_t *startOffset, int32_t *endOffset, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wchar getCharacterAtOffset (in long offset); */
NS_IMETHODIMP nsAccessibleText::GetCharacterAtOffset(int32_t offset, char16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPersistentProperties getTextAttributes (in boolean includeDefAttrs, in long offset, out long rangeStartOffset, out long rangeEndOffset); */
NS_IMETHODIMP nsAccessibleText::GetTextAttributes(bool includeDefAttrs, int32_t offset, int32_t *rangeStartOffset, int32_t *rangeEndOffset, nsIPersistentProperties * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIPersistentProperties defaultTextAttributes; */
NS_IMETHODIMP nsAccessibleText::GetDefaultTextAttributes(nsIPersistentProperties * *aDefaultTextAttributes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCharacterExtents (in long offset, out long x, out long y, out long width, out long height, in unsigned long coordType); */
NS_IMETHODIMP nsAccessibleText::GetCharacterExtents(int32_t offset, int32_t *x, int32_t *y, int32_t *width, int32_t *height, uint32_t coordType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getRangeExtents (in long startOffset, in long endOffset, out long x, out long y, out long width, out long height, in unsigned long coordType); */
NS_IMETHODIMP nsAccessibleText::GetRangeExtents(int32_t startOffset, int32_t endOffset, int32_t *x, int32_t *y, int32_t *width, int32_t *height, uint32_t coordType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getOffsetAtPoint (in long x, in long y, in unsigned long coordType); */
NS_IMETHODIMP nsAccessibleText::GetOffsetAtPoint(int32_t x, int32_t y, uint32_t coordType, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSelectionBounds (in long selectionNum, out long startOffset, out long endOffset); */
NS_IMETHODIMP nsAccessibleText::GetSelectionBounds(int32_t selectionNum, int32_t *startOffset, int32_t *endOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSelectionBounds (in long selectionNum, in long startOffset, in long endOffset); */
NS_IMETHODIMP nsAccessibleText::SetSelectionBounds(int32_t selectionNum, int32_t startOffset, int32_t endOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addSelection (in long startOffset, in long endOffset); */
NS_IMETHODIMP nsAccessibleText::AddSelection(int32_t startOffset, int32_t endOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeSelection (in long selectionNum); */
NS_IMETHODIMP nsAccessibleText::RemoveSelection(int32_t selectionNum)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(ScriptableScrollSubstringTo)] void scrollSubstringTo (in long startIndex, in long endIndex, in unsigned long scrollType); */
NS_IMETHODIMP nsAccessibleText::ScriptableScrollSubstringTo(int32_t startIndex, int32_t endIndex, uint32_t scrollType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(ScriptableScrollSubstringToPoint)] void scrollSubstringToPoint (in long startIndex, in long endIndex, in unsigned long coordinateType, in long x, in long y); */
NS_IMETHODIMP nsAccessibleText::ScriptableScrollSubstringToPoint(int32_t startIndex, int32_t endIndex, uint32_t coordinateType, int32_t x, int32_t y)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessibleTextRange enclosingRange; */
NS_IMETHODIMP nsAccessibleText::GetEnclosingRange(nsIAccessibleTextRange * *aEnclosingRange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIArray selectionRanges; */
NS_IMETHODIMP nsAccessibleText::GetSelectionRanges(nsIArray * *aSelectionRanges)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIArray visibleRanges; */
NS_IMETHODIMP nsAccessibleText::GetVisibleRanges(nsIArray * *aVisibleRanges)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessibleTextRange getRangeByChild (in nsIAccessible child); */
NS_IMETHODIMP nsAccessibleText::GetRangeByChild(nsIAccessible *child, nsIAccessibleTextRange * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessibleTextRange getRangeAtPoint (in long x, in long y); */
NS_IMETHODIMP nsAccessibleText::GetRangeAtPoint(int32_t x, int32_t y, nsIAccessibleTextRange * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleText_h__ */

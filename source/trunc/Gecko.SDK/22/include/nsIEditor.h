/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/editor/idl/nsIEditor.idl
 */

#ifndef __gen_nsIEditor_h__
#define __gen_nsIEditor_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIAtom; /* forward declaration */

class nsIContent; /* forward declaration */

class nsISelection; /* forward declaration */

class nsISelectionController; /* forward declaration */

class nsIDocumentStateListener; /* forward declaration */

class nsIOutputStream; /* forward declaration */

class nsITransactionManager; /* forward declaration */

class nsITransaction; /* forward declaration */

class nsIEditorObserver; /* forward declaration */

class nsIEditActionListener; /* forward declaration */

class nsIInlineSpellChecker; /* forward declaration */

class nsITransferable; /* forward declaration */


/* starting interface:    nsIEditor */
#define NS_IEDITOR_IID_STR "753b38d1-ee03-4e58-a650-1076ccccdb7f"

#define NS_IEDITOR_IID \
  {0x753b38d1, 0xee03, 0x4e58, \
    { 0xa6, 0x50, 0x10, 0x76, 0xcc, 0xcc, 0xdb, 0x7f }}

class nsIEditor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEDITOR_IID)

   typedef short EDirection;
  typedef short EStripWrappers;
  enum {
    eNone = 0,
    eNext = 1,
    ePrevious = 2,
    eNextWord = 3,
    ePreviousWord = 4,
    eToBeginningOfLine = 5,
    eToEndOfLine = 6,
    eStrip = 0,
    eNoStrip = 1
  };

  /* readonly attribute nsISelection selection; */
  NS_IMETHOD GetSelection(nsISelection * *aSelection) = 0;

  /* [noscript] void init (in nsIDOMDocument doc, in nsIContent aRoot, in nsISelectionController aSelCon, in unsigned long aFlags); */
  NS_IMETHOD Init(nsIDOMDocument *doc, nsIContent *aRoot, nsISelectionController *aSelCon, uint32_t aFlags) = 0;

  /* void setAttributeOrEquivalent (in nsIDOMElement element, in AString sourceAttrName, in AString sourceAttrValue, in boolean aSuppressTransaction); */
  NS_IMETHOD SetAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, const nsAString & sourceAttrValue, bool aSuppressTransaction) = 0;

  /* void removeAttributeOrEquivalent (in nsIDOMElement element, in DOMString sourceAttrName, in boolean aSuppressTransaction); */
  NS_IMETHOD RemoveAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, bool aSuppressTransaction) = 0;

  /* void postCreate (); */
  NS_IMETHOD PostCreate(void) = 0;

  /* void preDestroy (in boolean aDestroyingFrames); */
  NS_IMETHOD PreDestroy(bool aDestroyingFrames) = 0;

  /* attribute unsigned long flags; */
  NS_IMETHOD GetFlags(uint32_t *aFlags) = 0;
  NS_IMETHOD SetFlags(uint32_t aFlags) = 0;

  /* attribute string contentsMIMEType; */
  NS_IMETHOD GetContentsMIMEType(char * *aContentsMIMEType) = 0;
  NS_IMETHOD SetContentsMIMEType(const char * aContentsMIMEType) = 0;

  /* readonly attribute boolean isDocumentEditable; */
  NS_IMETHOD GetIsDocumentEditable(bool *aIsDocumentEditable) = 0;

  /* readonly attribute boolean isSelectionEditable; */
  NS_IMETHOD GetIsSelectionEditable(bool *aIsSelectionEditable) = 0;

  /* readonly attribute nsIDOMDocument document; */
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) = 0;

  /* readonly attribute nsIDOMElement rootElement; */
  NS_IMETHOD GetRootElement(nsIDOMElement * *aRootElement) = 0;

  /* readonly attribute nsISelectionController selectionController; */
  NS_IMETHOD GetSelectionController(nsISelectionController * *aSelectionController) = 0;

  /* void deleteSelection (in short action, in short stripWrappers); */
  NS_IMETHOD DeleteSelection(int16_t action, int16_t stripWrappers) = 0;

  /* readonly attribute boolean documentIsEmpty; */
  NS_IMETHOD GetDocumentIsEmpty(bool *aDocumentIsEmpty) = 0;

  /* readonly attribute boolean documentModified; */
  NS_IMETHOD GetDocumentModified(bool *aDocumentModified) = 0;

  /* attribute ACString documentCharacterSet; */
  NS_IMETHOD GetDocumentCharacterSet(nsACString & aDocumentCharacterSet) = 0;
  NS_IMETHOD SetDocumentCharacterSet(const nsACString & aDocumentCharacterSet) = 0;

  /* void resetModificationCount (); */
  NS_IMETHOD ResetModificationCount(void) = 0;

  /* long getModificationCount (); */
  NS_IMETHOD GetModificationCount(int32_t *_retval) = 0;

  /* void incrementModificationCount (in long aModCount); */
  NS_IMETHOD IncrementModificationCount(int32_t aModCount) = 0;

  /* attribute nsITransactionManager transactionManager; */
  NS_IMETHOD GetTransactionManager(nsITransactionManager * *aTransactionManager) = 0;
  NS_IMETHOD SetTransactionManager(nsITransactionManager *aTransactionManager) = 0;

  /* void doTransaction (in nsITransaction txn); */
  NS_IMETHOD DoTransaction(nsITransaction *txn) = 0;

  /* void enableUndo (in boolean enable); */
  NS_IMETHOD EnableUndo(bool enable) = 0;

  /* readonly attribute long numberOfUndoItems; */
  NS_IMETHOD GetNumberOfUndoItems(int32_t *aNumberOfUndoItems) = 0;

  /* readonly attribute long numberOfRedoItems; */
  NS_IMETHOD GetNumberOfRedoItems(int32_t *aNumberOfRedoItems) = 0;

  /* void undo (in unsigned long count); */
  NS_IMETHOD Undo(uint32_t count) = 0;

  /* void canUndo (out boolean isEnabled, out boolean canUndo); */
  NS_IMETHOD CanUndo(bool *isEnabled, bool *canUndo) = 0;

  /* void redo (in unsigned long count); */
  NS_IMETHOD Redo(uint32_t count) = 0;

  /* void canRedo (out boolean isEnabled, out boolean canRedo); */
  NS_IMETHOD CanRedo(bool *isEnabled, bool *canRedo) = 0;

  /* void beginTransaction (); */
  NS_IMETHOD BeginTransaction(void) = 0;

  /* void endTransaction (); */
  NS_IMETHOD EndTransaction(void) = 0;

  /* void beginPlaceHolderTransaction (in nsIAtom name); */
  NS_IMETHOD BeginPlaceHolderTransaction(nsIAtom *name) = 0;

  /* void endPlaceHolderTransaction (); */
  NS_IMETHOD EndPlaceHolderTransaction(void) = 0;

  /* boolean shouldTxnSetSelection (); */
  NS_IMETHOD ShouldTxnSetSelection(bool *_retval) = 0;

  /* void setShouldTxnSetSelection (in boolean should); */
  NS_IMETHOD SetShouldTxnSetSelection(bool should) = 0;

  /* nsIInlineSpellChecker getInlineSpellChecker (in boolean autoCreate); */
  NS_IMETHOD GetInlineSpellChecker(bool autoCreate, nsIInlineSpellChecker * *_retval) = 0;

  /* void syncRealTimeSpell (); */
  NS_IMETHOD SyncRealTimeSpell(void) = 0;

  /* void setSpellcheckUserOverride (in boolean enable); */
  NS_IMETHOD SetSpellcheckUserOverride(bool enable) = 0;

  /* void cut (); */
  NS_IMETHOD Cut(void) = 0;

  /* boolean canCut (); */
  NS_IMETHOD CanCut(bool *_retval) = 0;

  /* void copy (); */
  NS_IMETHOD Copy(void) = 0;

  /* boolean canCopy (); */
  NS_IMETHOD CanCopy(bool *_retval) = 0;

  /* void paste (in long aSelectionType); */
  NS_IMETHOD Paste(int32_t aSelectionType) = 0;

  /* void pasteTransferable (in nsITransferable aTransferable); */
  NS_IMETHOD PasteTransferable(nsITransferable *aTransferable) = 0;

  /* boolean canPaste (in long aSelectionType); */
  NS_IMETHOD CanPaste(int32_t aSelectionType, bool *_retval) = 0;

  /* boolean canPasteTransferable ([optional] in nsITransferable aTransferable); */
  NS_IMETHOD CanPasteTransferable(nsITransferable *aTransferable, bool *_retval) = 0;

  /* void selectAll (); */
  NS_IMETHOD SelectAll(void) = 0;

  /* void beginningOfDocument (); */
  NS_IMETHOD BeginningOfDocument(void) = 0;

  /* void endOfDocument (); */
  NS_IMETHOD EndOfDocument(void) = 0;

  /* void setAttribute (in nsIDOMElement aElement, in AString attributestr, in AString attvalue); */
  NS_IMETHOD SetAttribute(nsIDOMElement *aElement, const nsAString & attributestr, const nsAString & attvalue) = 0;

  /* boolean getAttributeValue (in nsIDOMElement aElement, in AString attributestr, out AString resultValue); */
  NS_IMETHOD GetAttributeValue(nsIDOMElement *aElement, const nsAString & attributestr, nsAString & resultValue, bool *_retval) = 0;

  /* void removeAttribute (in nsIDOMElement aElement, in AString aAttribute); */
  NS_IMETHOD RemoveAttribute(nsIDOMElement *aElement, const nsAString & aAttribute) = 0;

  /* void cloneAttribute (in AString aAttribute, in nsIDOMNode aDestNode, in nsIDOMNode aSourceNode); */
  NS_IMETHOD CloneAttribute(const nsAString & aAttribute, nsIDOMNode *aDestNode, nsIDOMNode *aSourceNode) = 0;

  /* void cloneAttributes (in nsIDOMNode destNode, in nsIDOMNode sourceNode); */
  NS_IMETHOD CloneAttributes(nsIDOMNode *destNode, nsIDOMNode *sourceNode) = 0;

  /* nsIDOMNode createNode (in AString tag, in nsIDOMNode parent, in long position); */
  NS_IMETHOD CreateNode(const nsAString & tag, nsIDOMNode *parent, int32_t position, nsIDOMNode * *_retval) = 0;

  /* void insertNode (in nsIDOMNode node, in nsIDOMNode parent, in long aPosition); */
  NS_IMETHOD InsertNode(nsIDOMNode *node, nsIDOMNode *parent, int32_t aPosition) = 0;

  /* void splitNode (in nsIDOMNode existingRightNode, in long offset, out nsIDOMNode newLeftNode); */
  NS_IMETHOD SplitNode(nsIDOMNode *existingRightNode, int32_t offset, nsIDOMNode * *newLeftNode) = 0;

  /* void joinNodes (in nsIDOMNode leftNode, in nsIDOMNode rightNode, in nsIDOMNode parent); */
  NS_IMETHOD JoinNodes(nsIDOMNode *leftNode, nsIDOMNode *rightNode, nsIDOMNode *parent) = 0;

  /* void deleteNode (in nsIDOMNode child); */
  NS_IMETHOD DeleteNode(nsIDOMNode *child) = 0;

  /* [notxpcom] boolean outputsMozDirty (); */
  NS_IMETHOD_(bool) OutputsMozDirty(void) = 0;

  /* void markNodeDirty (in nsIDOMNode node); */
  NS_IMETHOD MarkNodeDirty(nsIDOMNode *node) = 0;

  /* void switchTextDirection (); */
  NS_IMETHOD SwitchTextDirection(void) = 0;

  /* AString outputToString (in AString formatType, in unsigned long flags); */
  NS_IMETHOD OutputToString(const nsAString & formatType, uint32_t flags, nsAString & _retval) = 0;

  /* void outputToStream (in nsIOutputStream aStream, in AString formatType, in ACString charsetOverride, in unsigned long flags); */
  NS_IMETHOD OutputToStream(nsIOutputStream *aStream, const nsAString & formatType, const nsACString & charsetOverride, uint32_t flags) = 0;

  /* void addEditorObserver (in nsIEditorObserver observer); */
  NS_IMETHOD AddEditorObserver(nsIEditorObserver *observer) = 0;

  /* void removeEditorObserver (in nsIEditorObserver observer); */
  NS_IMETHOD RemoveEditorObserver(nsIEditorObserver *observer) = 0;

  /* void addEditActionListener (in nsIEditActionListener listener); */
  NS_IMETHOD AddEditActionListener(nsIEditActionListener *listener) = 0;

  /* void removeEditActionListener (in nsIEditActionListener listener); */
  NS_IMETHOD RemoveEditActionListener(nsIEditActionListener *listener) = 0;

  /* void addDocumentStateListener (in nsIDocumentStateListener listener); */
  NS_IMETHOD AddDocumentStateListener(nsIDocumentStateListener *listener) = 0;

  /* void removeDocumentStateListener (in nsIDocumentStateListener listener); */
  NS_IMETHOD RemoveDocumentStateListener(nsIDocumentStateListener *listener) = 0;

  /* void dumpContentTree (); */
  NS_IMETHOD DumpContentTree(void) = 0;

  /* void debugDumpContent (); */
  NS_IMETHOD DebugDumpContent(void) = 0;

  /* void debugUnitTests (out long outNumTests, out long outNumTestsFailed); */
  NS_IMETHOD DebugUnitTests(int32_t *outNumTests, int32_t *outNumTestsFailed) = 0;

  /* [notxpcom] boolean isModifiableNode (in nsIDOMNode aNode); */
  NS_IMETHOD_(bool) IsModifiableNode(nsIDOMNode *aNode) = 0;

  /* attribute boolean suppressDispatchingInputEvent; */
  NS_IMETHOD GetSuppressDispatchingInputEvent(bool *aSuppressDispatchingInputEvent) = 0;
  NS_IMETHOD SetSuppressDispatchingInputEvent(bool aSuppressDispatchingInputEvent) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEditor, NS_IEDITOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEDITOR \
  NS_IMETHOD GetSelection(nsISelection * *aSelection); \
  NS_IMETHOD Init(nsIDOMDocument *doc, nsIContent *aRoot, nsISelectionController *aSelCon, uint32_t aFlags); \
  NS_IMETHOD SetAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, const nsAString & sourceAttrValue, bool aSuppressTransaction); \
  NS_IMETHOD RemoveAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, bool aSuppressTransaction); \
  NS_IMETHOD PostCreate(void); \
  NS_IMETHOD PreDestroy(bool aDestroyingFrames); \
  NS_IMETHOD GetFlags(uint32_t *aFlags); \
  NS_IMETHOD SetFlags(uint32_t aFlags); \
  NS_IMETHOD GetContentsMIMEType(char * *aContentsMIMEType); \
  NS_IMETHOD SetContentsMIMEType(const char * aContentsMIMEType); \
  NS_IMETHOD GetIsDocumentEditable(bool *aIsDocumentEditable); \
  NS_IMETHOD GetIsSelectionEditable(bool *aIsSelectionEditable); \
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument); \
  NS_IMETHOD GetRootElement(nsIDOMElement * *aRootElement); \
  NS_IMETHOD GetSelectionController(nsISelectionController * *aSelectionController); \
  NS_IMETHOD DeleteSelection(int16_t action, int16_t stripWrappers); \
  NS_IMETHOD GetDocumentIsEmpty(bool *aDocumentIsEmpty); \
  NS_IMETHOD GetDocumentModified(bool *aDocumentModified); \
  NS_IMETHOD GetDocumentCharacterSet(nsACString & aDocumentCharacterSet); \
  NS_IMETHOD SetDocumentCharacterSet(const nsACString & aDocumentCharacterSet); \
  NS_IMETHOD ResetModificationCount(void); \
  NS_IMETHOD GetModificationCount(int32_t *_retval); \
  NS_IMETHOD IncrementModificationCount(int32_t aModCount); \
  NS_IMETHOD GetTransactionManager(nsITransactionManager * *aTransactionManager); \
  NS_IMETHOD SetTransactionManager(nsITransactionManager *aTransactionManager); \
  NS_IMETHOD DoTransaction(nsITransaction *txn); \
  NS_IMETHOD EnableUndo(bool enable); \
  NS_IMETHOD GetNumberOfUndoItems(int32_t *aNumberOfUndoItems); \
  NS_IMETHOD GetNumberOfRedoItems(int32_t *aNumberOfRedoItems); \
  NS_IMETHOD Undo(uint32_t count); \
  NS_IMETHOD CanUndo(bool *isEnabled, bool *canUndo); \
  NS_IMETHOD Redo(uint32_t count); \
  NS_IMETHOD CanRedo(bool *isEnabled, bool *canRedo); \
  NS_IMETHOD BeginTransaction(void); \
  NS_IMETHOD EndTransaction(void); \
  NS_IMETHOD BeginPlaceHolderTransaction(nsIAtom *name); \
  NS_IMETHOD EndPlaceHolderTransaction(void); \
  NS_IMETHOD ShouldTxnSetSelection(bool *_retval); \
  NS_IMETHOD SetShouldTxnSetSelection(bool should); \
  NS_IMETHOD GetInlineSpellChecker(bool autoCreate, nsIInlineSpellChecker * *_retval); \
  NS_IMETHOD SyncRealTimeSpell(void); \
  NS_IMETHOD SetSpellcheckUserOverride(bool enable); \
  NS_IMETHOD Cut(void); \
  NS_IMETHOD CanCut(bool *_retval); \
  NS_IMETHOD Copy(void); \
  NS_IMETHOD CanCopy(bool *_retval); \
  NS_IMETHOD Paste(int32_t aSelectionType); \
  NS_IMETHOD PasteTransferable(nsITransferable *aTransferable); \
  NS_IMETHOD CanPaste(int32_t aSelectionType, bool *_retval); \
  NS_IMETHOD CanPasteTransferable(nsITransferable *aTransferable, bool *_retval); \
  NS_IMETHOD SelectAll(void); \
  NS_IMETHOD BeginningOfDocument(void); \
  NS_IMETHOD EndOfDocument(void); \
  NS_IMETHOD SetAttribute(nsIDOMElement *aElement, const nsAString & attributestr, const nsAString & attvalue); \
  NS_IMETHOD GetAttributeValue(nsIDOMElement *aElement, const nsAString & attributestr, nsAString & resultValue, bool *_retval); \
  NS_IMETHOD RemoveAttribute(nsIDOMElement *aElement, const nsAString & aAttribute); \
  NS_IMETHOD CloneAttribute(const nsAString & aAttribute, nsIDOMNode *aDestNode, nsIDOMNode *aSourceNode); \
  NS_IMETHOD CloneAttributes(nsIDOMNode *destNode, nsIDOMNode *sourceNode); \
  NS_IMETHOD CreateNode(const nsAString & tag, nsIDOMNode *parent, int32_t position, nsIDOMNode * *_retval); \
  NS_IMETHOD InsertNode(nsIDOMNode *node, nsIDOMNode *parent, int32_t aPosition); \
  NS_IMETHOD SplitNode(nsIDOMNode *existingRightNode, int32_t offset, nsIDOMNode * *newLeftNode); \
  NS_IMETHOD JoinNodes(nsIDOMNode *leftNode, nsIDOMNode *rightNode, nsIDOMNode *parent); \
  NS_IMETHOD DeleteNode(nsIDOMNode *child); \
  NS_IMETHOD_(bool) OutputsMozDirty(void); \
  NS_IMETHOD MarkNodeDirty(nsIDOMNode *node); \
  NS_IMETHOD SwitchTextDirection(void); \
  NS_IMETHOD OutputToString(const nsAString & formatType, uint32_t flags, nsAString & _retval); \
  NS_IMETHOD OutputToStream(nsIOutputStream *aStream, const nsAString & formatType, const nsACString & charsetOverride, uint32_t flags); \
  NS_IMETHOD AddEditorObserver(nsIEditorObserver *observer); \
  NS_IMETHOD RemoveEditorObserver(nsIEditorObserver *observer); \
  NS_IMETHOD AddEditActionListener(nsIEditActionListener *listener); \
  NS_IMETHOD RemoveEditActionListener(nsIEditActionListener *listener); \
  NS_IMETHOD AddDocumentStateListener(nsIDocumentStateListener *listener); \
  NS_IMETHOD RemoveDocumentStateListener(nsIDocumentStateListener *listener); \
  NS_IMETHOD DumpContentTree(void); \
  NS_IMETHOD DebugDumpContent(void); \
  NS_IMETHOD DebugUnitTests(int32_t *outNumTests, int32_t *outNumTestsFailed); \
  NS_IMETHOD_(bool) IsModifiableNode(nsIDOMNode *aNode); \
  NS_IMETHOD GetSuppressDispatchingInputEvent(bool *aSuppressDispatchingInputEvent); \
  NS_IMETHOD SetSuppressDispatchingInputEvent(bool aSuppressDispatchingInputEvent); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEDITOR(_to) \
  NS_IMETHOD GetSelection(nsISelection * *aSelection) { return _to GetSelection(aSelection); } \
  NS_IMETHOD Init(nsIDOMDocument *doc, nsIContent *aRoot, nsISelectionController *aSelCon, uint32_t aFlags) { return _to Init(doc, aRoot, aSelCon, aFlags); } \
  NS_IMETHOD SetAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, const nsAString & sourceAttrValue, bool aSuppressTransaction) { return _to SetAttributeOrEquivalent(element, sourceAttrName, sourceAttrValue, aSuppressTransaction); } \
  NS_IMETHOD RemoveAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, bool aSuppressTransaction) { return _to RemoveAttributeOrEquivalent(element, sourceAttrName, aSuppressTransaction); } \
  NS_IMETHOD PostCreate(void) { return _to PostCreate(); } \
  NS_IMETHOD PreDestroy(bool aDestroyingFrames) { return _to PreDestroy(aDestroyingFrames); } \
  NS_IMETHOD GetFlags(uint32_t *aFlags) { return _to GetFlags(aFlags); } \
  NS_IMETHOD SetFlags(uint32_t aFlags) { return _to SetFlags(aFlags); } \
  NS_IMETHOD GetContentsMIMEType(char * *aContentsMIMEType) { return _to GetContentsMIMEType(aContentsMIMEType); } \
  NS_IMETHOD SetContentsMIMEType(const char * aContentsMIMEType) { return _to SetContentsMIMEType(aContentsMIMEType); } \
  NS_IMETHOD GetIsDocumentEditable(bool *aIsDocumentEditable) { return _to GetIsDocumentEditable(aIsDocumentEditable); } \
  NS_IMETHOD GetIsSelectionEditable(bool *aIsSelectionEditable) { return _to GetIsSelectionEditable(aIsSelectionEditable); } \
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) { return _to GetDocument(aDocument); } \
  NS_IMETHOD GetRootElement(nsIDOMElement * *aRootElement) { return _to GetRootElement(aRootElement); } \
  NS_IMETHOD GetSelectionController(nsISelectionController * *aSelectionController) { return _to GetSelectionController(aSelectionController); } \
  NS_IMETHOD DeleteSelection(int16_t action, int16_t stripWrappers) { return _to DeleteSelection(action, stripWrappers); } \
  NS_IMETHOD GetDocumentIsEmpty(bool *aDocumentIsEmpty) { return _to GetDocumentIsEmpty(aDocumentIsEmpty); } \
  NS_IMETHOD GetDocumentModified(bool *aDocumentModified) { return _to GetDocumentModified(aDocumentModified); } \
  NS_IMETHOD GetDocumentCharacterSet(nsACString & aDocumentCharacterSet) { return _to GetDocumentCharacterSet(aDocumentCharacterSet); } \
  NS_IMETHOD SetDocumentCharacterSet(const nsACString & aDocumentCharacterSet) { return _to SetDocumentCharacterSet(aDocumentCharacterSet); } \
  NS_IMETHOD ResetModificationCount(void) { return _to ResetModificationCount(); } \
  NS_IMETHOD GetModificationCount(int32_t *_retval) { return _to GetModificationCount(_retval); } \
  NS_IMETHOD IncrementModificationCount(int32_t aModCount) { return _to IncrementModificationCount(aModCount); } \
  NS_IMETHOD GetTransactionManager(nsITransactionManager * *aTransactionManager) { return _to GetTransactionManager(aTransactionManager); } \
  NS_IMETHOD SetTransactionManager(nsITransactionManager *aTransactionManager) { return _to SetTransactionManager(aTransactionManager); } \
  NS_IMETHOD DoTransaction(nsITransaction *txn) { return _to DoTransaction(txn); } \
  NS_IMETHOD EnableUndo(bool enable) { return _to EnableUndo(enable); } \
  NS_IMETHOD GetNumberOfUndoItems(int32_t *aNumberOfUndoItems) { return _to GetNumberOfUndoItems(aNumberOfUndoItems); } \
  NS_IMETHOD GetNumberOfRedoItems(int32_t *aNumberOfRedoItems) { return _to GetNumberOfRedoItems(aNumberOfRedoItems); } \
  NS_IMETHOD Undo(uint32_t count) { return _to Undo(count); } \
  NS_IMETHOD CanUndo(bool *isEnabled, bool *canUndo) { return _to CanUndo(isEnabled, canUndo); } \
  NS_IMETHOD Redo(uint32_t count) { return _to Redo(count); } \
  NS_IMETHOD CanRedo(bool *isEnabled, bool *canRedo) { return _to CanRedo(isEnabled, canRedo); } \
  NS_IMETHOD BeginTransaction(void) { return _to BeginTransaction(); } \
  NS_IMETHOD EndTransaction(void) { return _to EndTransaction(); } \
  NS_IMETHOD BeginPlaceHolderTransaction(nsIAtom *name) { return _to BeginPlaceHolderTransaction(name); } \
  NS_IMETHOD EndPlaceHolderTransaction(void) { return _to EndPlaceHolderTransaction(); } \
  NS_IMETHOD ShouldTxnSetSelection(bool *_retval) { return _to ShouldTxnSetSelection(_retval); } \
  NS_IMETHOD SetShouldTxnSetSelection(bool should) { return _to SetShouldTxnSetSelection(should); } \
  NS_IMETHOD GetInlineSpellChecker(bool autoCreate, nsIInlineSpellChecker * *_retval) { return _to GetInlineSpellChecker(autoCreate, _retval); } \
  NS_IMETHOD SyncRealTimeSpell(void) { return _to SyncRealTimeSpell(); } \
  NS_IMETHOD SetSpellcheckUserOverride(bool enable) { return _to SetSpellcheckUserOverride(enable); } \
  NS_IMETHOD Cut(void) { return _to Cut(); } \
  NS_IMETHOD CanCut(bool *_retval) { return _to CanCut(_retval); } \
  NS_IMETHOD Copy(void) { return _to Copy(); } \
  NS_IMETHOD CanCopy(bool *_retval) { return _to CanCopy(_retval); } \
  NS_IMETHOD Paste(int32_t aSelectionType) { return _to Paste(aSelectionType); } \
  NS_IMETHOD PasteTransferable(nsITransferable *aTransferable) { return _to PasteTransferable(aTransferable); } \
  NS_IMETHOD CanPaste(int32_t aSelectionType, bool *_retval) { return _to CanPaste(aSelectionType, _retval); } \
  NS_IMETHOD CanPasteTransferable(nsITransferable *aTransferable, bool *_retval) { return _to CanPasteTransferable(aTransferable, _retval); } \
  NS_IMETHOD SelectAll(void) { return _to SelectAll(); } \
  NS_IMETHOD BeginningOfDocument(void) { return _to BeginningOfDocument(); } \
  NS_IMETHOD EndOfDocument(void) { return _to EndOfDocument(); } \
  NS_IMETHOD SetAttribute(nsIDOMElement *aElement, const nsAString & attributestr, const nsAString & attvalue) { return _to SetAttribute(aElement, attributestr, attvalue); } \
  NS_IMETHOD GetAttributeValue(nsIDOMElement *aElement, const nsAString & attributestr, nsAString & resultValue, bool *_retval) { return _to GetAttributeValue(aElement, attributestr, resultValue, _retval); } \
  NS_IMETHOD RemoveAttribute(nsIDOMElement *aElement, const nsAString & aAttribute) { return _to RemoveAttribute(aElement, aAttribute); } \
  NS_IMETHOD CloneAttribute(const nsAString & aAttribute, nsIDOMNode *aDestNode, nsIDOMNode *aSourceNode) { return _to CloneAttribute(aAttribute, aDestNode, aSourceNode); } \
  NS_IMETHOD CloneAttributes(nsIDOMNode *destNode, nsIDOMNode *sourceNode) { return _to CloneAttributes(destNode, sourceNode); } \
  NS_IMETHOD CreateNode(const nsAString & tag, nsIDOMNode *parent, int32_t position, nsIDOMNode * *_retval) { return _to CreateNode(tag, parent, position, _retval); } \
  NS_IMETHOD InsertNode(nsIDOMNode *node, nsIDOMNode *parent, int32_t aPosition) { return _to InsertNode(node, parent, aPosition); } \
  NS_IMETHOD SplitNode(nsIDOMNode *existingRightNode, int32_t offset, nsIDOMNode * *newLeftNode) { return _to SplitNode(existingRightNode, offset, newLeftNode); } \
  NS_IMETHOD JoinNodes(nsIDOMNode *leftNode, nsIDOMNode *rightNode, nsIDOMNode *parent) { return _to JoinNodes(leftNode, rightNode, parent); } \
  NS_IMETHOD DeleteNode(nsIDOMNode *child) { return _to DeleteNode(child); } \
  NS_IMETHOD_(bool) OutputsMozDirty(void) { return _to OutputsMozDirty(); } \
  NS_IMETHOD MarkNodeDirty(nsIDOMNode *node) { return _to MarkNodeDirty(node); } \
  NS_IMETHOD SwitchTextDirection(void) { return _to SwitchTextDirection(); } \
  NS_IMETHOD OutputToString(const nsAString & formatType, uint32_t flags, nsAString & _retval) { return _to OutputToString(formatType, flags, _retval); } \
  NS_IMETHOD OutputToStream(nsIOutputStream *aStream, const nsAString & formatType, const nsACString & charsetOverride, uint32_t flags) { return _to OutputToStream(aStream, formatType, charsetOverride, flags); } \
  NS_IMETHOD AddEditorObserver(nsIEditorObserver *observer) { return _to AddEditorObserver(observer); } \
  NS_IMETHOD RemoveEditorObserver(nsIEditorObserver *observer) { return _to RemoveEditorObserver(observer); } \
  NS_IMETHOD AddEditActionListener(nsIEditActionListener *listener) { return _to AddEditActionListener(listener); } \
  NS_IMETHOD RemoveEditActionListener(nsIEditActionListener *listener) { return _to RemoveEditActionListener(listener); } \
  NS_IMETHOD AddDocumentStateListener(nsIDocumentStateListener *listener) { return _to AddDocumentStateListener(listener); } \
  NS_IMETHOD RemoveDocumentStateListener(nsIDocumentStateListener *listener) { return _to RemoveDocumentStateListener(listener); } \
  NS_IMETHOD DumpContentTree(void) { return _to DumpContentTree(); } \
  NS_IMETHOD DebugDumpContent(void) { return _to DebugDumpContent(); } \
  NS_IMETHOD DebugUnitTests(int32_t *outNumTests, int32_t *outNumTestsFailed) { return _to DebugUnitTests(outNumTests, outNumTestsFailed); } \
  NS_IMETHOD_(bool) IsModifiableNode(nsIDOMNode *aNode) { return _to IsModifiableNode(aNode); } \
  NS_IMETHOD GetSuppressDispatchingInputEvent(bool *aSuppressDispatchingInputEvent) { return _to GetSuppressDispatchingInputEvent(aSuppressDispatchingInputEvent); } \
  NS_IMETHOD SetSuppressDispatchingInputEvent(bool aSuppressDispatchingInputEvent) { return _to SetSuppressDispatchingInputEvent(aSuppressDispatchingInputEvent); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEDITOR(_to) \
  NS_IMETHOD GetSelection(nsISelection * *aSelection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelection(aSelection); } \
  NS_IMETHOD Init(nsIDOMDocument *doc, nsIContent *aRoot, nsISelectionController *aSelCon, uint32_t aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(doc, aRoot, aSelCon, aFlags); } \
  NS_IMETHOD SetAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, const nsAString & sourceAttrValue, bool aSuppressTransaction) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAttributeOrEquivalent(element, sourceAttrName, sourceAttrValue, aSuppressTransaction); } \
  NS_IMETHOD RemoveAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, bool aSuppressTransaction) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAttributeOrEquivalent(element, sourceAttrName, aSuppressTransaction); } \
  NS_IMETHOD PostCreate(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PostCreate(); } \
  NS_IMETHOD PreDestroy(bool aDestroyingFrames) { return !_to ? NS_ERROR_NULL_POINTER : _to->PreDestroy(aDestroyingFrames); } \
  NS_IMETHOD GetFlags(uint32_t *aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFlags(aFlags); } \
  NS_IMETHOD SetFlags(uint32_t aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFlags(aFlags); } \
  NS_IMETHOD GetContentsMIMEType(char * *aContentsMIMEType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentsMIMEType(aContentsMIMEType); } \
  NS_IMETHOD SetContentsMIMEType(const char * aContentsMIMEType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentsMIMEType(aContentsMIMEType); } \
  NS_IMETHOD GetIsDocumentEditable(bool *aIsDocumentEditable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsDocumentEditable(aIsDocumentEditable); } \
  NS_IMETHOD GetIsSelectionEditable(bool *aIsSelectionEditable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsSelectionEditable(aIsSelectionEditable); } \
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocument(aDocument); } \
  NS_IMETHOD GetRootElement(nsIDOMElement * *aRootElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootElement(aRootElement); } \
  NS_IMETHOD GetSelectionController(nsISelectionController * *aSelectionController) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionController(aSelectionController); } \
  NS_IMETHOD DeleteSelection(int16_t action, int16_t stripWrappers) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteSelection(action, stripWrappers); } \
  NS_IMETHOD GetDocumentIsEmpty(bool *aDocumentIsEmpty) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentIsEmpty(aDocumentIsEmpty); } \
  NS_IMETHOD GetDocumentModified(bool *aDocumentModified) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentModified(aDocumentModified); } \
  NS_IMETHOD GetDocumentCharacterSet(nsACString & aDocumentCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentCharacterSet(aDocumentCharacterSet); } \
  NS_IMETHOD SetDocumentCharacterSet(const nsACString & aDocumentCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocumentCharacterSet(aDocumentCharacterSet); } \
  NS_IMETHOD ResetModificationCount(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResetModificationCount(); } \
  NS_IMETHOD GetModificationCount(int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetModificationCount(_retval); } \
  NS_IMETHOD IncrementModificationCount(int32_t aModCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->IncrementModificationCount(aModCount); } \
  NS_IMETHOD GetTransactionManager(nsITransactionManager * *aTransactionManager) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransactionManager(aTransactionManager); } \
  NS_IMETHOD SetTransactionManager(nsITransactionManager *aTransactionManager) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTransactionManager(aTransactionManager); } \
  NS_IMETHOD DoTransaction(nsITransaction *txn) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoTransaction(txn); } \
  NS_IMETHOD EnableUndo(bool enable) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableUndo(enable); } \
  NS_IMETHOD GetNumberOfUndoItems(int32_t *aNumberOfUndoItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumberOfUndoItems(aNumberOfUndoItems); } \
  NS_IMETHOD GetNumberOfRedoItems(int32_t *aNumberOfRedoItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumberOfRedoItems(aNumberOfRedoItems); } \
  NS_IMETHOD Undo(uint32_t count) { return !_to ? NS_ERROR_NULL_POINTER : _to->Undo(count); } \
  NS_IMETHOD CanUndo(bool *isEnabled, bool *canUndo) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanUndo(isEnabled, canUndo); } \
  NS_IMETHOD Redo(uint32_t count) { return !_to ? NS_ERROR_NULL_POINTER : _to->Redo(count); } \
  NS_IMETHOD CanRedo(bool *isEnabled, bool *canRedo) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanRedo(isEnabled, canRedo); } \
  NS_IMETHOD BeginTransaction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginTransaction(); } \
  NS_IMETHOD EndTransaction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndTransaction(); } \
  NS_IMETHOD BeginPlaceHolderTransaction(nsIAtom *name) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginPlaceHolderTransaction(name); } \
  NS_IMETHOD EndPlaceHolderTransaction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndPlaceHolderTransaction(); } \
  NS_IMETHOD ShouldTxnSetSelection(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShouldTxnSetSelection(_retval); } \
  NS_IMETHOD SetShouldTxnSetSelection(bool should) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShouldTxnSetSelection(should); } \
  NS_IMETHOD GetInlineSpellChecker(bool autoCreate, nsIInlineSpellChecker * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInlineSpellChecker(autoCreate, _retval); } \
  NS_IMETHOD SyncRealTimeSpell(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SyncRealTimeSpell(); } \
  NS_IMETHOD SetSpellcheckUserOverride(bool enable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSpellcheckUserOverride(enable); } \
  NS_IMETHOD Cut(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Cut(); } \
  NS_IMETHOD CanCut(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanCut(_retval); } \
  NS_IMETHOD Copy(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Copy(); } \
  NS_IMETHOD CanCopy(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanCopy(_retval); } \
  NS_IMETHOD Paste(int32_t aSelectionType) { return !_to ? NS_ERROR_NULL_POINTER : _to->Paste(aSelectionType); } \
  NS_IMETHOD PasteTransferable(nsITransferable *aTransferable) { return !_to ? NS_ERROR_NULL_POINTER : _to->PasteTransferable(aTransferable); } \
  NS_IMETHOD CanPaste(int32_t aSelectionType, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanPaste(aSelectionType, _retval); } \
  NS_IMETHOD CanPasteTransferable(nsITransferable *aTransferable, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanPasteTransferable(aTransferable, _retval); } \
  NS_IMETHOD SelectAll(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectAll(); } \
  NS_IMETHOD BeginningOfDocument(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginningOfDocument(); } \
  NS_IMETHOD EndOfDocument(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndOfDocument(); } \
  NS_IMETHOD SetAttribute(nsIDOMElement *aElement, const nsAString & attributestr, const nsAString & attvalue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAttribute(aElement, attributestr, attvalue); } \
  NS_IMETHOD GetAttributeValue(nsIDOMElement *aElement, const nsAString & attributestr, nsAString & resultValue, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttributeValue(aElement, attributestr, resultValue, _retval); } \
  NS_IMETHOD RemoveAttribute(nsIDOMElement *aElement, const nsAString & aAttribute) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAttribute(aElement, aAttribute); } \
  NS_IMETHOD CloneAttribute(const nsAString & aAttribute, nsIDOMNode *aDestNode, nsIDOMNode *aSourceNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloneAttribute(aAttribute, aDestNode, aSourceNode); } \
  NS_IMETHOD CloneAttributes(nsIDOMNode *destNode, nsIDOMNode *sourceNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloneAttributes(destNode, sourceNode); } \
  NS_IMETHOD CreateNode(const nsAString & tag, nsIDOMNode *parent, int32_t position, nsIDOMNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateNode(tag, parent, position, _retval); } \
  NS_IMETHOD InsertNode(nsIDOMNode *node, nsIDOMNode *parent, int32_t aPosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertNode(node, parent, aPosition); } \
  NS_IMETHOD SplitNode(nsIDOMNode *existingRightNode, int32_t offset, nsIDOMNode * *newLeftNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SplitNode(existingRightNode, offset, newLeftNode); } \
  NS_IMETHOD JoinNodes(nsIDOMNode *leftNode, nsIDOMNode *rightNode, nsIDOMNode *parent) { return !_to ? NS_ERROR_NULL_POINTER : _to->JoinNodes(leftNode, rightNode, parent); } \
  NS_IMETHOD DeleteNode(nsIDOMNode *child) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteNode(child); } \
  NS_IMETHOD_(bool) OutputsMozDirty(void); \
  NS_IMETHOD MarkNodeDirty(nsIDOMNode *node) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkNodeDirty(node); } \
  NS_IMETHOD SwitchTextDirection(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SwitchTextDirection(); } \
  NS_IMETHOD OutputToString(const nsAString & formatType, uint32_t flags, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OutputToString(formatType, flags, _retval); } \
  NS_IMETHOD OutputToStream(nsIOutputStream *aStream, const nsAString & formatType, const nsACString & charsetOverride, uint32_t flags) { return !_to ? NS_ERROR_NULL_POINTER : _to->OutputToStream(aStream, formatType, charsetOverride, flags); } \
  NS_IMETHOD AddEditorObserver(nsIEditorObserver *observer) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddEditorObserver(observer); } \
  NS_IMETHOD RemoveEditorObserver(nsIEditorObserver *observer) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveEditorObserver(observer); } \
  NS_IMETHOD AddEditActionListener(nsIEditActionListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddEditActionListener(listener); } \
  NS_IMETHOD RemoveEditActionListener(nsIEditActionListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveEditActionListener(listener); } \
  NS_IMETHOD AddDocumentStateListener(nsIDocumentStateListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddDocumentStateListener(listener); } \
  NS_IMETHOD RemoveDocumentStateListener(nsIDocumentStateListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveDocumentStateListener(listener); } \
  NS_IMETHOD DumpContentTree(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DumpContentTree(); } \
  NS_IMETHOD DebugDumpContent(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DebugDumpContent(); } \
  NS_IMETHOD DebugUnitTests(int32_t *outNumTests, int32_t *outNumTestsFailed) { return !_to ? NS_ERROR_NULL_POINTER : _to->DebugUnitTests(outNumTests, outNumTestsFailed); } \
  NS_IMETHOD_(bool) IsModifiableNode(nsIDOMNode *aNode); \
  NS_IMETHOD GetSuppressDispatchingInputEvent(bool *aSuppressDispatchingInputEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSuppressDispatchingInputEvent(aSuppressDispatchingInputEvent); } \
  NS_IMETHOD SetSuppressDispatchingInputEvent(bool aSuppressDispatchingInputEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSuppressDispatchingInputEvent(aSuppressDispatchingInputEvent); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEditor : public nsIEditor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEDITOR

  nsEditor();

private:
  ~nsEditor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEditor, nsIEditor)

nsEditor::nsEditor()
{
  /* member initializers and constructor code */
}

nsEditor::~nsEditor()
{
  /* destructor code */
}

/* readonly attribute nsISelection selection; */
NS_IMETHODIMP nsEditor::GetSelection(nsISelection * *aSelection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void init (in nsIDOMDocument doc, in nsIContent aRoot, in nsISelectionController aSelCon, in unsigned long aFlags); */
NS_IMETHODIMP nsEditor::Init(nsIDOMDocument *doc, nsIContent *aRoot, nsISelectionController *aSelCon, uint32_t aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAttributeOrEquivalent (in nsIDOMElement element, in AString sourceAttrName, in AString sourceAttrValue, in boolean aSuppressTransaction); */
NS_IMETHODIMP nsEditor::SetAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, const nsAString & sourceAttrValue, bool aSuppressTransaction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAttributeOrEquivalent (in nsIDOMElement element, in DOMString sourceAttrName, in boolean aSuppressTransaction); */
NS_IMETHODIMP nsEditor::RemoveAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, bool aSuppressTransaction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void postCreate (); */
NS_IMETHODIMP nsEditor::PostCreate()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void preDestroy (in boolean aDestroyingFrames); */
NS_IMETHODIMP nsEditor::PreDestroy(bool aDestroyingFrames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long flags; */
NS_IMETHODIMP nsEditor::GetFlags(uint32_t *aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsEditor::SetFlags(uint32_t aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute string contentsMIMEType; */
NS_IMETHODIMP nsEditor::GetContentsMIMEType(char * *aContentsMIMEType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsEditor::SetContentsMIMEType(const char * aContentsMIMEType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isDocumentEditable; */
NS_IMETHODIMP nsEditor::GetIsDocumentEditable(bool *aIsDocumentEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isSelectionEditable; */
NS_IMETHODIMP nsEditor::GetIsSelectionEditable(bool *aIsSelectionEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDocument document; */
NS_IMETHODIMP nsEditor::GetDocument(nsIDOMDocument * *aDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement rootElement; */
NS_IMETHODIMP nsEditor::GetRootElement(nsIDOMElement * *aRootElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISelectionController selectionController; */
NS_IMETHODIMP nsEditor::GetSelectionController(nsISelectionController * *aSelectionController)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteSelection (in short action, in short stripWrappers); */
NS_IMETHODIMP nsEditor::DeleteSelection(int16_t action, int16_t stripWrappers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean documentIsEmpty; */
NS_IMETHODIMP nsEditor::GetDocumentIsEmpty(bool *aDocumentIsEmpty)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean documentModified; */
NS_IMETHODIMP nsEditor::GetDocumentModified(bool *aDocumentModified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString documentCharacterSet; */
NS_IMETHODIMP nsEditor::GetDocumentCharacterSet(nsACString & aDocumentCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsEditor::SetDocumentCharacterSet(const nsACString & aDocumentCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resetModificationCount (); */
NS_IMETHODIMP nsEditor::ResetModificationCount()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getModificationCount (); */
NS_IMETHODIMP nsEditor::GetModificationCount(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void incrementModificationCount (in long aModCount); */
NS_IMETHODIMP nsEditor::IncrementModificationCount(int32_t aModCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsITransactionManager transactionManager; */
NS_IMETHODIMP nsEditor::GetTransactionManager(nsITransactionManager * *aTransactionManager)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsEditor::SetTransactionManager(nsITransactionManager *aTransactionManager)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doTransaction (in nsITransaction txn); */
NS_IMETHODIMP nsEditor::DoTransaction(nsITransaction *txn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enableUndo (in boolean enable); */
NS_IMETHODIMP nsEditor::EnableUndo(bool enable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long numberOfUndoItems; */
NS_IMETHODIMP nsEditor::GetNumberOfUndoItems(int32_t *aNumberOfUndoItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long numberOfRedoItems; */
NS_IMETHODIMP nsEditor::GetNumberOfRedoItems(int32_t *aNumberOfRedoItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void undo (in unsigned long count); */
NS_IMETHODIMP nsEditor::Undo(uint32_t count)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void canUndo (out boolean isEnabled, out boolean canUndo); */
NS_IMETHODIMP nsEditor::CanUndo(bool *isEnabled, bool *canUndo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void redo (in unsigned long count); */
NS_IMETHODIMP nsEditor::Redo(uint32_t count)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void canRedo (out boolean isEnabled, out boolean canRedo); */
NS_IMETHODIMP nsEditor::CanRedo(bool *isEnabled, bool *canRedo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginTransaction (); */
NS_IMETHODIMP nsEditor::BeginTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endTransaction (); */
NS_IMETHODIMP nsEditor::EndTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginPlaceHolderTransaction (in nsIAtom name); */
NS_IMETHODIMP nsEditor::BeginPlaceHolderTransaction(nsIAtom *name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endPlaceHolderTransaction (); */
NS_IMETHODIMP nsEditor::EndPlaceHolderTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean shouldTxnSetSelection (); */
NS_IMETHODIMP nsEditor::ShouldTxnSetSelection(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setShouldTxnSetSelection (in boolean should); */
NS_IMETHODIMP nsEditor::SetShouldTxnSetSelection(bool should)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInlineSpellChecker getInlineSpellChecker (in boolean autoCreate); */
NS_IMETHODIMP nsEditor::GetInlineSpellChecker(bool autoCreate, nsIInlineSpellChecker * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void syncRealTimeSpell (); */
NS_IMETHODIMP nsEditor::SyncRealTimeSpell()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSpellcheckUserOverride (in boolean enable); */
NS_IMETHODIMP nsEditor::SetSpellcheckUserOverride(bool enable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cut (); */
NS_IMETHODIMP nsEditor::Cut()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canCut (); */
NS_IMETHODIMP nsEditor::CanCut(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void copy (); */
NS_IMETHODIMP nsEditor::Copy()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canCopy (); */
NS_IMETHODIMP nsEditor::CanCopy(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void paste (in long aSelectionType); */
NS_IMETHODIMP nsEditor::Paste(int32_t aSelectionType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void pasteTransferable (in nsITransferable aTransferable); */
NS_IMETHODIMP nsEditor::PasteTransferable(nsITransferable *aTransferable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canPaste (in long aSelectionType); */
NS_IMETHODIMP nsEditor::CanPaste(int32_t aSelectionType, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canPasteTransferable ([optional] in nsITransferable aTransferable); */
NS_IMETHODIMP nsEditor::CanPasteTransferable(nsITransferable *aTransferable, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectAll (); */
NS_IMETHODIMP nsEditor::SelectAll()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginningOfDocument (); */
NS_IMETHODIMP nsEditor::BeginningOfDocument()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endOfDocument (); */
NS_IMETHODIMP nsEditor::EndOfDocument()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAttribute (in nsIDOMElement aElement, in AString attributestr, in AString attvalue); */
NS_IMETHODIMP nsEditor::SetAttribute(nsIDOMElement *aElement, const nsAString & attributestr, const nsAString & attvalue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getAttributeValue (in nsIDOMElement aElement, in AString attributestr, out AString resultValue); */
NS_IMETHODIMP nsEditor::GetAttributeValue(nsIDOMElement *aElement, const nsAString & attributestr, nsAString & resultValue, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAttribute (in nsIDOMElement aElement, in AString aAttribute); */
NS_IMETHODIMP nsEditor::RemoveAttribute(nsIDOMElement *aElement, const nsAString & aAttribute)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cloneAttribute (in AString aAttribute, in nsIDOMNode aDestNode, in nsIDOMNode aSourceNode); */
NS_IMETHODIMP nsEditor::CloneAttribute(const nsAString & aAttribute, nsIDOMNode *aDestNode, nsIDOMNode *aSourceNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cloneAttributes (in nsIDOMNode destNode, in nsIDOMNode sourceNode); */
NS_IMETHODIMP nsEditor::CloneAttributes(nsIDOMNode *destNode, nsIDOMNode *sourceNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode createNode (in AString tag, in nsIDOMNode parent, in long position); */
NS_IMETHODIMP nsEditor::CreateNode(const nsAString & tag, nsIDOMNode *parent, int32_t position, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertNode (in nsIDOMNode node, in nsIDOMNode parent, in long aPosition); */
NS_IMETHODIMP nsEditor::InsertNode(nsIDOMNode *node, nsIDOMNode *parent, int32_t aPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void splitNode (in nsIDOMNode existingRightNode, in long offset, out nsIDOMNode newLeftNode); */
NS_IMETHODIMP nsEditor::SplitNode(nsIDOMNode *existingRightNode, int32_t offset, nsIDOMNode * *newLeftNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void joinNodes (in nsIDOMNode leftNode, in nsIDOMNode rightNode, in nsIDOMNode parent); */
NS_IMETHODIMP nsEditor::JoinNodes(nsIDOMNode *leftNode, nsIDOMNode *rightNode, nsIDOMNode *parent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteNode (in nsIDOMNode child); */
NS_IMETHODIMP nsEditor::DeleteNode(nsIDOMNode *child)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean outputsMozDirty (); */
NS_IMETHODIMP_(bool) nsEditor::OutputsMozDirty()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markNodeDirty (in nsIDOMNode node); */
NS_IMETHODIMP nsEditor::MarkNodeDirty(nsIDOMNode *node)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void switchTextDirection (); */
NS_IMETHODIMP nsEditor::SwitchTextDirection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString outputToString (in AString formatType, in unsigned long flags); */
NS_IMETHODIMP nsEditor::OutputToString(const nsAString & formatType, uint32_t flags, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void outputToStream (in nsIOutputStream aStream, in AString formatType, in ACString charsetOverride, in unsigned long flags); */
NS_IMETHODIMP nsEditor::OutputToStream(nsIOutputStream *aStream, const nsAString & formatType, const nsACString & charsetOverride, uint32_t flags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addEditorObserver (in nsIEditorObserver observer); */
NS_IMETHODIMP nsEditor::AddEditorObserver(nsIEditorObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeEditorObserver (in nsIEditorObserver observer); */
NS_IMETHODIMP nsEditor::RemoveEditorObserver(nsIEditorObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addEditActionListener (in nsIEditActionListener listener); */
NS_IMETHODIMP nsEditor::AddEditActionListener(nsIEditActionListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeEditActionListener (in nsIEditActionListener listener); */
NS_IMETHODIMP nsEditor::RemoveEditActionListener(nsIEditActionListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addDocumentStateListener (in nsIDocumentStateListener listener); */
NS_IMETHODIMP nsEditor::AddDocumentStateListener(nsIDocumentStateListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeDocumentStateListener (in nsIDocumentStateListener listener); */
NS_IMETHODIMP nsEditor::RemoveDocumentStateListener(nsIDocumentStateListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dumpContentTree (); */
NS_IMETHODIMP nsEditor::DumpContentTree()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void debugDumpContent (); */
NS_IMETHODIMP nsEditor::DebugDumpContent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void debugUnitTests (out long outNumTests, out long outNumTestsFailed); */
NS_IMETHODIMP nsEditor::DebugUnitTests(int32_t *outNumTests, int32_t *outNumTestsFailed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean isModifiableNode (in nsIDOMNode aNode); */
NS_IMETHODIMP_(bool) nsEditor::IsModifiableNode(nsIDOMNode *aNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean suppressDispatchingInputEvent; */
NS_IMETHODIMP nsEditor::GetSuppressDispatchingInputEvent(bool *aSuppressDispatchingInputEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsEditor::SetSuppressDispatchingInputEvent(bool aSuppressDispatchingInputEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEditor_h__ */

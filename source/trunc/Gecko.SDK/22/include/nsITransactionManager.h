/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/editor/txmgr/idl/nsITransactionManager.idl
 */

#ifndef __gen_nsITransactionManager_h__
#define __gen_nsITransactionManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsITransaction_h__
#include "nsITransaction.h"
#endif

#ifndef __gen_nsITransactionList_h__
#include "nsITransactionList.h"
#endif

#ifndef __gen_nsITransactionListener_h__
#include "nsITransactionListener.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

#define NS_TRANSACTIONMANAGER_CONTRACTID "@mozilla.org/transactionmanager;1"

/* starting interface:    nsITransactionManager */
#define NS_ITRANSACTIONMANAGER_IID_STR "c77763df-0fb9-41a8-8074-8e882f605755"

#define NS_ITRANSACTIONMANAGER_IID \
  {0xc77763df, 0x0fb9, 0x41a8, \
    { 0x80, 0x74, 0x8e, 0x88, 0x2f, 0x60, 0x57, 0x55 }}

class NS_NO_VTABLE nsITransactionManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITRANSACTIONMANAGER_IID)

  /* void doTransaction (in nsITransaction aTransaction); */
  NS_IMETHOD DoTransaction(nsITransaction *aTransaction) = 0;

  /* void undoTransaction (); */
  NS_IMETHOD UndoTransaction(void) = 0;

  /* void redoTransaction (); */
  NS_IMETHOD RedoTransaction(void) = 0;

  /* void clear (); */
  NS_IMETHOD Clear(void) = 0;

  /* void clearUndoStack (); */
  NS_IMETHOD ClearUndoStack(void) = 0;

  /* void clearRedoStack (); */
  NS_IMETHOD ClearRedoStack(void) = 0;

  /* void beginBatch (in nsISupports aData); */
  NS_IMETHOD BeginBatch(nsISupports *aData) = 0;

  /* void endBatch (in boolean aAllowEmpty); */
  NS_IMETHOD EndBatch(bool aAllowEmpty) = 0;

  /* readonly attribute long numberOfUndoItems; */
  NS_IMETHOD GetNumberOfUndoItems(int32_t *aNumberOfUndoItems) = 0;

  /* readonly attribute long numberOfRedoItems; */
  NS_IMETHOD GetNumberOfRedoItems(int32_t *aNumberOfRedoItems) = 0;

  /* attribute long maxTransactionCount; */
  NS_IMETHOD GetMaxTransactionCount(int32_t *aMaxTransactionCount) = 0;
  NS_IMETHOD SetMaxTransactionCount(int32_t aMaxTransactionCount) = 0;

  /* void batchTopUndo (); */
  NS_IMETHOD BatchTopUndo(void) = 0;

  /* void removeTopUndo (); */
  NS_IMETHOD RemoveTopUndo(void) = 0;

  /* nsITransaction peekUndoStack (); */
  NS_IMETHOD PeekUndoStack(nsITransaction * *_retval) = 0;

  /* nsITransaction peekRedoStack (); */
  NS_IMETHOD PeekRedoStack(nsITransaction * *_retval) = 0;

  /* nsITransactionList getUndoList (); */
  NS_IMETHOD GetUndoList(nsITransactionList * *_retval) = 0;

  /* nsITransactionList getRedoList (); */
  NS_IMETHOD GetRedoList(nsITransactionList * *_retval) = 0;

  /* void AddListener (in nsITransactionListener aListener); */
  NS_IMETHOD AddListener(nsITransactionListener *aListener) = 0;

  /* void RemoveListener (in nsITransactionListener aListener); */
  NS_IMETHOD RemoveListener(nsITransactionListener *aListener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITransactionManager, NS_ITRANSACTIONMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITRANSACTIONMANAGER \
  NS_IMETHOD DoTransaction(nsITransaction *aTransaction); \
  NS_IMETHOD UndoTransaction(void); \
  NS_IMETHOD RedoTransaction(void); \
  NS_IMETHOD Clear(void); \
  NS_IMETHOD ClearUndoStack(void); \
  NS_IMETHOD ClearRedoStack(void); \
  NS_IMETHOD BeginBatch(nsISupports *aData); \
  NS_IMETHOD EndBatch(bool aAllowEmpty); \
  NS_IMETHOD GetNumberOfUndoItems(int32_t *aNumberOfUndoItems); \
  NS_IMETHOD GetNumberOfRedoItems(int32_t *aNumberOfRedoItems); \
  NS_IMETHOD GetMaxTransactionCount(int32_t *aMaxTransactionCount); \
  NS_IMETHOD SetMaxTransactionCount(int32_t aMaxTransactionCount); \
  NS_IMETHOD BatchTopUndo(void); \
  NS_IMETHOD RemoveTopUndo(void); \
  NS_IMETHOD PeekUndoStack(nsITransaction * *_retval); \
  NS_IMETHOD PeekRedoStack(nsITransaction * *_retval); \
  NS_IMETHOD GetUndoList(nsITransactionList * *_retval); \
  NS_IMETHOD GetRedoList(nsITransactionList * *_retval); \
  NS_IMETHOD AddListener(nsITransactionListener *aListener); \
  NS_IMETHOD RemoveListener(nsITransactionListener *aListener); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITRANSACTIONMANAGER(_to) \
  NS_IMETHOD DoTransaction(nsITransaction *aTransaction) { return _to DoTransaction(aTransaction); } \
  NS_IMETHOD UndoTransaction(void) { return _to UndoTransaction(); } \
  NS_IMETHOD RedoTransaction(void) { return _to RedoTransaction(); } \
  NS_IMETHOD Clear(void) { return _to Clear(); } \
  NS_IMETHOD ClearUndoStack(void) { return _to ClearUndoStack(); } \
  NS_IMETHOD ClearRedoStack(void) { return _to ClearRedoStack(); } \
  NS_IMETHOD BeginBatch(nsISupports *aData) { return _to BeginBatch(aData); } \
  NS_IMETHOD EndBatch(bool aAllowEmpty) { return _to EndBatch(aAllowEmpty); } \
  NS_IMETHOD GetNumberOfUndoItems(int32_t *aNumberOfUndoItems) { return _to GetNumberOfUndoItems(aNumberOfUndoItems); } \
  NS_IMETHOD GetNumberOfRedoItems(int32_t *aNumberOfRedoItems) { return _to GetNumberOfRedoItems(aNumberOfRedoItems); } \
  NS_IMETHOD GetMaxTransactionCount(int32_t *aMaxTransactionCount) { return _to GetMaxTransactionCount(aMaxTransactionCount); } \
  NS_IMETHOD SetMaxTransactionCount(int32_t aMaxTransactionCount) { return _to SetMaxTransactionCount(aMaxTransactionCount); } \
  NS_IMETHOD BatchTopUndo(void) { return _to BatchTopUndo(); } \
  NS_IMETHOD RemoveTopUndo(void) { return _to RemoveTopUndo(); } \
  NS_IMETHOD PeekUndoStack(nsITransaction * *_retval) { return _to PeekUndoStack(_retval); } \
  NS_IMETHOD PeekRedoStack(nsITransaction * *_retval) { return _to PeekRedoStack(_retval); } \
  NS_IMETHOD GetUndoList(nsITransactionList * *_retval) { return _to GetUndoList(_retval); } \
  NS_IMETHOD GetRedoList(nsITransactionList * *_retval) { return _to GetRedoList(_retval); } \
  NS_IMETHOD AddListener(nsITransactionListener *aListener) { return _to AddListener(aListener); } \
  NS_IMETHOD RemoveListener(nsITransactionListener *aListener) { return _to RemoveListener(aListener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITRANSACTIONMANAGER(_to) \
  NS_IMETHOD DoTransaction(nsITransaction *aTransaction) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoTransaction(aTransaction); } \
  NS_IMETHOD UndoTransaction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->UndoTransaction(); } \
  NS_IMETHOD RedoTransaction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RedoTransaction(); } \
  NS_IMETHOD Clear(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(); } \
  NS_IMETHOD ClearUndoStack(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearUndoStack(); } \
  NS_IMETHOD ClearRedoStack(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearRedoStack(); } \
  NS_IMETHOD BeginBatch(nsISupports *aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginBatch(aData); } \
  NS_IMETHOD EndBatch(bool aAllowEmpty) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndBatch(aAllowEmpty); } \
  NS_IMETHOD GetNumberOfUndoItems(int32_t *aNumberOfUndoItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumberOfUndoItems(aNumberOfUndoItems); } \
  NS_IMETHOD GetNumberOfRedoItems(int32_t *aNumberOfRedoItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumberOfRedoItems(aNumberOfRedoItems); } \
  NS_IMETHOD GetMaxTransactionCount(int32_t *aMaxTransactionCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxTransactionCount(aMaxTransactionCount); } \
  NS_IMETHOD SetMaxTransactionCount(int32_t aMaxTransactionCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMaxTransactionCount(aMaxTransactionCount); } \
  NS_IMETHOD BatchTopUndo(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->BatchTopUndo(); } \
  NS_IMETHOD RemoveTopUndo(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveTopUndo(); } \
  NS_IMETHOD PeekUndoStack(nsITransaction * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->PeekUndoStack(_retval); } \
  NS_IMETHOD PeekRedoStack(nsITransaction * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->PeekRedoStack(_retval); } \
  NS_IMETHOD GetUndoList(nsITransactionList * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUndoList(_retval); } \
  NS_IMETHOD GetRedoList(nsITransactionList * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRedoList(_retval); } \
  NS_IMETHOD AddListener(nsITransactionListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddListener(aListener); } \
  NS_IMETHOD RemoveListener(nsITransactionListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveListener(aListener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTransactionManager : public nsITransactionManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITRANSACTIONMANAGER

  nsTransactionManager();

private:
  ~nsTransactionManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTransactionManager, nsITransactionManager)

nsTransactionManager::nsTransactionManager()
{
  /* member initializers and constructor code */
}

nsTransactionManager::~nsTransactionManager()
{
  /* destructor code */
}

/* void doTransaction (in nsITransaction aTransaction); */
NS_IMETHODIMP nsTransactionManager::DoTransaction(nsITransaction *aTransaction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void undoTransaction (); */
NS_IMETHODIMP nsTransactionManager::UndoTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void redoTransaction (); */
NS_IMETHODIMP nsTransactionManager::RedoTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clear (); */
NS_IMETHODIMP nsTransactionManager::Clear()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearUndoStack (); */
NS_IMETHODIMP nsTransactionManager::ClearUndoStack()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearRedoStack (); */
NS_IMETHODIMP nsTransactionManager::ClearRedoStack()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginBatch (in nsISupports aData); */
NS_IMETHODIMP nsTransactionManager::BeginBatch(nsISupports *aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endBatch (in boolean aAllowEmpty); */
NS_IMETHODIMP nsTransactionManager::EndBatch(bool aAllowEmpty)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long numberOfUndoItems; */
NS_IMETHODIMP nsTransactionManager::GetNumberOfUndoItems(int32_t *aNumberOfUndoItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long numberOfRedoItems; */
NS_IMETHODIMP nsTransactionManager::GetNumberOfRedoItems(int32_t *aNumberOfRedoItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long maxTransactionCount; */
NS_IMETHODIMP nsTransactionManager::GetMaxTransactionCount(int32_t *aMaxTransactionCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTransactionManager::SetMaxTransactionCount(int32_t aMaxTransactionCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void batchTopUndo (); */
NS_IMETHODIMP nsTransactionManager::BatchTopUndo()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeTopUndo (); */
NS_IMETHODIMP nsTransactionManager::RemoveTopUndo()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITransaction peekUndoStack (); */
NS_IMETHODIMP nsTransactionManager::PeekUndoStack(nsITransaction * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITransaction peekRedoStack (); */
NS_IMETHODIMP nsTransactionManager::PeekRedoStack(nsITransaction * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITransactionList getUndoList (); */
NS_IMETHODIMP nsTransactionManager::GetUndoList(nsITransactionList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITransactionList getRedoList (); */
NS_IMETHODIMP nsTransactionManager::GetRedoList(nsITransactionList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void AddListener (in nsITransactionListener aListener); */
NS_IMETHODIMP nsTransactionManager::AddListener(nsITransactionListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void RemoveListener (in nsITransactionListener aListener); */
NS_IMETHODIMP nsTransactionManager::RemoveListener(nsITransactionListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITransactionManager_h__ */

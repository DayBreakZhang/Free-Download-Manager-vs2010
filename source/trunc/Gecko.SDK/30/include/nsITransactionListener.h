/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITransactionListener.idl
 */

#ifndef __gen_nsITransactionListener_h__
#define __gen_nsITransactionListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITransaction; /* forward declaration */

class nsITransactionManager; /* forward declaration */


/* starting interface:    nsITransactionListener */
#define NS_ITRANSACTIONLISTENER_IID_STR "58e330c4-7b48-11d2-98b9-00805f297d89"

#define NS_ITRANSACTIONLISTENER_IID \
  {0x58e330c4, 0x7b48, 0x11d2, \
    { 0x98, 0xb9, 0x00, 0x80, 0x5f, 0x29, 0x7d, 0x89 }}

class NS_NO_VTABLE nsITransactionListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITRANSACTIONLISTENER_IID)

  /* boolean willDo (in nsITransactionManager aManager, in nsITransaction aTransaction); */
  NS_IMETHOD WillDo(nsITransactionManager *aManager, nsITransaction *aTransaction, bool *_retval) = 0;

  /* void didDo (in nsITransactionManager aManager, in nsITransaction aTransaction, in nsresult aDoResult); */
  NS_IMETHOD DidDo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aDoResult) = 0;

  /* boolean willUndo (in nsITransactionManager aManager, in nsITransaction aTransaction); */
  NS_IMETHOD WillUndo(nsITransactionManager *aManager, nsITransaction *aTransaction, bool *_retval) = 0;

  /* void didUndo (in nsITransactionManager aManager, in nsITransaction aTransaction, in nsresult aUndoResult); */
  NS_IMETHOD DidUndo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aUndoResult) = 0;

  /* boolean willRedo (in nsITransactionManager aManager, in nsITransaction aTransaction); */
  NS_IMETHOD WillRedo(nsITransactionManager *aManager, nsITransaction *aTransaction, bool *_retval) = 0;

  /* void didRedo (in nsITransactionManager aManager, in nsITransaction aTransaction, in nsresult aRedoResult); */
  NS_IMETHOD DidRedo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aRedoResult) = 0;

  /* boolean willBeginBatch (in nsITransactionManager aManager); */
  NS_IMETHOD WillBeginBatch(nsITransactionManager *aManager, bool *_retval) = 0;

  /* void didBeginBatch (in nsITransactionManager aManager, in nsresult aResult); */
  NS_IMETHOD DidBeginBatch(nsITransactionManager *aManager, nsresult aResult) = 0;

  /* boolean willEndBatch (in nsITransactionManager aManager); */
  NS_IMETHOD WillEndBatch(nsITransactionManager *aManager, bool *_retval) = 0;

  /* void didEndBatch (in nsITransactionManager aManager, in nsresult aResult); */
  NS_IMETHOD DidEndBatch(nsITransactionManager *aManager, nsresult aResult) = 0;

  /* boolean willMerge (in nsITransactionManager aManager, in nsITransaction aTopTransaction, in nsITransaction aTransactionToMerge); */
  NS_IMETHOD WillMerge(nsITransactionManager *aManager, nsITransaction *aTopTransaction, nsITransaction *aTransactionToMerge, bool *_retval) = 0;

  /* void didMerge (in nsITransactionManager aManager, in nsITransaction aTopTransaction, in nsITransaction aTransactionToMerge, in boolean aDidMerge, in nsresult aMergeResult); */
  NS_IMETHOD DidMerge(nsITransactionManager *aManager, nsITransaction *aTopTransaction, nsITransaction *aTransactionToMerge, bool aDidMerge, nsresult aMergeResult) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITransactionListener, NS_ITRANSACTIONLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITRANSACTIONLISTENER \
  NS_IMETHOD WillDo(nsITransactionManager *aManager, nsITransaction *aTransaction, bool *_retval); \
  NS_IMETHOD DidDo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aDoResult); \
  NS_IMETHOD WillUndo(nsITransactionManager *aManager, nsITransaction *aTransaction, bool *_retval); \
  NS_IMETHOD DidUndo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aUndoResult); \
  NS_IMETHOD WillRedo(nsITransactionManager *aManager, nsITransaction *aTransaction, bool *_retval); \
  NS_IMETHOD DidRedo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aRedoResult); \
  NS_IMETHOD WillBeginBatch(nsITransactionManager *aManager, bool *_retval); \
  NS_IMETHOD DidBeginBatch(nsITransactionManager *aManager, nsresult aResult); \
  NS_IMETHOD WillEndBatch(nsITransactionManager *aManager, bool *_retval); \
  NS_IMETHOD DidEndBatch(nsITransactionManager *aManager, nsresult aResult); \
  NS_IMETHOD WillMerge(nsITransactionManager *aManager, nsITransaction *aTopTransaction, nsITransaction *aTransactionToMerge, bool *_retval); \
  NS_IMETHOD DidMerge(nsITransactionManager *aManager, nsITransaction *aTopTransaction, nsITransaction *aTransactionToMerge, bool aDidMerge, nsresult aMergeResult); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITRANSACTIONLISTENER(_to) \
  NS_IMETHOD WillDo(nsITransactionManager *aManager, nsITransaction *aTransaction, bool *_retval) { return _to WillDo(aManager, aTransaction, _retval); } \
  NS_IMETHOD DidDo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aDoResult) { return _to DidDo(aManager, aTransaction, aDoResult); } \
  NS_IMETHOD WillUndo(nsITransactionManager *aManager, nsITransaction *aTransaction, bool *_retval) { return _to WillUndo(aManager, aTransaction, _retval); } \
  NS_IMETHOD DidUndo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aUndoResult) { return _to DidUndo(aManager, aTransaction, aUndoResult); } \
  NS_IMETHOD WillRedo(nsITransactionManager *aManager, nsITransaction *aTransaction, bool *_retval) { return _to WillRedo(aManager, aTransaction, _retval); } \
  NS_IMETHOD DidRedo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aRedoResult) { return _to DidRedo(aManager, aTransaction, aRedoResult); } \
  NS_IMETHOD WillBeginBatch(nsITransactionManager *aManager, bool *_retval) { return _to WillBeginBatch(aManager, _retval); } \
  NS_IMETHOD DidBeginBatch(nsITransactionManager *aManager, nsresult aResult) { return _to DidBeginBatch(aManager, aResult); } \
  NS_IMETHOD WillEndBatch(nsITransactionManager *aManager, bool *_retval) { return _to WillEndBatch(aManager, _retval); } \
  NS_IMETHOD DidEndBatch(nsITransactionManager *aManager, nsresult aResult) { return _to DidEndBatch(aManager, aResult); } \
  NS_IMETHOD WillMerge(nsITransactionManager *aManager, nsITransaction *aTopTransaction, nsITransaction *aTransactionToMerge, bool *_retval) { return _to WillMerge(aManager, aTopTransaction, aTransactionToMerge, _retval); } \
  NS_IMETHOD DidMerge(nsITransactionManager *aManager, nsITransaction *aTopTransaction, nsITransaction *aTransactionToMerge, bool aDidMerge, nsresult aMergeResult) { return _to DidMerge(aManager, aTopTransaction, aTransactionToMerge, aDidMerge, aMergeResult); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITRANSACTIONLISTENER(_to) \
  NS_IMETHOD WillDo(nsITransactionManager *aManager, nsITransaction *aTransaction, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillDo(aManager, aTransaction, _retval); } \
  NS_IMETHOD DidDo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aDoResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidDo(aManager, aTransaction, aDoResult); } \
  NS_IMETHOD WillUndo(nsITransactionManager *aManager, nsITransaction *aTransaction, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillUndo(aManager, aTransaction, _retval); } \
  NS_IMETHOD DidUndo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aUndoResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidUndo(aManager, aTransaction, aUndoResult); } \
  NS_IMETHOD WillRedo(nsITransactionManager *aManager, nsITransaction *aTransaction, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillRedo(aManager, aTransaction, _retval); } \
  NS_IMETHOD DidRedo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aRedoResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidRedo(aManager, aTransaction, aRedoResult); } \
  NS_IMETHOD WillBeginBatch(nsITransactionManager *aManager, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillBeginBatch(aManager, _retval); } \
  NS_IMETHOD DidBeginBatch(nsITransactionManager *aManager, nsresult aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidBeginBatch(aManager, aResult); } \
  NS_IMETHOD WillEndBatch(nsITransactionManager *aManager, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillEndBatch(aManager, _retval); } \
  NS_IMETHOD DidEndBatch(nsITransactionManager *aManager, nsresult aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidEndBatch(aManager, aResult); } \
  NS_IMETHOD WillMerge(nsITransactionManager *aManager, nsITransaction *aTopTransaction, nsITransaction *aTransactionToMerge, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillMerge(aManager, aTopTransaction, aTransactionToMerge, _retval); } \
  NS_IMETHOD DidMerge(nsITransactionManager *aManager, nsITransaction *aTopTransaction, nsITransaction *aTransactionToMerge, bool aDidMerge, nsresult aMergeResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidMerge(aManager, aTopTransaction, aTransactionToMerge, aDidMerge, aMergeResult); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTransactionListener : public nsITransactionListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITRANSACTIONLISTENER

  nsTransactionListener();

private:
  ~nsTransactionListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTransactionListener, nsITransactionListener)

nsTransactionListener::nsTransactionListener()
{
  /* member initializers and constructor code */
}

nsTransactionListener::~nsTransactionListener()
{
  /* destructor code */
}

/* boolean willDo (in nsITransactionManager aManager, in nsITransaction aTransaction); */
NS_IMETHODIMP nsTransactionListener::WillDo(nsITransactionManager *aManager, nsITransaction *aTransaction, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void didDo (in nsITransactionManager aManager, in nsITransaction aTransaction, in nsresult aDoResult); */
NS_IMETHODIMP nsTransactionListener::DidDo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aDoResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean willUndo (in nsITransactionManager aManager, in nsITransaction aTransaction); */
NS_IMETHODIMP nsTransactionListener::WillUndo(nsITransactionManager *aManager, nsITransaction *aTransaction, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void didUndo (in nsITransactionManager aManager, in nsITransaction aTransaction, in nsresult aUndoResult); */
NS_IMETHODIMP nsTransactionListener::DidUndo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aUndoResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean willRedo (in nsITransactionManager aManager, in nsITransaction aTransaction); */
NS_IMETHODIMP nsTransactionListener::WillRedo(nsITransactionManager *aManager, nsITransaction *aTransaction, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void didRedo (in nsITransactionManager aManager, in nsITransaction aTransaction, in nsresult aRedoResult); */
NS_IMETHODIMP nsTransactionListener::DidRedo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aRedoResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean willBeginBatch (in nsITransactionManager aManager); */
NS_IMETHODIMP nsTransactionListener::WillBeginBatch(nsITransactionManager *aManager, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void didBeginBatch (in nsITransactionManager aManager, in nsresult aResult); */
NS_IMETHODIMP nsTransactionListener::DidBeginBatch(nsITransactionManager *aManager, nsresult aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean willEndBatch (in nsITransactionManager aManager); */
NS_IMETHODIMP nsTransactionListener::WillEndBatch(nsITransactionManager *aManager, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void didEndBatch (in nsITransactionManager aManager, in nsresult aResult); */
NS_IMETHODIMP nsTransactionListener::DidEndBatch(nsITransactionManager *aManager, nsresult aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean willMerge (in nsITransactionManager aManager, in nsITransaction aTopTransaction, in nsITransaction aTransactionToMerge); */
NS_IMETHODIMP nsTransactionListener::WillMerge(nsITransactionManager *aManager, nsITransaction *aTopTransaction, nsITransaction *aTransactionToMerge, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void didMerge (in nsITransactionManager aManager, in nsITransaction aTopTransaction, in nsITransaction aTransactionToMerge, in boolean aDidMerge, in nsresult aMergeResult); */
NS_IMETHODIMP nsTransactionListener::DidMerge(nsITransactionManager *aManager, nsITransaction *aTopTransaction, nsITransaction *aTransactionToMerge, bool aDidMerge, nsresult aMergeResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITransactionListener_h__ */

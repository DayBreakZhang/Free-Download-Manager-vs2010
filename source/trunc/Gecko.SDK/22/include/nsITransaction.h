/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/editor/txmgr/idl/nsITransaction.idl
 */

#ifndef __gen_nsITransaction_h__
#define __gen_nsITransaction_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsITransaction */
#define NS_ITRANSACTION_IID_STR "58e330c1-7b48-11d2-98b9-00805f297d89"

#define NS_ITRANSACTION_IID \
  {0x58e330c1, 0x7b48, 0x11d2, \
    { 0x98, 0xb9, 0x00, 0x80, 0x5f, 0x29, 0x7d, 0x89 }}

class NS_NO_VTABLE nsITransaction : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITRANSACTION_IID)

  /* void doTransaction (); */
  NS_IMETHOD DoTransaction(void) = 0;

  /* void undoTransaction (); */
  NS_IMETHOD UndoTransaction(void) = 0;

  /* void redoTransaction (); */
  NS_IMETHOD RedoTransaction(void) = 0;

  /* readonly attribute boolean isTransient; */
  NS_IMETHOD GetIsTransient(bool *aIsTransient) = 0;

  /* boolean merge (in nsITransaction aTransaction); */
  NS_IMETHOD Merge(nsITransaction *aTransaction, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITransaction, NS_ITRANSACTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITRANSACTION \
  NS_IMETHOD DoTransaction(void); \
  NS_IMETHOD UndoTransaction(void); \
  NS_IMETHOD RedoTransaction(void); \
  NS_IMETHOD GetIsTransient(bool *aIsTransient); \
  NS_IMETHOD Merge(nsITransaction *aTransaction, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITRANSACTION(_to) \
  NS_IMETHOD DoTransaction(void) { return _to DoTransaction(); } \
  NS_IMETHOD UndoTransaction(void) { return _to UndoTransaction(); } \
  NS_IMETHOD RedoTransaction(void) { return _to RedoTransaction(); } \
  NS_IMETHOD GetIsTransient(bool *aIsTransient) { return _to GetIsTransient(aIsTransient); } \
  NS_IMETHOD Merge(nsITransaction *aTransaction, bool *_retval) { return _to Merge(aTransaction, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITRANSACTION(_to) \
  NS_IMETHOD DoTransaction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoTransaction(); } \
  NS_IMETHOD UndoTransaction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->UndoTransaction(); } \
  NS_IMETHOD RedoTransaction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RedoTransaction(); } \
  NS_IMETHOD GetIsTransient(bool *aIsTransient) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsTransient(aIsTransient); } \
  NS_IMETHOD Merge(nsITransaction *aTransaction, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Merge(aTransaction, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTransaction : public nsITransaction
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITRANSACTION

  nsTransaction();

private:
  ~nsTransaction();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTransaction, nsITransaction)

nsTransaction::nsTransaction()
{
  /* member initializers and constructor code */
}

nsTransaction::~nsTransaction()
{
  /* destructor code */
}

/* void doTransaction (); */
NS_IMETHODIMP nsTransaction::DoTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void undoTransaction (); */
NS_IMETHODIMP nsTransaction::UndoTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void redoTransaction (); */
NS_IMETHODIMP nsTransaction::RedoTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isTransient; */
NS_IMETHODIMP nsTransaction::GetIsTransient(bool *aIsTransient)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean merge (in nsITransaction aTransaction); */
NS_IMETHODIMP nsTransaction::Merge(nsITransaction *aTransaction, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITransaction_h__ */

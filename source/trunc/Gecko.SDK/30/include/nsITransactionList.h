/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITransactionList.idl
 */

#ifndef __gen_nsITransactionList_h__
#define __gen_nsITransactionList_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITransaction; /* forward declaration */


/* starting interface:    nsITransactionList */
#define NS_ITRANSACTIONLIST_IID_STR "d007ceff-c978-486a-b697-384ca01997be"

#define NS_ITRANSACTIONLIST_IID \
  {0xd007ceff, 0xc978, 0x486a, \
    { 0xb6, 0x97, 0x38, 0x4c, 0xa0, 0x19, 0x97, 0xbe }}

class NS_NO_VTABLE nsITransactionList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITRANSACTIONLIST_IID)

  /* readonly attribute long numItems; */
  NS_IMETHOD GetNumItems(int32_t *aNumItems) = 0;

  /* boolean itemIsBatch (in long aIndex); */
  NS_IMETHOD ItemIsBatch(int32_t aIndex, bool *_retval) = 0;

  /* nsITransaction getItem (in long aIndex); */
  NS_IMETHOD GetItem(int32_t aIndex, nsITransaction * *_retval) = 0;

  /* void getData (in long aIndex, [optional] out unsigned long aLength, [array, size_is (aLength), retval] out nsISupports aData); */
  NS_IMETHOD GetData(int32_t aIndex, uint32_t *aLength, nsISupports * **aData) = 0;

  /* long getNumChildrenForItem (in long aIndex); */
  NS_IMETHOD GetNumChildrenForItem(int32_t aIndex, int32_t *_retval) = 0;

  /* nsITransactionList getChildListForItem (in long aIndex); */
  NS_IMETHOD GetChildListForItem(int32_t aIndex, nsITransactionList * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITransactionList, NS_ITRANSACTIONLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITRANSACTIONLIST \
  NS_IMETHOD GetNumItems(int32_t *aNumItems); \
  NS_IMETHOD ItemIsBatch(int32_t aIndex, bool *_retval); \
  NS_IMETHOD GetItem(int32_t aIndex, nsITransaction * *_retval); \
  NS_IMETHOD GetData(int32_t aIndex, uint32_t *aLength, nsISupports * **aData); \
  NS_IMETHOD GetNumChildrenForItem(int32_t aIndex, int32_t *_retval); \
  NS_IMETHOD GetChildListForItem(int32_t aIndex, nsITransactionList * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITRANSACTIONLIST(_to) \
  NS_IMETHOD GetNumItems(int32_t *aNumItems) { return _to GetNumItems(aNumItems); } \
  NS_IMETHOD ItemIsBatch(int32_t aIndex, bool *_retval) { return _to ItemIsBatch(aIndex, _retval); } \
  NS_IMETHOD GetItem(int32_t aIndex, nsITransaction * *_retval) { return _to GetItem(aIndex, _retval); } \
  NS_IMETHOD GetData(int32_t aIndex, uint32_t *aLength, nsISupports * **aData) { return _to GetData(aIndex, aLength, aData); } \
  NS_IMETHOD GetNumChildrenForItem(int32_t aIndex, int32_t *_retval) { return _to GetNumChildrenForItem(aIndex, _retval); } \
  NS_IMETHOD GetChildListForItem(int32_t aIndex, nsITransactionList * *_retval) { return _to GetChildListForItem(aIndex, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITRANSACTIONLIST(_to) \
  NS_IMETHOD GetNumItems(int32_t *aNumItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumItems(aNumItems); } \
  NS_IMETHOD ItemIsBatch(int32_t aIndex, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ItemIsBatch(aIndex, _retval); } \
  NS_IMETHOD GetItem(int32_t aIndex, nsITransaction * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItem(aIndex, _retval); } \
  NS_IMETHOD GetData(int32_t aIndex, uint32_t *aLength, nsISupports * **aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aIndex, aLength, aData); } \
  NS_IMETHOD GetNumChildrenForItem(int32_t aIndex, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumChildrenForItem(aIndex, _retval); } \
  NS_IMETHOD GetChildListForItem(int32_t aIndex, nsITransactionList * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildListForItem(aIndex, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTransactionList : public nsITransactionList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITRANSACTIONLIST

  nsTransactionList();

private:
  ~nsTransactionList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTransactionList, nsITransactionList)

nsTransactionList::nsTransactionList()
{
  /* member initializers and constructor code */
}

nsTransactionList::~nsTransactionList()
{
  /* destructor code */
}

/* readonly attribute long numItems; */
NS_IMETHODIMP nsTransactionList::GetNumItems(int32_t *aNumItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean itemIsBatch (in long aIndex); */
NS_IMETHODIMP nsTransactionList::ItemIsBatch(int32_t aIndex, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITransaction getItem (in long aIndex); */
NS_IMETHODIMP nsTransactionList::GetItem(int32_t aIndex, nsITransaction * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getData (in long aIndex, [optional] out unsigned long aLength, [array, size_is (aLength), retval] out nsISupports aData); */
NS_IMETHODIMP nsTransactionList::GetData(int32_t aIndex, uint32_t *aLength, nsISupports * **aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getNumChildrenForItem (in long aIndex); */
NS_IMETHODIMP nsTransactionList::GetNumChildrenForItem(int32_t aIndex, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITransactionList getChildListForItem (in long aIndex); */
NS_IMETHODIMP nsTransactionList::GetChildListForItem(int32_t aIndex, nsITransactionList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITransactionList_h__ */

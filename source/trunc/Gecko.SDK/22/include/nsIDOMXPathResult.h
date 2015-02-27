/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/xpath/nsIDOMXPathResult.idl
 */

#ifndef __gen_nsIDOMXPathResult_h__
#define __gen_nsIDOMXPathResult_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class XPathException; /* forward declaration */


/* starting interface:    nsIDOMXPathResult */
#define NS_IDOMXPATHRESULT_IID_STR "75506f84-b504-11d5-a7f2-ca108ab8b6fc"

#define NS_IDOMXPATHRESULT_IID \
  {0x75506f84, 0xb504, 0x11d5, \
    { 0xa7, 0xf2, 0xca, 0x10, 0x8a, 0xb8, 0xb6, 0xfc }}

class NS_NO_VTABLE nsIDOMXPathResult : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXPATHRESULT_IID)

  enum {
    ANY_TYPE = 0U,
    NUMBER_TYPE = 1U,
    STRING_TYPE = 2U,
    BOOLEAN_TYPE = 3U,
    UNORDERED_NODE_ITERATOR_TYPE = 4U,
    ORDERED_NODE_ITERATOR_TYPE = 5U,
    UNORDERED_NODE_SNAPSHOT_TYPE = 6U,
    ORDERED_NODE_SNAPSHOT_TYPE = 7U,
    ANY_UNORDERED_NODE_TYPE = 8U,
    FIRST_ORDERED_NODE_TYPE = 9U
  };

  /* readonly attribute unsigned short resultType; */
  NS_IMETHOD GetResultType(uint16_t *aResultType) = 0;

  /* readonly attribute double numberValue; */
  NS_IMETHOD GetNumberValue(double *aNumberValue) = 0;

  /* readonly attribute DOMString stringValue; */
  NS_IMETHOD GetStringValue(nsAString & aStringValue) = 0;

  /* readonly attribute boolean booleanValue; */
  NS_IMETHOD GetBooleanValue(bool *aBooleanValue) = 0;

  /* readonly attribute nsIDOMNode singleNodeValue; */
  NS_IMETHOD GetSingleNodeValue(nsIDOMNode * *aSingleNodeValue) = 0;

  /* readonly attribute boolean invalidIteratorState; */
  NS_IMETHOD GetInvalidIteratorState(bool *aInvalidIteratorState) = 0;

  /* readonly attribute unsigned long snapshotLength; */
  NS_IMETHOD GetSnapshotLength(uint32_t *aSnapshotLength) = 0;

  /* nsIDOMNode iterateNext () raises (XPathException,DOMException); */
  NS_IMETHOD IterateNext(nsIDOMNode * *_retval) = 0;

  /* nsIDOMNode snapshotItem (in unsigned long index) raises (XPathException); */
  NS_IMETHOD SnapshotItem(uint32_t index, nsIDOMNode * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXPathResult, NS_IDOMXPATHRESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXPATHRESULT \
  NS_IMETHOD GetResultType(uint16_t *aResultType); \
  NS_IMETHOD GetNumberValue(double *aNumberValue); \
  NS_IMETHOD GetStringValue(nsAString & aStringValue); \
  NS_IMETHOD GetBooleanValue(bool *aBooleanValue); \
  NS_IMETHOD GetSingleNodeValue(nsIDOMNode * *aSingleNodeValue); \
  NS_IMETHOD GetInvalidIteratorState(bool *aInvalidIteratorState); \
  NS_IMETHOD GetSnapshotLength(uint32_t *aSnapshotLength); \
  NS_IMETHOD IterateNext(nsIDOMNode * *_retval); \
  NS_IMETHOD SnapshotItem(uint32_t index, nsIDOMNode * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXPATHRESULT(_to) \
  NS_IMETHOD GetResultType(uint16_t *aResultType) { return _to GetResultType(aResultType); } \
  NS_IMETHOD GetNumberValue(double *aNumberValue) { return _to GetNumberValue(aNumberValue); } \
  NS_IMETHOD GetStringValue(nsAString & aStringValue) { return _to GetStringValue(aStringValue); } \
  NS_IMETHOD GetBooleanValue(bool *aBooleanValue) { return _to GetBooleanValue(aBooleanValue); } \
  NS_IMETHOD GetSingleNodeValue(nsIDOMNode * *aSingleNodeValue) { return _to GetSingleNodeValue(aSingleNodeValue); } \
  NS_IMETHOD GetInvalidIteratorState(bool *aInvalidIteratorState) { return _to GetInvalidIteratorState(aInvalidIteratorState); } \
  NS_IMETHOD GetSnapshotLength(uint32_t *aSnapshotLength) { return _to GetSnapshotLength(aSnapshotLength); } \
  NS_IMETHOD IterateNext(nsIDOMNode * *_retval) { return _to IterateNext(_retval); } \
  NS_IMETHOD SnapshotItem(uint32_t index, nsIDOMNode * *_retval) { return _to SnapshotItem(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXPATHRESULT(_to) \
  NS_IMETHOD GetResultType(uint16_t *aResultType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResultType(aResultType); } \
  NS_IMETHOD GetNumberValue(double *aNumberValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumberValue(aNumberValue); } \
  NS_IMETHOD GetStringValue(nsAString & aStringValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringValue(aStringValue); } \
  NS_IMETHOD GetBooleanValue(bool *aBooleanValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBooleanValue(aBooleanValue); } \
  NS_IMETHOD GetSingleNodeValue(nsIDOMNode * *aSingleNodeValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSingleNodeValue(aSingleNodeValue); } \
  NS_IMETHOD GetInvalidIteratorState(bool *aInvalidIteratorState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInvalidIteratorState(aInvalidIteratorState); } \
  NS_IMETHOD GetSnapshotLength(uint32_t *aSnapshotLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSnapshotLength(aSnapshotLength); } \
  NS_IMETHOD IterateNext(nsIDOMNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IterateNext(_retval); } \
  NS_IMETHOD SnapshotItem(uint32_t index, nsIDOMNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SnapshotItem(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXPathResult : public nsIDOMXPathResult
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXPATHRESULT

  nsDOMXPathResult();

private:
  ~nsDOMXPathResult();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXPathResult, nsIDOMXPathResult)

nsDOMXPathResult::nsDOMXPathResult()
{
  /* member initializers and constructor code */
}

nsDOMXPathResult::~nsDOMXPathResult()
{
  /* destructor code */
}

/* readonly attribute unsigned short resultType; */
NS_IMETHODIMP nsDOMXPathResult::GetResultType(uint16_t *aResultType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double numberValue; */
NS_IMETHODIMP nsDOMXPathResult::GetNumberValue(double *aNumberValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString stringValue; */
NS_IMETHODIMP nsDOMXPathResult::GetStringValue(nsAString & aStringValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean booleanValue; */
NS_IMETHODIMP nsDOMXPathResult::GetBooleanValue(bool *aBooleanValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode singleNodeValue; */
NS_IMETHODIMP nsDOMXPathResult::GetSingleNodeValue(nsIDOMNode * *aSingleNodeValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean invalidIteratorState; */
NS_IMETHODIMP nsDOMXPathResult::GetInvalidIteratorState(bool *aInvalidIteratorState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long snapshotLength; */
NS_IMETHODIMP nsDOMXPathResult::GetSnapshotLength(uint32_t *aSnapshotLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode iterateNext () raises (XPathException,DOMException); */
NS_IMETHODIMP nsDOMXPathResult::IterateNext(nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode snapshotItem (in unsigned long index) raises (XPathException); */
NS_IMETHODIMP nsDOMXPathResult::SnapshotItem(uint32_t index, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXPathResult_h__ */

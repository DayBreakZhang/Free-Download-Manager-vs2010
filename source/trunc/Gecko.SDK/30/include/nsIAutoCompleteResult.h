/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAutoCompleteResult.idl
 */

#ifndef __gen_nsIAutoCompleteResult_h__
#define __gen_nsIAutoCompleteResult_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAutoCompleteResult */
#define NS_IAUTOCOMPLETERESULT_IID_STR "7b43fad1-c735-4b45-9383-c3f057fed20d"

#define NS_IAUTOCOMPLETERESULT_IID \
  {0x7b43fad1, 0xc735, 0x4b45, \
    { 0x93, 0x83, 0xc3, 0xf0, 0x57, 0xfe, 0xd2, 0x0d }}

class NS_NO_VTABLE nsIAutoCompleteResult : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTOCOMPLETERESULT_IID)

  enum {
    RESULT_IGNORED = 1U,
    RESULT_FAILURE = 2U,
    RESULT_NOMATCH = 3U,
    RESULT_SUCCESS = 4U,
    RESULT_NOMATCH_ONGOING = 5U,
    RESULT_SUCCESS_ONGOING = 6U
  };

  /* readonly attribute AString searchString; */
  NS_IMETHOD GetSearchString(nsAString & aSearchString) = 0;

  /* readonly attribute unsigned short searchResult; */
  NS_IMETHOD GetSearchResult(uint16_t *aSearchResult) = 0;

  /* readonly attribute long defaultIndex; */
  NS_IMETHOD GetDefaultIndex(int32_t *aDefaultIndex) = 0;

  /* readonly attribute AString errorDescription; */
  NS_IMETHOD GetErrorDescription(nsAString & aErrorDescription) = 0;

  /* readonly attribute unsigned long matchCount; */
  NS_IMETHOD GetMatchCount(uint32_t *aMatchCount) = 0;

  /* readonly attribute boolean typeAheadResult; */
  NS_IMETHOD GetTypeAheadResult(bool *aTypeAheadResult) = 0;

  /* AString getValueAt (in long index); */
  NS_IMETHOD GetValueAt(int32_t index, nsAString & _retval) = 0;

  /* AString getLabelAt (in long index); */
  NS_IMETHOD GetLabelAt(int32_t index, nsAString & _retval) = 0;

  /* AString getCommentAt (in long index); */
  NS_IMETHOD GetCommentAt(int32_t index, nsAString & _retval) = 0;

  /* AString getStyleAt (in long index); */
  NS_IMETHOD GetStyleAt(int32_t index, nsAString & _retval) = 0;

  /* AString getImageAt (in long index); */
  NS_IMETHOD GetImageAt(int32_t index, nsAString & _retval) = 0;

  /* void removeValueAt (in long rowIndex, in boolean removeFromDb); */
  NS_IMETHOD RemoveValueAt(int32_t rowIndex, bool removeFromDb) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAutoCompleteResult, NS_IAUTOCOMPLETERESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTOCOMPLETERESULT \
  NS_IMETHOD GetSearchString(nsAString & aSearchString); \
  NS_IMETHOD GetSearchResult(uint16_t *aSearchResult); \
  NS_IMETHOD GetDefaultIndex(int32_t *aDefaultIndex); \
  NS_IMETHOD GetErrorDescription(nsAString & aErrorDescription); \
  NS_IMETHOD GetMatchCount(uint32_t *aMatchCount); \
  NS_IMETHOD GetTypeAheadResult(bool *aTypeAheadResult); \
  NS_IMETHOD GetValueAt(int32_t index, nsAString & _retval); \
  NS_IMETHOD GetLabelAt(int32_t index, nsAString & _retval); \
  NS_IMETHOD GetCommentAt(int32_t index, nsAString & _retval); \
  NS_IMETHOD GetStyleAt(int32_t index, nsAString & _retval); \
  NS_IMETHOD GetImageAt(int32_t index, nsAString & _retval); \
  NS_IMETHOD RemoveValueAt(int32_t rowIndex, bool removeFromDb); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTOCOMPLETERESULT(_to) \
  NS_IMETHOD GetSearchString(nsAString & aSearchString) { return _to GetSearchString(aSearchString); } \
  NS_IMETHOD GetSearchResult(uint16_t *aSearchResult) { return _to GetSearchResult(aSearchResult); } \
  NS_IMETHOD GetDefaultIndex(int32_t *aDefaultIndex) { return _to GetDefaultIndex(aDefaultIndex); } \
  NS_IMETHOD GetErrorDescription(nsAString & aErrorDescription) { return _to GetErrorDescription(aErrorDescription); } \
  NS_IMETHOD GetMatchCount(uint32_t *aMatchCount) { return _to GetMatchCount(aMatchCount); } \
  NS_IMETHOD GetTypeAheadResult(bool *aTypeAheadResult) { return _to GetTypeAheadResult(aTypeAheadResult); } \
  NS_IMETHOD GetValueAt(int32_t index, nsAString & _retval) { return _to GetValueAt(index, _retval); } \
  NS_IMETHOD GetLabelAt(int32_t index, nsAString & _retval) { return _to GetLabelAt(index, _retval); } \
  NS_IMETHOD GetCommentAt(int32_t index, nsAString & _retval) { return _to GetCommentAt(index, _retval); } \
  NS_IMETHOD GetStyleAt(int32_t index, nsAString & _retval) { return _to GetStyleAt(index, _retval); } \
  NS_IMETHOD GetImageAt(int32_t index, nsAString & _retval) { return _to GetImageAt(index, _retval); } \
  NS_IMETHOD RemoveValueAt(int32_t rowIndex, bool removeFromDb) { return _to RemoveValueAt(rowIndex, removeFromDb); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTOCOMPLETERESULT(_to) \
  NS_IMETHOD GetSearchString(nsAString & aSearchString) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchString(aSearchString); } \
  NS_IMETHOD GetSearchResult(uint16_t *aSearchResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchResult(aSearchResult); } \
  NS_IMETHOD GetDefaultIndex(int32_t *aDefaultIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultIndex(aDefaultIndex); } \
  NS_IMETHOD GetErrorDescription(nsAString & aErrorDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetErrorDescription(aErrorDescription); } \
  NS_IMETHOD GetMatchCount(uint32_t *aMatchCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMatchCount(aMatchCount); } \
  NS_IMETHOD GetTypeAheadResult(bool *aTypeAheadResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypeAheadResult(aTypeAheadResult); } \
  NS_IMETHOD GetValueAt(int32_t index, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueAt(index, _retval); } \
  NS_IMETHOD GetLabelAt(int32_t index, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLabelAt(index, _retval); } \
  NS_IMETHOD GetCommentAt(int32_t index, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCommentAt(index, _retval); } \
  NS_IMETHOD GetStyleAt(int32_t index, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStyleAt(index, _retval); } \
  NS_IMETHOD GetImageAt(int32_t index, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageAt(index, _retval); } \
  NS_IMETHOD RemoveValueAt(int32_t rowIndex, bool removeFromDb) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveValueAt(rowIndex, removeFromDb); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAutoCompleteResult : public nsIAutoCompleteResult
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTOCOMPLETERESULT

  nsAutoCompleteResult();

private:
  ~nsAutoCompleteResult();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAutoCompleteResult, nsIAutoCompleteResult)

nsAutoCompleteResult::nsAutoCompleteResult()
{
  /* member initializers and constructor code */
}

nsAutoCompleteResult::~nsAutoCompleteResult()
{
  /* destructor code */
}

/* readonly attribute AString searchString; */
NS_IMETHODIMP nsAutoCompleteResult::GetSearchString(nsAString & aSearchString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short searchResult; */
NS_IMETHODIMP nsAutoCompleteResult::GetSearchResult(uint16_t *aSearchResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long defaultIndex; */
NS_IMETHODIMP nsAutoCompleteResult::GetDefaultIndex(int32_t *aDefaultIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString errorDescription; */
NS_IMETHODIMP nsAutoCompleteResult::GetErrorDescription(nsAString & aErrorDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long matchCount; */
NS_IMETHODIMP nsAutoCompleteResult::GetMatchCount(uint32_t *aMatchCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean typeAheadResult; */
NS_IMETHODIMP nsAutoCompleteResult::GetTypeAheadResult(bool *aTypeAheadResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getValueAt (in long index); */
NS_IMETHODIMP nsAutoCompleteResult::GetValueAt(int32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getLabelAt (in long index); */
NS_IMETHODIMP nsAutoCompleteResult::GetLabelAt(int32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getCommentAt (in long index); */
NS_IMETHODIMP nsAutoCompleteResult::GetCommentAt(int32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getStyleAt (in long index); */
NS_IMETHODIMP nsAutoCompleteResult::GetStyleAt(int32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getImageAt (in long index); */
NS_IMETHODIMP nsAutoCompleteResult::GetImageAt(int32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeValueAt (in long rowIndex, in boolean removeFromDb); */
NS_IMETHODIMP nsAutoCompleteResult::RemoveValueAt(int32_t rowIndex, bool removeFromDb)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAutoCompleteResult_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/toolkit/components/autocomplete/nsIAutoCompleteInput.idl
 */

#ifndef __gen_nsIAutoCompleteInput_h__
#define __gen_nsIAutoCompleteInput_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIAutoCompleteController_h__
#include "nsIAutoCompleteController.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAutoCompletePopup; /* forward declaration */


/* starting interface:    nsIAutoCompleteInput */
#define NS_IAUTOCOMPLETEINPUT_IID_STR "fadb2bb9-3e2e-4ca0-b0e0-0982b8dda9dc"

#define NS_IAUTOCOMPLETEINPUT_IID \
  {0xfadb2bb9, 0x3e2e, 0x4ca0, \
    { 0xb0, 0xe0, 0x09, 0x82, 0xb8, 0xdd, 0xa9, 0xdc }}

class NS_NO_VTABLE nsIAutoCompleteInput : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTOCOMPLETEINPUT_IID)

  /* readonly attribute nsIAutoCompletePopup popup; */
  NS_IMETHOD GetPopup(nsIAutoCompletePopup * *aPopup) = 0;

  /* readonly attribute nsIAutoCompleteController controller; */
  NS_IMETHOD GetController(nsIAutoCompleteController * *aController) = 0;

  /* attribute boolean popupOpen; */
  NS_IMETHOD GetPopupOpen(bool *aPopupOpen) = 0;
  NS_IMETHOD SetPopupOpen(bool aPopupOpen) = 0;

  /* attribute boolean disableAutoComplete; */
  NS_IMETHOD GetDisableAutoComplete(bool *aDisableAutoComplete) = 0;
  NS_IMETHOD SetDisableAutoComplete(bool aDisableAutoComplete) = 0;

  /* attribute boolean completeDefaultIndex; */
  NS_IMETHOD GetCompleteDefaultIndex(bool *aCompleteDefaultIndex) = 0;
  NS_IMETHOD SetCompleteDefaultIndex(bool aCompleteDefaultIndex) = 0;

  /* attribute boolean completeSelectedIndex; */
  NS_IMETHOD GetCompleteSelectedIndex(bool *aCompleteSelectedIndex) = 0;
  NS_IMETHOD SetCompleteSelectedIndex(bool aCompleteSelectedIndex) = 0;

  /* attribute boolean forceComplete; */
  NS_IMETHOD GetForceComplete(bool *aForceComplete) = 0;
  NS_IMETHOD SetForceComplete(bool aForceComplete) = 0;

  /* attribute unsigned long minResultsForPopup; */
  NS_IMETHOD GetMinResultsForPopup(uint32_t *aMinResultsForPopup) = 0;
  NS_IMETHOD SetMinResultsForPopup(uint32_t aMinResultsForPopup) = 0;

  /* attribute unsigned long maxRows; */
  NS_IMETHOD GetMaxRows(uint32_t *aMaxRows) = 0;
  NS_IMETHOD SetMaxRows(uint32_t aMaxRows) = 0;

  /* attribute boolean showCommentColumn; */
  NS_IMETHOD GetShowCommentColumn(bool *aShowCommentColumn) = 0;
  NS_IMETHOD SetShowCommentColumn(bool aShowCommentColumn) = 0;

  /* attribute boolean showImageColumn; */
  NS_IMETHOD GetShowImageColumn(bool *aShowImageColumn) = 0;
  NS_IMETHOD SetShowImageColumn(bool aShowImageColumn) = 0;

  /* attribute unsigned long timeout; */
  NS_IMETHOD GetTimeout(uint32_t *aTimeout) = 0;
  NS_IMETHOD SetTimeout(uint32_t aTimeout) = 0;

  /* attribute AString searchParam; */
  NS_IMETHOD GetSearchParam(nsAString & aSearchParam) = 0;
  NS_IMETHOD SetSearchParam(const nsAString & aSearchParam) = 0;

  /* readonly attribute unsigned long searchCount; */
  NS_IMETHOD GetSearchCount(uint32_t *aSearchCount) = 0;

  /* ACString getSearchAt (in unsigned long index); */
  NS_IMETHOD GetSearchAt(uint32_t index, nsACString & _retval) = 0;

  /* attribute AString textValue; */
  NS_IMETHOD GetTextValue(nsAString & aTextValue) = 0;
  NS_IMETHOD SetTextValue(const nsAString & aTextValue) = 0;

  /* readonly attribute long selectionStart; */
  NS_IMETHOD GetSelectionStart(int32_t *aSelectionStart) = 0;

  /* readonly attribute long selectionEnd; */
  NS_IMETHOD GetSelectionEnd(int32_t *aSelectionEnd) = 0;

  /* void selectTextRange (in long startIndex, in long endIndex); */
  NS_IMETHOD SelectTextRange(int32_t startIndex, int32_t endIndex) = 0;

  /* void onSearchBegin (); */
  NS_IMETHOD OnSearchBegin(void) = 0;

  /* void onSearchComplete (); */
  NS_IMETHOD OnSearchComplete(void) = 0;

  /* boolean onTextEntered (); */
  NS_IMETHOD OnTextEntered(bool *_retval) = 0;

  /* boolean onTextReverted (); */
  NS_IMETHOD OnTextReverted(bool *_retval) = 0;

  /* readonly attribute boolean consumeRollupEvent; */
  NS_IMETHOD GetConsumeRollupEvent(bool *aConsumeRollupEvent) = 0;

  /* readonly attribute boolean inPrivateContext; */
  NS_IMETHOD GetInPrivateContext(bool *aInPrivateContext) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAutoCompleteInput, NS_IAUTOCOMPLETEINPUT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTOCOMPLETEINPUT \
  NS_IMETHOD GetPopup(nsIAutoCompletePopup * *aPopup); \
  NS_IMETHOD GetController(nsIAutoCompleteController * *aController); \
  NS_IMETHOD GetPopupOpen(bool *aPopupOpen); \
  NS_IMETHOD SetPopupOpen(bool aPopupOpen); \
  NS_IMETHOD GetDisableAutoComplete(bool *aDisableAutoComplete); \
  NS_IMETHOD SetDisableAutoComplete(bool aDisableAutoComplete); \
  NS_IMETHOD GetCompleteDefaultIndex(bool *aCompleteDefaultIndex); \
  NS_IMETHOD SetCompleteDefaultIndex(bool aCompleteDefaultIndex); \
  NS_IMETHOD GetCompleteSelectedIndex(bool *aCompleteSelectedIndex); \
  NS_IMETHOD SetCompleteSelectedIndex(bool aCompleteSelectedIndex); \
  NS_IMETHOD GetForceComplete(bool *aForceComplete); \
  NS_IMETHOD SetForceComplete(bool aForceComplete); \
  NS_IMETHOD GetMinResultsForPopup(uint32_t *aMinResultsForPopup); \
  NS_IMETHOD SetMinResultsForPopup(uint32_t aMinResultsForPopup); \
  NS_IMETHOD GetMaxRows(uint32_t *aMaxRows); \
  NS_IMETHOD SetMaxRows(uint32_t aMaxRows); \
  NS_IMETHOD GetShowCommentColumn(bool *aShowCommentColumn); \
  NS_IMETHOD SetShowCommentColumn(bool aShowCommentColumn); \
  NS_IMETHOD GetShowImageColumn(bool *aShowImageColumn); \
  NS_IMETHOD SetShowImageColumn(bool aShowImageColumn); \
  NS_IMETHOD GetTimeout(uint32_t *aTimeout); \
  NS_IMETHOD SetTimeout(uint32_t aTimeout); \
  NS_IMETHOD GetSearchParam(nsAString & aSearchParam); \
  NS_IMETHOD SetSearchParam(const nsAString & aSearchParam); \
  NS_IMETHOD GetSearchCount(uint32_t *aSearchCount); \
  NS_IMETHOD GetSearchAt(uint32_t index, nsACString & _retval); \
  NS_IMETHOD GetTextValue(nsAString & aTextValue); \
  NS_IMETHOD SetTextValue(const nsAString & aTextValue); \
  NS_IMETHOD GetSelectionStart(int32_t *aSelectionStart); \
  NS_IMETHOD GetSelectionEnd(int32_t *aSelectionEnd); \
  NS_IMETHOD SelectTextRange(int32_t startIndex, int32_t endIndex); \
  NS_IMETHOD OnSearchBegin(void); \
  NS_IMETHOD OnSearchComplete(void); \
  NS_IMETHOD OnTextEntered(bool *_retval); \
  NS_IMETHOD OnTextReverted(bool *_retval); \
  NS_IMETHOD GetConsumeRollupEvent(bool *aConsumeRollupEvent); \
  NS_IMETHOD GetInPrivateContext(bool *aInPrivateContext); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTOCOMPLETEINPUT(_to) \
  NS_IMETHOD GetPopup(nsIAutoCompletePopup * *aPopup) { return _to GetPopup(aPopup); } \
  NS_IMETHOD GetController(nsIAutoCompleteController * *aController) { return _to GetController(aController); } \
  NS_IMETHOD GetPopupOpen(bool *aPopupOpen) { return _to GetPopupOpen(aPopupOpen); } \
  NS_IMETHOD SetPopupOpen(bool aPopupOpen) { return _to SetPopupOpen(aPopupOpen); } \
  NS_IMETHOD GetDisableAutoComplete(bool *aDisableAutoComplete) { return _to GetDisableAutoComplete(aDisableAutoComplete); } \
  NS_IMETHOD SetDisableAutoComplete(bool aDisableAutoComplete) { return _to SetDisableAutoComplete(aDisableAutoComplete); } \
  NS_IMETHOD GetCompleteDefaultIndex(bool *aCompleteDefaultIndex) { return _to GetCompleteDefaultIndex(aCompleteDefaultIndex); } \
  NS_IMETHOD SetCompleteDefaultIndex(bool aCompleteDefaultIndex) { return _to SetCompleteDefaultIndex(aCompleteDefaultIndex); } \
  NS_IMETHOD GetCompleteSelectedIndex(bool *aCompleteSelectedIndex) { return _to GetCompleteSelectedIndex(aCompleteSelectedIndex); } \
  NS_IMETHOD SetCompleteSelectedIndex(bool aCompleteSelectedIndex) { return _to SetCompleteSelectedIndex(aCompleteSelectedIndex); } \
  NS_IMETHOD GetForceComplete(bool *aForceComplete) { return _to GetForceComplete(aForceComplete); } \
  NS_IMETHOD SetForceComplete(bool aForceComplete) { return _to SetForceComplete(aForceComplete); } \
  NS_IMETHOD GetMinResultsForPopup(uint32_t *aMinResultsForPopup) { return _to GetMinResultsForPopup(aMinResultsForPopup); } \
  NS_IMETHOD SetMinResultsForPopup(uint32_t aMinResultsForPopup) { return _to SetMinResultsForPopup(aMinResultsForPopup); } \
  NS_IMETHOD GetMaxRows(uint32_t *aMaxRows) { return _to GetMaxRows(aMaxRows); } \
  NS_IMETHOD SetMaxRows(uint32_t aMaxRows) { return _to SetMaxRows(aMaxRows); } \
  NS_IMETHOD GetShowCommentColumn(bool *aShowCommentColumn) { return _to GetShowCommentColumn(aShowCommentColumn); } \
  NS_IMETHOD SetShowCommentColumn(bool aShowCommentColumn) { return _to SetShowCommentColumn(aShowCommentColumn); } \
  NS_IMETHOD GetShowImageColumn(bool *aShowImageColumn) { return _to GetShowImageColumn(aShowImageColumn); } \
  NS_IMETHOD SetShowImageColumn(bool aShowImageColumn) { return _to SetShowImageColumn(aShowImageColumn); } \
  NS_IMETHOD GetTimeout(uint32_t *aTimeout) { return _to GetTimeout(aTimeout); } \
  NS_IMETHOD SetTimeout(uint32_t aTimeout) { return _to SetTimeout(aTimeout); } \
  NS_IMETHOD GetSearchParam(nsAString & aSearchParam) { return _to GetSearchParam(aSearchParam); } \
  NS_IMETHOD SetSearchParam(const nsAString & aSearchParam) { return _to SetSearchParam(aSearchParam); } \
  NS_IMETHOD GetSearchCount(uint32_t *aSearchCount) { return _to GetSearchCount(aSearchCount); } \
  NS_IMETHOD GetSearchAt(uint32_t index, nsACString & _retval) { return _to GetSearchAt(index, _retval); } \
  NS_IMETHOD GetTextValue(nsAString & aTextValue) { return _to GetTextValue(aTextValue); } \
  NS_IMETHOD SetTextValue(const nsAString & aTextValue) { return _to SetTextValue(aTextValue); } \
  NS_IMETHOD GetSelectionStart(int32_t *aSelectionStart) { return _to GetSelectionStart(aSelectionStart); } \
  NS_IMETHOD GetSelectionEnd(int32_t *aSelectionEnd) { return _to GetSelectionEnd(aSelectionEnd); } \
  NS_IMETHOD SelectTextRange(int32_t startIndex, int32_t endIndex) { return _to SelectTextRange(startIndex, endIndex); } \
  NS_IMETHOD OnSearchBegin(void) { return _to OnSearchBegin(); } \
  NS_IMETHOD OnSearchComplete(void) { return _to OnSearchComplete(); } \
  NS_IMETHOD OnTextEntered(bool *_retval) { return _to OnTextEntered(_retval); } \
  NS_IMETHOD OnTextReverted(bool *_retval) { return _to OnTextReverted(_retval); } \
  NS_IMETHOD GetConsumeRollupEvent(bool *aConsumeRollupEvent) { return _to GetConsumeRollupEvent(aConsumeRollupEvent); } \
  NS_IMETHOD GetInPrivateContext(bool *aInPrivateContext) { return _to GetInPrivateContext(aInPrivateContext); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTOCOMPLETEINPUT(_to) \
  NS_IMETHOD GetPopup(nsIAutoCompletePopup * *aPopup) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPopup(aPopup); } \
  NS_IMETHOD GetController(nsIAutoCompleteController * *aController) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetController(aController); } \
  NS_IMETHOD GetPopupOpen(bool *aPopupOpen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPopupOpen(aPopupOpen); } \
  NS_IMETHOD SetPopupOpen(bool aPopupOpen) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPopupOpen(aPopupOpen); } \
  NS_IMETHOD GetDisableAutoComplete(bool *aDisableAutoComplete) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisableAutoComplete(aDisableAutoComplete); } \
  NS_IMETHOD SetDisableAutoComplete(bool aDisableAutoComplete) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisableAutoComplete(aDisableAutoComplete); } \
  NS_IMETHOD GetCompleteDefaultIndex(bool *aCompleteDefaultIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCompleteDefaultIndex(aCompleteDefaultIndex); } \
  NS_IMETHOD SetCompleteDefaultIndex(bool aCompleteDefaultIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCompleteDefaultIndex(aCompleteDefaultIndex); } \
  NS_IMETHOD GetCompleteSelectedIndex(bool *aCompleteSelectedIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCompleteSelectedIndex(aCompleteSelectedIndex); } \
  NS_IMETHOD SetCompleteSelectedIndex(bool aCompleteSelectedIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCompleteSelectedIndex(aCompleteSelectedIndex); } \
  NS_IMETHOD GetForceComplete(bool *aForceComplete) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForceComplete(aForceComplete); } \
  NS_IMETHOD SetForceComplete(bool aForceComplete) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetForceComplete(aForceComplete); } \
  NS_IMETHOD GetMinResultsForPopup(uint32_t *aMinResultsForPopup) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMinResultsForPopup(aMinResultsForPopup); } \
  NS_IMETHOD SetMinResultsForPopup(uint32_t aMinResultsForPopup) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMinResultsForPopup(aMinResultsForPopup); } \
  NS_IMETHOD GetMaxRows(uint32_t *aMaxRows) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxRows(aMaxRows); } \
  NS_IMETHOD SetMaxRows(uint32_t aMaxRows) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMaxRows(aMaxRows); } \
  NS_IMETHOD GetShowCommentColumn(bool *aShowCommentColumn) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShowCommentColumn(aShowCommentColumn); } \
  NS_IMETHOD SetShowCommentColumn(bool aShowCommentColumn) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShowCommentColumn(aShowCommentColumn); } \
  NS_IMETHOD GetShowImageColumn(bool *aShowImageColumn) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShowImageColumn(aShowImageColumn); } \
  NS_IMETHOD SetShowImageColumn(bool aShowImageColumn) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShowImageColumn(aShowImageColumn); } \
  NS_IMETHOD GetTimeout(uint32_t *aTimeout) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimeout(aTimeout); } \
  NS_IMETHOD SetTimeout(uint32_t aTimeout) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTimeout(aTimeout); } \
  NS_IMETHOD GetSearchParam(nsAString & aSearchParam) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchParam(aSearchParam); } \
  NS_IMETHOD SetSearchParam(const nsAString & aSearchParam) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSearchParam(aSearchParam); } \
  NS_IMETHOD GetSearchCount(uint32_t *aSearchCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchCount(aSearchCount); } \
  NS_IMETHOD GetSearchAt(uint32_t index, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchAt(index, _retval); } \
  NS_IMETHOD GetTextValue(nsAString & aTextValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextValue(aTextValue); } \
  NS_IMETHOD SetTextValue(const nsAString & aTextValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTextValue(aTextValue); } \
  NS_IMETHOD GetSelectionStart(int32_t *aSelectionStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionStart(aSelectionStart); } \
  NS_IMETHOD GetSelectionEnd(int32_t *aSelectionEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionEnd(aSelectionEnd); } \
  NS_IMETHOD SelectTextRange(int32_t startIndex, int32_t endIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectTextRange(startIndex, endIndex); } \
  NS_IMETHOD OnSearchBegin(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSearchBegin(); } \
  NS_IMETHOD OnSearchComplete(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSearchComplete(); } \
  NS_IMETHOD OnTextEntered(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnTextEntered(_retval); } \
  NS_IMETHOD OnTextReverted(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnTextReverted(_retval); } \
  NS_IMETHOD GetConsumeRollupEvent(bool *aConsumeRollupEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConsumeRollupEvent(aConsumeRollupEvent); } \
  NS_IMETHOD GetInPrivateContext(bool *aInPrivateContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInPrivateContext(aInPrivateContext); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAutoCompleteInput : public nsIAutoCompleteInput
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTOCOMPLETEINPUT

  nsAutoCompleteInput();

private:
  ~nsAutoCompleteInput();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAutoCompleteInput, nsIAutoCompleteInput)

nsAutoCompleteInput::nsAutoCompleteInput()
{
  /* member initializers and constructor code */
}

nsAutoCompleteInput::~nsAutoCompleteInput()
{
  /* destructor code */
}

/* readonly attribute nsIAutoCompletePopup popup; */
NS_IMETHODIMP nsAutoCompleteInput::GetPopup(nsIAutoCompletePopup * *aPopup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAutoCompleteController controller; */
NS_IMETHODIMP nsAutoCompleteInput::GetController(nsIAutoCompleteController * *aController)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean popupOpen; */
NS_IMETHODIMP nsAutoCompleteInput::GetPopupOpen(bool *aPopupOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetPopupOpen(bool aPopupOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean disableAutoComplete; */
NS_IMETHODIMP nsAutoCompleteInput::GetDisableAutoComplete(bool *aDisableAutoComplete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetDisableAutoComplete(bool aDisableAutoComplete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean completeDefaultIndex; */
NS_IMETHODIMP nsAutoCompleteInput::GetCompleteDefaultIndex(bool *aCompleteDefaultIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetCompleteDefaultIndex(bool aCompleteDefaultIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean completeSelectedIndex; */
NS_IMETHODIMP nsAutoCompleteInput::GetCompleteSelectedIndex(bool *aCompleteSelectedIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetCompleteSelectedIndex(bool aCompleteSelectedIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean forceComplete; */
NS_IMETHODIMP nsAutoCompleteInput::GetForceComplete(bool *aForceComplete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetForceComplete(bool aForceComplete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long minResultsForPopup; */
NS_IMETHODIMP nsAutoCompleteInput::GetMinResultsForPopup(uint32_t *aMinResultsForPopup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetMinResultsForPopup(uint32_t aMinResultsForPopup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long maxRows; */
NS_IMETHODIMP nsAutoCompleteInput::GetMaxRows(uint32_t *aMaxRows)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetMaxRows(uint32_t aMaxRows)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean showCommentColumn; */
NS_IMETHODIMP nsAutoCompleteInput::GetShowCommentColumn(bool *aShowCommentColumn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetShowCommentColumn(bool aShowCommentColumn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean showImageColumn; */
NS_IMETHODIMP nsAutoCompleteInput::GetShowImageColumn(bool *aShowImageColumn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetShowImageColumn(bool aShowImageColumn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long timeout; */
NS_IMETHODIMP nsAutoCompleteInput::GetTimeout(uint32_t *aTimeout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetTimeout(uint32_t aTimeout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString searchParam; */
NS_IMETHODIMP nsAutoCompleteInput::GetSearchParam(nsAString & aSearchParam)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetSearchParam(const nsAString & aSearchParam)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long searchCount; */
NS_IMETHODIMP nsAutoCompleteInput::GetSearchCount(uint32_t *aSearchCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getSearchAt (in unsigned long index); */
NS_IMETHODIMP nsAutoCompleteInput::GetSearchAt(uint32_t index, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString textValue; */
NS_IMETHODIMP nsAutoCompleteInput::GetTextValue(nsAString & aTextValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetTextValue(const nsAString & aTextValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long selectionStart; */
NS_IMETHODIMP nsAutoCompleteInput::GetSelectionStart(int32_t *aSelectionStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long selectionEnd; */
NS_IMETHODIMP nsAutoCompleteInput::GetSelectionEnd(int32_t *aSelectionEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectTextRange (in long startIndex, in long endIndex); */
NS_IMETHODIMP nsAutoCompleteInput::SelectTextRange(int32_t startIndex, int32_t endIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onSearchBegin (); */
NS_IMETHODIMP nsAutoCompleteInput::OnSearchBegin()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onSearchComplete (); */
NS_IMETHODIMP nsAutoCompleteInput::OnSearchComplete()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean onTextEntered (); */
NS_IMETHODIMP nsAutoCompleteInput::OnTextEntered(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean onTextReverted (); */
NS_IMETHODIMP nsAutoCompleteInput::OnTextReverted(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean consumeRollupEvent; */
NS_IMETHODIMP nsAutoCompleteInput::GetConsumeRollupEvent(bool *aConsumeRollupEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean inPrivateContext; */
NS_IMETHODIMP nsAutoCompleteInput::GetInPrivateContext(bool *aInPrivateContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAutoCompleteInput_h__ */

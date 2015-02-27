/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/editor/idl/nsIEditorSpellCheck.idl
 */

#ifndef __gen_nsIEditorSpellCheck_h__
#define __gen_nsIEditorSpellCheck_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIEditor; /* forward declaration */

class nsITextServicesFilter; /* forward declaration */


/* starting interface:    nsIEditorSpellCheck */
#define NS_IEDITORSPELLCHECK_IID_STR "334946c3-0e93-4aac-b662-e1b56f95d68b"

#define NS_IEDITORSPELLCHECK_IID \
  {0x334946c3, 0x0e93, 0x4aac, \
    { 0xb6, 0x62, 0xe1, 0xb5, 0x6f, 0x95, 0xd6, 0x8b }}

class NS_NO_VTABLE nsIEditorSpellCheck : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEDITORSPELLCHECK_IID)

  /* void checkCurrentDictionary (); */
  NS_IMETHOD CheckCurrentDictionary(void) = 0;

  /* boolean canSpellCheck (); */
  NS_IMETHOD CanSpellCheck(bool *_retval) = 0;

  /* void InitSpellChecker (in nsIEditor editor, in boolean enableSelectionChecking); */
  NS_IMETHOD InitSpellChecker(nsIEditor *editor, bool enableSelectionChecking) = 0;

  /* wstring GetNextMisspelledWord (); */
  NS_IMETHOD GetNextMisspelledWord(PRUnichar * *_retval) = 0;

  /* wstring GetSuggestedWord (); */
  NS_IMETHOD GetSuggestedWord(PRUnichar * *_retval) = 0;

  /* boolean CheckCurrentWord (in wstring suggestedWord); */
  NS_IMETHOD CheckCurrentWord(const PRUnichar * suggestedWord, bool *_retval) = 0;

  /* void ReplaceWord (in wstring misspelledWord, in wstring replaceWord, in boolean allOccurrences); */
  NS_IMETHOD ReplaceWord(const PRUnichar * misspelledWord, const PRUnichar * replaceWord, bool allOccurrences) = 0;

  /* void IgnoreWordAllOccurrences (in wstring word); */
  NS_IMETHOD IgnoreWordAllOccurrences(const PRUnichar * word) = 0;

  /* void GetPersonalDictionary (); */
  NS_IMETHOD GetPersonalDictionary(void) = 0;

  /* wstring GetPersonalDictionaryWord (); */
  NS_IMETHOD GetPersonalDictionaryWord(PRUnichar * *_retval) = 0;

  /* void AddWordToDictionary (in wstring word); */
  NS_IMETHOD AddWordToDictionary(const PRUnichar * word) = 0;

  /* void RemoveWordFromDictionary (in wstring word); */
  NS_IMETHOD RemoveWordFromDictionary(const PRUnichar * word) = 0;

  /* void GetDictionaryList ([array, size_is (count)] out wstring dictionaryList, out uint32_t count); */
  NS_IMETHOD GetDictionaryList(PRUnichar * **dictionaryList, uint32_t *count) = 0;

  /* AString GetCurrentDictionary (); */
  NS_IMETHOD GetCurrentDictionary(nsAString & _retval) = 0;

  /* void SetCurrentDictionary (in AString dictionary); */
  NS_IMETHOD SetCurrentDictionary(const nsAString & dictionary) = 0;

  /* void UninitSpellChecker (); */
  NS_IMETHOD UninitSpellChecker(void) = 0;

  /* void setFilter (in nsITextServicesFilter filter); */
  NS_IMETHOD SetFilter(nsITextServicesFilter *filter) = 0;

  /* boolean CheckCurrentWordNoSuggest (in wstring suggestedWord); */
  NS_IMETHOD CheckCurrentWordNoSuggest(const PRUnichar * suggestedWord, bool *_retval) = 0;

  /* void UpdateCurrentDictionary (); */
  NS_IMETHOD UpdateCurrentDictionary(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEditorSpellCheck, NS_IEDITORSPELLCHECK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEDITORSPELLCHECK \
  NS_IMETHOD CheckCurrentDictionary(void); \
  NS_IMETHOD CanSpellCheck(bool *_retval); \
  NS_IMETHOD InitSpellChecker(nsIEditor *editor, bool enableSelectionChecking); \
  NS_IMETHOD GetNextMisspelledWord(PRUnichar * *_retval); \
  NS_IMETHOD GetSuggestedWord(PRUnichar * *_retval); \
  NS_IMETHOD CheckCurrentWord(const PRUnichar * suggestedWord, bool *_retval); \
  NS_IMETHOD ReplaceWord(const PRUnichar * misspelledWord, const PRUnichar * replaceWord, bool allOccurrences); \
  NS_IMETHOD IgnoreWordAllOccurrences(const PRUnichar * word); \
  NS_IMETHOD GetPersonalDictionary(void); \
  NS_IMETHOD GetPersonalDictionaryWord(PRUnichar * *_retval); \
  NS_IMETHOD AddWordToDictionary(const PRUnichar * word); \
  NS_IMETHOD RemoveWordFromDictionary(const PRUnichar * word); \
  NS_IMETHOD GetDictionaryList(PRUnichar * **dictionaryList, uint32_t *count); \
  NS_IMETHOD GetCurrentDictionary(nsAString & _retval); \
  NS_IMETHOD SetCurrentDictionary(const nsAString & dictionary); \
  NS_IMETHOD UninitSpellChecker(void); \
  NS_IMETHOD SetFilter(nsITextServicesFilter *filter); \
  NS_IMETHOD CheckCurrentWordNoSuggest(const PRUnichar * suggestedWord, bool *_retval); \
  NS_IMETHOD UpdateCurrentDictionary(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEDITORSPELLCHECK(_to) \
  NS_IMETHOD CheckCurrentDictionary(void) { return _to CheckCurrentDictionary(); } \
  NS_IMETHOD CanSpellCheck(bool *_retval) { return _to CanSpellCheck(_retval); } \
  NS_IMETHOD InitSpellChecker(nsIEditor *editor, bool enableSelectionChecking) { return _to InitSpellChecker(editor, enableSelectionChecking); } \
  NS_IMETHOD GetNextMisspelledWord(PRUnichar * *_retval) { return _to GetNextMisspelledWord(_retval); } \
  NS_IMETHOD GetSuggestedWord(PRUnichar * *_retval) { return _to GetSuggestedWord(_retval); } \
  NS_IMETHOD CheckCurrentWord(const PRUnichar * suggestedWord, bool *_retval) { return _to CheckCurrentWord(suggestedWord, _retval); } \
  NS_IMETHOD ReplaceWord(const PRUnichar * misspelledWord, const PRUnichar * replaceWord, bool allOccurrences) { return _to ReplaceWord(misspelledWord, replaceWord, allOccurrences); } \
  NS_IMETHOD IgnoreWordAllOccurrences(const PRUnichar * word) { return _to IgnoreWordAllOccurrences(word); } \
  NS_IMETHOD GetPersonalDictionary(void) { return _to GetPersonalDictionary(); } \
  NS_IMETHOD GetPersonalDictionaryWord(PRUnichar * *_retval) { return _to GetPersonalDictionaryWord(_retval); } \
  NS_IMETHOD AddWordToDictionary(const PRUnichar * word) { return _to AddWordToDictionary(word); } \
  NS_IMETHOD RemoveWordFromDictionary(const PRUnichar * word) { return _to RemoveWordFromDictionary(word); } \
  NS_IMETHOD GetDictionaryList(PRUnichar * **dictionaryList, uint32_t *count) { return _to GetDictionaryList(dictionaryList, count); } \
  NS_IMETHOD GetCurrentDictionary(nsAString & _retval) { return _to GetCurrentDictionary(_retval); } \
  NS_IMETHOD SetCurrentDictionary(const nsAString & dictionary) { return _to SetCurrentDictionary(dictionary); } \
  NS_IMETHOD UninitSpellChecker(void) { return _to UninitSpellChecker(); } \
  NS_IMETHOD SetFilter(nsITextServicesFilter *filter) { return _to SetFilter(filter); } \
  NS_IMETHOD CheckCurrentWordNoSuggest(const PRUnichar * suggestedWord, bool *_retval) { return _to CheckCurrentWordNoSuggest(suggestedWord, _retval); } \
  NS_IMETHOD UpdateCurrentDictionary(void) { return _to UpdateCurrentDictionary(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEDITORSPELLCHECK(_to) \
  NS_IMETHOD CheckCurrentDictionary(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckCurrentDictionary(); } \
  NS_IMETHOD CanSpellCheck(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanSpellCheck(_retval); } \
  NS_IMETHOD InitSpellChecker(nsIEditor *editor, bool enableSelectionChecking) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitSpellChecker(editor, enableSelectionChecking); } \
  NS_IMETHOD GetNextMisspelledWord(PRUnichar * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNextMisspelledWord(_retval); } \
  NS_IMETHOD GetSuggestedWord(PRUnichar * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSuggestedWord(_retval); } \
  NS_IMETHOD CheckCurrentWord(const PRUnichar * suggestedWord, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckCurrentWord(suggestedWord, _retval); } \
  NS_IMETHOD ReplaceWord(const PRUnichar * misspelledWord, const PRUnichar * replaceWord, bool allOccurrences) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceWord(misspelledWord, replaceWord, allOccurrences); } \
  NS_IMETHOD IgnoreWordAllOccurrences(const PRUnichar * word) { return !_to ? NS_ERROR_NULL_POINTER : _to->IgnoreWordAllOccurrences(word); } \
  NS_IMETHOD GetPersonalDictionary(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPersonalDictionary(); } \
  NS_IMETHOD GetPersonalDictionaryWord(PRUnichar * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPersonalDictionaryWord(_retval); } \
  NS_IMETHOD AddWordToDictionary(const PRUnichar * word) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddWordToDictionary(word); } \
  NS_IMETHOD RemoveWordFromDictionary(const PRUnichar * word) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveWordFromDictionary(word); } \
  NS_IMETHOD GetDictionaryList(PRUnichar * **dictionaryList, uint32_t *count) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDictionaryList(dictionaryList, count); } \
  NS_IMETHOD GetCurrentDictionary(nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentDictionary(_retval); } \
  NS_IMETHOD SetCurrentDictionary(const nsAString & dictionary) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurrentDictionary(dictionary); } \
  NS_IMETHOD UninitSpellChecker(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->UninitSpellChecker(); } \
  NS_IMETHOD SetFilter(nsITextServicesFilter *filter) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFilter(filter); } \
  NS_IMETHOD CheckCurrentWordNoSuggest(const PRUnichar * suggestedWord, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckCurrentWordNoSuggest(suggestedWord, _retval); } \
  NS_IMETHOD UpdateCurrentDictionary(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateCurrentDictionary(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEditorSpellCheck : public nsIEditorSpellCheck
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEDITORSPELLCHECK

  nsEditorSpellCheck();

private:
  ~nsEditorSpellCheck();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEditorSpellCheck, nsIEditorSpellCheck)

nsEditorSpellCheck::nsEditorSpellCheck()
{
  /* member initializers and constructor code */
}

nsEditorSpellCheck::~nsEditorSpellCheck()
{
  /* destructor code */
}

/* void checkCurrentDictionary (); */
NS_IMETHODIMP nsEditorSpellCheck::CheckCurrentDictionary()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canSpellCheck (); */
NS_IMETHODIMP nsEditorSpellCheck::CanSpellCheck(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void InitSpellChecker (in nsIEditor editor, in boolean enableSelectionChecking); */
NS_IMETHODIMP nsEditorSpellCheck::InitSpellChecker(nsIEditor *editor, bool enableSelectionChecking)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring GetNextMisspelledWord (); */
NS_IMETHODIMP nsEditorSpellCheck::GetNextMisspelledWord(PRUnichar * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring GetSuggestedWord (); */
NS_IMETHODIMP nsEditorSpellCheck::GetSuggestedWord(PRUnichar * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean CheckCurrentWord (in wstring suggestedWord); */
NS_IMETHODIMP nsEditorSpellCheck::CheckCurrentWord(const PRUnichar * suggestedWord, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ReplaceWord (in wstring misspelledWord, in wstring replaceWord, in boolean allOccurrences); */
NS_IMETHODIMP nsEditorSpellCheck::ReplaceWord(const PRUnichar * misspelledWord, const PRUnichar * replaceWord, bool allOccurrences)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void IgnoreWordAllOccurrences (in wstring word); */
NS_IMETHODIMP nsEditorSpellCheck::IgnoreWordAllOccurrences(const PRUnichar * word)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void GetPersonalDictionary (); */
NS_IMETHODIMP nsEditorSpellCheck::GetPersonalDictionary()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring GetPersonalDictionaryWord (); */
NS_IMETHODIMP nsEditorSpellCheck::GetPersonalDictionaryWord(PRUnichar * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void AddWordToDictionary (in wstring word); */
NS_IMETHODIMP nsEditorSpellCheck::AddWordToDictionary(const PRUnichar * word)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void RemoveWordFromDictionary (in wstring word); */
NS_IMETHODIMP nsEditorSpellCheck::RemoveWordFromDictionary(const PRUnichar * word)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void GetDictionaryList ([array, size_is (count)] out wstring dictionaryList, out uint32_t count); */
NS_IMETHODIMP nsEditorSpellCheck::GetDictionaryList(PRUnichar * **dictionaryList, uint32_t *count)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString GetCurrentDictionary (); */
NS_IMETHODIMP nsEditorSpellCheck::GetCurrentDictionary(nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SetCurrentDictionary (in AString dictionary); */
NS_IMETHODIMP nsEditorSpellCheck::SetCurrentDictionary(const nsAString & dictionary)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void UninitSpellChecker (); */
NS_IMETHODIMP nsEditorSpellCheck::UninitSpellChecker()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFilter (in nsITextServicesFilter filter); */
NS_IMETHODIMP nsEditorSpellCheck::SetFilter(nsITextServicesFilter *filter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean CheckCurrentWordNoSuggest (in wstring suggestedWord); */
NS_IMETHODIMP nsEditorSpellCheck::CheckCurrentWordNoSuggest(const PRUnichar * suggestedWord, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void UpdateCurrentDictionary (); */
NS_IMETHODIMP nsEditorSpellCheck::UpdateCurrentDictionary()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEditorSpellCheck_h__ */

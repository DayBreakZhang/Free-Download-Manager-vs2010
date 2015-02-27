/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIEditorSpellCheck.idl
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

class nsIEditorSpellCheckCallback; /* forward declaration */


/* starting interface:    nsIEditorSpellCheck */
#define NS_IEDITORSPELLCHECK_IID_STR "dd32ef3b-a7d8-43d1-9617-5f2dddbe29eb"

#define NS_IEDITORSPELLCHECK_IID \
  {0xdd32ef3b, 0xa7d8, 0x43d1, \
    { 0x96, 0x17, 0x5f, 0x2d, 0xdd, 0xbe, 0x29, 0xeb }}

class NS_NO_VTABLE nsIEditorSpellCheck : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEDITORSPELLCHECK_IID)

  /* void checkCurrentDictionary (); */
  NS_IMETHOD CheckCurrentDictionary(void) = 0;

  /* boolean canSpellCheck (); */
  NS_IMETHOD CanSpellCheck(bool *_retval) = 0;

  /* void InitSpellChecker (in nsIEditor editor, in boolean enableSelectionChecking, [optional] in nsIEditorSpellCheckCallback callback); */
  NS_IMETHOD InitSpellChecker(nsIEditor *editor, bool enableSelectionChecking, nsIEditorSpellCheckCallback *callback) = 0;

  /* wstring GetNextMisspelledWord (); */
  NS_IMETHOD GetNextMisspelledWord(char16_t * *_retval) = 0;

  /* wstring GetSuggestedWord (); */
  NS_IMETHOD GetSuggestedWord(char16_t * *_retval) = 0;

  /* boolean CheckCurrentWord (in wstring suggestedWord); */
  NS_IMETHOD CheckCurrentWord(const char16_t * suggestedWord, bool *_retval) = 0;

  /* void ReplaceWord (in wstring misspelledWord, in wstring replaceWord, in boolean allOccurrences); */
  NS_IMETHOD ReplaceWord(const char16_t * misspelledWord, const char16_t * replaceWord, bool allOccurrences) = 0;

  /* void IgnoreWordAllOccurrences (in wstring word); */
  NS_IMETHOD IgnoreWordAllOccurrences(const char16_t * word) = 0;

  /* void GetPersonalDictionary (); */
  NS_IMETHOD GetPersonalDictionary(void) = 0;

  /* wstring GetPersonalDictionaryWord (); */
  NS_IMETHOD GetPersonalDictionaryWord(char16_t * *_retval) = 0;

  /* void AddWordToDictionary (in wstring word); */
  NS_IMETHOD AddWordToDictionary(const char16_t * word) = 0;

  /* void RemoveWordFromDictionary (in wstring word); */
  NS_IMETHOD RemoveWordFromDictionary(const char16_t * word) = 0;

  /* void GetDictionaryList ([array, size_is (count)] out wstring dictionaryList, out uint32_t count); */
  NS_IMETHOD GetDictionaryList(char16_t * **dictionaryList, uint32_t *count) = 0;

  /* AString GetCurrentDictionary (); */
  NS_IMETHOD GetCurrentDictionary(nsAString & _retval) = 0;

  /* void SetCurrentDictionary (in AString dictionary); */
  NS_IMETHOD SetCurrentDictionary(const nsAString & dictionary) = 0;

  /* void UninitSpellChecker (); */
  NS_IMETHOD UninitSpellChecker(void) = 0;

  /* void setFilter (in nsITextServicesFilter filter); */
  NS_IMETHOD SetFilter(nsITextServicesFilter *filter) = 0;

  /* boolean CheckCurrentWordNoSuggest (in wstring suggestedWord); */
  NS_IMETHOD CheckCurrentWordNoSuggest(const char16_t * suggestedWord, bool *_retval) = 0;

  /* void UpdateCurrentDictionary ([optional] in nsIEditorSpellCheckCallback callback); */
  NS_IMETHOD UpdateCurrentDictionary(nsIEditorSpellCheckCallback *callback) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEditorSpellCheck, NS_IEDITORSPELLCHECK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEDITORSPELLCHECK \
  NS_IMETHOD CheckCurrentDictionary(void); \
  NS_IMETHOD CanSpellCheck(bool *_retval); \
  NS_IMETHOD InitSpellChecker(nsIEditor *editor, bool enableSelectionChecking, nsIEditorSpellCheckCallback *callback); \
  NS_IMETHOD GetNextMisspelledWord(char16_t * *_retval); \
  NS_IMETHOD GetSuggestedWord(char16_t * *_retval); \
  NS_IMETHOD CheckCurrentWord(const char16_t * suggestedWord, bool *_retval); \
  NS_IMETHOD ReplaceWord(const char16_t * misspelledWord, const char16_t * replaceWord, bool allOccurrences); \
  NS_IMETHOD IgnoreWordAllOccurrences(const char16_t * word); \
  NS_IMETHOD GetPersonalDictionary(void); \
  NS_IMETHOD GetPersonalDictionaryWord(char16_t * *_retval); \
  NS_IMETHOD AddWordToDictionary(const char16_t * word); \
  NS_IMETHOD RemoveWordFromDictionary(const char16_t * word); \
  NS_IMETHOD GetDictionaryList(char16_t * **dictionaryList, uint32_t *count); \
  NS_IMETHOD GetCurrentDictionary(nsAString & _retval); \
  NS_IMETHOD SetCurrentDictionary(const nsAString & dictionary); \
  NS_IMETHOD UninitSpellChecker(void); \
  NS_IMETHOD SetFilter(nsITextServicesFilter *filter); \
  NS_IMETHOD CheckCurrentWordNoSuggest(const char16_t * suggestedWord, bool *_retval); \
  NS_IMETHOD UpdateCurrentDictionary(nsIEditorSpellCheckCallback *callback); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEDITORSPELLCHECK(_to) \
  NS_IMETHOD CheckCurrentDictionary(void) { return _to CheckCurrentDictionary(); } \
  NS_IMETHOD CanSpellCheck(bool *_retval) { return _to CanSpellCheck(_retval); } \
  NS_IMETHOD InitSpellChecker(nsIEditor *editor, bool enableSelectionChecking, nsIEditorSpellCheckCallback *callback) { return _to InitSpellChecker(editor, enableSelectionChecking, callback); } \
  NS_IMETHOD GetNextMisspelledWord(char16_t * *_retval) { return _to GetNextMisspelledWord(_retval); } \
  NS_IMETHOD GetSuggestedWord(char16_t * *_retval) { return _to GetSuggestedWord(_retval); } \
  NS_IMETHOD CheckCurrentWord(const char16_t * suggestedWord, bool *_retval) { return _to CheckCurrentWord(suggestedWord, _retval); } \
  NS_IMETHOD ReplaceWord(const char16_t * misspelledWord, const char16_t * replaceWord, bool allOccurrences) { return _to ReplaceWord(misspelledWord, replaceWord, allOccurrences); } \
  NS_IMETHOD IgnoreWordAllOccurrences(const char16_t * word) { return _to IgnoreWordAllOccurrences(word); } \
  NS_IMETHOD GetPersonalDictionary(void) { return _to GetPersonalDictionary(); } \
  NS_IMETHOD GetPersonalDictionaryWord(char16_t * *_retval) { return _to GetPersonalDictionaryWord(_retval); } \
  NS_IMETHOD AddWordToDictionary(const char16_t * word) { return _to AddWordToDictionary(word); } \
  NS_IMETHOD RemoveWordFromDictionary(const char16_t * word) { return _to RemoveWordFromDictionary(word); } \
  NS_IMETHOD GetDictionaryList(char16_t * **dictionaryList, uint32_t *count) { return _to GetDictionaryList(dictionaryList, count); } \
  NS_IMETHOD GetCurrentDictionary(nsAString & _retval) { return _to GetCurrentDictionary(_retval); } \
  NS_IMETHOD SetCurrentDictionary(const nsAString & dictionary) { return _to SetCurrentDictionary(dictionary); } \
  NS_IMETHOD UninitSpellChecker(void) { return _to UninitSpellChecker(); } \
  NS_IMETHOD SetFilter(nsITextServicesFilter *filter) { return _to SetFilter(filter); } \
  NS_IMETHOD CheckCurrentWordNoSuggest(const char16_t * suggestedWord, bool *_retval) { return _to CheckCurrentWordNoSuggest(suggestedWord, _retval); } \
  NS_IMETHOD UpdateCurrentDictionary(nsIEditorSpellCheckCallback *callback) { return _to UpdateCurrentDictionary(callback); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEDITORSPELLCHECK(_to) \
  NS_IMETHOD CheckCurrentDictionary(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckCurrentDictionary(); } \
  NS_IMETHOD CanSpellCheck(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanSpellCheck(_retval); } \
  NS_IMETHOD InitSpellChecker(nsIEditor *editor, bool enableSelectionChecking, nsIEditorSpellCheckCallback *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitSpellChecker(editor, enableSelectionChecking, callback); } \
  NS_IMETHOD GetNextMisspelledWord(char16_t * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNextMisspelledWord(_retval); } \
  NS_IMETHOD GetSuggestedWord(char16_t * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSuggestedWord(_retval); } \
  NS_IMETHOD CheckCurrentWord(const char16_t * suggestedWord, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckCurrentWord(suggestedWord, _retval); } \
  NS_IMETHOD ReplaceWord(const char16_t * misspelledWord, const char16_t * replaceWord, bool allOccurrences) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceWord(misspelledWord, replaceWord, allOccurrences); } \
  NS_IMETHOD IgnoreWordAllOccurrences(const char16_t * word) { return !_to ? NS_ERROR_NULL_POINTER : _to->IgnoreWordAllOccurrences(word); } \
  NS_IMETHOD GetPersonalDictionary(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPersonalDictionary(); } \
  NS_IMETHOD GetPersonalDictionaryWord(char16_t * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPersonalDictionaryWord(_retval); } \
  NS_IMETHOD AddWordToDictionary(const char16_t * word) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddWordToDictionary(word); } \
  NS_IMETHOD RemoveWordFromDictionary(const char16_t * word) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveWordFromDictionary(word); } \
  NS_IMETHOD GetDictionaryList(char16_t * **dictionaryList, uint32_t *count) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDictionaryList(dictionaryList, count); } \
  NS_IMETHOD GetCurrentDictionary(nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentDictionary(_retval); } \
  NS_IMETHOD SetCurrentDictionary(const nsAString & dictionary) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurrentDictionary(dictionary); } \
  NS_IMETHOD UninitSpellChecker(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->UninitSpellChecker(); } \
  NS_IMETHOD SetFilter(nsITextServicesFilter *filter) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFilter(filter); } \
  NS_IMETHOD CheckCurrentWordNoSuggest(const char16_t * suggestedWord, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckCurrentWordNoSuggest(suggestedWord, _retval); } \
  NS_IMETHOD UpdateCurrentDictionary(nsIEditorSpellCheckCallback *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateCurrentDictionary(callback); } 

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

/* void InitSpellChecker (in nsIEditor editor, in boolean enableSelectionChecking, [optional] in nsIEditorSpellCheckCallback callback); */
NS_IMETHODIMP nsEditorSpellCheck::InitSpellChecker(nsIEditor *editor, bool enableSelectionChecking, nsIEditorSpellCheckCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring GetNextMisspelledWord (); */
NS_IMETHODIMP nsEditorSpellCheck::GetNextMisspelledWord(char16_t * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring GetSuggestedWord (); */
NS_IMETHODIMP nsEditorSpellCheck::GetSuggestedWord(char16_t * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean CheckCurrentWord (in wstring suggestedWord); */
NS_IMETHODIMP nsEditorSpellCheck::CheckCurrentWord(const char16_t * suggestedWord, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ReplaceWord (in wstring misspelledWord, in wstring replaceWord, in boolean allOccurrences); */
NS_IMETHODIMP nsEditorSpellCheck::ReplaceWord(const char16_t * misspelledWord, const char16_t * replaceWord, bool allOccurrences)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void IgnoreWordAllOccurrences (in wstring word); */
NS_IMETHODIMP nsEditorSpellCheck::IgnoreWordAllOccurrences(const char16_t * word)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void GetPersonalDictionary (); */
NS_IMETHODIMP nsEditorSpellCheck::GetPersonalDictionary()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring GetPersonalDictionaryWord (); */
NS_IMETHODIMP nsEditorSpellCheck::GetPersonalDictionaryWord(char16_t * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void AddWordToDictionary (in wstring word); */
NS_IMETHODIMP nsEditorSpellCheck::AddWordToDictionary(const char16_t * word)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void RemoveWordFromDictionary (in wstring word); */
NS_IMETHODIMP nsEditorSpellCheck::RemoveWordFromDictionary(const char16_t * word)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void GetDictionaryList ([array, size_is (count)] out wstring dictionaryList, out uint32_t count); */
NS_IMETHODIMP nsEditorSpellCheck::GetDictionaryList(char16_t * **dictionaryList, uint32_t *count)
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
NS_IMETHODIMP nsEditorSpellCheck::CheckCurrentWordNoSuggest(const char16_t * suggestedWord, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void UpdateCurrentDictionary ([optional] in nsIEditorSpellCheckCallback callback); */
NS_IMETHODIMP nsEditorSpellCheck::UpdateCurrentDictionary(nsIEditorSpellCheckCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIEditorSpellCheckCallback */
#define NS_IEDITORSPELLCHECKCALLBACK_IID_STR "5f0a4bab-8538-4074-89d3-2f0e866a1c0b"

#define NS_IEDITORSPELLCHECKCALLBACK_IID \
  {0x5f0a4bab, 0x8538, 0x4074, \
    { 0x89, 0xd3, 0x2f, 0x0e, 0x86, 0x6a, 0x1c, 0x0b }}

class NS_NO_VTABLE nsIEditorSpellCheckCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEDITORSPELLCHECKCALLBACK_IID)

  /* void editorSpellCheckDone (); */
  NS_IMETHOD EditorSpellCheckDone(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEditorSpellCheckCallback, NS_IEDITORSPELLCHECKCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEDITORSPELLCHECKCALLBACK \
  NS_IMETHOD EditorSpellCheckDone(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEDITORSPELLCHECKCALLBACK(_to) \
  NS_IMETHOD EditorSpellCheckDone(void) { return _to EditorSpellCheckDone(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEDITORSPELLCHECKCALLBACK(_to) \
  NS_IMETHOD EditorSpellCheckDone(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EditorSpellCheckDone(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEditorSpellCheckCallback : public nsIEditorSpellCheckCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEDITORSPELLCHECKCALLBACK

  nsEditorSpellCheckCallback();

private:
  ~nsEditorSpellCheckCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEditorSpellCheckCallback, nsIEditorSpellCheckCallback)

nsEditorSpellCheckCallback::nsEditorSpellCheckCallback()
{
  /* member initializers and constructor code */
}

nsEditorSpellCheckCallback::~nsEditorSpellCheckCallback()
{
  /* destructor code */
}

/* void editorSpellCheckDone (); */
NS_IMETHODIMP nsEditorSpellCheckCallback::EditorSpellCheckDone()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEditorSpellCheck_h__ */

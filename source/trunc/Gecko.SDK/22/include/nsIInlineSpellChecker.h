/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/editor/txtsvc/public/nsIInlineSpellChecker.idl
 */

#ifndef __gen_nsIInlineSpellChecker_h__
#define __gen_nsIInlineSpellChecker_h__


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
class nsISelection; /* forward declaration */

class nsIEditor; /* forward declaration */

class nsIEditorSpellCheck; /* forward declaration */


/* starting interface:    nsIInlineSpellChecker */
#define NS_IINLINESPELLCHECKER_IID_STR "df635540-d073-47b8-8678-18776130691d"

#define NS_IINLINESPELLCHECKER_IID \
  {0xdf635540, 0xd073, 0x47b8, \
    { 0x86, 0x78, 0x18, 0x77, 0x61, 0x30, 0x69, 0x1d }}

class NS_NO_VTABLE nsIInlineSpellChecker : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINLINESPELLCHECKER_IID)

  /* readonly attribute nsIEditorSpellCheck spellChecker; */
  NS_IMETHOD GetSpellChecker(nsIEditorSpellCheck * *aSpellChecker) = 0;

  /* void init (in nsIEditor aEditor); */
  NS_IMETHOD Init(nsIEditor *aEditor) = 0;

  /* void cleanup (in boolean aDestroyingFrames); */
  NS_IMETHOD Cleanup(bool aDestroyingFrames) = 0;

  /* attribute boolean enableRealTimeSpell; */
  NS_IMETHOD GetEnableRealTimeSpell(bool *aEnableRealTimeSpell) = 0;
  NS_IMETHOD SetEnableRealTimeSpell(bool aEnableRealTimeSpell) = 0;

  /* void spellCheckAfterEditorChange (in long aAction, in nsISelection aSelection, in nsIDOMNode aPreviousSelectedNode, in long aPreviousSelectedOffset, in nsIDOMNode aStartNode, in long aStartOffset, in nsIDOMNode aEndNode, in long aEndOffset); */
  NS_IMETHOD SpellCheckAfterEditorChange(int32_t aAction, nsISelection *aSelection, nsIDOMNode *aPreviousSelectedNode, int32_t aPreviousSelectedOffset, nsIDOMNode *aStartNode, int32_t aStartOffset, nsIDOMNode *aEndNode, int32_t aEndOffset) = 0;

  /* void spellCheckRange (in nsIDOMRange aSelection); */
  NS_IMETHOD SpellCheckRange(nsIDOMRange *aSelection) = 0;

  /* nsIDOMRange getMisspelledWord (in nsIDOMNode aNode, in long aOffset); */
  NS_IMETHOD GetMisspelledWord(nsIDOMNode *aNode, int32_t aOffset, nsIDOMRange * *_retval) = 0;

  /* void replaceWord (in nsIDOMNode aNode, in long aOffset, in AString aNewword); */
  NS_IMETHOD ReplaceWord(nsIDOMNode *aNode, int32_t aOffset, const nsAString & aNewword) = 0;

  /* void addWordToDictionary (in AString aWord); */
  NS_IMETHOD AddWordToDictionary(const nsAString & aWord) = 0;

  /* void removeWordFromDictionary (in AString aWord); */
  NS_IMETHOD RemoveWordFromDictionary(const nsAString & aWord) = 0;

  /* void ignoreWord (in AString aWord); */
  NS_IMETHOD IgnoreWord(const nsAString & aWord) = 0;

  /* void ignoreWords ([array, size_is (aCount)] in wstring aWordsToIgnore, in unsigned long aCount); */
  NS_IMETHOD IgnoreWords(const PRUnichar * *aWordsToIgnore, uint32_t aCount) = 0;

  /* void updateCurrentDictionary (); */
  NS_IMETHOD UpdateCurrentDictionary(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInlineSpellChecker, NS_IINLINESPELLCHECKER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINLINESPELLCHECKER \
  NS_IMETHOD GetSpellChecker(nsIEditorSpellCheck * *aSpellChecker); \
  NS_IMETHOD Init(nsIEditor *aEditor); \
  NS_IMETHOD Cleanup(bool aDestroyingFrames); \
  NS_IMETHOD GetEnableRealTimeSpell(bool *aEnableRealTimeSpell); \
  NS_IMETHOD SetEnableRealTimeSpell(bool aEnableRealTimeSpell); \
  NS_IMETHOD SpellCheckAfterEditorChange(int32_t aAction, nsISelection *aSelection, nsIDOMNode *aPreviousSelectedNode, int32_t aPreviousSelectedOffset, nsIDOMNode *aStartNode, int32_t aStartOffset, nsIDOMNode *aEndNode, int32_t aEndOffset); \
  NS_IMETHOD SpellCheckRange(nsIDOMRange *aSelection); \
  NS_IMETHOD GetMisspelledWord(nsIDOMNode *aNode, int32_t aOffset, nsIDOMRange * *_retval); \
  NS_IMETHOD ReplaceWord(nsIDOMNode *aNode, int32_t aOffset, const nsAString & aNewword); \
  NS_IMETHOD AddWordToDictionary(const nsAString & aWord); \
  NS_IMETHOD RemoveWordFromDictionary(const nsAString & aWord); \
  NS_IMETHOD IgnoreWord(const nsAString & aWord); \
  NS_IMETHOD IgnoreWords(const PRUnichar * *aWordsToIgnore, uint32_t aCount); \
  NS_IMETHOD UpdateCurrentDictionary(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINLINESPELLCHECKER(_to) \
  NS_IMETHOD GetSpellChecker(nsIEditorSpellCheck * *aSpellChecker) { return _to GetSpellChecker(aSpellChecker); } \
  NS_IMETHOD Init(nsIEditor *aEditor) { return _to Init(aEditor); } \
  NS_IMETHOD Cleanup(bool aDestroyingFrames) { return _to Cleanup(aDestroyingFrames); } \
  NS_IMETHOD GetEnableRealTimeSpell(bool *aEnableRealTimeSpell) { return _to GetEnableRealTimeSpell(aEnableRealTimeSpell); } \
  NS_IMETHOD SetEnableRealTimeSpell(bool aEnableRealTimeSpell) { return _to SetEnableRealTimeSpell(aEnableRealTimeSpell); } \
  NS_IMETHOD SpellCheckAfterEditorChange(int32_t aAction, nsISelection *aSelection, nsIDOMNode *aPreviousSelectedNode, int32_t aPreviousSelectedOffset, nsIDOMNode *aStartNode, int32_t aStartOffset, nsIDOMNode *aEndNode, int32_t aEndOffset) { return _to SpellCheckAfterEditorChange(aAction, aSelection, aPreviousSelectedNode, aPreviousSelectedOffset, aStartNode, aStartOffset, aEndNode, aEndOffset); } \
  NS_IMETHOD SpellCheckRange(nsIDOMRange *aSelection) { return _to SpellCheckRange(aSelection); } \
  NS_IMETHOD GetMisspelledWord(nsIDOMNode *aNode, int32_t aOffset, nsIDOMRange * *_retval) { return _to GetMisspelledWord(aNode, aOffset, _retval); } \
  NS_IMETHOD ReplaceWord(nsIDOMNode *aNode, int32_t aOffset, const nsAString & aNewword) { return _to ReplaceWord(aNode, aOffset, aNewword); } \
  NS_IMETHOD AddWordToDictionary(const nsAString & aWord) { return _to AddWordToDictionary(aWord); } \
  NS_IMETHOD RemoveWordFromDictionary(const nsAString & aWord) { return _to RemoveWordFromDictionary(aWord); } \
  NS_IMETHOD IgnoreWord(const nsAString & aWord) { return _to IgnoreWord(aWord); } \
  NS_IMETHOD IgnoreWords(const PRUnichar * *aWordsToIgnore, uint32_t aCount) { return _to IgnoreWords(aWordsToIgnore, aCount); } \
  NS_IMETHOD UpdateCurrentDictionary(void) { return _to UpdateCurrentDictionary(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINLINESPELLCHECKER(_to) \
  NS_IMETHOD GetSpellChecker(nsIEditorSpellCheck * *aSpellChecker) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSpellChecker(aSpellChecker); } \
  NS_IMETHOD Init(nsIEditor *aEditor) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aEditor); } \
  NS_IMETHOD Cleanup(bool aDestroyingFrames) { return !_to ? NS_ERROR_NULL_POINTER : _to->Cleanup(aDestroyingFrames); } \
  NS_IMETHOD GetEnableRealTimeSpell(bool *aEnableRealTimeSpell) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnableRealTimeSpell(aEnableRealTimeSpell); } \
  NS_IMETHOD SetEnableRealTimeSpell(bool aEnableRealTimeSpell) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEnableRealTimeSpell(aEnableRealTimeSpell); } \
  NS_IMETHOD SpellCheckAfterEditorChange(int32_t aAction, nsISelection *aSelection, nsIDOMNode *aPreviousSelectedNode, int32_t aPreviousSelectedOffset, nsIDOMNode *aStartNode, int32_t aStartOffset, nsIDOMNode *aEndNode, int32_t aEndOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->SpellCheckAfterEditorChange(aAction, aSelection, aPreviousSelectedNode, aPreviousSelectedOffset, aStartNode, aStartOffset, aEndNode, aEndOffset); } \
  NS_IMETHOD SpellCheckRange(nsIDOMRange *aSelection) { return !_to ? NS_ERROR_NULL_POINTER : _to->SpellCheckRange(aSelection); } \
  NS_IMETHOD GetMisspelledWord(nsIDOMNode *aNode, int32_t aOffset, nsIDOMRange * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMisspelledWord(aNode, aOffset, _retval); } \
  NS_IMETHOD ReplaceWord(nsIDOMNode *aNode, int32_t aOffset, const nsAString & aNewword) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceWord(aNode, aOffset, aNewword); } \
  NS_IMETHOD AddWordToDictionary(const nsAString & aWord) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddWordToDictionary(aWord); } \
  NS_IMETHOD RemoveWordFromDictionary(const nsAString & aWord) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveWordFromDictionary(aWord); } \
  NS_IMETHOD IgnoreWord(const nsAString & aWord) { return !_to ? NS_ERROR_NULL_POINTER : _to->IgnoreWord(aWord); } \
  NS_IMETHOD IgnoreWords(const PRUnichar * *aWordsToIgnore, uint32_t aCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->IgnoreWords(aWordsToIgnore, aCount); } \
  NS_IMETHOD UpdateCurrentDictionary(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateCurrentDictionary(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInlineSpellChecker : public nsIInlineSpellChecker
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINLINESPELLCHECKER

  nsInlineSpellChecker();

private:
  ~nsInlineSpellChecker();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsInlineSpellChecker, nsIInlineSpellChecker)

nsInlineSpellChecker::nsInlineSpellChecker()
{
  /* member initializers and constructor code */
}

nsInlineSpellChecker::~nsInlineSpellChecker()
{
  /* destructor code */
}

/* readonly attribute nsIEditorSpellCheck spellChecker; */
NS_IMETHODIMP nsInlineSpellChecker::GetSpellChecker(nsIEditorSpellCheck * *aSpellChecker)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void init (in nsIEditor aEditor); */
NS_IMETHODIMP nsInlineSpellChecker::Init(nsIEditor *aEditor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cleanup (in boolean aDestroyingFrames); */
NS_IMETHODIMP nsInlineSpellChecker::Cleanup(bool aDestroyingFrames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean enableRealTimeSpell; */
NS_IMETHODIMP nsInlineSpellChecker::GetEnableRealTimeSpell(bool *aEnableRealTimeSpell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineSpellChecker::SetEnableRealTimeSpell(bool aEnableRealTimeSpell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void spellCheckAfterEditorChange (in long aAction, in nsISelection aSelection, in nsIDOMNode aPreviousSelectedNode, in long aPreviousSelectedOffset, in nsIDOMNode aStartNode, in long aStartOffset, in nsIDOMNode aEndNode, in long aEndOffset); */
NS_IMETHODIMP nsInlineSpellChecker::SpellCheckAfterEditorChange(int32_t aAction, nsISelection *aSelection, nsIDOMNode *aPreviousSelectedNode, int32_t aPreviousSelectedOffset, nsIDOMNode *aStartNode, int32_t aStartOffset, nsIDOMNode *aEndNode, int32_t aEndOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void spellCheckRange (in nsIDOMRange aSelection); */
NS_IMETHODIMP nsInlineSpellChecker::SpellCheckRange(nsIDOMRange *aSelection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMRange getMisspelledWord (in nsIDOMNode aNode, in long aOffset); */
NS_IMETHODIMP nsInlineSpellChecker::GetMisspelledWord(nsIDOMNode *aNode, int32_t aOffset, nsIDOMRange * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void replaceWord (in nsIDOMNode aNode, in long aOffset, in AString aNewword); */
NS_IMETHODIMP nsInlineSpellChecker::ReplaceWord(nsIDOMNode *aNode, int32_t aOffset, const nsAString & aNewword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addWordToDictionary (in AString aWord); */
NS_IMETHODIMP nsInlineSpellChecker::AddWordToDictionary(const nsAString & aWord)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeWordFromDictionary (in AString aWord); */
NS_IMETHODIMP nsInlineSpellChecker::RemoveWordFromDictionary(const nsAString & aWord)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ignoreWord (in AString aWord); */
NS_IMETHODIMP nsInlineSpellChecker::IgnoreWord(const nsAString & aWord)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ignoreWords ([array, size_is (aCount)] in wstring aWordsToIgnore, in unsigned long aCount); */
NS_IMETHODIMP nsInlineSpellChecker::IgnoreWords(const PRUnichar * *aWordsToIgnore, uint32_t aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateCurrentDictionary (); */
NS_IMETHODIMP nsInlineSpellChecker::UpdateCurrentDictionary()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define MOZ_INLINESPELLCHECKER_CONTRACTID "@mozilla.org/spellchecker-inline;1"

#endif /* __gen_nsIInlineSpellChecker_h__ */

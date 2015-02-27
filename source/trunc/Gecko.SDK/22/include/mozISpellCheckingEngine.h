/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/extensions/spellcheck/idl/mozISpellCheckingEngine.idl
 */

#ifndef __gen_mozISpellCheckingEngine_h__
#define __gen_mozISpellCheckingEngine_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */

class mozIPersonalDictionary; /* forward declaration */


/* starting interface:    mozISpellCheckingEngine */
#define MOZISPELLCHECKINGENGINE_IID_STR "8ba643a4-7ddc-4662-b976-7ec123843f10"

#define MOZISPELLCHECKINGENGINE_IID \
  {0x8ba643a4, 0x7ddc, 0x4662, \
    { 0xb9, 0x76, 0x7e, 0xc1, 0x23, 0x84, 0x3f, 0x10 }}

class NS_NO_VTABLE mozISpellCheckingEngine : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISPELLCHECKINGENGINE_IID)

  /* attribute wstring dictionary; */
  NS_IMETHOD GetDictionary(PRUnichar * *aDictionary) = 0;
  NS_IMETHOD SetDictionary(const PRUnichar * aDictionary) = 0;

  /* readonly attribute wstring language; */
  NS_IMETHOD GetLanguage(PRUnichar * *aLanguage) = 0;

  /* readonly attribute boolean providesPersonalDictionary; */
  NS_IMETHOD GetProvidesPersonalDictionary(bool *aProvidesPersonalDictionary) = 0;

  /* readonly attribute boolean providesWordUtils; */
  NS_IMETHOD GetProvidesWordUtils(bool *aProvidesWordUtils) = 0;

  /* readonly attribute wstring name; */
  NS_IMETHOD GetName(PRUnichar * *aName) = 0;

  /* readonly attribute wstring copyright; */
  NS_IMETHOD GetCopyright(PRUnichar * *aCopyright) = 0;

  /* attribute mozIPersonalDictionary personalDictionary; */
  NS_IMETHOD GetPersonalDictionary(mozIPersonalDictionary * *aPersonalDictionary) = 0;
  NS_IMETHOD SetPersonalDictionary(mozIPersonalDictionary *aPersonalDictionary) = 0;

  /* void getDictionaryList ([array, size_is (count)] out wstring dictionaries, out uint32_t count); */
  NS_IMETHOD GetDictionaryList(PRUnichar * **dictionaries, uint32_t *count) = 0;

  /* boolean check (in wstring word); */
  NS_IMETHOD Check(const PRUnichar * word, bool *_retval) = 0;

  /* void suggest (in wstring word, [array, size_is (count)] out wstring suggestions, out uint32_t count); */
  NS_IMETHOD Suggest(const PRUnichar * word, PRUnichar * **suggestions, uint32_t *count) = 0;

  /* void loadDictionariesFromDir (in nsIFile dir); */
  NS_IMETHOD LoadDictionariesFromDir(nsIFile *dir) = 0;

  /* void addDirectory (in nsIFile dir); */
  NS_IMETHOD AddDirectory(nsIFile *dir) = 0;

  /* void removeDirectory (in nsIFile dir); */
  NS_IMETHOD RemoveDirectory(nsIFile *dir) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozISpellCheckingEngine, MOZISPELLCHECKINGENGINE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISPELLCHECKINGENGINE \
  NS_IMETHOD GetDictionary(PRUnichar * *aDictionary); \
  NS_IMETHOD SetDictionary(const PRUnichar * aDictionary); \
  NS_IMETHOD GetLanguage(PRUnichar * *aLanguage); \
  NS_IMETHOD GetProvidesPersonalDictionary(bool *aProvidesPersonalDictionary); \
  NS_IMETHOD GetProvidesWordUtils(bool *aProvidesWordUtils); \
  NS_IMETHOD GetName(PRUnichar * *aName); \
  NS_IMETHOD GetCopyright(PRUnichar * *aCopyright); \
  NS_IMETHOD GetPersonalDictionary(mozIPersonalDictionary * *aPersonalDictionary); \
  NS_IMETHOD SetPersonalDictionary(mozIPersonalDictionary *aPersonalDictionary); \
  NS_IMETHOD GetDictionaryList(PRUnichar * **dictionaries, uint32_t *count); \
  NS_IMETHOD Check(const PRUnichar * word, bool *_retval); \
  NS_IMETHOD Suggest(const PRUnichar * word, PRUnichar * **suggestions, uint32_t *count); \
  NS_IMETHOD LoadDictionariesFromDir(nsIFile *dir); \
  NS_IMETHOD AddDirectory(nsIFile *dir); \
  NS_IMETHOD RemoveDirectory(nsIFile *dir); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISPELLCHECKINGENGINE(_to) \
  NS_IMETHOD GetDictionary(PRUnichar * *aDictionary) { return _to GetDictionary(aDictionary); } \
  NS_IMETHOD SetDictionary(const PRUnichar * aDictionary) { return _to SetDictionary(aDictionary); } \
  NS_IMETHOD GetLanguage(PRUnichar * *aLanguage) { return _to GetLanguage(aLanguage); } \
  NS_IMETHOD GetProvidesPersonalDictionary(bool *aProvidesPersonalDictionary) { return _to GetProvidesPersonalDictionary(aProvidesPersonalDictionary); } \
  NS_IMETHOD GetProvidesWordUtils(bool *aProvidesWordUtils) { return _to GetProvidesWordUtils(aProvidesWordUtils); } \
  NS_IMETHOD GetName(PRUnichar * *aName) { return _to GetName(aName); } \
  NS_IMETHOD GetCopyright(PRUnichar * *aCopyright) { return _to GetCopyright(aCopyright); } \
  NS_IMETHOD GetPersonalDictionary(mozIPersonalDictionary * *aPersonalDictionary) { return _to GetPersonalDictionary(aPersonalDictionary); } \
  NS_IMETHOD SetPersonalDictionary(mozIPersonalDictionary *aPersonalDictionary) { return _to SetPersonalDictionary(aPersonalDictionary); } \
  NS_IMETHOD GetDictionaryList(PRUnichar * **dictionaries, uint32_t *count) { return _to GetDictionaryList(dictionaries, count); } \
  NS_IMETHOD Check(const PRUnichar * word, bool *_retval) { return _to Check(word, _retval); } \
  NS_IMETHOD Suggest(const PRUnichar * word, PRUnichar * **suggestions, uint32_t *count) { return _to Suggest(word, suggestions, count); } \
  NS_IMETHOD LoadDictionariesFromDir(nsIFile *dir) { return _to LoadDictionariesFromDir(dir); } \
  NS_IMETHOD AddDirectory(nsIFile *dir) { return _to AddDirectory(dir); } \
  NS_IMETHOD RemoveDirectory(nsIFile *dir) { return _to RemoveDirectory(dir); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISPELLCHECKINGENGINE(_to) \
  NS_IMETHOD GetDictionary(PRUnichar * *aDictionary) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDictionary(aDictionary); } \
  NS_IMETHOD SetDictionary(const PRUnichar * aDictionary) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDictionary(aDictionary); } \
  NS_IMETHOD GetLanguage(PRUnichar * *aLanguage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLanguage(aLanguage); } \
  NS_IMETHOD GetProvidesPersonalDictionary(bool *aProvidesPersonalDictionary) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProvidesPersonalDictionary(aProvidesPersonalDictionary); } \
  NS_IMETHOD GetProvidesWordUtils(bool *aProvidesWordUtils) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProvidesWordUtils(aProvidesWordUtils); } \
  NS_IMETHOD GetName(PRUnichar * *aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetCopyright(PRUnichar * *aCopyright) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCopyright(aCopyright); } \
  NS_IMETHOD GetPersonalDictionary(mozIPersonalDictionary * *aPersonalDictionary) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPersonalDictionary(aPersonalDictionary); } \
  NS_IMETHOD SetPersonalDictionary(mozIPersonalDictionary *aPersonalDictionary) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPersonalDictionary(aPersonalDictionary); } \
  NS_IMETHOD GetDictionaryList(PRUnichar * **dictionaries, uint32_t *count) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDictionaryList(dictionaries, count); } \
  NS_IMETHOD Check(const PRUnichar * word, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Check(word, _retval); } \
  NS_IMETHOD Suggest(const PRUnichar * word, PRUnichar * **suggestions, uint32_t *count) { return !_to ? NS_ERROR_NULL_POINTER : _to->Suggest(word, suggestions, count); } \
  NS_IMETHOD LoadDictionariesFromDir(nsIFile *dir) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadDictionariesFromDir(dir); } \
  NS_IMETHOD AddDirectory(nsIFile *dir) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddDirectory(dir); } \
  NS_IMETHOD RemoveDirectory(nsIFile *dir) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveDirectory(dir); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozISpellCheckingEngine
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISPELLCHECKINGENGINE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozISpellCheckingEngine)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* attribute wstring dictionary; */
NS_IMETHODIMP _MYCLASS_::GetDictionary(PRUnichar * *aDictionary)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetDictionary(const PRUnichar * aDictionary)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring language; */
NS_IMETHODIMP _MYCLASS_::GetLanguage(PRUnichar * *aLanguage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean providesPersonalDictionary; */
NS_IMETHODIMP _MYCLASS_::GetProvidesPersonalDictionary(bool *aProvidesPersonalDictionary)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean providesWordUtils; */
NS_IMETHODIMP _MYCLASS_::GetProvidesWordUtils(bool *aProvidesWordUtils)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring name; */
NS_IMETHODIMP _MYCLASS_::GetName(PRUnichar * *aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring copyright; */
NS_IMETHODIMP _MYCLASS_::GetCopyright(PRUnichar * *aCopyright)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute mozIPersonalDictionary personalDictionary; */
NS_IMETHODIMP _MYCLASS_::GetPersonalDictionary(mozIPersonalDictionary * *aPersonalDictionary)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetPersonalDictionary(mozIPersonalDictionary *aPersonalDictionary)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getDictionaryList ([array, size_is (count)] out wstring dictionaries, out uint32_t count); */
NS_IMETHODIMP _MYCLASS_::GetDictionaryList(PRUnichar * **dictionaries, uint32_t *count)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean check (in wstring word); */
NS_IMETHODIMP _MYCLASS_::Check(const PRUnichar * word, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void suggest (in wstring word, [array, size_is (count)] out wstring suggestions, out uint32_t count); */
NS_IMETHODIMP _MYCLASS_::Suggest(const PRUnichar * word, PRUnichar * **suggestions, uint32_t *count)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadDictionariesFromDir (in nsIFile dir); */
NS_IMETHODIMP _MYCLASS_::LoadDictionariesFromDir(nsIFile *dir)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addDirectory (in nsIFile dir); */
NS_IMETHODIMP _MYCLASS_::AddDirectory(nsIFile *dir)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeDirectory (in nsIFile dir); */
NS_IMETHODIMP _MYCLASS_::RemoveDirectory(nsIFile *dir)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define DICTIONARY_SEARCH_DIRECTORY "DictD"
#define DICTIONARY_SEARCH_DIRECTORY_LIST "DictDL"
#define SPELLCHECK_DICTIONARY_UPDATE_NOTIFICATION \
  "spellcheck-dictionary-update"

#endif /* __gen_mozISpellCheckingEngine_h__ */

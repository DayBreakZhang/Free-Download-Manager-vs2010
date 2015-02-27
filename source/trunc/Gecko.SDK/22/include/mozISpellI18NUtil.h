/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/extensions/spellcheck/idl/mozISpellI18NUtil.idl
 */

#ifndef __gen_mozISpellI18NUtil_h__
#define __gen_mozISpellI18NUtil_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    mozISpellI18NUtil */
#define MOZISPELLI18NUTIL_IID_STR "b075d5dc-1df1-441a-bebf-680d8caaa19c"

#define MOZISPELLI18NUTIL_IID \
  {0xb075d5dc, 0x1df1, 0x441a, \
    { 0xbe, 0xbf, 0x68, 0x0d, 0x8c, 0xaa, 0xa1, 0x9c }}

class NS_NO_VTABLE mozISpellI18NUtil : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISPELLI18NUTIL_IID)

  enum {
    kCheck = 0U,
    kSuggest = 1U
  };

  /* readonly attribute wstring language; */
  NS_IMETHOD GetLanguage(PRUnichar * *aLanguage) = 0;

  /* void getRootForm (in wstring word, in uint32_t type, [array, size_is (count)] out wstring words, out uint32_t count); */
  NS_IMETHOD GetRootForm(const PRUnichar * word, uint32_t type, PRUnichar * **words, uint32_t *count) = 0;

  /* void fromRootForm (in wstring word, [array, size_is (icount)] in wstring iwords, in uint32_t icount, [array, size_is (ocount)] out wstring owords, out uint32_t ocount); */
  NS_IMETHOD FromRootForm(const PRUnichar * word, const PRUnichar * *iwords, uint32_t icount, PRUnichar * **owords, uint32_t *ocount) = 0;

  /* void findNextWord (in wstring word, in uint32_t length, in uint32_t offset, out int32_t begin, out int32_t end); */
  NS_IMETHOD FindNextWord(const PRUnichar * word, uint32_t length, uint32_t offset, int32_t *begin, int32_t *end) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozISpellI18NUtil, MOZISPELLI18NUTIL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISPELLI18NUTIL \
  NS_IMETHOD GetLanguage(PRUnichar * *aLanguage); \
  NS_IMETHOD GetRootForm(const PRUnichar * word, uint32_t type, PRUnichar * **words, uint32_t *count); \
  NS_IMETHOD FromRootForm(const PRUnichar * word, const PRUnichar * *iwords, uint32_t icount, PRUnichar * **owords, uint32_t *ocount); \
  NS_IMETHOD FindNextWord(const PRUnichar * word, uint32_t length, uint32_t offset, int32_t *begin, int32_t *end); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISPELLI18NUTIL(_to) \
  NS_IMETHOD GetLanguage(PRUnichar * *aLanguage) { return _to GetLanguage(aLanguage); } \
  NS_IMETHOD GetRootForm(const PRUnichar * word, uint32_t type, PRUnichar * **words, uint32_t *count) { return _to GetRootForm(word, type, words, count); } \
  NS_IMETHOD FromRootForm(const PRUnichar * word, const PRUnichar * *iwords, uint32_t icount, PRUnichar * **owords, uint32_t *ocount) { return _to FromRootForm(word, iwords, icount, owords, ocount); } \
  NS_IMETHOD FindNextWord(const PRUnichar * word, uint32_t length, uint32_t offset, int32_t *begin, int32_t *end) { return _to FindNextWord(word, length, offset, begin, end); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISPELLI18NUTIL(_to) \
  NS_IMETHOD GetLanguage(PRUnichar * *aLanguage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLanguage(aLanguage); } \
  NS_IMETHOD GetRootForm(const PRUnichar * word, uint32_t type, PRUnichar * **words, uint32_t *count) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootForm(word, type, words, count); } \
  NS_IMETHOD FromRootForm(const PRUnichar * word, const PRUnichar * *iwords, uint32_t icount, PRUnichar * **owords, uint32_t *ocount) { return !_to ? NS_ERROR_NULL_POINTER : _to->FromRootForm(word, iwords, icount, owords, ocount); } \
  NS_IMETHOD FindNextWord(const PRUnichar * word, uint32_t length, uint32_t offset, int32_t *begin, int32_t *end) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindNextWord(word, length, offset, begin, end); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozISpellI18NUtil
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISPELLI18NUTIL

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozISpellI18NUtil)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute wstring language; */
NS_IMETHODIMP _MYCLASS_::GetLanguage(PRUnichar * *aLanguage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getRootForm (in wstring word, in uint32_t type, [array, size_is (count)] out wstring words, out uint32_t count); */
NS_IMETHODIMP _MYCLASS_::GetRootForm(const PRUnichar * word, uint32_t type, PRUnichar * **words, uint32_t *count)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void fromRootForm (in wstring word, [array, size_is (icount)] in wstring iwords, in uint32_t icount, [array, size_is (ocount)] out wstring owords, out uint32_t ocount); */
NS_IMETHODIMP _MYCLASS_::FromRootForm(const PRUnichar * word, const PRUnichar * *iwords, uint32_t icount, PRUnichar * **owords, uint32_t *ocount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void findNextWord (in wstring word, in uint32_t length, in uint32_t offset, out int32_t begin, out int32_t end); */
NS_IMETHODIMP _MYCLASS_::FindNextWord(const PRUnichar * word, uint32_t length, uint32_t offset, int32_t *begin, int32_t *end)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozISpellI18NUtil_h__ */

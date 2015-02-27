/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/gfx/src/nsIFontEnumerator.idl
 */

#ifndef __gen_nsIFontEnumerator_h__
#define __gen_nsIFontEnumerator_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIFontEnumerator */
#define NS_IFONTENUMERATOR_IID_STR "924d98d9-3518-4cb4-8708-c74fe8e3ec3c"

#define NS_IFONTENUMERATOR_IID \
  {0x924d98d9, 0x3518, 0x4cb4, \
    { 0x87, 0x08, 0xc7, 0x4f, 0xe8, 0xe3, 0xec, 0x3c }}

class NS_NO_VTABLE nsIFontEnumerator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFONTENUMERATOR_IID)

  /* void EnumerateAllFonts (out uint32_t aCount, [array, size_is (aCount), retval] out wstring aResult); */
  NS_IMETHOD EnumerateAllFonts(uint32_t *aCount, PRUnichar * **aResult) = 0;

  /* void EnumerateFonts (in string aLangGroup, in string aGeneric, out uint32_t aCount, [array, size_is (aCount), retval] out wstring aResult); */
  NS_IMETHOD EnumerateFonts(const char * aLangGroup, const char * aGeneric, uint32_t *aCount, PRUnichar * **aResult) = 0;

  /* void HaveFontFor (in string aLangGroup, [retval] out boolean aResult); */
  NS_IMETHOD HaveFontFor(const char * aLangGroup, bool *aResult) = 0;

  /* wstring getDefaultFont (in string aLangGroup, in string aGeneric); */
  NS_IMETHOD GetDefaultFont(const char * aLangGroup, const char * aGeneric, PRUnichar * *_retval) = 0;

  /* boolean updateFontList (); */
  NS_IMETHOD UpdateFontList(bool *_retval) = 0;

  /* wstring getStandardFamilyName (in wstring aName); */
  NS_IMETHOD GetStandardFamilyName(const PRUnichar * aName, PRUnichar * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFontEnumerator, NS_IFONTENUMERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFONTENUMERATOR \
  NS_IMETHOD EnumerateAllFonts(uint32_t *aCount, PRUnichar * **aResult); \
  NS_IMETHOD EnumerateFonts(const char * aLangGroup, const char * aGeneric, uint32_t *aCount, PRUnichar * **aResult); \
  NS_IMETHOD HaveFontFor(const char * aLangGroup, bool *aResult); \
  NS_IMETHOD GetDefaultFont(const char * aLangGroup, const char * aGeneric, PRUnichar * *_retval); \
  NS_IMETHOD UpdateFontList(bool *_retval); \
  NS_IMETHOD GetStandardFamilyName(const PRUnichar * aName, PRUnichar * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFONTENUMERATOR(_to) \
  NS_IMETHOD EnumerateAllFonts(uint32_t *aCount, PRUnichar * **aResult) { return _to EnumerateAllFonts(aCount, aResult); } \
  NS_IMETHOD EnumerateFonts(const char * aLangGroup, const char * aGeneric, uint32_t *aCount, PRUnichar * **aResult) { return _to EnumerateFonts(aLangGroup, aGeneric, aCount, aResult); } \
  NS_IMETHOD HaveFontFor(const char * aLangGroup, bool *aResult) { return _to HaveFontFor(aLangGroup, aResult); } \
  NS_IMETHOD GetDefaultFont(const char * aLangGroup, const char * aGeneric, PRUnichar * *_retval) { return _to GetDefaultFont(aLangGroup, aGeneric, _retval); } \
  NS_IMETHOD UpdateFontList(bool *_retval) { return _to UpdateFontList(_retval); } \
  NS_IMETHOD GetStandardFamilyName(const PRUnichar * aName, PRUnichar * *_retval) { return _to GetStandardFamilyName(aName, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFONTENUMERATOR(_to) \
  NS_IMETHOD EnumerateAllFonts(uint32_t *aCount, PRUnichar * **aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateAllFonts(aCount, aResult); } \
  NS_IMETHOD EnumerateFonts(const char * aLangGroup, const char * aGeneric, uint32_t *aCount, PRUnichar * **aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateFonts(aLangGroup, aGeneric, aCount, aResult); } \
  NS_IMETHOD HaveFontFor(const char * aLangGroup, bool *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->HaveFontFor(aLangGroup, aResult); } \
  NS_IMETHOD GetDefaultFont(const char * aLangGroup, const char * aGeneric, PRUnichar * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultFont(aLangGroup, aGeneric, _retval); } \
  NS_IMETHOD UpdateFontList(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateFontList(_retval); } \
  NS_IMETHOD GetStandardFamilyName(const PRUnichar * aName, PRUnichar * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStandardFamilyName(aName, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFontEnumerator : public nsIFontEnumerator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFONTENUMERATOR

  nsFontEnumerator();

private:
  ~nsFontEnumerator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFontEnumerator, nsIFontEnumerator)

nsFontEnumerator::nsFontEnumerator()
{
  /* member initializers and constructor code */
}

nsFontEnumerator::~nsFontEnumerator()
{
  /* destructor code */
}

/* void EnumerateAllFonts (out uint32_t aCount, [array, size_is (aCount), retval] out wstring aResult); */
NS_IMETHODIMP nsFontEnumerator::EnumerateAllFonts(uint32_t *aCount, PRUnichar * **aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void EnumerateFonts (in string aLangGroup, in string aGeneric, out uint32_t aCount, [array, size_is (aCount), retval] out wstring aResult); */
NS_IMETHODIMP nsFontEnumerator::EnumerateFonts(const char * aLangGroup, const char * aGeneric, uint32_t *aCount, PRUnichar * **aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void HaveFontFor (in string aLangGroup, [retval] out boolean aResult); */
NS_IMETHODIMP nsFontEnumerator::HaveFontFor(const char * aLangGroup, bool *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring getDefaultFont (in string aLangGroup, in string aGeneric); */
NS_IMETHODIMP nsFontEnumerator::GetDefaultFont(const char * aLangGroup, const char * aGeneric, PRUnichar * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean updateFontList (); */
NS_IMETHODIMP nsFontEnumerator::UpdateFontList(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring getStandardFamilyName (in wstring aName); */
NS_IMETHODIMP nsFontEnumerator::GetStandardFamilyName(const PRUnichar * aName, PRUnichar * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFontEnumerator_h__ */

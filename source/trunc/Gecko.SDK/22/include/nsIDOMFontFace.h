/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/layout/inspector/public/nsIDOMFontFace.idl
 */

#ifndef __gen_nsIDOMFontFace_h__
#define __gen_nsIDOMFontFace_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMCSSFontFaceRule; /* forward declaration */

class nsIDOMCSSStyleDeclaration; /* forward declaration */


/* starting interface:    nsIDOMFontFace */
#define NS_IDOMFONTFACE_IID_STR "9a3b1272-6585-4f41-b08f-fdc5da444cd0"

#define NS_IDOMFONTFACE_IID \
  {0x9a3b1272, 0x6585, 0x4f41, \
    { 0xb0, 0x8f, 0xfd, 0xc5, 0xda, 0x44, 0x4c, 0xd0 }}

class NS_NO_VTABLE nsIDOMFontFace : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMFONTFACE_IID)

  /* readonly attribute boolean fromFontGroup; */
  NS_IMETHOD GetFromFontGroup(bool *aFromFontGroup) = 0;

  /* readonly attribute boolean fromLanguagePrefs; */
  NS_IMETHOD GetFromLanguagePrefs(bool *aFromLanguagePrefs) = 0;

  /* readonly attribute boolean fromSystemFallback; */
  NS_IMETHOD GetFromSystemFallback(bool *aFromSystemFallback) = 0;

  /* readonly attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute DOMString CSSFamilyName; */
  NS_IMETHOD GetCSSFamilyName(nsAString & aCSSFamilyName) = 0;

  /* readonly attribute nsIDOMCSSFontFaceRule rule; */
  NS_IMETHOD GetRule(nsIDOMCSSFontFaceRule * *aRule) = 0;

  /* readonly attribute long srcIndex; */
  NS_IMETHOD GetSrcIndex(int32_t *aSrcIndex) = 0;

  /* readonly attribute DOMString URI; */
  NS_IMETHOD GetURI(nsAString & aURI) = 0;

  /* readonly attribute DOMString localName; */
  NS_IMETHOD GetLocalName(nsAString & aLocalName) = 0;

  /* readonly attribute DOMString format; */
  NS_IMETHOD GetFormat(nsAString & aFormat) = 0;

  /* readonly attribute DOMString metadata; */
  NS_IMETHOD GetMetadata(nsAString & aMetadata) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMFontFace, NS_IDOMFONTFACE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMFONTFACE \
  NS_IMETHOD GetFromFontGroup(bool *aFromFontGroup); \
  NS_IMETHOD GetFromLanguagePrefs(bool *aFromLanguagePrefs); \
  NS_IMETHOD GetFromSystemFallback(bool *aFromSystemFallback); \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD GetCSSFamilyName(nsAString & aCSSFamilyName); \
  NS_IMETHOD GetRule(nsIDOMCSSFontFaceRule * *aRule); \
  NS_IMETHOD GetSrcIndex(int32_t *aSrcIndex); \
  NS_IMETHOD GetURI(nsAString & aURI); \
  NS_IMETHOD GetLocalName(nsAString & aLocalName); \
  NS_IMETHOD GetFormat(nsAString & aFormat); \
  NS_IMETHOD GetMetadata(nsAString & aMetadata); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMFONTFACE(_to) \
  NS_IMETHOD GetFromFontGroup(bool *aFromFontGroup) { return _to GetFromFontGroup(aFromFontGroup); } \
  NS_IMETHOD GetFromLanguagePrefs(bool *aFromLanguagePrefs) { return _to GetFromLanguagePrefs(aFromLanguagePrefs); } \
  NS_IMETHOD GetFromSystemFallback(bool *aFromSystemFallback) { return _to GetFromSystemFallback(aFromSystemFallback); } \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD GetCSSFamilyName(nsAString & aCSSFamilyName) { return _to GetCSSFamilyName(aCSSFamilyName); } \
  NS_IMETHOD GetRule(nsIDOMCSSFontFaceRule * *aRule) { return _to GetRule(aRule); } \
  NS_IMETHOD GetSrcIndex(int32_t *aSrcIndex) { return _to GetSrcIndex(aSrcIndex); } \
  NS_IMETHOD GetURI(nsAString & aURI) { return _to GetURI(aURI); } \
  NS_IMETHOD GetLocalName(nsAString & aLocalName) { return _to GetLocalName(aLocalName); } \
  NS_IMETHOD GetFormat(nsAString & aFormat) { return _to GetFormat(aFormat); } \
  NS_IMETHOD GetMetadata(nsAString & aMetadata) { return _to GetMetadata(aMetadata); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMFONTFACE(_to) \
  NS_IMETHOD GetFromFontGroup(bool *aFromFontGroup) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFromFontGroup(aFromFontGroup); } \
  NS_IMETHOD GetFromLanguagePrefs(bool *aFromLanguagePrefs) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFromLanguagePrefs(aFromLanguagePrefs); } \
  NS_IMETHOD GetFromSystemFallback(bool *aFromSystemFallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFromSystemFallback(aFromSystemFallback); } \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetCSSFamilyName(nsAString & aCSSFamilyName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCSSFamilyName(aCSSFamilyName); } \
  NS_IMETHOD GetRule(nsIDOMCSSFontFaceRule * *aRule) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRule(aRule); } \
  NS_IMETHOD GetSrcIndex(int32_t *aSrcIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSrcIndex(aSrcIndex); } \
  NS_IMETHOD GetURI(nsAString & aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURI(aURI); } \
  NS_IMETHOD GetLocalName(nsAString & aLocalName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalName(aLocalName); } \
  NS_IMETHOD GetFormat(nsAString & aFormat) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFormat(aFormat); } \
  NS_IMETHOD GetMetadata(nsAString & aMetadata) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMetadata(aMetadata); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMFontFace : public nsIDOMFontFace
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMFONTFACE

  nsDOMFontFace();

private:
  ~nsDOMFontFace();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMFontFace, nsIDOMFontFace)

nsDOMFontFace::nsDOMFontFace()
{
  /* member initializers and constructor code */
}

nsDOMFontFace::~nsDOMFontFace()
{
  /* destructor code */
}

/* readonly attribute boolean fromFontGroup; */
NS_IMETHODIMP nsDOMFontFace::GetFromFontGroup(bool *aFromFontGroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean fromLanguagePrefs; */
NS_IMETHODIMP nsDOMFontFace::GetFromLanguagePrefs(bool *aFromLanguagePrefs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean fromSystemFallback; */
NS_IMETHODIMP nsDOMFontFace::GetFromSystemFallback(bool *aFromSystemFallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString name; */
NS_IMETHODIMP nsDOMFontFace::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString CSSFamilyName; */
NS_IMETHODIMP nsDOMFontFace::GetCSSFamilyName(nsAString & aCSSFamilyName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMCSSFontFaceRule rule; */
NS_IMETHODIMP nsDOMFontFace::GetRule(nsIDOMCSSFontFaceRule * *aRule)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long srcIndex; */
NS_IMETHODIMP nsDOMFontFace::GetSrcIndex(int32_t *aSrcIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString URI; */
NS_IMETHODIMP nsDOMFontFace::GetURI(nsAString & aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString localName; */
NS_IMETHODIMP nsDOMFontFace::GetLocalName(nsAString & aLocalName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString format; */
NS_IMETHODIMP nsDOMFontFace::GetFormat(nsAString & aFormat)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString metadata; */
NS_IMETHODIMP nsDOMFontFace::GetMetadata(nsAString & aMetadata)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMFontFace_h__ */

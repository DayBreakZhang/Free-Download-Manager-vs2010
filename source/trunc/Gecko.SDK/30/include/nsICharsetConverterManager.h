/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICharsetConverterManager.idl
 */

#ifndef __gen_nsICharsetConverterManager_h__
#define __gen_nsICharsetConverterManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIAtom_h__
#include "nsIAtom.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsIUnicodeDecoder.h"
#include "nsIUnicodeEncoder.h"
// XXX change to NS_CHARSETCONVERTERMANAGER_CID
#define NS_ICHARSETCONVERTERMANAGER_CID \
  {0x3c1c0163, 0x9bd0, 0x11d3, { 0x9d, 0x9, 0x0, 0x50, 0x4, 0x0, 0x7, 0xb2}}
#define NS_CHARSETCONVERTERMANAGER_CONTRACTID "@mozilla.org/charset-converter-manager;1"
class nsIUnicodeDecoder; /* forward declaration */

class nsIUnicodeEncoder; /* forward declaration */

class nsIUTF8StringEnumerator; /* forward declaration */


/* starting interface:    nsICharsetConverterManager */
#define NS_ICHARSETCONVERTERMANAGER_IID_STR "a0550d46-8d9c-47dd-acc7-c083620dff12"

#define NS_ICHARSETCONVERTERMANAGER_IID \
  {0xa0550d46, 0x8d9c, 0x47dd, \
    { 0xac, 0xc7, 0xc0, 0x83, 0x62, 0x0d, 0xff, 0x12 }}

class NS_NO_VTABLE nsICharsetConverterManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICHARSETCONVERTERMANAGER_IID)

  /* [noscript] nsIUnicodeDecoder getUnicodeDecoder (in string charset); */
  NS_IMETHOD GetUnicodeDecoder(const char * charset, nsIUnicodeDecoder * *_retval) = 0;

  /* [noscript] nsIUnicodeDecoder getUnicodeDecoderRaw (in string charset); */
  NS_IMETHOD GetUnicodeDecoderRaw(const char * charset, nsIUnicodeDecoder * *_retval) = 0;

  /* [noscript] nsIUnicodeDecoder getUnicodeDecoderInternal (in string charset); */
  NS_IMETHOD GetUnicodeDecoderInternal(const char * charset, nsIUnicodeDecoder * *_retval) = 0;

  /* [noscript] nsIUnicodeEncoder getUnicodeEncoder (in string charset); */
  NS_IMETHOD GetUnicodeEncoder(const char * charset, nsIUnicodeEncoder * *_retval) = 0;

  /* [noscript] nsIUnicodeEncoder getUnicodeEncoderRaw (in string charset); */
  NS_IMETHOD GetUnicodeEncoderRaw(const char * charset, nsIUnicodeEncoder * *_retval) = 0;

  /* ACString getCharsetAlias (in string aCharset); */
  NS_IMETHOD GetCharsetAlias(const char * aCharset, nsACString & _retval) = 0;

  /* nsIUTF8StringEnumerator getDecoderList (); */
  NS_IMETHOD GetDecoderList(nsIUTF8StringEnumerator * *_retval) = 0;

  /* nsIUTF8StringEnumerator getEncoderList (); */
  NS_IMETHOD GetEncoderList(nsIUTF8StringEnumerator * *_retval) = 0;

  /* nsIUTF8StringEnumerator GetCharsetDetectorList (); */
  NS_IMETHOD GetCharsetDetectorList(nsIUTF8StringEnumerator * *_retval) = 0;

  /* AString getCharsetTitle (in string aCharset); */
  NS_IMETHOD GetCharsetTitle(const char * aCharset, nsAString & _retval) = 0;

  /* AString getCharsetData (in string aCharset, in wstring aProp); */
  NS_IMETHOD GetCharsetData(const char * aCharset, const char16_t * aProp, nsAString & _retval) = 0;

  /* nsIAtom getCharsetLangGroup (in string aCharset); */
  NS_IMETHOD GetCharsetLangGroup(const char * aCharset, nsIAtom * *_retval) = 0;

  /* nsIAtom getCharsetLangGroupRaw (in string aCharset); */
  NS_IMETHOD GetCharsetLangGroupRaw(const char * aCharset, nsIAtom * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICharsetConverterManager, NS_ICHARSETCONVERTERMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICHARSETCONVERTERMANAGER \
  NS_IMETHOD GetUnicodeDecoder(const char * charset, nsIUnicodeDecoder * *_retval); \
  NS_IMETHOD GetUnicodeDecoderRaw(const char * charset, nsIUnicodeDecoder * *_retval); \
  NS_IMETHOD GetUnicodeDecoderInternal(const char * charset, nsIUnicodeDecoder * *_retval); \
  NS_IMETHOD GetUnicodeEncoder(const char * charset, nsIUnicodeEncoder * *_retval); \
  NS_IMETHOD GetUnicodeEncoderRaw(const char * charset, nsIUnicodeEncoder * *_retval); \
  NS_IMETHOD GetCharsetAlias(const char * aCharset, nsACString & _retval); \
  NS_IMETHOD GetDecoderList(nsIUTF8StringEnumerator * *_retval); \
  NS_IMETHOD GetEncoderList(nsIUTF8StringEnumerator * *_retval); \
  NS_IMETHOD GetCharsetDetectorList(nsIUTF8StringEnumerator * *_retval); \
  NS_IMETHOD GetCharsetTitle(const char * aCharset, nsAString & _retval); \
  NS_IMETHOD GetCharsetData(const char * aCharset, const char16_t * aProp, nsAString & _retval); \
  NS_IMETHOD GetCharsetLangGroup(const char * aCharset, nsIAtom * *_retval); \
  NS_IMETHOD GetCharsetLangGroupRaw(const char * aCharset, nsIAtom * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICHARSETCONVERTERMANAGER(_to) \
  NS_IMETHOD GetUnicodeDecoder(const char * charset, nsIUnicodeDecoder * *_retval) { return _to GetUnicodeDecoder(charset, _retval); } \
  NS_IMETHOD GetUnicodeDecoderRaw(const char * charset, nsIUnicodeDecoder * *_retval) { return _to GetUnicodeDecoderRaw(charset, _retval); } \
  NS_IMETHOD GetUnicodeDecoderInternal(const char * charset, nsIUnicodeDecoder * *_retval) { return _to GetUnicodeDecoderInternal(charset, _retval); } \
  NS_IMETHOD GetUnicodeEncoder(const char * charset, nsIUnicodeEncoder * *_retval) { return _to GetUnicodeEncoder(charset, _retval); } \
  NS_IMETHOD GetUnicodeEncoderRaw(const char * charset, nsIUnicodeEncoder * *_retval) { return _to GetUnicodeEncoderRaw(charset, _retval); } \
  NS_IMETHOD GetCharsetAlias(const char * aCharset, nsACString & _retval) { return _to GetCharsetAlias(aCharset, _retval); } \
  NS_IMETHOD GetDecoderList(nsIUTF8StringEnumerator * *_retval) { return _to GetDecoderList(_retval); } \
  NS_IMETHOD GetEncoderList(nsIUTF8StringEnumerator * *_retval) { return _to GetEncoderList(_retval); } \
  NS_IMETHOD GetCharsetDetectorList(nsIUTF8StringEnumerator * *_retval) { return _to GetCharsetDetectorList(_retval); } \
  NS_IMETHOD GetCharsetTitle(const char * aCharset, nsAString & _retval) { return _to GetCharsetTitle(aCharset, _retval); } \
  NS_IMETHOD GetCharsetData(const char * aCharset, const char16_t * aProp, nsAString & _retval) { return _to GetCharsetData(aCharset, aProp, _retval); } \
  NS_IMETHOD GetCharsetLangGroup(const char * aCharset, nsIAtom * *_retval) { return _to GetCharsetLangGroup(aCharset, _retval); } \
  NS_IMETHOD GetCharsetLangGroupRaw(const char * aCharset, nsIAtom * *_retval) { return _to GetCharsetLangGroupRaw(aCharset, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICHARSETCONVERTERMANAGER(_to) \
  NS_IMETHOD GetUnicodeDecoder(const char * charset, nsIUnicodeDecoder * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnicodeDecoder(charset, _retval); } \
  NS_IMETHOD GetUnicodeDecoderRaw(const char * charset, nsIUnicodeDecoder * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnicodeDecoderRaw(charset, _retval); } \
  NS_IMETHOD GetUnicodeDecoderInternal(const char * charset, nsIUnicodeDecoder * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnicodeDecoderInternal(charset, _retval); } \
  NS_IMETHOD GetUnicodeEncoder(const char * charset, nsIUnicodeEncoder * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnicodeEncoder(charset, _retval); } \
  NS_IMETHOD GetUnicodeEncoderRaw(const char * charset, nsIUnicodeEncoder * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnicodeEncoderRaw(charset, _retval); } \
  NS_IMETHOD GetCharsetAlias(const char * aCharset, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharsetAlias(aCharset, _retval); } \
  NS_IMETHOD GetDecoderList(nsIUTF8StringEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDecoderList(_retval); } \
  NS_IMETHOD GetEncoderList(nsIUTF8StringEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEncoderList(_retval); } \
  NS_IMETHOD GetCharsetDetectorList(nsIUTF8StringEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharsetDetectorList(_retval); } \
  NS_IMETHOD GetCharsetTitle(const char * aCharset, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharsetTitle(aCharset, _retval); } \
  NS_IMETHOD GetCharsetData(const char * aCharset, const char16_t * aProp, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharsetData(aCharset, aProp, _retval); } \
  NS_IMETHOD GetCharsetLangGroup(const char * aCharset, nsIAtom * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharsetLangGroup(aCharset, _retval); } \
  NS_IMETHOD GetCharsetLangGroupRaw(const char * aCharset, nsIAtom * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharsetLangGroupRaw(aCharset, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCharsetConverterManager : public nsICharsetConverterManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICHARSETCONVERTERMANAGER

  nsCharsetConverterManager();

private:
  ~nsCharsetConverterManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCharsetConverterManager, nsICharsetConverterManager)

nsCharsetConverterManager::nsCharsetConverterManager()
{
  /* member initializers and constructor code */
}

nsCharsetConverterManager::~nsCharsetConverterManager()
{
  /* destructor code */
}

/* [noscript] nsIUnicodeDecoder getUnicodeDecoder (in string charset); */
NS_IMETHODIMP nsCharsetConverterManager::GetUnicodeDecoder(const char * charset, nsIUnicodeDecoder * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIUnicodeDecoder getUnicodeDecoderRaw (in string charset); */
NS_IMETHODIMP nsCharsetConverterManager::GetUnicodeDecoderRaw(const char * charset, nsIUnicodeDecoder * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIUnicodeDecoder getUnicodeDecoderInternal (in string charset); */
NS_IMETHODIMP nsCharsetConverterManager::GetUnicodeDecoderInternal(const char * charset, nsIUnicodeDecoder * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIUnicodeEncoder getUnicodeEncoder (in string charset); */
NS_IMETHODIMP nsCharsetConverterManager::GetUnicodeEncoder(const char * charset, nsIUnicodeEncoder * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIUnicodeEncoder getUnicodeEncoderRaw (in string charset); */
NS_IMETHODIMP nsCharsetConverterManager::GetUnicodeEncoderRaw(const char * charset, nsIUnicodeEncoder * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getCharsetAlias (in string aCharset); */
NS_IMETHODIMP nsCharsetConverterManager::GetCharsetAlias(const char * aCharset, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIUTF8StringEnumerator getDecoderList (); */
NS_IMETHODIMP nsCharsetConverterManager::GetDecoderList(nsIUTF8StringEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIUTF8StringEnumerator getEncoderList (); */
NS_IMETHODIMP nsCharsetConverterManager::GetEncoderList(nsIUTF8StringEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIUTF8StringEnumerator GetCharsetDetectorList (); */
NS_IMETHODIMP nsCharsetConverterManager::GetCharsetDetectorList(nsIUTF8StringEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getCharsetTitle (in string aCharset); */
NS_IMETHODIMP nsCharsetConverterManager::GetCharsetTitle(const char * aCharset, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getCharsetData (in string aCharset, in wstring aProp); */
NS_IMETHODIMP nsCharsetConverterManager::GetCharsetData(const char * aCharset, const char16_t * aProp, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAtom getCharsetLangGroup (in string aCharset); */
NS_IMETHODIMP nsCharsetConverterManager::GetCharsetLangGroup(const char * aCharset, nsIAtom * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAtom getCharsetLangGroupRaw (in string aCharset); */
NS_IMETHODIMP nsCharsetConverterManager::GetCharsetLangGroupRaw(const char * aCharset, nsIAtom * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICharsetConverterManager_h__ */

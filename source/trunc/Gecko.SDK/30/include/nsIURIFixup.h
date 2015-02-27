/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIURIFixup.idl
 */

#ifndef __gen_nsIURIFixup_h__
#define __gen_nsIURIFixup_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIInputStream; /* forward declaration */


/* starting interface:    nsIURIFixup */
#define NS_IURIFIXUP_IID_STR "731877f8-973b-414c-b772-9ca1f3fffb7e"

#define NS_IURIFIXUP_IID \
  {0x731877f8, 0x973b, 0x414c, \
    { 0xb7, 0x72, 0x9c, 0xa1, 0xf3, 0xff, 0xfb, 0x7e }}

class NS_NO_VTABLE nsIURIFixup : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURIFIXUP_IID)

  enum {
    FIXUP_FLAG_NONE = 0U,
    FIXUP_FLAG_ALLOW_KEYWORD_LOOKUP = 1U,
    FIXUP_FLAGS_MAKE_ALTERNATE_URI = 2U,
    FIXUP_FLAG_FIX_SCHEME_TYPOS = 8U
  };

  /* nsIURI createExposableURI (in nsIURI aURI); */
  NS_IMETHOD CreateExposableURI(nsIURI *aURI, nsIURI * *_retval) = 0;

  /* nsIURI createFixupURI (in AUTF8String aURIText, in unsigned long aFixupFlags, [optional] out nsIInputStream aPostData); */
  NS_IMETHOD CreateFixupURI(const nsACString & aURIText, uint32_t aFixupFlags, nsIInputStream * *aPostData, nsIURI * *_retval) = 0;

  /* nsIURI keywordToURI (in AUTF8String aKeyword, [optional] out nsIInputStream aPostData); */
  NS_IMETHOD KeywordToURI(const nsACString & aKeyword, nsIInputStream * *aPostData, nsIURI * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIURIFixup, NS_IURIFIXUP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURIFIXUP \
  NS_IMETHOD CreateExposableURI(nsIURI *aURI, nsIURI * *_retval); \
  NS_IMETHOD CreateFixupURI(const nsACString & aURIText, uint32_t aFixupFlags, nsIInputStream * *aPostData, nsIURI * *_retval); \
  NS_IMETHOD KeywordToURI(const nsACString & aKeyword, nsIInputStream * *aPostData, nsIURI * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURIFIXUP(_to) \
  NS_IMETHOD CreateExposableURI(nsIURI *aURI, nsIURI * *_retval) { return _to CreateExposableURI(aURI, _retval); } \
  NS_IMETHOD CreateFixupURI(const nsACString & aURIText, uint32_t aFixupFlags, nsIInputStream * *aPostData, nsIURI * *_retval) { return _to CreateFixupURI(aURIText, aFixupFlags, aPostData, _retval); } \
  NS_IMETHOD KeywordToURI(const nsACString & aKeyword, nsIInputStream * *aPostData, nsIURI * *_retval) { return _to KeywordToURI(aKeyword, aPostData, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURIFIXUP(_to) \
  NS_IMETHOD CreateExposableURI(nsIURI *aURI, nsIURI * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateExposableURI(aURI, _retval); } \
  NS_IMETHOD CreateFixupURI(const nsACString & aURIText, uint32_t aFixupFlags, nsIInputStream * *aPostData, nsIURI * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateFixupURI(aURIText, aFixupFlags, aPostData, _retval); } \
  NS_IMETHOD KeywordToURI(const nsACString & aKeyword, nsIInputStream * *aPostData, nsIURI * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->KeywordToURI(aKeyword, aPostData, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsURIFixup : public nsIURIFixup
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURIFIXUP

  nsURIFixup();

private:
  ~nsURIFixup();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsURIFixup, nsIURIFixup)

nsURIFixup::nsURIFixup()
{
  /* member initializers and constructor code */
}

nsURIFixup::~nsURIFixup()
{
  /* destructor code */
}

/* nsIURI createExposableURI (in nsIURI aURI); */
NS_IMETHODIMP nsURIFixup::CreateExposableURI(nsIURI *aURI, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI createFixupURI (in AUTF8String aURIText, in unsigned long aFixupFlags, [optional] out nsIInputStream aPostData); */
NS_IMETHODIMP nsURIFixup::CreateFixupURI(const nsACString & aURIText, uint32_t aFixupFlags, nsIInputStream * *aPostData, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI keywordToURI (in AUTF8String aKeyword, [optional] out nsIInputStream aPostData); */
NS_IMETHODIMP nsURIFixup::KeywordToURI(const nsACString & aKeyword, nsIInputStream * *aPostData, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIURIFixup_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/docshell/base/nsIURIFixup.idl
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


/* starting interface:    nsIURIFixup */
#define NS_IURIFIXUP_IID_STR "773081ac-9f81-4bdb-9e7a-5e87b4361f09"

#define NS_IURIFIXUP_IID \
  {0x773081ac, 0x9f81, 0x4bdb, \
    { 0x9e, 0x7a, 0x5e, 0x87, 0xb4, 0x36, 0x1f, 0x09 }}

class NS_NO_VTABLE nsIURIFixup : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURIFIXUP_IID)

  enum {
    FIXUP_FLAG_NONE = 0U,
    FIXUP_FLAG_ALLOW_KEYWORD_LOOKUP = 1U,
    FIXUP_FLAGS_MAKE_ALTERNATE_URI = 2U,
    FIXUP_FLAG_USE_UTF8 = 4U
  };

  /* nsIURI createExposableURI (in nsIURI aURI); */
  NS_IMETHOD CreateExposableURI(nsIURI *aURI, nsIURI * *_retval) = 0;

  /* nsIURI createFixupURI (in AUTF8String aURIText, in unsigned long aFixupFlags); */
  NS_IMETHOD CreateFixupURI(const nsACString & aURIText, uint32_t aFixupFlags, nsIURI * *_retval) = 0;

  /* nsIURI keywordToURI (in AUTF8String aKeyword); */
  NS_IMETHOD KeywordToURI(const nsACString & aKeyword, nsIURI * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIURIFixup, NS_IURIFIXUP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURIFIXUP \
  NS_IMETHOD CreateExposableURI(nsIURI *aURI, nsIURI * *_retval); \
  NS_IMETHOD CreateFixupURI(const nsACString & aURIText, uint32_t aFixupFlags, nsIURI * *_retval); \
  NS_IMETHOD KeywordToURI(const nsACString & aKeyword, nsIURI * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURIFIXUP(_to) \
  NS_IMETHOD CreateExposableURI(nsIURI *aURI, nsIURI * *_retval) { return _to CreateExposableURI(aURI, _retval); } \
  NS_IMETHOD CreateFixupURI(const nsACString & aURIText, uint32_t aFixupFlags, nsIURI * *_retval) { return _to CreateFixupURI(aURIText, aFixupFlags, _retval); } \
  NS_IMETHOD KeywordToURI(const nsACString & aKeyword, nsIURI * *_retval) { return _to KeywordToURI(aKeyword, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURIFIXUP(_to) \
  NS_IMETHOD CreateExposableURI(nsIURI *aURI, nsIURI * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateExposableURI(aURI, _retval); } \
  NS_IMETHOD CreateFixupURI(const nsACString & aURIText, uint32_t aFixupFlags, nsIURI * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateFixupURI(aURIText, aFixupFlags, _retval); } \
  NS_IMETHOD KeywordToURI(const nsACString & aKeyword, nsIURI * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->KeywordToURI(aKeyword, _retval); } 

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

/* nsIURI createFixupURI (in AUTF8String aURIText, in unsigned long aFixupFlags); */
NS_IMETHODIMP nsURIFixup::CreateFixupURI(const nsACString & aURIText, uint32_t aFixupFlags, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI keywordToURI (in AUTF8String aKeyword); */
NS_IMETHODIMP nsURIFixup::KeywordToURI(const nsACString & aKeyword, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIURIFixup_h__ */

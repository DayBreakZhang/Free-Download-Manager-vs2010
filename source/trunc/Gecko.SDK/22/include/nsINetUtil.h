/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsINetUtil.idl
 */

#ifndef __gen_nsINetUtil_h__
#define __gen_nsINetUtil_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIPrefBranch; /* forward declaration */


/* starting interface:    nsINetUtil */
#define NS_INETUTIL_IID_STR "ca68c485-9db3-4c12-82a6-4fab7948e2d5"

#define NS_INETUTIL_IID \
  {0xca68c485, 0x9db3, 0x4c12, \
    { 0x82, 0xa6, 0x4f, 0xab, 0x79, 0x48, 0xe2, 0xd5 }}

class NS_NO_VTABLE nsINetUtil : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INETUTIL_IID)

  /* AUTF8String parseContentType (in AUTF8String aTypeHeader, out AUTF8String aCharset, out boolean aHadCharset); */
  NS_IMETHOD ParseContentType(const nsACString & aTypeHeader, nsACString & aCharset, bool *aHadCharset, nsACString & _retval) = 0;

  /* boolean protocolHasFlags (in nsIURI aURI, in unsigned long aFlag); */
  NS_IMETHOD ProtocolHasFlags(nsIURI *aURI, uint32_t aFlag, bool *_retval) = 0;

  /* boolean URIChainHasFlags (in nsIURI aURI, in unsigned long aFlags); */
  NS_IMETHOD URIChainHasFlags(nsIURI *aURI, uint32_t aFlags, bool *_retval) = 0;

  /* nsIURI toImmutableURI (in nsIURI aURI); */
  NS_IMETHOD ToImmutableURI(nsIURI *aURI, nsIURI * *_retval) = 0;

  /* nsIURI newSimpleNestedURI (in nsIURI aURI); */
  NS_IMETHOD NewSimpleNestedURI(nsIURI *aURI, nsIURI * *_retval) = 0;

  enum {
    ESCAPE_ALL = 0U,
    ESCAPE_XALPHAS = 1U,
    ESCAPE_XPALPHAS = 2U,
    ESCAPE_URL_PATH = 4U
  };

  /* ACString escapeString (in ACString aString, in unsigned long aEscapeType); */
  NS_IMETHOD EscapeString(const nsACString & aString, uint32_t aEscapeType, nsACString & _retval) = 0;

  enum {
    ESCAPE_URL_SCHEME = 1U,
    ESCAPE_URL_USERNAME = 2U,
    ESCAPE_URL_PASSWORD = 4U,
    ESCAPE_URL_HOST = 8U,
    ESCAPE_URL_DIRECTORY = 16U,
    ESCAPE_URL_FILE_BASENAME = 32U,
    ESCAPE_URL_FILE_EXTENSION = 64U,
    ESCAPE_URL_PARAM = 128U,
    ESCAPE_URL_QUERY = 256U,
    ESCAPE_URL_REF = 512U,
    ESCAPE_URL_FILEPATH = 112U,
    ESCAPE_URL_MINIMAL = 1023U,
    ESCAPE_URL_FORCED = 1024U,
    ESCAPE_URL_ONLY_ASCII = 2048U,
    ESCAPE_URL_ONLY_NONASCII = 4096U,
    ESCAPE_URL_COLON = 16384U,
    ESCAPE_URL_SKIP_CONTROL = 32768U
  };

  /* ACString escapeURL (in ACString aStr, in unsigned long aFlags); */
  NS_IMETHOD EscapeURL(const nsACString & aStr, uint32_t aFlags, nsACString & _retval) = 0;

  /* ACString unescapeString (in AUTF8String aStr, in unsigned long aFlags); */
  NS_IMETHOD UnescapeString(const nsACString & aStr, uint32_t aFlags, nsACString & _retval) = 0;

  /* boolean extractCharsetFromContentType (in AUTF8String aTypeHeader, out AUTF8String aCharset, out long aCharsetStart, out long aCharsetEnd); */
  NS_IMETHOD ExtractCharsetFromContentType(const nsACString & aTypeHeader, nsACString & aCharset, int32_t *aCharsetStart, int32_t *aCharsetEnd, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINetUtil, NS_INETUTIL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINETUTIL \
  NS_IMETHOD ParseContentType(const nsACString & aTypeHeader, nsACString & aCharset, bool *aHadCharset, nsACString & _retval); \
  NS_IMETHOD ProtocolHasFlags(nsIURI *aURI, uint32_t aFlag, bool *_retval); \
  NS_IMETHOD URIChainHasFlags(nsIURI *aURI, uint32_t aFlags, bool *_retval); \
  NS_IMETHOD ToImmutableURI(nsIURI *aURI, nsIURI * *_retval); \
  NS_IMETHOD NewSimpleNestedURI(nsIURI *aURI, nsIURI * *_retval); \
  NS_IMETHOD EscapeString(const nsACString & aString, uint32_t aEscapeType, nsACString & _retval); \
  NS_IMETHOD EscapeURL(const nsACString & aStr, uint32_t aFlags, nsACString & _retval); \
  NS_IMETHOD UnescapeString(const nsACString & aStr, uint32_t aFlags, nsACString & _retval); \
  NS_IMETHOD ExtractCharsetFromContentType(const nsACString & aTypeHeader, nsACString & aCharset, int32_t *aCharsetStart, int32_t *aCharsetEnd, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINETUTIL(_to) \
  NS_IMETHOD ParseContentType(const nsACString & aTypeHeader, nsACString & aCharset, bool *aHadCharset, nsACString & _retval) { return _to ParseContentType(aTypeHeader, aCharset, aHadCharset, _retval); } \
  NS_IMETHOD ProtocolHasFlags(nsIURI *aURI, uint32_t aFlag, bool *_retval) { return _to ProtocolHasFlags(aURI, aFlag, _retval); } \
  NS_IMETHOD URIChainHasFlags(nsIURI *aURI, uint32_t aFlags, bool *_retval) { return _to URIChainHasFlags(aURI, aFlags, _retval); } \
  NS_IMETHOD ToImmutableURI(nsIURI *aURI, nsIURI * *_retval) { return _to ToImmutableURI(aURI, _retval); } \
  NS_IMETHOD NewSimpleNestedURI(nsIURI *aURI, nsIURI * *_retval) { return _to NewSimpleNestedURI(aURI, _retval); } \
  NS_IMETHOD EscapeString(const nsACString & aString, uint32_t aEscapeType, nsACString & _retval) { return _to EscapeString(aString, aEscapeType, _retval); } \
  NS_IMETHOD EscapeURL(const nsACString & aStr, uint32_t aFlags, nsACString & _retval) { return _to EscapeURL(aStr, aFlags, _retval); } \
  NS_IMETHOD UnescapeString(const nsACString & aStr, uint32_t aFlags, nsACString & _retval) { return _to UnescapeString(aStr, aFlags, _retval); } \
  NS_IMETHOD ExtractCharsetFromContentType(const nsACString & aTypeHeader, nsACString & aCharset, int32_t *aCharsetStart, int32_t *aCharsetEnd, bool *_retval) { return _to ExtractCharsetFromContentType(aTypeHeader, aCharset, aCharsetStart, aCharsetEnd, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINETUTIL(_to) \
  NS_IMETHOD ParseContentType(const nsACString & aTypeHeader, nsACString & aCharset, bool *aHadCharset, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseContentType(aTypeHeader, aCharset, aHadCharset, _retval); } \
  NS_IMETHOD ProtocolHasFlags(nsIURI *aURI, uint32_t aFlag, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ProtocolHasFlags(aURI, aFlag, _retval); } \
  NS_IMETHOD URIChainHasFlags(nsIURI *aURI, uint32_t aFlags, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->URIChainHasFlags(aURI, aFlags, _retval); } \
  NS_IMETHOD ToImmutableURI(nsIURI *aURI, nsIURI * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToImmutableURI(aURI, _retval); } \
  NS_IMETHOD NewSimpleNestedURI(nsIURI *aURI, nsIURI * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewSimpleNestedURI(aURI, _retval); } \
  NS_IMETHOD EscapeString(const nsACString & aString, uint32_t aEscapeType, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EscapeString(aString, aEscapeType, _retval); } \
  NS_IMETHOD EscapeURL(const nsACString & aStr, uint32_t aFlags, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EscapeURL(aStr, aFlags, _retval); } \
  NS_IMETHOD UnescapeString(const nsACString & aStr, uint32_t aFlags, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnescapeString(aStr, aFlags, _retval); } \
  NS_IMETHOD ExtractCharsetFromContentType(const nsACString & aTypeHeader, nsACString & aCharset, int32_t *aCharsetStart, int32_t *aCharsetEnd, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExtractCharsetFromContentType(aTypeHeader, aCharset, aCharsetStart, aCharsetEnd, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNetUtil : public nsINetUtil
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINETUTIL

  nsNetUtil();

private:
  ~nsNetUtil();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNetUtil, nsINetUtil)

nsNetUtil::nsNetUtil()
{
  /* member initializers and constructor code */
}

nsNetUtil::~nsNetUtil()
{
  /* destructor code */
}

/* AUTF8String parseContentType (in AUTF8String aTypeHeader, out AUTF8String aCharset, out boolean aHadCharset); */
NS_IMETHODIMP nsNetUtil::ParseContentType(const nsACString & aTypeHeader, nsACString & aCharset, bool *aHadCharset, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean protocolHasFlags (in nsIURI aURI, in unsigned long aFlag); */
NS_IMETHODIMP nsNetUtil::ProtocolHasFlags(nsIURI *aURI, uint32_t aFlag, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean URIChainHasFlags (in nsIURI aURI, in unsigned long aFlags); */
NS_IMETHODIMP nsNetUtil::URIChainHasFlags(nsIURI *aURI, uint32_t aFlags, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI toImmutableURI (in nsIURI aURI); */
NS_IMETHODIMP nsNetUtil::ToImmutableURI(nsIURI *aURI, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI newSimpleNestedURI (in nsIURI aURI); */
NS_IMETHODIMP nsNetUtil::NewSimpleNestedURI(nsIURI *aURI, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString escapeString (in ACString aString, in unsigned long aEscapeType); */
NS_IMETHODIMP nsNetUtil::EscapeString(const nsACString & aString, uint32_t aEscapeType, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString escapeURL (in ACString aStr, in unsigned long aFlags); */
NS_IMETHODIMP nsNetUtil::EscapeURL(const nsACString & aStr, uint32_t aFlags, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString unescapeString (in AUTF8String aStr, in unsigned long aFlags); */
NS_IMETHODIMP nsNetUtil::UnescapeString(const nsACString & aStr, uint32_t aFlags, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean extractCharsetFromContentType (in AUTF8String aTypeHeader, out AUTF8String aCharset, out long aCharsetStart, out long aCharsetEnd); */
NS_IMETHODIMP nsNetUtil::ExtractCharsetFromContentType(const nsACString & aTypeHeader, nsACString & aCharset, int32_t *aCharsetStart, int32_t *aCharsetEnd, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINetUtil_h__ */

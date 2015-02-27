/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMParser.idl
 */

#ifndef __gen_nsIDOMParser_h__
#define __gen_nsIDOMParser_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

class nsIDOMDocument; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIPrincipal; /* forward declaration */

class nsIScriptGlobalObject; /* forward declaration */


/* starting interface:    nsIDOMParser */
#define NS_IDOMPARSER_IID_STR "5677f36e-1842-4c6f-a39c-2e5576ab8b40"

#define NS_IDOMPARSER_IID \
  {0x5677f36e, 0x1842, 0x4c6f, \
    { 0xa3, 0x9c, 0x2e, 0x55, 0x76, 0xab, 0x8b, 0x40 }}

class NS_NO_VTABLE nsIDOMParser : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMPARSER_IID)

  /* nsIDOMDocument parseFromString (in wstring str, in string contentType); */
  NS_IMETHOD ParseFromString(const char16_t * str, const char * contentType, nsIDOMDocument * *_retval) = 0;

  /* nsIDOMDocument parseFromBuffer ([array, size_is (bufLen), const] in octet buf, in uint32_t bufLen, in string contentType); */
  NS_IMETHOD ParseFromBuffer(const uint8_t *buf, uint32_t bufLen, const char * contentType, nsIDOMDocument * *_retval) = 0;

  /* nsIDOMDocument parseFromStream (in nsIInputStream stream, in string charset, in long contentLength, in string contentType); */
  NS_IMETHOD ParseFromStream(nsIInputStream *stream, const char * charset, int32_t contentLength, const char * contentType, nsIDOMDocument * *_retval) = 0;

  /* [noscript] void init (in nsIPrincipal principal, in nsIURI documentURI, in nsIURI baseURI, in nsIScriptGlobalObject scriptObject); */
  NS_IMETHOD Init(nsIPrincipal *principal, nsIURI *documentURI, nsIURI *baseURI, nsIScriptGlobalObject *scriptObject) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMParser, NS_IDOMPARSER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMPARSER \
  NS_IMETHOD ParseFromString(const char16_t * str, const char * contentType, nsIDOMDocument * *_retval); \
  NS_IMETHOD ParseFromBuffer(const uint8_t *buf, uint32_t bufLen, const char * contentType, nsIDOMDocument * *_retval); \
  NS_IMETHOD ParseFromStream(nsIInputStream *stream, const char * charset, int32_t contentLength, const char * contentType, nsIDOMDocument * *_retval); \
  NS_IMETHOD Init(nsIPrincipal *principal, nsIURI *documentURI, nsIURI *baseURI, nsIScriptGlobalObject *scriptObject); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMPARSER(_to) \
  NS_IMETHOD ParseFromString(const char16_t * str, const char * contentType, nsIDOMDocument * *_retval) { return _to ParseFromString(str, contentType, _retval); } \
  NS_IMETHOD ParseFromBuffer(const uint8_t *buf, uint32_t bufLen, const char * contentType, nsIDOMDocument * *_retval) { return _to ParseFromBuffer(buf, bufLen, contentType, _retval); } \
  NS_IMETHOD ParseFromStream(nsIInputStream *stream, const char * charset, int32_t contentLength, const char * contentType, nsIDOMDocument * *_retval) { return _to ParseFromStream(stream, charset, contentLength, contentType, _retval); } \
  NS_IMETHOD Init(nsIPrincipal *principal, nsIURI *documentURI, nsIURI *baseURI, nsIScriptGlobalObject *scriptObject) { return _to Init(principal, documentURI, baseURI, scriptObject); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMPARSER(_to) \
  NS_IMETHOD ParseFromString(const char16_t * str, const char * contentType, nsIDOMDocument * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseFromString(str, contentType, _retval); } \
  NS_IMETHOD ParseFromBuffer(const uint8_t *buf, uint32_t bufLen, const char * contentType, nsIDOMDocument * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseFromBuffer(buf, bufLen, contentType, _retval); } \
  NS_IMETHOD ParseFromStream(nsIInputStream *stream, const char * charset, int32_t contentLength, const char * contentType, nsIDOMDocument * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseFromStream(stream, charset, contentLength, contentType, _retval); } \
  NS_IMETHOD Init(nsIPrincipal *principal, nsIURI *documentURI, nsIURI *baseURI, nsIScriptGlobalObject *scriptObject) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(principal, documentURI, baseURI, scriptObject); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMParser : public nsIDOMParser
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMPARSER

  nsDOMParser();

private:
  ~nsDOMParser();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMParser, nsIDOMParser)

nsDOMParser::nsDOMParser()
{
  /* member initializers and constructor code */
}

nsDOMParser::~nsDOMParser()
{
  /* destructor code */
}

/* nsIDOMDocument parseFromString (in wstring str, in string contentType); */
NS_IMETHODIMP nsDOMParser::ParseFromString(const char16_t * str, const char * contentType, nsIDOMDocument * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocument parseFromBuffer ([array, size_is (bufLen), const] in octet buf, in uint32_t bufLen, in string contentType); */
NS_IMETHODIMP nsDOMParser::ParseFromBuffer(const uint8_t *buf, uint32_t bufLen, const char * contentType, nsIDOMDocument * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocument parseFromStream (in nsIInputStream stream, in string charset, in long contentLength, in string contentType); */
NS_IMETHODIMP nsDOMParser::ParseFromStream(nsIInputStream *stream, const char * charset, int32_t contentLength, const char * contentType, nsIDOMDocument * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void init (in nsIPrincipal principal, in nsIURI documentURI, in nsIURI baseURI, in nsIScriptGlobalObject scriptObject); */
NS_IMETHODIMP nsDOMParser::Init(nsIPrincipal *principal, nsIURI *documentURI, nsIURI *baseURI, nsIScriptGlobalObject *scriptObject)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_DOMPARSER_CID                            \
 { /* 3a8a3a50-512c-11d4-9a54-000064657374 */       \
   0x3a8a3a50, 0x512c, 0x11d4,                      \
  {0x9a, 0x54, 0x00, 0x00, 0x64, 0x65, 0x73, 0x74} }
#define NS_DOMPARSER_CONTRACTID \
"@mozilla.org/xmlextras/domparser;1"

#endif /* __gen_nsIDOMParser_h__ */

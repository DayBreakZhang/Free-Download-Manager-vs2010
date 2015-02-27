/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/json/nsIJSON.idl
 */

#ifndef __gen_nsIJSON_h__
#define __gen_nsIJSON_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

class nsIOutputStream; /* forward declaration */

class nsIScriptGlobalObject; /* forward declaration */

#include "jspubtd.h"

/* starting interface:    nsIJSON */
#define NS_IJSON_IID_STR "a4d68b4e-0c0b-4c7c-b540-ef2f9834171f"

#define NS_IJSON_IID \
  {0xa4d68b4e, 0x0c0b, 0x4c7c, \
    { 0xb5, 0x40, 0xef, 0x2f, 0x98, 0x34, 0x17, 0x1f }}

/**
 * Encode and decode JSON text.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIJSON : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJSON_IID)

  /* AString encode (); */
  NS_SCRIPTABLE NS_IMETHOD Encode(nsAString & _retval NS_OUTPARAM) = 0;

  /* void encodeToStream (in nsIOutputStream stream, in string charset, in boolean writeBOM); */
  NS_SCRIPTABLE NS_IMETHOD EncodeToStream(nsIOutputStream *stream, const char *charset, PRBool writeBOM) = 0;

  /* void decode (in AString str); */
  NS_SCRIPTABLE NS_IMETHOD Decode(const nsAString & str) = 0;

  /* void decodeFromStream (in nsIInputStream stream, in long contentLength); */
  NS_SCRIPTABLE NS_IMETHOD DecodeFromStream(nsIInputStream *stream, PRInt32 contentLength) = 0;

  /* [noscript] AString encodeFromJSVal (in JSValPtr value, in JSContext cx); */
  NS_IMETHOD EncodeFromJSVal(jsval *value, JSContext *cx, nsAString & _retval NS_OUTPARAM) = 0;

  /* [noscript] jsval decodeToJSVal (in AString str, in JSContext cx); */
  NS_IMETHOD DecodeToJSVal(const nsAString & str, JSContext *cx, jsval *_retval NS_OUTPARAM) = 0;

  /* void legacyDecode (in AString str); */
  NS_SCRIPTABLE NS_IMETHOD LegacyDecode(const nsAString & str) = 0;

  /* void legacyDecodeFromStream (in nsIInputStream stream, in long contentLength); */
  NS_SCRIPTABLE NS_IMETHOD LegacyDecodeFromStream(nsIInputStream *stream, PRInt32 contentLength) = 0;

  /* [noscript] jsval legacyDecodeToJSVal (in AString str, in JSContext cx); */
  NS_IMETHOD LegacyDecodeToJSVal(const nsAString & str, JSContext *cx, jsval *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJSON, NS_IJSON_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJSON \
  NS_SCRIPTABLE NS_IMETHOD Encode(nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD EncodeToStream(nsIOutputStream *stream, const char *charset, PRBool writeBOM); \
  NS_SCRIPTABLE NS_IMETHOD Decode(const nsAString & str); \
  NS_SCRIPTABLE NS_IMETHOD DecodeFromStream(nsIInputStream *stream, PRInt32 contentLength); \
  NS_IMETHOD EncodeFromJSVal(jsval *value, JSContext *cx, nsAString & _retval NS_OUTPARAM); \
  NS_IMETHOD DecodeToJSVal(const nsAString & str, JSContext *cx, jsval *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD LegacyDecode(const nsAString & str); \
  NS_SCRIPTABLE NS_IMETHOD LegacyDecodeFromStream(nsIInputStream *stream, PRInt32 contentLength); \
  NS_IMETHOD LegacyDecodeToJSVal(const nsAString & str, JSContext *cx, jsval *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJSON(_to) \
  NS_SCRIPTABLE NS_IMETHOD Encode(nsAString & _retval NS_OUTPARAM) { return _to Encode(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD EncodeToStream(nsIOutputStream *stream, const char *charset, PRBool writeBOM) { return _to EncodeToStream(stream, charset, writeBOM); } \
  NS_SCRIPTABLE NS_IMETHOD Decode(const nsAString & str) { return _to Decode(str); } \
  NS_SCRIPTABLE NS_IMETHOD DecodeFromStream(nsIInputStream *stream, PRInt32 contentLength) { return _to DecodeFromStream(stream, contentLength); } \
  NS_IMETHOD EncodeFromJSVal(jsval *value, JSContext *cx, nsAString & _retval NS_OUTPARAM) { return _to EncodeFromJSVal(value, cx, _retval); } \
  NS_IMETHOD DecodeToJSVal(const nsAString & str, JSContext *cx, jsval *_retval NS_OUTPARAM) { return _to DecodeToJSVal(str, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LegacyDecode(const nsAString & str) { return _to LegacyDecode(str); } \
  NS_SCRIPTABLE NS_IMETHOD LegacyDecodeFromStream(nsIInputStream *stream, PRInt32 contentLength) { return _to LegacyDecodeFromStream(stream, contentLength); } \
  NS_IMETHOD LegacyDecodeToJSVal(const nsAString & str, JSContext *cx, jsval *_retval NS_OUTPARAM) { return _to LegacyDecodeToJSVal(str, cx, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJSON(_to) \
  NS_SCRIPTABLE NS_IMETHOD Encode(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Encode(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD EncodeToStream(nsIOutputStream *stream, const char *charset, PRBool writeBOM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EncodeToStream(stream, charset, writeBOM); } \
  NS_SCRIPTABLE NS_IMETHOD Decode(const nsAString & str) { return !_to ? NS_ERROR_NULL_POINTER : _to->Decode(str); } \
  NS_SCRIPTABLE NS_IMETHOD DecodeFromStream(nsIInputStream *stream, PRInt32 contentLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->DecodeFromStream(stream, contentLength); } \
  NS_IMETHOD EncodeFromJSVal(jsval *value, JSContext *cx, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EncodeFromJSVal(value, cx, _retval); } \
  NS_IMETHOD DecodeToJSVal(const nsAString & str, JSContext *cx, jsval *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->DecodeToJSVal(str, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LegacyDecode(const nsAString & str) { return !_to ? NS_ERROR_NULL_POINTER : _to->LegacyDecode(str); } \
  NS_SCRIPTABLE NS_IMETHOD LegacyDecodeFromStream(nsIInputStream *stream, PRInt32 contentLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->LegacyDecodeFromStream(stream, contentLength); } \
  NS_IMETHOD LegacyDecodeToJSVal(const nsAString & str, JSContext *cx, jsval *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->LegacyDecodeToJSVal(str, cx, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJSON : public nsIJSON
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJSON

  nsJSON();

private:
  ~nsJSON();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJSON, nsIJSON)

nsJSON::nsJSON()
{
  /* member initializers and constructor code */
}

nsJSON::~nsJSON()
{
  /* destructor code */
}

/* AString encode (); */
NS_IMETHODIMP nsJSON::Encode(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void encodeToStream (in nsIOutputStream stream, in string charset, in boolean writeBOM); */
NS_IMETHODIMP nsJSON::EncodeToStream(nsIOutputStream *stream, const char *charset, PRBool writeBOM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void decode (in AString str); */
NS_IMETHODIMP nsJSON::Decode(const nsAString & str)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void decodeFromStream (in nsIInputStream stream, in long contentLength); */
NS_IMETHODIMP nsJSON::DecodeFromStream(nsIInputStream *stream, PRInt32 contentLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] AString encodeFromJSVal (in JSValPtr value, in JSContext cx); */
NS_IMETHODIMP nsJSON::EncodeFromJSVal(jsval *value, JSContext *cx, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] jsval decodeToJSVal (in AString str, in JSContext cx); */
NS_IMETHODIMP nsJSON::DecodeToJSVal(const nsAString & str, JSContext *cx, jsval *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void legacyDecode (in AString str); */
NS_IMETHODIMP nsJSON::LegacyDecode(const nsAString & str)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void legacyDecodeFromStream (in nsIInputStream stream, in long contentLength); */
NS_IMETHODIMP nsJSON::LegacyDecodeFromStream(nsIInputStream *stream, PRInt32 contentLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] jsval legacyDecodeToJSVal (in AString str, in JSContext cx); */
NS_IMETHODIMP nsJSON::LegacyDecodeToJSVal(const nsAString & str, JSContext *cx, jsval *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJSON_h__ */

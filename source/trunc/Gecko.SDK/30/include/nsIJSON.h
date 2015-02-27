/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIJSON.idl
 */

#ifndef __gen_nsIJSON_h__
#define __gen_nsIJSON_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

class nsIOutputStream; /* forward declaration */

class nsIScriptGlobalObject; /* forward declaration */

#include "js/TypeDecls.h"

/* starting interface:    nsIJSON */
#define NS_IJSON_IID_STR "083aebb0-7790-43b2-ae81-9e404e626236"

#define NS_IJSON_IID \
  {0x083aebb0, 0x7790, 0x43b2, \
    { 0xae, 0x81, 0x9e, 0x40, 0x4e, 0x62, 0x62, 0x36 }}

class NS_NO_VTABLE nsIJSON : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJSON_IID)

  /* [deprecated,implicit_jscontext,optional_argc] AString encode ([optional] in jsval value); */
  NS_IMETHOD Encode(JS::HandleValue value, JSContext* cx, uint8_t _argc, nsAString & _retval) = 0;

  /* [deprecated,implicit_jscontext,optional_argc] void encodeToStream (in nsIOutputStream stream, in string charset, in boolean writeBOM, [optional] in jsval value); */
  NS_IMETHOD EncodeToStream(nsIOutputStream *stream, const char * charset, bool writeBOM, JS::HandleValue value, JSContext* cx, uint8_t _argc) = 0;

  /* [deprecated,implicit_jscontext] jsval decode (in AString str); */
  NS_IMETHOD Decode(const nsAString & str, JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* [implicit_jscontext] jsval decodeFromStream (in nsIInputStream stream, in long contentLength); */
  NS_IMETHOD DecodeFromStream(nsIInputStream *stream, int32_t contentLength, JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* [noscript] AString encodeFromJSVal (in JSValPtr value, in JSContext cx); */
  NS_IMETHOD EncodeFromJSVal(JS::Value *value, JSContext *cx, nsAString & _retval) = 0;

  /* [noscript] jsval decodeToJSVal (in AString str, in JSContext cx); */
  NS_IMETHOD DecodeToJSVal(const nsAString & str, JSContext *cx, JS::MutableHandleValue _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJSON, NS_IJSON_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJSON \
  NS_IMETHOD Encode(JS::HandleValue value, JSContext* cx, uint8_t _argc, nsAString & _retval); \
  NS_IMETHOD EncodeToStream(nsIOutputStream *stream, const char * charset, bool writeBOM, JS::HandleValue value, JSContext* cx, uint8_t _argc); \
  NS_IMETHOD Decode(const nsAString & str, JSContext* cx, JS::MutableHandleValue _retval); \
  NS_IMETHOD DecodeFromStream(nsIInputStream *stream, int32_t contentLength, JSContext* cx, JS::MutableHandleValue _retval); \
  NS_IMETHOD EncodeFromJSVal(JS::Value *value, JSContext *cx, nsAString & _retval); \
  NS_IMETHOD DecodeToJSVal(const nsAString & str, JSContext *cx, JS::MutableHandleValue _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJSON(_to) \
  NS_IMETHOD Encode(JS::HandleValue value, JSContext* cx, uint8_t _argc, nsAString & _retval) { return _to Encode(value, cx, _argc, _retval); } \
  NS_IMETHOD EncodeToStream(nsIOutputStream *stream, const char * charset, bool writeBOM, JS::HandleValue value, JSContext* cx, uint8_t _argc) { return _to EncodeToStream(stream, charset, writeBOM, value, cx, _argc); } \
  NS_IMETHOD Decode(const nsAString & str, JSContext* cx, JS::MutableHandleValue _retval) { return _to Decode(str, cx, _retval); } \
  NS_IMETHOD DecodeFromStream(nsIInputStream *stream, int32_t contentLength, JSContext* cx, JS::MutableHandleValue _retval) { return _to DecodeFromStream(stream, contentLength, cx, _retval); } \
  NS_IMETHOD EncodeFromJSVal(JS::Value *value, JSContext *cx, nsAString & _retval) { return _to EncodeFromJSVal(value, cx, _retval); } \
  NS_IMETHOD DecodeToJSVal(const nsAString & str, JSContext *cx, JS::MutableHandleValue _retval) { return _to DecodeToJSVal(str, cx, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJSON(_to) \
  NS_IMETHOD Encode(JS::HandleValue value, JSContext* cx, uint8_t _argc, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Encode(value, cx, _argc, _retval); } \
  NS_IMETHOD EncodeToStream(nsIOutputStream *stream, const char * charset, bool writeBOM, JS::HandleValue value, JSContext* cx, uint8_t _argc) { return !_to ? NS_ERROR_NULL_POINTER : _to->EncodeToStream(stream, charset, writeBOM, value, cx, _argc); } \
  NS_IMETHOD Decode(const nsAString & str, JSContext* cx, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Decode(str, cx, _retval); } \
  NS_IMETHOD DecodeFromStream(nsIInputStream *stream, int32_t contentLength, JSContext* cx, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->DecodeFromStream(stream, contentLength, cx, _retval); } \
  NS_IMETHOD EncodeFromJSVal(JS::Value *value, JSContext *cx, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EncodeFromJSVal(value, cx, _retval); } \
  NS_IMETHOD DecodeToJSVal(const nsAString & str, JSContext *cx, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->DecodeToJSVal(str, cx, _retval); } 

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

/* [deprecated,implicit_jscontext,optional_argc] AString encode ([optional] in jsval value); */
NS_IMETHODIMP nsJSON::Encode(JS::HandleValue value, JSContext* cx, uint8_t _argc, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [deprecated,implicit_jscontext,optional_argc] void encodeToStream (in nsIOutputStream stream, in string charset, in boolean writeBOM, [optional] in jsval value); */
NS_IMETHODIMP nsJSON::EncodeToStream(nsIOutputStream *stream, const char * charset, bool writeBOM, JS::HandleValue value, JSContext* cx, uint8_t _argc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [deprecated,implicit_jscontext] jsval decode (in AString str); */
NS_IMETHODIMP nsJSON::Decode(const nsAString & str, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval decodeFromStream (in nsIInputStream stream, in long contentLength); */
NS_IMETHODIMP nsJSON::DecodeFromStream(nsIInputStream *stream, int32_t contentLength, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] AString encodeFromJSVal (in JSValPtr value, in JSContext cx); */
NS_IMETHODIMP nsJSON::EncodeFromJSVal(JS::Value *value, JSContext *cx, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] jsval decodeToJSVal (in AString str, in JSContext cx); */
NS_IMETHODIMP nsJSON::DecodeToJSVal(const nsAString & str, JSContext *cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJSON_h__ */

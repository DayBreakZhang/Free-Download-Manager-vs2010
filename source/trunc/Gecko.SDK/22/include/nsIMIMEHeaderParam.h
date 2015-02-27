/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/mime/nsIMIMEHeaderParam.idl
 */

#ifndef __gen_nsIMIMEHeaderParam_h__
#define __gen_nsIMIMEHeaderParam_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMIMEHeaderParam */
#define NS_IMIMEHEADERPARAM_IID_STR "9c9252a1-fdaf-40a2-9c2b-a3dc45e28dde"

#define NS_IMIMEHEADERPARAM_IID \
  {0x9c9252a1, 0xfdaf, 0x40a2, \
    { 0x9c, 0x2b, 0xa3, 0xdc, 0x45, 0xe2, 0x8d, 0xde }}

class NS_NO_VTABLE nsIMIMEHeaderParam : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMIMEHEADERPARAM_IID)

  /* AString getParameter (in ACString aHeaderVal, in string aParamName, in ACString aFallbackCharset, in boolean aTryLocaleCharset, out string aLang); */
  NS_IMETHOD GetParameter(const nsACString & aHeaderVal, const char * aParamName, const nsACString & aFallbackCharset, bool aTryLocaleCharset, char * *aLang, nsAString & _retval) = 0;

  /* AString getParameterHTTP (in ACString aHeaderVal, in string aParamName, in ACString aFallbackCharset, in boolean aTryLocaleCharset, out string aLang); */
  NS_IMETHOD GetParameterHTTP(const nsACString & aHeaderVal, const char * aParamName, const nsACString & aFallbackCharset, bool aTryLocaleCharset, char * *aLang, nsAString & _retval) = 0;

  /* AString decodeRFC5987Param (in ACString aParamVal, out ACString aLang); */
  NS_IMETHOD DecodeRFC5987Param(const nsACString & aParamVal, nsACString & aLang, nsAString & _retval) = 0;

  /* [noscript] string getParameterInternal (in string aHeaderVal, in string aParamName, out string aCharset, out string aLang); */
  NS_IMETHOD GetParameterInternal(const char * aHeaderVal, const char * aParamName, char * *aCharset, char * *aLang, char * *_retval) = 0;

  /* [noscript] ACString decodeRFC2047Header (in string aHeaderVal, in string aDefaultCharset, in boolean aOverrideCharset, in boolean aEatContinuation); */
  NS_IMETHOD DecodeRFC2047Header(const char * aHeaderVal, const char * aDefaultCharset, bool aOverrideCharset, bool aEatContinuation, nsACString & _retval) = 0;

  /* [noscript] ACString decodeParameter (in ACString aParamValue, in string aCharset, in string aDefaultCharset, in boolean aOverrideCharset); */
  NS_IMETHOD DecodeParameter(const nsACString & aParamValue, const char * aCharset, const char * aDefaultCharset, bool aOverrideCharset, nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMIMEHeaderParam, NS_IMIMEHEADERPARAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMIMEHEADERPARAM \
  NS_IMETHOD GetParameter(const nsACString & aHeaderVal, const char * aParamName, const nsACString & aFallbackCharset, bool aTryLocaleCharset, char * *aLang, nsAString & _retval); \
  NS_IMETHOD GetParameterHTTP(const nsACString & aHeaderVal, const char * aParamName, const nsACString & aFallbackCharset, bool aTryLocaleCharset, char * *aLang, nsAString & _retval); \
  NS_IMETHOD DecodeRFC5987Param(const nsACString & aParamVal, nsACString & aLang, nsAString & _retval); \
  NS_IMETHOD GetParameterInternal(const char * aHeaderVal, const char * aParamName, char * *aCharset, char * *aLang, char * *_retval); \
  NS_IMETHOD DecodeRFC2047Header(const char * aHeaderVal, const char * aDefaultCharset, bool aOverrideCharset, bool aEatContinuation, nsACString & _retval); \
  NS_IMETHOD DecodeParameter(const nsACString & aParamValue, const char * aCharset, const char * aDefaultCharset, bool aOverrideCharset, nsACString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMIMEHEADERPARAM(_to) \
  NS_IMETHOD GetParameter(const nsACString & aHeaderVal, const char * aParamName, const nsACString & aFallbackCharset, bool aTryLocaleCharset, char * *aLang, nsAString & _retval) { return _to GetParameter(aHeaderVal, aParamName, aFallbackCharset, aTryLocaleCharset, aLang, _retval); } \
  NS_IMETHOD GetParameterHTTP(const nsACString & aHeaderVal, const char * aParamName, const nsACString & aFallbackCharset, bool aTryLocaleCharset, char * *aLang, nsAString & _retval) { return _to GetParameterHTTP(aHeaderVal, aParamName, aFallbackCharset, aTryLocaleCharset, aLang, _retval); } \
  NS_IMETHOD DecodeRFC5987Param(const nsACString & aParamVal, nsACString & aLang, nsAString & _retval) { return _to DecodeRFC5987Param(aParamVal, aLang, _retval); } \
  NS_IMETHOD GetParameterInternal(const char * aHeaderVal, const char * aParamName, char * *aCharset, char * *aLang, char * *_retval) { return _to GetParameterInternal(aHeaderVal, aParamName, aCharset, aLang, _retval); } \
  NS_IMETHOD DecodeRFC2047Header(const char * aHeaderVal, const char * aDefaultCharset, bool aOverrideCharset, bool aEatContinuation, nsACString & _retval) { return _to DecodeRFC2047Header(aHeaderVal, aDefaultCharset, aOverrideCharset, aEatContinuation, _retval); } \
  NS_IMETHOD DecodeParameter(const nsACString & aParamValue, const char * aCharset, const char * aDefaultCharset, bool aOverrideCharset, nsACString & _retval) { return _to DecodeParameter(aParamValue, aCharset, aDefaultCharset, aOverrideCharset, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMIMEHEADERPARAM(_to) \
  NS_IMETHOD GetParameter(const nsACString & aHeaderVal, const char * aParamName, const nsACString & aFallbackCharset, bool aTryLocaleCharset, char * *aLang, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParameter(aHeaderVal, aParamName, aFallbackCharset, aTryLocaleCharset, aLang, _retval); } \
  NS_IMETHOD GetParameterHTTP(const nsACString & aHeaderVal, const char * aParamName, const nsACString & aFallbackCharset, bool aTryLocaleCharset, char * *aLang, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParameterHTTP(aHeaderVal, aParamName, aFallbackCharset, aTryLocaleCharset, aLang, _retval); } \
  NS_IMETHOD DecodeRFC5987Param(const nsACString & aParamVal, nsACString & aLang, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->DecodeRFC5987Param(aParamVal, aLang, _retval); } \
  NS_IMETHOD GetParameterInternal(const char * aHeaderVal, const char * aParamName, char * *aCharset, char * *aLang, char * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParameterInternal(aHeaderVal, aParamName, aCharset, aLang, _retval); } \
  NS_IMETHOD DecodeRFC2047Header(const char * aHeaderVal, const char * aDefaultCharset, bool aOverrideCharset, bool aEatContinuation, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->DecodeRFC2047Header(aHeaderVal, aDefaultCharset, aOverrideCharset, aEatContinuation, _retval); } \
  NS_IMETHOD DecodeParameter(const nsACString & aParamValue, const char * aCharset, const char * aDefaultCharset, bool aOverrideCharset, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->DecodeParameter(aParamValue, aCharset, aDefaultCharset, aOverrideCharset, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMIMEHeaderParam : public nsIMIMEHeaderParam
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMIMEHEADERPARAM

  nsMIMEHeaderParam();

private:
  ~nsMIMEHeaderParam();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMIMEHeaderParam, nsIMIMEHeaderParam)

nsMIMEHeaderParam::nsMIMEHeaderParam()
{
  /* member initializers and constructor code */
}

nsMIMEHeaderParam::~nsMIMEHeaderParam()
{
  /* destructor code */
}

/* AString getParameter (in ACString aHeaderVal, in string aParamName, in ACString aFallbackCharset, in boolean aTryLocaleCharset, out string aLang); */
NS_IMETHODIMP nsMIMEHeaderParam::GetParameter(const nsACString & aHeaderVal, const char * aParamName, const nsACString & aFallbackCharset, bool aTryLocaleCharset, char * *aLang, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getParameterHTTP (in ACString aHeaderVal, in string aParamName, in ACString aFallbackCharset, in boolean aTryLocaleCharset, out string aLang); */
NS_IMETHODIMP nsMIMEHeaderParam::GetParameterHTTP(const nsACString & aHeaderVal, const char * aParamName, const nsACString & aFallbackCharset, bool aTryLocaleCharset, char * *aLang, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString decodeRFC5987Param (in ACString aParamVal, out ACString aLang); */
NS_IMETHODIMP nsMIMEHeaderParam::DecodeRFC5987Param(const nsACString & aParamVal, nsACString & aLang, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] string getParameterInternal (in string aHeaderVal, in string aParamName, out string aCharset, out string aLang); */
NS_IMETHODIMP nsMIMEHeaderParam::GetParameterInternal(const char * aHeaderVal, const char * aParamName, char * *aCharset, char * *aLang, char * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] ACString decodeRFC2047Header (in string aHeaderVal, in string aDefaultCharset, in boolean aOverrideCharset, in boolean aEatContinuation); */
NS_IMETHODIMP nsMIMEHeaderParam::DecodeRFC2047Header(const char * aHeaderVal, const char * aDefaultCharset, bool aOverrideCharset, bool aEatContinuation, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] ACString decodeParameter (in ACString aParamValue, in string aCharset, in string aDefaultCharset, in boolean aOverrideCharset); */
NS_IMETHODIMP nsMIMEHeaderParam::DecodeParameter(const nsACString & aParamValue, const char * aCharset, const char * aDefaultCharset, bool aOverrideCharset, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMIMEHeaderParam_h__ */

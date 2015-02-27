/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/storage/public/mozIStorageBaseStatement.idl
 */

#ifndef __gen_mozIStorageBaseStatement_h__
#define __gen_mozIStorageBaseStatement_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_mozIStorageBindingParams_h__
#include "mozIStorageBindingParams.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class mozIStorageConnection; /* forward declaration */

class mozIStorageStatementCallback; /* forward declaration */

class mozIStoragePendingStatement; /* forward declaration */

class mozIStorageBindingParams; /* forward declaration */

class mozIStorageBindingParamsArray; /* forward declaration */


/* starting interface:    mozIStorageBaseStatement */
#define MOZISTORAGEBASESTATEMENT_IID_STR "da2ec336-fbbb-4ba1-9778-8c9825980d01"

#define MOZISTORAGEBASESTATEMENT_IID \
  {0xda2ec336, 0xfbbb, 0x4ba1, \
    { 0x97, 0x78, 0x8c, 0x98, 0x25, 0x98, 0x0d, 0x01 }}

class NS_NO_VTABLE mozIStorageBaseStatement : public mozIStorageBindingParams {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGEBASESTATEMENT_IID)

  /* void finalize (); */
  NS_IMETHOD Finalize(void) = 0;

  /* [deprecated] void bindUTF8StringParameter (in unsigned long aParamIndex, in AUTF8String aValue); */
  NS_IMETHOD BindUTF8StringParameter(uint32_t aParamIndex, const nsACString & aValue) = 0;

  /* [deprecated] void bindStringParameter (in unsigned long aParamIndex, in AString aValue); */
  NS_IMETHOD BindStringParameter(uint32_t aParamIndex, const nsAString & aValue) = 0;

  /* [deprecated] void bindDoubleParameter (in unsigned long aParamIndex, in double aValue); */
  NS_IMETHOD BindDoubleParameter(uint32_t aParamIndex, double aValue) = 0;

  /* [deprecated] void bindInt32Parameter (in unsigned long aParamIndex, in long aValue); */
  NS_IMETHOD BindInt32Parameter(uint32_t aParamIndex, int32_t aValue) = 0;

  /* [deprecated] void bindInt64Parameter (in unsigned long aParamIndex, in long long aValue); */
  NS_IMETHOD BindInt64Parameter(uint32_t aParamIndex, int64_t aValue) = 0;

  /* [deprecated] void bindNullParameter (in unsigned long aParamIndex); */
  NS_IMETHOD BindNullParameter(uint32_t aParamIndex) = 0;

  /* [deprecated] void bindBlobParameter (in unsigned long aParamIndex, [array, size_is (aValueSize), const] in octet aValue, in unsigned long aValueSize); */
  NS_IMETHOD BindBlobParameter(uint32_t aParamIndex, const uint8_t *aValue, uint32_t aValueSize) = 0;

  /* void bindParameters (in mozIStorageBindingParamsArray aParameters); */
  NS_IMETHOD BindParameters(mozIStorageBindingParamsArray *aParameters) = 0;

  /* mozIStorageBindingParamsArray newBindingParamsArray (); */
  NS_IMETHOD NewBindingParamsArray(mozIStorageBindingParamsArray * *_retval) = 0;

  /* mozIStoragePendingStatement executeAsync ([optional] in mozIStorageStatementCallback aCallback); */
  NS_IMETHOD ExecuteAsync(mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval) = 0;

  enum {
    MOZ_STORAGE_STATEMENT_INVALID = 0,
    MOZ_STORAGE_STATEMENT_READY = 1,
    MOZ_STORAGE_STATEMENT_EXECUTING = 2
  };

  /* readonly attribute long state; */
  NS_IMETHOD GetState(int32_t *aState) = 0;

  /* AString escapeStringForLIKE (in AString aValue, in wchar aEscapeChar); */
  NS_IMETHOD EscapeStringForLIKE(const nsAString & aValue, PRUnichar aEscapeChar, nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageBaseStatement, MOZISTORAGEBASESTATEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGEBASESTATEMENT \
  NS_IMETHOD Finalize(void); \
  NS_IMETHOD BindUTF8StringParameter(uint32_t aParamIndex, const nsACString & aValue); \
  NS_IMETHOD BindStringParameter(uint32_t aParamIndex, const nsAString & aValue); \
  NS_IMETHOD BindDoubleParameter(uint32_t aParamIndex, double aValue); \
  NS_IMETHOD BindInt32Parameter(uint32_t aParamIndex, int32_t aValue); \
  NS_IMETHOD BindInt64Parameter(uint32_t aParamIndex, int64_t aValue); \
  NS_IMETHOD BindNullParameter(uint32_t aParamIndex); \
  NS_IMETHOD BindBlobParameter(uint32_t aParamIndex, const uint8_t *aValue, uint32_t aValueSize); \
  NS_IMETHOD BindParameters(mozIStorageBindingParamsArray *aParameters); \
  NS_IMETHOD NewBindingParamsArray(mozIStorageBindingParamsArray * *_retval); \
  NS_IMETHOD ExecuteAsync(mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval); \
  NS_IMETHOD GetState(int32_t *aState); \
  NS_IMETHOD EscapeStringForLIKE(const nsAString & aValue, PRUnichar aEscapeChar, nsAString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGEBASESTATEMENT(_to) \
  NS_IMETHOD Finalize(void) { return _to Finalize(); } \
  NS_IMETHOD BindUTF8StringParameter(uint32_t aParamIndex, const nsACString & aValue) { return _to BindUTF8StringParameter(aParamIndex, aValue); } \
  NS_IMETHOD BindStringParameter(uint32_t aParamIndex, const nsAString & aValue) { return _to BindStringParameter(aParamIndex, aValue); } \
  NS_IMETHOD BindDoubleParameter(uint32_t aParamIndex, double aValue) { return _to BindDoubleParameter(aParamIndex, aValue); } \
  NS_IMETHOD BindInt32Parameter(uint32_t aParamIndex, int32_t aValue) { return _to BindInt32Parameter(aParamIndex, aValue); } \
  NS_IMETHOD BindInt64Parameter(uint32_t aParamIndex, int64_t aValue) { return _to BindInt64Parameter(aParamIndex, aValue); } \
  NS_IMETHOD BindNullParameter(uint32_t aParamIndex) { return _to BindNullParameter(aParamIndex); } \
  NS_IMETHOD BindBlobParameter(uint32_t aParamIndex, const uint8_t *aValue, uint32_t aValueSize) { return _to BindBlobParameter(aParamIndex, aValue, aValueSize); } \
  NS_IMETHOD BindParameters(mozIStorageBindingParamsArray *aParameters) { return _to BindParameters(aParameters); } \
  NS_IMETHOD NewBindingParamsArray(mozIStorageBindingParamsArray * *_retval) { return _to NewBindingParamsArray(_retval); } \
  NS_IMETHOD ExecuteAsync(mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval) { return _to ExecuteAsync(aCallback, _retval); } \
  NS_IMETHOD GetState(int32_t *aState) { return _to GetState(aState); } \
  NS_IMETHOD EscapeStringForLIKE(const nsAString & aValue, PRUnichar aEscapeChar, nsAString & _retval) { return _to EscapeStringForLIKE(aValue, aEscapeChar, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGEBASESTATEMENT(_to) \
  NS_IMETHOD Finalize(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Finalize(); } \
  NS_IMETHOD BindUTF8StringParameter(uint32_t aParamIndex, const nsACString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindUTF8StringParameter(aParamIndex, aValue); } \
  NS_IMETHOD BindStringParameter(uint32_t aParamIndex, const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindStringParameter(aParamIndex, aValue); } \
  NS_IMETHOD BindDoubleParameter(uint32_t aParamIndex, double aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindDoubleParameter(aParamIndex, aValue); } \
  NS_IMETHOD BindInt32Parameter(uint32_t aParamIndex, int32_t aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindInt32Parameter(aParamIndex, aValue); } \
  NS_IMETHOD BindInt64Parameter(uint32_t aParamIndex, int64_t aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindInt64Parameter(aParamIndex, aValue); } \
  NS_IMETHOD BindNullParameter(uint32_t aParamIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindNullParameter(aParamIndex); } \
  NS_IMETHOD BindBlobParameter(uint32_t aParamIndex, const uint8_t *aValue, uint32_t aValueSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindBlobParameter(aParamIndex, aValue, aValueSize); } \
  NS_IMETHOD BindParameters(mozIStorageBindingParamsArray *aParameters) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindParameters(aParameters); } \
  NS_IMETHOD NewBindingParamsArray(mozIStorageBindingParamsArray * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewBindingParamsArray(_retval); } \
  NS_IMETHOD ExecuteAsync(mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecuteAsync(aCallback, _retval); } \
  NS_IMETHOD GetState(int32_t *aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_IMETHOD EscapeStringForLIKE(const nsAString & aValue, PRUnichar aEscapeChar, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EscapeStringForLIKE(aValue, aEscapeChar, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageBaseStatement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGEBASESTATEMENT

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageBaseStatement)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void finalize (); */
NS_IMETHODIMP _MYCLASS_::Finalize()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [deprecated] void bindUTF8StringParameter (in unsigned long aParamIndex, in AUTF8String aValue); */
NS_IMETHODIMP _MYCLASS_::BindUTF8StringParameter(uint32_t aParamIndex, const nsACString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [deprecated] void bindStringParameter (in unsigned long aParamIndex, in AString aValue); */
NS_IMETHODIMP _MYCLASS_::BindStringParameter(uint32_t aParamIndex, const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [deprecated] void bindDoubleParameter (in unsigned long aParamIndex, in double aValue); */
NS_IMETHODIMP _MYCLASS_::BindDoubleParameter(uint32_t aParamIndex, double aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [deprecated] void bindInt32Parameter (in unsigned long aParamIndex, in long aValue); */
NS_IMETHODIMP _MYCLASS_::BindInt32Parameter(uint32_t aParamIndex, int32_t aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [deprecated] void bindInt64Parameter (in unsigned long aParamIndex, in long long aValue); */
NS_IMETHODIMP _MYCLASS_::BindInt64Parameter(uint32_t aParamIndex, int64_t aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [deprecated] void bindNullParameter (in unsigned long aParamIndex); */
NS_IMETHODIMP _MYCLASS_::BindNullParameter(uint32_t aParamIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [deprecated] void bindBlobParameter (in unsigned long aParamIndex, [array, size_is (aValueSize), const] in octet aValue, in unsigned long aValueSize); */
NS_IMETHODIMP _MYCLASS_::BindBlobParameter(uint32_t aParamIndex, const uint8_t *aValue, uint32_t aValueSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void bindParameters (in mozIStorageBindingParamsArray aParameters); */
NS_IMETHODIMP _MYCLASS_::BindParameters(mozIStorageBindingParamsArray *aParameters)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStorageBindingParamsArray newBindingParamsArray (); */
NS_IMETHODIMP _MYCLASS_::NewBindingParamsArray(mozIStorageBindingParamsArray * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStoragePendingStatement executeAsync ([optional] in mozIStorageStatementCallback aCallback); */
NS_IMETHODIMP _MYCLASS_::ExecuteAsync(mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long state; */
NS_IMETHODIMP _MYCLASS_::GetState(int32_t *aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString escapeStringForLIKE (in AString aValue, in wchar aEscapeChar); */
NS_IMETHODIMP _MYCLASS_::EscapeStringForLIKE(const nsAString & aValue, PRUnichar aEscapeChar, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageBaseStatement_h__ */

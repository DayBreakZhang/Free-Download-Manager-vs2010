/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/storage/public/mozIStorageStatement.idl
 */

#ifndef __gen_mozIStorageStatement_h__
#define __gen_mozIStorageStatement_h__


#ifndef __gen_mozIStorageBaseStatement_h__
#include "mozIStorageBaseStatement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "mozilla/DebugOnly.h"

/* starting interface:    mozIStorageStatement */
#define MOZISTORAGESTATEMENT_IID_STR "57ec7be1-36cf-4510-b938-7d1c9ee8cec5"

#define MOZISTORAGESTATEMENT_IID \
  {0x57ec7be1, 0x36cf, 0x4510, \
    { 0xb9, 0x38, 0x7d, 0x1c, 0x9e, 0xe8, 0xce, 0xc5 }}

class mozIStorageStatement : public mozIStorageBaseStatement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGESTATEMENT_IID)

  /* mozIStorageStatement clone (); */
  NS_IMETHOD Clone(mozIStorageStatement * *_retval) = 0;

  /* readonly attribute unsigned long parameterCount; */
  NS_IMETHOD GetParameterCount(uint32_t *aParameterCount) = 0;

  /* AUTF8String getParameterName (in unsigned long aParamIndex); */
  NS_IMETHOD GetParameterName(uint32_t aParamIndex, nsACString & _retval) = 0;

  /* unsigned long getParameterIndex (in AUTF8String aName); */
  NS_IMETHOD GetParameterIndex(const nsACString & aName, uint32_t *_retval) = 0;

  /* readonly attribute unsigned long columnCount; */
  NS_IMETHOD GetColumnCount(uint32_t *aColumnCount) = 0;

  /* AUTF8String getColumnName (in unsigned long aColumnIndex); */
  NS_IMETHOD GetColumnName(uint32_t aColumnIndex, nsACString & _retval) = 0;

  /* unsigned long getColumnIndex (in AUTF8String aName); */
  NS_IMETHOD GetColumnIndex(const nsACString & aName, uint32_t *_retval) = 0;

  /* AUTF8String getColumnDecltype (in unsigned long aParamIndex); */
  NS_IMETHOD GetColumnDecltype(uint32_t aParamIndex, nsACString & _retval) = 0;

  /* void reset (); */
  NS_IMETHOD Reset(void) = 0;

  /* void execute (); */
  NS_IMETHOD Execute(void) = 0;

  /* boolean executeStep (); */
  NS_IMETHOD ExecuteStep(bool *_retval) = 0;

  enum {
    VALUE_TYPE_NULL = 0,
    VALUE_TYPE_INTEGER = 1,
    VALUE_TYPE_FLOAT = 2,
    VALUE_TYPE_TEXT = 3,
    VALUE_TYPE_BLOB = 4
  };

  /* readonly attribute unsigned long numEntries; */
  NS_IMETHOD GetNumEntries(uint32_t *aNumEntries) = 0;

  /* long getTypeOfIndex (in unsigned long aIndex); */
  NS_IMETHOD GetTypeOfIndex(uint32_t aIndex, int32_t *_retval) = 0;

  /* long getInt32 (in unsigned long aIndex); */
  NS_IMETHOD GetInt32(uint32_t aIndex, int32_t *_retval) = 0;

  /* long long getInt64 (in unsigned long aIndex); */
  NS_IMETHOD GetInt64(uint32_t aIndex, int64_t *_retval) = 0;

  /* double getDouble (in unsigned long aIndex); */
  NS_IMETHOD GetDouble(uint32_t aIndex, double *_retval) = 0;

  /* AUTF8String getUTF8String (in unsigned long aIndex); */
  NS_IMETHOD GetUTF8String(uint32_t aIndex, nsACString & _retval) = 0;

  /* AString getString (in unsigned long aIndex); */
  NS_IMETHOD GetString(uint32_t aIndex, nsAString & _retval) = 0;

  /* void getBlob (in unsigned long aIndex, out unsigned long aDataSize, [array, size_is (aDataSize)] out octet aData); */
  NS_IMETHOD GetBlob(uint32_t aIndex, uint32_t *aDataSize, uint8_t **aData) = 0;

  /* boolean getIsNull (in unsigned long aIndex); */
  NS_IMETHOD GetIsNull(uint32_t aIndex, bool *_retval) = 0;

  /* [noscript] void getSharedUTF8String (in unsigned long aIndex, out unsigned long aLength, [shared, retval] out string aResult); */
  NS_IMETHOD GetSharedUTF8String(uint32_t aIndex, uint32_t *aLength, const char * *aResult) = 0;

  /* [noscript] void getSharedString (in unsigned long aIndex, out unsigned long aLength, [shared, retval] out wstring aResult); */
  NS_IMETHOD GetSharedString(uint32_t aIndex, uint32_t *aLength, const PRUnichar * *aResult) = 0;

  /* [noscript] void getSharedBlob (in unsigned long aIndex, out unsigned long aLength, [shared, retval] out octetPtr aResult); */
  NS_IMETHOD GetSharedBlob(uint32_t aIndex, uint32_t *aLength, const uint8_t **aResult) = 0;

   /**
   * Getters for native code that return their values as
   * the return type, for convenience and sanity.
   *
   * Not virtual; no vtable bloat.
   */
  inline int32_t AsInt32(uint32_t idx) {
    int32_t v = 0;
    mozilla::DebugOnly<nsresult> rv = GetInt32(idx, &v);
    NS_ABORT_IF_FALSE(NS_SUCCEEDED(rv) || IsNull(idx),
                      "Getting value failed, wrong column index?");
    return v;
  }
  inline int64_t AsInt64(uint32_t idx) {
    int64_t v = 0;
    mozilla::DebugOnly<nsresult> rv = GetInt64(idx, &v);
    NS_ABORT_IF_FALSE(NS_SUCCEEDED(rv) || IsNull(idx),
                      "Getting value failed, wrong column index?");
    return v;
  }
  inline double AsDouble(uint32_t idx) {
    double v = 0.0;
    mozilla::DebugOnly<nsresult> rv = GetDouble(idx, &v);
    NS_ABORT_IF_FALSE(NS_SUCCEEDED(rv) || IsNull(idx),
                      "Getting value failed, wrong column index?");
    return v;
  }
  inline const char* AsSharedUTF8String(uint32_t idx, uint32_t *len) {
    const char *str = nullptr;
    *len = 0;
    mozilla::DebugOnly<nsresult> rv = GetSharedUTF8String(idx, len, &str);
    NS_ABORT_IF_FALSE(NS_SUCCEEDED(rv) || IsNull(idx),
                      "Getting value failed, wrong column index?");
    return str;
  }
  inline const PRUnichar* AsSharedWString(uint32_t idx, uint32_t *len) {
    const PRUnichar *str = nullptr;
    *len = 0;
    mozilla::DebugOnly<nsresult> rv = GetSharedString(idx, len, &str);
    NS_ABORT_IF_FALSE(NS_SUCCEEDED(rv) || IsNull(idx),
                      "Getting value failed, wrong column index?");
    return str;
  }
  inline const uint8_t* AsSharedBlob(uint32_t idx, uint32_t *len) {
    const uint8_t *blob = nullptr;
    *len = 0;
    mozilla::DebugOnly<nsresult> rv = GetSharedBlob(idx, len, &blob);
    NS_ABORT_IF_FALSE(NS_SUCCEEDED(rv) || IsNull(idx),
                      "Getting value failed, wrong column index?");
    return blob;
  }
  inline bool IsNull(uint32_t idx) {
    bool b = false;
    mozilla::DebugOnly<nsresult> rv = GetIsNull(idx, &b);
    NS_ABORT_IF_FALSE(NS_SUCCEEDED(rv),
                      "Getting value failed, wrong column index?");
    return b;
  }
};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageStatement, MOZISTORAGESTATEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGESTATEMENT \
  NS_IMETHOD Clone(mozIStorageStatement * *_retval); \
  NS_IMETHOD GetParameterCount(uint32_t *aParameterCount); \
  NS_IMETHOD GetParameterName(uint32_t aParamIndex, nsACString & _retval); \
  NS_IMETHOD GetParameterIndex(const nsACString & aName, uint32_t *_retval); \
  NS_IMETHOD GetColumnCount(uint32_t *aColumnCount); \
  NS_IMETHOD GetColumnName(uint32_t aColumnIndex, nsACString & _retval); \
  NS_IMETHOD GetColumnIndex(const nsACString & aName, uint32_t *_retval); \
  NS_IMETHOD GetColumnDecltype(uint32_t aParamIndex, nsACString & _retval); \
  NS_IMETHOD Reset(void); \
  NS_IMETHOD Execute(void); \
  NS_IMETHOD ExecuteStep(bool *_retval); \
  NS_IMETHOD GetNumEntries(uint32_t *aNumEntries); \
  NS_IMETHOD GetTypeOfIndex(uint32_t aIndex, int32_t *_retval); \
  NS_IMETHOD GetInt32(uint32_t aIndex, int32_t *_retval); \
  NS_IMETHOD GetInt64(uint32_t aIndex, int64_t *_retval); \
  NS_IMETHOD GetDouble(uint32_t aIndex, double *_retval); \
  NS_IMETHOD GetUTF8String(uint32_t aIndex, nsACString & _retval); \
  NS_IMETHOD GetString(uint32_t aIndex, nsAString & _retval); \
  NS_IMETHOD GetBlob(uint32_t aIndex, uint32_t *aDataSize, uint8_t **aData); \
  NS_IMETHOD GetIsNull(uint32_t aIndex, bool *_retval); \
  NS_IMETHOD GetSharedUTF8String(uint32_t aIndex, uint32_t *aLength, const char * *aResult); \
  NS_IMETHOD GetSharedString(uint32_t aIndex, uint32_t *aLength, const PRUnichar * *aResult); \
  NS_IMETHOD GetSharedBlob(uint32_t aIndex, uint32_t *aLength, const uint8_t **aResult); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGESTATEMENT(_to) \
  NS_IMETHOD Clone(mozIStorageStatement * *_retval) { return _to Clone(_retval); } \
  NS_IMETHOD GetParameterCount(uint32_t *aParameterCount) { return _to GetParameterCount(aParameterCount); } \
  NS_IMETHOD GetParameterName(uint32_t aParamIndex, nsACString & _retval) { return _to GetParameterName(aParamIndex, _retval); } \
  NS_IMETHOD GetParameterIndex(const nsACString & aName, uint32_t *_retval) { return _to GetParameterIndex(aName, _retval); } \
  NS_IMETHOD GetColumnCount(uint32_t *aColumnCount) { return _to GetColumnCount(aColumnCount); } \
  NS_IMETHOD GetColumnName(uint32_t aColumnIndex, nsACString & _retval) { return _to GetColumnName(aColumnIndex, _retval); } \
  NS_IMETHOD GetColumnIndex(const nsACString & aName, uint32_t *_retval) { return _to GetColumnIndex(aName, _retval); } \
  NS_IMETHOD GetColumnDecltype(uint32_t aParamIndex, nsACString & _retval) { return _to GetColumnDecltype(aParamIndex, _retval); } \
  NS_IMETHOD Reset(void) { return _to Reset(); } \
  NS_IMETHOD Execute(void) { return _to Execute(); } \
  NS_IMETHOD ExecuteStep(bool *_retval) { return _to ExecuteStep(_retval); } \
  NS_IMETHOD GetNumEntries(uint32_t *aNumEntries) { return _to GetNumEntries(aNumEntries); } \
  NS_IMETHOD GetTypeOfIndex(uint32_t aIndex, int32_t *_retval) { return _to GetTypeOfIndex(aIndex, _retval); } \
  NS_IMETHOD GetInt32(uint32_t aIndex, int32_t *_retval) { return _to GetInt32(aIndex, _retval); } \
  NS_IMETHOD GetInt64(uint32_t aIndex, int64_t *_retval) { return _to GetInt64(aIndex, _retval); } \
  NS_IMETHOD GetDouble(uint32_t aIndex, double *_retval) { return _to GetDouble(aIndex, _retval); } \
  NS_IMETHOD GetUTF8String(uint32_t aIndex, nsACString & _retval) { return _to GetUTF8String(aIndex, _retval); } \
  NS_IMETHOD GetString(uint32_t aIndex, nsAString & _retval) { return _to GetString(aIndex, _retval); } \
  NS_IMETHOD GetBlob(uint32_t aIndex, uint32_t *aDataSize, uint8_t **aData) { return _to GetBlob(aIndex, aDataSize, aData); } \
  NS_IMETHOD GetIsNull(uint32_t aIndex, bool *_retval) { return _to GetIsNull(aIndex, _retval); } \
  NS_IMETHOD GetSharedUTF8String(uint32_t aIndex, uint32_t *aLength, const char * *aResult) { return _to GetSharedUTF8String(aIndex, aLength, aResult); } \
  NS_IMETHOD GetSharedString(uint32_t aIndex, uint32_t *aLength, const PRUnichar * *aResult) { return _to GetSharedString(aIndex, aLength, aResult); } \
  NS_IMETHOD GetSharedBlob(uint32_t aIndex, uint32_t *aLength, const uint8_t **aResult) { return _to GetSharedBlob(aIndex, aLength, aResult); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGESTATEMENT(_to) \
  NS_IMETHOD Clone(mozIStorageStatement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } \
  NS_IMETHOD GetParameterCount(uint32_t *aParameterCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParameterCount(aParameterCount); } \
  NS_IMETHOD GetParameterName(uint32_t aParamIndex, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParameterName(aParamIndex, _retval); } \
  NS_IMETHOD GetParameterIndex(const nsACString & aName, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParameterIndex(aName, _retval); } \
  NS_IMETHOD GetColumnCount(uint32_t *aColumnCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnCount(aColumnCount); } \
  NS_IMETHOD GetColumnName(uint32_t aColumnIndex, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnName(aColumnIndex, _retval); } \
  NS_IMETHOD GetColumnIndex(const nsACString & aName, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnIndex(aName, _retval); } \
  NS_IMETHOD GetColumnDecltype(uint32_t aParamIndex, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnDecltype(aParamIndex, _retval); } \
  NS_IMETHOD Reset(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Reset(); } \
  NS_IMETHOD Execute(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Execute(); } \
  NS_IMETHOD ExecuteStep(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecuteStep(_retval); } \
  NS_IMETHOD GetNumEntries(uint32_t *aNumEntries) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumEntries(aNumEntries); } \
  NS_IMETHOD GetTypeOfIndex(uint32_t aIndex, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypeOfIndex(aIndex, _retval); } \
  NS_IMETHOD GetInt32(uint32_t aIndex, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInt32(aIndex, _retval); } \
  NS_IMETHOD GetInt64(uint32_t aIndex, int64_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInt64(aIndex, _retval); } \
  NS_IMETHOD GetDouble(uint32_t aIndex, double *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDouble(aIndex, _retval); } \
  NS_IMETHOD GetUTF8String(uint32_t aIndex, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUTF8String(aIndex, _retval); } \
  NS_IMETHOD GetString(uint32_t aIndex, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetString(aIndex, _retval); } \
  NS_IMETHOD GetBlob(uint32_t aIndex, uint32_t *aDataSize, uint8_t **aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBlob(aIndex, aDataSize, aData); } \
  NS_IMETHOD GetIsNull(uint32_t aIndex, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsNull(aIndex, _retval); } \
  NS_IMETHOD GetSharedUTF8String(uint32_t aIndex, uint32_t *aLength, const char * *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSharedUTF8String(aIndex, aLength, aResult); } \
  NS_IMETHOD GetSharedString(uint32_t aIndex, uint32_t *aLength, const PRUnichar * *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSharedString(aIndex, aLength, aResult); } \
  NS_IMETHOD GetSharedBlob(uint32_t aIndex, uint32_t *aLength, const uint8_t **aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSharedBlob(aIndex, aLength, aResult); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageStatement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGESTATEMENT

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageStatement)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* mozIStorageStatement clone (); */
NS_IMETHODIMP _MYCLASS_::Clone(mozIStorageStatement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long parameterCount; */
NS_IMETHODIMP _MYCLASS_::GetParameterCount(uint32_t *aParameterCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getParameterName (in unsigned long aParamIndex); */
NS_IMETHODIMP _MYCLASS_::GetParameterName(uint32_t aParamIndex, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getParameterIndex (in AUTF8String aName); */
NS_IMETHODIMP _MYCLASS_::GetParameterIndex(const nsACString & aName, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long columnCount; */
NS_IMETHODIMP _MYCLASS_::GetColumnCount(uint32_t *aColumnCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getColumnName (in unsigned long aColumnIndex); */
NS_IMETHODIMP _MYCLASS_::GetColumnName(uint32_t aColumnIndex, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getColumnIndex (in AUTF8String aName); */
NS_IMETHODIMP _MYCLASS_::GetColumnIndex(const nsACString & aName, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getColumnDecltype (in unsigned long aParamIndex); */
NS_IMETHODIMP _MYCLASS_::GetColumnDecltype(uint32_t aParamIndex, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reset (); */
NS_IMETHODIMP _MYCLASS_::Reset()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void execute (); */
NS_IMETHODIMP _MYCLASS_::Execute()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean executeStep (); */
NS_IMETHODIMP _MYCLASS_::ExecuteStep(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long numEntries; */
NS_IMETHODIMP _MYCLASS_::GetNumEntries(uint32_t *aNumEntries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getTypeOfIndex (in unsigned long aIndex); */
NS_IMETHODIMP _MYCLASS_::GetTypeOfIndex(uint32_t aIndex, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getInt32 (in unsigned long aIndex); */
NS_IMETHODIMP _MYCLASS_::GetInt32(uint32_t aIndex, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long long getInt64 (in unsigned long aIndex); */
NS_IMETHODIMP _MYCLASS_::GetInt64(uint32_t aIndex, int64_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* double getDouble (in unsigned long aIndex); */
NS_IMETHODIMP _MYCLASS_::GetDouble(uint32_t aIndex, double *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getUTF8String (in unsigned long aIndex); */
NS_IMETHODIMP _MYCLASS_::GetUTF8String(uint32_t aIndex, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getString (in unsigned long aIndex); */
NS_IMETHODIMP _MYCLASS_::GetString(uint32_t aIndex, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getBlob (in unsigned long aIndex, out unsigned long aDataSize, [array, size_is (aDataSize)] out octet aData); */
NS_IMETHODIMP _MYCLASS_::GetBlob(uint32_t aIndex, uint32_t *aDataSize, uint8_t **aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getIsNull (in unsigned long aIndex); */
NS_IMETHODIMP _MYCLASS_::GetIsNull(uint32_t aIndex, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getSharedUTF8String (in unsigned long aIndex, out unsigned long aLength, [shared, retval] out string aResult); */
NS_IMETHODIMP _MYCLASS_::GetSharedUTF8String(uint32_t aIndex, uint32_t *aLength, const char * *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getSharedString (in unsigned long aIndex, out unsigned long aLength, [shared, retval] out wstring aResult); */
NS_IMETHODIMP _MYCLASS_::GetSharedString(uint32_t aIndex, uint32_t *aLength, const PRUnichar * *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getSharedBlob (in unsigned long aIndex, out unsigned long aLength, [shared, retval] out octetPtr aResult); */
NS_IMETHODIMP _MYCLASS_::GetSharedBlob(uint32_t aIndex, uint32_t *aLength, const uint8_t **aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageStatement_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\mozIStorageValueArray.idl
 */

#ifndef __gen_mozIStorageValueArray_h__
#define __gen_mozIStorageValueArray_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "mozilla/DebugOnly.h"

/* starting interface:    mozIStorageValueArray */
#define MOZISTORAGEVALUEARRAY_IID_STR "07b5b93e-113c-4150-863c-d247b003a55d"

#define MOZISTORAGEVALUEARRAY_IID \
  {0x07b5b93e, 0x113c, 0x4150, \
    { 0x86, 0x3c, 0xd2, 0x47, 0xb0, 0x03, 0xa5, 0x5d }}

class mozIStorageValueArray : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGEVALUEARRAY_IID)

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
  NS_IMETHOD GetSharedString(uint32_t aIndex, uint32_t *aLength, const char16_t * *aResult) = 0;

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
  inline const char16_t* AsSharedWString(uint32_t idx, uint32_t *len) {
    const char16_t *str = nullptr;
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

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageValueArray, MOZISTORAGEVALUEARRAY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGEVALUEARRAY \
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
  NS_IMETHOD GetSharedString(uint32_t aIndex, uint32_t *aLength, const char16_t * *aResult); \
  NS_IMETHOD GetSharedBlob(uint32_t aIndex, uint32_t *aLength, const uint8_t **aResult); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGEVALUEARRAY(_to) \
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
  NS_IMETHOD GetSharedString(uint32_t aIndex, uint32_t *aLength, const char16_t * *aResult) { return _to GetSharedString(aIndex, aLength, aResult); } \
  NS_IMETHOD GetSharedBlob(uint32_t aIndex, uint32_t *aLength, const uint8_t **aResult) { return _to GetSharedBlob(aIndex, aLength, aResult); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGEVALUEARRAY(_to) \
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
  NS_IMETHOD GetSharedString(uint32_t aIndex, uint32_t *aLength, const char16_t * *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSharedString(aIndex, aLength, aResult); } \
  NS_IMETHOD GetSharedBlob(uint32_t aIndex, uint32_t *aLength, const uint8_t **aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSharedBlob(aIndex, aLength, aResult); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageValueArray
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGEVALUEARRAY

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageValueArray)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
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
NS_IMETHODIMP _MYCLASS_::GetSharedString(uint32_t aIndex, uint32_t *aLength, const char16_t * *aResult)
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


#endif /* __gen_mozIStorageValueArray_h__ */

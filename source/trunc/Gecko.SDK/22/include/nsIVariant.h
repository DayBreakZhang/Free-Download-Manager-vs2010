/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/ds/nsIVariant.idl
 */

#ifndef __gen_nsIVariant_h__
#define __gen_nsIVariant_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDataType */
#define NS_IDATATYPE_IID_STR "4d12e540-83d7-11d5-90ed-0010a4e73d9a"

#define NS_IDATATYPE_IID \
  {0x4d12e540, 0x83d7, 0x11d5, \
    { 0x90, 0xed, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

class NS_NO_VTABLE nsIDataType : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDATATYPE_IID)

  enum {
    VTYPE_INT8 = 0U,
    VTYPE_INT16 = 1U,
    VTYPE_INT32 = 2U,
    VTYPE_INT64 = 3U,
    VTYPE_UINT8 = 4U,
    VTYPE_UINT16 = 5U,
    VTYPE_UINT32 = 6U,
    VTYPE_UINT64 = 7U,
    VTYPE_FLOAT = 8U,
    VTYPE_DOUBLE = 9U,
    VTYPE_BOOL = 10U,
    VTYPE_CHAR = 11U,
    VTYPE_WCHAR = 12U,
    VTYPE_VOID = 13U,
    VTYPE_ID = 14U,
    VTYPE_DOMSTRING = 15U,
    VTYPE_CHAR_STR = 16U,
    VTYPE_WCHAR_STR = 17U,
    VTYPE_INTERFACE = 18U,
    VTYPE_INTERFACE_IS = 19U,
    VTYPE_ARRAY = 20U,
    VTYPE_STRING_SIZE_IS = 21U,
    VTYPE_WSTRING_SIZE_IS = 22U,
    VTYPE_UTF8STRING = 23U,
    VTYPE_CSTRING = 24U,
    VTYPE_ASTRING = 25U,
    VTYPE_EMPTY_ARRAY = 254U,
    VTYPE_EMPTY = 255U
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDataType, NS_IDATATYPE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDATATYPE \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDATATYPE(_to) \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDATATYPE(_to) \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDataType : public nsIDataType
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDATATYPE

  nsDataType();

private:
  ~nsDataType();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDataType, nsIDataType)

nsDataType::nsDataType()
{
  /* member initializers and constructor code */
}

nsDataType::~nsDataType()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIVariant */
#define NS_IVARIANT_IID_STR "81e4c2de-acac-4ad6-901a-b5fb1b851a0d"

#define NS_IVARIANT_IID \
  {0x81e4c2de, 0xacac, 0x4ad6, \
    { 0x90, 0x1a, 0xb5, 0xfb, 0x1b, 0x85, 0x1a, 0x0d }}

class NS_NO_VTABLE nsIVariant : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IVARIANT_IID)

  /* [noscript] readonly attribute uint16_t dataType; */
  NS_IMETHOD GetDataType(uint16_t *aDataType) = 0;

  /* [noscript] uint8_t getAsInt8 (); */
  NS_IMETHOD GetAsInt8(uint8_t *_retval) = 0;

  /* [noscript] int16_t getAsInt16 (); */
  NS_IMETHOD GetAsInt16(int16_t *_retval) = 0;

  /* [noscript] int32_t getAsInt32 (); */
  NS_IMETHOD GetAsInt32(int32_t *_retval) = 0;

  /* [noscript] int64_t getAsInt64 (); */
  NS_IMETHOD GetAsInt64(int64_t *_retval) = 0;

  /* [noscript] uint8_t getAsUint8 (); */
  NS_IMETHOD GetAsUint8(uint8_t *_retval) = 0;

  /* [noscript] uint16_t getAsUint16 (); */
  NS_IMETHOD GetAsUint16(uint16_t *_retval) = 0;

  /* [noscript] uint32_t getAsUint32 (); */
  NS_IMETHOD GetAsUint32(uint32_t *_retval) = 0;

  /* [noscript] uint64_t getAsUint64 (); */
  NS_IMETHOD GetAsUint64(uint64_t *_retval) = 0;

  /* [noscript] float getAsFloat (); */
  NS_IMETHOD GetAsFloat(float *_retval) = 0;

  /* [noscript] double getAsDouble (); */
  NS_IMETHOD GetAsDouble(double *_retval) = 0;

  /* [noscript] boolean getAsBool (); */
  NS_IMETHOD GetAsBool(bool *_retval) = 0;

  /* [noscript] char getAsChar (); */
  NS_IMETHOD GetAsChar(char *_retval) = 0;

  /* [noscript] wchar getAsWChar (); */
  NS_IMETHOD GetAsWChar(PRUnichar *_retval) = 0;

  /* [notxpcom] nsresult getAsID (out nsID retval); */
  NS_IMETHOD_(nsresult) GetAsID(nsID *retval) = 0;

  /* [noscript] AString getAsAString (); */
  NS_IMETHOD GetAsAString(nsAString & _retval) = 0;

  /* [noscript] DOMString getAsDOMString (); */
  NS_IMETHOD GetAsDOMString(nsAString & _retval) = 0;

  /* [noscript] ACString getAsACString (); */
  NS_IMETHOD GetAsACString(nsACString & _retval) = 0;

  /* [noscript] AUTF8String getAsAUTF8String (); */
  NS_IMETHOD GetAsAUTF8String(nsACString & _retval) = 0;

  /* [noscript] string getAsString (); */
  NS_IMETHOD GetAsString(char * *_retval) = 0;

  /* [noscript] wstring getAsWString (); */
  NS_IMETHOD GetAsWString(PRUnichar * *_retval) = 0;

  /* [noscript] nsISupports getAsISupports (); */
  NS_IMETHOD GetAsISupports(nsISupports * *_retval) = 0;

  /* [noscript] jsval getAsJSVal (); */
  NS_IMETHOD GetAsJSVal(JS::Value *_retval) = 0;

  /* [noscript] void getAsInterface (out nsIIDPtr iid, [iid_is (iid), retval] out nsQIResult iface); */
  NS_IMETHOD GetAsInterface(nsIID **iid, void **iface) = 0;

  /* [notxpcom] nsresult getAsArray (out uint16_t type, out nsIID iid, out uint32_t count, out voidPtr ptr); */
  NS_IMETHOD_(nsresult) GetAsArray(uint16_t *type, nsIID *iid, uint32_t *count, void **ptr) = 0;

  /* [noscript] void getAsStringWithSize (out uint32_t size, [size_is (size), retval] out string str); */
  NS_IMETHOD GetAsStringWithSize(uint32_t *size, char * *str) = 0;

  /* [noscript] void getAsWStringWithSize (out uint32_t size, [size_is (size), retval] out wstring str); */
  NS_IMETHOD GetAsWStringWithSize(uint32_t *size, PRUnichar * *str) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIVariant, NS_IVARIANT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIVARIANT \
  NS_IMETHOD GetDataType(uint16_t *aDataType); \
  NS_IMETHOD GetAsInt8(uint8_t *_retval); \
  NS_IMETHOD GetAsInt16(int16_t *_retval); \
  NS_IMETHOD GetAsInt32(int32_t *_retval); \
  NS_IMETHOD GetAsInt64(int64_t *_retval); \
  NS_IMETHOD GetAsUint8(uint8_t *_retval); \
  NS_IMETHOD GetAsUint16(uint16_t *_retval); \
  NS_IMETHOD GetAsUint32(uint32_t *_retval); \
  NS_IMETHOD GetAsUint64(uint64_t *_retval); \
  NS_IMETHOD GetAsFloat(float *_retval); \
  NS_IMETHOD GetAsDouble(double *_retval); \
  NS_IMETHOD GetAsBool(bool *_retval); \
  NS_IMETHOD GetAsChar(char *_retval); \
  NS_IMETHOD GetAsWChar(PRUnichar *_retval); \
  NS_IMETHOD_(nsresult) GetAsID(nsID *retval); \
  NS_IMETHOD GetAsAString(nsAString & _retval); \
  NS_IMETHOD GetAsDOMString(nsAString & _retval); \
  NS_IMETHOD GetAsACString(nsACString & _retval); \
  NS_IMETHOD GetAsAUTF8String(nsACString & _retval); \
  NS_IMETHOD GetAsString(char * *_retval); \
  NS_IMETHOD GetAsWString(PRUnichar * *_retval); \
  NS_IMETHOD GetAsISupports(nsISupports * *_retval); \
  NS_IMETHOD GetAsJSVal(JS::Value *_retval); \
  NS_IMETHOD GetAsInterface(nsIID **iid, void **iface); \
  NS_IMETHOD_(nsresult) GetAsArray(uint16_t *type, nsIID *iid, uint32_t *count, void **ptr); \
  NS_IMETHOD GetAsStringWithSize(uint32_t *size, char * *str); \
  NS_IMETHOD GetAsWStringWithSize(uint32_t *size, PRUnichar * *str); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIVARIANT(_to) \
  NS_IMETHOD GetDataType(uint16_t *aDataType) { return _to GetDataType(aDataType); } \
  NS_IMETHOD GetAsInt8(uint8_t *_retval) { return _to GetAsInt8(_retval); } \
  NS_IMETHOD GetAsInt16(int16_t *_retval) { return _to GetAsInt16(_retval); } \
  NS_IMETHOD GetAsInt32(int32_t *_retval) { return _to GetAsInt32(_retval); } \
  NS_IMETHOD GetAsInt64(int64_t *_retval) { return _to GetAsInt64(_retval); } \
  NS_IMETHOD GetAsUint8(uint8_t *_retval) { return _to GetAsUint8(_retval); } \
  NS_IMETHOD GetAsUint16(uint16_t *_retval) { return _to GetAsUint16(_retval); } \
  NS_IMETHOD GetAsUint32(uint32_t *_retval) { return _to GetAsUint32(_retval); } \
  NS_IMETHOD GetAsUint64(uint64_t *_retval) { return _to GetAsUint64(_retval); } \
  NS_IMETHOD GetAsFloat(float *_retval) { return _to GetAsFloat(_retval); } \
  NS_IMETHOD GetAsDouble(double *_retval) { return _to GetAsDouble(_retval); } \
  NS_IMETHOD GetAsBool(bool *_retval) { return _to GetAsBool(_retval); } \
  NS_IMETHOD GetAsChar(char *_retval) { return _to GetAsChar(_retval); } \
  NS_IMETHOD GetAsWChar(PRUnichar *_retval) { return _to GetAsWChar(_retval); } \
  NS_IMETHOD_(nsresult) GetAsID(nsID *retval) { return _to GetAsID(retval); } \
  NS_IMETHOD GetAsAString(nsAString & _retval) { return _to GetAsAString(_retval); } \
  NS_IMETHOD GetAsDOMString(nsAString & _retval) { return _to GetAsDOMString(_retval); } \
  NS_IMETHOD GetAsACString(nsACString & _retval) { return _to GetAsACString(_retval); } \
  NS_IMETHOD GetAsAUTF8String(nsACString & _retval) { return _to GetAsAUTF8String(_retval); } \
  NS_IMETHOD GetAsString(char * *_retval) { return _to GetAsString(_retval); } \
  NS_IMETHOD GetAsWString(PRUnichar * *_retval) { return _to GetAsWString(_retval); } \
  NS_IMETHOD GetAsISupports(nsISupports * *_retval) { return _to GetAsISupports(_retval); } \
  NS_IMETHOD GetAsJSVal(JS::Value *_retval) { return _to GetAsJSVal(_retval); } \
  NS_IMETHOD GetAsInterface(nsIID **iid, void **iface) { return _to GetAsInterface(iid, iface); } \
  NS_IMETHOD_(nsresult) GetAsArray(uint16_t *type, nsIID *iid, uint32_t *count, void **ptr) { return _to GetAsArray(type, iid, count, ptr); } \
  NS_IMETHOD GetAsStringWithSize(uint32_t *size, char * *str) { return _to GetAsStringWithSize(size, str); } \
  NS_IMETHOD GetAsWStringWithSize(uint32_t *size, PRUnichar * *str) { return _to GetAsWStringWithSize(size, str); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIVARIANT(_to) \
  NS_IMETHOD GetDataType(uint16_t *aDataType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataType(aDataType); } \
  NS_IMETHOD GetAsInt8(uint8_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsInt8(_retval); } \
  NS_IMETHOD GetAsInt16(int16_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsInt16(_retval); } \
  NS_IMETHOD GetAsInt32(int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsInt32(_retval); } \
  NS_IMETHOD GetAsInt64(int64_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsInt64(_retval); } \
  NS_IMETHOD GetAsUint8(uint8_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsUint8(_retval); } \
  NS_IMETHOD GetAsUint16(uint16_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsUint16(_retval); } \
  NS_IMETHOD GetAsUint32(uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsUint32(_retval); } \
  NS_IMETHOD GetAsUint64(uint64_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsUint64(_retval); } \
  NS_IMETHOD GetAsFloat(float *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsFloat(_retval); } \
  NS_IMETHOD GetAsDouble(double *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsDouble(_retval); } \
  NS_IMETHOD GetAsBool(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsBool(_retval); } \
  NS_IMETHOD GetAsChar(char *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsChar(_retval); } \
  NS_IMETHOD GetAsWChar(PRUnichar *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsWChar(_retval); } \
  NS_IMETHOD_(nsresult) GetAsID(nsID *retval); \
  NS_IMETHOD GetAsAString(nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsAString(_retval); } \
  NS_IMETHOD GetAsDOMString(nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsDOMString(_retval); } \
  NS_IMETHOD GetAsACString(nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsACString(_retval); } \
  NS_IMETHOD GetAsAUTF8String(nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsAUTF8String(_retval); } \
  NS_IMETHOD GetAsString(char * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsString(_retval); } \
  NS_IMETHOD GetAsWString(PRUnichar * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsWString(_retval); } \
  NS_IMETHOD GetAsISupports(nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsISupports(_retval); } \
  NS_IMETHOD GetAsJSVal(JS::Value *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsJSVal(_retval); } \
  NS_IMETHOD GetAsInterface(nsIID **iid, void **iface) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsInterface(iid, iface); } \
  NS_IMETHOD_(nsresult) GetAsArray(uint16_t *type, nsIID *iid, uint32_t *count, void **ptr); \
  NS_IMETHOD GetAsStringWithSize(uint32_t *size, char * *str) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsStringWithSize(size, str); } \
  NS_IMETHOD GetAsWStringWithSize(uint32_t *size, PRUnichar * *str) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsWStringWithSize(size, str); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsVariant : public nsIVariant
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIVARIANT

  nsVariant();

private:
  ~nsVariant();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsVariant, nsIVariant)

nsVariant::nsVariant()
{
  /* member initializers and constructor code */
}

nsVariant::~nsVariant()
{
  /* destructor code */
}

/* [noscript] readonly attribute uint16_t dataType; */
NS_IMETHODIMP nsVariant::GetDataType(uint16_t *aDataType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] uint8_t getAsInt8 (); */
NS_IMETHODIMP nsVariant::GetAsInt8(uint8_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] int16_t getAsInt16 (); */
NS_IMETHODIMP nsVariant::GetAsInt16(int16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] int32_t getAsInt32 (); */
NS_IMETHODIMP nsVariant::GetAsInt32(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] int64_t getAsInt64 (); */
NS_IMETHODIMP nsVariant::GetAsInt64(int64_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] uint8_t getAsUint8 (); */
NS_IMETHODIMP nsVariant::GetAsUint8(uint8_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] uint16_t getAsUint16 (); */
NS_IMETHODIMP nsVariant::GetAsUint16(uint16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] uint32_t getAsUint32 (); */
NS_IMETHODIMP nsVariant::GetAsUint32(uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] uint64_t getAsUint64 (); */
NS_IMETHODIMP nsVariant::GetAsUint64(uint64_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] float getAsFloat (); */
NS_IMETHODIMP nsVariant::GetAsFloat(float *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] double getAsDouble (); */
NS_IMETHODIMP nsVariant::GetAsDouble(double *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] boolean getAsBool (); */
NS_IMETHODIMP nsVariant::GetAsBool(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] char getAsChar (); */
NS_IMETHODIMP nsVariant::GetAsChar(char *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] wchar getAsWChar (); */
NS_IMETHODIMP nsVariant::GetAsWChar(PRUnichar *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] nsresult getAsID (out nsID retval); */
NS_IMETHODIMP_(nsresult) nsVariant::GetAsID(nsID *retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] AString getAsAString (); */
NS_IMETHODIMP nsVariant::GetAsAString(nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] DOMString getAsDOMString (); */
NS_IMETHODIMP nsVariant::GetAsDOMString(nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] ACString getAsACString (); */
NS_IMETHODIMP nsVariant::GetAsACString(nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] AUTF8String getAsAUTF8String (); */
NS_IMETHODIMP nsVariant::GetAsAUTF8String(nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] string getAsString (); */
NS_IMETHODIMP nsVariant::GetAsString(char * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] wstring getAsWString (); */
NS_IMETHODIMP nsVariant::GetAsWString(PRUnichar * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsISupports getAsISupports (); */
NS_IMETHODIMP nsVariant::GetAsISupports(nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] jsval getAsJSVal (); */
NS_IMETHODIMP nsVariant::GetAsJSVal(JS::Value *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getAsInterface (out nsIIDPtr iid, [iid_is (iid), retval] out nsQIResult iface); */
NS_IMETHODIMP nsVariant::GetAsInterface(nsIID **iid, void **iface)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] nsresult getAsArray (out uint16_t type, out nsIID iid, out uint32_t count, out voidPtr ptr); */
NS_IMETHODIMP_(nsresult) nsVariant::GetAsArray(uint16_t *type, nsIID *iid, uint32_t *count, void **ptr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getAsStringWithSize (out uint32_t size, [size_is (size), retval] out string str); */
NS_IMETHODIMP nsVariant::GetAsStringWithSize(uint32_t *size, char * *str)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getAsWStringWithSize (out uint32_t size, [size_is (size), retval] out wstring str); */
NS_IMETHODIMP nsVariant::GetAsWStringWithSize(uint32_t *size, PRUnichar * *str)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWritableVariant */
#define NS_IWRITABLEVARIANT_IID_STR "5586a590-8c82-11d5-90f3-0010a4e73d9a"

#define NS_IWRITABLEVARIANT_IID \
  {0x5586a590, 0x8c82, 0x11d5, \
    { 0x90, 0xf3, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

class NS_NO_VTABLE nsIWritableVariant : public nsIVariant {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWRITABLEVARIANT_IID)

  /* attribute boolean writable; */
  NS_IMETHOD GetWritable(bool *aWritable) = 0;
  NS_IMETHOD SetWritable(bool aWritable) = 0;

  /* void setAsInt8 (in uint8_t aValue); */
  NS_IMETHOD SetAsInt8(uint8_t aValue) = 0;

  /* void setAsInt16 (in int16_t aValue); */
  NS_IMETHOD SetAsInt16(int16_t aValue) = 0;

  /* void setAsInt32 (in int32_t aValue); */
  NS_IMETHOD SetAsInt32(int32_t aValue) = 0;

  /* void setAsInt64 (in int64_t aValue); */
  NS_IMETHOD SetAsInt64(int64_t aValue) = 0;

  /* void setAsUint8 (in uint8_t aValue); */
  NS_IMETHOD SetAsUint8(uint8_t aValue) = 0;

  /* void setAsUint16 (in uint16_t aValue); */
  NS_IMETHOD SetAsUint16(uint16_t aValue) = 0;

  /* void setAsUint32 (in uint32_t aValue); */
  NS_IMETHOD SetAsUint32(uint32_t aValue) = 0;

  /* void setAsUint64 (in uint64_t aValue); */
  NS_IMETHOD SetAsUint64(uint64_t aValue) = 0;

  /* void setAsFloat (in float aValue); */
  NS_IMETHOD SetAsFloat(float aValue) = 0;

  /* void setAsDouble (in double aValue); */
  NS_IMETHOD SetAsDouble(double aValue) = 0;

  /* void setAsBool (in boolean aValue); */
  NS_IMETHOD SetAsBool(bool aValue) = 0;

  /* void setAsChar (in char aValue); */
  NS_IMETHOD SetAsChar(char aValue) = 0;

  /* void setAsWChar (in wchar aValue); */
  NS_IMETHOD SetAsWChar(PRUnichar aValue) = 0;

  /* void setAsID (in nsIDRef aValue); */
  NS_IMETHOD SetAsID(const nsID & aValue) = 0;

  /* void setAsAString (in AString aValue); */
  NS_IMETHOD SetAsAString(const nsAString & aValue) = 0;

  /* void setAsDOMString (in DOMString aValue); */
  NS_IMETHOD SetAsDOMString(const nsAString & aValue) = 0;

  /* void setAsACString (in ACString aValue); */
  NS_IMETHOD SetAsACString(const nsACString & aValue) = 0;

  /* void setAsAUTF8String (in AUTF8String aValue); */
  NS_IMETHOD SetAsAUTF8String(const nsACString & aValue) = 0;

  /* void setAsString (in string aValue); */
  NS_IMETHOD SetAsString(const char * aValue) = 0;

  /* void setAsWString (in wstring aValue); */
  NS_IMETHOD SetAsWString(const PRUnichar * aValue) = 0;

  /* void setAsISupports (in nsISupports aValue); */
  NS_IMETHOD SetAsISupports(nsISupports *aValue) = 0;

  /* void setAsInterface (in nsIIDRef iid, [iid_is (iid)] in nsQIResult iface); */
  NS_IMETHOD SetAsInterface(const nsIID & iid, void *iface) = 0;

  /* [noscript] void setAsArray (in uint16_t type, in nsIIDPtr iid, in uint32_t count, in voidPtr ptr); */
  NS_IMETHOD SetAsArray(uint16_t type, const nsIID *iid, uint32_t count, void *ptr) = 0;

  /* void setAsStringWithSize (in uint32_t size, [size_is (size)] in string str); */
  NS_IMETHOD SetAsStringWithSize(uint32_t size, const char * str) = 0;

  /* void setAsWStringWithSize (in uint32_t size, [size_is (size)] in wstring str); */
  NS_IMETHOD SetAsWStringWithSize(uint32_t size, const PRUnichar * str) = 0;

  /* void setAsVoid (); */
  NS_IMETHOD SetAsVoid(void) = 0;

  /* void setAsEmpty (); */
  NS_IMETHOD SetAsEmpty(void) = 0;

  /* void setAsEmptyArray (); */
  NS_IMETHOD SetAsEmptyArray(void) = 0;

  /* void setFromVariant (in nsIVariant aValue); */
  NS_IMETHOD SetFromVariant(nsIVariant *aValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWritableVariant, NS_IWRITABLEVARIANT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWRITABLEVARIANT \
  NS_IMETHOD GetWritable(bool *aWritable); \
  NS_IMETHOD SetWritable(bool aWritable); \
  NS_IMETHOD SetAsInt8(uint8_t aValue); \
  NS_IMETHOD SetAsInt16(int16_t aValue); \
  NS_IMETHOD SetAsInt32(int32_t aValue); \
  NS_IMETHOD SetAsInt64(int64_t aValue); \
  NS_IMETHOD SetAsUint8(uint8_t aValue); \
  NS_IMETHOD SetAsUint16(uint16_t aValue); \
  NS_IMETHOD SetAsUint32(uint32_t aValue); \
  NS_IMETHOD SetAsUint64(uint64_t aValue); \
  NS_IMETHOD SetAsFloat(float aValue); \
  NS_IMETHOD SetAsDouble(double aValue); \
  NS_IMETHOD SetAsBool(bool aValue); \
  NS_IMETHOD SetAsChar(char aValue); \
  NS_IMETHOD SetAsWChar(PRUnichar aValue); \
  NS_IMETHOD SetAsID(const nsID & aValue); \
  NS_IMETHOD SetAsAString(const nsAString & aValue); \
  NS_IMETHOD SetAsDOMString(const nsAString & aValue); \
  NS_IMETHOD SetAsACString(const nsACString & aValue); \
  NS_IMETHOD SetAsAUTF8String(const nsACString & aValue); \
  NS_IMETHOD SetAsString(const char * aValue); \
  NS_IMETHOD SetAsWString(const PRUnichar * aValue); \
  NS_IMETHOD SetAsISupports(nsISupports *aValue); \
  NS_IMETHOD SetAsInterface(const nsIID & iid, void *iface); \
  NS_IMETHOD SetAsArray(uint16_t type, const nsIID *iid, uint32_t count, void *ptr); \
  NS_IMETHOD SetAsStringWithSize(uint32_t size, const char * str); \
  NS_IMETHOD SetAsWStringWithSize(uint32_t size, const PRUnichar * str); \
  NS_IMETHOD SetAsVoid(void); \
  NS_IMETHOD SetAsEmpty(void); \
  NS_IMETHOD SetAsEmptyArray(void); \
  NS_IMETHOD SetFromVariant(nsIVariant *aValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWRITABLEVARIANT(_to) \
  NS_IMETHOD GetWritable(bool *aWritable) { return _to GetWritable(aWritable); } \
  NS_IMETHOD SetWritable(bool aWritable) { return _to SetWritable(aWritable); } \
  NS_IMETHOD SetAsInt8(uint8_t aValue) { return _to SetAsInt8(aValue); } \
  NS_IMETHOD SetAsInt16(int16_t aValue) { return _to SetAsInt16(aValue); } \
  NS_IMETHOD SetAsInt32(int32_t aValue) { return _to SetAsInt32(aValue); } \
  NS_IMETHOD SetAsInt64(int64_t aValue) { return _to SetAsInt64(aValue); } \
  NS_IMETHOD SetAsUint8(uint8_t aValue) { return _to SetAsUint8(aValue); } \
  NS_IMETHOD SetAsUint16(uint16_t aValue) { return _to SetAsUint16(aValue); } \
  NS_IMETHOD SetAsUint32(uint32_t aValue) { return _to SetAsUint32(aValue); } \
  NS_IMETHOD SetAsUint64(uint64_t aValue) { return _to SetAsUint64(aValue); } \
  NS_IMETHOD SetAsFloat(float aValue) { return _to SetAsFloat(aValue); } \
  NS_IMETHOD SetAsDouble(double aValue) { return _to SetAsDouble(aValue); } \
  NS_IMETHOD SetAsBool(bool aValue) { return _to SetAsBool(aValue); } \
  NS_IMETHOD SetAsChar(char aValue) { return _to SetAsChar(aValue); } \
  NS_IMETHOD SetAsWChar(PRUnichar aValue) { return _to SetAsWChar(aValue); } \
  NS_IMETHOD SetAsID(const nsID & aValue) { return _to SetAsID(aValue); } \
  NS_IMETHOD SetAsAString(const nsAString & aValue) { return _to SetAsAString(aValue); } \
  NS_IMETHOD SetAsDOMString(const nsAString & aValue) { return _to SetAsDOMString(aValue); } \
  NS_IMETHOD SetAsACString(const nsACString & aValue) { return _to SetAsACString(aValue); } \
  NS_IMETHOD SetAsAUTF8String(const nsACString & aValue) { return _to SetAsAUTF8String(aValue); } \
  NS_IMETHOD SetAsString(const char * aValue) { return _to SetAsString(aValue); } \
  NS_IMETHOD SetAsWString(const PRUnichar * aValue) { return _to SetAsWString(aValue); } \
  NS_IMETHOD SetAsISupports(nsISupports *aValue) { return _to SetAsISupports(aValue); } \
  NS_IMETHOD SetAsInterface(const nsIID & iid, void *iface) { return _to SetAsInterface(iid, iface); } \
  NS_IMETHOD SetAsArray(uint16_t type, const nsIID *iid, uint32_t count, void *ptr) { return _to SetAsArray(type, iid, count, ptr); } \
  NS_IMETHOD SetAsStringWithSize(uint32_t size, const char * str) { return _to SetAsStringWithSize(size, str); } \
  NS_IMETHOD SetAsWStringWithSize(uint32_t size, const PRUnichar * str) { return _to SetAsWStringWithSize(size, str); } \
  NS_IMETHOD SetAsVoid(void) { return _to SetAsVoid(); } \
  NS_IMETHOD SetAsEmpty(void) { return _to SetAsEmpty(); } \
  NS_IMETHOD SetAsEmptyArray(void) { return _to SetAsEmptyArray(); } \
  NS_IMETHOD SetFromVariant(nsIVariant *aValue) { return _to SetFromVariant(aValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWRITABLEVARIANT(_to) \
  NS_IMETHOD GetWritable(bool *aWritable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWritable(aWritable); } \
  NS_IMETHOD SetWritable(bool aWritable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWritable(aWritable); } \
  NS_IMETHOD SetAsInt8(uint8_t aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsInt8(aValue); } \
  NS_IMETHOD SetAsInt16(int16_t aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsInt16(aValue); } \
  NS_IMETHOD SetAsInt32(int32_t aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsInt32(aValue); } \
  NS_IMETHOD SetAsInt64(int64_t aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsInt64(aValue); } \
  NS_IMETHOD SetAsUint8(uint8_t aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsUint8(aValue); } \
  NS_IMETHOD SetAsUint16(uint16_t aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsUint16(aValue); } \
  NS_IMETHOD SetAsUint32(uint32_t aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsUint32(aValue); } \
  NS_IMETHOD SetAsUint64(uint64_t aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsUint64(aValue); } \
  NS_IMETHOD SetAsFloat(float aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsFloat(aValue); } \
  NS_IMETHOD SetAsDouble(double aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsDouble(aValue); } \
  NS_IMETHOD SetAsBool(bool aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsBool(aValue); } \
  NS_IMETHOD SetAsChar(char aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsChar(aValue); } \
  NS_IMETHOD SetAsWChar(PRUnichar aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsWChar(aValue); } \
  NS_IMETHOD SetAsID(const nsID & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsID(aValue); } \
  NS_IMETHOD SetAsAString(const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsAString(aValue); } \
  NS_IMETHOD SetAsDOMString(const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsDOMString(aValue); } \
  NS_IMETHOD SetAsACString(const nsACString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsACString(aValue); } \
  NS_IMETHOD SetAsAUTF8String(const nsACString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsAUTF8String(aValue); } \
  NS_IMETHOD SetAsString(const char * aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsString(aValue); } \
  NS_IMETHOD SetAsWString(const PRUnichar * aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsWString(aValue); } \
  NS_IMETHOD SetAsISupports(nsISupports *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsISupports(aValue); } \
  NS_IMETHOD SetAsInterface(const nsIID & iid, void *iface) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsInterface(iid, iface); } \
  NS_IMETHOD SetAsArray(uint16_t type, const nsIID *iid, uint32_t count, void *ptr) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsArray(type, iid, count, ptr); } \
  NS_IMETHOD SetAsStringWithSize(uint32_t size, const char * str) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsStringWithSize(size, str); } \
  NS_IMETHOD SetAsWStringWithSize(uint32_t size, const PRUnichar * str) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsWStringWithSize(size, str); } \
  NS_IMETHOD SetAsVoid(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsVoid(); } \
  NS_IMETHOD SetAsEmpty(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsEmpty(); } \
  NS_IMETHOD SetAsEmptyArray(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsEmptyArray(); } \
  NS_IMETHOD SetFromVariant(nsIVariant *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFromVariant(aValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWritableVariant : public nsIWritableVariant
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWRITABLEVARIANT

  nsWritableVariant();

private:
  ~nsWritableVariant();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWritableVariant, nsIWritableVariant)

nsWritableVariant::nsWritableVariant()
{
  /* member initializers and constructor code */
}

nsWritableVariant::~nsWritableVariant()
{
  /* destructor code */
}

/* attribute boolean writable; */
NS_IMETHODIMP nsWritableVariant::GetWritable(bool *aWritable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWritableVariant::SetWritable(bool aWritable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsInt8 (in uint8_t aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsInt8(uint8_t aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsInt16 (in int16_t aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsInt16(int16_t aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsInt32 (in int32_t aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsInt32(int32_t aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsInt64 (in int64_t aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsInt64(int64_t aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsUint8 (in uint8_t aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsUint8(uint8_t aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsUint16 (in uint16_t aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsUint16(uint16_t aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsUint32 (in uint32_t aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsUint32(uint32_t aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsUint64 (in uint64_t aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsUint64(uint64_t aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsFloat (in float aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsFloat(float aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsDouble (in double aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsDouble(double aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsBool (in boolean aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsBool(bool aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsChar (in char aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsChar(char aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsWChar (in wchar aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsWChar(PRUnichar aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsID (in nsIDRef aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsID(const nsID & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsAString (in AString aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsAString(const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsDOMString (in DOMString aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsDOMString(const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsACString (in ACString aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsACString(const nsACString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsAUTF8String (in AUTF8String aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsAUTF8String(const nsACString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsString (in string aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsString(const char * aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsWString (in wstring aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsWString(const PRUnichar * aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsISupports (in nsISupports aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsISupports(nsISupports *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsInterface (in nsIIDRef iid, [iid_is (iid)] in nsQIResult iface); */
NS_IMETHODIMP nsWritableVariant::SetAsInterface(const nsIID & iid, void *iface)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setAsArray (in uint16_t type, in nsIIDPtr iid, in uint32_t count, in voidPtr ptr); */
NS_IMETHODIMP nsWritableVariant::SetAsArray(uint16_t type, const nsIID *iid, uint32_t count, void *ptr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsStringWithSize (in uint32_t size, [size_is (size)] in string str); */
NS_IMETHODIMP nsWritableVariant::SetAsStringWithSize(uint32_t size, const char * str)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsWStringWithSize (in uint32_t size, [size_is (size)] in wstring str); */
NS_IMETHODIMP nsWritableVariant::SetAsWStringWithSize(uint32_t size, const PRUnichar * str)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsVoid (); */
NS_IMETHODIMP nsWritableVariant::SetAsVoid()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsEmpty (); */
NS_IMETHODIMP nsWritableVariant::SetAsEmpty()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsEmptyArray (); */
NS_IMETHODIMP nsWritableVariant::SetAsEmptyArray()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFromVariant (in nsIVariant aValue); */
NS_IMETHODIMP nsWritableVariant::SetFromVariant(nsIVariant *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// The contractID for the generic implementation built in to xpcom.
#define NS_VARIANT_CONTRACTID "@mozilla.org/variant;1"

#endif /* __gen_nsIVariant_h__ */

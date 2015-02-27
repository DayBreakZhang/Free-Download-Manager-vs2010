/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIBinaryOutputStream.idl
 */

#ifndef __gen_nsIBinaryOutputStream_h__
#define __gen_nsIBinaryOutputStream_h__


#ifndef __gen_nsIOutputStream_h__
#include "nsIOutputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIBinaryOutputStream */
#define NS_IBINARYOUTPUTSTREAM_IID_STR "204ee610-8765-11d3-90cf-0040056a906e"

#define NS_IBINARYOUTPUTSTREAM_IID \
  {0x204ee610, 0x8765, 0x11d3, \
    { 0x90, 0xcf, 0x00, 0x40, 0x05, 0x6a, 0x90, 0x6e }}

class NS_NO_VTABLE nsIBinaryOutputStream : public nsIOutputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBINARYOUTPUTSTREAM_IID)

  /* void setOutputStream (in nsIOutputStream aOutputStream); */
  NS_IMETHOD SetOutputStream(nsIOutputStream *aOutputStream) = 0;

  /* void writeBoolean (in boolean aBoolean); */
  NS_IMETHOD WriteBoolean(bool aBoolean) = 0;

  /* void write8 (in uint8_t aByte); */
  NS_IMETHOD Write8(uint8_t aByte) = 0;

  /* void write16 (in uint16_t a16); */
  NS_IMETHOD Write16(uint16_t a16) = 0;

  /* void write32 (in uint32_t a32); */
  NS_IMETHOD Write32(uint32_t a32) = 0;

  /* void write64 (in uint64_t a64); */
  NS_IMETHOD Write64(uint64_t a64) = 0;

  /* void writeFloat (in float aFloat); */
  NS_IMETHOD WriteFloat(float aFloat) = 0;

  /* void writeDouble (in double aDouble); */
  NS_IMETHOD WriteDouble(double aDouble) = 0;

  /* void writeStringZ (in string aString); */
  NS_IMETHOD WriteStringZ(const char * aString) = 0;

  /* void writeWStringZ (in wstring aString); */
  NS_IMETHOD WriteWStringZ(const char16_t * aString) = 0;

  /* void writeUtf8Z (in wstring aString); */
  NS_IMETHOD WriteUtf8Z(const char16_t * aString) = 0;

  /* void writeBytes ([size_is (aLength)] in string aString, in uint32_t aLength); */
  NS_IMETHOD WriteBytes(const char * aString, uint32_t aLength) = 0;

  /* void writeByteArray ([array, size_is (aLength)] in uint8_t aBytes, in uint32_t aLength); */
  NS_IMETHOD WriteByteArray(uint8_t *aBytes, uint32_t aLength) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBinaryOutputStream, NS_IBINARYOUTPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBINARYOUTPUTSTREAM \
  NS_IMETHOD SetOutputStream(nsIOutputStream *aOutputStream); \
  NS_IMETHOD WriteBoolean(bool aBoolean); \
  NS_IMETHOD Write8(uint8_t aByte); \
  NS_IMETHOD Write16(uint16_t a16); \
  NS_IMETHOD Write32(uint32_t a32); \
  NS_IMETHOD Write64(uint64_t a64); \
  NS_IMETHOD WriteFloat(float aFloat); \
  NS_IMETHOD WriteDouble(double aDouble); \
  NS_IMETHOD WriteStringZ(const char * aString); \
  NS_IMETHOD WriteWStringZ(const char16_t * aString); \
  NS_IMETHOD WriteUtf8Z(const char16_t * aString); \
  NS_IMETHOD WriteBytes(const char * aString, uint32_t aLength); \
  NS_IMETHOD WriteByteArray(uint8_t *aBytes, uint32_t aLength); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBINARYOUTPUTSTREAM(_to) \
  NS_IMETHOD SetOutputStream(nsIOutputStream *aOutputStream) { return _to SetOutputStream(aOutputStream); } \
  NS_IMETHOD WriteBoolean(bool aBoolean) { return _to WriteBoolean(aBoolean); } \
  NS_IMETHOD Write8(uint8_t aByte) { return _to Write8(aByte); } \
  NS_IMETHOD Write16(uint16_t a16) { return _to Write16(a16); } \
  NS_IMETHOD Write32(uint32_t a32) { return _to Write32(a32); } \
  NS_IMETHOD Write64(uint64_t a64) { return _to Write64(a64); } \
  NS_IMETHOD WriteFloat(float aFloat) { return _to WriteFloat(aFloat); } \
  NS_IMETHOD WriteDouble(double aDouble) { return _to WriteDouble(aDouble); } \
  NS_IMETHOD WriteStringZ(const char * aString) { return _to WriteStringZ(aString); } \
  NS_IMETHOD WriteWStringZ(const char16_t * aString) { return _to WriteWStringZ(aString); } \
  NS_IMETHOD WriteUtf8Z(const char16_t * aString) { return _to WriteUtf8Z(aString); } \
  NS_IMETHOD WriteBytes(const char * aString, uint32_t aLength) { return _to WriteBytes(aString, aLength); } \
  NS_IMETHOD WriteByteArray(uint8_t *aBytes, uint32_t aLength) { return _to WriteByteArray(aBytes, aLength); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBINARYOUTPUTSTREAM(_to) \
  NS_IMETHOD SetOutputStream(nsIOutputStream *aOutputStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOutputStream(aOutputStream); } \
  NS_IMETHOD WriteBoolean(bool aBoolean) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteBoolean(aBoolean); } \
  NS_IMETHOD Write8(uint8_t aByte) { return !_to ? NS_ERROR_NULL_POINTER : _to->Write8(aByte); } \
  NS_IMETHOD Write16(uint16_t a16) { return !_to ? NS_ERROR_NULL_POINTER : _to->Write16(a16); } \
  NS_IMETHOD Write32(uint32_t a32) { return !_to ? NS_ERROR_NULL_POINTER : _to->Write32(a32); } \
  NS_IMETHOD Write64(uint64_t a64) { return !_to ? NS_ERROR_NULL_POINTER : _to->Write64(a64); } \
  NS_IMETHOD WriteFloat(float aFloat) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteFloat(aFloat); } \
  NS_IMETHOD WriteDouble(double aDouble) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteDouble(aDouble); } \
  NS_IMETHOD WriteStringZ(const char * aString) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteStringZ(aString); } \
  NS_IMETHOD WriteWStringZ(const char16_t * aString) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteWStringZ(aString); } \
  NS_IMETHOD WriteUtf8Z(const char16_t * aString) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteUtf8Z(aString); } \
  NS_IMETHOD WriteBytes(const char * aString, uint32_t aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteBytes(aString, aLength); } \
  NS_IMETHOD WriteByteArray(uint8_t *aBytes, uint32_t aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteByteArray(aBytes, aLength); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBinaryOutputStream : public nsIBinaryOutputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBINARYOUTPUTSTREAM

  nsBinaryOutputStream();

private:
  ~nsBinaryOutputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBinaryOutputStream, nsIBinaryOutputStream)

nsBinaryOutputStream::nsBinaryOutputStream()
{
  /* member initializers and constructor code */
}

nsBinaryOutputStream::~nsBinaryOutputStream()
{
  /* destructor code */
}

/* void setOutputStream (in nsIOutputStream aOutputStream); */
NS_IMETHODIMP nsBinaryOutputStream::SetOutputStream(nsIOutputStream *aOutputStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeBoolean (in boolean aBoolean); */
NS_IMETHODIMP nsBinaryOutputStream::WriteBoolean(bool aBoolean)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void write8 (in uint8_t aByte); */
NS_IMETHODIMP nsBinaryOutputStream::Write8(uint8_t aByte)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void write16 (in uint16_t a16); */
NS_IMETHODIMP nsBinaryOutputStream::Write16(uint16_t a16)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void write32 (in uint32_t a32); */
NS_IMETHODIMP nsBinaryOutputStream::Write32(uint32_t a32)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void write64 (in uint64_t a64); */
NS_IMETHODIMP nsBinaryOutputStream::Write64(uint64_t a64)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeFloat (in float aFloat); */
NS_IMETHODIMP nsBinaryOutputStream::WriteFloat(float aFloat)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeDouble (in double aDouble); */
NS_IMETHODIMP nsBinaryOutputStream::WriteDouble(double aDouble)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeStringZ (in string aString); */
NS_IMETHODIMP nsBinaryOutputStream::WriteStringZ(const char * aString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeWStringZ (in wstring aString); */
NS_IMETHODIMP nsBinaryOutputStream::WriteWStringZ(const char16_t * aString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeUtf8Z (in wstring aString); */
NS_IMETHODIMP nsBinaryOutputStream::WriteUtf8Z(const char16_t * aString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeBytes ([size_is (aLength)] in string aString, in uint32_t aLength); */
NS_IMETHODIMP nsBinaryOutputStream::WriteBytes(const char * aString, uint32_t aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeByteArray ([array, size_is (aLength)] in uint8_t aBytes, in uint32_t aLength); */
NS_IMETHODIMP nsBinaryOutputStream::WriteByteArray(uint8_t *aBytes, uint32_t aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


inline nsresult
NS_WriteOptionalStringZ(nsIBinaryOutputStream* aStream, const char* aString)
{
    bool nonnull = (aString != nullptr);
    nsresult rv = aStream->WriteBoolean(nonnull);
    if (NS_SUCCEEDED(rv) && nonnull)
        rv = aStream->WriteStringZ(aString);
    return rv;
}
inline nsresult
NS_WriteOptionalWStringZ(nsIBinaryOutputStream* aStream, const char16_t* aString)
{
    bool nonnull = (aString != nullptr);
    nsresult rv = aStream->WriteBoolean(nonnull);
    if (NS_SUCCEEDED(rv) && nonnull)
        rv = aStream->WriteWStringZ(aString);
    return rv;
}

#endif /* __gen_nsIBinaryOutputStream_h__ */

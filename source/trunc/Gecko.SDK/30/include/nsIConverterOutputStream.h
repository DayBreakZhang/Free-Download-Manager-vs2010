/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIConverterOutputStream.idl
 */

#ifndef __gen_nsIConverterOutputStream_h__
#define __gen_nsIConverterOutputStream_h__


#ifndef __gen_nsIUnicharOutputStream_h__
#include "nsIUnicharOutputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIOutputStream; /* forward declaration */


/* starting interface:    nsIConverterOutputStream */
#define NS_ICONVERTEROUTPUTSTREAM_IID_STR "4b71113a-cb0d-479f-8ed5-01daeba2e8d4"

#define NS_ICONVERTEROUTPUTSTREAM_IID \
  {0x4b71113a, 0xcb0d, 0x479f, \
    { 0x8e, 0xd5, 0x01, 0xda, 0xeb, 0xa2, 0xe8, 0xd4 }}

class NS_NO_VTABLE nsIConverterOutputStream : public nsIUnicharOutputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONVERTEROUTPUTSTREAM_IID)

  /* void init (in nsIOutputStream aOutStream, in string aCharset, in unsigned long aBufferSize, in char16_t aReplacementCharacter); */
  NS_IMETHOD Init(nsIOutputStream *aOutStream, const char * aCharset, uint32_t aBufferSize, char16_t aReplacementCharacter) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIConverterOutputStream, NS_ICONVERTEROUTPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONVERTEROUTPUTSTREAM \
  NS_IMETHOD Init(nsIOutputStream *aOutStream, const char * aCharset, uint32_t aBufferSize, char16_t aReplacementCharacter); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONVERTEROUTPUTSTREAM(_to) \
  NS_IMETHOD Init(nsIOutputStream *aOutStream, const char * aCharset, uint32_t aBufferSize, char16_t aReplacementCharacter) { return _to Init(aOutStream, aCharset, aBufferSize, aReplacementCharacter); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONVERTEROUTPUTSTREAM(_to) \
  NS_IMETHOD Init(nsIOutputStream *aOutStream, const char * aCharset, uint32_t aBufferSize, char16_t aReplacementCharacter) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aOutStream, aCharset, aBufferSize, aReplacementCharacter); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsConverterOutputStream : public nsIConverterOutputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONVERTEROUTPUTSTREAM

  nsConverterOutputStream();

private:
  ~nsConverterOutputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsConverterOutputStream, nsIConverterOutputStream)

nsConverterOutputStream::nsConverterOutputStream()
{
  /* member initializers and constructor code */
}

nsConverterOutputStream::~nsConverterOutputStream()
{
  /* destructor code */
}

/* void init (in nsIOutputStream aOutStream, in string aCharset, in unsigned long aBufferSize, in char16_t aReplacementCharacter); */
NS_IMETHODIMP nsConverterOutputStream::Init(nsIOutputStream *aOutStream, const char * aCharset, uint32_t aBufferSize, char16_t aReplacementCharacter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIConverterOutputStream_h__ */

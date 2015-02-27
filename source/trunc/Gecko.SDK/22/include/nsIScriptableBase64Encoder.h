/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/io/nsIScriptableBase64Encoder.idl
 */

#ifndef __gen_nsIScriptableBase64Encoder_h__
#define __gen_nsIScriptableBase64Encoder_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */


/* starting interface:    nsIScriptableBase64Encoder */
#define NS_ISCRIPTABLEBASE64ENCODER_IID_STR "9479c864-d1f9-45ab-b7b9-28b907bd2ba9"

#define NS_ISCRIPTABLEBASE64ENCODER_IID \
  {0x9479c864, 0xd1f9, 0x45ab, \
    { 0xb7, 0xb9, 0x28, 0xb9, 0x07, 0xbd, 0x2b, 0xa9 }}

class NS_NO_VTABLE nsIScriptableBase64Encoder : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTABLEBASE64ENCODER_IID)

  /* ACString encodeToCString (in nsIInputStream stream, in unsigned long length); */
  NS_IMETHOD EncodeToCString(nsIInputStream *stream, uint32_t length, nsACString & _retval) = 0;

  /* AString encodeToString (in nsIInputStream stream, in unsigned long length); */
  NS_IMETHOD EncodeToString(nsIInputStream *stream, uint32_t length, nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptableBase64Encoder, NS_ISCRIPTABLEBASE64ENCODER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTABLEBASE64ENCODER \
  NS_IMETHOD EncodeToCString(nsIInputStream *stream, uint32_t length, nsACString & _retval); \
  NS_IMETHOD EncodeToString(nsIInputStream *stream, uint32_t length, nsAString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTABLEBASE64ENCODER(_to) \
  NS_IMETHOD EncodeToCString(nsIInputStream *stream, uint32_t length, nsACString & _retval) { return _to EncodeToCString(stream, length, _retval); } \
  NS_IMETHOD EncodeToString(nsIInputStream *stream, uint32_t length, nsAString & _retval) { return _to EncodeToString(stream, length, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTABLEBASE64ENCODER(_to) \
  NS_IMETHOD EncodeToCString(nsIInputStream *stream, uint32_t length, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EncodeToCString(stream, length, _retval); } \
  NS_IMETHOD EncodeToString(nsIInputStream *stream, uint32_t length, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EncodeToString(stream, length, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptableBase64Encoder : public nsIScriptableBase64Encoder
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTABLEBASE64ENCODER

  nsScriptableBase64Encoder();

private:
  ~nsScriptableBase64Encoder();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScriptableBase64Encoder, nsIScriptableBase64Encoder)

nsScriptableBase64Encoder::nsScriptableBase64Encoder()
{
  /* member initializers and constructor code */
}

nsScriptableBase64Encoder::~nsScriptableBase64Encoder()
{
  /* destructor code */
}

/* ACString encodeToCString (in nsIInputStream stream, in unsigned long length); */
NS_IMETHODIMP nsScriptableBase64Encoder::EncodeToCString(nsIInputStream *stream, uint32_t length, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString encodeToString (in nsIInputStream stream, in unsigned long length); */
NS_IMETHODIMP nsScriptableBase64Encoder::EncodeToString(nsIInputStream *stream, uint32_t length, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIScriptableBase64Encoder_h__ */

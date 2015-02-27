/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIStringStream.idl
 */

#ifndef __gen_nsIStringStream_h__
#define __gen_nsIStringStream_h__


#ifndef __gen_nsIInputStream_h__
#include "nsIInputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIStringInputStream */
#define NS_ISTRINGINPUTSTREAM_IID_STR "450cd2d4-f0fd-424d-b365-b1251f80fd53"

#define NS_ISTRINGINPUTSTREAM_IID \
  {0x450cd2d4, 0xf0fd, 0x424d, \
    { 0xb3, 0x65, 0xb1, 0x25, 0x1f, 0x80, 0xfd, 0x53 }}

class NS_NO_VTABLE nsIStringInputStream : public nsIInputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTRINGINPUTSTREAM_IID)

  /* void setData (in string data, in long dataLen); */
  NS_IMETHOD SetData(const char * data, int32_t dataLen) = 0;

  /* [noscript] void adoptData (in charPtr data, in long dataLen); */
  NS_IMETHOD AdoptData(char *data, int32_t dataLen) = 0;

  /* [noscript] void shareData (in string data, in long dataLen); */
  NS_IMETHOD ShareData(const char * data, int32_t dataLen) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStringInputStream, NS_ISTRINGINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTRINGINPUTSTREAM \
  NS_IMETHOD SetData(const char * data, int32_t dataLen); \
  NS_IMETHOD AdoptData(char *data, int32_t dataLen); \
  NS_IMETHOD ShareData(const char * data, int32_t dataLen); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTRINGINPUTSTREAM(_to) \
  NS_IMETHOD SetData(const char * data, int32_t dataLen) { return _to SetData(data, dataLen); } \
  NS_IMETHOD AdoptData(char *data, int32_t dataLen) { return _to AdoptData(data, dataLen); } \
  NS_IMETHOD ShareData(const char * data, int32_t dataLen) { return _to ShareData(data, dataLen); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTRINGINPUTSTREAM(_to) \
  NS_IMETHOD SetData(const char * data, int32_t dataLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetData(data, dataLen); } \
  NS_IMETHOD AdoptData(char *data, int32_t dataLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->AdoptData(data, dataLen); } \
  NS_IMETHOD ShareData(const char * data, int32_t dataLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShareData(data, dataLen); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStringInputStream : public nsIStringInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTRINGINPUTSTREAM

  nsStringInputStream();

private:
  ~nsStringInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStringInputStream, nsIStringInputStream)

nsStringInputStream::nsStringInputStream()
{
  /* member initializers and constructor code */
}

nsStringInputStream::~nsStringInputStream()
{
  /* destructor code */
}

/* void setData (in string data, in long dataLen); */
NS_IMETHODIMP nsStringInputStream::SetData(const char * data, int32_t dataLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void adoptData (in charPtr data, in long dataLen); */
NS_IMETHODIMP nsStringInputStream::AdoptData(char *data, int32_t dataLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void shareData (in string data, in long dataLen); */
NS_IMETHODIMP nsStringInputStream::ShareData(const char * data, int32_t dataLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStringStream_h__ */

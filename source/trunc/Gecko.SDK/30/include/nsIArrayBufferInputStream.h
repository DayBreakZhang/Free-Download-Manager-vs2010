/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIArrayBufferInputStream.idl
 */

#ifndef __gen_nsIArrayBufferInputStream_h__
#define __gen_nsIArrayBufferInputStream_h__


#ifndef __gen_nsIInputStream_h__
#include "nsIInputStream.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIArrayBufferInputStream */
#define NS_IARRAYBUFFERINPUTSTREAM_IID_STR "3014dde6-aa1c-41db-87d0-48764a3710f6"

#define NS_IARRAYBUFFERINPUTSTREAM_IID \
  {0x3014dde6, 0xaa1c, 0x41db, \
    { 0x87, 0xd0, 0x48, 0x76, 0x4a, 0x37, 0x10, 0xf6 }}

class NS_NO_VTABLE nsIArrayBufferInputStream : public nsIInputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IARRAYBUFFERINPUTSTREAM_IID)

  /* [implicit_jscontext] void setData (in jsval buffer, in unsigned long byteOffset, in unsigned long byteLen); */
  NS_IMETHOD SetData(JS::HandleValue buffer, uint32_t byteOffset, uint32_t byteLen, JSContext* cx) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIArrayBufferInputStream, NS_IARRAYBUFFERINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIARRAYBUFFERINPUTSTREAM \
  NS_IMETHOD SetData(JS::HandleValue buffer, uint32_t byteOffset, uint32_t byteLen, JSContext* cx); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIARRAYBUFFERINPUTSTREAM(_to) \
  NS_IMETHOD SetData(JS::HandleValue buffer, uint32_t byteOffset, uint32_t byteLen, JSContext* cx) { return _to SetData(buffer, byteOffset, byteLen, cx); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIARRAYBUFFERINPUTSTREAM(_to) \
  NS_IMETHOD SetData(JS::HandleValue buffer, uint32_t byteOffset, uint32_t byteLen, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetData(buffer, byteOffset, byteLen, cx); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsArrayBufferInputStream : public nsIArrayBufferInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIARRAYBUFFERINPUTSTREAM

  nsArrayBufferInputStream();

private:
  ~nsArrayBufferInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsArrayBufferInputStream, nsIArrayBufferInputStream)

nsArrayBufferInputStream::nsArrayBufferInputStream()
{
  /* member initializers and constructor code */
}

nsArrayBufferInputStream::~nsArrayBufferInputStream()
{
  /* destructor code */
}

/* [implicit_jscontext] void setData (in jsval buffer, in unsigned long byteOffset, in unsigned long byteLen); */
NS_IMETHODIMP nsArrayBufferInputStream::SetData(JS::HandleValue buffer, uint32_t byteOffset, uint32_t byteLen, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIArrayBufferInputStream_h__ */

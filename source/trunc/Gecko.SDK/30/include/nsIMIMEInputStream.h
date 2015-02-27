/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMIMEInputStream.idl
 */

#ifndef __gen_nsIMIMEInputStream_h__
#define __gen_nsIMIMEInputStream_h__


#ifndef __gen_nsIInputStream_h__
#include "nsIInputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMIMEInputStream */
#define NS_IMIMEINPUTSTREAM_IID_STR "dcbce63c-1dd1-11b2-b94d-91f6d49a3161"

#define NS_IMIMEINPUTSTREAM_IID \
  {0xdcbce63c, 0x1dd1, 0x11b2, \
    { 0xb9, 0x4d, 0x91, 0xf6, 0xd4, 0x9a, 0x31, 0x61 }}

class NS_NO_VTABLE nsIMIMEInputStream : public nsIInputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMIMEINPUTSTREAM_IID)

  /* attribute boolean addContentLength; */
  NS_IMETHOD GetAddContentLength(bool *aAddContentLength) = 0;
  NS_IMETHOD SetAddContentLength(bool aAddContentLength) = 0;

  /* void addHeader (in string name, in string value); */
  NS_IMETHOD AddHeader(const char * name, const char * value) = 0;

  /* void setData (in nsIInputStream stream); */
  NS_IMETHOD SetData(nsIInputStream *stream) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMIMEInputStream, NS_IMIMEINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMIMEINPUTSTREAM \
  NS_IMETHOD GetAddContentLength(bool *aAddContentLength); \
  NS_IMETHOD SetAddContentLength(bool aAddContentLength); \
  NS_IMETHOD AddHeader(const char * name, const char * value); \
  NS_IMETHOD SetData(nsIInputStream *stream); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMIMEINPUTSTREAM(_to) \
  NS_IMETHOD GetAddContentLength(bool *aAddContentLength) { return _to GetAddContentLength(aAddContentLength); } \
  NS_IMETHOD SetAddContentLength(bool aAddContentLength) { return _to SetAddContentLength(aAddContentLength); } \
  NS_IMETHOD AddHeader(const char * name, const char * value) { return _to AddHeader(name, value); } \
  NS_IMETHOD SetData(nsIInputStream *stream) { return _to SetData(stream); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMIMEINPUTSTREAM(_to) \
  NS_IMETHOD GetAddContentLength(bool *aAddContentLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAddContentLength(aAddContentLength); } \
  NS_IMETHOD SetAddContentLength(bool aAddContentLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAddContentLength(aAddContentLength); } \
  NS_IMETHOD AddHeader(const char * name, const char * value) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddHeader(name, value); } \
  NS_IMETHOD SetData(nsIInputStream *stream) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetData(stream); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMIMEInputStream : public nsIMIMEInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMIMEINPUTSTREAM

  nsMIMEInputStream();

private:
  ~nsMIMEInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMIMEInputStream, nsIMIMEInputStream)

nsMIMEInputStream::nsMIMEInputStream()
{
  /* member initializers and constructor code */
}

nsMIMEInputStream::~nsMIMEInputStream()
{
  /* destructor code */
}

/* attribute boolean addContentLength; */
NS_IMETHODIMP nsMIMEInputStream::GetAddContentLength(bool *aAddContentLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMIMEInputStream::SetAddContentLength(bool aAddContentLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addHeader (in string name, in string value); */
NS_IMETHODIMP nsMIMEInputStream::AddHeader(const char * name, const char * value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setData (in nsIInputStream stream); */
NS_IMETHODIMP nsMIMEInputStream::SetData(nsIInputStream *stream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMIMEInputStream_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\imgIEncoder.idl
 */

#ifndef __gen_imgIEncoder_h__
#define __gen_imgIEncoder_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIAsyncInputStream_h__
#include "nsIAsyncInputStream.h"
#endif

#ifndef __gen_nsIEventTarget_h__
#include "nsIEventTarget.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    imgIEncoder */
#define IMGIENCODER_IID_STR "4baa2d6e-fee7-42df-ae3f-5fbebc0c267c"

#define IMGIENCODER_IID \
  {0x4baa2d6e, 0xfee7, 0x42df, \
    { 0xae, 0x3f, 0x5f, 0xbe, 0xbc, 0x0c, 0x26, 0x7c }}

class NS_NO_VTABLE imgIEncoder : public nsIAsyncInputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMGIENCODER_IID)

  enum {
    INPUT_FORMAT_RGB = 0U,
    INPUT_FORMAT_RGBA = 1U,
    INPUT_FORMAT_HOSTARGB = 2U
  };

  /* void initFromData ([array, size_is (length), const] in uint8_t data, in unsigned long length, in uint32_t width, in uint32_t height, in uint32_t stride, in uint32_t inputFormat, in AString outputOptions); */
  NS_IMETHOD InitFromData(const uint8_t *data, uint32_t length, uint32_t width, uint32_t height, uint32_t stride, uint32_t inputFormat, const nsAString & outputOptions) = 0;

  /* void startImageEncode (in uint32_t width, in uint32_t height, in uint32_t inputFormat, in AString outputOptions); */
  NS_IMETHOD StartImageEncode(uint32_t width, uint32_t height, uint32_t inputFormat, const nsAString & outputOptions) = 0;

  /* void addImageFrame ([array, size_is (length), const] in uint8_t data, in unsigned long length, in uint32_t width, in uint32_t height, in uint32_t stride, in uint32_t frameFormat, in AString frameOptions); */
  NS_IMETHOD AddImageFrame(const uint8_t *data, uint32_t length, uint32_t width, uint32_t height, uint32_t stride, uint32_t frameFormat, const nsAString & frameOptions) = 0;

  /* void endImageEncode (); */
  NS_IMETHOD EndImageEncode(void) = 0;

  /* [noscript] unsigned long getImageBufferUsed (); */
  NS_IMETHOD GetImageBufferUsed(uint32_t *_retval) = 0;

  /* [noscript] charPtr getImageBuffer (); */
  NS_IMETHOD GetImageBuffer(char **_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(imgIEncoder, IMGIENCODER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMGIENCODER \
  NS_IMETHOD InitFromData(const uint8_t *data, uint32_t length, uint32_t width, uint32_t height, uint32_t stride, uint32_t inputFormat, const nsAString & outputOptions); \
  NS_IMETHOD StartImageEncode(uint32_t width, uint32_t height, uint32_t inputFormat, const nsAString & outputOptions); \
  NS_IMETHOD AddImageFrame(const uint8_t *data, uint32_t length, uint32_t width, uint32_t height, uint32_t stride, uint32_t frameFormat, const nsAString & frameOptions); \
  NS_IMETHOD EndImageEncode(void); \
  NS_IMETHOD GetImageBufferUsed(uint32_t *_retval); \
  NS_IMETHOD GetImageBuffer(char **_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMGIENCODER(_to) \
  NS_IMETHOD InitFromData(const uint8_t *data, uint32_t length, uint32_t width, uint32_t height, uint32_t stride, uint32_t inputFormat, const nsAString & outputOptions) { return _to InitFromData(data, length, width, height, stride, inputFormat, outputOptions); } \
  NS_IMETHOD StartImageEncode(uint32_t width, uint32_t height, uint32_t inputFormat, const nsAString & outputOptions) { return _to StartImageEncode(width, height, inputFormat, outputOptions); } \
  NS_IMETHOD AddImageFrame(const uint8_t *data, uint32_t length, uint32_t width, uint32_t height, uint32_t stride, uint32_t frameFormat, const nsAString & frameOptions) { return _to AddImageFrame(data, length, width, height, stride, frameFormat, frameOptions); } \
  NS_IMETHOD EndImageEncode(void) { return _to EndImageEncode(); } \
  NS_IMETHOD GetImageBufferUsed(uint32_t *_retval) { return _to GetImageBufferUsed(_retval); } \
  NS_IMETHOD GetImageBuffer(char **_retval) { return _to GetImageBuffer(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMGIENCODER(_to) \
  NS_IMETHOD InitFromData(const uint8_t *data, uint32_t length, uint32_t width, uint32_t height, uint32_t stride, uint32_t inputFormat, const nsAString & outputOptions) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitFromData(data, length, width, height, stride, inputFormat, outputOptions); } \
  NS_IMETHOD StartImageEncode(uint32_t width, uint32_t height, uint32_t inputFormat, const nsAString & outputOptions) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartImageEncode(width, height, inputFormat, outputOptions); } \
  NS_IMETHOD AddImageFrame(const uint8_t *data, uint32_t length, uint32_t width, uint32_t height, uint32_t stride, uint32_t frameFormat, const nsAString & frameOptions) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddImageFrame(data, length, width, height, stride, frameFormat, frameOptions); } \
  NS_IMETHOD EndImageEncode(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndImageEncode(); } \
  NS_IMETHOD GetImageBufferUsed(uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageBufferUsed(_retval); } \
  NS_IMETHOD GetImageBuffer(char **_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageBuffer(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public imgIEncoder
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMGIENCODER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, imgIEncoder)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void initFromData ([array, size_is (length), const] in uint8_t data, in unsigned long length, in uint32_t width, in uint32_t height, in uint32_t stride, in uint32_t inputFormat, in AString outputOptions); */
NS_IMETHODIMP _MYCLASS_::InitFromData(const uint8_t *data, uint32_t length, uint32_t width, uint32_t height, uint32_t stride, uint32_t inputFormat, const nsAString & outputOptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startImageEncode (in uint32_t width, in uint32_t height, in uint32_t inputFormat, in AString outputOptions); */
NS_IMETHODIMP _MYCLASS_::StartImageEncode(uint32_t width, uint32_t height, uint32_t inputFormat, const nsAString & outputOptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addImageFrame ([array, size_is (length), const] in uint8_t data, in unsigned long length, in uint32_t width, in uint32_t height, in uint32_t stride, in uint32_t frameFormat, in AString frameOptions); */
NS_IMETHODIMP _MYCLASS_::AddImageFrame(const uint8_t *data, uint32_t length, uint32_t width, uint32_t height, uint32_t stride, uint32_t frameFormat, const nsAString & frameOptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endImageEncode (); */
NS_IMETHODIMP _MYCLASS_::EndImageEncode()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] unsigned long getImageBufferUsed (); */
NS_IMETHODIMP _MYCLASS_::GetImageBufferUsed(uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] charPtr getImageBuffer (); */
NS_IMETHODIMP _MYCLASS_::GetImageBuffer(char **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_imgIEncoder_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\imgITools.idl
 */

#ifndef __gen_imgITools_h__
#define __gen_imgITools_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

class imgIContainer; /* forward declaration */

class imgILoader; /* forward declaration */

class imgICache; /* forward declaration */

class nsIDOMDocument; /* forward declaration */

class imgIScriptedNotificationObserver; /* forward declaration */

class imgINotificationObserver; /* forward declaration */


/* starting interface:    imgITools */
#define IMGITOOLS_IID_STR "4c2383a4-931c-484d-8c4a-973590f66e3f"

#define IMGITOOLS_IID \
  {0x4c2383a4, 0x931c, 0x484d, \
    { 0x8c, 0x4a, 0x97, 0x35, 0x90, 0xf6, 0x6e, 0x3f }}

class NS_NO_VTABLE imgITools : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMGITOOLS_IID)

  /* imgIContainer decodeImage (in nsIInputStream aStream, in ACString aMimeType); */
  NS_IMETHOD DecodeImage(nsIInputStream *aStream, const nsACString & aMimeType, imgIContainer * *_retval) = 0;

  /* [deprecated] void decodeImageData (in nsIInputStream aStream, in ACString aMimeType, inout imgIContainer aContainer); */
  NS_IMETHOD DecodeImageData(nsIInputStream *aStream, const nsACString & aMimeType, imgIContainer * *aContainer) = 0;

  /* nsIInputStream encodeImage (in imgIContainer aContainer, in ACString aMimeType, [optional] in AString outputOptions); */
  NS_IMETHOD EncodeImage(imgIContainer *aContainer, const nsACString & aMimeType, const nsAString & outputOptions, nsIInputStream * *_retval) = 0;

  /* nsIInputStream encodeScaledImage (in imgIContainer aContainer, in ACString aMimeType, in long aWidth, in long aHeight, [optional] in AString outputOptions); */
  NS_IMETHOD EncodeScaledImage(imgIContainer *aContainer, const nsACString & aMimeType, int32_t aWidth, int32_t aHeight, const nsAString & outputOptions, nsIInputStream * *_retval) = 0;

  /* imgILoader getImgLoaderForDocument (in nsIDOMDocument doc); */
  NS_IMETHOD GetImgLoaderForDocument(nsIDOMDocument *doc, imgILoader * *_retval) = 0;

  /* imgICache getImgCacheForDocument (in nsIDOMDocument doc); */
  NS_IMETHOD GetImgCacheForDocument(nsIDOMDocument *doc, imgICache * *_retval) = 0;

  /* nsIInputStream encodeCroppedImage (in imgIContainer aContainer, in ACString aMimeType, in long aOffsetX, in long aOffsetY, in long aWidth, in long aHeight, [optional] in AString outputOptions); */
  NS_IMETHOD EncodeCroppedImage(imgIContainer *aContainer, const nsACString & aMimeType, int32_t aOffsetX, int32_t aOffsetY, int32_t aWidth, int32_t aHeight, const nsAString & outputOptions, nsIInputStream * *_retval) = 0;

  /* imgINotificationObserver createScriptedObserver (in imgIScriptedNotificationObserver aObserver); */
  NS_IMETHOD CreateScriptedObserver(imgIScriptedNotificationObserver *aObserver, imgINotificationObserver * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(imgITools, IMGITOOLS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMGITOOLS \
  NS_IMETHOD DecodeImage(nsIInputStream *aStream, const nsACString & aMimeType, imgIContainer * *_retval); \
  NS_IMETHOD DecodeImageData(nsIInputStream *aStream, const nsACString & aMimeType, imgIContainer * *aContainer); \
  NS_IMETHOD EncodeImage(imgIContainer *aContainer, const nsACString & aMimeType, const nsAString & outputOptions, nsIInputStream * *_retval); \
  NS_IMETHOD EncodeScaledImage(imgIContainer *aContainer, const nsACString & aMimeType, int32_t aWidth, int32_t aHeight, const nsAString & outputOptions, nsIInputStream * *_retval); \
  NS_IMETHOD GetImgLoaderForDocument(nsIDOMDocument *doc, imgILoader * *_retval); \
  NS_IMETHOD GetImgCacheForDocument(nsIDOMDocument *doc, imgICache * *_retval); \
  NS_IMETHOD EncodeCroppedImage(imgIContainer *aContainer, const nsACString & aMimeType, int32_t aOffsetX, int32_t aOffsetY, int32_t aWidth, int32_t aHeight, const nsAString & outputOptions, nsIInputStream * *_retval); \
  NS_IMETHOD CreateScriptedObserver(imgIScriptedNotificationObserver *aObserver, imgINotificationObserver * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMGITOOLS(_to) \
  NS_IMETHOD DecodeImage(nsIInputStream *aStream, const nsACString & aMimeType, imgIContainer * *_retval) { return _to DecodeImage(aStream, aMimeType, _retval); } \
  NS_IMETHOD DecodeImageData(nsIInputStream *aStream, const nsACString & aMimeType, imgIContainer * *aContainer) { return _to DecodeImageData(aStream, aMimeType, aContainer); } \
  NS_IMETHOD EncodeImage(imgIContainer *aContainer, const nsACString & aMimeType, const nsAString & outputOptions, nsIInputStream * *_retval) { return _to EncodeImage(aContainer, aMimeType, outputOptions, _retval); } \
  NS_IMETHOD EncodeScaledImage(imgIContainer *aContainer, const nsACString & aMimeType, int32_t aWidth, int32_t aHeight, const nsAString & outputOptions, nsIInputStream * *_retval) { return _to EncodeScaledImage(aContainer, aMimeType, aWidth, aHeight, outputOptions, _retval); } \
  NS_IMETHOD GetImgLoaderForDocument(nsIDOMDocument *doc, imgILoader * *_retval) { return _to GetImgLoaderForDocument(doc, _retval); } \
  NS_IMETHOD GetImgCacheForDocument(nsIDOMDocument *doc, imgICache * *_retval) { return _to GetImgCacheForDocument(doc, _retval); } \
  NS_IMETHOD EncodeCroppedImage(imgIContainer *aContainer, const nsACString & aMimeType, int32_t aOffsetX, int32_t aOffsetY, int32_t aWidth, int32_t aHeight, const nsAString & outputOptions, nsIInputStream * *_retval) { return _to EncodeCroppedImage(aContainer, aMimeType, aOffsetX, aOffsetY, aWidth, aHeight, outputOptions, _retval); } \
  NS_IMETHOD CreateScriptedObserver(imgIScriptedNotificationObserver *aObserver, imgINotificationObserver * *_retval) { return _to CreateScriptedObserver(aObserver, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMGITOOLS(_to) \
  NS_IMETHOD DecodeImage(nsIInputStream *aStream, const nsACString & aMimeType, imgIContainer * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->DecodeImage(aStream, aMimeType, _retval); } \
  NS_IMETHOD DecodeImageData(nsIInputStream *aStream, const nsACString & aMimeType, imgIContainer * *aContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->DecodeImageData(aStream, aMimeType, aContainer); } \
  NS_IMETHOD EncodeImage(imgIContainer *aContainer, const nsACString & aMimeType, const nsAString & outputOptions, nsIInputStream * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EncodeImage(aContainer, aMimeType, outputOptions, _retval); } \
  NS_IMETHOD EncodeScaledImage(imgIContainer *aContainer, const nsACString & aMimeType, int32_t aWidth, int32_t aHeight, const nsAString & outputOptions, nsIInputStream * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EncodeScaledImage(aContainer, aMimeType, aWidth, aHeight, outputOptions, _retval); } \
  NS_IMETHOD GetImgLoaderForDocument(nsIDOMDocument *doc, imgILoader * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImgLoaderForDocument(doc, _retval); } \
  NS_IMETHOD GetImgCacheForDocument(nsIDOMDocument *doc, imgICache * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImgCacheForDocument(doc, _retval); } \
  NS_IMETHOD EncodeCroppedImage(imgIContainer *aContainer, const nsACString & aMimeType, int32_t aOffsetX, int32_t aOffsetY, int32_t aWidth, int32_t aHeight, const nsAString & outputOptions, nsIInputStream * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EncodeCroppedImage(aContainer, aMimeType, aOffsetX, aOffsetY, aWidth, aHeight, outputOptions, _retval); } \
  NS_IMETHOD CreateScriptedObserver(imgIScriptedNotificationObserver *aObserver, imgINotificationObserver * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateScriptedObserver(aObserver, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public imgITools
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMGITOOLS

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, imgITools)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* imgIContainer decodeImage (in nsIInputStream aStream, in ACString aMimeType); */
NS_IMETHODIMP _MYCLASS_::DecodeImage(nsIInputStream *aStream, const nsACString & aMimeType, imgIContainer * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [deprecated] void decodeImageData (in nsIInputStream aStream, in ACString aMimeType, inout imgIContainer aContainer); */
NS_IMETHODIMP _MYCLASS_::DecodeImageData(nsIInputStream *aStream, const nsACString & aMimeType, imgIContainer * *aContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream encodeImage (in imgIContainer aContainer, in ACString aMimeType, [optional] in AString outputOptions); */
NS_IMETHODIMP _MYCLASS_::EncodeImage(imgIContainer *aContainer, const nsACString & aMimeType, const nsAString & outputOptions, nsIInputStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream encodeScaledImage (in imgIContainer aContainer, in ACString aMimeType, in long aWidth, in long aHeight, [optional] in AString outputOptions); */
NS_IMETHODIMP _MYCLASS_::EncodeScaledImage(imgIContainer *aContainer, const nsACString & aMimeType, int32_t aWidth, int32_t aHeight, const nsAString & outputOptions, nsIInputStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* imgILoader getImgLoaderForDocument (in nsIDOMDocument doc); */
NS_IMETHODIMP _MYCLASS_::GetImgLoaderForDocument(nsIDOMDocument *doc, imgILoader * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* imgICache getImgCacheForDocument (in nsIDOMDocument doc); */
NS_IMETHODIMP _MYCLASS_::GetImgCacheForDocument(nsIDOMDocument *doc, imgICache * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream encodeCroppedImage (in imgIContainer aContainer, in ACString aMimeType, in long aOffsetX, in long aOffsetY, in long aWidth, in long aHeight, [optional] in AString outputOptions); */
NS_IMETHODIMP _MYCLASS_::EncodeCroppedImage(imgIContainer *aContainer, const nsACString & aMimeType, int32_t aOffsetX, int32_t aOffsetY, int32_t aWidth, int32_t aHeight, const nsAString & outputOptions, nsIInputStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* imgINotificationObserver createScriptedObserver (in imgIScriptedNotificationObserver aObserver); */
NS_IMETHODIMP _MYCLASS_::CreateScriptedObserver(imgIScriptedNotificationObserver *aObserver, imgINotificationObserver * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_imgITools_h__ */

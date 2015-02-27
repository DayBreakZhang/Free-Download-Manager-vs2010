/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIIconURI.idl
 */

#ifndef __gen_nsIIconURI_h__
#define __gen_nsIIconURI_h__


#ifndef __gen_nsIURL_h__
#include "nsIURL.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMozIconURI */
#define NS_IMOZICONURI_IID_STR "da53adda-cbe3-41bc-a57d-fdd7a0ff448b"

#define NS_IMOZICONURI_IID \
  {0xda53adda, 0xcbe3, 0x41bc, \
    { 0xa5, 0x7d, 0xfd, 0xd7, 0xa0, 0xff, 0x44, 0x8b }}

class NS_NO_VTABLE nsIMozIconURI : public nsIURI {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOZICONURI_IID)

  /* attribute nsIURL iconURL; */
  NS_IMETHOD GetIconURL(nsIURL * *aIconURL) = 0;
  NS_IMETHOD SetIconURL(nsIURL *aIconURL) = 0;

  /* attribute unsigned long imageSize; */
  NS_IMETHOD GetImageSize(uint32_t *aImageSize) = 0;
  NS_IMETHOD SetImageSize(uint32_t aImageSize) = 0;

  /* readonly attribute ACString stockIcon; */
  NS_IMETHOD GetStockIcon(nsACString & aStockIcon) = 0;

  /* readonly attribute ACString iconSize; */
  NS_IMETHOD GetIconSize(nsACString & aIconSize) = 0;

  /* readonly attribute ACString iconState; */
  NS_IMETHOD GetIconState(nsACString & aIconState) = 0;

  /* attribute ACString contentType; */
  NS_IMETHOD GetContentType(nsACString & aContentType) = 0;
  NS_IMETHOD SetContentType(const nsACString & aContentType) = 0;

  /* readonly attribute ACString fileExtension; */
  NS_IMETHOD GetFileExtension(nsACString & aFileExtension) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMozIconURI, NS_IMOZICONURI_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOZICONURI \
  NS_IMETHOD GetIconURL(nsIURL * *aIconURL); \
  NS_IMETHOD SetIconURL(nsIURL *aIconURL); \
  NS_IMETHOD GetImageSize(uint32_t *aImageSize); \
  NS_IMETHOD SetImageSize(uint32_t aImageSize); \
  NS_IMETHOD GetStockIcon(nsACString & aStockIcon); \
  NS_IMETHOD GetIconSize(nsACString & aIconSize); \
  NS_IMETHOD GetIconState(nsACString & aIconState); \
  NS_IMETHOD GetContentType(nsACString & aContentType); \
  NS_IMETHOD SetContentType(const nsACString & aContentType); \
  NS_IMETHOD GetFileExtension(nsACString & aFileExtension); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOZICONURI(_to) \
  NS_IMETHOD GetIconURL(nsIURL * *aIconURL) { return _to GetIconURL(aIconURL); } \
  NS_IMETHOD SetIconURL(nsIURL *aIconURL) { return _to SetIconURL(aIconURL); } \
  NS_IMETHOD GetImageSize(uint32_t *aImageSize) { return _to GetImageSize(aImageSize); } \
  NS_IMETHOD SetImageSize(uint32_t aImageSize) { return _to SetImageSize(aImageSize); } \
  NS_IMETHOD GetStockIcon(nsACString & aStockIcon) { return _to GetStockIcon(aStockIcon); } \
  NS_IMETHOD GetIconSize(nsACString & aIconSize) { return _to GetIconSize(aIconSize); } \
  NS_IMETHOD GetIconState(nsACString & aIconState) { return _to GetIconState(aIconState); } \
  NS_IMETHOD GetContentType(nsACString & aContentType) { return _to GetContentType(aContentType); } \
  NS_IMETHOD SetContentType(const nsACString & aContentType) { return _to SetContentType(aContentType); } \
  NS_IMETHOD GetFileExtension(nsACString & aFileExtension) { return _to GetFileExtension(aFileExtension); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOZICONURI(_to) \
  NS_IMETHOD GetIconURL(nsIURL * *aIconURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIconURL(aIconURL); } \
  NS_IMETHOD SetIconURL(nsIURL *aIconURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIconURL(aIconURL); } \
  NS_IMETHOD GetImageSize(uint32_t *aImageSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageSize(aImageSize); } \
  NS_IMETHOD SetImageSize(uint32_t aImageSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetImageSize(aImageSize); } \
  NS_IMETHOD GetStockIcon(nsACString & aStockIcon) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStockIcon(aStockIcon); } \
  NS_IMETHOD GetIconSize(nsACString & aIconSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIconSize(aIconSize); } \
  NS_IMETHOD GetIconState(nsACString & aIconState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIconState(aIconState); } \
  NS_IMETHOD GetContentType(nsACString & aContentType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentType(aContentType); } \
  NS_IMETHOD SetContentType(const nsACString & aContentType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentType(aContentType); } \
  NS_IMETHOD GetFileExtension(nsACString & aFileExtension) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileExtension(aFileExtension); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMozIconURI : public nsIMozIconURI
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOZICONURI

  nsMozIconURI();

private:
  ~nsMozIconURI();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMozIconURI, nsIMozIconURI)

nsMozIconURI::nsMozIconURI()
{
  /* member initializers and constructor code */
}

nsMozIconURI::~nsMozIconURI()
{
  /* destructor code */
}

/* attribute nsIURL iconURL; */
NS_IMETHODIMP nsMozIconURI::GetIconURL(nsIURL * *aIconURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMozIconURI::SetIconURL(nsIURL *aIconURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long imageSize; */
NS_IMETHODIMP nsMozIconURI::GetImageSize(uint32_t *aImageSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMozIconURI::SetImageSize(uint32_t aImageSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString stockIcon; */
NS_IMETHODIMP nsMozIconURI::GetStockIcon(nsACString & aStockIcon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString iconSize; */
NS_IMETHODIMP nsMozIconURI::GetIconSize(nsACString & aIconSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString iconState; */
NS_IMETHODIMP nsMozIconURI::GetIconState(nsACString & aIconState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString contentType; */
NS_IMETHODIMP nsMozIconURI::GetContentType(nsACString & aContentType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMozIconURI::SetContentType(const nsACString & aContentType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString fileExtension; */
NS_IMETHODIMP nsMozIconURI::GetFileExtension(nsACString & aFileExtension)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIconURI_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIUploadChannel.idl
 */

#ifndef __gen_nsIUploadChannel_h__
#define __gen_nsIUploadChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */


/* starting interface:    nsIUploadChannel */
#define NS_IUPLOADCHANNEL_IID_STR "5cfe15bd-5adb-4a7f-9e55-4f5a67d15794"

#define NS_IUPLOADCHANNEL_IID \
  {0x5cfe15bd, 0x5adb, 0x4a7f, \
    { 0x9e, 0x55, 0x4f, 0x5a, 0x67, 0xd1, 0x57, 0x94 }}

class NS_NO_VTABLE nsIUploadChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUPLOADCHANNEL_IID)

  /* void setUploadStream (in nsIInputStream aStream, in ACString aContentType, in long long aContentLength); */
  NS_IMETHOD SetUploadStream(nsIInputStream *aStream, const nsACString & aContentType, int64_t aContentLength) = 0;

  /* readonly attribute nsIInputStream uploadStream; */
  NS_IMETHOD GetUploadStream(nsIInputStream * *aUploadStream) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUploadChannel, NS_IUPLOADCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUPLOADCHANNEL \
  NS_IMETHOD SetUploadStream(nsIInputStream *aStream, const nsACString & aContentType, int64_t aContentLength); \
  NS_IMETHOD GetUploadStream(nsIInputStream * *aUploadStream); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUPLOADCHANNEL(_to) \
  NS_IMETHOD SetUploadStream(nsIInputStream *aStream, const nsACString & aContentType, int64_t aContentLength) { return _to SetUploadStream(aStream, aContentType, aContentLength); } \
  NS_IMETHOD GetUploadStream(nsIInputStream * *aUploadStream) { return _to GetUploadStream(aUploadStream); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUPLOADCHANNEL(_to) \
  NS_IMETHOD SetUploadStream(nsIInputStream *aStream, const nsACString & aContentType, int64_t aContentLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUploadStream(aStream, aContentType, aContentLength); } \
  NS_IMETHOD GetUploadStream(nsIInputStream * *aUploadStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUploadStream(aUploadStream); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUploadChannel : public nsIUploadChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUPLOADCHANNEL

  nsUploadChannel();

private:
  ~nsUploadChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUploadChannel, nsIUploadChannel)

nsUploadChannel::nsUploadChannel()
{
  /* member initializers and constructor code */
}

nsUploadChannel::~nsUploadChannel()
{
  /* destructor code */
}

/* void setUploadStream (in nsIInputStream aStream, in ACString aContentType, in long long aContentLength); */
NS_IMETHODIMP nsUploadChannel::SetUploadStream(nsIInputStream *aStream, const nsACString & aContentType, int64_t aContentLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIInputStream uploadStream; */
NS_IMETHODIMP nsUploadChannel::GetUploadStream(nsIInputStream * *aUploadStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUploadChannel_h__ */

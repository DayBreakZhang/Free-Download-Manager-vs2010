/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIUploadChannel2.idl
 */

#ifndef __gen_nsIUploadChannel2_h__
#define __gen_nsIUploadChannel2_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */


/* starting interface:    nsIUploadChannel2 */
#define NS_IUPLOADCHANNEL2_IID_STR "ad9d3f1c-a8de-4d0b-9714-1b922297ad65"

#define NS_IUPLOADCHANNEL2_IID \
  {0xad9d3f1c, 0xa8de, 0x4d0b, \
    { 0x97, 0x14, 0x1b, 0x92, 0x22, 0x97, 0xad, 0x65 }}

class NS_NO_VTABLE nsIUploadChannel2 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUPLOADCHANNEL2_IID)

  /* void explicitSetUploadStream (in nsIInputStream aStream, in ACString aContentType, in long long aContentLength, in ACString aMethod, in boolean aStreamHasHeaders); */
  NS_IMETHOD ExplicitSetUploadStream(nsIInputStream *aStream, const nsACString & aContentType, int64_t aContentLength, const nsACString & aMethod, bool aStreamHasHeaders) = 0;

  /* readonly attribute boolean uploadStreamHasHeaders; */
  NS_IMETHOD GetUploadStreamHasHeaders(bool *aUploadStreamHasHeaders) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUploadChannel2, NS_IUPLOADCHANNEL2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUPLOADCHANNEL2 \
  NS_IMETHOD ExplicitSetUploadStream(nsIInputStream *aStream, const nsACString & aContentType, int64_t aContentLength, const nsACString & aMethod, bool aStreamHasHeaders); \
  NS_IMETHOD GetUploadStreamHasHeaders(bool *aUploadStreamHasHeaders); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUPLOADCHANNEL2(_to) \
  NS_IMETHOD ExplicitSetUploadStream(nsIInputStream *aStream, const nsACString & aContentType, int64_t aContentLength, const nsACString & aMethod, bool aStreamHasHeaders) { return _to ExplicitSetUploadStream(aStream, aContentType, aContentLength, aMethod, aStreamHasHeaders); } \
  NS_IMETHOD GetUploadStreamHasHeaders(bool *aUploadStreamHasHeaders) { return _to GetUploadStreamHasHeaders(aUploadStreamHasHeaders); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUPLOADCHANNEL2(_to) \
  NS_IMETHOD ExplicitSetUploadStream(nsIInputStream *aStream, const nsACString & aContentType, int64_t aContentLength, const nsACString & aMethod, bool aStreamHasHeaders) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExplicitSetUploadStream(aStream, aContentType, aContentLength, aMethod, aStreamHasHeaders); } \
  NS_IMETHOD GetUploadStreamHasHeaders(bool *aUploadStreamHasHeaders) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUploadStreamHasHeaders(aUploadStreamHasHeaders); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUploadChannel2 : public nsIUploadChannel2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUPLOADCHANNEL2

  nsUploadChannel2();

private:
  ~nsUploadChannel2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUploadChannel2, nsIUploadChannel2)

nsUploadChannel2::nsUploadChannel2()
{
  /* member initializers and constructor code */
}

nsUploadChannel2::~nsUploadChannel2()
{
  /* destructor code */
}

/* void explicitSetUploadStream (in nsIInputStream aStream, in ACString aContentType, in long long aContentLength, in ACString aMethod, in boolean aStreamHasHeaders); */
NS_IMETHODIMP nsUploadChannel2::ExplicitSetUploadStream(nsIInputStream *aStream, const nsACString & aContentType, int64_t aContentLength, const nsACString & aMethod, bool aStreamHasHeaders)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean uploadStreamHasHeaders; */
NS_IMETHODIMP nsUploadChannel2::GetUploadStreamHasHeaders(bool *aUploadStreamHasHeaders)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUploadChannel2_h__ */

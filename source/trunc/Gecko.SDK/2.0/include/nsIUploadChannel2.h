/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/netwerk/base/public/nsIUploadChannel2.idl
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
#define NS_IUPLOADCHANNEL2_IID_STR "8821e259-7252-4464-b874-a55d8ef6b222"

#define NS_IUPLOADCHANNEL2_IID \
  {0x8821e259, 0x7252, 0x4464, \
    { 0xb8, 0x74, 0xa5, 0x5d, 0x8e, 0xf6, 0xb2, 0x22 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIUploadChannel2 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUPLOADCHANNEL2_IID)

  /**
     * Sets a stream to be uploaded by this channel with the specified
     * Content-Type and Content-Length header values.
     *
     * Most implementations of this interface require that the stream:
     *   (1) implement threadsafe addRef and release
     *   (2) implement nsIInputStream::readSegments
     *   (3) implement nsISeekableStream::seek
     *
     * @param aStream
     *        The stream to be uploaded by this channel.
     * @param aContentType
     *        This value will replace any existing Content-Type
     *        header on the HTTP request, regardless of whether
     *        or not its empty.
     * @param aContentLength
     *        A value of -1 indicates that the length of the stream should be
     *        determined by calling the stream's |available| method.
     * @param aMethod
     *        The HTTP request method to set on the stream.
     * @param aStreamHasHeaders
     *        True if the stream already contains headers for the HTTP request.
     */
  /* void explicitSetUploadStream (in nsIInputStream aStream, in ACString aContentType, in long long aContentLength, in ACString aMethod, in boolean aStreamHasHeaders); */
  NS_SCRIPTABLE NS_IMETHOD ExplicitSetUploadStream(nsIInputStream *aStream, const nsACString & aContentType, PRInt64 aContentLength, const nsACString & aMethod, PRBool aStreamHasHeaders) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUploadChannel2, NS_IUPLOADCHANNEL2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUPLOADCHANNEL2 \
  NS_SCRIPTABLE NS_IMETHOD ExplicitSetUploadStream(nsIInputStream *aStream, const nsACString & aContentType, PRInt64 aContentLength, const nsACString & aMethod, PRBool aStreamHasHeaders); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUPLOADCHANNEL2(_to) \
  NS_SCRIPTABLE NS_IMETHOD ExplicitSetUploadStream(nsIInputStream *aStream, const nsACString & aContentType, PRInt64 aContentLength, const nsACString & aMethod, PRBool aStreamHasHeaders) { return _to ExplicitSetUploadStream(aStream, aContentType, aContentLength, aMethod, aStreamHasHeaders); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUPLOADCHANNEL2(_to) \
  NS_SCRIPTABLE NS_IMETHOD ExplicitSetUploadStream(nsIInputStream *aStream, const nsACString & aContentType, PRInt64 aContentLength, const nsACString & aMethod, PRBool aStreamHasHeaders) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExplicitSetUploadStream(aStream, aContentType, aContentLength, aMethod, aStreamHasHeaders); } 

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
NS_IMETHODIMP nsUploadChannel2::ExplicitSetUploadStream(nsIInputStream *aStream, const nsACString & aContentType, PRInt64 aContentLength, const nsACString & aMethod, PRBool aStreamHasHeaders)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUploadChannel2_h__ */

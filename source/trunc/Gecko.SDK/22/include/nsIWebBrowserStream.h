/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/embedding/browser/webBrowser/nsIWebBrowserStream.idl
 */

#ifndef __gen_nsIWebBrowserStream_h__
#define __gen_nsIWebBrowserStream_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsIWebBrowserStream */
#define NS_IWEBBROWSERSTREAM_IID_STR "86d02f0e-219b-4cfc-9c88-bd98d2cce0b8"

#define NS_IWEBBROWSERSTREAM_IID \
  {0x86d02f0e, 0x219b, 0x4cfc, \
    { 0x9c, 0x88, 0xbd, 0x98, 0xd2, 0xcc, 0xe0, 0xb8 }}

class NS_NO_VTABLE nsIWebBrowserStream : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBBROWSERSTREAM_IID)

  /* void openStream (in nsIURI aBaseURI, in ACString aContentType); */
  NS_IMETHOD OpenStream(nsIURI *aBaseURI, const nsACString & aContentType) = 0;

  /* void appendToStream ([array, size_is (aLen), const] in octet aData, in unsigned long aLen); */
  NS_IMETHOD AppendToStream(const uint8_t *aData, uint32_t aLen) = 0;

  /* void closeStream (); */
  NS_IMETHOD CloseStream(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebBrowserStream, NS_IWEBBROWSERSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBBROWSERSTREAM \
  NS_IMETHOD OpenStream(nsIURI *aBaseURI, const nsACString & aContentType); \
  NS_IMETHOD AppendToStream(const uint8_t *aData, uint32_t aLen); \
  NS_IMETHOD CloseStream(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBBROWSERSTREAM(_to) \
  NS_IMETHOD OpenStream(nsIURI *aBaseURI, const nsACString & aContentType) { return _to OpenStream(aBaseURI, aContentType); } \
  NS_IMETHOD AppendToStream(const uint8_t *aData, uint32_t aLen) { return _to AppendToStream(aData, aLen); } \
  NS_IMETHOD CloseStream(void) { return _to CloseStream(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBBROWSERSTREAM(_to) \
  NS_IMETHOD OpenStream(nsIURI *aBaseURI, const nsACString & aContentType) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenStream(aBaseURI, aContentType); } \
  NS_IMETHOD AppendToStream(const uint8_t *aData, uint32_t aLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendToStream(aData, aLen); } \
  NS_IMETHOD CloseStream(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloseStream(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebBrowserStream : public nsIWebBrowserStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBBROWSERSTREAM

  nsWebBrowserStream();

private:
  ~nsWebBrowserStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebBrowserStream, nsIWebBrowserStream)

nsWebBrowserStream::nsWebBrowserStream()
{
  /* member initializers and constructor code */
}

nsWebBrowserStream::~nsWebBrowserStream()
{
  /* destructor code */
}

/* void openStream (in nsIURI aBaseURI, in ACString aContentType); */
NS_IMETHODIMP nsWebBrowserStream::OpenStream(nsIURI *aBaseURI, const nsACString & aContentType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void appendToStream ([array, size_is (aLen), const] in octet aData, in unsigned long aLen); */
NS_IMETHODIMP nsWebBrowserStream::AppendToStream(const uint8_t *aData, uint32_t aLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void closeStream (); */
NS_IMETHODIMP nsWebBrowserStream::CloseStream()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebBrowserStream_h__ */

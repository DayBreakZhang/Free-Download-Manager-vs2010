/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/streamconv/public/nsIStreamConverter.idl
 */

#ifndef __gen_nsIStreamConverter_h__
#define __gen_nsIStreamConverter_h__


#ifndef __gen_nsIStreamListener_h__
#include "nsIStreamListener.h"
#endif

#ifndef __gen_nsIInputStream_h__
#include "nsIInputStream.h"
#endif

#ifndef __gen_nsIURI_h__
#include "nsIURI.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIStreamConverter */
#define NS_ISTREAMCONVERTER_IID_STR "0b6e2c69-5cf5-48b0-9dfd-c95950e2cc7b"

#define NS_ISTREAMCONVERTER_IID \
  {0x0b6e2c69, 0x5cf5, 0x48b0, \
    { 0x9d, 0xfd, 0xc9, 0x59, 0x50, 0xe2, 0xcc, 0x7b }}

class NS_NO_VTABLE nsIStreamConverter : public nsIStreamListener {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTREAMCONVERTER_IID)

  /* nsIInputStream convert (in nsIInputStream aFromStream, in string aFromType, in string aToType, in nsISupports aCtxt); */
  NS_IMETHOD Convert(nsIInputStream *aFromStream, const char * aFromType, const char * aToType, nsISupports *aCtxt, nsIInputStream * *_retval) = 0;

  /* void asyncConvertData (in string aFromType, in string aToType, in nsIStreamListener aListener, in nsISupports aCtxt); */
  NS_IMETHOD AsyncConvertData(const char * aFromType, const char * aToType, nsIStreamListener *aListener, nsISupports *aCtxt) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStreamConverter, NS_ISTREAMCONVERTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTREAMCONVERTER \
  NS_IMETHOD Convert(nsIInputStream *aFromStream, const char * aFromType, const char * aToType, nsISupports *aCtxt, nsIInputStream * *_retval); \
  NS_IMETHOD AsyncConvertData(const char * aFromType, const char * aToType, nsIStreamListener *aListener, nsISupports *aCtxt); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTREAMCONVERTER(_to) \
  NS_IMETHOD Convert(nsIInputStream *aFromStream, const char * aFromType, const char * aToType, nsISupports *aCtxt, nsIInputStream * *_retval) { return _to Convert(aFromStream, aFromType, aToType, aCtxt, _retval); } \
  NS_IMETHOD AsyncConvertData(const char * aFromType, const char * aToType, nsIStreamListener *aListener, nsISupports *aCtxt) { return _to AsyncConvertData(aFromType, aToType, aListener, aCtxt); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTREAMCONVERTER(_to) \
  NS_IMETHOD Convert(nsIInputStream *aFromStream, const char * aFromType, const char * aToType, nsISupports *aCtxt, nsIInputStream * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Convert(aFromStream, aFromType, aToType, aCtxt, _retval); } \
  NS_IMETHOD AsyncConvertData(const char * aFromType, const char * aToType, nsIStreamListener *aListener, nsISupports *aCtxt) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncConvertData(aFromType, aToType, aListener, aCtxt); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStreamConverter : public nsIStreamConverter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTREAMCONVERTER

  nsStreamConverter();

private:
  ~nsStreamConverter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStreamConverter, nsIStreamConverter)

nsStreamConverter::nsStreamConverter()
{
  /* member initializers and constructor code */
}

nsStreamConverter::~nsStreamConverter()
{
  /* destructor code */
}

/* nsIInputStream convert (in nsIInputStream aFromStream, in string aFromType, in string aToType, in nsISupports aCtxt); */
NS_IMETHODIMP nsStreamConverter::Convert(nsIInputStream *aFromStream, const char * aFromType, const char * aToType, nsISupports *aCtxt, nsIInputStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncConvertData (in string aFromType, in string aToType, in nsIStreamListener aListener, in nsISupports aCtxt); */
NS_IMETHODIMP nsStreamConverter::AsyncConvertData(const char * aFromType, const char * aToType, nsIStreamListener *aListener, nsISupports *aCtxt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_ISTREAMCONVERTER_KEY         "@mozilla.org/streamconv;1"

#endif /* __gen_nsIStreamConverter_h__ */

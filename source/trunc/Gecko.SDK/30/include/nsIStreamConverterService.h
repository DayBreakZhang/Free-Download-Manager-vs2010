/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIStreamConverterService.idl
 */

#ifndef __gen_nsIStreamConverterService_h__
#define __gen_nsIStreamConverterService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

class nsIStreamListener; /* forward declaration */

#define NS_ISTREAMCONVERTER_KEY         "@mozilla.org/streamconv;1"

/* starting interface:    nsIStreamConverterService */
#define NS_ISTREAMCONVERTERSERVICE_IID_STR "f2b1ab53-f0bd-4adb-9365-e59b1701a258"

#define NS_ISTREAMCONVERTERSERVICE_IID \
  {0xf2b1ab53, 0xf0bd, 0x4adb, \
    { 0x93, 0x65, 0xe5, 0x9b, 0x17, 0x01, 0xa2, 0x58 }}

class NS_NO_VTABLE nsIStreamConverterService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTREAMCONVERTERSERVICE_IID)

  /* boolean canConvert (in string aFromType, in string aToType); */
  NS_IMETHOD CanConvert(const char * aFromType, const char * aToType, bool *_retval) = 0;

  /* nsIInputStream convert (in nsIInputStream aFromStream, in string aFromType, in string aToType, in nsISupports aContext); */
  NS_IMETHOD Convert(nsIInputStream *aFromStream, const char * aFromType, const char * aToType, nsISupports *aContext, nsIInputStream * *_retval) = 0;

  /* nsIStreamListener asyncConvertData (in string aFromType, in string aToType, in nsIStreamListener aListener, in nsISupports aContext); */
  NS_IMETHOD AsyncConvertData(const char * aFromType, const char * aToType, nsIStreamListener *aListener, nsISupports *aContext, nsIStreamListener * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStreamConverterService, NS_ISTREAMCONVERTERSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTREAMCONVERTERSERVICE \
  NS_IMETHOD CanConvert(const char * aFromType, const char * aToType, bool *_retval); \
  NS_IMETHOD Convert(nsIInputStream *aFromStream, const char * aFromType, const char * aToType, nsISupports *aContext, nsIInputStream * *_retval); \
  NS_IMETHOD AsyncConvertData(const char * aFromType, const char * aToType, nsIStreamListener *aListener, nsISupports *aContext, nsIStreamListener * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTREAMCONVERTERSERVICE(_to) \
  NS_IMETHOD CanConvert(const char * aFromType, const char * aToType, bool *_retval) { return _to CanConvert(aFromType, aToType, _retval); } \
  NS_IMETHOD Convert(nsIInputStream *aFromStream, const char * aFromType, const char * aToType, nsISupports *aContext, nsIInputStream * *_retval) { return _to Convert(aFromStream, aFromType, aToType, aContext, _retval); } \
  NS_IMETHOD AsyncConvertData(const char * aFromType, const char * aToType, nsIStreamListener *aListener, nsISupports *aContext, nsIStreamListener * *_retval) { return _to AsyncConvertData(aFromType, aToType, aListener, aContext, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTREAMCONVERTERSERVICE(_to) \
  NS_IMETHOD CanConvert(const char * aFromType, const char * aToType, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanConvert(aFromType, aToType, _retval); } \
  NS_IMETHOD Convert(nsIInputStream *aFromStream, const char * aFromType, const char * aToType, nsISupports *aContext, nsIInputStream * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Convert(aFromStream, aFromType, aToType, aContext, _retval); } \
  NS_IMETHOD AsyncConvertData(const char * aFromType, const char * aToType, nsIStreamListener *aListener, nsISupports *aContext, nsIStreamListener * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncConvertData(aFromType, aToType, aListener, aContext, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStreamConverterService : public nsIStreamConverterService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTREAMCONVERTERSERVICE

  nsStreamConverterService();

private:
  ~nsStreamConverterService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStreamConverterService, nsIStreamConverterService)

nsStreamConverterService::nsStreamConverterService()
{
  /* member initializers and constructor code */
}

nsStreamConverterService::~nsStreamConverterService()
{
  /* destructor code */
}

/* boolean canConvert (in string aFromType, in string aToType); */
NS_IMETHODIMP nsStreamConverterService::CanConvert(const char * aFromType, const char * aToType, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream convert (in nsIInputStream aFromStream, in string aFromType, in string aToType, in nsISupports aContext); */
NS_IMETHODIMP nsStreamConverterService::Convert(nsIInputStream *aFromStream, const char * aFromType, const char * aToType, nsISupports *aContext, nsIInputStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIStreamListener asyncConvertData (in string aFromType, in string aToType, in nsIStreamListener aListener, in nsISupports aContext); */
NS_IMETHODIMP nsStreamConverterService::AsyncConvertData(const char * aFromType, const char * aToType, nsIStreamListener *aListener, nsISupports *aContext, nsIStreamListener * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStreamConverterService_h__ */

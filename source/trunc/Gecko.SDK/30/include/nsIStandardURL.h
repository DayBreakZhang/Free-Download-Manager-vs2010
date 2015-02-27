/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIStandardURL.idl
 */

#ifndef __gen_nsIStandardURL_h__
#define __gen_nsIStandardURL_h__


#ifndef __gen_nsIMutable_h__
#include "nsIMutable.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsIStandardURL */
#define NS_ISTANDARDURL_IID_STR "babd6cca-ebe7-4329-967c-d6b9e33caa81"

#define NS_ISTANDARDURL_IID \
  {0xbabd6cca, 0xebe7, 0x4329, \
    { 0x96, 0x7c, 0xd6, 0xb9, 0xe3, 0x3c, 0xaa, 0x81 }}

class NS_NO_VTABLE nsIStandardURL : public nsIMutable {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTANDARDURL_IID)

  enum {
    URLTYPE_STANDARD = 1U,
    URLTYPE_AUTHORITY = 2U,
    URLTYPE_NO_AUTHORITY = 3U
  };

  /* void init (in unsigned long aUrlType, in long aDefaultPort, in AUTF8String aSpec, in string aOriginCharset, in nsIURI aBaseURI); */
  NS_IMETHOD Init(uint32_t aUrlType, int32_t aDefaultPort, const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStandardURL, NS_ISTANDARDURL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTANDARDURL \
  NS_IMETHOD Init(uint32_t aUrlType, int32_t aDefaultPort, const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTANDARDURL(_to) \
  NS_IMETHOD Init(uint32_t aUrlType, int32_t aDefaultPort, const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI) { return _to Init(aUrlType, aDefaultPort, aSpec, aOriginCharset, aBaseURI); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTANDARDURL(_to) \
  NS_IMETHOD Init(uint32_t aUrlType, int32_t aDefaultPort, const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aUrlType, aDefaultPort, aSpec, aOriginCharset, aBaseURI); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStandardURL : public nsIStandardURL
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTANDARDURL

  nsStandardURL();

private:
  ~nsStandardURL();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStandardURL, nsIStandardURL)

nsStandardURL::nsStandardURL()
{
  /* member initializers and constructor code */
}

nsStandardURL::~nsStandardURL()
{
  /* destructor code */
}

/* void init (in unsigned long aUrlType, in long aDefaultPort, in AUTF8String aSpec, in string aOriginCharset, in nsIURI aBaseURI); */
NS_IMETHODIMP nsStandardURL::Init(uint32_t aUrlType, int32_t aDefaultPort, const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStandardURL_h__ */

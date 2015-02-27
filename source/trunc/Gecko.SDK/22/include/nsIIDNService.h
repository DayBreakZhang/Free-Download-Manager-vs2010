/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/dns/nsIIDNService.idl
 */

#ifndef __gen_nsIIDNService_h__
#define __gen_nsIIDNService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIIDNService */
#define NS_IIDNSERVICE_IID_STR "a592a60e-3621-4f19-a318-2bf233cfad3e"

#define NS_IIDNSERVICE_IID \
  {0xa592a60e, 0x3621, 0x4f19, \
    { 0xa3, 0x18, 0x2b, 0xf2, 0x33, 0xcf, 0xad, 0x3e }}

class NS_NO_VTABLE nsIIDNService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDNSERVICE_IID)

  /* ACString convertUTF8toACE (in AUTF8String input); */
  NS_IMETHOD ConvertUTF8toACE(const nsACString & input, nsACString & _retval) = 0;

  /* AUTF8String convertACEtoUTF8 (in ACString input); */
  NS_IMETHOD ConvertACEtoUTF8(const nsACString & input, nsACString & _retval) = 0;

  /* boolean isACE (in ACString input); */
  NS_IMETHOD IsACE(const nsACString & input, bool *_retval) = 0;

  /* AUTF8String normalize (in AUTF8String input); */
  NS_IMETHOD Normalize(const nsACString & input, nsACString & _retval) = 0;

  /* AUTF8String convertToDisplayIDN (in AUTF8String input, out boolean isASCII); */
  NS_IMETHOD ConvertToDisplayIDN(const nsACString & input, bool *isASCII, nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDNService, NS_IIDNSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDNSERVICE \
  NS_IMETHOD ConvertUTF8toACE(const nsACString & input, nsACString & _retval); \
  NS_IMETHOD ConvertACEtoUTF8(const nsACString & input, nsACString & _retval); \
  NS_IMETHOD IsACE(const nsACString & input, bool *_retval); \
  NS_IMETHOD Normalize(const nsACString & input, nsACString & _retval); \
  NS_IMETHOD ConvertToDisplayIDN(const nsACString & input, bool *isASCII, nsACString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDNSERVICE(_to) \
  NS_IMETHOD ConvertUTF8toACE(const nsACString & input, nsACString & _retval) { return _to ConvertUTF8toACE(input, _retval); } \
  NS_IMETHOD ConvertACEtoUTF8(const nsACString & input, nsACString & _retval) { return _to ConvertACEtoUTF8(input, _retval); } \
  NS_IMETHOD IsACE(const nsACString & input, bool *_retval) { return _to IsACE(input, _retval); } \
  NS_IMETHOD Normalize(const nsACString & input, nsACString & _retval) { return _to Normalize(input, _retval); } \
  NS_IMETHOD ConvertToDisplayIDN(const nsACString & input, bool *isASCII, nsACString & _retval) { return _to ConvertToDisplayIDN(input, isASCII, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDNSERVICE(_to) \
  NS_IMETHOD ConvertUTF8toACE(const nsACString & input, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConvertUTF8toACE(input, _retval); } \
  NS_IMETHOD ConvertACEtoUTF8(const nsACString & input, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConvertACEtoUTF8(input, _retval); } \
  NS_IMETHOD IsACE(const nsACString & input, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsACE(input, _retval); } \
  NS_IMETHOD Normalize(const nsACString & input, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Normalize(input, _retval); } \
  NS_IMETHOD ConvertToDisplayIDN(const nsACString & input, bool *isASCII, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConvertToDisplayIDN(input, isASCII, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIDNService : public nsIIDNService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDNSERVICE

  nsIDNService();

private:
  ~nsIDNService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIDNService, nsIIDNService)

nsIDNService::nsIDNService()
{
  /* member initializers and constructor code */
}

nsIDNService::~nsIDNService()
{
  /* destructor code */
}

/* ACString convertUTF8toACE (in AUTF8String input); */
NS_IMETHODIMP nsIDNService::ConvertUTF8toACE(const nsACString & input, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String convertACEtoUTF8 (in ACString input); */
NS_IMETHODIMP nsIDNService::ConvertACEtoUTF8(const nsACString & input, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isACE (in ACString input); */
NS_IMETHODIMP nsIDNService::IsACE(const nsACString & input, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String normalize (in AUTF8String input); */
NS_IMETHODIMP nsIDNService::Normalize(const nsACString & input, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String convertToDisplayIDN (in AUTF8String input, out boolean isASCII); */
NS_IMETHODIMP nsIDNService::ConvertToDisplayIDN(const nsACString & input, bool *isASCII, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDNService_h__ */

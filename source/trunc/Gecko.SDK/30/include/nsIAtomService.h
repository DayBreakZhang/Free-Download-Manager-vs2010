/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAtomService.idl
 */

#ifndef __gen_nsIAtomService_h__
#define __gen_nsIAtomService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAtom; /* forward declaration */

#define NS_ATOMSERVICE_CID \
{ /* ed3db3fc-0168-4cab-8818-98f5475a490c */ \
    0xed3db3fc,                              \
    0x0168,                                  \
    0x4cab,                                  \
    {0x88, 0x18, 0x98, 0xf5, 0x47, 0x5a, 0x49, 0x0c} }
#define NS_ATOMSERVICE_CONTRACTID "@mozilla.org/atom-service;1"

/* starting interface:    nsIAtomService */
#define NS_IATOMSERVICE_IID_STR "9c1f50b9-f9eb-42d4-a8cb-2c7600aeb241"

#define NS_IATOMSERVICE_IID \
  {0x9c1f50b9, 0xf9eb, 0x42d4, \
    { 0xa8, 0xcb, 0x2c, 0x76, 0x00, 0xae, 0xb2, 0x41 }}

class NS_NO_VTABLE nsIAtomService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IATOMSERVICE_IID)

  /* nsIAtom getAtom (in AString value); */
  NS_IMETHOD GetAtom(const nsAString & value, nsIAtom * *_retval) = 0;

  /* nsIAtom getPermanentAtom (in AString value); */
  NS_IMETHOD GetPermanentAtom(const nsAString & value, nsIAtom * *_retval) = 0;

  /* [noscript] nsIAtom getAtomUTF8 (in string value); */
  NS_IMETHOD GetAtomUTF8(const char * value, nsIAtom * *_retval) = 0;

  /* [noscript] nsIAtom getPermanentAtomUTF8 (in string value); */
  NS_IMETHOD GetPermanentAtomUTF8(const char * value, nsIAtom * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAtomService, NS_IATOMSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIATOMSERVICE \
  NS_IMETHOD GetAtom(const nsAString & value, nsIAtom * *_retval); \
  NS_IMETHOD GetPermanentAtom(const nsAString & value, nsIAtom * *_retval); \
  NS_IMETHOD GetAtomUTF8(const char * value, nsIAtom * *_retval); \
  NS_IMETHOD GetPermanentAtomUTF8(const char * value, nsIAtom * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIATOMSERVICE(_to) \
  NS_IMETHOD GetAtom(const nsAString & value, nsIAtom * *_retval) { return _to GetAtom(value, _retval); } \
  NS_IMETHOD GetPermanentAtom(const nsAString & value, nsIAtom * *_retval) { return _to GetPermanentAtom(value, _retval); } \
  NS_IMETHOD GetAtomUTF8(const char * value, nsIAtom * *_retval) { return _to GetAtomUTF8(value, _retval); } \
  NS_IMETHOD GetPermanentAtomUTF8(const char * value, nsIAtom * *_retval) { return _to GetPermanentAtomUTF8(value, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIATOMSERVICE(_to) \
  NS_IMETHOD GetAtom(const nsAString & value, nsIAtom * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAtom(value, _retval); } \
  NS_IMETHOD GetPermanentAtom(const nsAString & value, nsIAtom * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPermanentAtom(value, _retval); } \
  NS_IMETHOD GetAtomUTF8(const char * value, nsIAtom * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAtomUTF8(value, _retval); } \
  NS_IMETHOD GetPermanentAtomUTF8(const char * value, nsIAtom * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPermanentAtomUTF8(value, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAtomService : public nsIAtomService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIATOMSERVICE

  nsAtomService();

private:
  ~nsAtomService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAtomService, nsIAtomService)

nsAtomService::nsAtomService()
{
  /* member initializers and constructor code */
}

nsAtomService::~nsAtomService()
{
  /* destructor code */
}

/* nsIAtom getAtom (in AString value); */
NS_IMETHODIMP nsAtomService::GetAtom(const nsAString & value, nsIAtom * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAtom getPermanentAtom (in AString value); */
NS_IMETHODIMP nsAtomService::GetPermanentAtom(const nsAString & value, nsIAtom * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIAtom getAtomUTF8 (in string value); */
NS_IMETHODIMP nsAtomService::GetAtomUTF8(const char * value, nsIAtom * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIAtom getPermanentAtomUTF8 (in string value); */
NS_IMETHODIMP nsAtomService::GetPermanentAtomUTF8(const char * value, nsIAtom * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAtomService_h__ */

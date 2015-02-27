/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/base/nsIUUIDGenerator.idl
 */

#ifndef __gen_nsIUUIDGenerator_h__
#define __gen_nsIUUIDGenerator_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIUUIDGenerator */
#define NS_IUUIDGENERATOR_IID_STR "138ad1b2-c694-41cc-b201-333ce936d8b8"

#define NS_IUUIDGENERATOR_IID \
  {0x138ad1b2, 0xc694, 0x41cc, \
    { 0xb2, 0x01, 0x33, 0x3c, 0xe9, 0x36, 0xd8, 0xb8 }}

class NS_NO_VTABLE nsIUUIDGenerator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUUIDGENERATOR_IID)

  /* nsIDPtr generateUUID (); */
  NS_IMETHOD GenerateUUID(nsID **_retval) = 0;

  /* [noscript] void generateUUIDInPlace (in nsNonConstIDPtr id); */
  NS_IMETHOD GenerateUUIDInPlace(nsID *id) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUUIDGenerator, NS_IUUIDGENERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUUIDGENERATOR \
  NS_IMETHOD GenerateUUID(nsID **_retval); \
  NS_IMETHOD GenerateUUIDInPlace(nsID *id); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUUIDGENERATOR(_to) \
  NS_IMETHOD GenerateUUID(nsID **_retval) { return _to GenerateUUID(_retval); } \
  NS_IMETHOD GenerateUUIDInPlace(nsID *id) { return _to GenerateUUIDInPlace(id); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUUIDGENERATOR(_to) \
  NS_IMETHOD GenerateUUID(nsID **_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GenerateUUID(_retval); } \
  NS_IMETHOD GenerateUUIDInPlace(nsID *id) { return !_to ? NS_ERROR_NULL_POINTER : _to->GenerateUUIDInPlace(id); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUUIDGenerator : public nsIUUIDGenerator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUUIDGENERATOR

  nsUUIDGenerator();

private:
  ~nsUUIDGenerator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUUIDGenerator, nsIUUIDGenerator)

nsUUIDGenerator::nsUUIDGenerator()
{
  /* member initializers and constructor code */
}

nsUUIDGenerator::~nsUUIDGenerator()
{
  /* destructor code */
}

/* nsIDPtr generateUUID (); */
NS_IMETHODIMP nsUUIDGenerator::GenerateUUID(nsID **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void generateUUIDInPlace (in nsNonConstIDPtr id); */
NS_IMETHODIMP nsUUIDGenerator::GenerateUUIDInPlace(nsID *id)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUUIDGenerator_h__ */

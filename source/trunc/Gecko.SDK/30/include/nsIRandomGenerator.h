/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIRandomGenerator.idl
 */

#ifndef __gen_nsIRandomGenerator_h__
#define __gen_nsIRandomGenerator_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRandomGenerator */
#define NS_IRANDOMGENERATOR_IID_STR "2362d97a-747a-4576-8863-697667309209"

#define NS_IRANDOMGENERATOR_IID \
  {0x2362d97a, 0x747a, 0x4576, \
    { 0x88, 0x63, 0x69, 0x76, 0x67, 0x30, 0x92, 0x09 }}

class NS_NO_VTABLE nsIRandomGenerator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRANDOMGENERATOR_IID)

  /* void generateRandomBytes (in unsigned long aLength, [array, size_is (aLength), retval] out octet aBuffer); */
  NS_IMETHOD GenerateRandomBytes(uint32_t aLength, uint8_t **aBuffer) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRandomGenerator, NS_IRANDOMGENERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRANDOMGENERATOR \
  NS_IMETHOD GenerateRandomBytes(uint32_t aLength, uint8_t **aBuffer); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRANDOMGENERATOR(_to) \
  NS_IMETHOD GenerateRandomBytes(uint32_t aLength, uint8_t **aBuffer) { return _to GenerateRandomBytes(aLength, aBuffer); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRANDOMGENERATOR(_to) \
  NS_IMETHOD GenerateRandomBytes(uint32_t aLength, uint8_t **aBuffer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GenerateRandomBytes(aLength, aBuffer); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRandomGenerator : public nsIRandomGenerator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRANDOMGENERATOR

  nsRandomGenerator();

private:
  ~nsRandomGenerator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRandomGenerator, nsIRandomGenerator)

nsRandomGenerator::nsRandomGenerator()
{
  /* member initializers and constructor code */
}

nsRandomGenerator::~nsRandomGenerator()
{
  /* destructor code */
}

/* void generateRandomBytes (in unsigned long aLength, [array, size_is (aLength), retval] out octet aBuffer); */
NS_IMETHODIMP nsRandomGenerator::GenerateRandomBytes(uint32_t aLength, uint8_t **aBuffer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRandomGenerator_h__ */

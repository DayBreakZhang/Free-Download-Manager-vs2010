/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIStreamCipher.idl
 */

#ifndef __gen_nsIStreamCipher_h__
#define __gen_nsIStreamCipher_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIKeyModule_h__
#include "nsIKeyModule.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */


/* starting interface:    nsIStreamCipher */
#define NS_ISTREAMCIPHER_IID_STR "1d507cd6-1630-4710-af1b-4012dbcc514c"

#define NS_ISTREAMCIPHER_IID \
  {0x1d507cd6, 0x1630, 0x4710, \
    { 0xaf, 0x1b, 0x40, 0x12, 0xdb, 0xcc, 0x51, 0x4c }}

class NS_NO_VTABLE nsIStreamCipher : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTREAMCIPHER_IID)

  /* void init (in nsIKeyObject aKey); */
  NS_IMETHOD Init(nsIKeyObject *aKey) = 0;

  /* void initWithIV (in nsIKeyObject aKey, [array, size_is (aIVLen), const] in octet aIV, in unsigned long aIVLen); */
  NS_IMETHOD InitWithIV(nsIKeyObject *aKey, const uint8_t *aIV, uint32_t aIVLen) = 0;

  /* void update ([array, size_is (aLen), const] in octet aData, in unsigned long aLen); */
  NS_IMETHOD Update(const uint8_t *aData, uint32_t aLen) = 0;

  /* void updateFromStream (in nsIInputStream aStream, in long aLen); */
  NS_IMETHOD UpdateFromStream(nsIInputStream *aStream, int32_t aLen) = 0;

  /* void updateFromString (in ACString aInput); */
  NS_IMETHOD UpdateFromString(const nsACString & aInput) = 0;

  /* ACString finish (in boolean aASCII); */
  NS_IMETHOD Finish(bool aASCII, nsACString & _retval) = 0;

  /* void discard (in long aLen); */
  NS_IMETHOD Discard(int32_t aLen) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStreamCipher, NS_ISTREAMCIPHER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTREAMCIPHER \
  NS_IMETHOD Init(nsIKeyObject *aKey); \
  NS_IMETHOD InitWithIV(nsIKeyObject *aKey, const uint8_t *aIV, uint32_t aIVLen); \
  NS_IMETHOD Update(const uint8_t *aData, uint32_t aLen); \
  NS_IMETHOD UpdateFromStream(nsIInputStream *aStream, int32_t aLen); \
  NS_IMETHOD UpdateFromString(const nsACString & aInput); \
  NS_IMETHOD Finish(bool aASCII, nsACString & _retval); \
  NS_IMETHOD Discard(int32_t aLen); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTREAMCIPHER(_to) \
  NS_IMETHOD Init(nsIKeyObject *aKey) { return _to Init(aKey); } \
  NS_IMETHOD InitWithIV(nsIKeyObject *aKey, const uint8_t *aIV, uint32_t aIVLen) { return _to InitWithIV(aKey, aIV, aIVLen); } \
  NS_IMETHOD Update(const uint8_t *aData, uint32_t aLen) { return _to Update(aData, aLen); } \
  NS_IMETHOD UpdateFromStream(nsIInputStream *aStream, int32_t aLen) { return _to UpdateFromStream(aStream, aLen); } \
  NS_IMETHOD UpdateFromString(const nsACString & aInput) { return _to UpdateFromString(aInput); } \
  NS_IMETHOD Finish(bool aASCII, nsACString & _retval) { return _to Finish(aASCII, _retval); } \
  NS_IMETHOD Discard(int32_t aLen) { return _to Discard(aLen); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTREAMCIPHER(_to) \
  NS_IMETHOD Init(nsIKeyObject *aKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aKey); } \
  NS_IMETHOD InitWithIV(nsIKeyObject *aKey, const uint8_t *aIV, uint32_t aIVLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitWithIV(aKey, aIV, aIVLen); } \
  NS_IMETHOD Update(const uint8_t *aData, uint32_t aLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->Update(aData, aLen); } \
  NS_IMETHOD UpdateFromStream(nsIInputStream *aStream, int32_t aLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateFromStream(aStream, aLen); } \
  NS_IMETHOD UpdateFromString(const nsACString & aInput) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateFromString(aInput); } \
  NS_IMETHOD Finish(bool aASCII, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Finish(aASCII, _retval); } \
  NS_IMETHOD Discard(int32_t aLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->Discard(aLen); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStreamCipher : public nsIStreamCipher
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTREAMCIPHER

  nsStreamCipher();

private:
  ~nsStreamCipher();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStreamCipher, nsIStreamCipher)

nsStreamCipher::nsStreamCipher()
{
  /* member initializers and constructor code */
}

nsStreamCipher::~nsStreamCipher()
{
  /* destructor code */
}

/* void init (in nsIKeyObject aKey); */
NS_IMETHODIMP nsStreamCipher::Init(nsIKeyObject *aKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initWithIV (in nsIKeyObject aKey, [array, size_is (aIVLen), const] in octet aIV, in unsigned long aIVLen); */
NS_IMETHODIMP nsStreamCipher::InitWithIV(nsIKeyObject *aKey, const uint8_t *aIV, uint32_t aIVLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void update ([array, size_is (aLen), const] in octet aData, in unsigned long aLen); */
NS_IMETHODIMP nsStreamCipher::Update(const uint8_t *aData, uint32_t aLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateFromStream (in nsIInputStream aStream, in long aLen); */
NS_IMETHODIMP nsStreamCipher::UpdateFromStream(nsIInputStream *aStream, int32_t aLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateFromString (in ACString aInput); */
NS_IMETHODIMP nsStreamCipher::UpdateFromString(const nsACString & aInput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString finish (in boolean aASCII); */
NS_IMETHODIMP nsStreamCipher::Finish(bool aASCII, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void discard (in long aLen); */
NS_IMETHODIMP nsStreamCipher::Discard(int32_t aLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStreamCipher_h__ */

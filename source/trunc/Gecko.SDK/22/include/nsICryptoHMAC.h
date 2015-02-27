/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsICryptoHMAC.idl
 */

#ifndef __gen_nsICryptoHMAC_h__
#define __gen_nsICryptoHMAC_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

class nsIKeyObject; /* forward declaration */


/* starting interface:    nsICryptoHMAC */
#define NS_ICRYPTOHMAC_IID_STR "8feb4c7c-1641-4a7b-bc6d-1964e2099497"

#define NS_ICRYPTOHMAC_IID \
  {0x8feb4c7c, 0x1641, 0x4a7b, \
    { 0xbc, 0x6d, 0x19, 0x64, 0xe2, 0x09, 0x94, 0x97 }}

class NS_NO_VTABLE nsICryptoHMAC : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICRYPTOHMAC_IID)

  enum {
    MD2 = 1,
    MD5 = 2,
    SHA1 = 3,
    SHA256 = 4,
    SHA384 = 5,
    SHA512 = 6
  };

  /* void init (in unsigned long aAlgorithm, in nsIKeyObject aKeyObject); */
  NS_IMETHOD Init(uint32_t aAlgorithm, nsIKeyObject *aKeyObject) = 0;

  /* void update ([array, size_is (aLen), const] in octet aData, in unsigned long aLen); */
  NS_IMETHOD Update(const uint8_t *aData, uint32_t aLen) = 0;

  /* void updateFromStream (in nsIInputStream aStream, in unsigned long aLen); */
  NS_IMETHOD UpdateFromStream(nsIInputStream *aStream, uint32_t aLen) = 0;

  /* ACString finish (in boolean aASCII); */
  NS_IMETHOD Finish(bool aASCII, nsACString & _retval) = 0;

  /* void reset (); */
  NS_IMETHOD Reset(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICryptoHMAC, NS_ICRYPTOHMAC_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICRYPTOHMAC \
  NS_IMETHOD Init(uint32_t aAlgorithm, nsIKeyObject *aKeyObject); \
  NS_IMETHOD Update(const uint8_t *aData, uint32_t aLen); \
  NS_IMETHOD UpdateFromStream(nsIInputStream *aStream, uint32_t aLen); \
  NS_IMETHOD Finish(bool aASCII, nsACString & _retval); \
  NS_IMETHOD Reset(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICRYPTOHMAC(_to) \
  NS_IMETHOD Init(uint32_t aAlgorithm, nsIKeyObject *aKeyObject) { return _to Init(aAlgorithm, aKeyObject); } \
  NS_IMETHOD Update(const uint8_t *aData, uint32_t aLen) { return _to Update(aData, aLen); } \
  NS_IMETHOD UpdateFromStream(nsIInputStream *aStream, uint32_t aLen) { return _to UpdateFromStream(aStream, aLen); } \
  NS_IMETHOD Finish(bool aASCII, nsACString & _retval) { return _to Finish(aASCII, _retval); } \
  NS_IMETHOD Reset(void) { return _to Reset(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICRYPTOHMAC(_to) \
  NS_IMETHOD Init(uint32_t aAlgorithm, nsIKeyObject *aKeyObject) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aAlgorithm, aKeyObject); } \
  NS_IMETHOD Update(const uint8_t *aData, uint32_t aLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->Update(aData, aLen); } \
  NS_IMETHOD UpdateFromStream(nsIInputStream *aStream, uint32_t aLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateFromStream(aStream, aLen); } \
  NS_IMETHOD Finish(bool aASCII, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Finish(aASCII, _retval); } \
  NS_IMETHOD Reset(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Reset(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCryptoHMAC : public nsICryptoHMAC
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICRYPTOHMAC

  nsCryptoHMAC();

private:
  ~nsCryptoHMAC();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCryptoHMAC, nsICryptoHMAC)

nsCryptoHMAC::nsCryptoHMAC()
{
  /* member initializers and constructor code */
}

nsCryptoHMAC::~nsCryptoHMAC()
{
  /* destructor code */
}

/* void init (in unsigned long aAlgorithm, in nsIKeyObject aKeyObject); */
NS_IMETHODIMP nsCryptoHMAC::Init(uint32_t aAlgorithm, nsIKeyObject *aKeyObject)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void update ([array, size_is (aLen), const] in octet aData, in unsigned long aLen); */
NS_IMETHODIMP nsCryptoHMAC::Update(const uint8_t *aData, uint32_t aLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateFromStream (in nsIInputStream aStream, in unsigned long aLen); */
NS_IMETHODIMP nsCryptoHMAC::UpdateFromStream(nsIInputStream *aStream, uint32_t aLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString finish (in boolean aASCII); */
NS_IMETHODIMP nsCryptoHMAC::Finish(bool aASCII, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reset (); */
NS_IMETHODIMP nsCryptoHMAC::Reset()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICryptoHMAC_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsICryptoHash.idl
 */

#ifndef __gen_nsICryptoHash_h__
#define __gen_nsICryptoHash_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */


/* starting interface:    nsICryptoHash */
#define NS_ICRYPTOHASH_IID_STR "1e5b7c43-4688-45ce-92e1-77ed931e3bbe"

#define NS_ICRYPTOHASH_IID \
  {0x1e5b7c43, 0x4688, 0x45ce, \
    { 0x92, 0xe1, 0x77, 0xed, 0x93, 0x1e, 0x3b, 0xbe }}

class NS_NO_VTABLE nsICryptoHash : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICRYPTOHASH_IID)

  enum {
    MD2 = 1,
    MD5 = 2,
    SHA1 = 3,
    SHA256 = 4,
    SHA384 = 5,
    SHA512 = 6
  };

  /* void init (in unsigned long aAlgorithm); */
  NS_IMETHOD Init(uint32_t aAlgorithm) = 0;

  /* void initWithString (in ACString aAlgorithm); */
  NS_IMETHOD InitWithString(const nsACString & aAlgorithm) = 0;

  /* void update ([array, size_is (aLen), const] in octet aData, in unsigned long aLen); */
  NS_IMETHOD Update(const uint8_t *aData, uint32_t aLen) = 0;

  /* void updateFromStream (in nsIInputStream aStream, in unsigned long aLen); */
  NS_IMETHOD UpdateFromStream(nsIInputStream *aStream, uint32_t aLen) = 0;

  /* ACString finish (in boolean aASCII); */
  NS_IMETHOD Finish(bool aASCII, nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICryptoHash, NS_ICRYPTOHASH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICRYPTOHASH \
  NS_IMETHOD Init(uint32_t aAlgorithm); \
  NS_IMETHOD InitWithString(const nsACString & aAlgorithm); \
  NS_IMETHOD Update(const uint8_t *aData, uint32_t aLen); \
  NS_IMETHOD UpdateFromStream(nsIInputStream *aStream, uint32_t aLen); \
  NS_IMETHOD Finish(bool aASCII, nsACString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICRYPTOHASH(_to) \
  NS_IMETHOD Init(uint32_t aAlgorithm) { return _to Init(aAlgorithm); } \
  NS_IMETHOD InitWithString(const nsACString & aAlgorithm) { return _to InitWithString(aAlgorithm); } \
  NS_IMETHOD Update(const uint8_t *aData, uint32_t aLen) { return _to Update(aData, aLen); } \
  NS_IMETHOD UpdateFromStream(nsIInputStream *aStream, uint32_t aLen) { return _to UpdateFromStream(aStream, aLen); } \
  NS_IMETHOD Finish(bool aASCII, nsACString & _retval) { return _to Finish(aASCII, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICRYPTOHASH(_to) \
  NS_IMETHOD Init(uint32_t aAlgorithm) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aAlgorithm); } \
  NS_IMETHOD InitWithString(const nsACString & aAlgorithm) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitWithString(aAlgorithm); } \
  NS_IMETHOD Update(const uint8_t *aData, uint32_t aLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->Update(aData, aLen); } \
  NS_IMETHOD UpdateFromStream(nsIInputStream *aStream, uint32_t aLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateFromStream(aStream, aLen); } \
  NS_IMETHOD Finish(bool aASCII, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Finish(aASCII, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCryptoHash : public nsICryptoHash
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICRYPTOHASH

  nsCryptoHash();

private:
  ~nsCryptoHash();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCryptoHash, nsICryptoHash)

nsCryptoHash::nsCryptoHash()
{
  /* member initializers and constructor code */
}

nsCryptoHash::~nsCryptoHash()
{
  /* destructor code */
}

/* void init (in unsigned long aAlgorithm); */
NS_IMETHODIMP nsCryptoHash::Init(uint32_t aAlgorithm)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initWithString (in ACString aAlgorithm); */
NS_IMETHODIMP nsCryptoHash::InitWithString(const nsACString & aAlgorithm)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void update ([array, size_is (aLen), const] in octet aData, in unsigned long aLen); */
NS_IMETHODIMP nsCryptoHash::Update(const uint8_t *aData, uint32_t aLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateFromStream (in nsIInputStream aStream, in unsigned long aLen); */
NS_IMETHODIMP nsCryptoHash::UpdateFromStream(nsIInputStream *aStream, uint32_t aLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString finish (in boolean aASCII); */
NS_IMETHODIMP nsCryptoHash::Finish(bool aASCII, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICryptoHash_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISyncJPAKE.idl
 */

#ifndef __gen_nsISyncJPAKE_h__
#define __gen_nsISyncJPAKE_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISyncJPAKE */
#define NS_ISYNCJPAKE_IID_STR "5ab02a98-5122-4b90-93cd-f259c4b42e3a"

#define NS_ISYNCJPAKE_IID \
  {0x5ab02a98, 0x5122, 0x4b90, \
    { 0x93, 0xcd, 0xf2, 0x59, 0xc4, 0xb4, 0x2e, 0x3a }}

class NS_NO_VTABLE nsISyncJPAKE : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISYNCJPAKE_IID)

  /* void round1 (in ACString aSignerID, out ACString aGX1, out ACString aGV1, out ACString aR1, out ACString aGX2, out ACString aGV2, out ACString aR2); */
  NS_IMETHOD Round1(const nsACString & aSignerID, nsACString & aGX1, nsACString & aGV1, nsACString & aR1, nsACString & aGX2, nsACString & aGV2, nsACString & aR2) = 0;

  /* void round2 (in ACString aPeerID, in ACString aPIN, in ACString aGX3, in ACString aGV3, in ACString aR3, in ACString aGX4, in ACString aGV4, in ACString aR4, out ACString aA, out ACString aGVA, out ACString aRA); */
  NS_IMETHOD Round2(const nsACString & aPeerID, const nsACString & aPIN, const nsACString & aGX3, const nsACString & aGV3, const nsACString & aR3, const nsACString & aGX4, const nsACString & aGV4, const nsACString & aR4, nsACString & aA, nsACString & aGVA, nsACString & aRA) = 0;

  /* void final (in ACString aB, in ACString aGVB, in ACString aRB, in ACString aHkdfInfo, out ACString aAES256Key, out ACString aHMAC256Key); */
  NS_IMETHOD Final(const nsACString & aB, const nsACString & aGVB, const nsACString & aRB, const nsACString & aHkdfInfo, nsACString & aAES256Key, nsACString & aHMAC256Key) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISyncJPAKE, NS_ISYNCJPAKE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISYNCJPAKE \
  NS_IMETHOD Round1(const nsACString & aSignerID, nsACString & aGX1, nsACString & aGV1, nsACString & aR1, nsACString & aGX2, nsACString & aGV2, nsACString & aR2); \
  NS_IMETHOD Round2(const nsACString & aPeerID, const nsACString & aPIN, const nsACString & aGX3, const nsACString & aGV3, const nsACString & aR3, const nsACString & aGX4, const nsACString & aGV4, const nsACString & aR4, nsACString & aA, nsACString & aGVA, nsACString & aRA); \
  NS_IMETHOD Final(const nsACString & aB, const nsACString & aGVB, const nsACString & aRB, const nsACString & aHkdfInfo, nsACString & aAES256Key, nsACString & aHMAC256Key); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISYNCJPAKE(_to) \
  NS_IMETHOD Round1(const nsACString & aSignerID, nsACString & aGX1, nsACString & aGV1, nsACString & aR1, nsACString & aGX2, nsACString & aGV2, nsACString & aR2) { return _to Round1(aSignerID, aGX1, aGV1, aR1, aGX2, aGV2, aR2); } \
  NS_IMETHOD Round2(const nsACString & aPeerID, const nsACString & aPIN, const nsACString & aGX3, const nsACString & aGV3, const nsACString & aR3, const nsACString & aGX4, const nsACString & aGV4, const nsACString & aR4, nsACString & aA, nsACString & aGVA, nsACString & aRA) { return _to Round2(aPeerID, aPIN, aGX3, aGV3, aR3, aGX4, aGV4, aR4, aA, aGVA, aRA); } \
  NS_IMETHOD Final(const nsACString & aB, const nsACString & aGVB, const nsACString & aRB, const nsACString & aHkdfInfo, nsACString & aAES256Key, nsACString & aHMAC256Key) { return _to Final(aB, aGVB, aRB, aHkdfInfo, aAES256Key, aHMAC256Key); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISYNCJPAKE(_to) \
  NS_IMETHOD Round1(const nsACString & aSignerID, nsACString & aGX1, nsACString & aGV1, nsACString & aR1, nsACString & aGX2, nsACString & aGV2, nsACString & aR2) { return !_to ? NS_ERROR_NULL_POINTER : _to->Round1(aSignerID, aGX1, aGV1, aR1, aGX2, aGV2, aR2); } \
  NS_IMETHOD Round2(const nsACString & aPeerID, const nsACString & aPIN, const nsACString & aGX3, const nsACString & aGV3, const nsACString & aR3, const nsACString & aGX4, const nsACString & aGV4, const nsACString & aR4, nsACString & aA, nsACString & aGVA, nsACString & aRA) { return !_to ? NS_ERROR_NULL_POINTER : _to->Round2(aPeerID, aPIN, aGX3, aGV3, aR3, aGX4, aGV4, aR4, aA, aGVA, aRA); } \
  NS_IMETHOD Final(const nsACString & aB, const nsACString & aGVB, const nsACString & aRB, const nsACString & aHkdfInfo, nsACString & aAES256Key, nsACString & aHMAC256Key) { return !_to ? NS_ERROR_NULL_POINTER : _to->Final(aB, aGVB, aRB, aHkdfInfo, aAES256Key, aHMAC256Key); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSyncJPAKE : public nsISyncJPAKE
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISYNCJPAKE

  nsSyncJPAKE();

private:
  ~nsSyncJPAKE();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSyncJPAKE, nsISyncJPAKE)

nsSyncJPAKE::nsSyncJPAKE()
{
  /* member initializers and constructor code */
}

nsSyncJPAKE::~nsSyncJPAKE()
{
  /* destructor code */
}

/* void round1 (in ACString aSignerID, out ACString aGX1, out ACString aGV1, out ACString aR1, out ACString aGX2, out ACString aGV2, out ACString aR2); */
NS_IMETHODIMP nsSyncJPAKE::Round1(const nsACString & aSignerID, nsACString & aGX1, nsACString & aGV1, nsACString & aR1, nsACString & aGX2, nsACString & aGV2, nsACString & aR2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void round2 (in ACString aPeerID, in ACString aPIN, in ACString aGX3, in ACString aGV3, in ACString aR3, in ACString aGX4, in ACString aGV4, in ACString aR4, out ACString aA, out ACString aGVA, out ACString aRA); */
NS_IMETHODIMP nsSyncJPAKE::Round2(const nsACString & aPeerID, const nsACString & aPIN, const nsACString & aGX3, const nsACString & aGV3, const nsACString & aR3, const nsACString & aGX4, const nsACString & aGV4, const nsACString & aR4, nsACString & aA, nsACString & aGVA, nsACString & aRA)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void final (in ACString aB, in ACString aGVB, in ACString aRB, in ACString aHkdfInfo, out ACString aAES256Key, out ACString aHMAC256Key); */
NS_IMETHODIMP nsSyncJPAKE::Final(const nsACString & aB, const nsACString & aGVB, const nsACString & aRB, const nsACString & aHkdfInfo, nsACString & aAES256Key, nsACString & aHMAC256Key)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISyncJPAKE_h__ */

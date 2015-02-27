/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/services/crypto/component/nsISyncJPAKE.idl
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

class NS_NO_VTABLE NS_SCRIPTABLE nsISyncJPAKE : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISYNCJPAKE_IID)

  /**
   * Perform first round of the JPAKE exchange.
   *
   * @param aSignerID
   *        String identifying the signer.
   * @param aGX1
   *        Schnorr signature value g^x1, in hex representation.
   * @param aGV1
   *        Schnorr signature value g^v1 (v1 is a random value), in hex
   *        representation.
   * @param aR1
   *        Schnorr signature value r1 = v1 - x1 * h, in hex representation.
   * @param aGX2
   *        Schnorr signature value g^x2, in hex representation.
   * @param aGV2
   *        Schnorr signature value g^v2 (v2 is a random value), in hex
   *        representation.
   * @param aR2
   *        Schnorr signature value r2 = v2 - x2 * h, in hex representation.
   */
  /* void round1 (in ACString aSignerID, out ACString aGX1, out ACString aGV1, out ACString aR1, out ACString aGX2, out ACString aGV2, out ACString aR2); */
  NS_SCRIPTABLE NS_IMETHOD Round1(const nsACString & aSignerID, nsACString & aGX1 NS_OUTPARAM, nsACString & aGV1 NS_OUTPARAM, nsACString & aR1 NS_OUTPARAM, nsACString & aGX2 NS_OUTPARAM, nsACString & aGV2 NS_OUTPARAM, nsACString & aR2 NS_OUTPARAM) = 0;

  /**
   * Perform second round of the JPAKE exchange.
   *
   * @param aPeerID
   *        String identifying the peer.
   * @param aPIN
   *        String containing the weak secret (PIN).
   * @param aGX3
   *        Schnorr signature value g^x3, in hex representation.
   * @param aGV3
   *        Schnorr signature value g^v3 (v3 is a random value), in hex
   *        representation.
   * @param aR3
   *        Schnorr signature value r3 = v3 - x3 * h, in hex representation.
   * @param aGX4
   *        Schnorr signature value g^x4, in hex representation.
   * @param aGV4
   *        Schnorr signature value g^v4 (v4 is a random value), in hex
   *        representation.
   * @param aR4
   *        Schnorr signature value r4 = v4 - x4 * h, in hex representation.
   * @param aA
   *        Schnorr signature value A, in hex representation.
   * @param aGVA
   *        Schnorr signature value g^va (va is a random value), in hex
   *        representation.
   * @param aRA
   *        Schnorr signature value ra = va - xa * h, in hex representation.
   */
  /* void round2 (in ACString aPeerID, in ACString aPIN, in ACString aGX3, in ACString aGV3, in ACString aR3, in ACString aGX4, in ACString aGV4, in ACString aR4, out ACString aA, out ACString aGVA, out ACString aRA); */
  NS_SCRIPTABLE NS_IMETHOD Round2(const nsACString & aPeerID, const nsACString & aPIN, const nsACString & aGX3, const nsACString & aGV3, const nsACString & aR3, const nsACString & aGX4, const nsACString & aGV4, const nsACString & aR4, nsACString & aA NS_OUTPARAM, nsACString & aGVA NS_OUTPARAM, nsACString & aRA NS_OUTPARAM) = 0;

  /**
   * Perform the final step of the JPAKE exchange. This will compute
   * the key and expand the key to two keys, an AES256 encryption key
   * and a 256 bit HMAC key. It returns a key confirmation value
   * (SHA256d of the key) and the encryption and HMAC keys.
   *
   * @param aB
   *        Schnorr signature value B, in hex representation.
   * @param aGVB
   *        Schnorr signature value g^vb (vb is a random value), in hex
   *        representation.
   * @param aRB
   *        Schnorr signature value rb = vb - xb * h, in hex representation.
   * @param aAES256Key
   *        The AES 256 encryption key, in base64 representation.
   * @param aHMAC256Key
   *        The 256 bit HMAC key, in base64 representation.
   */
  /* void final (in ACString aB, in ACString aGVB, in ACString aRB, in ACString aHkdfInfo, out ACString aAES256Key, out ACString aHMAC256Key); */
  NS_SCRIPTABLE NS_IMETHOD Final(const nsACString & aB, const nsACString & aGVB, const nsACString & aRB, const nsACString & aHkdfInfo, nsACString & aAES256Key NS_OUTPARAM, nsACString & aHMAC256Key NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISyncJPAKE, NS_ISYNCJPAKE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISYNCJPAKE \
  NS_SCRIPTABLE NS_IMETHOD Round1(const nsACString & aSignerID, nsACString & aGX1 NS_OUTPARAM, nsACString & aGV1 NS_OUTPARAM, nsACString & aR1 NS_OUTPARAM, nsACString & aGX2 NS_OUTPARAM, nsACString & aGV2 NS_OUTPARAM, nsACString & aR2 NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Round2(const nsACString & aPeerID, const nsACString & aPIN, const nsACString & aGX3, const nsACString & aGV3, const nsACString & aR3, const nsACString & aGX4, const nsACString & aGV4, const nsACString & aR4, nsACString & aA NS_OUTPARAM, nsACString & aGVA NS_OUTPARAM, nsACString & aRA NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Final(const nsACString & aB, const nsACString & aGVB, const nsACString & aRB, const nsACString & aHkdfInfo, nsACString & aAES256Key NS_OUTPARAM, nsACString & aHMAC256Key NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISYNCJPAKE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Round1(const nsACString & aSignerID, nsACString & aGX1 NS_OUTPARAM, nsACString & aGV1 NS_OUTPARAM, nsACString & aR1 NS_OUTPARAM, nsACString & aGX2 NS_OUTPARAM, nsACString & aGV2 NS_OUTPARAM, nsACString & aR2 NS_OUTPARAM) { return _to Round1(aSignerID, aGX1, aGV1, aR1, aGX2, aGV2, aR2); } \
  NS_SCRIPTABLE NS_IMETHOD Round2(const nsACString & aPeerID, const nsACString & aPIN, const nsACString & aGX3, const nsACString & aGV3, const nsACString & aR3, const nsACString & aGX4, const nsACString & aGV4, const nsACString & aR4, nsACString & aA NS_OUTPARAM, nsACString & aGVA NS_OUTPARAM, nsACString & aRA NS_OUTPARAM) { return _to Round2(aPeerID, aPIN, aGX3, aGV3, aR3, aGX4, aGV4, aR4, aA, aGVA, aRA); } \
  NS_SCRIPTABLE NS_IMETHOD Final(const nsACString & aB, const nsACString & aGVB, const nsACString & aRB, const nsACString & aHkdfInfo, nsACString & aAES256Key NS_OUTPARAM, nsACString & aHMAC256Key NS_OUTPARAM) { return _to Final(aB, aGVB, aRB, aHkdfInfo, aAES256Key, aHMAC256Key); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISYNCJPAKE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Round1(const nsACString & aSignerID, nsACString & aGX1 NS_OUTPARAM, nsACString & aGV1 NS_OUTPARAM, nsACString & aR1 NS_OUTPARAM, nsACString & aGX2 NS_OUTPARAM, nsACString & aGV2 NS_OUTPARAM, nsACString & aR2 NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Round1(aSignerID, aGX1, aGV1, aR1, aGX2, aGV2, aR2); } \
  NS_SCRIPTABLE NS_IMETHOD Round2(const nsACString & aPeerID, const nsACString & aPIN, const nsACString & aGX3, const nsACString & aGV3, const nsACString & aR3, const nsACString & aGX4, const nsACString & aGV4, const nsACString & aR4, nsACString & aA NS_OUTPARAM, nsACString & aGVA NS_OUTPARAM, nsACString & aRA NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Round2(aPeerID, aPIN, aGX3, aGV3, aR3, aGX4, aGV4, aR4, aA, aGVA, aRA); } \
  NS_SCRIPTABLE NS_IMETHOD Final(const nsACString & aB, const nsACString & aGVB, const nsACString & aRB, const nsACString & aHkdfInfo, nsACString & aAES256Key NS_OUTPARAM, nsACString & aHMAC256Key NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Final(aB, aGVB, aRB, aHkdfInfo, aAES256Key, aHMAC256Key); } 

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
NS_IMETHODIMP nsSyncJPAKE::Round1(const nsACString & aSignerID, nsACString & aGX1 NS_OUTPARAM, nsACString & aGV1 NS_OUTPARAM, nsACString & aR1 NS_OUTPARAM, nsACString & aGX2 NS_OUTPARAM, nsACString & aGV2 NS_OUTPARAM, nsACString & aR2 NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void round2 (in ACString aPeerID, in ACString aPIN, in ACString aGX3, in ACString aGV3, in ACString aR3, in ACString aGX4, in ACString aGV4, in ACString aR4, out ACString aA, out ACString aGVA, out ACString aRA); */
NS_IMETHODIMP nsSyncJPAKE::Round2(const nsACString & aPeerID, const nsACString & aPIN, const nsACString & aGX3, const nsACString & aGV3, const nsACString & aR3, const nsACString & aGX4, const nsACString & aGV4, const nsACString & aR4, nsACString & aA NS_OUTPARAM, nsACString & aGVA NS_OUTPARAM, nsACString & aRA NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void final (in ACString aB, in ACString aGVB, in ACString aRB, in ACString aHkdfInfo, out ACString aAES256Key, out ACString aHMAC256Key); */
NS_IMETHODIMP nsSyncJPAKE::Final(const nsACString & aB, const nsACString & aGVB, const nsACString & aRB, const nsACString & aHkdfInfo, nsACString & aAES256Key NS_OUTPARAM, nsACString & aHMAC256Key NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISyncJPAKE_h__ */

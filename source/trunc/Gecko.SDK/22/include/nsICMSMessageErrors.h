/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/security/manager/ssl/public/nsICMSMessageErrors.idl
 */

#ifndef __gen_nsICMSMessageErrors_h__
#define __gen_nsICMSMessageErrors_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsICMSMessageErrors */
#define NS_ICMSMESSAGEERRORS_IID_STR "f2aec680-60a0-49f0-afe5-6cf1d3f15e0d"

#define NS_ICMSMESSAGEERRORS_IID \
  {0xf2aec680, 0x60a0, 0x49f0, \
    { 0xaf, 0xe5, 0x6c, 0xf1, 0xd3, 0xf1, 0x5e, 0x0d }}

class NS_NO_VTABLE nsICMSMessageErrors : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICMSMESSAGEERRORS_IID)

  enum {
    SUCCESS = 0,
    GENERAL_ERROR = 1,
    VERIFY_NOT_SIGNED = 1024,
    VERIFY_NO_CONTENT_INFO = 1025,
    VERIFY_BAD_DIGEST = 1026,
    VERIFY_NOCERT = 1028,
    VERIFY_UNTRUSTED = 1029,
    VERIFY_ERROR_UNVERIFIED = 1031,
    VERIFY_ERROR_PROCESSING = 1032,
    VERIFY_BAD_SIGNATURE = 1033,
    VERIFY_DIGEST_MISMATCH = 1034,
    VERIFY_UNKNOWN_ALGO = 1035,
    VERIFY_UNSUPPORTED_ALGO = 1036,
    VERIFY_MALFORMED_SIGNATURE = 1037,
    VERIFY_HEADER_MISMATCH = 1038,
    VERIFY_NOT_YET_ATTEMPTED = 1039,
    VERIFY_CERT_WITHOUT_ADDRESS = 1040,
    ENCRYPT_NO_BULK_ALG = 1056,
    ENCRYPT_INCOMPLETE = 1057
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICMSMessageErrors, NS_ICMSMESSAGEERRORS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICMSMESSAGEERRORS \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICMSMESSAGEERRORS(_to) \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICMSMESSAGEERRORS(_to) \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCMSMessageErrors : public nsICMSMessageErrors
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICMSMESSAGEERRORS

  nsCMSMessageErrors();

private:
  ~nsCMSMessageErrors();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCMSMessageErrors, nsICMSMessageErrors)

nsCMSMessageErrors::nsCMSMessageErrors()
{
  /* member initializers and constructor code */
}

nsCMSMessageErrors::~nsCMSMessageErrors()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICMSMessageErrors_h__ */

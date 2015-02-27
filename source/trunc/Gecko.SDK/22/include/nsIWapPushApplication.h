/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/mms/interfaces/nsIWapPushApplication.idl
 */

#ifndef __gen_nsIWapPushApplication_h__
#define __gen_nsIWapPushApplication_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIWapPushApplication */
#define NS_IWAPPUSHAPPLICATION_IID_STR "fd6f7f6b-a67e-4892-930d-fca864df8fe7"

#define NS_IWAPPUSHAPPLICATION_IID \
  {0xfd6f7f6b, 0xa67e, 0x4892, \
    { 0x93, 0x0d, 0xfc, 0xa8, 0x64, 0xdf, 0x8f, 0xe7 }}

class NS_NO_VTABLE nsIWapPushApplication : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWAPPUSHAPPLICATION_IID)

  /* void receiveWapPush ([array, size_is (aLength)] in octet aData, in unsigned long aLength, in unsigned long aOffset, in jsval aOptions); */
  NS_IMETHOD ReceiveWapPush(uint8_t *aData, uint32_t aLength, uint32_t aOffset, const JS::Value & aOptions) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWapPushApplication, NS_IWAPPUSHAPPLICATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWAPPUSHAPPLICATION \
  NS_IMETHOD ReceiveWapPush(uint8_t *aData, uint32_t aLength, uint32_t aOffset, const JS::Value & aOptions); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWAPPUSHAPPLICATION(_to) \
  NS_IMETHOD ReceiveWapPush(uint8_t *aData, uint32_t aLength, uint32_t aOffset, const JS::Value & aOptions) { return _to ReceiveWapPush(aData, aLength, aOffset, aOptions); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWAPPUSHAPPLICATION(_to) \
  NS_IMETHOD ReceiveWapPush(uint8_t *aData, uint32_t aLength, uint32_t aOffset, const JS::Value & aOptions) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReceiveWapPush(aData, aLength, aOffset, aOptions); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWapPushApplication : public nsIWapPushApplication
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWAPPUSHAPPLICATION

  nsWapPushApplication();

private:
  ~nsWapPushApplication();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWapPushApplication, nsIWapPushApplication)

nsWapPushApplication::nsWapPushApplication()
{
  /* member initializers and constructor code */
}

nsWapPushApplication::~nsWapPushApplication()
{
  /* destructor code */
}

/* void receiveWapPush ([array, size_is (aLength)] in octet aData, in unsigned long aLength, in unsigned long aOffset, in jsval aOptions); */
NS_IMETHODIMP nsWapPushApplication::ReceiveWapPush(uint8_t *aData, uint32_t aLength, uint32_t aOffset, const JS::Value & aOptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWapPushApplication_h__ */

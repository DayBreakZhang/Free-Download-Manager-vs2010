/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIEncodedChannel.idl
 */

#ifndef __gen_nsIEncodedChannel_h__
#define __gen_nsIEncodedChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIUTF8StringEnumerator; /* forward declaration */


/* starting interface:    nsIEncodedChannel */
#define NS_IENCODEDCHANNEL_IID_STR "30d7ec3a-f376-4652-9276-3092ec57abb6"

#define NS_IENCODEDCHANNEL_IID \
  {0x30d7ec3a, 0xf376, 0x4652, \
    { 0x92, 0x76, 0x30, 0x92, 0xec, 0x57, 0xab, 0xb6 }}

class NS_NO_VTABLE nsIEncodedChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IENCODEDCHANNEL_IID)

  /* readonly attribute nsIUTF8StringEnumerator contentEncodings; */
  NS_IMETHOD GetContentEncodings(nsIUTF8StringEnumerator * *aContentEncodings) = 0;

  /* attribute boolean applyConversion; */
  NS_IMETHOD GetApplyConversion(bool *aApplyConversion) = 0;
  NS_IMETHOD SetApplyConversion(bool aApplyConversion) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEncodedChannel, NS_IENCODEDCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIENCODEDCHANNEL \
  NS_IMETHOD GetContentEncodings(nsIUTF8StringEnumerator * *aContentEncodings); \
  NS_IMETHOD GetApplyConversion(bool *aApplyConversion); \
  NS_IMETHOD SetApplyConversion(bool aApplyConversion); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIENCODEDCHANNEL(_to) \
  NS_IMETHOD GetContentEncodings(nsIUTF8StringEnumerator * *aContentEncodings) { return _to GetContentEncodings(aContentEncodings); } \
  NS_IMETHOD GetApplyConversion(bool *aApplyConversion) { return _to GetApplyConversion(aApplyConversion); } \
  NS_IMETHOD SetApplyConversion(bool aApplyConversion) { return _to SetApplyConversion(aApplyConversion); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIENCODEDCHANNEL(_to) \
  NS_IMETHOD GetContentEncodings(nsIUTF8StringEnumerator * *aContentEncodings) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentEncodings(aContentEncodings); } \
  NS_IMETHOD GetApplyConversion(bool *aApplyConversion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApplyConversion(aApplyConversion); } \
  NS_IMETHOD SetApplyConversion(bool aApplyConversion) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetApplyConversion(aApplyConversion); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEncodedChannel : public nsIEncodedChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIENCODEDCHANNEL

  nsEncodedChannel();

private:
  ~nsEncodedChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEncodedChannel, nsIEncodedChannel)

nsEncodedChannel::nsEncodedChannel()
{
  /* member initializers and constructor code */
}

nsEncodedChannel::~nsEncodedChannel()
{
  /* destructor code */
}

/* readonly attribute nsIUTF8StringEnumerator contentEncodings; */
NS_IMETHODIMP nsEncodedChannel::GetContentEncodings(nsIUTF8StringEnumerator * *aContentEncodings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean applyConversion; */
NS_IMETHODIMP nsEncodedChannel::GetApplyConversion(bool *aApplyConversion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsEncodedChannel::SetApplyConversion(bool aApplyConversion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEncodedChannel_h__ */

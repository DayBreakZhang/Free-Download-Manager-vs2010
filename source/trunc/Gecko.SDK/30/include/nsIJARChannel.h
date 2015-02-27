/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIJARChannel.idl
 */

#ifndef __gen_nsIJARChannel_h__
#define __gen_nsIJARChannel_h__


#ifndef __gen_nsIChannel_h__
#include "nsIChannel.h"
#endif

#include "mozilla/Assertions.h"
#include "mozilla/DebugOnly.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIJARChannel */
#define NS_IJARCHANNEL_IID_STR "6e6cc56d-51eb-4299-a795-dcfd1229ab3d"

#define NS_IJARCHANNEL_IID \
  {0x6e6cc56d, 0x51eb, 0x4299, \
    { 0xa7, 0x95, 0xdc, 0xfd, 0x12, 0x29, 0xab, 0x3d }}

class NS_NO_VTABLE nsIJARChannel : public nsIChannel {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJARCHANNEL_IID)

  /* [infallible] readonly attribute boolean isUnsafe; */
  NS_IMETHOD GetIsUnsafe(bool *aIsUnsafe) = 0;
  inline bool GetIsUnsafe()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetIsUnsafe(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* void setAppURI (in nsIURI uri); */
  NS_IMETHOD SetAppURI(nsIURI *uri) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJARChannel, NS_IJARCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJARCHANNEL \
  NS_IMETHOD GetIsUnsafe(bool *aIsUnsafe); \
  NS_IMETHOD SetAppURI(nsIURI *uri); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJARCHANNEL(_to) \
  NS_IMETHOD GetIsUnsafe(bool *aIsUnsafe) { return _to GetIsUnsafe(aIsUnsafe); } \
  NS_IMETHOD SetAppURI(nsIURI *uri) { return _to SetAppURI(uri); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJARCHANNEL(_to) \
  NS_IMETHOD GetIsUnsafe(bool *aIsUnsafe) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsUnsafe(aIsUnsafe); } \
  NS_IMETHOD SetAppURI(nsIURI *uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAppURI(uri); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJARChannel : public nsIJARChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJARCHANNEL

  nsJARChannel();

private:
  ~nsJARChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJARChannel, nsIJARChannel)

nsJARChannel::nsJARChannel()
{
  /* member initializers and constructor code */
}

nsJARChannel::~nsJARChannel()
{
  /* destructor code */
}

/* [infallible] readonly attribute boolean isUnsafe; */
NS_IMETHODIMP nsJARChannel::GetIsUnsafe(bool *aIsUnsafe)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAppURI (in nsIURI uri); */
NS_IMETHODIMP nsJARChannel::SetAppURI(nsIURI *uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJARChannel_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/protocol/wyciwyg/nsIWyciwygChannel.idl
 */

#ifndef __gen_nsIWyciwygChannel_h__
#define __gen_nsIWyciwygChannel_h__


#ifndef __gen_nsIChannel_h__
#include "nsIChannel.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIWyciwygChannel */
#define NS_IWYCIWYGCHANNEL_IID_STR "89b0674a-9e2f-4124-9b59-481444be841d"

#define NS_IWYCIWYGCHANNEL_IID \
  {0x89b0674a, 0x9e2f, 0x4124, \
    { 0x9b, 0x59, 0x48, 0x14, 0x44, 0xbe, 0x84, 0x1d }}

class NS_NO_VTABLE nsIWyciwygChannel : public nsIChannel {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWYCIWYGCHANNEL_IID)

  /* void writeToCacheEntry (in AString aData); */
  NS_IMETHOD WriteToCacheEntry(const nsAString & aData) = 0;

  /* void closeCacheEntry (in nsresult reason); */
  NS_IMETHOD CloseCacheEntry(nsresult reason) = 0;

  /* void setSecurityInfo (in nsISupports aSecurityInfo); */
  NS_IMETHOD SetSecurityInfo(nsISupports *aSecurityInfo) = 0;

  /* void setCharsetAndSource (in long aSource, in ACString aCharset); */
  NS_IMETHOD SetCharsetAndSource(int32_t aSource, const nsACString & aCharset) = 0;

  /* ACString getCharsetAndSource (out long aSource); */
  NS_IMETHOD GetCharsetAndSource(int32_t *aSource, nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWyciwygChannel, NS_IWYCIWYGCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWYCIWYGCHANNEL \
  NS_IMETHOD WriteToCacheEntry(const nsAString & aData); \
  NS_IMETHOD CloseCacheEntry(nsresult reason); \
  NS_IMETHOD SetSecurityInfo(nsISupports *aSecurityInfo); \
  NS_IMETHOD SetCharsetAndSource(int32_t aSource, const nsACString & aCharset); \
  NS_IMETHOD GetCharsetAndSource(int32_t *aSource, nsACString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWYCIWYGCHANNEL(_to) \
  NS_IMETHOD WriteToCacheEntry(const nsAString & aData) { return _to WriteToCacheEntry(aData); } \
  NS_IMETHOD CloseCacheEntry(nsresult reason) { return _to CloseCacheEntry(reason); } \
  NS_IMETHOD SetSecurityInfo(nsISupports *aSecurityInfo) { return _to SetSecurityInfo(aSecurityInfo); } \
  NS_IMETHOD SetCharsetAndSource(int32_t aSource, const nsACString & aCharset) { return _to SetCharsetAndSource(aSource, aCharset); } \
  NS_IMETHOD GetCharsetAndSource(int32_t *aSource, nsACString & _retval) { return _to GetCharsetAndSource(aSource, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWYCIWYGCHANNEL(_to) \
  NS_IMETHOD WriteToCacheEntry(const nsAString & aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteToCacheEntry(aData); } \
  NS_IMETHOD CloseCacheEntry(nsresult reason) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloseCacheEntry(reason); } \
  NS_IMETHOD SetSecurityInfo(nsISupports *aSecurityInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSecurityInfo(aSecurityInfo); } \
  NS_IMETHOD SetCharsetAndSource(int32_t aSource, const nsACString & aCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCharsetAndSource(aSource, aCharset); } \
  NS_IMETHOD GetCharsetAndSource(int32_t *aSource, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharsetAndSource(aSource, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWyciwygChannel : public nsIWyciwygChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWYCIWYGCHANNEL

  nsWyciwygChannel();

private:
  ~nsWyciwygChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWyciwygChannel, nsIWyciwygChannel)

nsWyciwygChannel::nsWyciwygChannel()
{
  /* member initializers and constructor code */
}

nsWyciwygChannel::~nsWyciwygChannel()
{
  /* destructor code */
}

/* void writeToCacheEntry (in AString aData); */
NS_IMETHODIMP nsWyciwygChannel::WriteToCacheEntry(const nsAString & aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void closeCacheEntry (in nsresult reason); */
NS_IMETHODIMP nsWyciwygChannel::CloseCacheEntry(nsresult reason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSecurityInfo (in nsISupports aSecurityInfo); */
NS_IMETHODIMP nsWyciwygChannel::SetSecurityInfo(nsISupports *aSecurityInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCharsetAndSource (in long aSource, in ACString aCharset); */
NS_IMETHODIMP nsWyciwygChannel::SetCharsetAndSource(int32_t aSource, const nsACString & aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getCharsetAndSource (out long aSource); */
NS_IMETHODIMP nsWyciwygChannel::GetCharsetAndSource(int32_t *aSource, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWyciwygChannel_h__ */

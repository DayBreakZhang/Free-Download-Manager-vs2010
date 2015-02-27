/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIContentSniffer.idl
 */

#ifndef __gen_nsIContentSniffer_h__
#define __gen_nsIContentSniffer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIRequest; /* forward declaration */


/* starting interface:    nsIContentSniffer */
#define NS_ICONTENTSNIFFER_IID_STR "a5772d1b-fc63-495e-a169-96e8d3311af0"

#define NS_ICONTENTSNIFFER_IID \
  {0xa5772d1b, 0xfc63, 0x495e, \
    { 0xa1, 0x69, 0x96, 0xe8, 0xd3, 0x31, 0x1a, 0xf0 }}

class NS_NO_VTABLE nsIContentSniffer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTSNIFFER_IID)

  /* ACString getMIMETypeFromContent (in nsIRequest aRequest, [array, size_is (aLength), const] in octet aData, in unsigned long aLength); */
  NS_IMETHOD GetMIMETypeFromContent(nsIRequest *aRequest, const uint8_t *aData, uint32_t aLength, nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentSniffer, NS_ICONTENTSNIFFER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTSNIFFER \
  NS_IMETHOD GetMIMETypeFromContent(nsIRequest *aRequest, const uint8_t *aData, uint32_t aLength, nsACString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTSNIFFER(_to) \
  NS_IMETHOD GetMIMETypeFromContent(nsIRequest *aRequest, const uint8_t *aData, uint32_t aLength, nsACString & _retval) { return _to GetMIMETypeFromContent(aRequest, aData, aLength, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTSNIFFER(_to) \
  NS_IMETHOD GetMIMETypeFromContent(nsIRequest *aRequest, const uint8_t *aData, uint32_t aLength, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMIMETypeFromContent(aRequest, aData, aLength, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentSniffer : public nsIContentSniffer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTSNIFFER

  nsContentSniffer();

private:
  ~nsContentSniffer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentSniffer, nsIContentSniffer)

nsContentSniffer::nsContentSniffer()
{
  /* member initializers and constructor code */
}

nsContentSniffer::~nsContentSniffer()
{
  /* destructor code */
}

/* ACString getMIMETypeFromContent (in nsIRequest aRequest, [array, size_is (aLength), const] in octet aData, in unsigned long aLength); */
NS_IMETHODIMP nsContentSniffer::GetMIMETypeFromContent(nsIRequest *aRequest, const uint8_t *aData, uint32_t aLength, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContentSniffer_h__ */

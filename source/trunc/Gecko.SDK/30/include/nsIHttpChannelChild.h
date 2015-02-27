/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIHttpChannelChild.idl
 */

#ifndef __gen_nsIHttpChannelChild_h__
#define __gen_nsIHttpChannelChild_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIHttpChannelChild */
#define NS_IHTTPCHANNELCHILD_IID_STR "306acf4d-c6df-4ef6-bda9-5cb92e83edd9"

#define NS_IHTTPCHANNELCHILD_IID \
  {0x306acf4d, 0xc6df, 0x4ef6, \
    { 0xbd, 0xa9, 0x5c, 0xb9, 0x2e, 0x83, 0xed, 0xd9 }}

class NS_NO_VTABLE nsIHttpChannelChild : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPCHANNELCHILD_IID)

  /* void addCookiesToRequest (); */
  NS_IMETHOD AddCookiesToRequest(void) = 0;

  /* readonly attribute RequestHeaderTuples clientSetRequestHeaders; */
  NS_IMETHOD GetClientSetRequestHeaders(mozilla::net::RequestHeaderTuples **aClientSetRequestHeaders) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpChannelChild, NS_IHTTPCHANNELCHILD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPCHANNELCHILD \
  NS_IMETHOD AddCookiesToRequest(void); \
  NS_IMETHOD GetClientSetRequestHeaders(mozilla::net::RequestHeaderTuples **aClientSetRequestHeaders); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPCHANNELCHILD(_to) \
  NS_IMETHOD AddCookiesToRequest(void) { return _to AddCookiesToRequest(); } \
  NS_IMETHOD GetClientSetRequestHeaders(mozilla::net::RequestHeaderTuples **aClientSetRequestHeaders) { return _to GetClientSetRequestHeaders(aClientSetRequestHeaders); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPCHANNELCHILD(_to) \
  NS_IMETHOD AddCookiesToRequest(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddCookiesToRequest(); } \
  NS_IMETHOD GetClientSetRequestHeaders(mozilla::net::RequestHeaderTuples **aClientSetRequestHeaders) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientSetRequestHeaders(aClientSetRequestHeaders); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpChannelChild : public nsIHttpChannelChild
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPCHANNELCHILD

  nsHttpChannelChild();

private:
  ~nsHttpChannelChild();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHttpChannelChild, nsIHttpChannelChild)

nsHttpChannelChild::nsHttpChannelChild()
{
  /* member initializers and constructor code */
}

nsHttpChannelChild::~nsHttpChannelChild()
{
  /* destructor code */
}

/* void addCookiesToRequest (); */
NS_IMETHODIMP nsHttpChannelChild::AddCookiesToRequest()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute RequestHeaderTuples clientSetRequestHeaders; */
NS_IMETHODIMP nsHttpChannelChild::GetClientSetRequestHeaders(mozilla::net::RequestHeaderTuples **aClientSetRequestHeaders)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHttpChannelChild_h__ */

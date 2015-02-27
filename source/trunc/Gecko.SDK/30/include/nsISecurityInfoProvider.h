/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISecurityInfoProvider.idl
 */

#ifndef __gen_nsISecurityInfoProvider_h__
#define __gen_nsISecurityInfoProvider_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISecurityInfoProvider */
#define NS_ISECURITYINFOPROVIDER_IID_STR "b8cc9126-9319-4415-afd9-b82220d453ed"

#define NS_ISECURITYINFOPROVIDER_IID \
  {0xb8cc9126, 0x9319, 0x4415, \
    { 0xaf, 0xd9, 0xb8, 0x22, 0x20, 0xd4, 0x53, 0xed }}

class NS_NO_VTABLE nsISecurityInfoProvider : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISECURITYINFOPROVIDER_IID)

  /* readonly attribute nsISupports securityInfo; */
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) = 0;

  /* readonly attribute boolean hasTransferredData; */
  NS_IMETHOD GetHasTransferredData(bool *aHasTransferredData) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISecurityInfoProvider, NS_ISECURITYINFOPROVIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISECURITYINFOPROVIDER \
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo); \
  NS_IMETHOD GetHasTransferredData(bool *aHasTransferredData); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISECURITYINFOPROVIDER(_to) \
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) { return _to GetSecurityInfo(aSecurityInfo); } \
  NS_IMETHOD GetHasTransferredData(bool *aHasTransferredData) { return _to GetHasTransferredData(aHasTransferredData); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISECURITYINFOPROVIDER(_to) \
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSecurityInfo(aSecurityInfo); } \
  NS_IMETHOD GetHasTransferredData(bool *aHasTransferredData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasTransferredData(aHasTransferredData); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSecurityInfoProvider : public nsISecurityInfoProvider
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISECURITYINFOPROVIDER

  nsSecurityInfoProvider();

private:
  ~nsSecurityInfoProvider();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSecurityInfoProvider, nsISecurityInfoProvider)

nsSecurityInfoProvider::nsSecurityInfoProvider()
{
  /* member initializers and constructor code */
}

nsSecurityInfoProvider::~nsSecurityInfoProvider()
{
  /* destructor code */
}

/* readonly attribute nsISupports securityInfo; */
NS_IMETHODIMP nsSecurityInfoProvider::GetSecurityInfo(nsISupports * *aSecurityInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasTransferredData; */
NS_IMETHODIMP nsSecurityInfoProvider::GetHasTransferredData(bool *aHasTransferredData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISecurityInfoProvider_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIInterfaceRequestor.idl
 */

#ifndef __gen_nsIInterfaceRequestor_h__
#define __gen_nsIInterfaceRequestor_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIInterfaceRequestor */
#define NS_IINTERFACEREQUESTOR_IID_STR "033a1470-8b2a-11d3-af88-00a024ffc08c"

#define NS_IINTERFACEREQUESTOR_IID \
  {0x033a1470, 0x8b2a, 0x11d3, \
    { 0xaf, 0x88, 0x00, 0xa0, 0x24, 0xff, 0xc0, 0x8c }}

class NS_NO_VTABLE nsIInterfaceRequestor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINTERFACEREQUESTOR_IID)

  /* void getInterface (in nsIIDRef uuid, [iid_is (uuid), retval] out nsQIResult result); */
  NS_IMETHOD GetInterface(const nsIID & uuid, void **result) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInterfaceRequestor, NS_IINTERFACEREQUESTOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINTERFACEREQUESTOR \
  NS_IMETHOD GetInterface(const nsIID & uuid, void **result); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINTERFACEREQUESTOR(_to) \
  NS_IMETHOD GetInterface(const nsIID & uuid, void **result) { return _to GetInterface(uuid, result); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINTERFACEREQUESTOR(_to) \
  NS_IMETHOD GetInterface(const nsIID & uuid, void **result) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterface(uuid, result); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInterfaceRequestor : public nsIInterfaceRequestor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINTERFACEREQUESTOR

  nsInterfaceRequestor();

private:
  ~nsInterfaceRequestor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsInterfaceRequestor, nsIInterfaceRequestor)

nsInterfaceRequestor::nsInterfaceRequestor()
{
  /* member initializers and constructor code */
}

nsInterfaceRequestor::~nsInterfaceRequestor()
{
  /* destructor code */
}

/* void getInterface (in nsIIDRef uuid, [iid_is (uuid), retval] out nsQIResult result); */
NS_IMETHODIMP nsInterfaceRequestor::GetInterface(const nsIID & uuid, void **result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIInterfaceRequestor_h__ */

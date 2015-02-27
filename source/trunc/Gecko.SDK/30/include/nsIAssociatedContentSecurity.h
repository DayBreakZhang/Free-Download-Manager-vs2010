/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAssociatedContentSecurity.idl
 */

#ifndef __gen_nsIAssociatedContentSecurity_h__
#define __gen_nsIAssociatedContentSecurity_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAssociatedContentSecurity */
#define NS_IASSOCIATEDCONTENTSECURITY_IID_STR "a8285dae-f125-454f-9d1b-089e3f01b2c4"

#define NS_IASSOCIATEDCONTENTSECURITY_IID \
  {0xa8285dae, 0xf125, 0x454f, \
    { 0x9d, 0x1b, 0x08, 0x9e, 0x3f, 0x01, 0xb2, 0xc4 }}

class NS_NO_VTABLE nsIAssociatedContentSecurity : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IASSOCIATEDCONTENTSECURITY_IID)

  /* attribute long countSubRequestsBrokenSecurity; */
  NS_IMETHOD GetCountSubRequestsBrokenSecurity(int32_t *aCountSubRequestsBrokenSecurity) = 0;
  NS_IMETHOD SetCountSubRequestsBrokenSecurity(int32_t aCountSubRequestsBrokenSecurity) = 0;

  /* attribute long countSubRequestsNoSecurity; */
  NS_IMETHOD GetCountSubRequestsNoSecurity(int32_t *aCountSubRequestsNoSecurity) = 0;
  NS_IMETHOD SetCountSubRequestsNoSecurity(int32_t aCountSubRequestsNoSecurity) = 0;

  /* void flush (); */
  NS_IMETHOD Flush(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAssociatedContentSecurity, NS_IASSOCIATEDCONTENTSECURITY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIASSOCIATEDCONTENTSECURITY \
  NS_IMETHOD GetCountSubRequestsBrokenSecurity(int32_t *aCountSubRequestsBrokenSecurity); \
  NS_IMETHOD SetCountSubRequestsBrokenSecurity(int32_t aCountSubRequestsBrokenSecurity); \
  NS_IMETHOD GetCountSubRequestsNoSecurity(int32_t *aCountSubRequestsNoSecurity); \
  NS_IMETHOD SetCountSubRequestsNoSecurity(int32_t aCountSubRequestsNoSecurity); \
  NS_IMETHOD Flush(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIASSOCIATEDCONTENTSECURITY(_to) \
  NS_IMETHOD GetCountSubRequestsBrokenSecurity(int32_t *aCountSubRequestsBrokenSecurity) { return _to GetCountSubRequestsBrokenSecurity(aCountSubRequestsBrokenSecurity); } \
  NS_IMETHOD SetCountSubRequestsBrokenSecurity(int32_t aCountSubRequestsBrokenSecurity) { return _to SetCountSubRequestsBrokenSecurity(aCountSubRequestsBrokenSecurity); } \
  NS_IMETHOD GetCountSubRequestsNoSecurity(int32_t *aCountSubRequestsNoSecurity) { return _to GetCountSubRequestsNoSecurity(aCountSubRequestsNoSecurity); } \
  NS_IMETHOD SetCountSubRequestsNoSecurity(int32_t aCountSubRequestsNoSecurity) { return _to SetCountSubRequestsNoSecurity(aCountSubRequestsNoSecurity); } \
  NS_IMETHOD Flush(void) { return _to Flush(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIASSOCIATEDCONTENTSECURITY(_to) \
  NS_IMETHOD GetCountSubRequestsBrokenSecurity(int32_t *aCountSubRequestsBrokenSecurity) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCountSubRequestsBrokenSecurity(aCountSubRequestsBrokenSecurity); } \
  NS_IMETHOD SetCountSubRequestsBrokenSecurity(int32_t aCountSubRequestsBrokenSecurity) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCountSubRequestsBrokenSecurity(aCountSubRequestsBrokenSecurity); } \
  NS_IMETHOD GetCountSubRequestsNoSecurity(int32_t *aCountSubRequestsNoSecurity) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCountSubRequestsNoSecurity(aCountSubRequestsNoSecurity); } \
  NS_IMETHOD SetCountSubRequestsNoSecurity(int32_t aCountSubRequestsNoSecurity) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCountSubRequestsNoSecurity(aCountSubRequestsNoSecurity); } \
  NS_IMETHOD Flush(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Flush(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAssociatedContentSecurity : public nsIAssociatedContentSecurity
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIASSOCIATEDCONTENTSECURITY

  nsAssociatedContentSecurity();

private:
  ~nsAssociatedContentSecurity();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAssociatedContentSecurity, nsIAssociatedContentSecurity)

nsAssociatedContentSecurity::nsAssociatedContentSecurity()
{
  /* member initializers and constructor code */
}

nsAssociatedContentSecurity::~nsAssociatedContentSecurity()
{
  /* destructor code */
}

/* attribute long countSubRequestsBrokenSecurity; */
NS_IMETHODIMP nsAssociatedContentSecurity::GetCountSubRequestsBrokenSecurity(int32_t *aCountSubRequestsBrokenSecurity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAssociatedContentSecurity::SetCountSubRequestsBrokenSecurity(int32_t aCountSubRequestsBrokenSecurity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long countSubRequestsNoSecurity; */
NS_IMETHODIMP nsAssociatedContentSecurity::GetCountSubRequestsNoSecurity(int32_t *aCountSubRequestsNoSecurity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAssociatedContentSecurity::SetCountSubRequestsNoSecurity(int32_t aCountSubRequestsNoSecurity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void flush (); */
NS_IMETHODIMP nsAssociatedContentSecurity::Flush()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAssociatedContentSecurity_h__ */

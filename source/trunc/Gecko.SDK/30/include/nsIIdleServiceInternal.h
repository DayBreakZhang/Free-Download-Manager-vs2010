/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIIdleServiceInternal.idl
 */

#ifndef __gen_nsIIdleServiceInternal_h__
#define __gen_nsIIdleServiceInternal_h__


#ifndef __gen_nsIIdleService_h__
#include "nsIIdleService.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIIdleServiceInternal */
#define NS_IIDLESERVICEINTERNAL_IID_STR "7b89a2e7-ed12-42e0-b86d-4984239abd7b"

#define NS_IIDLESERVICEINTERNAL_IID \
  {0x7b89a2e7, 0xed12, 0x42e0, \
    { 0xb8, 0x6d, 0x49, 0x84, 0x23, 0x9a, 0xbd, 0x7b }}

class NS_NO_VTABLE nsIIdleServiceInternal : public nsIIdleService {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDLESERVICEINTERNAL_IID)

  /* void resetIdleTimeOut (in unsigned long idleDeltaInMS); */
  NS_IMETHOD ResetIdleTimeOut(uint32_t idleDeltaInMS) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIdleServiceInternal, NS_IIDLESERVICEINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDLESERVICEINTERNAL \
  NS_IMETHOD ResetIdleTimeOut(uint32_t idleDeltaInMS); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDLESERVICEINTERNAL(_to) \
  NS_IMETHOD ResetIdleTimeOut(uint32_t idleDeltaInMS) { return _to ResetIdleTimeOut(idleDeltaInMS); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDLESERVICEINTERNAL(_to) \
  NS_IMETHOD ResetIdleTimeOut(uint32_t idleDeltaInMS) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResetIdleTimeOut(idleDeltaInMS); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIdleServiceInternal : public nsIIdleServiceInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDLESERVICEINTERNAL

  nsIdleServiceInternal();

private:
  ~nsIdleServiceInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIdleServiceInternal, nsIIdleServiceInternal)

nsIdleServiceInternal::nsIdleServiceInternal()
{
  /* member initializers and constructor code */
}

nsIdleServiceInternal::~nsIdleServiceInternal()
{
  /* destructor code */
}

/* void resetIdleTimeOut (in unsigned long idleDeltaInMS); */
NS_IMETHODIMP nsIdleServiceInternal::ResetIdleTimeOut(uint32_t idleDeltaInMS)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIdleServiceInternal_h__ */

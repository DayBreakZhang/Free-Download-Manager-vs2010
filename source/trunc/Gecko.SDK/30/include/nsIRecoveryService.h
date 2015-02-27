/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIRecoveryService.idl
 */

#ifndef __gen_nsIRecoveryService_h__
#define __gen_nsIRecoveryService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRecoveryService */
#define NS_IRECOVERYSERVICE_IID_STR "acb93ff8-aa6d-4bc8-bedd-2a6a3b802a74"

#define NS_IRECOVERYSERVICE_IID \
  {0xacb93ff8, 0xaa6d, 0x4bc8, \
    { 0xbe, 0xdd, 0x2a, 0x6a, 0x3b, 0x80, 0x2a, 0x74 }}

class NS_NO_VTABLE nsIRecoveryService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRECOVERYSERVICE_IID)

  enum {
    FOTA_UPDATE_UNKNOWN = 0,
    FOTA_UPDATE_FAIL = 1,
    FOTA_UPDATE_SUCCESS = 2
  };

  /* void factoryReset (); */
  NS_IMETHOD FactoryReset(void) = 0;

  /* void installFotaUpdate (in string updatePath); */
  NS_IMETHOD InstallFotaUpdate(const char * updatePath) = 0;

  /* long getFotaUpdateStatus (); */
  NS_IMETHOD GetFotaUpdateStatus(int32_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRecoveryService, NS_IRECOVERYSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRECOVERYSERVICE \
  NS_IMETHOD FactoryReset(void); \
  NS_IMETHOD InstallFotaUpdate(const char * updatePath); \
  NS_IMETHOD GetFotaUpdateStatus(int32_t *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRECOVERYSERVICE(_to) \
  NS_IMETHOD FactoryReset(void) { return _to FactoryReset(); } \
  NS_IMETHOD InstallFotaUpdate(const char * updatePath) { return _to InstallFotaUpdate(updatePath); } \
  NS_IMETHOD GetFotaUpdateStatus(int32_t *_retval) { return _to GetFotaUpdateStatus(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRECOVERYSERVICE(_to) \
  NS_IMETHOD FactoryReset(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->FactoryReset(); } \
  NS_IMETHOD InstallFotaUpdate(const char * updatePath) { return !_to ? NS_ERROR_NULL_POINTER : _to->InstallFotaUpdate(updatePath); } \
  NS_IMETHOD GetFotaUpdateStatus(int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFotaUpdateStatus(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRecoveryService : public nsIRecoveryService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRECOVERYSERVICE

  nsRecoveryService();

private:
  ~nsRecoveryService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRecoveryService, nsIRecoveryService)

nsRecoveryService::nsRecoveryService()
{
  /* member initializers and constructor code */
}

nsRecoveryService::~nsRecoveryService()
{
  /* destructor code */
}

/* void factoryReset (); */
NS_IMETHODIMP nsRecoveryService::FactoryReset()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void installFotaUpdate (in string updatePath); */
NS_IMETHODIMP nsRecoveryService::InstallFotaUpdate(const char * updatePath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getFotaUpdateStatus (); */
NS_IMETHODIMP nsRecoveryService::GetFotaUpdateStatus(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRecoveryService_h__ */

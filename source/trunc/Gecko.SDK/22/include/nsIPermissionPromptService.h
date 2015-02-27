/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/permission/nsIPermissionPromptService.idl
 */

#ifndef __gen_nsIPermissionPromptService_h__
#define __gen_nsIPermissionPromptService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIContentPermissionRequest; /* forward declaration */


/* starting interface:    nsIPermissionPromptService */
#define NS_IPERMISSIONPROMPTSERVICE_IID_STR "e5f953b3-a6ca-444e-a88d-cdc81383741c"

#define NS_IPERMISSIONPROMPTSERVICE_IID \
  {0xe5f953b3, 0xa6ca, 0x444e, \
    { 0xa8, 0x8d, 0xcd, 0xc8, 0x13, 0x83, 0x74, 0x1c }}

class NS_NO_VTABLE nsIPermissionPromptService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPERMISSIONPROMPTSERVICE_IID)

  /* void getPermission (in nsIContentPermissionRequest aRequest); */
  NS_IMETHOD GetPermission(nsIContentPermissionRequest *aRequest) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPermissionPromptService, NS_IPERMISSIONPROMPTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPERMISSIONPROMPTSERVICE \
  NS_IMETHOD GetPermission(nsIContentPermissionRequest *aRequest); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPERMISSIONPROMPTSERVICE(_to) \
  NS_IMETHOD GetPermission(nsIContentPermissionRequest *aRequest) { return _to GetPermission(aRequest); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPERMISSIONPROMPTSERVICE(_to) \
  NS_IMETHOD GetPermission(nsIContentPermissionRequest *aRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPermission(aRequest); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPermissionPromptService : public nsIPermissionPromptService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPERMISSIONPROMPTSERVICE

  nsPermissionPromptService();

private:
  ~nsPermissionPromptService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPermissionPromptService, nsIPermissionPromptService)

nsPermissionPromptService::nsPermissionPromptService()
{
  /* member initializers and constructor code */
}

nsPermissionPromptService::~nsPermissionPromptService()
{
  /* destructor code */
}

/* void getPermission (in nsIContentPermissionRequest aRequest); */
NS_IMETHODIMP nsPermissionPromptService::GetPermission(nsIContentPermissionRequest *aRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPermissionPromptService_h__ */

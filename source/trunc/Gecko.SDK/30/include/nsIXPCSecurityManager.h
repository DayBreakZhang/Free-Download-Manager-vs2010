/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIXPCSecurityManager.idl
 */

#ifndef __gen_nsIXPCSecurityManager_h__
#define __gen_nsIXPCSecurityManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "jspubtd.h"
class nsAXPCNativeCallContext;
class nsIClassInfo; /* forward declaration */


/* starting interface:    nsIXPCSecurityManager */
#define NS_IXPCSECURITYMANAGER_IID_STR "d4d21714-116b-4851-a785-098c5dfea523"

#define NS_IXPCSECURITYMANAGER_IID \
  {0xd4d21714, 0x116b, 0x4851, \
    { 0xa7, 0x85, 0x09, 0x8c, 0x5d, 0xfe, 0xa5, 0x23 }}

class NS_NO_VTABLE nsIXPCSecurityManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCSECURITYMANAGER_IID)

  /* void CanCreateWrapper (in JSContextPtr aJSContext, in nsIIDRef aIID, in nsISupports aObj, in nsIClassInfo aClassInfo); */
  NS_IMETHOD CanCreateWrapper(JSContext *aJSContext, const nsIID & aIID, nsISupports *aObj, nsIClassInfo *aClassInfo) = 0;

  /* void CanCreateInstance (in JSContextPtr aJSContext, in nsCIDRef aCID); */
  NS_IMETHOD CanCreateInstance(JSContext *aJSContext, const nsCID & aCID) = 0;

  /* void CanGetService (in JSContextPtr aJSContext, in nsCIDRef aCID); */
  NS_IMETHOD CanGetService(JSContext *aJSContext, const nsCID & aCID) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCSecurityManager, NS_IXPCSECURITYMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCSECURITYMANAGER \
  NS_IMETHOD CanCreateWrapper(JSContext *aJSContext, const nsIID & aIID, nsISupports *aObj, nsIClassInfo *aClassInfo); \
  NS_IMETHOD CanCreateInstance(JSContext *aJSContext, const nsCID & aCID); \
  NS_IMETHOD CanGetService(JSContext *aJSContext, const nsCID & aCID); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCSECURITYMANAGER(_to) \
  NS_IMETHOD CanCreateWrapper(JSContext *aJSContext, const nsIID & aIID, nsISupports *aObj, nsIClassInfo *aClassInfo) { return _to CanCreateWrapper(aJSContext, aIID, aObj, aClassInfo); } \
  NS_IMETHOD CanCreateInstance(JSContext *aJSContext, const nsCID & aCID) { return _to CanCreateInstance(aJSContext, aCID); } \
  NS_IMETHOD CanGetService(JSContext *aJSContext, const nsCID & aCID) { return _to CanGetService(aJSContext, aCID); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCSECURITYMANAGER(_to) \
  NS_IMETHOD CanCreateWrapper(JSContext *aJSContext, const nsIID & aIID, nsISupports *aObj, nsIClassInfo *aClassInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanCreateWrapper(aJSContext, aIID, aObj, aClassInfo); } \
  NS_IMETHOD CanCreateInstance(JSContext *aJSContext, const nsCID & aCID) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanCreateInstance(aJSContext, aCID); } \
  NS_IMETHOD CanGetService(JSContext *aJSContext, const nsCID & aCID) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanGetService(aJSContext, aCID); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCSecurityManager : public nsIXPCSecurityManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCSECURITYMANAGER

  nsXPCSecurityManager();

private:
  ~nsXPCSecurityManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPCSecurityManager, nsIXPCSecurityManager)

nsXPCSecurityManager::nsXPCSecurityManager()
{
  /* member initializers and constructor code */
}

nsXPCSecurityManager::~nsXPCSecurityManager()
{
  /* destructor code */
}

/* void CanCreateWrapper (in JSContextPtr aJSContext, in nsIIDRef aIID, in nsISupports aObj, in nsIClassInfo aClassInfo); */
NS_IMETHODIMP nsXPCSecurityManager::CanCreateWrapper(JSContext *aJSContext, const nsIID & aIID, nsISupports *aObj, nsIClassInfo *aClassInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void CanCreateInstance (in JSContextPtr aJSContext, in nsCIDRef aCID); */
NS_IMETHODIMP nsXPCSecurityManager::CanCreateInstance(JSContext *aJSContext, const nsCID & aCID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void CanGetService (in JSContextPtr aJSContext, in nsCIDRef aCID); */
NS_IMETHODIMP nsXPCSecurityManager::CanGetService(JSContext *aJSContext, const nsCID & aCID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXPCSecurityManager_h__ */

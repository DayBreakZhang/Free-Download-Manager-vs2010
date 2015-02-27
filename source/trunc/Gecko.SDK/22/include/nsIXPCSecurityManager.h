/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/js/xpconnect/idl/nsIXPCSecurityManager.idl
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
#define NS_IXPCSECURITYMANAGER_IID_STR "31431440-f1ce-11d2-985a-006008962422"

#define NS_IXPCSECURITYMANAGER_IID \
  {0x31431440, 0xf1ce, 0x11d2, \
    { 0x98, 0x5a, 0x00, 0x60, 0x08, 0x96, 0x24, 0x22 }}

class NS_NO_VTABLE nsIXPCSecurityManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCSECURITYMANAGER_IID)

  enum {
    HOOK_CREATE_WRAPPER = 1U,
    HOOK_CREATE_INSTANCE = 2U,
    HOOK_GET_SERVICE = 4U,
    HOOK_CALL_METHOD = 8U,
    HOOK_GET_PROPERTY = 16U,
    HOOK_SET_PROPERTY = 32U,
    HOOK_ALL = 63U
  };

  /* void CanCreateWrapper (in JSContextPtr aJSContext, in nsIIDRef aIID, in nsISupports aObj, in nsIClassInfo aClassInfo, inout voidPtr aPolicy); */
  NS_IMETHOD CanCreateWrapper(JSContext *aJSContext, const nsIID & aIID, nsISupports *aObj, nsIClassInfo *aClassInfo, void **aPolicy) = 0;

  /* void CanCreateInstance (in JSContextPtr aJSContext, in nsCIDRef aCID); */
  NS_IMETHOD CanCreateInstance(JSContext *aJSContext, const nsCID & aCID) = 0;

  /* void CanGetService (in JSContextPtr aJSContext, in nsCIDRef aCID); */
  NS_IMETHOD CanGetService(JSContext *aJSContext, const nsCID & aCID) = 0;

  enum {
    ACCESS_CALL_METHOD = 0U,
    ACCESS_GET_PROPERTY = 1U,
    ACCESS_SET_PROPERTY = 2U
  };

  /* void CanAccess (in uint32_t aAction, in nsAXPCNativeCallContextPtr aCallContext, in JSContextPtr aJSContext, in JSObjectPtr aJSObject, in nsISupports aObj, in nsIClassInfo aClassInfo, in jsid aName, inout voidPtr aPolicy); */
  NS_IMETHOD CanAccess(uint32_t aAction, nsAXPCNativeCallContext *aCallContext, JSContext *aJSContext, JSObject *aJSObject, nsISupports *aObj, nsIClassInfo *aClassInfo, jsid aName, void **aPolicy) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCSecurityManager, NS_IXPCSECURITYMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCSECURITYMANAGER \
  NS_IMETHOD CanCreateWrapper(JSContext *aJSContext, const nsIID & aIID, nsISupports *aObj, nsIClassInfo *aClassInfo, void **aPolicy); \
  NS_IMETHOD CanCreateInstance(JSContext *aJSContext, const nsCID & aCID); \
  NS_IMETHOD CanGetService(JSContext *aJSContext, const nsCID & aCID); \
  NS_IMETHOD CanAccess(uint32_t aAction, nsAXPCNativeCallContext *aCallContext, JSContext *aJSContext, JSObject *aJSObject, nsISupports *aObj, nsIClassInfo *aClassInfo, jsid aName, void **aPolicy); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCSECURITYMANAGER(_to) \
  NS_IMETHOD CanCreateWrapper(JSContext *aJSContext, const nsIID & aIID, nsISupports *aObj, nsIClassInfo *aClassInfo, void **aPolicy) { return _to CanCreateWrapper(aJSContext, aIID, aObj, aClassInfo, aPolicy); } \
  NS_IMETHOD CanCreateInstance(JSContext *aJSContext, const nsCID & aCID) { return _to CanCreateInstance(aJSContext, aCID); } \
  NS_IMETHOD CanGetService(JSContext *aJSContext, const nsCID & aCID) { return _to CanGetService(aJSContext, aCID); } \
  NS_IMETHOD CanAccess(uint32_t aAction, nsAXPCNativeCallContext *aCallContext, JSContext *aJSContext, JSObject *aJSObject, nsISupports *aObj, nsIClassInfo *aClassInfo, jsid aName, void **aPolicy) { return _to CanAccess(aAction, aCallContext, aJSContext, aJSObject, aObj, aClassInfo, aName, aPolicy); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCSECURITYMANAGER(_to) \
  NS_IMETHOD CanCreateWrapper(JSContext *aJSContext, const nsIID & aIID, nsISupports *aObj, nsIClassInfo *aClassInfo, void **aPolicy) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanCreateWrapper(aJSContext, aIID, aObj, aClassInfo, aPolicy); } \
  NS_IMETHOD CanCreateInstance(JSContext *aJSContext, const nsCID & aCID) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanCreateInstance(aJSContext, aCID); } \
  NS_IMETHOD CanGetService(JSContext *aJSContext, const nsCID & aCID) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanGetService(aJSContext, aCID); } \
  NS_IMETHOD CanAccess(uint32_t aAction, nsAXPCNativeCallContext *aCallContext, JSContext *aJSContext, JSObject *aJSObject, nsISupports *aObj, nsIClassInfo *aClassInfo, jsid aName, void **aPolicy) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanAccess(aAction, aCallContext, aJSContext, aJSObject, aObj, aClassInfo, aName, aPolicy); } 

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

/* void CanCreateWrapper (in JSContextPtr aJSContext, in nsIIDRef aIID, in nsISupports aObj, in nsIClassInfo aClassInfo, inout voidPtr aPolicy); */
NS_IMETHODIMP nsXPCSecurityManager::CanCreateWrapper(JSContext *aJSContext, const nsIID & aIID, nsISupports *aObj, nsIClassInfo *aClassInfo, void **aPolicy)
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

/* void CanAccess (in uint32_t aAction, in nsAXPCNativeCallContextPtr aCallContext, in JSContextPtr aJSContext, in JSObjectPtr aJSObject, in nsISupports aObj, in nsIClassInfo aClassInfo, in jsid aName, inout voidPtr aPolicy); */
NS_IMETHODIMP nsXPCSecurityManager::CanAccess(uint32_t aAction, nsAXPCNativeCallContext *aCallContext, JSContext *aJSContext, JSObject *aJSObject, nsISupports *aObj, nsIClassInfo *aClassInfo, jsid aName, void **aPolicy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXPCSecurityManager_h__ */

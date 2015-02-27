/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpfe/appshell/public/nsIPopupWindowManager.idl
 */

#ifndef __gen_nsIPopupWindowManager_h__
#define __gen_nsIPopupWindowManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPrincipal; /* forward declaration */


/* starting interface:    nsIPopupWindowManager */
#define NS_IPOPUPWINDOWMANAGER_IID_STR "66386aa9-2088-4bae-82c7-9f58bc02be64"

#define NS_IPOPUPWINDOWMANAGER_IID \
  {0x66386aa9, 0x2088, 0x4bae, \
    { 0x82, 0xc7, 0x9f, 0x58, 0xbc, 0x02, 0xbe, 0x64 }}

class NS_NO_VTABLE nsIPopupWindowManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPOPUPWINDOWMANAGER_IID)

  enum {
    ALLOW_POPUP = 1U,
    DENY_POPUP = 2U,
    ALLOW_POPUP_WITH_PREJUDICE = 3U
  };

  /* uint32_t testPermission (in nsIPrincipal principal); */
  NS_IMETHOD TestPermission(nsIPrincipal *principal, uint32_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPopupWindowManager, NS_IPOPUPWINDOWMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPOPUPWINDOWMANAGER \
  NS_IMETHOD TestPermission(nsIPrincipal *principal, uint32_t *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPOPUPWINDOWMANAGER(_to) \
  NS_IMETHOD TestPermission(nsIPrincipal *principal, uint32_t *_retval) { return _to TestPermission(principal, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPOPUPWINDOWMANAGER(_to) \
  NS_IMETHOD TestPermission(nsIPrincipal *principal, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestPermission(principal, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPopupWindowManager : public nsIPopupWindowManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPOPUPWINDOWMANAGER

  nsPopupWindowManager();

private:
  ~nsPopupWindowManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPopupWindowManager, nsIPopupWindowManager)

nsPopupWindowManager::nsPopupWindowManager()
{
  /* member initializers and constructor code */
}

nsPopupWindowManager::~nsPopupWindowManager()
{
  /* destructor code */
}

/* uint32_t testPermission (in nsIPrincipal principal); */
NS_IMETHODIMP nsPopupWindowManager::TestPermission(nsIPrincipal *principal, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_POPUPWINDOWMANAGER_CONTRACTID "@mozilla.org/PopupWindowManager;1"

#endif /* __gen_nsIPopupWindowManager_h__ */

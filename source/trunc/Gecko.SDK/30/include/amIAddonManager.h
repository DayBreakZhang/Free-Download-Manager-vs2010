/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\amIAddonManager.idl
 */

#ifndef __gen_amIAddonManager_h__
#define __gen_amIAddonManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    amIAddonManager */
#define AMIADDONMANAGER_IID_STR "7b45d82d-7ad5-48d7-9b05-f32eb9818cd4"

#define AMIADDONMANAGER_IID \
  {0x7b45d82d, 0x7ad5, 0x48d7, \
    { 0x9b, 0x05, 0xf3, 0x2e, 0xb9, 0x81, 0x8c, 0xd4 }}

class NS_NO_VTABLE amIAddonManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(AMIADDONMANAGER_IID)

  /* boolean mapURIToAddonID (in nsIURI aURI, out AUTF8String aID); */
  NS_IMETHOD MapURIToAddonID(nsIURI *aURI, nsACString & aID, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(amIAddonManager, AMIADDONMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_AMIADDONMANAGER \
  NS_IMETHOD MapURIToAddonID(nsIURI *aURI, nsACString & aID, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_AMIADDONMANAGER(_to) \
  NS_IMETHOD MapURIToAddonID(nsIURI *aURI, nsACString & aID, bool *_retval) { return _to MapURIToAddonID(aURI, aID, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_AMIADDONMANAGER(_to) \
  NS_IMETHOD MapURIToAddonID(nsIURI *aURI, nsACString & aID, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MapURIToAddonID(aURI, aID, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class amAddonManager : public amIAddonManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_AMIADDONMANAGER

  amAddonManager();

private:
  ~amAddonManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(amAddonManager, amIAddonManager)

amAddonManager::amAddonManager()
{
  /* member initializers and constructor code */
}

amAddonManager::~amAddonManager()
{
  /* destructor code */
}

/* boolean mapURIToAddonID (in nsIURI aURI, out AUTF8String aID); */
NS_IMETHODIMP amAddonManager::MapURIToAddonID(nsIURI *aURI, nsACString & aID, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_amIAddonManager_h__ */

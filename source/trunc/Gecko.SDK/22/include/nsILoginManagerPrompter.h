/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/toolkit/components/passwordmgr/nsILoginManagerPrompter.idl
 */

#ifndef __gen_nsILoginManagerPrompter_h__
#define __gen_nsILoginManagerPrompter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsILoginInfo; /* forward declaration */

class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsILoginManagerPrompter */
#define NS_ILOGINMANAGERPROMPTER_IID_STR "68b3cb59-51b8-4c57-bd7f-b2ce955a593d"

#define NS_ILOGINMANAGERPROMPTER_IID \
  {0x68b3cb59, 0x51b8, 0x4c57, \
    { 0xbd, 0x7f, 0xb2, 0xce, 0x95, 0x5a, 0x59, 0x3d }}

class NS_NO_VTABLE nsILoginManagerPrompter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOGINMANAGERPROMPTER_IID)

  /* void init (in nsIDOMWindow aWindow); */
  NS_IMETHOD Init(nsIDOMWindow *aWindow) = 0;

  /* void promptToSavePassword (in nsILoginInfo aLogin); */
  NS_IMETHOD PromptToSavePassword(nsILoginInfo *aLogin) = 0;

  /* void promptToChangePassword (in nsILoginInfo aOldLogin, in nsILoginInfo aNewLogin); */
  NS_IMETHOD PromptToChangePassword(nsILoginInfo *aOldLogin, nsILoginInfo *aNewLogin) = 0;

  /* void promptToChangePasswordWithUsernames ([array, size_is (count)] in nsILoginInfo logins, in uint32_t count, in nsILoginInfo aNewLogin); */
  NS_IMETHOD PromptToChangePasswordWithUsernames(nsILoginInfo **logins, uint32_t count, nsILoginInfo *aNewLogin) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILoginManagerPrompter, NS_ILOGINMANAGERPROMPTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOGINMANAGERPROMPTER \
  NS_IMETHOD Init(nsIDOMWindow *aWindow); \
  NS_IMETHOD PromptToSavePassword(nsILoginInfo *aLogin); \
  NS_IMETHOD PromptToChangePassword(nsILoginInfo *aOldLogin, nsILoginInfo *aNewLogin); \
  NS_IMETHOD PromptToChangePasswordWithUsernames(nsILoginInfo **logins, uint32_t count, nsILoginInfo *aNewLogin); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOGINMANAGERPROMPTER(_to) \
  NS_IMETHOD Init(nsIDOMWindow *aWindow) { return _to Init(aWindow); } \
  NS_IMETHOD PromptToSavePassword(nsILoginInfo *aLogin) { return _to PromptToSavePassword(aLogin); } \
  NS_IMETHOD PromptToChangePassword(nsILoginInfo *aOldLogin, nsILoginInfo *aNewLogin) { return _to PromptToChangePassword(aOldLogin, aNewLogin); } \
  NS_IMETHOD PromptToChangePasswordWithUsernames(nsILoginInfo **logins, uint32_t count, nsILoginInfo *aNewLogin) { return _to PromptToChangePasswordWithUsernames(logins, count, aNewLogin); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOGINMANAGERPROMPTER(_to) \
  NS_IMETHOD Init(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aWindow); } \
  NS_IMETHOD PromptToSavePassword(nsILoginInfo *aLogin) { return !_to ? NS_ERROR_NULL_POINTER : _to->PromptToSavePassword(aLogin); } \
  NS_IMETHOD PromptToChangePassword(nsILoginInfo *aOldLogin, nsILoginInfo *aNewLogin) { return !_to ? NS_ERROR_NULL_POINTER : _to->PromptToChangePassword(aOldLogin, aNewLogin); } \
  NS_IMETHOD PromptToChangePasswordWithUsernames(nsILoginInfo **logins, uint32_t count, nsILoginInfo *aNewLogin) { return !_to ? NS_ERROR_NULL_POINTER : _to->PromptToChangePasswordWithUsernames(logins, count, aNewLogin); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLoginManagerPrompter : public nsILoginManagerPrompter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOGINMANAGERPROMPTER

  nsLoginManagerPrompter();

private:
  ~nsLoginManagerPrompter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLoginManagerPrompter, nsILoginManagerPrompter)

nsLoginManagerPrompter::nsLoginManagerPrompter()
{
  /* member initializers and constructor code */
}

nsLoginManagerPrompter::~nsLoginManagerPrompter()
{
  /* destructor code */
}

/* void init (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsLoginManagerPrompter::Init(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void promptToSavePassword (in nsILoginInfo aLogin); */
NS_IMETHODIMP nsLoginManagerPrompter::PromptToSavePassword(nsILoginInfo *aLogin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void promptToChangePassword (in nsILoginInfo aOldLogin, in nsILoginInfo aNewLogin); */
NS_IMETHODIMP nsLoginManagerPrompter::PromptToChangePassword(nsILoginInfo *aOldLogin, nsILoginInfo *aNewLogin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void promptToChangePasswordWithUsernames ([array, size_is (count)] in nsILoginInfo logins, in uint32_t count, in nsILoginInfo aNewLogin); */
NS_IMETHODIMP nsLoginManagerPrompter::PromptToChangePasswordWithUsernames(nsILoginInfo **logins, uint32_t count, nsILoginInfo *aNewLogin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define NS_LOGINMANAGERPROMPTER_CONTRACTID "@mozilla.org/login-manager/prompter/;1"

#endif /* __gen_nsILoginManagerPrompter_h__ */

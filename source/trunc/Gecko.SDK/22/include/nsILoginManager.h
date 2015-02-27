/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/toolkit/components/passwordmgr/nsILoginManager.idl
 */

#ifndef __gen_nsILoginManager_h__
#define __gen_nsILoginManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsILoginInfo; /* forward declaration */

class nsIAutoCompleteResult; /* forward declaration */

class nsIDOMHTMLInputElement; /* forward declaration */

class nsIDOMHTMLFormElement; /* forward declaration */

class nsIPropertyBag; /* forward declaration */


/* starting interface:    nsILoginManager */
#define NS_ILOGINMANAGER_IID_STR "338c8597-1e32-4682-b5c7-cf8142c0bd1d"

#define NS_ILOGINMANAGER_IID \
  {0x338c8597, 0x1e32, 0x4682, \
    { 0xb5, 0xc7, 0xcf, 0x81, 0x42, 0xc0, 0xbd, 0x1d }}

class NS_NO_VTABLE nsILoginManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOGINMANAGER_IID)

  /* void addLogin (in nsILoginInfo aLogin); */
  NS_IMETHOD AddLogin(nsILoginInfo *aLogin) = 0;

  /* void removeLogin (in nsILoginInfo aLogin); */
  NS_IMETHOD RemoveLogin(nsILoginInfo *aLogin) = 0;

  /* void modifyLogin (in nsILoginInfo oldLogin, in nsISupports newLoginData); */
  NS_IMETHOD ModifyLogin(nsILoginInfo *oldLogin, nsISupports *newLoginData) = 0;

  /* void removeAllLogins (); */
  NS_IMETHOD RemoveAllLogins(void) = 0;

  /* void getAllLogins ([optional] out unsigned long count, [array, size_is (count), retval] out nsILoginInfo logins); */
  NS_IMETHOD GetAllLogins(uint32_t *count, nsILoginInfo * **logins) = 0;

  /* void getAllDisabledHosts ([optional] out unsigned long count, [array, size_is (count), retval] out wstring hostnames); */
  NS_IMETHOD GetAllDisabledHosts(uint32_t *count, PRUnichar * **hostnames) = 0;

  /* boolean getLoginSavingEnabled (in AString aHost); */
  NS_IMETHOD GetLoginSavingEnabled(const nsAString & aHost, bool *_retval) = 0;

  /* void setLoginSavingEnabled (in AString aHost, in boolean isEnabled); */
  NS_IMETHOD SetLoginSavingEnabled(const nsAString & aHost, bool isEnabled) = 0;

  /* void findLogins (out unsigned long count, in AString aHostname, in AString aActionURL, in AString aHttpRealm, [array, size_is (count), retval] out nsILoginInfo logins); */
  NS_IMETHOD FindLogins(uint32_t *count, const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, nsILoginInfo * **logins) = 0;

  /* unsigned long countLogins (in AString aHostname, in AString aActionURL, in AString aHttpRealm); */
  NS_IMETHOD CountLogins(const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, uint32_t *_retval) = 0;

  /* nsIAutoCompleteResult autoCompleteSearch (in AString aSearchString, in nsIAutoCompleteResult aPreviousResult, in nsIDOMHTMLInputElement aElement); */
  NS_IMETHOD AutoCompleteSearch(const nsAString & aSearchString, nsIAutoCompleteResult *aPreviousResult, nsIDOMHTMLInputElement *aElement, nsIAutoCompleteResult * *_retval) = 0;

  /* boolean fillForm (in nsIDOMHTMLFormElement aForm); */
  NS_IMETHOD FillForm(nsIDOMHTMLFormElement *aForm, bool *_retval) = 0;

  /* void searchLogins (out unsigned long count, in nsIPropertyBag matchData, [array, size_is (count), retval] out nsILoginInfo logins); */
  NS_IMETHOD SearchLogins(uint32_t *count, nsIPropertyBag *matchData, nsILoginInfo * **logins) = 0;

  /* readonly attribute boolean uiBusy; */
  NS_IMETHOD GetUiBusy(bool *aUiBusy) = 0;

  /* readonly attribute boolean isLoggedIn; */
  NS_IMETHOD GetIsLoggedIn(bool *aIsLoggedIn) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILoginManager, NS_ILOGINMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOGINMANAGER \
  NS_IMETHOD AddLogin(nsILoginInfo *aLogin); \
  NS_IMETHOD RemoveLogin(nsILoginInfo *aLogin); \
  NS_IMETHOD ModifyLogin(nsILoginInfo *oldLogin, nsISupports *newLoginData); \
  NS_IMETHOD RemoveAllLogins(void); \
  NS_IMETHOD GetAllLogins(uint32_t *count, nsILoginInfo * **logins); \
  NS_IMETHOD GetAllDisabledHosts(uint32_t *count, PRUnichar * **hostnames); \
  NS_IMETHOD GetLoginSavingEnabled(const nsAString & aHost, bool *_retval); \
  NS_IMETHOD SetLoginSavingEnabled(const nsAString & aHost, bool isEnabled); \
  NS_IMETHOD FindLogins(uint32_t *count, const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, nsILoginInfo * **logins); \
  NS_IMETHOD CountLogins(const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, uint32_t *_retval); \
  NS_IMETHOD AutoCompleteSearch(const nsAString & aSearchString, nsIAutoCompleteResult *aPreviousResult, nsIDOMHTMLInputElement *aElement, nsIAutoCompleteResult * *_retval); \
  NS_IMETHOD FillForm(nsIDOMHTMLFormElement *aForm, bool *_retval); \
  NS_IMETHOD SearchLogins(uint32_t *count, nsIPropertyBag *matchData, nsILoginInfo * **logins); \
  NS_IMETHOD GetUiBusy(bool *aUiBusy); \
  NS_IMETHOD GetIsLoggedIn(bool *aIsLoggedIn); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOGINMANAGER(_to) \
  NS_IMETHOD AddLogin(nsILoginInfo *aLogin) { return _to AddLogin(aLogin); } \
  NS_IMETHOD RemoveLogin(nsILoginInfo *aLogin) { return _to RemoveLogin(aLogin); } \
  NS_IMETHOD ModifyLogin(nsILoginInfo *oldLogin, nsISupports *newLoginData) { return _to ModifyLogin(oldLogin, newLoginData); } \
  NS_IMETHOD RemoveAllLogins(void) { return _to RemoveAllLogins(); } \
  NS_IMETHOD GetAllLogins(uint32_t *count, nsILoginInfo * **logins) { return _to GetAllLogins(count, logins); } \
  NS_IMETHOD GetAllDisabledHosts(uint32_t *count, PRUnichar * **hostnames) { return _to GetAllDisabledHosts(count, hostnames); } \
  NS_IMETHOD GetLoginSavingEnabled(const nsAString & aHost, bool *_retval) { return _to GetLoginSavingEnabled(aHost, _retval); } \
  NS_IMETHOD SetLoginSavingEnabled(const nsAString & aHost, bool isEnabled) { return _to SetLoginSavingEnabled(aHost, isEnabled); } \
  NS_IMETHOD FindLogins(uint32_t *count, const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, nsILoginInfo * **logins) { return _to FindLogins(count, aHostname, aActionURL, aHttpRealm, logins); } \
  NS_IMETHOD CountLogins(const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, uint32_t *_retval) { return _to CountLogins(aHostname, aActionURL, aHttpRealm, _retval); } \
  NS_IMETHOD AutoCompleteSearch(const nsAString & aSearchString, nsIAutoCompleteResult *aPreviousResult, nsIDOMHTMLInputElement *aElement, nsIAutoCompleteResult * *_retval) { return _to AutoCompleteSearch(aSearchString, aPreviousResult, aElement, _retval); } \
  NS_IMETHOD FillForm(nsIDOMHTMLFormElement *aForm, bool *_retval) { return _to FillForm(aForm, _retval); } \
  NS_IMETHOD SearchLogins(uint32_t *count, nsIPropertyBag *matchData, nsILoginInfo * **logins) { return _to SearchLogins(count, matchData, logins); } \
  NS_IMETHOD GetUiBusy(bool *aUiBusy) { return _to GetUiBusy(aUiBusy); } \
  NS_IMETHOD GetIsLoggedIn(bool *aIsLoggedIn) { return _to GetIsLoggedIn(aIsLoggedIn); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOGINMANAGER(_to) \
  NS_IMETHOD AddLogin(nsILoginInfo *aLogin) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddLogin(aLogin); } \
  NS_IMETHOD RemoveLogin(nsILoginInfo *aLogin) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveLogin(aLogin); } \
  NS_IMETHOD ModifyLogin(nsILoginInfo *oldLogin, nsISupports *newLoginData) { return !_to ? NS_ERROR_NULL_POINTER : _to->ModifyLogin(oldLogin, newLoginData); } \
  NS_IMETHOD RemoveAllLogins(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAllLogins(); } \
  NS_IMETHOD GetAllLogins(uint32_t *count, nsILoginInfo * **logins) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllLogins(count, logins); } \
  NS_IMETHOD GetAllDisabledHosts(uint32_t *count, PRUnichar * **hostnames) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllDisabledHosts(count, hostnames); } \
  NS_IMETHOD GetLoginSavingEnabled(const nsAString & aHost, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoginSavingEnabled(aHost, _retval); } \
  NS_IMETHOD SetLoginSavingEnabled(const nsAString & aHost, bool isEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLoginSavingEnabled(aHost, isEnabled); } \
  NS_IMETHOD FindLogins(uint32_t *count, const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, nsILoginInfo * **logins) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindLogins(count, aHostname, aActionURL, aHttpRealm, logins); } \
  NS_IMETHOD CountLogins(const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CountLogins(aHostname, aActionURL, aHttpRealm, _retval); } \
  NS_IMETHOD AutoCompleteSearch(const nsAString & aSearchString, nsIAutoCompleteResult *aPreviousResult, nsIDOMHTMLInputElement *aElement, nsIAutoCompleteResult * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AutoCompleteSearch(aSearchString, aPreviousResult, aElement, _retval); } \
  NS_IMETHOD FillForm(nsIDOMHTMLFormElement *aForm, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FillForm(aForm, _retval); } \
  NS_IMETHOD SearchLogins(uint32_t *count, nsIPropertyBag *matchData, nsILoginInfo * **logins) { return !_to ? NS_ERROR_NULL_POINTER : _to->SearchLogins(count, matchData, logins); } \
  NS_IMETHOD GetUiBusy(bool *aUiBusy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUiBusy(aUiBusy); } \
  NS_IMETHOD GetIsLoggedIn(bool *aIsLoggedIn) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsLoggedIn(aIsLoggedIn); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLoginManager : public nsILoginManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOGINMANAGER

  nsLoginManager();

private:
  ~nsLoginManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLoginManager, nsILoginManager)

nsLoginManager::nsLoginManager()
{
  /* member initializers and constructor code */
}

nsLoginManager::~nsLoginManager()
{
  /* destructor code */
}

/* void addLogin (in nsILoginInfo aLogin); */
NS_IMETHODIMP nsLoginManager::AddLogin(nsILoginInfo *aLogin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeLogin (in nsILoginInfo aLogin); */
NS_IMETHODIMP nsLoginManager::RemoveLogin(nsILoginInfo *aLogin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void modifyLogin (in nsILoginInfo oldLogin, in nsISupports newLoginData); */
NS_IMETHODIMP nsLoginManager::ModifyLogin(nsILoginInfo *oldLogin, nsISupports *newLoginData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAllLogins (); */
NS_IMETHODIMP nsLoginManager::RemoveAllLogins()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAllLogins ([optional] out unsigned long count, [array, size_is (count), retval] out nsILoginInfo logins); */
NS_IMETHODIMP nsLoginManager::GetAllLogins(uint32_t *count, nsILoginInfo * **logins)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAllDisabledHosts ([optional] out unsigned long count, [array, size_is (count), retval] out wstring hostnames); */
NS_IMETHODIMP nsLoginManager::GetAllDisabledHosts(uint32_t *count, PRUnichar * **hostnames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getLoginSavingEnabled (in AString aHost); */
NS_IMETHODIMP nsLoginManager::GetLoginSavingEnabled(const nsAString & aHost, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setLoginSavingEnabled (in AString aHost, in boolean isEnabled); */
NS_IMETHODIMP nsLoginManager::SetLoginSavingEnabled(const nsAString & aHost, bool isEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void findLogins (out unsigned long count, in AString aHostname, in AString aActionURL, in AString aHttpRealm, [array, size_is (count), retval] out nsILoginInfo logins); */
NS_IMETHODIMP nsLoginManager::FindLogins(uint32_t *count, const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, nsILoginInfo * **logins)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long countLogins (in AString aHostname, in AString aActionURL, in AString aHttpRealm); */
NS_IMETHODIMP nsLoginManager::CountLogins(const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAutoCompleteResult autoCompleteSearch (in AString aSearchString, in nsIAutoCompleteResult aPreviousResult, in nsIDOMHTMLInputElement aElement); */
NS_IMETHODIMP nsLoginManager::AutoCompleteSearch(const nsAString & aSearchString, nsIAutoCompleteResult *aPreviousResult, nsIDOMHTMLInputElement *aElement, nsIAutoCompleteResult * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean fillForm (in nsIDOMHTMLFormElement aForm); */
NS_IMETHODIMP nsLoginManager::FillForm(nsIDOMHTMLFormElement *aForm, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void searchLogins (out unsigned long count, in nsIPropertyBag matchData, [array, size_is (count), retval] out nsILoginInfo logins); */
NS_IMETHODIMP nsLoginManager::SearchLogins(uint32_t *count, nsIPropertyBag *matchData, nsILoginInfo * **logins)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean uiBusy; */
NS_IMETHODIMP nsLoginManager::GetUiBusy(bool *aUiBusy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isLoggedIn; */
NS_IMETHODIMP nsLoginManager::GetIsLoggedIn(bool *aIsLoggedIn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define NS_LOGINMANAGER_CONTRACTID "@mozilla.org/login-manager;1"

#endif /* __gen_nsILoginManager_h__ */

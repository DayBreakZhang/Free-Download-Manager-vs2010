/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\amIWebInstaller.idl
 */

#ifndef __gen_amIWebInstaller_h__
#define __gen_amIWebInstaller_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIVariant; /* forward declaration */

class amIInstallCallback; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    amIWebInstaller */
#define AMIWEBINSTALLER_IID_STR "4fdf4f84-73dc-4857-9bbe-84895e8afd5d"

#define AMIWEBINSTALLER_IID \
  {0x4fdf4f84, 0x73dc, 0x4857, \
    { 0x9b, 0xbe, 0x84, 0x89, 0x5e, 0x8a, 0xfd, 0x5d }}

class NS_NO_VTABLE amIWebInstaller : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(AMIWEBINSTALLER_IID)

  /* boolean isInstallEnabled (in AString aMimetype, in nsIURI aReferer); */
  NS_IMETHOD IsInstallEnabled(const nsAString & aMimetype, nsIURI *aReferer, bool *_retval) = 0;

  /* boolean installAddonsFromWebpage (in AString aMimetype, in nsIDOMWindow aWindow, in nsIURI aReferer, [array, size_is (aInstallCount)] in wstring aUris, [array, size_is (aInstallCount)] in wstring aHashes, [array, size_is (aInstallCount)] in wstring aNames, [array, size_is (aInstallCount)] in wstring aIcons, [optional] in amIInstallCallback aCallback, [optional] in uint32_t aInstallCount); */
  NS_IMETHOD InstallAddonsFromWebpage(const nsAString & aMimetype, nsIDOMWindow *aWindow, nsIURI *aReferer, const char16_t * *aUris, const char16_t * *aHashes, const char16_t * *aNames, const char16_t * *aIcons, amIInstallCallback *aCallback, uint32_t aInstallCount, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(amIWebInstaller, AMIWEBINSTALLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_AMIWEBINSTALLER \
  NS_IMETHOD IsInstallEnabled(const nsAString & aMimetype, nsIURI *aReferer, bool *_retval); \
  NS_IMETHOD InstallAddonsFromWebpage(const nsAString & aMimetype, nsIDOMWindow *aWindow, nsIURI *aReferer, const char16_t * *aUris, const char16_t * *aHashes, const char16_t * *aNames, const char16_t * *aIcons, amIInstallCallback *aCallback, uint32_t aInstallCount, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_AMIWEBINSTALLER(_to) \
  NS_IMETHOD IsInstallEnabled(const nsAString & aMimetype, nsIURI *aReferer, bool *_retval) { return _to IsInstallEnabled(aMimetype, aReferer, _retval); } \
  NS_IMETHOD InstallAddonsFromWebpage(const nsAString & aMimetype, nsIDOMWindow *aWindow, nsIURI *aReferer, const char16_t * *aUris, const char16_t * *aHashes, const char16_t * *aNames, const char16_t * *aIcons, amIInstallCallback *aCallback, uint32_t aInstallCount, bool *_retval) { return _to InstallAddonsFromWebpage(aMimetype, aWindow, aReferer, aUris, aHashes, aNames, aIcons, aCallback, aInstallCount, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_AMIWEBINSTALLER(_to) \
  NS_IMETHOD IsInstallEnabled(const nsAString & aMimetype, nsIURI *aReferer, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsInstallEnabled(aMimetype, aReferer, _retval); } \
  NS_IMETHOD InstallAddonsFromWebpage(const nsAString & aMimetype, nsIDOMWindow *aWindow, nsIURI *aReferer, const char16_t * *aUris, const char16_t * *aHashes, const char16_t * *aNames, const char16_t * *aIcons, amIInstallCallback *aCallback, uint32_t aInstallCount, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->InstallAddonsFromWebpage(aMimetype, aWindow, aReferer, aUris, aHashes, aNames, aIcons, aCallback, aInstallCount, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class amWebInstaller : public amIWebInstaller
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_AMIWEBINSTALLER

  amWebInstaller();

private:
  ~amWebInstaller();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(amWebInstaller, amIWebInstaller)

amWebInstaller::amWebInstaller()
{
  /* member initializers and constructor code */
}

amWebInstaller::~amWebInstaller()
{
  /* destructor code */
}

/* boolean isInstallEnabled (in AString aMimetype, in nsIURI aReferer); */
NS_IMETHODIMP amWebInstaller::IsInstallEnabled(const nsAString & aMimetype, nsIURI *aReferer, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean installAddonsFromWebpage (in AString aMimetype, in nsIDOMWindow aWindow, in nsIURI aReferer, [array, size_is (aInstallCount)] in wstring aUris, [array, size_is (aInstallCount)] in wstring aHashes, [array, size_is (aInstallCount)] in wstring aNames, [array, size_is (aInstallCount)] in wstring aIcons, [optional] in amIInstallCallback aCallback, [optional] in uint32_t aInstallCount); */
NS_IMETHODIMP amWebInstaller::InstallAddonsFromWebpage(const nsAString & aMimetype, nsIDOMWindow *aWindow, nsIURI *aReferer, const char16_t * *aUris, const char16_t * *aHashes, const char16_t * *aNames, const char16_t * *aIcons, amIInstallCallback *aCallback, uint32_t aInstallCount, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_amIWebInstaller_h__ */

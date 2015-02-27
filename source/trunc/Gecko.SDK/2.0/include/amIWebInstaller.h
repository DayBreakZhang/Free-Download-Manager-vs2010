/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/toolkit/mozapps/extensions/amIWebInstaller.idl
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
class nsIDOMWindowInternal; /* forward declaration */

class nsIVariant; /* forward declaration */

class amIInstallCallback; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    amIWebInstaller */
#define AMIWEBINSTALLER_IID_STR "4fdf4f84-73dc-4857-9bbe-84895e8afd5d"

#define AMIWEBINSTALLER_IID \
  {0x4fdf4f84, 0x73dc, 0x4857, \
    { 0x9b, 0xbe, 0x84, 0x89, 0x5e, 0x8a, 0xfd, 0x5d }}

/**
 * This interface is used to allow webpages to start installing add-ons.
 */
class NS_NO_VTABLE NS_SCRIPTABLE amIWebInstaller : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(AMIWEBINSTALLER_IID)

  /**
   * Checks if installation is enabled for a webpage.
   *
   * @param  aMimetype
   *         The mimetype for the add-on to be installed
   * @param  referer
   *         The URL of the webpage trying to install an add-on
   * @return true if installation is enabled
   */
  /* boolean isInstallEnabled (in AString aMimetype, in nsIURI aReferer); */
  NS_SCRIPTABLE NS_IMETHOD IsInstallEnabled(const nsAString & aMimetype, nsIURI *aReferer, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Installs an array of add-ons at the request of a webpage
   *
   * @param  aMimetype
   *         The mimetype for the add-ons
   * @param  aWindow
   *         The window installing the add-ons
   * @param  aReferer
   *         The URI for the webpage installing the add-ons
   * @param  aUris
   *         The URIs of add-ons to be installed
   * @param  aHashes
   *         The hashes for the add-ons to be installed
   * @param  aNames
   *         The names for the add-ons to be installed
   * @param  aIcons
   *         The icons for the add-ons to be installed
   * @param  aCallback
   *         An optional callback to notify about installation success and
   *         failure
   * @param  aInstallCount
   *         An optional argument including the number of add-ons to install
   * @return true if the installation was successfully started
   */
  /* boolean installAddonsFromWebpage (in AString aMimetype, in nsIDOMWindowInternal aWindow, in nsIURI aReferer, [array, size_is (aInstallCount)] in wstring aUris, [array, size_is (aInstallCount)] in wstring aHashes, [array, size_is (aInstallCount)] in wstring aNames, [array, size_is (aInstallCount)] in wstring aIcons, [optional] in amIInstallCallback aCallback, [optional] in PRUint32 aInstallCount); */
  NS_SCRIPTABLE NS_IMETHOD InstallAddonsFromWebpage(const nsAString & aMimetype, nsIDOMWindowInternal *aWindow, nsIURI *aReferer, const PRUnichar **aUris, const PRUnichar **aHashes, const PRUnichar **aNames, const PRUnichar **aIcons, amIInstallCallback *aCallback, PRUint32 aInstallCount, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(amIWebInstaller, AMIWEBINSTALLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_AMIWEBINSTALLER \
  NS_SCRIPTABLE NS_IMETHOD IsInstallEnabled(const nsAString & aMimetype, nsIURI *aReferer, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD InstallAddonsFromWebpage(const nsAString & aMimetype, nsIDOMWindowInternal *aWindow, nsIURI *aReferer, const PRUnichar **aUris, const PRUnichar **aHashes, const PRUnichar **aNames, const PRUnichar **aIcons, amIInstallCallback *aCallback, PRUint32 aInstallCount, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_AMIWEBINSTALLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD IsInstallEnabled(const nsAString & aMimetype, nsIURI *aReferer, PRBool *_retval NS_OUTPARAM) { return _to IsInstallEnabled(aMimetype, aReferer, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InstallAddonsFromWebpage(const nsAString & aMimetype, nsIDOMWindowInternal *aWindow, nsIURI *aReferer, const PRUnichar **aUris, const PRUnichar **aHashes, const PRUnichar **aNames, const PRUnichar **aIcons, amIInstallCallback *aCallback, PRUint32 aInstallCount, PRBool *_retval NS_OUTPARAM) { return _to InstallAddonsFromWebpage(aMimetype, aWindow, aReferer, aUris, aHashes, aNames, aIcons, aCallback, aInstallCount, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_AMIWEBINSTALLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD IsInstallEnabled(const nsAString & aMimetype, nsIURI *aReferer, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsInstallEnabled(aMimetype, aReferer, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InstallAddonsFromWebpage(const nsAString & aMimetype, nsIDOMWindowInternal *aWindow, nsIURI *aReferer, const PRUnichar **aUris, const PRUnichar **aHashes, const PRUnichar **aNames, const PRUnichar **aIcons, amIInstallCallback *aCallback, PRUint32 aInstallCount, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->InstallAddonsFromWebpage(aMimetype, aWindow, aReferer, aUris, aHashes, aNames, aIcons, aCallback, aInstallCount, _retval); } 

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
NS_IMETHODIMP amWebInstaller::IsInstallEnabled(const nsAString & aMimetype, nsIURI *aReferer, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean installAddonsFromWebpage (in AString aMimetype, in nsIDOMWindowInternal aWindow, in nsIURI aReferer, [array, size_is (aInstallCount)] in wstring aUris, [array, size_is (aInstallCount)] in wstring aHashes, [array, size_is (aInstallCount)] in wstring aNames, [array, size_is (aInstallCount)] in wstring aIcons, [optional] in amIInstallCallback aCallback, [optional] in PRUint32 aInstallCount); */
NS_IMETHODIMP amWebInstaller::InstallAddonsFromWebpage(const nsAString & aMimetype, nsIDOMWindowInternal *aWindow, nsIURI *aReferer, const PRUnichar **aUris, const PRUnichar **aHashes, const PRUnichar **aNames, const PRUnichar **aIcons, amIInstallCallback *aCallback, PRUint32 aInstallCount, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_amIWebInstaller_h__ */

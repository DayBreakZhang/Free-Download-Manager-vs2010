/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/chrome/public/nsIToolkitChromeRegistry.idl
 */

#ifndef __gen_nsIToolkitChromeRegistry_h__
#define __gen_nsIToolkitChromeRegistry_h__


#ifndef __gen_nsIChromeRegistry_h__
#include "nsIChromeRegistry.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIUTF8StringEnumerator; /* forward declaration */


/* starting interface:    nsIToolkitChromeRegistry */
#define NS_ITOOLKITCHROMEREGISTRY_IID_STR "8727651c-9530-45a0-b81e-0e0690c30c50"

#define NS_ITOOLKITCHROMEREGISTRY_IID \
  {0x8727651c, 0x9530, 0x45a0, \
    { 0xb8, 0x1e, 0x0e, 0x06, 0x90, 0xc3, 0x0c, 0x50 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIToolkitChromeRegistry : public nsIXULChromeRegistry {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITOOLKITCHROMEREGISTRY_IID)

  /**
   * If the OS has a "high-visibility" or "disabled-friendly" theme set,
   * we want to force mozilla into the classic theme, which (for the most part
   * obeys the system color/font settings. We cannot do this at initialization,
   * because it depends on the toolkit (GTK2) being initialized, which is
   * not the case in some embedding situations. Embedders have to manually
   * call this method during the startup process.
   */
  /* void checkForOSAccessibility (); */
  NS_SCRIPTABLE NS_IMETHOD CheckForOSAccessibility(void) = 0;

  /**
   * Get a list of locales available for the specified package.
   */
  /* nsIUTF8StringEnumerator getLocalesForPackage (in AUTF8String aPackage); */
  NS_SCRIPTABLE NS_IMETHOD GetLocalesForPackage(const nsACString & aPackage, nsIUTF8StringEnumerator **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIToolkitChromeRegistry, NS_ITOOLKITCHROMEREGISTRY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITOOLKITCHROMEREGISTRY \
  NS_SCRIPTABLE NS_IMETHOD CheckForOSAccessibility(void); \
  NS_SCRIPTABLE NS_IMETHOD GetLocalesForPackage(const nsACString & aPackage, nsIUTF8StringEnumerator **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITOOLKITCHROMEREGISTRY(_to) \
  NS_SCRIPTABLE NS_IMETHOD CheckForOSAccessibility(void) { return _to CheckForOSAccessibility(); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocalesForPackage(const nsACString & aPackage, nsIUTF8StringEnumerator **_retval NS_OUTPARAM) { return _to GetLocalesForPackage(aPackage, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITOOLKITCHROMEREGISTRY(_to) \
  NS_SCRIPTABLE NS_IMETHOD CheckForOSAccessibility(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckForOSAccessibility(); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocalesForPackage(const nsACString & aPackage, nsIUTF8StringEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalesForPackage(aPackage, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsToolkitChromeRegistry : public nsIToolkitChromeRegistry
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITOOLKITCHROMEREGISTRY

  nsToolkitChromeRegistry();

private:
  ~nsToolkitChromeRegistry();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsToolkitChromeRegistry, nsIToolkitChromeRegistry)

nsToolkitChromeRegistry::nsToolkitChromeRegistry()
{
  /* member initializers and constructor code */
}

nsToolkitChromeRegistry::~nsToolkitChromeRegistry()
{
  /* destructor code */
}

/* void checkForOSAccessibility (); */
NS_IMETHODIMP nsToolkitChromeRegistry::CheckForOSAccessibility()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIUTF8StringEnumerator getLocalesForPackage (in AUTF8String aPackage); */
NS_IMETHODIMP nsToolkitChromeRegistry::GetLocalesForPackage(const nsACString & aPackage, nsIUTF8StringEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIToolkitChromeRegistry_h__ */

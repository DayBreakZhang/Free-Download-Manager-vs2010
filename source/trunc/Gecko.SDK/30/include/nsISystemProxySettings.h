/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISystemProxySettings.idl
 */

#ifndef __gen_nsISystemProxySettings_h__
#define __gen_nsISystemProxySettings_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISystemProxySettings */
#define NS_ISYSTEMPROXYSETTINGS_IID_STR "971591cd-277e-409a-bbf6-0a79879cd307"

#define NS_ISYSTEMPROXYSETTINGS_IID \
  {0x971591cd, 0x277e, 0x409a, \
    { 0xbb, 0xf6, 0x0a, 0x79, 0x87, 0x9c, 0xd3, 0x07 }}

class NS_NO_VTABLE nsISystemProxySettings : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISYSTEMPROXYSETTINGS_IID)

  /* readonly attribute bool mainThreadOnly; */
  NS_IMETHOD GetMainThreadOnly(bool *aMainThreadOnly) = 0;

  /* readonly attribute AUTF8String PACURI; */
  NS_IMETHOD GetPACURI(nsACString & aPACURI) = 0;

  /* AUTF8String getProxyForURI (in AUTF8String testSpec, in AUTF8String testScheme, in AUTF8String testHost, in int32_t testPort); */
  NS_IMETHOD GetProxyForURI(const nsACString & testSpec, const nsACString & testScheme, const nsACString & testHost, int32_t testPort, nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISystemProxySettings, NS_ISYSTEMPROXYSETTINGS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISYSTEMPROXYSETTINGS \
  NS_IMETHOD GetMainThreadOnly(bool *aMainThreadOnly); \
  NS_IMETHOD GetPACURI(nsACString & aPACURI); \
  NS_IMETHOD GetProxyForURI(const nsACString & testSpec, const nsACString & testScheme, const nsACString & testHost, int32_t testPort, nsACString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISYSTEMPROXYSETTINGS(_to) \
  NS_IMETHOD GetMainThreadOnly(bool *aMainThreadOnly) { return _to GetMainThreadOnly(aMainThreadOnly); } \
  NS_IMETHOD GetPACURI(nsACString & aPACURI) { return _to GetPACURI(aPACURI); } \
  NS_IMETHOD GetProxyForURI(const nsACString & testSpec, const nsACString & testScheme, const nsACString & testHost, int32_t testPort, nsACString & _retval) { return _to GetProxyForURI(testSpec, testScheme, testHost, testPort, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISYSTEMPROXYSETTINGS(_to) \
  NS_IMETHOD GetMainThreadOnly(bool *aMainThreadOnly) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMainThreadOnly(aMainThreadOnly); } \
  NS_IMETHOD GetPACURI(nsACString & aPACURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPACURI(aPACURI); } \
  NS_IMETHOD GetProxyForURI(const nsACString & testSpec, const nsACString & testScheme, const nsACString & testHost, int32_t testPort, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProxyForURI(testSpec, testScheme, testHost, testPort, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSystemProxySettings : public nsISystemProxySettings
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISYSTEMPROXYSETTINGS

  nsSystemProxySettings();

private:
  ~nsSystemProxySettings();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSystemProxySettings, nsISystemProxySettings)

nsSystemProxySettings::nsSystemProxySettings()
{
  /* member initializers and constructor code */
}

nsSystemProxySettings::~nsSystemProxySettings()
{
  /* destructor code */
}

/* readonly attribute bool mainThreadOnly; */
NS_IMETHODIMP nsSystemProxySettings::GetMainThreadOnly(bool *aMainThreadOnly)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String PACURI; */
NS_IMETHODIMP nsSystemProxySettings::GetPACURI(nsACString & aPACURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getProxyForURI (in AUTF8String testSpec, in AUTF8String testScheme, in AUTF8String testHost, in int32_t testPort); */
NS_IMETHODIMP nsSystemProxySettings::GetProxyForURI(const nsACString & testSpec, const nsACString & testScheme, const nsACString & testHost, int32_t testPort, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISystemProxySettings_h__ */

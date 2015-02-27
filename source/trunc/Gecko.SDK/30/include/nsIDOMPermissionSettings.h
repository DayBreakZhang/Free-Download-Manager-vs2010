/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMPermissionSettings.idl
 */

#ifndef __gen_nsIDOMPermissionSettings_h__
#define __gen_nsIDOMPermissionSettings_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDOMRequest; /* forward declaration */


/* starting interface:    nsIDOMPermissionSettings */
#define NS_IDOMPERMISSIONSETTINGS_IID_STR "18390770-02ab-11e2-a21f-0800200c9a66"

#define NS_IDOMPERMISSIONSETTINGS_IID \
  {0x18390770, 0x02ab, 0x11e2, \
    { 0xa2, 0x1f, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIDOMPermissionSettings : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMPERMISSIONSETTINGS_IID)

  /* DOMString get (in DOMString permission, in DOMString manifestURI, in DOMString origin, in bool browserFlag); */
  NS_IMETHOD Get(const nsAString & permission, const nsAString & manifestURI, const nsAString & origin, bool browserFlag, nsAString & _retval) = 0;

  /* void set (in DOMString permission, in DOMString value, in DOMString manifestURI, in DOMString origin, in bool browserFlag); */
  NS_IMETHOD Set(const nsAString & permission, const nsAString & value, const nsAString & manifestURI, const nsAString & origin, bool browserFlag) = 0;

  /* bool isExplicit (in DOMString permission, in DOMString manifestURI, in DOMString origin, in bool browserFlag); */
  NS_IMETHOD IsExplicit(const nsAString & permission, const nsAString & manifestURI, const nsAString & origin, bool browserFlag, bool *_retval) = 0;

  /* void remove (in DOMString permission, in DOMString manifestURI, in DOMString origin); */
  NS_IMETHOD Remove(const nsAString & permission, const nsAString & manifestURI, const nsAString & origin) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMPermissionSettings, NS_IDOMPERMISSIONSETTINGS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMPERMISSIONSETTINGS \
  NS_IMETHOD Get(const nsAString & permission, const nsAString & manifestURI, const nsAString & origin, bool browserFlag, nsAString & _retval); \
  NS_IMETHOD Set(const nsAString & permission, const nsAString & value, const nsAString & manifestURI, const nsAString & origin, bool browserFlag); \
  NS_IMETHOD IsExplicit(const nsAString & permission, const nsAString & manifestURI, const nsAString & origin, bool browserFlag, bool *_retval); \
  NS_IMETHOD Remove(const nsAString & permission, const nsAString & manifestURI, const nsAString & origin); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMPERMISSIONSETTINGS(_to) \
  NS_IMETHOD Get(const nsAString & permission, const nsAString & manifestURI, const nsAString & origin, bool browserFlag, nsAString & _retval) { return _to Get(permission, manifestURI, origin, browserFlag, _retval); } \
  NS_IMETHOD Set(const nsAString & permission, const nsAString & value, const nsAString & manifestURI, const nsAString & origin, bool browserFlag) { return _to Set(permission, value, manifestURI, origin, browserFlag); } \
  NS_IMETHOD IsExplicit(const nsAString & permission, const nsAString & manifestURI, const nsAString & origin, bool browserFlag, bool *_retval) { return _to IsExplicit(permission, manifestURI, origin, browserFlag, _retval); } \
  NS_IMETHOD Remove(const nsAString & permission, const nsAString & manifestURI, const nsAString & origin) { return _to Remove(permission, manifestURI, origin); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMPERMISSIONSETTINGS(_to) \
  NS_IMETHOD Get(const nsAString & permission, const nsAString & manifestURI, const nsAString & origin, bool browserFlag, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(permission, manifestURI, origin, browserFlag, _retval); } \
  NS_IMETHOD Set(const nsAString & permission, const nsAString & value, const nsAString & manifestURI, const nsAString & origin, bool browserFlag) { return !_to ? NS_ERROR_NULL_POINTER : _to->Set(permission, value, manifestURI, origin, browserFlag); } \
  NS_IMETHOD IsExplicit(const nsAString & permission, const nsAString & manifestURI, const nsAString & origin, bool browserFlag, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsExplicit(permission, manifestURI, origin, browserFlag, _retval); } \
  NS_IMETHOD Remove(const nsAString & permission, const nsAString & manifestURI, const nsAString & origin) { return !_to ? NS_ERROR_NULL_POINTER : _to->Remove(permission, manifestURI, origin); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMPermissionSettings : public nsIDOMPermissionSettings
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMPERMISSIONSETTINGS

  nsDOMPermissionSettings();

private:
  ~nsDOMPermissionSettings();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMPermissionSettings, nsIDOMPermissionSettings)

nsDOMPermissionSettings::nsDOMPermissionSettings()
{
  /* member initializers and constructor code */
}

nsDOMPermissionSettings::~nsDOMPermissionSettings()
{
  /* destructor code */
}

/* DOMString get (in DOMString permission, in DOMString manifestURI, in DOMString origin, in bool browserFlag); */
NS_IMETHODIMP nsDOMPermissionSettings::Get(const nsAString & permission, const nsAString & manifestURI, const nsAString & origin, bool browserFlag, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void set (in DOMString permission, in DOMString value, in DOMString manifestURI, in DOMString origin, in bool browserFlag); */
NS_IMETHODIMP nsDOMPermissionSettings::Set(const nsAString & permission, const nsAString & value, const nsAString & manifestURI, const nsAString & origin, bool browserFlag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool isExplicit (in DOMString permission, in DOMString manifestURI, in DOMString origin, in bool browserFlag); */
NS_IMETHODIMP nsDOMPermissionSettings::IsExplicit(const nsAString & permission, const nsAString & manifestURI, const nsAString & origin, bool browserFlag, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void remove (in DOMString permission, in DOMString manifestURI, in DOMString origin); */
NS_IMETHODIMP nsDOMPermissionSettings::Remove(const nsAString & permission, const nsAString & manifestURI, const nsAString & origin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMPermissionSettings_h__ */

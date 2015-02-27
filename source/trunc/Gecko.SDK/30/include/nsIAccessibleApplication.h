/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAccessibleApplication.idl
 */

#ifndef __gen_nsIAccessibleApplication_h__
#define __gen_nsIAccessibleApplication_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAccessibleApplication */
#define NS_IACCESSIBLEAPPLICATION_IID_STR "79251626-387c-4531-89f3-680d31d6cf05"

#define NS_IACCESSIBLEAPPLICATION_IID \
  {0x79251626, 0x387c, 0x4531, \
    { 0x89, 0xf3, 0x68, 0x0d, 0x31, 0xd6, 0xcf, 0x05 }}

class NS_NO_VTABLE nsIAccessibleApplication : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEAPPLICATION_IID)

  /* readonly attribute DOMString appName; */
  NS_IMETHOD GetAppName(nsAString & aAppName) = 0;

  /* readonly attribute DOMString appVersion; */
  NS_IMETHOD GetAppVersion(nsAString & aAppVersion) = 0;

  /* readonly attribute DOMString platformName; */
  NS_IMETHOD GetPlatformName(nsAString & aPlatformName) = 0;

  /* readonly attribute DOMString platformVersion; */
  NS_IMETHOD GetPlatformVersion(nsAString & aPlatformVersion) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleApplication, NS_IACCESSIBLEAPPLICATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEAPPLICATION \
  NS_IMETHOD GetAppName(nsAString & aAppName); \
  NS_IMETHOD GetAppVersion(nsAString & aAppVersion); \
  NS_IMETHOD GetPlatformName(nsAString & aPlatformName); \
  NS_IMETHOD GetPlatformVersion(nsAString & aPlatformVersion); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEAPPLICATION(_to) \
  NS_IMETHOD GetAppName(nsAString & aAppName) { return _to GetAppName(aAppName); } \
  NS_IMETHOD GetAppVersion(nsAString & aAppVersion) { return _to GetAppVersion(aAppVersion); } \
  NS_IMETHOD GetPlatformName(nsAString & aPlatformName) { return _to GetPlatformName(aPlatformName); } \
  NS_IMETHOD GetPlatformVersion(nsAString & aPlatformVersion) { return _to GetPlatformVersion(aPlatformVersion); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEAPPLICATION(_to) \
  NS_IMETHOD GetAppName(nsAString & aAppName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppName(aAppName); } \
  NS_IMETHOD GetAppVersion(nsAString & aAppVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppVersion(aAppVersion); } \
  NS_IMETHOD GetPlatformName(nsAString & aPlatformName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlatformName(aPlatformName); } \
  NS_IMETHOD GetPlatformVersion(nsAString & aPlatformVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlatformVersion(aPlatformVersion); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleApplication : public nsIAccessibleApplication
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEAPPLICATION

  nsAccessibleApplication();

private:
  ~nsAccessibleApplication();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleApplication, nsIAccessibleApplication)

nsAccessibleApplication::nsAccessibleApplication()
{
  /* member initializers and constructor code */
}

nsAccessibleApplication::~nsAccessibleApplication()
{
  /* destructor code */
}

/* readonly attribute DOMString appName; */
NS_IMETHODIMP nsAccessibleApplication::GetAppName(nsAString & aAppName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString appVersion; */
NS_IMETHODIMP nsAccessibleApplication::GetAppVersion(nsAString & aAppVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString platformName; */
NS_IMETHODIMP nsAccessibleApplication::GetPlatformName(nsAString & aPlatformName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString platformVersion; */
NS_IMETHODIMP nsAccessibleApplication::GetPlatformVersion(nsAString & aPlatformVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleApplication_h__ */

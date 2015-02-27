/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/toolkit/components/webapps/nsIWebappsSupport.idl
 */

#ifndef __gen_nsIWebappsSupport_h__
#define __gen_nsIWebappsSupport_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIWebappsSupport */
#define NS_IWEBAPPSSUPPORT_IID_STR "adb91273-0cf1-4bbe-a37b-22e660192e2a"

#define NS_IWEBAPPSSUPPORT_IID \
  {0xadb91273, 0x0cf1, 0x4bbe, \
    { 0xa3, 0x7b, 0x22, 0xe6, 0x60, 0x19, 0x2e, 0x2a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWebappsSupport : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBAPPSSUPPORT_IID)

  /**
   * This method installs a web app.
   *
   * @param title     the user-friendly name of the application.
   * @param uri       the uri of the web app.
   * @param iconData  a base64 encoded representation of the application's icon.
   */
  /* void installApplication (in wstring title, in wstring uri, in wstring iconUri, in wstring iconData); */
  NS_SCRIPTABLE NS_IMETHOD InstallApplication(const PRUnichar *title, const PRUnichar *uri, const PRUnichar *iconUri, const PRUnichar *iconData) = 0;

  /**
   * Checks is a web app is already installed
   *
   * @param uri the uri of the web app
   * @return true if the web app is installed, false if it's not installed
   */
  /* boolean isApplicationInstalled (in wstring uri); */
  NS_SCRIPTABLE NS_IMETHOD IsApplicationInstalled(const PRUnichar *uri, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebappsSupport, NS_IWEBAPPSSUPPORT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBAPPSSUPPORT \
  NS_SCRIPTABLE NS_IMETHOD InstallApplication(const PRUnichar *title, const PRUnichar *uri, const PRUnichar *iconUri, const PRUnichar *iconData); \
  NS_SCRIPTABLE NS_IMETHOD IsApplicationInstalled(const PRUnichar *uri, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBAPPSSUPPORT(_to) \
  NS_SCRIPTABLE NS_IMETHOD InstallApplication(const PRUnichar *title, const PRUnichar *uri, const PRUnichar *iconUri, const PRUnichar *iconData) { return _to InstallApplication(title, uri, iconUri, iconData); } \
  NS_SCRIPTABLE NS_IMETHOD IsApplicationInstalled(const PRUnichar *uri, PRBool *_retval NS_OUTPARAM) { return _to IsApplicationInstalled(uri, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBAPPSSUPPORT(_to) \
  NS_SCRIPTABLE NS_IMETHOD InstallApplication(const PRUnichar *title, const PRUnichar *uri, const PRUnichar *iconUri, const PRUnichar *iconData) { return !_to ? NS_ERROR_NULL_POINTER : _to->InstallApplication(title, uri, iconUri, iconData); } \
  NS_SCRIPTABLE NS_IMETHOD IsApplicationInstalled(const PRUnichar *uri, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsApplicationInstalled(uri, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebappsSupport : public nsIWebappsSupport
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBAPPSSUPPORT

  nsWebappsSupport();

private:
  ~nsWebappsSupport();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebappsSupport, nsIWebappsSupport)

nsWebappsSupport::nsWebappsSupport()
{
  /* member initializers and constructor code */
}

nsWebappsSupport::~nsWebappsSupport()
{
  /* destructor code */
}

/* void installApplication (in wstring title, in wstring uri, in wstring iconUri, in wstring iconData); */
NS_IMETHODIMP nsWebappsSupport::InstallApplication(const PRUnichar *title, const PRUnichar *uri, const PRUnichar *iconUri, const PRUnichar *iconData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isApplicationInstalled (in wstring uri); */
NS_IMETHODIMP nsWebappsSupport::IsApplicationInstalled(const PRUnichar *uri, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebappsSupport_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xulrunner/setup/nsIXULAppInstall.idl
 */

#ifndef __gen_nsIXULAppInstall_h__
#define __gen_nsIXULAppInstall_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */


/* starting interface:    nsIXULAppInstall */
#define NS_IXULAPPINSTALL_IID_STR "800ace15-6b38-48c4-b057-7928378f6cd2"

#define NS_IXULAPPINSTALL_IID \
  {0x800ace15, 0x6b38, 0x48c4, \
    { 0xb0, 0x57, 0x79, 0x28, 0x37, 0x8f, 0x6c, 0xd2 }}

class NS_NO_VTABLE nsIXULAppInstall : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULAPPINSTALL_IID)

  /* void installApplication (in nsIFile aAppFile, in nsIFile aDirectory, in AString aLeafName); */
  NS_IMETHOD InstallApplication(nsIFile *aAppFile, nsIFile *aDirectory, const nsAString & aLeafName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULAppInstall, NS_IXULAPPINSTALL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULAPPINSTALL \
  NS_IMETHOD InstallApplication(nsIFile *aAppFile, nsIFile *aDirectory, const nsAString & aLeafName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULAPPINSTALL(_to) \
  NS_IMETHOD InstallApplication(nsIFile *aAppFile, nsIFile *aDirectory, const nsAString & aLeafName) { return _to InstallApplication(aAppFile, aDirectory, aLeafName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULAPPINSTALL(_to) \
  NS_IMETHOD InstallApplication(nsIFile *aAppFile, nsIFile *aDirectory, const nsAString & aLeafName) { return !_to ? NS_ERROR_NULL_POINTER : _to->InstallApplication(aAppFile, aDirectory, aLeafName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULAppInstall : public nsIXULAppInstall
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULAPPINSTALL

  nsXULAppInstall();

private:
  ~nsXULAppInstall();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXULAppInstall, nsIXULAppInstall)

nsXULAppInstall::nsXULAppInstall()
{
  /* member initializers and constructor code */
}

nsXULAppInstall::~nsXULAppInstall()
{
  /* destructor code */
}

/* void installApplication (in nsIFile aAppFile, in nsIFile aDirectory, in AString aLeafName); */
NS_IMETHODIMP nsXULAppInstall::InstallApplication(nsIFile *aAppFile, nsIFile *aDirectory, const nsAString & aLeafName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXULAppInstall_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/toolkit/profile/nsIProfileMigrator.idl
 */

#ifndef __gen_nsIProfileMigrator_h__
#define __gen_nsIProfileMigrator_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */


/* starting interface:    nsIProfileStartup */
#define NS_IPROFILESTARTUP_IID_STR "048e5ca1-0eb7-4bb1-a9a2-a36f7d4e0e3c"

#define NS_IPROFILESTARTUP_IID \
  {0x048e5ca1, 0x0eb7, 0x4bb1, \
    { 0xa9, 0xa2, 0xa3, 0x6f, 0x7d, 0x4e, 0x0e, 0x3c }}

class NS_NO_VTABLE nsIProfileStartup : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROFILESTARTUP_IID)

  /* readonly attribute nsIFile directory; */
  NS_IMETHOD GetDirectory(nsIFile * *aDirectory) = 0;

  /* void doStartup (); */
  NS_IMETHOD DoStartup(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProfileStartup, NS_IPROFILESTARTUP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROFILESTARTUP \
  NS_IMETHOD GetDirectory(nsIFile * *aDirectory); \
  NS_IMETHOD DoStartup(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROFILESTARTUP(_to) \
  NS_IMETHOD GetDirectory(nsIFile * *aDirectory) { return _to GetDirectory(aDirectory); } \
  NS_IMETHOD DoStartup(void) { return _to DoStartup(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROFILESTARTUP(_to) \
  NS_IMETHOD GetDirectory(nsIFile * *aDirectory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDirectory(aDirectory); } \
  NS_IMETHOD DoStartup(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoStartup(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProfileStartup : public nsIProfileStartup
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROFILESTARTUP

  nsProfileStartup();

private:
  ~nsProfileStartup();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProfileStartup, nsIProfileStartup)

nsProfileStartup::nsProfileStartup()
{
  /* member initializers and constructor code */
}

nsProfileStartup::~nsProfileStartup()
{
  /* destructor code */
}

/* readonly attribute nsIFile directory; */
NS_IMETHODIMP nsProfileStartup::GetDirectory(nsIFile * *aDirectory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doStartup (); */
NS_IMETHODIMP nsProfileStartup::DoStartup()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIProfileMigrator */
#define NS_IPROFILEMIGRATOR_IID_STR "3df284a5-2258-4d46-a664-761ecdc04c22"

#define NS_IPROFILEMIGRATOR_IID \
  {0x3df284a5, 0x2258, 0x4d46, \
    { 0xa6, 0x64, 0x76, 0x1e, 0xcd, 0xc0, 0x4c, 0x22 }}

class NS_NO_VTABLE nsIProfileMigrator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROFILEMIGRATOR_IID)

  /* void migrate (in nsIProfileStartup aStartup, in ACString aKey); */
  NS_IMETHOD Migrate(nsIProfileStartup *aStartup, const nsACString & aKey) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProfileMigrator, NS_IPROFILEMIGRATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROFILEMIGRATOR \
  NS_IMETHOD Migrate(nsIProfileStartup *aStartup, const nsACString & aKey); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROFILEMIGRATOR(_to) \
  NS_IMETHOD Migrate(nsIProfileStartup *aStartup, const nsACString & aKey) { return _to Migrate(aStartup, aKey); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROFILEMIGRATOR(_to) \
  NS_IMETHOD Migrate(nsIProfileStartup *aStartup, const nsACString & aKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->Migrate(aStartup, aKey); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProfileMigrator : public nsIProfileMigrator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROFILEMIGRATOR

  nsProfileMigrator();

private:
  ~nsProfileMigrator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProfileMigrator, nsIProfileMigrator)

nsProfileMigrator::nsProfileMigrator()
{
  /* member initializers and constructor code */
}

nsProfileMigrator::~nsProfileMigrator()
{
  /* destructor code */
}

/* void migrate (in nsIProfileStartup aStartup, in ACString aKey); */
NS_IMETHODIMP nsProfileMigrator::Migrate(nsIProfileStartup *aStartup, const nsACString & aKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_PROFILEMIGRATOR_CONTRACTID "@mozilla.org/toolkit/profile-migrator;1"

#endif /* __gen_nsIProfileMigrator_h__ */

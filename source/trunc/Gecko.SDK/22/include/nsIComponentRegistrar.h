/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/components/nsIComponentRegistrar.idl
 */

#ifndef __gen_nsIComponentRegistrar_h__
#define __gen_nsIComponentRegistrar_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */

class nsIFactory; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */


/* starting interface:    nsIComponentRegistrar */
#define NS_ICOMPONENTREGISTRAR_IID_STR "2417cbfe-65ad-48a6-b4b6-eb84db174392"

#define NS_ICOMPONENTREGISTRAR_IID \
  {0x2417cbfe, 0x65ad, 0x48a6, \
    { 0xb4, 0xb6, 0xeb, 0x84, 0xdb, 0x17, 0x43, 0x92 }}

class NS_NO_VTABLE nsIComponentRegistrar : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOMPONENTREGISTRAR_IID)

  /* void autoRegister (in nsIFile aSpec); */
  NS_IMETHOD AutoRegister(nsIFile *aSpec) = 0;

  /* void autoUnregister (in nsIFile aSpec); */
  NS_IMETHOD AutoUnregister(nsIFile *aSpec) = 0;

  /* void registerFactory (in nsCIDRef aClass, in string aClassName, in string aContractID, in nsIFactory aFactory); */
  NS_IMETHOD RegisterFactory(const nsCID & aClass, const char * aClassName, const char * aContractID, nsIFactory *aFactory) = 0;

  /* void unregisterFactory (in nsCIDRef aClass, in nsIFactory aFactory); */
  NS_IMETHOD UnregisterFactory(const nsCID & aClass, nsIFactory *aFactory) = 0;

  /* void registerFactoryLocation (in nsCIDRef aClass, in string aClassName, in string aContractID, in nsIFile aFile, in string aLoaderStr, in string aType); */
  NS_IMETHOD RegisterFactoryLocation(const nsCID & aClass, const char * aClassName, const char * aContractID, nsIFile *aFile, const char * aLoaderStr, const char * aType) = 0;

  /* void unregisterFactoryLocation (in nsCIDRef aClass, in nsIFile aFile); */
  NS_IMETHOD UnregisterFactoryLocation(const nsCID & aClass, nsIFile *aFile) = 0;

  /* boolean isCIDRegistered (in nsCIDRef aClass); */
  NS_IMETHOD IsCIDRegistered(const nsCID & aClass, bool *_retval) = 0;

  /* boolean isContractIDRegistered (in string aContractID); */
  NS_IMETHOD IsContractIDRegistered(const char * aContractID, bool *_retval) = 0;

  /* nsISimpleEnumerator enumerateCIDs (); */
  NS_IMETHOD EnumerateCIDs(nsISimpleEnumerator * *_retval) = 0;

  /* nsISimpleEnumerator enumerateContractIDs (); */
  NS_IMETHOD EnumerateContractIDs(nsISimpleEnumerator * *_retval) = 0;

  /* string CIDToContractID (in nsCIDRef aClass); */
  NS_IMETHOD CIDToContractID(const nsCID & aClass, char * *_retval) = 0;

  /* nsCIDPtr contractIDToCID (in string aContractID); */
  NS_IMETHOD ContractIDToCID(const char * aContractID, nsCID **_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIComponentRegistrar, NS_ICOMPONENTREGISTRAR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOMPONENTREGISTRAR \
  NS_IMETHOD AutoRegister(nsIFile *aSpec); \
  NS_IMETHOD AutoUnregister(nsIFile *aSpec); \
  NS_IMETHOD RegisterFactory(const nsCID & aClass, const char * aClassName, const char * aContractID, nsIFactory *aFactory); \
  NS_IMETHOD UnregisterFactory(const nsCID & aClass, nsIFactory *aFactory); \
  NS_IMETHOD RegisterFactoryLocation(const nsCID & aClass, const char * aClassName, const char * aContractID, nsIFile *aFile, const char * aLoaderStr, const char * aType); \
  NS_IMETHOD UnregisterFactoryLocation(const nsCID & aClass, nsIFile *aFile); \
  NS_IMETHOD IsCIDRegistered(const nsCID & aClass, bool *_retval); \
  NS_IMETHOD IsContractIDRegistered(const char * aContractID, bool *_retval); \
  NS_IMETHOD EnumerateCIDs(nsISimpleEnumerator * *_retval); \
  NS_IMETHOD EnumerateContractIDs(nsISimpleEnumerator * *_retval); \
  NS_IMETHOD CIDToContractID(const nsCID & aClass, char * *_retval); \
  NS_IMETHOD ContractIDToCID(const char * aContractID, nsCID **_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOMPONENTREGISTRAR(_to) \
  NS_IMETHOD AutoRegister(nsIFile *aSpec) { return _to AutoRegister(aSpec); } \
  NS_IMETHOD AutoUnregister(nsIFile *aSpec) { return _to AutoUnregister(aSpec); } \
  NS_IMETHOD RegisterFactory(const nsCID & aClass, const char * aClassName, const char * aContractID, nsIFactory *aFactory) { return _to RegisterFactory(aClass, aClassName, aContractID, aFactory); } \
  NS_IMETHOD UnregisterFactory(const nsCID & aClass, nsIFactory *aFactory) { return _to UnregisterFactory(aClass, aFactory); } \
  NS_IMETHOD RegisterFactoryLocation(const nsCID & aClass, const char * aClassName, const char * aContractID, nsIFile *aFile, const char * aLoaderStr, const char * aType) { return _to RegisterFactoryLocation(aClass, aClassName, aContractID, aFile, aLoaderStr, aType); } \
  NS_IMETHOD UnregisterFactoryLocation(const nsCID & aClass, nsIFile *aFile) { return _to UnregisterFactoryLocation(aClass, aFile); } \
  NS_IMETHOD IsCIDRegistered(const nsCID & aClass, bool *_retval) { return _to IsCIDRegistered(aClass, _retval); } \
  NS_IMETHOD IsContractIDRegistered(const char * aContractID, bool *_retval) { return _to IsContractIDRegistered(aContractID, _retval); } \
  NS_IMETHOD EnumerateCIDs(nsISimpleEnumerator * *_retval) { return _to EnumerateCIDs(_retval); } \
  NS_IMETHOD EnumerateContractIDs(nsISimpleEnumerator * *_retval) { return _to EnumerateContractIDs(_retval); } \
  NS_IMETHOD CIDToContractID(const nsCID & aClass, char * *_retval) { return _to CIDToContractID(aClass, _retval); } \
  NS_IMETHOD ContractIDToCID(const char * aContractID, nsCID **_retval) { return _to ContractIDToCID(aContractID, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOMPONENTREGISTRAR(_to) \
  NS_IMETHOD AutoRegister(nsIFile *aSpec) { return !_to ? NS_ERROR_NULL_POINTER : _to->AutoRegister(aSpec); } \
  NS_IMETHOD AutoUnregister(nsIFile *aSpec) { return !_to ? NS_ERROR_NULL_POINTER : _to->AutoUnregister(aSpec); } \
  NS_IMETHOD RegisterFactory(const nsCID & aClass, const char * aClassName, const char * aContractID, nsIFactory *aFactory) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterFactory(aClass, aClassName, aContractID, aFactory); } \
  NS_IMETHOD UnregisterFactory(const nsCID & aClass, nsIFactory *aFactory) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterFactory(aClass, aFactory); } \
  NS_IMETHOD RegisterFactoryLocation(const nsCID & aClass, const char * aClassName, const char * aContractID, nsIFile *aFile, const char * aLoaderStr, const char * aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterFactoryLocation(aClass, aClassName, aContractID, aFile, aLoaderStr, aType); } \
  NS_IMETHOD UnregisterFactoryLocation(const nsCID & aClass, nsIFile *aFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterFactoryLocation(aClass, aFile); } \
  NS_IMETHOD IsCIDRegistered(const nsCID & aClass, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCIDRegistered(aClass, _retval); } \
  NS_IMETHOD IsContractIDRegistered(const char * aContractID, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsContractIDRegistered(aContractID, _retval); } \
  NS_IMETHOD EnumerateCIDs(nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateCIDs(_retval); } \
  NS_IMETHOD EnumerateContractIDs(nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateContractIDs(_retval); } \
  NS_IMETHOD CIDToContractID(const nsCID & aClass, char * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CIDToContractID(aClass, _retval); } \
  NS_IMETHOD ContractIDToCID(const char * aContractID, nsCID **_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ContractIDToCID(aContractID, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsComponentRegistrar : public nsIComponentRegistrar
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOMPONENTREGISTRAR

  nsComponentRegistrar();

private:
  ~nsComponentRegistrar();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsComponentRegistrar, nsIComponentRegistrar)

nsComponentRegistrar::nsComponentRegistrar()
{
  /* member initializers and constructor code */
}

nsComponentRegistrar::~nsComponentRegistrar()
{
  /* destructor code */
}

/* void autoRegister (in nsIFile aSpec); */
NS_IMETHODIMP nsComponentRegistrar::AutoRegister(nsIFile *aSpec)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void autoUnregister (in nsIFile aSpec); */
NS_IMETHODIMP nsComponentRegistrar::AutoUnregister(nsIFile *aSpec)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerFactory (in nsCIDRef aClass, in string aClassName, in string aContractID, in nsIFactory aFactory); */
NS_IMETHODIMP nsComponentRegistrar::RegisterFactory(const nsCID & aClass, const char * aClassName, const char * aContractID, nsIFactory *aFactory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterFactory (in nsCIDRef aClass, in nsIFactory aFactory); */
NS_IMETHODIMP nsComponentRegistrar::UnregisterFactory(const nsCID & aClass, nsIFactory *aFactory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerFactoryLocation (in nsCIDRef aClass, in string aClassName, in string aContractID, in nsIFile aFile, in string aLoaderStr, in string aType); */
NS_IMETHODIMP nsComponentRegistrar::RegisterFactoryLocation(const nsCID & aClass, const char * aClassName, const char * aContractID, nsIFile *aFile, const char * aLoaderStr, const char * aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterFactoryLocation (in nsCIDRef aClass, in nsIFile aFile); */
NS_IMETHODIMP nsComponentRegistrar::UnregisterFactoryLocation(const nsCID & aClass, nsIFile *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isCIDRegistered (in nsCIDRef aClass); */
NS_IMETHODIMP nsComponentRegistrar::IsCIDRegistered(const nsCID & aClass, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isContractIDRegistered (in string aContractID); */
NS_IMETHODIMP nsComponentRegistrar::IsContractIDRegistered(const char * aContractID, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator enumerateCIDs (); */
NS_IMETHODIMP nsComponentRegistrar::EnumerateCIDs(nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator enumerateContractIDs (); */
NS_IMETHODIMP nsComponentRegistrar::EnumerateContractIDs(nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string CIDToContractID (in nsCIDRef aClass); */
NS_IMETHODIMP nsComponentRegistrar::CIDToContractID(const nsCID & aClass, char * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsCIDPtr contractIDToCID (in string aContractID); */
NS_IMETHODIMP nsComponentRegistrar::ContractIDToCID(const char * aContractID, nsCID **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIComponentRegistrar_h__ */

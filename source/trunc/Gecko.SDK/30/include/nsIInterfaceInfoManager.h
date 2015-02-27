/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIInterfaceInfoManager.idl
 */

#ifndef __gen_nsIInterfaceInfoManager_h__
#define __gen_nsIInterfaceInfoManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInterfaceInfo; /* forward declaration */

class nsIEnumerator; /* forward declaration */


/* starting interface:    nsIInterfaceInfoManager */
#define NS_IINTERFACEINFOMANAGER_IID_STR "1d53d8d9-1d92-428f-b5cc-198b55e897d7"

#define NS_IINTERFACEINFOMANAGER_IID \
  {0x1d53d8d9, 0x1d92, 0x428f, \
    { 0xb5, 0xcc, 0x19, 0x8b, 0x55, 0xe8, 0x97, 0xd7 }}

class NS_NO_VTABLE nsIInterfaceInfoManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINTERFACEINFOMANAGER_IID)

  /* nsIInterfaceInfo getInfoForIID (in nsIIDPtr iid); */
  NS_IMETHOD GetInfoForIID(const nsIID *iid, nsIInterfaceInfo * *_retval) = 0;

  /* nsIInterfaceInfo getInfoForName (in string name); */
  NS_IMETHOD GetInfoForName(const char * name, nsIInterfaceInfo * *_retval) = 0;

  /* nsIIDPtr getIIDForName (in string name); */
  NS_IMETHOD GetIIDForName(const char * name, nsIID **_retval) = 0;

  /* string getNameForIID (in nsIIDPtr iid); */
  NS_IMETHOD GetNameForIID(const nsIID *iid, char * *_retval) = 0;

  /* void autoRegisterInterfaces (); */
  NS_IMETHOD AutoRegisterInterfaces(void) = 0;

  /* nsIEnumerator enumerateInterfacesWhoseNamesStartWith (in string prefix); */
  NS_IMETHOD EnumerateInterfacesWhoseNamesStartWith(const char * prefix, nsIEnumerator * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInterfaceInfoManager, NS_IINTERFACEINFOMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINTERFACEINFOMANAGER \
  NS_IMETHOD GetInfoForIID(const nsIID *iid, nsIInterfaceInfo * *_retval); \
  NS_IMETHOD GetInfoForName(const char * name, nsIInterfaceInfo * *_retval); \
  NS_IMETHOD GetIIDForName(const char * name, nsIID **_retval); \
  NS_IMETHOD GetNameForIID(const nsIID *iid, char * *_retval); \
  NS_IMETHOD AutoRegisterInterfaces(void); \
  NS_IMETHOD EnumerateInterfacesWhoseNamesStartWith(const char * prefix, nsIEnumerator * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINTERFACEINFOMANAGER(_to) \
  NS_IMETHOD GetInfoForIID(const nsIID *iid, nsIInterfaceInfo * *_retval) { return _to GetInfoForIID(iid, _retval); } \
  NS_IMETHOD GetInfoForName(const char * name, nsIInterfaceInfo * *_retval) { return _to GetInfoForName(name, _retval); } \
  NS_IMETHOD GetIIDForName(const char * name, nsIID **_retval) { return _to GetIIDForName(name, _retval); } \
  NS_IMETHOD GetNameForIID(const nsIID *iid, char * *_retval) { return _to GetNameForIID(iid, _retval); } \
  NS_IMETHOD AutoRegisterInterfaces(void) { return _to AutoRegisterInterfaces(); } \
  NS_IMETHOD EnumerateInterfacesWhoseNamesStartWith(const char * prefix, nsIEnumerator * *_retval) { return _to EnumerateInterfacesWhoseNamesStartWith(prefix, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINTERFACEINFOMANAGER(_to) \
  NS_IMETHOD GetInfoForIID(const nsIID *iid, nsIInterfaceInfo * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInfoForIID(iid, _retval); } \
  NS_IMETHOD GetInfoForName(const char * name, nsIInterfaceInfo * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInfoForName(name, _retval); } \
  NS_IMETHOD GetIIDForName(const char * name, nsIID **_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIIDForName(name, _retval); } \
  NS_IMETHOD GetNameForIID(const nsIID *iid, char * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNameForIID(iid, _retval); } \
  NS_IMETHOD AutoRegisterInterfaces(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->AutoRegisterInterfaces(); } \
  NS_IMETHOD EnumerateInterfacesWhoseNamesStartWith(const char * prefix, nsIEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateInterfacesWhoseNamesStartWith(prefix, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInterfaceInfoManager : public nsIInterfaceInfoManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINTERFACEINFOMANAGER

  nsInterfaceInfoManager();

private:
  ~nsInterfaceInfoManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsInterfaceInfoManager, nsIInterfaceInfoManager)

nsInterfaceInfoManager::nsInterfaceInfoManager()
{
  /* member initializers and constructor code */
}

nsInterfaceInfoManager::~nsInterfaceInfoManager()
{
  /* destructor code */
}

/* nsIInterfaceInfo getInfoForIID (in nsIIDPtr iid); */
NS_IMETHODIMP nsInterfaceInfoManager::GetInfoForIID(const nsIID *iid, nsIInterfaceInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInterfaceInfo getInfoForName (in string name); */
NS_IMETHODIMP nsInterfaceInfoManager::GetInfoForName(const char * name, nsIInterfaceInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIIDPtr getIIDForName (in string name); */
NS_IMETHODIMP nsInterfaceInfoManager::GetIIDForName(const char * name, nsIID **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string getNameForIID (in nsIIDPtr iid); */
NS_IMETHODIMP nsInterfaceInfoManager::GetNameForIID(const nsIID *iid, char * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void autoRegisterInterfaces (); */
NS_IMETHODIMP nsInterfaceInfoManager::AutoRegisterInterfaces()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIEnumerator enumerateInterfacesWhoseNamesStartWith (in string prefix); */
NS_IMETHODIMP nsInterfaceInfoManager::EnumerateInterfacesWhoseNamesStartWith(const char * prefix, nsIEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_INTERFACEINFOMANAGER_SERVICE_CID            \
 { /* 13bef784-f8e0-4f96-85c1-09f9ef4f9a19 */          \
  0x13bef784, 0xf8e0, 0x4f96,                          \
  {0x85, 0xc1, 0x09, 0xf9, 0xef, 0x4f, 0x9a, 0x19} }  
#define NS_INTERFACEINFOMANAGER_SERVICE_CONTRACTID  \
   "@mozilla.org/xpti/interfaceinfomanager-service;1"

#endif /* __gen_nsIInterfaceInfoManager_h__ */

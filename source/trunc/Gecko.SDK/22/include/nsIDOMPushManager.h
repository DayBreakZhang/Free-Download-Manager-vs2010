/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/push/nsIDOMPushManager.idl
 */

#ifndef __gen_nsIDOMPushManager_h__
#define __gen_nsIDOMPushManager_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDOMRequest; /* forward declaration */


/* starting interface:    nsIDOMPushManager */
#define NS_IDOMPUSHMANAGER_IID_STR "c7ad4f42-faae-4e8b-9879-780a72349945"

#define NS_IDOMPUSHMANAGER_IID \
  {0xc7ad4f42, 0xfaae, 0x4e8b, \
    { 0x98, 0x79, 0x78, 0x0a, 0x72, 0x34, 0x99, 0x45 }}

class NS_NO_VTABLE nsIDOMPushManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMPUSHMANAGER_IID)

  /* nsIDOMDOMRequest register (); */
  NS_IMETHOD Register(nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest unregister (in ACString endpoint); */
  NS_IMETHOD Unregister(const nsACString & endpoint, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest registrations (); */
  NS_IMETHOD Registrations(nsIDOMDOMRequest * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMPushManager, NS_IDOMPUSHMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMPUSHMANAGER \
  NS_IMETHOD Register(nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD Unregister(const nsACString & endpoint, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD Registrations(nsIDOMDOMRequest * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMPUSHMANAGER(_to) \
  NS_IMETHOD Register(nsIDOMDOMRequest * *_retval) { return _to Register(_retval); } \
  NS_IMETHOD Unregister(const nsACString & endpoint, nsIDOMDOMRequest * *_retval) { return _to Unregister(endpoint, _retval); } \
  NS_IMETHOD Registrations(nsIDOMDOMRequest * *_retval) { return _to Registrations(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMPUSHMANAGER(_to) \
  NS_IMETHOD Register(nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Register(_retval); } \
  NS_IMETHOD Unregister(const nsACString & endpoint, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Unregister(endpoint, _retval); } \
  NS_IMETHOD Registrations(nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Registrations(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMPushManager : public nsIDOMPushManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMPUSHMANAGER

  nsDOMPushManager();

private:
  ~nsDOMPushManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMPushManager, nsIDOMPushManager)

nsDOMPushManager::nsDOMPushManager()
{
  /* member initializers and constructor code */
}

nsDOMPushManager::~nsDOMPushManager()
{
  /* destructor code */
}

/* nsIDOMDOMRequest register (); */
NS_IMETHODIMP nsDOMPushManager::Register(nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest unregister (in ACString endpoint); */
NS_IMETHODIMP nsDOMPushManager::Unregister(const nsACString & endpoint, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest registrations (); */
NS_IMETHODIMP nsDOMPushManager::Registrations(nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMPushManager_h__ */

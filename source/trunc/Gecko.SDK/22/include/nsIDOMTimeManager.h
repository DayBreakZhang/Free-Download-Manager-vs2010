/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/time/nsIDOMTimeManager.idl
 */

#ifndef __gen_nsIDOMTimeManager_h__
#define __gen_nsIDOMTimeManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMozTimeManager */
#define NS_IDOMMOZTIMEMANAGER_IID_STR "d29beaaa-bd54-4fd5-9f18-e0eedb1dc96d"

#define NS_IDOMMOZTIMEMANAGER_IID \
  {0xd29beaaa, 0xbd54, 0x4fd5, \
    { 0x9f, 0x18, 0xe0, 0xee, 0xdb, 0x1d, 0xc9, 0x6d }}

class NS_NO_VTABLE nsIDOMMozTimeManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZTIMEMANAGER_IID)

  /* [implicit_jscontext] void set (in jsval time); */
  NS_IMETHOD Set(const JS::Value & time, JSContext* cx) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozTimeManager, NS_IDOMMOZTIMEMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZTIMEMANAGER \
  NS_IMETHOD Set(const JS::Value & time, JSContext* cx); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZTIMEMANAGER(_to) \
  NS_IMETHOD Set(const JS::Value & time, JSContext* cx) { return _to Set(time, cx); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZTIMEMANAGER(_to) \
  NS_IMETHOD Set(const JS::Value & time, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->Set(time, cx); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozTimeManager : public nsIDOMMozTimeManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZTIMEMANAGER

  nsDOMMozTimeManager();

private:
  ~nsDOMMozTimeManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozTimeManager, nsIDOMMozTimeManager)

nsDOMMozTimeManager::nsDOMMozTimeManager()
{
  /* member initializers and constructor code */
}

nsDOMMozTimeManager::~nsDOMMozTimeManager()
{
  /* destructor code */
}

/* [implicit_jscontext] void set (in jsval time); */
NS_IMETHODIMP nsDOMMozTimeManager::Set(const JS::Value & time, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMTimeManager_h__ */

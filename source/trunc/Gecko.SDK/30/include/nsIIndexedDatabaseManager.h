/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIIndexedDatabaseManager.idl
 */

#ifndef __gen_nsIIndexedDatabaseManager_h__
#define __gen_nsIIndexedDatabaseManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIIndexedDatabaseManager */
#define NS_IINDEXEDDATABASEMANAGER_IID_STR "538d1085-517e-405a-a0f0-eb575cb0b8e5"

#define NS_IINDEXEDDATABASEMANAGER_IID \
  {0x538d1085, 0x517e, 0x405a, \
    { 0xa0, 0xf0, 0xeb, 0x57, 0x5c, 0xb0, 0xb8, 0xe5 }}

class NS_NO_VTABLE nsIIndexedDatabaseManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINDEXEDDATABASEMANAGER_IID)

  /* [implicit_jscontext] void initWindowless (in jsval aGlobal); */
  NS_IMETHOD InitWindowless(JS::HandleValue aGlobal, JSContext* cx) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIndexedDatabaseManager, NS_IINDEXEDDATABASEMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINDEXEDDATABASEMANAGER \
  NS_IMETHOD InitWindowless(JS::HandleValue aGlobal, JSContext* cx); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINDEXEDDATABASEMANAGER(_to) \
  NS_IMETHOD InitWindowless(JS::HandleValue aGlobal, JSContext* cx) { return _to InitWindowless(aGlobal, cx); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINDEXEDDATABASEMANAGER(_to) \
  NS_IMETHOD InitWindowless(JS::HandleValue aGlobal, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitWindowless(aGlobal, cx); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIndexedDatabaseManager : public nsIIndexedDatabaseManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINDEXEDDATABASEMANAGER

  nsIndexedDatabaseManager();

private:
  ~nsIndexedDatabaseManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIndexedDatabaseManager, nsIIndexedDatabaseManager)

nsIndexedDatabaseManager::nsIndexedDatabaseManager()
{
  /* member initializers and constructor code */
}

nsIndexedDatabaseManager::~nsIndexedDatabaseManager()
{
  /* destructor code */
}

/* [implicit_jscontext] void initWindowless (in jsval aGlobal); */
NS_IMETHODIMP nsIndexedDatabaseManager::InitWindowless(JS::HandleValue aGlobal, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIndexedDatabaseManager_h__ */

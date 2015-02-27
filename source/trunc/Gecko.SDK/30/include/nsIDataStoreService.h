/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDataStoreService.idl
 */

#ifndef __gen_nsIDataStoreService_h__
#define __gen_nsIDataStoreService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIDataStoreService */
#define NS_IDATASTORESERVICE_IID_STR "bd02d09c-41ab-47b7-9319-57aa8e5059b0"

#define NS_IDATASTORESERVICE_IID \
  {0xbd02d09c, 0x41ab, 0x47b7, \
    { 0x93, 0x19, 0x57, 0xaa, 0x8e, 0x50, 0x59, 0xb0 }}

class NS_NO_VTABLE nsIDataStoreService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDATASTORESERVICE_IID)

  /* void installDataStore (in unsigned long appId, in DOMString name, in DOMString originURL, in DOMString manifestURL, in boolean readOnly); */
  NS_IMETHOD InstallDataStore(uint32_t appId, const nsAString & name, const nsAString & originURL, const nsAString & manifestURL, bool readOnly) = 0;

  /* void installAccessDataStore (in unsigned long appId, in DOMString name, in DOMString originURL, in DOMString manifestURL, in boolean readOnly); */
  NS_IMETHOD InstallAccessDataStore(uint32_t appId, const nsAString & name, const nsAString & originURL, const nsAString & manifestURL, bool readOnly) = 0;

  /* nsISupports getDataStores (in nsIDOMWindow window, in DOMString name); */
  NS_IMETHOD GetDataStores(nsIDOMWindow *window, const nsAString & name, nsISupports * *_retval) = 0;

  /* jsval getDataStoresInfo (in DOMString name, in unsigned long appId); */
  NS_IMETHOD GetDataStoresInfo(const nsAString & name, uint32_t appId, JS::MutableHandleValue _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDataStoreService, NS_IDATASTORESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDATASTORESERVICE \
  NS_IMETHOD InstallDataStore(uint32_t appId, const nsAString & name, const nsAString & originURL, const nsAString & manifestURL, bool readOnly); \
  NS_IMETHOD InstallAccessDataStore(uint32_t appId, const nsAString & name, const nsAString & originURL, const nsAString & manifestURL, bool readOnly); \
  NS_IMETHOD GetDataStores(nsIDOMWindow *window, const nsAString & name, nsISupports * *_retval); \
  NS_IMETHOD GetDataStoresInfo(const nsAString & name, uint32_t appId, JS::MutableHandleValue _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDATASTORESERVICE(_to) \
  NS_IMETHOD InstallDataStore(uint32_t appId, const nsAString & name, const nsAString & originURL, const nsAString & manifestURL, bool readOnly) { return _to InstallDataStore(appId, name, originURL, manifestURL, readOnly); } \
  NS_IMETHOD InstallAccessDataStore(uint32_t appId, const nsAString & name, const nsAString & originURL, const nsAString & manifestURL, bool readOnly) { return _to InstallAccessDataStore(appId, name, originURL, manifestURL, readOnly); } \
  NS_IMETHOD GetDataStores(nsIDOMWindow *window, const nsAString & name, nsISupports * *_retval) { return _to GetDataStores(window, name, _retval); } \
  NS_IMETHOD GetDataStoresInfo(const nsAString & name, uint32_t appId, JS::MutableHandleValue _retval) { return _to GetDataStoresInfo(name, appId, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDATASTORESERVICE(_to) \
  NS_IMETHOD InstallDataStore(uint32_t appId, const nsAString & name, const nsAString & originURL, const nsAString & manifestURL, bool readOnly) { return !_to ? NS_ERROR_NULL_POINTER : _to->InstallDataStore(appId, name, originURL, manifestURL, readOnly); } \
  NS_IMETHOD InstallAccessDataStore(uint32_t appId, const nsAString & name, const nsAString & originURL, const nsAString & manifestURL, bool readOnly) { return !_to ? NS_ERROR_NULL_POINTER : _to->InstallAccessDataStore(appId, name, originURL, manifestURL, readOnly); } \
  NS_IMETHOD GetDataStores(nsIDOMWindow *window, const nsAString & name, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataStores(window, name, _retval); } \
  NS_IMETHOD GetDataStoresInfo(const nsAString & name, uint32_t appId, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataStoresInfo(name, appId, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDataStoreService : public nsIDataStoreService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDATASTORESERVICE

  nsDataStoreService();

private:
  ~nsDataStoreService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDataStoreService, nsIDataStoreService)

nsDataStoreService::nsDataStoreService()
{
  /* member initializers and constructor code */
}

nsDataStoreService::~nsDataStoreService()
{
  /* destructor code */
}

/* void installDataStore (in unsigned long appId, in DOMString name, in DOMString originURL, in DOMString manifestURL, in boolean readOnly); */
NS_IMETHODIMP nsDataStoreService::InstallDataStore(uint32_t appId, const nsAString & name, const nsAString & originURL, const nsAString & manifestURL, bool readOnly)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void installAccessDataStore (in unsigned long appId, in DOMString name, in DOMString originURL, in DOMString manifestURL, in boolean readOnly); */
NS_IMETHODIMP nsDataStoreService::InstallAccessDataStore(uint32_t appId, const nsAString & name, const nsAString & originURL, const nsAString & manifestURL, bool readOnly)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getDataStores (in nsIDOMWindow window, in DOMString name); */
NS_IMETHODIMP nsDataStoreService::GetDataStores(nsIDOMWindow *window, const nsAString & name, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval getDataStoresInfo (in DOMString name, in unsigned long appId); */
NS_IMETHODIMP nsDataStoreService::GetDataStoresInfo(const nsAString & name, uint32_t appId, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDataStoreService_h__ */

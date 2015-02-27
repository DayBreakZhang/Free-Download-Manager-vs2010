/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/devicestorage/nsIDOMNavigatorDeviceStorage.idl
 */

#ifndef __gen_nsIDOMNavigatorDeviceStorage_h__
#define __gen_nsIDOMNavigatorDeviceStorage_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDeviceStorage; /* forward declaration */


/* starting interface:    nsIDOMNavigatorDeviceStorage */
#define NS_IDOMNAVIGATORDEVICESTORAGE_IID_STR "da1fbf6e-259c-40bc-ba8c-4ae81748dca3"

#define NS_IDOMNAVIGATORDEVICESTORAGE_IID \
  {0xda1fbf6e, 0x259c, 0x40bc, \
    { 0xba, 0x8c, 0x4a, 0xe8, 0x17, 0x48, 0xdc, 0xa3 }}

class NS_NO_VTABLE nsIDOMNavigatorDeviceStorage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNAVIGATORDEVICESTORAGE_IID)

  /* nsIDOMDeviceStorage getDeviceStorage (in DOMString type); */
  NS_IMETHOD GetDeviceStorage(const nsAString & type, nsIDOMDeviceStorage * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNavigatorDeviceStorage, NS_IDOMNAVIGATORDEVICESTORAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNAVIGATORDEVICESTORAGE \
  NS_IMETHOD GetDeviceStorage(const nsAString & type, nsIDOMDeviceStorage * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNAVIGATORDEVICESTORAGE(_to) \
  NS_IMETHOD GetDeviceStorage(const nsAString & type, nsIDOMDeviceStorage * *_retval) { return _to GetDeviceStorage(type, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNAVIGATORDEVICESTORAGE(_to) \
  NS_IMETHOD GetDeviceStorage(const nsAString & type, nsIDOMDeviceStorage * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDeviceStorage(type, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNavigatorDeviceStorage : public nsIDOMNavigatorDeviceStorage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNAVIGATORDEVICESTORAGE

  nsDOMNavigatorDeviceStorage();

private:
  ~nsDOMNavigatorDeviceStorage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNavigatorDeviceStorage, nsIDOMNavigatorDeviceStorage)

nsDOMNavigatorDeviceStorage::nsDOMNavigatorDeviceStorage()
{
  /* member initializers and constructor code */
}

nsDOMNavigatorDeviceStorage::~nsDOMNavigatorDeviceStorage()
{
  /* destructor code */
}

/* nsIDOMDeviceStorage getDeviceStorage (in DOMString type); */
NS_IMETHODIMP nsDOMNavigatorDeviceStorage::GetDeviceStorage(const nsAString & type, nsIDOMDeviceStorage * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNavigatorDeviceStorage_h__ */

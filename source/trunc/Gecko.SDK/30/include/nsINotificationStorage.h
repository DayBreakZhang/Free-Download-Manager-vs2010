/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsINotificationStorage.idl
 */

#ifndef __gen_nsINotificationStorage_h__
#define __gen_nsINotificationStorage_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsINotificationStorageCallback */
#define NS_INOTIFICATIONSTORAGECALLBACK_IID_STR "fb089720-1c5c-11e3-b773-0800200c9a66"

#define NS_INOTIFICATIONSTORAGECALLBACK_IID \
  {0xfb089720, 0x1c5c, 0x11e3, \
    { 0xb7, 0x73, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsINotificationStorageCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INOTIFICATIONSTORAGECALLBACK_IID)

  /* [implicit_jscontext] void handle (in DOMString id, in DOMString title, in DOMString dir, in DOMString lang, in DOMString body, in DOMString tag, in DOMString icon); */
  NS_IMETHOD Handle(const nsAString & id, const nsAString & title, const nsAString & dir, const nsAString & lang, const nsAString & body, const nsAString & tag, const nsAString & icon, JSContext* cx) = 0;

  /* [implicit_jscontext] void done (); */
  NS_IMETHOD Done(JSContext* cx) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINotificationStorageCallback, NS_INOTIFICATIONSTORAGECALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINOTIFICATIONSTORAGECALLBACK \
  NS_IMETHOD Handle(const nsAString & id, const nsAString & title, const nsAString & dir, const nsAString & lang, const nsAString & body, const nsAString & tag, const nsAString & icon, JSContext* cx); \
  NS_IMETHOD Done(JSContext* cx); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINOTIFICATIONSTORAGECALLBACK(_to) \
  NS_IMETHOD Handle(const nsAString & id, const nsAString & title, const nsAString & dir, const nsAString & lang, const nsAString & body, const nsAString & tag, const nsAString & icon, JSContext* cx) { return _to Handle(id, title, dir, lang, body, tag, icon, cx); } \
  NS_IMETHOD Done(JSContext* cx) { return _to Done(cx); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINOTIFICATIONSTORAGECALLBACK(_to) \
  NS_IMETHOD Handle(const nsAString & id, const nsAString & title, const nsAString & dir, const nsAString & lang, const nsAString & body, const nsAString & tag, const nsAString & icon, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->Handle(id, title, dir, lang, body, tag, icon, cx); } \
  NS_IMETHOD Done(JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->Done(cx); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNotificationStorageCallback : public nsINotificationStorageCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINOTIFICATIONSTORAGECALLBACK

  nsNotificationStorageCallback();

private:
  ~nsNotificationStorageCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNotificationStorageCallback, nsINotificationStorageCallback)

nsNotificationStorageCallback::nsNotificationStorageCallback()
{
  /* member initializers and constructor code */
}

nsNotificationStorageCallback::~nsNotificationStorageCallback()
{
  /* destructor code */
}

/* [implicit_jscontext] void handle (in DOMString id, in DOMString title, in DOMString dir, in DOMString lang, in DOMString body, in DOMString tag, in DOMString icon); */
NS_IMETHODIMP nsNotificationStorageCallback::Handle(const nsAString & id, const nsAString & title, const nsAString & dir, const nsAString & lang, const nsAString & body, const nsAString & tag, const nsAString & icon, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void done (); */
NS_IMETHODIMP nsNotificationStorageCallback::Done(JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINotificationStorage */
#define NS_INOTIFICATIONSTORAGE_IID_STR "b177b080-2a23-11e3-8224-0800200c9a66"

#define NS_INOTIFICATIONSTORAGE_IID \
  {0xb177b080, 0x2a23, 0x11e3, \
    { 0x82, 0x24, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsINotificationStorage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INOTIFICATIONSTORAGE_IID)

  /* void put (in DOMString origin, in DOMString id, in DOMString title, in DOMString dir, in DOMString lang, in DOMString body, in DOMString tag, in DOMString icon); */
  NS_IMETHOD Put(const nsAString & origin, const nsAString & id, const nsAString & title, const nsAString & dir, const nsAString & lang, const nsAString & body, const nsAString & tag, const nsAString & icon) = 0;

  /* void get (in DOMString origin, in DOMString tag, in nsINotificationStorageCallback aCallback); */
  NS_IMETHOD Get(const nsAString & origin, const nsAString & tag, nsINotificationStorageCallback *aCallback) = 0;

  /* void delete (in DOMString origin, in DOMString id); */
  NS_IMETHOD Delete(const nsAString & origin, const nsAString & id) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINotificationStorage, NS_INOTIFICATIONSTORAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINOTIFICATIONSTORAGE \
  NS_IMETHOD Put(const nsAString & origin, const nsAString & id, const nsAString & title, const nsAString & dir, const nsAString & lang, const nsAString & body, const nsAString & tag, const nsAString & icon); \
  NS_IMETHOD Get(const nsAString & origin, const nsAString & tag, nsINotificationStorageCallback *aCallback); \
  NS_IMETHOD Delete(const nsAString & origin, const nsAString & id); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINOTIFICATIONSTORAGE(_to) \
  NS_IMETHOD Put(const nsAString & origin, const nsAString & id, const nsAString & title, const nsAString & dir, const nsAString & lang, const nsAString & body, const nsAString & tag, const nsAString & icon) { return _to Put(origin, id, title, dir, lang, body, tag, icon); } \
  NS_IMETHOD Get(const nsAString & origin, const nsAString & tag, nsINotificationStorageCallback *aCallback) { return _to Get(origin, tag, aCallback); } \
  NS_IMETHOD Delete(const nsAString & origin, const nsAString & id) { return _to Delete(origin, id); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINOTIFICATIONSTORAGE(_to) \
  NS_IMETHOD Put(const nsAString & origin, const nsAString & id, const nsAString & title, const nsAString & dir, const nsAString & lang, const nsAString & body, const nsAString & tag, const nsAString & icon) { return !_to ? NS_ERROR_NULL_POINTER : _to->Put(origin, id, title, dir, lang, body, tag, icon); } \
  NS_IMETHOD Get(const nsAString & origin, const nsAString & tag, nsINotificationStorageCallback *aCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(origin, tag, aCallback); } \
  NS_IMETHOD Delete(const nsAString & origin, const nsAString & id) { return !_to ? NS_ERROR_NULL_POINTER : _to->Delete(origin, id); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNotificationStorage : public nsINotificationStorage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINOTIFICATIONSTORAGE

  nsNotificationStorage();

private:
  ~nsNotificationStorage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNotificationStorage, nsINotificationStorage)

nsNotificationStorage::nsNotificationStorage()
{
  /* member initializers and constructor code */
}

nsNotificationStorage::~nsNotificationStorage()
{
  /* destructor code */
}

/* void put (in DOMString origin, in DOMString id, in DOMString title, in DOMString dir, in DOMString lang, in DOMString body, in DOMString tag, in DOMString icon); */
NS_IMETHODIMP nsNotificationStorage::Put(const nsAString & origin, const nsAString & id, const nsAString & title, const nsAString & dir, const nsAString & lang, const nsAString & body, const nsAString & tag, const nsAString & icon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void get (in DOMString origin, in DOMString tag, in nsINotificationStorageCallback aCallback); */
NS_IMETHODIMP nsNotificationStorage::Get(const nsAString & origin, const nsAString & tag, nsINotificationStorageCallback *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void delete (in DOMString origin, in DOMString id); */
NS_IMETHODIMP nsNotificationStorage::Delete(const nsAString & origin, const nsAString & id)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_NOTIFICATION_STORAGE_CONTRACTID "@mozilla.org/notificationStorage;1"

#endif /* __gen_nsINotificationStorage_h__ */

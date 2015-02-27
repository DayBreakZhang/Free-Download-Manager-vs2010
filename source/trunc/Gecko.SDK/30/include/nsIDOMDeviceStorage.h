/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMDeviceStorage.idl
 */

#ifndef __gen_nsIDOMDeviceStorage_h__
#define __gen_nsIDOMDeviceStorage_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDOMEventTarget_h__
#include "nsIDOMEventTarget.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMBlob; /* forward declaration */

class nsIDOMDOMRequest; /* forward declaration */

class nsIDOMDOMCursor; /* forward declaration */

class nsIDOMDeviceStorageChangeEvent; /* forward declaration */

class nsIDOMEventListener; /* forward declaration */

class nsIFile; /* forward declaration */

class DeviceStorageFileDescriptor;

/* starting interface:    nsIDOMDeviceStorage */
#define NS_IDOMDEVICESTORAGE_IID_STR "8b724547-3c78-4244-969a-f00a1f4ae0c3"

#define NS_IDOMDEVICESTORAGE_IID \
  {0x8b724547, 0x3c78, 0x4244, \
    { 0x96, 0x9a, 0xf0, 0x0a, 0x1f, 0x4a, 0xe0, 0xc3 }}

class NS_NO_VTABLE nsIDOMDeviceStorage : public nsIDOMEventTarget {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDEVICESTORAGE_IID)

  /* [implicit_jscontext] attribute jsval onchange; */
  NS_IMETHOD GetOnchange(JSContext* cx, JS::MutableHandleValue aOnchange) = 0;
  NS_IMETHOD SetOnchange(JSContext* cx, JS::HandleValue aOnchange) = 0;

  /* nsIDOMDOMRequest add (in nsIDOMBlob aBlob); */
  NS_IMETHOD Add(nsIDOMBlob *aBlob, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest addNamed (in nsIDOMBlob aBlob, in DOMString aName); */
  NS_IMETHOD AddNamed(nsIDOMBlob *aBlob, const nsAString & aName, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest get ([Null (Stringify)] in DOMString aName); */
  NS_IMETHOD Get(const nsAString & aName, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest getEditable ([Null (Stringify)] in DOMString aName); */
  NS_IMETHOD GetEditable(const nsAString & aName, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest delete ([Null (Stringify)] in DOMString aName); */
  NS_IMETHOD Delete(const nsAString & aName, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest freeSpace (); */
  NS_IMETHOD FreeSpace(nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest usedSpace (); */
  NS_IMETHOD UsedSpace(nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest available (); */
  NS_IMETHOD Available(nsIDOMDOMRequest * *_retval) = 0;

  /* readonly attribute DOMString storageName; */
  NS_IMETHOD GetStorageName(nsAString & aStorageName) = 0;

  /* readonly attribute bool default; */
  NS_IMETHOD GetDefault(bool *aDefault) = 0;

  /* [noscript] nsIDOMDOMRequest createFileDescriptor (in DOMString aName, in DeviceStorageFdPtr aFileDescriptor); */
  NS_IMETHOD CreateFileDescriptor(const nsAString & aName, DeviceStorageFileDescriptor *aFileDescriptor, nsIDOMDOMRequest * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDeviceStorage, NS_IDOMDEVICESTORAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDEVICESTORAGE \
  NS_IMETHOD GetOnchange(JSContext* cx, JS::MutableHandleValue aOnchange); \
  NS_IMETHOD SetOnchange(JSContext* cx, JS::HandleValue aOnchange); \
  NS_IMETHOD Add(nsIDOMBlob *aBlob, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD AddNamed(nsIDOMBlob *aBlob, const nsAString & aName, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD Get(const nsAString & aName, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetEditable(const nsAString & aName, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD Delete(const nsAString & aName, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD FreeSpace(nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD UsedSpace(nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD Available(nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetStorageName(nsAString & aStorageName); \
  NS_IMETHOD GetDefault(bool *aDefault); \
  NS_IMETHOD CreateFileDescriptor(const nsAString & aName, DeviceStorageFileDescriptor *aFileDescriptor, nsIDOMDOMRequest * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDEVICESTORAGE(_to) \
  NS_IMETHOD GetOnchange(JSContext* cx, JS::MutableHandleValue aOnchange) { return _to GetOnchange(cx, aOnchange); } \
  NS_IMETHOD SetOnchange(JSContext* cx, JS::HandleValue aOnchange) { return _to SetOnchange(cx, aOnchange); } \
  NS_IMETHOD Add(nsIDOMBlob *aBlob, nsIDOMDOMRequest * *_retval) { return _to Add(aBlob, _retval); } \
  NS_IMETHOD AddNamed(nsIDOMBlob *aBlob, const nsAString & aName, nsIDOMDOMRequest * *_retval) { return _to AddNamed(aBlob, aName, _retval); } \
  NS_IMETHOD Get(const nsAString & aName, nsIDOMDOMRequest * *_retval) { return _to Get(aName, _retval); } \
  NS_IMETHOD GetEditable(const nsAString & aName, nsIDOMDOMRequest * *_retval) { return _to GetEditable(aName, _retval); } \
  NS_IMETHOD Delete(const nsAString & aName, nsIDOMDOMRequest * *_retval) { return _to Delete(aName, _retval); } \
  NS_IMETHOD FreeSpace(nsIDOMDOMRequest * *_retval) { return _to FreeSpace(_retval); } \
  NS_IMETHOD UsedSpace(nsIDOMDOMRequest * *_retval) { return _to UsedSpace(_retval); } \
  NS_IMETHOD Available(nsIDOMDOMRequest * *_retval) { return _to Available(_retval); } \
  NS_IMETHOD GetStorageName(nsAString & aStorageName) { return _to GetStorageName(aStorageName); } \
  NS_IMETHOD GetDefault(bool *aDefault) { return _to GetDefault(aDefault); } \
  NS_IMETHOD CreateFileDescriptor(const nsAString & aName, DeviceStorageFileDescriptor *aFileDescriptor, nsIDOMDOMRequest * *_retval) { return _to CreateFileDescriptor(aName, aFileDescriptor, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDEVICESTORAGE(_to) \
  NS_IMETHOD GetOnchange(JSContext* cx, JS::MutableHandleValue aOnchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnchange(cx, aOnchange); } \
  NS_IMETHOD SetOnchange(JSContext* cx, JS::HandleValue aOnchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnchange(cx, aOnchange); } \
  NS_IMETHOD Add(nsIDOMBlob *aBlob, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(aBlob, _retval); } \
  NS_IMETHOD AddNamed(nsIDOMBlob *aBlob, const nsAString & aName, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddNamed(aBlob, aName, _retval); } \
  NS_IMETHOD Get(const nsAString & aName, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(aName, _retval); } \
  NS_IMETHOD GetEditable(const nsAString & aName, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEditable(aName, _retval); } \
  NS_IMETHOD Delete(const nsAString & aName, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Delete(aName, _retval); } \
  NS_IMETHOD FreeSpace(nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FreeSpace(_retval); } \
  NS_IMETHOD UsedSpace(nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->UsedSpace(_retval); } \
  NS_IMETHOD Available(nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Available(_retval); } \
  NS_IMETHOD GetStorageName(nsAString & aStorageName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStorageName(aStorageName); } \
  NS_IMETHOD GetDefault(bool *aDefault) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefault(aDefault); } \
  NS_IMETHOD CreateFileDescriptor(const nsAString & aName, DeviceStorageFileDescriptor *aFileDescriptor, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateFileDescriptor(aName, aFileDescriptor, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDeviceStorage : public nsIDOMDeviceStorage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDEVICESTORAGE

  nsDOMDeviceStorage();

private:
  ~nsDOMDeviceStorage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDeviceStorage, nsIDOMDeviceStorage)

nsDOMDeviceStorage::nsDOMDeviceStorage()
{
  /* member initializers and constructor code */
}

nsDOMDeviceStorage::~nsDOMDeviceStorage()
{
  /* destructor code */
}

/* [implicit_jscontext] attribute jsval onchange; */
NS_IMETHODIMP nsDOMDeviceStorage::GetOnchange(JSContext* cx, JS::MutableHandleValue aOnchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDeviceStorage::SetOnchange(JSContext* cx, JS::HandleValue aOnchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest add (in nsIDOMBlob aBlob); */
NS_IMETHODIMP nsDOMDeviceStorage::Add(nsIDOMBlob *aBlob, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest addNamed (in nsIDOMBlob aBlob, in DOMString aName); */
NS_IMETHODIMP nsDOMDeviceStorage::AddNamed(nsIDOMBlob *aBlob, const nsAString & aName, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest get ([Null (Stringify)] in DOMString aName); */
NS_IMETHODIMP nsDOMDeviceStorage::Get(const nsAString & aName, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest getEditable ([Null (Stringify)] in DOMString aName); */
NS_IMETHODIMP nsDOMDeviceStorage::GetEditable(const nsAString & aName, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest delete ([Null (Stringify)] in DOMString aName); */
NS_IMETHODIMP nsDOMDeviceStorage::Delete(const nsAString & aName, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest freeSpace (); */
NS_IMETHODIMP nsDOMDeviceStorage::FreeSpace(nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest usedSpace (); */
NS_IMETHODIMP nsDOMDeviceStorage::UsedSpace(nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest available (); */
NS_IMETHODIMP nsDOMDeviceStorage::Available(nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString storageName; */
NS_IMETHODIMP nsDOMDeviceStorage::GetStorageName(nsAString & aStorageName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute bool default; */
NS_IMETHODIMP nsDOMDeviceStorage::GetDefault(bool *aDefault)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIDOMDOMRequest createFileDescriptor (in DOMString aName, in DeviceStorageFdPtr aFileDescriptor); */
NS_IMETHODIMP nsDOMDeviceStorage::CreateFileDescriptor(const nsAString & aName, DeviceStorageFileDescriptor *aFileDescriptor, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDeviceStorage_h__ */

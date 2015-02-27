/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/file/nsIDOMFileHandle.idl
 */

#ifndef __gen_nsIDOMFileHandle_h__
#define __gen_nsIDOMFileHandle_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
namespace mozilla {
namespace dom {
namespace indexedDB {
class FileInfo;
}
}
}
class nsIDOMDOMRequest; /* forward declaration */

class nsIDOMEventListener; /* forward declaration */

class nsIDOMLockedFile; /* forward declaration */


/* starting interface:    nsIDOMFileHandle */
#define NS_IDOMFILEHANDLE_IID_STR "47438729-7f3f-4a66-b6d4-d1297c593d46"

#define NS_IDOMFILEHANDLE_IID \
  {0x47438729, 0x7f3f, 0x4a66, \
    { 0xb6, 0xd4, 0xd1, 0x29, 0x7c, 0x59, 0x3d, 0x46 }}

class NS_NO_VTABLE nsIDOMFileHandle : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMFILEHANDLE_IID)

  /* [binaryname(DOMName)] readonly attribute DOMString name; */
  NS_IMETHOD GetDOMName(nsAString & aName) = 0;

  /* [binaryname(DOMType)] readonly attribute DOMString type; */
  NS_IMETHOD GetDOMType(nsAString & aType) = 0;

  /* [optional_argc] nsIDOMLockedFile open ([optional] in DOMString mode); */
  NS_IMETHOD Open(const nsAString & mode, uint8_t _argc, nsIDOMLockedFile * *_retval) = 0;

  /* nsIDOMDOMRequest getFile (); */
  NS_IMETHOD GetFile(nsIDOMDOMRequest * *_retval) = 0;

  /* [notxpcom] long long getFileId (); */
  NS_IMETHOD_(int64_t) GetFileId(void) = 0;

  /* [notxpcom] FileInfo getFileInfo (); */
  NS_IMETHOD_(mozilla::dom::indexedDB::FileInfo *) GetFileInfo(void) = 0;

  /* [implicit_jscontext] attribute jsval onabort; */
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort) = 0;
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort) = 0;

  /* [implicit_jscontext] attribute jsval onerror; */
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) = 0;
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMFileHandle, NS_IDOMFILEHANDLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMFILEHANDLE \
  NS_IMETHOD GetDOMName(nsAString & aName); \
  NS_IMETHOD GetDOMType(nsAString & aType); \
  NS_IMETHOD Open(const nsAString & mode, uint8_t _argc, nsIDOMLockedFile * *_retval); \
  NS_IMETHOD GetFile(nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD_(int64_t) GetFileId(void); \
  NS_IMETHOD_(mozilla::dom::indexedDB::FileInfo *) GetFileInfo(void); \
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort); \
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort); \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror); \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMFILEHANDLE(_to) \
  NS_IMETHOD GetDOMName(nsAString & aName) { return _to GetDOMName(aName); } \
  NS_IMETHOD GetDOMType(nsAString & aType) { return _to GetDOMType(aType); } \
  NS_IMETHOD Open(const nsAString & mode, uint8_t _argc, nsIDOMLockedFile * *_retval) { return _to Open(mode, _argc, _retval); } \
  NS_IMETHOD GetFile(nsIDOMDOMRequest * *_retval) { return _to GetFile(_retval); } \
  NS_IMETHOD_(int64_t) GetFileId(void) { return _to GetFileId(); } \
  NS_IMETHOD_(mozilla::dom::indexedDB::FileInfo *) GetFileInfo(void) { return _to GetFileInfo(); } \
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort) { return _to GetOnabort(cx, aOnabort); } \
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort) { return _to SetOnabort(cx, aOnabort); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) { return _to GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) { return _to SetOnerror(cx, aOnerror); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMFILEHANDLE(_to) \
  NS_IMETHOD GetDOMName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDOMName(aName); } \
  NS_IMETHOD GetDOMType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDOMType(aType); } \
  NS_IMETHOD Open(const nsAString & mode, uint8_t _argc, nsIDOMLockedFile * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(mode, _argc, _retval); } \
  NS_IMETHOD GetFile(nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFile(_retval); } \
  NS_IMETHOD_(int64_t) GetFileId(void); \
  NS_IMETHOD_(mozilla::dom::indexedDB::FileInfo *) GetFileInfo(void); \
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnabort(cx, aOnabort); } \
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnabort(cx, aOnabort); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnerror(cx, aOnerror); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMFileHandle : public nsIDOMFileHandle
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMFILEHANDLE

  nsDOMFileHandle();

private:
  ~nsDOMFileHandle();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMFileHandle, nsIDOMFileHandle)

nsDOMFileHandle::nsDOMFileHandle()
{
  /* member initializers and constructor code */
}

nsDOMFileHandle::~nsDOMFileHandle()
{
  /* destructor code */
}

/* [binaryname(DOMName)] readonly attribute DOMString name; */
NS_IMETHODIMP nsDOMFileHandle::GetDOMName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(DOMType)] readonly attribute DOMString type; */
NS_IMETHODIMP nsDOMFileHandle::GetDOMType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] nsIDOMLockedFile open ([optional] in DOMString mode); */
NS_IMETHODIMP nsDOMFileHandle::Open(const nsAString & mode, uint8_t _argc, nsIDOMLockedFile * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest getFile (); */
NS_IMETHODIMP nsDOMFileHandle::GetFile(nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] long long getFileId (); */
NS_IMETHODIMP_(int64_t) nsDOMFileHandle::GetFileId()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] FileInfo getFileInfo (); */
NS_IMETHODIMP_(mozilla::dom::indexedDB::FileInfo *) nsDOMFileHandle::GetFileInfo()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onabort; */
NS_IMETHODIMP nsDOMFileHandle::GetOnabort(JSContext* cx, JS::Value *aOnabort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMFileHandle::SetOnabort(JSContext* cx, const JS::Value & aOnabort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onerror; */
NS_IMETHODIMP nsDOMFileHandle::GetOnerror(JSContext* cx, JS::Value *aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMFileHandle::SetOnerror(JSContext* cx, const JS::Value & aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMFileHandle_h__ */

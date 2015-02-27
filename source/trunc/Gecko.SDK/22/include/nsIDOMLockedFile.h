/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/file/nsIDOMLockedFile.idl
 */

#ifndef __gen_nsIDOMLockedFile_h__
#define __gen_nsIDOMLockedFile_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMEventListener; /* forward declaration */

class nsIDOMFileHandle; /* forward declaration */


/* starting interface:    nsIDOMLockedFile */
#define NS_IDOMLOCKEDFILE_IID_STR "a09cdc35-6b1e-42ce-95bb-f8f10a354202"

#define NS_IDOMLOCKEDFILE_IID \
  {0xa09cdc35, 0x6b1e, 0x42ce, \
    { 0x95, 0xbb, 0xf8, 0xf1, 0x0a, 0x35, 0x42, 0x02 }}

class NS_NO_VTABLE nsIDOMLockedFile : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMLOCKEDFILE_IID)

  /* readonly attribute nsIDOMFileHandle fileHandle; */
  NS_IMETHOD GetFileHandle(nsIDOMFileHandle * *aFileHandle) = 0;

  /* readonly attribute DOMString mode; */
  NS_IMETHOD GetMode(nsAString & aMode) = 0;

  /* readonly attribute boolean active; */
  NS_IMETHOD GetActive(bool *aActive) = 0;

  /* [implicit_jscontext] attribute jsval location; */
  NS_IMETHOD GetLocation(JSContext* cx, JS::Value *aLocation) = 0;
  NS_IMETHOD SetLocation(JSContext* cx, const JS::Value & aLocation) = 0;

  /* [implicit_jscontext] nsISupports getMetadata ([optional] in jsval parameters); */
  NS_IMETHOD GetMetadata(const JS::Value & parameters, JSContext* cx, nsISupports * *_retval) = 0;

  /* [implicit_jscontext] nsISupports readAsArrayBuffer (in unsigned long long size); */
  NS_IMETHOD ReadAsArrayBuffer(uint64_t size, JSContext* cx, nsISupports * *_retval) = 0;

  /* nsISupports readAsText (in unsigned long long size, [optional] in DOMString encoding); */
  NS_IMETHOD ReadAsText(uint64_t size, const nsAString & encoding, nsISupports * *_retval) = 0;

  /* [implicit_jscontext] nsISupports write (in jsval value); */
  NS_IMETHOD Write(const JS::Value & value, JSContext* cx, nsISupports * *_retval) = 0;

  /* [implicit_jscontext] nsISupports append (in jsval value); */
  NS_IMETHOD Append(const JS::Value & value, JSContext* cx, nsISupports * *_retval) = 0;

  /* [optional_argc] nsISupports truncate ([optional] in unsigned long long size); */
  NS_IMETHOD Truncate(uint64_t size, uint8_t _argc, nsISupports * *_retval) = 0;

  /* nsISupports flush (); */
  NS_IMETHOD Flush(nsISupports * *_retval) = 0;

  /* void abort (); */
  NS_IMETHOD Abort(void) = 0;

  /* [implicit_jscontext] attribute jsval oncomplete; */
  NS_IMETHOD GetOncomplete(JSContext* cx, JS::Value *aOncomplete) = 0;
  NS_IMETHOD SetOncomplete(JSContext* cx, const JS::Value & aOncomplete) = 0;

  /* [implicit_jscontext] attribute jsval onabort; */
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort) = 0;
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort) = 0;

  /* [implicit_jscontext] attribute jsval onerror; */
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) = 0;
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMLockedFile, NS_IDOMLOCKEDFILE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMLOCKEDFILE \
  NS_IMETHOD GetFileHandle(nsIDOMFileHandle * *aFileHandle); \
  NS_IMETHOD GetMode(nsAString & aMode); \
  NS_IMETHOD GetActive(bool *aActive); \
  NS_IMETHOD GetLocation(JSContext* cx, JS::Value *aLocation); \
  NS_IMETHOD SetLocation(JSContext* cx, const JS::Value & aLocation); \
  NS_IMETHOD GetMetadata(const JS::Value & parameters, JSContext* cx, nsISupports * *_retval); \
  NS_IMETHOD ReadAsArrayBuffer(uint64_t size, JSContext* cx, nsISupports * *_retval); \
  NS_IMETHOD ReadAsText(uint64_t size, const nsAString & encoding, nsISupports * *_retval); \
  NS_IMETHOD Write(const JS::Value & value, JSContext* cx, nsISupports * *_retval); \
  NS_IMETHOD Append(const JS::Value & value, JSContext* cx, nsISupports * *_retval); \
  NS_IMETHOD Truncate(uint64_t size, uint8_t _argc, nsISupports * *_retval); \
  NS_IMETHOD Flush(nsISupports * *_retval); \
  NS_IMETHOD Abort(void); \
  NS_IMETHOD GetOncomplete(JSContext* cx, JS::Value *aOncomplete); \
  NS_IMETHOD SetOncomplete(JSContext* cx, const JS::Value & aOncomplete); \
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort); \
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort); \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror); \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMLOCKEDFILE(_to) \
  NS_IMETHOD GetFileHandle(nsIDOMFileHandle * *aFileHandle) { return _to GetFileHandle(aFileHandle); } \
  NS_IMETHOD GetMode(nsAString & aMode) { return _to GetMode(aMode); } \
  NS_IMETHOD GetActive(bool *aActive) { return _to GetActive(aActive); } \
  NS_IMETHOD GetLocation(JSContext* cx, JS::Value *aLocation) { return _to GetLocation(cx, aLocation); } \
  NS_IMETHOD SetLocation(JSContext* cx, const JS::Value & aLocation) { return _to SetLocation(cx, aLocation); } \
  NS_IMETHOD GetMetadata(const JS::Value & parameters, JSContext* cx, nsISupports * *_retval) { return _to GetMetadata(parameters, cx, _retval); } \
  NS_IMETHOD ReadAsArrayBuffer(uint64_t size, JSContext* cx, nsISupports * *_retval) { return _to ReadAsArrayBuffer(size, cx, _retval); } \
  NS_IMETHOD ReadAsText(uint64_t size, const nsAString & encoding, nsISupports * *_retval) { return _to ReadAsText(size, encoding, _retval); } \
  NS_IMETHOD Write(const JS::Value & value, JSContext* cx, nsISupports * *_retval) { return _to Write(value, cx, _retval); } \
  NS_IMETHOD Append(const JS::Value & value, JSContext* cx, nsISupports * *_retval) { return _to Append(value, cx, _retval); } \
  NS_IMETHOD Truncate(uint64_t size, uint8_t _argc, nsISupports * *_retval) { return _to Truncate(size, _argc, _retval); } \
  NS_IMETHOD Flush(nsISupports * *_retval) { return _to Flush(_retval); } \
  NS_IMETHOD Abort(void) { return _to Abort(); } \
  NS_IMETHOD GetOncomplete(JSContext* cx, JS::Value *aOncomplete) { return _to GetOncomplete(cx, aOncomplete); } \
  NS_IMETHOD SetOncomplete(JSContext* cx, const JS::Value & aOncomplete) { return _to SetOncomplete(cx, aOncomplete); } \
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort) { return _to GetOnabort(cx, aOnabort); } \
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort) { return _to SetOnabort(cx, aOnabort); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) { return _to GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) { return _to SetOnerror(cx, aOnerror); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMLOCKEDFILE(_to) \
  NS_IMETHOD GetFileHandle(nsIDOMFileHandle * *aFileHandle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileHandle(aFileHandle); } \
  NS_IMETHOD GetMode(nsAString & aMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMode(aMode); } \
  NS_IMETHOD GetActive(bool *aActive) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActive(aActive); } \
  NS_IMETHOD GetLocation(JSContext* cx, JS::Value *aLocation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocation(cx, aLocation); } \
  NS_IMETHOD SetLocation(JSContext* cx, const JS::Value & aLocation) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLocation(cx, aLocation); } \
  NS_IMETHOD GetMetadata(const JS::Value & parameters, JSContext* cx, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMetadata(parameters, cx, _retval); } \
  NS_IMETHOD ReadAsArrayBuffer(uint64_t size, JSContext* cx, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadAsArrayBuffer(size, cx, _retval); } \
  NS_IMETHOD ReadAsText(uint64_t size, const nsAString & encoding, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadAsText(size, encoding, _retval); } \
  NS_IMETHOD Write(const JS::Value & value, JSContext* cx, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Write(value, cx, _retval); } \
  NS_IMETHOD Append(const JS::Value & value, JSContext* cx, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Append(value, cx, _retval); } \
  NS_IMETHOD Truncate(uint64_t size, uint8_t _argc, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Truncate(size, _argc, _retval); } \
  NS_IMETHOD Flush(nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Flush(_retval); } \
  NS_IMETHOD Abort(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Abort(); } \
  NS_IMETHOD GetOncomplete(JSContext* cx, JS::Value *aOncomplete) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOncomplete(cx, aOncomplete); } \
  NS_IMETHOD SetOncomplete(JSContext* cx, const JS::Value & aOncomplete) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOncomplete(cx, aOncomplete); } \
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnabort(cx, aOnabort); } \
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnabort(cx, aOnabort); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnerror(cx, aOnerror); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMLockedFile : public nsIDOMLockedFile
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMLOCKEDFILE

  nsDOMLockedFile();

private:
  ~nsDOMLockedFile();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMLockedFile, nsIDOMLockedFile)

nsDOMLockedFile::nsDOMLockedFile()
{
  /* member initializers and constructor code */
}

nsDOMLockedFile::~nsDOMLockedFile()
{
  /* destructor code */
}

/* readonly attribute nsIDOMFileHandle fileHandle; */
NS_IMETHODIMP nsDOMLockedFile::GetFileHandle(nsIDOMFileHandle * *aFileHandle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString mode; */
NS_IMETHODIMP nsDOMLockedFile::GetMode(nsAString & aMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean active; */
NS_IMETHODIMP nsDOMLockedFile::GetActive(bool *aActive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval location; */
NS_IMETHODIMP nsDOMLockedFile::GetLocation(JSContext* cx, JS::Value *aLocation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLockedFile::SetLocation(JSContext* cx, const JS::Value & aLocation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsISupports getMetadata ([optional] in jsval parameters); */
NS_IMETHODIMP nsDOMLockedFile::GetMetadata(const JS::Value & parameters, JSContext* cx, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsISupports readAsArrayBuffer (in unsigned long long size); */
NS_IMETHODIMP nsDOMLockedFile::ReadAsArrayBuffer(uint64_t size, JSContext* cx, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports readAsText (in unsigned long long size, [optional] in DOMString encoding); */
NS_IMETHODIMP nsDOMLockedFile::ReadAsText(uint64_t size, const nsAString & encoding, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsISupports write (in jsval value); */
NS_IMETHODIMP nsDOMLockedFile::Write(const JS::Value & value, JSContext* cx, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsISupports append (in jsval value); */
NS_IMETHODIMP nsDOMLockedFile::Append(const JS::Value & value, JSContext* cx, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] nsISupports truncate ([optional] in unsigned long long size); */
NS_IMETHODIMP nsDOMLockedFile::Truncate(uint64_t size, uint8_t _argc, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports flush (); */
NS_IMETHODIMP nsDOMLockedFile::Flush(nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void abort (); */
NS_IMETHODIMP nsDOMLockedFile::Abort()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval oncomplete; */
NS_IMETHODIMP nsDOMLockedFile::GetOncomplete(JSContext* cx, JS::Value *aOncomplete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLockedFile::SetOncomplete(JSContext* cx, const JS::Value & aOncomplete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onabort; */
NS_IMETHODIMP nsDOMLockedFile::GetOnabort(JSContext* cx, JS::Value *aOnabort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLockedFile::SetOnabort(JSContext* cx, const JS::Value & aOnabort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onerror; */
NS_IMETHODIMP nsDOMLockedFile::GetOnerror(JSContext* cx, JS::Value *aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLockedFile::SetOnerror(JSContext* cx, const JS::Value & aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMLockedFile_h__ */

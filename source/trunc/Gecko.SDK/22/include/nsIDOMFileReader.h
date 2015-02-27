/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/content/base/public/nsIDOMFileReader.idl
 */

#ifndef __gen_nsIDOMFileReader_h__
#define __gen_nsIDOMFileReader_h__


#ifndef __gen_nsIDOMEventTarget_h__
#include "nsIDOMEventTarget.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMEventListener; /* forward declaration */

class nsIDOMBlob; /* forward declaration */

class nsIDOMDOMError; /* forward declaration */


/* starting interface:    nsIDOMFileReader */
#define NS_IDOMFILEREADER_IID_STR "81a8d00b-2982-44f6-aecf-faac0d0819d6"

#define NS_IDOMFILEREADER_IID \
  {0x81a8d00b, 0x2982, 0x44f6, \
    { 0xae, 0xcf, 0xfa, 0xac, 0x0d, 0x08, 0x19, 0xd6 }}

class NS_NO_VTABLE nsIDOMFileReader : public nsIDOMEventTarget {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMFILEREADER_IID)

  /* [implicit_jscontext] void readAsArrayBuffer (in nsIDOMBlob filedata); */
  NS_IMETHOD ReadAsArrayBuffer(nsIDOMBlob *filedata, JSContext* cx) = 0;

  /* void readAsBinaryString (in nsIDOMBlob filedata); */
  NS_IMETHOD ReadAsBinaryString(nsIDOMBlob *filedata) = 0;

  /* void readAsText (in nsIDOMBlob filedata, [optional] in DOMString encoding); */
  NS_IMETHOD ReadAsText(nsIDOMBlob *filedata, const nsAString & encoding) = 0;

  /* void readAsDataURL (in nsIDOMBlob file); */
  NS_IMETHOD ReadAsDataURL(nsIDOMBlob *file) = 0;

  /* void abort (); */
  NS_IMETHOD Abort(void) = 0;

  enum {
    EMPTY = 0U,
    LOADING = 1U,
    DONE = 2U
  };

  /* readonly attribute unsigned short readyState; */
  NS_IMETHOD GetReadyState(uint16_t *aReadyState) = 0;

  /* [implicit_jscontext] readonly attribute jsval result; */
  NS_IMETHOD GetResult(JSContext* cx, JS::Value *aResult) = 0;

  /* readonly attribute nsIDOMDOMError error; */
  NS_IMETHOD GetError(nsIDOMDOMError * *aError) = 0;

  /* [implicit_jscontext] attribute jsval onloadstart; */
  NS_IMETHOD GetOnloadstart(JSContext* cx, JS::Value *aOnloadstart) = 0;
  NS_IMETHOD SetOnloadstart(JSContext* cx, const JS::Value & aOnloadstart) = 0;

  /* [implicit_jscontext] attribute jsval onprogress; */
  NS_IMETHOD GetOnprogress(JSContext* cx, JS::Value *aOnprogress) = 0;
  NS_IMETHOD SetOnprogress(JSContext* cx, const JS::Value & aOnprogress) = 0;

  /* [implicit_jscontext] attribute jsval onload; */
  NS_IMETHOD GetOnload(JSContext* cx, JS::Value *aOnload) = 0;
  NS_IMETHOD SetOnload(JSContext* cx, const JS::Value & aOnload) = 0;

  /* [implicit_jscontext] attribute jsval onabort; */
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort) = 0;
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort) = 0;

  /* [implicit_jscontext] attribute jsval onerror; */
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) = 0;
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) = 0;

  /* [implicit_jscontext] attribute jsval onloadend; */
  NS_IMETHOD GetOnloadend(JSContext* cx, JS::Value *aOnloadend) = 0;
  NS_IMETHOD SetOnloadend(JSContext* cx, const JS::Value & aOnloadend) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMFileReader, NS_IDOMFILEREADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMFILEREADER \
  NS_IMETHOD ReadAsArrayBuffer(nsIDOMBlob *filedata, JSContext* cx); \
  NS_IMETHOD ReadAsBinaryString(nsIDOMBlob *filedata); \
  NS_IMETHOD ReadAsText(nsIDOMBlob *filedata, const nsAString & encoding); \
  NS_IMETHOD ReadAsDataURL(nsIDOMBlob *file); \
  NS_IMETHOD Abort(void); \
  NS_IMETHOD GetReadyState(uint16_t *aReadyState); \
  NS_IMETHOD GetResult(JSContext* cx, JS::Value *aResult); \
  NS_IMETHOD GetError(nsIDOMDOMError * *aError); \
  NS_IMETHOD GetOnloadstart(JSContext* cx, JS::Value *aOnloadstart); \
  NS_IMETHOD SetOnloadstart(JSContext* cx, const JS::Value & aOnloadstart); \
  NS_IMETHOD GetOnprogress(JSContext* cx, JS::Value *aOnprogress); \
  NS_IMETHOD SetOnprogress(JSContext* cx, const JS::Value & aOnprogress); \
  NS_IMETHOD GetOnload(JSContext* cx, JS::Value *aOnload); \
  NS_IMETHOD SetOnload(JSContext* cx, const JS::Value & aOnload); \
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort); \
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort); \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror); \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror); \
  NS_IMETHOD GetOnloadend(JSContext* cx, JS::Value *aOnloadend); \
  NS_IMETHOD SetOnloadend(JSContext* cx, const JS::Value & aOnloadend); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMFILEREADER(_to) \
  NS_IMETHOD ReadAsArrayBuffer(nsIDOMBlob *filedata, JSContext* cx) { return _to ReadAsArrayBuffer(filedata, cx); } \
  NS_IMETHOD ReadAsBinaryString(nsIDOMBlob *filedata) { return _to ReadAsBinaryString(filedata); } \
  NS_IMETHOD ReadAsText(nsIDOMBlob *filedata, const nsAString & encoding) { return _to ReadAsText(filedata, encoding); } \
  NS_IMETHOD ReadAsDataURL(nsIDOMBlob *file) { return _to ReadAsDataURL(file); } \
  NS_IMETHOD Abort(void) { return _to Abort(); } \
  NS_IMETHOD GetReadyState(uint16_t *aReadyState) { return _to GetReadyState(aReadyState); } \
  NS_IMETHOD GetResult(JSContext* cx, JS::Value *aResult) { return _to GetResult(cx, aResult); } \
  NS_IMETHOD GetError(nsIDOMDOMError * *aError) { return _to GetError(aError); } \
  NS_IMETHOD GetOnloadstart(JSContext* cx, JS::Value *aOnloadstart) { return _to GetOnloadstart(cx, aOnloadstart); } \
  NS_IMETHOD SetOnloadstart(JSContext* cx, const JS::Value & aOnloadstart) { return _to SetOnloadstart(cx, aOnloadstart); } \
  NS_IMETHOD GetOnprogress(JSContext* cx, JS::Value *aOnprogress) { return _to GetOnprogress(cx, aOnprogress); } \
  NS_IMETHOD SetOnprogress(JSContext* cx, const JS::Value & aOnprogress) { return _to SetOnprogress(cx, aOnprogress); } \
  NS_IMETHOD GetOnload(JSContext* cx, JS::Value *aOnload) { return _to GetOnload(cx, aOnload); } \
  NS_IMETHOD SetOnload(JSContext* cx, const JS::Value & aOnload) { return _to SetOnload(cx, aOnload); } \
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort) { return _to GetOnabort(cx, aOnabort); } \
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort) { return _to SetOnabort(cx, aOnabort); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) { return _to GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) { return _to SetOnerror(cx, aOnerror); } \
  NS_IMETHOD GetOnloadend(JSContext* cx, JS::Value *aOnloadend) { return _to GetOnloadend(cx, aOnloadend); } \
  NS_IMETHOD SetOnloadend(JSContext* cx, const JS::Value & aOnloadend) { return _to SetOnloadend(cx, aOnloadend); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMFILEREADER(_to) \
  NS_IMETHOD ReadAsArrayBuffer(nsIDOMBlob *filedata, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadAsArrayBuffer(filedata, cx); } \
  NS_IMETHOD ReadAsBinaryString(nsIDOMBlob *filedata) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadAsBinaryString(filedata); } \
  NS_IMETHOD ReadAsText(nsIDOMBlob *filedata, const nsAString & encoding) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadAsText(filedata, encoding); } \
  NS_IMETHOD ReadAsDataURL(nsIDOMBlob *file) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadAsDataURL(file); } \
  NS_IMETHOD Abort(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Abort(); } \
  NS_IMETHOD GetReadyState(uint16_t *aReadyState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReadyState(aReadyState); } \
  NS_IMETHOD GetResult(JSContext* cx, JS::Value *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResult(cx, aResult); } \
  NS_IMETHOD GetError(nsIDOMDOMError * *aError) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetError(aError); } \
  NS_IMETHOD GetOnloadstart(JSContext* cx, JS::Value *aOnloadstart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnloadstart(cx, aOnloadstart); } \
  NS_IMETHOD SetOnloadstart(JSContext* cx, const JS::Value & aOnloadstart) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnloadstart(cx, aOnloadstart); } \
  NS_IMETHOD GetOnprogress(JSContext* cx, JS::Value *aOnprogress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnprogress(cx, aOnprogress); } \
  NS_IMETHOD SetOnprogress(JSContext* cx, const JS::Value & aOnprogress) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnprogress(cx, aOnprogress); } \
  NS_IMETHOD GetOnload(JSContext* cx, JS::Value *aOnload) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnload(cx, aOnload); } \
  NS_IMETHOD SetOnload(JSContext* cx, const JS::Value & aOnload) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnload(cx, aOnload); } \
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnabort(cx, aOnabort); } \
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnabort(cx, aOnabort); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnerror(cx, aOnerror); } \
  NS_IMETHOD GetOnloadend(JSContext* cx, JS::Value *aOnloadend) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnloadend(cx, aOnloadend); } \
  NS_IMETHOD SetOnloadend(JSContext* cx, const JS::Value & aOnloadend) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnloadend(cx, aOnloadend); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMFileReader : public nsIDOMFileReader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMFILEREADER

  nsDOMFileReader();

private:
  ~nsDOMFileReader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMFileReader, nsIDOMFileReader)

nsDOMFileReader::nsDOMFileReader()
{
  /* member initializers and constructor code */
}

nsDOMFileReader::~nsDOMFileReader()
{
  /* destructor code */
}

/* [implicit_jscontext] void readAsArrayBuffer (in nsIDOMBlob filedata); */
NS_IMETHODIMP nsDOMFileReader::ReadAsArrayBuffer(nsIDOMBlob *filedata, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void readAsBinaryString (in nsIDOMBlob filedata); */
NS_IMETHODIMP nsDOMFileReader::ReadAsBinaryString(nsIDOMBlob *filedata)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void readAsText (in nsIDOMBlob filedata, [optional] in DOMString encoding); */
NS_IMETHODIMP nsDOMFileReader::ReadAsText(nsIDOMBlob *filedata, const nsAString & encoding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void readAsDataURL (in nsIDOMBlob file); */
NS_IMETHODIMP nsDOMFileReader::ReadAsDataURL(nsIDOMBlob *file)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void abort (); */
NS_IMETHODIMP nsDOMFileReader::Abort()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short readyState; */
NS_IMETHODIMP nsDOMFileReader::GetReadyState(uint16_t *aReadyState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval result; */
NS_IMETHODIMP nsDOMFileReader::GetResult(JSContext* cx, JS::Value *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDOMError error; */
NS_IMETHODIMP nsDOMFileReader::GetError(nsIDOMDOMError * *aError)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onloadstart; */
NS_IMETHODIMP nsDOMFileReader::GetOnloadstart(JSContext* cx, JS::Value *aOnloadstart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMFileReader::SetOnloadstart(JSContext* cx, const JS::Value & aOnloadstart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onprogress; */
NS_IMETHODIMP nsDOMFileReader::GetOnprogress(JSContext* cx, JS::Value *aOnprogress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMFileReader::SetOnprogress(JSContext* cx, const JS::Value & aOnprogress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onload; */
NS_IMETHODIMP nsDOMFileReader::GetOnload(JSContext* cx, JS::Value *aOnload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMFileReader::SetOnload(JSContext* cx, const JS::Value & aOnload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onabort; */
NS_IMETHODIMP nsDOMFileReader::GetOnabort(JSContext* cx, JS::Value *aOnabort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMFileReader::SetOnabort(JSContext* cx, const JS::Value & aOnabort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onerror; */
NS_IMETHODIMP nsDOMFileReader::GetOnerror(JSContext* cx, JS::Value *aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMFileReader::SetOnerror(JSContext* cx, const JS::Value & aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onloadend; */
NS_IMETHODIMP nsDOMFileReader::GetOnloadend(JSContext* cx, JS::Value *aOnloadend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMFileReader::SetOnloadend(JSContext* cx, const JS::Value & aOnloadend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_FILEREADER_CID                            \
{0x06aa7c21, 0xfe05, 0x4cf2,                         \
{0xb1, 0xc4, 0x0c, 0x71, 0x26, 0xa4, 0xf7, 0x13}}
#define NS_FILEREADER_CONTRACTID \
"@mozilla.org/files/filereader;1"

#endif /* __gen_nsIDOMFileReader_h__ */

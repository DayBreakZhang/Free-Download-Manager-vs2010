/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIRequest.idl
 */

#ifndef __gen_nsIRequest_h__
#define __gen_nsIRequest_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsILoadGroup; /* forward declaration */

typedef uint32_t  nsLoadFlags;


/* starting interface:    nsIRequest */
#define NS_IREQUEST_IID_STR "ef6bfbd2-fd46-48d8-96b7-9f8f0fd387fe"

#define NS_IREQUEST_IID \
  {0xef6bfbd2, 0xfd46, 0x48d8, \
    { 0x96, 0xb7, 0x9f, 0x8f, 0x0f, 0xd3, 0x87, 0xfe }}

class NS_NO_VTABLE nsIRequest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IREQUEST_IID)

  /* readonly attribute AUTF8String name; */
  NS_IMETHOD GetName(nsACString & aName) = 0;

  /* boolean isPending (); */
  NS_IMETHOD IsPending(bool *_retval) = 0;

  /* readonly attribute nsresult status; */
  NS_IMETHOD GetStatus(nsresult *aStatus) = 0;

  /* void cancel (in nsresult aStatus); */
  NS_IMETHOD Cancel(nsresult aStatus) = 0;

  /* void suspend (); */
  NS_IMETHOD Suspend(void) = 0;

  /* void resume (); */
  NS_IMETHOD Resume(void) = 0;

  /* attribute nsILoadGroup loadGroup; */
  NS_IMETHOD GetLoadGroup(nsILoadGroup * *aLoadGroup) = 0;
  NS_IMETHOD SetLoadGroup(nsILoadGroup *aLoadGroup) = 0;

  /* attribute nsLoadFlags loadFlags; */
  NS_IMETHOD GetLoadFlags(nsLoadFlags *aLoadFlags) = 0;
  NS_IMETHOD SetLoadFlags(nsLoadFlags aLoadFlags) = 0;

  enum {
    LOAD_REQUESTMASK = 65535U,
    LOAD_NORMAL = 0U,
    LOAD_BACKGROUND = 1U,
    INHIBIT_PIPELINE = 64U,
    INHIBIT_CACHING = 128U,
    INHIBIT_PERSISTENT_CACHING = 256U,
    LOAD_BYPASS_CACHE = 512U,
    LOAD_FROM_CACHE = 1024U,
    VALIDATE_ALWAYS = 2048U,
    VALIDATE_NEVER = 4096U,
    VALIDATE_ONCE_PER_SESSION = 8192U,
    LOAD_ANONYMOUS = 16384U,
    LOAD_FRESH_CONNECTION = 32768U
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRequest, NS_IREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIREQUEST \
  NS_IMETHOD GetName(nsACString & aName); \
  NS_IMETHOD IsPending(bool *_retval); \
  NS_IMETHOD GetStatus(nsresult *aStatus); \
  NS_IMETHOD Cancel(nsresult aStatus); \
  NS_IMETHOD Suspend(void); \
  NS_IMETHOD Resume(void); \
  NS_IMETHOD GetLoadGroup(nsILoadGroup * *aLoadGroup); \
  NS_IMETHOD SetLoadGroup(nsILoadGroup *aLoadGroup); \
  NS_IMETHOD GetLoadFlags(nsLoadFlags *aLoadFlags); \
  NS_IMETHOD SetLoadFlags(nsLoadFlags aLoadFlags); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIREQUEST(_to) \
  NS_IMETHOD GetName(nsACString & aName) { return _to GetName(aName); } \
  NS_IMETHOD IsPending(bool *_retval) { return _to IsPending(_retval); } \
  NS_IMETHOD GetStatus(nsresult *aStatus) { return _to GetStatus(aStatus); } \
  NS_IMETHOD Cancel(nsresult aStatus) { return _to Cancel(aStatus); } \
  NS_IMETHOD Suspend(void) { return _to Suspend(); } \
  NS_IMETHOD Resume(void) { return _to Resume(); } \
  NS_IMETHOD GetLoadGroup(nsILoadGroup * *aLoadGroup) { return _to GetLoadGroup(aLoadGroup); } \
  NS_IMETHOD SetLoadGroup(nsILoadGroup *aLoadGroup) { return _to SetLoadGroup(aLoadGroup); } \
  NS_IMETHOD GetLoadFlags(nsLoadFlags *aLoadFlags) { return _to GetLoadFlags(aLoadFlags); } \
  NS_IMETHOD SetLoadFlags(nsLoadFlags aLoadFlags) { return _to SetLoadFlags(aLoadFlags); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIREQUEST(_to) \
  NS_IMETHOD GetName(nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD IsPending(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsPending(_retval); } \
  NS_IMETHOD GetStatus(nsresult *aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatus(aStatus); } \
  NS_IMETHOD Cancel(nsresult aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->Cancel(aStatus); } \
  NS_IMETHOD Suspend(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Suspend(); } \
  NS_IMETHOD Resume(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Resume(); } \
  NS_IMETHOD GetLoadGroup(nsILoadGroup * *aLoadGroup) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadGroup(aLoadGroup); } \
  NS_IMETHOD SetLoadGroup(nsILoadGroup *aLoadGroup) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLoadGroup(aLoadGroup); } \
  NS_IMETHOD GetLoadFlags(nsLoadFlags *aLoadFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadFlags(aLoadFlags); } \
  NS_IMETHOD SetLoadFlags(nsLoadFlags aLoadFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLoadFlags(aLoadFlags); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRequest : public nsIRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIREQUEST

  nsRequest();

private:
  ~nsRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRequest, nsIRequest)

nsRequest::nsRequest()
{
  /* member initializers and constructor code */
}

nsRequest::~nsRequest()
{
  /* destructor code */
}

/* readonly attribute AUTF8String name; */
NS_IMETHODIMP nsRequest::GetName(nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isPending (); */
NS_IMETHODIMP nsRequest::IsPending(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsresult status; */
NS_IMETHODIMP nsRequest::GetStatus(nsresult *aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancel (in nsresult aStatus); */
NS_IMETHODIMP nsRequest::Cancel(nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void suspend (); */
NS_IMETHODIMP nsRequest::Suspend()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resume (); */
NS_IMETHODIMP nsRequest::Resume()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsILoadGroup loadGroup; */
NS_IMETHODIMP nsRequest::GetLoadGroup(nsILoadGroup * *aLoadGroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsRequest::SetLoadGroup(nsILoadGroup *aLoadGroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsLoadFlags loadFlags; */
NS_IMETHODIMP nsRequest::GetLoadFlags(nsLoadFlags *aLoadFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsRequest::SetLoadFlags(nsLoadFlags aLoadFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRequest_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/base/nsIContentPermissionPrompt.idl
 */

#ifndef __gen_nsIContentPermissionPrompt_h__
#define __gen_nsIContentPermissionPrompt_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIDOMWindow; /* forward declaration */

class nsIDOMElement; /* forward declaration */


/* starting interface:    nsIContentPermissionRequest */
#define NS_ICONTENTPERMISSIONREQUEST_IID_STR "e79c7063-dbab-45e3-8a98-d0142e1abc9a"

#define NS_ICONTENTPERMISSIONREQUEST_IID \
  {0xe79c7063, 0xdbab, 0x45e3, \
    { 0x8a, 0x98, 0xd0, 0x14, 0x2e, 0x1a, 0xbc, 0x9a }}

/**
 * Interface allows access to a content to request
 * permission to perform a privileged operation such as
 * geolocation.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIContentPermissionRequest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPERMISSIONREQUEST_IID)

  /**
   *  The type of the permission request, such as
   *  "geolocation".
   */
  /* readonly attribute ACString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsACString & aType) = 0;

  /**
   *  The uri of the permission request.
   */
  /* readonly attribute nsIURI uri; */
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI **aUri) = 0;

  /**
   *  The window or element that the permission request was
   *  originated in.  Typically the element will be non-null
   *  in when using out of process content.  window or
   *  element can be null but not both.
   */
  /* readonly attribute nsIDOMWindow window; */
  NS_SCRIPTABLE NS_IMETHOD GetWindow(nsIDOMWindow **aWindow) = 0;

  /* readonly attribute nsIDOMElement element; */
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsIDOMElement **aElement) = 0;

  /**
   * allow or cancel the request
   */
  /* void cancel (); */
  NS_SCRIPTABLE NS_IMETHOD Cancel(void) = 0;

  /* void allow (); */
  NS_SCRIPTABLE NS_IMETHOD Allow(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPermissionRequest, NS_ICONTENTPERMISSIONREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPERMISSIONREQUEST \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsACString & aType); \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI **aUri); \
  NS_SCRIPTABLE NS_IMETHOD GetWindow(nsIDOMWindow **aWindow); \
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsIDOMElement **aElement); \
  NS_SCRIPTABLE NS_IMETHOD Cancel(void); \
  NS_SCRIPTABLE NS_IMETHOD Allow(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPERMISSIONREQUEST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsACString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI **aUri) { return _to GetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD GetWindow(nsIDOMWindow **aWindow) { return _to GetWindow(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsIDOMElement **aElement) { return _to GetElement(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD Cancel(void) { return _to Cancel(); } \
  NS_SCRIPTABLE NS_IMETHOD Allow(void) { return _to Allow(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPERMISSIONREQUEST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsACString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI **aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD GetWindow(nsIDOMWindow **aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindow(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsIDOMElement **aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElement(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD Cancel(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Cancel(); } \
  NS_SCRIPTABLE NS_IMETHOD Allow(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Allow(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentPermissionRequest : public nsIContentPermissionRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTPERMISSIONREQUEST

  nsContentPermissionRequest();

private:
  ~nsContentPermissionRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentPermissionRequest, nsIContentPermissionRequest)

nsContentPermissionRequest::nsContentPermissionRequest()
{
  /* member initializers and constructor code */
}

nsContentPermissionRequest::~nsContentPermissionRequest()
{
  /* destructor code */
}

/* readonly attribute ACString type; */
NS_IMETHODIMP nsContentPermissionRequest::GetType(nsACString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI uri; */
NS_IMETHODIMP nsContentPermissionRequest::GetUri(nsIURI **aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow window; */
NS_IMETHODIMP nsContentPermissionRequest::GetWindow(nsIDOMWindow **aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement element; */
NS_IMETHODIMP nsContentPermissionRequest::GetElement(nsIDOMElement **aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancel (); */
NS_IMETHODIMP nsContentPermissionRequest::Cancel()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void allow (); */
NS_IMETHODIMP nsContentPermissionRequest::Allow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContentPermissionPrompt */
#define NS_ICONTENTPERMISSIONPROMPT_IID_STR "f72de90d-e954-4e69-9a61-917303029301"

#define NS_ICONTENTPERMISSIONPROMPT_IID \
  {0xf72de90d, 0xe954, 0x4e69, \
    { 0x9a, 0x61, 0x91, 0x73, 0x03, 0x02, 0x93, 0x01 }}

/**
 * Interface provides a way for the application to handle
 * the UI prompts associated with geo position.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIContentPermissionPrompt : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPERMISSIONPROMPT_IID)

  /**
   * Called when a request has been made to access
   * privileged content apis
   */
  /* void prompt (in nsIContentPermissionRequest request); */
  NS_SCRIPTABLE NS_IMETHOD Prompt(nsIContentPermissionRequest *request) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPermissionPrompt, NS_ICONTENTPERMISSIONPROMPT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPERMISSIONPROMPT \
  NS_SCRIPTABLE NS_IMETHOD Prompt(nsIContentPermissionRequest *request); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPERMISSIONPROMPT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Prompt(nsIContentPermissionRequest *request) { return _to Prompt(request); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPERMISSIONPROMPT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Prompt(nsIContentPermissionRequest *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->Prompt(request); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentPermissionPrompt : public nsIContentPermissionPrompt
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTPERMISSIONPROMPT

  nsContentPermissionPrompt();

private:
  ~nsContentPermissionPrompt();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentPermissionPrompt, nsIContentPermissionPrompt)

nsContentPermissionPrompt::nsContentPermissionPrompt()
{
  /* member initializers and constructor code */
}

nsContentPermissionPrompt::~nsContentPermissionPrompt()
{
  /* destructor code */
}

/* void prompt (in nsIContentPermissionRequest request); */
NS_IMETHODIMP nsContentPermissionPrompt::Prompt(nsIContentPermissionRequest *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_CONTENT_PERMISSION_PROMPT_CONTRACTID   "@mozilla.org/content-permission/prompt;1"

#endif /* __gen_nsIContentPermissionPrompt_h__ */

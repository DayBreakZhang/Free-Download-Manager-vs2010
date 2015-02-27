/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIContentPermissionPrompt.idl
 */

#ifndef __gen_nsIContentPermissionPrompt_h__
#define __gen_nsIContentPermissionPrompt_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPrincipal; /* forward declaration */

class nsIDOMWindow; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIArray; /* forward declaration */


/* starting interface:    nsIContentPermissionType */
#define NS_ICONTENTPERMISSIONTYPE_IID_STR "ef4db3b8-ca9c-4b1d-8f81-fd88ec32af13"

#define NS_ICONTENTPERMISSIONTYPE_IID \
  {0xef4db3b8, 0xca9c, 0x4b1d, \
    { 0x8f, 0x81, 0xfd, 0x88, 0xec, 0x32, 0xaf, 0x13 }}

class NS_NO_VTABLE nsIContentPermissionType : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPERMISSIONTYPE_IID)

  /* readonly attribute ACString type; */
  NS_IMETHOD GetType(nsACString & aType) = 0;

  /* readonly attribute ACString access; */
  NS_IMETHOD GetAccess(nsACString & aAccess) = 0;

  /* readonly attribute nsIArray options; */
  NS_IMETHOD GetOptions(nsIArray * *aOptions) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPermissionType, NS_ICONTENTPERMISSIONTYPE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPERMISSIONTYPE \
  NS_IMETHOD GetType(nsACString & aType); \
  NS_IMETHOD GetAccess(nsACString & aAccess); \
  NS_IMETHOD GetOptions(nsIArray * *aOptions); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPERMISSIONTYPE(_to) \
  NS_IMETHOD GetType(nsACString & aType) { return _to GetType(aType); } \
  NS_IMETHOD GetAccess(nsACString & aAccess) { return _to GetAccess(aAccess); } \
  NS_IMETHOD GetOptions(nsIArray * *aOptions) { return _to GetOptions(aOptions); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPERMISSIONTYPE(_to) \
  NS_IMETHOD GetType(nsACString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetAccess(nsACString & aAccess) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccess(aAccess); } \
  NS_IMETHOD GetOptions(nsIArray * *aOptions) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOptions(aOptions); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentPermissionType : public nsIContentPermissionType
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTPERMISSIONTYPE

  nsContentPermissionType();

private:
  ~nsContentPermissionType();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentPermissionType, nsIContentPermissionType)

nsContentPermissionType::nsContentPermissionType()
{
  /* member initializers and constructor code */
}

nsContentPermissionType::~nsContentPermissionType()
{
  /* destructor code */
}

/* readonly attribute ACString type; */
NS_IMETHODIMP nsContentPermissionType::GetType(nsACString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString access; */
NS_IMETHODIMP nsContentPermissionType::GetAccess(nsACString & aAccess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIArray options; */
NS_IMETHODIMP nsContentPermissionType::GetOptions(nsIArray * *aOptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContentPermissionRequest */
#define NS_ICONTENTPERMISSIONREQUEST_IID_STR "69a39d88-d1c4-4ba9-9b19-bafc7a1bb783"

#define NS_ICONTENTPERMISSIONREQUEST_IID \
  {0x69a39d88, 0xd1c4, 0x4ba9, \
    { 0x9b, 0x19, 0xba, 0xfc, 0x7a, 0x1b, 0xb7, 0x83 }}

class NS_NO_VTABLE nsIContentPermissionRequest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPERMISSIONREQUEST_IID)

  /* readonly attribute nsIArray types; */
  NS_IMETHOD GetTypes(nsIArray * *aTypes) = 0;

  /* readonly attribute nsIPrincipal principal; */
  NS_IMETHOD GetPrincipal(nsIPrincipal * *aPrincipal) = 0;

  /* readonly attribute nsIDOMWindow window; */
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) = 0;

  /* readonly attribute nsIDOMElement element; */
  NS_IMETHOD GetElement(nsIDOMElement * *aElement) = 0;

  /* void cancel (); */
  NS_IMETHOD Cancel(void) = 0;

  /* void allow ([optional] in jsval choices); */
  NS_IMETHOD Allow(JS::HandleValue choices) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPermissionRequest, NS_ICONTENTPERMISSIONREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPERMISSIONREQUEST \
  NS_IMETHOD GetTypes(nsIArray * *aTypes); \
  NS_IMETHOD GetPrincipal(nsIPrincipal * *aPrincipal); \
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow); \
  NS_IMETHOD GetElement(nsIDOMElement * *aElement); \
  NS_IMETHOD Cancel(void); \
  NS_IMETHOD Allow(JS::HandleValue choices); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPERMISSIONREQUEST(_to) \
  NS_IMETHOD GetTypes(nsIArray * *aTypes) { return _to GetTypes(aTypes); } \
  NS_IMETHOD GetPrincipal(nsIPrincipal * *aPrincipal) { return _to GetPrincipal(aPrincipal); } \
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) { return _to GetWindow(aWindow); } \
  NS_IMETHOD GetElement(nsIDOMElement * *aElement) { return _to GetElement(aElement); } \
  NS_IMETHOD Cancel(void) { return _to Cancel(); } \
  NS_IMETHOD Allow(JS::HandleValue choices) { return _to Allow(choices); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPERMISSIONREQUEST(_to) \
  NS_IMETHOD GetTypes(nsIArray * *aTypes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypes(aTypes); } \
  NS_IMETHOD GetPrincipal(nsIPrincipal * *aPrincipal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrincipal(aPrincipal); } \
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindow(aWindow); } \
  NS_IMETHOD GetElement(nsIDOMElement * *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElement(aElement); } \
  NS_IMETHOD Cancel(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Cancel(); } \
  NS_IMETHOD Allow(JS::HandleValue choices) { return !_to ? NS_ERROR_NULL_POINTER : _to->Allow(choices); } 

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

/* readonly attribute nsIArray types; */
NS_IMETHODIMP nsContentPermissionRequest::GetTypes(nsIArray * *aTypes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIPrincipal principal; */
NS_IMETHODIMP nsContentPermissionRequest::GetPrincipal(nsIPrincipal * *aPrincipal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow window; */
NS_IMETHODIMP nsContentPermissionRequest::GetWindow(nsIDOMWindow * *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement element; */
NS_IMETHODIMP nsContentPermissionRequest::GetElement(nsIDOMElement * *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancel (); */
NS_IMETHODIMP nsContentPermissionRequest::Cancel()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void allow ([optional] in jsval choices); */
NS_IMETHODIMP nsContentPermissionRequest::Allow(JS::HandleValue choices)
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

class NS_NO_VTABLE nsIContentPermissionPrompt : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPERMISSIONPROMPT_IID)

  /* void prompt (in nsIContentPermissionRequest request); */
  NS_IMETHOD Prompt(nsIContentPermissionRequest *request) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPermissionPrompt, NS_ICONTENTPERMISSIONPROMPT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPERMISSIONPROMPT \
  NS_IMETHOD Prompt(nsIContentPermissionRequest *request); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPERMISSIONPROMPT(_to) \
  NS_IMETHOD Prompt(nsIContentPermissionRequest *request) { return _to Prompt(request); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPERMISSIONPROMPT(_to) \
  NS_IMETHOD Prompt(nsIContentPermissionRequest *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->Prompt(request); } 

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

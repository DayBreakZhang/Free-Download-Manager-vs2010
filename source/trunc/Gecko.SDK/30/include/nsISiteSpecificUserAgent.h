/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISiteSpecificUserAgent.idl
 */

#ifndef __gen_nsISiteSpecificUserAgent_h__
#define __gen_nsISiteSpecificUserAgent_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsISiteSpecificUserAgent */
#define NS_ISITESPECIFICUSERAGENT_IID_STR "a509469a-ef3d-4ad1-8dba-c92a96b0bc64"

#define NS_ISITESPECIFICUSERAGENT_IID \
  {0xa509469a, 0xef3d, 0x4ad1, \
    { 0x8d, 0xba, 0xc9, 0x2a, 0x96, 0xb0, 0xbc, 0x64 }}

class NS_NO_VTABLE nsISiteSpecificUserAgent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISITESPECIFICUSERAGENT_IID)

  /* AString getUserAgentForURIAndWindow (in nsIURI aURI, in nsIDOMWindow aWindow); */
  NS_IMETHOD GetUserAgentForURIAndWindow(nsIURI *aURI, nsIDOMWindow *aWindow, nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISiteSpecificUserAgent, NS_ISITESPECIFICUSERAGENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISITESPECIFICUSERAGENT \
  NS_IMETHOD GetUserAgentForURIAndWindow(nsIURI *aURI, nsIDOMWindow *aWindow, nsAString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISITESPECIFICUSERAGENT(_to) \
  NS_IMETHOD GetUserAgentForURIAndWindow(nsIURI *aURI, nsIDOMWindow *aWindow, nsAString & _retval) { return _to GetUserAgentForURIAndWindow(aURI, aWindow, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISITESPECIFICUSERAGENT(_to) \
  NS_IMETHOD GetUserAgentForURIAndWindow(nsIURI *aURI, nsIDOMWindow *aWindow, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUserAgentForURIAndWindow(aURI, aWindow, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSiteSpecificUserAgent : public nsISiteSpecificUserAgent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISITESPECIFICUSERAGENT

  nsSiteSpecificUserAgent();

private:
  ~nsSiteSpecificUserAgent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSiteSpecificUserAgent, nsISiteSpecificUserAgent)

nsSiteSpecificUserAgent::nsSiteSpecificUserAgent()
{
  /* member initializers and constructor code */
}

nsSiteSpecificUserAgent::~nsSiteSpecificUserAgent()
{
  /* destructor code */
}

/* AString getUserAgentForURIAndWindow (in nsIURI aURI, in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsSiteSpecificUserAgent::GetUserAgentForURIAndWindow(nsIURI *aURI, nsIDOMWindow *aWindow, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISiteSpecificUserAgent_h__ */

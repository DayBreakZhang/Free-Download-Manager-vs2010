/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIInterAppCommService.idl
 */

#ifndef __gen_nsIInterAppCommService_h__
#define __gen_nsIInterAppCommService_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsIInterAppCommService */
#define NS_IINTERAPPCOMMSERVICE_IID_STR "b3d711a4-c6a4-11e3-8fd3-738e7fbcb6d6"

#define NS_IINTERAPPCOMMSERVICE_IID \
  {0xb3d711a4, 0xc6a4, 0x11e3, \
    { 0x8f, 0xd3, 0x73, 0x8e, 0x7f, 0xbc, 0xb6, 0xd6 }}

class NS_NO_VTABLE nsIInterAppCommService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINTERAPPCOMMSERVICE_IID)

  /* void registerConnection (in DOMString keyword, in nsIURI handlerPageURI, in nsIURI manifestURI, in DOMString description, in jsval rules); */
  NS_IMETHOD RegisterConnection(const nsAString & keyword, nsIURI *handlerPageURI, nsIURI *manifestURI, const nsAString & description, JS::HandleValue rules) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInterAppCommService, NS_IINTERAPPCOMMSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINTERAPPCOMMSERVICE \
  NS_IMETHOD RegisterConnection(const nsAString & keyword, nsIURI *handlerPageURI, nsIURI *manifestURI, const nsAString & description, JS::HandleValue rules); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINTERAPPCOMMSERVICE(_to) \
  NS_IMETHOD RegisterConnection(const nsAString & keyword, nsIURI *handlerPageURI, nsIURI *manifestURI, const nsAString & description, JS::HandleValue rules) { return _to RegisterConnection(keyword, handlerPageURI, manifestURI, description, rules); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINTERAPPCOMMSERVICE(_to) \
  NS_IMETHOD RegisterConnection(const nsAString & keyword, nsIURI *handlerPageURI, nsIURI *manifestURI, const nsAString & description, JS::HandleValue rules) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterConnection(keyword, handlerPageURI, manifestURI, description, rules); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInterAppCommService : public nsIInterAppCommService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINTERAPPCOMMSERVICE

  nsInterAppCommService();

private:
  ~nsInterAppCommService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsInterAppCommService, nsIInterAppCommService)

nsInterAppCommService::nsInterAppCommService()
{
  /* member initializers and constructor code */
}

nsInterAppCommService::~nsInterAppCommService()
{
  /* destructor code */
}

/* void registerConnection (in DOMString keyword, in nsIURI handlerPageURI, in nsIURI manifestURI, in DOMString description, in jsval rules); */
NS_IMETHODIMP nsInterAppCommService::RegisterConnection(const nsAString & keyword, nsIURI *handlerPageURI, nsIURI *manifestURI, const nsAString & description, JS::HandleValue rules)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIInterAppCommService_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISecurityWarningDialogs.idl
 */

#ifndef __gen_nsISecurityWarningDialogs_h__
#define __gen_nsISecurityWarningDialogs_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInterfaceRequestor; /* forward declaration */


/* starting interface:    nsISecurityWarningDialogs */
#define NS_ISECURITYWARNINGDIALOGS_IID_STR "a9561631-5964-4d3f-b372-9f23504054b1"

#define NS_ISECURITYWARNINGDIALOGS_IID \
  {0xa9561631, 0x5964, 0x4d3f, \
    { 0xb3, 0x72, 0x9f, 0x23, 0x50, 0x40, 0x54, 0xb1 }}

class NS_NO_VTABLE nsISecurityWarningDialogs : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISECURITYWARNINGDIALOGS_IID)

  /* boolean confirmPostToInsecureFromSecure (in nsIInterfaceRequestor ctx); */
  NS_IMETHOD ConfirmPostToInsecureFromSecure(nsIInterfaceRequestor *ctx, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISecurityWarningDialogs, NS_ISECURITYWARNINGDIALOGS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISECURITYWARNINGDIALOGS \
  NS_IMETHOD ConfirmPostToInsecureFromSecure(nsIInterfaceRequestor *ctx, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISECURITYWARNINGDIALOGS(_to) \
  NS_IMETHOD ConfirmPostToInsecureFromSecure(nsIInterfaceRequestor *ctx, bool *_retval) { return _to ConfirmPostToInsecureFromSecure(ctx, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISECURITYWARNINGDIALOGS(_to) \
  NS_IMETHOD ConfirmPostToInsecureFromSecure(nsIInterfaceRequestor *ctx, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConfirmPostToInsecureFromSecure(ctx, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSecurityWarningDialogs : public nsISecurityWarningDialogs
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISECURITYWARNINGDIALOGS

  nsSecurityWarningDialogs();

private:
  ~nsSecurityWarningDialogs();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSecurityWarningDialogs, nsISecurityWarningDialogs)

nsSecurityWarningDialogs::nsSecurityWarningDialogs()
{
  /* member initializers and constructor code */
}

nsSecurityWarningDialogs::~nsSecurityWarningDialogs()
{
  /* destructor code */
}

/* boolean confirmPostToInsecureFromSecure (in nsIInterfaceRequestor ctx); */
NS_IMETHODIMP nsSecurityWarningDialogs::ConfirmPostToInsecureFromSecure(nsIInterfaceRequestor *ctx, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_SECURITYWARNINGDIALOGS_CONTRACTID "@mozilla.org/nsSecurityWarningDialogs;1"

#endif /* __gen_nsISecurityWarningDialogs_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAboutModule.idl
 */

#ifndef __gen_nsIAboutModule_h__
#define __gen_nsIAboutModule_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIChannel; /* forward declaration */


/* starting interface:    nsIAboutModule */
#define NS_IABOUTMODULE_IID_STR "9575693c-60d9-4332-b6b8-6c29289339cb"

#define NS_IABOUTMODULE_IID \
  {0x9575693c, 0x60d9, 0x4332, \
    { 0xb6, 0xb8, 0x6c, 0x29, 0x28, 0x93, 0x39, 0xcb }}

class NS_NO_VTABLE nsIAboutModule : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IABOUTMODULE_IID)

  /* nsIChannel newChannel (in nsIURI aURI); */
  NS_IMETHOD NewChannel(nsIURI *aURI, nsIChannel * *_retval) = 0;

  enum {
    URI_SAFE_FOR_UNTRUSTED_CONTENT = 1U,
    ALLOW_SCRIPT = 2U,
    HIDE_FROM_ABOUTABOUT = 4U
  };

  /* unsigned long getURIFlags (in nsIURI aURI); */
  NS_IMETHOD GetURIFlags(nsIURI *aURI, uint32_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAboutModule, NS_IABOUTMODULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIABOUTMODULE \
  NS_IMETHOD NewChannel(nsIURI *aURI, nsIChannel * *_retval); \
  NS_IMETHOD GetURIFlags(nsIURI *aURI, uint32_t *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIABOUTMODULE(_to) \
  NS_IMETHOD NewChannel(nsIURI *aURI, nsIChannel * *_retval) { return _to NewChannel(aURI, _retval); } \
  NS_IMETHOD GetURIFlags(nsIURI *aURI, uint32_t *_retval) { return _to GetURIFlags(aURI, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIABOUTMODULE(_to) \
  NS_IMETHOD NewChannel(nsIURI *aURI, nsIChannel * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewChannel(aURI, _retval); } \
  NS_IMETHOD GetURIFlags(nsIURI *aURI, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURIFlags(aURI, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAboutModule : public nsIAboutModule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIABOUTMODULE

  nsAboutModule();

private:
  ~nsAboutModule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAboutModule, nsIAboutModule)

nsAboutModule::nsAboutModule()
{
  /* member initializers and constructor code */
}

nsAboutModule::~nsAboutModule()
{
  /* destructor code */
}

/* nsIChannel newChannel (in nsIURI aURI); */
NS_IMETHODIMP nsAboutModule::NewChannel(nsIURI *aURI, nsIChannel * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getURIFlags (in nsIURI aURI); */
NS_IMETHODIMP nsAboutModule::GetURIFlags(nsIURI *aURI, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define NS_ABOUT_MODULE_CONTRACTID        "@mozilla.org/network/protocol/about;1" 
#define NS_ABOUT_MODULE_CONTRACTID_PREFIX NS_ABOUT_MODULE_CONTRACTID "?what=" 
#define NS_ABOUT_MODULE_CONTRACTID_LENGTH 49      // strlen(NS_ABOUT_MODULE_CONTRACTID_PREFIX)

#endif /* __gen_nsIAboutModule_h__ */

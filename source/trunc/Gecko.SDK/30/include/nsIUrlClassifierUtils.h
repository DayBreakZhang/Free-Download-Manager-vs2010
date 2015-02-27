/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIUrlClassifierUtils.idl
 */

#ifndef __gen_nsIUrlClassifierUtils_h__
#define __gen_nsIUrlClassifierUtils_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsIUrlClassifierUtils */
#define NS_IURLCLASSIFIERUTILS_IID_STR "e4f0e59c-b922-48b0-a7b6-1735c1f96fed"

#define NS_IURLCLASSIFIERUTILS_IID \
  {0xe4f0e59c, 0xb922, 0x48b0, \
    { 0xa7, 0xb6, 0x17, 0x35, 0xc1, 0xf9, 0x6f, 0xed }}

class NS_NO_VTABLE nsIUrlClassifierUtils : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURLCLASSIFIERUTILS_IID)

  /* ACString getKeyForURI (in nsIURI uri); */
  NS_IMETHOD GetKeyForURI(nsIURI *uri, nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUrlClassifierUtils, NS_IURLCLASSIFIERUTILS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURLCLASSIFIERUTILS \
  NS_IMETHOD GetKeyForURI(nsIURI *uri, nsACString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURLCLASSIFIERUTILS(_to) \
  NS_IMETHOD GetKeyForURI(nsIURI *uri, nsACString & _retval) { return _to GetKeyForURI(uri, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURLCLASSIFIERUTILS(_to) \
  NS_IMETHOD GetKeyForURI(nsIURI *uri, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeyForURI(uri, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUrlClassifierUtils : public nsIUrlClassifierUtils
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURLCLASSIFIERUTILS

  nsUrlClassifierUtils();

private:
  ~nsUrlClassifierUtils();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUrlClassifierUtils, nsIUrlClassifierUtils)

nsUrlClassifierUtils::nsUrlClassifierUtils()
{
  /* member initializers and constructor code */
}

nsUrlClassifierUtils::~nsUrlClassifierUtils()
{
  /* destructor code */
}

/* ACString getKeyForURI (in nsIURI uri); */
NS_IMETHODIMP nsUrlClassifierUtils::GetKeyForURI(nsIURI *uri, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUrlClassifierUtils_h__ */

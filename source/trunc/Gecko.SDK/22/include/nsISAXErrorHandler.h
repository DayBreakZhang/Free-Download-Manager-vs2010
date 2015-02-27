/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/parser/xml/public/nsISAXErrorHandler.idl
 */

#ifndef __gen_nsISAXErrorHandler_h__
#define __gen_nsISAXErrorHandler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISAXLocator; /* forward declaration */


/* starting interface:    nsISAXErrorHandler */
#define NS_ISAXERRORHANDLER_IID_STR "e02b6693-6cca-11da-be43-001422106990"

#define NS_ISAXERRORHANDLER_IID \
  {0xe02b6693, 0x6cca, 0x11da, \
    { 0xbe, 0x43, 0x00, 0x14, 0x22, 0x10, 0x69, 0x90 }}

class NS_NO_VTABLE nsISAXErrorHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISAXERRORHANDLER_IID)

  /* void error (in nsISAXLocator locator, in AString error); */
  NS_IMETHOD Error(nsISAXLocator *locator, const nsAString & error) = 0;

  /* void fatalError (in nsISAXLocator locator, in AString error); */
  NS_IMETHOD FatalError(nsISAXLocator *locator, const nsAString & error) = 0;

  /* void ignorableWarning (in nsISAXLocator locator, in AString error); */
  NS_IMETHOD IgnorableWarning(nsISAXLocator *locator, const nsAString & error) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISAXErrorHandler, NS_ISAXERRORHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISAXERRORHANDLER \
  NS_IMETHOD Error(nsISAXLocator *locator, const nsAString & error); \
  NS_IMETHOD FatalError(nsISAXLocator *locator, const nsAString & error); \
  NS_IMETHOD IgnorableWarning(nsISAXLocator *locator, const nsAString & error); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISAXERRORHANDLER(_to) \
  NS_IMETHOD Error(nsISAXLocator *locator, const nsAString & error) { return _to Error(locator, error); } \
  NS_IMETHOD FatalError(nsISAXLocator *locator, const nsAString & error) { return _to FatalError(locator, error); } \
  NS_IMETHOD IgnorableWarning(nsISAXLocator *locator, const nsAString & error) { return _to IgnorableWarning(locator, error); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISAXERRORHANDLER(_to) \
  NS_IMETHOD Error(nsISAXLocator *locator, const nsAString & error) { return !_to ? NS_ERROR_NULL_POINTER : _to->Error(locator, error); } \
  NS_IMETHOD FatalError(nsISAXLocator *locator, const nsAString & error) { return !_to ? NS_ERROR_NULL_POINTER : _to->FatalError(locator, error); } \
  NS_IMETHOD IgnorableWarning(nsISAXLocator *locator, const nsAString & error) { return !_to ? NS_ERROR_NULL_POINTER : _to->IgnorableWarning(locator, error); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSAXErrorHandler : public nsISAXErrorHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISAXERRORHANDLER

  nsSAXErrorHandler();

private:
  ~nsSAXErrorHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSAXErrorHandler, nsISAXErrorHandler)

nsSAXErrorHandler::nsSAXErrorHandler()
{
  /* member initializers and constructor code */
}

nsSAXErrorHandler::~nsSAXErrorHandler()
{
  /* destructor code */
}

/* void error (in nsISAXLocator locator, in AString error); */
NS_IMETHODIMP nsSAXErrorHandler::Error(nsISAXLocator *locator, const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void fatalError (in nsISAXLocator locator, in AString error); */
NS_IMETHODIMP nsSAXErrorHandler::FatalError(nsISAXLocator *locator, const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ignorableWarning (in nsISAXLocator locator, in AString error); */
NS_IMETHODIMP nsSAXErrorHandler::IgnorableWarning(nsISAXLocator *locator, const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISAXErrorHandler_h__ */

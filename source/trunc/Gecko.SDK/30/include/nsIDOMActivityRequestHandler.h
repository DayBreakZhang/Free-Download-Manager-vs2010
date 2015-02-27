/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMActivityRequestHandler.idl
 */

#ifndef __gen_nsIDOMActivityRequestHandler_h__
#define __gen_nsIDOMActivityRequestHandler_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMMozActivityOptions; /* forward declaration */


/* starting interface:    nsIDOMMozActivityRequestHandler */
#define NS_IDOMMOZACTIVITYREQUESTHANDLER_IID_STR "e70c4181-ea3f-4aa5-a2f7-af910dc65e45"

#define NS_IDOMMOZACTIVITYREQUESTHANDLER_IID \
  {0xe70c4181, 0xea3f, 0x4aa5, \
    { 0xa2, 0xf7, 0xaf, 0x91, 0x0d, 0xc6, 0x5e, 0x45 }}

class NS_NO_VTABLE nsIDOMMozActivityRequestHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZACTIVITYREQUESTHANDLER_IID)

  /* void postResult (in jsval result); */
  NS_IMETHOD PostResult(JS::HandleValue result) = 0;

  /* void postError (in DOMString error); */
  NS_IMETHOD PostError(const nsAString & error) = 0;

  /* readonly attribute nsIDOMMozActivityOptions source; */
  NS_IMETHOD GetSource(nsIDOMMozActivityOptions * *aSource) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozActivityRequestHandler, NS_IDOMMOZACTIVITYREQUESTHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZACTIVITYREQUESTHANDLER \
  NS_IMETHOD PostResult(JS::HandleValue result); \
  NS_IMETHOD PostError(const nsAString & error); \
  NS_IMETHOD GetSource(nsIDOMMozActivityOptions * *aSource); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZACTIVITYREQUESTHANDLER(_to) \
  NS_IMETHOD PostResult(JS::HandleValue result) { return _to PostResult(result); } \
  NS_IMETHOD PostError(const nsAString & error) { return _to PostError(error); } \
  NS_IMETHOD GetSource(nsIDOMMozActivityOptions * *aSource) { return _to GetSource(aSource); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZACTIVITYREQUESTHANDLER(_to) \
  NS_IMETHOD PostResult(JS::HandleValue result) { return !_to ? NS_ERROR_NULL_POINTER : _to->PostResult(result); } \
  NS_IMETHOD PostError(const nsAString & error) { return !_to ? NS_ERROR_NULL_POINTER : _to->PostError(error); } \
  NS_IMETHOD GetSource(nsIDOMMozActivityOptions * *aSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSource(aSource); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozActivityRequestHandler : public nsIDOMMozActivityRequestHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZACTIVITYREQUESTHANDLER

  nsDOMMozActivityRequestHandler();

private:
  ~nsDOMMozActivityRequestHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozActivityRequestHandler, nsIDOMMozActivityRequestHandler)

nsDOMMozActivityRequestHandler::nsDOMMozActivityRequestHandler()
{
  /* member initializers and constructor code */
}

nsDOMMozActivityRequestHandler::~nsDOMMozActivityRequestHandler()
{
  /* destructor code */
}

/* void postResult (in jsval result); */
NS_IMETHODIMP nsDOMMozActivityRequestHandler::PostResult(JS::HandleValue result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void postError (in DOMString error); */
NS_IMETHODIMP nsDOMMozActivityRequestHandler::PostError(const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMMozActivityOptions source; */
NS_IMETHODIMP nsDOMMozActivityRequestHandler::GetSource(nsIDOMMozActivityOptions * *aSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMActivityRequestHandler_h__ */

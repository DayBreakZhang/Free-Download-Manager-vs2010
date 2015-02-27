/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIXULSortService.idl
 */

#ifndef __gen_nsIXULSortService_h__
#define __gen_nsIXULSortService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNode; /* forward declaration */


/* starting interface:    nsIXULSortService */
#define NS_IXULSORTSERVICE_IID_STR "f29270c8-3be5-4046-9b57-945a84dff132"

#define NS_IXULSORTSERVICE_IID \
  {0xf29270c8, 0x3be5, 0x4046, \
    { 0x9b, 0x57, 0x94, 0x5a, 0x84, 0xdf, 0xf1, 0x32 }}

class NS_NO_VTABLE nsIXULSortService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULSORTSERVICE_IID)

  enum {
    SORT_COMPARECASE = 1U,
    SORT_INTEGER = 256U
  };

  /* void sort (in nsIDOMNode aNode, in AString aSortKey, in AString aSortHints); */
  NS_IMETHOD Sort(nsIDOMNode *aNode, const nsAString & aSortKey, const nsAString & aSortHints) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULSortService, NS_IXULSORTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULSORTSERVICE \
  NS_IMETHOD Sort(nsIDOMNode *aNode, const nsAString & aSortKey, const nsAString & aSortHints); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULSORTSERVICE(_to) \
  NS_IMETHOD Sort(nsIDOMNode *aNode, const nsAString & aSortKey, const nsAString & aSortHints) { return _to Sort(aNode, aSortKey, aSortHints); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULSORTSERVICE(_to) \
  NS_IMETHOD Sort(nsIDOMNode *aNode, const nsAString & aSortKey, const nsAString & aSortHints) { return !_to ? NS_ERROR_NULL_POINTER : _to->Sort(aNode, aSortKey, aSortHints); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULSortService : public nsIXULSortService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULSORTSERVICE

  nsXULSortService();

private:
  ~nsXULSortService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXULSortService, nsIXULSortService)

nsXULSortService::nsXULSortService()
{
  /* member initializers and constructor code */
}

nsXULSortService::~nsXULSortService()
{
  /* destructor code */
}

/* void sort (in nsIDOMNode aNode, in AString aSortKey, in AString aSortHints); */
NS_IMETHODIMP nsXULSortService::Sort(nsIDOMNode *aNode, const nsAString & aSortKey, const nsAString & aSortHints)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

nsresult
NS_NewXULSortService(nsIXULSortService **result);

#endif /* __gen_nsIXULSortService_h__ */

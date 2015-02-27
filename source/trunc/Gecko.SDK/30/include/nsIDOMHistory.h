/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMHistory.idl
 */

#ifndef __gen_nsIDOMHistory_h__
#define __gen_nsIDOMHistory_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHistory */
#define NS_IDOMHISTORY_IID_STR "55226663-fe68-48ba-addf-08e32eaab569"

#define NS_IDOMHISTORY_IID \
  {0x55226663, 0xfe68, 0x48ba, \
    { 0xad, 0xdf, 0x08, 0xe3, 0x2e, 0xaa, 0xb5, 0x69 }}

class NS_NO_VTABLE nsIDOMHistory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHISTORY_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHistory, NS_IDOMHISTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHISTORY \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHISTORY(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHISTORY(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHistory : public nsIDOMHistory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHISTORY

  nsDOMHistory();

private:
  ~nsDOMHistory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHistory, nsIDOMHistory)

nsDOMHistory::nsDOMHistory()
{
  /* member initializers and constructor code */
}

nsDOMHistory::~nsDOMHistory()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHistory_h__ */

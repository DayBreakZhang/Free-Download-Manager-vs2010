/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/css/nsIDOMCSSValueList.idl
 */

#ifndef __gen_nsIDOMCSSValueList_h__
#define __gen_nsIDOMCSSValueList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDOMCSSValue_h__
#include "nsIDOMCSSValue.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCSSValueList */
#define NS_IDOMCSSVALUELIST_IID_STR "92364ed1-e364-4175-bc52-c2fe9671cbc7"

#define NS_IDOMCSSVALUELIST_IID \
  {0x92364ed1, 0xe364, 0x4175, \
    { 0xbc, 0x52, 0xc2, 0xfe, 0x96, 0x71, 0xcb, 0xc7 }}

class NS_NO_VTABLE nsIDOMCSSValueList : public nsIDOMCSSValue {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSVALUELIST_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSValueList, NS_IDOMCSSVALUELIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSVALUELIST \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSVALUELIST(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSVALUELIST(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSValueList : public nsIDOMCSSValueList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSVALUELIST

  nsDOMCSSValueList();

private:
  ~nsDOMCSSValueList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCSSValueList, nsIDOMCSSValueList)

nsDOMCSSValueList::nsDOMCSSValueList()
{
  /* member initializers and constructor code */
}

nsDOMCSSValueList::~nsDOMCSSValueList()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSValueList_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/core/nsIDOMNodeList.idl
 */

#ifndef __gen_nsIDOMNodeList_h__
#define __gen_nsIDOMNodeList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNodeList */
#define NS_IDOMNODELIST_IID_STR "450cf0ba-de90-4f86-85bf-e10cc8b8713f"

#define NS_IDOMNODELIST_IID \
  {0x450cf0ba, 0xde90, 0x4f86, \
    { 0x85, 0xbf, 0xe1, 0x0c, 0xc8, 0xb8, 0x71, 0x3f }}

class NS_NO_VTABLE nsIDOMNodeList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNODELIST_IID)

  /* nsIDOMNode item (in unsigned long index); */
  NS_IMETHOD Item(uint32_t index, nsIDOMNode * *_retval) = 0;

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNodeList, NS_IDOMNODELIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNODELIST \
  NS_IMETHOD Item(uint32_t index, nsIDOMNode * *_retval); \
  NS_IMETHOD GetLength(uint32_t *aLength); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNODELIST(_to) \
  NS_IMETHOD Item(uint32_t index, nsIDOMNode * *_retval) { return _to Item(index, _retval); } \
  NS_IMETHOD GetLength(uint32_t *aLength) { return _to GetLength(aLength); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNODELIST(_to) \
  NS_IMETHOD Item(uint32_t index, nsIDOMNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } \
  NS_IMETHOD GetLength(uint32_t *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNodeList : public nsIDOMNodeList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNODELIST

  nsDOMNodeList();

private:
  ~nsDOMNodeList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNodeList, nsIDOMNodeList)

nsDOMNodeList::nsDOMNodeList()
{
  /* member initializers and constructor code */
}

nsDOMNodeList::~nsDOMNodeList()
{
  /* destructor code */
}

/* nsIDOMNode item (in unsigned long index); */
NS_IMETHODIMP nsDOMNodeList::Item(uint32_t index, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMNodeList::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNodeList_h__ */

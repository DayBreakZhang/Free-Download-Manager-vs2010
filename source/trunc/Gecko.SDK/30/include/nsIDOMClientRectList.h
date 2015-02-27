/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMClientRectList.idl
 */

#ifndef __gen_nsIDOMClientRectList_h__
#define __gen_nsIDOMClientRectList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMClientRectList */
#define NS_IDOMCLIENTRECTLIST_IID_STR "f474c567-cbcb-458f-abad-ae42363da287"

#define NS_IDOMCLIENTRECTLIST_IID \
  {0xf474c567, 0xcbcb, 0x458f, \
    { 0xab, 0xad, 0xae, 0x42, 0x36, 0x3d, 0xa2, 0x87 }}

class NS_NO_VTABLE nsIDOMClientRectList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCLIENTRECTLIST_IID)

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

  /* nsIDOMClientRect item (in unsigned long index); */
  NS_IMETHOD Item(uint32_t index, nsIDOMClientRect * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMClientRectList, NS_IDOMCLIENTRECTLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCLIENTRECTLIST \
  NS_IMETHOD GetLength(uint32_t *aLength); \
  NS_IMETHOD Item(uint32_t index, nsIDOMClientRect * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCLIENTRECTLIST(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) { return _to GetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsIDOMClientRect * *_retval) { return _to Item(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCLIENTRECTLIST(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsIDOMClientRect * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMClientRectList : public nsIDOMClientRectList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCLIENTRECTLIST

  nsDOMClientRectList();

private:
  ~nsDOMClientRectList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMClientRectList, nsIDOMClientRectList)

nsDOMClientRectList::nsDOMClientRectList()
{
  /* member initializers and constructor code */
}

nsDOMClientRectList::~nsDOMClientRectList()
{
  /* destructor code */
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMClientRectList::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMClientRect item (in unsigned long index); */
NS_IMETHODIMP nsDOMClientRectList::Item(uint32_t index, nsIDOMClientRect * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMClientRectList_h__ */

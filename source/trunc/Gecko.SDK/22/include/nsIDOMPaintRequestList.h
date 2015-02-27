/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMPaintRequestList.idl
 */

#ifndef __gen_nsIDOMPaintRequestList_h__
#define __gen_nsIDOMPaintRequestList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMPaintRequest; /* forward declaration */


/* starting interface:    nsIDOMPaintRequestList */
#define NS_IDOMPAINTREQUESTLIST_IID_STR "1d6a6e10-e9f0-468b-b8e5-da39c945690e"

#define NS_IDOMPAINTREQUESTLIST_IID \
  {0x1d6a6e10, 0xe9f0, 0x468b, \
    { 0xb8, 0xe5, 0xda, 0x39, 0xc9, 0x45, 0x69, 0x0e }}

class NS_NO_VTABLE nsIDOMPaintRequestList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMPAINTREQUESTLIST_IID)

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

  /* nsIDOMPaintRequest item (in unsigned long index); */
  NS_IMETHOD Item(uint32_t index, nsIDOMPaintRequest * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMPaintRequestList, NS_IDOMPAINTREQUESTLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMPAINTREQUESTLIST \
  NS_IMETHOD GetLength(uint32_t *aLength); \
  NS_IMETHOD Item(uint32_t index, nsIDOMPaintRequest * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMPAINTREQUESTLIST(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) { return _to GetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsIDOMPaintRequest * *_retval) { return _to Item(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMPAINTREQUESTLIST(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsIDOMPaintRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMPaintRequestList : public nsIDOMPaintRequestList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMPAINTREQUESTLIST

  nsDOMPaintRequestList();

private:
  ~nsDOMPaintRequestList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMPaintRequestList, nsIDOMPaintRequestList)

nsDOMPaintRequestList::nsDOMPaintRequestList()
{
  /* member initializers and constructor code */
}

nsDOMPaintRequestList::~nsDOMPaintRequestList()
{
  /* destructor code */
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMPaintRequestList::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMPaintRequest item (in unsigned long index); */
NS_IMETHODIMP nsDOMPaintRequestList::Item(uint32_t index, nsIDOMPaintRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMPaintRequestList_h__ */

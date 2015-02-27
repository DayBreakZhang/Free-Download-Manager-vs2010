/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/content/base/public/nsIDOMFileList.idl
 */

#ifndef __gen_nsIDOMFileList_h__
#define __gen_nsIDOMFileList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMFile; /* forward declaration */


/* starting interface:    nsIDOMFileList */
#define NS_IDOMFILELIST_IID_STR "283aa7b2-da81-4c72-aea2-9797b440fe34"

#define NS_IDOMFILELIST_IID \
  {0x283aa7b2, 0xda81, 0x4c72, \
    { 0xae, 0xa2, 0x97, 0x97, 0xb4, 0x40, 0xfe, 0x34 }}

class NS_NO_VTABLE nsIDOMFileList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMFILELIST_IID)

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

  /* nsIDOMFile item (in unsigned long index); */
  NS_IMETHOD Item(uint32_t index, nsIDOMFile * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMFileList, NS_IDOMFILELIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMFILELIST \
  NS_IMETHOD GetLength(uint32_t *aLength); \
  NS_IMETHOD Item(uint32_t index, nsIDOMFile * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMFILELIST(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) { return _to GetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsIDOMFile * *_retval) { return _to Item(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMFILELIST(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsIDOMFile * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMFileList : public nsIDOMFileList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMFILELIST

  nsDOMFileList();

private:
  ~nsDOMFileList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMFileList, nsIDOMFileList)

nsDOMFileList::nsDOMFileList()
{
  /* member initializers and constructor code */
}

nsDOMFileList::~nsDOMFileList()
{
  /* destructor code */
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMFileList::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMFile item (in unsigned long index); */
NS_IMETHODIMP nsDOMFileList::Item(uint32_t index, nsIDOMFile * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMFileList_h__ */

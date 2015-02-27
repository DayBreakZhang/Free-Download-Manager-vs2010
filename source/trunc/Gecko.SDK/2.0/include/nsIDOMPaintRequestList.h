/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/events/nsIDOMPaintRequestList.idl
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
#define NS_IDOMPAINTREQUESTLIST_IID_STR "01627136-fdd8-44b4-aac0-7d613608a3d4"

#define NS_IDOMPAINTREQUESTLIST_IID \
  {0x01627136, 0xfdd8, 0x44b4, \
    { 0xaa, 0xc0, 0x7d, 0x61, 0x36, 0x08, 0xa3, 0xd4 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMPaintRequestList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMPAINTREQUESTLIST_IID)

  /* readonly attribute unsigned long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) = 0;

  /* nsIDOMPaintRequest item (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMPaintRequest **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMPaintRequestList, NS_IDOMPAINTREQUESTLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMPAINTREQUESTLIST \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength); \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMPaintRequest **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMPAINTREQUESTLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return _to GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMPaintRequest **_retval NS_OUTPARAM) { return _to Item(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMPAINTREQUESTLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMPaintRequest **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } 

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
NS_IMETHODIMP nsDOMPaintRequestList::GetLength(PRUint32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMPaintRequest item (in unsigned long index); */
NS_IMETHODIMP nsDOMPaintRequestList::Item(PRUint32 index, nsIDOMPaintRequest **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMPaintRequestList_h__ */

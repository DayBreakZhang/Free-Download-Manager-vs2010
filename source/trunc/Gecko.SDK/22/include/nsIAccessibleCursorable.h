/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/accessible/public/nsIAccessibleCursorable.idl
 */

#ifndef __gen_nsIAccessibleCursorable_h__
#define __gen_nsIAccessibleCursorable_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAccessiblePivot; /* forward declaration */


/* starting interface:    nsIAccessibleCursorable */
#define NS_IACCESSIBLECURSORABLE_IID_STR "5452dea5-d235-496f-8757-3ca016ff49ff"

#define NS_IACCESSIBLECURSORABLE_IID \
  {0x5452dea5, 0xd235, 0x496f, \
    { 0x87, 0x57, 0x3c, 0xa0, 0x16, 0xff, 0x49, 0xff }}

class NS_NO_VTABLE nsIAccessibleCursorable : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLECURSORABLE_IID)

  /* readonly attribute nsIAccessiblePivot virtualCursor; */
  NS_IMETHOD GetVirtualCursor(nsIAccessiblePivot * *aVirtualCursor) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleCursorable, NS_IACCESSIBLECURSORABLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLECURSORABLE \
  NS_IMETHOD GetVirtualCursor(nsIAccessiblePivot * *aVirtualCursor); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLECURSORABLE(_to) \
  NS_IMETHOD GetVirtualCursor(nsIAccessiblePivot * *aVirtualCursor) { return _to GetVirtualCursor(aVirtualCursor); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLECURSORABLE(_to) \
  NS_IMETHOD GetVirtualCursor(nsIAccessiblePivot * *aVirtualCursor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVirtualCursor(aVirtualCursor); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleCursorable : public nsIAccessibleCursorable
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLECURSORABLE

  nsAccessibleCursorable();

private:
  ~nsAccessibleCursorable();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleCursorable, nsIAccessibleCursorable)

nsAccessibleCursorable::nsAccessibleCursorable()
{
  /* member initializers and constructor code */
}

nsAccessibleCursorable::~nsAccessibleCursorable()
{
  /* destructor code */
}

/* readonly attribute nsIAccessiblePivot virtualCursor; */
NS_IMETHODIMP nsAccessibleCursorable::GetVirtualCursor(nsIAccessiblePivot * *aVirtualCursor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleCursorable_h__ */

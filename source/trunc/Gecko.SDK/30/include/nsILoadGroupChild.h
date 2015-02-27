/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsILoadGroupChild.idl
 */

#ifndef __gen_nsILoadGroupChild_h__
#define __gen_nsILoadGroupChild_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsILoadGroup; /* forward declaration */


/* starting interface:    nsILoadGroupChild */
#define NS_ILOADGROUPCHILD_IID_STR "02efe8e2-fbbc-4718-a299-b8a09c60bf6b"

#define NS_ILOADGROUPCHILD_IID \
  {0x02efe8e2, 0xfbbc, 0x4718, \
    { 0xa2, 0x99, 0xb8, 0xa0, 0x9c, 0x60, 0xbf, 0x6b }}

class NS_NO_VTABLE nsILoadGroupChild : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOADGROUPCHILD_IID)

  /* attribute nsILoadGroup parentLoadGroup; */
  NS_IMETHOD GetParentLoadGroup(nsILoadGroup * *aParentLoadGroup) = 0;
  NS_IMETHOD SetParentLoadGroup(nsILoadGroup *aParentLoadGroup) = 0;

  /* readonly attribute nsILoadGroup childLoadGroup; */
  NS_IMETHOD GetChildLoadGroup(nsILoadGroup * *aChildLoadGroup) = 0;

  /* readonly attribute nsILoadGroup rootLoadGroup; */
  NS_IMETHOD GetRootLoadGroup(nsILoadGroup * *aRootLoadGroup) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILoadGroupChild, NS_ILOADGROUPCHILD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOADGROUPCHILD \
  NS_IMETHOD GetParentLoadGroup(nsILoadGroup * *aParentLoadGroup); \
  NS_IMETHOD SetParentLoadGroup(nsILoadGroup *aParentLoadGroup); \
  NS_IMETHOD GetChildLoadGroup(nsILoadGroup * *aChildLoadGroup); \
  NS_IMETHOD GetRootLoadGroup(nsILoadGroup * *aRootLoadGroup); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOADGROUPCHILD(_to) \
  NS_IMETHOD GetParentLoadGroup(nsILoadGroup * *aParentLoadGroup) { return _to GetParentLoadGroup(aParentLoadGroup); } \
  NS_IMETHOD SetParentLoadGroup(nsILoadGroup *aParentLoadGroup) { return _to SetParentLoadGroup(aParentLoadGroup); } \
  NS_IMETHOD GetChildLoadGroup(nsILoadGroup * *aChildLoadGroup) { return _to GetChildLoadGroup(aChildLoadGroup); } \
  NS_IMETHOD GetRootLoadGroup(nsILoadGroup * *aRootLoadGroup) { return _to GetRootLoadGroup(aRootLoadGroup); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOADGROUPCHILD(_to) \
  NS_IMETHOD GetParentLoadGroup(nsILoadGroup * *aParentLoadGroup) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentLoadGroup(aParentLoadGroup); } \
  NS_IMETHOD SetParentLoadGroup(nsILoadGroup *aParentLoadGroup) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetParentLoadGroup(aParentLoadGroup); } \
  NS_IMETHOD GetChildLoadGroup(nsILoadGroup * *aChildLoadGroup) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildLoadGroup(aChildLoadGroup); } \
  NS_IMETHOD GetRootLoadGroup(nsILoadGroup * *aRootLoadGroup) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootLoadGroup(aRootLoadGroup); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLoadGroupChild : public nsILoadGroupChild
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOADGROUPCHILD

  nsLoadGroupChild();

private:
  ~nsLoadGroupChild();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLoadGroupChild, nsILoadGroupChild)

nsLoadGroupChild::nsLoadGroupChild()
{
  /* member initializers and constructor code */
}

nsLoadGroupChild::~nsLoadGroupChild()
{
  /* destructor code */
}

/* attribute nsILoadGroup parentLoadGroup; */
NS_IMETHODIMP nsLoadGroupChild::GetParentLoadGroup(nsILoadGroup * *aParentLoadGroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoadGroupChild::SetParentLoadGroup(nsILoadGroup *aParentLoadGroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsILoadGroup childLoadGroup; */
NS_IMETHODIMP nsLoadGroupChild::GetChildLoadGroup(nsILoadGroup * *aChildLoadGroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsILoadGroup rootLoadGroup; */
NS_IMETHODIMP nsLoadGroupChild::GetRootLoadGroup(nsILoadGroup * *aRootLoadGroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsILoadGroupChild_h__ */

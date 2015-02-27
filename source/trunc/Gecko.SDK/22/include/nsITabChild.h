/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/base/nsITabChild.idl
 */

#ifndef __gen_nsITabChild_h__
#define __gen_nsITabChild_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIContentFrameMessageManager; /* forward declaration */


/* starting interface:    nsITabChild */
#define NS_ITABCHILD_IID_STR "bf1eddf9-731b-4a4b-bd65-9a712a892832"

#define NS_ITABCHILD_IID \
  {0xbf1eddf9, 0x731b, 0x4a4b, \
    { 0xbd, 0x65, 0x9a, 0x71, 0x2a, 0x89, 0x28, 0x32 }}

class NS_NO_VTABLE nsITabChild : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITABCHILD_IID)

  /* readonly attribute nsIContentFrameMessageManager messageManager; */
  NS_IMETHOD GetMessageManager(nsIContentFrameMessageManager * *aMessageManager) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITabChild, NS_ITABCHILD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITABCHILD \
  NS_IMETHOD GetMessageManager(nsIContentFrameMessageManager * *aMessageManager); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITABCHILD(_to) \
  NS_IMETHOD GetMessageManager(nsIContentFrameMessageManager * *aMessageManager) { return _to GetMessageManager(aMessageManager); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITABCHILD(_to) \
  NS_IMETHOD GetMessageManager(nsIContentFrameMessageManager * *aMessageManager) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessageManager(aMessageManager); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTabChild : public nsITabChild
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITABCHILD

  nsTabChild();

private:
  ~nsTabChild();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTabChild, nsITabChild)

nsTabChild::nsTabChild()
{
  /* member initializers and constructor code */
}

nsTabChild::~nsTabChild()
{
  /* destructor code */
}

/* readonly attribute nsIContentFrameMessageManager messageManager; */
NS_IMETHODIMP nsTabChild::GetMessageManager(nsIContentFrameMessageManager * *aMessageManager)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITabChild_h__ */

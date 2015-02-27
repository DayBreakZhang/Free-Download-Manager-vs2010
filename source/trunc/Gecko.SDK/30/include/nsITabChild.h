/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITabChild.idl
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
#define NS_ITABCHILD_IID_STR "60146bc6-31d8-450b-a9eb-4000b6403d5c"

#define NS_ITABCHILD_IID \
  {0x60146bc6, 0x31d8, 0x450b, \
    { 0xa9, 0xeb, 0x40, 0x00, 0xb6, 0x40, 0x3d, 0x5c }}

class NS_NO_VTABLE nsITabChild : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITABCHILD_IID)

  /* readonly attribute nsIContentFrameMessageManager messageManager; */
  NS_IMETHOD GetMessageManager(nsIContentFrameMessageManager * *aMessageManager) = 0;

  /* [notxpcom] void sendRequestFocus (in boolean canFocus); */
  NS_IMETHOD_(void) SendRequestFocus(bool canFocus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITabChild, NS_ITABCHILD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITABCHILD \
  NS_IMETHOD GetMessageManager(nsIContentFrameMessageManager * *aMessageManager); \
  NS_IMETHOD_(void) SendRequestFocus(bool canFocus); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITABCHILD(_to) \
  NS_IMETHOD GetMessageManager(nsIContentFrameMessageManager * *aMessageManager) { return _to GetMessageManager(aMessageManager); } \
  NS_IMETHOD_(void) SendRequestFocus(bool canFocus) { return _to SendRequestFocus(canFocus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITABCHILD(_to) \
  NS_IMETHOD GetMessageManager(nsIContentFrameMessageManager * *aMessageManager) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessageManager(aMessageManager); } \
  NS_IMETHOD_(void) SendRequestFocus(bool canFocus); 

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

/* [notxpcom] void sendRequestFocus (in boolean canFocus); */
NS_IMETHODIMP_(void) nsTabChild::SendRequestFocus(bool canFocus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITabChild_h__ */

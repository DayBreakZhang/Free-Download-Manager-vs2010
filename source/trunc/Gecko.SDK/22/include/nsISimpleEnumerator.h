/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/ds/nsISimpleEnumerator.idl
 */

#ifndef __gen_nsISimpleEnumerator_h__
#define __gen_nsISimpleEnumerator_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISimpleEnumerator */
#define NS_ISIMPLEENUMERATOR_IID_STR "d1899240-f9d2-11d2-bdd6-000064657374"

#define NS_ISIMPLEENUMERATOR_IID \
  {0xd1899240, 0xf9d2, 0x11d2, \
    { 0xbd, 0xd6, 0x00, 0x00, 0x64, 0x65, 0x73, 0x74 }}

class NS_NO_VTABLE nsISimpleEnumerator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISIMPLEENUMERATOR_IID)

  /* boolean hasMoreElements (); */
  NS_IMETHOD HasMoreElements(bool *_retval) = 0;

  /* nsISupports getNext (); */
  NS_IMETHOD GetNext(nsISupports * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISimpleEnumerator, NS_ISIMPLEENUMERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISIMPLEENUMERATOR \
  NS_IMETHOD HasMoreElements(bool *_retval); \
  NS_IMETHOD GetNext(nsISupports * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISIMPLEENUMERATOR(_to) \
  NS_IMETHOD HasMoreElements(bool *_retval) { return _to HasMoreElements(_retval); } \
  NS_IMETHOD GetNext(nsISupports * *_retval) { return _to GetNext(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISIMPLEENUMERATOR(_to) \
  NS_IMETHOD HasMoreElements(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasMoreElements(_retval); } \
  NS_IMETHOD GetNext(nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNext(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSimpleEnumerator : public nsISimpleEnumerator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISIMPLEENUMERATOR

  nsSimpleEnumerator();

private:
  ~nsSimpleEnumerator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSimpleEnumerator, nsISimpleEnumerator)

nsSimpleEnumerator::nsSimpleEnumerator()
{
  /* member initializers and constructor code */
}

nsSimpleEnumerator::~nsSimpleEnumerator()
{
  /* destructor code */
}

/* boolean hasMoreElements (); */
NS_IMETHODIMP nsSimpleEnumerator::HasMoreElements(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getNext (); */
NS_IMETHODIMP nsSimpleEnumerator::GetNext(nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISimpleEnumerator_h__ */

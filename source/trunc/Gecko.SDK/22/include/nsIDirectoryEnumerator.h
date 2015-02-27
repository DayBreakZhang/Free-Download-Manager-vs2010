/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/io/nsIDirectoryEnumerator.idl
 */

#ifndef __gen_nsIDirectoryEnumerator_h__
#define __gen_nsIDirectoryEnumerator_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */


/* starting interface:    nsIDirectoryEnumerator */
#define NS_IDIRECTORYENUMERATOR_IID_STR "31f7f4ae-6916-4f2d-a81e-926a4e3022ee"

#define NS_IDIRECTORYENUMERATOR_IID \
  {0x31f7f4ae, 0x6916, 0x4f2d, \
    { 0xa8, 0x1e, 0x92, 0x6a, 0x4e, 0x30, 0x22, 0xee }}

class NS_NO_VTABLE nsIDirectoryEnumerator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDIRECTORYENUMERATOR_IID)

  /* readonly attribute nsIFile nextFile; */
  NS_IMETHOD GetNextFile(nsIFile * *aNextFile) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDirectoryEnumerator, NS_IDIRECTORYENUMERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDIRECTORYENUMERATOR \
  NS_IMETHOD GetNextFile(nsIFile * *aNextFile); \
  NS_IMETHOD Close(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDIRECTORYENUMERATOR(_to) \
  NS_IMETHOD GetNextFile(nsIFile * *aNextFile) { return _to GetNextFile(aNextFile); } \
  NS_IMETHOD Close(void) { return _to Close(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDIRECTORYENUMERATOR(_to) \
  NS_IMETHOD GetNextFile(nsIFile * *aNextFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNextFile(aNextFile); } \
  NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDirectoryEnumerator : public nsIDirectoryEnumerator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDIRECTORYENUMERATOR

  nsDirectoryEnumerator();

private:
  ~nsDirectoryEnumerator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDirectoryEnumerator, nsIDirectoryEnumerator)

nsDirectoryEnumerator::nsDirectoryEnumerator()
{
  /* member initializers and constructor code */
}

nsDirectoryEnumerator::~nsDirectoryEnumerator()
{
  /* destructor code */
}

/* readonly attribute nsIFile nextFile; */
NS_IMETHODIMP nsDirectoryEnumerator::GetNextFile(nsIFile * *aNextFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsDirectoryEnumerator::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDirectoryEnumerator_h__ */

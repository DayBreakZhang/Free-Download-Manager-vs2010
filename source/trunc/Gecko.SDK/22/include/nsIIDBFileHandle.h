/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/indexedDB/nsIIDBFileHandle.idl
 */

#ifndef __gen_nsIIDBFileHandle_h__
#define __gen_nsIIDBFileHandle_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIIDBDatabase; /* forward declaration */


/* starting interface:    nsIIDBFileHandle */
#define NS_IIDBFILEHANDLE_IID_STR "7b05f6bb-26b0-4c12-a9a1-e31dd933deb8"

#define NS_IIDBFILEHANDLE_IID \
  {0x7b05f6bb, 0x26b0, 0x4c12, \
    { 0xa9, 0xa1, 0xe3, 0x1d, 0xd9, 0x33, 0xde, 0xb8 }}

class NS_NO_VTABLE nsIIDBFileHandle : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBFILEHANDLE_IID)

  /* readonly attribute nsIIDBDatabase database; */
  NS_IMETHOD GetDatabase(nsIIDBDatabase * *aDatabase) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBFileHandle, NS_IIDBFILEHANDLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBFILEHANDLE \
  NS_IMETHOD GetDatabase(nsIIDBDatabase * *aDatabase); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBFILEHANDLE(_to) \
  NS_IMETHOD GetDatabase(nsIIDBDatabase * *aDatabase) { return _to GetDatabase(aDatabase); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBFILEHANDLE(_to) \
  NS_IMETHOD GetDatabase(nsIIDBDatabase * *aDatabase) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDatabase(aDatabase); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIDBFileHandle : public nsIIDBFileHandle
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDBFILEHANDLE

  nsIDBFileHandle();

private:
  ~nsIDBFileHandle();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIDBFileHandle, nsIIDBFileHandle)

nsIDBFileHandle::nsIDBFileHandle()
{
  /* member initializers and constructor code */
}

nsIDBFileHandle::~nsIDBFileHandle()
{
  /* destructor code */
}

/* readonly attribute nsIIDBDatabase database; */
NS_IMETHODIMP nsIDBFileHandle::GetDatabase(nsIIDBDatabase * *aDatabase)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBFileHandle_h__ */

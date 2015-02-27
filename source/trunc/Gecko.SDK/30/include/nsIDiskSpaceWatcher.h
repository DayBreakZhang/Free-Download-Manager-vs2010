/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDiskSpaceWatcher.idl
 */

#ifndef __gen_nsIDiskSpaceWatcher_h__
#define __gen_nsIDiskSpaceWatcher_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#ifdef XP_WIN
#undef GetFreeSpace
#endif

/* starting interface:    nsIDiskSpaceWatcher */
#define NS_IDISKSPACEWATCHER_IID_STR "3aceba74-2ed5-4e99-8fe4-06e90e2b8ef0"

#define NS_IDISKSPACEWATCHER_IID \
  {0x3aceba74, 0x2ed5, 0x4e99, \
    { 0x8f, 0xe4, 0x06, 0xe9, 0x0e, 0x2b, 0x8e, 0xf0 }}

class NS_NO_VTABLE nsIDiskSpaceWatcher : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDISKSPACEWATCHER_IID)

  /* readonly attribute bool isDiskFull; */
  NS_IMETHOD GetIsDiskFull(bool *aIsDiskFull) = 0;

  /* readonly attribute unsigned long long freeSpace; */
  NS_IMETHOD GetFreeSpace(uint64_t *aFreeSpace) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDiskSpaceWatcher, NS_IDISKSPACEWATCHER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDISKSPACEWATCHER \
  NS_IMETHOD GetIsDiskFull(bool *aIsDiskFull); \
  NS_IMETHOD GetFreeSpace(uint64_t *aFreeSpace); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDISKSPACEWATCHER(_to) \
  NS_IMETHOD GetIsDiskFull(bool *aIsDiskFull) { return _to GetIsDiskFull(aIsDiskFull); } \
  NS_IMETHOD GetFreeSpace(uint64_t *aFreeSpace) { return _to GetFreeSpace(aFreeSpace); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDISKSPACEWATCHER(_to) \
  NS_IMETHOD GetIsDiskFull(bool *aIsDiskFull) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsDiskFull(aIsDiskFull); } \
  NS_IMETHOD GetFreeSpace(uint64_t *aFreeSpace) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFreeSpace(aFreeSpace); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDiskSpaceWatcher : public nsIDiskSpaceWatcher
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDISKSPACEWATCHER

  nsDiskSpaceWatcher();

private:
  ~nsDiskSpaceWatcher();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDiskSpaceWatcher, nsIDiskSpaceWatcher)

nsDiskSpaceWatcher::nsDiskSpaceWatcher()
{
  /* member initializers and constructor code */
}

nsDiskSpaceWatcher::~nsDiskSpaceWatcher()
{
  /* destructor code */
}

/* readonly attribute bool isDiskFull; */
NS_IMETHODIMP nsDiskSpaceWatcher::GetIsDiskFull(bool *aIsDiskFull)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long freeSpace; */
NS_IMETHODIMP nsDiskSpaceWatcher::GetFreeSpace(uint64_t *aFreeSpace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define DISKSPACEWATCHER_CONTRACTID "@mozilla.org/toolkit/disk-space-watcher;1"
// The data for this notification will be either 'free' or 'full'.
#define DISKSPACEWATCHER_OBSERVER_TOPIC "disk-space-watcher"

#endif /* __gen_nsIDiskSpaceWatcher_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsPIDNSService.idl
 */

#ifndef __gen_nsPIDNSService_h__
#define __gen_nsPIDNSService_h__


#ifndef __gen_nsIDNSService_h__
#include "nsIDNSService.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsPIDNSService */
#define NS_PIDNSSERVICE_IID_STR "6b16fb1f-5709-4c94-a89f-a22be873c54d"

#define NS_PIDNSSERVICE_IID \
  {0x6b16fb1f, 0x5709, 0x4c94, \
    { 0xa8, 0x9f, 0xa2, 0x2b, 0xe8, 0x73, 0xc5, 0x4d }}

class NS_NO_VTABLE nsPIDNSService : public nsIDNSService {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PIDNSSERVICE_IID)

  /* void init (); */
  NS_IMETHOD Init(void) = 0;

  /* void shutdown (); */
  NS_IMETHOD Shutdown(void) = 0;

  /* attribute boolean prefetchEnabled; */
  NS_IMETHOD GetPrefetchEnabled(bool *aPrefetchEnabled) = 0;
  NS_IMETHOD SetPrefetchEnabled(bool aPrefetchEnabled) = 0;

  /* attribute boolean offline; */
  NS_IMETHOD GetOffline(bool *aOffline) = 0;
  NS_IMETHOD SetOffline(bool aOffline) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPIDNSService, NS_PIDNSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPIDNSSERVICE \
  NS_IMETHOD Init(void); \
  NS_IMETHOD Shutdown(void); \
  NS_IMETHOD GetPrefetchEnabled(bool *aPrefetchEnabled); \
  NS_IMETHOD SetPrefetchEnabled(bool aPrefetchEnabled); \
  NS_IMETHOD GetOffline(bool *aOffline); \
  NS_IMETHOD SetOffline(bool aOffline); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPIDNSSERVICE(_to) \
  NS_IMETHOD Init(void) { return _to Init(); } \
  NS_IMETHOD Shutdown(void) { return _to Shutdown(); } \
  NS_IMETHOD GetPrefetchEnabled(bool *aPrefetchEnabled) { return _to GetPrefetchEnabled(aPrefetchEnabled); } \
  NS_IMETHOD SetPrefetchEnabled(bool aPrefetchEnabled) { return _to SetPrefetchEnabled(aPrefetchEnabled); } \
  NS_IMETHOD GetOffline(bool *aOffline) { return _to GetOffline(aOffline); } \
  NS_IMETHOD SetOffline(bool aOffline) { return _to SetOffline(aOffline); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPIDNSSERVICE(_to) \
  NS_IMETHOD Init(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(); } \
  NS_IMETHOD Shutdown(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Shutdown(); } \
  NS_IMETHOD GetPrefetchEnabled(bool *aPrefetchEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrefetchEnabled(aPrefetchEnabled); } \
  NS_IMETHOD SetPrefetchEnabled(bool aPrefetchEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrefetchEnabled(aPrefetchEnabled); } \
  NS_IMETHOD GetOffline(bool *aOffline) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffline(aOffline); } \
  NS_IMETHOD SetOffline(bool aOffline) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOffline(aOffline); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPIDNSService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPIDNSSERVICE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, nsPIDNSService)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void init (); */
NS_IMETHODIMP _MYCLASS_::Init()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void shutdown (); */
NS_IMETHODIMP _MYCLASS_::Shutdown()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean prefetchEnabled; */
NS_IMETHODIMP _MYCLASS_::GetPrefetchEnabled(bool *aPrefetchEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetPrefetchEnabled(bool aPrefetchEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean offline; */
NS_IMETHODIMP _MYCLASS_::GetOffline(bool *aOffline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetOffline(bool aOffline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsPIDNSService_h__ */

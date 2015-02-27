/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIIdleObserver.idl
 */

#ifndef __gen_nsIIdleObserver_h__
#define __gen_nsIIdleObserver_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIIdleObserver */
#define NS_IIDLEOBSERVER_IID_STR "37916e05-e062-4f72-96d5-660cfb55e9b6"

#define NS_IIDLEOBSERVER_IID \
  {0x37916e05, 0xe062, 0x4f72, \
    { 0x96, 0xd5, 0x66, 0x0c, 0xfb, 0x55, 0xe9, 0xb6 }}

class NS_NO_VTABLE nsIIdleObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDLEOBSERVER_IID)

  /* readonly attribute unsigned long time; */
  NS_IMETHOD GetTime(uint32_t *aTime) = 0;

  /* void onidle (); */
  NS_IMETHOD Onidle(void) = 0;

  /* void onactive (); */
  NS_IMETHOD Onactive(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIdleObserver, NS_IIDLEOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDLEOBSERVER \
  NS_IMETHOD GetTime(uint32_t *aTime); \
  NS_IMETHOD Onidle(void); \
  NS_IMETHOD Onactive(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDLEOBSERVER(_to) \
  NS_IMETHOD GetTime(uint32_t *aTime) { return _to GetTime(aTime); } \
  NS_IMETHOD Onidle(void) { return _to Onidle(); } \
  NS_IMETHOD Onactive(void) { return _to Onactive(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDLEOBSERVER(_to) \
  NS_IMETHOD GetTime(uint32_t *aTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTime(aTime); } \
  NS_IMETHOD Onidle(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Onidle(); } \
  NS_IMETHOD Onactive(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Onactive(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIdleObserver : public nsIIdleObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDLEOBSERVER

  nsIdleObserver();

private:
  ~nsIdleObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIdleObserver, nsIIdleObserver)

nsIdleObserver::nsIdleObserver()
{
  /* member initializers and constructor code */
}

nsIdleObserver::~nsIdleObserver()
{
  /* destructor code */
}

/* readonly attribute unsigned long time; */
NS_IMETHODIMP nsIdleObserver::GetTime(uint32_t *aTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onidle (); */
NS_IMETHODIMP nsIdleObserver::Onidle()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onactive (); */
NS_IMETHODIMP nsIdleObserver::Onactive()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIdleObserver_h__ */

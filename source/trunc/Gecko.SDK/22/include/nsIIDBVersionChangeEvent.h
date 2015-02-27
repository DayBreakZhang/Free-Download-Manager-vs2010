/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/indexedDB/nsIIDBVersionChangeEvent.idl
 */

#ifndef __gen_nsIIDBVersionChangeEvent_h__
#define __gen_nsIIDBVersionChangeEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIIDBVersionChangeEvent */
#define NS_IIDBVERSIONCHANGEEVENT_IID_STR "08a6b8b1-92fa-4f80-98cc-370143b11ff3"

#define NS_IIDBVERSIONCHANGEEVENT_IID \
  {0x08a6b8b1, 0x92fa, 0x4f80, \
    { 0x98, 0xcc, 0x37, 0x01, 0x43, 0xb1, 0x1f, 0xf3 }}

class NS_NO_VTABLE nsIIDBVersionChangeEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBVERSIONCHANGEEVENT_IID)

  /* readonly attribute unsigned long long oldVersion; */
  NS_IMETHOD GetOldVersion(uint64_t *aOldVersion) = 0;

  /* [implicit_jscontext] readonly attribute jsval newVersion; */
  NS_IMETHOD GetNewVersion(JSContext* cx, JS::Value *aNewVersion) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBVersionChangeEvent, NS_IIDBVERSIONCHANGEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBVERSIONCHANGEEVENT \
  NS_IMETHOD GetOldVersion(uint64_t *aOldVersion); \
  NS_IMETHOD GetNewVersion(JSContext* cx, JS::Value *aNewVersion); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBVERSIONCHANGEEVENT(_to) \
  NS_IMETHOD GetOldVersion(uint64_t *aOldVersion) { return _to GetOldVersion(aOldVersion); } \
  NS_IMETHOD GetNewVersion(JSContext* cx, JS::Value *aNewVersion) { return _to GetNewVersion(cx, aNewVersion); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBVERSIONCHANGEEVENT(_to) \
  NS_IMETHOD GetOldVersion(uint64_t *aOldVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOldVersion(aOldVersion); } \
  NS_IMETHOD GetNewVersion(JSContext* cx, JS::Value *aNewVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNewVersion(cx, aNewVersion); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIDBVersionChangeEvent : public nsIIDBVersionChangeEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDBVERSIONCHANGEEVENT

  nsIDBVersionChangeEvent();

private:
  ~nsIDBVersionChangeEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIDBVersionChangeEvent, nsIIDBVersionChangeEvent)

nsIDBVersionChangeEvent::nsIDBVersionChangeEvent()
{
  /* member initializers and constructor code */
}

nsIDBVersionChangeEvent::~nsIDBVersionChangeEvent()
{
  /* destructor code */
}

/* readonly attribute unsigned long long oldVersion; */
NS_IMETHODIMP nsIDBVersionChangeEvent::GetOldVersion(uint64_t *aOldVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval newVersion; */
NS_IMETHODIMP nsIDBVersionChangeEvent::GetNewVersion(JSContext* cx, JS::Value *aNewVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBVersionChangeEvent_h__ */

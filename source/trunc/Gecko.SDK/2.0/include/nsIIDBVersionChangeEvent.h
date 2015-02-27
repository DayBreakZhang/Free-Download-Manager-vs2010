/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/indexedDB/nsIIDBVersionChangeEvent.idl
 */

#ifndef __gen_nsIIDBVersionChangeEvent_h__
#define __gen_nsIIDBVersionChangeEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIIDBVersionChangeEvent */
#define NS_IIDBVERSIONCHANGEEVENT_IID_STR "6a232c30-1bc4-4d5b-9ce0-6e7c08934755"

#define NS_IIDBVERSIONCHANGEEVENT_IID \
  {0x6a232c30, 0x1bc4, 0x4d5b, \
    { 0x9c, 0xe0, 0x6e, 0x7c, 0x08, 0x93, 0x47, 0x55 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIIDBVersionChangeEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBVERSIONCHANGEEVENT_IID)

  /* readonly attribute AString version; */
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBVersionChangeEvent, NS_IIDBVERSIONCHANGEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBVERSIONCHANGEEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBVERSIONCHANGEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) { return _to GetVersion(aVersion); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBVERSIONCHANGEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } 

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

/* readonly attribute AString version; */
NS_IMETHODIMP nsIDBVersionChangeEvent::GetVersion(nsAString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBVersionChangeEvent_h__ */

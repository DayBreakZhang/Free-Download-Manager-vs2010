/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIProfileSaveEvent.idl
 */

#ifndef __gen_nsIProfileSaveEvent_h__
#define __gen_nsIProfileSaveEvent_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIProfileSaveEvent */
#define NS_IPROFILESAVEEVENT_IID_STR "f5ad0830-e178-41f9-b253-db9b4fae4cb3"

#define NS_IPROFILESAVEEVENT_IID \
  {0xf5ad0830, 0xe178, 0x41f9, \
    { 0xb2, 0x53, 0xdb, 0x9b, 0x4f, 0xae, 0x4c, 0xb3 }}

class NS_NO_VTABLE nsIProfileSaveEvent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROFILESAVEEVENT_IID)

  /* void AddSubProfile (in string aMarker); */
  NS_IMETHOD AddSubProfile(const char * aMarker) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProfileSaveEvent, NS_IPROFILESAVEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROFILESAVEEVENT \
  NS_IMETHOD AddSubProfile(const char * aMarker); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROFILESAVEEVENT(_to) \
  NS_IMETHOD AddSubProfile(const char * aMarker) { return _to AddSubProfile(aMarker); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROFILESAVEEVENT(_to) \
  NS_IMETHOD AddSubProfile(const char * aMarker) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddSubProfile(aMarker); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProfileSaveEvent : public nsIProfileSaveEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROFILESAVEEVENT

  nsProfileSaveEvent();

private:
  ~nsProfileSaveEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProfileSaveEvent, nsIProfileSaveEvent)

nsProfileSaveEvent::nsProfileSaveEvent()
{
  /* member initializers and constructor code */
}

nsProfileSaveEvent::~nsProfileSaveEvent()
{
  /* destructor code */
}

/* void AddSubProfile (in string aMarker); */
NS_IMETHODIMP nsProfileSaveEvent::AddSubProfile(const char * aMarker)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIProfileSaveEvent_h__ */

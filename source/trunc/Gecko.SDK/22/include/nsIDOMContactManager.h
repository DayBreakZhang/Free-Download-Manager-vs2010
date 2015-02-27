/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/contacts/nsIDOMContactManager.idl
 */

#ifndef __gen_nsIDOMContactManager_h__
#define __gen_nsIDOMContactManager_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDOMContactProperties_h__
#include "nsIDOMContactProperties.h"
#endif

#ifndef __gen_nsIDOMEventTarget_h__
#include "nsIDOMEventTarget.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsIDOMContactFindSortOptions; /* forward declaration */

class nsIDOMContactFindOptions; /* forward declaration */

class nsIDOMContactProperties; /* forward declaration */

class nsIDOMDOMRequest; /* forward declaration */

class nsIDOMDOMCursor; /* forward declaration */


/* starting interface:    nsIDOMContact */
#define NS_IDOMCONTACT_IID_STR "da0f7040-388b-11e1-b86c-0800200c9a66"

#define NS_IDOMCONTACT_IID \
  {0xda0f7040, 0x388b, 0x11e1, \
    { 0xb8, 0x6c, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIDOMContact : public nsIDOMContactProperties {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCONTACT_IID)

  /* attribute DOMString id; */
  NS_IMETHOD GetId(nsAString & aId) = 0;
  NS_IMETHOD SetId(const nsAString & aId) = 0;

  /* readonly attribute jsval published; */
  NS_IMETHOD GetPublished(JS::Value *aPublished) = 0;

  /* readonly attribute jsval updated; */
  NS_IMETHOD GetUpdated(JS::Value *aUpdated) = 0;

  /* void init (in nsIDOMContactProperties properties); */
  NS_IMETHOD Init(nsIDOMContactProperties *properties) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMContact, NS_IDOMCONTACT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCONTACT \
  NS_IMETHOD GetId(nsAString & aId); \
  NS_IMETHOD SetId(const nsAString & aId); \
  NS_IMETHOD GetPublished(JS::Value *aPublished); \
  NS_IMETHOD GetUpdated(JS::Value *aUpdated); \
  NS_IMETHOD Init(nsIDOMContactProperties *properties); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCONTACT(_to) \
  NS_IMETHOD GetId(nsAString & aId) { return _to GetId(aId); } \
  NS_IMETHOD SetId(const nsAString & aId) { return _to SetId(aId); } \
  NS_IMETHOD GetPublished(JS::Value *aPublished) { return _to GetPublished(aPublished); } \
  NS_IMETHOD GetUpdated(JS::Value *aUpdated) { return _to GetUpdated(aUpdated); } \
  NS_IMETHOD Init(nsIDOMContactProperties *properties) { return _to Init(properties); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCONTACT(_to) \
  NS_IMETHOD GetId(nsAString & aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_IMETHOD SetId(const nsAString & aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetId(aId); } \
  NS_IMETHOD GetPublished(JS::Value *aPublished) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPublished(aPublished); } \
  NS_IMETHOD GetUpdated(JS::Value *aUpdated) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpdated(aUpdated); } \
  NS_IMETHOD Init(nsIDOMContactProperties *properties) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(properties); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMContact : public nsIDOMContact
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCONTACT

  nsDOMContact();

private:
  ~nsDOMContact();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMContact, nsIDOMContact)

nsDOMContact::nsDOMContact()
{
  /* member initializers and constructor code */
}

nsDOMContact::~nsDOMContact()
{
  /* destructor code */
}

/* attribute DOMString id; */
NS_IMETHODIMP nsDOMContact::GetId(nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMContact::SetId(const nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsval published; */
NS_IMETHODIMP nsDOMContact::GetPublished(JS::Value *aPublished)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsval updated; */
NS_IMETHODIMP nsDOMContact::GetUpdated(JS::Value *aUpdated)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void init (in nsIDOMContactProperties properties); */
NS_IMETHODIMP nsDOMContact::Init(nsIDOMContactProperties *properties)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMContactManager */
#define NS_IDOMCONTACTMANAGER_IID_STR "1d70322b-f11b-4f19-9586-7bf291f212aa"

#define NS_IDOMCONTACTMANAGER_IID \
  {0x1d70322b, 0xf11b, 0x4f19, \
    { 0x95, 0x86, 0x7b, 0xf2, 0x91, 0xf2, 0x12, 0xaa }}

class NS_NO_VTABLE nsIDOMContactManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCONTACTMANAGER_IID)

  /* nsIDOMDOMRequest find (in nsIDOMContactFindOptions options); */
  NS_IMETHOD Find(nsIDOMContactFindOptions *options, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMCursor getAll (in nsIDOMContactFindSortOptions options); */
  NS_IMETHOD GetAll(nsIDOMContactFindSortOptions *options, nsIDOMDOMCursor * *_retval) = 0;

  /* nsIDOMDOMRequest clear (); */
  NS_IMETHOD Clear(nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest save (in nsIDOMContact contact); */
  NS_IMETHOD Save(nsIDOMContact *contact, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest remove (in nsIDOMContact contact); */
  NS_IMETHOD Remove(nsIDOMContact *contact, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest getSimContacts (in DOMString type); */
  NS_IMETHOD GetSimContacts(const nsAString & type, nsIDOMDOMRequest * *_retval) = 0;

  /* attribute nsIDOMEventListener oncontactchange; */
  NS_IMETHOD GetOncontactchange(nsIDOMEventListener * *aOncontactchange) = 0;
  NS_IMETHOD SetOncontactchange(nsIDOMEventListener *aOncontactchange) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMContactManager, NS_IDOMCONTACTMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCONTACTMANAGER \
  NS_IMETHOD Find(nsIDOMContactFindOptions *options, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetAll(nsIDOMContactFindSortOptions *options, nsIDOMDOMCursor * *_retval); \
  NS_IMETHOD Clear(nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD Save(nsIDOMContact *contact, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD Remove(nsIDOMContact *contact, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetSimContacts(const nsAString & type, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetOncontactchange(nsIDOMEventListener * *aOncontactchange); \
  NS_IMETHOD SetOncontactchange(nsIDOMEventListener *aOncontactchange); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCONTACTMANAGER(_to) \
  NS_IMETHOD Find(nsIDOMContactFindOptions *options, nsIDOMDOMRequest * *_retval) { return _to Find(options, _retval); } \
  NS_IMETHOD GetAll(nsIDOMContactFindSortOptions *options, nsIDOMDOMCursor * *_retval) { return _to GetAll(options, _retval); } \
  NS_IMETHOD Clear(nsIDOMDOMRequest * *_retval) { return _to Clear(_retval); } \
  NS_IMETHOD Save(nsIDOMContact *contact, nsIDOMDOMRequest * *_retval) { return _to Save(contact, _retval); } \
  NS_IMETHOD Remove(nsIDOMContact *contact, nsIDOMDOMRequest * *_retval) { return _to Remove(contact, _retval); } \
  NS_IMETHOD GetSimContacts(const nsAString & type, nsIDOMDOMRequest * *_retval) { return _to GetSimContacts(type, _retval); } \
  NS_IMETHOD GetOncontactchange(nsIDOMEventListener * *aOncontactchange) { return _to GetOncontactchange(aOncontactchange); } \
  NS_IMETHOD SetOncontactchange(nsIDOMEventListener *aOncontactchange) { return _to SetOncontactchange(aOncontactchange); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCONTACTMANAGER(_to) \
  NS_IMETHOD Find(nsIDOMContactFindOptions *options, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Find(options, _retval); } \
  NS_IMETHOD GetAll(nsIDOMContactFindSortOptions *options, nsIDOMDOMCursor * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAll(options, _retval); } \
  NS_IMETHOD Clear(nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(_retval); } \
  NS_IMETHOD Save(nsIDOMContact *contact, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Save(contact, _retval); } \
  NS_IMETHOD Remove(nsIDOMContact *contact, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Remove(contact, _retval); } \
  NS_IMETHOD GetSimContacts(const nsAString & type, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSimContacts(type, _retval); } \
  NS_IMETHOD GetOncontactchange(nsIDOMEventListener * *aOncontactchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOncontactchange(aOncontactchange); } \
  NS_IMETHOD SetOncontactchange(nsIDOMEventListener *aOncontactchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOncontactchange(aOncontactchange); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMContactManager : public nsIDOMContactManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCONTACTMANAGER

  nsDOMContactManager();

private:
  ~nsDOMContactManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMContactManager, nsIDOMContactManager)

nsDOMContactManager::nsDOMContactManager()
{
  /* member initializers and constructor code */
}

nsDOMContactManager::~nsDOMContactManager()
{
  /* destructor code */
}

/* nsIDOMDOMRequest find (in nsIDOMContactFindOptions options); */
NS_IMETHODIMP nsDOMContactManager::Find(nsIDOMContactFindOptions *options, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMCursor getAll (in nsIDOMContactFindSortOptions options); */
NS_IMETHODIMP nsDOMContactManager::GetAll(nsIDOMContactFindSortOptions *options, nsIDOMDOMCursor * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest clear (); */
NS_IMETHODIMP nsDOMContactManager::Clear(nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest save (in nsIDOMContact contact); */
NS_IMETHODIMP nsDOMContactManager::Save(nsIDOMContact *contact, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest remove (in nsIDOMContact contact); */
NS_IMETHODIMP nsDOMContactManager::Remove(nsIDOMContact *contact, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest getSimContacts (in DOMString type); */
NS_IMETHODIMP nsDOMContactManager::GetSimContacts(const nsAString & type, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener oncontactchange; */
NS_IMETHODIMP nsDOMContactManager::GetOncontactchange(nsIDOMEventListener * *aOncontactchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMContactManager::SetOncontactchange(nsIDOMEventListener *aOncontactchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMContactManager_h__ */

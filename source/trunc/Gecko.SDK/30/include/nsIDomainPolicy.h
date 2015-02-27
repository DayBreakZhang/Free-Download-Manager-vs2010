/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDomainPolicy.idl
 */

#ifndef __gen_nsIDomainPolicy_h__
#define __gen_nsIDomainPolicy_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIDomainSet; /* forward declaration */


/* starting interface:    nsIDomainPolicy */
#define NS_IDOMAINPOLICY_IID_STR "27b10f54-f34b-42b7-8594-4348d3ad7953"

#define NS_IDOMAINPOLICY_IID \
  {0x27b10f54, 0xf34b, 0x42b7, \
    { 0x85, 0x94, 0x43, 0x48, 0xd3, 0xad, 0x79, 0x53 }}

class NS_NO_VTABLE nsIDomainPolicy : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMAINPOLICY_IID)

  /* readonly attribute nsIDomainSet blacklist; */
  NS_IMETHOD GetBlacklist(nsIDomainSet * *aBlacklist) = 0;

  /* readonly attribute nsIDomainSet superBlacklist; */
  NS_IMETHOD GetSuperBlacklist(nsIDomainSet * *aSuperBlacklist) = 0;

  /* readonly attribute nsIDomainSet whitelist; */
  NS_IMETHOD GetWhitelist(nsIDomainSet * *aWhitelist) = 0;

  /* readonly attribute nsIDomainSet superWhitelist; */
  NS_IMETHOD GetSuperWhitelist(nsIDomainSet * *aSuperWhitelist) = 0;

  /* void deactivate (); */
  NS_IMETHOD Deactivate(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDomainPolicy, NS_IDOMAINPOLICY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMAINPOLICY \
  NS_IMETHOD GetBlacklist(nsIDomainSet * *aBlacklist); \
  NS_IMETHOD GetSuperBlacklist(nsIDomainSet * *aSuperBlacklist); \
  NS_IMETHOD GetWhitelist(nsIDomainSet * *aWhitelist); \
  NS_IMETHOD GetSuperWhitelist(nsIDomainSet * *aSuperWhitelist); \
  NS_IMETHOD Deactivate(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMAINPOLICY(_to) \
  NS_IMETHOD GetBlacklist(nsIDomainSet * *aBlacklist) { return _to GetBlacklist(aBlacklist); } \
  NS_IMETHOD GetSuperBlacklist(nsIDomainSet * *aSuperBlacklist) { return _to GetSuperBlacklist(aSuperBlacklist); } \
  NS_IMETHOD GetWhitelist(nsIDomainSet * *aWhitelist) { return _to GetWhitelist(aWhitelist); } \
  NS_IMETHOD GetSuperWhitelist(nsIDomainSet * *aSuperWhitelist) { return _to GetSuperWhitelist(aSuperWhitelist); } \
  NS_IMETHOD Deactivate(void) { return _to Deactivate(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMAINPOLICY(_to) \
  NS_IMETHOD GetBlacklist(nsIDomainSet * *aBlacklist) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBlacklist(aBlacklist); } \
  NS_IMETHOD GetSuperBlacklist(nsIDomainSet * *aSuperBlacklist) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSuperBlacklist(aSuperBlacklist); } \
  NS_IMETHOD GetWhitelist(nsIDomainSet * *aWhitelist) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWhitelist(aWhitelist); } \
  NS_IMETHOD GetSuperWhitelist(nsIDomainSet * *aSuperWhitelist) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSuperWhitelist(aSuperWhitelist); } \
  NS_IMETHOD Deactivate(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Deactivate(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDomainPolicy : public nsIDomainPolicy
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMAINPOLICY

  nsDomainPolicy();

private:
  ~nsDomainPolicy();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDomainPolicy, nsIDomainPolicy)

nsDomainPolicy::nsDomainPolicy()
{
  /* member initializers and constructor code */
}

nsDomainPolicy::~nsDomainPolicy()
{
  /* destructor code */
}

/* readonly attribute nsIDomainSet blacklist; */
NS_IMETHODIMP nsDomainPolicy::GetBlacklist(nsIDomainSet * *aBlacklist)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDomainSet superBlacklist; */
NS_IMETHODIMP nsDomainPolicy::GetSuperBlacklist(nsIDomainSet * *aSuperBlacklist)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDomainSet whitelist; */
NS_IMETHODIMP nsDomainPolicy::GetWhitelist(nsIDomainSet * *aWhitelist)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDomainSet superWhitelist; */
NS_IMETHODIMP nsDomainPolicy::GetSuperWhitelist(nsIDomainSet * *aSuperWhitelist)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deactivate (); */
NS_IMETHODIMP nsDomainPolicy::Deactivate()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDomainSet */
#define NS_IDOMAINSET_IID_STR "946a01ff-6525-4007-a2c2-447ebe1875d3"

#define NS_IDOMAINSET_IID \
  {0x946a01ff, 0x6525, 0x4007, \
    { 0xa2, 0xc2, 0x44, 0x7e, 0xbe, 0x18, 0x75, 0xd3 }}

class NS_NO_VTABLE nsIDomainSet : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMAINSET_IID)

  /* void add (in nsIURI aDomain); */
  NS_IMETHOD Add(nsIURI *aDomain) = 0;

  /* void remove (in nsIURI aDomain); */
  NS_IMETHOD Remove(nsIURI *aDomain) = 0;

  /* void clear (); */
  NS_IMETHOD Clear(void) = 0;

  /* bool contains (in nsIURI aDomain); */
  NS_IMETHOD Contains(nsIURI *aDomain, bool *_retval) = 0;

  /* bool containsSuperDomain (in nsIURI aDomain); */
  NS_IMETHOD ContainsSuperDomain(nsIURI *aDomain, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDomainSet, NS_IDOMAINSET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMAINSET \
  NS_IMETHOD Add(nsIURI *aDomain); \
  NS_IMETHOD Remove(nsIURI *aDomain); \
  NS_IMETHOD Clear(void); \
  NS_IMETHOD Contains(nsIURI *aDomain, bool *_retval); \
  NS_IMETHOD ContainsSuperDomain(nsIURI *aDomain, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMAINSET(_to) \
  NS_IMETHOD Add(nsIURI *aDomain) { return _to Add(aDomain); } \
  NS_IMETHOD Remove(nsIURI *aDomain) { return _to Remove(aDomain); } \
  NS_IMETHOD Clear(void) { return _to Clear(); } \
  NS_IMETHOD Contains(nsIURI *aDomain, bool *_retval) { return _to Contains(aDomain, _retval); } \
  NS_IMETHOD ContainsSuperDomain(nsIURI *aDomain, bool *_retval) { return _to ContainsSuperDomain(aDomain, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMAINSET(_to) \
  NS_IMETHOD Add(nsIURI *aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(aDomain); } \
  NS_IMETHOD Remove(nsIURI *aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->Remove(aDomain); } \
  NS_IMETHOD Clear(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(); } \
  NS_IMETHOD Contains(nsIURI *aDomain, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Contains(aDomain, _retval); } \
  NS_IMETHOD ContainsSuperDomain(nsIURI *aDomain, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ContainsSuperDomain(aDomain, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDomainSet : public nsIDomainSet
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMAINSET

  nsDomainSet();

private:
  ~nsDomainSet();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDomainSet, nsIDomainSet)

nsDomainSet::nsDomainSet()
{
  /* member initializers and constructor code */
}

nsDomainSet::~nsDomainSet()
{
  /* destructor code */
}

/* void add (in nsIURI aDomain); */
NS_IMETHODIMP nsDomainSet::Add(nsIURI *aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void remove (in nsIURI aDomain); */
NS_IMETHODIMP nsDomainSet::Remove(nsIURI *aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clear (); */
NS_IMETHODIMP nsDomainSet::Clear()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool contains (in nsIURI aDomain); */
NS_IMETHODIMP nsDomainSet::Contains(nsIURI *aDomain, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool containsSuperDomain (in nsIURI aDomain); */
NS_IMETHODIMP nsDomainSet::ContainsSuperDomain(nsIURI *aDomain, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDomainPolicy_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/accessible/public/nsIAccessibleRetrieval.idl
 */

#ifndef __gen_nsIAccessibleRetrieval_h__
#define __gen_nsIAccessibleRetrieval_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNode; /* forward declaration */

class nsIAccessible; /* forward declaration */

class nsIWeakReference; /* forward declaration */

class nsIPresShell; /* forward declaration */

class nsIDOMWindow; /* forward declaration */

class nsIDOMDOMStringList; /* forward declaration */

class nsIAccessiblePivot; /* forward declaration */


/* starting interface:    nsIAccessibleRetrieval */
#define NS_IACCESSIBLERETRIEVAL_IID_STR "17f86615-1a3d-4021-b227-3a2ef5cbffd8"

#define NS_IACCESSIBLERETRIEVAL_IID \
  {0x17f86615, 0x1a3d, 0x4021, \
    { 0xb2, 0x27, 0x3a, 0x2e, 0xf5, 0xcb, 0xff, 0xd8 }}

class NS_NO_VTABLE nsIAccessibleRetrieval : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLERETRIEVAL_IID)

  /* nsIAccessible getApplicationAccessible (); */
  NS_IMETHOD GetApplicationAccessible(nsIAccessible * *_retval) = 0;

  /* nsIAccessible getAccessibleFor (in nsIDOMNode aNode); */
  NS_IMETHOD GetAccessibleFor(nsIDOMNode *aNode, nsIAccessible * *_retval) = 0;

  /* AString getStringRole (in unsigned long aRole); */
  NS_IMETHOD GetStringRole(uint32_t aRole, nsAString & _retval) = 0;

  /* nsIDOMDOMStringList getStringStates (in unsigned long aStates, in unsigned long aExtraStates); */
  NS_IMETHOD GetStringStates(uint32_t aStates, uint32_t aExtraStates, nsIDOMDOMStringList * *_retval) = 0;

  /* AString getStringEventType (in unsigned long aEventType); */
  NS_IMETHOD GetStringEventType(uint32_t aEventType, nsAString & _retval) = 0;

  /* AString getStringRelationType (in unsigned long aRelationType); */
  NS_IMETHOD GetStringRelationType(uint32_t aRelationType, nsAString & _retval) = 0;

  /* nsIAccessible getAccessibleFromCache (in nsIDOMNode aNode); */
  NS_IMETHOD GetAccessibleFromCache(nsIDOMNode *aNode, nsIAccessible * *_retval) = 0;

  /* nsIAccessiblePivot createAccessiblePivot (in nsIAccessible aRoot); */
  NS_IMETHOD CreateAccessiblePivot(nsIAccessible *aRoot, nsIAccessiblePivot * *_retval) = 0;

  /* void setLogging (in ACString aModules); */
  NS_IMETHOD SetLogging(const nsACString & aModules) = 0;

  /* boolean isLogged (in AString aModule); */
  NS_IMETHOD IsLogged(const nsAString & aModule, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleRetrieval, NS_IACCESSIBLERETRIEVAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLERETRIEVAL \
  NS_IMETHOD GetApplicationAccessible(nsIAccessible * *_retval); \
  NS_IMETHOD GetAccessibleFor(nsIDOMNode *aNode, nsIAccessible * *_retval); \
  NS_IMETHOD GetStringRole(uint32_t aRole, nsAString & _retval); \
  NS_IMETHOD GetStringStates(uint32_t aStates, uint32_t aExtraStates, nsIDOMDOMStringList * *_retval); \
  NS_IMETHOD GetStringEventType(uint32_t aEventType, nsAString & _retval); \
  NS_IMETHOD GetStringRelationType(uint32_t aRelationType, nsAString & _retval); \
  NS_IMETHOD GetAccessibleFromCache(nsIDOMNode *aNode, nsIAccessible * *_retval); \
  NS_IMETHOD CreateAccessiblePivot(nsIAccessible *aRoot, nsIAccessiblePivot * *_retval); \
  NS_IMETHOD SetLogging(const nsACString & aModules); \
  NS_IMETHOD IsLogged(const nsAString & aModule, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLERETRIEVAL(_to) \
  NS_IMETHOD GetApplicationAccessible(nsIAccessible * *_retval) { return _to GetApplicationAccessible(_retval); } \
  NS_IMETHOD GetAccessibleFor(nsIDOMNode *aNode, nsIAccessible * *_retval) { return _to GetAccessibleFor(aNode, _retval); } \
  NS_IMETHOD GetStringRole(uint32_t aRole, nsAString & _retval) { return _to GetStringRole(aRole, _retval); } \
  NS_IMETHOD GetStringStates(uint32_t aStates, uint32_t aExtraStates, nsIDOMDOMStringList * *_retval) { return _to GetStringStates(aStates, aExtraStates, _retval); } \
  NS_IMETHOD GetStringEventType(uint32_t aEventType, nsAString & _retval) { return _to GetStringEventType(aEventType, _retval); } \
  NS_IMETHOD GetStringRelationType(uint32_t aRelationType, nsAString & _retval) { return _to GetStringRelationType(aRelationType, _retval); } \
  NS_IMETHOD GetAccessibleFromCache(nsIDOMNode *aNode, nsIAccessible * *_retval) { return _to GetAccessibleFromCache(aNode, _retval); } \
  NS_IMETHOD CreateAccessiblePivot(nsIAccessible *aRoot, nsIAccessiblePivot * *_retval) { return _to CreateAccessiblePivot(aRoot, _retval); } \
  NS_IMETHOD SetLogging(const nsACString & aModules) { return _to SetLogging(aModules); } \
  NS_IMETHOD IsLogged(const nsAString & aModule, bool *_retval) { return _to IsLogged(aModule, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLERETRIEVAL(_to) \
  NS_IMETHOD GetApplicationAccessible(nsIAccessible * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApplicationAccessible(_retval); } \
  NS_IMETHOD GetAccessibleFor(nsIDOMNode *aNode, nsIAccessible * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessibleFor(aNode, _retval); } \
  NS_IMETHOD GetStringRole(uint32_t aRole, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringRole(aRole, _retval); } \
  NS_IMETHOD GetStringStates(uint32_t aStates, uint32_t aExtraStates, nsIDOMDOMStringList * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringStates(aStates, aExtraStates, _retval); } \
  NS_IMETHOD GetStringEventType(uint32_t aEventType, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringEventType(aEventType, _retval); } \
  NS_IMETHOD GetStringRelationType(uint32_t aRelationType, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringRelationType(aRelationType, _retval); } \
  NS_IMETHOD GetAccessibleFromCache(nsIDOMNode *aNode, nsIAccessible * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessibleFromCache(aNode, _retval); } \
  NS_IMETHOD CreateAccessiblePivot(nsIAccessible *aRoot, nsIAccessiblePivot * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateAccessiblePivot(aRoot, _retval); } \
  NS_IMETHOD SetLogging(const nsACString & aModules) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLogging(aModules); } \
  NS_IMETHOD IsLogged(const nsAString & aModule, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsLogged(aModule, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleRetrieval : public nsIAccessibleRetrieval
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLERETRIEVAL

  nsAccessibleRetrieval();

private:
  ~nsAccessibleRetrieval();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleRetrieval, nsIAccessibleRetrieval)

nsAccessibleRetrieval::nsAccessibleRetrieval()
{
  /* member initializers and constructor code */
}

nsAccessibleRetrieval::~nsAccessibleRetrieval()
{
  /* destructor code */
}

/* nsIAccessible getApplicationAccessible (); */
NS_IMETHODIMP nsAccessibleRetrieval::GetApplicationAccessible(nsIAccessible * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getAccessibleFor (in nsIDOMNode aNode); */
NS_IMETHODIMP nsAccessibleRetrieval::GetAccessibleFor(nsIDOMNode *aNode, nsIAccessible * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getStringRole (in unsigned long aRole); */
NS_IMETHODIMP nsAccessibleRetrieval::GetStringRole(uint32_t aRole, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMStringList getStringStates (in unsigned long aStates, in unsigned long aExtraStates); */
NS_IMETHODIMP nsAccessibleRetrieval::GetStringStates(uint32_t aStates, uint32_t aExtraStates, nsIDOMDOMStringList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getStringEventType (in unsigned long aEventType); */
NS_IMETHODIMP nsAccessibleRetrieval::GetStringEventType(uint32_t aEventType, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getStringRelationType (in unsigned long aRelationType); */
NS_IMETHODIMP nsAccessibleRetrieval::GetStringRelationType(uint32_t aRelationType, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getAccessibleFromCache (in nsIDOMNode aNode); */
NS_IMETHODIMP nsAccessibleRetrieval::GetAccessibleFromCache(nsIDOMNode *aNode, nsIAccessible * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessiblePivot createAccessiblePivot (in nsIAccessible aRoot); */
NS_IMETHODIMP nsAccessibleRetrieval::CreateAccessiblePivot(nsIAccessible *aRoot, nsIAccessiblePivot * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setLogging (in ACString aModules); */
NS_IMETHODIMP nsAccessibleRetrieval::SetLogging(const nsACString & aModules)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isLogged (in AString aModule); */
NS_IMETHODIMP nsAccessibleRetrieval::IsLogged(const nsAString & aModule, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


// for component registration
// {663CA4A8-D219-4000-925D-D8F66406B626}
#define NS_ACCESSIBLE_RETRIEVAL_CID \
{ 0x663ca4a8, 0xd219, 0x4000, { 0x92, 0x5d, 0xd8, 0xf6, 0x64, 0x6, 0xb6, 0x26 } }

#endif /* __gen_nsIAccessibleRetrieval_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/accessible/public/nsIAccessibleRetrieval.idl
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

class nsIAccessNode; /* forward declaration */

class nsIDOMDOMStringList; /* forward declaration */


/* starting interface:    nsIAccessibleRetrieval */
#define NS_IACCESSIBLERETRIEVAL_IID_STR "310ce77d-c92b-4761-82e8-77e1a728e8d4"

#define NS_IACCESSIBLERETRIEVAL_IID \
  {0x310ce77d, 0xc92b, 0x4761, \
    { 0x82, 0xe8, 0x77, 0xe1, 0xa7, 0x28, 0xe8, 0xd4 }}

/**
 * An interface for in-process accessibility clients
 * wishing to get an nsIAccessible or nsIAccessNode for
 * a given DOM node.
 * More documentation at:
 *   http://www.mozilla.org/projects/ui/accessibility
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessibleRetrieval : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLERETRIEVAL_IID)

  /**
   * Return application accessible.
   */
  /* nsIAccessible getApplicationAccessible (); */
  NS_SCRIPTABLE NS_IMETHOD GetApplicationAccessible(nsIAccessible **_retval NS_OUTPARAM) = 0;

  /**
   * Return an nsIAccessible for a DOM node in pres shell 0.
   * Create a new accessible of the appropriate type if necessary,
   * or use one from the accessibility cache if it already exists.
   * @param aNode The DOM node to get an accessible for.
   * @return The nsIAccessible for the given DOM node.
   */
  /* nsIAccessible getAccessibleFor (in nsIDOMNode aNode); */
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleFor(nsIDOMNode *aNode, nsIAccessible **_retval NS_OUTPARAM) = 0;

  /**
    * Returns accessible role as a string.
    *
    * @param aRole - the accessible role constants.
    */
  /* AString getStringRole (in unsigned long aRole); */
  NS_SCRIPTABLE NS_IMETHOD GetStringRole(PRUint32 aRole, nsAString & _retval NS_OUTPARAM) = 0;

  /**
    * Returns list which contains accessible states as a strings.
    *
    * @param aStates - accessible states.
    * @param aExtraStates - accessible extra states.
    */
  /* nsIDOMDOMStringList getStringStates (in unsigned long aStates, in unsigned long aExtraStates); */
  NS_SCRIPTABLE NS_IMETHOD GetStringStates(PRUint32 aStates, PRUint32 aExtraStates, nsIDOMDOMStringList **_retval NS_OUTPARAM) = 0;

  /**
   * Get the type of accessible event as a string.
   *
   * @param aEventType - the accessible event type constant
   * @return - accessible event type presented as human readable string
   */
  /* AString getStringEventType (in unsigned long aEventType); */
  NS_SCRIPTABLE NS_IMETHOD GetStringEventType(PRUint32 aEventType, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Get the type of accessible relation as a string.
   *
   * @param aRelationType - the accessible relation type constant
   * @return - accessible relation type presented as human readable string
   */
  /* AString getStringRelationType (in unsigned long aRelationType); */
  NS_SCRIPTABLE NS_IMETHOD GetStringRelationType(PRUint32 aRelationType, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Return an accessible for the given DOM node from the cache.
   * @note  the method is intended for testing purposes
   *
   * @param aNode  [in] the DOM node to get an accessible for
   *
   * @return       cached accessible for the given DOM node if any
   */
  /* nsIAccessible getAccessibleFromCache (in nsIDOMNode aNode); */
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleFromCache(nsIDOMNode *aNode, nsIAccessible **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleRetrieval, NS_IACCESSIBLERETRIEVAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLERETRIEVAL \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationAccessible(nsIAccessible **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleFor(nsIDOMNode *aNode, nsIAccessible **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetStringRole(PRUint32 aRole, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetStringStates(PRUint32 aStates, PRUint32 aExtraStates, nsIDOMDOMStringList **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetStringEventType(PRUint32 aEventType, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetStringRelationType(PRUint32 aRelationType, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleFromCache(nsIDOMNode *aNode, nsIAccessible **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLERETRIEVAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationAccessible(nsIAccessible **_retval NS_OUTPARAM) { return _to GetApplicationAccessible(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleFor(nsIDOMNode *aNode, nsIAccessible **_retval NS_OUTPARAM) { return _to GetAccessibleFor(aNode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringRole(PRUint32 aRole, nsAString & _retval NS_OUTPARAM) { return _to GetStringRole(aRole, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringStates(PRUint32 aStates, PRUint32 aExtraStates, nsIDOMDOMStringList **_retval NS_OUTPARAM) { return _to GetStringStates(aStates, aExtraStates, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringEventType(PRUint32 aEventType, nsAString & _retval NS_OUTPARAM) { return _to GetStringEventType(aEventType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringRelationType(PRUint32 aRelationType, nsAString & _retval NS_OUTPARAM) { return _to GetStringRelationType(aRelationType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleFromCache(nsIDOMNode *aNode, nsIAccessible **_retval NS_OUTPARAM) { return _to GetAccessibleFromCache(aNode, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLERETRIEVAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationAccessible(nsIAccessible **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApplicationAccessible(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleFor(nsIDOMNode *aNode, nsIAccessible **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessibleFor(aNode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringRole(PRUint32 aRole, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringRole(aRole, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringStates(PRUint32 aStates, PRUint32 aExtraStates, nsIDOMDOMStringList **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringStates(aStates, aExtraStates, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringEventType(PRUint32 aEventType, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringEventType(aEventType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringRelationType(PRUint32 aRelationType, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringRelationType(aRelationType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleFromCache(nsIDOMNode *aNode, nsIAccessible **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessibleFromCache(aNode, _retval); } 

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
NS_IMETHODIMP nsAccessibleRetrieval::GetApplicationAccessible(nsIAccessible **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getAccessibleFor (in nsIDOMNode aNode); */
NS_IMETHODIMP nsAccessibleRetrieval::GetAccessibleFor(nsIDOMNode *aNode, nsIAccessible **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getStringRole (in unsigned long aRole); */
NS_IMETHODIMP nsAccessibleRetrieval::GetStringRole(PRUint32 aRole, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMStringList getStringStates (in unsigned long aStates, in unsigned long aExtraStates); */
NS_IMETHODIMP nsAccessibleRetrieval::GetStringStates(PRUint32 aStates, PRUint32 aExtraStates, nsIDOMDOMStringList **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getStringEventType (in unsigned long aEventType); */
NS_IMETHODIMP nsAccessibleRetrieval::GetStringEventType(PRUint32 aEventType, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getStringRelationType (in unsigned long aRelationType); */
NS_IMETHODIMP nsAccessibleRetrieval::GetStringRelationType(PRUint32 aRelationType, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getAccessibleFromCache (in nsIDOMNode aNode); */
NS_IMETHODIMP nsAccessibleRetrieval::GetAccessibleFromCache(nsIDOMNode *aNode, nsIAccessible **_retval NS_OUTPARAM)
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

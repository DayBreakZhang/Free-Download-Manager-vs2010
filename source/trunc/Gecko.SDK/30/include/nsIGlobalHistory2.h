/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIGlobalHistory2.idl
 */

#ifndef __gen_nsIGlobalHistory2_h__
#define __gen_nsIGlobalHistory2_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


// nsIObserver topic to fire when you add new visited URIs to the history;
// the nsIURI is the subject
#define NS_LINK_VISITED_EVENT_TOPIC "link-visited"

/* starting interface:    nsIGlobalHistory2 */
#define NS_IGLOBALHISTORY2_IID_STR "cf777d42-1270-4b34-be7b-2931c93feda5"

#define NS_IGLOBALHISTORY2_IID \
  {0xcf777d42, 0x1270, 0x4b34, \
    { 0xbe, 0x7b, 0x29, 0x31, 0xc9, 0x3f, 0xed, 0xa5 }}

class NS_NO_VTABLE nsIGlobalHistory2 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGLOBALHISTORY2_IID)

  /* void addURI (in nsIURI aURI, in boolean aRedirect, in boolean aToplevel, in nsIURI aReferrer); */
  NS_IMETHOD AddURI(nsIURI *aURI, bool aRedirect, bool aToplevel, nsIURI *aReferrer) = 0;

  /* boolean isVisited (in nsIURI aURI); */
  NS_IMETHOD IsVisited(nsIURI *aURI, bool *_retval) = 0;

  /* void setPageTitle (in nsIURI aURI, in AString aTitle); */
  NS_IMETHOD SetPageTitle(nsIURI *aURI, const nsAString & aTitle) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGlobalHistory2, NS_IGLOBALHISTORY2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGLOBALHISTORY2 \
  NS_IMETHOD AddURI(nsIURI *aURI, bool aRedirect, bool aToplevel, nsIURI *aReferrer); \
  NS_IMETHOD IsVisited(nsIURI *aURI, bool *_retval); \
  NS_IMETHOD SetPageTitle(nsIURI *aURI, const nsAString & aTitle); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGLOBALHISTORY2(_to) \
  NS_IMETHOD AddURI(nsIURI *aURI, bool aRedirect, bool aToplevel, nsIURI *aReferrer) { return _to AddURI(aURI, aRedirect, aToplevel, aReferrer); } \
  NS_IMETHOD IsVisited(nsIURI *aURI, bool *_retval) { return _to IsVisited(aURI, _retval); } \
  NS_IMETHOD SetPageTitle(nsIURI *aURI, const nsAString & aTitle) { return _to SetPageTitle(aURI, aTitle); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGLOBALHISTORY2(_to) \
  NS_IMETHOD AddURI(nsIURI *aURI, bool aRedirect, bool aToplevel, nsIURI *aReferrer) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddURI(aURI, aRedirect, aToplevel, aReferrer); } \
  NS_IMETHOD IsVisited(nsIURI *aURI, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsVisited(aURI, _retval); } \
  NS_IMETHOD SetPageTitle(nsIURI *aURI, const nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPageTitle(aURI, aTitle); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGlobalHistory2 : public nsIGlobalHistory2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGLOBALHISTORY2

  nsGlobalHistory2();

private:
  ~nsGlobalHistory2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsGlobalHistory2, nsIGlobalHistory2)

nsGlobalHistory2::nsGlobalHistory2()
{
  /* member initializers and constructor code */
}

nsGlobalHistory2::~nsGlobalHistory2()
{
  /* destructor code */
}

/* void addURI (in nsIURI aURI, in boolean aRedirect, in boolean aToplevel, in nsIURI aReferrer); */
NS_IMETHODIMP nsGlobalHistory2::AddURI(nsIURI *aURI, bool aRedirect, bool aToplevel, nsIURI *aReferrer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isVisited (in nsIURI aURI); */
NS_IMETHODIMP nsGlobalHistory2::IsVisited(nsIURI *aURI, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPageTitle (in nsIURI aURI, in AString aTitle); */
NS_IMETHODIMP nsGlobalHistory2::SetPageTitle(nsIURI *aURI, const nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIGlobalHistory2_h__ */

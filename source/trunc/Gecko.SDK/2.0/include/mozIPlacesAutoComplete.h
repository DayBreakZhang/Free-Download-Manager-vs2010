/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/toolkit/components/places/public/mozIPlacesAutoComplete.idl
 */

#ifndef __gen_mozIPlacesAutoComplete_h__
#define __gen_mozIPlacesAutoComplete_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    mozIPlacesAutoComplete */
#define MOZIPLACESAUTOCOMPLETE_IID_STR "3bf895a0-d6d9-4ba7-b8db-f2f0e0f32d23"

#define MOZIPLACESAUTOCOMPLETE_IID \
  {0x3bf895a0, 0xd6d9, 0x4ba7, \
    { 0xb8, 0xdb, 0xf2, 0xf0, 0xe0, 0xf3, 0x2d, 0x23 }}

/**
 * This interface provides some constants used by the Places AutoComplete
 * search provider as well as methods to track opened pages for AutoComplete
 * purposes.
 */
class NS_NO_VTABLE NS_SCRIPTABLE mozIPlacesAutoComplete : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIPLACESAUTOCOMPLETE_IID)

  /**
   * Match anywhere in each searchable term.
   */
  enum { MATCH_ANYWHERE = 0 };

  /**
   * Match first on word boundaries, and if we do not get enough results, then
   * match anywhere in each searchable term.
   */
  enum { MATCH_BOUNDARY_ANYWHERE = 1 };

  /**
   * Match on word boundaries in each searchable term.
   */
  enum { MATCH_BOUNDARY = 2 };

  /**
   * Match only the beginning of each search term.
   */
  enum { MATCH_BEGINNING = 3 };

  /**
   * Search through history.
   */
  enum { BEHAVIOR_HISTORY = 1 };

  /**
   * Search though bookmarks.
   */
  enum { BEHAVIOR_BOOKMARK = 2 };

  /**
   * Search through tags.
   */
  enum { BEHAVIOR_TAG = 4 };

  /**
   * Search the title of pages.
   */
  enum { BEHAVIOR_TITLE = 8 };

  /**
   * Search the URL of pages.
   */
  enum { BEHAVIOR_URL = 16 };

  /**
   * Search for typed pages.
   */
  enum { BEHAVIOR_TYPED = 32 };

  /**
   * Search javascript: URLs.
   */
  enum { BEHAVIOR_JAVASCRIPT = 64 };

  /**
   * Search for pages that have been marked as being opened, such as a tab
   * in a tabbrowser.
   */
  enum { BEHAVIOR_OPENPAGE = 128 };

  /**
   * Mark a page as being currently open.
   *
   * @note Pages will not be automatically unregistered when Private Browsing
   *       mode is entered or exited.  Therefore, consumers MUST unregister or
   *       register themselves.
   *
   * @param aURI
   *        The URI to register as an open page.
   */
  /* void registerOpenPage (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD RegisterOpenPage(nsIURI *aURI) = 0;

  /**
   * Mark a page as no longer being open (either by closing the window or tab,
   * or by navigating away from that page).
   *
   * @note Pages will not be automatically unregistered when Private Browsing
   *       mode is entered or exited.  Therefore, consumers MUST unregister or
   *       register themselves.
   *
   * @param aURI
   *        The URI to unregister as an open page.
   */
  /* void unregisterOpenPage (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD UnregisterOpenPage(nsIURI *aURI) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIPlacesAutoComplete, MOZIPLACESAUTOCOMPLETE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIPLACESAUTOCOMPLETE \
  NS_SCRIPTABLE NS_IMETHOD RegisterOpenPage(nsIURI *aURI); \
  NS_SCRIPTABLE NS_IMETHOD UnregisterOpenPage(nsIURI *aURI); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIPLACESAUTOCOMPLETE(_to) \
  NS_SCRIPTABLE NS_IMETHOD RegisterOpenPage(nsIURI *aURI) { return _to RegisterOpenPage(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterOpenPage(nsIURI *aURI) { return _to UnregisterOpenPage(aURI); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIPLACESAUTOCOMPLETE(_to) \
  NS_SCRIPTABLE NS_IMETHOD RegisterOpenPage(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterOpenPage(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterOpenPage(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterOpenPage(aURI); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIPlacesAutoComplete
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZIPLACESAUTOCOMPLETE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIPlacesAutoComplete)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void registerOpenPage (in nsIURI aURI); */
NS_IMETHODIMP _MYCLASS_::RegisterOpenPage(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterOpenPage (in nsIURI aURI); */
NS_IMETHODIMP _MYCLASS_::UnregisterOpenPage(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIPlacesAutoComplete_h__ */

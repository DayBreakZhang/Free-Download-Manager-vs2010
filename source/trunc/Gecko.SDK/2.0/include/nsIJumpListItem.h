/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/widget/public/nsIJumpListItem.idl
 */

#ifndef __gen_nsIJumpListItem_h__
#define __gen_nsIJumpListItem_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsILocalHandlerApp; /* forward declaration */

class nsIMutableArray; /* forward declaration */


/* starting interface:    nsIJumpListItem */
#define NS_IJUMPLISTITEM_IID_STR "acb8fb3c-e1b0-4044-8a50-e52c3e7c1057"

#define NS_IJUMPLISTITEM_IID \
  {0xacb8fb3c, 0xe1b0, 0x4044, \
    { 0x8a, 0x50, 0xe5, 0x2c, 0x3e, 0x7c, 0x10, 0x57 }}

/**
 * Implements Win7 Taskbar jump list item interfaces.
 *
 * Note to consumers: it's reasonable to expect we'll need support for other types
 * of jump list items (an audio file, an email message, etc.). To add types,
 * create the specific interface here, add an implementation class to WinJumpListItem,
 * and add support to addListBuild & removed items processing.
 * 
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIJumpListItem : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJUMPLISTITEM_IID)

  enum { JUMPLIST_ITEM_EMPTY = 0 };

  enum { JUMPLIST_ITEM_SEPARATOR = 1 };

  enum { JUMPLIST_ITEM_LINK = 2 };

  enum { JUMPLIST_ITEM_SHORTCUT = 3 };

  /**
   * Retrieves the jump list item type.
   */
  /* readonly attribute short type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(PRInt16 *aType) = 0;

  /**
   * Compare this item to another.
   *
   * Compares the type and other properties specific to this item's
   * type.
   *
   * separator: type
   * link: type, uri, title
   * shortcut: type, handler app
   */
  /* boolean equals (in nsIJumpListItem item); */
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIJumpListItem *item, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJumpListItem, NS_IJUMPLISTITEM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJUMPLISTITEM \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRInt16 *aType); \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIJumpListItem *item, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJUMPLISTITEM(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRInt16 *aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIJumpListItem *item, PRBool *_retval NS_OUTPARAM) { return _to Equals(item, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJUMPLISTITEM(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRInt16 *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIJumpListItem *item, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Equals(item, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJumpListItem : public nsIJumpListItem
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJUMPLISTITEM

  nsJumpListItem();

private:
  ~nsJumpListItem();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJumpListItem, nsIJumpListItem)

nsJumpListItem::nsJumpListItem()
{
  /* member initializers and constructor code */
}

nsJumpListItem::~nsJumpListItem()
{
  /* destructor code */
}

/* readonly attribute short type; */
NS_IMETHODIMP nsJumpListItem::GetType(PRInt16 *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean equals (in nsIJumpListItem item); */
NS_IMETHODIMP nsJumpListItem::Equals(nsIJumpListItem *item, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIJumpListSeparator */
#define NS_IJUMPLISTSEPARATOR_IID_STR "69a2d5c5-14dc-47da-925d-869e0bd64d27"

#define NS_IJUMPLISTSEPARATOR_IID \
  {0x69a2d5c5, 0x14dc, 0x47da, \
    { 0x92, 0x5d, 0x86, 0x9e, 0x0b, 0xd6, 0x4d, 0x27 }}

/**
 * A menu separator.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIJumpListSeparator : public nsIJumpListItem {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJUMPLISTSEPARATOR_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJumpListSeparator, NS_IJUMPLISTSEPARATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJUMPLISTSEPARATOR \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJUMPLISTSEPARATOR(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJUMPLISTSEPARATOR(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJumpListSeparator : public nsIJumpListSeparator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJUMPLISTSEPARATOR

  nsJumpListSeparator();

private:
  ~nsJumpListSeparator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJumpListSeparator, nsIJumpListSeparator)

nsJumpListSeparator::nsJumpListSeparator()
{
  /* member initializers and constructor code */
}

nsJumpListSeparator::~nsJumpListSeparator()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIJumpListLink */
#define NS_IJUMPLISTLINK_IID_STR "76ea47b1-c797-49b3-9f18-5e740a688524"

#define NS_IJUMPLISTLINK_IID \
  {0x76ea47b1, 0xc797, 0x49b3, \
    { 0x9f, 0x18, 0x5e, 0x74, 0x0a, 0x68, 0x85, 0x24 }}

/**
 * A URI link jump list item.
 *
 * Note the application must be the registered protocol
 * handler for the protocol of the link.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIJumpListLink : public nsIJumpListItem {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJUMPLISTLINK_IID)

  /**
   * Set or get the uri for this link item.
   */
  /* attribute nsIURI uri; */
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI **aUri) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetUri(nsIURI *aUri) = 0;

  /**
   * Set or get the title for a link item.  
   */
  /* attribute AString uriTitle; */
  NS_SCRIPTABLE NS_IMETHOD GetUriTitle(nsAString & aUriTitle) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetUriTitle(const nsAString & aUriTitle) = 0;

  /**
   * Get a 'privacy safe' unique string hash of the uri's
   * spec. Useful in tracking removed items using visible
   * data stores such as prefs. Generates an MD5 hash of
   * the URI spec using nsICryptoHash.
   */
  /* readonly attribute ACString uriHash; */
  NS_SCRIPTABLE NS_IMETHOD GetUriHash(nsACString & aUriHash) = 0;

  /**
   * Compare this item's hash to another uri.
   *
   * Generates a spec hash of the incoming uri and compares
   * it to this item's uri spec hash.
   */
  /* boolean compareHash (in nsIURI uri); */
  NS_SCRIPTABLE NS_IMETHOD CompareHash(nsIURI *uri, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJumpListLink, NS_IJUMPLISTLINK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJUMPLISTLINK \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI **aUri); \
  NS_SCRIPTABLE NS_IMETHOD SetUri(nsIURI *aUri); \
  NS_SCRIPTABLE NS_IMETHOD GetUriTitle(nsAString & aUriTitle); \
  NS_SCRIPTABLE NS_IMETHOD SetUriTitle(const nsAString & aUriTitle); \
  NS_SCRIPTABLE NS_IMETHOD GetUriHash(nsACString & aUriHash); \
  NS_SCRIPTABLE NS_IMETHOD CompareHash(nsIURI *uri, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJUMPLISTLINK(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI **aUri) { return _to GetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD SetUri(nsIURI *aUri) { return _to SetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD GetUriTitle(nsAString & aUriTitle) { return _to GetUriTitle(aUriTitle); } \
  NS_SCRIPTABLE NS_IMETHOD SetUriTitle(const nsAString & aUriTitle) { return _to SetUriTitle(aUriTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetUriHash(nsACString & aUriHash) { return _to GetUriHash(aUriHash); } \
  NS_SCRIPTABLE NS_IMETHOD CompareHash(nsIURI *uri, PRBool *_retval NS_OUTPARAM) { return _to CompareHash(uri, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJUMPLISTLINK(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI **aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD SetUri(nsIURI *aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD GetUriTitle(nsAString & aUriTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUriTitle(aUriTitle); } \
  NS_SCRIPTABLE NS_IMETHOD SetUriTitle(const nsAString & aUriTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUriTitle(aUriTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetUriHash(nsACString & aUriHash) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUriHash(aUriHash); } \
  NS_SCRIPTABLE NS_IMETHOD CompareHash(nsIURI *uri, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CompareHash(uri, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJumpListLink : public nsIJumpListLink
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJUMPLISTLINK

  nsJumpListLink();

private:
  ~nsJumpListLink();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJumpListLink, nsIJumpListLink)

nsJumpListLink::nsJumpListLink()
{
  /* member initializers and constructor code */
}

nsJumpListLink::~nsJumpListLink()
{
  /* destructor code */
}

/* attribute nsIURI uri; */
NS_IMETHODIMP nsJumpListLink::GetUri(nsIURI **aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsJumpListLink::SetUri(nsIURI *aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString uriTitle; */
NS_IMETHODIMP nsJumpListLink::GetUriTitle(nsAString & aUriTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsJumpListLink::SetUriTitle(const nsAString & aUriTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString uriHash; */
NS_IMETHODIMP nsJumpListLink::GetUriHash(nsACString & aUriHash)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean compareHash (in nsIURI uri); */
NS_IMETHODIMP nsJumpListLink::CompareHash(nsIURI *uri, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIJumpListShortcut */
#define NS_IJUMPLISTSHORTCUT_IID_STR "9664389e-11d6-4bea-b68c-d70232162068"

#define NS_IJUMPLISTSHORTCUT_IID \
  {0x9664389e, 0x11d6, 0x4bea, \
    { 0xb6, 0x8c, 0xd7, 0x02, 0x32, 0x16, 0x20, 0x68 }}

/**
 * A generic application shortcut with command line support.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIJumpListShortcut : public nsIJumpListItem {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJUMPLISTSHORTCUT_IID)

  /**
   * Set or get the handler app for this shortcut item.
   * 
   * @throw NS_ERROR_FILE_NOT_FOUND if the handler app can
   * not be found on  the system.
   */
  /* attribute nsILocalHandlerApp app; */
  NS_SCRIPTABLE NS_IMETHOD GetApp(nsILocalHandlerApp **aApp) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetApp(nsILocalHandlerApp *aApp) = 0;

  /**
   * Set or get the icon displayed with the jump list item.
   *
   * Indicates the resource index of the icon contained
   * within the the handler executable.
   */
  /* attribute long iconIndex; */
  NS_SCRIPTABLE NS_IMETHOD GetIconIndex(PRInt32 *aIconIndex) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetIconIndex(PRInt32 aIconIndex) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJumpListShortcut, NS_IJUMPLISTSHORTCUT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJUMPLISTSHORTCUT \
  NS_SCRIPTABLE NS_IMETHOD GetApp(nsILocalHandlerApp **aApp); \
  NS_SCRIPTABLE NS_IMETHOD SetApp(nsILocalHandlerApp *aApp); \
  NS_SCRIPTABLE NS_IMETHOD GetIconIndex(PRInt32 *aIconIndex); \
  NS_SCRIPTABLE NS_IMETHOD SetIconIndex(PRInt32 aIconIndex); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJUMPLISTSHORTCUT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetApp(nsILocalHandlerApp **aApp) { return _to GetApp(aApp); } \
  NS_SCRIPTABLE NS_IMETHOD SetApp(nsILocalHandlerApp *aApp) { return _to SetApp(aApp); } \
  NS_SCRIPTABLE NS_IMETHOD GetIconIndex(PRInt32 *aIconIndex) { return _to GetIconIndex(aIconIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetIconIndex(PRInt32 aIconIndex) { return _to SetIconIndex(aIconIndex); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJUMPLISTSHORTCUT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetApp(nsILocalHandlerApp **aApp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApp(aApp); } \
  NS_SCRIPTABLE NS_IMETHOD SetApp(nsILocalHandlerApp *aApp) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetApp(aApp); } \
  NS_SCRIPTABLE NS_IMETHOD GetIconIndex(PRInt32 *aIconIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIconIndex(aIconIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetIconIndex(PRInt32 aIconIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIconIndex(aIconIndex); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJumpListShortcut : public nsIJumpListShortcut
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJUMPLISTSHORTCUT

  nsJumpListShortcut();

private:
  ~nsJumpListShortcut();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJumpListShortcut, nsIJumpListShortcut)

nsJumpListShortcut::nsJumpListShortcut()
{
  /* member initializers and constructor code */
}

nsJumpListShortcut::~nsJumpListShortcut()
{
  /* destructor code */
}

/* attribute nsILocalHandlerApp app; */
NS_IMETHODIMP nsJumpListShortcut::GetApp(nsILocalHandlerApp **aApp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsJumpListShortcut::SetApp(nsILocalHandlerApp *aApp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long iconIndex; */
NS_IMETHODIMP nsJumpListShortcut::GetIconIndex(PRInt32 *aIconIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsJumpListShortcut::SetIconIndex(PRInt32 aIconIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJumpListItem_h__ */

/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/widget/nsIJumpListItem.idl
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

class NS_NO_VTABLE nsIJumpListItem : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJUMPLISTITEM_IID)

  enum {
    JUMPLIST_ITEM_EMPTY = 0,
    JUMPLIST_ITEM_SEPARATOR = 1,
    JUMPLIST_ITEM_LINK = 2,
    JUMPLIST_ITEM_SHORTCUT = 3
  };

  /* readonly attribute short type; */
  NS_IMETHOD GetType(int16_t *aType) = 0;

  /* boolean equals (in nsIJumpListItem item); */
  NS_IMETHOD Equals(nsIJumpListItem *item, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJumpListItem, NS_IJUMPLISTITEM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJUMPLISTITEM \
  NS_IMETHOD GetType(int16_t *aType); \
  NS_IMETHOD Equals(nsIJumpListItem *item, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJUMPLISTITEM(_to) \
  NS_IMETHOD GetType(int16_t *aType) { return _to GetType(aType); } \
  NS_IMETHOD Equals(nsIJumpListItem *item, bool *_retval) { return _to Equals(item, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJUMPLISTITEM(_to) \
  NS_IMETHOD GetType(int16_t *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD Equals(nsIJumpListItem *item, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Equals(item, _retval); } 

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
NS_IMETHODIMP nsJumpListItem::GetType(int16_t *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean equals (in nsIJumpListItem item); */
NS_IMETHODIMP nsJumpListItem::Equals(nsIJumpListItem *item, bool *_retval)
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

class NS_NO_VTABLE nsIJumpListSeparator : public nsIJumpListItem {
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

class NS_NO_VTABLE nsIJumpListLink : public nsIJumpListItem {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJUMPLISTLINK_IID)

  /* attribute nsIURI uri; */
  NS_IMETHOD GetUri(nsIURI * *aUri) = 0;
  NS_IMETHOD SetUri(nsIURI *aUri) = 0;

  /* attribute AString uriTitle; */
  NS_IMETHOD GetUriTitle(nsAString & aUriTitle) = 0;
  NS_IMETHOD SetUriTitle(const nsAString & aUriTitle) = 0;

  /* readonly attribute ACString uriHash; */
  NS_IMETHOD GetUriHash(nsACString & aUriHash) = 0;

  /* boolean compareHash (in nsIURI uri); */
  NS_IMETHOD CompareHash(nsIURI *uri, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJumpListLink, NS_IJUMPLISTLINK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJUMPLISTLINK \
  NS_IMETHOD GetUri(nsIURI * *aUri); \
  NS_IMETHOD SetUri(nsIURI *aUri); \
  NS_IMETHOD GetUriTitle(nsAString & aUriTitle); \
  NS_IMETHOD SetUriTitle(const nsAString & aUriTitle); \
  NS_IMETHOD GetUriHash(nsACString & aUriHash); \
  NS_IMETHOD CompareHash(nsIURI *uri, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJUMPLISTLINK(_to) \
  NS_IMETHOD GetUri(nsIURI * *aUri) { return _to GetUri(aUri); } \
  NS_IMETHOD SetUri(nsIURI *aUri) { return _to SetUri(aUri); } \
  NS_IMETHOD GetUriTitle(nsAString & aUriTitle) { return _to GetUriTitle(aUriTitle); } \
  NS_IMETHOD SetUriTitle(const nsAString & aUriTitle) { return _to SetUriTitle(aUriTitle); } \
  NS_IMETHOD GetUriHash(nsACString & aUriHash) { return _to GetUriHash(aUriHash); } \
  NS_IMETHOD CompareHash(nsIURI *uri, bool *_retval) { return _to CompareHash(uri, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJUMPLISTLINK(_to) \
  NS_IMETHOD GetUri(nsIURI * *aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUri(aUri); } \
  NS_IMETHOD SetUri(nsIURI *aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUri(aUri); } \
  NS_IMETHOD GetUriTitle(nsAString & aUriTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUriTitle(aUriTitle); } \
  NS_IMETHOD SetUriTitle(const nsAString & aUriTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUriTitle(aUriTitle); } \
  NS_IMETHOD GetUriHash(nsACString & aUriHash) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUriHash(aUriHash); } \
  NS_IMETHOD CompareHash(nsIURI *uri, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CompareHash(uri, _retval); } 

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
NS_IMETHODIMP nsJumpListLink::GetUri(nsIURI * *aUri)
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
NS_IMETHODIMP nsJumpListLink::CompareHash(nsIURI *uri, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIJumpListShortcut */
#define NS_IJUMPLISTSHORTCUT_IID_STR "cbe3a37c-bce1-4fec-80a5-5ffbc7f33eea"

#define NS_IJUMPLISTSHORTCUT_IID \
  {0xcbe3a37c, 0xbce1, 0x4fec, \
    { 0x80, 0xa5, 0x5f, 0xfb, 0xc7, 0xf3, 0x3e, 0xea }}

class NS_NO_VTABLE nsIJumpListShortcut : public nsIJumpListItem {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJUMPLISTSHORTCUT_IID)

  /* attribute nsILocalHandlerApp app; */
  NS_IMETHOD GetApp(nsILocalHandlerApp * *aApp) = 0;
  NS_IMETHOD SetApp(nsILocalHandlerApp *aApp) = 0;

  /* attribute long iconIndex; */
  NS_IMETHOD GetIconIndex(int32_t *aIconIndex) = 0;
  NS_IMETHOD SetIconIndex(int32_t aIconIndex) = 0;

  /* attribute nsIURI faviconPageUri; */
  NS_IMETHOD GetFaviconPageUri(nsIURI * *aFaviconPageUri) = 0;
  NS_IMETHOD SetFaviconPageUri(nsIURI *aFaviconPageUri) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJumpListShortcut, NS_IJUMPLISTSHORTCUT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJUMPLISTSHORTCUT \
  NS_IMETHOD GetApp(nsILocalHandlerApp * *aApp); \
  NS_IMETHOD SetApp(nsILocalHandlerApp *aApp); \
  NS_IMETHOD GetIconIndex(int32_t *aIconIndex); \
  NS_IMETHOD SetIconIndex(int32_t aIconIndex); \
  NS_IMETHOD GetFaviconPageUri(nsIURI * *aFaviconPageUri); \
  NS_IMETHOD SetFaviconPageUri(nsIURI *aFaviconPageUri); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJUMPLISTSHORTCUT(_to) \
  NS_IMETHOD GetApp(nsILocalHandlerApp * *aApp) { return _to GetApp(aApp); } \
  NS_IMETHOD SetApp(nsILocalHandlerApp *aApp) { return _to SetApp(aApp); } \
  NS_IMETHOD GetIconIndex(int32_t *aIconIndex) { return _to GetIconIndex(aIconIndex); } \
  NS_IMETHOD SetIconIndex(int32_t aIconIndex) { return _to SetIconIndex(aIconIndex); } \
  NS_IMETHOD GetFaviconPageUri(nsIURI * *aFaviconPageUri) { return _to GetFaviconPageUri(aFaviconPageUri); } \
  NS_IMETHOD SetFaviconPageUri(nsIURI *aFaviconPageUri) { return _to SetFaviconPageUri(aFaviconPageUri); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJUMPLISTSHORTCUT(_to) \
  NS_IMETHOD GetApp(nsILocalHandlerApp * *aApp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApp(aApp); } \
  NS_IMETHOD SetApp(nsILocalHandlerApp *aApp) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetApp(aApp); } \
  NS_IMETHOD GetIconIndex(int32_t *aIconIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIconIndex(aIconIndex); } \
  NS_IMETHOD SetIconIndex(int32_t aIconIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIconIndex(aIconIndex); } \
  NS_IMETHOD GetFaviconPageUri(nsIURI * *aFaviconPageUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFaviconPageUri(aFaviconPageUri); } \
  NS_IMETHOD SetFaviconPageUri(nsIURI *aFaviconPageUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFaviconPageUri(aFaviconPageUri); } 

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
NS_IMETHODIMP nsJumpListShortcut::GetApp(nsILocalHandlerApp * *aApp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsJumpListShortcut::SetApp(nsILocalHandlerApp *aApp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long iconIndex; */
NS_IMETHODIMP nsJumpListShortcut::GetIconIndex(int32_t *aIconIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsJumpListShortcut::SetIconIndex(int32_t aIconIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIURI faviconPageUri; */
NS_IMETHODIMP nsJumpListShortcut::GetFaviconPageUri(nsIURI * *aFaviconPageUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsJumpListShortcut::SetFaviconPageUri(nsIURI *aFaviconPageUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJumpListItem_h__ */

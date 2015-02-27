/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\imgICache.idl
 */

#ifndef __gen_imgICache_h__
#define __gen_imgICache_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class imgIRequest; /* forward declaration */

class nsIProperties; /* forward declaration */


/* starting interface:    imgICache */
#define IMGICACHE_IID_STR "b06e0fa5-d6e2-4fa3-8fc0-7775aed96522"

#define IMGICACHE_IID \
  {0xb06e0fa5, 0xd6e2, 0x4fa3, \
    { 0x8f, 0xc0, 0x77, 0x75, 0xae, 0xd9, 0x65, 0x22 }}

class NS_NO_VTABLE imgICache : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMGICACHE_IID)

  /* void clearCache (in boolean chrome); */
  NS_IMETHOD ClearCache(bool chrome) = 0;

  /* void removeEntry (in nsIURI uri); */
  NS_IMETHOD RemoveEntry(nsIURI *uri) = 0;

  /* nsIProperties findEntryProperties (in nsIURI uri); */
  NS_IMETHOD FindEntryProperties(nsIURI *uri, nsIProperties * *_retval) = 0;

  /* void respectPrivacyNotifications (); */
  NS_IMETHOD RespectPrivacyNotifications(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(imgICache, IMGICACHE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMGICACHE \
  NS_IMETHOD ClearCache(bool chrome); \
  NS_IMETHOD RemoveEntry(nsIURI *uri); \
  NS_IMETHOD FindEntryProperties(nsIURI *uri, nsIProperties * *_retval); \
  NS_IMETHOD RespectPrivacyNotifications(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMGICACHE(_to) \
  NS_IMETHOD ClearCache(bool chrome) { return _to ClearCache(chrome); } \
  NS_IMETHOD RemoveEntry(nsIURI *uri) { return _to RemoveEntry(uri); } \
  NS_IMETHOD FindEntryProperties(nsIURI *uri, nsIProperties * *_retval) { return _to FindEntryProperties(uri, _retval); } \
  NS_IMETHOD RespectPrivacyNotifications(void) { return _to RespectPrivacyNotifications(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMGICACHE(_to) \
  NS_IMETHOD ClearCache(bool chrome) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearCache(chrome); } \
  NS_IMETHOD RemoveEntry(nsIURI *uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveEntry(uri); } \
  NS_IMETHOD FindEntryProperties(nsIURI *uri, nsIProperties * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindEntryProperties(uri, _retval); } \
  NS_IMETHOD RespectPrivacyNotifications(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RespectPrivacyNotifications(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public imgICache
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMGICACHE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, imgICache)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void clearCache (in boolean chrome); */
NS_IMETHODIMP _MYCLASS_::ClearCache(bool chrome)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeEntry (in nsIURI uri); */
NS_IMETHODIMP _MYCLASS_::RemoveEntry(nsIURI *uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIProperties findEntryProperties (in nsIURI uri); */
NS_IMETHODIMP _MYCLASS_::FindEntryProperties(nsIURI *uri, nsIProperties * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void respectPrivacyNotifications (); */
NS_IMETHODIMP _MYCLASS_::RespectPrivacyNotifications()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_imgICache_h__ */

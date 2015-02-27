/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/uriloader/base/nsIURIContentListener.idl
 */

#ifndef __gen_nsIURIContentListener_h__
#define __gen_nsIURIContentListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIRequest; /* forward declaration */

class nsIStreamListener; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIURIContentListener */
#define NS_IURICONTENTLISTENER_IID_STR "94928ab3-8b63-11d3-989d-001083010e9b"

#define NS_IURICONTENTLISTENER_IID \
  {0x94928ab3, 0x8b63, 0x11d3, \
    { 0x98, 0x9d, 0x00, 0x10, 0x83, 0x01, 0x0e, 0x9b }}

class NS_NO_VTABLE nsIURIContentListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURICONTENTLISTENER_IID)

  /* boolean onStartURIOpen (in nsIURI aURI); */
  NS_IMETHOD OnStartURIOpen(nsIURI *aURI, bool *_retval) = 0;

  /* boolean doContent (in string aContentType, in boolean aIsContentPreferred, in nsIRequest aRequest, out nsIStreamListener aContentHandler); */
  NS_IMETHOD DoContent(const char * aContentType, bool aIsContentPreferred, nsIRequest *aRequest, nsIStreamListener * *aContentHandler, bool *_retval) = 0;

  /* boolean isPreferred (in string aContentType, out string aDesiredContentType); */
  NS_IMETHOD IsPreferred(const char * aContentType, char * *aDesiredContentType, bool *_retval) = 0;

  /* boolean canHandleContent (in string aContentType, in boolean aIsContentPreferred, out string aDesiredContentType); */
  NS_IMETHOD CanHandleContent(const char * aContentType, bool aIsContentPreferred, char * *aDesiredContentType, bool *_retval) = 0;

  /* attribute nsISupports loadCookie; */
  NS_IMETHOD GetLoadCookie(nsISupports * *aLoadCookie) = 0;
  NS_IMETHOD SetLoadCookie(nsISupports *aLoadCookie) = 0;

  /* attribute nsIURIContentListener parentContentListener; */
  NS_IMETHOD GetParentContentListener(nsIURIContentListener * *aParentContentListener) = 0;
  NS_IMETHOD SetParentContentListener(nsIURIContentListener *aParentContentListener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIURIContentListener, NS_IURICONTENTLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURICONTENTLISTENER \
  NS_IMETHOD OnStartURIOpen(nsIURI *aURI, bool *_retval); \
  NS_IMETHOD DoContent(const char * aContentType, bool aIsContentPreferred, nsIRequest *aRequest, nsIStreamListener * *aContentHandler, bool *_retval); \
  NS_IMETHOD IsPreferred(const char * aContentType, char * *aDesiredContentType, bool *_retval); \
  NS_IMETHOD CanHandleContent(const char * aContentType, bool aIsContentPreferred, char * *aDesiredContentType, bool *_retval); \
  NS_IMETHOD GetLoadCookie(nsISupports * *aLoadCookie); \
  NS_IMETHOD SetLoadCookie(nsISupports *aLoadCookie); \
  NS_IMETHOD GetParentContentListener(nsIURIContentListener * *aParentContentListener); \
  NS_IMETHOD SetParentContentListener(nsIURIContentListener *aParentContentListener); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURICONTENTLISTENER(_to) \
  NS_IMETHOD OnStartURIOpen(nsIURI *aURI, bool *_retval) { return _to OnStartURIOpen(aURI, _retval); } \
  NS_IMETHOD DoContent(const char * aContentType, bool aIsContentPreferred, nsIRequest *aRequest, nsIStreamListener * *aContentHandler, bool *_retval) { return _to DoContent(aContentType, aIsContentPreferred, aRequest, aContentHandler, _retval); } \
  NS_IMETHOD IsPreferred(const char * aContentType, char * *aDesiredContentType, bool *_retval) { return _to IsPreferred(aContentType, aDesiredContentType, _retval); } \
  NS_IMETHOD CanHandleContent(const char * aContentType, bool aIsContentPreferred, char * *aDesiredContentType, bool *_retval) { return _to CanHandleContent(aContentType, aIsContentPreferred, aDesiredContentType, _retval); } \
  NS_IMETHOD GetLoadCookie(nsISupports * *aLoadCookie) { return _to GetLoadCookie(aLoadCookie); } \
  NS_IMETHOD SetLoadCookie(nsISupports *aLoadCookie) { return _to SetLoadCookie(aLoadCookie); } \
  NS_IMETHOD GetParentContentListener(nsIURIContentListener * *aParentContentListener) { return _to GetParentContentListener(aParentContentListener); } \
  NS_IMETHOD SetParentContentListener(nsIURIContentListener *aParentContentListener) { return _to SetParentContentListener(aParentContentListener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURICONTENTLISTENER(_to) \
  NS_IMETHOD OnStartURIOpen(nsIURI *aURI, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStartURIOpen(aURI, _retval); } \
  NS_IMETHOD DoContent(const char * aContentType, bool aIsContentPreferred, nsIRequest *aRequest, nsIStreamListener * *aContentHandler, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoContent(aContentType, aIsContentPreferred, aRequest, aContentHandler, _retval); } \
  NS_IMETHOD IsPreferred(const char * aContentType, char * *aDesiredContentType, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsPreferred(aContentType, aDesiredContentType, _retval); } \
  NS_IMETHOD CanHandleContent(const char * aContentType, bool aIsContentPreferred, char * *aDesiredContentType, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanHandleContent(aContentType, aIsContentPreferred, aDesiredContentType, _retval); } \
  NS_IMETHOD GetLoadCookie(nsISupports * *aLoadCookie) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadCookie(aLoadCookie); } \
  NS_IMETHOD SetLoadCookie(nsISupports *aLoadCookie) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLoadCookie(aLoadCookie); } \
  NS_IMETHOD GetParentContentListener(nsIURIContentListener * *aParentContentListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentContentListener(aParentContentListener); } \
  NS_IMETHOD SetParentContentListener(nsIURIContentListener *aParentContentListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetParentContentListener(aParentContentListener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsURIContentListener : public nsIURIContentListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURICONTENTLISTENER

  nsURIContentListener();

private:
  ~nsURIContentListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsURIContentListener, nsIURIContentListener)

nsURIContentListener::nsURIContentListener()
{
  /* member initializers and constructor code */
}

nsURIContentListener::~nsURIContentListener()
{
  /* destructor code */
}

/* boolean onStartURIOpen (in nsIURI aURI); */
NS_IMETHODIMP nsURIContentListener::OnStartURIOpen(nsIURI *aURI, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean doContent (in string aContentType, in boolean aIsContentPreferred, in nsIRequest aRequest, out nsIStreamListener aContentHandler); */
NS_IMETHODIMP nsURIContentListener::DoContent(const char * aContentType, bool aIsContentPreferred, nsIRequest *aRequest, nsIStreamListener * *aContentHandler, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isPreferred (in string aContentType, out string aDesiredContentType); */
NS_IMETHODIMP nsURIContentListener::IsPreferred(const char * aContentType, char * *aDesiredContentType, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canHandleContent (in string aContentType, in boolean aIsContentPreferred, out string aDesiredContentType); */
NS_IMETHODIMP nsURIContentListener::CanHandleContent(const char * aContentType, bool aIsContentPreferred, char * *aDesiredContentType, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISupports loadCookie; */
NS_IMETHODIMP nsURIContentListener::GetLoadCookie(nsISupports * *aLoadCookie)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsURIContentListener::SetLoadCookie(nsISupports *aLoadCookie)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIURIContentListener parentContentListener; */
NS_IMETHODIMP nsURIContentListener::GetParentContentListener(nsIURIContentListener * *aParentContentListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsURIContentListener::SetParentContentListener(nsIURIContentListener *aParentContentListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIURIContentListener_h__ */

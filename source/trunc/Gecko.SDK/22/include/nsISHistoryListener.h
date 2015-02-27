/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/docshell/shistory/public/nsISHistoryListener.idl
 */

#ifndef __gen_nsISHistoryListener_h__
#define __gen_nsISHistoryListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsISHistoryListener */
#define NS_ISHISTORYLISTENER_IID_STR "3b07f591-e8e1-11d4-9882-00c04fa02f40"

#define NS_ISHISTORYLISTENER_IID \
  {0x3b07f591, 0xe8e1, 0x11d4, \
    { 0x98, 0x82, 0x00, 0xc0, 0x4f, 0xa0, 0x2f, 0x40 }}

class NS_NO_VTABLE nsISHistoryListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISHISTORYLISTENER_IID)

  /* void OnHistoryNewEntry (in nsIURI aNewURI); */
  NS_IMETHOD OnHistoryNewEntry(nsIURI *aNewURI) = 0;

  /* boolean OnHistoryGoBack (in nsIURI aBackURI); */
  NS_IMETHOD OnHistoryGoBack(nsIURI *aBackURI, bool *_retval) = 0;

  /* boolean OnHistoryGoForward (in nsIURI aForwardURI); */
  NS_IMETHOD OnHistoryGoForward(nsIURI *aForwardURI, bool *_retval) = 0;

  /* boolean OnHistoryReload (in nsIURI aReloadURI, in unsigned long aReloadFlags); */
  NS_IMETHOD OnHistoryReload(nsIURI *aReloadURI, uint32_t aReloadFlags, bool *_retval) = 0;

  /* boolean OnHistoryGotoIndex (in long aIndex, in nsIURI aGotoURI); */
  NS_IMETHOD OnHistoryGotoIndex(int32_t aIndex, nsIURI *aGotoURI, bool *_retval) = 0;

  /* boolean OnHistoryPurge (in long aNumEntries); */
  NS_IMETHOD OnHistoryPurge(int32_t aNumEntries, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISHistoryListener, NS_ISHISTORYLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISHISTORYLISTENER \
  NS_IMETHOD OnHistoryNewEntry(nsIURI *aNewURI); \
  NS_IMETHOD OnHistoryGoBack(nsIURI *aBackURI, bool *_retval); \
  NS_IMETHOD OnHistoryGoForward(nsIURI *aForwardURI, bool *_retval); \
  NS_IMETHOD OnHistoryReload(nsIURI *aReloadURI, uint32_t aReloadFlags, bool *_retval); \
  NS_IMETHOD OnHistoryGotoIndex(int32_t aIndex, nsIURI *aGotoURI, bool *_retval); \
  NS_IMETHOD OnHistoryPurge(int32_t aNumEntries, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISHISTORYLISTENER(_to) \
  NS_IMETHOD OnHistoryNewEntry(nsIURI *aNewURI) { return _to OnHistoryNewEntry(aNewURI); } \
  NS_IMETHOD OnHistoryGoBack(nsIURI *aBackURI, bool *_retval) { return _to OnHistoryGoBack(aBackURI, _retval); } \
  NS_IMETHOD OnHistoryGoForward(nsIURI *aForwardURI, bool *_retval) { return _to OnHistoryGoForward(aForwardURI, _retval); } \
  NS_IMETHOD OnHistoryReload(nsIURI *aReloadURI, uint32_t aReloadFlags, bool *_retval) { return _to OnHistoryReload(aReloadURI, aReloadFlags, _retval); } \
  NS_IMETHOD OnHistoryGotoIndex(int32_t aIndex, nsIURI *aGotoURI, bool *_retval) { return _to OnHistoryGotoIndex(aIndex, aGotoURI, _retval); } \
  NS_IMETHOD OnHistoryPurge(int32_t aNumEntries, bool *_retval) { return _to OnHistoryPurge(aNumEntries, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISHISTORYLISTENER(_to) \
  NS_IMETHOD OnHistoryNewEntry(nsIURI *aNewURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnHistoryNewEntry(aNewURI); } \
  NS_IMETHOD OnHistoryGoBack(nsIURI *aBackURI, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnHistoryGoBack(aBackURI, _retval); } \
  NS_IMETHOD OnHistoryGoForward(nsIURI *aForwardURI, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnHistoryGoForward(aForwardURI, _retval); } \
  NS_IMETHOD OnHistoryReload(nsIURI *aReloadURI, uint32_t aReloadFlags, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnHistoryReload(aReloadURI, aReloadFlags, _retval); } \
  NS_IMETHOD OnHistoryGotoIndex(int32_t aIndex, nsIURI *aGotoURI, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnHistoryGotoIndex(aIndex, aGotoURI, _retval); } \
  NS_IMETHOD OnHistoryPurge(int32_t aNumEntries, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnHistoryPurge(aNumEntries, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSHistoryListener : public nsISHistoryListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISHISTORYLISTENER

  nsSHistoryListener();

private:
  ~nsSHistoryListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSHistoryListener, nsISHistoryListener)

nsSHistoryListener::nsSHistoryListener()
{
  /* member initializers and constructor code */
}

nsSHistoryListener::~nsSHistoryListener()
{
  /* destructor code */
}

/* void OnHistoryNewEntry (in nsIURI aNewURI); */
NS_IMETHODIMP nsSHistoryListener::OnHistoryNewEntry(nsIURI *aNewURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean OnHistoryGoBack (in nsIURI aBackURI); */
NS_IMETHODIMP nsSHistoryListener::OnHistoryGoBack(nsIURI *aBackURI, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean OnHistoryGoForward (in nsIURI aForwardURI); */
NS_IMETHODIMP nsSHistoryListener::OnHistoryGoForward(nsIURI *aForwardURI, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean OnHistoryReload (in nsIURI aReloadURI, in unsigned long aReloadFlags); */
NS_IMETHODIMP nsSHistoryListener::OnHistoryReload(nsIURI *aReloadURI, uint32_t aReloadFlags, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean OnHistoryGotoIndex (in long aIndex, in nsIURI aGotoURI); */
NS_IMETHODIMP nsSHistoryListener::OnHistoryGotoIndex(int32_t aIndex, nsIURI *aGotoURI, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean OnHistoryPurge (in long aNumEntries); */
NS_IMETHODIMP nsSHistoryListener::OnHistoryPurge(int32_t aNumEntries, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISHistoryListener_h__ */

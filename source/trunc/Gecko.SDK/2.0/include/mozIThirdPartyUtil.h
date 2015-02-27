/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/netwerk/base/public/mozIThirdPartyUtil.idl
 */

#ifndef __gen_mozIThirdPartyUtil_h__
#define __gen_mozIThirdPartyUtil_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIDOMWindow; /* forward declaration */

class nsIChannel; /* forward declaration */


/* starting interface:    mozIThirdPartyUtil */
#define MOZITHIRDPARTYUTIL_IID_STR "55385caa-1b94-4376-a34c-b47c51ef0837"

#define MOZITHIRDPARTYUTIL_IID \
  {0x55385caa, 0x1b94, 0x4376, \
    { 0xa3, 0x4c, 0xb4, 0x7c, 0x51, 0xef, 0x08, 0x37 }}

/**
 * Utility functions for determining whether a given URI, channel, or window
 * hierarchy is third party with respect to a known URI.
 */
class NS_NO_VTABLE NS_SCRIPTABLE mozIThirdPartyUtil : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZITHIRDPARTYUTIL_IID)

  /**
   * isThirdPartyURI
   *
   * Determine whether two URIs are third party with respect to each other.
   * This is determined by computing the base domain for both URIs. If they can
   * be determined, and the base domains match, the request is defined as first
   * party. If it cannot be determined because one or both URIs do not have a
   * base domain (for instance, in the case of IP addresses, host aliases such
   * as 'localhost', or a file:// URI), an exact string comparison on host is
   * performed.
   *
   * For example, the URI "http://mail.google.com/" is not third party with
   * respect to "http://images.google.com/", but "http://mail.yahoo.com/" and
   * "http://192.168.1.1/" are.
   *
   * @return true if aFirstURI is third party with respect to aSecondURI.
   *
   * @throws if either URI is null, has a malformed host, or has an empty host
   *         and is not a file:// URI.
   */
  /* boolean isThirdPartyURI (in nsIURI aFirstURI, in nsIURI aSecondURI); */
  NS_SCRIPTABLE NS_IMETHOD IsThirdPartyURI(nsIURI *aFirstURI, nsIURI *aSecondURI, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * isThirdPartyWindow
   *
   * Determine whether the given window hierarchy is third party. This is done
   * as follows:
   *
   * 1) Obtain the URI of the principal associated with 'aWindow'. Call this the
   *    'bottom URI'.
   * 2) If 'aURI' is provided, determine if it is third party with respect to
   *    the bottom URI. If so, return.
   * 3) Find the same-type parent window, if there is one, and its URI.
   *    Determine whether it is third party with respect to the bottom URI. If
   *    so, return.
   *
   * Therefore, each level in the window hierarchy is tested. (This means that
   * nested iframes with different base domains, even though the bottommost and
   * topmost URIs might be equal, will be considered third party.)
   *
   * @param aWindow
   *        The bottommost window in the hierarchy.
   * @param aURI
   *        A URI to test against. If null, the URI of the principal
   *        associated with 'aWindow' will be used.
   *
   * For example, if 'aURI' is "http://mail.google.com/", 'aWindow' has a URI
   * of "http://google.com/", and its parent is the topmost content window with
   * a URI of "http://mozilla.com", the result will be true.
   *
   * @return true if 'aURI' is third party with respect to any of the URIs
   *         associated with aWindow and its same-type parents.
   *
   * @throws if aWindow is null; the same-type parent of any window in the
   *         hierarchy cannot be determined; or the URI associated with any
   *         window in the hierarchy is null, has a malformed host, or has an
   *         empty host and is not a file:// URI.
   *
   * @see isThirdPartyURI
   */
  /* boolean isThirdPartyWindow (in nsIDOMWindow aWindow, [optional] in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD IsThirdPartyWindow(nsIDOMWindow *aWindow, nsIURI *aURI, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * isThirdPartyChannel
   *
   * Determine whether the given channel and its content window hierarchy is
   * third party. This is done as follows:
   *
   * 1) If 'aChannel' is an nsIHttpChannel and has the
   *    'forceAllowThirdPartyCookie' property set, then:
   *    a) If 'aURI' is null, return false.
   *    b) Otherwise, find the URI of the channel, determine whether it is
   *       foreign with respect to 'aURI', and return.
   * 2) Find the URI of the channel and determine whether it is third party with
   *    respect to the URI of the channel. If so, return.
   * 3) Obtain the bottommost nsIDOMWindow, and its same-type parent if it
   *    exists, from the channel's notification callbacks. Then:
   *    a) If the parent is the same as the bottommost window, and the channel
   *       has the LOAD_DOCUMENT_URI flag set, return false. This represents the
   *       case where a toplevel load is occurring and the window's URI has not
   *       yet been updated. (We have already checked that 'aURI' is not foreign
   *       with respect to the channel URI.)
   *    b) Otherwise, return the result of isThirdPartyWindow with arguments
   *       of the channel's bottommost window and the channel URI, respectively.
   *
   * Therefore, both the channel's URI and each level in the window hierarchy
   * associated with the channel is tested.
   *
   * @param aChannel
   *        The channel associated with the load.
   * @param aURI
   *        A URI to test against. If null, the URI of the channel will be used.
   *
   * For example, if 'aURI' is "http://mail.google.com/", 'aChannel' has a URI
   * of "http://google.com/", and its parent is the topmost content window with
   * a URI of "http://mozilla.com", the result will be true.
   *
   * @return true if aURI is third party with respect to the channel URI or any
   *         of the URIs associated with the same-type window hierarchy of the
   *         channel.
   *
   * @throws if 'aChannel' is null; the channel has no notification callbacks or
   *         an associated window; or isThirdPartyWindow throws.
   *
   * @see isThirdPartyWindow
   */
  /* boolean isThirdPartyChannel (in nsIChannel aChannel, [optional] in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD IsThirdPartyChannel(nsIChannel *aChannel, nsIURI *aURI, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIThirdPartyUtil, MOZITHIRDPARTYUTIL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZITHIRDPARTYUTIL \
  NS_SCRIPTABLE NS_IMETHOD IsThirdPartyURI(nsIURI *aFirstURI, nsIURI *aSecondURI, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsThirdPartyWindow(nsIDOMWindow *aWindow, nsIURI *aURI, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsThirdPartyChannel(nsIChannel *aChannel, nsIURI *aURI, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZITHIRDPARTYUTIL(_to) \
  NS_SCRIPTABLE NS_IMETHOD IsThirdPartyURI(nsIURI *aFirstURI, nsIURI *aSecondURI, PRBool *_retval NS_OUTPARAM) { return _to IsThirdPartyURI(aFirstURI, aSecondURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsThirdPartyWindow(nsIDOMWindow *aWindow, nsIURI *aURI, PRBool *_retval NS_OUTPARAM) { return _to IsThirdPartyWindow(aWindow, aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsThirdPartyChannel(nsIChannel *aChannel, nsIURI *aURI, PRBool *_retval NS_OUTPARAM) { return _to IsThirdPartyChannel(aChannel, aURI, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZITHIRDPARTYUTIL(_to) \
  NS_SCRIPTABLE NS_IMETHOD IsThirdPartyURI(nsIURI *aFirstURI, nsIURI *aSecondURI, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsThirdPartyURI(aFirstURI, aSecondURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsThirdPartyWindow(nsIDOMWindow *aWindow, nsIURI *aURI, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsThirdPartyWindow(aWindow, aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsThirdPartyChannel(nsIChannel *aChannel, nsIURI *aURI, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsThirdPartyChannel(aChannel, aURI, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIThirdPartyUtil
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZITHIRDPARTYUTIL

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIThirdPartyUtil)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* boolean isThirdPartyURI (in nsIURI aFirstURI, in nsIURI aSecondURI); */
NS_IMETHODIMP _MYCLASS_::IsThirdPartyURI(nsIURI *aFirstURI, nsIURI *aSecondURI, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isThirdPartyWindow (in nsIDOMWindow aWindow, [optional] in nsIURI aURI); */
NS_IMETHODIMP _MYCLASS_::IsThirdPartyWindow(nsIDOMWindow *aWindow, nsIURI *aURI, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isThirdPartyChannel (in nsIChannel aChannel, [optional] in nsIURI aURI); */
NS_IMETHODIMP _MYCLASS_::IsThirdPartyChannel(nsIChannel *aChannel, nsIURI *aURI, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * The mozIThirdPartyUtil implementation is an XPCOM service registered
 * under the ContractID:
 */
#define THIRDPARTYUTIL_CONTRACTID "@mozilla.org/thirdpartyutil;1"

#endif /* __gen_mozIThirdPartyUtil_h__ */

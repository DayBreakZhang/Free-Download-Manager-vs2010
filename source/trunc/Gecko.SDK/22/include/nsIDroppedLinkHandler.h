/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/content/base/public/nsIDroppedLinkHandler.idl
 */

#ifndef __gen_nsIDroppedLinkHandler_h__
#define __gen_nsIDroppedLinkHandler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDragEvent; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIDroppedLinkHandler */
#define NS_IDROPPEDLINKHANDLER_IID_STR "6b58a5a7-76d0-4e93-ab2e-4de108683ff8"

#define NS_IDROPPEDLINKHANDLER_IID \
  {0x6b58a5a7, 0x76d0, 0x4e93, \
    { 0xab, 0x2e, 0x4d, 0xe1, 0x08, 0x68, 0x3f, 0xf8 }}

class NS_NO_VTABLE nsIDroppedLinkHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDROPPEDLINKHANDLER_IID)

  /* boolean canDropLink (in nsIDOMDragEvent aEvent, in boolean aAllowSameDocument); */
  NS_IMETHOD CanDropLink(nsIDOMDragEvent *aEvent, bool aAllowSameDocument, bool *_retval) = 0;

  /* AString dropLink (in nsIDOMDragEvent aEvent, out AString aName, [optional] in boolean aDisallowInherit); */
  NS_IMETHOD DropLink(nsIDOMDragEvent *aEvent, nsAString & aName, bool aDisallowInherit, nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDroppedLinkHandler, NS_IDROPPEDLINKHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDROPPEDLINKHANDLER \
  NS_IMETHOD CanDropLink(nsIDOMDragEvent *aEvent, bool aAllowSameDocument, bool *_retval); \
  NS_IMETHOD DropLink(nsIDOMDragEvent *aEvent, nsAString & aName, bool aDisallowInherit, nsAString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDROPPEDLINKHANDLER(_to) \
  NS_IMETHOD CanDropLink(nsIDOMDragEvent *aEvent, bool aAllowSameDocument, bool *_retval) { return _to CanDropLink(aEvent, aAllowSameDocument, _retval); } \
  NS_IMETHOD DropLink(nsIDOMDragEvent *aEvent, nsAString & aName, bool aDisallowInherit, nsAString & _retval) { return _to DropLink(aEvent, aName, aDisallowInherit, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDROPPEDLINKHANDLER(_to) \
  NS_IMETHOD CanDropLink(nsIDOMDragEvent *aEvent, bool aAllowSameDocument, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanDropLink(aEvent, aAllowSameDocument, _retval); } \
  NS_IMETHOD DropLink(nsIDOMDragEvent *aEvent, nsAString & aName, bool aDisallowInherit, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->DropLink(aEvent, aName, aDisallowInherit, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDroppedLinkHandler : public nsIDroppedLinkHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDROPPEDLINKHANDLER

  nsDroppedLinkHandler();

private:
  ~nsDroppedLinkHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDroppedLinkHandler, nsIDroppedLinkHandler)

nsDroppedLinkHandler::nsDroppedLinkHandler()
{
  /* member initializers and constructor code */
}

nsDroppedLinkHandler::~nsDroppedLinkHandler()
{
  /* destructor code */
}

/* boolean canDropLink (in nsIDOMDragEvent aEvent, in boolean aAllowSameDocument); */
NS_IMETHODIMP nsDroppedLinkHandler::CanDropLink(nsIDOMDragEvent *aEvent, bool aAllowSameDocument, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString dropLink (in nsIDOMDragEvent aEvent, out AString aName, [optional] in boolean aDisallowInherit); */
NS_IMETHODIMP nsDroppedLinkHandler::DropLink(nsIDOMDragEvent *aEvent, nsAString & aName, bool aDisallowInherit, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDroppedLinkHandler_h__ */

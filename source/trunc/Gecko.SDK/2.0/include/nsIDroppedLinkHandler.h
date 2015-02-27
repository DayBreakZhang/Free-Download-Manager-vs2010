/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/content/base/public/nsIDroppedLinkHandler.idl
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
#define NS_IDROPPEDLINKHANDLER_IID_STR "f266b79b-7026-4d2d-b4bd-4f2c6b6c59b4"

#define NS_IDROPPEDLINKHANDLER_IID \
  {0xf266b79b, 0x7026, 0x4d2d, \
    { 0xb4, 0xbd, 0x4f, 0x2c, 0x6b, 0x6c, 0x59, 0xb4 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDroppedLinkHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDROPPEDLINKHANDLER_IID)

  /**
   * Determines if a link being dragged can be dropped and returns true if so.
   * aEvent should be a dragenter or dragover event.
   *
   * If aAllowSameDocument is false, drops are only allowed if the document
   * of the source of the drag is different from the destination. This check
   * includes any parent, sibling and child frames in the same content tree.
   * If true, the source is not checked.
   */
  /* boolean canDropLink (in nsIDOMDragEvent aEvent, in PRBool aAllowSameDocument); */
  NS_SCRIPTABLE NS_IMETHOD CanDropLink(nsIDOMDragEvent *aEvent, PRBool aAllowSameDocument, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Given a drop event aEvent, determines the link being dragged and returns
   * it. If a uri is returned the caller can, for instance, load it. If null
   * is returned, there is no valid link to be dropped. A
   * NS_ERROR_DOM_SECURITY_ERR error will be thrown and the event cancelled if
   * the receiving target should not load the uri for security reasons. This
   * will occur if the source of the drag initiated a link for dragging that
   * it itself cannot access. This prevents a source document from tricking
   * the user into a dragging a chrome url for example.
   *
   * aName is filled in with the link title if it exists, or an empty string
   * otherwise.
   */
  /* AString dropLink (in nsIDOMDragEvent aEvent, out AString aName); */
  NS_SCRIPTABLE NS_IMETHOD DropLink(nsIDOMDragEvent *aEvent, nsAString & aName NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDroppedLinkHandler, NS_IDROPPEDLINKHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDROPPEDLINKHANDLER \
  NS_SCRIPTABLE NS_IMETHOD CanDropLink(nsIDOMDragEvent *aEvent, PRBool aAllowSameDocument, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DropLink(nsIDOMDragEvent *aEvent, nsAString & aName NS_OUTPARAM, nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDROPPEDLINKHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD CanDropLink(nsIDOMDragEvent *aEvent, PRBool aAllowSameDocument, PRBool *_retval NS_OUTPARAM) { return _to CanDropLink(aEvent, aAllowSameDocument, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DropLink(nsIDOMDragEvent *aEvent, nsAString & aName NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) { return _to DropLink(aEvent, aName, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDROPPEDLINKHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD CanDropLink(nsIDOMDragEvent *aEvent, PRBool aAllowSameDocument, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanDropLink(aEvent, aAllowSameDocument, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DropLink(nsIDOMDragEvent *aEvent, nsAString & aName NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->DropLink(aEvent, aName, _retval); } 

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

/* boolean canDropLink (in nsIDOMDragEvent aEvent, in PRBool aAllowSameDocument); */
NS_IMETHODIMP nsDroppedLinkHandler::CanDropLink(nsIDOMDragEvent *aEvent, PRBool aAllowSameDocument, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString dropLink (in nsIDOMDragEvent aEvent, out AString aName); */
NS_IMETHODIMP nsDroppedLinkHandler::DropLink(nsIDOMDragEvent *aEvent, nsAString & aName NS_OUTPARAM, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDroppedLinkHandler_h__ */

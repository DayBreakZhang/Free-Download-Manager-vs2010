/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIContextMenuListener.idl
 */

#ifndef __gen_nsIContextMenuListener_h__
#define __gen_nsIContextMenuListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMEvent; /* forward declaration */

class nsIDOMNode; /* forward declaration */


/* starting interface:    nsIContextMenuListener */
#define NS_ICONTEXTMENULISTENER_IID_STR "3478b6b0-3875-11d4-94ef-0020183bf181"

#define NS_ICONTEXTMENULISTENER_IID \
  {0x3478b6b0, 0x3875, 0x11d4, \
    { 0x94, 0xef, 0x00, 0x20, 0x18, 0x3b, 0xf1, 0x81 }}

class NS_NO_VTABLE nsIContextMenuListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTEXTMENULISTENER_IID)

  enum {
    CONTEXT_NONE = 0U,
    CONTEXT_LINK = 1U,
    CONTEXT_IMAGE = 2U,
    CONTEXT_DOCUMENT = 4U,
    CONTEXT_TEXT = 8U,
    CONTEXT_INPUT = 16U
  };

  /* void onShowContextMenu (in unsigned long aContextFlags, in nsIDOMEvent aEvent, in nsIDOMNode aNode); */
  NS_IMETHOD OnShowContextMenu(uint32_t aContextFlags, nsIDOMEvent *aEvent, nsIDOMNode *aNode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContextMenuListener, NS_ICONTEXTMENULISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTEXTMENULISTENER \
  NS_IMETHOD OnShowContextMenu(uint32_t aContextFlags, nsIDOMEvent *aEvent, nsIDOMNode *aNode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTEXTMENULISTENER(_to) \
  NS_IMETHOD OnShowContextMenu(uint32_t aContextFlags, nsIDOMEvent *aEvent, nsIDOMNode *aNode) { return _to OnShowContextMenu(aContextFlags, aEvent, aNode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTEXTMENULISTENER(_to) \
  NS_IMETHOD OnShowContextMenu(uint32_t aContextFlags, nsIDOMEvent *aEvent, nsIDOMNode *aNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnShowContextMenu(aContextFlags, aEvent, aNode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContextMenuListener : public nsIContextMenuListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTEXTMENULISTENER

  nsContextMenuListener();

private:
  ~nsContextMenuListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContextMenuListener, nsIContextMenuListener)

nsContextMenuListener::nsContextMenuListener()
{
  /* member initializers and constructor code */
}

nsContextMenuListener::~nsContextMenuListener()
{
  /* destructor code */
}

/* void onShowContextMenu (in unsigned long aContextFlags, in nsIDOMEvent aEvent, in nsIDOMNode aNode); */
NS_IMETHODIMP nsContextMenuListener::OnShowContextMenu(uint32_t aContextFlags, nsIDOMEvent *aEvent, nsIDOMNode *aNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContextMenuListener_h__ */

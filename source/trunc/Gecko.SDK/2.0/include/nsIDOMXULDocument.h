/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/xul/nsIDOMXULDocument.idl
 */

#ifndef __gen_nsIDOMXULDocument_h__
#define __gen_nsIDOMXULDocument_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMXULCommandDispatcher; /* forward declaration */

class nsIObserver; /* forward declaration */

class nsIBoxObject; /* forward declaration */


/* starting interface:    nsIDOMXULDocument */
#define NS_IDOMXULDOCUMENT_IID_STR "b16d13c3-837d-445d-8f56-05d83d9b9eae"

#define NS_IDOMXULDOCUMENT_IID \
  {0xb16d13c3, 0x837d, 0x445d, \
    { 0x8f, 0x56, 0x05, 0xd8, 0x3d, 0x9b, 0x9e, 0xae }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXULDocument : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULDOCUMENT_IID)

  /* attribute nsIDOMNode popupNode; */
  NS_SCRIPTABLE NS_IMETHOD GetPopupNode(nsIDOMNode **aPopupNode) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPopupNode(nsIDOMNode *aPopupNode) = 0;

  /**
   * These attributes correspond to trustedGetPopupNode().rangeOffset and
   * rangeParent. They will help you find where in the DOM the popup is
   * happening. Can be accessed from chrome only, and only during a popup
   * event. Accessing any other time will be an error.
   */
  /* readonly attribute nsIDOMNode popupRangeParent; */
  NS_SCRIPTABLE NS_IMETHOD GetPopupRangeParent(nsIDOMNode **aPopupRangeParent) = 0;

  /* readonly attribute long popupRangeOffset; */
  NS_SCRIPTABLE NS_IMETHOD GetPopupRangeOffset(PRInt32 *aPopupRangeOffset) = 0;

  /* attribute nsIDOMNode tooltipNode; */
  NS_SCRIPTABLE NS_IMETHOD GetTooltipNode(nsIDOMNode **aTooltipNode) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTooltipNode(nsIDOMNode *aTooltipNode) = 0;

  /* readonly attribute nsIDOMXULCommandDispatcher commandDispatcher; */
  NS_SCRIPTABLE NS_IMETHOD GetCommandDispatcher(nsIDOMXULCommandDispatcher **aCommandDispatcher) = 0;

  /* readonly attribute long width; */
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) = 0;

  /* readonly attribute long height; */
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) = 0;

  /* nsIDOMNodeList getElementsByAttribute (in DOMString name, in DOMString value); */
  NS_SCRIPTABLE NS_IMETHOD GetElementsByAttribute(const nsAString & name, const nsAString & value, nsIDOMNodeList **_retval NS_OUTPARAM) = 0;

  /* nsIDOMNodeList getElementsByAttributeNS (in DOMString namespaceURI, in DOMString name, in DOMString value); */
  NS_SCRIPTABLE NS_IMETHOD GetElementsByAttributeNS(const nsAString & namespaceURI, const nsAString & name, const nsAString & value, nsIDOMNodeList **_retval NS_OUTPARAM) = 0;

  /* void addBroadcastListenerFor (in nsIDOMElement broadcaster, in nsIDOMElement observer, in DOMString attr); */
  NS_SCRIPTABLE NS_IMETHOD AddBroadcastListenerFor(nsIDOMElement *broadcaster, nsIDOMElement *observer, const nsAString & attr) = 0;

  /* void removeBroadcastListenerFor (in nsIDOMElement broadcaster, in nsIDOMElement observer, in DOMString attr); */
  NS_SCRIPTABLE NS_IMETHOD RemoveBroadcastListenerFor(nsIDOMElement *broadcaster, nsIDOMElement *observer, const nsAString & attr) = 0;

  /* void persist (in DOMString id, in DOMString attr); */
  NS_SCRIPTABLE NS_IMETHOD Persist(const nsAString & id, const nsAString & attr) = 0;

  /* nsIBoxObject getBoxObjectFor (in nsIDOMElement elt); */
  NS_SCRIPTABLE NS_IMETHOD GetBoxObjectFor(nsIDOMElement *elt, nsIBoxObject **_retval NS_OUTPARAM) = 0;

  /**
   * Loads a XUL overlay and merges it with the current document, notifying an
   * observer when the merge is complete. 
   * @param   url
   *          The URL of the overlay to load and merge
   * @param   observer
   *          An object implementing nsIObserver that will be notified with a
   *          message of topic "xul-overlay-merged" when the merge is complete. 
   *          The subject parameter of |observe| will QI to a nsIURI - the URI 
   *          of the merged overlay. This parameter is optional and may be null.
   *
   * NOTICE:  In the 2.0 timeframe this API will change such that the 
   *          implementation will fire a DOMXULOverlayMerged event upon merge
   *          completion rather than notifying an observer. Do not rely on this
   *          API's behavior _not_ to change because it will!
   *          - Ben Goodger (8/23/2005)
   */
  /* void loadOverlay (in DOMString url, in nsIObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD LoadOverlay(const nsAString & url, nsIObserver *aObserver) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULDocument, NS_IDOMXULDOCUMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULDOCUMENT \
  NS_SCRIPTABLE NS_IMETHOD GetPopupNode(nsIDOMNode **aPopupNode); \
  NS_SCRIPTABLE NS_IMETHOD SetPopupNode(nsIDOMNode *aPopupNode); \
  NS_SCRIPTABLE NS_IMETHOD GetPopupRangeParent(nsIDOMNode **aPopupRangeParent); \
  NS_SCRIPTABLE NS_IMETHOD GetPopupRangeOffset(PRInt32 *aPopupRangeOffset); \
  NS_SCRIPTABLE NS_IMETHOD GetTooltipNode(nsIDOMNode **aTooltipNode); \
  NS_SCRIPTABLE NS_IMETHOD SetTooltipNode(nsIDOMNode *aTooltipNode); \
  NS_SCRIPTABLE NS_IMETHOD GetCommandDispatcher(nsIDOMXULCommandDispatcher **aCommandDispatcher); \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight); \
  NS_SCRIPTABLE NS_IMETHOD GetElementsByAttribute(const nsAString & name, const nsAString & value, nsIDOMNodeList **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetElementsByAttributeNS(const nsAString & namespaceURI, const nsAString & name, const nsAString & value, nsIDOMNodeList **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddBroadcastListenerFor(nsIDOMElement *broadcaster, nsIDOMElement *observer, const nsAString & attr); \
  NS_SCRIPTABLE NS_IMETHOD RemoveBroadcastListenerFor(nsIDOMElement *broadcaster, nsIDOMElement *observer, const nsAString & attr); \
  NS_SCRIPTABLE NS_IMETHOD Persist(const nsAString & id, const nsAString & attr); \
  NS_SCRIPTABLE NS_IMETHOD GetBoxObjectFor(nsIDOMElement *elt, nsIBoxObject **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD LoadOverlay(const nsAString & url, nsIObserver *aObserver); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULDOCUMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPopupNode(nsIDOMNode **aPopupNode) { return _to GetPopupNode(aPopupNode); } \
  NS_SCRIPTABLE NS_IMETHOD SetPopupNode(nsIDOMNode *aPopupNode) { return _to SetPopupNode(aPopupNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetPopupRangeParent(nsIDOMNode **aPopupRangeParent) { return _to GetPopupRangeParent(aPopupRangeParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetPopupRangeOffset(PRInt32 *aPopupRangeOffset) { return _to GetPopupRangeOffset(aPopupRangeOffset); } \
  NS_SCRIPTABLE NS_IMETHOD GetTooltipNode(nsIDOMNode **aTooltipNode) { return _to GetTooltipNode(aTooltipNode); } \
  NS_SCRIPTABLE NS_IMETHOD SetTooltipNode(nsIDOMNode *aTooltipNode) { return _to SetTooltipNode(aTooltipNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetCommandDispatcher(nsIDOMXULCommandDispatcher **aCommandDispatcher) { return _to GetCommandDispatcher(aCommandDispatcher); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return _to GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) { return _to GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetElementsByAttribute(const nsAString & name, const nsAString & value, nsIDOMNodeList **_retval NS_OUTPARAM) { return _to GetElementsByAttribute(name, value, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetElementsByAttributeNS(const nsAString & namespaceURI, const nsAString & name, const nsAString & value, nsIDOMNodeList **_retval NS_OUTPARAM) { return _to GetElementsByAttributeNS(namespaceURI, name, value, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddBroadcastListenerFor(nsIDOMElement *broadcaster, nsIDOMElement *observer, const nsAString & attr) { return _to AddBroadcastListenerFor(broadcaster, observer, attr); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveBroadcastListenerFor(nsIDOMElement *broadcaster, nsIDOMElement *observer, const nsAString & attr) { return _to RemoveBroadcastListenerFor(broadcaster, observer, attr); } \
  NS_SCRIPTABLE NS_IMETHOD Persist(const nsAString & id, const nsAString & attr) { return _to Persist(id, attr); } \
  NS_SCRIPTABLE NS_IMETHOD GetBoxObjectFor(nsIDOMElement *elt, nsIBoxObject **_retval NS_OUTPARAM) { return _to GetBoxObjectFor(elt, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LoadOverlay(const nsAString & url, nsIObserver *aObserver) { return _to LoadOverlay(url, aObserver); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULDOCUMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPopupNode(nsIDOMNode **aPopupNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPopupNode(aPopupNode); } \
  NS_SCRIPTABLE NS_IMETHOD SetPopupNode(nsIDOMNode *aPopupNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPopupNode(aPopupNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetPopupRangeParent(nsIDOMNode **aPopupRangeParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPopupRangeParent(aPopupRangeParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetPopupRangeOffset(PRInt32 *aPopupRangeOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPopupRangeOffset(aPopupRangeOffset); } \
  NS_SCRIPTABLE NS_IMETHOD GetTooltipNode(nsIDOMNode **aTooltipNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTooltipNode(aTooltipNode); } \
  NS_SCRIPTABLE NS_IMETHOD SetTooltipNode(nsIDOMNode *aTooltipNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTooltipNode(aTooltipNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetCommandDispatcher(nsIDOMXULCommandDispatcher **aCommandDispatcher) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCommandDispatcher(aCommandDispatcher); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetElementsByAttribute(const nsAString & name, const nsAString & value, nsIDOMNodeList **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElementsByAttribute(name, value, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetElementsByAttributeNS(const nsAString & namespaceURI, const nsAString & name, const nsAString & value, nsIDOMNodeList **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElementsByAttributeNS(namespaceURI, name, value, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddBroadcastListenerFor(nsIDOMElement *broadcaster, nsIDOMElement *observer, const nsAString & attr) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddBroadcastListenerFor(broadcaster, observer, attr); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveBroadcastListenerFor(nsIDOMElement *broadcaster, nsIDOMElement *observer, const nsAString & attr) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveBroadcastListenerFor(broadcaster, observer, attr); } \
  NS_SCRIPTABLE NS_IMETHOD Persist(const nsAString & id, const nsAString & attr) { return !_to ? NS_ERROR_NULL_POINTER : _to->Persist(id, attr); } \
  NS_SCRIPTABLE NS_IMETHOD GetBoxObjectFor(nsIDOMElement *elt, nsIBoxObject **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBoxObjectFor(elt, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LoadOverlay(const nsAString & url, nsIObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadOverlay(url, aObserver); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULDocument : public nsIDOMXULDocument
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULDOCUMENT

  nsDOMXULDocument();

private:
  ~nsDOMXULDocument();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULDocument, nsIDOMXULDocument)

nsDOMXULDocument::nsDOMXULDocument()
{
  /* member initializers and constructor code */
}

nsDOMXULDocument::~nsDOMXULDocument()
{
  /* destructor code */
}

/* attribute nsIDOMNode popupNode; */
NS_IMETHODIMP nsDOMXULDocument::GetPopupNode(nsIDOMNode **aPopupNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULDocument::SetPopupNode(nsIDOMNode *aPopupNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode popupRangeParent; */
NS_IMETHODIMP nsDOMXULDocument::GetPopupRangeParent(nsIDOMNode **aPopupRangeParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long popupRangeOffset; */
NS_IMETHODIMP nsDOMXULDocument::GetPopupRangeOffset(PRInt32 *aPopupRangeOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMNode tooltipNode; */
NS_IMETHODIMP nsDOMXULDocument::GetTooltipNode(nsIDOMNode **aTooltipNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULDocument::SetTooltipNode(nsIDOMNode *aTooltipNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMXULCommandDispatcher commandDispatcher; */
NS_IMETHODIMP nsDOMXULDocument::GetCommandDispatcher(nsIDOMXULCommandDispatcher **aCommandDispatcher)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long width; */
NS_IMETHODIMP nsDOMXULDocument::GetWidth(PRInt32 *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long height; */
NS_IMETHODIMP nsDOMXULDocument::GetHeight(PRInt32 *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList getElementsByAttribute (in DOMString name, in DOMString value); */
NS_IMETHODIMP nsDOMXULDocument::GetElementsByAttribute(const nsAString & name, const nsAString & value, nsIDOMNodeList **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList getElementsByAttributeNS (in DOMString namespaceURI, in DOMString name, in DOMString value); */
NS_IMETHODIMP nsDOMXULDocument::GetElementsByAttributeNS(const nsAString & namespaceURI, const nsAString & name, const nsAString & value, nsIDOMNodeList **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addBroadcastListenerFor (in nsIDOMElement broadcaster, in nsIDOMElement observer, in DOMString attr); */
NS_IMETHODIMP nsDOMXULDocument::AddBroadcastListenerFor(nsIDOMElement *broadcaster, nsIDOMElement *observer, const nsAString & attr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeBroadcastListenerFor (in nsIDOMElement broadcaster, in nsIDOMElement observer, in DOMString attr); */
NS_IMETHODIMP nsDOMXULDocument::RemoveBroadcastListenerFor(nsIDOMElement *broadcaster, nsIDOMElement *observer, const nsAString & attr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void persist (in DOMString id, in DOMString attr); */
NS_IMETHODIMP nsDOMXULDocument::Persist(const nsAString & id, const nsAString & attr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIBoxObject getBoxObjectFor (in nsIDOMElement elt); */
NS_IMETHODIMP nsDOMXULDocument::GetBoxObjectFor(nsIDOMElement *elt, nsIBoxObject **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadOverlay (in DOMString url, in nsIObserver aObserver); */
NS_IMETHODIMP nsDOMXULDocument::LoadOverlay(const nsAString & url, nsIObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULDocument_h__ */

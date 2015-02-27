/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMElement.idl
 */

#ifndef __gen_nsIDOMElement_h__
#define __gen_nsIDOMElement_h__


#ifndef __gen_nsIDOMNode_h__
#include "nsIDOMNode.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMMozNamedAttrMap; /* forward declaration */


/* starting interface:    nsIDOMElement */
#define NS_IDOMELEMENT_IID_STR "989422ef-120d-4d29-8a56-6aa2505a8b02"

#define NS_IDOMELEMENT_IID \
  {0x989422ef, 0x120d, 0x4d29, \
    { 0x8a, 0x56, 0x6a, 0xa2, 0x50, 0x5a, 0x8b, 0x02 }}

class NS_NO_VTABLE nsIDOMElement : public nsIDOMNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMELEMENT_IID)

  /* readonly attribute DOMString tagName; */
  NS_IMETHOD GetTagName(nsAString & aTagName) = 0;

  /* readonly attribute nsISupports classList; */
  NS_IMETHOD GetClassList(nsISupports * *aClassList) = 0;

  /* readonly attribute nsIDOMMozNamedAttrMap attributes; */
  NS_IMETHOD GetAttributes(nsIDOMMozNamedAttrMap * *aAttributes) = 0;

  /* DOMString getAttribute (in DOMString name); */
  NS_IMETHOD GetAttribute(const nsAString & name, nsAString & _retval) = 0;

  /* DOMString getAttributeNS (in DOMString namespaceURI, in DOMString localName); */
  NS_IMETHOD GetAttributeNS(const nsAString & namespaceURI, const nsAString & localName, nsAString & _retval) = 0;

  /* void setAttribute (in DOMString name, in DOMString value); */
  NS_IMETHOD SetAttribute(const nsAString & name, const nsAString & value) = 0;

  /* void setAttributeNS (in DOMString namespaceURI, in DOMString qualifiedName, in DOMString value); */
  NS_IMETHOD SetAttributeNS(const nsAString & namespaceURI, const nsAString & qualifiedName, const nsAString & value) = 0;

  /* void removeAttribute (in DOMString name); */
  NS_IMETHOD RemoveAttribute(const nsAString & name) = 0;

  /* void removeAttributeNS (in DOMString namespaceURI, in DOMString localName); */
  NS_IMETHOD RemoveAttributeNS(const nsAString & namespaceURI, const nsAString & localName) = 0;

  /* boolean hasAttribute (in DOMString name); */
  NS_IMETHOD HasAttribute(const nsAString & name, bool *_retval) = 0;

  /* boolean hasAttributeNS (in DOMString namespaceURI, in DOMString localName); */
  NS_IMETHOD HasAttributeNS(const nsAString & namespaceURI, const nsAString & localName, bool *_retval) = 0;

  /* nsIDOMAttr getAttributeNode (in DOMString name); */
  NS_IMETHOD GetAttributeNode(const nsAString & name, nsIDOMAttr * *_retval) = 0;

  /* nsIDOMAttr setAttributeNode (in nsIDOMAttr newAttr); */
  NS_IMETHOD SetAttributeNode(nsIDOMAttr *newAttr, nsIDOMAttr * *_retval) = 0;

  /* nsIDOMAttr removeAttributeNode (in nsIDOMAttr oldAttr); */
  NS_IMETHOD RemoveAttributeNode(nsIDOMAttr *oldAttr, nsIDOMAttr * *_retval) = 0;

  /* nsIDOMAttr getAttributeNodeNS (in DOMString namespaceURI, in DOMString localName); */
  NS_IMETHOD GetAttributeNodeNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMAttr * *_retval) = 0;

  /* nsIDOMAttr setAttributeNodeNS (in nsIDOMAttr newAttr) raises (DOMException); */
  NS_IMETHOD SetAttributeNodeNS(nsIDOMAttr *newAttr, nsIDOMAttr * *_retval) = 0;

  /* nsIDOMHTMLCollection getElementsByTagName (in DOMString name); */
  NS_IMETHOD GetElementsByTagName(const nsAString & name, nsIDOMHTMLCollection * *_retval) = 0;

  /* nsIDOMHTMLCollection getElementsByTagNameNS (in DOMString namespaceURI, in DOMString localName); */
  NS_IMETHOD GetElementsByTagNameNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMHTMLCollection * *_retval) = 0;

  /* nsIDOMHTMLCollection getElementsByClassName (in DOMString classes); */
  NS_IMETHOD GetElementsByClassName(const nsAString & classes, nsIDOMHTMLCollection * *_retval) = 0;

  /* [binaryname(ChildElements)] readonly attribute nsIDOMNodeList children; */
  NS_IMETHOD GetChildElements(nsIDOMNodeList * *aChildren) = 0;

  /* readonly attribute nsIDOMElement firstElementChild; */
  NS_IMETHOD GetFirstElementChild(nsIDOMElement * *aFirstElementChild) = 0;

  /* readonly attribute nsIDOMElement lastElementChild; */
  NS_IMETHOD GetLastElementChild(nsIDOMElement * *aLastElementChild) = 0;

  /* readonly attribute nsIDOMElement previousElementSibling; */
  NS_IMETHOD GetPreviousElementSibling(nsIDOMElement * *aPreviousElementSibling) = 0;

  /* readonly attribute nsIDOMElement nextElementSibling; */
  NS_IMETHOD GetNextElementSibling(nsIDOMElement * *aNextElementSibling) = 0;

  /* readonly attribute unsigned long childElementCount; */
  NS_IMETHOD GetChildElementCount(uint32_t *aChildElementCount) = 0;

  /* [binaryname(MozRemove)] void remove (); */
  NS_IMETHOD MozRemove(void) = 0;

  /* nsIDOMClientRectList getClientRects (); */
  NS_IMETHOD GetClientRects(nsIDOMClientRectList * *_retval) = 0;

  /* nsIDOMClientRect getBoundingClientRect (); */
  NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect * *_retval) = 0;

  /* attribute long scrollTop; */
  NS_IMETHOD GetScrollTop(int32_t *aScrollTop) = 0;
  NS_IMETHOD SetScrollTop(int32_t aScrollTop) = 0;

  /* attribute long scrollLeft; */
  NS_IMETHOD GetScrollLeft(int32_t *aScrollLeft) = 0;
  NS_IMETHOD SetScrollLeft(int32_t aScrollLeft) = 0;

  /* readonly attribute long scrollWidth; */
  NS_IMETHOD GetScrollWidth(int32_t *aScrollWidth) = 0;

  /* readonly attribute long scrollHeight; */
  NS_IMETHOD GetScrollHeight(int32_t *aScrollHeight) = 0;

  /* readonly attribute long clientTop; */
  NS_IMETHOD GetClientTop(int32_t *aClientTop) = 0;

  /* readonly attribute long clientLeft; */
  NS_IMETHOD GetClientLeft(int32_t *aClientLeft) = 0;

  /* readonly attribute long clientWidth; */
  NS_IMETHOD GetClientWidth(int32_t *aClientWidth) = 0;

  /* readonly attribute long clientHeight; */
  NS_IMETHOD GetClientHeight(int32_t *aClientHeight) = 0;

  /* readonly attribute long scrollLeftMax; */
  NS_IMETHOD GetScrollLeftMax(int32_t *aScrollLeftMax) = 0;

  /* readonly attribute long scrollTopMax; */
  NS_IMETHOD GetScrollTopMax(int32_t *aScrollTopMax) = 0;

  /* boolean mozMatchesSelector ([Null (Stringify)] in DOMString selector); */
  NS_IMETHOD MozMatchesSelector(const nsAString & selector, bool *_retval) = 0;

  /* void setCapture ([optional] in boolean retargetToElement); */
  NS_IMETHOD SetCapture(bool retargetToElement) = 0;

  /* void releaseCapture (); */
  NS_IMETHOD ReleaseCapture(void) = 0;

  /* void mozRequestFullScreen (); */
  NS_IMETHOD MozRequestFullScreen(void) = 0;

  /* void mozRequestPointerLock (); */
  NS_IMETHOD MozRequestPointerLock(void) = 0;

  /* nsIDOMElement querySelector ([Null (Stringify)] in DOMString selectors); */
  NS_IMETHOD QuerySelector(const nsAString & selectors, nsIDOMElement * *_retval) = 0;

  /* nsIDOMNodeList querySelectorAll ([Null (Stringify)] in DOMString selectors); */
  NS_IMETHOD QuerySelectorAll(const nsAString & selectors, nsIDOMNodeList * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMElement, NS_IDOMELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMELEMENT \
  NS_IMETHOD GetTagName(nsAString & aTagName); \
  NS_IMETHOD GetClassList(nsISupports * *aClassList); \
  NS_IMETHOD GetAttributes(nsIDOMMozNamedAttrMap * *aAttributes); \
  NS_IMETHOD GetAttribute(const nsAString & name, nsAString & _retval); \
  NS_IMETHOD GetAttributeNS(const nsAString & namespaceURI, const nsAString & localName, nsAString & _retval); \
  NS_IMETHOD SetAttribute(const nsAString & name, const nsAString & value); \
  NS_IMETHOD SetAttributeNS(const nsAString & namespaceURI, const nsAString & qualifiedName, const nsAString & value); \
  NS_IMETHOD RemoveAttribute(const nsAString & name); \
  NS_IMETHOD RemoveAttributeNS(const nsAString & namespaceURI, const nsAString & localName); \
  NS_IMETHOD HasAttribute(const nsAString & name, bool *_retval); \
  NS_IMETHOD HasAttributeNS(const nsAString & namespaceURI, const nsAString & localName, bool *_retval); \
  NS_IMETHOD GetAttributeNode(const nsAString & name, nsIDOMAttr * *_retval); \
  NS_IMETHOD SetAttributeNode(nsIDOMAttr *newAttr, nsIDOMAttr * *_retval); \
  NS_IMETHOD RemoveAttributeNode(nsIDOMAttr *oldAttr, nsIDOMAttr * *_retval); \
  NS_IMETHOD GetAttributeNodeNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMAttr * *_retval); \
  NS_IMETHOD SetAttributeNodeNS(nsIDOMAttr *newAttr, nsIDOMAttr * *_retval); \
  NS_IMETHOD GetElementsByTagName(const nsAString & name, nsIDOMHTMLCollection * *_retval); \
  NS_IMETHOD GetElementsByTagNameNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMHTMLCollection * *_retval); \
  NS_IMETHOD GetElementsByClassName(const nsAString & classes, nsIDOMHTMLCollection * *_retval); \
  NS_IMETHOD GetChildElements(nsIDOMNodeList * *aChildren); \
  NS_IMETHOD GetFirstElementChild(nsIDOMElement * *aFirstElementChild); \
  NS_IMETHOD GetLastElementChild(nsIDOMElement * *aLastElementChild); \
  NS_IMETHOD GetPreviousElementSibling(nsIDOMElement * *aPreviousElementSibling); \
  NS_IMETHOD GetNextElementSibling(nsIDOMElement * *aNextElementSibling); \
  NS_IMETHOD GetChildElementCount(uint32_t *aChildElementCount); \
  NS_IMETHOD MozRemove(void); \
  NS_IMETHOD GetClientRects(nsIDOMClientRectList * *_retval); \
  NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect * *_retval); \
  NS_IMETHOD GetScrollTop(int32_t *aScrollTop); \
  NS_IMETHOD SetScrollTop(int32_t aScrollTop); \
  NS_IMETHOD GetScrollLeft(int32_t *aScrollLeft); \
  NS_IMETHOD SetScrollLeft(int32_t aScrollLeft); \
  NS_IMETHOD GetScrollWidth(int32_t *aScrollWidth); \
  NS_IMETHOD GetScrollHeight(int32_t *aScrollHeight); \
  NS_IMETHOD GetClientTop(int32_t *aClientTop); \
  NS_IMETHOD GetClientLeft(int32_t *aClientLeft); \
  NS_IMETHOD GetClientWidth(int32_t *aClientWidth); \
  NS_IMETHOD GetClientHeight(int32_t *aClientHeight); \
  NS_IMETHOD GetScrollLeftMax(int32_t *aScrollLeftMax); \
  NS_IMETHOD GetScrollTopMax(int32_t *aScrollTopMax); \
  NS_IMETHOD MozMatchesSelector(const nsAString & selector, bool *_retval); \
  NS_IMETHOD SetCapture(bool retargetToElement); \
  NS_IMETHOD ReleaseCapture(void); \
  NS_IMETHOD MozRequestFullScreen(void); \
  NS_IMETHOD MozRequestPointerLock(void); \
  NS_IMETHOD QuerySelector(const nsAString & selectors, nsIDOMElement * *_retval); \
  NS_IMETHOD QuerySelectorAll(const nsAString & selectors, nsIDOMNodeList * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMELEMENT(_to) \
  NS_IMETHOD GetTagName(nsAString & aTagName) { return _to GetTagName(aTagName); } \
  NS_IMETHOD GetClassList(nsISupports * *aClassList) { return _to GetClassList(aClassList); } \
  NS_IMETHOD GetAttributes(nsIDOMMozNamedAttrMap * *aAttributes) { return _to GetAttributes(aAttributes); } \
  NS_IMETHOD GetAttribute(const nsAString & name, nsAString & _retval) { return _to GetAttribute(name, _retval); } \
  NS_IMETHOD GetAttributeNS(const nsAString & namespaceURI, const nsAString & localName, nsAString & _retval) { return _to GetAttributeNS(namespaceURI, localName, _retval); } \
  NS_IMETHOD SetAttribute(const nsAString & name, const nsAString & value) { return _to SetAttribute(name, value); } \
  NS_IMETHOD SetAttributeNS(const nsAString & namespaceURI, const nsAString & qualifiedName, const nsAString & value) { return _to SetAttributeNS(namespaceURI, qualifiedName, value); } \
  NS_IMETHOD RemoveAttribute(const nsAString & name) { return _to RemoveAttribute(name); } \
  NS_IMETHOD RemoveAttributeNS(const nsAString & namespaceURI, const nsAString & localName) { return _to RemoveAttributeNS(namespaceURI, localName); } \
  NS_IMETHOD HasAttribute(const nsAString & name, bool *_retval) { return _to HasAttribute(name, _retval); } \
  NS_IMETHOD HasAttributeNS(const nsAString & namespaceURI, const nsAString & localName, bool *_retval) { return _to HasAttributeNS(namespaceURI, localName, _retval); } \
  NS_IMETHOD GetAttributeNode(const nsAString & name, nsIDOMAttr * *_retval) { return _to GetAttributeNode(name, _retval); } \
  NS_IMETHOD SetAttributeNode(nsIDOMAttr *newAttr, nsIDOMAttr * *_retval) { return _to SetAttributeNode(newAttr, _retval); } \
  NS_IMETHOD RemoveAttributeNode(nsIDOMAttr *oldAttr, nsIDOMAttr * *_retval) { return _to RemoveAttributeNode(oldAttr, _retval); } \
  NS_IMETHOD GetAttributeNodeNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMAttr * *_retval) { return _to GetAttributeNodeNS(namespaceURI, localName, _retval); } \
  NS_IMETHOD SetAttributeNodeNS(nsIDOMAttr *newAttr, nsIDOMAttr * *_retval) { return _to SetAttributeNodeNS(newAttr, _retval); } \
  NS_IMETHOD GetElementsByTagName(const nsAString & name, nsIDOMHTMLCollection * *_retval) { return _to GetElementsByTagName(name, _retval); } \
  NS_IMETHOD GetElementsByTagNameNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMHTMLCollection * *_retval) { return _to GetElementsByTagNameNS(namespaceURI, localName, _retval); } \
  NS_IMETHOD GetElementsByClassName(const nsAString & classes, nsIDOMHTMLCollection * *_retval) { return _to GetElementsByClassName(classes, _retval); } \
  NS_IMETHOD GetChildElements(nsIDOMNodeList * *aChildren) { return _to GetChildElements(aChildren); } \
  NS_IMETHOD GetFirstElementChild(nsIDOMElement * *aFirstElementChild) { return _to GetFirstElementChild(aFirstElementChild); } \
  NS_IMETHOD GetLastElementChild(nsIDOMElement * *aLastElementChild) { return _to GetLastElementChild(aLastElementChild); } \
  NS_IMETHOD GetPreviousElementSibling(nsIDOMElement * *aPreviousElementSibling) { return _to GetPreviousElementSibling(aPreviousElementSibling); } \
  NS_IMETHOD GetNextElementSibling(nsIDOMElement * *aNextElementSibling) { return _to GetNextElementSibling(aNextElementSibling); } \
  NS_IMETHOD GetChildElementCount(uint32_t *aChildElementCount) { return _to GetChildElementCount(aChildElementCount); } \
  NS_IMETHOD MozRemove(void) { return _to MozRemove(); } \
  NS_IMETHOD GetClientRects(nsIDOMClientRectList * *_retval) { return _to GetClientRects(_retval); } \
  NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect * *_retval) { return _to GetBoundingClientRect(_retval); } \
  NS_IMETHOD GetScrollTop(int32_t *aScrollTop) { return _to GetScrollTop(aScrollTop); } \
  NS_IMETHOD SetScrollTop(int32_t aScrollTop) { return _to SetScrollTop(aScrollTop); } \
  NS_IMETHOD GetScrollLeft(int32_t *aScrollLeft) { return _to GetScrollLeft(aScrollLeft); } \
  NS_IMETHOD SetScrollLeft(int32_t aScrollLeft) { return _to SetScrollLeft(aScrollLeft); } \
  NS_IMETHOD GetScrollWidth(int32_t *aScrollWidth) { return _to GetScrollWidth(aScrollWidth); } \
  NS_IMETHOD GetScrollHeight(int32_t *aScrollHeight) { return _to GetScrollHeight(aScrollHeight); } \
  NS_IMETHOD GetClientTop(int32_t *aClientTop) { return _to GetClientTop(aClientTop); } \
  NS_IMETHOD GetClientLeft(int32_t *aClientLeft) { return _to GetClientLeft(aClientLeft); } \
  NS_IMETHOD GetClientWidth(int32_t *aClientWidth) { return _to GetClientWidth(aClientWidth); } \
  NS_IMETHOD GetClientHeight(int32_t *aClientHeight) { return _to GetClientHeight(aClientHeight); } \
  NS_IMETHOD GetScrollLeftMax(int32_t *aScrollLeftMax) { return _to GetScrollLeftMax(aScrollLeftMax); } \
  NS_IMETHOD GetScrollTopMax(int32_t *aScrollTopMax) { return _to GetScrollTopMax(aScrollTopMax); } \
  NS_IMETHOD MozMatchesSelector(const nsAString & selector, bool *_retval) { return _to MozMatchesSelector(selector, _retval); } \
  NS_IMETHOD SetCapture(bool retargetToElement) { return _to SetCapture(retargetToElement); } \
  NS_IMETHOD ReleaseCapture(void) { return _to ReleaseCapture(); } \
  NS_IMETHOD MozRequestFullScreen(void) { return _to MozRequestFullScreen(); } \
  NS_IMETHOD MozRequestPointerLock(void) { return _to MozRequestPointerLock(); } \
  NS_IMETHOD QuerySelector(const nsAString & selectors, nsIDOMElement * *_retval) { return _to QuerySelector(selectors, _retval); } \
  NS_IMETHOD QuerySelectorAll(const nsAString & selectors, nsIDOMNodeList * *_retval) { return _to QuerySelectorAll(selectors, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMELEMENT(_to) \
  NS_IMETHOD GetTagName(nsAString & aTagName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTagName(aTagName); } \
  NS_IMETHOD GetClassList(nsISupports * *aClassList) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClassList(aClassList); } \
  NS_IMETHOD GetAttributes(nsIDOMMozNamedAttrMap * *aAttributes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttributes(aAttributes); } \
  NS_IMETHOD GetAttribute(const nsAString & name, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttribute(name, _retval); } \
  NS_IMETHOD GetAttributeNS(const nsAString & namespaceURI, const nsAString & localName, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttributeNS(namespaceURI, localName, _retval); } \
  NS_IMETHOD SetAttribute(const nsAString & name, const nsAString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAttribute(name, value); } \
  NS_IMETHOD SetAttributeNS(const nsAString & namespaceURI, const nsAString & qualifiedName, const nsAString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAttributeNS(namespaceURI, qualifiedName, value); } \
  NS_IMETHOD RemoveAttribute(const nsAString & name) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAttribute(name); } \
  NS_IMETHOD RemoveAttributeNS(const nsAString & namespaceURI, const nsAString & localName) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAttributeNS(namespaceURI, localName); } \
  NS_IMETHOD HasAttribute(const nsAString & name, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasAttribute(name, _retval); } \
  NS_IMETHOD HasAttributeNS(const nsAString & namespaceURI, const nsAString & localName, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasAttributeNS(namespaceURI, localName, _retval); } \
  NS_IMETHOD GetAttributeNode(const nsAString & name, nsIDOMAttr * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttributeNode(name, _retval); } \
  NS_IMETHOD SetAttributeNode(nsIDOMAttr *newAttr, nsIDOMAttr * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAttributeNode(newAttr, _retval); } \
  NS_IMETHOD RemoveAttributeNode(nsIDOMAttr *oldAttr, nsIDOMAttr * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAttributeNode(oldAttr, _retval); } \
  NS_IMETHOD GetAttributeNodeNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMAttr * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttributeNodeNS(namespaceURI, localName, _retval); } \
  NS_IMETHOD SetAttributeNodeNS(nsIDOMAttr *newAttr, nsIDOMAttr * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAttributeNodeNS(newAttr, _retval); } \
  NS_IMETHOD GetElementsByTagName(const nsAString & name, nsIDOMHTMLCollection * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElementsByTagName(name, _retval); } \
  NS_IMETHOD GetElementsByTagNameNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMHTMLCollection * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElementsByTagNameNS(namespaceURI, localName, _retval); } \
  NS_IMETHOD GetElementsByClassName(const nsAString & classes, nsIDOMHTMLCollection * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElementsByClassName(classes, _retval); } \
  NS_IMETHOD GetChildElements(nsIDOMNodeList * *aChildren) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildElements(aChildren); } \
  NS_IMETHOD GetFirstElementChild(nsIDOMElement * *aFirstElementChild) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFirstElementChild(aFirstElementChild); } \
  NS_IMETHOD GetLastElementChild(nsIDOMElement * *aLastElementChild) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastElementChild(aLastElementChild); } \
  NS_IMETHOD GetPreviousElementSibling(nsIDOMElement * *aPreviousElementSibling) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreviousElementSibling(aPreviousElementSibling); } \
  NS_IMETHOD GetNextElementSibling(nsIDOMElement * *aNextElementSibling) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNextElementSibling(aNextElementSibling); } \
  NS_IMETHOD GetChildElementCount(uint32_t *aChildElementCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildElementCount(aChildElementCount); } \
  NS_IMETHOD MozRemove(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozRemove(); } \
  NS_IMETHOD GetClientRects(nsIDOMClientRectList * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientRects(_retval); } \
  NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBoundingClientRect(_retval); } \
  NS_IMETHOD GetScrollTop(int32_t *aScrollTop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollTop(aScrollTop); } \
  NS_IMETHOD SetScrollTop(int32_t aScrollTop) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScrollTop(aScrollTop); } \
  NS_IMETHOD GetScrollLeft(int32_t *aScrollLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollLeft(aScrollLeft); } \
  NS_IMETHOD SetScrollLeft(int32_t aScrollLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScrollLeft(aScrollLeft); } \
  NS_IMETHOD GetScrollWidth(int32_t *aScrollWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollWidth(aScrollWidth); } \
  NS_IMETHOD GetScrollHeight(int32_t *aScrollHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollHeight(aScrollHeight); } \
  NS_IMETHOD GetClientTop(int32_t *aClientTop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientTop(aClientTop); } \
  NS_IMETHOD GetClientLeft(int32_t *aClientLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientLeft(aClientLeft); } \
  NS_IMETHOD GetClientWidth(int32_t *aClientWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientWidth(aClientWidth); } \
  NS_IMETHOD GetClientHeight(int32_t *aClientHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientHeight(aClientHeight); } \
  NS_IMETHOD GetScrollLeftMax(int32_t *aScrollLeftMax) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollLeftMax(aScrollLeftMax); } \
  NS_IMETHOD GetScrollTopMax(int32_t *aScrollTopMax) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollTopMax(aScrollTopMax); } \
  NS_IMETHOD MozMatchesSelector(const nsAString & selector, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozMatchesSelector(selector, _retval); } \
  NS_IMETHOD SetCapture(bool retargetToElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCapture(retargetToElement); } \
  NS_IMETHOD ReleaseCapture(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReleaseCapture(); } \
  NS_IMETHOD MozRequestFullScreen(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozRequestFullScreen(); } \
  NS_IMETHOD MozRequestPointerLock(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozRequestPointerLock(); } \
  NS_IMETHOD QuerySelector(const nsAString & selectors, nsIDOMElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->QuerySelector(selectors, _retval); } \
  NS_IMETHOD QuerySelectorAll(const nsAString & selectors, nsIDOMNodeList * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->QuerySelectorAll(selectors, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMElement : public nsIDOMElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMELEMENT

  nsDOMElement();

private:
  ~nsDOMElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMElement, nsIDOMElement)

nsDOMElement::nsDOMElement()
{
  /* member initializers and constructor code */
}

nsDOMElement::~nsDOMElement()
{
  /* destructor code */
}

/* readonly attribute DOMString tagName; */
NS_IMETHODIMP nsDOMElement::GetTagName(nsAString & aTagName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports classList; */
NS_IMETHODIMP nsDOMElement::GetClassList(nsISupports * *aClassList)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMMozNamedAttrMap attributes; */
NS_IMETHODIMP nsDOMElement::GetAttributes(nsIDOMMozNamedAttrMap * *aAttributes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getAttribute (in DOMString name); */
NS_IMETHODIMP nsDOMElement::GetAttribute(const nsAString & name, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getAttributeNS (in DOMString namespaceURI, in DOMString localName); */
NS_IMETHODIMP nsDOMElement::GetAttributeNS(const nsAString & namespaceURI, const nsAString & localName, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAttribute (in DOMString name, in DOMString value); */
NS_IMETHODIMP nsDOMElement::SetAttribute(const nsAString & name, const nsAString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAttributeNS (in DOMString namespaceURI, in DOMString qualifiedName, in DOMString value); */
NS_IMETHODIMP nsDOMElement::SetAttributeNS(const nsAString & namespaceURI, const nsAString & qualifiedName, const nsAString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAttribute (in DOMString name); */
NS_IMETHODIMP nsDOMElement::RemoveAttribute(const nsAString & name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAttributeNS (in DOMString namespaceURI, in DOMString localName); */
NS_IMETHODIMP nsDOMElement::RemoveAttributeNS(const nsAString & namespaceURI, const nsAString & localName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasAttribute (in DOMString name); */
NS_IMETHODIMP nsDOMElement::HasAttribute(const nsAString & name, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasAttributeNS (in DOMString namespaceURI, in DOMString localName); */
NS_IMETHODIMP nsDOMElement::HasAttributeNS(const nsAString & namespaceURI, const nsAString & localName, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMAttr getAttributeNode (in DOMString name); */
NS_IMETHODIMP nsDOMElement::GetAttributeNode(const nsAString & name, nsIDOMAttr * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMAttr setAttributeNode (in nsIDOMAttr newAttr); */
NS_IMETHODIMP nsDOMElement::SetAttributeNode(nsIDOMAttr *newAttr, nsIDOMAttr * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMAttr removeAttributeNode (in nsIDOMAttr oldAttr); */
NS_IMETHODIMP nsDOMElement::RemoveAttributeNode(nsIDOMAttr *oldAttr, nsIDOMAttr * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMAttr getAttributeNodeNS (in DOMString namespaceURI, in DOMString localName); */
NS_IMETHODIMP nsDOMElement::GetAttributeNodeNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMAttr * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMAttr setAttributeNodeNS (in nsIDOMAttr newAttr) raises (DOMException); */
NS_IMETHODIMP nsDOMElement::SetAttributeNodeNS(nsIDOMAttr *newAttr, nsIDOMAttr * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMHTMLCollection getElementsByTagName (in DOMString name); */
NS_IMETHODIMP nsDOMElement::GetElementsByTagName(const nsAString & name, nsIDOMHTMLCollection * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMHTMLCollection getElementsByTagNameNS (in DOMString namespaceURI, in DOMString localName); */
NS_IMETHODIMP nsDOMElement::GetElementsByTagNameNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMHTMLCollection * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMHTMLCollection getElementsByClassName (in DOMString classes); */
NS_IMETHODIMP nsDOMElement::GetElementsByClassName(const nsAString & classes, nsIDOMHTMLCollection * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(ChildElements)] readonly attribute nsIDOMNodeList children; */
NS_IMETHODIMP nsDOMElement::GetChildElements(nsIDOMNodeList * *aChildren)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement firstElementChild; */
NS_IMETHODIMP nsDOMElement::GetFirstElementChild(nsIDOMElement * *aFirstElementChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement lastElementChild; */
NS_IMETHODIMP nsDOMElement::GetLastElementChild(nsIDOMElement * *aLastElementChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement previousElementSibling; */
NS_IMETHODIMP nsDOMElement::GetPreviousElementSibling(nsIDOMElement * *aPreviousElementSibling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement nextElementSibling; */
NS_IMETHODIMP nsDOMElement::GetNextElementSibling(nsIDOMElement * *aNextElementSibling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long childElementCount; */
NS_IMETHODIMP nsDOMElement::GetChildElementCount(uint32_t *aChildElementCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(MozRemove)] void remove (); */
NS_IMETHODIMP nsDOMElement::MozRemove()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMClientRectList getClientRects (); */
NS_IMETHODIMP nsDOMElement::GetClientRects(nsIDOMClientRectList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMClientRect getBoundingClientRect (); */
NS_IMETHODIMP nsDOMElement::GetBoundingClientRect(nsIDOMClientRect * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long scrollTop; */
NS_IMETHODIMP nsDOMElement::GetScrollTop(int32_t *aScrollTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMElement::SetScrollTop(int32_t aScrollTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long scrollLeft; */
NS_IMETHODIMP nsDOMElement::GetScrollLeft(int32_t *aScrollLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMElement::SetScrollLeft(int32_t aScrollLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long scrollWidth; */
NS_IMETHODIMP nsDOMElement::GetScrollWidth(int32_t *aScrollWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long scrollHeight; */
NS_IMETHODIMP nsDOMElement::GetScrollHeight(int32_t *aScrollHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long clientTop; */
NS_IMETHODIMP nsDOMElement::GetClientTop(int32_t *aClientTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long clientLeft; */
NS_IMETHODIMP nsDOMElement::GetClientLeft(int32_t *aClientLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long clientWidth; */
NS_IMETHODIMP nsDOMElement::GetClientWidth(int32_t *aClientWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long clientHeight; */
NS_IMETHODIMP nsDOMElement::GetClientHeight(int32_t *aClientHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long scrollLeftMax; */
NS_IMETHODIMP nsDOMElement::GetScrollLeftMax(int32_t *aScrollLeftMax)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long scrollTopMax; */
NS_IMETHODIMP nsDOMElement::GetScrollTopMax(int32_t *aScrollTopMax)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean mozMatchesSelector ([Null (Stringify)] in DOMString selector); */
NS_IMETHODIMP nsDOMElement::MozMatchesSelector(const nsAString & selector, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCapture ([optional] in boolean retargetToElement); */
NS_IMETHODIMP nsDOMElement::SetCapture(bool retargetToElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void releaseCapture (); */
NS_IMETHODIMP nsDOMElement::ReleaseCapture()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozRequestFullScreen (); */
NS_IMETHODIMP nsDOMElement::MozRequestFullScreen()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozRequestPointerLock (); */
NS_IMETHODIMP nsDOMElement::MozRequestPointerLock()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement querySelector ([Null (Stringify)] in DOMString selectors); */
NS_IMETHODIMP nsDOMElement::QuerySelector(const nsAString & selectors, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList querySelectorAll ([Null (Stringify)] in DOMString selectors); */
NS_IMETHODIMP nsDOMElement::QuerySelectorAll(const nsAString & selectors, nsIDOMNodeList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMElement_h__ */

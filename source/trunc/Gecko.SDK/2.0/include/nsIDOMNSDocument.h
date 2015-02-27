/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/core/nsIDOMNSDocument.idl
 */

#ifndef __gen_nsIDOMNSDocument_h__
#define __gen_nsIDOMNSDocument_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIBoxObject; /* forward declaration */

class nsIDOMLocation; /* forward declaration */

class nsIVariant; /* forward declaration */


/* starting interface:    nsIDOMNSDocument */
#define NS_IDOMNSDOCUMENT_IID_STR "92f2c6f8-3668-4a47-8251-2a900afe11fa"

#define NS_IDOMNSDOCUMENT_IID \
  {0x92f2c6f8, 0x3668, 0x4a47, \
    { 0x82, 0x51, 0x2a, 0x90, 0x0a, 0xfe, 0x11, 0xfa }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSDocument : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSDOCUMENT_IID)

  /* readonly attribute DOMString characterSet; */
  NS_SCRIPTABLE NS_IMETHOD GetCharacterSet(nsAString & aCharacterSet) = 0;

  /* attribute DOMString dir; */
  NS_SCRIPTABLE NS_IMETHOD GetDir(nsAString & aDir) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDir(const nsAString & aDir) = 0;

  /* readonly attribute nsIDOMLocation location; */
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIDOMLocation **aLocation) = 0;

  /* attribute DOMString title; */
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle) = 0;

  /* readonly attribute DOMString contentType; */
  NS_SCRIPTABLE NS_IMETHOD GetContentType(nsAString & aContentType) = 0;

  /* readonly attribute DOMString readyState; */
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(nsAString & aReadyState) = 0;

  /* readonly attribute DOMString lastModified; */
  NS_SCRIPTABLE NS_IMETHOD GetLastModified(nsAString & aLastModified) = 0;

  /* readonly attribute DOMString referrer; */
  NS_SCRIPTABLE NS_IMETHOD GetReferrer(nsAString & aReferrer) = 0;

  /* boolean hasFocus (); */
  NS_SCRIPTABLE NS_IMETHOD HasFocus(PRBool *_retval NS_OUTPARAM) = 0;

  /* readonly attribute nsIDOMElement activeElement; */
  NS_SCRIPTABLE NS_IMETHOD GetActiveElement(nsIDOMElement **aActiveElement) = 0;

  /* readonly attribute nsIDOMElement currentScript; */
  NS_SCRIPTABLE NS_IMETHOD GetCurrentScript(nsIDOMElement **aCurrentScript) = 0;

  /* nsIDOMNodeList getElementsByClassName (in DOMString classes); */
  NS_SCRIPTABLE NS_IMETHOD GetElementsByClassName(const nsAString & classes, nsIDOMNodeList **_retval NS_OUTPARAM) = 0;

  /**
  * Returns the element from the caller's document at the given point,
  * relative to the upper-left-most point in the (possibly scrolled)
  * window or frame.
  *
  * If the element at the given point belongs to another document (such as
  * an iframe's subdocument), the element in the calling document's DOM
  * (e.g. the iframe) is returned. If the element at the given point is
  * anonymous or XBL generated content, such as a textbox's scrollbars, then
  * the first non-anonymous parent element (that is, the textbox) is returned.
  *
  * This method returns null if either coordinate is negative, or if the
  * specified point lies outside the visible bounds of the document.
  *
  * Callers from XUL documents should wait until the onload event has fired
  * before calling this method.
  *
  * See <http://www.w3.org/TR/cssom-view/#the-documentview-interface>
  */
  /* nsIDOMElement elementFromPoint (in float x, in float y); */
  NS_SCRIPTABLE NS_IMETHOD ElementFromPoint(float x, float y, nsIDOMElement **_retval NS_OUTPARAM) = 0;

  /**
   * Release the current mouse capture if it is on an element within this
   * document.
   */
  /* void releaseCapture (); */
  NS_SCRIPTABLE NS_IMETHOD ReleaseCapture(void) = 0;

  /**
   * Use the given DOM element as the source image of target |-moz-element()|.
   *
   * This function introduces a new special ID (called "image element ID"),
   * which is only used by |-moz-element()|, and associates it with the given
   * DOM element.  Image elements ID's have the higher precedence than general
   * HTML id's, so if |document.mozSetImageElement(<id>, <element>)| is called,
   * |-moz-element(#<id>)| uses |<element>| as the source image even if there
   * is another element with id attribute = |<id>|.  To unregister an image
   * element ID |<id>|, call |document.mozSetImageElement(<id>, null)|.
   *
   * Example:
   * <script>
   *   canvas = document.createElement("canvas");
   *   canvas.setAttribute("width", 100);
   *   canvas.setAttribute("height", 100);
   *   // draw to canvas
   *   document.mozSetImageElement("canvasbg", canvas);
   * </script>
   * <div style="background-image: -moz-element(#canvasbg);"></div>
   *
   * @param aImageElementId an image element ID to associate with
   * |aImageElement|
   * @param aImageElement a DOM element to be used as the source image of
   * |-moz-element(#aImageElementId)|. If this is null, the function will
   * unregister the image element ID |aImageElementId|.
   */
  /* void mozSetImageElement (in DOMString aImageElementId, in nsIDOMElement aImageElement); */
  NS_SCRIPTABLE NS_IMETHOD MozSetImageElement(const nsAString & aImageElementId, nsIDOMElement *aImageElement) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSDocument, NS_IDOMNSDOCUMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSDOCUMENT \
  NS_SCRIPTABLE NS_IMETHOD GetCharacterSet(nsAString & aCharacterSet); \
  NS_SCRIPTABLE NS_IMETHOD GetDir(nsAString & aDir); \
  NS_SCRIPTABLE NS_IMETHOD SetDir(const nsAString & aDir); \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIDOMLocation **aLocation); \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle); \
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle); \
  NS_SCRIPTABLE NS_IMETHOD GetContentType(nsAString & aContentType); \
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(nsAString & aReadyState); \
  NS_SCRIPTABLE NS_IMETHOD GetLastModified(nsAString & aLastModified); \
  NS_SCRIPTABLE NS_IMETHOD GetReferrer(nsAString & aReferrer); \
  NS_SCRIPTABLE NS_IMETHOD HasFocus(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetActiveElement(nsIDOMElement **aActiveElement); \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentScript(nsIDOMElement **aCurrentScript); \
  NS_SCRIPTABLE NS_IMETHOD GetElementsByClassName(const nsAString & classes, nsIDOMNodeList **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ElementFromPoint(float x, float y, nsIDOMElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ReleaseCapture(void); \
  NS_SCRIPTABLE NS_IMETHOD MozSetImageElement(const nsAString & aImageElementId, nsIDOMElement *aImageElement); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSDOCUMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCharacterSet(nsAString & aCharacterSet) { return _to GetCharacterSet(aCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD GetDir(nsAString & aDir) { return _to GetDir(aDir); } \
  NS_SCRIPTABLE NS_IMETHOD SetDir(const nsAString & aDir) { return _to SetDir(aDir); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIDOMLocation **aLocation) { return _to GetLocation(aLocation); } \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) { return _to GetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle) { return _to SetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentType(nsAString & aContentType) { return _to GetContentType(aContentType); } \
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(nsAString & aReadyState) { return _to GetReadyState(aReadyState); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastModified(nsAString & aLastModified) { return _to GetLastModified(aLastModified); } \
  NS_SCRIPTABLE NS_IMETHOD GetReferrer(nsAString & aReferrer) { return _to GetReferrer(aReferrer); } \
  NS_SCRIPTABLE NS_IMETHOD HasFocus(PRBool *_retval NS_OUTPARAM) { return _to HasFocus(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetActiveElement(nsIDOMElement **aActiveElement) { return _to GetActiveElement(aActiveElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentScript(nsIDOMElement **aCurrentScript) { return _to GetCurrentScript(aCurrentScript); } \
  NS_SCRIPTABLE NS_IMETHOD GetElementsByClassName(const nsAString & classes, nsIDOMNodeList **_retval NS_OUTPARAM) { return _to GetElementsByClassName(classes, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ElementFromPoint(float x, float y, nsIDOMElement **_retval NS_OUTPARAM) { return _to ElementFromPoint(x, y, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReleaseCapture(void) { return _to ReleaseCapture(); } \
  NS_SCRIPTABLE NS_IMETHOD MozSetImageElement(const nsAString & aImageElementId, nsIDOMElement *aImageElement) { return _to MozSetImageElement(aImageElementId, aImageElement); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSDOCUMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCharacterSet(nsAString & aCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharacterSet(aCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD GetDir(nsAString & aDir) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDir(aDir); } \
  NS_SCRIPTABLE NS_IMETHOD SetDir(const nsAString & aDir) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDir(aDir); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIDOMLocation **aLocation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocation(aLocation); } \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentType(nsAString & aContentType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentType(aContentType); } \
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(nsAString & aReadyState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReadyState(aReadyState); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastModified(nsAString & aLastModified) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastModified(aLastModified); } \
  NS_SCRIPTABLE NS_IMETHOD GetReferrer(nsAString & aReferrer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReferrer(aReferrer); } \
  NS_SCRIPTABLE NS_IMETHOD HasFocus(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasFocus(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetActiveElement(nsIDOMElement **aActiveElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActiveElement(aActiveElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentScript(nsIDOMElement **aCurrentScript) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentScript(aCurrentScript); } \
  NS_SCRIPTABLE NS_IMETHOD GetElementsByClassName(const nsAString & classes, nsIDOMNodeList **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElementsByClassName(classes, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ElementFromPoint(float x, float y, nsIDOMElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ElementFromPoint(x, y, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReleaseCapture(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReleaseCapture(); } \
  NS_SCRIPTABLE NS_IMETHOD MozSetImageElement(const nsAString & aImageElementId, nsIDOMElement *aImageElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozSetImageElement(aImageElementId, aImageElement); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSDocument : public nsIDOMNSDocument
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSDOCUMENT

  nsDOMNSDocument();

private:
  ~nsDOMNSDocument();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSDocument, nsIDOMNSDocument)

nsDOMNSDocument::nsDOMNSDocument()
{
  /* member initializers and constructor code */
}

nsDOMNSDocument::~nsDOMNSDocument()
{
  /* destructor code */
}

/* readonly attribute DOMString characterSet; */
NS_IMETHODIMP nsDOMNSDocument::GetCharacterSet(nsAString & aCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString dir; */
NS_IMETHODIMP nsDOMNSDocument::GetDir(nsAString & aDir)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSDocument::SetDir(const nsAString & aDir)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMLocation location; */
NS_IMETHODIMP nsDOMNSDocument::GetLocation(nsIDOMLocation **aLocation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString title; */
NS_IMETHODIMP nsDOMNSDocument::GetTitle(nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSDocument::SetTitle(const nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString contentType; */
NS_IMETHODIMP nsDOMNSDocument::GetContentType(nsAString & aContentType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString readyState; */
NS_IMETHODIMP nsDOMNSDocument::GetReadyState(nsAString & aReadyState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString lastModified; */
NS_IMETHODIMP nsDOMNSDocument::GetLastModified(nsAString & aLastModified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString referrer; */
NS_IMETHODIMP nsDOMNSDocument::GetReferrer(nsAString & aReferrer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasFocus (); */
NS_IMETHODIMP nsDOMNSDocument::HasFocus(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement activeElement; */
NS_IMETHODIMP nsDOMNSDocument::GetActiveElement(nsIDOMElement **aActiveElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement currentScript; */
NS_IMETHODIMP nsDOMNSDocument::GetCurrentScript(nsIDOMElement **aCurrentScript)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList getElementsByClassName (in DOMString classes); */
NS_IMETHODIMP nsDOMNSDocument::GetElementsByClassName(const nsAString & classes, nsIDOMNodeList **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement elementFromPoint (in float x, in float y); */
NS_IMETHODIMP nsDOMNSDocument::ElementFromPoint(float x, float y, nsIDOMElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void releaseCapture (); */
NS_IMETHODIMP nsDOMNSDocument::ReleaseCapture()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozSetImageElement (in DOMString aImageElementId, in nsIDOMElement aImageElement); */
NS_IMETHODIMP nsDOMNSDocument::MozSetImageElement(const nsAString & aImageElementId, nsIDOMElement *aImageElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMNSDocument_MOZILLA_2_0_BRANCH */
#define NS_IDOMNSDOCUMENT_MOZILLA_2_0_BRANCH_IID_STR "fee67aed-3b94-4136-ad7d-fb88ef23f45f"

#define NS_IDOMNSDOCUMENT_MOZILLA_2_0_BRANCH_IID \
  {0xfee67aed, 0x3b94, 0x4136, \
    { 0xad, 0x7d, 0xfb, 0x88, 0xef, 0x23, 0xf4, 0x5f }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSDocument_MOZILLA_2_0_BRANCH : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSDOCUMENT_MOZILLA_2_0_BRANCH_IID)

  /* readonly attribute nsIVariant mozCurrentStateObject; */
  NS_SCRIPTABLE NS_IMETHOD GetMozCurrentStateObject(nsIVariant **aMozCurrentStateObject) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSDocument_MOZILLA_2_0_BRANCH, NS_IDOMNSDOCUMENT_MOZILLA_2_0_BRANCH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSDOCUMENT_MOZILLA_2_0_BRANCH \
  NS_SCRIPTABLE NS_IMETHOD GetMozCurrentStateObject(nsIVariant **aMozCurrentStateObject); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSDOCUMENT_MOZILLA_2_0_BRANCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMozCurrentStateObject(nsIVariant **aMozCurrentStateObject) { return _to GetMozCurrentStateObject(aMozCurrentStateObject); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSDOCUMENT_MOZILLA_2_0_BRANCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMozCurrentStateObject(nsIVariant **aMozCurrentStateObject) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozCurrentStateObject(aMozCurrentStateObject); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSDocument_MOZILLA_2_0_BRANCH : public nsIDOMNSDocument_MOZILLA_2_0_BRANCH
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSDOCUMENT_MOZILLA_2_0_BRANCH

  nsDOMNSDocument_MOZILLA_2_0_BRANCH();

private:
  ~nsDOMNSDocument_MOZILLA_2_0_BRANCH();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSDocument_MOZILLA_2_0_BRANCH, nsIDOMNSDocument_MOZILLA_2_0_BRANCH)

nsDOMNSDocument_MOZILLA_2_0_BRANCH::nsDOMNSDocument_MOZILLA_2_0_BRANCH()
{
  /* member initializers and constructor code */
}

nsDOMNSDocument_MOZILLA_2_0_BRANCH::~nsDOMNSDocument_MOZILLA_2_0_BRANCH()
{
  /* destructor code */
}

/* readonly attribute nsIVariant mozCurrentStateObject; */
NS_IMETHODIMP nsDOMNSDocument_MOZILLA_2_0_BRANCH::GetMozCurrentStateObject(nsIVariant **aMozCurrentStateObject)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSDocument_h__ */

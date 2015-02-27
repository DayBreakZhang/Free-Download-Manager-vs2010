/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLDocument.idl
 */

#ifndef __gen_nsIDOMHTMLDocument_h__
#define __gen_nsIDOMHTMLDocument_h__


#ifndef __gen_nsIDOMDocument_h__
#include "nsIDOMDocument.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISelection; /* forward declaration */


/* starting interface:    nsIDOMHTMLDocument */
#define NS_IDOMHTMLDOCUMENT_IID_STR "fd76e045-8d97-4a97-ad75-eac5ae2f3ea4"

#define NS_IDOMHTMLDOCUMENT_IID \
  {0xfd76e045, 0x8d97, 0x4a97, \
    { 0xad, 0x75, 0xea, 0xc5, 0xae, 0x2f, 0x3e, 0xa4 }}

class NS_NO_VTABLE nsIDOMHTMLDocument : public nsIDOMDocument {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLDOCUMENT_IID)

  /* attribute DOMString domain; */
  NS_IMETHOD GetDomain(nsAString & aDomain) = 0;
  NS_IMETHOD SetDomain(const nsAString & aDomain) = 0;

  /* attribute DOMString cookie; */
  NS_IMETHOD GetCookie(nsAString & aCookie) = 0;
  NS_IMETHOD SetCookie(const nsAString & aCookie) = 0;

  /* readonly attribute nsIDOMHTMLHeadElement head; */
  NS_IMETHOD GetHead(nsIDOMHTMLHeadElement * *aHead) = 0;

  /* attribute nsIDOMHTMLElement body; */
  NS_IMETHOD GetBody(nsIDOMHTMLElement * *aBody) = 0;
  NS_IMETHOD SetBody(nsIDOMHTMLElement *aBody) = 0;

  /* readonly attribute nsIDOMHTMLCollection images; */
  NS_IMETHOD GetImages(nsIDOMHTMLCollection * *aImages) = 0;

  /* readonly attribute nsIDOMHTMLCollection embeds; */
  NS_IMETHOD GetEmbeds(nsIDOMHTMLCollection * *aEmbeds) = 0;

  /* readonly attribute nsIDOMHTMLCollection plugins; */
  NS_IMETHOD GetPlugins(nsIDOMHTMLCollection * *aPlugins) = 0;

  /* readonly attribute nsIDOMHTMLCollection links; */
  NS_IMETHOD GetLinks(nsIDOMHTMLCollection * *aLinks) = 0;

  /* readonly attribute nsIDOMHTMLCollection forms; */
  NS_IMETHOD GetForms(nsIDOMHTMLCollection * *aForms) = 0;

  /* readonly attribute nsIDOMHTMLCollection scripts; */
  NS_IMETHOD GetScripts(nsIDOMHTMLCollection * *aScripts) = 0;

  /* nsIDOMNodeList getElementsByName (in DOMString elementName); */
  NS_IMETHOD GetElementsByName(const nsAString & elementName, nsIDOMNodeList * *_retval) = 0;

  /* nsIDOMNodeList getItems ([optional] in DOMString types); */
  NS_IMETHOD GetItems(const nsAString & types, nsIDOMNodeList * *_retval) = 0;

  /* [implicit_jscontext,optional_argc] nsISupports open ([optional] in DOMString aContentTypeOrUrl, [optional] in DOMString aReplaceOrName, [optional] in DOMString aFeatures); */
  NS_IMETHOD Open(const nsAString & aContentTypeOrUrl, const nsAString & aReplaceOrName, const nsAString & aFeatures, JSContext* cx, uint8_t _argc, nsISupports * *_retval) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

  /* [implicit_jscontext] void write ([optional, Null (Stringify)] in DOMString text); */
  NS_IMETHOD Write(const nsAString & text, JSContext* cx) = 0;

  /* [implicit_jscontext] void writeln ([optional, Null (Stringify)] in DOMString text); */
  NS_IMETHOD Writeln(const nsAString & text, JSContext* cx) = 0;

  /* attribute DOMString designMode; */
  NS_IMETHOD GetDesignMode(nsAString & aDesignMode) = 0;
  NS_IMETHOD SetDesignMode(const nsAString & aDesignMode) = 0;

  /* boolean execCommand (in DOMString commandID, [optional] in boolean doShowUI, [optional] in DOMString value); */
  NS_IMETHOD ExecCommand(const nsAString & commandID, bool doShowUI, const nsAString & value, bool *_retval) = 0;

  /* boolean queryCommandEnabled (in DOMString commandID); */
  NS_IMETHOD QueryCommandEnabled(const nsAString & commandID, bool *_retval) = 0;

  /* boolean queryCommandIndeterm (in DOMString commandID); */
  NS_IMETHOD QueryCommandIndeterm(const nsAString & commandID, bool *_retval) = 0;

  /* boolean queryCommandState (in DOMString commandID); */
  NS_IMETHOD QueryCommandState(const nsAString & commandID, bool *_retval) = 0;

  /* boolean queryCommandSupported (in DOMString commandID); */
  NS_IMETHOD QueryCommandSupported(const nsAString & commandID, bool *_retval) = 0;

  /* DOMString queryCommandValue (in DOMString commandID); */
  NS_IMETHOD QueryCommandValue(const nsAString & commandID, nsAString & _retval) = 0;

  /* attribute DOMString fgColor; */
  NS_IMETHOD GetFgColor(nsAString & aFgColor) = 0;
  NS_IMETHOD SetFgColor(const nsAString & aFgColor) = 0;

  /* attribute DOMString bgColor; */
  NS_IMETHOD GetBgColor(nsAString & aBgColor) = 0;
  NS_IMETHOD SetBgColor(const nsAString & aBgColor) = 0;

  /* attribute DOMString linkColor; */
  NS_IMETHOD GetLinkColor(nsAString & aLinkColor) = 0;
  NS_IMETHOD SetLinkColor(const nsAString & aLinkColor) = 0;

  /* attribute DOMString vlinkColor; */
  NS_IMETHOD GetVlinkColor(nsAString & aVlinkColor) = 0;
  NS_IMETHOD SetVlinkColor(const nsAString & aVlinkColor) = 0;

  /* attribute DOMString alinkColor; */
  NS_IMETHOD GetAlinkColor(nsAString & aAlinkColor) = 0;
  NS_IMETHOD SetAlinkColor(const nsAString & aAlinkColor) = 0;

  /* readonly attribute nsIDOMHTMLCollection anchors; */
  NS_IMETHOD GetAnchors(nsIDOMHTMLCollection * *aAnchors) = 0;

  /* readonly attribute nsIDOMHTMLCollection applets; */
  NS_IMETHOD GetApplets(nsIDOMHTMLCollection * *aApplets) = 0;

  /* void clear (); */
  NS_IMETHOD Clear(void) = 0;

  /* nsISelection getSelection (); */
  NS_IMETHOD GetSelection(nsISelection * *_retval) = 0;

  /* void captureEvents (in long eventFlags); */
  NS_IMETHOD CaptureEvents(int32_t eventFlags) = 0;

  /* void releaseEvents (in long eventFlags); */
  NS_IMETHOD ReleaseEvents(int32_t eventFlags) = 0;

  /* void routeEvent (in nsIDOMEvent evt); */
  NS_IMETHOD RouteEvent(nsIDOMEvent *evt) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLDocument, NS_IDOMHTMLDOCUMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLDOCUMENT \
  NS_IMETHOD GetDomain(nsAString & aDomain); \
  NS_IMETHOD SetDomain(const nsAString & aDomain); \
  NS_IMETHOD GetCookie(nsAString & aCookie); \
  NS_IMETHOD SetCookie(const nsAString & aCookie); \
  NS_IMETHOD GetHead(nsIDOMHTMLHeadElement * *aHead); \
  NS_IMETHOD GetBody(nsIDOMHTMLElement * *aBody); \
  NS_IMETHOD SetBody(nsIDOMHTMLElement *aBody); \
  NS_IMETHOD GetImages(nsIDOMHTMLCollection * *aImages); \
  NS_IMETHOD GetEmbeds(nsIDOMHTMLCollection * *aEmbeds); \
  NS_IMETHOD GetPlugins(nsIDOMHTMLCollection * *aPlugins); \
  NS_IMETHOD GetLinks(nsIDOMHTMLCollection * *aLinks); \
  NS_IMETHOD GetForms(nsIDOMHTMLCollection * *aForms); \
  NS_IMETHOD GetScripts(nsIDOMHTMLCollection * *aScripts); \
  NS_IMETHOD GetElementsByName(const nsAString & elementName, nsIDOMNodeList * *_retval); \
  NS_IMETHOD GetItems(const nsAString & types, nsIDOMNodeList * *_retval); \
  NS_IMETHOD Open(const nsAString & aContentTypeOrUrl, const nsAString & aReplaceOrName, const nsAString & aFeatures, JSContext* cx, uint8_t _argc, nsISupports * *_retval); \
  NS_IMETHOD Close(void); \
  NS_IMETHOD Write(const nsAString & text, JSContext* cx); \
  NS_IMETHOD Writeln(const nsAString & text, JSContext* cx); \
  NS_IMETHOD GetDesignMode(nsAString & aDesignMode); \
  NS_IMETHOD SetDesignMode(const nsAString & aDesignMode); \
  NS_IMETHOD ExecCommand(const nsAString & commandID, bool doShowUI, const nsAString & value, bool *_retval); \
  NS_IMETHOD QueryCommandEnabled(const nsAString & commandID, bool *_retval); \
  NS_IMETHOD QueryCommandIndeterm(const nsAString & commandID, bool *_retval); \
  NS_IMETHOD QueryCommandState(const nsAString & commandID, bool *_retval); \
  NS_IMETHOD QueryCommandSupported(const nsAString & commandID, bool *_retval); \
  NS_IMETHOD QueryCommandValue(const nsAString & commandID, nsAString & _retval); \
  NS_IMETHOD GetFgColor(nsAString & aFgColor); \
  NS_IMETHOD SetFgColor(const nsAString & aFgColor); \
  NS_IMETHOD GetBgColor(nsAString & aBgColor); \
  NS_IMETHOD SetBgColor(const nsAString & aBgColor); \
  NS_IMETHOD GetLinkColor(nsAString & aLinkColor); \
  NS_IMETHOD SetLinkColor(const nsAString & aLinkColor); \
  NS_IMETHOD GetVlinkColor(nsAString & aVlinkColor); \
  NS_IMETHOD SetVlinkColor(const nsAString & aVlinkColor); \
  NS_IMETHOD GetAlinkColor(nsAString & aAlinkColor); \
  NS_IMETHOD SetAlinkColor(const nsAString & aAlinkColor); \
  NS_IMETHOD GetAnchors(nsIDOMHTMLCollection * *aAnchors); \
  NS_IMETHOD GetApplets(nsIDOMHTMLCollection * *aApplets); \
  NS_IMETHOD Clear(void); \
  NS_IMETHOD GetSelection(nsISelection * *_retval); \
  NS_IMETHOD CaptureEvents(int32_t eventFlags); \
  NS_IMETHOD ReleaseEvents(int32_t eventFlags); \
  NS_IMETHOD RouteEvent(nsIDOMEvent *evt); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLDOCUMENT(_to) \
  NS_IMETHOD GetDomain(nsAString & aDomain) { return _to GetDomain(aDomain); } \
  NS_IMETHOD SetDomain(const nsAString & aDomain) { return _to SetDomain(aDomain); } \
  NS_IMETHOD GetCookie(nsAString & aCookie) { return _to GetCookie(aCookie); } \
  NS_IMETHOD SetCookie(const nsAString & aCookie) { return _to SetCookie(aCookie); } \
  NS_IMETHOD GetHead(nsIDOMHTMLHeadElement * *aHead) { return _to GetHead(aHead); } \
  NS_IMETHOD GetBody(nsIDOMHTMLElement * *aBody) { return _to GetBody(aBody); } \
  NS_IMETHOD SetBody(nsIDOMHTMLElement *aBody) { return _to SetBody(aBody); } \
  NS_IMETHOD GetImages(nsIDOMHTMLCollection * *aImages) { return _to GetImages(aImages); } \
  NS_IMETHOD GetEmbeds(nsIDOMHTMLCollection * *aEmbeds) { return _to GetEmbeds(aEmbeds); } \
  NS_IMETHOD GetPlugins(nsIDOMHTMLCollection * *aPlugins) { return _to GetPlugins(aPlugins); } \
  NS_IMETHOD GetLinks(nsIDOMHTMLCollection * *aLinks) { return _to GetLinks(aLinks); } \
  NS_IMETHOD GetForms(nsIDOMHTMLCollection * *aForms) { return _to GetForms(aForms); } \
  NS_IMETHOD GetScripts(nsIDOMHTMLCollection * *aScripts) { return _to GetScripts(aScripts); } \
  NS_IMETHOD GetElementsByName(const nsAString & elementName, nsIDOMNodeList * *_retval) { return _to GetElementsByName(elementName, _retval); } \
  NS_IMETHOD GetItems(const nsAString & types, nsIDOMNodeList * *_retval) { return _to GetItems(types, _retval); } \
  NS_IMETHOD Open(const nsAString & aContentTypeOrUrl, const nsAString & aReplaceOrName, const nsAString & aFeatures, JSContext* cx, uint8_t _argc, nsISupports * *_retval) { return _to Open(aContentTypeOrUrl, aReplaceOrName, aFeatures, cx, _argc, _retval); } \
  NS_IMETHOD Close(void) { return _to Close(); } \
  NS_IMETHOD Write(const nsAString & text, JSContext* cx) { return _to Write(text, cx); } \
  NS_IMETHOD Writeln(const nsAString & text, JSContext* cx) { return _to Writeln(text, cx); } \
  NS_IMETHOD GetDesignMode(nsAString & aDesignMode) { return _to GetDesignMode(aDesignMode); } \
  NS_IMETHOD SetDesignMode(const nsAString & aDesignMode) { return _to SetDesignMode(aDesignMode); } \
  NS_IMETHOD ExecCommand(const nsAString & commandID, bool doShowUI, const nsAString & value, bool *_retval) { return _to ExecCommand(commandID, doShowUI, value, _retval); } \
  NS_IMETHOD QueryCommandEnabled(const nsAString & commandID, bool *_retval) { return _to QueryCommandEnabled(commandID, _retval); } \
  NS_IMETHOD QueryCommandIndeterm(const nsAString & commandID, bool *_retval) { return _to QueryCommandIndeterm(commandID, _retval); } \
  NS_IMETHOD QueryCommandState(const nsAString & commandID, bool *_retval) { return _to QueryCommandState(commandID, _retval); } \
  NS_IMETHOD QueryCommandSupported(const nsAString & commandID, bool *_retval) { return _to QueryCommandSupported(commandID, _retval); } \
  NS_IMETHOD QueryCommandValue(const nsAString & commandID, nsAString & _retval) { return _to QueryCommandValue(commandID, _retval); } \
  NS_IMETHOD GetFgColor(nsAString & aFgColor) { return _to GetFgColor(aFgColor); } \
  NS_IMETHOD SetFgColor(const nsAString & aFgColor) { return _to SetFgColor(aFgColor); } \
  NS_IMETHOD GetBgColor(nsAString & aBgColor) { return _to GetBgColor(aBgColor); } \
  NS_IMETHOD SetBgColor(const nsAString & aBgColor) { return _to SetBgColor(aBgColor); } \
  NS_IMETHOD GetLinkColor(nsAString & aLinkColor) { return _to GetLinkColor(aLinkColor); } \
  NS_IMETHOD SetLinkColor(const nsAString & aLinkColor) { return _to SetLinkColor(aLinkColor); } \
  NS_IMETHOD GetVlinkColor(nsAString & aVlinkColor) { return _to GetVlinkColor(aVlinkColor); } \
  NS_IMETHOD SetVlinkColor(const nsAString & aVlinkColor) { return _to SetVlinkColor(aVlinkColor); } \
  NS_IMETHOD GetAlinkColor(nsAString & aAlinkColor) { return _to GetAlinkColor(aAlinkColor); } \
  NS_IMETHOD SetAlinkColor(const nsAString & aAlinkColor) { return _to SetAlinkColor(aAlinkColor); } \
  NS_IMETHOD GetAnchors(nsIDOMHTMLCollection * *aAnchors) { return _to GetAnchors(aAnchors); } \
  NS_IMETHOD GetApplets(nsIDOMHTMLCollection * *aApplets) { return _to GetApplets(aApplets); } \
  NS_IMETHOD Clear(void) { return _to Clear(); } \
  NS_IMETHOD GetSelection(nsISelection * *_retval) { return _to GetSelection(_retval); } \
  NS_IMETHOD CaptureEvents(int32_t eventFlags) { return _to CaptureEvents(eventFlags); } \
  NS_IMETHOD ReleaseEvents(int32_t eventFlags) { return _to ReleaseEvents(eventFlags); } \
  NS_IMETHOD RouteEvent(nsIDOMEvent *evt) { return _to RouteEvent(evt); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLDOCUMENT(_to) \
  NS_IMETHOD GetDomain(nsAString & aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomain(aDomain); } \
  NS_IMETHOD SetDomain(const nsAString & aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDomain(aDomain); } \
  NS_IMETHOD GetCookie(nsAString & aCookie) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCookie(aCookie); } \
  NS_IMETHOD SetCookie(const nsAString & aCookie) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCookie(aCookie); } \
  NS_IMETHOD GetHead(nsIDOMHTMLHeadElement * *aHead) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHead(aHead); } \
  NS_IMETHOD GetBody(nsIDOMHTMLElement * *aBody) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBody(aBody); } \
  NS_IMETHOD SetBody(nsIDOMHTMLElement *aBody) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBody(aBody); } \
  NS_IMETHOD GetImages(nsIDOMHTMLCollection * *aImages) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImages(aImages); } \
  NS_IMETHOD GetEmbeds(nsIDOMHTMLCollection * *aEmbeds) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEmbeds(aEmbeds); } \
  NS_IMETHOD GetPlugins(nsIDOMHTMLCollection * *aPlugins) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlugins(aPlugins); } \
  NS_IMETHOD GetLinks(nsIDOMHTMLCollection * *aLinks) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLinks(aLinks); } \
  NS_IMETHOD GetForms(nsIDOMHTMLCollection * *aForms) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForms(aForms); } \
  NS_IMETHOD GetScripts(nsIDOMHTMLCollection * *aScripts) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScripts(aScripts); } \
  NS_IMETHOD GetElementsByName(const nsAString & elementName, nsIDOMNodeList * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElementsByName(elementName, _retval); } \
  NS_IMETHOD GetItems(const nsAString & types, nsIDOMNodeList * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItems(types, _retval); } \
  NS_IMETHOD Open(const nsAString & aContentTypeOrUrl, const nsAString & aReplaceOrName, const nsAString & aFeatures, JSContext* cx, uint8_t _argc, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(aContentTypeOrUrl, aReplaceOrName, aFeatures, cx, _argc, _retval); } \
  NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_IMETHOD Write(const nsAString & text, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->Write(text, cx); } \
  NS_IMETHOD Writeln(const nsAString & text, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->Writeln(text, cx); } \
  NS_IMETHOD GetDesignMode(nsAString & aDesignMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDesignMode(aDesignMode); } \
  NS_IMETHOD SetDesignMode(const nsAString & aDesignMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDesignMode(aDesignMode); } \
  NS_IMETHOD ExecCommand(const nsAString & commandID, bool doShowUI, const nsAString & value, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecCommand(commandID, doShowUI, value, _retval); } \
  NS_IMETHOD QueryCommandEnabled(const nsAString & commandID, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryCommandEnabled(commandID, _retval); } \
  NS_IMETHOD QueryCommandIndeterm(const nsAString & commandID, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryCommandIndeterm(commandID, _retval); } \
  NS_IMETHOD QueryCommandState(const nsAString & commandID, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryCommandState(commandID, _retval); } \
  NS_IMETHOD QueryCommandSupported(const nsAString & commandID, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryCommandSupported(commandID, _retval); } \
  NS_IMETHOD QueryCommandValue(const nsAString & commandID, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryCommandValue(commandID, _retval); } \
  NS_IMETHOD GetFgColor(nsAString & aFgColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFgColor(aFgColor); } \
  NS_IMETHOD SetFgColor(const nsAString & aFgColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFgColor(aFgColor); } \
  NS_IMETHOD GetBgColor(nsAString & aBgColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBgColor(aBgColor); } \
  NS_IMETHOD SetBgColor(const nsAString & aBgColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBgColor(aBgColor); } \
  NS_IMETHOD GetLinkColor(nsAString & aLinkColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLinkColor(aLinkColor); } \
  NS_IMETHOD SetLinkColor(const nsAString & aLinkColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLinkColor(aLinkColor); } \
  NS_IMETHOD GetVlinkColor(nsAString & aVlinkColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVlinkColor(aVlinkColor); } \
  NS_IMETHOD SetVlinkColor(const nsAString & aVlinkColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVlinkColor(aVlinkColor); } \
  NS_IMETHOD GetAlinkColor(nsAString & aAlinkColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlinkColor(aAlinkColor); } \
  NS_IMETHOD SetAlinkColor(const nsAString & aAlinkColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlinkColor(aAlinkColor); } \
  NS_IMETHOD GetAnchors(nsIDOMHTMLCollection * *aAnchors) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnchors(aAnchors); } \
  NS_IMETHOD GetApplets(nsIDOMHTMLCollection * *aApplets) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApplets(aApplets); } \
  NS_IMETHOD Clear(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(); } \
  NS_IMETHOD GetSelection(nsISelection * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelection(_retval); } \
  NS_IMETHOD CaptureEvents(int32_t eventFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->CaptureEvents(eventFlags); } \
  NS_IMETHOD ReleaseEvents(int32_t eventFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReleaseEvents(eventFlags); } \
  NS_IMETHOD RouteEvent(nsIDOMEvent *evt) { return !_to ? NS_ERROR_NULL_POINTER : _to->RouteEvent(evt); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLDocument : public nsIDOMHTMLDocument
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLDOCUMENT

  nsDOMHTMLDocument();

private:
  ~nsDOMHTMLDocument();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLDocument, nsIDOMHTMLDocument)

nsDOMHTMLDocument::nsDOMHTMLDocument()
{
  /* member initializers and constructor code */
}

nsDOMHTMLDocument::~nsDOMHTMLDocument()
{
  /* destructor code */
}

/* attribute DOMString domain; */
NS_IMETHODIMP nsDOMHTMLDocument::GetDomain(nsAString & aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLDocument::SetDomain(const nsAString & aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString cookie; */
NS_IMETHODIMP nsDOMHTMLDocument::GetCookie(nsAString & aCookie)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLDocument::SetCookie(const nsAString & aCookie)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLHeadElement head; */
NS_IMETHODIMP nsDOMHTMLDocument::GetHead(nsIDOMHTMLHeadElement * *aHead)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMHTMLElement body; */
NS_IMETHODIMP nsDOMHTMLDocument::GetBody(nsIDOMHTMLElement * *aBody)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLDocument::SetBody(nsIDOMHTMLElement *aBody)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLCollection images; */
NS_IMETHODIMP nsDOMHTMLDocument::GetImages(nsIDOMHTMLCollection * *aImages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLCollection embeds; */
NS_IMETHODIMP nsDOMHTMLDocument::GetEmbeds(nsIDOMHTMLCollection * *aEmbeds)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLCollection plugins; */
NS_IMETHODIMP nsDOMHTMLDocument::GetPlugins(nsIDOMHTMLCollection * *aPlugins)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLCollection links; */
NS_IMETHODIMP nsDOMHTMLDocument::GetLinks(nsIDOMHTMLCollection * *aLinks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLCollection forms; */
NS_IMETHODIMP nsDOMHTMLDocument::GetForms(nsIDOMHTMLCollection * *aForms)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLCollection scripts; */
NS_IMETHODIMP nsDOMHTMLDocument::GetScripts(nsIDOMHTMLCollection * *aScripts)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList getElementsByName (in DOMString elementName); */
NS_IMETHODIMP nsDOMHTMLDocument::GetElementsByName(const nsAString & elementName, nsIDOMNodeList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList getItems ([optional] in DOMString types); */
NS_IMETHODIMP nsDOMHTMLDocument::GetItems(const nsAString & types, nsIDOMNodeList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] nsISupports open ([optional] in DOMString aContentTypeOrUrl, [optional] in DOMString aReplaceOrName, [optional] in DOMString aFeatures); */
NS_IMETHODIMP nsDOMHTMLDocument::Open(const nsAString & aContentTypeOrUrl, const nsAString & aReplaceOrName, const nsAString & aFeatures, JSContext* cx, uint8_t _argc, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsDOMHTMLDocument::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void write ([optional, Null (Stringify)] in DOMString text); */
NS_IMETHODIMP nsDOMHTMLDocument::Write(const nsAString & text, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void writeln ([optional, Null (Stringify)] in DOMString text); */
NS_IMETHODIMP nsDOMHTMLDocument::Writeln(const nsAString & text, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString designMode; */
NS_IMETHODIMP nsDOMHTMLDocument::GetDesignMode(nsAString & aDesignMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLDocument::SetDesignMode(const nsAString & aDesignMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean execCommand (in DOMString commandID, [optional] in boolean doShowUI, [optional] in DOMString value); */
NS_IMETHODIMP nsDOMHTMLDocument::ExecCommand(const nsAString & commandID, bool doShowUI, const nsAString & value, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean queryCommandEnabled (in DOMString commandID); */
NS_IMETHODIMP nsDOMHTMLDocument::QueryCommandEnabled(const nsAString & commandID, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean queryCommandIndeterm (in DOMString commandID); */
NS_IMETHODIMP nsDOMHTMLDocument::QueryCommandIndeterm(const nsAString & commandID, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean queryCommandState (in DOMString commandID); */
NS_IMETHODIMP nsDOMHTMLDocument::QueryCommandState(const nsAString & commandID, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean queryCommandSupported (in DOMString commandID); */
NS_IMETHODIMP nsDOMHTMLDocument::QueryCommandSupported(const nsAString & commandID, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString queryCommandValue (in DOMString commandID); */
NS_IMETHODIMP nsDOMHTMLDocument::QueryCommandValue(const nsAString & commandID, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString fgColor; */
NS_IMETHODIMP nsDOMHTMLDocument::GetFgColor(nsAString & aFgColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLDocument::SetFgColor(const nsAString & aFgColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString bgColor; */
NS_IMETHODIMP nsDOMHTMLDocument::GetBgColor(nsAString & aBgColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLDocument::SetBgColor(const nsAString & aBgColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString linkColor; */
NS_IMETHODIMP nsDOMHTMLDocument::GetLinkColor(nsAString & aLinkColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLDocument::SetLinkColor(const nsAString & aLinkColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString vlinkColor; */
NS_IMETHODIMP nsDOMHTMLDocument::GetVlinkColor(nsAString & aVlinkColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLDocument::SetVlinkColor(const nsAString & aVlinkColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString alinkColor; */
NS_IMETHODIMP nsDOMHTMLDocument::GetAlinkColor(nsAString & aAlinkColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLDocument::SetAlinkColor(const nsAString & aAlinkColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLCollection anchors; */
NS_IMETHODIMP nsDOMHTMLDocument::GetAnchors(nsIDOMHTMLCollection * *aAnchors)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLCollection applets; */
NS_IMETHODIMP nsDOMHTMLDocument::GetApplets(nsIDOMHTMLCollection * *aApplets)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clear (); */
NS_IMETHODIMP nsDOMHTMLDocument::Clear()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISelection getSelection (); */
NS_IMETHODIMP nsDOMHTMLDocument::GetSelection(nsISelection * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void captureEvents (in long eventFlags); */
NS_IMETHODIMP nsDOMHTMLDocument::CaptureEvents(int32_t eventFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void releaseEvents (in long eventFlags); */
NS_IMETHODIMP nsDOMHTMLDocument::ReleaseEvents(int32_t eventFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void routeEvent (in nsIDOMEvent evt); */
NS_IMETHODIMP nsDOMHTMLDocument::RouteEvent(nsIDOMEvent *evt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLDocument_h__ */

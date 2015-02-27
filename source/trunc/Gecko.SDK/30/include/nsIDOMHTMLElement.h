/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMHTMLElement.idl
 */

#ifndef __gen_nsIDOMHTMLElement_h__
#define __gen_nsIDOMHTMLElement_h__


#ifndef __gen_nsIDOMElement_h__
#include "nsIDOMElement.h"
#endif

#ifndef __gen_nsIVariant_h__
#include "nsIVariant.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMHTMLMenuElement; /* forward declaration */


/* starting interface:    nsIDOMHTMLElement */
#define NS_IDOMHTMLELEMENT_IID_STR "e29ddc73-ac40-40fe-8bbd-14bf2d52c53a"

#define NS_IDOMHTMLELEMENT_IID \
  {0xe29ddc73, 0xac40, 0x40fe, \
    { 0x8b, 0xbd, 0x14, 0xbf, 0x2d, 0x52, 0xc5, 0x3a }}

class NS_NO_VTABLE nsIDOMHTMLElement : public nsIDOMElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLELEMENT_IID)

  /* attribute DOMString id; */
  NS_IMETHOD GetId(nsAString & aId) = 0;
  NS_IMETHOD SetId(const nsAString & aId) = 0;

  /* attribute DOMString title; */
  NS_IMETHOD GetTitle(nsAString & aTitle) = 0;
  NS_IMETHOD SetTitle(const nsAString & aTitle) = 0;

  /* attribute DOMString lang; */
  NS_IMETHOD GetLang(nsAString & aLang) = 0;
  NS_IMETHOD SetLang(const nsAString & aLang) = 0;

  /* attribute DOMString dir; */
  NS_IMETHOD GetDir(nsAString & aDir) = 0;
  NS_IMETHOD SetDir(const nsAString & aDir) = 0;

  /* [binaryname(DOMClassName)] attribute DOMString className; */
  NS_IMETHOD GetDOMClassName(nsAString & aClassName) = 0;
  NS_IMETHOD SetDOMClassName(const nsAString & aClassName) = 0;

  /* readonly attribute nsISupports dataset; */
  NS_IMETHOD GetDataset(nsISupports * *aDataset) = 0;

  /* attribute boolean itemScope; */
  NS_IMETHOD GetItemScope(bool *aItemScope) = 0;
  NS_IMETHOD SetItemScope(bool aItemScope) = 0;

  /* attribute nsIVariant itemType; */
  NS_IMETHOD GetItemType(nsIVariant * *aItemType) = 0;
  NS_IMETHOD SetItemType(nsIVariant *aItemType) = 0;

  /* attribute DOMString itemId; */
  NS_IMETHOD GetItemId(nsAString & aItemId) = 0;
  NS_IMETHOD SetItemId(const nsAString & aItemId) = 0;

  /* readonly attribute nsISupports properties; */
  NS_IMETHOD GetProperties(nsISupports * *aProperties) = 0;

  /* attribute nsIVariant itemValue; */
  NS_IMETHOD GetItemValue(nsIVariant * *aItemValue) = 0;
  NS_IMETHOD SetItemValue(nsIVariant *aItemValue) = 0;

  /* attribute nsIVariant itemProp; */
  NS_IMETHOD GetItemProp(nsIVariant * *aItemProp) = 0;
  NS_IMETHOD SetItemProp(nsIVariant *aItemProp) = 0;

  /* attribute nsIVariant itemRef; */
  NS_IMETHOD GetItemRef(nsIVariant * *aItemRef) = 0;
  NS_IMETHOD SetItemRef(nsIVariant *aItemRef) = 0;

  /* attribute boolean hidden; */
  NS_IMETHOD GetHidden(bool *aHidden) = 0;
  NS_IMETHOD SetHidden(bool aHidden) = 0;

  /* [binaryname(DOMClick)] void click (); */
  NS_IMETHOD DOMClick(void) = 0;

  /* attribute long tabIndex; */
  NS_IMETHOD GetTabIndex(int32_t *aTabIndex) = 0;
  NS_IMETHOD SetTabIndex(int32_t aTabIndex) = 0;

  /* void focus (); */
  NS_IMETHOD Focus(void) = 0;

  /* [binaryname(DOMBlur)] void blur (); */
  NS_IMETHOD DOMBlur(void) = 0;

  /* attribute DOMString accessKey; */
  NS_IMETHOD GetAccessKey(nsAString & aAccessKey) = 0;
  NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) = 0;

  /* readonly attribute DOMString accessKeyLabel; */
  NS_IMETHOD GetAccessKeyLabel(nsAString & aAccessKeyLabel) = 0;

  /* attribute boolean draggable; */
  NS_IMETHOD GetDraggable(bool *aDraggable) = 0;
  NS_IMETHOD SetDraggable(bool aDraggable) = 0;

  /* attribute DOMString contentEditable; */
  NS_IMETHOD GetContentEditable(nsAString & aContentEditable) = 0;
  NS_IMETHOD SetContentEditable(const nsAString & aContentEditable) = 0;

  /* readonly attribute boolean isContentEditable; */
  NS_IMETHOD GetIsContentEditable(bool *aIsContentEditable) = 0;

  /* readonly attribute nsIDOMHTMLMenuElement contextMenu; */
  NS_IMETHOD GetContextMenu(nsIDOMHTMLMenuElement * *aContextMenu) = 0;

  /* attribute boolean spellcheck; */
  NS_IMETHOD GetSpellcheck(bool *aSpellcheck) = 0;
  NS_IMETHOD SetSpellcheck(bool aSpellcheck) = 0;

  /* attribute DOMString innerHTML; */
  NS_IMETHOD GetInnerHTML(nsAString & aInnerHTML) = 0;
  NS_IMETHOD SetInnerHTML(const nsAString & aInnerHTML) = 0;

  /* attribute DOMString outerHTML; */
  NS_IMETHOD GetOuterHTML(nsAString & aOuterHTML) = 0;
  NS_IMETHOD SetOuterHTML(const nsAString & aOuterHTML) = 0;

  /* void insertAdjacentHTML (in DOMString position, in DOMString text); */
  NS_IMETHOD InsertAdjacentHTML(const nsAString & position, const nsAString & text) = 0;

  /* [optional_argc] void scrollIntoView ([optional] in boolean top); */
  NS_IMETHOD ScrollIntoView(bool top, uint8_t _argc) = 0;

  /* readonly attribute nsIDOMElement offsetParent; */
  NS_IMETHOD GetOffsetParent(nsIDOMElement * *aOffsetParent) = 0;

  /* readonly attribute long offsetTop; */
  NS_IMETHOD GetOffsetTop(int32_t *aOffsetTop) = 0;

  /* readonly attribute long offsetLeft; */
  NS_IMETHOD GetOffsetLeft(int32_t *aOffsetLeft) = 0;

  /* readonly attribute long offsetWidth; */
  NS_IMETHOD GetOffsetWidth(int32_t *aOffsetWidth) = 0;

  /* readonly attribute long offsetHeight; */
  NS_IMETHOD GetOffsetHeight(int32_t *aOffsetHeight) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLElement, NS_IDOMHTMLELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLELEMENT \
  NS_IMETHOD GetId(nsAString & aId); \
  NS_IMETHOD SetId(const nsAString & aId); \
  NS_IMETHOD GetTitle(nsAString & aTitle); \
  NS_IMETHOD SetTitle(const nsAString & aTitle); \
  NS_IMETHOD GetLang(nsAString & aLang); \
  NS_IMETHOD SetLang(const nsAString & aLang); \
  NS_IMETHOD GetDir(nsAString & aDir); \
  NS_IMETHOD SetDir(const nsAString & aDir); \
  NS_IMETHOD GetDOMClassName(nsAString & aClassName); \
  NS_IMETHOD SetDOMClassName(const nsAString & aClassName); \
  NS_IMETHOD GetDataset(nsISupports * *aDataset); \
  NS_IMETHOD GetItemScope(bool *aItemScope); \
  NS_IMETHOD SetItemScope(bool aItemScope); \
  NS_IMETHOD GetItemType(nsIVariant * *aItemType); \
  NS_IMETHOD SetItemType(nsIVariant *aItemType); \
  NS_IMETHOD GetItemId(nsAString & aItemId); \
  NS_IMETHOD SetItemId(const nsAString & aItemId); \
  NS_IMETHOD GetProperties(nsISupports * *aProperties); \
  NS_IMETHOD GetItemValue(nsIVariant * *aItemValue); \
  NS_IMETHOD SetItemValue(nsIVariant *aItemValue); \
  NS_IMETHOD GetItemProp(nsIVariant * *aItemProp); \
  NS_IMETHOD SetItemProp(nsIVariant *aItemProp); \
  NS_IMETHOD GetItemRef(nsIVariant * *aItemRef); \
  NS_IMETHOD SetItemRef(nsIVariant *aItemRef); \
  NS_IMETHOD GetHidden(bool *aHidden); \
  NS_IMETHOD SetHidden(bool aHidden); \
  NS_IMETHOD DOMClick(void); \
  NS_IMETHOD GetTabIndex(int32_t *aTabIndex); \
  NS_IMETHOD SetTabIndex(int32_t aTabIndex); \
  NS_IMETHOD Focus(void); \
  NS_IMETHOD DOMBlur(void); \
  NS_IMETHOD GetAccessKey(nsAString & aAccessKey); \
  NS_IMETHOD SetAccessKey(const nsAString & aAccessKey); \
  NS_IMETHOD GetAccessKeyLabel(nsAString & aAccessKeyLabel); \
  NS_IMETHOD GetDraggable(bool *aDraggable); \
  NS_IMETHOD SetDraggable(bool aDraggable); \
  NS_IMETHOD GetContentEditable(nsAString & aContentEditable); \
  NS_IMETHOD SetContentEditable(const nsAString & aContentEditable); \
  NS_IMETHOD GetIsContentEditable(bool *aIsContentEditable); \
  NS_IMETHOD GetContextMenu(nsIDOMHTMLMenuElement * *aContextMenu); \
  NS_IMETHOD GetSpellcheck(bool *aSpellcheck); \
  NS_IMETHOD SetSpellcheck(bool aSpellcheck); \
  NS_IMETHOD GetInnerHTML(nsAString & aInnerHTML); \
  NS_IMETHOD SetInnerHTML(const nsAString & aInnerHTML); \
  NS_IMETHOD GetOuterHTML(nsAString & aOuterHTML); \
  NS_IMETHOD SetOuterHTML(const nsAString & aOuterHTML); \
  NS_IMETHOD InsertAdjacentHTML(const nsAString & position, const nsAString & text); \
  NS_IMETHOD ScrollIntoView(bool top, uint8_t _argc); \
  NS_IMETHOD GetOffsetParent(nsIDOMElement * *aOffsetParent); \
  NS_IMETHOD GetOffsetTop(int32_t *aOffsetTop); \
  NS_IMETHOD GetOffsetLeft(int32_t *aOffsetLeft); \
  NS_IMETHOD GetOffsetWidth(int32_t *aOffsetWidth); \
  NS_IMETHOD GetOffsetHeight(int32_t *aOffsetHeight); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLELEMENT(_to) \
  NS_IMETHOD GetId(nsAString & aId) { return _to GetId(aId); } \
  NS_IMETHOD SetId(const nsAString & aId) { return _to SetId(aId); } \
  NS_IMETHOD GetTitle(nsAString & aTitle) { return _to GetTitle(aTitle); } \
  NS_IMETHOD SetTitle(const nsAString & aTitle) { return _to SetTitle(aTitle); } \
  NS_IMETHOD GetLang(nsAString & aLang) { return _to GetLang(aLang); } \
  NS_IMETHOD SetLang(const nsAString & aLang) { return _to SetLang(aLang); } \
  NS_IMETHOD GetDir(nsAString & aDir) { return _to GetDir(aDir); } \
  NS_IMETHOD SetDir(const nsAString & aDir) { return _to SetDir(aDir); } \
  NS_IMETHOD GetDOMClassName(nsAString & aClassName) { return _to GetDOMClassName(aClassName); } \
  NS_IMETHOD SetDOMClassName(const nsAString & aClassName) { return _to SetDOMClassName(aClassName); } \
  NS_IMETHOD GetDataset(nsISupports * *aDataset) { return _to GetDataset(aDataset); } \
  NS_IMETHOD GetItemScope(bool *aItemScope) { return _to GetItemScope(aItemScope); } \
  NS_IMETHOD SetItemScope(bool aItemScope) { return _to SetItemScope(aItemScope); } \
  NS_IMETHOD GetItemType(nsIVariant * *aItemType) { return _to GetItemType(aItemType); } \
  NS_IMETHOD SetItemType(nsIVariant *aItemType) { return _to SetItemType(aItemType); } \
  NS_IMETHOD GetItemId(nsAString & aItemId) { return _to GetItemId(aItemId); } \
  NS_IMETHOD SetItemId(const nsAString & aItemId) { return _to SetItemId(aItemId); } \
  NS_IMETHOD GetProperties(nsISupports * *aProperties) { return _to GetProperties(aProperties); } \
  NS_IMETHOD GetItemValue(nsIVariant * *aItemValue) { return _to GetItemValue(aItemValue); } \
  NS_IMETHOD SetItemValue(nsIVariant *aItemValue) { return _to SetItemValue(aItemValue); } \
  NS_IMETHOD GetItemProp(nsIVariant * *aItemProp) { return _to GetItemProp(aItemProp); } \
  NS_IMETHOD SetItemProp(nsIVariant *aItemProp) { return _to SetItemProp(aItemProp); } \
  NS_IMETHOD GetItemRef(nsIVariant * *aItemRef) { return _to GetItemRef(aItemRef); } \
  NS_IMETHOD SetItemRef(nsIVariant *aItemRef) { return _to SetItemRef(aItemRef); } \
  NS_IMETHOD GetHidden(bool *aHidden) { return _to GetHidden(aHidden); } \
  NS_IMETHOD SetHidden(bool aHidden) { return _to SetHidden(aHidden); } \
  NS_IMETHOD DOMClick(void) { return _to DOMClick(); } \
  NS_IMETHOD GetTabIndex(int32_t *aTabIndex) { return _to GetTabIndex(aTabIndex); } \
  NS_IMETHOD SetTabIndex(int32_t aTabIndex) { return _to SetTabIndex(aTabIndex); } \
  NS_IMETHOD Focus(void) { return _to Focus(); } \
  NS_IMETHOD DOMBlur(void) { return _to DOMBlur(); } \
  NS_IMETHOD GetAccessKey(nsAString & aAccessKey) { return _to GetAccessKey(aAccessKey); } \
  NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) { return _to SetAccessKey(aAccessKey); } \
  NS_IMETHOD GetAccessKeyLabel(nsAString & aAccessKeyLabel) { return _to GetAccessKeyLabel(aAccessKeyLabel); } \
  NS_IMETHOD GetDraggable(bool *aDraggable) { return _to GetDraggable(aDraggable); } \
  NS_IMETHOD SetDraggable(bool aDraggable) { return _to SetDraggable(aDraggable); } \
  NS_IMETHOD GetContentEditable(nsAString & aContentEditable) { return _to GetContentEditable(aContentEditable); } \
  NS_IMETHOD SetContentEditable(const nsAString & aContentEditable) { return _to SetContentEditable(aContentEditable); } \
  NS_IMETHOD GetIsContentEditable(bool *aIsContentEditable) { return _to GetIsContentEditable(aIsContentEditable); } \
  NS_IMETHOD GetContextMenu(nsIDOMHTMLMenuElement * *aContextMenu) { return _to GetContextMenu(aContextMenu); } \
  NS_IMETHOD GetSpellcheck(bool *aSpellcheck) { return _to GetSpellcheck(aSpellcheck); } \
  NS_IMETHOD SetSpellcheck(bool aSpellcheck) { return _to SetSpellcheck(aSpellcheck); } \
  NS_IMETHOD GetInnerHTML(nsAString & aInnerHTML) { return _to GetInnerHTML(aInnerHTML); } \
  NS_IMETHOD SetInnerHTML(const nsAString & aInnerHTML) { return _to SetInnerHTML(aInnerHTML); } \
  NS_IMETHOD GetOuterHTML(nsAString & aOuterHTML) { return _to GetOuterHTML(aOuterHTML); } \
  NS_IMETHOD SetOuterHTML(const nsAString & aOuterHTML) { return _to SetOuterHTML(aOuterHTML); } \
  NS_IMETHOD InsertAdjacentHTML(const nsAString & position, const nsAString & text) { return _to InsertAdjacentHTML(position, text); } \
  NS_IMETHOD ScrollIntoView(bool top, uint8_t _argc) { return _to ScrollIntoView(top, _argc); } \
  NS_IMETHOD GetOffsetParent(nsIDOMElement * *aOffsetParent) { return _to GetOffsetParent(aOffsetParent); } \
  NS_IMETHOD GetOffsetTop(int32_t *aOffsetTop) { return _to GetOffsetTop(aOffsetTop); } \
  NS_IMETHOD GetOffsetLeft(int32_t *aOffsetLeft) { return _to GetOffsetLeft(aOffsetLeft); } \
  NS_IMETHOD GetOffsetWidth(int32_t *aOffsetWidth) { return _to GetOffsetWidth(aOffsetWidth); } \
  NS_IMETHOD GetOffsetHeight(int32_t *aOffsetHeight) { return _to GetOffsetHeight(aOffsetHeight); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLELEMENT(_to) \
  NS_IMETHOD GetId(nsAString & aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_IMETHOD SetId(const nsAString & aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetId(aId); } \
  NS_IMETHOD GetTitle(nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_IMETHOD SetTitle(const nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTitle(aTitle); } \
  NS_IMETHOD GetLang(nsAString & aLang) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLang(aLang); } \
  NS_IMETHOD SetLang(const nsAString & aLang) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLang(aLang); } \
  NS_IMETHOD GetDir(nsAString & aDir) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDir(aDir); } \
  NS_IMETHOD SetDir(const nsAString & aDir) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDir(aDir); } \
  NS_IMETHOD GetDOMClassName(nsAString & aClassName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDOMClassName(aClassName); } \
  NS_IMETHOD SetDOMClassName(const nsAString & aClassName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDOMClassName(aClassName); } \
  NS_IMETHOD GetDataset(nsISupports * *aDataset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataset(aDataset); } \
  NS_IMETHOD GetItemScope(bool *aItemScope) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemScope(aItemScope); } \
  NS_IMETHOD SetItemScope(bool aItemScope) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemScope(aItemScope); } \
  NS_IMETHOD GetItemType(nsIVariant * *aItemType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemType(aItemType); } \
  NS_IMETHOD SetItemType(nsIVariant *aItemType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemType(aItemType); } \
  NS_IMETHOD GetItemId(nsAString & aItemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemId(aItemId); } \
  NS_IMETHOD SetItemId(const nsAString & aItemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemId(aItemId); } \
  NS_IMETHOD GetProperties(nsISupports * *aProperties) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProperties(aProperties); } \
  NS_IMETHOD GetItemValue(nsIVariant * *aItemValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemValue(aItemValue); } \
  NS_IMETHOD SetItemValue(nsIVariant *aItemValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemValue(aItemValue); } \
  NS_IMETHOD GetItemProp(nsIVariant * *aItemProp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemProp(aItemProp); } \
  NS_IMETHOD SetItemProp(nsIVariant *aItemProp) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemProp(aItemProp); } \
  NS_IMETHOD GetItemRef(nsIVariant * *aItemRef) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemRef(aItemRef); } \
  NS_IMETHOD SetItemRef(nsIVariant *aItemRef) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemRef(aItemRef); } \
  NS_IMETHOD GetHidden(bool *aHidden) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHidden(aHidden); } \
  NS_IMETHOD SetHidden(bool aHidden) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHidden(aHidden); } \
  NS_IMETHOD DOMClick(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DOMClick(); } \
  NS_IMETHOD GetTabIndex(int32_t *aTabIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTabIndex(aTabIndex); } \
  NS_IMETHOD SetTabIndex(int32_t aTabIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTabIndex(aTabIndex); } \
  NS_IMETHOD Focus(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Focus(); } \
  NS_IMETHOD DOMBlur(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DOMBlur(); } \
  NS_IMETHOD GetAccessKey(nsAString & aAccessKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessKey(aAccessKey); } \
  NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAccessKey(aAccessKey); } \
  NS_IMETHOD GetAccessKeyLabel(nsAString & aAccessKeyLabel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessKeyLabel(aAccessKeyLabel); } \
  NS_IMETHOD GetDraggable(bool *aDraggable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDraggable(aDraggable); } \
  NS_IMETHOD SetDraggable(bool aDraggable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDraggable(aDraggable); } \
  NS_IMETHOD GetContentEditable(nsAString & aContentEditable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentEditable(aContentEditable); } \
  NS_IMETHOD SetContentEditable(const nsAString & aContentEditable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentEditable(aContentEditable); } \
  NS_IMETHOD GetIsContentEditable(bool *aIsContentEditable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsContentEditable(aIsContentEditable); } \
  NS_IMETHOD GetContextMenu(nsIDOMHTMLMenuElement * *aContextMenu) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContextMenu(aContextMenu); } \
  NS_IMETHOD GetSpellcheck(bool *aSpellcheck) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSpellcheck(aSpellcheck); } \
  NS_IMETHOD SetSpellcheck(bool aSpellcheck) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSpellcheck(aSpellcheck); } \
  NS_IMETHOD GetInnerHTML(nsAString & aInnerHTML) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInnerHTML(aInnerHTML); } \
  NS_IMETHOD SetInnerHTML(const nsAString & aInnerHTML) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInnerHTML(aInnerHTML); } \
  NS_IMETHOD GetOuterHTML(nsAString & aOuterHTML) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOuterHTML(aOuterHTML); } \
  NS_IMETHOD SetOuterHTML(const nsAString & aOuterHTML) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOuterHTML(aOuterHTML); } \
  NS_IMETHOD InsertAdjacentHTML(const nsAString & position, const nsAString & text) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertAdjacentHTML(position, text); } \
  NS_IMETHOD ScrollIntoView(bool top, uint8_t _argc) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollIntoView(top, _argc); } \
  NS_IMETHOD GetOffsetParent(nsIDOMElement * *aOffsetParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffsetParent(aOffsetParent); } \
  NS_IMETHOD GetOffsetTop(int32_t *aOffsetTop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffsetTop(aOffsetTop); } \
  NS_IMETHOD GetOffsetLeft(int32_t *aOffsetLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffsetLeft(aOffsetLeft); } \
  NS_IMETHOD GetOffsetWidth(int32_t *aOffsetWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffsetWidth(aOffsetWidth); } \
  NS_IMETHOD GetOffsetHeight(int32_t *aOffsetHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffsetHeight(aOffsetHeight); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLElement : public nsIDOMHTMLElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLELEMENT

  nsDOMHTMLElement();

private:
  ~nsDOMHTMLElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLElement, nsIDOMHTMLElement)

nsDOMHTMLElement::nsDOMHTMLElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLElement::~nsDOMHTMLElement()
{
  /* destructor code */
}

/* attribute DOMString id; */
NS_IMETHODIMP nsDOMHTMLElement::GetId(nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetId(const nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString title; */
NS_IMETHODIMP nsDOMHTMLElement::GetTitle(nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetTitle(const nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString lang; */
NS_IMETHODIMP nsDOMHTMLElement::GetLang(nsAString & aLang)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetLang(const nsAString & aLang)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString dir; */
NS_IMETHODIMP nsDOMHTMLElement::GetDir(nsAString & aDir)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetDir(const nsAString & aDir)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(DOMClassName)] attribute DOMString className; */
NS_IMETHODIMP nsDOMHTMLElement::GetDOMClassName(nsAString & aClassName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetDOMClassName(const nsAString & aClassName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports dataset; */
NS_IMETHODIMP nsDOMHTMLElement::GetDataset(nsISupports * *aDataset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean itemScope; */
NS_IMETHODIMP nsDOMHTMLElement::GetItemScope(bool *aItemScope)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetItemScope(bool aItemScope)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIVariant itemType; */
NS_IMETHODIMP nsDOMHTMLElement::GetItemType(nsIVariant * *aItemType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetItemType(nsIVariant *aItemType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString itemId; */
NS_IMETHODIMP nsDOMHTMLElement::GetItemId(nsAString & aItemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetItemId(const nsAString & aItemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports properties; */
NS_IMETHODIMP nsDOMHTMLElement::GetProperties(nsISupports * *aProperties)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIVariant itemValue; */
NS_IMETHODIMP nsDOMHTMLElement::GetItemValue(nsIVariant * *aItemValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetItemValue(nsIVariant *aItemValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIVariant itemProp; */
NS_IMETHODIMP nsDOMHTMLElement::GetItemProp(nsIVariant * *aItemProp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetItemProp(nsIVariant *aItemProp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIVariant itemRef; */
NS_IMETHODIMP nsDOMHTMLElement::GetItemRef(nsIVariant * *aItemRef)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetItemRef(nsIVariant *aItemRef)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean hidden; */
NS_IMETHODIMP nsDOMHTMLElement::GetHidden(bool *aHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetHidden(bool aHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(DOMClick)] void click (); */
NS_IMETHODIMP nsDOMHTMLElement::DOMClick()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long tabIndex; */
NS_IMETHODIMP nsDOMHTMLElement::GetTabIndex(int32_t *aTabIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetTabIndex(int32_t aTabIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void focus (); */
NS_IMETHODIMP nsDOMHTMLElement::Focus()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(DOMBlur)] void blur (); */
NS_IMETHODIMP nsDOMHTMLElement::DOMBlur()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString accessKey; */
NS_IMETHODIMP nsDOMHTMLElement::GetAccessKey(nsAString & aAccessKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetAccessKey(const nsAString & aAccessKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString accessKeyLabel; */
NS_IMETHODIMP nsDOMHTMLElement::GetAccessKeyLabel(nsAString & aAccessKeyLabel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean draggable; */
NS_IMETHODIMP nsDOMHTMLElement::GetDraggable(bool *aDraggable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetDraggable(bool aDraggable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString contentEditable; */
NS_IMETHODIMP nsDOMHTMLElement::GetContentEditable(nsAString & aContentEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetContentEditable(const nsAString & aContentEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isContentEditable; */
NS_IMETHODIMP nsDOMHTMLElement::GetIsContentEditable(bool *aIsContentEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLMenuElement contextMenu; */
NS_IMETHODIMP nsDOMHTMLElement::GetContextMenu(nsIDOMHTMLMenuElement * *aContextMenu)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean spellcheck; */
NS_IMETHODIMP nsDOMHTMLElement::GetSpellcheck(bool *aSpellcheck)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetSpellcheck(bool aSpellcheck)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString innerHTML; */
NS_IMETHODIMP nsDOMHTMLElement::GetInnerHTML(nsAString & aInnerHTML)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetInnerHTML(const nsAString & aInnerHTML)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString outerHTML; */
NS_IMETHODIMP nsDOMHTMLElement::GetOuterHTML(nsAString & aOuterHTML)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetOuterHTML(const nsAString & aOuterHTML)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertAdjacentHTML (in DOMString position, in DOMString text); */
NS_IMETHODIMP nsDOMHTMLElement::InsertAdjacentHTML(const nsAString & position, const nsAString & text)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] void scrollIntoView ([optional] in boolean top); */
NS_IMETHODIMP nsDOMHTMLElement::ScrollIntoView(bool top, uint8_t _argc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement offsetParent; */
NS_IMETHODIMP nsDOMHTMLElement::GetOffsetParent(nsIDOMElement * *aOffsetParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long offsetTop; */
NS_IMETHODIMP nsDOMHTMLElement::GetOffsetTop(int32_t *aOffsetTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long offsetLeft; */
NS_IMETHODIMP nsDOMHTMLElement::GetOffsetLeft(int32_t *aOffsetLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long offsetWidth; */
NS_IMETHODIMP nsDOMHTMLElement::GetOffsetWidth(int32_t *aOffsetWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long offsetHeight; */
NS_IMETHODIMP nsDOMHTMLElement::GetOffsetHeight(int32_t *aOffsetHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLElement_h__ */

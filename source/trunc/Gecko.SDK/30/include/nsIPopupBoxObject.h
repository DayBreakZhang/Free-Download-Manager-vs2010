/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPopupBoxObject.idl
 */

#ifndef __gen_nsIPopupBoxObject_h__
#define __gen_nsIPopupBoxObject_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsIDOMEvent; /* forward declaration */

class nsIDOMClientRect; /* forward declaration */


/* starting interface:    nsIPopupBoxObject */
#define NS_IPOPUPBOXOBJECT_IID_STR "b1192cac-467b-42ca-88d6-fcdec5bb4ef7"

#define NS_IPOPUPBOXOBJECT_IID \
  {0xb1192cac, 0x467b, 0x42ca, \
    { 0x88, 0xd6, 0xfc, 0xde, 0xc5, 0xbb, 0x4e, 0xf7 }}

class NS_NO_VTABLE nsIPopupBoxObject : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPOPUPBOXOBJECT_IID)

  /* void showPopup (in nsIDOMElement srcContent, in nsIDOMElement popupContent, in long xpos, in long ypos, in wstring popupType, in wstring anchorAlignment, in wstring popupAlignment); */
  NS_IMETHOD ShowPopup(nsIDOMElement *srcContent, nsIDOMElement *popupContent, int32_t xpos, int32_t ypos, const char16_t * popupType, const char16_t * anchorAlignment, const char16_t * popupAlignment) = 0;

  /* void hidePopup (); */
  NS_IMETHOD HidePopup(void) = 0;

  /* attribute boolean autoPosition; */
  NS_IMETHOD GetAutoPosition(bool *aAutoPosition) = 0;
  NS_IMETHOD SetAutoPosition(bool aAutoPosition) = 0;

  /* void enableKeyboardNavigator (in boolean enableKeyboardNavigator); */
  NS_IMETHOD EnableKeyboardNavigator(bool enableKeyboardNavigator) = 0;

  /* void enableRollup (in boolean enableRollup); */
  NS_IMETHOD EnableRollup(bool enableRollup) = 0;

  enum {
    ROLLUP_DEFAULT = 0U,
    ROLLUP_CONSUME = 1U,
    ROLLUP_NO_CONSUME = 2U
  };

  /* void setConsumeRollupEvent (in uint32_t consume); */
  NS_IMETHOD SetConsumeRollupEvent(uint32_t consume) = 0;

  /* void sizeTo (in long width, in long height); */
  NS_IMETHOD SizeTo(int32_t width, int32_t height) = 0;

  /* void moveTo (in long left, in long top); */
  NS_IMETHOD MoveTo(int32_t left, int32_t top) = 0;

  /* void openPopup (in nsIDOMElement anchorElement, in AString position, in long x, in long y, in boolean isContextMenu, in boolean attributesOverride, in nsIDOMEvent triggerEvent); */
  NS_IMETHOD OpenPopup(nsIDOMElement *anchorElement, const nsAString & position, int32_t x, int32_t y, bool isContextMenu, bool attributesOverride, nsIDOMEvent *triggerEvent) = 0;

  /* void openPopupAtScreen (in long x, in long y, in boolean isContextMenu, in nsIDOMEvent triggerEvent); */
  NS_IMETHOD OpenPopupAtScreen(int32_t x, int32_t y, bool isContextMenu, nsIDOMEvent *triggerEvent) = 0;

  /* readonly attribute AString popupState; */
  NS_IMETHOD GetPopupState(nsAString & aPopupState) = 0;

  /* readonly attribute nsIDOMNode triggerNode; */
  NS_IMETHOD GetTriggerNode(nsIDOMNode * *aTriggerNode) = 0;

  /* readonly attribute nsIDOMElement anchorNode; */
  NS_IMETHOD GetAnchorNode(nsIDOMElement * *aAnchorNode) = 0;

  /* nsIDOMClientRect getOuterScreenRect (); */
  NS_IMETHOD GetOuterScreenRect(nsIDOMClientRect * *_retval) = 0;

  /* void moveToAnchor (in nsIDOMElement anchorElement, in AString position, in long x, in long y, in boolean attributesOverride); */
  NS_IMETHOD MoveToAnchor(nsIDOMElement *anchorElement, const nsAString & position, int32_t x, int32_t y, bool attributesOverride) = 0;

  /* readonly attribute AString alignmentPosition; */
  NS_IMETHOD GetAlignmentPosition(nsAString & aAlignmentPosition) = 0;

  /* readonly attribute long alignmentOffset; */
  NS_IMETHOD GetAlignmentOffset(int32_t *aAlignmentOffset) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPopupBoxObject, NS_IPOPUPBOXOBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPOPUPBOXOBJECT \
  NS_IMETHOD ShowPopup(nsIDOMElement *srcContent, nsIDOMElement *popupContent, int32_t xpos, int32_t ypos, const char16_t * popupType, const char16_t * anchorAlignment, const char16_t * popupAlignment); \
  NS_IMETHOD HidePopup(void); \
  NS_IMETHOD GetAutoPosition(bool *aAutoPosition); \
  NS_IMETHOD SetAutoPosition(bool aAutoPosition); \
  NS_IMETHOD EnableKeyboardNavigator(bool enableKeyboardNavigator); \
  NS_IMETHOD EnableRollup(bool enableRollup); \
  NS_IMETHOD SetConsumeRollupEvent(uint32_t consume); \
  NS_IMETHOD SizeTo(int32_t width, int32_t height); \
  NS_IMETHOD MoveTo(int32_t left, int32_t top); \
  NS_IMETHOD OpenPopup(nsIDOMElement *anchorElement, const nsAString & position, int32_t x, int32_t y, bool isContextMenu, bool attributesOverride, nsIDOMEvent *triggerEvent); \
  NS_IMETHOD OpenPopupAtScreen(int32_t x, int32_t y, bool isContextMenu, nsIDOMEvent *triggerEvent); \
  NS_IMETHOD GetPopupState(nsAString & aPopupState); \
  NS_IMETHOD GetTriggerNode(nsIDOMNode * *aTriggerNode); \
  NS_IMETHOD GetAnchorNode(nsIDOMElement * *aAnchorNode); \
  NS_IMETHOD GetOuterScreenRect(nsIDOMClientRect * *_retval); \
  NS_IMETHOD MoveToAnchor(nsIDOMElement *anchorElement, const nsAString & position, int32_t x, int32_t y, bool attributesOverride); \
  NS_IMETHOD GetAlignmentPosition(nsAString & aAlignmentPosition); \
  NS_IMETHOD GetAlignmentOffset(int32_t *aAlignmentOffset); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPOPUPBOXOBJECT(_to) \
  NS_IMETHOD ShowPopup(nsIDOMElement *srcContent, nsIDOMElement *popupContent, int32_t xpos, int32_t ypos, const char16_t * popupType, const char16_t * anchorAlignment, const char16_t * popupAlignment) { return _to ShowPopup(srcContent, popupContent, xpos, ypos, popupType, anchorAlignment, popupAlignment); } \
  NS_IMETHOD HidePopup(void) { return _to HidePopup(); } \
  NS_IMETHOD GetAutoPosition(bool *aAutoPosition) { return _to GetAutoPosition(aAutoPosition); } \
  NS_IMETHOD SetAutoPosition(bool aAutoPosition) { return _to SetAutoPosition(aAutoPosition); } \
  NS_IMETHOD EnableKeyboardNavigator(bool enableKeyboardNavigator) { return _to EnableKeyboardNavigator(enableKeyboardNavigator); } \
  NS_IMETHOD EnableRollup(bool enableRollup) { return _to EnableRollup(enableRollup); } \
  NS_IMETHOD SetConsumeRollupEvent(uint32_t consume) { return _to SetConsumeRollupEvent(consume); } \
  NS_IMETHOD SizeTo(int32_t width, int32_t height) { return _to SizeTo(width, height); } \
  NS_IMETHOD MoveTo(int32_t left, int32_t top) { return _to MoveTo(left, top); } \
  NS_IMETHOD OpenPopup(nsIDOMElement *anchorElement, const nsAString & position, int32_t x, int32_t y, bool isContextMenu, bool attributesOverride, nsIDOMEvent *triggerEvent) { return _to OpenPopup(anchorElement, position, x, y, isContextMenu, attributesOverride, triggerEvent); } \
  NS_IMETHOD OpenPopupAtScreen(int32_t x, int32_t y, bool isContextMenu, nsIDOMEvent *triggerEvent) { return _to OpenPopupAtScreen(x, y, isContextMenu, triggerEvent); } \
  NS_IMETHOD GetPopupState(nsAString & aPopupState) { return _to GetPopupState(aPopupState); } \
  NS_IMETHOD GetTriggerNode(nsIDOMNode * *aTriggerNode) { return _to GetTriggerNode(aTriggerNode); } \
  NS_IMETHOD GetAnchorNode(nsIDOMElement * *aAnchorNode) { return _to GetAnchorNode(aAnchorNode); } \
  NS_IMETHOD GetOuterScreenRect(nsIDOMClientRect * *_retval) { return _to GetOuterScreenRect(_retval); } \
  NS_IMETHOD MoveToAnchor(nsIDOMElement *anchorElement, const nsAString & position, int32_t x, int32_t y, bool attributesOverride) { return _to MoveToAnchor(anchorElement, position, x, y, attributesOverride); } \
  NS_IMETHOD GetAlignmentPosition(nsAString & aAlignmentPosition) { return _to GetAlignmentPosition(aAlignmentPosition); } \
  NS_IMETHOD GetAlignmentOffset(int32_t *aAlignmentOffset) { return _to GetAlignmentOffset(aAlignmentOffset); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPOPUPBOXOBJECT(_to) \
  NS_IMETHOD ShowPopup(nsIDOMElement *srcContent, nsIDOMElement *popupContent, int32_t xpos, int32_t ypos, const char16_t * popupType, const char16_t * anchorAlignment, const char16_t * popupAlignment) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowPopup(srcContent, popupContent, xpos, ypos, popupType, anchorAlignment, popupAlignment); } \
  NS_IMETHOD HidePopup(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->HidePopup(); } \
  NS_IMETHOD GetAutoPosition(bool *aAutoPosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAutoPosition(aAutoPosition); } \
  NS_IMETHOD SetAutoPosition(bool aAutoPosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAutoPosition(aAutoPosition); } \
  NS_IMETHOD EnableKeyboardNavigator(bool enableKeyboardNavigator) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableKeyboardNavigator(enableKeyboardNavigator); } \
  NS_IMETHOD EnableRollup(bool enableRollup) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableRollup(enableRollup); } \
  NS_IMETHOD SetConsumeRollupEvent(uint32_t consume) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetConsumeRollupEvent(consume); } \
  NS_IMETHOD SizeTo(int32_t width, int32_t height) { return !_to ? NS_ERROR_NULL_POINTER : _to->SizeTo(width, height); } \
  NS_IMETHOD MoveTo(int32_t left, int32_t top) { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveTo(left, top); } \
  NS_IMETHOD OpenPopup(nsIDOMElement *anchorElement, const nsAString & position, int32_t x, int32_t y, bool isContextMenu, bool attributesOverride, nsIDOMEvent *triggerEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenPopup(anchorElement, position, x, y, isContextMenu, attributesOverride, triggerEvent); } \
  NS_IMETHOD OpenPopupAtScreen(int32_t x, int32_t y, bool isContextMenu, nsIDOMEvent *triggerEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenPopupAtScreen(x, y, isContextMenu, triggerEvent); } \
  NS_IMETHOD GetPopupState(nsAString & aPopupState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPopupState(aPopupState); } \
  NS_IMETHOD GetTriggerNode(nsIDOMNode * *aTriggerNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTriggerNode(aTriggerNode); } \
  NS_IMETHOD GetAnchorNode(nsIDOMElement * *aAnchorNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnchorNode(aAnchorNode); } \
  NS_IMETHOD GetOuterScreenRect(nsIDOMClientRect * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOuterScreenRect(_retval); } \
  NS_IMETHOD MoveToAnchor(nsIDOMElement *anchorElement, const nsAString & position, int32_t x, int32_t y, bool attributesOverride) { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveToAnchor(anchorElement, position, x, y, attributesOverride); } \
  NS_IMETHOD GetAlignmentPosition(nsAString & aAlignmentPosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlignmentPosition(aAlignmentPosition); } \
  NS_IMETHOD GetAlignmentOffset(int32_t *aAlignmentOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlignmentOffset(aAlignmentOffset); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPopupBoxObject : public nsIPopupBoxObject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPOPUPBOXOBJECT

  nsPopupBoxObject();

private:
  ~nsPopupBoxObject();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPopupBoxObject, nsIPopupBoxObject)

nsPopupBoxObject::nsPopupBoxObject()
{
  /* member initializers and constructor code */
}

nsPopupBoxObject::~nsPopupBoxObject()
{
  /* destructor code */
}

/* void showPopup (in nsIDOMElement srcContent, in nsIDOMElement popupContent, in long xpos, in long ypos, in wstring popupType, in wstring anchorAlignment, in wstring popupAlignment); */
NS_IMETHODIMP nsPopupBoxObject::ShowPopup(nsIDOMElement *srcContent, nsIDOMElement *popupContent, int32_t xpos, int32_t ypos, const char16_t * popupType, const char16_t * anchorAlignment, const char16_t * popupAlignment)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void hidePopup (); */
NS_IMETHODIMP nsPopupBoxObject::HidePopup()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean autoPosition; */
NS_IMETHODIMP nsPopupBoxObject::GetAutoPosition(bool *aAutoPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPopupBoxObject::SetAutoPosition(bool aAutoPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enableKeyboardNavigator (in boolean enableKeyboardNavigator); */
NS_IMETHODIMP nsPopupBoxObject::EnableKeyboardNavigator(bool enableKeyboardNavigator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enableRollup (in boolean enableRollup); */
NS_IMETHODIMP nsPopupBoxObject::EnableRollup(bool enableRollup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setConsumeRollupEvent (in uint32_t consume); */
NS_IMETHODIMP nsPopupBoxObject::SetConsumeRollupEvent(uint32_t consume)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sizeTo (in long width, in long height); */
NS_IMETHODIMP nsPopupBoxObject::SizeTo(int32_t width, int32_t height)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void moveTo (in long left, in long top); */
NS_IMETHODIMP nsPopupBoxObject::MoveTo(int32_t left, int32_t top)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void openPopup (in nsIDOMElement anchorElement, in AString position, in long x, in long y, in boolean isContextMenu, in boolean attributesOverride, in nsIDOMEvent triggerEvent); */
NS_IMETHODIMP nsPopupBoxObject::OpenPopup(nsIDOMElement *anchorElement, const nsAString & position, int32_t x, int32_t y, bool isContextMenu, bool attributesOverride, nsIDOMEvent *triggerEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void openPopupAtScreen (in long x, in long y, in boolean isContextMenu, in nsIDOMEvent triggerEvent); */
NS_IMETHODIMP nsPopupBoxObject::OpenPopupAtScreen(int32_t x, int32_t y, bool isContextMenu, nsIDOMEvent *triggerEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString popupState; */
NS_IMETHODIMP nsPopupBoxObject::GetPopupState(nsAString & aPopupState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode triggerNode; */
NS_IMETHODIMP nsPopupBoxObject::GetTriggerNode(nsIDOMNode * *aTriggerNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement anchorNode; */
NS_IMETHODIMP nsPopupBoxObject::GetAnchorNode(nsIDOMElement * *aAnchorNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMClientRect getOuterScreenRect (); */
NS_IMETHODIMP nsPopupBoxObject::GetOuterScreenRect(nsIDOMClientRect * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void moveToAnchor (in nsIDOMElement anchorElement, in AString position, in long x, in long y, in boolean attributesOverride); */
NS_IMETHODIMP nsPopupBoxObject::MoveToAnchor(nsIDOMElement *anchorElement, const nsAString & position, int32_t x, int32_t y, bool attributesOverride)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString alignmentPosition; */
NS_IMETHODIMP nsPopupBoxObject::GetAlignmentPosition(nsAString & aAlignmentPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long alignmentOffset; */
NS_IMETHODIMP nsPopupBoxObject::GetAlignmentOffset(int32_t *aAlignmentOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

class nsIBoxObject;
nsresult
NS_NewPopupBoxObject(nsIBoxObject** aResult);

#endif /* __gen_nsIPopupBoxObject_h__ */

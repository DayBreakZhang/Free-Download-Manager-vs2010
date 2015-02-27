/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/accessible/public/nsIAccessible.idl
 */

#ifndef __gen_nsIAccessible_h__
#define __gen_nsIAccessible_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIArray_h__
#include "nsIArray.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPersistentProperties; /* forward declaration */

class nsIDOMCSSPrimitiveValue; /* forward declaration */

class nsIDOMDOMStringList; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsIAccessibleDocument; /* forward declaration */

class nsIAccessibleRelation; /* forward declaration */


/* starting interface:    nsIAccessible */
#define NS_IACCESSIBLE_IID_STR "45600c50-b06a-11e1-afa6-0800200c9a66"

#define NS_IACCESSIBLE_IID \
  {0x45600c50, 0xb06a, 0x11e1, \
    { 0xaf, 0xa6, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIAccessible : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLE_IID)

  /* readonly attribute nsIAccessible parent; */
  NS_IMETHOD GetParent(nsIAccessible * *aParent) = 0;

  /* readonly attribute nsIAccessible nextSibling; */
  NS_IMETHOD GetNextSibling(nsIAccessible * *aNextSibling) = 0;

  /* readonly attribute nsIAccessible previousSibling; */
  NS_IMETHOD GetPreviousSibling(nsIAccessible * *aPreviousSibling) = 0;

  /* readonly attribute nsIAccessible firstChild; */
  NS_IMETHOD GetFirstChild(nsIAccessible * *aFirstChild) = 0;

  /* readonly attribute nsIAccessible lastChild; */
  NS_IMETHOD GetLastChild(nsIAccessible * *aLastChild) = 0;

  /* readonly attribute nsIArray children; */
  NS_IMETHOD GetChildren(nsIArray * *aChildren) = 0;

  /* readonly attribute long childCount; */
  NS_IMETHOD GetChildCount(int32_t *aChildCount) = 0;

  /* readonly attribute long indexInParent; */
  NS_IMETHOD GetIndexInParent(int32_t *aIndexInParent) = 0;

  /* readonly attribute nsIDOMNode DOMNode; */
  NS_IMETHOD GetDOMNode(nsIDOMNode * *aDOMNode) = 0;

  /* readonly attribute nsIAccessibleDocument document; */
  NS_IMETHOD GetDocument(nsIAccessibleDocument * *aDocument) = 0;

  /* readonly attribute nsIAccessibleDocument rootDocument; */
  NS_IMETHOD GetRootDocument(nsIAccessibleDocument * *aRootDocument) = 0;

  /* readonly attribute DOMString language; */
  NS_IMETHOD GetLanguage(nsAString & aLanguage) = 0;

  /* attribute AString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_IMETHOD SetName(const nsAString & aName) = 0;

  /* readonly attribute AString value; */
  NS_IMETHOD GetValue(nsAString & aValue) = 0;

  /* readonly attribute AString description; */
  NS_IMETHOD GetDescription(nsAString & aDescription) = 0;

  /* readonly attribute AString accessKey; */
  NS_IMETHOD GetAccessKey(nsAString & aAccessKey) = 0;

  /* readonly attribute AString keyboardShortcut; */
  NS_IMETHOD GetKeyboardShortcut(nsAString & aKeyboardShortcut) = 0;

  /* readonly attribute unsigned long role; */
  NS_IMETHOD GetRole(uint32_t *aRole) = 0;

  /* void getState (out unsigned long aState, out unsigned long aExtraState); */
  NS_IMETHOD GetState(uint32_t *aState, uint32_t *aExtraState) = 0;

  /* readonly attribute AString help; */
  NS_IMETHOD GetHelp(nsAString & aHelp) = 0;

  /* readonly attribute nsIAccessible focusedChild; */
  NS_IMETHOD GetFocusedChild(nsIAccessible * *aFocusedChild) = 0;

  /* readonly attribute nsIPersistentProperties attributes; */
  NS_IMETHOD GetAttributes(nsIPersistentProperties * *aAttributes) = 0;

  /* void groupPosition (out long aGroupLevel, out long aSimilarItemsInGroup, out long aPositionInGroup); */
  NS_IMETHOD GroupPosition(int32_t *aGroupLevel, int32_t *aSimilarItemsInGroup, int32_t *aPositionInGroup) = 0;

  /* nsIAccessible getChildAtPoint (in long x, in long y); */
  NS_IMETHOD GetChildAtPoint(int32_t x, int32_t y, nsIAccessible * *_retval) = 0;

  /* nsIAccessible getDeepestChildAtPoint (in long x, in long y); */
  NS_IMETHOD GetDeepestChildAtPoint(int32_t x, int32_t y, nsIAccessible * *_retval) = 0;

  /* nsIAccessible getChildAt (in long aChildIndex); */
  NS_IMETHOD GetChildAt(int32_t aChildIndex, nsIAccessible * *_retval) = 0;

  /* nsIAccessibleRelation getRelationByType (in unsigned long aRelationType); */
  NS_IMETHOD GetRelationByType(uint32_t aRelationType, nsIAccessibleRelation * *_retval) = 0;

  /* nsIArray getRelations (); */
  NS_IMETHOD GetRelations(nsIArray * *_retval) = 0;

  /* void getBounds (out long x, out long y, out long width, out long height); */
  NS_IMETHOD GetBounds(int32_t *x, int32_t *y, int32_t *width, int32_t *height) = 0;

  /* void setSelected (in boolean isSelected); */
  NS_IMETHOD SetSelected(bool isSelected) = 0;

  /* void extendSelection (); */
  NS_IMETHOD ExtendSelection(void) = 0;

  /* void takeSelection (); */
  NS_IMETHOD TakeSelection(void) = 0;

  /* void takeFocus (); */
  NS_IMETHOD TakeFocus(void) = 0;

  /* readonly attribute uint8_t actionCount; */
  NS_IMETHOD GetActionCount(uint8_t *aActionCount) = 0;

  /* AString getActionName (in uint8_t index); */
  NS_IMETHOD GetActionName(uint8_t index, nsAString & _retval) = 0;

  /* AString getActionDescription (in uint8_t aIndex); */
  NS_IMETHOD GetActionDescription(uint8_t aIndex, nsAString & _retval) = 0;

  /* void doAction (in uint8_t index); */
  NS_IMETHOD DoAction(uint8_t index) = 0;

  /* void scrollTo (in unsigned long aScrollType); */
  NS_IMETHOD ScrollTo(uint32_t aScrollType) = 0;

  /* void scrollToPoint (in unsigned long coordinateType, in long x, in long y); */
  NS_IMETHOD ScrollToPoint(uint32_t coordinateType, int32_t x, int32_t y) = 0;

  /* [noscript] void getNativeInterface (out voidPtr aOutAccessible); */
  NS_IMETHOD GetNativeInterface(void **aOutAccessible) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessible, NS_IACCESSIBLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLE \
  NS_IMETHOD GetParent(nsIAccessible * *aParent); \
  NS_IMETHOD GetNextSibling(nsIAccessible * *aNextSibling); \
  NS_IMETHOD GetPreviousSibling(nsIAccessible * *aPreviousSibling); \
  NS_IMETHOD GetFirstChild(nsIAccessible * *aFirstChild); \
  NS_IMETHOD GetLastChild(nsIAccessible * *aLastChild); \
  NS_IMETHOD GetChildren(nsIArray * *aChildren); \
  NS_IMETHOD GetChildCount(int32_t *aChildCount); \
  NS_IMETHOD GetIndexInParent(int32_t *aIndexInParent); \
  NS_IMETHOD GetDOMNode(nsIDOMNode * *aDOMNode); \
  NS_IMETHOD GetDocument(nsIAccessibleDocument * *aDocument); \
  NS_IMETHOD GetRootDocument(nsIAccessibleDocument * *aRootDocument); \
  NS_IMETHOD GetLanguage(nsAString & aLanguage); \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD SetName(const nsAString & aName); \
  NS_IMETHOD GetValue(nsAString & aValue); \
  NS_IMETHOD GetDescription(nsAString & aDescription); \
  NS_IMETHOD GetAccessKey(nsAString & aAccessKey); \
  NS_IMETHOD GetKeyboardShortcut(nsAString & aKeyboardShortcut); \
  NS_IMETHOD GetRole(uint32_t *aRole); \
  NS_IMETHOD GetState(uint32_t *aState, uint32_t *aExtraState); \
  NS_IMETHOD GetHelp(nsAString & aHelp); \
  NS_IMETHOD GetFocusedChild(nsIAccessible * *aFocusedChild); \
  NS_IMETHOD GetAttributes(nsIPersistentProperties * *aAttributes); \
  NS_IMETHOD GroupPosition(int32_t *aGroupLevel, int32_t *aSimilarItemsInGroup, int32_t *aPositionInGroup); \
  NS_IMETHOD GetChildAtPoint(int32_t x, int32_t y, nsIAccessible * *_retval); \
  NS_IMETHOD GetDeepestChildAtPoint(int32_t x, int32_t y, nsIAccessible * *_retval); \
  NS_IMETHOD GetChildAt(int32_t aChildIndex, nsIAccessible * *_retval); \
  NS_IMETHOD GetRelationByType(uint32_t aRelationType, nsIAccessibleRelation * *_retval); \
  NS_IMETHOD GetRelations(nsIArray * *_retval); \
  NS_IMETHOD GetBounds(int32_t *x, int32_t *y, int32_t *width, int32_t *height); \
  NS_IMETHOD SetSelected(bool isSelected); \
  NS_IMETHOD ExtendSelection(void); \
  NS_IMETHOD TakeSelection(void); \
  NS_IMETHOD TakeFocus(void); \
  NS_IMETHOD GetActionCount(uint8_t *aActionCount); \
  NS_IMETHOD GetActionName(uint8_t index, nsAString & _retval); \
  NS_IMETHOD GetActionDescription(uint8_t aIndex, nsAString & _retval); \
  NS_IMETHOD DoAction(uint8_t index); \
  NS_IMETHOD ScrollTo(uint32_t aScrollType); \
  NS_IMETHOD ScrollToPoint(uint32_t coordinateType, int32_t x, int32_t y); \
  NS_IMETHOD GetNativeInterface(void **aOutAccessible); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLE(_to) \
  NS_IMETHOD GetParent(nsIAccessible * *aParent) { return _to GetParent(aParent); } \
  NS_IMETHOD GetNextSibling(nsIAccessible * *aNextSibling) { return _to GetNextSibling(aNextSibling); } \
  NS_IMETHOD GetPreviousSibling(nsIAccessible * *aPreviousSibling) { return _to GetPreviousSibling(aPreviousSibling); } \
  NS_IMETHOD GetFirstChild(nsIAccessible * *aFirstChild) { return _to GetFirstChild(aFirstChild); } \
  NS_IMETHOD GetLastChild(nsIAccessible * *aLastChild) { return _to GetLastChild(aLastChild); } \
  NS_IMETHOD GetChildren(nsIArray * *aChildren) { return _to GetChildren(aChildren); } \
  NS_IMETHOD GetChildCount(int32_t *aChildCount) { return _to GetChildCount(aChildCount); } \
  NS_IMETHOD GetIndexInParent(int32_t *aIndexInParent) { return _to GetIndexInParent(aIndexInParent); } \
  NS_IMETHOD GetDOMNode(nsIDOMNode * *aDOMNode) { return _to GetDOMNode(aDOMNode); } \
  NS_IMETHOD GetDocument(nsIAccessibleDocument * *aDocument) { return _to GetDocument(aDocument); } \
  NS_IMETHOD GetRootDocument(nsIAccessibleDocument * *aRootDocument) { return _to GetRootDocument(aRootDocument); } \
  NS_IMETHOD GetLanguage(nsAString & aLanguage) { return _to GetLanguage(aLanguage); } \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) { return _to SetName(aName); } \
  NS_IMETHOD GetValue(nsAString & aValue) { return _to GetValue(aValue); } \
  NS_IMETHOD GetDescription(nsAString & aDescription) { return _to GetDescription(aDescription); } \
  NS_IMETHOD GetAccessKey(nsAString & aAccessKey) { return _to GetAccessKey(aAccessKey); } \
  NS_IMETHOD GetKeyboardShortcut(nsAString & aKeyboardShortcut) { return _to GetKeyboardShortcut(aKeyboardShortcut); } \
  NS_IMETHOD GetRole(uint32_t *aRole) { return _to GetRole(aRole); } \
  NS_IMETHOD GetState(uint32_t *aState, uint32_t *aExtraState) { return _to GetState(aState, aExtraState); } \
  NS_IMETHOD GetHelp(nsAString & aHelp) { return _to GetHelp(aHelp); } \
  NS_IMETHOD GetFocusedChild(nsIAccessible * *aFocusedChild) { return _to GetFocusedChild(aFocusedChild); } \
  NS_IMETHOD GetAttributes(nsIPersistentProperties * *aAttributes) { return _to GetAttributes(aAttributes); } \
  NS_IMETHOD GroupPosition(int32_t *aGroupLevel, int32_t *aSimilarItemsInGroup, int32_t *aPositionInGroup) { return _to GroupPosition(aGroupLevel, aSimilarItemsInGroup, aPositionInGroup); } \
  NS_IMETHOD GetChildAtPoint(int32_t x, int32_t y, nsIAccessible * *_retval) { return _to GetChildAtPoint(x, y, _retval); } \
  NS_IMETHOD GetDeepestChildAtPoint(int32_t x, int32_t y, nsIAccessible * *_retval) { return _to GetDeepestChildAtPoint(x, y, _retval); } \
  NS_IMETHOD GetChildAt(int32_t aChildIndex, nsIAccessible * *_retval) { return _to GetChildAt(aChildIndex, _retval); } \
  NS_IMETHOD GetRelationByType(uint32_t aRelationType, nsIAccessibleRelation * *_retval) { return _to GetRelationByType(aRelationType, _retval); } \
  NS_IMETHOD GetRelations(nsIArray * *_retval) { return _to GetRelations(_retval); } \
  NS_IMETHOD GetBounds(int32_t *x, int32_t *y, int32_t *width, int32_t *height) { return _to GetBounds(x, y, width, height); } \
  NS_IMETHOD SetSelected(bool isSelected) { return _to SetSelected(isSelected); } \
  NS_IMETHOD ExtendSelection(void) { return _to ExtendSelection(); } \
  NS_IMETHOD TakeSelection(void) { return _to TakeSelection(); } \
  NS_IMETHOD TakeFocus(void) { return _to TakeFocus(); } \
  NS_IMETHOD GetActionCount(uint8_t *aActionCount) { return _to GetActionCount(aActionCount); } \
  NS_IMETHOD GetActionName(uint8_t index, nsAString & _retval) { return _to GetActionName(index, _retval); } \
  NS_IMETHOD GetActionDescription(uint8_t aIndex, nsAString & _retval) { return _to GetActionDescription(aIndex, _retval); } \
  NS_IMETHOD DoAction(uint8_t index) { return _to DoAction(index); } \
  NS_IMETHOD ScrollTo(uint32_t aScrollType) { return _to ScrollTo(aScrollType); } \
  NS_IMETHOD ScrollToPoint(uint32_t coordinateType, int32_t x, int32_t y) { return _to ScrollToPoint(coordinateType, x, y); } \
  NS_IMETHOD GetNativeInterface(void **aOutAccessible) { return _to GetNativeInterface(aOutAccessible); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLE(_to) \
  NS_IMETHOD GetParent(nsIAccessible * *aParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParent(aParent); } \
  NS_IMETHOD GetNextSibling(nsIAccessible * *aNextSibling) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNextSibling(aNextSibling); } \
  NS_IMETHOD GetPreviousSibling(nsIAccessible * *aPreviousSibling) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreviousSibling(aPreviousSibling); } \
  NS_IMETHOD GetFirstChild(nsIAccessible * *aFirstChild) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFirstChild(aFirstChild); } \
  NS_IMETHOD GetLastChild(nsIAccessible * *aLastChild) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastChild(aLastChild); } \
  NS_IMETHOD GetChildren(nsIArray * *aChildren) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildren(aChildren); } \
  NS_IMETHOD GetChildCount(int32_t *aChildCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildCount(aChildCount); } \
  NS_IMETHOD GetIndexInParent(int32_t *aIndexInParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexInParent(aIndexInParent); } \
  NS_IMETHOD GetDOMNode(nsIDOMNode * *aDOMNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDOMNode(aDOMNode); } \
  NS_IMETHOD GetDocument(nsIAccessibleDocument * *aDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocument(aDocument); } \
  NS_IMETHOD GetRootDocument(nsIAccessibleDocument * *aRootDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootDocument(aRootDocument); } \
  NS_IMETHOD GetLanguage(nsAString & aLanguage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLanguage(aLanguage); } \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_IMETHOD GetValue(nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_IMETHOD GetDescription(nsAString & aDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDescription(aDescription); } \
  NS_IMETHOD GetAccessKey(nsAString & aAccessKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessKey(aAccessKey); } \
  NS_IMETHOD GetKeyboardShortcut(nsAString & aKeyboardShortcut) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeyboardShortcut(aKeyboardShortcut); } \
  NS_IMETHOD GetRole(uint32_t *aRole) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRole(aRole); } \
  NS_IMETHOD GetState(uint32_t *aState, uint32_t *aExtraState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState, aExtraState); } \
  NS_IMETHOD GetHelp(nsAString & aHelp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHelp(aHelp); } \
  NS_IMETHOD GetFocusedChild(nsIAccessible * *aFocusedChild) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocusedChild(aFocusedChild); } \
  NS_IMETHOD GetAttributes(nsIPersistentProperties * *aAttributes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttributes(aAttributes); } \
  NS_IMETHOD GroupPosition(int32_t *aGroupLevel, int32_t *aSimilarItemsInGroup, int32_t *aPositionInGroup) { return !_to ? NS_ERROR_NULL_POINTER : _to->GroupPosition(aGroupLevel, aSimilarItemsInGroup, aPositionInGroup); } \
  NS_IMETHOD GetChildAtPoint(int32_t x, int32_t y, nsIAccessible * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildAtPoint(x, y, _retval); } \
  NS_IMETHOD GetDeepestChildAtPoint(int32_t x, int32_t y, nsIAccessible * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDeepestChildAtPoint(x, y, _retval); } \
  NS_IMETHOD GetChildAt(int32_t aChildIndex, nsIAccessible * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildAt(aChildIndex, _retval); } \
  NS_IMETHOD GetRelationByType(uint32_t aRelationType, nsIAccessibleRelation * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRelationByType(aRelationType, _retval); } \
  NS_IMETHOD GetRelations(nsIArray * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRelations(_retval); } \
  NS_IMETHOD GetBounds(int32_t *x, int32_t *y, int32_t *width, int32_t *height) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBounds(x, y, width, height); } \
  NS_IMETHOD SetSelected(bool isSelected) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelected(isSelected); } \
  NS_IMETHOD ExtendSelection(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExtendSelection(); } \
  NS_IMETHOD TakeSelection(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->TakeSelection(); } \
  NS_IMETHOD TakeFocus(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->TakeFocus(); } \
  NS_IMETHOD GetActionCount(uint8_t *aActionCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActionCount(aActionCount); } \
  NS_IMETHOD GetActionName(uint8_t index, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActionName(index, _retval); } \
  NS_IMETHOD GetActionDescription(uint8_t aIndex, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActionDescription(aIndex, _retval); } \
  NS_IMETHOD DoAction(uint8_t index) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoAction(index); } \
  NS_IMETHOD ScrollTo(uint32_t aScrollType) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollTo(aScrollType); } \
  NS_IMETHOD ScrollToPoint(uint32_t coordinateType, int32_t x, int32_t y) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollToPoint(coordinateType, x, y); } \
  NS_IMETHOD GetNativeInterface(void **aOutAccessible) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNativeInterface(aOutAccessible); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessible : public nsIAccessible
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLE

  nsAccessible();

private:
  ~nsAccessible();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessible, nsIAccessible)

nsAccessible::nsAccessible()
{
  /* member initializers and constructor code */
}

nsAccessible::~nsAccessible()
{
  /* destructor code */
}

/* readonly attribute nsIAccessible parent; */
NS_IMETHODIMP nsAccessible::GetParent(nsIAccessible * *aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessible nextSibling; */
NS_IMETHODIMP nsAccessible::GetNextSibling(nsIAccessible * *aNextSibling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessible previousSibling; */
NS_IMETHODIMP nsAccessible::GetPreviousSibling(nsIAccessible * *aPreviousSibling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessible firstChild; */
NS_IMETHODIMP nsAccessible::GetFirstChild(nsIAccessible * *aFirstChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessible lastChild; */
NS_IMETHODIMP nsAccessible::GetLastChild(nsIAccessible * *aLastChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIArray children; */
NS_IMETHODIMP nsAccessible::GetChildren(nsIArray * *aChildren)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long childCount; */
NS_IMETHODIMP nsAccessible::GetChildCount(int32_t *aChildCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long indexInParent; */
NS_IMETHODIMP nsAccessible::GetIndexInParent(int32_t *aIndexInParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode DOMNode; */
NS_IMETHODIMP nsAccessible::GetDOMNode(nsIDOMNode * *aDOMNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessibleDocument document; */
NS_IMETHODIMP nsAccessible::GetDocument(nsIAccessibleDocument * *aDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessibleDocument rootDocument; */
NS_IMETHODIMP nsAccessible::GetRootDocument(nsIAccessibleDocument * *aRootDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString language; */
NS_IMETHODIMP nsAccessible::GetLanguage(nsAString & aLanguage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString name; */
NS_IMETHODIMP nsAccessible::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAccessible::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString value; */
NS_IMETHODIMP nsAccessible::GetValue(nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString description; */
NS_IMETHODIMP nsAccessible::GetDescription(nsAString & aDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString accessKey; */
NS_IMETHODIMP nsAccessible::GetAccessKey(nsAString & aAccessKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString keyboardShortcut; */
NS_IMETHODIMP nsAccessible::GetKeyboardShortcut(nsAString & aKeyboardShortcut)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long role; */
NS_IMETHODIMP nsAccessible::GetRole(uint32_t *aRole)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getState (out unsigned long aState, out unsigned long aExtraState); */
NS_IMETHODIMP nsAccessible::GetState(uint32_t *aState, uint32_t *aExtraState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString help; */
NS_IMETHODIMP nsAccessible::GetHelp(nsAString & aHelp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessible focusedChild; */
NS_IMETHODIMP nsAccessible::GetFocusedChild(nsIAccessible * *aFocusedChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIPersistentProperties attributes; */
NS_IMETHODIMP nsAccessible::GetAttributes(nsIPersistentProperties * *aAttributes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void groupPosition (out long aGroupLevel, out long aSimilarItemsInGroup, out long aPositionInGroup); */
NS_IMETHODIMP nsAccessible::GroupPosition(int32_t *aGroupLevel, int32_t *aSimilarItemsInGroup, int32_t *aPositionInGroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getChildAtPoint (in long x, in long y); */
NS_IMETHODIMP nsAccessible::GetChildAtPoint(int32_t x, int32_t y, nsIAccessible * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getDeepestChildAtPoint (in long x, in long y); */
NS_IMETHODIMP nsAccessible::GetDeepestChildAtPoint(int32_t x, int32_t y, nsIAccessible * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getChildAt (in long aChildIndex); */
NS_IMETHODIMP nsAccessible::GetChildAt(int32_t aChildIndex, nsIAccessible * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessibleRelation getRelationByType (in unsigned long aRelationType); */
NS_IMETHODIMP nsAccessible::GetRelationByType(uint32_t aRelationType, nsIAccessibleRelation * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIArray getRelations (); */
NS_IMETHODIMP nsAccessible::GetRelations(nsIArray * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getBounds (out long x, out long y, out long width, out long height); */
NS_IMETHODIMP nsAccessible::GetBounds(int32_t *x, int32_t *y, int32_t *width, int32_t *height)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSelected (in boolean isSelected); */
NS_IMETHODIMP nsAccessible::SetSelected(bool isSelected)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void extendSelection (); */
NS_IMETHODIMP nsAccessible::ExtendSelection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void takeSelection (); */
NS_IMETHODIMP nsAccessible::TakeSelection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void takeFocus (); */
NS_IMETHODIMP nsAccessible::TakeFocus()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint8_t actionCount; */
NS_IMETHODIMP nsAccessible::GetActionCount(uint8_t *aActionCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getActionName (in uint8_t index); */
NS_IMETHODIMP nsAccessible::GetActionName(uint8_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getActionDescription (in uint8_t aIndex); */
NS_IMETHODIMP nsAccessible::GetActionDescription(uint8_t aIndex, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doAction (in uint8_t index); */
NS_IMETHODIMP nsAccessible::DoAction(uint8_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollTo (in unsigned long aScrollType); */
NS_IMETHODIMP nsAccessible::ScrollTo(uint32_t aScrollType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollToPoint (in unsigned long coordinateType, in long x, in long y); */
NS_IMETHODIMP nsAccessible::ScrollToPoint(uint32_t coordinateType, int32_t x, int32_t y)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getNativeInterface (out voidPtr aOutAccessible); */
NS_IMETHODIMP nsAccessible::GetNativeInterface(void **aOutAccessible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessible_h__ */

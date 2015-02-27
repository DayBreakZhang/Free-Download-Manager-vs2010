/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/editor/idl/nsIHTMLAbsPosEditor.idl
 */

#ifndef __gen_nsIHTMLAbsPosEditor_h__
#define __gen_nsIHTMLAbsPosEditor_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIHTMLAbsPosEditor */
#define NS_IHTMLABSPOSEDITOR_IID_STR "91375f52-20e6-4757-9835-eb04fabe5498"

#define NS_IHTMLABSPOSEDITOR_IID \
  {0x91375f52, 0x20e6, 0x4757, \
    { 0x98, 0x35, 0xeb, 0x04, 0xfa, 0xbe, 0x54, 0x98 }}

class NS_NO_VTABLE nsIHTMLAbsPosEditor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTMLABSPOSEDITOR_IID)

  /* readonly attribute boolean selectionContainerAbsolutelyPositioned; */
  NS_IMETHOD GetSelectionContainerAbsolutelyPositioned(bool *aSelectionContainerAbsolutelyPositioned) = 0;

  /* readonly attribute nsIDOMElement positionedElement; */
  NS_IMETHOD GetPositionedElement(nsIDOMElement * *aPositionedElement) = 0;

  /* attribute boolean absolutePositioningEnabled; */
  NS_IMETHOD GetAbsolutePositioningEnabled(bool *aAbsolutePositioningEnabled) = 0;
  NS_IMETHOD SetAbsolutePositioningEnabled(bool aAbsolutePositioningEnabled) = 0;

  /* attribute boolean snapToGridEnabled; */
  NS_IMETHOD GetSnapToGridEnabled(bool *aSnapToGridEnabled) = 0;
  NS_IMETHOD SetSnapToGridEnabled(bool aSnapToGridEnabled) = 0;

  /* attribute unsigned long gridSize; */
  NS_IMETHOD GetGridSize(uint32_t *aGridSize) = 0;
  NS_IMETHOD SetGridSize(uint32_t aGridSize) = 0;

  /* readonly attribute nsIDOMElement absolutelyPositionedSelectionContainer; */
  NS_IMETHOD GetAbsolutelyPositionedSelectionContainer(nsIDOMElement * *aAbsolutelyPositionedSelectionContainer) = 0;

  /* void absolutePositionSelection (in boolean aEnabled); */
  NS_IMETHOD AbsolutePositionSelection(bool aEnabled) = 0;

  /* void relativeChangeZIndex (in long aChange); */
  NS_IMETHOD RelativeChangeZIndex(int32_t aChange) = 0;

  /* void absolutelyPositionElement (in nsIDOMElement aElement, in boolean aEnabled); */
  NS_IMETHOD AbsolutelyPositionElement(nsIDOMElement *aElement, bool aEnabled) = 0;

  /* void setElementPosition (in nsIDOMElement aElement, in long aX, in long aY); */
  NS_IMETHOD SetElementPosition(nsIDOMElement *aElement, int32_t aX, int32_t aY) = 0;

  /* long getElementZIndex (in nsIDOMElement aElement); */
  NS_IMETHOD GetElementZIndex(nsIDOMElement *aElement, int32_t *_retval) = 0;

  /* void setElementZIndex (in nsIDOMElement aElement, in long aZorder); */
  NS_IMETHOD SetElementZIndex(nsIDOMElement *aElement, int32_t aZorder) = 0;

  /* long relativeChangeElementZIndex (in nsIDOMElement aElement, in long aChange); */
  NS_IMETHOD RelativeChangeElementZIndex(nsIDOMElement *aElement, int32_t aChange, int32_t *_retval) = 0;

  /* void showGrabberOnElement (in nsIDOMElement aElement); */
  NS_IMETHOD ShowGrabberOnElement(nsIDOMElement *aElement) = 0;

  /* void hideGrabber (); */
  NS_IMETHOD HideGrabber(void) = 0;

  /* void refreshGrabber (); */
  NS_IMETHOD RefreshGrabber(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHTMLAbsPosEditor, NS_IHTMLABSPOSEDITOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTMLABSPOSEDITOR \
  NS_IMETHOD GetSelectionContainerAbsolutelyPositioned(bool *aSelectionContainerAbsolutelyPositioned); \
  NS_IMETHOD GetPositionedElement(nsIDOMElement * *aPositionedElement); \
  NS_IMETHOD GetAbsolutePositioningEnabled(bool *aAbsolutePositioningEnabled); \
  NS_IMETHOD SetAbsolutePositioningEnabled(bool aAbsolutePositioningEnabled); \
  NS_IMETHOD GetSnapToGridEnabled(bool *aSnapToGridEnabled); \
  NS_IMETHOD SetSnapToGridEnabled(bool aSnapToGridEnabled); \
  NS_IMETHOD GetGridSize(uint32_t *aGridSize); \
  NS_IMETHOD SetGridSize(uint32_t aGridSize); \
  NS_IMETHOD GetAbsolutelyPositionedSelectionContainer(nsIDOMElement * *aAbsolutelyPositionedSelectionContainer); \
  NS_IMETHOD AbsolutePositionSelection(bool aEnabled); \
  NS_IMETHOD RelativeChangeZIndex(int32_t aChange); \
  NS_IMETHOD AbsolutelyPositionElement(nsIDOMElement *aElement, bool aEnabled); \
  NS_IMETHOD SetElementPosition(nsIDOMElement *aElement, int32_t aX, int32_t aY); \
  NS_IMETHOD GetElementZIndex(nsIDOMElement *aElement, int32_t *_retval); \
  NS_IMETHOD SetElementZIndex(nsIDOMElement *aElement, int32_t aZorder); \
  NS_IMETHOD RelativeChangeElementZIndex(nsIDOMElement *aElement, int32_t aChange, int32_t *_retval); \
  NS_IMETHOD ShowGrabberOnElement(nsIDOMElement *aElement); \
  NS_IMETHOD HideGrabber(void); \
  NS_IMETHOD RefreshGrabber(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTMLABSPOSEDITOR(_to) \
  NS_IMETHOD GetSelectionContainerAbsolutelyPositioned(bool *aSelectionContainerAbsolutelyPositioned) { return _to GetSelectionContainerAbsolutelyPositioned(aSelectionContainerAbsolutelyPositioned); } \
  NS_IMETHOD GetPositionedElement(nsIDOMElement * *aPositionedElement) { return _to GetPositionedElement(aPositionedElement); } \
  NS_IMETHOD GetAbsolutePositioningEnabled(bool *aAbsolutePositioningEnabled) { return _to GetAbsolutePositioningEnabled(aAbsolutePositioningEnabled); } \
  NS_IMETHOD SetAbsolutePositioningEnabled(bool aAbsolutePositioningEnabled) { return _to SetAbsolutePositioningEnabled(aAbsolutePositioningEnabled); } \
  NS_IMETHOD GetSnapToGridEnabled(bool *aSnapToGridEnabled) { return _to GetSnapToGridEnabled(aSnapToGridEnabled); } \
  NS_IMETHOD SetSnapToGridEnabled(bool aSnapToGridEnabled) { return _to SetSnapToGridEnabled(aSnapToGridEnabled); } \
  NS_IMETHOD GetGridSize(uint32_t *aGridSize) { return _to GetGridSize(aGridSize); } \
  NS_IMETHOD SetGridSize(uint32_t aGridSize) { return _to SetGridSize(aGridSize); } \
  NS_IMETHOD GetAbsolutelyPositionedSelectionContainer(nsIDOMElement * *aAbsolutelyPositionedSelectionContainer) { return _to GetAbsolutelyPositionedSelectionContainer(aAbsolutelyPositionedSelectionContainer); } \
  NS_IMETHOD AbsolutePositionSelection(bool aEnabled) { return _to AbsolutePositionSelection(aEnabled); } \
  NS_IMETHOD RelativeChangeZIndex(int32_t aChange) { return _to RelativeChangeZIndex(aChange); } \
  NS_IMETHOD AbsolutelyPositionElement(nsIDOMElement *aElement, bool aEnabled) { return _to AbsolutelyPositionElement(aElement, aEnabled); } \
  NS_IMETHOD SetElementPosition(nsIDOMElement *aElement, int32_t aX, int32_t aY) { return _to SetElementPosition(aElement, aX, aY); } \
  NS_IMETHOD GetElementZIndex(nsIDOMElement *aElement, int32_t *_retval) { return _to GetElementZIndex(aElement, _retval); } \
  NS_IMETHOD SetElementZIndex(nsIDOMElement *aElement, int32_t aZorder) { return _to SetElementZIndex(aElement, aZorder); } \
  NS_IMETHOD RelativeChangeElementZIndex(nsIDOMElement *aElement, int32_t aChange, int32_t *_retval) { return _to RelativeChangeElementZIndex(aElement, aChange, _retval); } \
  NS_IMETHOD ShowGrabberOnElement(nsIDOMElement *aElement) { return _to ShowGrabberOnElement(aElement); } \
  NS_IMETHOD HideGrabber(void) { return _to HideGrabber(); } \
  NS_IMETHOD RefreshGrabber(void) { return _to RefreshGrabber(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTMLABSPOSEDITOR(_to) \
  NS_IMETHOD GetSelectionContainerAbsolutelyPositioned(bool *aSelectionContainerAbsolutelyPositioned) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionContainerAbsolutelyPositioned(aSelectionContainerAbsolutelyPositioned); } \
  NS_IMETHOD GetPositionedElement(nsIDOMElement * *aPositionedElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPositionedElement(aPositionedElement); } \
  NS_IMETHOD GetAbsolutePositioningEnabled(bool *aAbsolutePositioningEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAbsolutePositioningEnabled(aAbsolutePositioningEnabled); } \
  NS_IMETHOD SetAbsolutePositioningEnabled(bool aAbsolutePositioningEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAbsolutePositioningEnabled(aAbsolutePositioningEnabled); } \
  NS_IMETHOD GetSnapToGridEnabled(bool *aSnapToGridEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSnapToGridEnabled(aSnapToGridEnabled); } \
  NS_IMETHOD SetSnapToGridEnabled(bool aSnapToGridEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSnapToGridEnabled(aSnapToGridEnabled); } \
  NS_IMETHOD GetGridSize(uint32_t *aGridSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGridSize(aGridSize); } \
  NS_IMETHOD SetGridSize(uint32_t aGridSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetGridSize(aGridSize); } \
  NS_IMETHOD GetAbsolutelyPositionedSelectionContainer(nsIDOMElement * *aAbsolutelyPositionedSelectionContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAbsolutelyPositionedSelectionContainer(aAbsolutelyPositionedSelectionContainer); } \
  NS_IMETHOD AbsolutePositionSelection(bool aEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->AbsolutePositionSelection(aEnabled); } \
  NS_IMETHOD RelativeChangeZIndex(int32_t aChange) { return !_to ? NS_ERROR_NULL_POINTER : _to->RelativeChangeZIndex(aChange); } \
  NS_IMETHOD AbsolutelyPositionElement(nsIDOMElement *aElement, bool aEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->AbsolutelyPositionElement(aElement, aEnabled); } \
  NS_IMETHOD SetElementPosition(nsIDOMElement *aElement, int32_t aX, int32_t aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetElementPosition(aElement, aX, aY); } \
  NS_IMETHOD GetElementZIndex(nsIDOMElement *aElement, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElementZIndex(aElement, _retval); } \
  NS_IMETHOD SetElementZIndex(nsIDOMElement *aElement, int32_t aZorder) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetElementZIndex(aElement, aZorder); } \
  NS_IMETHOD RelativeChangeElementZIndex(nsIDOMElement *aElement, int32_t aChange, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->RelativeChangeElementZIndex(aElement, aChange, _retval); } \
  NS_IMETHOD ShowGrabberOnElement(nsIDOMElement *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowGrabberOnElement(aElement); } \
  NS_IMETHOD HideGrabber(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->HideGrabber(); } \
  NS_IMETHOD RefreshGrabber(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RefreshGrabber(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHTMLAbsPosEditor : public nsIHTMLAbsPosEditor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTMLABSPOSEDITOR

  nsHTMLAbsPosEditor();

private:
  ~nsHTMLAbsPosEditor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHTMLAbsPosEditor, nsIHTMLAbsPosEditor)

nsHTMLAbsPosEditor::nsHTMLAbsPosEditor()
{
  /* member initializers and constructor code */
}

nsHTMLAbsPosEditor::~nsHTMLAbsPosEditor()
{
  /* destructor code */
}

/* readonly attribute boolean selectionContainerAbsolutelyPositioned; */
NS_IMETHODIMP nsHTMLAbsPosEditor::GetSelectionContainerAbsolutelyPositioned(bool *aSelectionContainerAbsolutelyPositioned)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement positionedElement; */
NS_IMETHODIMP nsHTMLAbsPosEditor::GetPositionedElement(nsIDOMElement * *aPositionedElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean absolutePositioningEnabled; */
NS_IMETHODIMP nsHTMLAbsPosEditor::GetAbsolutePositioningEnabled(bool *aAbsolutePositioningEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHTMLAbsPosEditor::SetAbsolutePositioningEnabled(bool aAbsolutePositioningEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean snapToGridEnabled; */
NS_IMETHODIMP nsHTMLAbsPosEditor::GetSnapToGridEnabled(bool *aSnapToGridEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHTMLAbsPosEditor::SetSnapToGridEnabled(bool aSnapToGridEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long gridSize; */
NS_IMETHODIMP nsHTMLAbsPosEditor::GetGridSize(uint32_t *aGridSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHTMLAbsPosEditor::SetGridSize(uint32_t aGridSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement absolutelyPositionedSelectionContainer; */
NS_IMETHODIMP nsHTMLAbsPosEditor::GetAbsolutelyPositionedSelectionContainer(nsIDOMElement * *aAbsolutelyPositionedSelectionContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void absolutePositionSelection (in boolean aEnabled); */
NS_IMETHODIMP nsHTMLAbsPosEditor::AbsolutePositionSelection(bool aEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void relativeChangeZIndex (in long aChange); */
NS_IMETHODIMP nsHTMLAbsPosEditor::RelativeChangeZIndex(int32_t aChange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void absolutelyPositionElement (in nsIDOMElement aElement, in boolean aEnabled); */
NS_IMETHODIMP nsHTMLAbsPosEditor::AbsolutelyPositionElement(nsIDOMElement *aElement, bool aEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setElementPosition (in nsIDOMElement aElement, in long aX, in long aY); */
NS_IMETHODIMP nsHTMLAbsPosEditor::SetElementPosition(nsIDOMElement *aElement, int32_t aX, int32_t aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getElementZIndex (in nsIDOMElement aElement); */
NS_IMETHODIMP nsHTMLAbsPosEditor::GetElementZIndex(nsIDOMElement *aElement, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setElementZIndex (in nsIDOMElement aElement, in long aZorder); */
NS_IMETHODIMP nsHTMLAbsPosEditor::SetElementZIndex(nsIDOMElement *aElement, int32_t aZorder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long relativeChangeElementZIndex (in nsIDOMElement aElement, in long aChange); */
NS_IMETHODIMP nsHTMLAbsPosEditor::RelativeChangeElementZIndex(nsIDOMElement *aElement, int32_t aChange, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showGrabberOnElement (in nsIDOMElement aElement); */
NS_IMETHODIMP nsHTMLAbsPosEditor::ShowGrabberOnElement(nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void hideGrabber (); */
NS_IMETHODIMP nsHTMLAbsPosEditor::HideGrabber()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void refreshGrabber (); */
NS_IMETHODIMP nsHTMLAbsPosEditor::RefreshGrabber()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHTMLAbsPosEditor_h__ */

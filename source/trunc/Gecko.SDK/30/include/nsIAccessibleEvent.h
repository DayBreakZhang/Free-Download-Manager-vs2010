/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAccessibleEvent.idl
 */

#ifndef __gen_nsIAccessibleEvent_h__
#define __gen_nsIAccessibleEvent_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAccessible; /* forward declaration */

class nsIAccessibleDocument; /* forward declaration */

class nsIDOMNode; /* forward declaration */

#define NS_ACCESSIBLE_EVENT_TOPIC "accessible-event"

/* starting interface:    nsIAccessibleEvent */
#define NS_IACCESSIBLEEVENT_IID_STR "7f66a33a-9ed7-4fd4-87a8-e431b0f43368"

#define NS_IACCESSIBLEEVENT_IID \
  {0x7f66a33a, 0x9ed7, 0x4fd4, \
    { 0x87, 0xa8, 0xe4, 0x31, 0xb0, 0xf4, 0x33, 0x68 }}

class NS_NO_VTABLE nsIAccessibleEvent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEEVENT_IID)

  enum {
    EVENT_SHOW = 1U,
    EVENT_HIDE = 2U,
    EVENT_REORDER = 3U,
    EVENT_ACTIVE_DECENDENT_CHANGED = 4U,
    EVENT_FOCUS = 5U,
    EVENT_STATE_CHANGE = 6U,
    EVENT_LOCATION_CHANGE = 7U,
    EVENT_NAME_CHANGE = 8U,
    EVENT_DESCRIPTION_CHANGE = 9U,
    EVENT_VALUE_CHANGE = 10U,
    EVENT_HELP_CHANGE = 11U,
    EVENT_DEFACTION_CHANGE = 12U,
    EVENT_ACTION_CHANGE = 13U,
    EVENT_ACCELERATOR_CHANGE = 14U,
    EVENT_SELECTION = 15U,
    EVENT_SELECTION_ADD = 16U,
    EVENT_SELECTION_REMOVE = 17U,
    EVENT_SELECTION_WITHIN = 18U,
    EVENT_ALERT = 19U,
    EVENT_FOREGROUND = 20U,
    EVENT_MENU_START = 21U,
    EVENT_MENU_END = 22U,
    EVENT_MENUPOPUP_START = 23U,
    EVENT_MENUPOPUP_END = 24U,
    EVENT_CAPTURE_START = 25U,
    EVENT_CAPTURE_END = 26U,
    EVENT_MOVESIZE_START = 27U,
    EVENT_MOVESIZE_END = 28U,
    EVENT_CONTEXTHELP_START = 29U,
    EVENT_CONTEXTHELP_END = 30U,
    EVENT_DRAGDROP_START = 31U,
    EVENT_DRAGDROP_END = 32U,
    EVENT_DIALOG_START = 33U,
    EVENT_DIALOG_END = 34U,
    EVENT_SCROLLING_START = 35U,
    EVENT_SCROLLING_END = 36U,
    EVENT_MINIMIZE_START = 37U,
    EVENT_MINIMIZE_END = 38U,
    EVENT_DOCUMENT_LOAD_COMPLETE = 39U,
    EVENT_DOCUMENT_RELOAD = 40U,
    EVENT_DOCUMENT_LOAD_STOPPED = 41U,
    EVENT_DOCUMENT_ATTRIBUTES_CHANGED = 42U,
    EVENT_DOCUMENT_CONTENT_CHANGED = 43U,
    EVENT_PROPERTY_CHANGED = 44U,
    EVENT_PAGE_CHANGED = 45U,
    EVENT_TEXT_ATTRIBUTE_CHANGED = 46U,
    EVENT_TEXT_CARET_MOVED = 47U,
    EVENT_TEXT_CHANGED = 48U,
    EVENT_TEXT_INSERTED = 49U,
    EVENT_TEXT_REMOVED = 50U,
    EVENT_TEXT_UPDATED = 51U,
    EVENT_TEXT_SELECTION_CHANGED = 52U,
    EVENT_VISIBLE_DATA_CHANGED = 53U,
    EVENT_TEXT_COLUMN_CHANGED = 54U,
    EVENT_SECTION_CHANGED = 55U,
    EVENT_TABLE_CAPTION_CHANGED = 56U,
    EVENT_TABLE_MODEL_CHANGED = 57U,
    EVENT_TABLE_SUMMARY_CHANGED = 58U,
    EVENT_TABLE_ROW_DESCRIPTION_CHANGED = 59U,
    EVENT_TABLE_ROW_HEADER_CHANGED = 60U,
    EVENT_TABLE_ROW_INSERT = 61U,
    EVENT_TABLE_ROW_DELETE = 62U,
    EVENT_TABLE_ROW_REORDER = 63U,
    EVENT_TABLE_COLUMN_DESCRIPTION_CHANGED = 64U,
    EVENT_TABLE_COLUMN_HEADER_CHANGED = 65U,
    EVENT_TABLE_COLUMN_INSERT = 66U,
    EVENT_TABLE_COLUMN_DELETE = 67U,
    EVENT_TABLE_COLUMN_REORDER = 68U,
    EVENT_WINDOW_ACTIVATE = 69U,
    EVENT_WINDOW_CREATE = 70U,
    EVENT_WINDOW_DEACTIVATE = 71U,
    EVENT_WINDOW_DESTROY = 72U,
    EVENT_WINDOW_MAXIMIZE = 73U,
    EVENT_WINDOW_MINIMIZE = 74U,
    EVENT_WINDOW_RESIZE = 75U,
    EVENT_WINDOW_RESTORE = 76U,
    EVENT_HYPERLINK_END_INDEX_CHANGED = 77U,
    EVENT_HYPERLINK_NUMBER_OF_ANCHORS_CHANGED = 78U,
    EVENT_HYPERLINK_SELECTED_LINK_CHANGED = 79U,
    EVENT_HYPERTEXT_LINK_ACTIVATED = 80U,
    EVENT_HYPERTEXT_LINK_SELECTED = 81U,
    EVENT_HYPERLINK_START_INDEX_CHANGED = 82U,
    EVENT_HYPERTEXT_CHANGED = 83U,
    EVENT_HYPERTEXT_NLINKS_CHANGED = 84U,
    EVENT_OBJECT_ATTRIBUTE_CHANGED = 85U,
    EVENT_VIRTUALCURSOR_CHANGED = 86U,
    EVENT_LAST_ENTRY = 87U
  };

  /* readonly attribute unsigned long eventType; */
  NS_IMETHOD GetEventType(uint32_t *aEventType) = 0;

  /* readonly attribute nsIAccessible accessible; */
  NS_IMETHOD GetAccessible(nsIAccessible * *aAccessible) = 0;

  /* readonly attribute nsIAccessibleDocument accessibleDocument; */
  NS_IMETHOD GetAccessibleDocument(nsIAccessibleDocument * *aAccessibleDocument) = 0;

  /* readonly attribute nsIDOMNode DOMNode; */
  NS_IMETHOD GetDOMNode(nsIDOMNode * *aDOMNode) = 0;

  /* readonly attribute boolean isFromUserInput; */
  NS_IMETHOD GetIsFromUserInput(bool *aIsFromUserInput) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleEvent, NS_IACCESSIBLEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEEVENT \
  NS_IMETHOD GetEventType(uint32_t *aEventType); \
  NS_IMETHOD GetAccessible(nsIAccessible * *aAccessible); \
  NS_IMETHOD GetAccessibleDocument(nsIAccessibleDocument * *aAccessibleDocument); \
  NS_IMETHOD GetDOMNode(nsIDOMNode * *aDOMNode); \
  NS_IMETHOD GetIsFromUserInput(bool *aIsFromUserInput); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEEVENT(_to) \
  NS_IMETHOD GetEventType(uint32_t *aEventType) { return _to GetEventType(aEventType); } \
  NS_IMETHOD GetAccessible(nsIAccessible * *aAccessible) { return _to GetAccessible(aAccessible); } \
  NS_IMETHOD GetAccessibleDocument(nsIAccessibleDocument * *aAccessibleDocument) { return _to GetAccessibleDocument(aAccessibleDocument); } \
  NS_IMETHOD GetDOMNode(nsIDOMNode * *aDOMNode) { return _to GetDOMNode(aDOMNode); } \
  NS_IMETHOD GetIsFromUserInput(bool *aIsFromUserInput) { return _to GetIsFromUserInput(aIsFromUserInput); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEEVENT(_to) \
  NS_IMETHOD GetEventType(uint32_t *aEventType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEventType(aEventType); } \
  NS_IMETHOD GetAccessible(nsIAccessible * *aAccessible) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessible(aAccessible); } \
  NS_IMETHOD GetAccessibleDocument(nsIAccessibleDocument * *aAccessibleDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessibleDocument(aAccessibleDocument); } \
  NS_IMETHOD GetDOMNode(nsIDOMNode * *aDOMNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDOMNode(aDOMNode); } \
  NS_IMETHOD GetIsFromUserInput(bool *aIsFromUserInput) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsFromUserInput(aIsFromUserInput); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleEvent : public nsIAccessibleEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEEVENT

  nsAccessibleEvent();

private:
  ~nsAccessibleEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleEvent, nsIAccessibleEvent)

nsAccessibleEvent::nsAccessibleEvent()
{
  /* member initializers and constructor code */
}

nsAccessibleEvent::~nsAccessibleEvent()
{
  /* destructor code */
}

/* readonly attribute unsigned long eventType; */
NS_IMETHODIMP nsAccessibleEvent::GetEventType(uint32_t *aEventType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessible accessible; */
NS_IMETHODIMP nsAccessibleEvent::GetAccessible(nsIAccessible * *aAccessible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessibleDocument accessibleDocument; */
NS_IMETHODIMP nsAccessibleEvent::GetAccessibleDocument(nsIAccessibleDocument * *aAccessibleDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode DOMNode; */
NS_IMETHODIMP nsAccessibleEvent::GetDOMNode(nsIDOMNode * *aDOMNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isFromUserInput; */
NS_IMETHODIMP nsAccessibleEvent::GetIsFromUserInput(bool *aIsFromUserInput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleEvent_h__ */

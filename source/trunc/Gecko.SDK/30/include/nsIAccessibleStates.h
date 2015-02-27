/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAccessibleStates.idl
 */

#ifndef __gen_nsIAccessibleStates_h__
#define __gen_nsIAccessibleStates_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAccessibleStates */
#define NS_IACCESSIBLESTATES_IID_STR "f1e0fbb7-fde4-4519-9383-2bcbee428513"

#define NS_IACCESSIBLESTATES_IID \
  {0xf1e0fbb7, 0xfde4, 0x4519, \
    { 0x93, 0x83, 0x2b, 0xcb, 0xee, 0x42, 0x85, 0x13 }}

class NS_NO_VTABLE nsIAccessibleStates : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLESTATES_IID)

  enum {
    STATE_UNAVAILABLE = 1U,
    STATE_SELECTED = 2U,
    STATE_FOCUSED = 4U,
    STATE_PRESSED = 8U,
    STATE_CHECKED = 16U,
    STATE_MIXED = 32U,
    STATE_READONLY = 64U,
    STATE_HOTTRACKED = 128U,
    STATE_DEFAULT = 256U,
    STATE_EXPANDED = 512U,
    STATE_COLLAPSED = 1024U,
    STATE_BUSY = 2048U,
    STATE_FLOATING = 4096U,
    STATE_MARQUEED = 8192U,
    STATE_ANIMATED = 16384U,
    STATE_INVISIBLE = 32768U,
    STATE_OFFSCREEN = 65536U,
    STATE_SIZEABLE = 131072U,
    STATE_MOVEABLE = 262144U,
    STATE_SELFVOICING = 524288U,
    STATE_FOCUSABLE = 1048576U,
    STATE_SELECTABLE = 2097152U,
    STATE_LINKED = 4194304U,
    STATE_TRAVERSED = 8388608U,
    STATE_MULTISELECTABLE = 16777216U,
    STATE_EXTSELECTABLE = 33554432U,
    STATE_ALERT_LOW = 67108864U,
    STATE_ALERT_MEDIUM = 134217728U,
    STATE_ALERT_HIGH = 268435456U,
    STATE_PROTECTED = 536870912U,
    STATE_HASPOPUP = 1073741824U,
    STATE_REQUIRED = 67108864U,
    STATE_IMPORTANT = 134217728U,
    STATE_INVALID = 268435456U,
    STATE_CHECKABLE = 8192U,
    EXT_STATE_SUPPORTS_AUTOCOMPLETION = 1U,
    EXT_STATE_DEFUNCT = 2U,
    EXT_STATE_SELECTABLE_TEXT = 4U,
    EXT_STATE_EDITABLE = 8U,
    EXT_STATE_ACTIVE = 16U,
    EXT_STATE_MODAL = 32U,
    EXT_STATE_MULTI_LINE = 64U,
    EXT_STATE_HORIZONTAL = 128U,
    EXT_STATE_OPAQUE = 256U,
    EXT_STATE_SINGLE_LINE = 512U,
    EXT_STATE_TRANSIENT = 1024U,
    EXT_STATE_VERTICAL = 2048U,
    EXT_STATE_STALE = 4096U,
    EXT_STATE_ENABLED = 8192U,
    EXT_STATE_SENSITIVE = 16384U,
    EXT_STATE_EXPANDABLE = 32768U,
    EXT_STATE_PINNED = 65536U
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleStates, NS_IACCESSIBLESTATES_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLESTATES \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLESTATES(_to) \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLESTATES(_to) \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleStates : public nsIAccessibleStates
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLESTATES

  nsAccessibleStates();

private:
  ~nsAccessibleStates();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleStates, nsIAccessibleStates)

nsAccessibleStates::nsAccessibleStates()
{
  /* member initializers and constructor code */
}

nsAccessibleStates::~nsAccessibleStates()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleStates_h__ */

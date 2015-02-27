/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMNSEvent.idl
 */

#ifndef __gen_nsIDOMNSEvent_h__
#define __gen_nsIDOMNSEvent_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#ifdef ERROR
#undef ERROR
#endif

/* starting interface:    nsIDOMNSEvent */
#define NS_IDOMNSEVENT_IID_STR "2580b4a2-6d85-4ca6-9be2-98f3406ad296"

#define NS_IDOMNSEVENT_IID \
  {0x2580b4a2, 0x6d85, 0x4ca6, \
    { 0x9b, 0xe2, 0x98, 0xf3, 0x40, 0x6a, 0xd2, 0x96 }}

class NS_NO_VTABLE nsIDOMNSEvent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSEVENT_IID)

  enum {
    MOUSEDOWN = 1,
    MOUSEUP = 2,
    MOUSEOVER = 4,
    MOUSEOUT = 8,
    MOUSEMOVE = 16,
    MOUSEDRAG = 32,
    CLICK = 64,
    DBLCLICK = 128,
    KEYDOWN = 256,
    KEYUP = 512,
    KEYPRESS = 1024,
    DRAGDROP = 2048,
    FOCUS = 4096,
    BLUR = 8192,
    SELECT = 16384,
    CHANGE = 32768,
    RESET = 65536,
    SUBMIT = 131072,
    SCROLL = 262144,
    LOAD = 524288,
    UNLOAD = 1048576,
    XFER_DONE = 2097152,
    ABORT = 4194304,
    ERROR = 8388608,
    LOCATE = 16777216,
    MOVE = 33554432,
    RESIZE = 67108864,
    FORWARD = 134217728,
    HELP = 268435456,
    BACK = 536870912,
    TEXT = 1073741824,
    ALT_MASK = 1,
    CONTROL_MASK = 2,
    SHIFT_MASK = 4,
    META_MASK = 8
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSEvent, NS_IDOMNSEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSEVENT \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSEVENT(_to) \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSEVENT(_to) \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSEvent : public nsIDOMNSEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSEVENT

  nsDOMNSEvent();

private:
  ~nsDOMNSEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSEvent, nsIDOMNSEvent)

nsDOMNSEvent::nsDOMNSEvent()
{
  /* member initializers and constructor code */
}

nsDOMNSEvent::~nsDOMNSEvent()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSEvent_h__ */

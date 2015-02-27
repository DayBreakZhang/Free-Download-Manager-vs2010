/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMKeyEvent.idl
 */

#ifndef __gen_nsIDOMKeyEvent_h__
#define __gen_nsIDOMKeyEvent_h__


#ifndef __gen_nsIDOMUIEvent_h__
#include "nsIDOMUIEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMKeyEvent */
#define NS_IDOMKEYEVENT_IID_STR "ffbe684c-ca90-4b58-aa8c-9727f997f86d"

#define NS_IDOMKEYEVENT_IID \
  {0xffbe684c, 0xca90, 0x4b58, \
    { 0xaa, 0x8c, 0x97, 0x27, 0xf9, 0x97, 0xf8, 0x6d }}

class NS_NO_VTABLE nsIDOMKeyEvent : public nsIDOMUIEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMKEYEVENT_IID)

  enum {
    DOM_VK_CANCEL = 3U,
    DOM_VK_HELP = 6U,
    DOM_VK_BACK_SPACE = 8U,
    DOM_VK_TAB = 9U,
    DOM_VK_CLEAR = 12U,
    DOM_VK_RETURN = 13U,
    DOM_VK_ENTER = 14U,
    DOM_VK_SHIFT = 16U,
    DOM_VK_CONTROL = 17U,
    DOM_VK_ALT = 18U,
    DOM_VK_PAUSE = 19U,
    DOM_VK_CAPS_LOCK = 20U,
    DOM_VK_KANA = 21U,
    DOM_VK_HANGUL = 21U,
    DOM_VK_EISU = 22U,
    DOM_VK_JUNJA = 23U,
    DOM_VK_FINAL = 24U,
    DOM_VK_HANJA = 25U,
    DOM_VK_KANJI = 25U,
    DOM_VK_ESCAPE = 27U,
    DOM_VK_CONVERT = 28U,
    DOM_VK_NONCONVERT = 29U,
    DOM_VK_ACCEPT = 30U,
    DOM_VK_MODECHANGE = 31U,
    DOM_VK_SPACE = 32U,
    DOM_VK_PAGE_UP = 33U,
    DOM_VK_PAGE_DOWN = 34U,
    DOM_VK_END = 35U,
    DOM_VK_HOME = 36U,
    DOM_VK_LEFT = 37U,
    DOM_VK_UP = 38U,
    DOM_VK_RIGHT = 39U,
    DOM_VK_DOWN = 40U,
    DOM_VK_SELECT = 41U,
    DOM_VK_PRINT = 42U,
    DOM_VK_EXECUTE = 43U,
    DOM_VK_PRINTSCREEN = 44U,
    DOM_VK_INSERT = 45U,
    DOM_VK_DELETE = 46U,
    DOM_VK_0 = 48U,
    DOM_VK_1 = 49U,
    DOM_VK_2 = 50U,
    DOM_VK_3 = 51U,
    DOM_VK_4 = 52U,
    DOM_VK_5 = 53U,
    DOM_VK_6 = 54U,
    DOM_VK_7 = 55U,
    DOM_VK_8 = 56U,
    DOM_VK_9 = 57U,
    DOM_VK_COLON = 58U,
    DOM_VK_SEMICOLON = 59U,
    DOM_VK_LESS_THAN = 60U,
    DOM_VK_EQUALS = 61U,
    DOM_VK_GREATER_THAN = 62U,
    DOM_VK_QUESTION_MARK = 63U,
    DOM_VK_AT = 64U,
    DOM_VK_A = 65U,
    DOM_VK_B = 66U,
    DOM_VK_C = 67U,
    DOM_VK_D = 68U,
    DOM_VK_E = 69U,
    DOM_VK_F = 70U,
    DOM_VK_G = 71U,
    DOM_VK_H = 72U,
    DOM_VK_I = 73U,
    DOM_VK_J = 74U,
    DOM_VK_K = 75U,
    DOM_VK_L = 76U,
    DOM_VK_M = 77U,
    DOM_VK_N = 78U,
    DOM_VK_O = 79U,
    DOM_VK_P = 80U,
    DOM_VK_Q = 81U,
    DOM_VK_R = 82U,
    DOM_VK_S = 83U,
    DOM_VK_T = 84U,
    DOM_VK_U = 85U,
    DOM_VK_V = 86U,
    DOM_VK_W = 87U,
    DOM_VK_X = 88U,
    DOM_VK_Y = 89U,
    DOM_VK_Z = 90U,
    DOM_VK_WIN = 91U,
    DOM_VK_CONTEXT_MENU = 93U,
    DOM_VK_SLEEP = 95U,
    DOM_VK_NUMPAD0 = 96U,
    DOM_VK_NUMPAD1 = 97U,
    DOM_VK_NUMPAD2 = 98U,
    DOM_VK_NUMPAD3 = 99U,
    DOM_VK_NUMPAD4 = 100U,
    DOM_VK_NUMPAD5 = 101U,
    DOM_VK_NUMPAD6 = 102U,
    DOM_VK_NUMPAD7 = 103U,
    DOM_VK_NUMPAD8 = 104U,
    DOM_VK_NUMPAD9 = 105U,
    DOM_VK_MULTIPLY = 106U,
    DOM_VK_ADD = 107U,
    DOM_VK_SEPARATOR = 108U,
    DOM_VK_SUBTRACT = 109U,
    DOM_VK_DECIMAL = 110U,
    DOM_VK_DIVIDE = 111U,
    DOM_VK_F1 = 112U,
    DOM_VK_F2 = 113U,
    DOM_VK_F3 = 114U,
    DOM_VK_F4 = 115U,
    DOM_VK_F5 = 116U,
    DOM_VK_F6 = 117U,
    DOM_VK_F7 = 118U,
    DOM_VK_F8 = 119U,
    DOM_VK_F9 = 120U,
    DOM_VK_F10 = 121U,
    DOM_VK_F11 = 122U,
    DOM_VK_F12 = 123U,
    DOM_VK_F13 = 124U,
    DOM_VK_F14 = 125U,
    DOM_VK_F15 = 126U,
    DOM_VK_F16 = 127U,
    DOM_VK_F17 = 128U,
    DOM_VK_F18 = 129U,
    DOM_VK_F19 = 130U,
    DOM_VK_F20 = 131U,
    DOM_VK_F21 = 132U,
    DOM_VK_F22 = 133U,
    DOM_VK_F23 = 134U,
    DOM_VK_F24 = 135U,
    DOM_VK_NUM_LOCK = 144U,
    DOM_VK_SCROLL_LOCK = 145U,
    DOM_VK_WIN_OEM_FJ_JISHO = 146U,
    DOM_VK_WIN_OEM_FJ_MASSHOU = 147U,
    DOM_VK_WIN_OEM_FJ_TOUROKU = 148U,
    DOM_VK_WIN_OEM_FJ_LOYA = 149U,
    DOM_VK_WIN_OEM_FJ_ROYA = 150U,
    DOM_VK_CIRCUMFLEX = 160U,
    DOM_VK_EXCLAMATION = 161U,
    DOM_VK_DOUBLE_QUOTE = 162U,
    DOM_VK_HASH = 163U,
    DOM_VK_DOLLAR = 164U,
    DOM_VK_PERCENT = 165U,
    DOM_VK_AMPERSAND = 166U,
    DOM_VK_UNDERSCORE = 167U,
    DOM_VK_OPEN_PAREN = 168U,
    DOM_VK_CLOSE_PAREN = 169U,
    DOM_VK_ASTERISK = 170U,
    DOM_VK_PLUS = 171U,
    DOM_VK_PIPE = 172U,
    DOM_VK_HYPHEN_MINUS = 173U,
    DOM_VK_OPEN_CURLY_BRACKET = 174U,
    DOM_VK_CLOSE_CURLY_BRACKET = 175U,
    DOM_VK_TILDE = 176U,
    DOM_VK_VOLUME_MUTE = 181U,
    DOM_VK_VOLUME_DOWN = 182U,
    DOM_VK_VOLUME_UP = 183U,
    DOM_VK_COMMA = 188U,
    DOM_VK_PERIOD = 190U,
    DOM_VK_SLASH = 191U,
    DOM_VK_BACK_QUOTE = 192U,
    DOM_VK_OPEN_BRACKET = 219U,
    DOM_VK_BACK_SLASH = 220U,
    DOM_VK_CLOSE_BRACKET = 221U,
    DOM_VK_QUOTE = 222U,
    DOM_VK_META = 224U,
    DOM_VK_ALTGR = 225U,
    DOM_VK_WIN_ICO_HELP = 227U,
    DOM_VK_WIN_ICO_00 = 228U,
    DOM_VK_WIN_ICO_CLEAR = 230U,
    DOM_VK_WIN_OEM_RESET = 233U,
    DOM_VK_WIN_OEM_JUMP = 234U,
    DOM_VK_WIN_OEM_PA1 = 235U,
    DOM_VK_WIN_OEM_PA2 = 236U,
    DOM_VK_WIN_OEM_PA3 = 237U,
    DOM_VK_WIN_OEM_WSCTRL = 238U,
    DOM_VK_WIN_OEM_CUSEL = 239U,
    DOM_VK_WIN_OEM_ATTN = 240U,
    DOM_VK_WIN_OEM_FINISH = 241U,
    DOM_VK_WIN_OEM_COPY = 242U,
    DOM_VK_WIN_OEM_AUTO = 243U,
    DOM_VK_WIN_OEM_ENLW = 244U,
    DOM_VK_WIN_OEM_BACKTAB = 245U,
    DOM_VK_ATTN = 246U,
    DOM_VK_CRSEL = 247U,
    DOM_VK_EXSEL = 248U,
    DOM_VK_EREOF = 249U,
    DOM_VK_PLAY = 250U,
    DOM_VK_ZOOM = 251U,
    DOM_VK_PA1 = 253U,
    DOM_VK_WIN_OEM_CLEAR = 254U
  };

  /* readonly attribute unsigned long charCode; */
  NS_IMETHOD GetCharCode(uint32_t *aCharCode) = 0;

  /* readonly attribute unsigned long keyCode; */
  NS_IMETHOD GetKeyCode(uint32_t *aKeyCode) = 0;

  /* readonly attribute boolean altKey; */
  NS_IMETHOD GetAltKey(bool *aAltKey) = 0;

  /* readonly attribute boolean ctrlKey; */
  NS_IMETHOD GetCtrlKey(bool *aCtrlKey) = 0;

  /* readonly attribute boolean shiftKey; */
  NS_IMETHOD GetShiftKey(bool *aShiftKey) = 0;

  /* readonly attribute boolean metaKey; */
  NS_IMETHOD GetMetaKey(bool *aMetaKey) = 0;

  /* void initKeyEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow viewArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in unsigned long keyCodeArg, in unsigned long charCodeArg); */
  NS_IMETHOD InitKeyEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, uint32_t keyCodeArg, uint32_t charCodeArg) = 0;

  /* bool getModifierState (in DOMString keyArg); */
  NS_IMETHOD GetModifierState(const nsAString & keyArg, bool *_retval) = 0;

  enum {
    DOM_KEY_LOCATION_STANDARD = 0U,
    DOM_KEY_LOCATION_LEFT = 1U,
    DOM_KEY_LOCATION_RIGHT = 2U,
    DOM_KEY_LOCATION_NUMPAD = 3U,
    DOM_KEY_LOCATION_MOBILE = 4U,
    DOM_KEY_LOCATION_JOYSTICK = 5U
  };

  /* readonly attribute unsigned long location; */
  NS_IMETHOD GetLocation(uint32_t *aLocation) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMKeyEvent, NS_IDOMKEYEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMKEYEVENT \
  NS_IMETHOD GetCharCode(uint32_t *aCharCode); \
  NS_IMETHOD GetKeyCode(uint32_t *aKeyCode); \
  NS_IMETHOD GetAltKey(bool *aAltKey); \
  NS_IMETHOD GetCtrlKey(bool *aCtrlKey); \
  NS_IMETHOD GetShiftKey(bool *aShiftKey); \
  NS_IMETHOD GetMetaKey(bool *aMetaKey); \
  NS_IMETHOD InitKeyEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, uint32_t keyCodeArg, uint32_t charCodeArg); \
  NS_IMETHOD GetModifierState(const nsAString & keyArg, bool *_retval); \
  NS_IMETHOD GetLocation(uint32_t *aLocation); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMKEYEVENT(_to) \
  NS_IMETHOD GetCharCode(uint32_t *aCharCode) { return _to GetCharCode(aCharCode); } \
  NS_IMETHOD GetKeyCode(uint32_t *aKeyCode) { return _to GetKeyCode(aKeyCode); } \
  NS_IMETHOD GetAltKey(bool *aAltKey) { return _to GetAltKey(aAltKey); } \
  NS_IMETHOD GetCtrlKey(bool *aCtrlKey) { return _to GetCtrlKey(aCtrlKey); } \
  NS_IMETHOD GetShiftKey(bool *aShiftKey) { return _to GetShiftKey(aShiftKey); } \
  NS_IMETHOD GetMetaKey(bool *aMetaKey) { return _to GetMetaKey(aMetaKey); } \
  NS_IMETHOD InitKeyEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, uint32_t keyCodeArg, uint32_t charCodeArg) { return _to InitKeyEvent(typeArg, canBubbleArg, cancelableArg, viewArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, keyCodeArg, charCodeArg); } \
  NS_IMETHOD GetModifierState(const nsAString & keyArg, bool *_retval) { return _to GetModifierState(keyArg, _retval); } \
  NS_IMETHOD GetLocation(uint32_t *aLocation) { return _to GetLocation(aLocation); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMKEYEVENT(_to) \
  NS_IMETHOD GetCharCode(uint32_t *aCharCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharCode(aCharCode); } \
  NS_IMETHOD GetKeyCode(uint32_t *aKeyCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeyCode(aKeyCode); } \
  NS_IMETHOD GetAltKey(bool *aAltKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAltKey(aAltKey); } \
  NS_IMETHOD GetCtrlKey(bool *aCtrlKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCtrlKey(aCtrlKey); } \
  NS_IMETHOD GetShiftKey(bool *aShiftKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShiftKey(aShiftKey); } \
  NS_IMETHOD GetMetaKey(bool *aMetaKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMetaKey(aMetaKey); } \
  NS_IMETHOD InitKeyEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, uint32_t keyCodeArg, uint32_t charCodeArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitKeyEvent(typeArg, canBubbleArg, cancelableArg, viewArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, keyCodeArg, charCodeArg); } \
  NS_IMETHOD GetModifierState(const nsAString & keyArg, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetModifierState(keyArg, _retval); } \
  NS_IMETHOD GetLocation(uint32_t *aLocation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocation(aLocation); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMKeyEvent : public nsIDOMKeyEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMKEYEVENT

  nsDOMKeyEvent();

private:
  ~nsDOMKeyEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMKeyEvent, nsIDOMKeyEvent)

nsDOMKeyEvent::nsDOMKeyEvent()
{
  /* member initializers and constructor code */
}

nsDOMKeyEvent::~nsDOMKeyEvent()
{
  /* destructor code */
}

/* readonly attribute unsigned long charCode; */
NS_IMETHODIMP nsDOMKeyEvent::GetCharCode(uint32_t *aCharCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long keyCode; */
NS_IMETHODIMP nsDOMKeyEvent::GetKeyCode(uint32_t *aKeyCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean altKey; */
NS_IMETHODIMP nsDOMKeyEvent::GetAltKey(bool *aAltKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean ctrlKey; */
NS_IMETHODIMP nsDOMKeyEvent::GetCtrlKey(bool *aCtrlKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean shiftKey; */
NS_IMETHODIMP nsDOMKeyEvent::GetShiftKey(bool *aShiftKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean metaKey; */
NS_IMETHODIMP nsDOMKeyEvent::GetMetaKey(bool *aMetaKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initKeyEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow viewArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in unsigned long keyCodeArg, in unsigned long charCodeArg); */
NS_IMETHODIMP nsDOMKeyEvent::InitKeyEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, uint32_t keyCodeArg, uint32_t charCodeArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool getModifierState (in DOMString keyArg); */
NS_IMETHODIMP nsDOMKeyEvent::GetModifierState(const nsAString & keyArg, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long location; */
NS_IMETHODIMP nsDOMKeyEvent::GetLocation(uint32_t *aLocation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMKeyEvent_h__ */

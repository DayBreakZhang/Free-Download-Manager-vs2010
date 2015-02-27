/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIInlineEventHandlers.idl
 */

#ifndef __gen_nsIInlineEventHandlers_h__
#define __gen_nsIInlineEventHandlers_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "jspubtd.h"

/* starting interface:    nsIInlineEventHandlers */
#define NS_IINLINEEVENTHANDLERS_IID_STR "6c1fcf3d-119b-4cf4-9437-b9357508976a"

#define NS_IINLINEEVENTHANDLERS_IID \
  {0x6c1fcf3d, 0x119b, 0x4cf4, \
    { 0x94, 0x37, 0xb9, 0x35, 0x75, 0x08, 0x97, 0x6a }}

class NS_NO_VTABLE nsIInlineEventHandlers : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINLINEEVENTHANDLERS_IID)

  /* [implicit_jscontext] attribute jsval onabort; */
  NS_IMETHOD GetOnabort(JSContext* cx, JS::MutableHandleValue aOnabort) = 0;
  NS_IMETHOD SetOnabort(JSContext* cx, JS::HandleValue aOnabort) = 0;

  /* [implicit_jscontext] attribute jsval onblur; */
  NS_IMETHOD GetOnblur(JSContext* cx, JS::MutableHandleValue aOnblur) = 0;
  NS_IMETHOD SetOnblur(JSContext* cx, JS::HandleValue aOnblur) = 0;

  /* [implicit_jscontext] attribute jsval oncanplay; */
  NS_IMETHOD GetOncanplay(JSContext* cx, JS::MutableHandleValue aOncanplay) = 0;
  NS_IMETHOD SetOncanplay(JSContext* cx, JS::HandleValue aOncanplay) = 0;

  /* [implicit_jscontext] attribute jsval oncanplaythrough; */
  NS_IMETHOD GetOncanplaythrough(JSContext* cx, JS::MutableHandleValue aOncanplaythrough) = 0;
  NS_IMETHOD SetOncanplaythrough(JSContext* cx, JS::HandleValue aOncanplaythrough) = 0;

  /* [implicit_jscontext] attribute jsval onchange; */
  NS_IMETHOD GetOnchange(JSContext* cx, JS::MutableHandleValue aOnchange) = 0;
  NS_IMETHOD SetOnchange(JSContext* cx, JS::HandleValue aOnchange) = 0;

  /* [implicit_jscontext] attribute jsval onclick; */
  NS_IMETHOD GetOnclick(JSContext* cx, JS::MutableHandleValue aOnclick) = 0;
  NS_IMETHOD SetOnclick(JSContext* cx, JS::HandleValue aOnclick) = 0;

  /* [implicit_jscontext] attribute jsval oncontextmenu; */
  NS_IMETHOD GetOncontextmenu(JSContext* cx, JS::MutableHandleValue aOncontextmenu) = 0;
  NS_IMETHOD SetOncontextmenu(JSContext* cx, JS::HandleValue aOncontextmenu) = 0;

  /* [implicit_jscontext] attribute jsval ondblclick; */
  NS_IMETHOD GetOndblclick(JSContext* cx, JS::MutableHandleValue aOndblclick) = 0;
  NS_IMETHOD SetOndblclick(JSContext* cx, JS::HandleValue aOndblclick) = 0;

  /* [implicit_jscontext] attribute jsval ondrag; */
  NS_IMETHOD GetOndrag(JSContext* cx, JS::MutableHandleValue aOndrag) = 0;
  NS_IMETHOD SetOndrag(JSContext* cx, JS::HandleValue aOndrag) = 0;

  /* [implicit_jscontext] attribute jsval ondragend; */
  NS_IMETHOD GetOndragend(JSContext* cx, JS::MutableHandleValue aOndragend) = 0;
  NS_IMETHOD SetOndragend(JSContext* cx, JS::HandleValue aOndragend) = 0;

  /* [implicit_jscontext] attribute jsval ondragenter; */
  NS_IMETHOD GetOndragenter(JSContext* cx, JS::MutableHandleValue aOndragenter) = 0;
  NS_IMETHOD SetOndragenter(JSContext* cx, JS::HandleValue aOndragenter) = 0;

  /* [implicit_jscontext] attribute jsval ondragleave; */
  NS_IMETHOD GetOndragleave(JSContext* cx, JS::MutableHandleValue aOndragleave) = 0;
  NS_IMETHOD SetOndragleave(JSContext* cx, JS::HandleValue aOndragleave) = 0;

  /* [implicit_jscontext] attribute jsval ondragover; */
  NS_IMETHOD GetOndragover(JSContext* cx, JS::MutableHandleValue aOndragover) = 0;
  NS_IMETHOD SetOndragover(JSContext* cx, JS::HandleValue aOndragover) = 0;

  /* [implicit_jscontext] attribute jsval ondragstart; */
  NS_IMETHOD GetOndragstart(JSContext* cx, JS::MutableHandleValue aOndragstart) = 0;
  NS_IMETHOD SetOndragstart(JSContext* cx, JS::HandleValue aOndragstart) = 0;

  /* [implicit_jscontext] attribute jsval ondrop; */
  NS_IMETHOD GetOndrop(JSContext* cx, JS::MutableHandleValue aOndrop) = 0;
  NS_IMETHOD SetOndrop(JSContext* cx, JS::HandleValue aOndrop) = 0;

  /* [implicit_jscontext] attribute jsval ondurationchange; */
  NS_IMETHOD GetOndurationchange(JSContext* cx, JS::MutableHandleValue aOndurationchange) = 0;
  NS_IMETHOD SetOndurationchange(JSContext* cx, JS::HandleValue aOndurationchange) = 0;

  /* [implicit_jscontext] attribute jsval onemptied; */
  NS_IMETHOD GetOnemptied(JSContext* cx, JS::MutableHandleValue aOnemptied) = 0;
  NS_IMETHOD SetOnemptied(JSContext* cx, JS::HandleValue aOnemptied) = 0;

  /* [implicit_jscontext] attribute jsval onended; */
  NS_IMETHOD GetOnended(JSContext* cx, JS::MutableHandleValue aOnended) = 0;
  NS_IMETHOD SetOnended(JSContext* cx, JS::HandleValue aOnended) = 0;

  /* [implicit_jscontext] attribute jsval onerror; */
  NS_IMETHOD GetOnerror(JSContext* cx, JS::MutableHandleValue aOnerror) = 0;
  NS_IMETHOD SetOnerror(JSContext* cx, JS::HandleValue aOnerror) = 0;

  /* [implicit_jscontext] attribute jsval onfocus; */
  NS_IMETHOD GetOnfocus(JSContext* cx, JS::MutableHandleValue aOnfocus) = 0;
  NS_IMETHOD SetOnfocus(JSContext* cx, JS::HandleValue aOnfocus) = 0;

  /* [implicit_jscontext] attribute jsval oninput; */
  NS_IMETHOD GetOninput(JSContext* cx, JS::MutableHandleValue aOninput) = 0;
  NS_IMETHOD SetOninput(JSContext* cx, JS::HandleValue aOninput) = 0;

  /* [implicit_jscontext] attribute jsval oninvalid; */
  NS_IMETHOD GetOninvalid(JSContext* cx, JS::MutableHandleValue aOninvalid) = 0;
  NS_IMETHOD SetOninvalid(JSContext* cx, JS::HandleValue aOninvalid) = 0;

  /* [implicit_jscontext] attribute jsval onkeydown; */
  NS_IMETHOD GetOnkeydown(JSContext* cx, JS::MutableHandleValue aOnkeydown) = 0;
  NS_IMETHOD SetOnkeydown(JSContext* cx, JS::HandleValue aOnkeydown) = 0;

  /* [implicit_jscontext] attribute jsval onkeypress; */
  NS_IMETHOD GetOnkeypress(JSContext* cx, JS::MutableHandleValue aOnkeypress) = 0;
  NS_IMETHOD SetOnkeypress(JSContext* cx, JS::HandleValue aOnkeypress) = 0;

  /* [implicit_jscontext] attribute jsval onkeyup; */
  NS_IMETHOD GetOnkeyup(JSContext* cx, JS::MutableHandleValue aOnkeyup) = 0;
  NS_IMETHOD SetOnkeyup(JSContext* cx, JS::HandleValue aOnkeyup) = 0;

  /* [implicit_jscontext] attribute jsval onload; */
  NS_IMETHOD GetOnload(JSContext* cx, JS::MutableHandleValue aOnload) = 0;
  NS_IMETHOD SetOnload(JSContext* cx, JS::HandleValue aOnload) = 0;

  /* [implicit_jscontext] attribute jsval onloadeddata; */
  NS_IMETHOD GetOnloadeddata(JSContext* cx, JS::MutableHandleValue aOnloadeddata) = 0;
  NS_IMETHOD SetOnloadeddata(JSContext* cx, JS::HandleValue aOnloadeddata) = 0;

  /* [implicit_jscontext] attribute jsval onloadedmetadata; */
  NS_IMETHOD GetOnloadedmetadata(JSContext* cx, JS::MutableHandleValue aOnloadedmetadata) = 0;
  NS_IMETHOD SetOnloadedmetadata(JSContext* cx, JS::HandleValue aOnloadedmetadata) = 0;

  /* [implicit_jscontext] attribute jsval onloadstart; */
  NS_IMETHOD GetOnloadstart(JSContext* cx, JS::MutableHandleValue aOnloadstart) = 0;
  NS_IMETHOD SetOnloadstart(JSContext* cx, JS::HandleValue aOnloadstart) = 0;

  /* [implicit_jscontext] attribute jsval onmousedown; */
  NS_IMETHOD GetOnmousedown(JSContext* cx, JS::MutableHandleValue aOnmousedown) = 0;
  NS_IMETHOD SetOnmousedown(JSContext* cx, JS::HandleValue aOnmousedown) = 0;

  /* [implicit_jscontext] attribute jsval onmousemove; */
  NS_IMETHOD GetOnmousemove(JSContext* cx, JS::MutableHandleValue aOnmousemove) = 0;
  NS_IMETHOD SetOnmousemove(JSContext* cx, JS::HandleValue aOnmousemove) = 0;

  /* [implicit_jscontext] attribute jsval onmouseout; */
  NS_IMETHOD GetOnmouseout(JSContext* cx, JS::MutableHandleValue aOnmouseout) = 0;
  NS_IMETHOD SetOnmouseout(JSContext* cx, JS::HandleValue aOnmouseout) = 0;

  /* [implicit_jscontext] attribute jsval onmouseover; */
  NS_IMETHOD GetOnmouseover(JSContext* cx, JS::MutableHandleValue aOnmouseover) = 0;
  NS_IMETHOD SetOnmouseover(JSContext* cx, JS::HandleValue aOnmouseover) = 0;

  /* [implicit_jscontext] attribute jsval onmouseup; */
  NS_IMETHOD GetOnmouseup(JSContext* cx, JS::MutableHandleValue aOnmouseup) = 0;
  NS_IMETHOD SetOnmouseup(JSContext* cx, JS::HandleValue aOnmouseup) = 0;

  /* [implicit_jscontext] attribute jsval onmozfullscreenchange; */
  NS_IMETHOD GetOnmozfullscreenchange(JSContext* cx, JS::MutableHandleValue aOnmozfullscreenchange) = 0;
  NS_IMETHOD SetOnmozfullscreenchange(JSContext* cx, JS::HandleValue aOnmozfullscreenchange) = 0;

  /* [implicit_jscontext] attribute jsval onmozfullscreenerror; */
  NS_IMETHOD GetOnmozfullscreenerror(JSContext* cx, JS::MutableHandleValue aOnmozfullscreenerror) = 0;
  NS_IMETHOD SetOnmozfullscreenerror(JSContext* cx, JS::HandleValue aOnmozfullscreenerror) = 0;

  /* [implicit_jscontext] attribute jsval onmozpointerlockchange; */
  NS_IMETHOD GetOnmozpointerlockchange(JSContext* cx, JS::MutableHandleValue aOnmozpointerlockchange) = 0;
  NS_IMETHOD SetOnmozpointerlockchange(JSContext* cx, JS::HandleValue aOnmozpointerlockchange) = 0;

  /* [implicit_jscontext] attribute jsval onmozpointerlockerror; */
  NS_IMETHOD GetOnmozpointerlockerror(JSContext* cx, JS::MutableHandleValue aOnmozpointerlockerror) = 0;
  NS_IMETHOD SetOnmozpointerlockerror(JSContext* cx, JS::HandleValue aOnmozpointerlockerror) = 0;

  /* [implicit_jscontext] attribute jsval onpause; */
  NS_IMETHOD GetOnpause(JSContext* cx, JS::MutableHandleValue aOnpause) = 0;
  NS_IMETHOD SetOnpause(JSContext* cx, JS::HandleValue aOnpause) = 0;

  /* [implicit_jscontext] attribute jsval onplay; */
  NS_IMETHOD GetOnplay(JSContext* cx, JS::MutableHandleValue aOnplay) = 0;
  NS_IMETHOD SetOnplay(JSContext* cx, JS::HandleValue aOnplay) = 0;

  /* [implicit_jscontext] attribute jsval onplaying; */
  NS_IMETHOD GetOnplaying(JSContext* cx, JS::MutableHandleValue aOnplaying) = 0;
  NS_IMETHOD SetOnplaying(JSContext* cx, JS::HandleValue aOnplaying) = 0;

  /* [implicit_jscontext] attribute jsval onprogress; */
  NS_IMETHOD GetOnprogress(JSContext* cx, JS::MutableHandleValue aOnprogress) = 0;
  NS_IMETHOD SetOnprogress(JSContext* cx, JS::HandleValue aOnprogress) = 0;

  /* [implicit_jscontext] attribute jsval onratechange; */
  NS_IMETHOD GetOnratechange(JSContext* cx, JS::MutableHandleValue aOnratechange) = 0;
  NS_IMETHOD SetOnratechange(JSContext* cx, JS::HandleValue aOnratechange) = 0;

  /* [implicit_jscontext] attribute jsval onreset; */
  NS_IMETHOD GetOnreset(JSContext* cx, JS::MutableHandleValue aOnreset) = 0;
  NS_IMETHOD SetOnreset(JSContext* cx, JS::HandleValue aOnreset) = 0;

  /* [implicit_jscontext] attribute jsval onscroll; */
  NS_IMETHOD GetOnscroll(JSContext* cx, JS::MutableHandleValue aOnscroll) = 0;
  NS_IMETHOD SetOnscroll(JSContext* cx, JS::HandleValue aOnscroll) = 0;

  /* [implicit_jscontext] attribute jsval onseeked; */
  NS_IMETHOD GetOnseeked(JSContext* cx, JS::MutableHandleValue aOnseeked) = 0;
  NS_IMETHOD SetOnseeked(JSContext* cx, JS::HandleValue aOnseeked) = 0;

  /* [implicit_jscontext] attribute jsval onseeking; */
  NS_IMETHOD GetOnseeking(JSContext* cx, JS::MutableHandleValue aOnseeking) = 0;
  NS_IMETHOD SetOnseeking(JSContext* cx, JS::HandleValue aOnseeking) = 0;

  /* [implicit_jscontext] attribute jsval onselect; */
  NS_IMETHOD GetOnselect(JSContext* cx, JS::MutableHandleValue aOnselect) = 0;
  NS_IMETHOD SetOnselect(JSContext* cx, JS::HandleValue aOnselect) = 0;

  /* [implicit_jscontext] attribute jsval onshow; */
  NS_IMETHOD GetOnshow(JSContext* cx, JS::MutableHandleValue aOnshow) = 0;
  NS_IMETHOD SetOnshow(JSContext* cx, JS::HandleValue aOnshow) = 0;

  /* [implicit_jscontext] attribute jsval onstalled; */
  NS_IMETHOD GetOnstalled(JSContext* cx, JS::MutableHandleValue aOnstalled) = 0;
  NS_IMETHOD SetOnstalled(JSContext* cx, JS::HandleValue aOnstalled) = 0;

  /* [implicit_jscontext] attribute jsval onsubmit; */
  NS_IMETHOD GetOnsubmit(JSContext* cx, JS::MutableHandleValue aOnsubmit) = 0;
  NS_IMETHOD SetOnsubmit(JSContext* cx, JS::HandleValue aOnsubmit) = 0;

  /* [implicit_jscontext] attribute jsval onsuspend; */
  NS_IMETHOD GetOnsuspend(JSContext* cx, JS::MutableHandleValue aOnsuspend) = 0;
  NS_IMETHOD SetOnsuspend(JSContext* cx, JS::HandleValue aOnsuspend) = 0;

  /* [implicit_jscontext] attribute jsval ontimeupdate; */
  NS_IMETHOD GetOntimeupdate(JSContext* cx, JS::MutableHandleValue aOntimeupdate) = 0;
  NS_IMETHOD SetOntimeupdate(JSContext* cx, JS::HandleValue aOntimeupdate) = 0;

  /* [implicit_jscontext] attribute jsval onvolumechange; */
  NS_IMETHOD GetOnvolumechange(JSContext* cx, JS::MutableHandleValue aOnvolumechange) = 0;
  NS_IMETHOD SetOnvolumechange(JSContext* cx, JS::HandleValue aOnvolumechange) = 0;

  /* [implicit_jscontext] attribute jsval onwaiting; */
  NS_IMETHOD GetOnwaiting(JSContext* cx, JS::MutableHandleValue aOnwaiting) = 0;
  NS_IMETHOD SetOnwaiting(JSContext* cx, JS::HandleValue aOnwaiting) = 0;

  /* [implicit_jscontext] attribute jsval onwheel; */
  NS_IMETHOD GetOnwheel(JSContext* cx, JS::MutableHandleValue aOnwheel) = 0;
  NS_IMETHOD SetOnwheel(JSContext* cx, JS::HandleValue aOnwheel) = 0;

  /* [implicit_jscontext] attribute jsval onpointerdown; */
  NS_IMETHOD GetOnpointerdown(JSContext* cx, JS::MutableHandleValue aOnpointerdown) = 0;
  NS_IMETHOD SetOnpointerdown(JSContext* cx, JS::HandleValue aOnpointerdown) = 0;

  /* [implicit_jscontext] attribute jsval onpointermove; */
  NS_IMETHOD GetOnpointermove(JSContext* cx, JS::MutableHandleValue aOnpointermove) = 0;
  NS_IMETHOD SetOnpointermove(JSContext* cx, JS::HandleValue aOnpointermove) = 0;

  /* [implicit_jscontext] attribute jsval onpointerout; */
  NS_IMETHOD GetOnpointerout(JSContext* cx, JS::MutableHandleValue aOnpointerout) = 0;
  NS_IMETHOD SetOnpointerout(JSContext* cx, JS::HandleValue aOnpointerout) = 0;

  /* [implicit_jscontext] attribute jsval onpointerover; */
  NS_IMETHOD GetOnpointerover(JSContext* cx, JS::MutableHandleValue aOnpointerover) = 0;
  NS_IMETHOD SetOnpointerover(JSContext* cx, JS::HandleValue aOnpointerover) = 0;

  /* [implicit_jscontext] attribute jsval onpointerup; */
  NS_IMETHOD GetOnpointerup(JSContext* cx, JS::MutableHandleValue aOnpointerup) = 0;
  NS_IMETHOD SetOnpointerup(JSContext* cx, JS::HandleValue aOnpointerup) = 0;

  /* [implicit_jscontext] attribute jsval onpointerenter; */
  NS_IMETHOD GetOnpointerenter(JSContext* cx, JS::MutableHandleValue aOnpointerenter) = 0;
  NS_IMETHOD SetOnpointerenter(JSContext* cx, JS::HandleValue aOnpointerenter) = 0;

  /* [implicit_jscontext] attribute jsval onpointerleave; */
  NS_IMETHOD GetOnpointerleave(JSContext* cx, JS::MutableHandleValue aOnpointerleave) = 0;
  NS_IMETHOD SetOnpointerleave(JSContext* cx, JS::HandleValue aOnpointerleave) = 0;

  /* [implicit_jscontext] attribute jsval ongotpointercapture; */
  NS_IMETHOD GetOngotpointercapture(JSContext* cx, JS::MutableHandleValue aOngotpointercapture) = 0;
  NS_IMETHOD SetOngotpointercapture(JSContext* cx, JS::HandleValue aOngotpointercapture) = 0;

  /* [implicit_jscontext] attribute jsval onlostpointercapture; */
  NS_IMETHOD GetOnlostpointercapture(JSContext* cx, JS::MutableHandleValue aOnlostpointercapture) = 0;
  NS_IMETHOD SetOnlostpointercapture(JSContext* cx, JS::HandleValue aOnlostpointercapture) = 0;

  /* [implicit_jscontext] attribute jsval onpointercancel; */
  NS_IMETHOD GetOnpointercancel(JSContext* cx, JS::MutableHandleValue aOnpointercancel) = 0;
  NS_IMETHOD SetOnpointercancel(JSContext* cx, JS::HandleValue aOnpointercancel) = 0;

  /* [implicit_jscontext] attribute jsval oncopy; */
  NS_IMETHOD GetOncopy(JSContext* cx, JS::MutableHandleValue aOncopy) = 0;
  NS_IMETHOD SetOncopy(JSContext* cx, JS::HandleValue aOncopy) = 0;

  /* [implicit_jscontext] attribute jsval oncut; */
  NS_IMETHOD GetOncut(JSContext* cx, JS::MutableHandleValue aOncut) = 0;
  NS_IMETHOD SetOncut(JSContext* cx, JS::HandleValue aOncut) = 0;

  /* [implicit_jscontext] attribute jsval onpaste; */
  NS_IMETHOD GetOnpaste(JSContext* cx, JS::MutableHandleValue aOnpaste) = 0;
  NS_IMETHOD SetOnpaste(JSContext* cx, JS::HandleValue aOnpaste) = 0;

  /* [implicit_jscontext] attribute jsval onbeforescriptexecute; */
  NS_IMETHOD GetOnbeforescriptexecute(JSContext* cx, JS::MutableHandleValue aOnbeforescriptexecute) = 0;
  NS_IMETHOD SetOnbeforescriptexecute(JSContext* cx, JS::HandleValue aOnbeforescriptexecute) = 0;

  /* [implicit_jscontext] attribute jsval onafterscriptexecute; */
  NS_IMETHOD GetOnafterscriptexecute(JSContext* cx, JS::MutableHandleValue aOnafterscriptexecute) = 0;
  NS_IMETHOD SetOnafterscriptexecute(JSContext* cx, JS::HandleValue aOnafterscriptexecute) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInlineEventHandlers, NS_IINLINEEVENTHANDLERS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINLINEEVENTHANDLERS \
  NS_IMETHOD GetOnabort(JSContext* cx, JS::MutableHandleValue aOnabort); \
  NS_IMETHOD SetOnabort(JSContext* cx, JS::HandleValue aOnabort); \
  NS_IMETHOD GetOnblur(JSContext* cx, JS::MutableHandleValue aOnblur); \
  NS_IMETHOD SetOnblur(JSContext* cx, JS::HandleValue aOnblur); \
  NS_IMETHOD GetOncanplay(JSContext* cx, JS::MutableHandleValue aOncanplay); \
  NS_IMETHOD SetOncanplay(JSContext* cx, JS::HandleValue aOncanplay); \
  NS_IMETHOD GetOncanplaythrough(JSContext* cx, JS::MutableHandleValue aOncanplaythrough); \
  NS_IMETHOD SetOncanplaythrough(JSContext* cx, JS::HandleValue aOncanplaythrough); \
  NS_IMETHOD GetOnchange(JSContext* cx, JS::MutableHandleValue aOnchange); \
  NS_IMETHOD SetOnchange(JSContext* cx, JS::HandleValue aOnchange); \
  NS_IMETHOD GetOnclick(JSContext* cx, JS::MutableHandleValue aOnclick); \
  NS_IMETHOD SetOnclick(JSContext* cx, JS::HandleValue aOnclick); \
  NS_IMETHOD GetOncontextmenu(JSContext* cx, JS::MutableHandleValue aOncontextmenu); \
  NS_IMETHOD SetOncontextmenu(JSContext* cx, JS::HandleValue aOncontextmenu); \
  NS_IMETHOD GetOndblclick(JSContext* cx, JS::MutableHandleValue aOndblclick); \
  NS_IMETHOD SetOndblclick(JSContext* cx, JS::HandleValue aOndblclick); \
  NS_IMETHOD GetOndrag(JSContext* cx, JS::MutableHandleValue aOndrag); \
  NS_IMETHOD SetOndrag(JSContext* cx, JS::HandleValue aOndrag); \
  NS_IMETHOD GetOndragend(JSContext* cx, JS::MutableHandleValue aOndragend); \
  NS_IMETHOD SetOndragend(JSContext* cx, JS::HandleValue aOndragend); \
  NS_IMETHOD GetOndragenter(JSContext* cx, JS::MutableHandleValue aOndragenter); \
  NS_IMETHOD SetOndragenter(JSContext* cx, JS::HandleValue aOndragenter); \
  NS_IMETHOD GetOndragleave(JSContext* cx, JS::MutableHandleValue aOndragleave); \
  NS_IMETHOD SetOndragleave(JSContext* cx, JS::HandleValue aOndragleave); \
  NS_IMETHOD GetOndragover(JSContext* cx, JS::MutableHandleValue aOndragover); \
  NS_IMETHOD SetOndragover(JSContext* cx, JS::HandleValue aOndragover); \
  NS_IMETHOD GetOndragstart(JSContext* cx, JS::MutableHandleValue aOndragstart); \
  NS_IMETHOD SetOndragstart(JSContext* cx, JS::HandleValue aOndragstart); \
  NS_IMETHOD GetOndrop(JSContext* cx, JS::MutableHandleValue aOndrop); \
  NS_IMETHOD SetOndrop(JSContext* cx, JS::HandleValue aOndrop); \
  NS_IMETHOD GetOndurationchange(JSContext* cx, JS::MutableHandleValue aOndurationchange); \
  NS_IMETHOD SetOndurationchange(JSContext* cx, JS::HandleValue aOndurationchange); \
  NS_IMETHOD GetOnemptied(JSContext* cx, JS::MutableHandleValue aOnemptied); \
  NS_IMETHOD SetOnemptied(JSContext* cx, JS::HandleValue aOnemptied); \
  NS_IMETHOD GetOnended(JSContext* cx, JS::MutableHandleValue aOnended); \
  NS_IMETHOD SetOnended(JSContext* cx, JS::HandleValue aOnended); \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::MutableHandleValue aOnerror); \
  NS_IMETHOD SetOnerror(JSContext* cx, JS::HandleValue aOnerror); \
  NS_IMETHOD GetOnfocus(JSContext* cx, JS::MutableHandleValue aOnfocus); \
  NS_IMETHOD SetOnfocus(JSContext* cx, JS::HandleValue aOnfocus); \
  NS_IMETHOD GetOninput(JSContext* cx, JS::MutableHandleValue aOninput); \
  NS_IMETHOD SetOninput(JSContext* cx, JS::HandleValue aOninput); \
  NS_IMETHOD GetOninvalid(JSContext* cx, JS::MutableHandleValue aOninvalid); \
  NS_IMETHOD SetOninvalid(JSContext* cx, JS::HandleValue aOninvalid); \
  NS_IMETHOD GetOnkeydown(JSContext* cx, JS::MutableHandleValue aOnkeydown); \
  NS_IMETHOD SetOnkeydown(JSContext* cx, JS::HandleValue aOnkeydown); \
  NS_IMETHOD GetOnkeypress(JSContext* cx, JS::MutableHandleValue aOnkeypress); \
  NS_IMETHOD SetOnkeypress(JSContext* cx, JS::HandleValue aOnkeypress); \
  NS_IMETHOD GetOnkeyup(JSContext* cx, JS::MutableHandleValue aOnkeyup); \
  NS_IMETHOD SetOnkeyup(JSContext* cx, JS::HandleValue aOnkeyup); \
  NS_IMETHOD GetOnload(JSContext* cx, JS::MutableHandleValue aOnload); \
  NS_IMETHOD SetOnload(JSContext* cx, JS::HandleValue aOnload); \
  NS_IMETHOD GetOnloadeddata(JSContext* cx, JS::MutableHandleValue aOnloadeddata); \
  NS_IMETHOD SetOnloadeddata(JSContext* cx, JS::HandleValue aOnloadeddata); \
  NS_IMETHOD GetOnloadedmetadata(JSContext* cx, JS::MutableHandleValue aOnloadedmetadata); \
  NS_IMETHOD SetOnloadedmetadata(JSContext* cx, JS::HandleValue aOnloadedmetadata); \
  NS_IMETHOD GetOnloadstart(JSContext* cx, JS::MutableHandleValue aOnloadstart); \
  NS_IMETHOD SetOnloadstart(JSContext* cx, JS::HandleValue aOnloadstart); \
  NS_IMETHOD GetOnmousedown(JSContext* cx, JS::MutableHandleValue aOnmousedown); \
  NS_IMETHOD SetOnmousedown(JSContext* cx, JS::HandleValue aOnmousedown); \
  NS_IMETHOD GetOnmousemove(JSContext* cx, JS::MutableHandleValue aOnmousemove); \
  NS_IMETHOD SetOnmousemove(JSContext* cx, JS::HandleValue aOnmousemove); \
  NS_IMETHOD GetOnmouseout(JSContext* cx, JS::MutableHandleValue aOnmouseout); \
  NS_IMETHOD SetOnmouseout(JSContext* cx, JS::HandleValue aOnmouseout); \
  NS_IMETHOD GetOnmouseover(JSContext* cx, JS::MutableHandleValue aOnmouseover); \
  NS_IMETHOD SetOnmouseover(JSContext* cx, JS::HandleValue aOnmouseover); \
  NS_IMETHOD GetOnmouseup(JSContext* cx, JS::MutableHandleValue aOnmouseup); \
  NS_IMETHOD SetOnmouseup(JSContext* cx, JS::HandleValue aOnmouseup); \
  NS_IMETHOD GetOnmozfullscreenchange(JSContext* cx, JS::MutableHandleValue aOnmozfullscreenchange); \
  NS_IMETHOD SetOnmozfullscreenchange(JSContext* cx, JS::HandleValue aOnmozfullscreenchange); \
  NS_IMETHOD GetOnmozfullscreenerror(JSContext* cx, JS::MutableHandleValue aOnmozfullscreenerror); \
  NS_IMETHOD SetOnmozfullscreenerror(JSContext* cx, JS::HandleValue aOnmozfullscreenerror); \
  NS_IMETHOD GetOnmozpointerlockchange(JSContext* cx, JS::MutableHandleValue aOnmozpointerlockchange); \
  NS_IMETHOD SetOnmozpointerlockchange(JSContext* cx, JS::HandleValue aOnmozpointerlockchange); \
  NS_IMETHOD GetOnmozpointerlockerror(JSContext* cx, JS::MutableHandleValue aOnmozpointerlockerror); \
  NS_IMETHOD SetOnmozpointerlockerror(JSContext* cx, JS::HandleValue aOnmozpointerlockerror); \
  NS_IMETHOD GetOnpause(JSContext* cx, JS::MutableHandleValue aOnpause); \
  NS_IMETHOD SetOnpause(JSContext* cx, JS::HandleValue aOnpause); \
  NS_IMETHOD GetOnplay(JSContext* cx, JS::MutableHandleValue aOnplay); \
  NS_IMETHOD SetOnplay(JSContext* cx, JS::HandleValue aOnplay); \
  NS_IMETHOD GetOnplaying(JSContext* cx, JS::MutableHandleValue aOnplaying); \
  NS_IMETHOD SetOnplaying(JSContext* cx, JS::HandleValue aOnplaying); \
  NS_IMETHOD GetOnprogress(JSContext* cx, JS::MutableHandleValue aOnprogress); \
  NS_IMETHOD SetOnprogress(JSContext* cx, JS::HandleValue aOnprogress); \
  NS_IMETHOD GetOnratechange(JSContext* cx, JS::MutableHandleValue aOnratechange); \
  NS_IMETHOD SetOnratechange(JSContext* cx, JS::HandleValue aOnratechange); \
  NS_IMETHOD GetOnreset(JSContext* cx, JS::MutableHandleValue aOnreset); \
  NS_IMETHOD SetOnreset(JSContext* cx, JS::HandleValue aOnreset); \
  NS_IMETHOD GetOnscroll(JSContext* cx, JS::MutableHandleValue aOnscroll); \
  NS_IMETHOD SetOnscroll(JSContext* cx, JS::HandleValue aOnscroll); \
  NS_IMETHOD GetOnseeked(JSContext* cx, JS::MutableHandleValue aOnseeked); \
  NS_IMETHOD SetOnseeked(JSContext* cx, JS::HandleValue aOnseeked); \
  NS_IMETHOD GetOnseeking(JSContext* cx, JS::MutableHandleValue aOnseeking); \
  NS_IMETHOD SetOnseeking(JSContext* cx, JS::HandleValue aOnseeking); \
  NS_IMETHOD GetOnselect(JSContext* cx, JS::MutableHandleValue aOnselect); \
  NS_IMETHOD SetOnselect(JSContext* cx, JS::HandleValue aOnselect); \
  NS_IMETHOD GetOnshow(JSContext* cx, JS::MutableHandleValue aOnshow); \
  NS_IMETHOD SetOnshow(JSContext* cx, JS::HandleValue aOnshow); \
  NS_IMETHOD GetOnstalled(JSContext* cx, JS::MutableHandleValue aOnstalled); \
  NS_IMETHOD SetOnstalled(JSContext* cx, JS::HandleValue aOnstalled); \
  NS_IMETHOD GetOnsubmit(JSContext* cx, JS::MutableHandleValue aOnsubmit); \
  NS_IMETHOD SetOnsubmit(JSContext* cx, JS::HandleValue aOnsubmit); \
  NS_IMETHOD GetOnsuspend(JSContext* cx, JS::MutableHandleValue aOnsuspend); \
  NS_IMETHOD SetOnsuspend(JSContext* cx, JS::HandleValue aOnsuspend); \
  NS_IMETHOD GetOntimeupdate(JSContext* cx, JS::MutableHandleValue aOntimeupdate); \
  NS_IMETHOD SetOntimeupdate(JSContext* cx, JS::HandleValue aOntimeupdate); \
  NS_IMETHOD GetOnvolumechange(JSContext* cx, JS::MutableHandleValue aOnvolumechange); \
  NS_IMETHOD SetOnvolumechange(JSContext* cx, JS::HandleValue aOnvolumechange); \
  NS_IMETHOD GetOnwaiting(JSContext* cx, JS::MutableHandleValue aOnwaiting); \
  NS_IMETHOD SetOnwaiting(JSContext* cx, JS::HandleValue aOnwaiting); \
  NS_IMETHOD GetOnwheel(JSContext* cx, JS::MutableHandleValue aOnwheel); \
  NS_IMETHOD SetOnwheel(JSContext* cx, JS::HandleValue aOnwheel); \
  NS_IMETHOD GetOnpointerdown(JSContext* cx, JS::MutableHandleValue aOnpointerdown); \
  NS_IMETHOD SetOnpointerdown(JSContext* cx, JS::HandleValue aOnpointerdown); \
  NS_IMETHOD GetOnpointermove(JSContext* cx, JS::MutableHandleValue aOnpointermove); \
  NS_IMETHOD SetOnpointermove(JSContext* cx, JS::HandleValue aOnpointermove); \
  NS_IMETHOD GetOnpointerout(JSContext* cx, JS::MutableHandleValue aOnpointerout); \
  NS_IMETHOD SetOnpointerout(JSContext* cx, JS::HandleValue aOnpointerout); \
  NS_IMETHOD GetOnpointerover(JSContext* cx, JS::MutableHandleValue aOnpointerover); \
  NS_IMETHOD SetOnpointerover(JSContext* cx, JS::HandleValue aOnpointerover); \
  NS_IMETHOD GetOnpointerup(JSContext* cx, JS::MutableHandleValue aOnpointerup); \
  NS_IMETHOD SetOnpointerup(JSContext* cx, JS::HandleValue aOnpointerup); \
  NS_IMETHOD GetOnpointerenter(JSContext* cx, JS::MutableHandleValue aOnpointerenter); \
  NS_IMETHOD SetOnpointerenter(JSContext* cx, JS::HandleValue aOnpointerenter); \
  NS_IMETHOD GetOnpointerleave(JSContext* cx, JS::MutableHandleValue aOnpointerleave); \
  NS_IMETHOD SetOnpointerleave(JSContext* cx, JS::HandleValue aOnpointerleave); \
  NS_IMETHOD GetOngotpointercapture(JSContext* cx, JS::MutableHandleValue aOngotpointercapture); \
  NS_IMETHOD SetOngotpointercapture(JSContext* cx, JS::HandleValue aOngotpointercapture); \
  NS_IMETHOD GetOnlostpointercapture(JSContext* cx, JS::MutableHandleValue aOnlostpointercapture); \
  NS_IMETHOD SetOnlostpointercapture(JSContext* cx, JS::HandleValue aOnlostpointercapture); \
  NS_IMETHOD GetOnpointercancel(JSContext* cx, JS::MutableHandleValue aOnpointercancel); \
  NS_IMETHOD SetOnpointercancel(JSContext* cx, JS::HandleValue aOnpointercancel); \
  NS_IMETHOD GetOncopy(JSContext* cx, JS::MutableHandleValue aOncopy); \
  NS_IMETHOD SetOncopy(JSContext* cx, JS::HandleValue aOncopy); \
  NS_IMETHOD GetOncut(JSContext* cx, JS::MutableHandleValue aOncut); \
  NS_IMETHOD SetOncut(JSContext* cx, JS::HandleValue aOncut); \
  NS_IMETHOD GetOnpaste(JSContext* cx, JS::MutableHandleValue aOnpaste); \
  NS_IMETHOD SetOnpaste(JSContext* cx, JS::HandleValue aOnpaste); \
  NS_IMETHOD GetOnbeforescriptexecute(JSContext* cx, JS::MutableHandleValue aOnbeforescriptexecute); \
  NS_IMETHOD SetOnbeforescriptexecute(JSContext* cx, JS::HandleValue aOnbeforescriptexecute); \
  NS_IMETHOD GetOnafterscriptexecute(JSContext* cx, JS::MutableHandleValue aOnafterscriptexecute); \
  NS_IMETHOD SetOnafterscriptexecute(JSContext* cx, JS::HandleValue aOnafterscriptexecute); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINLINEEVENTHANDLERS(_to) \
  NS_IMETHOD GetOnabort(JSContext* cx, JS::MutableHandleValue aOnabort) { return _to GetOnabort(cx, aOnabort); } \
  NS_IMETHOD SetOnabort(JSContext* cx, JS::HandleValue aOnabort) { return _to SetOnabort(cx, aOnabort); } \
  NS_IMETHOD GetOnblur(JSContext* cx, JS::MutableHandleValue aOnblur) { return _to GetOnblur(cx, aOnblur); } \
  NS_IMETHOD SetOnblur(JSContext* cx, JS::HandleValue aOnblur) { return _to SetOnblur(cx, aOnblur); } \
  NS_IMETHOD GetOncanplay(JSContext* cx, JS::MutableHandleValue aOncanplay) { return _to GetOncanplay(cx, aOncanplay); } \
  NS_IMETHOD SetOncanplay(JSContext* cx, JS::HandleValue aOncanplay) { return _to SetOncanplay(cx, aOncanplay); } \
  NS_IMETHOD GetOncanplaythrough(JSContext* cx, JS::MutableHandleValue aOncanplaythrough) { return _to GetOncanplaythrough(cx, aOncanplaythrough); } \
  NS_IMETHOD SetOncanplaythrough(JSContext* cx, JS::HandleValue aOncanplaythrough) { return _to SetOncanplaythrough(cx, aOncanplaythrough); } \
  NS_IMETHOD GetOnchange(JSContext* cx, JS::MutableHandleValue aOnchange) { return _to GetOnchange(cx, aOnchange); } \
  NS_IMETHOD SetOnchange(JSContext* cx, JS::HandleValue aOnchange) { return _to SetOnchange(cx, aOnchange); } \
  NS_IMETHOD GetOnclick(JSContext* cx, JS::MutableHandleValue aOnclick) { return _to GetOnclick(cx, aOnclick); } \
  NS_IMETHOD SetOnclick(JSContext* cx, JS::HandleValue aOnclick) { return _to SetOnclick(cx, aOnclick); } \
  NS_IMETHOD GetOncontextmenu(JSContext* cx, JS::MutableHandleValue aOncontextmenu) { return _to GetOncontextmenu(cx, aOncontextmenu); } \
  NS_IMETHOD SetOncontextmenu(JSContext* cx, JS::HandleValue aOncontextmenu) { return _to SetOncontextmenu(cx, aOncontextmenu); } \
  NS_IMETHOD GetOndblclick(JSContext* cx, JS::MutableHandleValue aOndblclick) { return _to GetOndblclick(cx, aOndblclick); } \
  NS_IMETHOD SetOndblclick(JSContext* cx, JS::HandleValue aOndblclick) { return _to SetOndblclick(cx, aOndblclick); } \
  NS_IMETHOD GetOndrag(JSContext* cx, JS::MutableHandleValue aOndrag) { return _to GetOndrag(cx, aOndrag); } \
  NS_IMETHOD SetOndrag(JSContext* cx, JS::HandleValue aOndrag) { return _to SetOndrag(cx, aOndrag); } \
  NS_IMETHOD GetOndragend(JSContext* cx, JS::MutableHandleValue aOndragend) { return _to GetOndragend(cx, aOndragend); } \
  NS_IMETHOD SetOndragend(JSContext* cx, JS::HandleValue aOndragend) { return _to SetOndragend(cx, aOndragend); } \
  NS_IMETHOD GetOndragenter(JSContext* cx, JS::MutableHandleValue aOndragenter) { return _to GetOndragenter(cx, aOndragenter); } \
  NS_IMETHOD SetOndragenter(JSContext* cx, JS::HandleValue aOndragenter) { return _to SetOndragenter(cx, aOndragenter); } \
  NS_IMETHOD GetOndragleave(JSContext* cx, JS::MutableHandleValue aOndragleave) { return _to GetOndragleave(cx, aOndragleave); } \
  NS_IMETHOD SetOndragleave(JSContext* cx, JS::HandleValue aOndragleave) { return _to SetOndragleave(cx, aOndragleave); } \
  NS_IMETHOD GetOndragover(JSContext* cx, JS::MutableHandleValue aOndragover) { return _to GetOndragover(cx, aOndragover); } \
  NS_IMETHOD SetOndragover(JSContext* cx, JS::HandleValue aOndragover) { return _to SetOndragover(cx, aOndragover); } \
  NS_IMETHOD GetOndragstart(JSContext* cx, JS::MutableHandleValue aOndragstart) { return _to GetOndragstart(cx, aOndragstart); } \
  NS_IMETHOD SetOndragstart(JSContext* cx, JS::HandleValue aOndragstart) { return _to SetOndragstart(cx, aOndragstart); } \
  NS_IMETHOD GetOndrop(JSContext* cx, JS::MutableHandleValue aOndrop) { return _to GetOndrop(cx, aOndrop); } \
  NS_IMETHOD SetOndrop(JSContext* cx, JS::HandleValue aOndrop) { return _to SetOndrop(cx, aOndrop); } \
  NS_IMETHOD GetOndurationchange(JSContext* cx, JS::MutableHandleValue aOndurationchange) { return _to GetOndurationchange(cx, aOndurationchange); } \
  NS_IMETHOD SetOndurationchange(JSContext* cx, JS::HandleValue aOndurationchange) { return _to SetOndurationchange(cx, aOndurationchange); } \
  NS_IMETHOD GetOnemptied(JSContext* cx, JS::MutableHandleValue aOnemptied) { return _to GetOnemptied(cx, aOnemptied); } \
  NS_IMETHOD SetOnemptied(JSContext* cx, JS::HandleValue aOnemptied) { return _to SetOnemptied(cx, aOnemptied); } \
  NS_IMETHOD GetOnended(JSContext* cx, JS::MutableHandleValue aOnended) { return _to GetOnended(cx, aOnended); } \
  NS_IMETHOD SetOnended(JSContext* cx, JS::HandleValue aOnended) { return _to SetOnended(cx, aOnended); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::MutableHandleValue aOnerror) { return _to GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, JS::HandleValue aOnerror) { return _to SetOnerror(cx, aOnerror); } \
  NS_IMETHOD GetOnfocus(JSContext* cx, JS::MutableHandleValue aOnfocus) { return _to GetOnfocus(cx, aOnfocus); } \
  NS_IMETHOD SetOnfocus(JSContext* cx, JS::HandleValue aOnfocus) { return _to SetOnfocus(cx, aOnfocus); } \
  NS_IMETHOD GetOninput(JSContext* cx, JS::MutableHandleValue aOninput) { return _to GetOninput(cx, aOninput); } \
  NS_IMETHOD SetOninput(JSContext* cx, JS::HandleValue aOninput) { return _to SetOninput(cx, aOninput); } \
  NS_IMETHOD GetOninvalid(JSContext* cx, JS::MutableHandleValue aOninvalid) { return _to GetOninvalid(cx, aOninvalid); } \
  NS_IMETHOD SetOninvalid(JSContext* cx, JS::HandleValue aOninvalid) { return _to SetOninvalid(cx, aOninvalid); } \
  NS_IMETHOD GetOnkeydown(JSContext* cx, JS::MutableHandleValue aOnkeydown) { return _to GetOnkeydown(cx, aOnkeydown); } \
  NS_IMETHOD SetOnkeydown(JSContext* cx, JS::HandleValue aOnkeydown) { return _to SetOnkeydown(cx, aOnkeydown); } \
  NS_IMETHOD GetOnkeypress(JSContext* cx, JS::MutableHandleValue aOnkeypress) { return _to GetOnkeypress(cx, aOnkeypress); } \
  NS_IMETHOD SetOnkeypress(JSContext* cx, JS::HandleValue aOnkeypress) { return _to SetOnkeypress(cx, aOnkeypress); } \
  NS_IMETHOD GetOnkeyup(JSContext* cx, JS::MutableHandleValue aOnkeyup) { return _to GetOnkeyup(cx, aOnkeyup); } \
  NS_IMETHOD SetOnkeyup(JSContext* cx, JS::HandleValue aOnkeyup) { return _to SetOnkeyup(cx, aOnkeyup); } \
  NS_IMETHOD GetOnload(JSContext* cx, JS::MutableHandleValue aOnload) { return _to GetOnload(cx, aOnload); } \
  NS_IMETHOD SetOnload(JSContext* cx, JS::HandleValue aOnload) { return _to SetOnload(cx, aOnload); } \
  NS_IMETHOD GetOnloadeddata(JSContext* cx, JS::MutableHandleValue aOnloadeddata) { return _to GetOnloadeddata(cx, aOnloadeddata); } \
  NS_IMETHOD SetOnloadeddata(JSContext* cx, JS::HandleValue aOnloadeddata) { return _to SetOnloadeddata(cx, aOnloadeddata); } \
  NS_IMETHOD GetOnloadedmetadata(JSContext* cx, JS::MutableHandleValue aOnloadedmetadata) { return _to GetOnloadedmetadata(cx, aOnloadedmetadata); } \
  NS_IMETHOD SetOnloadedmetadata(JSContext* cx, JS::HandleValue aOnloadedmetadata) { return _to SetOnloadedmetadata(cx, aOnloadedmetadata); } \
  NS_IMETHOD GetOnloadstart(JSContext* cx, JS::MutableHandleValue aOnloadstart) { return _to GetOnloadstart(cx, aOnloadstart); } \
  NS_IMETHOD SetOnloadstart(JSContext* cx, JS::HandleValue aOnloadstart) { return _to SetOnloadstart(cx, aOnloadstart); } \
  NS_IMETHOD GetOnmousedown(JSContext* cx, JS::MutableHandleValue aOnmousedown) { return _to GetOnmousedown(cx, aOnmousedown); } \
  NS_IMETHOD SetOnmousedown(JSContext* cx, JS::HandleValue aOnmousedown) { return _to SetOnmousedown(cx, aOnmousedown); } \
  NS_IMETHOD GetOnmousemove(JSContext* cx, JS::MutableHandleValue aOnmousemove) { return _to GetOnmousemove(cx, aOnmousemove); } \
  NS_IMETHOD SetOnmousemove(JSContext* cx, JS::HandleValue aOnmousemove) { return _to SetOnmousemove(cx, aOnmousemove); } \
  NS_IMETHOD GetOnmouseout(JSContext* cx, JS::MutableHandleValue aOnmouseout) { return _to GetOnmouseout(cx, aOnmouseout); } \
  NS_IMETHOD SetOnmouseout(JSContext* cx, JS::HandleValue aOnmouseout) { return _to SetOnmouseout(cx, aOnmouseout); } \
  NS_IMETHOD GetOnmouseover(JSContext* cx, JS::MutableHandleValue aOnmouseover) { return _to GetOnmouseover(cx, aOnmouseover); } \
  NS_IMETHOD SetOnmouseover(JSContext* cx, JS::HandleValue aOnmouseover) { return _to SetOnmouseover(cx, aOnmouseover); } \
  NS_IMETHOD GetOnmouseup(JSContext* cx, JS::MutableHandleValue aOnmouseup) { return _to GetOnmouseup(cx, aOnmouseup); } \
  NS_IMETHOD SetOnmouseup(JSContext* cx, JS::HandleValue aOnmouseup) { return _to SetOnmouseup(cx, aOnmouseup); } \
  NS_IMETHOD GetOnmozfullscreenchange(JSContext* cx, JS::MutableHandleValue aOnmozfullscreenchange) { return _to GetOnmozfullscreenchange(cx, aOnmozfullscreenchange); } \
  NS_IMETHOD SetOnmozfullscreenchange(JSContext* cx, JS::HandleValue aOnmozfullscreenchange) { return _to SetOnmozfullscreenchange(cx, aOnmozfullscreenchange); } \
  NS_IMETHOD GetOnmozfullscreenerror(JSContext* cx, JS::MutableHandleValue aOnmozfullscreenerror) { return _to GetOnmozfullscreenerror(cx, aOnmozfullscreenerror); } \
  NS_IMETHOD SetOnmozfullscreenerror(JSContext* cx, JS::HandleValue aOnmozfullscreenerror) { return _to SetOnmozfullscreenerror(cx, aOnmozfullscreenerror); } \
  NS_IMETHOD GetOnmozpointerlockchange(JSContext* cx, JS::MutableHandleValue aOnmozpointerlockchange) { return _to GetOnmozpointerlockchange(cx, aOnmozpointerlockchange); } \
  NS_IMETHOD SetOnmozpointerlockchange(JSContext* cx, JS::HandleValue aOnmozpointerlockchange) { return _to SetOnmozpointerlockchange(cx, aOnmozpointerlockchange); } \
  NS_IMETHOD GetOnmozpointerlockerror(JSContext* cx, JS::MutableHandleValue aOnmozpointerlockerror) { return _to GetOnmozpointerlockerror(cx, aOnmozpointerlockerror); } \
  NS_IMETHOD SetOnmozpointerlockerror(JSContext* cx, JS::HandleValue aOnmozpointerlockerror) { return _to SetOnmozpointerlockerror(cx, aOnmozpointerlockerror); } \
  NS_IMETHOD GetOnpause(JSContext* cx, JS::MutableHandleValue aOnpause) { return _to GetOnpause(cx, aOnpause); } \
  NS_IMETHOD SetOnpause(JSContext* cx, JS::HandleValue aOnpause) { return _to SetOnpause(cx, aOnpause); } \
  NS_IMETHOD GetOnplay(JSContext* cx, JS::MutableHandleValue aOnplay) { return _to GetOnplay(cx, aOnplay); } \
  NS_IMETHOD SetOnplay(JSContext* cx, JS::HandleValue aOnplay) { return _to SetOnplay(cx, aOnplay); } \
  NS_IMETHOD GetOnplaying(JSContext* cx, JS::MutableHandleValue aOnplaying) { return _to GetOnplaying(cx, aOnplaying); } \
  NS_IMETHOD SetOnplaying(JSContext* cx, JS::HandleValue aOnplaying) { return _to SetOnplaying(cx, aOnplaying); } \
  NS_IMETHOD GetOnprogress(JSContext* cx, JS::MutableHandleValue aOnprogress) { return _to GetOnprogress(cx, aOnprogress); } \
  NS_IMETHOD SetOnprogress(JSContext* cx, JS::HandleValue aOnprogress) { return _to SetOnprogress(cx, aOnprogress); } \
  NS_IMETHOD GetOnratechange(JSContext* cx, JS::MutableHandleValue aOnratechange) { return _to GetOnratechange(cx, aOnratechange); } \
  NS_IMETHOD SetOnratechange(JSContext* cx, JS::HandleValue aOnratechange) { return _to SetOnratechange(cx, aOnratechange); } \
  NS_IMETHOD GetOnreset(JSContext* cx, JS::MutableHandleValue aOnreset) { return _to GetOnreset(cx, aOnreset); } \
  NS_IMETHOD SetOnreset(JSContext* cx, JS::HandleValue aOnreset) { return _to SetOnreset(cx, aOnreset); } \
  NS_IMETHOD GetOnscroll(JSContext* cx, JS::MutableHandleValue aOnscroll) { return _to GetOnscroll(cx, aOnscroll); } \
  NS_IMETHOD SetOnscroll(JSContext* cx, JS::HandleValue aOnscroll) { return _to SetOnscroll(cx, aOnscroll); } \
  NS_IMETHOD GetOnseeked(JSContext* cx, JS::MutableHandleValue aOnseeked) { return _to GetOnseeked(cx, aOnseeked); } \
  NS_IMETHOD SetOnseeked(JSContext* cx, JS::HandleValue aOnseeked) { return _to SetOnseeked(cx, aOnseeked); } \
  NS_IMETHOD GetOnseeking(JSContext* cx, JS::MutableHandleValue aOnseeking) { return _to GetOnseeking(cx, aOnseeking); } \
  NS_IMETHOD SetOnseeking(JSContext* cx, JS::HandleValue aOnseeking) { return _to SetOnseeking(cx, aOnseeking); } \
  NS_IMETHOD GetOnselect(JSContext* cx, JS::MutableHandleValue aOnselect) { return _to GetOnselect(cx, aOnselect); } \
  NS_IMETHOD SetOnselect(JSContext* cx, JS::HandleValue aOnselect) { return _to SetOnselect(cx, aOnselect); } \
  NS_IMETHOD GetOnshow(JSContext* cx, JS::MutableHandleValue aOnshow) { return _to GetOnshow(cx, aOnshow); } \
  NS_IMETHOD SetOnshow(JSContext* cx, JS::HandleValue aOnshow) { return _to SetOnshow(cx, aOnshow); } \
  NS_IMETHOD GetOnstalled(JSContext* cx, JS::MutableHandleValue aOnstalled) { return _to GetOnstalled(cx, aOnstalled); } \
  NS_IMETHOD SetOnstalled(JSContext* cx, JS::HandleValue aOnstalled) { return _to SetOnstalled(cx, aOnstalled); } \
  NS_IMETHOD GetOnsubmit(JSContext* cx, JS::MutableHandleValue aOnsubmit) { return _to GetOnsubmit(cx, aOnsubmit); } \
  NS_IMETHOD SetOnsubmit(JSContext* cx, JS::HandleValue aOnsubmit) { return _to SetOnsubmit(cx, aOnsubmit); } \
  NS_IMETHOD GetOnsuspend(JSContext* cx, JS::MutableHandleValue aOnsuspend) { return _to GetOnsuspend(cx, aOnsuspend); } \
  NS_IMETHOD SetOnsuspend(JSContext* cx, JS::HandleValue aOnsuspend) { return _to SetOnsuspend(cx, aOnsuspend); } \
  NS_IMETHOD GetOntimeupdate(JSContext* cx, JS::MutableHandleValue aOntimeupdate) { return _to GetOntimeupdate(cx, aOntimeupdate); } \
  NS_IMETHOD SetOntimeupdate(JSContext* cx, JS::HandleValue aOntimeupdate) { return _to SetOntimeupdate(cx, aOntimeupdate); } \
  NS_IMETHOD GetOnvolumechange(JSContext* cx, JS::MutableHandleValue aOnvolumechange) { return _to GetOnvolumechange(cx, aOnvolumechange); } \
  NS_IMETHOD SetOnvolumechange(JSContext* cx, JS::HandleValue aOnvolumechange) { return _to SetOnvolumechange(cx, aOnvolumechange); } \
  NS_IMETHOD GetOnwaiting(JSContext* cx, JS::MutableHandleValue aOnwaiting) { return _to GetOnwaiting(cx, aOnwaiting); } \
  NS_IMETHOD SetOnwaiting(JSContext* cx, JS::HandleValue aOnwaiting) { return _to SetOnwaiting(cx, aOnwaiting); } \
  NS_IMETHOD GetOnwheel(JSContext* cx, JS::MutableHandleValue aOnwheel) { return _to GetOnwheel(cx, aOnwheel); } \
  NS_IMETHOD SetOnwheel(JSContext* cx, JS::HandleValue aOnwheel) { return _to SetOnwheel(cx, aOnwheel); } \
  NS_IMETHOD GetOnpointerdown(JSContext* cx, JS::MutableHandleValue aOnpointerdown) { return _to GetOnpointerdown(cx, aOnpointerdown); } \
  NS_IMETHOD SetOnpointerdown(JSContext* cx, JS::HandleValue aOnpointerdown) { return _to SetOnpointerdown(cx, aOnpointerdown); } \
  NS_IMETHOD GetOnpointermove(JSContext* cx, JS::MutableHandleValue aOnpointermove) { return _to GetOnpointermove(cx, aOnpointermove); } \
  NS_IMETHOD SetOnpointermove(JSContext* cx, JS::HandleValue aOnpointermove) { return _to SetOnpointermove(cx, aOnpointermove); } \
  NS_IMETHOD GetOnpointerout(JSContext* cx, JS::MutableHandleValue aOnpointerout) { return _to GetOnpointerout(cx, aOnpointerout); } \
  NS_IMETHOD SetOnpointerout(JSContext* cx, JS::HandleValue aOnpointerout) { return _to SetOnpointerout(cx, aOnpointerout); } \
  NS_IMETHOD GetOnpointerover(JSContext* cx, JS::MutableHandleValue aOnpointerover) { return _to GetOnpointerover(cx, aOnpointerover); } \
  NS_IMETHOD SetOnpointerover(JSContext* cx, JS::HandleValue aOnpointerover) { return _to SetOnpointerover(cx, aOnpointerover); } \
  NS_IMETHOD GetOnpointerup(JSContext* cx, JS::MutableHandleValue aOnpointerup) { return _to GetOnpointerup(cx, aOnpointerup); } \
  NS_IMETHOD SetOnpointerup(JSContext* cx, JS::HandleValue aOnpointerup) { return _to SetOnpointerup(cx, aOnpointerup); } \
  NS_IMETHOD GetOnpointerenter(JSContext* cx, JS::MutableHandleValue aOnpointerenter) { return _to GetOnpointerenter(cx, aOnpointerenter); } \
  NS_IMETHOD SetOnpointerenter(JSContext* cx, JS::HandleValue aOnpointerenter) { return _to SetOnpointerenter(cx, aOnpointerenter); } \
  NS_IMETHOD GetOnpointerleave(JSContext* cx, JS::MutableHandleValue aOnpointerleave) { return _to GetOnpointerleave(cx, aOnpointerleave); } \
  NS_IMETHOD SetOnpointerleave(JSContext* cx, JS::HandleValue aOnpointerleave) { return _to SetOnpointerleave(cx, aOnpointerleave); } \
  NS_IMETHOD GetOngotpointercapture(JSContext* cx, JS::MutableHandleValue aOngotpointercapture) { return _to GetOngotpointercapture(cx, aOngotpointercapture); } \
  NS_IMETHOD SetOngotpointercapture(JSContext* cx, JS::HandleValue aOngotpointercapture) { return _to SetOngotpointercapture(cx, aOngotpointercapture); } \
  NS_IMETHOD GetOnlostpointercapture(JSContext* cx, JS::MutableHandleValue aOnlostpointercapture) { return _to GetOnlostpointercapture(cx, aOnlostpointercapture); } \
  NS_IMETHOD SetOnlostpointercapture(JSContext* cx, JS::HandleValue aOnlostpointercapture) { return _to SetOnlostpointercapture(cx, aOnlostpointercapture); } \
  NS_IMETHOD GetOnpointercancel(JSContext* cx, JS::MutableHandleValue aOnpointercancel) { return _to GetOnpointercancel(cx, aOnpointercancel); } \
  NS_IMETHOD SetOnpointercancel(JSContext* cx, JS::HandleValue aOnpointercancel) { return _to SetOnpointercancel(cx, aOnpointercancel); } \
  NS_IMETHOD GetOncopy(JSContext* cx, JS::MutableHandleValue aOncopy) { return _to GetOncopy(cx, aOncopy); } \
  NS_IMETHOD SetOncopy(JSContext* cx, JS::HandleValue aOncopy) { return _to SetOncopy(cx, aOncopy); } \
  NS_IMETHOD GetOncut(JSContext* cx, JS::MutableHandleValue aOncut) { return _to GetOncut(cx, aOncut); } \
  NS_IMETHOD SetOncut(JSContext* cx, JS::HandleValue aOncut) { return _to SetOncut(cx, aOncut); } \
  NS_IMETHOD GetOnpaste(JSContext* cx, JS::MutableHandleValue aOnpaste) { return _to GetOnpaste(cx, aOnpaste); } \
  NS_IMETHOD SetOnpaste(JSContext* cx, JS::HandleValue aOnpaste) { return _to SetOnpaste(cx, aOnpaste); } \
  NS_IMETHOD GetOnbeforescriptexecute(JSContext* cx, JS::MutableHandleValue aOnbeforescriptexecute) { return _to GetOnbeforescriptexecute(cx, aOnbeforescriptexecute); } \
  NS_IMETHOD SetOnbeforescriptexecute(JSContext* cx, JS::HandleValue aOnbeforescriptexecute) { return _to SetOnbeforescriptexecute(cx, aOnbeforescriptexecute); } \
  NS_IMETHOD GetOnafterscriptexecute(JSContext* cx, JS::MutableHandleValue aOnafterscriptexecute) { return _to GetOnafterscriptexecute(cx, aOnafterscriptexecute); } \
  NS_IMETHOD SetOnafterscriptexecute(JSContext* cx, JS::HandleValue aOnafterscriptexecute) { return _to SetOnafterscriptexecute(cx, aOnafterscriptexecute); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINLINEEVENTHANDLERS(_to) \
  NS_IMETHOD GetOnabort(JSContext* cx, JS::MutableHandleValue aOnabort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnabort(cx, aOnabort); } \
  NS_IMETHOD SetOnabort(JSContext* cx, JS::HandleValue aOnabort) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnabort(cx, aOnabort); } \
  NS_IMETHOD GetOnblur(JSContext* cx, JS::MutableHandleValue aOnblur) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnblur(cx, aOnblur); } \
  NS_IMETHOD SetOnblur(JSContext* cx, JS::HandleValue aOnblur) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnblur(cx, aOnblur); } \
  NS_IMETHOD GetOncanplay(JSContext* cx, JS::MutableHandleValue aOncanplay) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOncanplay(cx, aOncanplay); } \
  NS_IMETHOD SetOncanplay(JSContext* cx, JS::HandleValue aOncanplay) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOncanplay(cx, aOncanplay); } \
  NS_IMETHOD GetOncanplaythrough(JSContext* cx, JS::MutableHandleValue aOncanplaythrough) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOncanplaythrough(cx, aOncanplaythrough); } \
  NS_IMETHOD SetOncanplaythrough(JSContext* cx, JS::HandleValue aOncanplaythrough) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOncanplaythrough(cx, aOncanplaythrough); } \
  NS_IMETHOD GetOnchange(JSContext* cx, JS::MutableHandleValue aOnchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnchange(cx, aOnchange); } \
  NS_IMETHOD SetOnchange(JSContext* cx, JS::HandleValue aOnchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnchange(cx, aOnchange); } \
  NS_IMETHOD GetOnclick(JSContext* cx, JS::MutableHandleValue aOnclick) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnclick(cx, aOnclick); } \
  NS_IMETHOD SetOnclick(JSContext* cx, JS::HandleValue aOnclick) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnclick(cx, aOnclick); } \
  NS_IMETHOD GetOncontextmenu(JSContext* cx, JS::MutableHandleValue aOncontextmenu) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOncontextmenu(cx, aOncontextmenu); } \
  NS_IMETHOD SetOncontextmenu(JSContext* cx, JS::HandleValue aOncontextmenu) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOncontextmenu(cx, aOncontextmenu); } \
  NS_IMETHOD GetOndblclick(JSContext* cx, JS::MutableHandleValue aOndblclick) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndblclick(cx, aOndblclick); } \
  NS_IMETHOD SetOndblclick(JSContext* cx, JS::HandleValue aOndblclick) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndblclick(cx, aOndblclick); } \
  NS_IMETHOD GetOndrag(JSContext* cx, JS::MutableHandleValue aOndrag) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndrag(cx, aOndrag); } \
  NS_IMETHOD SetOndrag(JSContext* cx, JS::HandleValue aOndrag) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndrag(cx, aOndrag); } \
  NS_IMETHOD GetOndragend(JSContext* cx, JS::MutableHandleValue aOndragend) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndragend(cx, aOndragend); } \
  NS_IMETHOD SetOndragend(JSContext* cx, JS::HandleValue aOndragend) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndragend(cx, aOndragend); } \
  NS_IMETHOD GetOndragenter(JSContext* cx, JS::MutableHandleValue aOndragenter) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndragenter(cx, aOndragenter); } \
  NS_IMETHOD SetOndragenter(JSContext* cx, JS::HandleValue aOndragenter) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndragenter(cx, aOndragenter); } \
  NS_IMETHOD GetOndragleave(JSContext* cx, JS::MutableHandleValue aOndragleave) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndragleave(cx, aOndragleave); } \
  NS_IMETHOD SetOndragleave(JSContext* cx, JS::HandleValue aOndragleave) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndragleave(cx, aOndragleave); } \
  NS_IMETHOD GetOndragover(JSContext* cx, JS::MutableHandleValue aOndragover) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndragover(cx, aOndragover); } \
  NS_IMETHOD SetOndragover(JSContext* cx, JS::HandleValue aOndragover) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndragover(cx, aOndragover); } \
  NS_IMETHOD GetOndragstart(JSContext* cx, JS::MutableHandleValue aOndragstart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndragstart(cx, aOndragstart); } \
  NS_IMETHOD SetOndragstart(JSContext* cx, JS::HandleValue aOndragstart) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndragstart(cx, aOndragstart); } \
  NS_IMETHOD GetOndrop(JSContext* cx, JS::MutableHandleValue aOndrop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndrop(cx, aOndrop); } \
  NS_IMETHOD SetOndrop(JSContext* cx, JS::HandleValue aOndrop) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndrop(cx, aOndrop); } \
  NS_IMETHOD GetOndurationchange(JSContext* cx, JS::MutableHandleValue aOndurationchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndurationchange(cx, aOndurationchange); } \
  NS_IMETHOD SetOndurationchange(JSContext* cx, JS::HandleValue aOndurationchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndurationchange(cx, aOndurationchange); } \
  NS_IMETHOD GetOnemptied(JSContext* cx, JS::MutableHandleValue aOnemptied) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnemptied(cx, aOnemptied); } \
  NS_IMETHOD SetOnemptied(JSContext* cx, JS::HandleValue aOnemptied) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnemptied(cx, aOnemptied); } \
  NS_IMETHOD GetOnended(JSContext* cx, JS::MutableHandleValue aOnended) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnended(cx, aOnended); } \
  NS_IMETHOD SetOnended(JSContext* cx, JS::HandleValue aOnended) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnended(cx, aOnended); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::MutableHandleValue aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, JS::HandleValue aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnerror(cx, aOnerror); } \
  NS_IMETHOD GetOnfocus(JSContext* cx, JS::MutableHandleValue aOnfocus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnfocus(cx, aOnfocus); } \
  NS_IMETHOD SetOnfocus(JSContext* cx, JS::HandleValue aOnfocus) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnfocus(cx, aOnfocus); } \
  NS_IMETHOD GetOninput(JSContext* cx, JS::MutableHandleValue aOninput) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOninput(cx, aOninput); } \
  NS_IMETHOD SetOninput(JSContext* cx, JS::HandleValue aOninput) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOninput(cx, aOninput); } \
  NS_IMETHOD GetOninvalid(JSContext* cx, JS::MutableHandleValue aOninvalid) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOninvalid(cx, aOninvalid); } \
  NS_IMETHOD SetOninvalid(JSContext* cx, JS::HandleValue aOninvalid) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOninvalid(cx, aOninvalid); } \
  NS_IMETHOD GetOnkeydown(JSContext* cx, JS::MutableHandleValue aOnkeydown) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnkeydown(cx, aOnkeydown); } \
  NS_IMETHOD SetOnkeydown(JSContext* cx, JS::HandleValue aOnkeydown) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnkeydown(cx, aOnkeydown); } \
  NS_IMETHOD GetOnkeypress(JSContext* cx, JS::MutableHandleValue aOnkeypress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnkeypress(cx, aOnkeypress); } \
  NS_IMETHOD SetOnkeypress(JSContext* cx, JS::HandleValue aOnkeypress) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnkeypress(cx, aOnkeypress); } \
  NS_IMETHOD GetOnkeyup(JSContext* cx, JS::MutableHandleValue aOnkeyup) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnkeyup(cx, aOnkeyup); } \
  NS_IMETHOD SetOnkeyup(JSContext* cx, JS::HandleValue aOnkeyup) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnkeyup(cx, aOnkeyup); } \
  NS_IMETHOD GetOnload(JSContext* cx, JS::MutableHandleValue aOnload) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnload(cx, aOnload); } \
  NS_IMETHOD SetOnload(JSContext* cx, JS::HandleValue aOnload) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnload(cx, aOnload); } \
  NS_IMETHOD GetOnloadeddata(JSContext* cx, JS::MutableHandleValue aOnloadeddata) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnloadeddata(cx, aOnloadeddata); } \
  NS_IMETHOD SetOnloadeddata(JSContext* cx, JS::HandleValue aOnloadeddata) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnloadeddata(cx, aOnloadeddata); } \
  NS_IMETHOD GetOnloadedmetadata(JSContext* cx, JS::MutableHandleValue aOnloadedmetadata) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnloadedmetadata(cx, aOnloadedmetadata); } \
  NS_IMETHOD SetOnloadedmetadata(JSContext* cx, JS::HandleValue aOnloadedmetadata) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnloadedmetadata(cx, aOnloadedmetadata); } \
  NS_IMETHOD GetOnloadstart(JSContext* cx, JS::MutableHandleValue aOnloadstart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnloadstart(cx, aOnloadstart); } \
  NS_IMETHOD SetOnloadstart(JSContext* cx, JS::HandleValue aOnloadstart) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnloadstart(cx, aOnloadstart); } \
  NS_IMETHOD GetOnmousedown(JSContext* cx, JS::MutableHandleValue aOnmousedown) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmousedown(cx, aOnmousedown); } \
  NS_IMETHOD SetOnmousedown(JSContext* cx, JS::HandleValue aOnmousedown) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmousedown(cx, aOnmousedown); } \
  NS_IMETHOD GetOnmousemove(JSContext* cx, JS::MutableHandleValue aOnmousemove) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmousemove(cx, aOnmousemove); } \
  NS_IMETHOD SetOnmousemove(JSContext* cx, JS::HandleValue aOnmousemove) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmousemove(cx, aOnmousemove); } \
  NS_IMETHOD GetOnmouseout(JSContext* cx, JS::MutableHandleValue aOnmouseout) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmouseout(cx, aOnmouseout); } \
  NS_IMETHOD SetOnmouseout(JSContext* cx, JS::HandleValue aOnmouseout) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmouseout(cx, aOnmouseout); } \
  NS_IMETHOD GetOnmouseover(JSContext* cx, JS::MutableHandleValue aOnmouseover) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmouseover(cx, aOnmouseover); } \
  NS_IMETHOD SetOnmouseover(JSContext* cx, JS::HandleValue aOnmouseover) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmouseover(cx, aOnmouseover); } \
  NS_IMETHOD GetOnmouseup(JSContext* cx, JS::MutableHandleValue aOnmouseup) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmouseup(cx, aOnmouseup); } \
  NS_IMETHOD SetOnmouseup(JSContext* cx, JS::HandleValue aOnmouseup) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmouseup(cx, aOnmouseup); } \
  NS_IMETHOD GetOnmozfullscreenchange(JSContext* cx, JS::MutableHandleValue aOnmozfullscreenchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmozfullscreenchange(cx, aOnmozfullscreenchange); } \
  NS_IMETHOD SetOnmozfullscreenchange(JSContext* cx, JS::HandleValue aOnmozfullscreenchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmozfullscreenchange(cx, aOnmozfullscreenchange); } \
  NS_IMETHOD GetOnmozfullscreenerror(JSContext* cx, JS::MutableHandleValue aOnmozfullscreenerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmozfullscreenerror(cx, aOnmozfullscreenerror); } \
  NS_IMETHOD SetOnmozfullscreenerror(JSContext* cx, JS::HandleValue aOnmozfullscreenerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmozfullscreenerror(cx, aOnmozfullscreenerror); } \
  NS_IMETHOD GetOnmozpointerlockchange(JSContext* cx, JS::MutableHandleValue aOnmozpointerlockchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmozpointerlockchange(cx, aOnmozpointerlockchange); } \
  NS_IMETHOD SetOnmozpointerlockchange(JSContext* cx, JS::HandleValue aOnmozpointerlockchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmozpointerlockchange(cx, aOnmozpointerlockchange); } \
  NS_IMETHOD GetOnmozpointerlockerror(JSContext* cx, JS::MutableHandleValue aOnmozpointerlockerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmozpointerlockerror(cx, aOnmozpointerlockerror); } \
  NS_IMETHOD SetOnmozpointerlockerror(JSContext* cx, JS::HandleValue aOnmozpointerlockerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmozpointerlockerror(cx, aOnmozpointerlockerror); } \
  NS_IMETHOD GetOnpause(JSContext* cx, JS::MutableHandleValue aOnpause) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnpause(cx, aOnpause); } \
  NS_IMETHOD SetOnpause(JSContext* cx, JS::HandleValue aOnpause) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnpause(cx, aOnpause); } \
  NS_IMETHOD GetOnplay(JSContext* cx, JS::MutableHandleValue aOnplay) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnplay(cx, aOnplay); } \
  NS_IMETHOD SetOnplay(JSContext* cx, JS::HandleValue aOnplay) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnplay(cx, aOnplay); } \
  NS_IMETHOD GetOnplaying(JSContext* cx, JS::MutableHandleValue aOnplaying) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnplaying(cx, aOnplaying); } \
  NS_IMETHOD SetOnplaying(JSContext* cx, JS::HandleValue aOnplaying) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnplaying(cx, aOnplaying); } \
  NS_IMETHOD GetOnprogress(JSContext* cx, JS::MutableHandleValue aOnprogress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnprogress(cx, aOnprogress); } \
  NS_IMETHOD SetOnprogress(JSContext* cx, JS::HandleValue aOnprogress) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnprogress(cx, aOnprogress); } \
  NS_IMETHOD GetOnratechange(JSContext* cx, JS::MutableHandleValue aOnratechange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnratechange(cx, aOnratechange); } \
  NS_IMETHOD SetOnratechange(JSContext* cx, JS::HandleValue aOnratechange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnratechange(cx, aOnratechange); } \
  NS_IMETHOD GetOnreset(JSContext* cx, JS::MutableHandleValue aOnreset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnreset(cx, aOnreset); } \
  NS_IMETHOD SetOnreset(JSContext* cx, JS::HandleValue aOnreset) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnreset(cx, aOnreset); } \
  NS_IMETHOD GetOnscroll(JSContext* cx, JS::MutableHandleValue aOnscroll) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnscroll(cx, aOnscroll); } \
  NS_IMETHOD SetOnscroll(JSContext* cx, JS::HandleValue aOnscroll) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnscroll(cx, aOnscroll); } \
  NS_IMETHOD GetOnseeked(JSContext* cx, JS::MutableHandleValue aOnseeked) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnseeked(cx, aOnseeked); } \
  NS_IMETHOD SetOnseeked(JSContext* cx, JS::HandleValue aOnseeked) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnseeked(cx, aOnseeked); } \
  NS_IMETHOD GetOnseeking(JSContext* cx, JS::MutableHandleValue aOnseeking) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnseeking(cx, aOnseeking); } \
  NS_IMETHOD SetOnseeking(JSContext* cx, JS::HandleValue aOnseeking) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnseeking(cx, aOnseeking); } \
  NS_IMETHOD GetOnselect(JSContext* cx, JS::MutableHandleValue aOnselect) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnselect(cx, aOnselect); } \
  NS_IMETHOD SetOnselect(JSContext* cx, JS::HandleValue aOnselect) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnselect(cx, aOnselect); } \
  NS_IMETHOD GetOnshow(JSContext* cx, JS::MutableHandleValue aOnshow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnshow(cx, aOnshow); } \
  NS_IMETHOD SetOnshow(JSContext* cx, JS::HandleValue aOnshow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnshow(cx, aOnshow); } \
  NS_IMETHOD GetOnstalled(JSContext* cx, JS::MutableHandleValue aOnstalled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnstalled(cx, aOnstalled); } \
  NS_IMETHOD SetOnstalled(JSContext* cx, JS::HandleValue aOnstalled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnstalled(cx, aOnstalled); } \
  NS_IMETHOD GetOnsubmit(JSContext* cx, JS::MutableHandleValue aOnsubmit) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnsubmit(cx, aOnsubmit); } \
  NS_IMETHOD SetOnsubmit(JSContext* cx, JS::HandleValue aOnsubmit) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnsubmit(cx, aOnsubmit); } \
  NS_IMETHOD GetOnsuspend(JSContext* cx, JS::MutableHandleValue aOnsuspend) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnsuspend(cx, aOnsuspend); } \
  NS_IMETHOD SetOnsuspend(JSContext* cx, JS::HandleValue aOnsuspend) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnsuspend(cx, aOnsuspend); } \
  NS_IMETHOD GetOntimeupdate(JSContext* cx, JS::MutableHandleValue aOntimeupdate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOntimeupdate(cx, aOntimeupdate); } \
  NS_IMETHOD SetOntimeupdate(JSContext* cx, JS::HandleValue aOntimeupdate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOntimeupdate(cx, aOntimeupdate); } \
  NS_IMETHOD GetOnvolumechange(JSContext* cx, JS::MutableHandleValue aOnvolumechange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnvolumechange(cx, aOnvolumechange); } \
  NS_IMETHOD SetOnvolumechange(JSContext* cx, JS::HandleValue aOnvolumechange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnvolumechange(cx, aOnvolumechange); } \
  NS_IMETHOD GetOnwaiting(JSContext* cx, JS::MutableHandleValue aOnwaiting) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnwaiting(cx, aOnwaiting); } \
  NS_IMETHOD SetOnwaiting(JSContext* cx, JS::HandleValue aOnwaiting) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnwaiting(cx, aOnwaiting); } \
  NS_IMETHOD GetOnwheel(JSContext* cx, JS::MutableHandleValue aOnwheel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnwheel(cx, aOnwheel); } \
  NS_IMETHOD SetOnwheel(JSContext* cx, JS::HandleValue aOnwheel) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnwheel(cx, aOnwheel); } \
  NS_IMETHOD GetOnpointerdown(JSContext* cx, JS::MutableHandleValue aOnpointerdown) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnpointerdown(cx, aOnpointerdown); } \
  NS_IMETHOD SetOnpointerdown(JSContext* cx, JS::HandleValue aOnpointerdown) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnpointerdown(cx, aOnpointerdown); } \
  NS_IMETHOD GetOnpointermove(JSContext* cx, JS::MutableHandleValue aOnpointermove) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnpointermove(cx, aOnpointermove); } \
  NS_IMETHOD SetOnpointermove(JSContext* cx, JS::HandleValue aOnpointermove) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnpointermove(cx, aOnpointermove); } \
  NS_IMETHOD GetOnpointerout(JSContext* cx, JS::MutableHandleValue aOnpointerout) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnpointerout(cx, aOnpointerout); } \
  NS_IMETHOD SetOnpointerout(JSContext* cx, JS::HandleValue aOnpointerout) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnpointerout(cx, aOnpointerout); } \
  NS_IMETHOD GetOnpointerover(JSContext* cx, JS::MutableHandleValue aOnpointerover) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnpointerover(cx, aOnpointerover); } \
  NS_IMETHOD SetOnpointerover(JSContext* cx, JS::HandleValue aOnpointerover) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnpointerover(cx, aOnpointerover); } \
  NS_IMETHOD GetOnpointerup(JSContext* cx, JS::MutableHandleValue aOnpointerup) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnpointerup(cx, aOnpointerup); } \
  NS_IMETHOD SetOnpointerup(JSContext* cx, JS::HandleValue aOnpointerup) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnpointerup(cx, aOnpointerup); } \
  NS_IMETHOD GetOnpointerenter(JSContext* cx, JS::MutableHandleValue aOnpointerenter) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnpointerenter(cx, aOnpointerenter); } \
  NS_IMETHOD SetOnpointerenter(JSContext* cx, JS::HandleValue aOnpointerenter) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnpointerenter(cx, aOnpointerenter); } \
  NS_IMETHOD GetOnpointerleave(JSContext* cx, JS::MutableHandleValue aOnpointerleave) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnpointerleave(cx, aOnpointerleave); } \
  NS_IMETHOD SetOnpointerleave(JSContext* cx, JS::HandleValue aOnpointerleave) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnpointerleave(cx, aOnpointerleave); } \
  NS_IMETHOD GetOngotpointercapture(JSContext* cx, JS::MutableHandleValue aOngotpointercapture) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOngotpointercapture(cx, aOngotpointercapture); } \
  NS_IMETHOD SetOngotpointercapture(JSContext* cx, JS::HandleValue aOngotpointercapture) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOngotpointercapture(cx, aOngotpointercapture); } \
  NS_IMETHOD GetOnlostpointercapture(JSContext* cx, JS::MutableHandleValue aOnlostpointercapture) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnlostpointercapture(cx, aOnlostpointercapture); } \
  NS_IMETHOD SetOnlostpointercapture(JSContext* cx, JS::HandleValue aOnlostpointercapture) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnlostpointercapture(cx, aOnlostpointercapture); } \
  NS_IMETHOD GetOnpointercancel(JSContext* cx, JS::MutableHandleValue aOnpointercancel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnpointercancel(cx, aOnpointercancel); } \
  NS_IMETHOD SetOnpointercancel(JSContext* cx, JS::HandleValue aOnpointercancel) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnpointercancel(cx, aOnpointercancel); } \
  NS_IMETHOD GetOncopy(JSContext* cx, JS::MutableHandleValue aOncopy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOncopy(cx, aOncopy); } \
  NS_IMETHOD SetOncopy(JSContext* cx, JS::HandleValue aOncopy) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOncopy(cx, aOncopy); } \
  NS_IMETHOD GetOncut(JSContext* cx, JS::MutableHandleValue aOncut) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOncut(cx, aOncut); } \
  NS_IMETHOD SetOncut(JSContext* cx, JS::HandleValue aOncut) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOncut(cx, aOncut); } \
  NS_IMETHOD GetOnpaste(JSContext* cx, JS::MutableHandleValue aOnpaste) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnpaste(cx, aOnpaste); } \
  NS_IMETHOD SetOnpaste(JSContext* cx, JS::HandleValue aOnpaste) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnpaste(cx, aOnpaste); } \
  NS_IMETHOD GetOnbeforescriptexecute(JSContext* cx, JS::MutableHandleValue aOnbeforescriptexecute) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnbeforescriptexecute(cx, aOnbeforescriptexecute); } \
  NS_IMETHOD SetOnbeforescriptexecute(JSContext* cx, JS::HandleValue aOnbeforescriptexecute) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnbeforescriptexecute(cx, aOnbeforescriptexecute); } \
  NS_IMETHOD GetOnafterscriptexecute(JSContext* cx, JS::MutableHandleValue aOnafterscriptexecute) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnafterscriptexecute(cx, aOnafterscriptexecute); } \
  NS_IMETHOD SetOnafterscriptexecute(JSContext* cx, JS::HandleValue aOnafterscriptexecute) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnafterscriptexecute(cx, aOnafterscriptexecute); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInlineEventHandlers : public nsIInlineEventHandlers
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINLINEEVENTHANDLERS

  nsInlineEventHandlers();

private:
  ~nsInlineEventHandlers();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsInlineEventHandlers, nsIInlineEventHandlers)

nsInlineEventHandlers::nsInlineEventHandlers()
{
  /* member initializers and constructor code */
}

nsInlineEventHandlers::~nsInlineEventHandlers()
{
  /* destructor code */
}

/* [implicit_jscontext] attribute jsval onabort; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnabort(JSContext* cx, JS::MutableHandleValue aOnabort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnabort(JSContext* cx, JS::HandleValue aOnabort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onblur; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnblur(JSContext* cx, JS::MutableHandleValue aOnblur)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnblur(JSContext* cx, JS::HandleValue aOnblur)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval oncanplay; */
NS_IMETHODIMP nsInlineEventHandlers::GetOncanplay(JSContext* cx, JS::MutableHandleValue aOncanplay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOncanplay(JSContext* cx, JS::HandleValue aOncanplay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval oncanplaythrough; */
NS_IMETHODIMP nsInlineEventHandlers::GetOncanplaythrough(JSContext* cx, JS::MutableHandleValue aOncanplaythrough)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOncanplaythrough(JSContext* cx, JS::HandleValue aOncanplaythrough)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onchange; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnchange(JSContext* cx, JS::MutableHandleValue aOnchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnchange(JSContext* cx, JS::HandleValue aOnchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onclick; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnclick(JSContext* cx, JS::MutableHandleValue aOnclick)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnclick(JSContext* cx, JS::HandleValue aOnclick)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval oncontextmenu; */
NS_IMETHODIMP nsInlineEventHandlers::GetOncontextmenu(JSContext* cx, JS::MutableHandleValue aOncontextmenu)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOncontextmenu(JSContext* cx, JS::HandleValue aOncontextmenu)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondblclick; */
NS_IMETHODIMP nsInlineEventHandlers::GetOndblclick(JSContext* cx, JS::MutableHandleValue aOndblclick)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOndblclick(JSContext* cx, JS::HandleValue aOndblclick)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondrag; */
NS_IMETHODIMP nsInlineEventHandlers::GetOndrag(JSContext* cx, JS::MutableHandleValue aOndrag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOndrag(JSContext* cx, JS::HandleValue aOndrag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondragend; */
NS_IMETHODIMP nsInlineEventHandlers::GetOndragend(JSContext* cx, JS::MutableHandleValue aOndragend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOndragend(JSContext* cx, JS::HandleValue aOndragend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondragenter; */
NS_IMETHODIMP nsInlineEventHandlers::GetOndragenter(JSContext* cx, JS::MutableHandleValue aOndragenter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOndragenter(JSContext* cx, JS::HandleValue aOndragenter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondragleave; */
NS_IMETHODIMP nsInlineEventHandlers::GetOndragleave(JSContext* cx, JS::MutableHandleValue aOndragleave)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOndragleave(JSContext* cx, JS::HandleValue aOndragleave)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondragover; */
NS_IMETHODIMP nsInlineEventHandlers::GetOndragover(JSContext* cx, JS::MutableHandleValue aOndragover)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOndragover(JSContext* cx, JS::HandleValue aOndragover)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondragstart; */
NS_IMETHODIMP nsInlineEventHandlers::GetOndragstart(JSContext* cx, JS::MutableHandleValue aOndragstart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOndragstart(JSContext* cx, JS::HandleValue aOndragstart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondrop; */
NS_IMETHODIMP nsInlineEventHandlers::GetOndrop(JSContext* cx, JS::MutableHandleValue aOndrop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOndrop(JSContext* cx, JS::HandleValue aOndrop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondurationchange; */
NS_IMETHODIMP nsInlineEventHandlers::GetOndurationchange(JSContext* cx, JS::MutableHandleValue aOndurationchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOndurationchange(JSContext* cx, JS::HandleValue aOndurationchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onemptied; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnemptied(JSContext* cx, JS::MutableHandleValue aOnemptied)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnemptied(JSContext* cx, JS::HandleValue aOnemptied)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onended; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnended(JSContext* cx, JS::MutableHandleValue aOnended)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnended(JSContext* cx, JS::HandleValue aOnended)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onerror; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnerror(JSContext* cx, JS::MutableHandleValue aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnerror(JSContext* cx, JS::HandleValue aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onfocus; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnfocus(JSContext* cx, JS::MutableHandleValue aOnfocus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnfocus(JSContext* cx, JS::HandleValue aOnfocus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval oninput; */
NS_IMETHODIMP nsInlineEventHandlers::GetOninput(JSContext* cx, JS::MutableHandleValue aOninput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOninput(JSContext* cx, JS::HandleValue aOninput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval oninvalid; */
NS_IMETHODIMP nsInlineEventHandlers::GetOninvalid(JSContext* cx, JS::MutableHandleValue aOninvalid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOninvalid(JSContext* cx, JS::HandleValue aOninvalid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onkeydown; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnkeydown(JSContext* cx, JS::MutableHandleValue aOnkeydown)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnkeydown(JSContext* cx, JS::HandleValue aOnkeydown)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onkeypress; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnkeypress(JSContext* cx, JS::MutableHandleValue aOnkeypress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnkeypress(JSContext* cx, JS::HandleValue aOnkeypress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onkeyup; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnkeyup(JSContext* cx, JS::MutableHandleValue aOnkeyup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnkeyup(JSContext* cx, JS::HandleValue aOnkeyup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onload; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnload(JSContext* cx, JS::MutableHandleValue aOnload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnload(JSContext* cx, JS::HandleValue aOnload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onloadeddata; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnloadeddata(JSContext* cx, JS::MutableHandleValue aOnloadeddata)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnloadeddata(JSContext* cx, JS::HandleValue aOnloadeddata)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onloadedmetadata; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnloadedmetadata(JSContext* cx, JS::MutableHandleValue aOnloadedmetadata)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnloadedmetadata(JSContext* cx, JS::HandleValue aOnloadedmetadata)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onloadstart; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnloadstart(JSContext* cx, JS::MutableHandleValue aOnloadstart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnloadstart(JSContext* cx, JS::HandleValue aOnloadstart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmousedown; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnmousedown(JSContext* cx, JS::MutableHandleValue aOnmousedown)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnmousedown(JSContext* cx, JS::HandleValue aOnmousedown)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmousemove; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnmousemove(JSContext* cx, JS::MutableHandleValue aOnmousemove)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnmousemove(JSContext* cx, JS::HandleValue aOnmousemove)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmouseout; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnmouseout(JSContext* cx, JS::MutableHandleValue aOnmouseout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnmouseout(JSContext* cx, JS::HandleValue aOnmouseout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmouseover; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnmouseover(JSContext* cx, JS::MutableHandleValue aOnmouseover)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnmouseover(JSContext* cx, JS::HandleValue aOnmouseover)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmouseup; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnmouseup(JSContext* cx, JS::MutableHandleValue aOnmouseup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnmouseup(JSContext* cx, JS::HandleValue aOnmouseup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmozfullscreenchange; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnmozfullscreenchange(JSContext* cx, JS::MutableHandleValue aOnmozfullscreenchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnmozfullscreenchange(JSContext* cx, JS::HandleValue aOnmozfullscreenchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmozfullscreenerror; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnmozfullscreenerror(JSContext* cx, JS::MutableHandleValue aOnmozfullscreenerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnmozfullscreenerror(JSContext* cx, JS::HandleValue aOnmozfullscreenerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmozpointerlockchange; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnmozpointerlockchange(JSContext* cx, JS::MutableHandleValue aOnmozpointerlockchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnmozpointerlockchange(JSContext* cx, JS::HandleValue aOnmozpointerlockchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmozpointerlockerror; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnmozpointerlockerror(JSContext* cx, JS::MutableHandleValue aOnmozpointerlockerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnmozpointerlockerror(JSContext* cx, JS::HandleValue aOnmozpointerlockerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onpause; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnpause(JSContext* cx, JS::MutableHandleValue aOnpause)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnpause(JSContext* cx, JS::HandleValue aOnpause)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onplay; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnplay(JSContext* cx, JS::MutableHandleValue aOnplay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnplay(JSContext* cx, JS::HandleValue aOnplay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onplaying; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnplaying(JSContext* cx, JS::MutableHandleValue aOnplaying)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnplaying(JSContext* cx, JS::HandleValue aOnplaying)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onprogress; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnprogress(JSContext* cx, JS::MutableHandleValue aOnprogress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnprogress(JSContext* cx, JS::HandleValue aOnprogress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onratechange; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnratechange(JSContext* cx, JS::MutableHandleValue aOnratechange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnratechange(JSContext* cx, JS::HandleValue aOnratechange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onreset; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnreset(JSContext* cx, JS::MutableHandleValue aOnreset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnreset(JSContext* cx, JS::HandleValue aOnreset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onscroll; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnscroll(JSContext* cx, JS::MutableHandleValue aOnscroll)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnscroll(JSContext* cx, JS::HandleValue aOnscroll)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onseeked; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnseeked(JSContext* cx, JS::MutableHandleValue aOnseeked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnseeked(JSContext* cx, JS::HandleValue aOnseeked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onseeking; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnseeking(JSContext* cx, JS::MutableHandleValue aOnseeking)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnseeking(JSContext* cx, JS::HandleValue aOnseeking)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onselect; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnselect(JSContext* cx, JS::MutableHandleValue aOnselect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnselect(JSContext* cx, JS::HandleValue aOnselect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onshow; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnshow(JSContext* cx, JS::MutableHandleValue aOnshow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnshow(JSContext* cx, JS::HandleValue aOnshow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onstalled; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnstalled(JSContext* cx, JS::MutableHandleValue aOnstalled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnstalled(JSContext* cx, JS::HandleValue aOnstalled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onsubmit; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnsubmit(JSContext* cx, JS::MutableHandleValue aOnsubmit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnsubmit(JSContext* cx, JS::HandleValue aOnsubmit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onsuspend; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnsuspend(JSContext* cx, JS::MutableHandleValue aOnsuspend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnsuspend(JSContext* cx, JS::HandleValue aOnsuspend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ontimeupdate; */
NS_IMETHODIMP nsInlineEventHandlers::GetOntimeupdate(JSContext* cx, JS::MutableHandleValue aOntimeupdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOntimeupdate(JSContext* cx, JS::HandleValue aOntimeupdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onvolumechange; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnvolumechange(JSContext* cx, JS::MutableHandleValue aOnvolumechange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnvolumechange(JSContext* cx, JS::HandleValue aOnvolumechange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onwaiting; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnwaiting(JSContext* cx, JS::MutableHandleValue aOnwaiting)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnwaiting(JSContext* cx, JS::HandleValue aOnwaiting)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onwheel; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnwheel(JSContext* cx, JS::MutableHandleValue aOnwheel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnwheel(JSContext* cx, JS::HandleValue aOnwheel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onpointerdown; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnpointerdown(JSContext* cx, JS::MutableHandleValue aOnpointerdown)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnpointerdown(JSContext* cx, JS::HandleValue aOnpointerdown)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onpointermove; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnpointermove(JSContext* cx, JS::MutableHandleValue aOnpointermove)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnpointermove(JSContext* cx, JS::HandleValue aOnpointermove)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onpointerout; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnpointerout(JSContext* cx, JS::MutableHandleValue aOnpointerout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnpointerout(JSContext* cx, JS::HandleValue aOnpointerout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onpointerover; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnpointerover(JSContext* cx, JS::MutableHandleValue aOnpointerover)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnpointerover(JSContext* cx, JS::HandleValue aOnpointerover)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onpointerup; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnpointerup(JSContext* cx, JS::MutableHandleValue aOnpointerup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnpointerup(JSContext* cx, JS::HandleValue aOnpointerup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onpointerenter; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnpointerenter(JSContext* cx, JS::MutableHandleValue aOnpointerenter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnpointerenter(JSContext* cx, JS::HandleValue aOnpointerenter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onpointerleave; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnpointerleave(JSContext* cx, JS::MutableHandleValue aOnpointerleave)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnpointerleave(JSContext* cx, JS::HandleValue aOnpointerleave)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ongotpointercapture; */
NS_IMETHODIMP nsInlineEventHandlers::GetOngotpointercapture(JSContext* cx, JS::MutableHandleValue aOngotpointercapture)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOngotpointercapture(JSContext* cx, JS::HandleValue aOngotpointercapture)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onlostpointercapture; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnlostpointercapture(JSContext* cx, JS::MutableHandleValue aOnlostpointercapture)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnlostpointercapture(JSContext* cx, JS::HandleValue aOnlostpointercapture)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onpointercancel; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnpointercancel(JSContext* cx, JS::MutableHandleValue aOnpointercancel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnpointercancel(JSContext* cx, JS::HandleValue aOnpointercancel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval oncopy; */
NS_IMETHODIMP nsInlineEventHandlers::GetOncopy(JSContext* cx, JS::MutableHandleValue aOncopy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOncopy(JSContext* cx, JS::HandleValue aOncopy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval oncut; */
NS_IMETHODIMP nsInlineEventHandlers::GetOncut(JSContext* cx, JS::MutableHandleValue aOncut)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOncut(JSContext* cx, JS::HandleValue aOncut)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onpaste; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnpaste(JSContext* cx, JS::MutableHandleValue aOnpaste)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnpaste(JSContext* cx, JS::HandleValue aOnpaste)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onbeforescriptexecute; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnbeforescriptexecute(JSContext* cx, JS::MutableHandleValue aOnbeforescriptexecute)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnbeforescriptexecute(JSContext* cx, JS::HandleValue aOnbeforescriptexecute)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onafterscriptexecute; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnafterscriptexecute(JSContext* cx, JS::MutableHandleValue aOnafterscriptexecute)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnafterscriptexecute(JSContext* cx, JS::HandleValue aOnafterscriptexecute)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIInlineEventHandlers_h__ */

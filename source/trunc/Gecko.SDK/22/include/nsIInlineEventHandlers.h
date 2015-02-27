/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/core/nsIInlineEventHandlers.idl
 */

#ifndef __gen_nsIInlineEventHandlers_h__
#define __gen_nsIInlineEventHandlers_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "jspubtd.h"

/* starting interface:    nsIInlineEventHandlers */
#define NS_IINLINEEVENTHANDLERS_IID_STR "22df6ed6-d094-4e45-97fc-a8eca11c390c"

#define NS_IINLINEEVENTHANDLERS_IID \
  {0x22df6ed6, 0xd094, 0x4e45, \
    { 0x97, 0xfc, 0xa8, 0xec, 0xa1, 0x1c, 0x39, 0x0c }}

class NS_NO_VTABLE nsIInlineEventHandlers : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINLINEEVENTHANDLERS_IID)

  /* [implicit_jscontext] attribute jsval onabort; */
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort) = 0;
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort) = 0;

  /* [implicit_jscontext] attribute jsval onblur; */
  NS_IMETHOD GetOnblur(JSContext* cx, JS::Value *aOnblur) = 0;
  NS_IMETHOD SetOnblur(JSContext* cx, const JS::Value & aOnblur) = 0;

  /* [implicit_jscontext] attribute jsval oncanplay; */
  NS_IMETHOD GetOncanplay(JSContext* cx, JS::Value *aOncanplay) = 0;
  NS_IMETHOD SetOncanplay(JSContext* cx, const JS::Value & aOncanplay) = 0;

  /* [implicit_jscontext] attribute jsval oncanplaythrough; */
  NS_IMETHOD GetOncanplaythrough(JSContext* cx, JS::Value *aOncanplaythrough) = 0;
  NS_IMETHOD SetOncanplaythrough(JSContext* cx, const JS::Value & aOncanplaythrough) = 0;

  /* [implicit_jscontext] attribute jsval onchange; */
  NS_IMETHOD GetOnchange(JSContext* cx, JS::Value *aOnchange) = 0;
  NS_IMETHOD SetOnchange(JSContext* cx, const JS::Value & aOnchange) = 0;

  /* [implicit_jscontext] attribute jsval onclick; */
  NS_IMETHOD GetOnclick(JSContext* cx, JS::Value *aOnclick) = 0;
  NS_IMETHOD SetOnclick(JSContext* cx, const JS::Value & aOnclick) = 0;

  /* [implicit_jscontext] attribute jsval oncontextmenu; */
  NS_IMETHOD GetOncontextmenu(JSContext* cx, JS::Value *aOncontextmenu) = 0;
  NS_IMETHOD SetOncontextmenu(JSContext* cx, const JS::Value & aOncontextmenu) = 0;

  /* [implicit_jscontext] attribute jsval ondblclick; */
  NS_IMETHOD GetOndblclick(JSContext* cx, JS::Value *aOndblclick) = 0;
  NS_IMETHOD SetOndblclick(JSContext* cx, const JS::Value & aOndblclick) = 0;

  /* [implicit_jscontext] attribute jsval ondrag; */
  NS_IMETHOD GetOndrag(JSContext* cx, JS::Value *aOndrag) = 0;
  NS_IMETHOD SetOndrag(JSContext* cx, const JS::Value & aOndrag) = 0;

  /* [implicit_jscontext] attribute jsval ondragend; */
  NS_IMETHOD GetOndragend(JSContext* cx, JS::Value *aOndragend) = 0;
  NS_IMETHOD SetOndragend(JSContext* cx, const JS::Value & aOndragend) = 0;

  /* [implicit_jscontext] attribute jsval ondragenter; */
  NS_IMETHOD GetOndragenter(JSContext* cx, JS::Value *aOndragenter) = 0;
  NS_IMETHOD SetOndragenter(JSContext* cx, const JS::Value & aOndragenter) = 0;

  /* [implicit_jscontext] attribute jsval ondragleave; */
  NS_IMETHOD GetOndragleave(JSContext* cx, JS::Value *aOndragleave) = 0;
  NS_IMETHOD SetOndragleave(JSContext* cx, const JS::Value & aOndragleave) = 0;

  /* [implicit_jscontext] attribute jsval ondragover; */
  NS_IMETHOD GetOndragover(JSContext* cx, JS::Value *aOndragover) = 0;
  NS_IMETHOD SetOndragover(JSContext* cx, const JS::Value & aOndragover) = 0;

  /* [implicit_jscontext] attribute jsval ondragstart; */
  NS_IMETHOD GetOndragstart(JSContext* cx, JS::Value *aOndragstart) = 0;
  NS_IMETHOD SetOndragstart(JSContext* cx, const JS::Value & aOndragstart) = 0;

  /* [implicit_jscontext] attribute jsval ondrop; */
  NS_IMETHOD GetOndrop(JSContext* cx, JS::Value *aOndrop) = 0;
  NS_IMETHOD SetOndrop(JSContext* cx, const JS::Value & aOndrop) = 0;

  /* [implicit_jscontext] attribute jsval ondurationchange; */
  NS_IMETHOD GetOndurationchange(JSContext* cx, JS::Value *aOndurationchange) = 0;
  NS_IMETHOD SetOndurationchange(JSContext* cx, const JS::Value & aOndurationchange) = 0;

  /* [implicit_jscontext] attribute jsval onemptied; */
  NS_IMETHOD GetOnemptied(JSContext* cx, JS::Value *aOnemptied) = 0;
  NS_IMETHOD SetOnemptied(JSContext* cx, const JS::Value & aOnemptied) = 0;

  /* [implicit_jscontext] attribute jsval onended; */
  NS_IMETHOD GetOnended(JSContext* cx, JS::Value *aOnended) = 0;
  NS_IMETHOD SetOnended(JSContext* cx, const JS::Value & aOnended) = 0;

  /* [implicit_jscontext] attribute jsval onerror; */
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) = 0;
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) = 0;

  /* [implicit_jscontext] attribute jsval onfocus; */
  NS_IMETHOD GetOnfocus(JSContext* cx, JS::Value *aOnfocus) = 0;
  NS_IMETHOD SetOnfocus(JSContext* cx, const JS::Value & aOnfocus) = 0;

  /* [implicit_jscontext] attribute jsval oninput; */
  NS_IMETHOD GetOninput(JSContext* cx, JS::Value *aOninput) = 0;
  NS_IMETHOD SetOninput(JSContext* cx, const JS::Value & aOninput) = 0;

  /* [implicit_jscontext] attribute jsval oninvalid; */
  NS_IMETHOD GetOninvalid(JSContext* cx, JS::Value *aOninvalid) = 0;
  NS_IMETHOD SetOninvalid(JSContext* cx, const JS::Value & aOninvalid) = 0;

  /* [implicit_jscontext] attribute jsval onkeydown; */
  NS_IMETHOD GetOnkeydown(JSContext* cx, JS::Value *aOnkeydown) = 0;
  NS_IMETHOD SetOnkeydown(JSContext* cx, const JS::Value & aOnkeydown) = 0;

  /* [implicit_jscontext] attribute jsval onkeypress; */
  NS_IMETHOD GetOnkeypress(JSContext* cx, JS::Value *aOnkeypress) = 0;
  NS_IMETHOD SetOnkeypress(JSContext* cx, const JS::Value & aOnkeypress) = 0;

  /* [implicit_jscontext] attribute jsval onkeyup; */
  NS_IMETHOD GetOnkeyup(JSContext* cx, JS::Value *aOnkeyup) = 0;
  NS_IMETHOD SetOnkeyup(JSContext* cx, const JS::Value & aOnkeyup) = 0;

  /* [implicit_jscontext] attribute jsval onload; */
  NS_IMETHOD GetOnload(JSContext* cx, JS::Value *aOnload) = 0;
  NS_IMETHOD SetOnload(JSContext* cx, const JS::Value & aOnload) = 0;

  /* [implicit_jscontext] attribute jsval onloadeddata; */
  NS_IMETHOD GetOnloadeddata(JSContext* cx, JS::Value *aOnloadeddata) = 0;
  NS_IMETHOD SetOnloadeddata(JSContext* cx, const JS::Value & aOnloadeddata) = 0;

  /* [implicit_jscontext] attribute jsval onloadedmetadata; */
  NS_IMETHOD GetOnloadedmetadata(JSContext* cx, JS::Value *aOnloadedmetadata) = 0;
  NS_IMETHOD SetOnloadedmetadata(JSContext* cx, const JS::Value & aOnloadedmetadata) = 0;

  /* [implicit_jscontext] attribute jsval onloadstart; */
  NS_IMETHOD GetOnloadstart(JSContext* cx, JS::Value *aOnloadstart) = 0;
  NS_IMETHOD SetOnloadstart(JSContext* cx, const JS::Value & aOnloadstart) = 0;

  /* [implicit_jscontext] attribute jsval onmousedown; */
  NS_IMETHOD GetOnmousedown(JSContext* cx, JS::Value *aOnmousedown) = 0;
  NS_IMETHOD SetOnmousedown(JSContext* cx, const JS::Value & aOnmousedown) = 0;

  /* [implicit_jscontext] attribute jsval onmousemove; */
  NS_IMETHOD GetOnmousemove(JSContext* cx, JS::Value *aOnmousemove) = 0;
  NS_IMETHOD SetOnmousemove(JSContext* cx, const JS::Value & aOnmousemove) = 0;

  /* [implicit_jscontext] attribute jsval onmouseout; */
  NS_IMETHOD GetOnmouseout(JSContext* cx, JS::Value *aOnmouseout) = 0;
  NS_IMETHOD SetOnmouseout(JSContext* cx, const JS::Value & aOnmouseout) = 0;

  /* [implicit_jscontext] attribute jsval onmouseover; */
  NS_IMETHOD GetOnmouseover(JSContext* cx, JS::Value *aOnmouseover) = 0;
  NS_IMETHOD SetOnmouseover(JSContext* cx, const JS::Value & aOnmouseover) = 0;

  /* [implicit_jscontext] attribute jsval onmouseup; */
  NS_IMETHOD GetOnmouseup(JSContext* cx, JS::Value *aOnmouseup) = 0;
  NS_IMETHOD SetOnmouseup(JSContext* cx, const JS::Value & aOnmouseup) = 0;

  /* [implicit_jscontext] attribute jsval onmozfullscreenchange; */
  NS_IMETHOD GetOnmozfullscreenchange(JSContext* cx, JS::Value *aOnmozfullscreenchange) = 0;
  NS_IMETHOD SetOnmozfullscreenchange(JSContext* cx, const JS::Value & aOnmozfullscreenchange) = 0;

  /* [implicit_jscontext] attribute jsval onmozfullscreenerror; */
  NS_IMETHOD GetOnmozfullscreenerror(JSContext* cx, JS::Value *aOnmozfullscreenerror) = 0;
  NS_IMETHOD SetOnmozfullscreenerror(JSContext* cx, const JS::Value & aOnmozfullscreenerror) = 0;

  /* [implicit_jscontext] attribute jsval onmozpointerlockchange; */
  NS_IMETHOD GetOnmozpointerlockchange(JSContext* cx, JS::Value *aOnmozpointerlockchange) = 0;
  NS_IMETHOD SetOnmozpointerlockchange(JSContext* cx, const JS::Value & aOnmozpointerlockchange) = 0;

  /* [implicit_jscontext] attribute jsval onmozpointerlockerror; */
  NS_IMETHOD GetOnmozpointerlockerror(JSContext* cx, JS::Value *aOnmozpointerlockerror) = 0;
  NS_IMETHOD SetOnmozpointerlockerror(JSContext* cx, const JS::Value & aOnmozpointerlockerror) = 0;

  /* [implicit_jscontext] attribute jsval onpause; */
  NS_IMETHOD GetOnpause(JSContext* cx, JS::Value *aOnpause) = 0;
  NS_IMETHOD SetOnpause(JSContext* cx, const JS::Value & aOnpause) = 0;

  /* [implicit_jscontext] attribute jsval onplay; */
  NS_IMETHOD GetOnplay(JSContext* cx, JS::Value *aOnplay) = 0;
  NS_IMETHOD SetOnplay(JSContext* cx, const JS::Value & aOnplay) = 0;

  /* [implicit_jscontext] attribute jsval onplaying; */
  NS_IMETHOD GetOnplaying(JSContext* cx, JS::Value *aOnplaying) = 0;
  NS_IMETHOD SetOnplaying(JSContext* cx, const JS::Value & aOnplaying) = 0;

  /* [implicit_jscontext] attribute jsval onprogress; */
  NS_IMETHOD GetOnprogress(JSContext* cx, JS::Value *aOnprogress) = 0;
  NS_IMETHOD SetOnprogress(JSContext* cx, const JS::Value & aOnprogress) = 0;

  /* [implicit_jscontext] attribute jsval onratechange; */
  NS_IMETHOD GetOnratechange(JSContext* cx, JS::Value *aOnratechange) = 0;
  NS_IMETHOD SetOnratechange(JSContext* cx, const JS::Value & aOnratechange) = 0;

  /* [implicit_jscontext] attribute jsval onreset; */
  NS_IMETHOD GetOnreset(JSContext* cx, JS::Value *aOnreset) = 0;
  NS_IMETHOD SetOnreset(JSContext* cx, const JS::Value & aOnreset) = 0;

  /* [implicit_jscontext] attribute jsval onscroll; */
  NS_IMETHOD GetOnscroll(JSContext* cx, JS::Value *aOnscroll) = 0;
  NS_IMETHOD SetOnscroll(JSContext* cx, const JS::Value & aOnscroll) = 0;

  /* [implicit_jscontext] attribute jsval onseeked; */
  NS_IMETHOD GetOnseeked(JSContext* cx, JS::Value *aOnseeked) = 0;
  NS_IMETHOD SetOnseeked(JSContext* cx, const JS::Value & aOnseeked) = 0;

  /* [implicit_jscontext] attribute jsval onseeking; */
  NS_IMETHOD GetOnseeking(JSContext* cx, JS::Value *aOnseeking) = 0;
  NS_IMETHOD SetOnseeking(JSContext* cx, const JS::Value & aOnseeking) = 0;

  /* [implicit_jscontext] attribute jsval onselect; */
  NS_IMETHOD GetOnselect(JSContext* cx, JS::Value *aOnselect) = 0;
  NS_IMETHOD SetOnselect(JSContext* cx, const JS::Value & aOnselect) = 0;

  /* [implicit_jscontext] attribute jsval onshow; */
  NS_IMETHOD GetOnshow(JSContext* cx, JS::Value *aOnshow) = 0;
  NS_IMETHOD SetOnshow(JSContext* cx, const JS::Value & aOnshow) = 0;

  /* [implicit_jscontext] attribute jsval onstalled; */
  NS_IMETHOD GetOnstalled(JSContext* cx, JS::Value *aOnstalled) = 0;
  NS_IMETHOD SetOnstalled(JSContext* cx, const JS::Value & aOnstalled) = 0;

  /* [implicit_jscontext] attribute jsval onsubmit; */
  NS_IMETHOD GetOnsubmit(JSContext* cx, JS::Value *aOnsubmit) = 0;
  NS_IMETHOD SetOnsubmit(JSContext* cx, const JS::Value & aOnsubmit) = 0;

  /* [implicit_jscontext] attribute jsval onsuspend; */
  NS_IMETHOD GetOnsuspend(JSContext* cx, JS::Value *aOnsuspend) = 0;
  NS_IMETHOD SetOnsuspend(JSContext* cx, const JS::Value & aOnsuspend) = 0;

  /* [implicit_jscontext] attribute jsval ontimeupdate; */
  NS_IMETHOD GetOntimeupdate(JSContext* cx, JS::Value *aOntimeupdate) = 0;
  NS_IMETHOD SetOntimeupdate(JSContext* cx, const JS::Value & aOntimeupdate) = 0;

  /* [implicit_jscontext] attribute jsval onvolumechange; */
  NS_IMETHOD GetOnvolumechange(JSContext* cx, JS::Value *aOnvolumechange) = 0;
  NS_IMETHOD SetOnvolumechange(JSContext* cx, const JS::Value & aOnvolumechange) = 0;

  /* [implicit_jscontext] attribute jsval onwaiting; */
  NS_IMETHOD GetOnwaiting(JSContext* cx, JS::Value *aOnwaiting) = 0;
  NS_IMETHOD SetOnwaiting(JSContext* cx, const JS::Value & aOnwaiting) = 0;

  /* [implicit_jscontext] attribute jsval onwheel; */
  NS_IMETHOD GetOnwheel(JSContext* cx, JS::Value *aOnwheel) = 0;
  NS_IMETHOD SetOnwheel(JSContext* cx, const JS::Value & aOnwheel) = 0;

  /* [implicit_jscontext] attribute jsval oncopy; */
  NS_IMETHOD GetOncopy(JSContext* cx, JS::Value *aOncopy) = 0;
  NS_IMETHOD SetOncopy(JSContext* cx, const JS::Value & aOncopy) = 0;

  /* [implicit_jscontext] attribute jsval oncut; */
  NS_IMETHOD GetOncut(JSContext* cx, JS::Value *aOncut) = 0;
  NS_IMETHOD SetOncut(JSContext* cx, const JS::Value & aOncut) = 0;

  /* [implicit_jscontext] attribute jsval onpaste; */
  NS_IMETHOD GetOnpaste(JSContext* cx, JS::Value *aOnpaste) = 0;
  NS_IMETHOD SetOnpaste(JSContext* cx, const JS::Value & aOnpaste) = 0;

  /* [implicit_jscontext] attribute jsval onbeforescriptexecute; */
  NS_IMETHOD GetOnbeforescriptexecute(JSContext* cx, JS::Value *aOnbeforescriptexecute) = 0;
  NS_IMETHOD SetOnbeforescriptexecute(JSContext* cx, const JS::Value & aOnbeforescriptexecute) = 0;

  /* [implicit_jscontext] attribute jsval onafterscriptexecute; */
  NS_IMETHOD GetOnafterscriptexecute(JSContext* cx, JS::Value *aOnafterscriptexecute) = 0;
  NS_IMETHOD SetOnafterscriptexecute(JSContext* cx, const JS::Value & aOnafterscriptexecute) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInlineEventHandlers, NS_IINLINEEVENTHANDLERS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINLINEEVENTHANDLERS \
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort); \
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort); \
  NS_IMETHOD GetOnblur(JSContext* cx, JS::Value *aOnblur); \
  NS_IMETHOD SetOnblur(JSContext* cx, const JS::Value & aOnblur); \
  NS_IMETHOD GetOncanplay(JSContext* cx, JS::Value *aOncanplay); \
  NS_IMETHOD SetOncanplay(JSContext* cx, const JS::Value & aOncanplay); \
  NS_IMETHOD GetOncanplaythrough(JSContext* cx, JS::Value *aOncanplaythrough); \
  NS_IMETHOD SetOncanplaythrough(JSContext* cx, const JS::Value & aOncanplaythrough); \
  NS_IMETHOD GetOnchange(JSContext* cx, JS::Value *aOnchange); \
  NS_IMETHOD SetOnchange(JSContext* cx, const JS::Value & aOnchange); \
  NS_IMETHOD GetOnclick(JSContext* cx, JS::Value *aOnclick); \
  NS_IMETHOD SetOnclick(JSContext* cx, const JS::Value & aOnclick); \
  NS_IMETHOD GetOncontextmenu(JSContext* cx, JS::Value *aOncontextmenu); \
  NS_IMETHOD SetOncontextmenu(JSContext* cx, const JS::Value & aOncontextmenu); \
  NS_IMETHOD GetOndblclick(JSContext* cx, JS::Value *aOndblclick); \
  NS_IMETHOD SetOndblclick(JSContext* cx, const JS::Value & aOndblclick); \
  NS_IMETHOD GetOndrag(JSContext* cx, JS::Value *aOndrag); \
  NS_IMETHOD SetOndrag(JSContext* cx, const JS::Value & aOndrag); \
  NS_IMETHOD GetOndragend(JSContext* cx, JS::Value *aOndragend); \
  NS_IMETHOD SetOndragend(JSContext* cx, const JS::Value & aOndragend); \
  NS_IMETHOD GetOndragenter(JSContext* cx, JS::Value *aOndragenter); \
  NS_IMETHOD SetOndragenter(JSContext* cx, const JS::Value & aOndragenter); \
  NS_IMETHOD GetOndragleave(JSContext* cx, JS::Value *aOndragleave); \
  NS_IMETHOD SetOndragleave(JSContext* cx, const JS::Value & aOndragleave); \
  NS_IMETHOD GetOndragover(JSContext* cx, JS::Value *aOndragover); \
  NS_IMETHOD SetOndragover(JSContext* cx, const JS::Value & aOndragover); \
  NS_IMETHOD GetOndragstart(JSContext* cx, JS::Value *aOndragstart); \
  NS_IMETHOD SetOndragstart(JSContext* cx, const JS::Value & aOndragstart); \
  NS_IMETHOD GetOndrop(JSContext* cx, JS::Value *aOndrop); \
  NS_IMETHOD SetOndrop(JSContext* cx, const JS::Value & aOndrop); \
  NS_IMETHOD GetOndurationchange(JSContext* cx, JS::Value *aOndurationchange); \
  NS_IMETHOD SetOndurationchange(JSContext* cx, const JS::Value & aOndurationchange); \
  NS_IMETHOD GetOnemptied(JSContext* cx, JS::Value *aOnemptied); \
  NS_IMETHOD SetOnemptied(JSContext* cx, const JS::Value & aOnemptied); \
  NS_IMETHOD GetOnended(JSContext* cx, JS::Value *aOnended); \
  NS_IMETHOD SetOnended(JSContext* cx, const JS::Value & aOnended); \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror); \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror); \
  NS_IMETHOD GetOnfocus(JSContext* cx, JS::Value *aOnfocus); \
  NS_IMETHOD SetOnfocus(JSContext* cx, const JS::Value & aOnfocus); \
  NS_IMETHOD GetOninput(JSContext* cx, JS::Value *aOninput); \
  NS_IMETHOD SetOninput(JSContext* cx, const JS::Value & aOninput); \
  NS_IMETHOD GetOninvalid(JSContext* cx, JS::Value *aOninvalid); \
  NS_IMETHOD SetOninvalid(JSContext* cx, const JS::Value & aOninvalid); \
  NS_IMETHOD GetOnkeydown(JSContext* cx, JS::Value *aOnkeydown); \
  NS_IMETHOD SetOnkeydown(JSContext* cx, const JS::Value & aOnkeydown); \
  NS_IMETHOD GetOnkeypress(JSContext* cx, JS::Value *aOnkeypress); \
  NS_IMETHOD SetOnkeypress(JSContext* cx, const JS::Value & aOnkeypress); \
  NS_IMETHOD GetOnkeyup(JSContext* cx, JS::Value *aOnkeyup); \
  NS_IMETHOD SetOnkeyup(JSContext* cx, const JS::Value & aOnkeyup); \
  NS_IMETHOD GetOnload(JSContext* cx, JS::Value *aOnload); \
  NS_IMETHOD SetOnload(JSContext* cx, const JS::Value & aOnload); \
  NS_IMETHOD GetOnloadeddata(JSContext* cx, JS::Value *aOnloadeddata); \
  NS_IMETHOD SetOnloadeddata(JSContext* cx, const JS::Value & aOnloadeddata); \
  NS_IMETHOD GetOnloadedmetadata(JSContext* cx, JS::Value *aOnloadedmetadata); \
  NS_IMETHOD SetOnloadedmetadata(JSContext* cx, const JS::Value & aOnloadedmetadata); \
  NS_IMETHOD GetOnloadstart(JSContext* cx, JS::Value *aOnloadstart); \
  NS_IMETHOD SetOnloadstart(JSContext* cx, const JS::Value & aOnloadstart); \
  NS_IMETHOD GetOnmousedown(JSContext* cx, JS::Value *aOnmousedown); \
  NS_IMETHOD SetOnmousedown(JSContext* cx, const JS::Value & aOnmousedown); \
  NS_IMETHOD GetOnmousemove(JSContext* cx, JS::Value *aOnmousemove); \
  NS_IMETHOD SetOnmousemove(JSContext* cx, const JS::Value & aOnmousemove); \
  NS_IMETHOD GetOnmouseout(JSContext* cx, JS::Value *aOnmouseout); \
  NS_IMETHOD SetOnmouseout(JSContext* cx, const JS::Value & aOnmouseout); \
  NS_IMETHOD GetOnmouseover(JSContext* cx, JS::Value *aOnmouseover); \
  NS_IMETHOD SetOnmouseover(JSContext* cx, const JS::Value & aOnmouseover); \
  NS_IMETHOD GetOnmouseup(JSContext* cx, JS::Value *aOnmouseup); \
  NS_IMETHOD SetOnmouseup(JSContext* cx, const JS::Value & aOnmouseup); \
  NS_IMETHOD GetOnmozfullscreenchange(JSContext* cx, JS::Value *aOnmozfullscreenchange); \
  NS_IMETHOD SetOnmozfullscreenchange(JSContext* cx, const JS::Value & aOnmozfullscreenchange); \
  NS_IMETHOD GetOnmozfullscreenerror(JSContext* cx, JS::Value *aOnmozfullscreenerror); \
  NS_IMETHOD SetOnmozfullscreenerror(JSContext* cx, const JS::Value & aOnmozfullscreenerror); \
  NS_IMETHOD GetOnmozpointerlockchange(JSContext* cx, JS::Value *aOnmozpointerlockchange); \
  NS_IMETHOD SetOnmozpointerlockchange(JSContext* cx, const JS::Value & aOnmozpointerlockchange); \
  NS_IMETHOD GetOnmozpointerlockerror(JSContext* cx, JS::Value *aOnmozpointerlockerror); \
  NS_IMETHOD SetOnmozpointerlockerror(JSContext* cx, const JS::Value & aOnmozpointerlockerror); \
  NS_IMETHOD GetOnpause(JSContext* cx, JS::Value *aOnpause); \
  NS_IMETHOD SetOnpause(JSContext* cx, const JS::Value & aOnpause); \
  NS_IMETHOD GetOnplay(JSContext* cx, JS::Value *aOnplay); \
  NS_IMETHOD SetOnplay(JSContext* cx, const JS::Value & aOnplay); \
  NS_IMETHOD GetOnplaying(JSContext* cx, JS::Value *aOnplaying); \
  NS_IMETHOD SetOnplaying(JSContext* cx, const JS::Value & aOnplaying); \
  NS_IMETHOD GetOnprogress(JSContext* cx, JS::Value *aOnprogress); \
  NS_IMETHOD SetOnprogress(JSContext* cx, const JS::Value & aOnprogress); \
  NS_IMETHOD GetOnratechange(JSContext* cx, JS::Value *aOnratechange); \
  NS_IMETHOD SetOnratechange(JSContext* cx, const JS::Value & aOnratechange); \
  NS_IMETHOD GetOnreset(JSContext* cx, JS::Value *aOnreset); \
  NS_IMETHOD SetOnreset(JSContext* cx, const JS::Value & aOnreset); \
  NS_IMETHOD GetOnscroll(JSContext* cx, JS::Value *aOnscroll); \
  NS_IMETHOD SetOnscroll(JSContext* cx, const JS::Value & aOnscroll); \
  NS_IMETHOD GetOnseeked(JSContext* cx, JS::Value *aOnseeked); \
  NS_IMETHOD SetOnseeked(JSContext* cx, const JS::Value & aOnseeked); \
  NS_IMETHOD GetOnseeking(JSContext* cx, JS::Value *aOnseeking); \
  NS_IMETHOD SetOnseeking(JSContext* cx, const JS::Value & aOnseeking); \
  NS_IMETHOD GetOnselect(JSContext* cx, JS::Value *aOnselect); \
  NS_IMETHOD SetOnselect(JSContext* cx, const JS::Value & aOnselect); \
  NS_IMETHOD GetOnshow(JSContext* cx, JS::Value *aOnshow); \
  NS_IMETHOD SetOnshow(JSContext* cx, const JS::Value & aOnshow); \
  NS_IMETHOD GetOnstalled(JSContext* cx, JS::Value *aOnstalled); \
  NS_IMETHOD SetOnstalled(JSContext* cx, const JS::Value & aOnstalled); \
  NS_IMETHOD GetOnsubmit(JSContext* cx, JS::Value *aOnsubmit); \
  NS_IMETHOD SetOnsubmit(JSContext* cx, const JS::Value & aOnsubmit); \
  NS_IMETHOD GetOnsuspend(JSContext* cx, JS::Value *aOnsuspend); \
  NS_IMETHOD SetOnsuspend(JSContext* cx, const JS::Value & aOnsuspend); \
  NS_IMETHOD GetOntimeupdate(JSContext* cx, JS::Value *aOntimeupdate); \
  NS_IMETHOD SetOntimeupdate(JSContext* cx, const JS::Value & aOntimeupdate); \
  NS_IMETHOD GetOnvolumechange(JSContext* cx, JS::Value *aOnvolumechange); \
  NS_IMETHOD SetOnvolumechange(JSContext* cx, const JS::Value & aOnvolumechange); \
  NS_IMETHOD GetOnwaiting(JSContext* cx, JS::Value *aOnwaiting); \
  NS_IMETHOD SetOnwaiting(JSContext* cx, const JS::Value & aOnwaiting); \
  NS_IMETHOD GetOnwheel(JSContext* cx, JS::Value *aOnwheel); \
  NS_IMETHOD SetOnwheel(JSContext* cx, const JS::Value & aOnwheel); \
  NS_IMETHOD GetOncopy(JSContext* cx, JS::Value *aOncopy); \
  NS_IMETHOD SetOncopy(JSContext* cx, const JS::Value & aOncopy); \
  NS_IMETHOD GetOncut(JSContext* cx, JS::Value *aOncut); \
  NS_IMETHOD SetOncut(JSContext* cx, const JS::Value & aOncut); \
  NS_IMETHOD GetOnpaste(JSContext* cx, JS::Value *aOnpaste); \
  NS_IMETHOD SetOnpaste(JSContext* cx, const JS::Value & aOnpaste); \
  NS_IMETHOD GetOnbeforescriptexecute(JSContext* cx, JS::Value *aOnbeforescriptexecute); \
  NS_IMETHOD SetOnbeforescriptexecute(JSContext* cx, const JS::Value & aOnbeforescriptexecute); \
  NS_IMETHOD GetOnafterscriptexecute(JSContext* cx, JS::Value *aOnafterscriptexecute); \
  NS_IMETHOD SetOnafterscriptexecute(JSContext* cx, const JS::Value & aOnafterscriptexecute); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINLINEEVENTHANDLERS(_to) \
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort) { return _to GetOnabort(cx, aOnabort); } \
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort) { return _to SetOnabort(cx, aOnabort); } \
  NS_IMETHOD GetOnblur(JSContext* cx, JS::Value *aOnblur) { return _to GetOnblur(cx, aOnblur); } \
  NS_IMETHOD SetOnblur(JSContext* cx, const JS::Value & aOnblur) { return _to SetOnblur(cx, aOnblur); } \
  NS_IMETHOD GetOncanplay(JSContext* cx, JS::Value *aOncanplay) { return _to GetOncanplay(cx, aOncanplay); } \
  NS_IMETHOD SetOncanplay(JSContext* cx, const JS::Value & aOncanplay) { return _to SetOncanplay(cx, aOncanplay); } \
  NS_IMETHOD GetOncanplaythrough(JSContext* cx, JS::Value *aOncanplaythrough) { return _to GetOncanplaythrough(cx, aOncanplaythrough); } \
  NS_IMETHOD SetOncanplaythrough(JSContext* cx, const JS::Value & aOncanplaythrough) { return _to SetOncanplaythrough(cx, aOncanplaythrough); } \
  NS_IMETHOD GetOnchange(JSContext* cx, JS::Value *aOnchange) { return _to GetOnchange(cx, aOnchange); } \
  NS_IMETHOD SetOnchange(JSContext* cx, const JS::Value & aOnchange) { return _to SetOnchange(cx, aOnchange); } \
  NS_IMETHOD GetOnclick(JSContext* cx, JS::Value *aOnclick) { return _to GetOnclick(cx, aOnclick); } \
  NS_IMETHOD SetOnclick(JSContext* cx, const JS::Value & aOnclick) { return _to SetOnclick(cx, aOnclick); } \
  NS_IMETHOD GetOncontextmenu(JSContext* cx, JS::Value *aOncontextmenu) { return _to GetOncontextmenu(cx, aOncontextmenu); } \
  NS_IMETHOD SetOncontextmenu(JSContext* cx, const JS::Value & aOncontextmenu) { return _to SetOncontextmenu(cx, aOncontextmenu); } \
  NS_IMETHOD GetOndblclick(JSContext* cx, JS::Value *aOndblclick) { return _to GetOndblclick(cx, aOndblclick); } \
  NS_IMETHOD SetOndblclick(JSContext* cx, const JS::Value & aOndblclick) { return _to SetOndblclick(cx, aOndblclick); } \
  NS_IMETHOD GetOndrag(JSContext* cx, JS::Value *aOndrag) { return _to GetOndrag(cx, aOndrag); } \
  NS_IMETHOD SetOndrag(JSContext* cx, const JS::Value & aOndrag) { return _to SetOndrag(cx, aOndrag); } \
  NS_IMETHOD GetOndragend(JSContext* cx, JS::Value *aOndragend) { return _to GetOndragend(cx, aOndragend); } \
  NS_IMETHOD SetOndragend(JSContext* cx, const JS::Value & aOndragend) { return _to SetOndragend(cx, aOndragend); } \
  NS_IMETHOD GetOndragenter(JSContext* cx, JS::Value *aOndragenter) { return _to GetOndragenter(cx, aOndragenter); } \
  NS_IMETHOD SetOndragenter(JSContext* cx, const JS::Value & aOndragenter) { return _to SetOndragenter(cx, aOndragenter); } \
  NS_IMETHOD GetOndragleave(JSContext* cx, JS::Value *aOndragleave) { return _to GetOndragleave(cx, aOndragleave); } \
  NS_IMETHOD SetOndragleave(JSContext* cx, const JS::Value & aOndragleave) { return _to SetOndragleave(cx, aOndragleave); } \
  NS_IMETHOD GetOndragover(JSContext* cx, JS::Value *aOndragover) { return _to GetOndragover(cx, aOndragover); } \
  NS_IMETHOD SetOndragover(JSContext* cx, const JS::Value & aOndragover) { return _to SetOndragover(cx, aOndragover); } \
  NS_IMETHOD GetOndragstart(JSContext* cx, JS::Value *aOndragstart) { return _to GetOndragstart(cx, aOndragstart); } \
  NS_IMETHOD SetOndragstart(JSContext* cx, const JS::Value & aOndragstart) { return _to SetOndragstart(cx, aOndragstart); } \
  NS_IMETHOD GetOndrop(JSContext* cx, JS::Value *aOndrop) { return _to GetOndrop(cx, aOndrop); } \
  NS_IMETHOD SetOndrop(JSContext* cx, const JS::Value & aOndrop) { return _to SetOndrop(cx, aOndrop); } \
  NS_IMETHOD GetOndurationchange(JSContext* cx, JS::Value *aOndurationchange) { return _to GetOndurationchange(cx, aOndurationchange); } \
  NS_IMETHOD SetOndurationchange(JSContext* cx, const JS::Value & aOndurationchange) { return _to SetOndurationchange(cx, aOndurationchange); } \
  NS_IMETHOD GetOnemptied(JSContext* cx, JS::Value *aOnemptied) { return _to GetOnemptied(cx, aOnemptied); } \
  NS_IMETHOD SetOnemptied(JSContext* cx, const JS::Value & aOnemptied) { return _to SetOnemptied(cx, aOnemptied); } \
  NS_IMETHOD GetOnended(JSContext* cx, JS::Value *aOnended) { return _to GetOnended(cx, aOnended); } \
  NS_IMETHOD SetOnended(JSContext* cx, const JS::Value & aOnended) { return _to SetOnended(cx, aOnended); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) { return _to GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) { return _to SetOnerror(cx, aOnerror); } \
  NS_IMETHOD GetOnfocus(JSContext* cx, JS::Value *aOnfocus) { return _to GetOnfocus(cx, aOnfocus); } \
  NS_IMETHOD SetOnfocus(JSContext* cx, const JS::Value & aOnfocus) { return _to SetOnfocus(cx, aOnfocus); } \
  NS_IMETHOD GetOninput(JSContext* cx, JS::Value *aOninput) { return _to GetOninput(cx, aOninput); } \
  NS_IMETHOD SetOninput(JSContext* cx, const JS::Value & aOninput) { return _to SetOninput(cx, aOninput); } \
  NS_IMETHOD GetOninvalid(JSContext* cx, JS::Value *aOninvalid) { return _to GetOninvalid(cx, aOninvalid); } \
  NS_IMETHOD SetOninvalid(JSContext* cx, const JS::Value & aOninvalid) { return _to SetOninvalid(cx, aOninvalid); } \
  NS_IMETHOD GetOnkeydown(JSContext* cx, JS::Value *aOnkeydown) { return _to GetOnkeydown(cx, aOnkeydown); } \
  NS_IMETHOD SetOnkeydown(JSContext* cx, const JS::Value & aOnkeydown) { return _to SetOnkeydown(cx, aOnkeydown); } \
  NS_IMETHOD GetOnkeypress(JSContext* cx, JS::Value *aOnkeypress) { return _to GetOnkeypress(cx, aOnkeypress); } \
  NS_IMETHOD SetOnkeypress(JSContext* cx, const JS::Value & aOnkeypress) { return _to SetOnkeypress(cx, aOnkeypress); } \
  NS_IMETHOD GetOnkeyup(JSContext* cx, JS::Value *aOnkeyup) { return _to GetOnkeyup(cx, aOnkeyup); } \
  NS_IMETHOD SetOnkeyup(JSContext* cx, const JS::Value & aOnkeyup) { return _to SetOnkeyup(cx, aOnkeyup); } \
  NS_IMETHOD GetOnload(JSContext* cx, JS::Value *aOnload) { return _to GetOnload(cx, aOnload); } \
  NS_IMETHOD SetOnload(JSContext* cx, const JS::Value & aOnload) { return _to SetOnload(cx, aOnload); } \
  NS_IMETHOD GetOnloadeddata(JSContext* cx, JS::Value *aOnloadeddata) { return _to GetOnloadeddata(cx, aOnloadeddata); } \
  NS_IMETHOD SetOnloadeddata(JSContext* cx, const JS::Value & aOnloadeddata) { return _to SetOnloadeddata(cx, aOnloadeddata); } \
  NS_IMETHOD GetOnloadedmetadata(JSContext* cx, JS::Value *aOnloadedmetadata) { return _to GetOnloadedmetadata(cx, aOnloadedmetadata); } \
  NS_IMETHOD SetOnloadedmetadata(JSContext* cx, const JS::Value & aOnloadedmetadata) { return _to SetOnloadedmetadata(cx, aOnloadedmetadata); } \
  NS_IMETHOD GetOnloadstart(JSContext* cx, JS::Value *aOnloadstart) { return _to GetOnloadstart(cx, aOnloadstart); } \
  NS_IMETHOD SetOnloadstart(JSContext* cx, const JS::Value & aOnloadstart) { return _to SetOnloadstart(cx, aOnloadstart); } \
  NS_IMETHOD GetOnmousedown(JSContext* cx, JS::Value *aOnmousedown) { return _to GetOnmousedown(cx, aOnmousedown); } \
  NS_IMETHOD SetOnmousedown(JSContext* cx, const JS::Value & aOnmousedown) { return _to SetOnmousedown(cx, aOnmousedown); } \
  NS_IMETHOD GetOnmousemove(JSContext* cx, JS::Value *aOnmousemove) { return _to GetOnmousemove(cx, aOnmousemove); } \
  NS_IMETHOD SetOnmousemove(JSContext* cx, const JS::Value & aOnmousemove) { return _to SetOnmousemove(cx, aOnmousemove); } \
  NS_IMETHOD GetOnmouseout(JSContext* cx, JS::Value *aOnmouseout) { return _to GetOnmouseout(cx, aOnmouseout); } \
  NS_IMETHOD SetOnmouseout(JSContext* cx, const JS::Value & aOnmouseout) { return _to SetOnmouseout(cx, aOnmouseout); } \
  NS_IMETHOD GetOnmouseover(JSContext* cx, JS::Value *aOnmouseover) { return _to GetOnmouseover(cx, aOnmouseover); } \
  NS_IMETHOD SetOnmouseover(JSContext* cx, const JS::Value & aOnmouseover) { return _to SetOnmouseover(cx, aOnmouseover); } \
  NS_IMETHOD GetOnmouseup(JSContext* cx, JS::Value *aOnmouseup) { return _to GetOnmouseup(cx, aOnmouseup); } \
  NS_IMETHOD SetOnmouseup(JSContext* cx, const JS::Value & aOnmouseup) { return _to SetOnmouseup(cx, aOnmouseup); } \
  NS_IMETHOD GetOnmozfullscreenchange(JSContext* cx, JS::Value *aOnmozfullscreenchange) { return _to GetOnmozfullscreenchange(cx, aOnmozfullscreenchange); } \
  NS_IMETHOD SetOnmozfullscreenchange(JSContext* cx, const JS::Value & aOnmozfullscreenchange) { return _to SetOnmozfullscreenchange(cx, aOnmozfullscreenchange); } \
  NS_IMETHOD GetOnmozfullscreenerror(JSContext* cx, JS::Value *aOnmozfullscreenerror) { return _to GetOnmozfullscreenerror(cx, aOnmozfullscreenerror); } \
  NS_IMETHOD SetOnmozfullscreenerror(JSContext* cx, const JS::Value & aOnmozfullscreenerror) { return _to SetOnmozfullscreenerror(cx, aOnmozfullscreenerror); } \
  NS_IMETHOD GetOnmozpointerlockchange(JSContext* cx, JS::Value *aOnmozpointerlockchange) { return _to GetOnmozpointerlockchange(cx, aOnmozpointerlockchange); } \
  NS_IMETHOD SetOnmozpointerlockchange(JSContext* cx, const JS::Value & aOnmozpointerlockchange) { return _to SetOnmozpointerlockchange(cx, aOnmozpointerlockchange); } \
  NS_IMETHOD GetOnmozpointerlockerror(JSContext* cx, JS::Value *aOnmozpointerlockerror) { return _to GetOnmozpointerlockerror(cx, aOnmozpointerlockerror); } \
  NS_IMETHOD SetOnmozpointerlockerror(JSContext* cx, const JS::Value & aOnmozpointerlockerror) { return _to SetOnmozpointerlockerror(cx, aOnmozpointerlockerror); } \
  NS_IMETHOD GetOnpause(JSContext* cx, JS::Value *aOnpause) { return _to GetOnpause(cx, aOnpause); } \
  NS_IMETHOD SetOnpause(JSContext* cx, const JS::Value & aOnpause) { return _to SetOnpause(cx, aOnpause); } \
  NS_IMETHOD GetOnplay(JSContext* cx, JS::Value *aOnplay) { return _to GetOnplay(cx, aOnplay); } \
  NS_IMETHOD SetOnplay(JSContext* cx, const JS::Value & aOnplay) { return _to SetOnplay(cx, aOnplay); } \
  NS_IMETHOD GetOnplaying(JSContext* cx, JS::Value *aOnplaying) { return _to GetOnplaying(cx, aOnplaying); } \
  NS_IMETHOD SetOnplaying(JSContext* cx, const JS::Value & aOnplaying) { return _to SetOnplaying(cx, aOnplaying); } \
  NS_IMETHOD GetOnprogress(JSContext* cx, JS::Value *aOnprogress) { return _to GetOnprogress(cx, aOnprogress); } \
  NS_IMETHOD SetOnprogress(JSContext* cx, const JS::Value & aOnprogress) { return _to SetOnprogress(cx, aOnprogress); } \
  NS_IMETHOD GetOnratechange(JSContext* cx, JS::Value *aOnratechange) { return _to GetOnratechange(cx, aOnratechange); } \
  NS_IMETHOD SetOnratechange(JSContext* cx, const JS::Value & aOnratechange) { return _to SetOnratechange(cx, aOnratechange); } \
  NS_IMETHOD GetOnreset(JSContext* cx, JS::Value *aOnreset) { return _to GetOnreset(cx, aOnreset); } \
  NS_IMETHOD SetOnreset(JSContext* cx, const JS::Value & aOnreset) { return _to SetOnreset(cx, aOnreset); } \
  NS_IMETHOD GetOnscroll(JSContext* cx, JS::Value *aOnscroll) { return _to GetOnscroll(cx, aOnscroll); } \
  NS_IMETHOD SetOnscroll(JSContext* cx, const JS::Value & aOnscroll) { return _to SetOnscroll(cx, aOnscroll); } \
  NS_IMETHOD GetOnseeked(JSContext* cx, JS::Value *aOnseeked) { return _to GetOnseeked(cx, aOnseeked); } \
  NS_IMETHOD SetOnseeked(JSContext* cx, const JS::Value & aOnseeked) { return _to SetOnseeked(cx, aOnseeked); } \
  NS_IMETHOD GetOnseeking(JSContext* cx, JS::Value *aOnseeking) { return _to GetOnseeking(cx, aOnseeking); } \
  NS_IMETHOD SetOnseeking(JSContext* cx, const JS::Value & aOnseeking) { return _to SetOnseeking(cx, aOnseeking); } \
  NS_IMETHOD GetOnselect(JSContext* cx, JS::Value *aOnselect) { return _to GetOnselect(cx, aOnselect); } \
  NS_IMETHOD SetOnselect(JSContext* cx, const JS::Value & aOnselect) { return _to SetOnselect(cx, aOnselect); } \
  NS_IMETHOD GetOnshow(JSContext* cx, JS::Value *aOnshow) { return _to GetOnshow(cx, aOnshow); } \
  NS_IMETHOD SetOnshow(JSContext* cx, const JS::Value & aOnshow) { return _to SetOnshow(cx, aOnshow); } \
  NS_IMETHOD GetOnstalled(JSContext* cx, JS::Value *aOnstalled) { return _to GetOnstalled(cx, aOnstalled); } \
  NS_IMETHOD SetOnstalled(JSContext* cx, const JS::Value & aOnstalled) { return _to SetOnstalled(cx, aOnstalled); } \
  NS_IMETHOD GetOnsubmit(JSContext* cx, JS::Value *aOnsubmit) { return _to GetOnsubmit(cx, aOnsubmit); } \
  NS_IMETHOD SetOnsubmit(JSContext* cx, const JS::Value & aOnsubmit) { return _to SetOnsubmit(cx, aOnsubmit); } \
  NS_IMETHOD GetOnsuspend(JSContext* cx, JS::Value *aOnsuspend) { return _to GetOnsuspend(cx, aOnsuspend); } \
  NS_IMETHOD SetOnsuspend(JSContext* cx, const JS::Value & aOnsuspend) { return _to SetOnsuspend(cx, aOnsuspend); } \
  NS_IMETHOD GetOntimeupdate(JSContext* cx, JS::Value *aOntimeupdate) { return _to GetOntimeupdate(cx, aOntimeupdate); } \
  NS_IMETHOD SetOntimeupdate(JSContext* cx, const JS::Value & aOntimeupdate) { return _to SetOntimeupdate(cx, aOntimeupdate); } \
  NS_IMETHOD GetOnvolumechange(JSContext* cx, JS::Value *aOnvolumechange) { return _to GetOnvolumechange(cx, aOnvolumechange); } \
  NS_IMETHOD SetOnvolumechange(JSContext* cx, const JS::Value & aOnvolumechange) { return _to SetOnvolumechange(cx, aOnvolumechange); } \
  NS_IMETHOD GetOnwaiting(JSContext* cx, JS::Value *aOnwaiting) { return _to GetOnwaiting(cx, aOnwaiting); } \
  NS_IMETHOD SetOnwaiting(JSContext* cx, const JS::Value & aOnwaiting) { return _to SetOnwaiting(cx, aOnwaiting); } \
  NS_IMETHOD GetOnwheel(JSContext* cx, JS::Value *aOnwheel) { return _to GetOnwheel(cx, aOnwheel); } \
  NS_IMETHOD SetOnwheel(JSContext* cx, const JS::Value & aOnwheel) { return _to SetOnwheel(cx, aOnwheel); } \
  NS_IMETHOD GetOncopy(JSContext* cx, JS::Value *aOncopy) { return _to GetOncopy(cx, aOncopy); } \
  NS_IMETHOD SetOncopy(JSContext* cx, const JS::Value & aOncopy) { return _to SetOncopy(cx, aOncopy); } \
  NS_IMETHOD GetOncut(JSContext* cx, JS::Value *aOncut) { return _to GetOncut(cx, aOncut); } \
  NS_IMETHOD SetOncut(JSContext* cx, const JS::Value & aOncut) { return _to SetOncut(cx, aOncut); } \
  NS_IMETHOD GetOnpaste(JSContext* cx, JS::Value *aOnpaste) { return _to GetOnpaste(cx, aOnpaste); } \
  NS_IMETHOD SetOnpaste(JSContext* cx, const JS::Value & aOnpaste) { return _to SetOnpaste(cx, aOnpaste); } \
  NS_IMETHOD GetOnbeforescriptexecute(JSContext* cx, JS::Value *aOnbeforescriptexecute) { return _to GetOnbeforescriptexecute(cx, aOnbeforescriptexecute); } \
  NS_IMETHOD SetOnbeforescriptexecute(JSContext* cx, const JS::Value & aOnbeforescriptexecute) { return _to SetOnbeforescriptexecute(cx, aOnbeforescriptexecute); } \
  NS_IMETHOD GetOnafterscriptexecute(JSContext* cx, JS::Value *aOnafterscriptexecute) { return _to GetOnafterscriptexecute(cx, aOnafterscriptexecute); } \
  NS_IMETHOD SetOnafterscriptexecute(JSContext* cx, const JS::Value & aOnafterscriptexecute) { return _to SetOnafterscriptexecute(cx, aOnafterscriptexecute); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINLINEEVENTHANDLERS(_to) \
  NS_IMETHOD GetOnabort(JSContext* cx, JS::Value *aOnabort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnabort(cx, aOnabort); } \
  NS_IMETHOD SetOnabort(JSContext* cx, const JS::Value & aOnabort) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnabort(cx, aOnabort); } \
  NS_IMETHOD GetOnblur(JSContext* cx, JS::Value *aOnblur) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnblur(cx, aOnblur); } \
  NS_IMETHOD SetOnblur(JSContext* cx, const JS::Value & aOnblur) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnblur(cx, aOnblur); } \
  NS_IMETHOD GetOncanplay(JSContext* cx, JS::Value *aOncanplay) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOncanplay(cx, aOncanplay); } \
  NS_IMETHOD SetOncanplay(JSContext* cx, const JS::Value & aOncanplay) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOncanplay(cx, aOncanplay); } \
  NS_IMETHOD GetOncanplaythrough(JSContext* cx, JS::Value *aOncanplaythrough) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOncanplaythrough(cx, aOncanplaythrough); } \
  NS_IMETHOD SetOncanplaythrough(JSContext* cx, const JS::Value & aOncanplaythrough) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOncanplaythrough(cx, aOncanplaythrough); } \
  NS_IMETHOD GetOnchange(JSContext* cx, JS::Value *aOnchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnchange(cx, aOnchange); } \
  NS_IMETHOD SetOnchange(JSContext* cx, const JS::Value & aOnchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnchange(cx, aOnchange); } \
  NS_IMETHOD GetOnclick(JSContext* cx, JS::Value *aOnclick) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnclick(cx, aOnclick); } \
  NS_IMETHOD SetOnclick(JSContext* cx, const JS::Value & aOnclick) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnclick(cx, aOnclick); } \
  NS_IMETHOD GetOncontextmenu(JSContext* cx, JS::Value *aOncontextmenu) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOncontextmenu(cx, aOncontextmenu); } \
  NS_IMETHOD SetOncontextmenu(JSContext* cx, const JS::Value & aOncontextmenu) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOncontextmenu(cx, aOncontextmenu); } \
  NS_IMETHOD GetOndblclick(JSContext* cx, JS::Value *aOndblclick) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndblclick(cx, aOndblclick); } \
  NS_IMETHOD SetOndblclick(JSContext* cx, const JS::Value & aOndblclick) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndblclick(cx, aOndblclick); } \
  NS_IMETHOD GetOndrag(JSContext* cx, JS::Value *aOndrag) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndrag(cx, aOndrag); } \
  NS_IMETHOD SetOndrag(JSContext* cx, const JS::Value & aOndrag) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndrag(cx, aOndrag); } \
  NS_IMETHOD GetOndragend(JSContext* cx, JS::Value *aOndragend) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndragend(cx, aOndragend); } \
  NS_IMETHOD SetOndragend(JSContext* cx, const JS::Value & aOndragend) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndragend(cx, aOndragend); } \
  NS_IMETHOD GetOndragenter(JSContext* cx, JS::Value *aOndragenter) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndragenter(cx, aOndragenter); } \
  NS_IMETHOD SetOndragenter(JSContext* cx, const JS::Value & aOndragenter) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndragenter(cx, aOndragenter); } \
  NS_IMETHOD GetOndragleave(JSContext* cx, JS::Value *aOndragleave) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndragleave(cx, aOndragleave); } \
  NS_IMETHOD SetOndragleave(JSContext* cx, const JS::Value & aOndragleave) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndragleave(cx, aOndragleave); } \
  NS_IMETHOD GetOndragover(JSContext* cx, JS::Value *aOndragover) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndragover(cx, aOndragover); } \
  NS_IMETHOD SetOndragover(JSContext* cx, const JS::Value & aOndragover) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndragover(cx, aOndragover); } \
  NS_IMETHOD GetOndragstart(JSContext* cx, JS::Value *aOndragstart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndragstart(cx, aOndragstart); } \
  NS_IMETHOD SetOndragstart(JSContext* cx, const JS::Value & aOndragstart) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndragstart(cx, aOndragstart); } \
  NS_IMETHOD GetOndrop(JSContext* cx, JS::Value *aOndrop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndrop(cx, aOndrop); } \
  NS_IMETHOD SetOndrop(JSContext* cx, const JS::Value & aOndrop) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndrop(cx, aOndrop); } \
  NS_IMETHOD GetOndurationchange(JSContext* cx, JS::Value *aOndurationchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndurationchange(cx, aOndurationchange); } \
  NS_IMETHOD SetOndurationchange(JSContext* cx, const JS::Value & aOndurationchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndurationchange(cx, aOndurationchange); } \
  NS_IMETHOD GetOnemptied(JSContext* cx, JS::Value *aOnemptied) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnemptied(cx, aOnemptied); } \
  NS_IMETHOD SetOnemptied(JSContext* cx, const JS::Value & aOnemptied) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnemptied(cx, aOnemptied); } \
  NS_IMETHOD GetOnended(JSContext* cx, JS::Value *aOnended) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnended(cx, aOnended); } \
  NS_IMETHOD SetOnended(JSContext* cx, const JS::Value & aOnended) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnended(cx, aOnended); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnerror(cx, aOnerror); } \
  NS_IMETHOD GetOnfocus(JSContext* cx, JS::Value *aOnfocus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnfocus(cx, aOnfocus); } \
  NS_IMETHOD SetOnfocus(JSContext* cx, const JS::Value & aOnfocus) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnfocus(cx, aOnfocus); } \
  NS_IMETHOD GetOninput(JSContext* cx, JS::Value *aOninput) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOninput(cx, aOninput); } \
  NS_IMETHOD SetOninput(JSContext* cx, const JS::Value & aOninput) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOninput(cx, aOninput); } \
  NS_IMETHOD GetOninvalid(JSContext* cx, JS::Value *aOninvalid) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOninvalid(cx, aOninvalid); } \
  NS_IMETHOD SetOninvalid(JSContext* cx, const JS::Value & aOninvalid) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOninvalid(cx, aOninvalid); } \
  NS_IMETHOD GetOnkeydown(JSContext* cx, JS::Value *aOnkeydown) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnkeydown(cx, aOnkeydown); } \
  NS_IMETHOD SetOnkeydown(JSContext* cx, const JS::Value & aOnkeydown) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnkeydown(cx, aOnkeydown); } \
  NS_IMETHOD GetOnkeypress(JSContext* cx, JS::Value *aOnkeypress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnkeypress(cx, aOnkeypress); } \
  NS_IMETHOD SetOnkeypress(JSContext* cx, const JS::Value & aOnkeypress) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnkeypress(cx, aOnkeypress); } \
  NS_IMETHOD GetOnkeyup(JSContext* cx, JS::Value *aOnkeyup) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnkeyup(cx, aOnkeyup); } \
  NS_IMETHOD SetOnkeyup(JSContext* cx, const JS::Value & aOnkeyup) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnkeyup(cx, aOnkeyup); } \
  NS_IMETHOD GetOnload(JSContext* cx, JS::Value *aOnload) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnload(cx, aOnload); } \
  NS_IMETHOD SetOnload(JSContext* cx, const JS::Value & aOnload) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnload(cx, aOnload); } \
  NS_IMETHOD GetOnloadeddata(JSContext* cx, JS::Value *aOnloadeddata) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnloadeddata(cx, aOnloadeddata); } \
  NS_IMETHOD SetOnloadeddata(JSContext* cx, const JS::Value & aOnloadeddata) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnloadeddata(cx, aOnloadeddata); } \
  NS_IMETHOD GetOnloadedmetadata(JSContext* cx, JS::Value *aOnloadedmetadata) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnloadedmetadata(cx, aOnloadedmetadata); } \
  NS_IMETHOD SetOnloadedmetadata(JSContext* cx, const JS::Value & aOnloadedmetadata) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnloadedmetadata(cx, aOnloadedmetadata); } \
  NS_IMETHOD GetOnloadstart(JSContext* cx, JS::Value *aOnloadstart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnloadstart(cx, aOnloadstart); } \
  NS_IMETHOD SetOnloadstart(JSContext* cx, const JS::Value & aOnloadstart) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnloadstart(cx, aOnloadstart); } \
  NS_IMETHOD GetOnmousedown(JSContext* cx, JS::Value *aOnmousedown) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmousedown(cx, aOnmousedown); } \
  NS_IMETHOD SetOnmousedown(JSContext* cx, const JS::Value & aOnmousedown) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmousedown(cx, aOnmousedown); } \
  NS_IMETHOD GetOnmousemove(JSContext* cx, JS::Value *aOnmousemove) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmousemove(cx, aOnmousemove); } \
  NS_IMETHOD SetOnmousemove(JSContext* cx, const JS::Value & aOnmousemove) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmousemove(cx, aOnmousemove); } \
  NS_IMETHOD GetOnmouseout(JSContext* cx, JS::Value *aOnmouseout) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmouseout(cx, aOnmouseout); } \
  NS_IMETHOD SetOnmouseout(JSContext* cx, const JS::Value & aOnmouseout) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmouseout(cx, aOnmouseout); } \
  NS_IMETHOD GetOnmouseover(JSContext* cx, JS::Value *aOnmouseover) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmouseover(cx, aOnmouseover); } \
  NS_IMETHOD SetOnmouseover(JSContext* cx, const JS::Value & aOnmouseover) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmouseover(cx, aOnmouseover); } \
  NS_IMETHOD GetOnmouseup(JSContext* cx, JS::Value *aOnmouseup) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmouseup(cx, aOnmouseup); } \
  NS_IMETHOD SetOnmouseup(JSContext* cx, const JS::Value & aOnmouseup) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmouseup(cx, aOnmouseup); } \
  NS_IMETHOD GetOnmozfullscreenchange(JSContext* cx, JS::Value *aOnmozfullscreenchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmozfullscreenchange(cx, aOnmozfullscreenchange); } \
  NS_IMETHOD SetOnmozfullscreenchange(JSContext* cx, const JS::Value & aOnmozfullscreenchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmozfullscreenchange(cx, aOnmozfullscreenchange); } \
  NS_IMETHOD GetOnmozfullscreenerror(JSContext* cx, JS::Value *aOnmozfullscreenerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmozfullscreenerror(cx, aOnmozfullscreenerror); } \
  NS_IMETHOD SetOnmozfullscreenerror(JSContext* cx, const JS::Value & aOnmozfullscreenerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmozfullscreenerror(cx, aOnmozfullscreenerror); } \
  NS_IMETHOD GetOnmozpointerlockchange(JSContext* cx, JS::Value *aOnmozpointerlockchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmozpointerlockchange(cx, aOnmozpointerlockchange); } \
  NS_IMETHOD SetOnmozpointerlockchange(JSContext* cx, const JS::Value & aOnmozpointerlockchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmozpointerlockchange(cx, aOnmozpointerlockchange); } \
  NS_IMETHOD GetOnmozpointerlockerror(JSContext* cx, JS::Value *aOnmozpointerlockerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmozpointerlockerror(cx, aOnmozpointerlockerror); } \
  NS_IMETHOD SetOnmozpointerlockerror(JSContext* cx, const JS::Value & aOnmozpointerlockerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmozpointerlockerror(cx, aOnmozpointerlockerror); } \
  NS_IMETHOD GetOnpause(JSContext* cx, JS::Value *aOnpause) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnpause(cx, aOnpause); } \
  NS_IMETHOD SetOnpause(JSContext* cx, const JS::Value & aOnpause) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnpause(cx, aOnpause); } \
  NS_IMETHOD GetOnplay(JSContext* cx, JS::Value *aOnplay) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnplay(cx, aOnplay); } \
  NS_IMETHOD SetOnplay(JSContext* cx, const JS::Value & aOnplay) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnplay(cx, aOnplay); } \
  NS_IMETHOD GetOnplaying(JSContext* cx, JS::Value *aOnplaying) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnplaying(cx, aOnplaying); } \
  NS_IMETHOD SetOnplaying(JSContext* cx, const JS::Value & aOnplaying) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnplaying(cx, aOnplaying); } \
  NS_IMETHOD GetOnprogress(JSContext* cx, JS::Value *aOnprogress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnprogress(cx, aOnprogress); } \
  NS_IMETHOD SetOnprogress(JSContext* cx, const JS::Value & aOnprogress) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnprogress(cx, aOnprogress); } \
  NS_IMETHOD GetOnratechange(JSContext* cx, JS::Value *aOnratechange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnratechange(cx, aOnratechange); } \
  NS_IMETHOD SetOnratechange(JSContext* cx, const JS::Value & aOnratechange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnratechange(cx, aOnratechange); } \
  NS_IMETHOD GetOnreset(JSContext* cx, JS::Value *aOnreset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnreset(cx, aOnreset); } \
  NS_IMETHOD SetOnreset(JSContext* cx, const JS::Value & aOnreset) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnreset(cx, aOnreset); } \
  NS_IMETHOD GetOnscroll(JSContext* cx, JS::Value *aOnscroll) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnscroll(cx, aOnscroll); } \
  NS_IMETHOD SetOnscroll(JSContext* cx, const JS::Value & aOnscroll) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnscroll(cx, aOnscroll); } \
  NS_IMETHOD GetOnseeked(JSContext* cx, JS::Value *aOnseeked) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnseeked(cx, aOnseeked); } \
  NS_IMETHOD SetOnseeked(JSContext* cx, const JS::Value & aOnseeked) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnseeked(cx, aOnseeked); } \
  NS_IMETHOD GetOnseeking(JSContext* cx, JS::Value *aOnseeking) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnseeking(cx, aOnseeking); } \
  NS_IMETHOD SetOnseeking(JSContext* cx, const JS::Value & aOnseeking) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnseeking(cx, aOnseeking); } \
  NS_IMETHOD GetOnselect(JSContext* cx, JS::Value *aOnselect) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnselect(cx, aOnselect); } \
  NS_IMETHOD SetOnselect(JSContext* cx, const JS::Value & aOnselect) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnselect(cx, aOnselect); } \
  NS_IMETHOD GetOnshow(JSContext* cx, JS::Value *aOnshow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnshow(cx, aOnshow); } \
  NS_IMETHOD SetOnshow(JSContext* cx, const JS::Value & aOnshow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnshow(cx, aOnshow); } \
  NS_IMETHOD GetOnstalled(JSContext* cx, JS::Value *aOnstalled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnstalled(cx, aOnstalled); } \
  NS_IMETHOD SetOnstalled(JSContext* cx, const JS::Value & aOnstalled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnstalled(cx, aOnstalled); } \
  NS_IMETHOD GetOnsubmit(JSContext* cx, JS::Value *aOnsubmit) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnsubmit(cx, aOnsubmit); } \
  NS_IMETHOD SetOnsubmit(JSContext* cx, const JS::Value & aOnsubmit) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnsubmit(cx, aOnsubmit); } \
  NS_IMETHOD GetOnsuspend(JSContext* cx, JS::Value *aOnsuspend) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnsuspend(cx, aOnsuspend); } \
  NS_IMETHOD SetOnsuspend(JSContext* cx, const JS::Value & aOnsuspend) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnsuspend(cx, aOnsuspend); } \
  NS_IMETHOD GetOntimeupdate(JSContext* cx, JS::Value *aOntimeupdate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOntimeupdate(cx, aOntimeupdate); } \
  NS_IMETHOD SetOntimeupdate(JSContext* cx, const JS::Value & aOntimeupdate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOntimeupdate(cx, aOntimeupdate); } \
  NS_IMETHOD GetOnvolumechange(JSContext* cx, JS::Value *aOnvolumechange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnvolumechange(cx, aOnvolumechange); } \
  NS_IMETHOD SetOnvolumechange(JSContext* cx, const JS::Value & aOnvolumechange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnvolumechange(cx, aOnvolumechange); } \
  NS_IMETHOD GetOnwaiting(JSContext* cx, JS::Value *aOnwaiting) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnwaiting(cx, aOnwaiting); } \
  NS_IMETHOD SetOnwaiting(JSContext* cx, const JS::Value & aOnwaiting) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnwaiting(cx, aOnwaiting); } \
  NS_IMETHOD GetOnwheel(JSContext* cx, JS::Value *aOnwheel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnwheel(cx, aOnwheel); } \
  NS_IMETHOD SetOnwheel(JSContext* cx, const JS::Value & aOnwheel) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnwheel(cx, aOnwheel); } \
  NS_IMETHOD GetOncopy(JSContext* cx, JS::Value *aOncopy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOncopy(cx, aOncopy); } \
  NS_IMETHOD SetOncopy(JSContext* cx, const JS::Value & aOncopy) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOncopy(cx, aOncopy); } \
  NS_IMETHOD GetOncut(JSContext* cx, JS::Value *aOncut) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOncut(cx, aOncut); } \
  NS_IMETHOD SetOncut(JSContext* cx, const JS::Value & aOncut) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOncut(cx, aOncut); } \
  NS_IMETHOD GetOnpaste(JSContext* cx, JS::Value *aOnpaste) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnpaste(cx, aOnpaste); } \
  NS_IMETHOD SetOnpaste(JSContext* cx, const JS::Value & aOnpaste) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnpaste(cx, aOnpaste); } \
  NS_IMETHOD GetOnbeforescriptexecute(JSContext* cx, JS::Value *aOnbeforescriptexecute) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnbeforescriptexecute(cx, aOnbeforescriptexecute); } \
  NS_IMETHOD SetOnbeforescriptexecute(JSContext* cx, const JS::Value & aOnbeforescriptexecute) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnbeforescriptexecute(cx, aOnbeforescriptexecute); } \
  NS_IMETHOD GetOnafterscriptexecute(JSContext* cx, JS::Value *aOnafterscriptexecute) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnafterscriptexecute(cx, aOnafterscriptexecute); } \
  NS_IMETHOD SetOnafterscriptexecute(JSContext* cx, const JS::Value & aOnafterscriptexecute) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnafterscriptexecute(cx, aOnafterscriptexecute); } 

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
NS_IMETHODIMP nsInlineEventHandlers::GetOnabort(JSContext* cx, JS::Value *aOnabort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnabort(JSContext* cx, const JS::Value & aOnabort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onblur; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnblur(JSContext* cx, JS::Value *aOnblur)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnblur(JSContext* cx, const JS::Value & aOnblur)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval oncanplay; */
NS_IMETHODIMP nsInlineEventHandlers::GetOncanplay(JSContext* cx, JS::Value *aOncanplay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOncanplay(JSContext* cx, const JS::Value & aOncanplay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval oncanplaythrough; */
NS_IMETHODIMP nsInlineEventHandlers::GetOncanplaythrough(JSContext* cx, JS::Value *aOncanplaythrough)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOncanplaythrough(JSContext* cx, const JS::Value & aOncanplaythrough)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onchange; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnchange(JSContext* cx, JS::Value *aOnchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnchange(JSContext* cx, const JS::Value & aOnchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onclick; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnclick(JSContext* cx, JS::Value *aOnclick)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnclick(JSContext* cx, const JS::Value & aOnclick)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval oncontextmenu; */
NS_IMETHODIMP nsInlineEventHandlers::GetOncontextmenu(JSContext* cx, JS::Value *aOncontextmenu)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOncontextmenu(JSContext* cx, const JS::Value & aOncontextmenu)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondblclick; */
NS_IMETHODIMP nsInlineEventHandlers::GetOndblclick(JSContext* cx, JS::Value *aOndblclick)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOndblclick(JSContext* cx, const JS::Value & aOndblclick)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondrag; */
NS_IMETHODIMP nsInlineEventHandlers::GetOndrag(JSContext* cx, JS::Value *aOndrag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOndrag(JSContext* cx, const JS::Value & aOndrag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondragend; */
NS_IMETHODIMP nsInlineEventHandlers::GetOndragend(JSContext* cx, JS::Value *aOndragend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOndragend(JSContext* cx, const JS::Value & aOndragend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondragenter; */
NS_IMETHODIMP nsInlineEventHandlers::GetOndragenter(JSContext* cx, JS::Value *aOndragenter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOndragenter(JSContext* cx, const JS::Value & aOndragenter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondragleave; */
NS_IMETHODIMP nsInlineEventHandlers::GetOndragleave(JSContext* cx, JS::Value *aOndragleave)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOndragleave(JSContext* cx, const JS::Value & aOndragleave)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondragover; */
NS_IMETHODIMP nsInlineEventHandlers::GetOndragover(JSContext* cx, JS::Value *aOndragover)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOndragover(JSContext* cx, const JS::Value & aOndragover)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondragstart; */
NS_IMETHODIMP nsInlineEventHandlers::GetOndragstart(JSContext* cx, JS::Value *aOndragstart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOndragstart(JSContext* cx, const JS::Value & aOndragstart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondrop; */
NS_IMETHODIMP nsInlineEventHandlers::GetOndrop(JSContext* cx, JS::Value *aOndrop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOndrop(JSContext* cx, const JS::Value & aOndrop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondurationchange; */
NS_IMETHODIMP nsInlineEventHandlers::GetOndurationchange(JSContext* cx, JS::Value *aOndurationchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOndurationchange(JSContext* cx, const JS::Value & aOndurationchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onemptied; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnemptied(JSContext* cx, JS::Value *aOnemptied)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnemptied(JSContext* cx, const JS::Value & aOnemptied)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onended; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnended(JSContext* cx, JS::Value *aOnended)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnended(JSContext* cx, const JS::Value & aOnended)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onerror; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnerror(JSContext* cx, JS::Value *aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnerror(JSContext* cx, const JS::Value & aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onfocus; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnfocus(JSContext* cx, JS::Value *aOnfocus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnfocus(JSContext* cx, const JS::Value & aOnfocus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval oninput; */
NS_IMETHODIMP nsInlineEventHandlers::GetOninput(JSContext* cx, JS::Value *aOninput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOninput(JSContext* cx, const JS::Value & aOninput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval oninvalid; */
NS_IMETHODIMP nsInlineEventHandlers::GetOninvalid(JSContext* cx, JS::Value *aOninvalid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOninvalid(JSContext* cx, const JS::Value & aOninvalid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onkeydown; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnkeydown(JSContext* cx, JS::Value *aOnkeydown)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnkeydown(JSContext* cx, const JS::Value & aOnkeydown)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onkeypress; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnkeypress(JSContext* cx, JS::Value *aOnkeypress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnkeypress(JSContext* cx, const JS::Value & aOnkeypress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onkeyup; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnkeyup(JSContext* cx, JS::Value *aOnkeyup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnkeyup(JSContext* cx, const JS::Value & aOnkeyup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onload; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnload(JSContext* cx, JS::Value *aOnload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnload(JSContext* cx, const JS::Value & aOnload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onloadeddata; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnloadeddata(JSContext* cx, JS::Value *aOnloadeddata)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnloadeddata(JSContext* cx, const JS::Value & aOnloadeddata)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onloadedmetadata; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnloadedmetadata(JSContext* cx, JS::Value *aOnloadedmetadata)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnloadedmetadata(JSContext* cx, const JS::Value & aOnloadedmetadata)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onloadstart; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnloadstart(JSContext* cx, JS::Value *aOnloadstart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnloadstart(JSContext* cx, const JS::Value & aOnloadstart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmousedown; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnmousedown(JSContext* cx, JS::Value *aOnmousedown)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnmousedown(JSContext* cx, const JS::Value & aOnmousedown)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmousemove; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnmousemove(JSContext* cx, JS::Value *aOnmousemove)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnmousemove(JSContext* cx, const JS::Value & aOnmousemove)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmouseout; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnmouseout(JSContext* cx, JS::Value *aOnmouseout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnmouseout(JSContext* cx, const JS::Value & aOnmouseout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmouseover; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnmouseover(JSContext* cx, JS::Value *aOnmouseover)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnmouseover(JSContext* cx, const JS::Value & aOnmouseover)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmouseup; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnmouseup(JSContext* cx, JS::Value *aOnmouseup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnmouseup(JSContext* cx, const JS::Value & aOnmouseup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmozfullscreenchange; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnmozfullscreenchange(JSContext* cx, JS::Value *aOnmozfullscreenchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnmozfullscreenchange(JSContext* cx, const JS::Value & aOnmozfullscreenchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmozfullscreenerror; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnmozfullscreenerror(JSContext* cx, JS::Value *aOnmozfullscreenerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnmozfullscreenerror(JSContext* cx, const JS::Value & aOnmozfullscreenerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmozpointerlockchange; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnmozpointerlockchange(JSContext* cx, JS::Value *aOnmozpointerlockchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnmozpointerlockchange(JSContext* cx, const JS::Value & aOnmozpointerlockchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmozpointerlockerror; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnmozpointerlockerror(JSContext* cx, JS::Value *aOnmozpointerlockerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnmozpointerlockerror(JSContext* cx, const JS::Value & aOnmozpointerlockerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onpause; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnpause(JSContext* cx, JS::Value *aOnpause)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnpause(JSContext* cx, const JS::Value & aOnpause)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onplay; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnplay(JSContext* cx, JS::Value *aOnplay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnplay(JSContext* cx, const JS::Value & aOnplay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onplaying; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnplaying(JSContext* cx, JS::Value *aOnplaying)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnplaying(JSContext* cx, const JS::Value & aOnplaying)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onprogress; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnprogress(JSContext* cx, JS::Value *aOnprogress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnprogress(JSContext* cx, const JS::Value & aOnprogress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onratechange; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnratechange(JSContext* cx, JS::Value *aOnratechange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnratechange(JSContext* cx, const JS::Value & aOnratechange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onreset; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnreset(JSContext* cx, JS::Value *aOnreset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnreset(JSContext* cx, const JS::Value & aOnreset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onscroll; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnscroll(JSContext* cx, JS::Value *aOnscroll)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnscroll(JSContext* cx, const JS::Value & aOnscroll)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onseeked; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnseeked(JSContext* cx, JS::Value *aOnseeked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnseeked(JSContext* cx, const JS::Value & aOnseeked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onseeking; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnseeking(JSContext* cx, JS::Value *aOnseeking)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnseeking(JSContext* cx, const JS::Value & aOnseeking)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onselect; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnselect(JSContext* cx, JS::Value *aOnselect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnselect(JSContext* cx, const JS::Value & aOnselect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onshow; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnshow(JSContext* cx, JS::Value *aOnshow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnshow(JSContext* cx, const JS::Value & aOnshow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onstalled; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnstalled(JSContext* cx, JS::Value *aOnstalled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnstalled(JSContext* cx, const JS::Value & aOnstalled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onsubmit; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnsubmit(JSContext* cx, JS::Value *aOnsubmit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnsubmit(JSContext* cx, const JS::Value & aOnsubmit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onsuspend; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnsuspend(JSContext* cx, JS::Value *aOnsuspend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnsuspend(JSContext* cx, const JS::Value & aOnsuspend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ontimeupdate; */
NS_IMETHODIMP nsInlineEventHandlers::GetOntimeupdate(JSContext* cx, JS::Value *aOntimeupdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOntimeupdate(JSContext* cx, const JS::Value & aOntimeupdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onvolumechange; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnvolumechange(JSContext* cx, JS::Value *aOnvolumechange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnvolumechange(JSContext* cx, const JS::Value & aOnvolumechange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onwaiting; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnwaiting(JSContext* cx, JS::Value *aOnwaiting)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnwaiting(JSContext* cx, const JS::Value & aOnwaiting)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onwheel; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnwheel(JSContext* cx, JS::Value *aOnwheel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnwheel(JSContext* cx, const JS::Value & aOnwheel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval oncopy; */
NS_IMETHODIMP nsInlineEventHandlers::GetOncopy(JSContext* cx, JS::Value *aOncopy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOncopy(JSContext* cx, const JS::Value & aOncopy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval oncut; */
NS_IMETHODIMP nsInlineEventHandlers::GetOncut(JSContext* cx, JS::Value *aOncut)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOncut(JSContext* cx, const JS::Value & aOncut)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onpaste; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnpaste(JSContext* cx, JS::Value *aOnpaste)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnpaste(JSContext* cx, const JS::Value & aOnpaste)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onbeforescriptexecute; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnbeforescriptexecute(JSContext* cx, JS::Value *aOnbeforescriptexecute)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnbeforescriptexecute(JSContext* cx, const JS::Value & aOnbeforescriptexecute)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onafterscriptexecute; */
NS_IMETHODIMP nsInlineEventHandlers::GetOnafterscriptexecute(JSContext* cx, JS::Value *aOnafterscriptexecute)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInlineEventHandlers::SetOnafterscriptexecute(JSContext* cx, const JS::Value & aOnafterscriptexecute)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIInlineEventHandlers_h__ */

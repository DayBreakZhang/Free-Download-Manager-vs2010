/*
 * We took some parts of code from Adblock Plus.
 *
 * The Initial Developer of the Original Code is
 * Wladimir Palant.
 * Portions created by the Initial Developer are Copyright (C) 2006-2010
 * the Initial Developer. All Rights Reserved.

 The functions we took are: ProcessCSSData, LoadTabCss,
  onTabClick, ShowTab, HideTab, positionTab, intersectRect,
  getElementPosition. We did minor changes in some of these functions.
 *
 *
*/

var freeDldMgr_fmb_rkStgs = null;
var freeDldMgr_fmb_Initialized = false;
var freeDldMgr_fmb_objTabElement = null;
var freeDldMgr_fmb_CurrentElement = null;
var freeDldMgr_fmb_OtherSwfUrls = null;
var freeDldMgr_fmb_OtherFlashVars = null;
var freeDldMgr_fmb_ImageDataURI = null;

freeDldMgr_fmb_Initialize ();

function freeDldMgr_fmb_Initialize ()
{
  var ext = Components.classes["@freedownloadmanager.org/FDMFirefoxExtension;1"].createInstance ();
  ext = ext.QueryInterface (Components.interfaces.IFDMFirefoxExtension);
  ext.MakeSureFlvSniffDllLoaded ();

  freeDldMgr_fmb_rkStgs = Components.classes["@mozilla.org/windows-registry-key;1"].createInstance (Components.interfaces.nsIWindowsRegKey);
  freeDldMgr_fmb_rkStgs.open (freeDldMgr_fmb_rkStgs.ROOT_KEY_CURRENT_USER, 
    "Software\\FreeDownloadManager.ORG\\Free Download Manager\\Settings\\FlvMonitoring",
    freeDldMgr_fmb_rkStgs.ACCESS_ALL);

  freeDldMgr_fmb_LoadTabCss ();

  /*if (freeDldMgr_fmb_ImageDataURI == null)
    freeDldMgr_fmb_ImageDataURI = freeDldMgr_fmb_generateDataURI (freeDldMgr_fmb_openMyFile ("chrome/skin/fdm.png"));*/
}

function freeDldMgr_fmb_ProcessCSSData (data)
{
  var styleService = Components.classes["@mozilla.org/content/style-sheet-service;1"]
                        .getService(Components.interfaces.nsIStyleSheetService);
  let ioService = Components.classes["@mozilla.org/network/io-service;1"].getService(Ci.nsIIOService);
  let url = ioService.newURI("chrome://fdm_ffext/content/fdm_objtabs.css", null, null);
  styleService.loadAndRegisterSheet(url, Components.interfaces.nsIStyleSheetService.USER_SHEET);
  window.addEventListener("unload",  freeDldMgr_fmbtn_unload, false);
  freeDldMgr_fmb_Initialized = true;
}

function freeDldMgr_fmbtn_unload (ev)
{
  var styleService = Components.classes["@mozilla.org/content/style-sheet-service;1"]
                        .getService(Components.interfaces.nsIStyleSheetService);
 let ioService = Components.classes["@mozilla.org/network/io-service;1"].getService(Ci.nsIIOService);
 let url = ioService.newURI("chrome://fdm_ffext/content/fdm_objtabs.css", null, null);
 if(styleService.sheetRegistered(u, Components.interfaces.nsIStyleSheetService.USER_SHEET))
  styleService.unregisterSheet(u, Components.interfaces.nsIStyleSheetService.USER_SHEET);
 window.removeEventListener("unload",  freeDldMgr_fmbtn_unload);
}

function freeDldMgr_fmb_LoadTabCss ()
{
  if (freeDldMgr_fmb_Initialized)
    return;
  var request = Components.classes["@mozilla.org/xmlextras/xmlhttprequest;1"].createInstance(Ci.nsIJSXMLHttpRequest);
  request.open("GET", "chrome://fdm_ffext/content/fdm_objtabs.css");
  request.overrideMimeType("text/plain");
  request.onload = function () {freeDldMgr_fmb_ProcessCSSData (request.responseText);}
  request.send (null);
}

function freeDldMgr_fmb_getElementParam (elem, paramName)
{
  var vars;

  try {
    vars = elem.getAttribute (paramName);
  } catch (e) {}

  if ((vars == null || vars == "") && elem.hasChildNodes ())
  {
    try {
     for (var i = 0; i < elem.childNodes.length; i++) 
     {
       try{
        if (elem.childNodes[i].getAttribute("name").toLowerCase() == paramName)
        {
          vars = elem.childNodes[i].getAttribute("value");
          break;
        }
       }catch(e){}
     }
    }catch(e){}
  }

  if ((vars == null || vars == "") && elem.parentNode && elem.parentNode.hasChildNodes ())
  {
    try {
     for (var i = 0; i < elem.parentNode.childNodes.length; i++) 
     {
       try{
        if (elem.parentNode.childNodes[i].getAttribute("name").toLowerCase() == paramName)
        {
          vars = elem.parentNode.childNodes[i].getAttribute("value");
          break;
        }
       }catch(e){}
     }
    }catch(e){}
  }

  return vars ? vars : "";
}

function freeDldMgr_fmb_getFlashElementSwfUrl (elem)
{
  var swfSrc;
  try {swfSrc = elem.data;}catch (e){}
  if (swfSrc == null || swfSrc == "")
  {
    try {swfSrc = elem.src;}catch (e){}
  }
  if (swfSrc == null || swfSrc == "")
    swfSrc = freeDldMgr_fmb_getElementParam (elem, "src");
  if (swfSrc == null || swfSrc == "")
    swfSrc = freeDldMgr_fmb_getElementParam (elem, "movie");
  return swfSrc;
}

function freeDldMgr_fmb_isFlashObject (elem)
{
  return /x-shockwave-flash/i.test (freeDldMgr_fmb_getElementParam (elem, "type")) ||
  	freeDldMgr_fmb_getFlashElementSwfUrl (elem) != "";
}

function freeDldMgr_fmb_getOtherSwfUrls_2 (coll, elemExcept)
{
  for (var i = 0; i < coll.length; i++)
  {
    var el = coll [i];
    if (!el)
      continue;
    if (el != elemExcept && freeDldMgr_fmb_isFlashObject (el))
    {
      freeDldMgr_fmb_OtherSwfUrls += freeDldMgr_fmb_getFlashElementSwfUrl (el);
      freeDldMgr_fmb_OtherSwfUrls += "\n";
      freeDldMgr_fmb_OtherFlashVars += freeDldMgr_fmb_getElementParam (el, "flashvars");
      freeDldMgr_fmb_OtherFlashVars += "\n";
    }
  }
}

function freeDldMgr_fmb_getOtherSwfUrls_impl (doc, elem)
{
  freeDldMgr_fmb_getOtherSwfUrls_2 (doc.embeds, elem);
  freeDldMgr_fmb_getOtherSwfUrls_2 (doc.getElementsByTagName ("object"), elem);
  var frames = doc.defaultView.frames;
  for (var i = 0; i < frames.length; i++)
    freeDldMgr_fmb_getOtherSwfUrls_impl (frames [i].document, elem);
}

function freeDldMgr_fmb_getOtherSwfUrls (elem)
{
  freeDldMgr_fmb_OtherSwfUrls = ""; 
  freeDldMgr_fmb_OtherFlashVars = "";
  //var doc = elem.ownerDocument;
  freeDldMgr_fmb_getOtherSwfUrls_impl (window.content.document, elem);
}

function freeDldMgr_fmb_isVideoFlash (elem)
{
  var swfSrc = freeDldMgr_fmb_getFlashElementSwfUrl (elem);
  var flashVars = freeDldMgr_fmb_getElementParam (elem, "flashvars");
  var frameUrl = elem.ownerDocument.URL;
  var webPageUrl = window.content.document.URL;
  if (frameUrl == webPageUrl)
    frameUrl = "";
  freeDldMgr_fmb_getOtherSwfUrls (elem);
  var otherSwfUrls = freeDldMgr_fmb_OtherSwfUrls;
  var otherFlashVars = freeDldMgr_fmb_OtherFlashVars;
  return freeDldMgr_FDM.IsVideoFlash (webPageUrl, frameUrl, swfSrc, 
      flashVars, otherSwfUrls, otherFlashVars);
}

function freeDldMgr_fmb_onTabClick (ev)
{
  if (!ev.isTrusted)
    return;
  if (ev.type == "click" && ev.button == 0)
  {
    ev.preventDefault ();
    ev.stopPropagation ();
    var swfSrc = freeDldMgr_fmb_getFlashElementSwfUrl (freeDldMgr_fmb_CurrentElement);
    var flashVars = freeDldMgr_fmb_getElementParam (freeDldMgr_fmb_CurrentElement, "flashvars");
    var frameUrl = freeDldMgr_fmb_CurrentElement.ownerDocument.URL;
    var webPageUrl = window.content.document.URL;
    if (frameUrl == webPageUrl)
      frameUrl = "";
    freeDldMgr_fmb_getOtherSwfUrls (freeDldMgr_fmb_CurrentElement);
    var otherSwfUrls = freeDldMgr_fmb_OtherSwfUrls;
    var otherFlashVars = freeDldMgr_fmb_OtherFlashVars;
    //alert (freeDldMgr_fmb_CurrentElement.ownerDocument.URL);
    //alert (freeDldMgr_fmb_CurrentElement.ownerDocument.defaultView.parent.document.URL);
    freeDldMgr_fmb_HideButton ();
    //freeDldMgr_dlURL (swfSrc);
    freeDldMgr_FDM.CreateVideoDownloadFromUrl3 (webPageUrl, frameUrl, swfSrc, 
      flashVars, otherSwfUrls, otherFlashVars);
  }
}

function freeDldMgr_fmb_ShowTab (elem)
{
  freeDldMgr_fmb_HideTab ();
  freeDldMgr_fmb_CurrentElement = elem;
  var doc = elem.ownerDocument.defaultView.top.document;

  freeDldMgr_fmb_objTabElement = doc.createElementNS ("http://www.w3.org/1999/xhtml", "a");
  freeDldMgr_fmb_objTabElement.setAttribute ("href", "");
  freeDldMgr_fmb_objTabElement.setAttribute ("class", "fdm_ffext_CLASSVISIBLETOP");
  freeDldMgr_fmb_objTabElement.style.setProperty ("opacity", "1", "important");
  freeDldMgr_fmb_objTabElement.addEventListener ("click", freeDldMgr_fmb_onTabClick, true);
  
  var el2 = doc.createElementNS ("http://www.w3.org/1999/xhtml", "img");
  el2.setAttribute ("src", "data:image/png,%89PNG%0D%0A%1A%0A%00%00%00%0DIHDR%00%00%00%10%00%00%00%10%08%02%00%00%00%90%91h6%00%00%00%01sRGB%00%AE%CE%1C%E9%00%00%00%04gAMA%00%00%B1%8F%0B%FCa%05%00%00%00%20cHRM%00%00z%26%00%00%80%84%00%00%FA%00%00%00%80%E8%00%00u0%00%00%EA%60%00%00%3A%98%00%00%17p%9C%BAQ%3C%00%00%01%01IDAT8O%8D%911%0E%C20%0CE%CD-8%40N%C0%CC%8AT%0EQ1%23%85%0B0%B1%C0%DC%BDB%EA%80%188%00%20%B8%01C%87n%9C%82%AEL%E6%3BN%D3%40%D5%0A%CB%AA%12%E7%3F%7F%A7%1913E1%DF%D1%F5%7DG%C1%BCffL%97u%7C%E8%D6%004%92-%9B%15%DB%92-%CB%D7%9C%99N5*%A8%C7%E1%01%CA'%C7G-%D2%90%3D%8C%00%B4!Q%BB%DE%9B%C1p%F3%E7%13%00%A2.E%5DUUQ%1C%BE%86p%1B%14qd%AD%05%40%01%C0%3E%00P%84%EC%05h%99%FF%E7%F0%F4%26%01%40oJ%09%19%FB%B4%23MoD%8EA%A2%AA%01u%C6%19%BE%A1%E2%01%B9xN%9Ei0%81%1D%B0g%1B3r%E9%00(%93p%82%84N%13k1o%7C%3C%A0O%01%A0%9B%A2~%92a%A3L%0B%A8%8Fb%AD(R%EB%ED%BF%00%7D%2C%C5%F4%17%85%DE%8B%26D%D0%7DTO%A6~%92%1F%C1%10%00%93n%BB%0Fg%7D%C9%E5%DA%24_%06%00%00%00%00IEND%AEB%60%82");
  el2.style.setProperty ("float", "left", "important");
  el2.style.setProperty ("padding-right", "3px", "important");
  el2.setAttribute ("align", "absmiddle");
  el2.setAttribute ("border", "0");
  el2.setAttribute ("hspace", "0");
  el2.setAttribute ("vspace", "0");

  var el3 = doc.createElementNS ("http://www.w3.org/1999/xhtml", "span");
  el3.textContent = freeDldMgr_FDM.GetLngString ("dlbyfdm"); //"Download by FDM";
  el3.setAttribute ("class", "");
  el3.setAttribute ("style", "");

  freeDldMgr_fmb_objTabElement.appendChild (el2);  
  freeDldMgr_fmb_objTabElement.appendChild (el3);  

  doc.documentElement.appendChild (freeDldMgr_fmb_objTabElement);
  freeDldMgr_fmb_positionTabByTimer ();
}

function freeDldMgr_fmb_openMyFile (path)
{
  var em = Components.classes["@mozilla.org/extensions/manager;1"].
         getService(Components.interfaces.nsIExtensionManager);
  return em.getInstallLocation ("fdm_ffext@freedownloadmanager.org").
  	getItemFile ("fdm_ffext@freedownloadmanager.org", path);
}

function freeDldMgr_fmb_generateDataURI (file) 
{
  var contentType = Components.classes["@mozilla.org/mime;1"]
                              .getService(Components.interfaces.nsIMIMEService)
                              .getTypeFromFile(file);
  var inputStream = Components.classes["@mozilla.org/network/file-input-stream;1"]
                              .createInstance(Components.interfaces.nsIFileInputStream);
  inputStream.init (file, 0x01, 0600, 0);
  var stream = Components.classes["@mozilla.org/binaryinputstream;1"]
                         .createInstance(Components.interfaces.nsIBinaryInputStream);
  stream.setInputStream(inputStream);
  var encoded = btoa(stream.readBytes(stream.available()));
  return "data:" + contentType + ";base64," + encoded;
}


function freeDldMgr_fmb_positionTabByTimer ()
{
  if (!freeDldMgr_fmb_objTabElement)
    return;
  freeDldMgr_fmb_positionTab ();
  if (freeDldMgr_fmb_objTabElement)
    setTimeout (function () {freeDldMgr_fmb_positionTabByTimer();}, 100);
}

function freeDldMgr_fmb_HideTab ()
{
  if (!freeDldMgr_fmb_objTabElement)
    return;
  var objtab = freeDldMgr_fmb_objTabElement;
  freeDldMgr_fmb_objTabElement = null;
  freeDldMgr_fmb_CurrentElement = null;
  try {
    objtab.parentNode.removeChild (objtab);
  } catch (e) {}
}

function freeDldMgr_fmb_positionTab ()
{
  var objRect = freeDldMgr_fmb_getElementPosition (freeDldMgr_fmb_CurrentElement); 
  var className = "fdm_ffext_CLASSVISIBLETOP";
  //var left = objRect.right - freeDldMgr_fmb_objTabElement.offsetWidth;
  var left = objRect.left;
  var top = objRect.top - freeDldMgr_fmb_objTabElement.offsetHeight;
  if (top < 0)
  {
    top = objRect.bottom;
    className = "fdm_ffext_CLASSVISIBLEBOTTOM";
  }
  /*var top = objRect.bottom;
  className = "fdm_ffext_CLASSVISIBLEBOTTOM";
  //var wnd = freeDldMgr_fmb_CurrentElement.ownerDocument.defaultView;
  //var doc = wnd.document;
  var wnd = window;
  var doc = window.content.document;
  var wndH = doc.documentElement.clientHeight;
  if (doc.compatMode == "BackCompat")
    wndH = doc.documentElement.offsetHeight - wnd.scrollMaxY;
  if (top + freeDldMgr_fmb_objTabElement.offsetHeight >= wndH)
  {
    top = objRect.top - freeDldMgr_fmb_objTabElement.offsetHeight;
    className = "fdm_ffext_CLASSVISIBLETOP";
  }*/
  if (freeDldMgr_fmb_objTabElement.style.left != left + "px")
    freeDldMgr_fmb_objTabElement.style.setProperty ("left", left + "px", "important");
  if (freeDldMgr_fmb_objTabElement.style.top != top + "px")
    freeDldMgr_fmb_objTabElement.style.setProperty ("top", top + "px", "important");
  if (freeDldMgr_fmb_objTabElement.getAttribute ("class") != className)
    freeDldMgr_fmb_objTabElement.setAttribute ("class", className);
}

function freeDldMgr_fmb_intersectRect (rect, wnd)
{
  var doc = wnd.document;
  var wndWidth = doc.documentElement.clientWidth;
  var wndHeight = doc.documentElement.clientHeight;
  if (doc.compatMode == "BackCompat")
    wndHeight = doc.documentElement.offsetHeight - wnd.scrollMaxY;
  rect.left = Math.max (rect.left, 0);
  rect.top = Math.max (rect.top, 0);
  rect.right = Math.min (rect.right, wndWidth);
  rect.bottom = Math.min (rect.bottom, wndHeight);
}

function freeDldMgr_fmb_getElementPosition (elem)
{
  var rect = elem.getBoundingClientRect ();
  let wnd = elem.ownerDocument.defaultView;
  var offsets = [0, 0, 0, 0];
  var style = wnd.getComputedStyle (elem, null);
  offsets [0] = parseFloat (style.borderLeftWidth) + parseFloat (style.paddingLeft);
  offsets [1] = parseFloat (style.borderTopWidth) + parseFloat (style.paddingTop);
  offsets [2] = parseFloat (style.borderRightWidth) + parseFloat (style.paddingRight);
  offsets [3] = parseFloat (style.borderBottomWidth) + parseFloat (style.paddingBottom);
  rect = {left: rect.left + offsets [0], top: rect.top + offsets [1], 
    right: rect.right - offsets [2], bottom: rect.bottom - offsets [3]};
  while (true)
  {
    freeDldMgr_fmb_intersectRect (rect, wnd);
    if (!wnd.frameElement)
      break;
    var frameElem = wnd.frameElement;
    wnd = frameElem.ownerDocument.defaultView;
    var frameRect = frameElem.getBoundingClientRect ();
    var frameStyle = wnd.getComputedStyle (frameElem, null);
    var relLeft = frameRect.left + parseFloat (frameStyle.borderLeftWidth) + parseFloat (frameStyle.paddingLeft);
    var relTop = frameRect.top + parseFloat (frameStyle.borderTopWidth) + parseFloat (frameStyle.paddingTop);
    rect.left += relLeft;
    rect.right += relLeft;
    rect.top += relTop;
    rect.bottom += relTop;
  }
  return rect;
}

function freeDldMgr_fmb_isEnabledInStgs ()
{
  if (!freeDldMgr_fmb_rkStgs.hasValue ("ShowDownloadItBtn"))
    return true;
  return freeDldMgr_fmb_rkStgs.readIntValue ("ShowDownloadItBtn");
} 

function freeDldMgr_fmb_setEnabledInStgs (bEn)
{
  freeDldMgr_fmb_rkStgs.writeIntValue ("ShowDownloadItBtn", bEn); 
}

function freeDldMgr_fmb_isElemBtnPart (elem)
{
  if (elem == freeDldMgr_fmb_objTabElement)
    return true;
  if (elem.parentNode)
    return freeDldMgr_fmb_isElemBtnPart (elem.parentNode);
}

function freeDldMgr_fmb_ShowButton (elemFlash)
{
    freeDldMgr_fmb_ShowTab (elemFlash);
}

function freeDldMgr_fmb_HideButton ()
{
    freeDldMgr_fmb_HideTab ();
}

function freeDldMgr_fmb_onMouseEvent_InElement (ev)
{
  ev = ev || window.event;
  var elem = ev.target || ev.srcElement;

  if (freeDldMgr_fmb_isElemBtnPart (elem))
    return; 

  if (elem.tagName.toLowerCase () != "embed" && 
  	elem.tagName.toLowerCase() != "object" && 
  	elem.tagName.toLowerCase() != "video")
  {
    freeDldMgr_fmb_HideButton ();
    return;
  }

  if (!elem.parentNode)
  {
    freeDldMgr_fmb_HideButton ();
    return;
  }

  if (freeDldMgr_fmb_isEnabledInStgs () && 
  	freeDldMgr_fmb_isFlashObject (elem) && 
  	freeDldMgr_fmb_isVideoFlash (elem))
    freeDldMgr_fmb_ShowButton (elem);
}

function freeDldMgr_fmb_onMouseMove (ev)
{
  freeDldMgr_fmb_onMouseEvent_InElement (ev);
}

function freeDldMgr_fmb_onMouseOver (ev)
{
  freeDldMgr_fmb_onMouseEvent_InElement (ev);
}

function freeDldMgr_fmb_onMouseOut (ev)
{
}

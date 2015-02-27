var freeDldMgr_FDM = Components.classes["@freedownloadmanager.org/FDMForFirefox;1"].createInstance ();
freeDldMgr_FDM = freeDldMgr_FDM.QueryInterface (Components.interfaces.IFDMForFirefox);

var freeDldMgr_hoverElement = null;
var freeDldMgr_lastClickCaptureTime = 0;

function freeDldMgr_gatherCookieForHost (_host, _cookieWeHave)
{
   var freeDldMgr_cookieManager =
      Components.classes["@mozilla.org/cookiemanager;1"].getService(Components.interfaces.nsICookieManager);
   var _cookie = _cookieWeHave;

   for (var iter = freeDldMgr_cookieManager.enumerator; iter.hasMoreElements();) 
   {
      if ((objCookie = iter.getNext()) instanceof Components.interfaces.nsICookie) 
      {
        var cookieHost = objCookie.host;
        if (cookieHost.charAt(0) == ".")
          cookieHost = cookieHost.substring (1);

        if (cookieHost == _host || _host.indexOf ("." + cookieHost) != -1)
        {
	        if (_cookie.indexOf (objCookie.name + "=" + objCookie.value) == -1)
	        {
		        if (_cookie.length)
		        	_cookie += "; ";
	        	_cookie += objCookie.name + "=" + objCookie.value;
	        }
	}
      }
   }

   return _cookie;
}


function freeDldMgr_dlURL (strUrl)
{
  var url = Components.classes["@freedownloadmanager.org/FDMUrl;1"].createInstance ();
  url = url.QueryInterface (Components.interfaces.IFDMUrl);
  url.Url = strUrl;
  url.Referer = document.commandDispatcher.focusedWindow.document.URL;
  url.Cookies = freeDldMgr_gatherCookieForHost (document.commandDispatcher.focusedWindow.document.location.hostname, document.commandDispatcher.focusedWindow.document.cookie);
  url.UserAgent = window.navigator.userAgent;

  var urlRcvr = Components.classes["@freedownloadmanager.org/FDMUrlReceiver;1"].createInstance ();
  urlRcvr = urlRcvr.QueryInterface (Components.interfaces.IFDMUrlReceiver);
  urlRcvr.SetUrl (url);
  urlRcvr.ShowAddDownloadDialog ();
}

function freeDldMgr_dlHoverElem()
{
  var strUrl = freeDldMgr_getURL (freeDldMgr_hoverElement);
  if (strUrl == null)
    return false;
  freeDldMgr_dlURL (strUrl);
  return true;
}

window.addEventListener ("mousemove", function(ev)
{
  freeDldMgr_fmb_onMouseMove (ev);
}, true);

window.addEventListener ("mouseout", function(ev) 
{
  freeDldMgr_fmb_onMouseOut (ev); 
}, true);

// remember the current hover element here
window.addEventListener("mouseover", function(ev) 
{
      freeDldMgr_hoverElement = ev.target;
      freeDldMgr_fmb_onMouseOver (ev);

}, false);

window.addEventListener("mouseup", function(ev) 
{
  if(ev.altKey && !(ev.ctrlKey || ev.metaKey || ev.shiftKey) && 
   	freeDldMgr_FDM.IsALTShouldBePressed()) 
  {
     if(freeDldMgr_dlHoverElem()) 
     {
       ev.preventDefault();
       ev.stopPropagation();
       freeDldMgr_lastClickCaptureTime = new Date().getTime();
       return;
     }
  }

}, false);

window.addEventListener("click",function(ev) 
{
      if(ev.altKey && new Date().getTime()-freeDldMgr_lastClickCaptureTime < 100) 
      {
        // catch click on a link
        ev.preventDefault();
        ev.stopPropagation();
      }

}, true);

var freeDldMgr_LastPost = null;

var freeDldMgr_Observer = { 
 observe: function (channel, topic, data) 
 {
   if(channel instanceof Components.interfaces.nsIUploadChannel) {
      var freeDldMgr_Ext = Components.classes["@freedownloadmanager.org/FDMFirefoxExtension;1"].createInstance ();
      freeDldMgr_Ext = freeDldMgr_Ext.QueryInterface (Components.interfaces.IFDMFirefoxExtension);
      freeDldMgr_LastPost = channel;
      freeDldMgr_Ext.LastPost = freeDldMgr_LastPost;
   }
 },

 QueryInterface: function (aIID) 
 {
   if (!aIID.equals (Components.interfaces.nsISupports) && !aIID.equals (Components.interfaces.nsIObserver))
      throw Components.result.NS_ERROR_NO_INTERFACE; 
   return this;
 }
};


const freeDldMgr_FFObsrv = Components.classes['@mozilla.org/observer-service;1'].getService(
    Components.interfaces.nsIObserverService);
freeDldMgr_FFObsrv.addObserver (freeDldMgr_Observer, "http-on-modify-request", false);
window.addEventListener("unload",  freeDldMgr_ffext_unload, false);

window.addEventListener("load", freeDldMgr_initOverlay, false);

function freeDldMgr_ffext_unload ()
{
	freeDldMgr_FFObsrv.removeObserver (freeDldMgr_Observer, "http-on-modify-request", false);
	window.removeEventListener("unload",  freeDldMgr_ffext_unload);
}

function freeDldMgr_initOverlay ()
{
  var menu = document.getElementById("contentAreaContextMenu");
  menu.addEventListener("popupshowing", freeDldMgr_contextPopupShowing, false);
}

function freeDldMgr_checkHasVideo ()
{
  return true;
  /*if (document.commandDispatcher.focusedWindow.document.domain == null)
  	return false;
  return freeDldMgr_FDM.IsDomainSupportedForVideoDownloads (document.commandDispatcher.focusedWindow.document.domain);*/
}

// handler. will be called by browser
function freeDldMgr_contextPopupShowing ()
{
  var menuitem = document.getElementById("fdm-context-item-dllink");
  menuitem.label  = freeDldMgr_FDM.GetLngString ("dllink");
  menuitem.hidden = freeDldMgr_FDM.IsContextMenuItemShouldBeHidden ("dllink") || 
  	!freeDldMgr_checkURL (freeDldMgr_getURL (document.popupNode));

  menuitem = document.getElementById("fdm-context-item-dlall");
  menuitem.label  = freeDldMgr_FDM.GetLngString ("dlall");
  menuitem.hidden = freeDldMgr_FDM.IsContextMenuItemShouldBeHidden ("dlall");

  menuitem = document.getElementById("fdm-context-item-dlselected");
  menuitem.label  = freeDldMgr_FDM.GetLngString ("dlselected");
  menuitem.hidden = freeDldMgr_FDM.IsContextMenuItemShouldBeHidden ("dlselected") ||
  	document.commandDispatcher.focusedWindow.getSelection().isCollapsed;

  menuitem = document.getElementById("fdm-context-item-dlvideo");
  menuitem.label  = freeDldMgr_FDM.GetLngString ("dlvideo");
  menuitem.hidden = freeDldMgr_FDM.IsContextMenuItemShouldBeHidden ("dlvideo") ||
  	freeDldMgr_checkHasVideo () == false;

  menuitem = document.getElementById("fdm-context-item-separator");
  menuitem.hidden = freeDldMgr_FDM.IsContextMenuItemShouldBeHidden ("separator1");
}

function freeDldMgr_getURL (node)
{
  if (node instanceof HTMLImageElement &&
	  	!((node.parentNode instanceof HTMLAnchorElement) || (node.parentNode instanceof HTMLAreaElement)))
  	return node.src;  

  if ((node instanceof HTMLAnchorElement) || (node instanceof HTMLAreaElement))
  	return node.href;

  return node.parentNode ? freeDldMgr_getURL (node.parentNode) : null;
}

function freeDldMgr_checkURL (url)
{
   return url ? true : false;
}

function freeDldMgr_dllink ()
{
  freeDldMgr_dlURL (freeDldMgr_getURL (document.popupNode));
}

function freeDldMgr_dlvideo ()
{
  /*freeDldMgr_FDM.ProcessVideoDocument (document.commandDispatcher.focusedWindow.document.domain, 
  	"", document.commandDispatcher.focusedWindow.document.documentElement.innerHTML);*/

  freeDldMgr_FDM.CreateVideoDownloadFromUrl (window.content.document.URL);
}

// add urls of all or selected only elements of current web page to fdm
function freeDldMgr_gatherElements (url, urlListRcvr, elements, bSelectedOnly)
{
  const selection = document.commandDispatcher.focusedWindow.getSelection();
  if (bSelectedOnly && selection.isCollapsed)
  	return;
  for (var i = 0; i < elements.length; i++)
  {
    const elem = elements.item (i);
    if (bSelectedOnly == false || selection.containsNode (elem, true))
    {
        var strUrl = freeDldMgr_getURL (elem);;
        if (freeDldMgr_checkURL (strUrl))
        {
	  url.Url = strUrl;
	  urlListRcvr.AddUrl (url);
	}
    }
  }
}

function freeDldMgr_gatherAllElements (bSelectedOnly, cookie)
{
  var url = Components.classes["@freedownloadmanager.org/FDMUrl;1"].createInstance ();
  url = url.QueryInterface (Components.interfaces.IFDMUrl);
  url.Referer = document.commandDispatcher.focusedWindow.document.URL;
  url.Cookies = cookie;

  var urlListRcvr = Components.classes["@freedownloadmanager.org/FDMUrlListReceiver;1"].createInstance ();
  urlListRcvr = urlListRcvr.QueryInterface (Components.interfaces.IFDMUrlListReceiver);

  freeDldMgr_gatherElements (url, urlListRcvr, 
      document.commandDispatcher.focusedWindow.document.links, bSelectedOnly);

  freeDldMgr_gatherElements (url, urlListRcvr, 
      document.commandDispatcher.focusedWindow.document.images, bSelectedOnly);

  urlListRcvr.ShowAddUrlListDialog ();
}

function freeDldMgr_dlall ()
{
  freeDldMgr_gatherAllElements (false, freeDldMgr_gatherCookieForHost (document.commandDispatcher.focusedWindow.document.location.hostname, document.commandDispatcher.focusedWindow.document.cookie));
}

function freeDldMgr_dlselected ()
{
  freeDldMgr_gatherAllElements (true, freeDldMgr_gatherCookieForHost (document.commandDispatcher.focusedWindow.document.location.hostname, document.commandDispatcher.focusedWindow.document.cookie));
}

Components.classes["@mozilla.org/observer-service;1"]
 .getService(Components.interfaces.nsIObserverService)
 .addObserver (
 {
 observe:
   function (subj, topic, data)
   {
     try {
      subj.QueryInterface (Components.interfaces.nsIHttpChannel);
      if (subj.URI.spec != subj.originalURI.spec)
        freeDldMgr_FDM.OnHttpRedirect (subj.URI.spec, subj.originalURI.spec);
    }catch (err){}
   }
 }, "http-on-examine-response", false);
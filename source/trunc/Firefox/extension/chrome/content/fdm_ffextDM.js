/*

  Overrides default download manager of Firefox.

*/

var fdm_FDM = Components.classes["@freedownloadmanager.org/FDMForFirefox;1"].createInstance ();
fdm_FDM = fdm_FDM.QueryInterface (Components.interfaces.IFDMForFirefox);

// set our "on load" handler.
window.addEventListener("load",  fdm_DM_load, false);

// extract HTTP POST data of the last download
function fdm_extractPostData(channel, url)
{
    if(channel instanceof Components.interfaces.nsIUploadChannel &&
       channel.uploadStream instanceof Components.interfaces.nsISeekableStream) {
      try {
        channel.uploadStream.seek(0,0);
        const sis=Components.classes[
          '@mozilla.org/scriptableinputstream;1'].createInstance(
          Components.interfaces.nsIScriptableInputStream);
        sis.init(channel.uploadStream);
        var index;
        var postData=sis.read(sis.available());
        if (postData.indexOf ("application/x-www-form-urlencoded") >= 0 &&
            url && (index=url.indexOf ("?")) >= 0) {
          // For Content-Type: application/x-www-form-urlencoded
          // get the parameters from the URL after the question mark.
            return url.substring (index+1);
        } else {
          postData=postData.replace(/\s$/,'').split(/[\r\n]/);
          return postData[postData.length-1];
        }
      } catch(ex) {
      } finally {
         sis.close();
      }
    }
    return null;
}

// extract HTTP Cookies of the last download
function fdm_extractCookie(channel, _cookieWeHave)
{
    var _cookie = _cookieWeHave;

    if(channel instanceof Components.interfaces.nsIUploadChannel &&
       channel.uploadStream instanceof Components.interfaces.nsISeekableStream) {
      var cookies = channel.getRequestHeader("Cookie");
      if (cookies) {
        cookies = cookies.split(/\s*;\s*/);
        if (cookies.length > 0) {
          for (var i = 0, l = cookies.length; i < l; i++) {
            if (_cookie.indexOf (cookies[i]) == -1)
            {
              if (_cookie.length)
                _cookie += "; ";
              _cookie += cookies[i];
            }
          }
        }
      }
    }

    return _cookie;
}

function fdm_gatherCookieForHost (_host, _cookieWeHave)
{
   var fdm_cookieManager =
      Components.classes["@mozilla.org/cookiemanager;1"].getService(Components.interfaces.nsICookieManager);
   var _cookie = _cookieWeHave;

   for (var iter = fdm_cookieManager.enumerator; iter.hasMoreElements();) 
   {
      var objCookie;
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

function fdm_DM_load (ev)
{
  var url = Components.classes["@freedownloadmanager.org/FDMUrl;1"].createInstance ();
  url = url.QueryInterface (Components.interfaces.IFDMUrl);
  url.Url = dialog.mLauncher.source.spec;
  try {
    url.UserAgent = window.navigator.userAgent;
  } catch (err) {}

  if (fdm_FDM.IsLinkShouldBeSkipped (url, dialog.mLauncher.suggestedFileName)) 
    return; // do default processing

  var doc;

  try {
    doc = dialog.mContext.QueryInterface(Components.interfaces.nsIInterfaceRequestor)
      .getInterface(Components.interfaces.nsIDOMWindow).document;
  } catch(err) {
    doc = top.opener && top.opener.content && top.opener.content.document || null;
  }

  var cookie = "";

  try {
     if (doc.URL != "about:blank")
	url.Referer = doc.URL;
     cookie = doc.cookie;	
  } catch(err) {}

  try {
    cookie = fdm_gatherCookieForHost (doc.location.hostname, cookie);
  } catch (err) {}

  var fdm_Ext = Components.classes["@freedownloadmanager.org/FDMFirefoxExtension;1"].createInstance ();
  fdm_Ext = fdm_Ext.QueryInterface (Components.interfaces.IFDMFirefoxExtension);

  // fdm_Ext is used by us to store the last HTTP post data
  // extract it if available
  var lastPost = fdm_Ext.LastPost; 
  if (lastPost != null)
  {
    lastPost = lastPost.QueryInterface (Components.interfaces.nsIHttpChannel)
    // This used to check for lastPost.isPending ()
    // but often isPending returns false when true is expected.
    if (url.Url == lastPost.URI.spec) {
      url.PostData = fdm_extractPostData (lastPost, url.Url);
      try {
        cookie = fdm_extractCookie (lastPost, cookie);
      } catch (err) {}
    }
  }

  url.Cookies = cookie;

  if (fdm_FDM.CatchLink (url, dialog.mLauncher.suggestedFileName))
    document.documentElement.cancelDialog(); // download was forwared to FDM. cancel processing by browser.
}
var freeDldMgr_CacheMon = Components.classes["@freedownloadmanager.org/FDMFfCacheMonitor;1"].createInstance ();
freeDldMgr_CacheMon.QueryInterface (Components.interfaces.IFDMFfCacheMonitor);

var freeDldMgr_FDM1 = Components.classes["@freedownloadmanager.org/FDMForFirefox;1"].createInstance ();
freeDldMgr_FDM1.QueryInterface (Components.interfaces.IFDMForFirefox);


function freeDldMgr_TracingListener() {

}

freeDldMgr_TracingListener.prototype =
{
    originalListener: null,
    httpDlgUID : 0,
    bJustNotify : false,
    Url : "",
    bDontCallOriginalListener : false,

    onStartRequest: function(request, context) {
      try{
       	this.originalListener.onStartRequest(request, context);
      }catch(e){this.bDontCallOriginalListener = true;}
    },

    onDataAvailable: function(request, context, inputStream, offset, count)
    {
    	if (!this.bJustNotify)
    	{
        	//fix for firebug error
            if (typeof Cc == "undefined") {
              	var Cc = Components.classes;
            }
            if (typeof Ci == "undefined") {
        		var Ci = Components.interfaces;
            }
            if (typeof CCIN == "undefined") {
               	function CCIN(cName, ifaceName){
		          return Cc[cName].createInstance(Ci[ifaceName]);
				}
            }
            if (typeof CCSV == "undefined") {
                function CCSV(cName, ifaceName){
					if (Cc[cName])
                        // if fbs fails to load, the error can be _CC[cName] has no properties
                        return Cc[cName].getService(Ci[ifaceName]);
					else
                        dumpError("CCSV fails for cName:" + cName);
				}
            }

			var binaryInputStream = CCIN("@mozilla.org/binaryinputstream;1",
                "nsIBinaryInputStream");
			var storageStream = CCIN("@mozilla.org/storagestream;1", "nsIStorageStream");
			var binaryOutputStream = CCIN("@mozilla.org/binaryoutputstream;1","nsIBinaryOutputStream");

			binaryInputStream.setInputStream(inputStream);
			storageStream.init(8192, count, null);
			binaryOutputStream.setOutputStream(storageStream.getOutputStream(0));

			// Copy received data as they come.
			var data = binaryInputStream.readByteArray (count);
        
			freeDldMgr_CacheMon.OnDataReceived (this.httpDlgUID, count, data);

			binaryOutputStream.writeByteArray(data, count);

			if (!this.bDontCallOriginalListener)
			  this.originalListener.onDataAvailable (request, context,
				storageStream.newInputStream(0), offset, count);
		}
		else // bJustNotify is true
		{
			try {
			  freeDldMgr_FDM1.onHttpActivity (this.Url);
			  if (!this.bDontCallOriginalListener)
			    this.originalListener.onDataAvailable (request, context, inputStream, offset, count);
			}catch(e){this.bDontCallOriginalListener = true;}
		}
    },

    onStopRequest: function(request, context, statusCode)
    {
        if (!this.bJustNotify)
	  freeDldMgr_CacheMon.OnDialogClosed (this.httpDlgUID);
        this.originalListener.onStopRequest(request, context, statusCode);
    },

    QueryInterface: function (aIID) {
        if (aIID.equals(Components.interfaces.nsIStreamListener) || aIID.equals(Components.interfaces.nsISupports))
        {
            return this;
        }
        throw Components.results.NS_NOINTERFACE;
    }
};

function freeDldMgr_httpHeaders () {}
freeDldMgr_httpHeaders.prototype =
{
    m_Headers       : "",

    visitHeader: function(name, value)
    {
      this.m_Headers += name + ": " + value + "\r\n"; 
    },

    QueryInterface: function (aIID) {
        if (aIID.equals(Components.interfaces.nsIHttpHeaderVisitor) || aIID.equals(Components.interfaces.nsISupports))
            return this;
        throw Components.results.NS_NOINTERFACE;
    }
};

function freeDldMgr_ExtractUrlFromHttpChannel (channel)
{
  return channel.URI.prePath + channel.URI.path;
}

function freeDldMgr_ExtractHttpHeadersFromHttpChannel (channel)
{
  var reqH = channel.requestMethod + " " + channel.URI.path + " HTTP/1.1" + "\r\n";
  var hdrs = new freeDldMgr_httpHeaders ();
  channel.visitRequestHeaders (hdrs);
  reqH += hdrs.m_Headers;
  delete hdrs;
  var respH = "HTTP/1.0 " + channel.responseStatus + " " + channel.responseStatusText + "\r\n";
  hdrs = new freeDldMgr_httpHeaders;
  channel.visitResponseHeaders (hdrs);
  respH += hdrs.m_Headers;
  delete hdrs;
  return {reqH : reqH, respH : respH};
}

function freeDldMgr_findChannelWindow (aChannel)
{
  try {
   var notificationCallbacks = aChannel.notificationCallbacks ? 
     aChannel.notificationCallbacks : aChannel.loadGroup.notificationCallbacks;
 
   if (!notificationCallbacks)
      return null;
 
    return notificationCallbacks.getInterface(Components.interfaces.nsIDOMWindow);
  }
  catch (e) {return null;}
}

var freeDldMgr_brCacheListener = { 
 observe: function (subject, topic, data) {
   if (false == (subject instanceof Components.interfaces.nsIHttpChannel))
     return;
   subject.QueryInterface(Components.interfaces.nsIHttpChannel);
   var url = freeDldMgr_ExtractUrlFromHttpChannel (subject);

   if (topic == "http-on-modify-request")
   {
     freeDldMgr_FDM1.onHttpActivity (url);
     var wndSrc = freeDldMgr_findChannelWindow (subject);
     if (wndSrc)
     {
       wndSrc = wndSrc.top;
       if (wndSrc)
         freeDldMgr_FDM1.OnNewHttpRequest (url, wndSrc.location.href);
     }
     return;
   }

   var newListener = new freeDldMgr_TracingListener();
   newListener.Url = url;
   newListener.bJustNotify = topic != "http-on-examine-cached-response";
   if (newListener.bJustNotify)
     freeDldMgr_FDM1.onHttpActivity (url);
   
   var hdrs = freeDldMgr_ExtractHttpHeadersFromHttpChannel (subject);
   if (!newListener.bJustNotify)
     newListener.httpDlgUID = freeDldMgr_CacheMon.OnNewHttpDialog (url, hdrs.reqH, hdrs.respH);
   subject.QueryInterface(Components.interfaces.nsITraceableChannel);
   newListener.originalListener = subject.setNewListener(newListener);
 },

 QueryInterface: function (aIID) {
   if (!aIID.equals (Components.interfaces.nsISupports) && !aIID.equals (Components.interfaces.nsIObserver))
      throw Components.result.NS_ERROR_NO_INTERFACE; 
   return this;
 }
};

function freeDldMgr_brCacheRegisterObserver ()
{
  var observerService = Components.classes["@mozilla.org/observer-service;1"]
              .getService(Components.interfaces.nsIObserverService);
  observerService.addObserver(freeDldMgr_brCacheListener, "http-on-modify-request", false);
  observerService.addObserver(freeDldMgr_brCacheListener, "http-on-examine-response", false);
  observerService.addObserver(freeDldMgr_brCacheListener, "http-on-examine-cached-response", false);
  //observerService.addObserver(freeDldMgr_brCacheListener, "http-on-examine-merged-response", false);
  window.addEventListener("unload",  freeDldMgr_brCache_unload, false);
}

freeDldMgr_brCacheRegisterObserver ();


function freeDldMgr_brCache_unload (ev)
{
	var observerService = Components.classes["@mozilla.org/observer-service;1"]
              .getService(Components.interfaces.nsIObserverService);
	observerService.removeObserver(freeDldMgr_brCacheListener, "http-on-modify-request");
	observerService.removeObserver(freeDldMgr_brCacheListener, "http-on-examine-response");
	observerService.removeObserver(freeDldMgr_brCacheListener, "http-on-examine-cached-response");
	observerService.removeObserver(freeDldMgr_brCacheListener, "http-on-examine-merged-response");
	window.removeEventListener("unload",  freeDldMgr_brCache_unload);
}
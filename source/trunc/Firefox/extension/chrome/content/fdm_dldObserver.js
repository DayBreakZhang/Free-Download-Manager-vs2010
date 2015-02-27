var freeDldMgr_FDM = Components.classes["@freedownloadmanager.org/FDMForFirefox;1"].createInstance ();
freeDldMgr_FDM = freeDldMgr_FDM.QueryInterface (Components.interfaces.IFDMForFirefox);

function freeDldMgr_DownloadInit(){
  var observerService = Components.classes["@mozilla.org/observer-service;1"]
                        .getService(Components.interfaces.nsIObserverService);
  observerService.addObserver(freeDldMgr_DownloadObserver, "dl-start", false);
  observerService.addObserver(freeDldMgr_DownloadObserver, "dl-done", false);
  observerService.addObserver(freeDldMgr_DownloadObserver, "dl-cancel", false);
  observerService.addObserver(freeDldMgr_DownloadObserver, "dl-failed", false);

  window.addEventListener("unload", function() {
    observerService.removeObserver(freeDldMgr_DownloadObserver, "dl-start");
    observerService.removeObserver(freeDldMgr_DownloadObserver, "dl-done");
    observerService.removeObserver(freeDldMgr_DownloadObserver, "dl-cancel");
    observerService.removeObserver(freeDldMgr_DownloadObserver, "dl-failed");
  }, false);
}
var freeDldMgr_DownloadObserver = {
  observe: function (subject, topic, state) {
    var oDownload = subject.QueryInterface(Components.interfaces.nsIDownload);
    var oFile = null;
    try{
      oFile = oDownload.targetFile;
    } catch (e){
      oFile = oDownload.target;
    }
    if (topic == "dl-start"){
	  freeDldMgr_FDM.DownloadBegin(oDownload.source);
    }
    if(topic == "dl-cancel"){ 
	  freeDldMgr_FDM.DownloadComplete(oDownload.source);
    }
    else if(topic == "dl-failed"){ 
	  freeDldMgr_FDM.DownloadComplete(oDownload.source);
    }
    else if(topic == "dl-done"){
	  freeDldMgr_FDM.DownloadComplete(oDownload.source);
    }    
  }
}
window.addEventListener("load", freeDldMgr_DownloadInit, false);